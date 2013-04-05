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
	Species f("food");
    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
	Species h("hopper");
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
	Species r("rover");
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
	Species t("trap");
	
	Species b("best");
    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        srand(0);
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
        Simulation s(8, 8, 1, 5);
        Creature f1('f', 2, &f);
        Creature h1('h', 1, &h);
        Creature h2('h', 2, &h);
        Creature h3('h', 3, &h);
        Creature h4('h', 0, &h);
        Creature f2('f', 1, &f);
        s.addCreature(0, 0, &f1);
        s.addCreature(3, 3, &h1);
        s.addCreature(3, 4, &h2);
        s.addCreature(4, 4, &h3);
        s.addCreature(4, 3, &h4);
        s.addCreature(7, 7, &f2);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
        for(int i = 0; i < 5; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
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
        Simulation s(7, 9, 1, 5);
        Creature t1('t', 3, &t);
        Creature h1('h', 2, &h);
        Creature r1('r', 1, &r);
        Creature t2('t', 0, &t);
        s.addCreature(0, 0, &t1);
        s.addCreature(3, 2, &h1);
        s.addCreature(5, 4, &r1);
        s.addCreature(6, 8, &t1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);   
        cout << endl;
        for(int i = 0; i < 5; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
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
        Simulation s(72, 72, 100, 1000);
        int dir;
        int pos;
        int col;
        int row;
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f1('f', dir, &f);      
        s.addCreature(row, col, &f1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f2('f', dir, &f);      
        s.addCreature(row, col, &f2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f3('f', dir, &f);       
        s.addCreature(row, col, &f3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f4('f', dir, &f);       
        s.addCreature(row, col, &f4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f5('f', dir, &f);       
        s.addCreature(row, col, &f5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f6('f', dir, &f);       
        s.addCreature(row, col, &f6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f7('f', dir, &f);      
        s.addCreature(row, col, &f7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f8('f', dir, &f);       
        s.addCreature(row, col, &f8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f9('f', dir, &f);   
        s.addCreature(row, col, &f9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f10('f', dir, &f);     
        s.addCreature(row, col, &f10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h1('h', dir, &h);      
        s.addCreature(row, col, &h1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h2('h', dir, &h);      
        s.addCreature(row, col, &h2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h3('h', dir, &h);       
        s.addCreature(row, col, &h3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h4('h', dir, &h);       
        s.addCreature(row, col, &h4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h5('h', dir, &h);       
        s.addCreature(row, col, &h5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h6('h', dir, &h);       
        s.addCreature(row, col, &h6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h7('h', dir, &h);      
        s.addCreature(row, col, &h7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h8('h', dir, &h);       
        s.addCreature(row, col, &h8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h9('h', dir, &h);   
        s.addCreature(row, col, &h9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h10('h', dir, &h);     
        s.addCreature(row, col, &h10);
        
                pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r1('r', dir, &r);      
        s.addCreature(row, col, &r1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r2('r', dir, &r);      
        s.addCreature(row, col, &r2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r3('r', dir, &r);       
        s.addCreature(row, col, &r3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r4('r', dir, &r);       
        s.addCreature(row, col, &r4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r5('r', dir, &r);       
        s.addCreature(row, col, &r5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r6('r', dir, &r);       
        s.addCreature(row, col, &r6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r7('r', dir, &r);      
        s.addCreature(row, col, &r7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r8('r', dir, &r);       
        s.addCreature(row, col, &r8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r9('r', dir, &r);   
        s.addCreature(row, col, &r9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r10('r', dir, &r);     
        s.addCreature(row, col, &r10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t1('t', dir, &t);      
        s.addCreature(row, col, &t1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t2('t', dir, &t);      
        s.addCreature(row, col, &t2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t3('t', dir, &t);       
        s.addCreature(row, col, &t3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t4('t', dir, &t);       
        s.addCreature(row, col, &t4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t5('t', dir, &t);       
        s.addCreature(row, col, &t5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t6('t', dir, &t);       
        s.addCreature(row, col, &t6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t7('t', dir, &t);      
        s.addCreature(row, col, &t7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t8('t', dir, &t);       
        s.addCreature(row, col, &t8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t9('t', dir, &t);   
        s.addCreature(row, col, &t9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t10('t', dir, &t);     
        s.addCreature(row, col, &t10);
        
        s.printBoard(cout);
        cout << endl;
        for(int i = 0; i < 1000; ++i) {
        	s.simulateTurn();
        	if(i % 100 == 99) {
		    	cout << "Turn = " << i+1 << "." << endl;
		    	s.printBoard(cout);
        		cout << endl;
        	}
        }
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
        
        Simulation s(72, 72, 100, 1000);
        int dir;
        int pos;
        int col;
        int row;
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f1('f', dir, &f);      
        s.addCreature(row, col, &f1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f2('f', dir, &f);      
        s.addCreature(row, col, &f2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f3('f', dir, &f);       
        s.addCreature(row, col, &f3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f4('f', dir, &f);       
        s.addCreature(row, col, &f4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f5('f', dir, &f);       
        s.addCreature(row, col, &f5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f6('f', dir, &f);       
        s.addCreature(row, col, &f6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f7('f', dir, &f);      
        s.addCreature(row, col, &f7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f8('f', dir, &f);       
        s.addCreature(row, col, &f8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f9('f', dir, &f);   
        s.addCreature(row, col, &f9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature f10('f', dir, &f);     
        s.addCreature(row, col, &f10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h1('h', dir, &h);      
        s.addCreature(row, col, &h1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h2('h', dir, &h);      
        s.addCreature(row, col, &h2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h3('h', dir, &h);       
        s.addCreature(row, col, &h3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h4('h', dir, &h);       
        s.addCreature(row, col, &h4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h5('h', dir, &h);       
        s.addCreature(row, col, &h5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h6('h', dir, &h);       
        s.addCreature(row, col, &h6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h7('h', dir, &h);      
        s.addCreature(row, col, &h7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h8('h', dir, &h);       
        s.addCreature(row, col, &h8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h9('h', dir, &h);   
        s.addCreature(row, col, &h9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature h10('h', dir, &h);     
        s.addCreature(row, col, &h10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r1('r', dir, &r);      
        s.addCreature(row, col, &r1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r2('r', dir, &r);      
        s.addCreature(row, col, &r2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r3('r', dir, &r);       
        s.addCreature(row, col, &r3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r4('r', dir, &r);       
        s.addCreature(row, col, &r4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r5('r', dir, &r);       
        s.addCreature(row, col, &r5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r6('r', dir, &r);       
        s.addCreature(row, col, &r6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r7('r', dir, &r);      
        s.addCreature(row, col, &r7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r8('r', dir, &r);       
        s.addCreature(row, col, &r8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r9('r', dir, &r);   
        s.addCreature(row, col, &r9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature r10('r', dir, &r);     
        s.addCreature(row, col, &r10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t1('t', dir, &t);      
        s.addCreature(row, col, &t1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t2('t', dir, &t);      
        s.addCreature(row, col, &t2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t3('t', dir, &t);       
        s.addCreature(row, col, &t3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t4('t', dir, &t);       
        s.addCreature(row, col, &t4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t5('t', dir, &t);       
        s.addCreature(row, col, &t5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t6('t', dir, &t);       
        s.addCreature(row, col, &t6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t7('t', dir, &t);      
        s.addCreature(row, col, &t7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t8('t', dir, &t);       
        s.addCreature(row, col, &t8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t9('t', dir, &t);   
        s.addCreature(row, col, &t9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature t10('t', dir, &t);     
        s.addCreature(row, col, &t10);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b1('b', dir, &b);      
        s.addCreature(row, col, &b1);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b2('b', dir, &b);      
        s.addCreature(row, col, &b2);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b3('b', dir, &b);       
        s.addCreature(row, col, &b3);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b4('b', dir, &b);       
        s.addCreature(row, col, &b4);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b5('b', dir, &b);       
        s.addCreature(row, col, &b5);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b6('b', dir, &b);       
        s.addCreature(row, col, &b6);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b7('b', dir, &b);      
        s.addCreature(row, col, &b7);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b8('b', dir, &b);       
        s.addCreature(row, col, &b8);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b9('b', dir, &b);   
        s.addCreature(row, col, &b9);
        
        pos = rand() % 5184;
        row = pos/72;
        col = pos%72;
        dir = rand() % 4;
        Creature b10('b', dir, &b);     
        s.addCreature(row, col, &b10);
        
        s.printBoard(cout);
        cout << endl;
        for(int i = 0; i < 1000; ++i) {
        	s.simulateTurn();
        	if(i % 100 == 99) {
		    	cout << "Turn = " << i+1 << "." << endl;
		    	s.printBoard(cout);
        		cout << endl;
        	}
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
                
    // ------------
    // darwin acceptance test 1
    // 1x4
    // ------------
        
    try {
        cout << "*** Darwin 1x4 ***" << endl;
        srand(0);
		Simulation s(1, 4, 1, 5);
		Creature r1('r', 2, &r);
		Creature f1('f', 0, &f);
		s.addCreature(0, 0, &r1);
		s.addCreature(0, 3, &f1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
        for(int i = 0; i < 7; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

            
    // ------------
    // darwin acceptance test 2
    // 2x4
    // ------------
        
    try {
        cout << "*** Darwin 2x4 ***" << endl;
        srand(0);
		Simulation s(2, 4, 1, 5);
		Creature r1('r', 2, &r);
		Creature f1('f', 0, &f);
		Creature t1('t', 1, &t);
		s.addCreature(0, 0, &r1);
		s.addCreature(0, 3, &f1);
		s.addCreature(1, 2, &t1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 10; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
    // ------------
    // darwin acceptance test 3
    // 1x5
    // ------------
        
    try {
        cout << "*** Darwin 1x5 ***" << endl;
        srand(0);
		Simulation s(1, 5, 1, 5);
		Creature h1('h', 2, &h);
		s.addCreature(0, 0, &h1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 10; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------
    // darwin acceptance test 4
    // 1x20
    // ------------
        
    try {
        cout << "*** Darwin 1x20 ***" << endl;
        srand(0);
		Simulation s(1, 20, 1, 5);
		Creature h1('h', 2, &h);
		Creature t1('t', 1, &t);
		Creature h2('h', 0, &h);
		s.addCreature(0, 0, &h1);
		s.addCreature(0, 10, &t1);
		s.addCreature(0, 19, &h2);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 20; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

 
    // ------------
    // darwin acceptance test 5
    // 1x1
    // ------------
        
    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
		Simulation s(1, 1, 1, 5);
		Creature f1('f', 2, &f);
		s.addCreature(0, 0, &f1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 3; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------
    // darwin acceptance test 6
    // 9x7
    // ------------
        
    try {
        cout << "*** Darwin 9x7 ***" << endl;
        srand(0);
		Simulation s(9, 7, 1, 5);
		Creature h1('h', 2, &h);
		Creature t1('t', 1, &t);
		Creature t2('t', 1, &t);
		Creature h2('h', 3, &h);
		Creature r1('r', 1, &r);
		s.addCreature(0, 0, &t1);
		s.addCreature(0, 2, &h1);
		s.addCreature(0, 6, &t2);
		s.addCreature(2, 6, &h2);
		s.addCreature(8, 0, &r1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 10; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin acceptance test 7
    // 3x7
    // ------------
        
    try {
        cout << "*** Darwin 3x7 ***" << endl;
        srand(0);
		Simulation s(3, 7, 1, 5);
		Creature t1('t', 3, &t);
		Creature f1('f', 0, &f);
		Creature f2('f', 1, &f);
		Creature f3('f', 2, &f);
		Creature f4('f', 3, &f);
		s.addCreature(1, 1, &t1);
		s.addCreature(1, 2, &f1);
		s.addCreature(1, 3, &f2);
		s.addCreature(1, 4, &f3);
		s.addCreature(1, 5, &f4);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 6; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin acceptance test 8
    // 5x1
    // ------------
        
    try {
        cout << "*** Darwin 5x1 ***" << endl;
        srand(0);
        Simulation s(5, 1, 1, 5);
		Creature t1('t', 2, &t);
		Creature r1('r', 1, &r);
		s.addCreature(0, 0, &t1);
		s.addCreature(4, 0, &r1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 5; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
		
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin acceptance test 9
    // 2x2
    // ------------
        
    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
		Simulation s(2, 2, 1, 5);
		Creature t1('t', 2, &t);
		Creature r1('r', 1, &r);
		s.addCreature(0, 0, &t1);
		s.addCreature(0, 1, &r1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 5; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
		
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin acceptance test 10
    // 5x4
    // ------------
        
    try {
        cout << "*** Darwin 5x4 ***" << endl;
        srand(0);
		Simulation s(5, 4, 1, 5);
		Creature r1('r', 3, &r);
		Creature r2('r', 1, &r);
		Creature f1('f', 1, &f);
		Creature f2('f', 1, &f);
		Creature f3('f', 1, &f);
		Creature f4('f', 1, &f);
		s.addCreature(2, 2, &r1);
		s.addCreature(2, 1, &r2);
		s.addCreature(4, 0, &f2);
		s.addCreature(0, 3, &f3);
		s.addCreature(4, 3, &f4);
		s.addCreature(0, 0, &f1);
        cout << "Turn = 0." << endl;
        s.printBoard(cout);
        cout << endl;
		for(int i = 0; i < 10; ++i) {
        	s.simulateTurn();
        	cout << "Turn = " << i+1 << "." << endl;
        	s.printBoard(cout);
        	cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
