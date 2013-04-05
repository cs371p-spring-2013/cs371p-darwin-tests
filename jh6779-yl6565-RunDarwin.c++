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
        Game g = Game(8,8);
        g.add("Food",EAST,0,0);
        g.add("Hopper",NORTH,3,3);
        g.add("Hopper",EAST,3,4);
        g.add("Hopper",SOUTH,4,4);
        g.add("Hopper",WEST,4,3);
        g.add("Food",NORTH,7,7);
        g.run(cout, 5, 1);
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
        Game g = Game(7,9);
        g.add("Trap",SOUTH,0,0);
        g.add("Hopper",EAST,3,2);
        g.add("Rover",NORTH,5,4);
        g.add("Trap",WEST,6,8);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Rover,  facing north, at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(1,1);
        g.add("Rover",NORTH,0,0);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Food,  facing north, at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(1,1);
        g.add("Food",NORTH,0,0);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Hopper,  facing north, at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(1,1);
        g.add("Hopper",NORTH,0,0);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Trap,  facing north, at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(1,1);
        g.add("Trap",NORTH,0,0);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Best,  facing north, at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(1,1);
        g.add("Best",NORTH,0,0);
        g.run(cout, 5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 5x3
    // ------------

    try {
        cout << "*** Darwin 5x3 ***" << endl;
        srand(0);
        /*
        5x3 Darwin
        Food,   facing south, at (0, 0)
        Food,   facing south, at (0, 2)
        Food,   facing south, at (4, 0)
        Food,   facing south, at (4, 2)
        Hopper, facing north,  at (3, 2)
        Rover,  facing north, at (1, 1)
        Trap,   facing west,  at (3, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(15,15);
        g.add("Food",SOUTH,0,0);
        g.add("Food",SOUTH,0,2);
        g.add("Food",SOUTH,4,0);
        g.add("Food",SOUTH,4,2);
        g.add("Hopper",NORTH,3,2);
        g.add("Rover",NORTH,1,1);
        g.add("Trap",WEST,3,1);
        g.run(cout, 15, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 4x4
    // ------------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
        srand(0);
        /*
        5x3 Darwin
        Food,   facing south, at (0, 0)
        Food,   facing south, at (0, 3)
        Food,   facing south, at (3, 0)
        Food,   facing south, at (3, 3)
        Hopper, facing north,  at (3, 2)
        Rover,  facing north, at (1, 1)
        Trap,   facing west,  at (3, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(15,15);
        g.add("Food",SOUTH,0,0);
        g.add("Food",SOUTH,0,2);
        g.add("Food",SOUTH,3,0);
        g.add("Food",SOUTH,3,3);
        g.add("Hopper",NORTH,3,2);
        g.add("Rover",NORTH,1,1);
        g.add("Trap",WEST,3,1);
        g.run(cout, 16, 2);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 3x3
    // ------------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);
        /*
        3x3 Darwin
        Food,   facing south, at (0, 0)
        Food,   facing south, at (2, 0)
        Food,   facing south, at (0, 2)
        Food,   facing south, at (2, 2)
        Hopper, facing north,  at (2, 1)
        Hopper, facing east,  at (1, 0)
        Hopper, facing west,  at (1, 1)
        Rover,  facing north, at (1, 2)
        Trap,   facing west,  at (0, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(15,15);
        g.add("Food",SOUTH,0,0);
        g.add("Food",SOUTH,2,0);
        g.add("Food",SOUTH,0,2);
        g.add("Food",SOUTH,2,2);
        g.add("Hopper",NORTH,2,1);
        g.add("Hopper",EAST,1,0);
        g.add("Hopper",WEST,1,1);
        g.add("Rover",NORTH,1,2);
        g.add("Trap",WEST,0,1);
        g.run(cout, 7, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 15x15
    // ------------

    try {
        cout << "*** Darwin 15x15 ***" << endl;
        srand(0);
        /*
        15x15 Darwin
        Food,   facing south, at (0, 0)
        Food,   facing south, at (1, 0)
        Food,   facing south, at (0, 14)
        Food,   facing south, at (5, 8)
        Hopper, facing north,  at (3, 2)
        Hopper, facing east,  at (10, 7)
        Best, facing west,  at (8, 5)
        Best, facing south,  at (3, 3)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(15,15);
        g.add("Food",SOUTH,0,0);
        g.add("Food",SOUTH,1,0);
        g.add("Food",SOUTH,0,14);
        g.add("Food",SOUTH,5,8);
        g.add("Hopper",NORTH,3,2);
        g.add("Hopper",EAST,10,7);
        g.add("Best",WEST,8,5);
        g.add("Best",SOUTH,3,3);
        g.add("Rover",NORTH,5,4);
        g.add("Trap",WEST,6,8);
        g.run(cout, 15, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 15x15
    // ------------

    try {
        cout << "*** Darwin 15x15 ***" << endl;
        srand(0);
        /*
        15x15 Darwin
        Food,   facing south, at (0, 0)
        Food,   facing south, at (1, 0)
        Food,   facing south, at (0, 14)
        Food,   facing south, at (5, 8)
        Hopper, facing north,  at (3, 2)
        Hopper, facing east,  at (10, 7)
        Hopper, facing west,  at (8, 5)
        Hopper, facing south,  at (3, 3)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        Game g = Game(15,15);
        g.add("Food",SOUTH,0,0);
        g.add("Food",SOUTH,1,0);
        g.add("Food",SOUTH,0,14);
        g.add("Food",SOUTH,5,8);
        g.add("Hopper",NORTH,3,2);
        g.add("Hopper",EAST,10,7);
        g.add("Hopper",WEST,8,5);
        g.add("Hopper",SOUTH,3,3);
        g.add("Rover",NORTH,5,4);
        g.add("Trap",WEST,6,8);
        g.run(cout, 15, 1);
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
        Game g = Game(72,72);
        vector<string> names = {"Food", "Hopper", "Rover", "Trap"};
        for(int i = 0; i < 4; i++){
          for(int j = 0; j < 10; j++){
            int c = rand() % 5184;
            int row = c/72;
            int col = c%72;
            while(!g.empty(row,col)){
              c = rand() % 5184;
              row = c/72;
              col = c%72;}

            int dir = rand()%4;
            g.add(names[i], dir, row, col);}}
        g.run(cout,1000,100);
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
        Game g = Game(72,72);
        vector<string> names = {"Food", "Hopper", "Rover", "Trap", "Best"};
        for(int i = 0; i < 5; i++){
          for(int j = 0; j < 10; j++){
            int c = rand() % 5184;
            int row = c/72;
            int col = c%72;
            while(!g.empty(row,col)){
              c = rand() % 5184;
              row = c/72;
              col = c%72;}

            int dir = rand()%4;
            g.add(names[i], dir, row, col);}}
        g.run(cout,1000,100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
