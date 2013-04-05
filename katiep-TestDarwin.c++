// ------------------------------------
// projects/darwin/TestDarwin.c++
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
    % valgrind TestDarwin >& TestDarwin.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <sstream>   // istringtstream, ostringstream
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Darwin.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {
	
	// -----------
	// instruction
	// -----------
	
	// Instruction (instruction name, int line)
	
	void test_instruction_1 () {
		Instruction i(HOP, -1);
		CPPUNIT_ASSERT(i._name == HOP);
		CPPUNIT_ASSERT(i._line == -1);
	}
	
	void test_instruction_2 () {
		Instruction i1(HOP);
		Instruction i2(HOP, -1);
		CPPUNIT_ASSERT(i1._name == i2._name);
		CPPUNIT_ASSERT(i1._line == i2._line);
		CPPUNIT_ASSERT(i1.equals(i2));
		CPPUNIT_ASSERT(i1 == i2);
	}
	
	void test_instruction_3 () {
		Instruction i[] = {
				Instruction(HOP, -1),
				Instruction(LEFT, -1),
				Instruction(RIGHT, -1),
				Instruction(INFECT, -1),
				Instruction(IF_EMPTY, 5),
				Instruction(IF_WALL, 6),
				Instruction(IF_RANDOM, 7),
				Instruction(IF_ENEMY, 8),
				Instruction(GO, 0)
		};
		
		CPPUNIT_ASSERT(i[0]._name == HOP);
		CPPUNIT_ASSERT(i[0]._line == -1);
		CPPUNIT_ASSERT(i[1]._name == LEFT);
		CPPUNIT_ASSERT(i[1]._line == -1);
		CPPUNIT_ASSERT(i[2]._name == RIGHT);
		CPPUNIT_ASSERT(i[2]._line == -1);
		CPPUNIT_ASSERT(i[3]._name == INFECT);
		CPPUNIT_ASSERT(i[3]._line == -1);
		CPPUNIT_ASSERT(i[4]._name == IF_EMPTY);
		CPPUNIT_ASSERT(i[4]._line == 5);
		CPPUNIT_ASSERT(i[5]._name == IF_WALL);
		CPPUNIT_ASSERT(i[5]._line == 6);
		CPPUNIT_ASSERT(i[6]._name == IF_RANDOM);
		CPPUNIT_ASSERT(i[6]._line == 7);
		CPPUNIT_ASSERT(i[7]._name == IF_ENEMY);
		CPPUNIT_ASSERT(i[7]._line == 8);
		CPPUNIT_ASSERT(i[8]._name == GO);
		CPPUNIT_ASSERT(i[8]._line == 0);
	}
	
	// --------
	// creature
	// --------

	// Creature (char sym, Instruction i[], int size_i, direction dir, bool has_moved)
	
	void test_creature_1 () {
		direction dir = NORTH;
		
		Creature c(FOOD, dir);
		for (int x = 0; x < food_size; x++) {
			CPPUNIT_ASSERT(c._i[x].equals(food_i[x]));
		}
		CPPUNIT_ASSERT(c._size_i == food_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(!c.isEmpty());
		
		c = Creature(HOPPER, dir);
		for (int x = 0; x < hopper_size; x++) {
			CPPUNIT_ASSERT(c._i[x].equals(hopper_i[x]));
		}
		CPPUNIT_ASSERT(c._size_i == hopper_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(!c.isEmpty());
		
		c = Creature(ROVER, dir);
		for (int x = 0; x < rover_size; x++) {
			CPPUNIT_ASSERT(c._i[x].equals(rover_i[x]));
		}
		CPPUNIT_ASSERT(c._size_i == rover_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(!c.isEmpty());
		
		c = Creature(TRAP, dir);
		for (int x = 0; x < trap_size; x++) {
			CPPUNIT_ASSERT(c._i[x].equals(trap_i[x]));
		}
		CPPUNIT_ASSERT(c._size_i == trap_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(!c.isEmpty());
		
		c = Creature(BEST, dir);
		for (int x = 0; x < best_size; x++) {
			CPPUNIT_ASSERT(c._i[x].equals(best_i[x]));
		}
		CPPUNIT_ASSERT(c._size_i == best_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(!c.isEmpty());
		
		c = Creature(EMPTY, dir);
		CPPUNIT_ASSERT(c._size_i == empty_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(c.isEmpty());
		
		c = Creature();
		CPPUNIT_ASSERT(c._size_i == empty_size);
		CPPUNIT_ASSERT(c._dir == dir);
		CPPUNIT_ASSERT(c._turn == 1);
		CPPUNIT_ASSERT(c.isEmpty());
	}
	
	void test_creature_2 () {
		Creature c1(FOOD, NORTH);
		Creature c2(FOOD, SOUTH);
		
		CPPUNIT_ASSERT(c1.equals(c2));
		CPPUNIT_ASSERT(c2.equals(c1));
		
		CPPUNIT_ASSERT(c1 == c2);
		CPPUNIT_ASSERT(c2 == c1);
		
		CPPUNIT_ASSERT(!c1.isEmpty());
		CPPUNIT_ASSERT(!c2.isEmpty());
	}
	
	void test_creature_3 () {
		Creature c1(FOOD, NORTH);
		Creature c2(HOPPER, SOUTH);
		
		CPPUNIT_ASSERT(!c1.equals(c2));
		CPPUNIT_ASSERT(!c2.equals(c1));
		
		CPPUNIT_ASSERT(!(c1 == c2));
		CPPUNIT_ASSERT(!(c2 == c1));
		
		CPPUNIT_ASSERT(c1 != c2);
		CPPUNIT_ASSERT(c2 != c1);
		
		CPPUNIT_ASSERT(!c1.isEmpty());
		CPPUNIT_ASSERT(!c2.isEmpty());
	}
	
	// -----
	// board
	// -----
	
	// Board (int height, int width)
	
	void test_board_1 () {
		int height = 10;
		int width = 10;
		
		Board b(height, width);
		
		for (int x = 0; x < height * width; x++) {
			CPPUNIT_ASSERT(b._board[x].isEmpty());
		}
	}
	
	void test_board_2 () {
		int height = 8;
		int width = 8;
		
		Board b(height, width);

		// Food, facing east, at (0, 0)
		int loc = 0 * width + 0;
		b.add_creature(FOOD, EAST, loc);
		Creature& cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
		
		// Hopper, facing north, at (3, 3)
		loc = 3 * width + 3;
		b.add_creature(HOPPER, NORTH, loc);
		cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
		
		// Hopper, facing east, at (3, 4)
		loc = 3 * width + 4;
		b.add_creature(HOPPER, EAST, loc);
		cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
		
		// Hopper, facing south, at (4, 4)
		loc = 4 * width + 4;
		b.add_creature(HOPPER, SOUTH, loc);
		cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
		
		// Hopper, facing west, at (4, 3)
		loc = 4 * width + 3;
		b.add_creature(HOPPER, WEST, loc);
		cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
		
		// Food, facing north, at (7, 7)
		loc = 7 * width + 7;
		b.add_creature(FOOD, NORTH, loc);
		cr = b._board[loc];
		CPPUNIT_ASSERT(b._board[loc] == cr);
	}

	// -------------------
	// test_helper_methods	
	// -------------------
	
	// void turn_end (Creature& cur)
	
	void test_turn_end_1 () {
		Creature c(FOOD, NORTH);
		
		turn_end(c);

		CPPUNIT_ASSERT(c._pc == 1);
		CPPUNIT_ASSERT(c._turn == 2);
	}
	
	void test_turn_end_2 () {
		Creature c(FOOD, NORTH);
		
		turn_end(c);
		turn_end(c);

		CPPUNIT_ASSERT(c._pc == 2);
		CPPUNIT_ASSERT(c._turn == 3);
	}
	
	void test_turn_end_3 () {
		Creature c(FOOD, NORTH);
		
		turn_end(c);
		turn_end(c);
		turn_end(c);
		turn_end(c);
		turn_end(c);

		CPPUNIT_ASSERT(c._pc == 5);
		CPPUNIT_ASSERT(c._turn == 6);
	}

	// int get_front (direction dir, int loc, Board& b)
	
	void test_get_front_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		// (1,1)
		CPPUNIT_ASSERT(get_front(NORTH, 12, b) 	==  1);
		CPPUNIT_ASSERT(get_front(EAST, 	12, b) 	== 13);
		CPPUNIT_ASSERT(get_front(SOUTH, 12, b) 	== 23);
		CPPUNIT_ASSERT(get_front(WEST, 	12, b) 	== 11);
	}
	
	void test_get_front_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		// (0,0)
		CPPUNIT_ASSERT(get_front(NORTH,  0, b) 	== -1);
		CPPUNIT_ASSERT(get_front(EAST, 	 0, b) 	==  1);
		CPPUNIT_ASSERT(get_front(SOUTH,  0, b) 	== 11);
		CPPUNIT_ASSERT(get_front(WEST, 	 0, b) 	== -1);
	}
	
	void test_get_front_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		// (0,0)
		CPPUNIT_ASSERT(get_front(NORTH,  0, b) 	== -1);
		CPPUNIT_ASSERT(get_front(EAST, 	 0, b) 	==  1);
		CPPUNIT_ASSERT(get_front(SOUTH,  0, b) 	== 11);
		CPPUNIT_ASSERT(get_front(WEST, 	 0, b) 	== -1);
	}

	// ------------
	// test_actions
	// ------------
	
	// void hop (Creature& cur, int loc, Board& b)
	
	void test_hop_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 0);
		
		Creature c = b._board[0];
		
		// (0,0) N
		hop(c, 0, b);
		CPPUNIT_ASSERT(b._board[0] == c);
		
		// (0,0) W
		c._dir = WEST;
		hop(c, 0, b);
		CPPUNIT_ASSERT(b._board[0] == c);
		
		// (0,0) E
		c._dir = EAST;
		hop(c, 0, b);
		CPPUNIT_ASSERT(b._board[0].isEmpty());
		CPPUNIT_ASSERT(b._board[1] == c);
		
		// (0,1) S
		c._dir = SOUTH;
		hop(c, 1, b);
		CPPUNIT_ASSERT(b._board[1].isEmpty());
		CPPUNIT_ASSERT(b._board[12] == c);
	}
	
	void test_hop_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 98);
		
		Creature c = b._board[98];
		
		// (8,10) E
		c._dir = EAST;
		hop(c, 98, b);
		CPPUNIT_ASSERT(b._board[98] == c);
		
		// (8,10) S
		c._dir = SOUTH;
		hop(c, 98, b);
		CPPUNIT_ASSERT(b._board[98] == c);
		
		// (8,10) W
		c._dir = WEST;
		hop(c, 98, b);
		CPPUNIT_ASSERT(b._board[98].isEmpty());
		CPPUNIT_ASSERT(b._board[97] == c);
		
		// (8,9) N
		c._dir = NORTH;
		hop(c, 97, b);
		CPPUNIT_ASSERT(b._board[97].isEmpty());
		CPPUNIT_ASSERT(b._board[86] == c);
	}
	
	void test_hop_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 10);
		
		Creature c = b._board[10];
		
		// (0,10) E
		c._dir = EAST;
		hop(c, 10, b);
		CPPUNIT_ASSERT(b._board[10] == c);
		
		// (0,10) N
		c._dir = NORTH;
		hop(c, 10, b);
		CPPUNIT_ASSERT(b._board[10] == c);
		
		// (0,10) S
		c._dir = SOUTH;
		hop(c, 10, b);
		CPPUNIT_ASSERT(b._board[10].isEmpty());
		CPPUNIT_ASSERT(b._board[21] == c);
		
		// (1,10) W
		c._dir = WEST;
		hop(c, 21, b);
		CPPUNIT_ASSERT(b._board[21].isEmpty());
		CPPUNIT_ASSERT(b._board[20] == c);
	}
	
	void test_hop_4 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 88);
		
		Creature c = b._board[88];
		
		// (8,0) W
		c._dir = WEST;
		hop(c, 88, b);
		CPPUNIT_ASSERT(b._board[88] == c);
		
		// (8,0) S
		c._dir = SOUTH;
		hop(c, 88, b);
		CPPUNIT_ASSERT(b._board[88] == c);
		
		// (8,0) N
		c._dir = NORTH;
		hop(c, 88, b);
		CPPUNIT_ASSERT(b._board[88].isEmpty());
		CPPUNIT_ASSERT(b._board[77] == c);
		
		// (7,0) E
		c._dir = EAST;
		hop(c, 77, b);
		CPPUNIT_ASSERT(b._board[77].isEmpty());
		CPPUNIT_ASSERT(b._board[78] == c);
	}

	// void left (Creature& cur)
	
	void test_left_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 0);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);

		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
	}
	
	void test_left_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, WEST, 0);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);
	}
	
	void test_left_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, SOUTH, 0);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);
		
		left(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
	}

	// void right (Creature& cur)
	
	void test_right_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, NORTH, 0);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
	}
	
	void test_right_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, EAST, 0);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
	}
	
	void test_right_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(FOOD, SOUTH, 0);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == WEST);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == NORTH);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == EAST);
		
		right(b._board[0]);
		CPPUNIT_ASSERT(b._board[0]._dir == SOUTH);
	}

	// void infect (Creature& cur, int loc, Board& b)
	
	void test_infect_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(FOOD, dir, 0);
		b.add_creature(HOPPER, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0] != b._board[1]);
		
		infect(b._board[0], 0, b);
		
		CPPUNIT_ASSERT(b._board[0] == b._board[1]);
	}
	
	void test_infect_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = WEST;
		
		b.add_creature(FOOD, dir, 0);
		b.add_creature(HOPPER, dir, 1);

		CPPUNIT_ASSERT(b._board[0] != b._board[1]);
		
		infect(b._board[0], 0, b);
		
		CPPUNIT_ASSERT(b._board[0] != b._board[1]);
	}
	
	void test_infect_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(FOOD, dir, 0);
		b.add_creature(FOOD, dir, 1);

		CPPUNIT_ASSERT(b._board[0] == b._board[1]);
		
		infect(b._board[0], 0, b);
		
		CPPUNIT_ASSERT(b._board[0] == b._board[1]);
	}
	
	void test_infect_4 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = SOUTH;
		
		b.add_creature(FOOD, dir, 0);
		b.add_creature(HOPPER, dir, 1);

		CPPUNIT_ASSERT(b._board[0] != b._board[1]);
		
		infect(b._board[0], 0, b);
		
		CPPUNIT_ASSERT(b._board[0] != b._board[1]);
	}

	// --------
	// controls
	// --------

	// void go (Creature& cur, int n)
	
	void test_go_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(ROVER, EAST, 0);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		go(b._board[0], 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_go_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);

		b.add_creature(ROVER, EAST, 0);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		go(b._board[0], 8);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 8);
	}
	
	void test_go_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(ROVER, EAST, 0);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		go(b._board[0], 5);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 5);
	}

	// void if_empty (Creature& cur, int n, int loc, Board& b)
	
	void test_if_empty_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		if_empty(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_empty_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = WEST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		if_empty(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_empty_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = SOUTH;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);

		CPPUNIT_ASSERT(b._board[0]._pc == 0);

		if_empty(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 2);
	}
	
	// void if_wall (Creature& cur, int n, int loc, Board& b)
	
	void test_if_wall_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_wall(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_wall_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = WEST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_wall(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 2);
	}
	
	void test_if_wall_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = SOUTH;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_wall(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}

	// void if_random (Creature& cur, int n, int loc) {
	
	void test_if_random_1 () {
		srand(0);
	
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(ROVER, EAST, 0);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		// 1804289383
		if_random(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 2);
	}
	
	void test_if_random_2 () {
		srand(0);
	
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(ROVER, WEST, 0);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		rand();
		
		// 846930886
		if_random(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_random_3 () {
		srand(0);
	
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		b.add_creature(ROVER, SOUTH, 0);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		rand();
		rand();
		
		// 1681692777
		if_random(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 2);
	}

	// void if_enemy (Creature& cur, int n, int loc, Board& b)
	
	void test_if_enemy_1 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_enemy(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 2);
	}
	
	void test_if_enemy_2 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = EAST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(ROVER, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_enemy(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_enemy_3 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = SOUTH;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_enemy(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	void test_if_enemy_4 () {
		int height = 9;
		int width = 11;
		
		Board b(height, width);
		
		direction dir = WEST;
		
		b.add_creature(ROVER, dir, 0);
		b.add_creature(BEST, dir, 1);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 0);
		
		if_enemy(b._board[0], 2, 0, b);
		
		CPPUNIT_ASSERT(b._board[0]._pc == 1);
	}
	
	// void print_board (Board& b, int turn, std::ostream& w)
	
	void test_print_board_1 () {
		std::ostringstream w;

		int height = 1;
		int width = 1;
		
		Board b(height, width);
		
		print_board(b, 0, w);

		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0\n0 .\n\n");
	}
	
	void test_print_board_2 () {
		std::ostringstream w;
		
		direction dir = NORTH;
		
		int height = 10;
		int width = 10;
		
		Board b(height, width);

		b.add_creature(FOOD, dir, 77);
		b.add_creature(FOOD, dir, 83);
		b.add_creature(FOOD, dir, 86);
		b.add_creature(HOPPER, dir, 15);
		b.add_creature(HOPPER, dir, 93);
		b.add_creature(HOPPER, dir, 35);
		b.add_creature(ROVER, dir, 21);
		b.add_creature(ROVER, dir, 49);
		b.add_creature(ROVER, dir, 92);
		
		print_board(b, 0, w);
		
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0123456789\n0 ..........\n1 .....h....\n2 .r........\n3 .....h....\n4 .........r\n5 ..........\n6 ..........\n7 .......f..\n8 ...f..f...\n9 ..rh......\n\n");
	}
	
	void test_print_board_3 () {
		std::ostringstream w;

		int height = 21;
		int width = 21;
		
		Board b(height, width);
		
		print_board(b, 0, w);
		
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012345678901234567890\n0 .....................\n1 .....................\n2 .....................\n3 .....................\n4 .....................\n5 .....................\n6 .....................\n7 .....................\n8 .....................\n9 .....................\n0 .....................\n1 .....................\n2 .....................\n3 .....................\n4 .....................\n5 .....................\n6 .....................\n7 .....................\n8 .....................\n9 .....................\n0 .....................\n\n");
	}

	// bool is_action (Instruction i)
	
	void test_is_action_1 () {
		Instruction i(HOP);
		CPPUNIT_ASSERT(is_action(i));
		
		i = Instruction(LEFT);
		CPPUNIT_ASSERT(is_action(i));
		
		i = Instruction(RIGHT);
		CPPUNIT_ASSERT(is_action(i));
		
		i = Instruction(INFECT);
		CPPUNIT_ASSERT(is_action(i));
	}
	
	void test_is_action_2 () {
		Instruction i(IF_EMPTY, 0);
		CPPUNIT_ASSERT(!is_action(i));
		
		i = Instruction(IF_WALL, 0);
		CPPUNIT_ASSERT(!is_action(i));
		
		i = Instruction(IF_RANDOM, 0);
		CPPUNIT_ASSERT(!is_action(i));
		
		i = Instruction(IF_ENEMY, 0);
		CPPUNIT_ASSERT(!is_action(i));
		
		i = Instruction(GO, 0);
		CPPUNIT_ASSERT(!is_action(i));
	}
	
	void test_is_action_3 () {
		Instruction i(NONE);
		CPPUNIT_ASSERT(!is_action(i));
	}
	
	// play_game (Board& b, int turns, ostream& w)
	
	void test_play_game_1 () {
		srand(0);
	
		/*
		8x8 Darwin
		Food, facing east, at (0, 0)
		Hopper, facing north, at (3, 3)
		Hopper, facing east, at (3, 4)
		Hopper, facing south, at (4, 4)
		Hopper, facing west, at (4, 3)
		Food, facing north, at (7, 7)
		Simulate 5 moves.
		Print every grid.
		*/
		
		int height = 8;
		int width = 8;
		
		Board b(height, width);

		b.add_creature(FOOD, EAST, 0, 0);
		b.add_creature(HOPPER, NORTH, 3, 3);
		b.add_creature(HOPPER, EAST, 3, 4);
		b.add_creature(HOPPER, SOUTH, 4, 4);
		b.add_creature(HOPPER, WEST, 4, 3);
		b.add_creature(FOOD, NORTH, 7, 7);
		
		int turns = 5;
		
		int rate = 1;
		
		std::ostringstream w;
		
		play_game(b, turns, w, rate);
		
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  01234567\n0 f.......\n1 ........\n2 ........\n3 ...hh...\n4 ...hh...\n5 ........\n6 ........\n7 .......f\n\nTurn = 1.\n  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\nTurn = 2.\n  01234567\n0 f.......\n1 ...h....\n2 ........\n3 ......h.\n4 .h......\n5 ........\n6 ....h...\n7 .......f\n\nTurn = 3.\n  01234567\n0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n\nTurn = 4.\n  01234567\n0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n\nTurn = 5.\n  01234567\n0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n\n");
	}
	
	void test_play_game_2 () {
		srand(0);
		
		/*
		7x9 Darwin
		Trap, facing south, at (0, 0)
		Hopper, facing east, at (3, 2)
		Rover, facing north, at (5, 4)
		Trap, facing west, at (6, 8)
		Simulate 5 moves.
		Print every grid.
		*/
		
		int height = 7;
		int width = 9;
		
		Board b(height, width);
		
		b.add_creature(TRAP, SOUTH, 0, 0);
		b.add_creature(HOPPER, EAST, 3, 2);
		b.add_creature(ROVER, NORTH, 5, 4);
		b.add_creature(TRAP, WEST, 6, 8);
		
		int turns = 5;
		
		int rate = 1;
		
		std::ostringstream w;
		
		play_game(b, turns, w, rate);
		
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012345678\n0 t........\n1 .........\n2 .........\n3 ..h......\n5 .........\n6 ....r....\n7 ........t\n\nTurn = 1.\n  012345678\n0 t........\n1 .........\n2 .........\n3 ...h.....\n5 ....r....\n6 .........\n7 ........t\n\nTurn = 2.\n  012345678\n0 t........\n1 .........\n2 .........\n3 ....r....\n5 ....r....\n6 .........\n7 ........t\n\nTurn = 3.\n  012345678\n0 t........\n1 .........\n2 .........\n3 ....rr...\n5 .........\n6 .........\n7 ........t\n\nTurn = 4.\n  012345678\n0 t........\n1 .........\n2 ....r....\n3 ......r..\n5 .........\n6 .........\n7 ........t\n\nTurn = 5.\n  012345678\n0 t........\n1 ....r....\n2 .........\n3 .......r.\n5 .........\n6 .........\n7 ........t\n\n");
	}
	
	void test_play_game_3 () {
		srand(0);
		
		int height = 1;
		int width = 1;
		
		Board b(height, width);
		
		int turns = 1;
		
		int rate = 1;
		
		std::ostringstream w;
		
		play_game(b, turns, w, rate);
		
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0\n0 .\n\nTurn = 1.\n  0\n0 .\n\n");
	}
	
	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestDarwin);
	
	CPPUNIT_TEST(test_instruction_1);
	CPPUNIT_TEST(test_instruction_2);
	CPPUNIT_TEST(test_instruction_3);
	
	CPPUNIT_TEST(test_creature_1);
	CPPUNIT_TEST(test_creature_2);
	CPPUNIT_TEST(test_creature_3);
	
	CPPUNIT_TEST(test_board_1);
	CPPUNIT_TEST(test_board_2);
	
	CPPUNIT_TEST(test_turn_end_1);
	CPPUNIT_TEST(test_turn_end_2);
	CPPUNIT_TEST(test_turn_end_3);
	
	CPPUNIT_TEST(test_get_front_1);
	CPPUNIT_TEST(test_get_front_2);
	CPPUNIT_TEST(test_get_front_3);
	
	CPPUNIT_TEST(test_hop_1);
	CPPUNIT_TEST(test_hop_2);
	CPPUNIT_TEST(test_hop_3);
	CPPUNIT_TEST(test_hop_4);
	
	CPPUNIT_TEST(test_left_1);
	CPPUNIT_TEST(test_left_2);
	CPPUNIT_TEST(test_left_3);
	
	CPPUNIT_TEST(test_right_1);
	CPPUNIT_TEST(test_right_2);
	CPPUNIT_TEST(test_right_3);
	
	CPPUNIT_TEST(test_infect_1);
	CPPUNIT_TEST(test_infect_2);
	CPPUNIT_TEST(test_infect_3);
	CPPUNIT_TEST(test_infect_4);
	
	CPPUNIT_TEST(test_go_1);
	CPPUNIT_TEST(test_go_2);
	CPPUNIT_TEST(test_go_3);
	
	CPPUNIT_TEST(test_if_empty_1);
	CPPUNIT_TEST(test_if_empty_2);
	CPPUNIT_TEST(test_if_empty_3);
	
	CPPUNIT_TEST(test_if_wall_1);
	CPPUNIT_TEST(test_if_wall_2);
	CPPUNIT_TEST(test_if_wall_3);
	
	CPPUNIT_TEST(test_if_random_1);
	CPPUNIT_TEST(test_if_random_2);
	CPPUNIT_TEST(test_if_random_3);
	
	CPPUNIT_TEST(test_if_enemy_1);
	CPPUNIT_TEST(test_if_enemy_2);
	CPPUNIT_TEST(test_if_enemy_3);
	CPPUNIT_TEST(test_if_enemy_4);
	
	CPPUNIT_TEST(test_print_board_1);
	CPPUNIT_TEST(test_print_board_2);
	CPPUNIT_TEST(test_print_board_3);
	
	CPPUNIT_TEST(test_is_action_1);
	CPPUNIT_TEST(test_is_action_2);
	CPPUNIT_TEST(test_is_action_3);
	
	CPPUNIT_TEST(test_play_game_1);
	CPPUNIT_TEST(test_play_game_2);
	CPPUNIT_TEST(test_play_game_3);
	
	CPPUNIT_TEST_SUITE_END();
};

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
	return 0;
}


