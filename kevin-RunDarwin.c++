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
#include "Darwin.c++"

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
        srand(0);
        Game<8, 8> g;
		Food<8, 8> f1;
		Hopper<8, 8> h1;
		Hopper<8, 8> h2;
		Hopper<8, 8> h3;
		Hopper<8, 8> h4;
		Food<8, 8> f2;
		g.add_creature(&f1, 0, 0, g.E);
		g.add_creature(&h1, 3, 3, g.N);
		g.add_creature(&h2, 3, 4, g.E);
		g.add_creature(&h3, 4, 4, g.S);
		g.add_creature(&h4, 4, 3, g.W);
		g.add_creature(&f2, 7, 7, g.N);
		g.play(5, 1);
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
        Game<7, 9> g;
        Trap<7, 9> t;
        Hopper<7, 9> h;
        Rover<7, 9> r;
        Trap<7, 9> t1;
        g.add_creature(&t, 0, 0, g.S);
        g.add_creature(&h, 3, 2, g.E);
        g.add_creature(&r, 5, 4, g.N);
        g.add_creature(&t, 6, 8, g.W);
        g.play(5, 1);
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
        Game<72, 72> g;
        Food<72, 72> f1;
        Food<72, 72> f2;
        Food<72, 72> f3;
        Food<72, 72> f4;
        Food<72, 72> f5;
        Food<72, 72> f6;
        Food<72, 72> f7;
        Food<72, 72> f8;
        Food<72, 72> f9;
        Food<72, 72> f10;
        Hopper<72, 72> h1;
        Hopper<72, 72> h2;
        Hopper<72, 72> h3;
        Hopper<72, 72> h4;
        Hopper<72, 72> h5;
        Hopper<72, 72> h6;
        Hopper<72, 72> h7;
        Hopper<72, 72> h8;
        Hopper<72, 72> h9;
        Hopper<72, 72> h10;
        Rover<72, 72> r1;
        Rover<72, 72> r2;
        Rover<72, 72> r3;
        Rover<72, 72> r4;
        Rover<72, 72> r5;
        Rover<72, 72> r6;
        Rover<72, 72> r7;
        Rover<72, 72> r8;
        Rover<72, 72> r9;
        Rover<72, 72> r10;
        Trap<72, 72> t1;
        Trap<72, 72> t2;
        Trap<72, 72> t3;
        Trap<72, 72> t4;
        Trap<72, 72> t5;
        Trap<72, 72> t6;
        Trap<72, 72> t7;
        Trap<72, 72> t8;
        Trap<72, 72> t9;
        Trap<72, 72> t10;
        
        g.add_creature(&f1, rand()%5184, rand()%4);
        g.add_creature(&f2, rand()%5184, rand()%4);
        g.add_creature(&f3, rand()%5184, rand()%4);
        g.add_creature(&f4, rand()%5184, rand()%4);
        g.add_creature(&f5, rand()%5184, rand()%4);
        g.add_creature(&f6, rand()%5184, rand()%4);
        g.add_creature(&f7, rand()%5184, rand()%4);
        g.add_creature(&f8, rand()%5184, rand()%4);
        g.add_creature(&f9, rand()%5184, rand()%4);
        g.add_creature(&f10, rand()%5184, rand()%4);
        
        g.add_creature(&h1, rand()%5184, rand()%4);
        g.add_creature(&h2, rand()%5184, rand()%4);
        g.add_creature(&h3, rand()%5184, rand()%4);
        g.add_creature(&h4, rand()%5184, rand()%4);
        g.add_creature(&h5, rand()%5184, rand()%4);
        g.add_creature(&h6, rand()%5184, rand()%4);
        g.add_creature(&h7, rand()%5184, rand()%4);
        g.add_creature(&h8, rand()%5184, rand()%4);
        g.add_creature(&h9, rand()%5184, rand()%4);
        g.add_creature(&h10, rand()%5184, rand()%4);
        
        g.add_creature(&r1, rand()%5184, rand()%4);
        g.add_creature(&r2, rand()%5184, rand()%4);
        g.add_creature(&r3, rand()%5184, rand()%4);
        g.add_creature(&r4, rand()%5184, rand()%4);
        g.add_creature(&r5, rand()%5184, rand()%4);
        g.add_creature(&r6, rand()%5184, rand()%4);
        g.add_creature(&r7, rand()%5184, rand()%4);
        g.add_creature(&r8, rand()%5184, rand()%4);
        g.add_creature(&r9, rand()%5184, rand()%4);
        g.add_creature(&r10, rand()%5184, rand()%4);
        
        g.add_creature(&t1, rand()%5184, rand()%4);
        g.add_creature(&t2, rand()%5184, rand()%4);
        g.add_creature(&t3, rand()%5184, rand()%4);
        g.add_creature(&t4, rand()%5184, rand()%4);
        g.add_creature(&t5, rand()%5184, rand()%4);
        g.add_creature(&t6, rand()%5184, rand()%4);
        g.add_creature(&t7, rand()%5184, rand()%4);
        g.add_creature(&t8, rand()%5184, rand()%4);
        g.add_creature(&t9, rand()%5184, rand()%4);
        g.add_creature(&t10, rand()%5184, rand()%4);
        
        g.play(1000, 100);
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
        Game<72, 72> g;
        Food<72, 72> f1;
        Food<72, 72> f2;
        Food<72, 72> f3;
        Food<72, 72> f4;
        Food<72, 72> f5;
        Food<72, 72> f6;
        Food<72, 72> f7;
        Food<72, 72> f8;
        Food<72, 72> f9;
        Food<72, 72> f10;
        Hopper<72, 72> h1;
        Hopper<72, 72> h2;
        Hopper<72, 72> h3;
        Hopper<72, 72> h4;
        Hopper<72, 72> h5;
        Hopper<72, 72> h6;
        Hopper<72, 72> h7;
        Hopper<72, 72> h8;
        Hopper<72, 72> h9;
        Hopper<72, 72> h10;
        Rover<72, 72> r1;
        Rover<72, 72> r2;
        Rover<72, 72> r3;
        Rover<72, 72> r4;
        Rover<72, 72> r5;
        Rover<72, 72> r6;
        Rover<72, 72> r7;
        Rover<72, 72> r8;
        Rover<72, 72> r9;
        Rover<72, 72> r10;
        Trap<72, 72> t1;
        Trap<72, 72> t2;
        Trap<72, 72> t3;
        Trap<72, 72> t4;
        Trap<72, 72> t5;
        Trap<72, 72> t6;
        Trap<72, 72> t7;
        Trap<72, 72> t8;
        Trap<72, 72> t9;
        Trap<72, 72> t10;
        Best<72, 72> b1;
        Best<72, 72> b2;
        Best<72, 72> b3;
        Best<72, 72> b4;
        Best<72, 72> b5;
        Best<72, 72> b6;
        Best<72, 72> b7;
        Best<72, 72> b8;
        Best<72, 72> b9;
        Best<72, 72> b10;
        
        g.add_creature(&f1, rand()%5184, rand()%4);
        g.add_creature(&f2, rand()%5184, rand()%4);
        g.add_creature(&f3, rand()%5184, rand()%4);
        g.add_creature(&f4, rand()%5184, rand()%4);
        g.add_creature(&f5, rand()%5184, rand()%4);
        g.add_creature(&f6, rand()%5184, rand()%4);
        g.add_creature(&f7, rand()%5184, rand()%4);
        g.add_creature(&f8, rand()%5184, rand()%4);
        g.add_creature(&f9, rand()%5184, rand()%4);
        g.add_creature(&f10, rand()%5184, rand()%4);
        
        g.add_creature(&h1, rand()%5184, rand()%4);
        g.add_creature(&h2, rand()%5184, rand()%4);
        g.add_creature(&h3, rand()%5184, rand()%4);
        g.add_creature(&h4, rand()%5184, rand()%4);
        g.add_creature(&h5, rand()%5184, rand()%4);
        g.add_creature(&h6, rand()%5184, rand()%4);
        g.add_creature(&h7, rand()%5184, rand()%4);
        g.add_creature(&h8, rand()%5184, rand()%4);
        g.add_creature(&h9, rand()%5184, rand()%4);
        g.add_creature(&h10, rand()%5184, rand()%4);
        
        g.add_creature(&r1, rand()%5184, rand()%4);
        g.add_creature(&r2, rand()%5184, rand()%4);
        g.add_creature(&r3, rand()%5184, rand()%4);
        g.add_creature(&r4, rand()%5184, rand()%4);
        g.add_creature(&r5, rand()%5184, rand()%4);
        g.add_creature(&r6, rand()%5184, rand()%4);
        g.add_creature(&r7, rand()%5184, rand()%4);
        g.add_creature(&r8, rand()%5184, rand()%4);
        g.add_creature(&r9, rand()%5184, rand()%4);
        g.add_creature(&r10, rand()%5184, rand()%4);
        
        g.add_creature(&t1, rand()%5184, rand()%4);
        g.add_creature(&t2, rand()%5184, rand()%4);
        g.add_creature(&t3, rand()%5184, rand()%4);
        g.add_creature(&t4, rand()%5184, rand()%4);
        g.add_creature(&t5, rand()%5184, rand()%4);
        g.add_creature(&t6, rand()%5184, rand()%4);
        g.add_creature(&t7, rand()%5184, rand()%4);
        g.add_creature(&t8, rand()%5184, rand()%4);
        g.add_creature(&t9, rand()%5184, rand()%4);
        g.add_creature(&t10, rand()%5184, rand()%4);
        
        g.add_creature(&b1, rand()%5184, rand()%4);
        g.add_creature(&b2, rand()%5184, rand()%4);
        g.add_creature(&b3, rand()%5184, rand()%4);
        g.add_creature(&b4, rand()%5184, rand()%4);
        g.add_creature(&b5, rand()%5184, rand()%4);
        g.add_creature(&b6, rand()%5184, rand()%4);
        g.add_creature(&b7, rand()%5184, rand()%4);
        g.add_creature(&b8, rand()%5184, rand()%4);
        g.add_creature(&b9, rand()%5184, rand()%4);
        g.add_creature(&b10, rand()%5184, rand()%4);
        
        g.play(1000, 100);
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
