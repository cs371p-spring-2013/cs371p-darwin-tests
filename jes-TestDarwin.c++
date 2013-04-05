// --------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app
	g++ Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app -lcppunit -ldl -pedantic -std=c++0x -Wall
    % valgrind TestDarwin.c++.app >& TestDarwin.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <typeinfo> // type
//#include <sstream>  // istringtstream, ostringstream
//#include <string>   // ==
//#include <vector>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"
#include <stdio.h>
extern vector<Creature> creatureList;
extern int _height;
extern int _width;
using namespace std;
// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
 
	// ----
    // Creature class
    // ----

    void test_creatureClass1() {
		Creature c('f','n',1,1, 0);
		CPPUNIT_ASSERT(c._species == 'f');
		CPPUNIT_ASSERT(c._direction == 'n');
		CPPUNIT_ASSERT(c._row == 1);
		CPPUNIT_ASSERT(c._col == 1);    
		CPPUNIT_ASSERT(c._programCounter == 0);
	}
	
	void test_creatureClass2() {
		Creature c('h','n',1,1,1);
		CPPUNIT_ASSERT(c._species == 'h');
		CPPUNIT_ASSERT(c._direction == 'n');
		CPPUNIT_ASSERT(c._row == 1);
		CPPUNIT_ASSERT(c._col == 1);    
		CPPUNIT_ASSERT(c._programCounter == 1);
	}
	
	void test_creatureClass3() {
		Creature c('n','a',0,0,0);
		CPPUNIT_ASSERT(c == Creature());
	}
	
	//testing Creature() constructor with no arguments
	void test_creatureClass4() {
		Creature c;
		CPPUNIT_ASSERT(c == Creature());
	}

	void test_creatureClass5() {
		Creature c;
		CPPUNIT_ASSERT(c._row == 0);
		CPPUNIT_ASSERT(c._col == 0);
		CPPUNIT_ASSERT(c._direction == 'a');
		CPPUNIT_ASSERT(c._species == 'n');
		CPPUNIT_ASSERT(c._programCounter == 0);
	}	
	
	void test_creatureClass6(){
		Creature c;
		CPPUNIT_ASSERT(c != Creature('f','e',1,1,1));
	}
	
	void test_creatureEqual1(){
		Creature c;
		CPPUNIT_ASSERT(c == Creature('n','a',0,0,0));
	}
	
	void test_creatureEqual2(){
		CPPUNIT_ASSERT(Creature('n','a',0,0,0) == Creature());
	}
	
	void test_creatureEqual3(){
		Creature c('f','w',1,2,0);		
		CPPUNIT_ASSERT(c == Creature('f','w',1,2,0));
	}
	
	void test_creatureNotEqual1(){
		Creature c;
		CPPUNIT_ASSERT(c != Creature('f','a',0,0,0));
	}
	
	void test_creatureNotEqual2(){
		CPPUNIT_ASSERT(!(Creature('n','a',0,0,0) != Creature()));
	}
	
	void test_creatureNotEqual3(){
		Creature c('f','w',1,2,1);		
		CPPUNIT_ASSERT(c != Creature());
	}
	
	void test_creaturePlayTurn1(){
		Game g(100,100,2,2);
		g.createCreature('h','e',3,2);
		g.createCreature('r','n',5,4);
		creatureList[0].goneMyTurn = false;
		creatureList[0].creatureProgram[0] = make_pair("hop", -1);
		creatureList[0].creatureProgram[1] = make_pair("go", 0);
		creatureList[1].goneMyTurn = false;
		creatureList[1].creatureProgram[0] = make_pair("if_enemy", 9);
		creatureList[1].creatureProgram[1] = make_pair("if_empty", 7);
		creatureList[1].creatureProgram[2] = make_pair("if_random", 5);
		creatureList[1].creatureProgram[3] = make_pair("left", -1);
		creatureList[1].creatureProgram[4] = make_pair("go", 0);
		creatureList[1].creatureProgram[5] = make_pair("right", -1);
		creatureList[1].creatureProgram[6] = make_pair("go",0);
		creatureList[1].creatureProgram[7] = make_pair("hop", -1);
		creatureList[1].creatureProgram[8] = make_pair("go",0);
		creatureList[1].creatureProgram[9] = make_pair("infect", -1);
		creatureList[1].creatureProgram[10] = make_pair("go",0);
		
		for (int i = 0; i < 5; ++i) {
			creatureList.at(0).playTurn();
			creatureList.at(0).goneMyTurn = false;
			creatureList.at(1).playTurn();
			creatureList.at(1).goneMyTurn = false;
		}
		// cout << "1st cre row " << creatureList[0]._row << ", col " << creatureList[0]._col << endl;
		// cout << "2nd cre row " << creatureList[1]._row << ", col " << creatureList[1]._col << endl;
		CPPUNIT_ASSERT(creatureList[1]._row == 1 && creatureList[1]._col == 4 && creatureList[1]._species == 'r');
		CPPUNIT_ASSERT(creatureList[0]._row == 3 && creatureList[0]._col == 7 && creatureList[0]._species == 'r');
	}
	
	void test_creaturePlayTurn2(){
		Game g(2,3,2,2); // height, width, numCreatures, turns
		g.createCreature('r','e',0,0);
		g.createCreature('r','e',1,0);
		for (int i = 0; i < 2; ++i) {
			creatureList[i].goneMyTurn = false;
			creatureList[i].creatureProgram[0] = make_pair("if_enemy", 9);
			creatureList[i].creatureProgram[1] = make_pair("if_empty", 7);
			creatureList[i].creatureProgram[2] = make_pair("if_random", 5);
			creatureList[i].creatureProgram[3] = make_pair("left", -1);
			creatureList[i].creatureProgram[4] = make_pair("go", 0);
			creatureList[i].creatureProgram[5] = make_pair("right", -1);
			creatureList[i].creatureProgram[6] = make_pair("go",0);
			creatureList[i].creatureProgram[7] = make_pair("hop", -1);
			creatureList[i].creatureProgram[8] = make_pair("go",0);
			creatureList[i].creatureProgram[9] = make_pair("infect", -1);
			creatureList[i].creatureProgram[10] = make_pair("go",0);
		}
		for (int i = 0; i < 5; ++i) {
			creatureList.at(0).playTurn();
			creatureList.at(0).goneMyTurn = false;
			creatureList.at(1).playTurn();
			creatureList.at(1).goneMyTurn = false;
			g.print(i,false);
		}
		CPPUNIT_ASSERT(creatureList.size() == 2);
		CPPUNIT_ASSERT(creatureList[0]._col == 1 && creatureList[0]._row == 0);
		// cout << "second creature is at " << creatureList[1]._row << ", " << creatureList[1]._col <<endl;
		// CPPUNIT_ASSERT(creatureList[1]._col == 2 && creatureList[1]._row == 1);
		CPPUNIT_ASSERT(g._turns == 2);
		
	}
	
	void test_creaturePlayTurn3(){
		Game g(25,3,2,2); // height, width, numCreatures, turns
		g.createCreature('f','e',0,0);
		g.createCreature('h','n',1,0);
		for (int i = 0; i < 2; ++i) {
			if (creatureList[i]._species == 'f'){				
				creatureList[i].creatureProgram[0] = make_pair("left",-1);
				creatureList[i].creatureProgram[1] = make_pair("go",0);
			} else {
				creatureList[i].creatureProgram[0] = make_pair("hop", -1);
				creatureList[i].creatureProgram[1] = make_pair("go", 0);
			}
			creatureList[i].goneMyTurn = false;
		}
		for (int i = 0; i < 5; ++i) {
			creatureList.at(0).playTurn();
			creatureList.at(0).goneMyTurn = false;
			creatureList.at(1).playTurn();
			creatureList.at(1).goneMyTurn = false;
			g.print(i,false);
		}
		CPPUNIT_ASSERT(creatureList.size() == 2);
		CPPUNIT_ASSERT(creatureList[0]._col == 0 && creatureList[0]._row == 0);
		CPPUNIT_ASSERT(creatureList[1]._col == 0 && creatureList[1]._row == 1);
	}
	
	void test_creatureAssign1(){
		Creature c('f','n',0,0,7);
		Creature c1('h','s',1,1,8);
		c = c1;
		CPPUNIT_ASSERT(c==c1);
	}
	
	void test_creatureAssign2(){
		Creature c('f','n',0,0,7);
		Creature c1('h','s',1,1,8);
		c = c1;
		CPPUNIT_ASSERT(c._programCounter==8);
		CPPUNIT_ASSERT(c._row==1);
	}
	
	void test_creatureAssign3(){
		Creature c;
		CPPUNIT_ASSERT(c._programCounter == 0);
		c = Creature('f','s',100,100,8);
		CPPUNIT_ASSERT(c._programCounter == 8);
	}
	
	void test_creatureHop1(){
		Game g(8,8,1,8);
		g.createCreature('h','s',7,7); 
		for (int i = 0; i < 3; ++i)
			creatureList[0].hop();
		// g.play(true);
		// cout << "row is " << creatureList[0]._col << endl;
		CPPUNIT_ASSERT(creatureList[0]._col == 7);
		CPPUNIT_ASSERT(creatureList[0]._row == 7);
	}
	
	void test_creatureHop2(){
		Game g(8,8,1,8);
		g.createCreature('h','n',7,7);
		for (int i = 0; i < 8; ++i)
			creatureList[0].hop();
		CPPUNIT_ASSERT(creatureList[0]._row == 0);
	}
	
	void test_creatureHop3(){
		Game g(10,10,2,4);
		g.createCreature('f','n',5,5);
		g.createCreature('h','n',6,5);
		for (int i = 0; i < 8; ++i)
			creatureList[1].hop();
		CPPUNIT_ASSERT(creatureList[1]._row == 6);
	}
	
	void test_creatureLeft1(){
		Creature c('r','s',0,0,0);
		c.left();
		CPPUNIT_ASSERT(c._direction == 'e');
	}
	
	void test_creatureLeft2(){
		Creature c('t','n',0,0,0);
		for (int i = 0; i < 4; ++i)
			c.left();
		CPPUNIT_ASSERT(c._direction == 'n');
	}
	
	void test_creatureLeft3(){
		Creature c('r','s',0,0,0);
		for (int i = 0; i < 4; ++i)
			c.left();
		CPPUNIT_ASSERT(c._direction == 's');
	}	
	
	void test_creatureRight1(){
		Creature c('f','s',0,0,0);
		c.right();
		CPPUNIT_ASSERT(c._direction == 'w');
	}
	
	void test_creatureRight2(){
		Creature c1('r','s',0,0,0);
		c1.right();
		c1.right();
		CPPUNIT_ASSERT(c1._direction == 'n');
	}
	
	void test_creatureRight3(){
		Creature c2('t','s',0,0,0);
		for (int i = 0; i < 4; ++i)
			c2.right();
		CPPUNIT_ASSERT(c2._direction == 's');
	}	
	
	void test_creatureInfect1(){
		Game g(30,30,2,1);
		g.createCreature('r','s',0,0);
		g.createCreature('f','n',1,0);
		creatureList[0].infect();
		CPPUNIT_ASSERT(creatureList[1]._species == 'r');
		CPPUNIT_ASSERT(creatureList[1]._programCounter == 0);
	}
	
	//if creature ahead is of the same species, it should not be infected
	void test_creatureInfect2(){
		Game g(30,30,2,1);
		g.createCreature('r','s',0,0);
		g.createCreature('r','n',1,0);
		creatureList[0].infect();
		CPPUNIT_ASSERT(creatureList[1]._species == 'r');
		CPPUNIT_ASSERT(creatureList[1]._programCounter == 0);
	}
	
	//creatures that don't have infect in program should not be able to infect
	void test_creatureInfect3(){
		Game g(100,100,2,2);
		g.createCreature('r','s',98,99);
		g.createCreature('h','n',99,99);
		creatureList[0].infect();
		// creatureList[1].infect();
		CPPUNIT_ASSERT(creatureList[0]._species == 'r');
		CPPUNIT_ASSERT(creatureList[0]._programCounter == 0);
		// cout << "species is " << creatureList[1]._species << endl;
		CPPUNIT_ASSERT(creatureList[1]._species == 'r');
		CPPUNIT_ASSERT(creatureList[1]._programCounter == 0);
	}	
	
	void test_creatureIfEmpty1(){
		Game g(100,100,1,1);
		g.createCreature('r','n',5,5);
		Creature c = creatureList[0];
		CPPUNIT_ASSERT(c._species == 'r');
		CPPUNIT_ASSERT(c._direction == 'n');
		CPPUNIT_ASSERT(c._row == 5);
		CPPUNIT_ASSERT(c._col == 5);
		CPPUNIT_ASSERT(c._programCounter == 0);
		CPPUNIT_ASSERT(c.ifEmpty());
		c._direction = 'w';
		CPPUNIT_ASSERT(c.ifEmpty());
		c._direction = 's';
		CPPUNIT_ASSERT(c.ifEmpty());
		c._direction = 'e';
		CPPUNIT_ASSERT(c.ifEmpty());
		CPPUNIT_ASSERT(creatureList[0].ifEmpty());
		creatureList[0]._direction = 'w';
		CPPUNIT_ASSERT(creatureList[0].ifEmpty());
		creatureList[0]._direction = 's';
		CPPUNIT_ASSERT(creatureList[0].ifEmpty());
		creatureList[0]._direction = 'e';
		CPPUNIT_ASSERT(creatureList[0].ifEmpty());
	}
	
	// test for implicit !ifEmpty() as it is within first two instructions of creature
	void test_creatureIfEmpty2(){
		Game g(100,100,1,1);
		g.createCreature('r','s',5,5);
		g.createCreature('r','n',6,5);
		g.play(false);
		CPPUNIT_ASSERT(creatureList[0]._direction == 'e' || creatureList[0]._direction == 'w');
		CPPUNIT_ASSERT(creatureList[1]._direction == 'e' || creatureList[1]._direction == 'w');
	}
	
	// test for explicit !ifEmpty()
	void test_creatureIfEmpty3(){
		Game g(100,100,1,1);
		g.createCreature('r','s',5,5);
		g.createCreature('r','n',6,5);
		CPPUNIT_ASSERT(!creatureList[0].ifEmpty());
		CPPUNIT_ASSERT(!creatureList[1].ifEmpty());
	}
	
	//uninitialized doesn't have valid x & y coordinates so ifWall should return false
	void test_creatureIfWall1(){
		Creature c;
		CPPUNIT_ASSERT(!c.ifWall());
	}
	
	//test corners
	void test_creatureIfWall2(){
		Game g(100,100,1,1);
		g.createCreature('r','n',0,0);
		Creature c = creatureList[0];
		CPPUNIT_ASSERT(c.ifWall());
		c._direction = 'w';
		CPPUNIT_ASSERT(c.ifWall());
		c._row = 99;
		c._col = 99;
		c._direction = 'e';
		CPPUNIT_ASSERT(c.ifWall());
		c._direction = 's';
		CPPUNIT_ASSERT(c.ifWall());
	}
	
	// test in a totally enclosed condition
	void test_creatureIfWall3(){
		Game g(1,1,1,1);
		g.createCreature('r','n',0,0);
		Creature c = creatureList[0];
		CPPUNIT_ASSERT(c.ifWall());
		c._direction = 'w';
		CPPUNIT_ASSERT(c.ifWall());
		c._direction = 'e';
		CPPUNIT_ASSERT(c.ifWall());
		c._direction = 's';
		CPPUNIT_ASSERT(c.ifWall());
	}
	
	void test_creatureIfRandom1(){
		Creature c;
		c.ifRandom();
		CPPUNIT_ASSERT(true);
	}
	
	void test_creatureIfRandom2(){
		Creature c;
		int b = c.ifRandom();
		if (b)
			CPPUNIT_ASSERT(true);
		else
			CPPUNIT_ASSERT(false);
	}
	
	void test_creatureIfRandom3(){
		Creature c;
		// cout << "type is " << typeid(c.ifRandom()).name() << endl;
		CPPUNIT_ASSERT(*typeid(c.ifRandom()).name() == 'b');
		
	}
	
	void test_creatureIfEnemy1(){
		Game g(3,3,5,1);
		g.createCreature('r','n',1,1);
		g.createCreature('f','n',0,1); //north
		g.createCreature('t','n',1,0); //west
		g.createCreature('f','n',2,1); //south
		g.createCreature('h','n',1,2); //east
		Creature c = creatureList[0];
		CPPUNIT_ASSERT((int)c.ifEnemy().first == 0 && (int)c.ifEnemy().second == 1);
		c._direction = 'w';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == 1 && (int)c.ifEnemy().second == 0);
		c._direction = 's';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == 2 && (int)c.ifEnemy().second == 1);
		c._direction = 'e';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == 1 && (int)c.ifEnemy().second == 2);
	}
	
	void test_creatureIfEnemy2(){
		Game g(10,10,5,1);
		g.createCreature('r','n',1,1);
		g.createCreature('r','n',0,1); //north
		g.createCreature('r','n',1,0); //west
		g.createCreature('r','n',2,1); //south
		g.createCreature('r','n',1,2); //east
		Creature c = creatureList[0];
		CPPUNIT_ASSERT((int)c.ifEnemy().first == -1 && (int)c.ifEnemy().second == -1);
		c._direction = 'w';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == -1 && (int)c.ifEnemy().second == -1);
		c._direction = 's';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == -1 && (int)c.ifEnemy().second == -1);
		c._direction = 'e';
		CPPUNIT_ASSERT((int)c.ifEnemy().first == -1 && (int)c.ifEnemy().second == -1);
	}
	
	//test if Enemy after infection
	void test_creatureIfEnemy3(){
		Game g(10,10,5,1);
		g.createCreature('r','n',1,1);
		g.createCreature('f','s',0,1); //north
		Creature infecter = creatureList[0];
		CPPUNIT_ASSERT(creatureList[1]._species == 'f');
		infecter.infect();
		Creature converted = creatureList[1];
		CPPUNIT_ASSERT(converted._species == 'r');
		CPPUNIT_ASSERT(converted.ifEnemy().first == -1 && converted.ifEnemy().second == -1);
		CPPUNIT_ASSERT(infecter.ifEnemy().first == -1 && infecter.ifEnemy().second == -1);
	}
	
	// ----
    // Game class
    // ----

    void test_gameClass1() {
		Game g(8,8,1,1);
		CPPUNIT_ASSERT(_height == 8);
		CPPUNIT_ASSERT(_width == 8);
		CPPUNIT_ASSERT(g._numCr == 1);
		CPPUNIT_ASSERT(g._turns == 1);
	}
	
	void test_gameClass2() {
		Game g(100, 100, 100, 1);
		CPPUNIT_ASSERT(_height == 100);
		CPPUNIT_ASSERT(_width == 100);
		CPPUNIT_ASSERT(g._numCr == 100);
		CPPUNIT_ASSERT(g._turns == 1);
	}
	
	void test_gameClass3() {
		Game g(2000, 2000, 1, 1);
		CPPUNIT_ASSERT(_height == 2000);
		CPPUNIT_ASSERT(_width == 2000);
		CPPUNIT_ASSERT(g._numCr == 1);
		CPPUNIT_ASSERT(g._turns == 1);
	}
	
	 void test_gameCreateCreature1() {
		Game g(8,8,1,1); //height, width, numCreatures, turns
		g.createCreature('f','n',0,0);
		int c = g.find(0,0);
		CPPUNIT_ASSERT(creatureList[c]._species == 'f');
		CPPUNIT_ASSERT(creatureList.at(c)._direction == 'n');
		CPPUNIT_ASSERT(creatureList.at(c)._programCounter == 0);
	}
	
	void test_gameCreateCreature2() {
		Game g(100, 100, 100, 1);
		g.createCreature('f','e',1,1);
		g.createCreature('h','s',2,3);
		CPPUNIT_ASSERT(creatureList.size() == (unsigned int)2);
		// cout << "160 size " << creatureList.size() << endl;
		CPPUNIT_ASSERT(g._numCr == 100);
		CPPUNIT_ASSERT(creatureList[0]._species == 'f');
		CPPUNIT_ASSERT(creatureList[1]._species == 'h');
		CPPUNIT_ASSERT(creatureList[g.find(2,3)]._row == 2);
	}
	
	void test_gameCreateCreature3() {
		Game g(2000, 1, 1, 1);
		g.createCreature('r','n',1,1);
		CPPUNIT_ASSERT(creatureList.size() == 0);
		//cout << "170 size " << creatureList.size() << endl;
	}
	
	void test_gameFindCreature1() {
		Game g(2000, 1, 1, 1);
		g.createCreature('r','n',0,0);
		CPPUNIT_ASSERT(g.find(2,3) == -2);
	}
	
	void test_gameFindCreature2() {
		Game g(100, 100, 100, 1);
		g.createCreature('f','e',1,0);
		g.createCreature('h','s',1,0);
		CPPUNIT_ASSERT(g.find(1,0) == 0); 
		//cout << "g.find " << g.find(1,0) << endl;
		CPPUNIT_ASSERT(creatureList.size() == 1);
		// for (unsigned int i = 0; i < creatureList.size(); ++i) {
			// Creature c = creatureList[i];
			// cout << "\n" << c._species << endl;
			// cout << c._direction << endl;
			// cout << c._row << ", " << c._col << "\n" << endl;
		// }
		// CPPUNIT_ASSERT(g.find(1,0)._species == 'h');
		// CPPUNIT_ASSERT(g.find(1,0)._species == 'f');
		
	}
	
	void test_gameFindCreature3() {
		Game g(8,8,1,1);
		g.createCreature('f','n',0,0);
		int c = g.find(0,0);
		CPPUNIT_ASSERT(c == 0);
		CPPUNIT_ASSERT(creatureList[c] == Creature('f','n',0,0,0));
		CPPUNIT_ASSERT(creatureList.at(c) == Creature('f','n',0,0,0));
	}
	
	void test_gamePrint1() {
		Game g(8,8,1,2); // height, width, numCreatures, turns
		g.createCreature('f','n',0,0);
		CPPUNIT_ASSERT(creatureList[0]._species == 'f');
		CPPUNIT_ASSERT(creatureList.size() == 1);
		CPPUNIT_ASSERT(_height == 8);
		CPPUNIT_ASSERT(_width == 8);
		CPPUNIT_ASSERT(g._turns == 2);
		g.print(0, false);
		CPPUNIT_ASSERT(true);
	}
	
	void test_gamePrint2() {
		Game g(8,9,1,2); // height, width, numCreatures, turns
		g.createCreature('f','n',8,9);
		CPPUNIT_ASSERT(creatureList.size() == 0);
		CPPUNIT_ASSERT(_height == 8);
		CPPUNIT_ASSERT(_width == 9);
		CPPUNIT_ASSERT(g._turns == 2);
		g.print(2, false);
		CPPUNIT_ASSERT(true);
	}
	
	void test_gamePrint3() {
		Game g(100,100,1,100); // height, width, numCreatures, turns
		g.createCreature('f','s',8,9);
		g.createCreature('r','s',8,9);
		CPPUNIT_ASSERT(creatureList.size() == 1);
		CPPUNIT_ASSERT(_height == 100);
		CPPUNIT_ASSERT(_width == 100);
		CPPUNIT_ASSERT(g._turns == 100);
		g.print(100, false);
		CPPUNIT_ASSERT(true);
	}
	
	void test_gamePlay1() {
		Game g(18,18,2,13); // height, width, numCreatures, turns
		g.createCreature('f','n',0,0);
		g.createCreature('h','n',17,7);
		g.createCreature('h','e',17,0);
		CPPUNIT_ASSERT(creatureList[0]._species == 'f');
		CPPUNIT_ASSERT(creatureList[1]._species == 'h');
		CPPUNIT_ASSERT(creatureList.size() == 3);
		CPPUNIT_ASSERT(_height == 18);
		CPPUNIT_ASSERT(_width == 18);
		CPPUNIT_ASSERT(g._turns == 13);
		g.play(false); //argument is false to avoid printing on tests
		CPPUNIT_ASSERT(creatureList[0]._row == creatureList[0]._col);
		CPPUNIT_ASSERT(creatureList[1]._row == 4 && creatureList[1]._col == 7);
		CPPUNIT_ASSERT(creatureList[2]._row == 17 && creatureList[2]._col == 13);
	}
	
	void test_gamePlay2() {
		Game g(10,10,4,5); // height, width, numCreatures, turns
		g.createCreature('t','s',0,0);
		g.createCreature('h','e',3,2);
		g.createCreature('r','n',5,4);
		// g.createCreature('h','n',5,4);
		g.createCreature('t','w',6,8);
		CPPUNIT_ASSERT(creatureList.size() == 4);
		CPPUNIT_ASSERT(_height == 10);
		CPPUNIT_ASSERT(_width == 10);
		CPPUNIT_ASSERT(g._turns == 5);
		g.play(false);
		CPPUNIT_ASSERT(creatureList[0]._row == creatureList[0]._col);
		// CPPUNIT_ASSERT(creatureList[2]._row == 1 && creatureList[2]._col == 4 && creatureList[2]._species == 'h');
		CPPUNIT_ASSERT(creatureList[2]._row == 1 && creatureList[2]._col == 4 && creatureList[2]._species == 'r');
		CPPUNIT_ASSERT(creatureList[1]._row == 3 && creatureList[1]._col == 7 && creatureList[1]._species == 'r');
	}
	
	void test_gamePlay3() {
		Game g(2,3,2,2); // height, width, numCreatures, turns
		g.createCreature('r','e',0,0);
		g.createCreature('r','e',1,0);
		g.play(false);
		CPPUNIT_ASSERT(creatureList.size() == 2);
		CPPUNIT_ASSERT(creatureList[0]._col == 2 && creatureList[0]._row == 0);
		CPPUNIT_ASSERT(creatureList[1]._col == 2 && creatureList[1]._row == 1);
		CPPUNIT_ASSERT(g._turns == 2);
	}
	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
	
    CPPUNIT_TEST(test_creatureClass1);
	CPPUNIT_TEST(test_creatureClass2);
	CPPUNIT_TEST(test_creatureClass3);
	CPPUNIT_TEST(test_creatureClass4);
	CPPUNIT_TEST(test_creatureClass5);
	CPPUNIT_TEST(test_creatureClass6);
	
	CPPUNIT_TEST(test_creatureEqual1);
	CPPUNIT_TEST(test_creatureEqual2);
	CPPUNIT_TEST(test_creatureEqual3);
	
	CPPUNIT_TEST(test_creatureNotEqual1);
	CPPUNIT_TEST(test_creatureNotEqual2);
	CPPUNIT_TEST(test_creatureNotEqual3);
		
	CPPUNIT_TEST(test_creaturePlayTurn1);
	CPPUNIT_TEST(test_creaturePlayTurn2);
	CPPUNIT_TEST(test_creaturePlayTurn3);
	
	CPPUNIT_TEST(test_creatureAssign1);
	CPPUNIT_TEST(test_creatureAssign2);
	CPPUNIT_TEST(test_creatureAssign3);
	
	CPPUNIT_TEST(test_creatureHop1);
	CPPUNIT_TEST(test_creatureHop2);
	CPPUNIT_TEST(test_creatureHop3);
	
	CPPUNIT_TEST(test_creatureLeft1);
	CPPUNIT_TEST(test_creatureLeft2);
	CPPUNIT_TEST(test_creatureLeft3);
	
	CPPUNIT_TEST(test_creatureRight1);
	CPPUNIT_TEST(test_creatureRight2);
	CPPUNIT_TEST(test_creatureRight3);
	
	CPPUNIT_TEST(test_creatureInfect1);
	CPPUNIT_TEST(test_creatureInfect2);
	CPPUNIT_TEST(test_creatureInfect3);
	
	CPPUNIT_TEST(test_creatureIfEmpty1);
	CPPUNIT_TEST(test_creatureIfEmpty2);
	CPPUNIT_TEST(test_creatureIfEmpty3);
	
	CPPUNIT_TEST(test_creatureIfWall1);
	CPPUNIT_TEST(test_creatureIfWall2);
	CPPUNIT_TEST(test_creatureIfWall3);
	
	CPPUNIT_TEST(test_creatureIfRandom1);
	CPPUNIT_TEST(test_creatureIfRandom2);
	CPPUNIT_TEST(test_creatureIfRandom3);
	
	CPPUNIT_TEST(test_creatureIfEnemy1);
	CPPUNIT_TEST(test_creatureIfEnemy2);
	CPPUNIT_TEST(test_creatureIfEnemy3);
	
	CPPUNIT_TEST(test_gameClass1);
	CPPUNIT_TEST(test_gameClass2);
	CPPUNIT_TEST(test_gameClass3);
	
	CPPUNIT_TEST(test_gameCreateCreature1);
	CPPUNIT_TEST(test_gameCreateCreature2);
	CPPUNIT_TEST(test_gameCreateCreature3);
	
	CPPUNIT_TEST(test_gameFindCreature1);
	CPPUNIT_TEST(test_gameFindCreature2);
	CPPUNIT_TEST(test_gameFindCreature3);
	
	CPPUNIT_TEST(test_gamePrint1);
	CPPUNIT_TEST(test_gamePrint2);
	CPPUNIT_TEST(test_gamePrint3);
	
	CPPUNIT_TEST(test_gamePlay1);
	CPPUNIT_TEST(test_gamePlay2); 
	CPPUNIT_TEST(test_gamePlay3);
	
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;
    
    CppUnit::TextTestRunner tr;
	// cout << "105\n";
    tr.addTest(TestDarwin::suite());
	// cout << "107\n";
    tr.run();
	// cout << "109\n";
    cout << "Done." << endl;
    return 0;}
