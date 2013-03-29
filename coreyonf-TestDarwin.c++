// --------------------------------
// projects/voting/TestDarwin.c++
// Copyright (C) 2013
// cmbes
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

    // ----
    // Game
    // ----

		
		/**Baseline test**/
    void test_game_1 () {
    	try {
			Game darwin(1,1);
		} catch (...) {
			CPPUNIT_ASSERT(false);
		}
        CPPUNIT_ASSERT(true);
	}
	
	void test_game_2 () {
    	try {
			Game darwin(1,10);
		} catch (...) {
			CPPUNIT_ASSERT(false);
		}
        CPPUNIT_ASSERT(true);
	}
	
	void test_game_3 () {
    	try {
			Game darwin(-100,100);
			CPPUNIT_ASSERT(false);
		} catch (...) {
        	CPPUNIT_ASSERT(true);
		}
	}
	
	void test_game_4 () {
    	Game darwin(1,1);
		CPPUNIT_ASSERT(darwin._species.size() == 5);
	}
	
	void test_game_5 () {
    	Game darwin(1,1);
		CPPUNIT_ASSERT(darwin._board.size() == 1);
	}
	
	void test_game_6 () {
    	Game darwin(1,1);
		CPPUNIT_ASSERT(darwin._board.at(0).size() == 1);
	}
	
	
	//test instruction
	void test_instruction_1() {
		Instruction i(go, 1);
		CPPUNIT_ASSERT(i.code() == go);
	}
	
	void test_instruction_2() {
		Instruction i(go, 1);
		CPPUNIT_ASSERT(i.target() == 1);
	}
	
	void test_instruction_3() {
		Instruction i(hop, -1);
		CPPUNIT_ASSERT(i.target() == -1);
	}
	
	//TEST SPECIES
	
	void test_species_1 () {
    	Species s(HOPPER);
    	CPPUNIT_ASSERT(s.type() == HOPPER);
	}
	
	void test_species_2 () {
    	Species s(HOPPER);
    	s.addInstruction(go, 0);
    	CPPUNIT_ASSERT(s.getLine(0).target() == 0);
	}
	
	void test_species_3 () {
    	Species s(HOPPER);
    	s.addInstruction(hop, -1);
    	CPPUNIT_ASSERT(s.getLine(0).code() == hop);
	}
	
	//TEST CREATURE
	
	void test_creature_1() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(true);
	}
	
	void test_creature_2() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.pos() == 1);
	}
	
	void test_creature_3() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.dir() == LEFT);
	}
	
	void test_creature_4() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.type() == HOPPER);
	}
	
	void test_creature_5() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.dir() == LEFT);
		c.left();
		CPPUNIT_ASSERT(c.dir() == DOWN);
	}
	
	void test_creature_6() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.dir() == LEFT);
		c.right();
		CPPUNIT_ASSERT(c.dir() == UP);
	}
	
	void test_creature_7() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.dir() == LEFT);
		c.turn(1);
		CPPUNIT_ASSERT(c.dir() == UP);
	}
	
	void test_creature_8() {
		Game darwin(1,1);
		Species s(HOPPER);
		Creature c(&s, LEFT,1,1, &darwin);
		CPPUNIT_ASSERT(c.dir() == LEFT);
		c.turn(0);
		CPPUNIT_ASSERT(c.dir() == DOWN);
	}
	
	void test_creature_9() {
		Game darwin(1,1);
		Species s(HOPPER);
		Species r(ROVER);
		Creature c(&s, LEFT,1,1, &darwin);
		c.infect(&r);
		CPPUNIT_ASSERT(c.type() == ROVER);
	}
	
	void test_creature_10() {
		Game darwin(1,1);
		Species s(HOPPER);
		Species r(BEST);
		Creature c(&s, LEFT,1,1, &darwin);
		c.infect(&r);
		CPPUNIT_ASSERT(c.type() == BEST);
	}
	
	//test hop and run
	void test_creature_11() {
		Game darwin(2,2);
		darwin.addCreature(HOPPER, 1, 1, UP);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(0).at(1) == 1);
		CPPUNIT_ASSERT(darwin._board.at(1).at(1) == 0);
	}
	
	//test hopping into walls
	void test_creature_13() {
		Game darwin(2,2);
		darwin.addCreature(HOPPER, 0, 1, UP);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(0).at(1) == 1);
	}
	
	//test hopping into walls
	void test_creature_14() {
		Game darwin(2,2);
		darwin.addCreature(HOPPER, 1, 1, DOWN);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(1).at(1) == 1);
	}
	
	//test hopping into walls
	void test_creature_15() {
		Game darwin(2,2);
		darwin.addCreature(HOPPER, 0, 0, LEFT);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(0).at(0) == 1);
	}
	
	//test hopping into walls
	void test_creature_16() {
		Game darwin(2,2);
		darwin.addCreature(HOPPER, 0, 1, RIGHT);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(0).at(1) == 1);
	}
	
	
	//test infect
	void test_creature_12() {
		Game darwin(2,2);
		darwin.addCreature(ROVER, 1, 0, RIGHT);
		darwin.addCreature(HOPPER, 1, 1, UP);
		darwin.run(1, -1);
		CPPUNIT_ASSERT(darwin._board.at(0).at(1) == 2);
		CPPUNIT_ASSERT(darwin._creatures.at(darwin._board.at(0).at(1)).type() == ROVER);
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_game_1);
    CPPUNIT_TEST(test_game_2);
    CPPUNIT_TEST(test_game_3);
    CPPUNIT_TEST(test_game_4);
    CPPUNIT_TEST(test_game_5);
    CPPUNIT_TEST(test_game_6);
    CPPUNIT_TEST(test_instruction_1);
    CPPUNIT_TEST(test_instruction_2);
    CPPUNIT_TEST(test_instruction_3);
    CPPUNIT_TEST(test_species_1);
    CPPUNIT_TEST(test_species_2);
    CPPUNIT_TEST(test_species_3);
    CPPUNIT_TEST(test_creature_1);
    CPPUNIT_TEST(test_creature_2);
    CPPUNIT_TEST(test_creature_3);
    CPPUNIT_TEST(test_creature_4);
    CPPUNIT_TEST(test_creature_5);
    CPPUNIT_TEST(test_creature_6);
    CPPUNIT_TEST(test_creature_7);
    CPPUNIT_TEST(test_creature_8);
    CPPUNIT_TEST(test_creature_9);
    CPPUNIT_TEST(test_creature_10);
    CPPUNIT_TEST(test_creature_11);
    CPPUNIT_TEST(test_creature_12);
    CPPUNIT_TEST(test_creature_13);
    CPPUNIT_TEST(test_creature_14);
    CPPUNIT_TEST(test_creature_15);
    CPPUNIT_TEST(test_creature_16);
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
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
