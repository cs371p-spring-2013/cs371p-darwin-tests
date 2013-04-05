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
    // darwin 10x1
    // ----------

    try { 
        /*
        rover facing north at (5,0)
        */
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        Game g (10, 1);
        g.addCreature(Creature(NORTH, 5, 0, ROVER));
        g.insertGamePieces();
        g.runGame(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 1x10
    // ----------

    try { 
        /*
        rover facing north at (0, 5)
        */
        cout << "*** Darwin 1x10 ***" << endl;
        srand(0);
        Game g (1, 10);
        g.addCreature(Creature(NORTH, 0, 5, ROVER));
        g.insertGamePieces();
        g.runGame(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 2x2
    // ----------

    try { 
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        Game g (2, 2);
        g.addCreature(Creature(NORTH, 0, 0, ROVER));
        g.addCreature(Creature(SOUTH, 0, 1, ROVER));
        g.addCreature(Creature(EAST, 1, 0, ROVER));
        g.addCreature(Creature(WEST, 1, 1, ROVER));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 3x3
    // ----------

    try { 
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);
        Game g (3, 3);
        g.addCreature(Creature(NORTH, 0, 0, TRAP));
        g.addCreature(Creature(SOUTH, 0, 2, TRAP));
        g.addCreature(Creature(EAST, 2, 0, TRAP));
        g.addCreature(Creature(WEST, 2, 2, TRAP));
        g.addCreature(Creature(WEST, 1, 1, ROVER));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try { 
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        Game g (5, 5);
        g.addCreature(Creature(EAST, 2, 0, ROVER));
        g.addCreature(Creature(SOUTH, 0, 2, ROVER));
        g.addCreature(Creature(WEST, 2, 4, ROVER));
        g.addCreature(Creature(NORTH, 4, 2, ROVER));
        g.addCreature(Creature(WEST, 2, 2, ROVER));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}    
    // ----------
    // darwin 8x8
    // ----------

    try { 
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
        cout << "*** Darwin 8x8 ***" << endl;
        srand(0);
        Game g (8, 8);
        g.addCreature(Creature(EAST, 0, 0, FOOD));
        g.addCreature(Creature(NORTH, 3, 3, HOPPER));
        g.addCreature(Creature(EAST, 3, 4, HOPPER));
        g.addCreature(Creature(SOUTH, 4, 2, HOPPER));
        g.addCreature(Creature(WEST, 4, 3, HOPPER));
        g.addCreature(Creature(NORTH, 7, 6, FOOD));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try { 
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
        cout << "*** Darwin 7x7 ***" << endl;
        srand(0);
        Game g (8, 8);
        g.addCreature(Creature(EAST, 0, 0, FOOD));
        g.addCreature(Creature(NORTH, 3, 3, HOPPER));
        g.addCreature(Creature(EAST, 3, 4, HOPPER));
        g.addCreature(Creature(SOUTH, 4, 2, HOPPER));
        g.addCreature(Creature(WEST, 4, 3, HOPPER));
        g.addCreature(Creature(NORTH, 7, 6, FOOD));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try { 
        /*
        10x10 Darwin
        Food,   facing east,  at (0, 0)
        Hopper, facing north, at (3, 3)
        Hopper, facing east,  at (3, 4)
        Hopper, facing south, at (4, 4)
        Hopper, facing west,  at (4, 3)
        Food,   facing north, at (7, 7)
        Simulate 5 moves.
        Print every grid.
        */
        cout << "*** Darwin 8x8 ***" << endl;
        srand(0);
        Game g (12, 12);
        g.addCreature(Creature(EAST, 0, 0, FOOD));
        g.addCreature(Creature(NORTH, 3, 3, HOPPER));
        g.addCreature(Creature(EAST, 3, 4, HOPPER));
        g.addCreature(Creature(SOUTH, 4, 4, HOPPER));
        g.addCreature(Creature(WEST, 4, 3, HOPPER));
        g.addCreature(Creature(NORTH, 7, 7, FOOD));
        g.insertGamePieces();
        g.runGame(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);
        Game g (7, 9);
        g.addCreature(Creature(SOUTH, 0, 0, TRAP));
        g.addCreature(Creature(EAST, 3, 2, HOPPER));
        g.addCreature(Creature(NORTH, 5, 4, ROVER));
        g.addCreature(Creature(WEST, 6, 8, TRAP));
        g.insertGamePieces();
        g.runGame(5, 1);
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

        Game g (72, 72);
        // insert food
        int n = 72;
        int mod = n * n;
        for (int i = 0; i < 10; ++i){
            int position = (rand() % mod);
            int direction = rand() % 4;
            g.addCreature(Creature(direction, position / n, position % n, FOOD));
        }
        // insert hopper
        for (int i = 0; i < 10; ++i){
            int position = (rand() % mod);
            int direction = rand() % 4;
            g.addCreature(Creature(direction, position / n, position % n, HOPPER));
        }
        // insert rover
        for (int i = 0; i < 10; ++i){
            int position = (rand() % mod);
            int direction = rand() % 4;
            g.addCreature(Creature(direction, position / n, position % n, ROVER));
        }

        // insert trap
        for (int i = 0; i < 10; ++i){
            int position = (rand() % mod);
            int direction = rand() % 4;
            g.addCreature(Creature(direction, position / n, position % n, TRAP));
        }
        g.insertGamePieces();
        g.runGame(1000, 100);
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
        // cout << "*** Darwin 72x72 with Best ***" << endl;
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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}