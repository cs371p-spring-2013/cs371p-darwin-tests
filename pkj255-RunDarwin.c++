// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunDarwin.c++ -o RunDarwin
    % valgrind RunDarwin > RunDarwin.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

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
    // ----------
    // darwin 8x8
    // ----------

    try {
		cout << "*** Darwin 8x8 ***" <<endl;
        /*
        8x8 Darwin
        Food,   facing east,  at (0, 0)
        Hopper, facing north, at (3, 3)
        Hopper, facing east,  at (3, 4)
        Hopper, facing south, at (4, 4)
        Hopper, facing west,  at (4, 3)
        Food,   facing north, at (7, 7)
        Simulate 5 moves.
        Print every grid.
        */
		Game g(8,8, cout);
		Creature reza = Creature(0 ,0 ,EAST ,'f' );
		g.addCreature(0, 0, EAST, 'f', reza);

		Creature reza2 = Creature(3, 3, NORTH, 'h');
		g.addCreature(3, 3, NORTH, 'h', reza2);

		Creature reza3 = Creature(3, 4, EAST, 'h');
		g.addCreature(3, 4, EAST, 'h', reza3);

		Creature reza4 = Creature(4, 4, SOUTH, 'h');
		g.addCreature(4, 4, SOUTH, 'h', reza4);

		Creature reza5 = Creature(4, 3, WEST, 'h');
		g.addCreature(4, 3, WEST, 'h', reza5);

		Creature reza6 = Creature(7, 7, NORTH, 'f');
		g.addCreature(7, 7, NORTH, 'f', reza6);
		
		g.play(5, 1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
		cout << "*** Darwin 7x9 ***" <<endl;
        srand(0);
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
		Game g(7, 9, cout);

		Creature reza = Creature(0, 0, SOUTH, 't');
		g.addCreature(0, 0, SOUTH, 't', reza);

		Creature reza2 = Creature(3, 2, EAST, 'h');
		g.addCreature(3, 2, EAST, 'h', reza2);

		Creature reza3 = Creature(5, 4, NORTH, 'r');
		g.addCreature(5, 4, NORTH, 'r', reza3);

		Creature reza4 = Creature(6, 8, WEST, 't');
		g.addCreature(6, 8, WEST, 't', reza4);
		g.print(cout);
		g.play(5, 1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
	// ----------
    // darwin 2x2 b vs b
    // ----------
		cout << "*** Darwin 2x2 ***" <<endl;
		srand(0);
		Game g(2, 2, cout);
		Creature steve = Creature(0, 0, WEST, 'b');
		g.addCreature(0, 0, WEST, 'b', steve);
		Creature john = Creature(1, 1, EAST, 'b');
		g.addCreature(1, 1, EAST, 'b', john);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}

	try {
	// ----------
    // darwin 12x12 b vs b
    // ----------
		cout << "*** Darwin 12x12 ***" <<endl;
		srand(0);
		Game g(12, 12, cout);
		Creature steve = Creature(0, 0, WEST, 'b');
		g.addCreature(0, 0, WEST, 'b', steve);
		Creature john = Creature(11, 11, EAST, 'b');
		g.addCreature(11, 11, EAST, 'b', john);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}

	try {
	// ----------
    // darwin 12x12 b vs r
    // ----------
		cout << "*** Darwin 12x12 ***" <<endl;
		srand(0);
		Game g(12, 12, cout);
		Creature steve = Creature(5, 9, NORTH, 'b');
		g.addCreature(5, 9, NORTH, 'b', steve);
		Creature john = Creature(1, 8, EAST, 'r');
		g.addCreature(1, 8, EAST, 'r', john);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}

	try {
	// ----------
    // darwin 15x15 b vs t
    // ----------
		cout << "*** Darwin 15x15 ***" <<endl;
		srand(0);
		Game g(15, 15, cout);
		Creature steve = Creature(5, 9, NORTH, 'b');
		g.addCreature(5, 9, NORTH, 'b', steve);
		Creature steve2 = Creature(8, 7, EAST, 'b');
		g.addCreature(8, 7, EAST, 'b', steve2);
		Creature steve3 = Creature(1, 1, WEST, 'b');
		g.addCreature(1, 1, WEST, 'b', steve3);
		Creature steve4 = Creature(0, 5, NORTH, 'b');
		g.addCreature(0, 5, SOUTH, 'b', steve4);

		Creature john = Creature(3, 3, NORTH, 't');
		g.addCreature(3, 3, NORTH, 't', john);
		Creature john2 = Creature(11, 11, EAST, 't');
		g.addCreature(11, 11, EAST, 't', john2);
		Creature john3 = Creature(7 ,6 , WEST, 't');
		g.addCreature(7, 6, WEST, 't', john3);
		Creature john4 = Creature(1, 8, SOUTH, 't');
		g.addCreature(1, 8, SOUTH, 't', john4);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}

try {
	// ----------
    // darwin 15x15 b vs f
    // ----------
		cout << "*** Darwin 15x15 ***" <<endl;
		srand(0);
		Game g(15, 15, cout);
		Creature steve = Creature(5, 9, NORTH, 'b');
		g.addCreature(5, 9, NORTH, 'b', steve);
		Creature steve2 = Creature(8, 7, EAST, 'b');
		g.addCreature(8, 7, EAST, 'b', steve2);
		Creature steve3 = Creature(1, 1, WEST, 'b');
		g.addCreature(1, 1, WEST, 'b', steve3);
		Creature steve4 = Creature(0, 5, NORTH, 'b');
		g.addCreature(0, 5, SOUTH, 'b', steve4);

		Creature john = Creature(3, 3, NORTH, 'f');
		g.addCreature(3, 3, NORTH, 'f', john);
		Creature john2 = Creature(11, 11, EAST, 'f');
		g.addCreature(11, 11, EAST, 'f', john2);
		Creature john3 = Creature(7 ,6 , WEST, 'f');
		g.addCreature(7, 6, WEST, 'f', john3);
		Creature john4 = Creature(1, 8, SOUTH, 'f');
		g.addCreature(1, 8, SOUTH, 'f', john4);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}


try {
	// ----------
    // darwin 15x15 b vs h
    // ----------
		cout << "*** Darwin 15x15 ***" <<endl;
		srand(0);
		Game g(15, 15, cout);
		Creature steve = Creature(5, 9, NORTH, 'b');
		g.addCreature(5, 9, NORTH, 'b', steve);
		Creature steve2 = Creature(8, 7, EAST, 'b');
		g.addCreature(8, 7, EAST, 'b', steve2);
		Creature steve3 = Creature(1, 1, WEST, 'b');
		g.addCreature(1, 1, WEST, 'b', steve3);
		Creature steve4 = Creature(0, 5, NORTH, 'b');
		g.addCreature(0, 5, SOUTH, 'b', steve4);

		Creature john = Creature(3, 3, NORTH, 'h');
		g.addCreature(3, 3, NORTH, 'h', john);
		Creature john2 = Creature(11, 11, EAST, 'h');
		g.addCreature(11, 11, EAST, 'h', john2);
		Creature john3 = Creature(7 ,6 , WEST, 'h');
		g.addCreature(7, 6, WEST, 'h', john3);
		Creature john4 = Creature(1, 8, SOUTH, 'h');
		g.addCreature(1, 8, SOUTH, 'h', john4);
		g.play(100, 10, cout);	
	}
	catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}

    // ------------
    // darwin 72x72
    // without best
    // ------------

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
		Game g(72,72, cout);
		//food
		int num = rand() % 5184;
		int row = num / 72;
		int col = num % 72;
		int dir = rand() % 4;
		Creature f0 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f1 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f1);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f2 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f3 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f4 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f5 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f6 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f7 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f8 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f9 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f9);
		
		//hopper
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h0 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h1 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h1);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h2 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h3 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h4 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h5 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h5);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h6 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h6);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h7 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h7);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h8 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h9 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h9);

		//rover
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r0 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r1 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r1);
		
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r2 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r3 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r4 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r5 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r6 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r7 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r8 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r9 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r9);

		//trap
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t0 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t1 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t1);		

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t2 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t3 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t4 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t5 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t6 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t7 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t8 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t9 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t9);												

		g.play(1000,100,cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    try {
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 5184 (72x72), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        10 Best
        Simulate 1000 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
		Game g(72,72, cout);
		//food
		int num = rand() % 5184;
		int row = num / 72;
		int col = num % 72;
		int dir = rand() % 4;
		Creature f0 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f1 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f1);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f2 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f3 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f4 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f5 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f6 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f7 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f8 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature f9 = Creature(row, col, dir, 'f');
		g.addCreature(row, col, dir, 'f', f9);
		
		//hopper
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h0 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h1 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h1);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h2 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h3 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h4 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h5 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h5);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h6 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h6);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h7 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h7);

				num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h8 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature h9 = Creature(row, col, dir, 'h');
		g.addCreature(row, col, dir, 'h', h9);

		//rover
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r0 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r1 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r1);
		
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r2 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r3 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r4 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r5 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r6 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r7 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r8 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature r9 = Creature(row, col, dir, 'r');
		g.addCreature(row, col, dir, 'r', r9);

		//trap
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t0 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t1 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t1);		

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t2 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t3 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t4 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t5 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t6 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t7 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t8 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature t9 = Creature(row, col, dir, 't');
		g.addCreature(row, col, dir, 't', t9);

		//BEST
		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b0 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b0);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b1 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b1);		

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b2 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b2);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b3 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b3);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b4 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b4);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b5 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b5);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b6 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b6);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b7 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b7);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b8 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b8);

		num = rand() % 5184;
		row = num / 72;
		col = num % 72;
		dir = rand() % 4;
		Creature b9 = Creature(row, col, dir, 'b');
		g.addCreature(row, col, dir, 'b', b9);											

		g.play(1000,100,cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& e) {
        assert(false);}
	


    return 0;}

