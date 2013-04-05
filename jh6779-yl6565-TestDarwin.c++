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
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <sstream>
#include <string>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {

    // ---------
    // test_food
    // ---------

    void test_food () {
      Creature c = Creature("Food",SOUTH);
      CPPUNIT_ASSERT(c._can_move);
      CPPUNIT_ASSERT(c._name == "Food");
      CPPUNIT_ASSERT(c._d == SOUTH);
      CPPUNIT_ASSERT(c._inst[0].first == left);
      CPPUNIT_ASSERT(c._inst[1].first == go);
      CPPUNIT_ASSERT(c._inst[1].second == 0);}

    // -----------
    // test_hopper
    // -----------

    void test_hopper () {
      Creature c = Creature("Hopper",NORTH);
      CPPUNIT_ASSERT(c._can_move);
      CPPUNIT_ASSERT(c._name == "Hopper");
      CPPUNIT_ASSERT(c._d == NORTH);
      CPPUNIT_ASSERT(c._inst[0].first == hop);
      CPPUNIT_ASSERT(c._inst[1].first == go);
      CPPUNIT_ASSERT(c._inst[1].second == 0);}

    // ----------
    // test_rover
    // ----------

    void test_rover () {
      Creature c = Creature("Rover",EAST);
      CPPUNIT_ASSERT(c._can_move);
      CPPUNIT_ASSERT(c._name == "Rover");
      CPPUNIT_ASSERT(c._d == EAST);
      CPPUNIT_ASSERT(c._inst[0].first == if_enemy);
      CPPUNIT_ASSERT(c._inst[0].second == 9);
      CPPUNIT_ASSERT(c._inst[1].first == if_empty);
      CPPUNIT_ASSERT(c._inst[1].second == 7);
      CPPUNIT_ASSERT(c._inst[2].first == if_random);
      CPPUNIT_ASSERT(c._inst[2].second == 5);
      CPPUNIT_ASSERT(c._inst[3].first == left);
      CPPUNIT_ASSERT(c._inst[4].first == go);
      CPPUNIT_ASSERT(c._inst[4].second == 0);
      CPPUNIT_ASSERT(c._inst[5].first == right);
      CPPUNIT_ASSERT(c._inst[6].first == go);
      CPPUNIT_ASSERT(c._inst[6].second == 0);
      CPPUNIT_ASSERT(c._inst[7].first == hop);
      CPPUNIT_ASSERT(c._inst[8].first == go);
      CPPUNIT_ASSERT(c._inst[8].second == 0);
      CPPUNIT_ASSERT(c._inst[9].first == infect);
      CPPUNIT_ASSERT(c._inst[10].first == go);
      CPPUNIT_ASSERT(c._inst[10].second == 0);}

    // ---------
    // test_trap
    // ---------

    void test_trap () {
      Creature c = Creature("Trap",WEST);
      CPPUNIT_ASSERT(c._can_move);
      CPPUNIT_ASSERT(c._name == "Trap");
      CPPUNIT_ASSERT(c._d == WEST);
      CPPUNIT_ASSERT(c._inst[0].first == if_enemy);
      CPPUNIT_ASSERT(c._inst[0].second == 3);
      CPPUNIT_ASSERT(c._inst[1].first == left);
      CPPUNIT_ASSERT(c._inst[2].first == go);
      CPPUNIT_ASSERT(c._inst[2].second == 0);
      CPPUNIT_ASSERT(c._inst[3].first == infect);
      CPPUNIT_ASSERT(c._inst[4].first == go);
      CPPUNIT_ASSERT(c._inst[4].second == 0);}
      
    // ----------
    // test_name1
    // ----------
    
    void test_name1 () {
      Creature c = Creature("Food", NORTH);
      CPPUNIT_ASSERT(c._name == "Food");
      CPPUNIT_ASSERT(c.name() == "Food");}
      
    // ----------
    // test_name2
    // ----------
    
    void test_name2 () {
      Creature c = Creature("Hopper", EAST);
      c._name = "Rover";
      CPPUNIT_ASSERT(c._name == "Rover");
      CPPUNIT_ASSERT(c.name() == "Rover");}
      
    // ----------
    // test_name3
    // ----------
    
    void test_name3 () {
      Creature c = Creature("Rover", SOUTH);
      c._name = "Hopper";
      c._name = "Rover";
      CPPUNIT_ASSERT(c._name == "Rover");
      CPPUNIT_ASSERT(c.name() == "Rover");}

    // ---------------
    // test_direction1
    // ---------------
    
    void test_direction1 () {
      Creature c = Creature("Food", NORTH);
      CPPUNIT_ASSERT(c._d == NORTH);
      CPPUNIT_ASSERT(c.direction() == NORTH);}  

    // ---------------
    // test_direction2
    // ---------------
    
    void test_direction2 () {
      Creature c = Creature("Trap", EAST);
      c._d = WEST;
      CPPUNIT_ASSERT(c._d == WEST);
      CPPUNIT_ASSERT(c.direction() == WEST);} 

    // ---------------
    // test_direction3
    // ---------------
    
    void test_direction3 () {
      Creature c = Creature("Rover", NORTH);
      c._d = WEST;
      c._d = EAST;
      CPPUNIT_ASSERT(c._d == EAST);
      CPPUNIT_ASSERT(c.direction() == EAST);}
    
    // ----------
    // test_copy1
    // ----------
    
    void test_copy1 () {
      Creature c1 = Creature("Food", NORTH);
      c1._pc = 3;
      CPPUNIT_ASSERT(c1._name == "Food");
      CPPUNIT_ASSERT(c1._d == NORTH);
      CPPUNIT_ASSERT(c1._pc == 3);
      CPPUNIT_ASSERT(c1._inst.size() == 2);
      
      Creature c2 = Creature("Rover", EAST);
      c2._pc = 4;
      CPPUNIT_ASSERT(c2._name == "Rover");
      CPPUNIT_ASSERT(c2._d == EAST);
      CPPUNIT_ASSERT(c2._pc == 4);
      CPPUNIT_ASSERT(c2._inst.size() == 11);
      
      c1.copy(c2);
      CPPUNIT_ASSERT(c1._name == "Food");
      CPPUNIT_ASSERT(c1._d == NORTH);
      CPPUNIT_ASSERT(c1._pc == 3);
      CPPUNIT_ASSERT(c1._inst.size() == 2);
      
      CPPUNIT_ASSERT(c2._name == "Food");
      CPPUNIT_ASSERT(c2._d == EAST);
      CPPUNIT_ASSERT(c2._pc == 0);
      CPPUNIT_ASSERT(c2._inst.size() == 2);
      
      CPPUNIT_ASSERT(c1._inst[0] == c2._inst[0]);
      CPPUNIT_ASSERT(c1._inst[1] == c2._inst[1]);}
    
    // ----------
    // test_copy2
    // ----------
    
    void test_copy2 () {
      Creature c1 = Creature("Rover", WEST);
      c1._pc = 4;
      CPPUNIT_ASSERT(c1._name == "Rover");
      CPPUNIT_ASSERT(c1._d == WEST);
      CPPUNIT_ASSERT(c1._pc == 4);
      CPPUNIT_ASSERT(c1._inst.size() == 11);
      
      Creature c2 = Creature("Hopper", SOUTH);
      c2._pc = 7;
      CPPUNIT_ASSERT(c2._name == "Hopper");
      CPPUNIT_ASSERT(c2._d == SOUTH);
      CPPUNIT_ASSERT(c2._pc == 7);
      CPPUNIT_ASSERT(c2._inst.size() == 2);
      
      c1.copy(c2);
      CPPUNIT_ASSERT(c1._name == "Rover");
      CPPUNIT_ASSERT(c1._d == WEST);
      CPPUNIT_ASSERT(c1._pc == 4);
      CPPUNIT_ASSERT(c1._inst.size() == 11);
      
      CPPUNIT_ASSERT(c2._name == "Rover");
      CPPUNIT_ASSERT(c2._d == SOUTH);
      CPPUNIT_ASSERT(c2._pc == 0);
      CPPUNIT_ASSERT(c2._inst.size() == 11);
      
      CPPUNIT_ASSERT(c1._inst[0] == c2._inst[0]);
      CPPUNIT_ASSERT(c1._inst[1] == c2._inst[1]);
      CPPUNIT_ASSERT(c1._inst[2] == c2._inst[2]);
      CPPUNIT_ASSERT(c1._inst[3] == c2._inst[3]);
      CPPUNIT_ASSERT(c1._inst[4] == c2._inst[4]);
      CPPUNIT_ASSERT(c1._inst[5] == c2._inst[5]);
      CPPUNIT_ASSERT(c1._inst[6] == c2._inst[6]);
      CPPUNIT_ASSERT(c1._inst[7] == c2._inst[7]);
      CPPUNIT_ASSERT(c1._inst[8] == c2._inst[8]);
      CPPUNIT_ASSERT(c1._inst[9] == c2._inst[9]);
      CPPUNIT_ASSERT(c1._inst[10] == c2._inst[10]);}
    
    // ----------
    // test_copy3
    // ----------
    
    void test_copy3 () {
      Creature c1 = Creature("Hopper", WEST);
      c1._pc = 10;
      CPPUNIT_ASSERT(c1._name == "Hopper");
      CPPUNIT_ASSERT(c1._d == WEST);
      CPPUNIT_ASSERT(c1._pc == 10);
      CPPUNIT_ASSERT(c1._inst.size() == 2);
      
      Creature c2 = Creature("Food", NORTH);
      c2._pc = 4;
      CPPUNIT_ASSERT(c2._name == "Food");
      CPPUNIT_ASSERT(c2._d == NORTH);
      CPPUNIT_ASSERT(c2._pc == 4);
      CPPUNIT_ASSERT(c2._inst.size() == 2);
      
      c1.copy(c2);
      CPPUNIT_ASSERT(c1._name == "Hopper");
      CPPUNIT_ASSERT(c1._d == WEST);
      CPPUNIT_ASSERT(c1._pc == 10);
      CPPUNIT_ASSERT(c1._inst.size() == 2);
      
      CPPUNIT_ASSERT(c2._name == "Hopper");
      CPPUNIT_ASSERT(c2._d == NORTH);
      CPPUNIT_ASSERT(c2._pc == 0);
      CPPUNIT_ASSERT(c2._inst.size() == 2);
      
      CPPUNIT_ASSERT(c1._inst[0] == c2._inst[0]);
      CPPUNIT_ASSERT(c1._inst[1] == c2._inst[1]);}
      
    // -----------
    // test_reset1
    // -----------
    
    void test_reset1 () {
      Creature c = Creature("Rover", NORTH);
      CPPUNIT_ASSERT(c._can_move);
      c._can_move = false;
      CPPUNIT_ASSERT(!c._can_move);
      c.reset();
      CPPUNIT_ASSERT(c._can_move);}
      
    // -----------
    // test_reset2
    // -----------
    
    void test_reset2 () {
      Creature c = Creature("Hopper", NORTH);
      CPPUNIT_ASSERT(c._can_move);
      c._can_move = false;
      CPPUNIT_ASSERT(!c._can_move);
      c.reset();
      c.reset();
      CPPUNIT_ASSERT(c._can_move);}
      
    // -----------
    // test_reset3
    // -----------
    
    void test_reset3 () {
      Creature c1 = Creature("Food", NORTH);
      Creature c2 = Creature("Hopper", NORTH);
      Creature c3 = Creature("Rover", NORTH);
      CPPUNIT_ASSERT(c1._can_move);
      CPPUNIT_ASSERT(c2._can_move);
      CPPUNIT_ASSERT(c3._can_move);
      c1._can_move = false;
      c3._can_move = false;
      CPPUNIT_ASSERT(!c1._can_move);
      CPPUNIT_ASSERT(c2._can_move);
      CPPUNIT_ASSERT(!c3._can_move);
      c1.reset();
      CPPUNIT_ASSERT(c1._can_move);
      CPPUNIT_ASSERT(c2._can_move);
      CPPUNIT_ASSERT(!c3._can_move);
      c2._can_move = false;
      c3.reset();
      CPPUNIT_ASSERT(c1._can_move);
      CPPUNIT_ASSERT(!c2._can_move);
      CPPUNIT_ASSERT(c3._can_move);
      c2.reset();
      c2.reset();
      CPPUNIT_ASSERT(c1._can_move);
      CPPUNIT_ASSERT(c2._can_move);
      CPPUNIT_ASSERT(c3._can_move);}
      
    // --------------
    // test_can_move1
    // --------------
    
    void test_can_move1 () {
      Creature c = Creature("Hopper",SOUTH);
      CPPUNIT_ASSERT(c.can_move());
      c._can_move = false;
      CPPUNIT_ASSERT(!c.can_move());
      c.reset();
      CPPUNIT_ASSERT(c.can_move());}
      
    // --------------
    // test_can_move2
    // --------------
    
    void test_can_move2 () {
      Creature c = Creature("Trap",EAST);
      CPPUNIT_ASSERT(c.can_move());
      c._can_move = false;
      CPPUNIT_ASSERT(!c.can_move());
      c.reset();
      CPPUNIT_ASSERT(c.can_move());}
      
    // --------------
    // test_can_move3
    // --------------
    
    void test_can_move3 () {
      Creature c = Creature("Rover",NORTH);
      CPPUNIT_ASSERT(c.can_move());
      c._can_move = false;
      CPPUNIT_ASSERT(!c.can_move());
      c.reset();
      CPPUNIT_ASSERT(c.can_move());}
      
    // ------------
    // test_passed1
    // ------------
    
    void test_passed1 () {
      Creature c = Creature("Trap", NORTH);
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c._pass_pc == 0);
      c._pass_pc = 2;
      CPPUNIT_ASSERT(c._pass_pc == 2);
      c.passed();
      CPPUNIT_ASSERT(c._pc == 2);
      CPPUNIT_ASSERT(c._pass_pc == 2);}
      
    // ------------
    // test_passed2
    // ------------
    
    void test_passed2 () {
      Creature c = Creature("Rover", SOUTH);
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c._pass_pc == 0);
      c._pass_pc = 2;
      c.passed();
      c._pass_pc = 100;
      c.passed();
      c._pass_pc = 1;
      c.passed();
      CPPUNIT_ASSERT(c._pc == 1);
      CPPUNIT_ASSERT(c._pass_pc == 1);}
      
    // ------------
    // test_passed3
    // ------------
    
    void test_passed3 () {
      Creature c = Creature("Food", EAST);
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c._pass_pc == 0);
      c._pc = 2;
      CPPUNIT_ASSERT(c._pc == 2);
      c.passed();
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c._pass_pc == 0);}
      
    // ----------
    // test_next1
    // ----------
    
    void test_next1 () {
      Creature c = Creature("Food", NORTH);
      Instruction temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 1);
      CPPUNIT_ASSERT(!c.can_move());
      c.reset();
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 0);}
      
    // ----------
    // test_next2
    // ----------
    
    void test_next2 () {
      Creature c = Creature("Rover", WEST);
      Instruction temp = c.next();
      CPPUNIT_ASSERT(temp.first == if_enemy);
      CPPUNIT_ASSERT(temp.second == 9);
      CPPUNIT_ASSERT(c._pc == 1);
      CPPUNIT_ASSERT(c.can_move());
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == if_empty);
      CPPUNIT_ASSERT(temp.second == 7);
      CPPUNIT_ASSERT(c._pc == 2);
      CPPUNIT_ASSERT(c.can_move());
      
      c.passed();
      CPPUNIT_ASSERT(c._pc == 7);
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == hop);
      CPPUNIT_ASSERT(c._pc == 8);
      CPPUNIT_ASSERT(!c.can_move());}
      
    // ----------
    // test_next3
    // ----------
    
    void test_next3 () {
      Creature c = Creature("Trap", EAST);
      Instruction temp = c.next();
      CPPUNIT_ASSERT(temp.first == if_enemy);
      CPPUNIT_ASSERT(c._pc == 1);
      CPPUNIT_ASSERT(c.can_move());
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 2);
      CPPUNIT_ASSERT(!c.can_move());
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 2);
      CPPUNIT_ASSERT(!c.can_move());
      
      c.reset();
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c.can_move());
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == if_enemy);
      CPPUNIT_ASSERT(c._pc == 1);
      CPPUNIT_ASSERT(c.can_move());
      
      c.passed();
      CPPUNIT_ASSERT(c._pc == 3);
      CPPUNIT_ASSERT(c.can_move());
      
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == infect);
      CPPUNIT_ASSERT(c._pc == 4);
      CPPUNIT_ASSERT(!c.can_move());
      
      c.reset();
      temp = c.next();
      CPPUNIT_ASSERT(temp.first == noop);
      CPPUNIT_ASSERT(c._pc == 0);
      CPPUNIT_ASSERT(c.can_move());}

    // -------------------
    // test_gameconstruct1
    // -------------------
	void test_gameconstruct1(){
		Game g = Game(5,5);
		CPPUNIT_ASSERT(g.empty(0,0));
		CPPUNIT_ASSERT(g.empty(4,4));
		CPPUNIT_ASSERT(g.empty(0,4));
		CPPUNIT_ASSERT(g.empty(4,0));
	}

    // -------------------
    // test_gameconstruct2
    // -------------------
	void test_gameconstruct2(){
		Game g = Game(10,5);
		CPPUNIT_ASSERT(g.empty(0,0));
		CPPUNIT_ASSERT(g.empty(9,4));
		CPPUNIT_ASSERT(g.empty(0,4));
		CPPUNIT_ASSERT(g.empty(9,0));
	}

    // -------------------
    // test_gameconstruct3
    // -------------------
	void test_gameconstruct3(){
		Game g = Game(1,1);
		CPPUNIT_ASSERT(g.empty(0,0));
	}

	// -------------------
    // test_gameadd1
    // -------------------
	void test_gameadd1(){
		Game g = Game(5,5);
		g.add("Food", NORTH,2,2);
		g.add("Hopper", SOUTH,0,0);
		CPPUNIT_ASSERT(g._map[2][2] == 0);
		CPPUNIT_ASSERT(g._map[0][0] == 1);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Food");
		CPPUNIT_ASSERT(g._creatures[0]._d == 0);
		CPPUNIT_ASSERT(g._creatures[1]._name == "Hopper");
		CPPUNIT_ASSERT(g._creatures[1]._d == 2);
	}

	// -------------------
    // test_gameadd2
    // -------------------
	void test_gameadd2(){
		Game g = Game(5,5);
		g.add("Trap", WEST,4,4);
		CPPUNIT_ASSERT(g._map[4][4] == 0);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Trap");
		CPPUNIT_ASSERT(g._creatures[0]._d == 3);
	}

	// -------------------
    // test_gameadd3
    // -------------------
	void test_gameadd3(){
		Game g = Game(5,5);
		g.add("Rover", NORTH,4,4);
		g.add("Trap", SOUTH,0,0);
		CPPUNIT_ASSERT(g._map[4][4] == 0);
		CPPUNIT_ASSERT(g._map[0][0] == 1);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Rover");
		CPPUNIT_ASSERT(g._creatures[0]._d == 0);
		CPPUNIT_ASSERT(g._creatures[1]._name == "Trap");
		CPPUNIT_ASSERT(g._creatures[1]._d == 2);
	}

	// -------------------
    // test_gamerun1
    // -------------------
	void test_gamerun1(){
		std::stringstream s;
		Game g = Game(5,5);
		g.add("Food", NORTH,2,2);
		g.add("Hopper", SOUTH,0,0);
		g.run(s,1,100);
		CPPUNIT_ASSERT(g._map[2][2] == 0);
		CPPUNIT_ASSERT(g._map[1][0] == 1);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Food");
		CPPUNIT_ASSERT(g._creatures[0]._d == 3);
		CPPUNIT_ASSERT(g._creatures[1]._name == "Hopper");
		CPPUNIT_ASSERT(g._creatures[1]._d == 2);
	}

	// -------------------
    // test_gamerun2
    // -------------------
	void test_gamerun2(){
		Game g = Game(5,5);
		std::stringstream s;
		g.add("Trap", WEST,4,4);
		g.run(s,1,100);
		CPPUNIT_ASSERT(g._map[4][4] == 0);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Trap");
		CPPUNIT_ASSERT(g._creatures[0]._d == SOUTH);
	}

	// -------------------
    // test_gamerun3
    // -------------------
	void test_gamerun3(){
		Game g = Game(5,5);
		std::stringstream s;
		g.add("Hopper", NORTH,4,0);
		g.add("Trap", SOUTH,0,0);
		g.run(s,50,100);
		CPPUNIT_ASSERT(g._map[1][0] == 0);
		CPPUNIT_ASSERT(g._map[0][0] == 1);
		CPPUNIT_ASSERT(g._creatures[0]._name == "Trap");
		CPPUNIT_ASSERT(g._creatures[1]._name == "Trap");
	}
	// -------------------
    // test_gameprint1
    // -------------------
	void test_gameprint1(){
		Game g1 = Game(5,5);
		Game g2 = Game(5,5);
		g1.add("Food", NORTH,2,2);
		g1.add("Hopper", SOUTH,0,0);
		std::stringstream s1;
		std::stringstream s2;
		g2._map[2][2] = 0;
		g2._map[0][0] = 1;
		g2._creatures.push_back(Creature("Food", 0));
		g2._creatures.push_back(Creature("Hopper", 2));
		g1.print(s1, 0);
		g2.print(s2, 0);
		CPPUNIT_ASSERT(s2.str() == s1.str());
	}

	// -------------------
    // test_gameprint2
    // -------------------
	void test_gameprint2(){
		Game g1 = Game(5,5);
		Game g2 = Game(5,5);
		g1.add("Trap", WEST,4,4);
		g2._map[4][4] = 0;
		g2._creatures.push_back(Creature("Trap", 0));
		std::stringstream s1;
		std::stringstream s2;
		g1.print(s1, 0);
		g2.print(s2, 0);
		CPPUNIT_ASSERT(s1.str() == s2.str());
	}

	// -------------------
    // test_gameprint3
    // -------------------
	void test_gameprint3(){
		Game g1 = Game(5,5);
		Game g2 = Game(5,5);
		g1.add("Rover", NORTH,4,4);
		g1.add("Trap", SOUTH,0,0);
		g2._map[4][4] = 0;
		g2._map[0][0] = 1;
		g2._creatures.push_back(Creature("Rover", 0));
		g2._creatures.push_back(Creature("Trap", 0));
		std::stringstream s1;
		std::stringstream s2;
		g1.print(s1, 0);
		g2.print(s2, 0);
		CPPUNIT_ASSERT(s1.str() == s2.str());
	}

	// -------------------
    // test_gameempty1
    // -------------------
	void test_gameempty1(){
		Game g = Game(5,5);
		g.add("Food", NORTH, 0, 0);
		CPPUNIT_ASSERT(!g.empty(0,0));
	}

	// -------------------
    // test_gameempty2
    // -------------------
	void test_gameempty2(){
		Game g = Game(1,1);
		CPPUNIT_ASSERT(g.empty(0,0));
	}

	// -------------------
    // test_gameempty3
    // -------------------
	void test_gameempty3(){
		Game g = Game(100,100);
		CPPUNIT_ASSERT(g.empty(99,99));
	}

	// -------------------
    // test_gameinfront1
    // -------------------
	void test_gameinfront1(){
		Game g = Game(5,5);
		g.add("Food", NORTH, 0, 0);
		CPPUNIT_ASSERT(g.inFront(g._creatures[0],0,0) == (std::pair<int,int>(0,0)));
	}

	// -------------------
    // test_gameinfront2
    // -------------------
	void test_gameinfront2(){
		Game g = Game(5,5);
		g.add("Food", WEST, 3, 3);
		CPPUNIT_ASSERT((g.inFront(g._creatures[0],3,3) == std::pair<int,int>(3,2)));
	}

	// -------------------
    // test_gameinfront3
    // -------------------
	void test_gameinfront3(){
		Game g = Game(5,5);
		g.add("Food", SOUTH, 0, 0);
		CPPUNIT_ASSERT(g.inFront(g._creatures[0],0,0) == (std::pair<int,int>(1,0)));
	}
   
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_food);
    CPPUNIT_TEST(test_hopper);
    CPPUNIT_TEST(test_rover);
    CPPUNIT_TEST(test_trap);
    CPPUNIT_TEST(test_name1);
    CPPUNIT_TEST(test_name2);
    CPPUNIT_TEST(test_name3);
    CPPUNIT_TEST(test_direction1);
    CPPUNIT_TEST(test_direction2);
    CPPUNIT_TEST(test_direction3);
    CPPUNIT_TEST(test_copy1);
    CPPUNIT_TEST(test_copy2);
    CPPUNIT_TEST(test_copy3);
    CPPUNIT_TEST(test_reset1);
    CPPUNIT_TEST(test_reset2);
    CPPUNIT_TEST(test_reset3);
    CPPUNIT_TEST(test_can_move1);
    CPPUNIT_TEST(test_can_move2);
    CPPUNIT_TEST(test_can_move3);
    CPPUNIT_TEST(test_passed1);
    CPPUNIT_TEST(test_passed2);
    CPPUNIT_TEST(test_passed3);
    CPPUNIT_TEST(test_next1);
    CPPUNIT_TEST(test_next2);
    CPPUNIT_TEST(test_next3);
	CPPUNIT_TEST(test_gameconstruct1);
	CPPUNIT_TEST(test_gameconstruct2);
	CPPUNIT_TEST(test_gameconstruct2);
	CPPUNIT_TEST(test_gameadd1);
	CPPUNIT_TEST(test_gameadd2);
	CPPUNIT_TEST(test_gameadd3);
	CPPUNIT_TEST(test_gamerun1);
	CPPUNIT_TEST(test_gamerun2);
	CPPUNIT_TEST(test_gamerun3);
	CPPUNIT_TEST(test_gameprint1);
	CPPUNIT_TEST(test_gameprint2);
	CPPUNIT_TEST(test_gameprint3);
	CPPUNIT_TEST(test_gameempty1);
	CPPUNIT_TEST(test_gameempty2);
	CPPUNIT_TEST(test_gameempty3);
	CPPUNIT_TEST(test_gameinfront1);
	CPPUNIT_TEST(test_gameinfront2);
	CPPUNIT_TEST(test_gameinfront3);
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
