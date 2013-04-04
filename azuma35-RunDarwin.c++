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
    
    addCreatures();

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
        world = World(8, 8);
        world.add(Species("food"), EAST, 0, 0);
        world.add(Species("hopper"), NORTH, 3, 3);
        world.add(Species("hopper"), EAST, 3, 4);
        world.add(Species("hopper"), SOUTH, 4, 4);
        world.add(Species("hopper"), WEST, 4, 3);
        world.add(Species("food"), NORTH, 7, 7);
        run(5, 1);
        world.clear();
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
        world = World(7, 9);
        world.add(Species("trap"), SOUTH, 0, 0);
        world.add(Species("hopper"), EAST, 3, 2);
        world.add(Species("rover"), NORTH, 5, 4);
        world.add(Species("trap"), WEST, 6, 8);
        run(5, 1);
        world.clear();
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
        world = World(72, 72);
        
        // Food
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("food"), rand()%4, total%72, total/72);
        }
        
        // Hopper
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("hopper"), rand()%4, total%72, total/72);
        }
        
        // Rover
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("rover"), rand()%4, total%72, total/72);
        }
        
        // Trap
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("trap"), rand()%4, total%72, total/72);
        }
        run(1000, 100);
        world.clear();
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
        world = World(72, 72);
        
        // Food
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("food"), rand()%4, total%72, total/72);
        }
        
        // Hopper
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("hopper"), rand()%4, total%72, total/72);
        }
        
        // Rover
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("rover"), rand()%4, total%72, total/72);
        }
        
        // Trap
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("trap"), rand()%4, total%72, total/72);
        }
        
        // Best
        for(int i = 0; i < 10; ++i) {
            int total = rand() % 5184;
            world.add(Species("best"), rand()%4, total%72, total/72);
        }
        run(1000, 100);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 1x1
    // ----------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        /*
        1x1 Darwin
        Best,   facing east,  at (0, 0)
        Simulate 1 moves.
        Print every grid.
        */
        world = World(1, 1);
        world.add(Species("best"), EAST, 0, 0);
        run(1, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 1x5
    // ----------

    try {
        cout << "*** Darwin 1x5 ***" << endl;
        /*
        1x5 Darwin
        Best,   facing east,  at (0, 0)
        Food,   facing west,  at (0, 3)
        Rover,  facing north, at (0, 4)
        Simulate 8 moves.
        Print every grid.
        */
        world = World(1, 5);
        world.add(Species("best"), EAST, 0, 0);
        world.add(Species("food"), WEST, 0, 3);
        world.add(Species("rover"), NORTH, 0, 4);
        run(8, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 5x1
    // ----------

    try {
        cout << "*** Darwin 5x1 ***" << endl;
        /*
        5x1 Darwin
        Best,   facing east,  at (0, 0)
        Rover,   facing south,  at (4, 0)
        Trap,   facing west,  at (3, 0)
        Food,   facing north,  at (1, 0)
        Simulate 8 moves.
        Print every grid.
        */
        world = World(5, 1);
        world.add(Species("best"), EAST, 0, 0);
        world.add(Species("rover"), SOUTH, 4, 0);
        world.add(Species("trap"), WEST, 3, 0);
        world.add(Species("food"), NORTH, 1, 0);
        run(8, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 3x3
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        world = World(5, 5);
        world.add(Species("best"), WEST, 0, 0);
        world.add(Species("best"), EAST, 2, 2);
        world.add(Species("rover"), NORTH, 2, 0);
        world.add(Species("rover"), SOUTH, 0, 2);
        world.add(Species("food"), WEST, 1, 1);
        world.add(Species("trap"), EAST, 2, 1);
        run(10, 2);
        world.clear();
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
        world = World(3, 3);
        world.add(Species("best"), WEST, 0, 0);
        world.add(Species("best"), EAST, 2, 2);
        world.add(Species("rover"), NORTH, 2, 0);
        world.add(Species("rover"), SOUTH, 0, 2);
        world.add(Species("food"), WEST, 1, 1);
        world.add(Species("trap"), EAST, 2, 1);
        run(10, 2);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 4x4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
        world = World(4, 4);
        world.add(Species("best"), EAST, 0, 0);
        world.add(Species("rover"), NORTH, 3, 3);
        world.add(Species("food"), SOUTH, 2, 2);
        run(5, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 1x2
    // ----------

    try {
        cout << "*** Darwin 1x2 ***" << endl;
        world = World(1, 2);
        world.add(Species("best"), EAST, 0, 0);
        world.add(Species("food"), EAST, 0, 1);
        run(3, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 2x1
    // ----------

    try {
        cout << "*** Darwin 2x1 ***" << endl;
        world = World(2, 1);
        world.add(Species("rover"), EAST, 1, 0);
        world.add(Species("trap"), SOUTH, 0, 0);
        run(3, 1);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 2x3
    // ----------

    try {
        cout << "*** Darwin 2x3 ***" << endl;
        world = World(2, 3);
        world.add(Species("best"), EAST, 1, 1);
        world.add(Species("food"), WEST, 0, 2);
        world.add(Species("trap"), NORTH, 0, 0);
        world.add(Species("food"), WEST, 1, 2);
        run(10, 2);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 80x80
    // ----------

    try {
        cout << "*** Darwin 20x20 ***" << endl;
        /*
        80x80 Darwin
        100 Best
        100 Rover
        100 Food
        Simulate 1000 moves.
        Print every grid.
        */
        world = World(20, 20);
        // Best
        for(int i = 0; i < 100; ++i) {
            int total = rand() % (400);
            world.add(Species("best"), rand()%4, total%20, total/20);
        }
        // Rover
        for(int i = 0; i < 100; ++i) {
            int total = rand() % (400);
            world.add(Species("rover"), rand()%4, total%20, total/20);
        }
        // Food
        for(int i = 0; i < 100; ++i) {
            int total = rand() % (400);
            world.add(Species("food"), rand()%4, total%20, total/20);
        }
        run(1000, 100);
        world.clear();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
