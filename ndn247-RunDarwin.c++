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
#include <map>       // player-location mappings
#include <utility>   // std::pair, std::make_pair

#include "Darwin.h"

using namespace std;


pair<int, int> getRandLocation() {
    int n = rand() % 5184;
    int row = n / 72;
    int col = n % 72;
    return make_pair(row, col); 
}

Direction getRandDirection() {
    int n = rand() % 4;
    switch(n) {
        case 0:
            return west;
        case 1:
            return north;
        case 2:
            return east;
        case 3:
            return south;
    }
}

// ----
// main
// ----

int main () {
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

    // ------
    // best      version of trap that can turn left or right
    // ------

    /*
      0: if_enemy 6
      1: if_random 4
      2: left
      3: go 0
      4: right
      5: go 0
      6: infect
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
        map<location_type, Creature*> players; 
        Food f;
        Creature c1 = Creature (&f, east);
        players[make_pair(0, 0)] = &c1;
        Hopper h;
        Creature c2 = Creature (&h, north);
        players[make_pair(3, 3)] = &c2;
        Hopper h1;
        Creature c3 = Creature (&h1, east);
        players[make_pair(3, 4)] = &c3;
        Hopper h2;
        Creature c4 = Creature (&h2, south);
        players[make_pair(4, 4)] = &c4;
        Hopper h3;
        Creature c5 = Creature (&h3, west);
        players[make_pair(4, 3)] = &c5;
        Food f1;
        Creature c6 = Creature (&f1, north);
        players[make_pair(7, 7)] = &c6;

        int displayBoardInterval = 1;
        int moves = 5;

        Game<8,8> newGame = Game<8,8> (players);
        newGame.play(moves, displayBoardInterval);
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
        map<location_type, Creature*> players;
        Trap t1;
        Creature c1 = Creature (&t1, south);
        players[make_pair(0, 0)] = &c1;
        Hopper h;
        Creature c2 = Creature (&h, east);
        players[make_pair(3, 2)] = &c2;
        Rover r;
        Creature c3 = Creature (&r, north);
        players[make_pair(5, 4)] = &c3;
        Trap t2;
        Creature c4 = Creature (&t2, west);
        players[make_pair(6, 8)] = &c4;

        int displayBoardInterval = 1;
        int moves = 5;
        
        Game<7,9> newGame = Game<7,9> (players);
        newGame.play(moves, displayBoardInterval);
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

        map<location_type, Creature*> players;
    
        
        Food f0;
        pair<int, int> location = getRandLocation();
        Direction dir = getRandDirection();
        Creature c0 = Creature (&f0, dir);
        players[location] = &c0;

        Food f1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c1 = Creature (&f1, dir);
        players[location] = &c1;

        Food f2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c2 = Creature (&f2, dir);
        players[location] = &c2;

        Food f3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c3 = Creature (&f3, dir);
        players[location] = &c3;

        Food f4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c4 = Creature (&f4, dir);
        players[location] = &c4;

        Food f5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c5 = Creature (&f5, dir);
        players[location] = &c5;

        Food f6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c6 = Creature (&f6, dir);
        players[location] = &c6;

        Food f7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c7 = Creature (&f7, dir);
        players[location] = &c7;

        Food f8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c8 = Creature (&f8, dir);
        players[location] = &c8;

        Food f9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c9 = Creature (&f9, dir);
        players[location] = &c9;

        Hopper h0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d0 = Creature (&h0, dir);
        players[location] = &d0;

        Hopper h1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d1 = Creature (&h1, dir);
        players[location] = &d1;

        Hopper h2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d2 = Creature (&h2, dir);
        players[location] = &d2;

        Hopper h3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d3 = Creature (&h3, dir);
        players[location] = &d3;

        Hopper h4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d4 = Creature (&h4, dir);
        players[location] = &d4;

        Hopper h5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d5 = Creature (&h5, dir);
        players[location] = &d5;

        Hopper h6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d6 = Creature (&h6, dir);
        players[location] = &d6;

        Hopper h7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d7 = Creature (&h7, dir);
        players[location] = &d7;

        Hopper h8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d8 = Creature (&h8, dir);
        players[location] = &d8;

        Hopper h9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d9 = Creature (&h9, dir);
        players[location] = &d9;

        Rover r0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e0 = Creature (&r0, dir);
        players[location] = &e0;

        Rover r1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e1 = Creature (&r1, dir);
        players[location] = &e1;

        Rover r2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e2 = Creature (&r2, dir);
        players[location] = &e2;

        Rover r3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e3 = Creature (&r3, dir);
        players[location] = &e3;

        Rover r4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e4 = Creature (&r4, dir);
        players[location] = &e4;

        Rover r5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e5 = Creature (&r5, dir);
        players[location] = &e5;

        Rover r6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e6 = Creature (&r6, dir);
        players[location] = &e6;

        Rover r7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e7 = Creature (&r7, dir);
        players[location] = &e7;

        Rover r8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e8 = Creature (&r8, dir);
        players[location] = &e8;

        Rover r9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e9 = Creature (&r9, dir);
        players[location] = &e9;
            
        Trap t0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g0 = Creature (&t0, dir);
        players[location] = &g0;

        Trap t1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g1 = Creature (&t1, dir);
        players[location] = &g1;

        Trap t2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g2 = Creature (&t2, dir);
        players[location] = &g2;

        Trap t3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g3 = Creature (&t3, dir);
        players[location] = &g3;

        Trap t4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g4 = Creature (&t4, dir);
        players[location] = &g4;

        Trap t5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g5 = Creature (&t5, dir);
        players[location] = &g5;

        Trap t6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g6 = Creature (&t6, dir);
        players[location] = &g6;

        Trap t7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g7 = Creature (&t7, dir);
        players[location] = &g7;

        Trap t8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g8 = Creature (&t8, dir);
        players[location] = &g8;

        Trap t9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g9 = Creature (&t9, dir);
        players[location] = &g9;

        int moves = 1000;
        int displayBoardInterval = 100;

        Game<72,72> newGame = Game<72,72> (players);
        newGame.play(moves, displayBoardInterval);
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

                map<location_type, Creature*> players;
    
        
        Food f0;
        pair<int, int> location = getRandLocation();
        Direction dir = getRandDirection();
        Creature c0 = Creature (&f0, dir);
        players[location] = &c0;

        Food f1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c1 = Creature (&f1, dir);
        players[location] = &c1;

        Food f2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c2 = Creature (&f2, dir);
        players[location] = &c2;

        Food f3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c3 = Creature (&f3, dir);
        players[location] = &c3;

        Food f4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c4 = Creature (&f4, dir);
        players[location] = &c4;

        Food f5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c5 = Creature (&f5, dir);
        players[location] = &c5;

        Food f6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c6 = Creature (&f6, dir);
        players[location] = &c6;

        Food f7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c7 = Creature (&f7, dir);
        players[location] = &c7;

        Food f8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c8 = Creature (&f8, dir);
        players[location] = &c8;

        Food f9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature c9 = Creature (&f9, dir);
        players[location] = &c9;

        Hopper h0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d0 = Creature (&h0, dir);
        players[location] = &d0;

        Hopper h1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d1 = Creature (&h1, dir);
        players[location] = &d1;

        Hopper h2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d2 = Creature (&h2, dir);
        players[location] = &d2;

        Hopper h3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d3 = Creature (&h3, dir);
        players[location] = &d3;

        Hopper h4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d4 = Creature (&h4, dir);
        players[location] = &d4;

        Hopper h5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d5 = Creature (&h5, dir);
        players[location] = &d5;

        Hopper h6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d6 = Creature (&h6, dir);
        players[location] = &d6;

        Hopper h7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d7 = Creature (&h7, dir);
        players[location] = &d7;

        Hopper h8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d8 = Creature (&h8, dir);
        players[location] = &d8;

        Hopper h9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature d9 = Creature (&h9, dir);
        players[location] = &d9;

        Rover r0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e0 = Creature (&r0, dir);
        players[location] = &e0;

        Rover r1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e1 = Creature (&r1, dir);
        players[location] = &e1;

        Rover r2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e2 = Creature (&r2, dir);
        players[location] = &e2;

        Rover r3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e3 = Creature (&r3, dir);
        players[location] = &e3;

        Rover r4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e4 = Creature (&r4, dir);
        players[location] = &e4;

        Rover r5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e5 = Creature (&r5, dir);
        players[location] = &e5;

        Rover r6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e6 = Creature (&r6, dir);
        players[location] = &e6;

        Rover r7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e7 = Creature (&r7, dir);
        players[location] = &e7;

        Rover r8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e8 = Creature (&r8, dir);
        players[location] = &e8;

        Rover r9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature e9 = Creature (&r9, dir);
        players[location] = &e9;
            
        Trap t0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g0 = Creature (&t0, dir);
        players[location] = &g0;

        Trap t1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g1 = Creature (&t1, dir);
        players[location] = &g1;

        Trap t2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g2 = Creature (&t2, dir);
        players[location] = &g2;

        Trap t3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g3 = Creature (&t3, dir);
        players[location] = &g3;

        Trap t4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g4 = Creature (&t4, dir);
        players[location] = &g4;

        Trap t5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g5 = Creature (&t5, dir);
        players[location] = &g5;

        Trap t6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g6 = Creature (&t6, dir);
        players[location] = &g6;

        Trap t7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g7 = Creature (&t7, dir);
        players[location] = &g7;

        Trap t8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g8 = Creature (&t8, dir);
        players[location] = &g8;

        Trap t9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature g9 = Creature (&t9, dir);
        players[location] = &g9;

        Best b0;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z0 = Creature (&b0, dir);
        players[location] = &z0;

        Best b1;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z1 = Creature (&b1, dir);
        players[location] = &z1;

        Best b2;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z2 = Creature (&b2, dir);
        players[location] = &z2;

        Best b3;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z3 = Creature (&b3, dir);
        players[location] = &z3;

        Best b4;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z4 = Creature (&b4, dir);
        players[location] = &z4;

        Best b5;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z5 = Creature (&b5, dir);
        players[location] = &z5;

        Best b6;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z6 = Creature (&b6, dir);
        players[location] = &z6;

        Best b7;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z7 = Creature (&b7, dir);
        players[location] = &z7;

        Best b8;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z8 = Creature (&b8, dir);
        players[location] = &z8;

        Best b9;
        location = getRandLocation();
        dir = getRandDirection();
        Creature z9 = Creature (&b9, dir);
        players[location] = &z9;

        int moves = 1000;
        int displayBoardInterval = 100;

        Game<72,72> newGame = Game<72,72> (players);
        newGame.play(moves, displayBoardInterval);
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
        Hopper, facing south, at (0, 0)
        Trap, facing north,  at (0, 1)
        Rover, facing east, at (1, 0)
        Simulate 3 moves.
        Print every grid.
        */
        map<location_type, Creature*> players; 

        Hopper h;
        Creature c0 = Creature (&h, south);
        players[make_pair(0, 0)] = &c0;
 
        Trap t;
        Creature c1 = Creature (&t, north);
        players[make_pair(0, 1)] = &c1;

        Rover r;
        Creature c2 = Creature (&r, east);
        players[make_pair(1, 0)] = &c2;        

        int displayBoardInterval = 1;
        int moves = 3;

        Game<2,2> newGame = Game<2,2> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

try {
        cout << "*** Darwin 1x8 ***" << endl;
        /*
        1x8 Darwin
        Hopper, facing east, at (0, 0)
        Hopper, facing east, at (0, 1)
        Hopper, facing west, at (0, 6)
        Hopper, facing west, at (0, 7)
        Simulate 4 moves.
        Print every grid.
        */
        map<location_type, Creature*> players; 

        Hopper h;
        Creature c0 = Creature (&h, east);
        players[make_pair(0, 0)] = &c0;
 
        Creature c1 = Creature (&h, east);
        players[make_pair(0, 1)] = &c1;

        Creature c2 = Creature (&h, west);
        players[make_pair(0, 6)] = &c2;     

        Creature c3 = Creature (&h, west);
        players[make_pair(0, 7)] = &c3;           

        int displayBoardInterval = 1;
        int moves = 4;

        Game<1,8> newGame = Game<1,8> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

try {
        cout << "*** Darwin 5x5 ***" << endl;
        /*
        5x5 Darwin
        Food, facing north, at (0, 0)
        Food, facing north, at (0, 2)
        Food, facing north, at (0, 4)
        Food, facing north, at (2, 0)
        Food, facing north, at (2, 4)
        Food, facing north, at (4, 0)
        Food, facing north, at (4, 2)
        Food, facing north, at (4, 4)
        Rover, facing north, at (2, 2)
        Simulate 10 moves.
        Print every grid.
        */
        map<location_type, Creature*> players; 

        Food f;
        Creature c0 = Creature (&f, north);
        players[make_pair(0, 0)] = &c0;
 
        Creature c1 = Creature (&f, north);
        players[make_pair(0, 2)] = &c1;

        Creature c2 = Creature (&f, north);
        players[make_pair(0, 4)] = &c2;     

        Creature c3 = Creature (&f, north);
        players[make_pair(2, 0)] = &c3; 

        Creature c4 = Creature (&f, north);
        players[make_pair(2, 4)] = &c4; 

        Creature c5 = Creature (&f, north);
        players[make_pair(4, 0)] = &c5;  

        Creature c6 = Creature (&f, north);
        players[make_pair(4, 2)] = &c6; 

        Creature c7 = Creature (&f, north);
        players[make_pair(4, 4)] = &c7;    

        Rover r;
        Creature c8 = Creature (&r, north);
        players[make_pair(2, 2)] = &c8;                                             

        int displayBoardInterval = 1;
        int moves = 10;

        Game<5,5> newGame = Game<5,5> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

try {
        cout << "*** Darwin 5x5 (2) ***" << endl;
        /*
        5x5 Darwin
        Trap, facing south, at (0, 0)
        Trap, facing south, at (1, 1)
        Trap, facing south, at (2, 2)
        Trap, facing south, at (3, 3)
        Trap, facing south, at (4, 4)
        Hopper, facing east, at (1, 3)
        Hopper, facing east, at (3, 1)
        Simulate 5 moves.
        Print every grid.
        */
        map<location_type, Creature*> players; 

        Trap t;
        Creature c0 = Creature (&t, south);
        players[make_pair(0, 0)] = &c0;

        Creature c1 = Creature (&t, south);
        players[make_pair(1, 1)] = &c1; 

        Creature c2 = Creature (&t, south);
        players[make_pair(2, 2)] = &c2;  

        Creature c3 = Creature (&t, south);
        players[make_pair(3, 3)] = &c3;   

        Creature c4 = Creature (&t, south);
        players[make_pair(4, 4)] = &c4;    

        Hopper h;
        Creature c5 = Creature (&h, east);
        players[make_pair(1, 3)] = &c5;   

        Creature c6 = Creature (&h, east);
        players[make_pair(3, 1)] = &c6;

        int displayBoardInterval = 1;
        int moves = 5;

        Game<5,5> newGame = Game<5,5> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

try {
        cout << "*** Darwin 1x1 ***" << endl;
        /*
        1x1 Darwin
        Rover, facing west
        Simulate 1000 moves.
        Print every 1000th grid.
        */
        map<location_type, Creature*> players; 

        Rover r;
        Creature c0 = Creature (&r, south);
        players[make_pair(0, 0)] = &c0;

        int displayBoardInterval = 1000;
        int moves = 1000;

        Game<1,1> newGame = Game<1,1> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

try {
        cout << "*** Darwin 2x4 ***" << endl;
        /*
        2x4 Darwin
        Best, facing east, at (0, 0)
        Trap, facing west, at (0, 1)
        Best, facing east, at (0, 2)
        Trap, facing west, at (0, 3)
        Trap, facing west, at (1, 0)
        Best, facing east, at(1, 1)
        Trap, facing west, at (1, 2)
        Best, facing east, at (1, 3)
        Simulate 1 move.
        Print the grid.
        */
        map<location_type, Creature*> players; 

        Best b;
        Creature c0 = Creature (&b, east);
        players[make_pair(0, 0)] = &c0;

        Creature c1 = Creature (&b, east);
        players[make_pair(0, 2)] = &c1;

        Creature c2 = Creature (&b, east);
        players[make_pair(1, 1)] = &c2;

        Creature c3 = Creature (&b, east);
        players[make_pair(1, 3)] = &c3;

        Trap t;
        Creature c4 = Creature (&t, west);
        players[make_pair(0, 1)] = &c4;  

        Creature c5 = Creature (&t, west);
        players[make_pair(0, 3)] = &c5;  

        Creature c6 = Creature (&t, west);
        players[make_pair(1, 0)] = &c6;  

        Creature c7 = Creature (&t, west);
        players[make_pair(1, 2)] = &c7;  

        int displayBoardInterval = 1;
        int moves = 1;

        Game<2,4> newGame = Game<2,4> (players);
        newGame.play(moves, displayBoardInterval);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
