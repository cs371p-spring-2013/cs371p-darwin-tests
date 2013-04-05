// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
% g++ -pedantic -std=c++0x -Wall Darwin.c++ RunDarwin.c++ -o RunDarwin
% valgrind RunDarwin > RunDarwin.out

To configure Doxygen:
doxygen -g
That creates the file Doxyfile.
Make the following edits:
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert> 		// assert
#include <cstdlib> 		// rand, srand
#include <iostream> 	// cout, endl
#include <stdexcept> 	// invalid_argument, out_of_range
#include <vector>

#include "Darwin.h"

// ----
// main
// ----

int main () {
	using namespace std;
	ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
	
	bool print_results = false;
	
	// ----
	// food
	// ----
	
	/*
	 0: left
	 1: go 0
	*/
	
	// ------
	// hopper
	// ------
	
	/*
	 0: hop
	 1: go 0
	*/
	
	// -----
	// rover
	// -----
	
	/*
	 0: if_enemy 9
	 1: if_empty 7
	 2: if_random 5
	 3: left
	 4: go 0
	 5: right
	 6: go 0
	 7: hop
	 8: go 0
	 9: infect
	10: go 0
	*/
	
	// ----
	// trap
	// ----
	
	/*
	 0: if_enemy 3
	 1: left
	 2: go 0
	 3: infect
	 4: go 0
	*/
	
	// --------------
	// 1 - darwin 8x8
	// --------------
	
	try {
		cout << "*** Darwin 8x8 ***" << endl;
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
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------
	// 2 - darwin 7x9
	// --------------
	
	try {
		cout << "*** Darwin 7x9 ***" << endl;
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
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ----------------
	// 3 - darwin 72x72
	// without best
	// ----------------
	
	try {
		cout << "*** Darwin 72x72 without Best ***" << endl;
		srand(0);
		
		/*
		Randomly place the following creatures facing randomly.
		Call rand(), mod it with 5184 (72x72), and use that for the position
		in a row-major order grid.
		Call rand() again, mod it with 4 and use that for it's direction with
		the ordering: west, north, east, south.
		Do that for each kind of creature.
		10 Food
		10 Hopper
		10 Rover
		10 Trap
		Simulate 1000 moves.
		Print every 100th grid.
		*/
		
		int height = 72;
		int width = 72;
		
		Board b(height, width);
		
		int num = 10;
		int limit = 5184;
		
		// add Food
		for (int x = 0; x < num; x++) {
			int loc = rand() % limit;
			while (!b._board[loc].isEmpty()) {
				loc = rand() % limit;
			}
			assert(b._board[loc].isEmpty());
			
			direction dir;
			switch (rand() % 4) {
			case 0 :
				dir = WEST;
				break;
			case 1 :
				dir = NORTH;
				break;
			case 2 :
				dir = EAST;
				break;
			case 3 :
				dir = SOUTH;
				break;
			default :
				assert(false);
			}
		
			b.add_creature(FOOD, dir, loc);
		}
		
		// add Hopper
		for (int x = 0; x < num; x++) {
			int loc = rand() % limit;
			while (!b._board[loc].isEmpty()) {
				loc = rand() % limit;
			}
			assert(b._board[loc].isEmpty());
			
			direction dir;
			switch (rand() % 4) {
			case 0 :
				dir = WEST;
				break;
			case 1 :
				dir = NORTH;
				break;
			case 2 :
				dir = EAST;
				break;
			case 3 :
				dir = SOUTH;
				break;
			default :
				assert(false);
			}
		
			b.add_creature(HOPPER, dir, loc);
		}
		
		// add Rover
		for (int x = 0; x < num; x++) {
			int loc = rand() % limit;
			while (!b._board[loc].isEmpty()) {
				loc = rand() % limit;
			}
			assert(b._board[loc].isEmpty());
			
			direction dir;
			switch (rand() % 4) {
			case 0 :
				dir = WEST;
				break;
			case 1 :
				dir = NORTH;
				break;
			case 2 :
				dir = EAST;
				break;
			case 3 :
				dir = SOUTH;
				break;
			default :
				assert(false);
			}
		
			b.add_creature(ROVER, dir, loc);
		}
		
		// add Trap
		for (int x = 0; x < num; x++) {
			int loc = rand() % limit;
			while (!b._board[loc].isEmpty()) {
				loc = rand() % limit;
			}
			assert(b._board[loc].isEmpty());
			
			direction dir;
			switch (rand() % 4) {
			case 0 :
				dir = WEST;
				break;
			case 1 :
				dir = NORTH;
				break;
			case 2 :
				dir = EAST;
				break;
			case 3 :
				dir = SOUTH;
				break;
			default :
				assert(false);
			}
		
			b.add_creature(TRAP, dir, loc);
		}
		
		int turns = 1000;
		
		int rate = 100;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ----------------
	// 4 - darwin 72x72
	// with best
	// ----------------
	
	// REMOVED BECAUSE OF BEST
	
	// --------------
	// 5 - darwin 1x1
	// filled
	// --------------
	
	try {
		cout << "*** Darwin 1x1 filled ***" << endl;
		srand(0);
		
		/*
		1x1 Darwin
		Hopper, facing east, at (0, 0)
		Simulate 2 moves.
		Print every grid.
		*/
		
		int height = 1;
		int width = 1;
		
		Board b(height, width);

		b.add_creature(HOPPER, EAST, 0, 0);
		
		int turns = 2;
		
		int rate = 1;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------
	// 6 - darwin 1x1
	// empty
	// --------------
	
	try {
		cout << "*** Darwin 1x1 empty ***" << endl;
		srand(0);
		
		/*
		1x1 Darwin
		Simulate 2 moves.
		Print every grid.
		*/
		
		int height = 1;
		int width = 1;
		
		Board b(height, width);

		int turns = 2;
		
		int rate = 1;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------
	// 7 - darwin 1x10
	// ---------------
	
	try {
		cout << "*** Darwin 1x10 ***" << endl;
		srand(0);
		
		/*
		1x10 Darwin
		Hopper, facing east, at (0, 0)
		Hopper, facing west, at (0, 9)
		Simulate 6 moves.
		Print every grid.
		*/
		
		int height = 1;
		int width = 10;
		
		Board b(height, width);
		
		b.add_creature(HOPPER, EAST, 0, 0);
		b.add_creature(HOPPER, WEST, 0, 9);

		int turns = 6;
		
		int rate = 1;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------
	// 8 - darwin 10x1
	// ---------------
	
	try {
		cout << "*** Darwin 10x1 ***" << endl;
		srand(0);
		
		/*
		10x1 Darwin
		Hopper, facing south, at (0, 0)
		Rover, facing north, at (9, 0)
		Simulate 10 moves.
		Print every grid.
		*/
		
		int height = 10;
		int width = 1;
		
		Board b(height, width);
		
		b.add_creature(HOPPER, SOUTH, 0, 0);
		b.add_creature(ROVER, NORTH, 9, 0);

		int turns = 10;
		
		int rate = 1;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------
	// 9 - darwin 3x3
	// --------------
	
	try {
		cout << "*** Darwin 3x3 ***" << endl;
		srand(0);
		
		/*
		3x3 Darwin
		Rover, facing south, at (0, 0)
		Hopper, facing south, at (0, 1)
		Rover, facing south, at (0, 2)
		Hopper, facing south, at (1, 0)
		Rover, facing south, at (1, 1)
		Hopper, facing south, at (1, 2)
		Rover, facing south, at (2, 0)
		Hopper, facing south, at (2, 1)
		Rover, facing south, at (2, 2)
		Simulate 5 moves.
		Print every grid.
		*/
		
		int height = 3;
		int width = 3;
		
		Board b(height, width);
		
		b.add_creature(ROVER, SOUTH, 0, 0);
		b.add_creature(HOPPER, SOUTH, 0, 1);
		b.add_creature(ROVER, SOUTH, 0, 2);
		b.add_creature(HOPPER, SOUTH, 1, 0);
		b.add_creature(ROVER, SOUTH, 1, 1);
		b.add_creature(HOPPER, SOUTH, 1, 2);
		b.add_creature(ROVER, SOUTH, 2, 0);
		b.add_creature(HOPPER, SOUTH, 2, 1);
		b.add_creature(ROVER, SOUTH, 2, 2);

		int turns = 5;
		
		int rate = 1;
		
		play_game(b, turns, cout, rate);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// -------------------
	// 10 - darwin 100x100
	// -------------------
	
	// REMOVED BECAUSE OF BEST
		
	return 0;
}
