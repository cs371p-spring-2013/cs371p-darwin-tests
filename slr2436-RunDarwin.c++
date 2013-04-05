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
        Game game(8,8);
        game.setupboard();
        Food a;
        Hopper c;
        game.putcreature(Creature(&a, 0, 0, 2), 0, 0);
        game.putcreature(Creature(&c, 3, 3, 1), 3, 3);
        game.putcreature(Creature(&c, 3, 4, 2), 3, 4);
        game.putcreature(Creature(&c, 4, 4, 3), 4, 4);
        game.putcreature(Creature(&c, 4, 3, 0), 4, 3);
        game.putcreature(Creature(&a, 7, 7, 1), 7, 7);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
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
        Game game(7,9);
        game.setupboard();
        Trap a;
        Hopper c;
        Rover d;
        game.putcreature(Creature(&a, 0, 0, 3), 0, 0);
        game.putcreature(Creature(&c, 3, 2, 2), 3, 2);
        game.putcreature(Creature(&d, 5, 4, 1), 5, 4);
        game.putcreature(Creature(&a, 6, 8, 0), 6, 8);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
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
         Game game(72,72);
         game.setupboard();
         Food a;
         Hopper b;
         Rover c;
         Trap d;
         
         
         for(int i = 0; i < 10; ++i){
         int pos = rand() % 5184;
         int x = pos/72;
         int y = pos%72;
            game.putcreature(Creature(&a, x, y, rand()%4), x, y);
         }
         for(int i = 0; i < 10; ++i){
         int pos = rand() % 5184;
         int x = pos/72;
         int y = pos%72;
            game.putcreature(Creature(&b,x, y, rand()%4), x, y);
         }
         for(int i = 0; i < 10; ++i){
         int pos = rand() % 5184;
         int x = pos/72;
         int y = pos%72;
            game.putcreature(Creature(&c,x, y, rand()%4), x, y);
         }
         for(int i = 0; i < 10; ++i){
         int pos = rand() % 5184;
         int x = pos/72;
         int y = pos%72;
            game.putcreature(Creature(&d,x, y, rand()%4), x, y);
         }
         
         cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 1000; i++){
            game.run();
            if(i%100 == 0){
                cout << "Turn = " << i << "." << endl;  
                game.printboard();
           }
        }
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
        srand(0);
        cout << "*** Darwin 8x8 test***" << endl;
        Game game(8,8);
        game.setupboard();
        Food a;
        Hopper c;
        Trap b;
        Rover d;
        game.putcreature(Creature(&b, 0, 0, 3), 0, 0);
        game.putcreature(Creature(&d, 0, 1, 0), 0, 1);
        game.putcreature(Creature(&a, 2, 0, 0), 2, 0);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
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
        
        
 try {
        srand(0);
        cout << "*** Darwin 1x1 test rover***" << endl;
        Game game(1,1);
        game.setupboard();
        Rover d;
        game.putcreature(Creature(&d, 0, 0, 3), 0, 0);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        1x1 Darwin
        Rover,   facing south,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
  try {
        srand(0);
        cout << "*** Darwin 2x2 test full map infect***" << endl;
        Game game(2,2);
        game.setupboard();
        Food d;
        Trap a;
        game.putcreature(Creature(&a, 1, 1, 1), 1, 1);
        game.putcreature(Creature(&d, 0, 0, 3), 0, 0);
        game.putcreature(Creature(&d, 0, 1, 3), 0, 1);
        game.putcreature(Creature(&d, 1, 0, 3), 1, 0);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        2x2 Darwin
        Rover,   facing south,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}     
        
        
        try {
        srand(0);
        cout << "*** Darwin 4x4 all hoppers***" << endl;
        Game game(4,4);
        game.setupboard();
        Hopper a;
        game.putcreature(Creature(&a, 1, 1, 3), 1, 1);
        game.putcreature(Creature(&a, 0, 0, 3), 0, 0);
        game.putcreature(Creature(&a, 0, 1, 3), 0, 1);
        game.putcreature(Creature(&a, 1, 0, 3), 1, 0);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        2x2 Darwin
        Rover,   facing south,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}   
        
        
        try {
        srand(0);
        cout << "*** Darwin 3x1 one rover***" << endl;
        Game game(3,1);
        game.setupboard();
        Rover a;
        game.putcreature(Creature(&a, 0, 0, 1), 0, 0);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 10; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        3x1 Darwin
        Rover,   facing north,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        
        
        
         try {
        srand(0);
        cout << "*** Darwin 3x3 all types on board***" << endl;
        Game game(3,3);
        game.setupboard();
        Rover a;
        Hopper b;
        Trap c;
        Food d;
        game.putcreature(Creature(&a, 0, 0, 1), 0, 0);
        game.putcreature(Creature(&b, 1, 0, 1), 1, 0);
        game.putcreature(Creature(&c, 0, 1, 1), 0, 1);
        game.putcreature(Creature(&d, 1, 1, 1), 1, 1);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        3x1 Darwin
        Rover,   facing north,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        
        
        
        
         try {
        srand(0);
        cout << "*** Darwin 1x10 hoppers facing each other***" << endl;
        Game game(1,10);
        game.setupboard();
        Hopper b;
        game.putcreature(Creature(&b, 0, 2, 2), 0, 2);
        game.putcreature(Creature(&b, 0, 3, 3), 0, 3);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 5; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        3x1 Darwin
        Rover,   facing north,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        
        
        
         try {
        srand(0);
        cout << "*** Darwin 11x11 testing printing out empty grid***" << endl;
        Game game(11,11);
        game.setupboard();
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 0; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        3x1 Darwin
        Rover,   facing north,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        
        
                 try {
        srand(0);
        cout << "*** Darwin 11x11 test 10 foods***" << endl;
        Game game(11,11);
        game.setupboard();
        Food d;
        game.putcreature(Creature(&d, 0, 0, 2), 0, 0);
        game.putcreature(Creature(&d, 0, 1, 2), 0, 1);
        game.putcreature(Creature(&d, 1, 0, 2), 1, 0);
        game.putcreature(Creature(&d, 9, 9, 2), 9, 9);
        cout << "Turn = 0." << endl;
        game.printboard();
        for(int i = 1; i <= 10; ++i){
            game.run();
            cout << "Turn = " << i << "." << endl;
            game.printboard();
        }
        /*
        3x1 Darwin
        Rover,   facing north,  at (0, 0)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        
        
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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}