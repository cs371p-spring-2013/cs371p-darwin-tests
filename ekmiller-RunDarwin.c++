// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunCollatz.c++ -o RunCollatz.c++.app
    % valgrind RunDarwin.c++.app > RunDarwin.out

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

using namespace std;

// ----
// main
// ----

int main () {
    ios_base::sync_with_stdio(false);
	enum compass {WEST, NORTH, EAST, SOUTH};
	enum species {FOOD, TRAP, HOPPER, ROVER, BEST};

    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "(1) *** Darwin 8x8 ***" << endl;
        Darwin darwin(8,8);
		darwin.add_creature(Creature(FOOD,   EAST),  darwin.row_major(0,0));
		darwin.add_creature(Creature(HOPPER, NORTH), darwin.row_major(3,3));
		darwin.add_creature(Creature(HOPPER, EAST),  darwin.row_major(3,4));
		darwin.add_creature(Creature(HOPPER, SOUTH), darwin.row_major(4,4));
		darwin.add_creature(Creature(HOPPER, WEST),  darwin.row_major(4,3));
		darwin.add_creature(Creature(FOOD,   NORTH), darwin.row_major(7,7));
		darwin.print();
		for(int i = 0; i < 5; ++i) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        cout << "(2) *** Darwin 7x9 ***" << endl;
        srand(0);
        Darwin darwin(7,9);
		darwin.add_creature(Creature(TRAP,   SOUTH), darwin.row_major(0,0));
		darwin.add_creature(Creature(HOPPER, EAST),  darwin.row_major(3,2));
		darwin.add_creature(Creature(ROVER,  NORTH), darwin.row_major(5,4));
		darwin.add_creature(Creature(TRAP,   WEST),  darwin.row_major(6,8));
		darwin.print();
		for(int i = 0; i < 5; ++i) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // without best
    // ------------

    try {
        cout << "(3) *** Darwin 72x72 without Best ***" << endl;
        srand(0);
		Darwin darwin(72,72);
		int direction;
		int position;
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(FOOD,   direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(HOPPER, direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(ROVER,  direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(TRAP,   direction), position); }
		darwin.print();
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 100; ++j)
				darwin.step(); 
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    try {
        cout << "(4) *** Darwin 72x72 with Best ***" << endl;
        srand(0);
		Darwin darwin(72,72);
		int direction;
		int position;
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(FOOD,   direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(HOPPER, direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(ROVER,  direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(TRAP,   direction), position); }
		for(int i = 0; i < 10; ++i) {
			position = rand() % 5184;
			direction = rand() % 4;
			darwin.add_creature(Creature(BEST,   direction), position); }
		darwin.print();
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 100; ++j)
				darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }


	try {
        cout << "(5) *** Darwin 10x10  ***" << endl;
        srand(0);
		Darwin darwin(10,10);
		darwin.add_creature(Creature(TRAP, NORTH),  darwin.row_major(0,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(1,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(2,0));
		darwin.add_creature(Creature(TRAP, SOUTH),  darwin.row_major(3,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(4,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(5,0));
		darwin.add_creature(Creature(TRAP, WEST),   darwin.row_major(6,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(7,0));
		darwin.add_creature(Creature(TRAP, WEST),   darwin.row_major(8,0));
		darwin.add_creature(Creature(TRAP, EAST),   darwin.row_major(9,0));
		darwin.add_creature(Creature(HOPPER, EAST), darwin.row_major(0,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(1,9));
		darwin.add_creature(Creature(HOPPER, WEST), darwin.row_major(2,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(3,9));
		darwin.add_creature(Creature(HOPPER, WEST), darwin.row_major(4,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(5,9));
		darwin.add_creature(Creature(HOPPER, WEST), darwin.row_major(6,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(7,9));
		darwin.add_creature(Creature(HOPPER, WEST), darwin.row_major(8,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(9,9));
		darwin.print();
		for(int j = 0; j < 20; ++j) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }

	try {
        cout << "(6) *** Darwin 1x10 ***" << endl;
        srand(0);
		Darwin darwin(1,10);
		for(int i = 0; i < 8; i += 2) {
			darwin.add_creature(Creature(BEST,  EAST), i);
			darwin.add_creature(Creature(ROVER, EAST), i+1); }
		darwin.add_creature(Creature(FOOD, NORTH), 9);
		darwin.print();
		for(int i = 0; i < 10; ++i) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }

try {
        cout << "(7) *** Darwin 10x10  ***" << endl;
        srand(0);
		Darwin darwin(10,10);
		darwin.add_creature(Creature(BEST, EAST), darwin.row_major(2,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(1,9));
		darwin.add_creature(Creature(BEST, WEST), darwin.row_major(2,5));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(3,9));
		darwin.add_creature(Creature(BEST, EAST), darwin.row_major(4,4));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(5,9));
		darwin.add_creature(Creature(BEST, NORTH), darwin.row_major(6,6));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(7,9));
		darwin.add_creature(Creature(BEST, WEST), darwin.row_major(3,2));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(9,2));
		darwin.print();
		for(int j = 0; j < 30; ++j) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }

try {
        cout << "(8) *** Darwin 10x10  ***" << endl;
        srand(0);
		Darwin darwin(10,10);
		darwin.add_creature(Creature(FOOD, EAST), darwin.row_major(2,9));
		darwin.add_creature(Creature(TRAP, WEST),  darwin.row_major(1,9));
		darwin.add_creature(Creature(HOPPER, WEST), darwin.row_major(2,5));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(3,3));
		darwin.add_creature(Creature(BEST, EAST), darwin.row_major(4,4));
		darwin.add_creature(Creature(FOOD, WEST),  darwin.row_major(5,9));
		darwin.add_creature(Creature(BEST, NORTH), darwin.row_major(6,6));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(7,9));
		darwin.add_creature(Creature(TRAP, WEST), darwin.row_major(3,9));
		darwin.add_creature(Creature(ROVER, WEST),  darwin.row_major(9,2));
		darwin.print();
		for(int j = 0; j < 30; ++j) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }

try {
        cout << "(9) *** Darwin 1x10  ***" << endl;
        srand(0);
		Darwin darwin(1,10);
		darwin.add_creature(Creature(BEST, EAST), darwin.row_major(0,0));
		darwin.print();
		for(int j = 0; j < 30; ++j) {
			darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }

try {
        cout << "(10) *** Darwin 1x10  ***" << endl;
        srand(0);
		Darwin darwin(10,10);
		int direction;
		int position;
		for(int i = 0; i < 3; ++i) {
			position = rand() % 100;
			position = position - 1;
			direction = rand() % 4;
			darwin.add_creature(Creature(FOOD,   direction), position); }
		for(int i = 0; i < 3; ++i) {
			position = rand() % 100;
			position = position - 1;
			direction = rand() % 4;
			darwin.add_creature(Creature(HOPPER, direction), position); }
		for(int i = 0; i < 3; ++i) {
			position = rand() % 100;
			position = position - 1;
			direction = rand() % 4;
			darwin.add_creature(Creature(ROVER,  direction), position); }
		for(int i = 0; i < 3; ++i) {
			position = rand() % 100;
			position = position - 1;
			direction = rand() % 4;
			darwin.add_creature(Creature(BEST,   direction), position); }
		darwin.add_creature(Creature(TRAP, NORTH), darwin.row_major(0,0));
		darwin.add_creature(Creature(TRAP, NORTH), darwin.row_major(9,0));
		darwin.add_creature(Creature(TRAP, NORTH), darwin.row_major(0,9));
		darwin.add_creature(Creature(TRAP, NORTH), darwin.row_major(9,9));
		darwin.print(); 
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 10; ++j)
				darwin.step();
			darwin.print(); } }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false); }
    return 0;}
