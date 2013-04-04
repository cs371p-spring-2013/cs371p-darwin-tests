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

        Game g(8,8);
        Food f(2);
        Hopper h1(1);
        Hopper h2(2);
        Hopper h3(3);
        Hopper h4(0);
        Food f2(1);
        g.add_creature(f,0,0);
        g.add_creature(h1,3,3);
        g.add_creature(h2,3,4);
        g.add_creature(h3,4,4);
        g.add_creature(h4,4,3);
        g.add_creature(f2,7,7);
        g.run(5);
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
        Game g(7,9);
        
        Trap t1(3);
        Hopper h1(2);
        Rover r1(1);
        Trap t2(0);
        
        g.add_creature(t1,0,0);
        g.add_creature(h1,3,2);
        g.add_creature(r1,5,4);
        g.add_creature(t2,6,8);
        g.run(5);
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
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
        Game g(72,72);
        
		int location = rand()%5184;
		Food f1(rand()%4);
		g.add_creature(f1,location/72,location%72);
		
        location = rand()%5184;
        Food f2(rand()%4);
        g.add_creature(f2,location/72,location%72);
        
        location = rand()%5184;
        Food f3(rand()%4);
        g.add_creature(f3,location/72,location%72);
        
        location = rand()%5184;
        Food f4(rand()%4);
        g.add_creature(f4,location/72,location%72);
        
        location = rand()%5184;
        Food f5(rand()%4);
        g.add_creature(f5,location/72,location%72);
        
        location = rand()%5184;
        Food f6(rand()%4);
        g.add_creature(f6,location/72,location%72);
        
        location = rand()%5184;
        Food f7(rand()%4);
        g.add_creature(f7,location/72,location%72);
        
        location = rand()%5184;
        Food f8(rand()%4);
        g.add_creature(f8,location/72,location%72);
        
        location = rand()%5184;
        Food f9(rand()%4);
        g.add_creature(f9,location/72,location%72);
        
        location = rand()%5184;
        Food f10(rand()%4);
        g.add_creature(f10,location/72,location%72);
        
        location = rand()%5184;
        Hopper h1(rand()%4);
        g.add_creature(h1,location/72,location%72);
        
        location = rand()%5184;
        Hopper h2(rand()%4);
        g.add_creature(h2,location/72,location%72);
        
        location = rand()%5184;
        Hopper h3(rand()%4);
        g.add_creature(h3,location/72,location%72);
        
        location = rand()%5184;
        Hopper h4(rand()%4);
        g.add_creature(h4,location/72,location%72);
        
        location = rand()%5184;
        Hopper h5(rand()%4);
        g.add_creature(h5,location/72,location%72);
        
        location = rand()%5184;
        Hopper h6(rand()%4);
        g.add_creature(h6,location/72,location%72);
        
        location = rand()%5184;
        Hopper h7(rand()%4);
        g.add_creature(h7,location/72,location%72);
        
        location = rand()%5184;
        Hopper h8(rand()%4);
        g.add_creature(h8,location/72,location%72);
        
        location = rand()%5184;
        Hopper h9(rand()%4);
        g.add_creature(h9,location/72,location%72);
        
        location = rand()%5184;
        Hopper h10(rand()%4);
        g.add_creature(h10,location/72,location%72);

        location = rand()%5184;
        Rover r1(rand()%4);
        g.add_creature(r1,location/72,location%72);
        
        location = rand()%5184;
        Rover r2(rand()%4);
        g.add_creature(r2,location/72,location%72);
        
        location = rand()%5184;
        Rover r3(rand()%4);
        g.add_creature(r3,location/72,location%72);
        
        location = rand()%5184;
        Rover r4(rand()%4);
        g.add_creature(r4,location/72,location%72);
        
        location = rand()%5184;
        Rover r5(rand()%4);
        g.add_creature(r5,location/72,location%72);
        
        location = rand()%5184;
        Rover r6(rand()%4);
        g.add_creature(r6,location/72,location%72);
        
        location = rand()%5184;
        Rover r7(rand()%4);
        g.add_creature(r7,location/72,location%72);
        
        location = rand()%5184;
        Rover r8(rand()%4);
        g.add_creature(r8,location/72,location%72);
        
        location = rand()%5184;
        Rover r9(rand()%4);
        g.add_creature(r9,location/72,location%72);
        
        location = rand()%5184;
        Rover r10(rand()%4);
        g.add_creature(r10,location/72,location%72);

        location = rand()%5184;
        Trap t1(rand()%4);
        g.add_creature(t1,location/72,location%72);
        
        location = rand()%5184;
        Trap t2(rand()%4);
        g.add_creature(t2,location/72,location%72);
        
        location = rand()%5184;
        Trap t3(rand()%4);
        g.add_creature(t3,location/72,location%72);
        
        location = rand()%5184;
        Trap t4(rand()%4);
        g.add_creature(t4,location/72,location%72);
        
        location = rand()%5184;
        Trap t5(rand()%4);
        g.add_creature(t5,location/72,location%72);
        
        location = rand()%5184;
        Trap t6(rand()%4);
        g.add_creature(t6,location/72,location%72);
        
        location = rand()%5184;
        Trap t7(rand()%4);
        g.add_creature(t7,location/72,location%72);
        
        location = rand()%5184;
        Trap t8(rand()%4);
        g.add_creature(t8,location/72,location%72);
        
        location = rand()%5184;
        Trap t9(rand()%4);
        g.add_creature(t9,location/72,location%72);
        
        location = rand()%5184;
        Trap t10(rand()%4);
        g.add_creature(t10,location/72,location%72);
        
        g.run(1000, 100);
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
        srand(0);
        Game g(72,72);
        
        int location = rand()%5184;
        Food f1(rand()%4);
        g.add_creature(f1,location/72,location%72);
        
        location = rand()%5184;
        Food f2(rand()%4);
        g.add_creature(f2,location/72,location%72);
        
        location = rand()%5184;
        Food f3(rand()%4);
        g.add_creature(f3,location/72,location%72);
        
        location = rand()%5184;
        Food f4(rand()%4);
        g.add_creature(f4,location/72,location%72);
        
        location = rand()%5184;
        Food f5(rand()%4);
        g.add_creature(f5,location/72,location%72);
        
        location = rand()%5184;
        Food f6(rand()%4);
        g.add_creature(f6,location/72,location%72);
        
        location = rand()%5184;
        Food f7(rand()%4);
        g.add_creature(f7,location/72,location%72);
        
        location = rand()%5184;
        Food f8(rand()%4);
        g.add_creature(f8,location/72,location%72);
        
        location = rand()%5184;
        Food f9(rand()%4);
        g.add_creature(f9,location/72,location%72);
        
        location = rand()%5184;
        Food f10(rand()%4);
        g.add_creature(f10,location/72,location%72);
        
        location = rand()%5184;
        Hopper h1(rand()%4);
        g.add_creature(h1,location/72,location%72);
        
        location = rand()%5184;
        Hopper h2(rand()%4);
        g.add_creature(h2,location/72,location%72);
        
        location = rand()%5184;
        Hopper h3(rand()%4);
        g.add_creature(h3,location/72,location%72);
        
        location = rand()%5184;
        Hopper h4(rand()%4);
        g.add_creature(h4,location/72,location%72);
        
        location = rand()%5184;
        Hopper h5(rand()%4);
        g.add_creature(h5,location/72,location%72);
        
        location = rand()%5184;
        Hopper h6(rand()%4);
        g.add_creature(h6,location/72,location%72);
        
        location = rand()%5184;
        Hopper h7(rand()%4);
        g.add_creature(h7,location/72,location%72);
        
        location = rand()%5184;
        Hopper h8(rand()%4);
        g.add_creature(h8,location/72,location%72);
        
        location = rand()%5184;
        Hopper h9(rand()%4);
        g.add_creature(h9,location/72,location%72);
        
        location = rand()%5184;
        Hopper h10(rand()%4);
        g.add_creature(h10,location/72,location%72);

        location = rand()%5184;
        Rover r1(rand()%4);
        g.add_creature(r1,location/72,location%72);
        
        location = rand()%5184;
        Rover r2(rand()%4);
        g.add_creature(r2,location/72,location%72);
        
        location = rand()%5184;
        Rover r3(rand()%4);
        g.add_creature(r3,location/72,location%72);
        
        location = rand()%5184;
        Rover r4(rand()%4);
        g.add_creature(r4,location/72,location%72);
        
        location = rand()%5184;
        Rover r5(rand()%4);
        g.add_creature(r5,location/72,location%72);
        
        location = rand()%5184;
        Rover r6(rand()%4);
        g.add_creature(r6,location/72,location%72);
        
        location = rand()%5184;
        Rover r7(rand()%4);
        g.add_creature(r7,location/72,location%72);
        
        location = rand()%5184;
        Rover r8(rand()%4);
        g.add_creature(r8,location/72,location%72);
        
        location = rand()%5184;
        Rover r9(rand()%4);
        g.add_creature(r9,location/72,location%72);
        
        location = rand()%5184;
        Rover r10(rand()%4);
        g.add_creature(r10,location/72,location%72);

        location = rand()%5184;
        Trap t1(rand()%4);
        g.add_creature(t1,location/72,location%72);
        
        location = rand()%5184;
        Trap t2(rand()%4);
        g.add_creature(t2,location/72,location%72);
        
        location = rand()%5184;
        Trap t3(rand()%4);
        g.add_creature(t3,location/72,location%72);
        
        location = rand()%5184;
        Trap t4(rand()%4);
        g.add_creature(t4,location/72,location%72);
        
        location = rand()%5184;
        Trap t5(rand()%4);
        g.add_creature(t5,location/72,location%72);
        
        location = rand()%5184;
        Trap t6(rand()%4);
        g.add_creature(t6,location/72,location%72);
        
        location = rand()%5184;
        Trap t7(rand()%4);
        g.add_creature(t7,location/72,location%72);
        
        location = rand()%5184;
        Trap t8(rand()%4);
        g.add_creature(t8,location/72,location%72);
        
        location = rand()%5184;
        Trap t9(rand()%4);
        g.add_creature(t9,location/72,location%72);
        
        location = rand()%5184;
        Trap t10(rand()%4);
        g.add_creature(t10,location/72,location%72);
        
        location = rand()%5184;
        Best b1(rand()%4);
        g.add_creature(b1,location/72,location%72);
        
        location = rand()%5184;
        Best b2(rand()%4);
        g.add_creature(b2,location/72,location%72);
        
        location = rand()%5184;
        Best b3(rand()%4);
        g.add_creature(b3,location/72,location%72);
        
        location = rand()%5184;
        Best b4(rand()%4);
        g.add_creature(b4,location/72,location%72);
        
        location = rand()%5184;
        Best b5(rand()%4);
        g.add_creature(b5,location/72,location%72);
        
        location = rand()%5184;
        Best b6(rand()%4);
        g.add_creature(b6,location/72,location%72);
        
        location = rand()%5184;
        Best b7(rand()%4);
        g.add_creature(b7,location/72,location%72);
        
        location = rand()%5184;
        Best b8(rand()%4);
        g.add_creature(b8,location/72,location%72);
        
        location = rand()%5184;
        Best b9(rand()%4);
        g.add_creature(b9,location/72,location%72);
        
        location = rand()%5184;
        Best b10(rand()%4);
        g.add_creature(b10,location/72,location%72);

        g.run(1000, 100);
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

    try {
        cout << "*** Darwin 4x4 ***" << endl;

        Game g(4,4);
        Food f(2);
        Hopper h1(0);
        Food f2(1);
        g.add_creature(f,0,0);
        g.add_creature(h1,0,3);
        g.add_creature(f2,3,3);
        g.run(3);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 1x1 ***" << endl;

        Game g(1,1);
        Food f(2);
        g.add_creature(f,0,0);
        g.run(10,5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 7x8 ***" << endl;

        Game g(7,8);
        Food f1(2);
        Food f2(2);
        Food f3(2);
        Food f4(2);
        Food f5(2);
        Food f6(2);
        Food f7(2);
        Food f8(2);
        Food f9(2);
        Food f10(2);
        g.add_creature(f1,1,2);
        g.add_creature(f2,2,2);
        g.add_creature(f3,1,5);
        g.add_creature(f4,2,5);
        g.add_creature(f5,4,1);
        g.add_creature(f6,5,2);
        g.add_creature(f7,5,3);
        g.add_creature(f8,5,4);
        g.add_creature(f9,5,5);
        g.add_creature(f10,4,6);
        g.run(0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 8x8 ***" << endl;

        Game g(8,8);
        Hopper f1(2);
        Hopper f2(2);
        Hopper f3(2);
        Hopper f4(2);
        Hopper f5(2);
        Hopper f6(2);
        Hopper f7(2);
        Hopper f8(2);
        g.add_creature(f1,0,0);
        g.add_creature(f2,1,0);
        g.add_creature(f3,2,0);
        g.add_creature(f4,3,0);
        g.add_creature(f5,4,0);
        g.add_creature(f6,5,0);
        g.add_creature(f7,6,0);
        g.add_creature(f8,7,0);
        g.run(8);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        srand(0);
        Game g(8,8);
        Rover f1(2);
        Rover f2(2);
        Rover f3(2);
        Rover f4(2);
        Rover f5(2);
        Rover f6(2);
        Rover f7(2);
        Rover f8(2);
        g.add_creature(f1,0,0);
        g.add_creature(f2,1,0);
        g.add_creature(f3,2,0);
        g.add_creature(f4,3,0);
        g.add_creature(f5,4,0);
        g.add_creature(f6,5,0);
        g.add_creature(f7,6,0);
        g.run(1000,100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 20x20 ***" << endl;
        srand(0);
        Game g(20,20);
        Rover f1(2);
        Rover f2(2);
        Rover f3(2);
        Rover f4(2);
        Rover f5(2);
        Rover f6(2);
        Rover f7(2);
        Rover f8(2);
        Rover f9(2);
        Rover f10(2);
        Best b1(0);
        Best b2(0);
        Best b3(0);
        Best b4(0);
        Best b5(0);
        Best b6(0);
        Best b7(0);
        Best b8(0);
        Best b9(0);
        Best b10(0);
        g.add_creature(f1,0,0);
        g.add_creature(f2,2,0);
        g.add_creature(f3,4,0);
        g.add_creature(f4,6,0);
        g.add_creature(f5,8,0);
        g.add_creature(f6,10,0);
        g.add_creature(f7,12,0);
        g.add_creature(f8,14,0);
        g.add_creature(f9,16,0);
        g.add_creature(f10,18,0);
        g.add_creature(b1,1,19);
        g.add_creature(b2,3,19);
        g.add_creature(b3,5,19);
        g.add_creature(b4,7,19);
        g.add_creature(b5,9,19);
        g.add_creature(b6,11,19);
        g.add_creature(b7,13,19);
        g.add_creature(b8,15,19);
        g.add_creature(b9,17,19);
        g.add_creature(b10,19,19);
        g.run(100,10);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
