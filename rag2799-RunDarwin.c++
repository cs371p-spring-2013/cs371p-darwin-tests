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
        Board b(8, 8);
        b.addCreature(food, 0, 0, 2);
        b.addCreature(hopper, 3, 3, 1);
        b.addCreature(hopper, 3, 4, 2);
        b.addCreature(hopper, 4, 4, 3);
        b.addCreature(hopper, 4, 3, 0);
        b.addCreature(food, 7, 7, 1);

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){ 
          b.display(cout);
          b.run(1);
          cout << "\nTurn = " << x << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        cout << "\n*** Darwin 7x9 ***" << endl;
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
        b.addCreature(trap, 0, 0, 3);
        b.addCreature(hopper, 3, 2, 2);
        b.addCreature(rover, 5, 4, 1);
        b.addCreature(trap, 6, 8, 0);

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){
          b.display(cout);
          b.run(1);
          cout << "\nTurn = " << x << ".\n";
        } b.display(cout);
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
        cout << "\n*** Darwin 72x72 without Best ***" << endl;
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
        srand(0);
        Board b(72, 72);
        //create 10 foods
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(food, loc/72, loc%72, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(hopper, loc/72, loc%72, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(rover, loc/72, loc%72, dir);
        }
        //create 10 traps
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(trap, loc/72, loc%72, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 10; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
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
        cout << "\n*** Darwin 72x72 with Best ***" << endl;
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
        srand(0);
        Board b(72, 72);
        //create 10 foods
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(food, loc/72, loc%72, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(hopper, loc/72, loc%72, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(rover, loc/72, loc%72, dir);
        }
        //create 10 traps
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(trap, loc/72, loc%72, dir);
        }
        //create 10 bests
        for(int x = 0; x < 10; ++x){
          int loc = rand()%5184;
          int dir = rand()%4;
          b.addCreature(best, loc/72, loc%72, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 10; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 4x4
    // 1
    // ----------

    try {
        cout << "\n*** Darwin 4x4 without Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 5184 (72x72), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        1 Food
        1 Hopper
        1 Rover
        1 Trap
        Simulate 300 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
        srand(0);
        Board b(4, 4);
        // Create one random of each creature
        int loc = rand()%16;
        int dir = rand()%4;
        b.addCreature(food, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(hopper, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(trap, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(rover, loc/4, loc%4, dir);

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 3; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 4x4
    // 2
    // ----------

    try {
        cout << "\n*** Darwin 4x4 with Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 61 (4x4), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        1 Food
        1 Hopper
        1 Rover
        1 Trap
        1 Best
        Simulate 300 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
        srand(0);
        Board b(4, 4);
        // Create one random of each creature
        int loc = rand()%16;
        int dir = rand()%4;
        b.addCreature(food, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(hopper, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(trap, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(rover, loc/4, loc%4, dir);
        loc = rand()%16;
        dir = rand()%4;
        b.addCreature(best, loc/4, loc%4, dir);
        

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 3; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 8x8
    // without best
    // 3 of my own
    // ------------

    try {
        cout << "\n*** Darwin 8x8 without Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 64 (8x8), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        3 Food
        3 Hopper
        3 Rover
        3 Trap
        Simulate 500 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
        srand(0);
        Board b(8, 8);
        //create 10 foods
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(food, loc/8, loc%8, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(hopper, loc/8, loc%8, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(rover, loc/8, loc%8, dir);
        }
        //create 10 traps
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(trap, loc/8, loc%8, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 8x8
    // without best
    // 4 of my own
    // ------------

    try {
        cout << "\n*** Darwin 8x8 without Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 64 (16x16), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        3 Food
        3 Hopper
        3 Rover
        3 Trap
        3 Best
        Simulate 500 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
        srand(0);
        Board b(8, 8);
        //create 10 foods
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(food, loc/8, loc%8, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(hopper, loc/8, loc%8, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(rover, loc/8, loc%8, dir);
        }
        //create 10 traps
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        //create 10 bests
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(best, loc/8, loc%8, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 8x8
    // trap field without best
    // 5 of my own
    // ------------

    try {
        cout << "\n*** Darwin 8x8: trap field without Best ***" << endl;
        /*
        Create a square of traps with random creatures on the board.
        Set other creatures randomly around (3 of each)
        Run 500 turns, printing every 100th
        */
        srand(0);
        Board b(8, 8);
        //create 3 foods
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(food, loc/8, loc%8, dir);
        }
        //create 3 hoppers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(hopper, loc/8, loc%8, dir);
        }
        //create 3 rovers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(rover, loc/8, loc%8, dir);
        }
        //create trap field
        for(int x = 0; x < 4; ++x){
          int loc = 3*8 + 3 + x;
          int dir = 1;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 2; ++x){
          int loc = (4+x)*8 + 3;
          int dir = 0;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 2; ++x){
          int loc = (4+x)*8 + 6;
          int dir = 2;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 4; ++x){
          int loc = 6*8 + 3 + x;
          int dir = 3;
          b.addCreature(trap, loc/8, loc%8, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 8x8
    // trap field with best
    // 6 of my own
    // ------------

    try {
        cout << "\n*** Darwin 8x8: trap field with Best ***" << endl;
        /*
        Create a square of traps with random creatures on the board.
        Set other creatures randomly around (3 of each)
        Run 500 turns, printing every 100th
        */
        srand(0);
        Board b(8, 8);
        //create 3 foods
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(food, loc/8, loc%8, dir);
        }
        //create 3 hoppers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(hopper, loc/8, loc%8, dir);
        }
        //create 3 rovers
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(rover, loc/8, loc%8, dir);
        }
        //create 3 bests
        for(int x = 0; x < 3; ++x){
          int loc = rand()%64;
          int dir = rand()%4;
          b.addCreature(best, loc/8, loc%8, dir);
        }
        //create trap field
        for(int x = 0; x < 4; ++x){
          int loc = 3*8 + 3 + x;
          int dir = 1;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 2; ++x){
          int loc = (4+x)*8 + 3;
          int dir = 0;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 2; ++x){
          int loc = (4+x)*8 + 6;
          int dir = 2;
          b.addCreature(trap, loc/8, loc%8, dir);
        }
        for(int x = 0; x < 4; ++x){
          int loc = 6*8 + 3 + x;
          int dir = 3;
          b.addCreature(trap, loc/8, loc%8, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 5; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 40x40
    // with best
    // seventh of my own
    // ------------

    try {
        cout << "\n*** Darwin 40x40 with Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 1600 (40x40), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        5 Food
        5 Hopper
        5 Rover
        5 Trap
        5 Best
        Simulate 1000 moves.
        Print every 100th grid.
        */
        srand(0);
        Board b(80, 80);
        //create 5 foods
        for(int x = 0; x < 5; ++x){
          int loc = rand()%1600;
          int dir = rand()%4;
          b.addCreature(food, loc/40, loc%40, dir);
        }
        //create 5 hoppers
         for(int x = 0; x < 5; ++x){
          int loc = rand()%1600;
          int dir = rand()%4;
          b.addCreature(hopper, loc/40, loc%40, dir);
        }
        //create 5 rovers
         for(int x = 0; x < 5; ++x){
          int loc = rand()%1600;
          int dir = rand()%4;
          b.addCreature(rover, loc/40, loc%40, dir);
        }
        //create 5 traps
         for(int x = 0; x < 5; ++x){
          int loc = rand()%1600;
          int dir = rand()%4;
          b.addCreature(trap, loc/40, loc%40, dir);
        }
        //create 5 bests
         for(int x = 0; x < 5; ++x){
          int loc = rand()%1600;
          int dir = rand()%4;
          b.addCreature(best, loc/40, loc%40, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 10; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 80x80
    // without best
    // eighth of my own
    // ------------

    try {
        cout << "\n*** Darwin 80x80 without Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 6400 (80x80), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        Simulate 1000 moves.
        Print every 100th grid.
        */
        srand(0);
        Board b(80, 80);
        //create 10 foods
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(food, loc/80, loc%80, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(hopper, loc/80, loc%80, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(rover, loc/80, loc%80, dir);
        }
        //create 10 traps
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(trap, loc/80, loc%80, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 10; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 80x80
    // with best
    // ninth of my own
    // ------------

    try {
        cout << "\n*** Darwin 80x80 with Best ***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 6400 (80x80), and use that for the position
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
        srand(0);
        Board b(80, 80);
        //create 10 foods
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(food, loc/80, loc%80, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(hopper, loc/80, loc%80, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(rover, loc/80, loc%80, dir);
        }
        //create 10 traps
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(trap, loc/80, loc%80, dir);
        }
        //create 10 bests
        for(int x = 0; x < 10; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(best, loc/80, loc%80, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 10; ++x){
          b.display(cout);
          b.run(100);
          cout << "\nTurn = " << x*100 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 80x80
    // with best and more creatures, more turns
    // final (10)
    // ------------

    try {
        cout << "\n*** Darwin 80x80 with Best and 30 of each + 30000 turns***" << endl;
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 6400 (80x80), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        30 Food
        30 Hopper
        30 Rover
        30 Trap
        30 Best
        Simulate 30000 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 1000th grid.
        */
        srand(0);
        Board b(80, 80);
        //create 10 foods
        for(int x = 0; x < 30; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(food, loc/80, loc%80, dir);
        }
        //create 10 hoppers
        for(int x = 0; x < 30; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(hopper, loc/80, loc%80, dir);
        }
        //create 10 rovers
        for(int x = 0; x < 30; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(rover, loc/80, loc%80, dir);
        }
        //create 10 traps
        for(int x = 0; x < 30; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(trap, loc/80, loc%80, dir);
        }
        //create 10 bests
        for(int x = 0; x < 30; ++x){
          int loc = rand()%6400;
          int dir = rand()%4;
          b.addCreature(best, loc/80, loc%80, dir);
        }

        cout << "Turn = 0.\n";
        for(int x = 1; x <= 30; ++x){
          b.display(cout);
          b.run(1000);
          cout << "\nTurn = " << x*1000 << ".\n";
        } b.display(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    return 0;}
