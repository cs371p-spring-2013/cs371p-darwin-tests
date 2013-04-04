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
        cout << "*** Darwin 8x8 ***" << endl;
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
        gameSetup(8, 8);
        addCreature(FOOD, EAST, 0, 0);
        addCreature(HOPPER, NORTH, 3, 3);
        addCreature(HOPPER, EAST, 3, 4);
        addCreature(HOPPER, SOUTH, 4, 4);
        addCreature(HOPPER, WEST, 4, 3);
        addCreature(FOOD, NORTH, 7, 7);
        play(5);
        }
    catch (const invalid_argument&) {
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
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        gameSetup(7, 9);
        addCreature(TRAP, SOUTH, 0, 0);
        addCreature(HOPPER, EAST, 3, 2);
        addCreature(ROVER, NORTH, 5, 4);
        addCreature(TRAP, WEST, 6, 8);
        play(5);
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
        gameSetup(72, 72);
        int r;
        int row;
        int column;
        Species_name s = FOOD;
        Directions direc;
        for (int i = 0; i < 40; ++i) {
          if (i == 10)
            s = HOPPER;
          else if (i == 20)
            s = ROVER;
          else if (i == 30)
            s = TRAP;
          r = rand() % 5184;
          row = r / 72;
          column = r % 72;
          direc = (Directions)(rand() % 4);
          addCreature(s, direc, row, column);
        }
        play(1000, 100);
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
        gameSetup(72, 72);
        int r;
        int row;
        int column;
        Species_name s = FOOD;
        Directions direc;
        for (int i = 0; i < 50; ++i) {
          if (i == 10)
            s = HOPPER;
          else if (i == 20)
            s = ROVER;
          else if (i == 30)
            s = TRAP;
          else if (i == 40)
            s = BEST;
          r = rand() % 5184;
          row = r / 72;
          column = r % 72;
          direc = (Directions)(rand() % 4);
          addCreature(s, direc, row, column);
        }
        play(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---
    // Darwin 1x1
    // ---

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        /*
        1x1 Darwin
        Food,   facing north,  at (0, 0)
        Simulate 3 moves.
        Print every grid.
        */
        gameSetup(1, 1);
        addCreature(FOOD, EAST, 0, 0);
        play(3);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---
    // Darwin 1x20
    // ---

    try {
        cout << "*** Darwin 1x20 ***" << endl;
        /*
        Hopper,   facing east,  at (0, 0)
        Trap,     facing north, at (0, 10)
        Hopper,   facing west,  at (0, 19)
        Simulate 20 moves.
        Print every 5 grids.
        */
        gameSetup(1, 20);
        addCreature(HOPPER, EAST, 0, 0);
        addCreature(TRAP, NORTH, 0, 10);
        addCreature(HOPPER, WEST, 0, 19);
        play(20, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---
    // Darwin 9x7
    // ---

    try {
        cout << "*** Darwin 9x7 ***" << endl;
        srand(0);
        /*
        Trap,     facing north, at (0, 0)
        Hopper,   facing east,  at (0, 2)
        Trap,     facing north, at (0, 6)
        Hopper,   facing south, at (2, 6)
        Rover,    facing north, at (8, 0)
        Simulate 10 moves.
        Print every other grid.
        */
        gameSetup(9, 7);
        addCreature(TRAP, NORTH, 0, 0);
        addCreature(HOPPER, EAST, 0, 2);
        addCreature(TRAP, NORTH, 0, 6);
        addCreature(HOPPER, SOUTH, 2, 6);
        addCreature(ROVER, NORTH, 8, 0);
        play(10, 2);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---
    // Darwin 5x1
    // ---

    try {
        cout << "*** Darwin 5x1 ***" << endl;
        srand(0);
        /*
        Trap,     facing east,  at (0, 0)
        Rover,    facing north, at (4, 0)
        Simulate 5 moves.
        Print every grid.
        */
        gameSetup(5, 1);
        addCreature(TRAP, EAST, 0, 0);
        addCreature(ROVER, NORTH, 4, 0);
        play(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---
    // Darwin 3x7
    // ---

    try {
        cout << "*** Darwin 3x7 ***" << endl;
        /*
        Trap,     facing south, at (1, 1)
        Food,     facing west,  at (1, 2)
        Food,     facing north, at (1, 3)
        Food,     facing east,  at (1, 4)
        Food,     facing south, at (1, 5)
        Simulate 6 moves.
        Print every grid.
        */
        gameSetup(3, 7);
        addCreature(TRAP, SOUTH, 1, 1);
        addCreature(FOOD, WEST, 1, 2);
        addCreature(FOOD, NORTH, 1, 3);
        addCreature(FOOD, EAST, 1, 4);
        addCreature(FOOD, SOUTH, 1, 5);
        play(6);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---
    // Darwin 100x100
    // ---

    try {
        cout << "*** Darwin 100x100 with Best ***" << endl;
        srand(0);
        /*
        200 food placed randomly
        1 rover
        1 best
        Simulate 1000 moves.
        Print every 100 grids.
        */
        gameSetup(100, 100);
        int r;
        int row;
        int column;
        Species_name s = FOOD;
        Directions direc;
        for (int i = 0; i < 202; ++i) {
          if (i == 200)
            s = ROVER;
          else if (i == 201)
            s = BEST;
          r = rand() % 10000;
          row = r / 100;
          column = r % 100;
          direc = (Directions)(rand() % 4);
          addCreature(s, direc, row, column);
        }
        play(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

