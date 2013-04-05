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
    
    Species food('f');
    food.add_instruction(LEFT);
    food.add_instruction(GO, 0);
    
    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    
    Species hopper('h');
    hopper.add_instruction(HOP);
    hopper.add_instruction(GO, 0);

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
    rover.add_instruction(IF_ENEMY, 9);
    rover.add_instruction(IF_EMPTY, 7);
    rover.add_instruction(IF_RANDOM, 5);
    rover.add_instruction(LEFT);
    rover.add_instruction(GO, 0);
    rover.add_instruction(RIGHT);
    rover.add_instruction(GO, 0);
    rover.add_instruction(HOP);
    rover.add_instruction(GO, 0);
    rover.add_instruction(INFECT);
    rover.add_instruction(GO, 0);

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
    trap.add_instruction(IF_ENEMY, 3);
    trap.add_instruction(LEFT);
    trap.add_instruction(GO, 0);
    trap.add_instruction(INFECT);
    trap.add_instruction(GO, 0);
    
    // ----
    // best
    // ----
    
    /*
    
    */
    
    Species best('b');
    best.add_instruction(IF_ENEMY, 9);
    best.add_instruction(IF_EMPTY, 7);
    best.add_instruction(IF_RANDOM, 5);
    best.add_instruction(LEFT);
    best.add_instruction(GO, 0);
    best.add_instruction(RIGHT);
    best.add_instruction(GO, 0);
    best.add_instruction(HOP);
    best.add_instruction(GO, 0);
    best.add_instruction(INFECT);
    best.add_instruction(GO, 0);

    // ----------
    // 1. darwin 8x8
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
        Darwin d(8, 8);
        d.add_creature(Creature(food), EAST, 0, 0);
        d.add_creature(Creature(hopper), NORTH, 3, 3);
        d.add_creature(Creature(hopper), EAST, 3, 4);
        d.add_creature(Creature(hopper), SOUTH, 4, 4);
        d.add_creature(Creature(hopper), WEST, 4, 3);
        d.add_creature(Creature(food), NORTH, 7, 7);
        d.run(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 2. darwin 7x9
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
        Darwin d(7, 9);
        d.add_creature(Creature(trap), SOUTH, 0, 0);
        d.add_creature(Creature(hopper), EAST, 3, 2);
        d.add_creature(Creature(rover), NORTH, 5, 4);
        d.add_creature(Creature(trap), WEST, 6, 8);
        d.run(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // 3. darwin 72x72
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
        int n = 72;
        int mod = n*n;
        Darwin d(n, n);
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(food), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(hopper), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(rover), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(trap), dir, (pos/n), (pos%n)); 
        }
        d.run(1000, 100);
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }

    // ------------
    // 4. darwin 72x72
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
        int n = 72;
        int mod = n*n;
        Darwin d(n, n);
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(food), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(hopper), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(rover), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(trap), dir, (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            d.add_creature(Creature(best), dir, (pos/n), (pos%n)); 
        }
        d.run(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // 5: darwin 5x5
    // --------------
    
    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        /*
        5x5 Darwin
        Rover,   facing east, at (2, 0)
        Rover,   facing south, at (0, 2)
        Rover,   facing west, at (2, 4)
        Rover,   facing north, at (4, 2)
        Rover,   facing west, at (2, 2)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin b(5, 5);
        b.add_creature(Creature(rover), EAST, 2, 0);
        b.add_creature(Creature(rover), SOUTH, 0, 2);
        b.add_creature(Creature(rover), WEST, 2, 4);
        b.add_creature(Creature(rover), NORTH, 4, 2);
        b.add_creature(Creature(rover), WEST, 2, 2);
        b.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 6: darwin 3x3
    // ----------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);
        /*
        3x3 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 2)
        Rover,   facing east, at (2, 0)
        Rover,   facing west, at (2, 2)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin b(3, 3);
        b.add_creature(Creature(trap), NORTH, 0, 0);
        b.add_creature(Creature(trap), SOUTH, 0, 2);
        b.add_creature(Creature(trap), EAST, 2, 0);
        b.add_creature(Creature(trap), WEST, 2, 2);
        b.add_creature(Creature(rover), WEST, 1, 1);
        b.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 7: darwin 10x1
    // -----------

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        srand(0);
        /*
        1x10 Darwin
        Rover,   facing north, at (0, 5)
        Simulate 10 moves.
        Print every grid.
        */
        Darwin b(1, 10);
        b.add_creature(Creature(rover), NORTH, 0, 5);
        b.run(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 8: darwin 2x2
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        /*
        2x2 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 1)
        Rover,   facing east, at (1, 0)
        Rover,   facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin b(2, 2);
        b.add_creature(Creature(rover), NORTH, 0, 0);
        b.add_creature(Creature(rover), SOUTH, 0, 1);
        b.add_creature(Creature(rover), EAST, 1, 0);
        b.add_creature(Creature(rover), WEST, 1, 1);
        b.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 9: darwin 1x1
    // ----------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        2x2 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 1)
        Rover,   facing east, at (1, 0)
        Rover,   facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin b(1, 1);
        b.add_creature(Creature(rover), NORTH, 0, 0);
        b.add_creature(Creature(trap), NORTH, 0, 0);
        b.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 10: darwin 1x1
    // ----------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        2x2 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 1)
        Rover,   facing east, at (1, 0)
        Rover,   facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin b(1, 1);
        b.add_creature(Creature(rover), NORTH, 4, 3);
        b.add_creature(Creature(trap), NORTH, 0, 0);
        b.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    return 0;}