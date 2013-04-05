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
    Species FOOD('f');
    FOOD.add_instr(LEFT, 0);
    FOOD.add_instr(GO, 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Species HOPPER('h');
    HOPPER.add_instr(HOP, 0);
    HOPPER.add_instr(GO, 0);

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
    Species ROVER('r');
    ROVER.add_instr(IF_ENEMY, 9);
    ROVER.add_instr(IF_EMPTY, 7);
    ROVER.add_instr(IF_RANDOM, 5);
    ROVER.add_instr(LEFT, 0);
    ROVER.add_instr(GO, 0);
    ROVER.add_instr(RIGHT, 0);
    ROVER.add_instr(GO, 0);
    ROVER.add_instr(HOP, 0);
    ROVER.add_instr(GO, 0);
    ROVER.add_instr(INFECT, 0);
    ROVER.add_instr(GO, 0);




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
    Species TRAP('t');
    TRAP.add_instr(IF_ENEMY, 3);
    TRAP.add_instr(LEFT, 0);
    TRAP.add_instr(GO, 0);
    TRAP.add_instr(INFECT, 0);
    TRAP.add_instr(GO, 0);

    // ----------
    // 1: darwin 10x1
    // -----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover,   facing north, at (5, 0)
        Simulate 10 moves.
        Print every grid.
        */
        Board b(10, 1);
        b.add_creature(Creature(ROVER, NORTH), 5, 0);
        Game g(b, std::cout);
        g.run(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 2: darwin 10x1
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
        Board b(1, 10);
        b.add_creature(Creature(ROVER, NORTH), 0, 5);
        Game g(b, std::cout);
        g.run(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 3: darwin 2x2
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
        Board b(2, 2);
        b.add_creature(Creature(ROVER, NORTH), 0, 0);
        b.add_creature(Creature(ROVER, SOUTH), 0, 1);
        b.add_creature(Creature(ROVER, EAST), 1, 0);
        b.add_creature(Creature(ROVER, WEST), 1, 1);
        Game g(b, std::cout);
        g.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

     // ----------
    // 4: darwin 3x3
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
        Board b(3, 3);
        b.add_creature(Creature(TRAP, NORTH), 0, 0);
        b.add_creature(Creature(TRAP, SOUTH), 0, 2);
        b.add_creature(Creature(TRAP, EAST), 2, 0);
        b.add_creature(Creature(TRAP, WEST), 2, 2);
        b.add_creature(Creature(ROVER, WEST), 1, 1);

        Game g(b, std::cout);
        g.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

 

    // ----------
    // 5: darwin 8x8
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
        b.add_creature(Creature(FOOD, EAST), 0, 0);
        b.add_creature(Creature(HOPPER, NORTH), 3, 3);
        b.add_creature(Creature(HOPPER, EAST), 3, 4);
        b.add_creature(Creature(HOPPER, SOUTH), 4, 4);
        b.add_creature(Creature(HOPPER, WEST), 4, 3);
        b.add_creature(Creature(FOOD, NORTH), 7, 7);
        Game g(b, std::cout);
        g.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 6: darwin 7x9
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
        Board b(7, 9);
        b.add_creature(Creature(TRAP, SOUTH), 0, 0);
        b.add_creature(Creature(HOPPER, EAST), 3, 2);
        b.add_creature(Creature(ROVER, NORTH), 5, 4);
        b.add_creature(Creature(TRAP, WEST), 6, 8);
        Game g(b, std::cout);
        g.run(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // 7: darwin 72x72
    // ------------

    try {
        cout << "*** ZOMBIE ATTACK!!! ***" << endl;
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
        int n = 25;
        int mod = n*n;
        Board b(n, n);
        for(int i = 0; i < 200; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(FOOD, dir), (pos/n), (pos%n)); 
        }
    for(int i = 0; i < 200; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(HOPPER, dir), (pos/n), (pos%n)); 
        }

             for(int i = 0; i < 1; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(ROVER, dir), (pos/n), (pos%n)); 
        }
             Game g(b, std::cout);
        g.run(60, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}




     // ------------
    // 8: darwin 72x72
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
        Board b(n, n);
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(FOOD, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(HOPPER, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(ROVER, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(TRAP, dir), (pos/n), (pos%n)); 
        }
        Game g(b, std::cout);
        g.run(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    

    // -------------------
    // 9: darwin 100x100
    // -------------------

    try {
        cout << "*** Darwin 100x100 without Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 10000 (100x100), and use that for the position
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
        int n = 100;
        int mod = n*n;
        Board b(n, n);
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(FOOD, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(HOPPER, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(ROVER, dir), (pos/n), (pos%n)); 
        }
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            b.add_creature(Creature(TRAP, dir), (pos/n), (pos%n)); 
        }
        Game g(b, std::cout);
        g.run(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    



    // ---------------
    // 10: darwin 5x5
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
        Board b(5, 5);
        b.add_creature(Creature(ROVER, EAST), 2, 0);
        b.add_creature(Creature(ROVER, SOUTH), 0, 2);
        b.add_creature(Creature(ROVER, WEST), 2, 4);
        b.add_creature(Creature(ROVER, NORTH), 4, 2);
        b.add_creature(Creature(ROVER, WEST), 2, 2);

        Game g(b, std::cout);
        g.run(5, 1);
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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
