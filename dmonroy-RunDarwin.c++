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

    // ----
    // best
    // ----

    /*
     0: if_empty 6
     1: if_enemy 4
     2: left
     3: go 0
     4: infect
     5: go 0
     6: hop
     7: go 0
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
    
        World w(8, 8);
        w.addCreature(0, 2, 0, 0);
        w.addCreature(1, 1, 3, 3);
        w.addCreature(1, 2, 3, 4);
        w.addCreature(1, 3, 4, 4);
        w.addCreature(1, 0, 4, 3);
        w.addCreature(0, 1, 7, 7);
        
        for(int i = 0; i < 5; ++i)
        {
            w.print(); 
            w.play();
        }
         w.print(); 
    
    
    
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
    
    
        World w(7, 9);
        w.addCreature(3, 3, 0, 0);
        w.addCreature(1, 2, 3, 2);
        w.addCreature(2, 1, 5, 4);
        w.addCreature(3, 0, 6, 8);
        
        for(int i = 0; i < 5; ++i){

            w.print(); 
            w.play();
            
        }
        w.print();
    
    
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
        srand(0);
        /*
        4x4 Darwin
        Trap,   facing south, at (1, 0)
        Hopper, facing east,  at (1, 1)

        Simulate 10 moves.
        Print every grids.
        */
    
        World w(4, 4);
        w.addCreature(3, 3, 1, 0);
        w.addCreature(1, 2, 1, 1);
        
        for(int i = 0; i < 10; ++i){

            w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        

    // ----------
    // darwin 14x14 With best
    // ----------

    try {
        cout << "*** Darwin 14x14 with best***" << endl;
        srand(0);
        /*
        14x4 Darwin
        3 Hopper
        5 Best
        Simulate 100 moves.
        Print every 10 grids.
        */
    
        World w(14, 14);
        w.addCreature(1, rand()%4, rand()%14, rand()%14);
        w.addCreature(1, rand()%4, rand()%14, rand()%14);
        w.addCreature(1, rand()%4, rand()%14, rand()%14);

        w.addCreature(4, rand()%4, rand()%14, rand()%14);
        w.addCreature(4, rand()%4, rand()%14, rand()%14);
        w.addCreature(4, rand()%4, rand()%14, rand()%14);
        w.addCreature(4, rand()%4, rand()%14, rand()%14);
        w.addCreature(4, rand()%4, rand()%14, rand()%14);

        
        for(int i = 0; i < 100; ++i){
            if((i%10) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
    // ----------
    // darwin 9x9  -----ACCEPTANCE TEST
    // ----------

    try {
        cout << "*** Darwin 9x9 ***" << endl;
        srand(0);
        /*
        9x9 Darwin
        3 Food
        3 Hoopers
        2 Rovers
        3 Traps
        Simulate 5 moves.
        Print every grid.
        */
    
        World w(9, 9);
        
        w.addCreature(0, rand()%4, rand()%9, rand()%9);
        w.addCreature(0, rand()%4, rand()%9, rand()%9);
        w.addCreature(0, rand()%4, rand()%9, rand()%9);
        
        w.addCreature(1, rand()%4, rand()%9, rand()%9);
        w.addCreature(1, rand()%4, rand()%9, rand()%9);
        w.addCreature(1, rand()%4, rand()%9, rand()%9);
        
        w.addCreature(2, rand()%4, rand()%9, rand()%9);
        w.addCreature(2, rand()%4, rand()%9, rand()%9);
        
        w.addCreature(3, rand()%4, rand()%9, rand()%9);
        w.addCreature(3, rand()%4, rand()%9, rand()%9);
        w.addCreature(3, rand()%4, rand()%9, rand()%9);
        
        w.addCreature(4, rand()%4, rand()%9, rand()%9);
        w.addCreature(4, rand()%4, rand()%9, rand()%9);
        w.addCreature(4, rand()%4, rand()%9, rand()%9);
        
        for(int i = 0; i < 10; ++i){
          
            w.print();        
            w.play();
            
        }
         w.print();               
    
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
    
        World w(72, 72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        
        for(int i = 0; i < 1000; ++i){
            if((i%100) == 0)
            w.print(); 
            w.play();
            
        }
          w.print();

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
        World w(72, 72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        w.addCreature(0, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        w.addCreature(1, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        w.addCreature(2, rand()%4, rand()%72, rand()%72);
        
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);
        w.addCreature(3, rand()%4, rand()%72, rand()%72);

        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);
        w.addCreature(4, rand()%4, rand()%72, rand()%72);

        for(int i = 0; i < 1000; ++i){
            if((i%100) == 0)
            w.print(); 
            w.play();
            
        }
          w.print();
        }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 10x10 With best
    // ----------

    try {
        cout << "*** Darwin 10x10 with best***" << endl;
        srand(0);
        /*
        10x10 Darwin
        30 Rover
        10 Best
        Simulate 1000 moves.
        Print every 100 grids.
        */
    
        World w(10, 10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);

        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);

        
        for(int i = 0; i < 1000; ++i){
            if((i%100) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 10x10 With best
    // ----------

    try {
        cout << "*** Darwin 10x10 with best***" << endl;
        srand(0);
        /*
        10x10 Darwin
        30 Rover
        10 Best
        Simulate 5000 moves.
        Print every 1000 grids.
        */
    
        World w(10, 10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);


        
        for(int i = 0; i < 5000; ++i){
            if((i%1000) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 10x10 With best
    // ----------

    try {
        cout << "*** Darwin 10x10 with best***" << endl;
        srand(0);
        /*
        10x10 Darwin
        30 Traps
        10 Rovers
        10 Best
        Simulate 5000 moves.
        Print every 1000 grids.
        */
    
        World w(10, 10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);
        w.addCreature(4, rand()%4, rand()%10, rand()%10);

        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        w.addCreature(3, rand()%4, rand()%10, rand()%10);
        
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);
        w.addCreature(2, rand()%4, rand()%10, rand()%10);


        
        for(int i = 0; i < 5000; ++i){
            if((i%1000) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 20x20 With best
    // ----------

    try {
        cout << "*** Darwin 20x20 with best***" << endl;
        srand(0);
        /*
        20x20 Darwin
        10 Traps
        5 Rovers
        10 Best
        Simulate 5000 moves.
        Print every 1000 grids.
        */
    
        World w(20, 20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);

        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);

        
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);


        
        for(int i = 0; i < 5000; ++i){
            if((i%1000) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 20x20 With best
    // ----------

    try {
        cout << "*** Darwin 20x20 with best***" << endl;
        srand(0);
        /*
        20x20 Darwin
        20 Traps
        5 Rovers
        10 Best
        Simulate 2000 moves.
        Print every 500 grids.
        */
    
        World w(20, 20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);
        w.addCreature(4, rand()%4, rand()%20, rand()%20);

        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);
        w.addCreature(3, rand()%4, rand()%20, rand()%20);

        
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);
        w.addCreature(2, rand()%4, rand()%20, rand()%20);


        
        for(int i = 0; i < 2000; ++i){
            if((i%500) == 0)
                w.print(); 
            w.play();
            
        }
        w.print();
    
    
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}