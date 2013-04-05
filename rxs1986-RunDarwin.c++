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

#define NORTH 1
#define SOUTH 2
#define EAST  4
#define WEST  3

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
    Creature f('f', SOUTH, 0, 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Creature h('h', SOUTH, 0, 0);
    
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
    Creature r('r', SOUTH, 0, 0);
    
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
    Creature t('t', SOUTH, 0, 0);
    
    // ----------
    // 1: darwin 8x8
    // ----------

    try {
        cout << "***1: Darwin 8x8 ***" << endl;
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
            Game g(8,8,5);
            Creature h1('h',1,3,3);
            Creature h2('h',4,3,4);
            Creature h3('h',2,4,4);
            Creature h4('h',3,4,3);
            Creature f1('f',EAST,0,0);
            Creature f2('f',NORTH,7,7);
            g.add_creature(h1);
            g.add_creature(h2);
            g.add_creature(h3);
            g.add_creature(h4);
            g.add_creature(f1);
            g.add_creature(f2);
            g.run_game(1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 2: darwin 7x9
    // ----------

    try {
        cout << "***2: Darwin 7x9 ***" << endl;
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
            Game g(7,9,5);
            Creature t1('t',SOUTH,0,0);
            Creature h1('h',EAST,3,2);
            Creature r('r',NORTH,5,4);
            Creature t2('t',WEST,6,8);
            g.add_creature(t1);
            g.add_creature(h1);
            g.add_creature(r);
            g.add_creature(t2);
            g.run_game(1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // 3: darwin 72x72
    // without best
    // ------------

    try {
        cout << "***3: Darwin 72x72 without Best ***" << endl;
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
        Game g(72,72,1000);
            int n = 72;
            int mod = n*n;
            int  num_placed = 0;
            Creature f;
            while (num_placed < 10){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('f', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 10){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('h', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 10){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('r', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 10){
                int pos = rand() % mod;
                int dir = rand() % 4 + 1;
                f = Creature('t', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            g.run_game(100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // --------------
    // 4: darwin 10x1
    // --------------
    try {
        cout << "***4: Darwin 10x1 ***" << endl;
        Game g(10,1,10);
        Creature h1('h',1,9,0);
        g.add_creature(h1);
        g.run_game(1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
    // --------------
    // 5: darwin 1x10
    // --------------
    try {
        cout << "***5: Darwin 1x10 ***" << endl;
        Game g(1,10,5);
        Creature h1('h',4,0,0);
        g.add_creature(h1);
        g.run_game(1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    
    // --------------
    // 6: darwin 5x5
    // --------------
    try {
        cout << "***6: Darwin 5x5 ***" << endl;
        Game g(5,5,5);
        Creature h1('h',4,0,0);
        Creature h2('h',3,4,4);
        Creature r('r',1,2,2);
        g.add_creature(h1);
        g.add_creature(h2);
        g.add_creature(r);
        g.run_game(1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    // --------------
    // 7: darwin 10x10
    // --------------
    try {
        cout << "***7: Darwin 10x10 ***" << endl;
        Game g(10,10,10);
        Creature h1('h',4,0,0);
        Creature h2('h',3,4,4);
        Creature r1('r',1,2,2);
        Creature r2('r',2,4,3);
        Creature r3('r',3,6,5);
        Creature r4('r',4,8,7);
        Creature r5('r',1,7,9);
        Creature t1('t',3,4,1);
        Creature t2('t',3,9,4);
        g.add_creature(h1);
        g.add_creature(h2);
        g.add_creature(r1);
        g.add_creature(r2);
        g.add_creature(r3);
        g.add_creature(r4);
        g.add_creature(r5);
        g.add_creature(t1);
        g.add_creature(t2);
        g.run_game(1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // 8: darwin 50x50
    // without best
    // ------------

    try {
        cout << "***8: Darwin 50x50 ***" << endl;
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
        Game g(50,50,1000);
            int n = 50;
            int mod = n*n;
            int  num_placed = 0;
            Creature f;
            while (num_placed < 20){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('f', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 20){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('h', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 20){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('r', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 20){
                int pos = rand() % mod;
                int dir = rand() % 4 + 1;
                f = Creature('t', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            g.run_game(100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // 9: darwin 50x50
    // without best
    // ------------

    try {
        cout << "***9: Darwin 50x50 ***" << endl;
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
        Game g(50,50,1000);
            int n = 50;
            int mod = n*n;
            int  num_placed = 0;
            Creature f;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('f', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('h', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('r', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = rand() % 4 + 1;
                f = Creature('t', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            g.run_game(100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // 10: darwin 20x20
    // without best
    // ------------

    try {
        cout << "***10: Darwin 20x20 ***" << endl;
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
        Game g(20,20,1000);
            int n = 20;
            int mod = n*n;
            int  num_placed = 0;
            Creature f;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('f', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('h', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = (rand() % 4) + 1;
                f = Creature('r', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            num_placed = 0;
            while (num_placed < 50){
                int pos = rand() % mod;
                int dir = rand() % 4 + 1;
                f = Creature('t', dir, (pos/n),(pos%n));
                bool placed = g.add_creature(f);
                if (placed) {
                    ++num_placed;
                }
            }
            g.run_game(100);
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

