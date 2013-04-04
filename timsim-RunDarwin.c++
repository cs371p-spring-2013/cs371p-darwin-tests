
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
    Instruction z(1, -1);
    Species food(z, 'f');
    food.add(8,0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Instruction j(0, -1);
    Species hopper(j, 'h');
    hopper.add(8, 0);     

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
    Instruction f(7, 9);
    Species rover(f, 'r');
    rover.add(4, 7);     
    rover.add(6, 5);
    rover.add(1, -1);
    rover.add(8, 0);
    rover.add(2, -1);
    rover.add(8, 0);
    rover.add(0, -1);
    rover.add(8, 0);
    rover.add(3, -1);
    rover.add(8, 0);

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
    Instruction i(7, 3);
    Species trap(i, 't');
    trap.add(1,-1);
    trap.add(8, 0);
    trap.add(3, -1);
    trap.add(8, 0);

    // ----------
    // darwin 2x2
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        /*
        2x2 Darwin
        Food,   facing east,  at (0, 0)
        Hopper, facing north, at (1, 0)
        
        Simulate 3 moves.
        Print every grid.
        */   
        Darwin d(8, 8);
        d.addCreature(food, 0 , 0 , 2);
        d.addCreature(hopper, 1, 0, 1);
        d.simulate(3, 1);
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
        /*
        2x2 Darwin
        Food,   facing east,  at (0, 0)
        Rover, facing north, at (1, 1)
        
        Simulate 3 moves.
        Print every grid.
        */   
        Darwin d(8, 8);
        d.addCreature(food, 0 , 0 , 2);
        d.addCreature(rover, 1, 1, 1);
        d.simulate(3, 1);
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
        /*
        2x2 Darwin
        Trap, facing east, at (0, 0)
        Trap, facing east, at (1, 0)
        Trap, facing south, at (0, 1)
        Rover, facing North at (1, 1)
        
        Simulate 3 moves.
        Print every grid.
        */   
        Darwin d(8, 8);
        d.addCreature(trap, 0, 0, 2);
        d.addCreature(trap, 1, 0, 2);
        d.addCreature(trap, 0, 1, 3);
        d.addCreature(rover, 1, 1, 1);
        d.simulate(3, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 10x1
    // ----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        /*
        10x1 Darwin
        Hopper, facing south, at (0, 0)
        Rover, facing south at (9, 0)
        
        Simulate 10 moves.
        Print every grid.
        */   
        Darwin d(10, 1);
        d.addCreature(hopper, 0, 0, 3);
        d.addCreature(rover, 9, 0, 3);
        d.simulate(10, 1);
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
        /*
        10x1 Darwin
        Trap, facing east at (0, 0)
        Trap, facing south at (1, 0)
        Trap, facing east at (0, 1)
        Trap, facing south at (1, 1)                            
        Rover, facing south at (3, 3)        
        
        Simulate 10 moves.
        Print every grid.
        */   
        Darwin d(4, 4);
        d.addCreature(trap, 0, 0, 2);
        d.addCreature(trap, 1, 0, 3);
        d.addCreature(trap, 0, 1, 2);
        d.addCreature(trap, 1, 1, 3);
        d.addCreature(rover, 3, 3, 3);
        d.simulate(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------
    // darwin 10x10
    // ----------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        /*
        10x10 Darwin
        Place 3 of each randomly
        Hopper, Rover, Food     
        
        Simulate 10 moves.
        Print every grid.
        */   
        Darwin d(10, 10);
        int x, y, n, dir;  
        for (int i = 0; i < 3; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(food, x, y, dir);
        }

        for (int i = 0; i < 3; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(hopper, x, y, dir);
        }

        for (int i = 0; i < 10; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(rover, x, y, dir);
        }
        d.simulate(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



     // ----------
    // darwin 10x10
    // ----------
        try {
        cout << "*** Darwin 10x10 ***" << endl;
        /*
        10x10 Darwin
        Place 10 Traps Randomly
        Place 2 Rovers 
        
        Simulate 10 moves.
        Print every grid.
        */   
        Darwin d(10, 10);
        int x, y, n, dir;  
        for (int i = 0; i < 2; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(rover, x, y, dir);
        }

        for (int i = 0; i < 10; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(trap, x, y, dir);
        }

        d.simulate(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------
    // darwin 10x10
    // ----------
        try {
        cout << "*** Darwin 10x10 ***" << endl;
        /*
        10x10 Darwin
        Place 1 Rover Randomly
        Place 5 Traps
        Place 5 Foods
        Place 5 Hoppers
        
        Simulate 10 moves.
        Print every grid.
        */   
        Darwin d(10, 10);
        int x, y, n, dir;  
        for (int i = 0; i < 1; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(rover, x, y, dir);
        }

        for (int i = 0; i < 5; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(trap, x, y, dir);
        }

        for (int i = 0; i < 5; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(food, x, y, dir);
        }

        for (int i = 0; i < 5; ++i){
            n = (rand() % 100) - 1;
            x = n / 10;
            y = n % 10; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(hopper, x, y, dir);
        }

        d.simulate(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


        






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
        Darwin d(8, 8);
        d.addCreature(food, 0 , 0 , 3);
        d.addCreature(food, 7 , 7 , 1);
        d.addCreature(hopper, 3, 3, 1);
        d.addCreature(hopper, 3, 4, 2);
        d.addCreature(hopper, 4, 4, 3);
        d.addCreature(hopper, 4, 3, 4);
        d.simulate(5, 1);
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
        Darwin d(7, 9);

        d.addCreature(trap, 0, 0, 3);
        d.addCreature(hopper, 3, 2, 2);
        d.addCreature(rover, 5, 4, 1);
        d.addCreature(trap, 6, 8, 4);

        d.simulate(5, 1);
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
        Darwin d(72,72);

        int x, y, n, dir;  
        for (int i = 0; i < 10; ++i){
            n = (rand() % 5184) - 1;
            x = n / 72;
            y = n % 72; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(food, x, y, dir);
        }

        for (int i = 0; i < 10; ++i){
            n = (rand() % 5184) - 1;
            x = n / 72;
            y = n % 72; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(hopper, x, y, dir);
        }

        for (int i = 0; i < 10; ++i){
            n = (rand() % 5184) - 1;
            x = n / 72;
            y = n % 72; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(rover, x, y, dir);
        }

        for (int i = 0; i < 10; ++i){
            n = (rand() % 5184) - 1;
            x = n / 72;
            y = n % 72; 
            dir = (rand() % 4);
            if( dir == 0)
                dir = 4;
            d.addCreature(trap, x, y, dir);
        }

        d.simulate(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    //....

    return 0;}
