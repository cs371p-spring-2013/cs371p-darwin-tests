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

    // -----
    // best
    // -----

    /*
     0: if_random 3
     1: left
     2: go 4
     3: right
     4: if_enemy 10
     5: if_empty 8
     6: if_random 3
     7: go 1
     8: hop
     9: go 0
     10: infect
     11: go 0
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
        srand(0);
        Food f = Food();
        //Trap t = Trap();
        //Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        Creature c2 = Creature(3,4, NORTH, sp);
        Creature c3 = Creature(4,4, NORTH, sp);
        Creature c4 = Creature(4,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, NORTH, sp);
        Creature c6 = Creature(7,7, NORTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH);
        b.place_piece(3, 4, &c2, EAST);
        b.place_piece(4, 4, &c3, SOUTH);
        b.place_piece(4, 3, &c4, WEST);
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(7, 7, &c6, NORTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        dw.simulate();
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
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &t;
        Creature c1 = Creature(0, 0, SOUTH, sp);
        Creature c2 = Creature(6, 8, WEST, sp);
        sp = &h;
        Creature c3 = Creature(3, 2, EAST, sp);
        sp = &r;
        Creature c4 = Creature(5, 4, NORTH, sp);
        Board b = Board(7, 9);
        b.place_piece(0, 0, &c1, SOUTH);
        b.place_piece(3, 2, &c3, EAST);
        b.place_piece(5, 4, &c4, NORTH);
        b.place_piece(6, 8, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(7, 9, 5, 1, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

 try {
        cout << "*** Darwin 7x7 ***" << endl;
        srand(0);
        /*
        7x7 Darwin
        Rover, facing west, at (0,0)
        Rover, facing east, at (6,6)
        food, facing east, at (0,6)
        food, facing north, at (6,0)
        Simulate 15 moves.
        Print every grid.
        */
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, SOUTH, sp);
        Creature c2 = Creature(6, 6, EAST, sp);
        sp = &f;
        Creature c3 = Creature(0, 6, SOUTH, sp);
        Creature c4 = Creature(6, 0, NORTH, sp);
        Board b = Board(7, 7);
        b.place_piece(0, 0, &c1, WEST);
        b.place_piece(6, 6, &c2, EAST);
        b.place_piece(0, 6, &c3, SOUTH);
        b.place_piece(6, 0, &c4, NORTH);
        DarwinsWorld dw = DarwinsWorld(7, 7, 15, 1, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

         try {
        cout << "*** Darwin 1x9 ***" << endl;
        srand(0);
        /*
        1x9 Darwin
        Rover,  facing north, at (0, 1)
        Simulate 8 moves.
        Print every grid.
        */
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, NORTH, sp);
        Board b = Board(1, 9);
        b.place_piece(0, 1, &c1, NORTH);
        DarwinsWorld dw = DarwinsWorld(1, 9, 8, 1, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover,  facing north, at (4, 0)
        Rover,  facing south, at (5, 0)
        Simulate 16 moves.
        Print every grid.
        */
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(4, 0, NORTH, sp);
        Creature c2 = Creature(5,0, SOUTH, sp);
        Board b = Board(10, 1);
        b.place_piece(4, 0, &c1, NORTH);
        b.place_piece(5, 0, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(10, 1, 16, 1, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Darwin 7x7 ***" << endl;
        srand(0);
        /*
        7x7 Darwin
        Rover, facing west, at (0,0)
        Rover, facing east, at (6,6)
        food, facing east, at (0,6)
        food, facing north, at (6,0)
        Simulate 15 moves.
        Print every grid.
        */
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, SOUTH, sp);
        Creature c2 = Creature(6, 6, EAST, sp);
        sp = &t;
        Creature c3 = Creature(0, 6, SOUTH, sp);
        Creature c4 = Creature(6, 0, NORTH, sp);
        Board b = Board(7, 7);
        b.place_piece(0, 0, &c1, WEST);
        b.place_piece(6, 6, &c2, EAST);
        b.place_piece(0, 6, &c3, NORTH);
        b.place_piece(6, 0, &c4, NORTH);
        DarwinsWorld dw = DarwinsWorld(7, 7, 30, 3, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
 

    try {
        cout << "*** Darwin 20x20 ***" << endl;
        srand(0);
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, NORTH, sp);
        Creature c2 = Creature(19, 19, EAST, sp);
        sp = &t;
        Creature c3 = Creature(0, 19, SOUTH, sp);
        Creature c4 = Creature(19, 0, WEST, sp);
        sp = &h;
        Creature c5 = Creature(0, 10, NORTH, sp);
        Creature c6 = Creature(10, 0, EAST, sp);
        sp = &f;
        Creature c7 = Creature(19, 10, SOUTH, sp);
        Creature c8 = Creature(10, 19, WEST, sp);
        sp = &t;
        Creature c9 = Creature(0, 19, NORTH, sp);

        Board b = Board(20, 20);
        b.place_piece(0, 0, &c1, NORTH);
        b.place_piece(19, 19, &c2, EAST);
        b.place_piece(0, 19, &c3, SOUTH);
        b.place_piece(19, 0, &c4, WEST);
        b.place_piece(0, 10, &c5, NORTH);
        b.place_piece(10, 0, &c6, EAST);
        b.place_piece(19, 10, &c7, SOUTH);
        b.place_piece(10, 19, &c8, WEST);
        b.place_piece(0, 19, &c8, WEST);
        DarwinsWorld dw = DarwinsWorld(20, 20, 60, 6, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, NORTH, sp);
        Creature c2 = Creature(9, 9, EAST, sp);
        sp = &t;
        Creature c3 = Creature(0, 9, SOUTH, sp);
        Creature c4 = Creature(9, 0, WEST, sp);
        sp = &h;
        Creature c5 = Creature(0, 5, NORTH, sp);
        Creature c6 = Creature(5, 0, EAST, sp);
        sp = &f;
        Creature c7 = Creature(9, 5, SOUTH, sp);
        Creature c8 = Creature(5, 9, WEST, sp);
        sp = &t;
        Creature c9 = Creature(0, 9, NORTH, sp);

        Board b = Board(10, 10);
        b.place_piece(0, 0, &c1, NORTH);
        b.place_piece(9, 9, &c2, EAST);
        b.place_piece(0, 9, &c3, SOUTH);
        b.place_piece(9, 0, &c4, WEST);
        b.place_piece(0, 5, &c5, NORTH);
        b.place_piece(5, 0, &c6, EAST);
        b.place_piece(9, 5, &c7, SOUTH);
        b.place_piece(5, 9, &c8, WEST);
        b.place_piece(0, 9, &c8, WEST);
        DarwinsWorld dw = DarwinsWorld(10, 10, 30, 2, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);
        
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &r;
        Creature c1 = Creature(0, 0, SOUTH, sp);
        Creature c2 = Creature(2, 2, EAST, sp);
        sp = &f;
        Creature c3 = Creature(0, 2, SOUTH, sp);
        Creature c4 = Creature(2, 0, NORTH, sp);
        Board b = Board(3, 3);
        b.place_piece(0, 0, &c1, WEST);
        b.place_piece(2, 2, &c2, EAST);
        b.place_piece(0, 2, &c3, SOUTH);
        b.place_piece(2, 0, &c4, NORTH);
        DarwinsWorld dw = DarwinsWorld(3, 3, 10, 1, &b);
        dw.simulate();
        
        }

        catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

         try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(0, 0, SOUTH, sp);
        Creature c2 = Creature(1, 1, EAST, sp);
        sp = &t;
        Creature c3 = Creature(0, 1, SOUTH, sp);
        Creature c4 = Creature(1, 0, NORTH, sp);
        Board b = Board(2, 2);
        b.place_piece(0, 0, &c1, WEST);
        b.place_piece(1, 1, &c2, EAST);
        b.place_piece(0, 1, &c3, SOUTH);
        b.place_piece(1, 0, &c4, NORTH);
        DarwinsWorld dw = DarwinsWorld(2,2, 10, 1, &b);
        dw.simulate();
        
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
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Species* sp;
        sp = &f;
        Creature c1 = Creature(0, 0, NORTH, sp);
        Creature c2 = Creature(0, 0, NORTH, sp);
        Creature c3 = Creature(0, 0, NORTH, sp);
        Creature c4 = Creature(0, 0, NORTH, sp);
        Creature c5 = Creature(0, 0, NORTH, sp);
        Creature c6 = Creature(0, 0, NORTH, sp);
        Creature c7 = Creature(0, 0, NORTH, sp);
        Creature c8 = Creature(0, 0, NORTH, sp);
        Creature c9 = Creature(0, 0, NORTH, sp);
        Creature c10 = Creature(0, 0, NORTH, sp);
        sp = &h;
        Creature c11 = Creature(0, 0, NORTH, sp);
        Creature c12 = Creature(0, 0, NORTH, sp);
        Creature c13 = Creature(0, 0, NORTH, sp);
        Creature c14 = Creature(0, 0, NORTH, sp);
        Creature c15 = Creature(0, 0, NORTH, sp);
        Creature c16 = Creature(0, 0, NORTH, sp);
        Creature c17 = Creature(0, 0, NORTH, sp);
        Creature c18 = Creature(0, 0, NORTH, sp);
        Creature c19 = Creature(0, 0, NORTH, sp);
        Creature c20 = Creature(0, 0, NORTH, sp);
        sp = &r;
        Creature c21 = Creature(0, 0, NORTH, sp);
        Creature c22 = Creature(0, 0, NORTH, sp);
        Creature c23 = Creature(0, 0, NORTH, sp);
        Creature c24 = Creature(0, 0, NORTH, sp);
        Creature c25 = Creature(0, 0, NORTH, sp);
        Creature c26 = Creature(0, 0, NORTH, sp);
        Creature c27 = Creature(0, 0, NORTH, sp);
        Creature c28 = Creature(0, 0, NORTH, sp);
        Creature c29 = Creature(0, 0, NORTH, sp);
        Creature c30 = Creature(0, 0, NORTH, sp);
        sp = &t;
        Creature c31 = Creature(0, 0, NORTH, sp);
        Creature c32 = Creature(0, 0, NORTH, sp);
        Creature c33 = Creature(0, 0, NORTH, sp);
        Creature c34 = Creature(0, 0, NORTH, sp);
        Creature c35 = Creature(0, 0, NORTH, sp);
        Creature c36 = Creature(0, 0, NORTH, sp);
        Creature c37 = Creature(0, 0, NORTH, sp);
        Creature c38 = Creature(0, 0, NORTH, sp);
        Creature c39 = Creature(0, 0, NORTH, sp);
        Creature c40 = Creature(0, 0, NORTH, sp);
        Board b = Board(72, 72);
        int ta;
        int tb;
        //cout << "ok so far" << endl;
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c1, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c2, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c3, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c4, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c5, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c6, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c7, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c8, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c9, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c10, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c11, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c12, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c13, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c14, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c15, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c16, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c17, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c18, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c19, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c20, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c21, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c22, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c23, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c24, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c25, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c26, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c27, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c28, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c29, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c30, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c31, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c32, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c33, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c34, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c35, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c36, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c37, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c38, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c39, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c40, (Direction)(rand() % 4));
        //cout << "ok so far" << endl;
        DarwinsWorld dw = DarwinsWorld(72, 72, 1000, 100, &b);
        //cout << "ok so far" << endl;
        dw.simulate();
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
        Food f = Food();
        Trap t = Trap();
        Rover r = Rover();
        Hopper h = Hopper();
        Best be = Best();
        Species* sp;
        sp = &f;
        Creature c1 = Creature(0, 0, NORTH, sp);
        Creature c2 = Creature(0, 0, NORTH, sp);
        Creature c3 = Creature(0, 0, NORTH, sp);
        Creature c4 = Creature(0, 0, NORTH, sp);
        Creature c5 = Creature(0, 0, NORTH, sp);
        Creature c6 = Creature(0, 0, NORTH, sp);
        Creature c7 = Creature(0, 0, NORTH, sp);
        Creature c8 = Creature(0, 0, NORTH, sp);
        Creature c9 = Creature(0, 0, NORTH, sp);
        Creature c10 = Creature(0, 0, NORTH, sp);
        sp = &h;
        Creature c11 = Creature(0, 0, NORTH, sp);
        Creature c12 = Creature(0, 0, NORTH, sp);
        Creature c13 = Creature(0, 0, NORTH, sp);
        Creature c14 = Creature(0, 0, NORTH, sp);
        Creature c15 = Creature(0, 0, NORTH, sp);
        Creature c16 = Creature(0, 0, NORTH, sp);
        Creature c17 = Creature(0, 0, NORTH, sp);
        Creature c18 = Creature(0, 0, NORTH, sp);
        Creature c19 = Creature(0, 0, NORTH, sp);
        Creature c20 = Creature(0, 0, NORTH, sp);
        sp = &r;
        Creature c21 = Creature(0, 0, NORTH, sp);
        Creature c22 = Creature(0, 0, NORTH, sp);
        Creature c23 = Creature(0, 0, NORTH, sp);
        Creature c24 = Creature(0, 0, NORTH, sp);
        Creature c25 = Creature(0, 0, NORTH, sp);
        Creature c26 = Creature(0, 0, NORTH, sp);
        Creature c27 = Creature(0, 0, NORTH, sp);
        Creature c28 = Creature(0, 0, NORTH, sp);
        Creature c29 = Creature(0, 0, NORTH, sp);
        Creature c30 = Creature(0, 0, NORTH, sp);
        sp = &t;
        Creature c31 = Creature(0, 0, NORTH, sp);
        Creature c32 = Creature(0, 0, NORTH, sp);
        Creature c33 = Creature(0, 0, NORTH, sp);
        Creature c34 = Creature(0, 0, NORTH, sp);
        Creature c35 = Creature(0, 0, NORTH, sp);
        Creature c36 = Creature(0, 0, NORTH, sp);
        Creature c37 = Creature(0, 0, NORTH, sp);
        Creature c38 = Creature(0, 0, NORTH, sp);
        Creature c39 = Creature(0, 0, NORTH, sp);
        Creature c40 = Creature(0, 0, NORTH, sp);
        sp = &be;
        Creature c41 = Creature(0, 0, NORTH, sp);
        Creature c42 = Creature(0, 0, NORTH, sp);
        Creature c43 = Creature(0, 0, NORTH, sp);
        Creature c44 = Creature(0, 0, NORTH, sp);
        Creature c45 = Creature(0, 0, NORTH, sp);
        Creature c46 = Creature(0, 0, NORTH, sp);
        Creature c47 = Creature(0, 0, NORTH, sp);
        Creature c48 = Creature(0, 0, NORTH, sp);
        Creature c49 = Creature(0, 0, NORTH, sp);
        Creature c50 = Creature(0, 0, NORTH, sp);
        Board b = Board(72, 72);
        int ta;
        int tb;
        //cout << "ok so far" << endl;
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c1, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c2, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c3, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c4, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c5, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c6, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c7, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c8, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c9, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c10, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c11, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c12, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c13, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c14, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c15, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c16, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c17, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c18, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c19, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c20, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c21, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c22, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c23, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c24, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c25, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c26, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c27, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c28, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c29, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c30, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c31, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c32, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c33, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c34, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c35, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c36, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c37, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c38, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c39, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c40, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c41, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c42, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c43, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c44, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c45, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c46, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c47, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c48, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c49, (Direction)(rand() % 4));
        ta = rand() % 5184;
        tb = ta / 72;
        b.place_piece(tb, ta - tb *72, &c50, (Direction)(rand() % 4));
        DarwinsWorld dw = DarwinsWorld(72, 72, 1000, 100, &b);
        dw.simulate();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
