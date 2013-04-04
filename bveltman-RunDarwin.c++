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
//
#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"
#include "Darwin.c++"
// ----
// main
// ----
//
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
        
        DarwinGame<8,8> g;
        g.addCreature(FOOD, EAST, 0, 0);
        g.addCreature(HOPPER, NORTH, 3,3);
        g.addCreature(HOPPER, EAST, 3, 4);
        g.addCreature(HOPPER, SOUTH, 4, 4);
        g.addCreature(HOPPER, WEST, 4, 3);
        g.addCreature(FOOD, NORTH, 7, 7);
        g.playGame(5, 1);
        
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
        
        DarwinGame<7,9> g;
        g.addCreature(TRAP, SOUTH, 0, 0);
        g.addCreature(HOPPER, EAST, 3,2);
        g.addCreature(ROVER, NORTH, 5, 4);
        g.addCreature(TRAP, WEST, 6, 8);
        g.playGame(5, 1);
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
        
       DarwinGame<72, 72> g;
       int p = (std::rand()%5184);
       int x = p/72;
       int y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
         p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
         p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
         p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
         p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        g.playGame(1000, 100);
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
        Call rand(), mod it with 72 (72x72), and use that for the position
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
        
        DarwinGame<72, 72> g;
        int p = (std::rand()&5184);
        int x = p/72;
        int y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(FOOD, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(HOPPER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);;
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(ROVER, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(TRAP, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        p = (std::rand()%5184);
        x = p/72;
        y = p-(x*72);
        g.addCreature(BEST, std::rand()%4, x, y);
        g.playGame(1000, 100);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 72x72 non-random ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 72 (72x72), and use that for the position
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
        
        DarwinGame<72, 72> g;
        g.addCreature(FOOD, SOUTH, 0, 0);
        g.addCreature(FOOD, NORTH, 3, 3);
        g.addCreature(FOOD, SOUTH, 4, 1);
        g.addCreature(FOOD, EAST, 9, 9);
        g.addCreature(FOOD, WEST, 50, 50);
        g.addCreature(FOOD, SOUTH, 51, 53);
        g.addCreature(FOOD, NORTH, 60, 60);
        g.addCreature(FOOD, SOUTH, 70, 68);
        g.addCreature(FOOD, WEST, 40, 10);
        g.addCreature(FOOD, SOUTH, 71, 71);
        g.addCreature(HOPPER, SOUTH, 1, 0);
        g.addCreature(HOPPER, NORTH, 3, 10);
        g.addCreature(HOPPER, SOUTH, 4, 10);
        g.addCreature(HOPPER, EAST, 9, 30);
        g.addCreature(HOPPER, WEST, 50, 70);
        g.addCreature(HOPPER, SOUTH, 51, 51);
        g.addCreature(HOPPER, NORTH, 60, 61);
        g.addCreature(HOPPER, SOUTH, 70, 10);
        g.addCreature(HOPPER, WEST, 40, 41);
        g.addCreature(HOPPER, SOUTH, 71, 0);
        g.addCreature(ROVER, SOUTH, 1, 10);
        g.addCreature(ROVER, NORTH, 33, 10);
        g.addCreature(ROVER, SOUTH, 43, 10);
        g.addCreature(ROVER, EAST, 23, 30);
        g.addCreature(ROVER, WEST, 57, 70);
        g.addCreature(ROVER, SOUTH, 51, 53);
        g.addCreature(ROVER, NORTH, 6, 61);
        g.addCreature(ROVER, SOUTH, 70, 1);
        g.addCreature(ROVER, WEST, 4, 47);
        g.addCreature(ROVER, SOUTH, 71, 5);
        g.addCreature(TRAP, SOUTH, 1, 7);
        g.addCreature(TRAP, NORTH, 33, 7);
        g.addCreature(TRAP, SOUTH, 43, 7);
        g.addCreature(TRAP, EAST, 23, 37);
        g.addCreature(TRAP, WEST, 57, 67);
        g.addCreature(TRAP, SOUTH, 51, 57);
        g.addCreature(TRAP, NORTH, 67, 61);
        g.addCreature(TRAP, SOUTH, 71, 50);
        g.addCreature(TRAP, WEST, 4, 52);
        g.addCreature(TRAP, SOUTH, 49, 5);
        g.addCreature(BEST, SOUTH, 1, 25);
        g.addCreature(BEST, NORTH, 25, 7);
        g.addCreature(BEST, SOUTH, 43, 25);
        g.addCreature(BEST, EAST, 23, 39);
        g.addCreature(BEST, WEST, 57, 57);
        g.addCreature(BEST, SOUTH, 12, 57);
        g.addCreature(BEST, NORTH, 67, 13);
        g.addCreature(BEST, SOUTH, 17, 50);
        g.addCreature(BEST, WEST, 4, 5);
        g.addCreature(BEST, SOUTH, 69, 5);
        g.playGame(1000, 100);
        
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
        cout << "*** Darwin 72x72 non-random 2 ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 72 (72x72), and use that for the position
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
        
        DarwinGame<72, 72> g;
        g.addCreature(FOOD, SOUTH, 0, 0);
        g.addCreature(FOOD, NORTH, 3, 3);
        g.addCreature(FOOD, SOUTH, 4, 1);
        g.addCreature(FOOD, EAST, 9, 9);
        g.addCreature(FOOD, WEST, 50, 50);
        g.addCreature(FOOD, SOUTH, 51, 53);
        g.addCreature(FOOD, NORTH, 60, 60);
        g.addCreature(FOOD, SOUTH, 70, 68);
        g.addCreature(FOOD, WEST, 40, 10);
        g.addCreature(FOOD, SOUTH, 71, 71);
        g.addCreature(HOPPER, SOUTH, 1, 0);
        g.addCreature(HOPPER, NORTH, 3, 10);
        g.addCreature(HOPPER, SOUTH, 4, 10);
        g.addCreature(HOPPER, EAST, 9, 30);
        g.addCreature(HOPPER, WEST, 50, 70);
        g.addCreature(HOPPER, SOUTH, 51, 51);
        g.addCreature(HOPPER, NORTH, 60, 61);
        g.addCreature(HOPPER, SOUTH, 70, 10);
        g.addCreature(HOPPER, WEST, 40, 41);
        g.addCreature(HOPPER, SOUTH, 71, 0);
        g.addCreature(ROVER, SOUTH, 1, 10);
        g.addCreature(ROVER, NORTH, 33, 10);
        g.addCreature(ROVER, SOUTH, 43, 10);
        g.addCreature(ROVER, EAST, 23, 30);
        g.addCreature(ROVER, WEST, 57, 70);
        g.addCreature(ROVER, SOUTH, 51, 53);
        g.addCreature(ROVER, NORTH, 6, 61);
        g.addCreature(ROVER, SOUTH, 70, 1);
        g.addCreature(ROVER, WEST, 4, 47);
        g.addCreature(ROVER, SOUTH, 71, 5);
        g.addCreature(TRAP, SOUTH, 1, 7);
        g.addCreature(TRAP, NORTH, 33, 7);
        g.addCreature(TRAP, SOUTH, 43, 7);
        g.addCreature(TRAP, EAST, 23, 37);
        g.addCreature(TRAP, WEST, 57, 67);
        g.addCreature(TRAP, SOUTH, 51, 57);
        g.addCreature(TRAP, NORTH, 67, 61);
        g.addCreature(TRAP, SOUTH, 71, 50);
        g.addCreature(TRAP, WEST, 4, 52);
        g.addCreature(TRAP, SOUTH, 49, 5);
        g.playGame(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    try {
        cout << "*** Darwin 10x10 ***" << endl;
        /*
        5x5 Darwin
        Simulate 10 moves.
        Print every grid.
        */
        
        DarwinGame<10,10> g;
        g.addCreature(ROVER, EAST, 0, 0);
        g.addCreature(ROVER, NORTH, 3,3);
        g.addCreature(ROVER, EAST, 3, 4);
        g.addCreature(BEST, SOUTH, 4, 4);
        g.addCreature(BEST, WEST, 4, 3);
        g.addCreature(BEST, NORTH, 7, 7);
        g.addCreature(TRAP, SOUTH, 5,5);
        g.playGame(10, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Darwin 20x20 ***" << endl;
        /*
        5x5 Darwin
        Simulate 20 moves.
        Print every grid.
        */
        
        DarwinGame<20,20> g;
        g.addCreature(ROVER, EAST, 0, 0);
        g.addCreature(ROVER, NORTH, 3,3);
        g.addCreature(ROVER, EAST, 3, 4);
        g.addCreature(BEST, SOUTH, 4, 4);
        g.addCreature(BEST, WEST, 4, 3);
        g.addCreature(BEST, NORTH, 7, 7);
        g.addCreature(TRAP, SOUTH, 5,5);
        g.addCreature(TRAP, SOUTH, 10,10);
        g.addCreature(TRAP, SOUTH, 10,11);
        g.addCreature(TRAP, SOUTH, 10,9);
        g.addCreature(HOPPER, NORTH, 19,15);
         g.addCreature(HOPPER, NORTH, 19,16);
        g.playGame(20, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Darwin 30x30 ***" << endl;
        /*
        30x30 Darwin
        Simulate 100 moves.
        Print every grid.
        */
        
        DarwinGame<30,30> g;
        g.addCreature(ROVER, EAST, 0, 0);
        g.addCreature(ROVER, NORTH, 3,3);
        g.addCreature(ROVER, EAST, 3, 4);
        g.addCreature(BEST, SOUTH, 4, 4);
        g.addCreature(BEST, WEST, 4, 3);
        g.addCreature(BEST, NORTH, 7, 7);
        g.addCreature(TRAP, SOUTH, 5,5);
        g.addCreature(TRAP, SOUTH, 10,10);
        g.addCreature(TRAP, SOUTH, 10,11);
        g.addCreature(TRAP, SOUTH, 10,9);
        g.addCreature(HOPPER, NORTH, 19,15);
        g.addCreature(HOPPER, NORTH, 19,16);
        g.addCreature(ROVER, EAST, 25, 25);
        g.addCreature(ROVER, NORTH, 25,26);
        g.addCreature(ROVER, EAST, 24, 14);
        g.addCreature(BEST, SOUTH, 20, 14);
        g.addCreature(BEST, WEST, 20, 13);
        g.addCreature(BEST, NORTH, 20, 17);
        g.playGame(100, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Darwin 4x4 ***" << endl;
        /*
        4x4 Darwin
        Simulate 10 moves.
        Print every grid.
        */
        
        DarwinGame<4,4> g;
        g.addCreature(ROVER, EAST, 0, 0);
        g.addCreature(BEST, WEST, 3, 3);
        g.playGame(10, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    

    return 0;}
