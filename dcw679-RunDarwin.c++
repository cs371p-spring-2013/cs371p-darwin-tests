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


    // Note: the species program are defined in Darwin.c++

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
        srand(0);
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

        Board b(8,8);
        b.placeCreature(Creature(food), east, 0, 0);
        b.placeCreature(Creature(hopper), north, 3, 3);
        b.placeCreature(Creature(hopper), east, 3, 4);
        b.placeCreature(Creature(hopper), south, 4, 4);
        b.placeCreature(Creature(hopper), west, 4, 3);
        b.placeCreature(Creature(food), north, 7, 7);
        b.run(5, 5);	
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

        Board b(7, 9);
        b.placeCreature(Creature(trap), south, 0, 0);
        b.placeCreature(Creature(hopper), east, 3, 2);
        b.placeCreature(Creature(rover), north, 5, 4);
        b.placeCreature(Creature(trap), west, 6, 8);
        b.run(5, 5);
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
        int i, r, row, col, dir;
        Board b(72, 72);
        //place Creatures 
        for(i=0; i < 10; ++i) {
            //place food
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(food), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place hoppers
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(hopper), (Direction)dir, row, col);
        }

        for(i=0; i < 10; ++i) {
            //place rovers 
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(rover), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place traps 
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(trap), (Direction)dir, row, col);
        }
        b.run(1000, 10);



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
        int i, r, row, col, dir;
        Board b(72, 72);
        //place Creatures 
        for(i=0; i < 10; ++i) {
            //place food
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(food), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place hoppers
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(hopper), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place rovers 
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(rover), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place traps 
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(trap), (Direction)dir, row, col);
        }
        for(i=0; i < 10; ++i) {
            //place best 
            r = rand() % 5184;
            row = r / 72;
            col = r % 72;
            dir = rand() % 4;
            b.placeCreature(Creature(best), (Direction)dir, row, col);
        }
        b.run(1000, 10);



    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -------
    // darwin alley test
    // ------

    try {
        cout << "*** Darwin 10x1 'Alley' ***" << endl;
        srand(0);
    
        Board b(10, 1);
        b.placeCreature(Creature(hopper), south, 0, 0);
        b.run(10, 5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try{
        cout << "*** Darwin 12x12 with Best ***" << endl;
        srand(0);

        Board b(12, 12);
        b.placeCreature(Creature(best), south, 1, 1);
        b.placeCreature(Creature(best), north, 10, 10);
        b.placeCreature(Creature(rover), west, 5, 5);
        b.placeCreature(Creature(food), south, 1, 2);
        b.placeCreature(Creature(trap), north, 7, 6);
        
        b.run(20, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 20x20 Rovers 'n' Best ***" << endl;
        srand(0);

        Board b(20, 20);
        b.placeCreature(Creature(best), west, 0, 0);
        b.placeCreature(Creature(best), east, 1, 5);
        b.placeCreature(Creature(best), north, 10, 15);
        b.placeCreature(Creature(best), south, 4, 19);
        b.placeCreature(Creature(best), north, 1, 19);
        b.placeCreature(Creature(rover), north, 10, 10);
        b.placeCreature(Creature(rover), north, 4, 3);
        b.placeCreature(Creature(rover), west, 19, 19);
        b.placeCreature(Creature(rover), south, 5, 9);
        b.placeCreature(Creature(rover), north, 14, 18);

        b.run(20, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 20x20 Rovers 'n' Traps ***" << endl;
        srand(0);

        Board b(20, 20);
        b.placeCreature(Creature(trap), west, 0, 0);
        b.placeCreature(Creature(trap), east, 1, 5);
        b.placeCreature(Creature(trap), north, 10, 15);
        b.placeCreature(Creature(trap), south, 4, 19);
        b.placeCreature(Creature(trap), north, 10, 10);
        b.placeCreature(Creature(rover), north, 4, 3);
        b.placeCreature(Creature(rover), west, 19, 19);
        b.placeCreature(Creature(rover), south, 5, 9);
        b.placeCreature(Creature(rover), north, 14, 18);

        b.run(20, 10);

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 100x1 Showdown ***" << endl;
        srand(0);

        Board b(100,1);
        b.placeCreature(Creature(trap), west, 0,0);
        b.placeCreature(Creature(hopper), south, 20, 0);
        b.placeCreature(Creature(rover), east, 40, 0);
        b.placeCreature(Creature(food), west, 60, 0);
        b.placeCreature(Creature(best), north, 80, 0);

        b.run(100, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 10x10 Empty Board ***" << endl;
        srand(0);

        Board b(10, 10);
        b.run(100, 4);
    
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    return 0;}
