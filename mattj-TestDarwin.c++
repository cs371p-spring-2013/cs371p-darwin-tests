// ----------------------------
// projects/darwin/TestDarwin.c++
// Matt A. Johnson
// ----------------------------

//Based on Glenn P. Downing's TestCollatz.c++ file


/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl
% valgrind TestCollatz >& TestCollatz.out
*/

// --------
// includes
// --------

#define private public
#define protected public
//#define class struct

#include <iostream> // cout, endl, ios_base
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "Darwin.h"



// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
    // ----
    // species_turnRQ
    // ----

    void test_species_turnRQ_1 () {
        Species s = Species();
        int counter = 4;
        CPPUNIT_ASSERT(s.turnRequest(6, counter) == 0);
        CPPUNIT_ASSERT(counter == 4);
    }
    
    void test_species_turnRQ_2 () {
        Species s = Species();
        int counter = 66;
        CPPUNIT_ASSERT(s.turnRequest(6, counter) == 0);
        CPPUNIT_ASSERT(counter == 66);
    }
    
    void test_species_turnRQ_3 () {
        Species s = Species();
        int counter = 3434;
        CPPUNIT_ASSERT(s.turnRequest(6, counter) == 0);
        CPPUNIT_ASSERT(counter == 3434);
    }
    
    void test_species_visual_1 () {
        Species s = Species();
        CPPUNIT_ASSERT(s.visual() == 'S');
    }
    
    void test_species_visual_2 () {
        Species s1 = Species();
        CPPUNIT_ASSERT(s1.visual() == 'S');
    }
    
    void test_species_visual_3 () {
        Species s2 = Species();
        CPPUNIT_ASSERT(s2.visual() == 'S');
    }
    
    void test_species_equal_1 () {
        Species s1 = Species();
        Species s2 = Species();
        CPPUNIT_ASSERT(!(s1 == s2));
    }
    
    void test_species_equal_2 () {
        Species s3 = Species();
        Species s4 = Species();
        CPPUNIT_ASSERT(!(s3 == s4));
    }
    
    void test_species_equal_3 () {
        Species s11 = Species();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(s11 == s22));
    }
    
    void test_food_turnRQ_1 () {
        Food f = Food();
        int counter = 0;
        CPPUNIT_ASSERT(f.turnRequest(INFO_UNSET, counter) == LEFT);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_food_turnRQ_2 () {
        Food f = Food();
        int counter = 1;
        CPPUNIT_ASSERT(f.turnRequest(INFO_UNSET, counter) == LEFT);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_food_turnRQ_3 () {
        Food f = Food();
        int counter = 0;
        CPPUNIT_ASSERT(f.turnRequest(INFO_UNSET, counter) == LEFT);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_food_visual_1 () {
        Food f = Food();
        CPPUNIT_ASSERT(f.visual() == 'f');
    }
    
    void test_food_visual_2 () {
        Food f1 = Food();
        CPPUNIT_ASSERT(f1.visual() == 'f');
    }
    
    void test_food_visual_3 () {
        Food f2 = Food();
        CPPUNIT_ASSERT(f2.visual() == 'f');
    }
    
    void test_food_equal_1 () {
        Food f1 = Food();
        Food f2 = Food();
        CPPUNIT_ASSERT(f1 == f2);
    }
    
    void test_food_equal_2 () {
        Food f1 = Food();
        Trap t1 = Trap();
        CPPUNIT_ASSERT(!(f1 == t1));
    }
    
    void test_food_equal_3 () {
        Food f1 = Food();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(f1 == s22));
    }
    
    void test_hopper_turnRQ_1 () {
        Hopper h = Hopper();
        int counter = 0;
        CPPUNIT_ASSERT(h.turnRequest(INFO_UNSET, counter) == HOP);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_hopper_turnRQ_2 () {
        Hopper h = Hopper();
        int counter = 1;
        CPPUNIT_ASSERT(h.turnRequest(INFO_UNSET, counter) == HOP);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_hopper_turnRQ_3 () {
        Hopper h = Hopper();
        int counter = 0;
        CPPUNIT_ASSERT(h.turnRequest(INFO_UNSET, counter) == HOP);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_hopper_visual_1 () {
        Hopper h = Hopper();
        CPPUNIT_ASSERT(h.visual() == 'h');
    }
    
    void test_hopper_visual_2 () {
        Hopper h1 = Hopper();
        CPPUNIT_ASSERT(h1.visual() == 'h');
    }
    
    void test_hopper_visual_3 () {
        Hopper h2 = Hopper();
        CPPUNIT_ASSERT(h2.visual() == 'h');
    }
    
    void test_hopper_equal_1 () {
        Hopper h1 = Hopper();
        Hopper h2 = Hopper();
        CPPUNIT_ASSERT(h1 == h2);
    }
    
    void test_hopper_equal_2 () {
        Hopper h3 = Hopper();
        Trap t1 = Trap();
        CPPUNIT_ASSERT(!(h3 == t1));
    }
    
    void test_hopper_equal_3 () {
        Hopper h1 = Hopper();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(h1 == s22));
    }
    
    void test_rover_turnRQ_1 () {
        Rover r = Rover();
        int counter = 0;
        CPPUNIT_ASSERT(r.turnRequest(INFO_UNSET, counter) == IF_ENEMY);
        CPPUNIT_ASSERT(counter == 0);
    }
    
    void test_rover_turnRQ_2 () {
        Rover r = Rover();
        int counter = 0;
        CPPUNIT_ASSERT(r.turnRequest(INFO_TRUE, counter) == INFECT);
        CPPUNIT_ASSERT(counter == 10);
    }
    
    void test_rover_turnRQ_3 () {
        Rover r = Rover();
        int counter = 0;
        CPPUNIT_ASSERT(r.turnRequest(INFO_FALSE, counter) == IF_EMPTY);
        CPPUNIT_ASSERT(counter == 1);
    }
    
    void test_rover_visual_1 () {
        Rover r = Rover();
        CPPUNIT_ASSERT(r.visual() == 'r');
    }
    
    void test_rover_visual_2 () {
        Rover r1 = Rover();
        CPPUNIT_ASSERT(r1.visual() == 'r');
    }
    
    void test_rover_visual_3 () {
        Rover r2 = Rover();
        CPPUNIT_ASSERT(r2.visual() == 'r');
    }
    
    void test_rover_equal_1 () {
        Rover r1 = Rover();
        Rover r2 = Rover();
        CPPUNIT_ASSERT(r1 == r2);
    }
    
    void test_rover_equal_2 () {
        Rover r1 = Rover();
        Trap t1 = Trap();
        CPPUNIT_ASSERT(!(r1 == t1));
    }
    
    void test_rover_equal_3 () {
        Rover r1 = Rover();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(r1 == s22));
    }

    void test_trap_turnRQ_1 () {
        Trap t = Trap();
        int counter = 0;
        CPPUNIT_ASSERT(t.turnRequest(INFO_UNSET, counter) == IF_ENEMY);
        CPPUNIT_ASSERT(counter == 0);
    }
    
    void test_trap_turnRQ_2 () {
        Trap t = Trap();
        int counter = 0;
        CPPUNIT_ASSERT(t.turnRequest(INFO_TRUE, counter) == INFECT);
        CPPUNIT_ASSERT(counter == 4);
    }
    
    void test_trap_turnRQ_3 () {
        Trap t = Trap();
        int counter = 0;
        CPPUNIT_ASSERT(t.turnRequest(INFO_FALSE, counter) == LEFT);
        CPPUNIT_ASSERT(counter == 2);
    }
    
    void test_trap_visual_1 () {
        Trap t = Trap();
        CPPUNIT_ASSERT(t.visual() == 't');
    }
    
    void test_trap_visual_2 () {
        Trap t1 = Trap();
        CPPUNIT_ASSERT(t1.visual() == 't');
    }
    
    void test_trap_visual_3 () {
        Trap t2 = Trap();
        CPPUNIT_ASSERT(t2.visual() == 't');
    }
    
    void test_trap_equal_1 () {
        Trap t1 = Trap();
        Trap t2 = Trap();
        CPPUNIT_ASSERT(t1 == t2);
    }
    
    void test_trap_equal_2 () {
        Trap t1 = Trap();
        Food f1 = Food();
        CPPUNIT_ASSERT(!(t1 == f1));
    }
    
    void test_trap_equal_3 () {
        Trap t1 = Trap();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(t1 == s22));
    }
    
    
    
    
    void test_best_turnRQ_1 () {
        Best b = Best();
        int counter = 0;
        CPPUNIT_ASSERT(b.turnRequest(INFO_UNSET, counter) == IF_ENEMY);
        CPPUNIT_ASSERT(counter == 0);
    }
    
    void test_best_turnRQ_2 () {
        Best b = Best();
        int counter = 0;
        CPPUNIT_ASSERT(b.turnRequest(INFO_TRUE, counter) == INFECT);
        CPPUNIT_ASSERT(counter == 10);
    }
    
    void test_best_turnRQ_3 () {
        Best b = Best();
        int counter = 5;
        CPPUNIT_ASSERT(b.turnRequest(INFO_FALSE, counter) == RIGHT);
        CPPUNIT_ASSERT(counter == 6);
    }
    
    void test_best_visual_1 () {
        Best b = Best();
        CPPUNIT_ASSERT(b.visual() == 'b');
    }
    
    void test_best_visual_2 () {
        Best b1 = Best();
        CPPUNIT_ASSERT(b1.visual() == 'b');
    }
    
    void test_best_visual_3 () {
        Best b2 = Best();
        CPPUNIT_ASSERT(b2.visual() == 'b');
    }
    
    void test_best_equal_1 () {
        Best b1 = Best();
        Best b2 = Best();
        CPPUNIT_ASSERT(b1 == b2);
    }
    
    void test_best_equal_2 () {
        Best b = Best();
        Trap t = Trap();
        CPPUNIT_ASSERT(!(b == t));
    }
    
    void test_best_equal_3 () {
        Best b = Best();
        Species s22 = Species();
        CPPUNIT_ASSERT(!(b == s22));
    }
    
    
    void test_creature_constructor_1 () {
    	Food f = Food();
    	Creature c = Creature(f, NORTH);
    	CPPUNIT_ASSERT(c._counter == 0);
    	CPPUNIT_ASSERT(c._direction == NORTH);
    	CPPUNIT_ASSERT(*(c._s) == Food());
    }
    
    void test_creature_constructor_2 () {
    	Trap t = Trap();
    	Creature c = Creature(t, SOUTH);
    	CPPUNIT_ASSERT(c._counter == 0);
    	CPPUNIT_ASSERT(c._direction == SOUTH);
    	CPPUNIT_ASSERT(*(c._s) == Trap());
    }
    
    void test_creature_constructor_3 () {
    	Rover r = Rover();
    	Creature c = Creature(r, EAST);
    	CPPUNIT_ASSERT(c._counter == 0);
    	CPPUNIT_ASSERT(c._direction == EAST);
    	CPPUNIT_ASSERT(*(c._s) == Rover());
    }
    
    void test_creature_turnRQ_1 () {
    	Food f = Food();
    	Creature c = Creature(f, NORTH);
    	CPPUNIT_ASSERT(c.turnRequest(INFO_FALSE) == LEFT);
    	CPPUNIT_ASSERT(c._counter == 1);
    }
    
    void test_creature_turnRQ_2 () {
    	Trap t = Trap();
    	Creature c = Creature(t, SOUTH);
    	CPPUNIT_ASSERT(c.turnRequest(INFO_FALSE) == LEFT);
    	CPPUNIT_ASSERT(c._counter == 2);
    }
    
    void test_creature_turnRQ_3 () {
    	Rover r = Rover();
    	Creature c = Creature(r, EAST);
    	CPPUNIT_ASSERT(c.turnRequest(INFO_UNSET) == IF_ENEMY);
    	CPPUNIT_ASSERT(c._counter == 0);
    }
    
    void test_creature_share_1 () {
    	Food f1 = Food();
    	Food f2 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	Creature c2 = Creature(f2, NORTH);
    	CPPUNIT_ASSERT(c1.shareSpecies(c2));
    }
    
    void test_creature_share_2 () {
    	Food f1 = Food();
    	Food f2 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	Creature c2 = Creature(f2, SOUTH);
    	CPPUNIT_ASSERT(c1.shareSpecies(c2));
    }
    
    void test_creature_share_3 () {
    	Rover r = Rover();
    	Food f = Food();
    	Creature c1 = Creature(r, EAST);
    	Creature c2 = Creature(f, EAST);
    	CPPUNIT_ASSERT(!c1.shareSpecies(c2));
    }
    
    void test_creature_turn_1 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	c1.turn(RIGHT);
    	CPPUNIT_ASSERT(c1._direction == EAST);
    }
    
    void test_creature_turn_2 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, SOUTH);
    	c1.turn(LEFT);
    	CPPUNIT_ASSERT(c1._direction == EAST);
    }
    
    void test_creature_turn_3 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, WEST);
    	c1.turn(RIGHT);
    	CPPUNIT_ASSERT(c1._direction == NORTH);
    }
    
    void test_creature_direction_1 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	CPPUNIT_ASSERT(c1._direction == c1.getDirection());
    }
    
    void test_creature_direction_2 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, SOUTH);
    	CPPUNIT_ASSERT(c1._direction == c1.getDirection());
    }
    
    void test_creature_direction_3 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, WEST);
    	CPPUNIT_ASSERT(c1._direction == c1.getDirection());
    }
    
    void test_creature_infect_1 () {
    	Food f1 = Food();
    	Food f2 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	Creature c2 = Creature(f2, WEST);
    	c2.turnRequest(INFO_UNSET);
    	c1.infect(&c2);
    	CPPUNIT_ASSERT(*(c2._s) == Food());
    	CPPUNIT_ASSERT(c2._counter == 0);
    	CPPUNIT_ASSERT(c2._direction == WEST);
    }
    
    void test_creature_infect_2 () {
    	Food f1 = Food();
    	Trap t2 = Trap();
    	Creature c1 = Creature(f1, NORTH);
    	Creature c2 = Creature(t2, SOUTH);
    	c2.turnRequest(INFO_UNSET);
    	c1.infect(&c2);
    	CPPUNIT_ASSERT(*(c2._s) == Food());
    	CPPUNIT_ASSERT(c2._counter == 0);
    	CPPUNIT_ASSERT(c2._direction == SOUTH);
    }
    
    void test_creature_infect_3 () {
    	Food f1 = Food();
    	Trap t2 = Trap();
    	Creature c1 = Creature(f1, WEST);
    	Creature c2 = Creature(t2, NORTH);
    	c1.turnRequest(INFO_UNSET);
    	c2.infect(&c1);
    	CPPUNIT_ASSERT(*(c1._s) == Trap());
    	CPPUNIT_ASSERT(c1._counter == 0);
    	CPPUNIT_ASSERT(c1._direction == WEST);
    }
    
    void test_creature_visual_1 () {
    	Food f1 = Food();
    	Creature c1 = Creature(f1, NORTH);
    	CPPUNIT_ASSERT(c1.visual() == 'f');
    }
    
    void test_creature_visual_2 () {
    	Hopper h = Hopper();
    	Creature c1 = Creature(h, NORTH);
    	CPPUNIT_ASSERT(c1.visual() == 'h');
    }
    
    void test_creature_visual_3 () {
    	Rover r = Rover();
    	Creature c1 = Creature(r, NORTH);
    	CPPUNIT_ASSERT(c1.visual() == 'r');
    }
    
    
    void test_board_constructor_1 () {
    	Board b = Board(5, 5);
    	CPPUNIT_ASSERT(b._height == 5);
    	CPPUNIT_ASSERT(b._width == 5);
    	CPPUNIT_ASSERT(b._turn == 0);
    	
    	for(int r = 0; r < 5; r++){
    		for(int c = 0; c < 5; c++){
    			CPPUNIT_ASSERT(b._board[r][c] == 0);
    			CPPUNIT_ASSERT(b._directions[r][c] == 0);
    		}
    	}
    }
    
    void test_board_constructor_2 () {
    	Board b = Board(7, 5);
    	CPPUNIT_ASSERT(b._height == 7);
    	CPPUNIT_ASSERT(b._width == 5);
    	CPPUNIT_ASSERT(b._turn == 0);
    	
    	for(int r = 0; r < 5; r++){
    		for(int c = 0; c < 7; c++){
    			CPPUNIT_ASSERT(b._board[r][c] == 0);
    			CPPUNIT_ASSERT(b._directions[r][c] == 0);
    		}
    	}
    }
    
    void test_board_constructor_3 () {
    	Board b = Board(5, 2);
    	CPPUNIT_ASSERT(b._height == 5);
    	CPPUNIT_ASSERT(b._width == 2);
    	CPPUNIT_ASSERT(b._turn == 0);
    	
    	for(int r = 0; r < 2; r++){
    		for(int c = 0; c < 5; c++){
    			CPPUNIT_ASSERT(b._board[r][c] == 0);
    			CPPUNIT_ASSERT(b._directions[r][c] == 0);
    		}
    	}
    }
    
    void test_board_placecoord_1 () {
    	Board b = Board(5, 5);
    	Rover r = Rover();
    	Creature c = Creature(r, NORTH);
    	b.placeCreature(&c, 4, 4);
    	CPPUNIT_ASSERT(b._directions[4][4] == -NORTH);
    	CPPUNIT_ASSERT(b._board[4][4] == &c);
    }
    
    void test_board_placecoord_2 () {
    	Board b = Board(5, 4);
    	Trap t = Trap();
    	Creature c = Creature(t, WEST);
    	b.placeCreature(&c, 2, 1);
    	CPPUNIT_ASSERT(b._directions[1][2] == -WEST);
    	CPPUNIT_ASSERT(b._board[1][2] == &c);
    }
    
    void test_board_placecoord_3 () {
    	Board b = Board(2, 4);
    	Trap t = Trap();
    	Creature c = Creature(t, WEST);
    	b.placeCreature(&c, 0, 1);
    	CPPUNIT_ASSERT(b._directions[1][0] == -WEST);
    	CPPUNIT_ASSERT(b._board[1][0] == &c);
    }
    
    void test_board_placeindex_1 () {
    	Board b = Board(5, 5);
    	Rover r = Rover();
    	Creature c = Creature(r, NORTH);
    	b.placeCreature(&c, 3);
    	CPPUNIT_ASSERT(b._directions[3][0] == -NORTH);
    	CPPUNIT_ASSERT(b._board[3][0] == &c);
    }
    
    void test_board_placeindex_2 () {
    	Board b = Board(5, 4);
    	Trap t = Trap();
    	Creature c = Creature(t, WEST);
    	b.placeCreature(&c, 7);
    	CPPUNIT_ASSERT(b._directions[3][1] == -WEST);
    	CPPUNIT_ASSERT(b._board[3][1] == &c);
    }
    
    void test_board_placeindex_3 () {
    	Board b = Board(2, 4);
    	Trap t = Trap();
    	Creature c = Creature(t, WEST);
    	b.placeCreature(&c, 6);
    	CPPUNIT_ASSERT(b._directions[2][1] == -WEST);
    	CPPUNIT_ASSERT(b._board[2][1] == &c);
    }
    
    void test_board_doturn_1 () {
    	Board b = Board(5, 5);
    	Rover r = Rover();
    	Creature c1 = Creature(r, NORTH);
    	Creature c2 = Creature(r, NORTH);
    	b.placeCreature(&c1, 4, 0);
    	b.placeCreature(&c2, 4, 1);
    	b.doTurn(1);
    	CPPUNIT_ASSERT(b._board[0][3] == &c1);
    	CPPUNIT_ASSERT(b._board[1][3] == &c2);
    	CPPUNIT_ASSERT(b._board[0][4] == 0);
    	CPPUNIT_ASSERT(b._board[1][4] == 0);
    }
    
    void test_board_doturn_2 () {
    	Board b = Board(5, 5);
    	Rover r = Rover();
    	Creature c1 = Creature(r, NORTH);
    	Creature c2 = Creature(r, NORTH);
    	b.placeCreature(&c1, 4, 0);
    	b.placeCreature(&c2, 4, 1);
    	b.doTurn(2);
    	CPPUNIT_ASSERT(b._board[0][2] == &c1);
    	CPPUNIT_ASSERT(b._board[1][2] == &c2);
    	CPPUNIT_ASSERT(b._board[0][4] == 0);
    	CPPUNIT_ASSERT(b._board[1][4] == 0);
    }
    
    void test_board_doturn_3 () {
    	Board b = Board(5, 5);
    	Rover r = Rover();
    	Creature c1 = Creature(r, NORTH);
    	Creature c2 = Creature(r, NORTH);
    	b.placeCreature(&c1, 4, 0);
    	b.placeCreature(&c2, 4, 1);
    	b.doTurn(3);
    	CPPUNIT_ASSERT(b._board[0][1] == &c1);
    	CPPUNIT_ASSERT(b._board[1][1] == &c2);
    	CPPUNIT_ASSERT(b._board[0][4] == 0);
    	CPPUNIT_ASSERT(b._board[1][4] == 0);
    }
    
    void test_board_print_1 () {
        std::ostringstream w;
        Hopper h = Hopper();
        Food f = Food();
        
        Creature c1 = Creature(f, EAST);
        Creature c2 = Creature(h, NORTH);
        Creature c3 = Creature(h, EAST);
        Creature c4 = Creature(h, SOUTH);
        Creature c5 = Creature(h, WEST);
        Creature c6 = Creature(f, NORTH);
        
        
        Board board = Board(8, 8);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 3, 3);
        board.placeCreature(&c3, 3, 4);
        board.placeCreature(&c4, 4, 4);
        board.placeCreature(&c5, 4, 3);
        board.placeCreature(&c6, 7, 7);
        board.printBoard(w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0\n  01234567\n0 f.......\n1 ........\n2 ........\n3 ...hh...\n4 ...hh...\n5 ........\n6 ........\n7 .......f\n\n");
    }

    void test_board_print_2 () {
        std::ostringstream w;
        Hopper h = Hopper();
        Trap t = Trap();
        Rover r = Rover();
        
        Creature c1 = Creature(t, SOUTH);
        Creature c2 = Creature(h, EAST);
        Creature c3 = Creature(r, NORTH);
        Creature c4 = Creature(t, WEST);
        
        Board board = Board(7, 9);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 3, 2);
        board.placeCreature(&c3, 5, 4);
        board.placeCreature(&c4, 6, 8);
        
        board.printBoard(w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0\n  012345678\n0 t........\n1 .........\n2 .........\n3 ..h......\n4 .........\n5 ....r....\n6 ........t\n\n");
    }

    void test_board_print_3 () {
        std::ostringstream w;
        Hopper h = Hopper();
        Trap t = Trap();
        Rover r = Rover();
        
        Creature c1 = Creature(t, SOUTH);
        Creature c2 = Creature(h, EAST);
        Creature c3 = Creature(r, NORTH);
        Creature c4 = Creature(t, WEST);
        
        Board board = Board(7, 9);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 3, 2);
        board.placeCreature(&c3, 5, 4);
        board.placeCreature(&c4, 6, 8);
        
       	board.doTurn(2);
        
        board.printBoard(w);
        CPPUNIT_ASSERT(w.str() == "Turn = 2\n  012345678\n0 t........\n1 .........\n2 .........\n3 ....r....\n4 ....r....\n5 .........\n6 ........t\n\n");
   }

    // ----
    // eval
    // ----
    
    /*

    void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}*/

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_species_turnRQ_1);
    CPPUNIT_TEST(test_species_turnRQ_2);
    CPPUNIT_TEST(test_species_turnRQ_3);
    CPPUNIT_TEST(test_species_visual_1);
    CPPUNIT_TEST(test_species_visual_2);
    CPPUNIT_TEST(test_species_visual_3);
    CPPUNIT_TEST(test_species_equal_1);
    CPPUNIT_TEST(test_species_equal_2);
    CPPUNIT_TEST(test_species_equal_3);
    
    CPPUNIT_TEST(test_food_turnRQ_1);
    CPPUNIT_TEST(test_food_turnRQ_2);
    CPPUNIT_TEST(test_food_turnRQ_3);
    CPPUNIT_TEST(test_food_visual_1);
    CPPUNIT_TEST(test_food_visual_2);
    CPPUNIT_TEST(test_food_visual_3);
    CPPUNIT_TEST(test_food_equal_1);
    CPPUNIT_TEST(test_food_equal_2);
    CPPUNIT_TEST(test_food_equal_3);
    
    CPPUNIT_TEST(test_hopper_turnRQ_1);
    CPPUNIT_TEST(test_hopper_turnRQ_2);
    CPPUNIT_TEST(test_hopper_turnRQ_3);
    CPPUNIT_TEST(test_hopper_visual_1);
    CPPUNIT_TEST(test_hopper_visual_2);
    CPPUNIT_TEST(test_hopper_visual_3);
    CPPUNIT_TEST(test_hopper_equal_1);
    CPPUNIT_TEST(test_hopper_equal_2);
    CPPUNIT_TEST(test_hopper_equal_3);
    
    CPPUNIT_TEST(test_rover_turnRQ_1);
    CPPUNIT_TEST(test_rover_turnRQ_2);
    CPPUNIT_TEST(test_rover_turnRQ_3);
    CPPUNIT_TEST(test_rover_visual_1);
    CPPUNIT_TEST(test_rover_visual_2);
    CPPUNIT_TEST(test_rover_visual_3);
    CPPUNIT_TEST(test_rover_equal_1);
    CPPUNIT_TEST(test_rover_equal_2);
    CPPUNIT_TEST(test_rover_equal_3);
    
    CPPUNIT_TEST(test_trap_turnRQ_1);
    CPPUNIT_TEST(test_trap_turnRQ_2);
    CPPUNIT_TEST(test_trap_turnRQ_3);
    CPPUNIT_TEST(test_trap_visual_1);
    CPPUNIT_TEST(test_trap_visual_2);
    CPPUNIT_TEST(test_trap_visual_3);
    CPPUNIT_TEST(test_trap_equal_1);
    CPPUNIT_TEST(test_trap_equal_2);
    CPPUNIT_TEST(test_trap_equal_3);
    
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_creature_turnRQ_1);
    CPPUNIT_TEST(test_creature_turnRQ_2);
    CPPUNIT_TEST(test_creature_turnRQ_3);
    CPPUNIT_TEST(test_creature_share_1);
    CPPUNIT_TEST(test_creature_share_2);
    CPPUNIT_TEST(test_creature_share_3);
    CPPUNIT_TEST(test_creature_turn_1);
    CPPUNIT_TEST(test_creature_turn_2);
    CPPUNIT_TEST(test_creature_turn_3);
    CPPUNIT_TEST(test_creature_direction_1);
    CPPUNIT_TEST(test_creature_direction_2);
    CPPUNIT_TEST(test_creature_direction_3);
    CPPUNIT_TEST(test_creature_infect_1);
    CPPUNIT_TEST(test_creature_infect_2);
    CPPUNIT_TEST(test_creature_infect_3);
    CPPUNIT_TEST(test_creature_visual_1);
    CPPUNIT_TEST(test_creature_visual_2);
    CPPUNIT_TEST(test_creature_visual_3);
    
    CPPUNIT_TEST(test_board_constructor_1);
    CPPUNIT_TEST(test_board_constructor_2);
    CPPUNIT_TEST(test_board_constructor_3);
    CPPUNIT_TEST(test_board_placecoord_1);
    CPPUNIT_TEST(test_board_placecoord_2);
    CPPUNIT_TEST(test_board_placecoord_3);
    CPPUNIT_TEST(test_board_placeindex_1);
    CPPUNIT_TEST(test_board_placeindex_2);
    CPPUNIT_TEST(test_board_placeindex_3); 
    CPPUNIT_TEST(test_board_doturn_1);
    CPPUNIT_TEST(test_board_doturn_2);
    CPPUNIT_TEST(test_board_doturn_3);
    CPPUNIT_TEST(test_board_print_1);
    CPPUNIT_TEST(test_board_print_2);
    CPPUNIT_TEST(test_board_print_3);
    
    
    CPPUNIT_TEST(test_best_turnRQ_1);
    CPPUNIT_TEST(test_best_turnRQ_2);
    CPPUNIT_TEST(test_best_turnRQ_3);
    CPPUNIT_TEST(test_best_visual_1);
    CPPUNIT_TEST(test_best_visual_2);
    CPPUNIT_TEST(test_best_visual_3);
    CPPUNIT_TEST(test_best_equal_1);
    CPPUNIT_TEST(test_best_equal_2);
    CPPUNIT_TEST(test_best_equal_3);
    
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    //ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
