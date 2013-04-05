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

	Species food('f');
	food.addInstruction(string("left"));
	food.addInstruction("go", 0);
	
    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
	Species hopper('h');
	hopper.addInstruction(string("hop"));
	hopper.addInstruction("go", 0);
	
	
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
    
    Species rover('r');
	rover.addInstruction("if_enemy", 9);
	rover.addInstruction("if_empty", 7);
	rover.addInstruction("if_random", 5);
	rover.addInstruction(string("left"));
	rover.addInstruction("go", 0);
	rover.addInstruction(string("right"));
	rover.addInstruction("go", 0);
	rover.addInstruction(string("hop"));
	rover.addInstruction("go", 0);
	rover.addInstruction(string("infect"));
	rover.addInstruction("go", 0);
	
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
    
    Species trap('t');
	trap.addInstruction("if_enemy", 3);
	trap.addInstruction(string("left"));
	trap.addInstruction("go", 0);
	trap.addInstruction(string("infect"));
	trap.addInstruction("go", 0);
	
	
	// ----
    // best
    // ----

    /*
     0: if_enemy 2
     1: go 3
     2: invade
     3: if_wall 5
     4: go 0
     5: left
    */
    
    Species best('b');
	best.addInstruction("if_enemy", 3);
	best.addInstruction("if_wall", 5);
	best.addInstruction("if_empty", 7);
	best.addInstruction(string("infect"));
	best.addInstruction("go", 0);
	best.addInstruction(string("left"));
	best.addInstruction("go", 0);
	best.addInstruction(string("hop"));
	best.addInstruction("go", 0);

	

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
        
        Grid g(8, 8);
        Creature F1(&food, EAST);
        Creature H1(&hopper, NORTH);
        Creature H2(&hopper, EAST);
        Creature H3(&hopper, SOUTH);
        Creature H4(&hopper, WEST);
        Creature F2(&food, NORTH);
        g.addCreature(&F1, 0, 0);
        g.addCreature(&H1, 3, 3);
        g.addCreature(&H2, 3, 4);
        g.addCreature(&H3, 4, 4);
        g.addCreature(&H4, 4, 3);
        g.addCreature(&F2, 7, 7);
        g.simulate(5, 1);
        
        
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
        
        Grid g(7, 9);
        Creature T1(&trap, SOUTH);
        Creature H1(&hopper, EAST);
        Creature R1(&rover, NORTH);
        Creature T2(&trap, WEST);
        g.addCreature(&T1, 0, 0);
        g.addCreature(&H1, 3, 2);
        g.addCreature(&R1, 5, 4);
        g.addCreature(&T2, 6, 8);
        g.simulate(5, 1);
        
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
        Grid g(72,72);
        for (int i = 0; i < 10; ++i) {
        	Creature F(&food, rand() % 4);
        	Creature H(&hopper, rand() % 4);
        	Creature R(&rover, rand() % 4);
        	Creature T(&trap, rand() % 4);
        	g.addCreature(&F, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&H, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&R, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&T, rand() % 5184 / 72, rand() % 5184 / 72);
        }
        g.simulate(1000, 100);
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
        Grid g(72,72);
        for (int i = 0; i < 10; ++i) {
        	Creature F(&food, rand() % 4);
        	Creature H(&hopper, rand() % 4);
        	Creature R(&rover, rand() % 4);
        	Creature T(&trap, rand() % 4);
        	Creature B(&best, rand() % 4);
        	g.addCreature(&F, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&H, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&R, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&T, rand() % 5184 / 72, rand() % 5184 / 72);
        	g.addCreature(&B, rand() % 5184 / 72, rand() % 5184 / 72);
        }
        g.simulate(1000, 100);
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
        
        Grid g(2, 2);
        Creature R(&rover, WEST);
        Creature F(&food, WEST);
        Creature T(&trap, WEST);
        g.addCreature(&R, 0, 0);
        g.addCreature(&F, 1, 1);
        g.addCreature(&T, 1, 0);
        g.simulate(10, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 100x20
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        
        Grid g(100, 20);
        Creature R(&rover, WEST);
        g.addCreature(&R, 1, 0);
        g.simulate(100, 20);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
    
    // ----------
    // darwin 10x20
    // ----------

    try {
        cout << "*** Darwin 10x20 ***" << endl;
        
        Grid g(10, 20);
        Creature R(&rover, WEST);
        Creature R1(&rover, WEST);
        Creature R2(&rover, WEST);
        Creature T1(&trap, WEST);
        Creature H1(&hopper, WEST);
        Creature F(&food, WEST);
        g.addCreature(&R, 0, 11);
        g.addCreature(&R1, 9, 13);
        g.addCreature(&R2, 4, 5);
        g.addCreature(&T1, 2, 0);
        g.addCreature(&F, 2, 10);
        g.simulate(100, 10);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        // ----------
    // darwin 1x10
    // ----------

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        /*
        8x8 Darwin
        Food,   facing east,  at (0, 0)
        Food,   facing north, at (0, 9)
        Simulate 10 moves.
        Print every grid.
        */
        
        Grid g(1, 10);
        Creature F1(&food, EAST);
        Creature F2(&food, NORTH);
        g.addCreature(&F1, 0, 0);
        g.addCreature(&F2, 0, 9);
        g.simulate(10, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ----------
    // darwin 10x10
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        /*
        5x5 Darwin
        Hopper, facing south, at (0, 0)
        Hopper, facing east, at  (1, 1)
        Hopper, facing north, at (2, 2)
        Hopper, facing south, at (3, 3)
        Hopper, facing south, at (4, 4)
        Simulate 10 moves.
        Print every grid.
        */
        
        Grid g(5, 5);
        Creature H1(&hopper, SOUTH);
        Creature H2(&hopper, EAST);
        Creature H3(&hopper, NORTH);
        Creature H4(&hopper, WEST);
        Creature H5(&hopper, NORTH);
        g.addCreature(&H1, 0, 0);
        g.addCreature(&H2, 1, 1);
        g.addCreature(&H3, 2, 2);
        g.addCreature(&H4, 3, 3);
        g.addCreature(&H5, 4, 4);
        g.simulate(10, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ----------
    // darwin 20x20
    // ----------

    try {
        cout << "*** Darwin 20x20 ***" << endl;
        
        Grid g(20, 20);
        Creature R(&rover, WEST);
        Creature F(&food, WEST);
        g.addCreature(&R, 0, 0);
        g.addCreature(&F, 19, 19);
        g.simulate(100, 10);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}