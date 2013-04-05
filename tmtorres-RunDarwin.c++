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
        
        Darwin d(8, 8);
        d.create(FOOD, EAST, 0, 0);
        d.create(HOPPER, NORTH, 3, 3);
        d.create(HOPPER, EAST, 3, 4);
        d.create(HOPPER, SOUTH, 4, 4);
        d.create(HOPPER, WEST, 4, 3);
        d.create(FOOD, WEST, 7, 7);
        d.simulate(5);
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
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 3, 2);
        d.create(ROVER, NORTH, 5, 4);
        d.create(TRAP, WEST, 6, 8);
        d.simulate(5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 21x21
    // ------------
    
    try {
        cout << "*** Darwin 21x21 ***" << endl;
        srand(0);
        Darwin d(21, 21);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 3, 2);
        d.create(ROVER, NORTH, 5, 4);
        d.create(TRAP, WEST, 6, 8);
        d.create(ROVER, WEST, 20, 20);
        d.simulate(50, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 21x21
    // ------------
    
    try {
        cout << "*** Darwin 21x21 ***" << endl;
        srand(0);
        Darwin d(21, 21);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 3, 2);
        d.create(ROVER, NORTH, 5, 4);
        d.create(TRAP, WEST, 6, 8);
        d.create(TRAP, WEST, 7, 9);
        d.create(TRAP, WEST, 10, 11);
        d.create(TRAP, WEST, 12, 13);
        d.create(ROVER, WEST, 20, 20);
        d.create(ROVER, NORTH, 19, 19);
        d.create(ROVER, EAST, 18, 18);
        d.create(ROVER, SOUTH, 17, 17);
        d.simulate(100, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 5x5
    // ------------
    
    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        Darwin d(5, 5);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 3, 2);
        d.create(ROVER, NORTH, 4, 4);
        d.create(FOOD, NORTH, 1, 1);
        d.simulate(100, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 10x10
    // ------------
    
    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Darwin d(10, 10);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 3, 2);
        d.create(ROVER, NORTH, 4, 4);
        d.create(FOOD, NORTH, 1, 1);
        d.create(TRAP, EAST, 7, 7);
        d.create(TRAP, WEST, 2, 2);
        d.create(TRAP, NORTH, 4, 3);
        d.create(TRAP, SOUTH, 9, 9);
        d.simulate(21);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 9x9
    // ----------
    
    try {
        cout << "*** Darwin 9x9 ***" << endl;
        srand(0);
        Darwin d(9, 9);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 2, 2);
        d.create(ROVER, NORTH, 5, 5);
        d.create(FOOD, NORTH, 8, 8);
        d.simulate(50, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 9x9
    // ----------
    
    try {
        cout << "*** Darwin 9x9 ***" << endl;
        srand(0);
        Darwin d(12, 12);
        d.create(TRAP, SOUTH, 0, 0);
        d.create(HOPPER, EAST, 2, 2);
        d.create(ROVER, NORTH, 5, 5);
        d.create(FOOD, NORTH, 8, 8);
        d.create(TRAP, NORTH, 11, 11);
        d.create(TRAP, WEST, 10, 10);
        d.create(TRAP, EAST, 7, 7);
        d.simulate(50, 10);
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
        
        Darwin g(72, 72);
        std::vector<int> indices;
        std::vector<int> cardinal;
        
        for(int i = 0; i < 40; ++i) {
            indices.push_back(rand() % 5184);
            cardinal.push_back(rand() % 4);
        }
        
        std::vector<int>::iterator ii = indices.begin();
        std::vector<int>::iterator di = cardinal.begin();
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(FOOD, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(HOPPER, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(ROVER, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(TRAP, *di, r, c);
            ++ii;
            ++di;
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
        
        Darwin g(72, 72);
        std::vector<int> indices;
        std::vector<int> cardinal;
        
        for(int i = 0; i < 50; ++i) {
            indices.push_back(rand() % 5184);
            cardinal.push_back(rand() % 4);
        }
        
        std::vector<int>::iterator ii = indices.begin();
        std::vector<int>::iterator di = cardinal.begin();
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(FOOD, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(HOPPER, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(ROVER, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(TRAP, *di, r, c);
            ++ii;
            ++di;
        }
        
        for(int i = 0; i < 10; ++i) {
            int n = *ii;
            int r = n / 72;
            int c = n - (r * 72);
            g.create(BEST, *di, r, c);
            ++ii;
            ++di;
        }
        g.simulate(1000, 100);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    return 0;}