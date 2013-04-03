// ------------------------------------
// projects/allocator/TestAllocator.c++
// Copyright (C) 2013
// Glenn P. Downing
// ------------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// -------------
// TestAllocator
// -------------

struct TestDarwin : CppUnit::TestFixture {


    // --------
    // test construct for Game
    // --------

    void test_Game1 () {
        Game x = Game(8, 8);
		assert(x._width == x._height);       
    }

    void test_Game2 () {
        Game x = Game(5, 8);
		assert(x._width != x._height);
		assert((x.board[0].compare("........")) ==0);       
    }

    void test_Game3 () {
        Game x = Game(3, 4);
		assert(x._width == 4);
		assert(x.creatures.empty());
		assert(x.board.size() == 3);       
    }

    // --------
    // test Add Creature for Game
    // --------
	
	void test_AddCreature1 (){
		Game x = Game(9,9);
		x.AddCreature(0,0,'f','e');
		assert(x.board[0].at(0) == 'f');
		assert(x.board[0].at(1) == '.');
	}

	void test_AddCreature2 (){
		Game x = Game(9,9);
		x.AddCreature(0,0,'f','e');
		x.AddCreature(2,2,'f','e');
		assert(x.board[0].at(0) == 'f');
		assert(x.board[2].at(2) == 'f');
		assert(x.creatures[0]._name == 'f');
		assert(x.creatures[1]._direction == 'e');
	}

	void test_AddCreature3 (){
		Game x = Game(9,9);
		x.AddCreature(0,0,'f','e');
		x.AddCreature(2,2,'f','e');
		x.AddCreature(2,3,'f','e');
		x.AddCreature(2,4,'f','e');
		assert(x.board[0].compare("f........") == 0);
		assert(x.board[2].compare("..fff....") == 0);
		assert(x.creatures.size() == 4);
	}


    // --------
    // test Simulate for Game
    // --------

	void test_Simulate1 (){
		Game x = Game(9,9);
		x.AddCreature(4,4,'h','n');
		assert(x.board[4].at(4) == 'h');
		x.Simulate(2,100);
		assert(x.board[4].at(4) == '.');
		assert(x.board[2].at(4) == 'h');
	}

	void test_Simulate2 (){
		Game x = Game(9,9);
		x.AddCreature(4,4,'h','n');
		x.AddCreature(0,0,'h','s');
		assert(x.board[4].at(4) == 'h');
		x.Simulate(50,100);
		assert(x.board[0].at(4) == 'h');
		assert(x.board[8].at(0) == 'h');
	}

	void test_Simulate3(){
		Game x = Game(9,9);
		x.AddCreature(0,0,'h','s');
		x.AddCreature(8,8,'h','n');
		x.Simulate(50,100);
		assert(x.board[8].at(0) == 'h');
		assert(x.board[0].at(8) == 'h');
		assert(x.board[0].at(0) == '.');
		assert(x.board[8].at(8) == '.');
	}

    // --------
    // test Execute for Game
    // --------
	void test_Execute1(){
		Game x = Game(8,8);
		x.AddCreature(0,0,'f','n');
		x.Execute("left",x.creatures[0]);
		assert(x.creatures[0]._direction == 'w');
	}


	void test_Execute2(){
		Game x = Game(8,8);
		x.AddCreature(0,0,'f','n');
		x.Execute("left",x.creatures[0]);
		x.Execute("left",x.creatures[0]);
		x.Execute("left",x.creatures[0]);
		x.Execute("left",x.creatures[0]);
		assert(x.creatures[0]._direction == 'n');
	}

	void test_Execute3(){
		Game x = Game(8,8);
		x.AddCreature(0,0,'h','s');
		x.Execute("hop",x.creatures[0]);
		x.Execute("hop",x.creatures[0]);
		assert(x.creatures[0]._rowPos == 2);
	}

    // --------
    // test checkIf for Game
    // --------
	void test_CheckIf1(){
		Game x = Game(8,8);
		x.AddCreature(0,0,'h','n');
		assert(x.CheckIf("wall",x.creatures[0]));
		assert(!(x.CheckIf("enemy",x.creatures[0])));
	}

	void test_CheckIf2(){
		Game x = Game(8,8);
		x.AddCreature(4,4,'h','n');
		assert(!(x.CheckIf("wall",x.creatures[0])));
		assert(!(x.CheckIf("enemy",x.creatures[0])));
	}

	void test_CheckIf3(){
		Game x = Game(8,8);
		x.AddCreature(0,0,'h','n');
		x.AddCreature(1,0,'t','n');
		assert(x.CheckIf("enemy",x.creatures[1]));
	}
    // --------
    // test isWall for Game
    // --------
	void test_isWall1(){
		Game x = Game(8,8);
		assert(!x.isWall(0,0));
	}

	void test_isWall2(){
		Game x = Game(8,8);
		assert(x.isWall(90,0));
	}

	void test_isWall3(){
		Game x = Game(8,8);
		assert(x.isWall(-1,4));
	}

    // --------
    // test isEmpty for Game
    // --------
	void test_isEmpty1(){
		Game x = Game(8,8);
		assert(x.isEmpty(0,0));
	}

	void test_isEmpty2(){
		Game x = Game(8,8);
		assert(x.isEmpty(5,5));
	}

	void test_isEmpty3(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'h','n');
		assert(!x.isEmpty(5,5));
	}

    // --------
    // test isEnemy for Game
    // --------
	void test_isEnemy1(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'h','n');
		assert(!x.isEnemy(0,0,x.creatures[0]));
	}

	void test_isEnemy2(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'h','n');
		x.AddCreature(6,5,'h','n');
		assert(!x.isEnemy(5,5,x.creatures[1]));
	}

	void test_isEnemy3(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'t','n');
		x.AddCreature(6,5,'h','n');
		assert(x.isEnemy(5,5,x.creatures[1]));
	}


    // --------
    // test CrSort for Game
    // --------
	void test_CrSort1(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'t','n');
		x.AddCreature(0,0,'h','n');
		assert(x.creatures[0]._name == 't');
	}

	void test_CrSort2(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'t','n');
		x.AddCreature(0,0,'h','n');
		assert(x.creatures[0]._name == 't');
		x.CrSort();
		assert(x.creatures[0]._name == 'h');
	}

	void test_CrSort3(){
		Game x = Game(8,8);
		x.AddCreature(5,5,'t','n');
		x.AddCreature(1,3,'h','n');
		x.AddCreature(6,6,'t','n');
		x.AddCreature(4,2,'h','n');
		x.AddCreature(2,4,'t','n');
		x.AddCreature(0,0,'h','n');
		assert(x.creatures[0]._name == 't');
		x.CrSort();
		assert(x.creatures[0]._name == 'h');
	}

    // --------
    // test construct for Creature
    // --------
	
	void test_Creature1(){
		Creature cr = Creature('f','n',0,0,5);
		assert(cr._name == 'f');
		assert(cr._pos == 0);
	}

	void test_Creature2(){
		Creature cr = Creature('h','n',0,0,5);
		assert(cr._name == 'h');
		assert(cr._pos == 0);
	}

	void test_Creature3(){
		Creature cr = Creature('t','n',0,0,5);
		assert(cr._name == 't');
		assert(cr._pos == 0);
		assert(cr._direction == 'n');
	}
	

    // --------
    // test Next_Instr for Creature
    // --------
	void test_Next_Instr1(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
	}

	void test_Next_Instr2(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
		cr._PC++;
		assert(cr.Next_Instr().compare("if_empty 7")==0);
	}

	void test_Next_Instr3(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
		cr._PC = 9;
		assert(cr.Next_Instr().compare("infect")==0);
	}


    // --------
    // test Set_Instr for Creature
    // --------
	void test_Set_Instr1(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
	}

	void test_Set_Instr2(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
		cr._name = 'h';
		cr.Set_Instr();
		assert(cr.Next_Instr().compare("hop")==0);
	}

	void test_Set_Instr3(){
		Creature cr = Creature('r','s',0,0,5);
		assert(cr._name == 'r');
		assert(cr.Next_Instr().compare("if_enemy 9")==0);
		cr._name = 'b';
		cr.Set_Instr();
		cr._PC = 13;
		assert(cr.Next_Instr().compare("infect")==0);
	}


    CPPUNIT_TEST_SUITE(TestDarwin);
  
    CPPUNIT_TEST(test_Game1);
    CPPUNIT_TEST(test_Game2);
    CPPUNIT_TEST(test_Game3);
    CPPUNIT_TEST(test_AddCreature1);
    CPPUNIT_TEST(test_AddCreature2);
    CPPUNIT_TEST(test_AddCreature3);
	CPPUNIT_TEST(test_Simulate1);
	CPPUNIT_TEST(test_Simulate2);
	CPPUNIT_TEST(test_Simulate3);
	CPPUNIT_TEST(test_Execute1);
	CPPUNIT_TEST(test_Execute2);
	CPPUNIT_TEST(test_Execute3);
	CPPUNIT_TEST(test_CheckIf1);
	CPPUNIT_TEST(test_CheckIf2);
	CPPUNIT_TEST(test_CheckIf3);
	CPPUNIT_TEST(test_isWall1);
	CPPUNIT_TEST(test_isWall2);
	CPPUNIT_TEST(test_isWall3);
	CPPUNIT_TEST(test_isEmpty1);
	CPPUNIT_TEST(test_isEmpty2);
	CPPUNIT_TEST(test_isEmpty3);
	CPPUNIT_TEST(test_isEnemy1);
	CPPUNIT_TEST(test_isEnemy2);
	CPPUNIT_TEST(test_isEnemy3);
	CPPUNIT_TEST(test_CrSort1);
	CPPUNIT_TEST(test_CrSort2);
	CPPUNIT_TEST(test_CrSort3);

	CPPUNIT_TEST(test_Creature1);
	CPPUNIT_TEST(test_Creature2);
	CPPUNIT_TEST(test_Creature3);
	CPPUNIT_TEST(test_Next_Instr1);
	CPPUNIT_TEST(test_Next_Instr2);
	CPPUNIT_TEST(test_Next_Instr3);
	CPPUNIT_TEST(test_Set_Instr1);
	CPPUNIT_TEST(test_Set_Instr2);
	CPPUNIT_TEST(test_Set_Instr3);




    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
