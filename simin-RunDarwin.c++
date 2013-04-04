// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

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

    try {
        cout << "*** Darwin 8x8: Rover Chomp ***" << endl;
        Board<8, 8> b;
        for(int i = 0; i < 8; i++) {
            b.place_creature(Creature(FOOD, 1), 5, i);
        }
        b.place_creature(Creature(ROVER, 1), 4, 7);
        
        b.play_game(19, 1, cout);
     }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 20x20: Hoppity Hop ***" << endl;
        Board<20, 20> b;
        for(int i = 0; i < 20; i++) {
            b.place_creature(Creature(HOPPER, NORTH), i, 19);
        }
        b.play_game(24, 4, cout);
     }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {

        cout << "*** Darwin 1x20 ***: All Traps" << endl;
        Board<1, 20> b;
        for(int i = 0; i < 19; i++) {
            b.place_creature(Creature(FOOD, (19-i)%4), i, 0);
        }
        b.place_creature(Creature(TRAP, 0), 19, 0);
        b.play_game(20, 1, cout);
     }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    try {
        cout << "*** Darwin 10x1 ***" << endl;
        Board<10, 1> b;
        srand(0);
        b.place_creature(Creature(ROVER, NORTH), 0, 5);
        b.play_game(10, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        Board<1, 10> b;
        srand(0);
        b.place_creature(Creature(ROVER, NORTH), 5, 0);
        b.play_game(10, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        Board<3, 3> b;
        srand(0);
        b.place_creature(Creature(TRAP, NORTH), 0, 0);
        b.place_creature(Creature(TRAP, SOUTH), 2, 0);
        b.place_creature(Creature(TRAP, EAST), 0, 2);
        b.place_creature(Creature(TRAP, WEST), 2, 2);
        b.place_creature(Creature(ROVER, WEST), 1, 1);
        b.play_game(5, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 2x1 ***" << endl;
        Board<2, 1> b;
        srand(0);
        b.place_creature(Creature(ROVER, EAST), 1, 0);
        b.place_creature(Creature(TRAP, SOUTH), 0, 0);
        b.play_game(3, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 4x4 ***" << endl;
        Board<4, 4> b;
        srand(0);
        b.place_creature(Creature(FOOD, 2), 0, 0);
        b.place_creature(Creature(HOPPER, 0), 3, 0);
        b.place_creature(Creature(FOOD, 1), 3, 3);
        b.play_game(3, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 3x9 ***" << endl;
        Board<3, 9> b;
        srand(0);
        b.place_creature(Creature(HOPPER, SOUTH), 5, 0);
        b.place_creature(Creature(HOPPER, WEST), 8, 2);
        b.place_creature(Creature(ROVER, EAST), 6, 1);
        b.play_game(9, 1, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        Board<8, 8> b;
        srand(0);
        b.place_creature(Creature(ROVER, 2), 0, 0);
        b.place_creature(Creature(ROVER, 2), 0, 1);
        b.place_creature(Creature(ROVER, 2), 0, 2);
        b.place_creature(Creature(ROVER, 2), 0, 3);
        b.place_creature(Creature(ROVER, 2), 0, 4);
        b.place_creature(Creature(ROVER, 2), 0, 5);
        b.place_creature(Creature(ROVER, 2), 0, 6);
        b.play_game(1000, 100, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    try {
        cout << "*** Darwin 2x6 ***" << endl;
        Board<2, 6> b;
        srand(0);
        b.place_creature(Creature(FOOD, 3), 0, 0);
        b.place_creature(Creature(FOOD, 3), 0, 1);
        b.place_creature(Creature(ROVER, 1), 5, 1);
        b.play_game(12, 1, cout);
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
        Board<8, 8> b;
        Creature f1(0, 2);
        Creature h1(1, 1);
        Creature h2(1, 2);
        Creature h3(1, 3);
        Creature h4(1, 0);
        Creature f2(0, 1);
	//0 WEST
	//1 NORTH
  	//2 EAST
	//3 SOUTH
        b.place_creature(f1, 0, 0);
        b.place_creature(h1, 3, 3);
        b.place_creature(h2, 4, 3);
        //std::cout << "DIRECTION : " << h2.direction << std::endl;
        b.place_creature(h3, 4, 4);
        b.place_creature(h4, 3, 4);
        b.place_creature(f2, 7, 7);

        b.play_game(5, 1, std::cout);
   
         
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
        Board<7, 9> b;
        Creature t1(3, 3);
        Creature h(1, 2);
        Creature r(2, 1);
        Creature t2(3, 0);

        b.place_creature(t1, 0, 0);
        b.place_creature(h, 2, 3);
        b.place_creature(r, 4, 5);
        b.place_creature(t2, 8, 6);

        b.play_game(5, 1, std::cout);
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
        Board<72, 72> b;
        int position;
        int direction;
        for(int t = 0; t < 4; t++) {
            for(int i = 0; i < 10; i++) {
                position = rand()%5184;
                direction = rand()%4;
                b.place_creature(Creature(t, direction), position%72, position/72);
            }
        }
        b.play_game(1000, 100, std::cout);
      
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
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
        Board<72, 72> b;
        int position;
        int direction;
        for(int t = 0; t < 5; t++) {
            for(int i = 0; i < 10; i++) {
                position = rand()%5184;
                direction = rand()%4;
                b.place_creature(Creature(t, direction), position%72, position/72);
            }
        }
        b.play_game(1000, 100, std::cout);
        int food = 0;
        int hopper = 0;
        int rover = 0;
        int trap = 0;
        int best = 0;

        for(int i = 0; i < 72; i++) {
             for(int j = 0; j < 72; j++) {
                 if((char)b.board[i][j] == 'f') food++;
                 if((char)b.board[i][j] == 'h') hopper++;
                 if((char)b.board[i][j] == 'r') rover++;
                 if((char)b.board[i][j] == 't') trap++;
                 if((char)b.board[i][j] == 'b') best++;
                 
             }
        }
        std::cout << "Food: " << food << "\nHopper: " << hopper << "\nRover: " << rover << "\nTrap: " << trap << "\nBest: " << best << std::endl; 
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
