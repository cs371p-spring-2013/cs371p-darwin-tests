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

#include <cassert> // assert
#include <cstdlib> // rand, srand
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"


// ----
// main
// ----

int main () {
    using namespace std;
    //ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

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
        cout << "*** Darwin 8x8 ***" << endl;
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

		Board b1(8, 8);

		int pos1[] = {0,0};
		Food f1('f', &b1, EAST);
		GridElement ge1(f1, pos1);
		b1.addGridElement(ge1);

		int pos2[] = {3,3};
		Hopper h1('h', &b1, NORTH);
		GridElement ge2(h1, pos2);
		b1.addGridElement(ge2);
		
		int pos3[] = {3,4};
		Hopper h2('h', &b1, EAST);
		GridElement ge3(h2, pos3);
		b1.addGridElement(ge3);
		
		int pos4[] = {4,4};
		Hopper h3('h', &b1, SOUTH);
		GridElement ge4(h3, pos4);
		b1.addGridElement(ge4);
		
		int pos5[] = {4,3};
		Hopper h4('h', &b1, WEST);
		GridElement ge5(h4, pos5);
		b1.addGridElement(ge5);
		
		int pos6[] = {7,7};
		Food f2('f', &b1, NORTH);
		GridElement ge6(f2, pos6);
		b1.addGridElement(ge6);
		
		b1.run(5, 1);
		
 	} catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

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
		
		Board b2(7, 9);
		
		int p1[] = {0,0};
		int p2[] = {3,2};
		int p3[] = {5,4};
		int p4[] = {6,8};
		Trap t1('t', &b2, SOUTH);
		Hopper h1('h', &b2, EAST);
		Rover r1('r', &b2, NORTH);
		Trap t2('t', &b2, WEST);
		GridElement ge1(t1, p1);
		GridElement ge2(h1, p2);
		GridElement ge3(r1, p3);
		GridElement ge4(t2, p4);
		b2.addGridElement(ge1);
		b2.addGridElement(ge2);
		b2.addGridElement(ge3);
		b2.addGridElement(ge4);
		
		b2.run(5, 1);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
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
		
		Board b3(72, 72);
		int x;
		int y;
		int direction;
		int position;
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Food f('f', &b3, direction);
			GridElement ge(f, pos);
			b3.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Hopper h('h', &b3, direction);
			GridElement ge(h, pos);
			b3.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Rover r('r', &b3, direction);
			GridElement ge(r, pos);
			b3.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Trap t('t', &b3, direction);
			GridElement ge(t, pos);
			b3.addGridElement(ge);
		}
		
		b3.run(1000, 100);
		
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
		
		Board b4(72, 72);
		int x;
		int y;
		int direction;
		int position;
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Food f('f', &b4, direction);
			GridElement ge(f, pos);
			b4.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Hopper h('h', &b4, direction);
			GridElement ge(h, pos);
			b4.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Rover r('r', &b4, direction);
			GridElement ge(r, pos);
			b4.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			Trap t('t', &b4, direction);
			GridElement ge(t, pos);
			b4.addGridElement(ge);
		}
		
		for (int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			x = (int)(position / 72);
			y = position % 72;
			int pos[] = {x, y};
			direction = rand() % 4;
			MutantRover mr('b', &b4, direction);
			GridElement ge(mr, pos);
			b4.addGridElement(ge);
		}
		
		b4.run(1000, 100);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}