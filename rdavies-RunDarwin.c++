// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ RunDarwin.c++ -o RunDarwin
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
        GameBoard game = GameBoard(8, 8);
        game.createCreature(0, 0, EAST, "food");
        game.createCreature(3, 3, NORTH, "hopper");
        game.createCreature(3, 4, EAST, "hopper");
        game.createCreature(4, 4, SOUTH, "hopper");
        game.createCreature(4, 3, WEST, "hopper");
        game.createCreature(7, 7, NORTH, "food");

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

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

        GameBoard game = GameBoard(7, 9);
        game.createCreature(0, 0, SOUTH, "trap");
        game.createCreature(3, 2, EAST, "hopper");
        game.createCreature(5, 4, NORTH, "rover");
        game.createCreature(6, 8, WEST, "trap");

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

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

        GameBoard game = GameBoard(72, 72);
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "food");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "food");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "food");
          else
            game.createCreature(row, col, SOUTH, "food");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "hopper");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "hopper");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "hopper");
          else
            game.createCreature(row, col, SOUTH, "hopper");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "rover");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "rover");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "rover");
          else
            game.createCreature(row, col, SOUTH, "rover");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "trap");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "trap");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "trap");
          else
            game.createCreature(row, col, SOUTH, "trap");
        }

        for (int i = 0; i < 1001; i++) {
          if (i % 100 == 0) {
            cout << "Turn = " << i << "." << endl;
            game.printBoard(cout);
            cout << endl;
          }
            game.doRound(i);
        }

        }
    catch (const invalid_argument&) {
      cout << "invalid args" << endl;
        assert(false);}
    catch (const out_of_range&) {
      cout << "out of range" << endl;
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

        GameBoard game = GameBoard(72, 72);
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "food");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "food");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "food");
          else
            game.createCreature(row, col, SOUTH, "food");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "hopper");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "hopper");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "hopper");
          else
            game.createCreature(row, col, SOUTH, "hopper");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "rover");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "rover");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "rover");
          else
            game.createCreature(row, col, SOUTH, "rover");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "trap");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "trap");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "trap");
          else
            game.createCreature(row, col, SOUTH, "trap");
        }
        for (int i = 0; i < 10; i++) {
          int r = rand() % 5184;
          int row = r / 72;
          int col = r % 72;
          int direct = rand() % 4;
          if (direct == 0)
            game.createCreature(row, col, WEST, "best");
          else if (direct == 1)
            game.createCreature(row, col, NORTH, "best");
          else if (direct == 2)
            game.createCreature(row, col, EAST, "best");
          else
            game.createCreature(row, col, SOUTH, "best");
        }

        for (int i = 0; i < 1001; i++) {
          if (i % 100 == 0) {
            cout << "Turn = " << i << "." << endl;
            game.printBoard(cout);
            cout << endl;
          }
          game.doRound(i);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //OUR TEST CASES

    //TEST 1
    try {
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);
        /*
        7x9 Darwin
        Trap,   facing north, at (3, 4)
        Hopper, facing south,  at (1, 2)
        Rover,  facing west, at (6, 2)
        Trap,   facing east,  at (2, 8)
        Best, facing north, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(7, 9);
        game.createCreature(3, 4, NORTH, "trap");
        game.createCreature(1, 2, SOUTH, "hopper");
        game.createCreature(6, 2, WEST, "rover");
        game.createCreature(2, 8, EAST, "trap");
        game.createCreature(1, 1, NORTH, "best");

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //TEST 2
    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Hopper, facing south, at (0, 0)
        Simulate 3 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(1, 1);
        game.createCreature(0, 0, SOUTH, "hopper");

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //TEST 3
    try {
        cout << "*** Darwin 12x12 ***" << endl;
        srand(0);
        /*
        12x12 Darwin
        Best, facing east, at (0, 0)
        Best, facing east, at (11, 0)
        Best, facing west, at (11, 11)
        Best, facing west, at (0, 11)
        Simulate 2 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(12, 12);
        game.createCreature(0, 0, EAST, "best");
        game.createCreature(11, 0, EAST, "best");
        game.createCreature(11, 11, WEST, "best");
        game.createCreature(0, 11, WEST, "best");

        for (int i = 0; i < 3; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //TEST 4
    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        /*
        5x5 Darwin
        Best,   facing south, at (0, 0)
        Trap,   facing south, at (0, 1)
        Hopper, facing east,  at (0, 2)
        Rover,  facing north, at (0, 3)
        Trap,   facing west,  at (0, 4)
        Simulate 10 moves.
        Print every 2nd grid.
        */

        GameBoard game = GameBoard(5, 5);
        game.createCreature(0, 0, SOUTH, "best");
        game.createCreature(0, 1, SOUTH, "trap");
        game.createCreature(0, 2, EAST, "hopper");
        game.createCreature(0, 3, NORTH, "rover");
        game.createCreature(0, 4, WEST, "trap");

        for (int i = 0; i < 11; i++) {
        if (i % 2 == 0) {
            cout << "Turn = " << i << "." << endl;
            game.printBoard(cout);
            cout << endl;
        }
        game.doRound(i);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //TEST 5
    try {
        cout << "*** Darwin 1x5 ***" << endl;
        srand(0);
        /*
        1x5 Darwin
        Best,    facing north, at (0, 4)
        Trap,    facing east,  at (0, 3)
        Hopper,  facing south, at (0, 2)
        Rover,   facing west,  at (0, 1)
        Food,    facing north, at (0, 0);
        Simulate 100 moves.
        Print every 10th grid.
        */

        GameBoard game = GameBoard(1, 5);
        game.createCreature(0, 4, NORTH, "best");
        game.createCreature(0, 3, EAST, "trap");
        game.createCreature(0, 2, SOUTH, "hopper");
        game.createCreature(0, 1, WEST, "rover");
        game.createCreature(0, 0, NORTH, "food");

        for (int i = 0; i < 101; i++) {
          if (i % 10 == 0) {
            cout << "Turn = " << i << "." << endl;
            game.printBoard(cout);
            cout << endl;
        }
        game.doRound(i);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    //TEST 6
    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        /*
        1x1 Darwin
        Simulate 100 moves.
        Print every 10th grid.
        */

        GameBoard game = GameBoard(1, 1);

        for (int i = 0; i < 101; i++) {
          if (i % 10 == 0) {
            cout << "Turn = " << i << "." << endl;
            game.printBoard(cout);
            cout << endl;
          }
          game.doRound(i);
        }
        }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //TEST 7
    try {
        cout << "*** Darwin 100x1 ***" << endl;
        srand(0);
        /*
        100x1 Darwin
        Trap,   facing west,   at (0, 0)
        Hopper, facing south,  at (20, 0)
        Rover,  facing east,   at (40, 0)
        Food,   facing west,   at (60, 0)
        Best,   facing north,  at (80, 0)
        Simulate 10 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(100, 1);
        game.createCreature(0, 0, WEST, "trap");
        game.createCreature(20, 0, SOUTH, "hopper");
        game.createCreature(40, 0, EAST, "rover");
        game.createCreature(60, 0, WEST, "food");
        game.createCreature(80, 0, NORTH, "best");

        for (int i = 0; i < 11; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //TEST 8
    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        /*
        10x10 Darwin
        Board filled with Best facing north.
        Simulate 5 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(10, 10);
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            game.createCreature(i, j, NORTH, "best");
          }
        }

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    //TEST 9
    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        /*
        5x5 Darwin
        Board filled with different species every 5 blocks.
        Bests facing south.
        Traps facing west.
        Foods facing north.
        Rovers facing east.
        Hoppers facing south.
        Simulate 5 moves.
        Print every grid.
        */

        GameBoard game = GameBoard(5, 5);
        for(int i = 0; i < 5; ++i){
          for(int j = 0; j < 5; ++j){
            if(j == 0)
              game.createCreature(i, j, SOUTH, "best");
            if(j == 1)
              game.createCreature(i, j, WEST, "trap");
            if(j == 2)
              game.createCreature(i, j, NORTH, "food");
            if(j == 3)
              game.createCreature(i, j, EAST, "rover");
            if(j == 4)
              game.createCreature(i, j, SOUTH, "hopper");
          }
        }

        for (int i = 0; i < 6; i++) {
          cout << "Turn = " << i << "." << endl;
          game.printBoard(cout);
          game.doRound(i);
          cout << endl;
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // TEST 10 
    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        /*
        10x10 Darwin
        Empty board.
        Simulate 5 moves.
        Print last grid.
        */

        GameBoard game = GameBoard(10, 10);
        for (int i = 0; i < 6; i++) {
          game.doRound(i);
        }
        cout << "Turn = " << 5 << "." << endl;
        game.printBoard(cout);
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    return 0;}
