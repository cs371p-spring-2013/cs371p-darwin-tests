// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunDarwin.c++ -o RunDarwin.c++.app
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
      srand(0);

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
      Game game(8,8);
      game.addCreature(EAST, FOOD, 0, 0);
      game.addCreature(NORTH, HOPPER, 3, 3);
      game.addCreature(EAST, HOPPER, 3, 4);
      game.addCreature(SOUTH, HOPPER, 4, 4);
      game.addCreature(WEST, HOPPER, 4, 3);
      game.addCreature(NORTH, FOOD, 7, 7);
      cout << "Start" <<endl;
      game.printGrid();
      cout << "Turn 1" <<endl;
      game.update();
      game.printGrid();
      cout << "Turn 2" <<endl;
      game.update();
      game.printGrid();
      cout << "Turn 3" <<endl;
      game.update();
      game.printGrid();
      cout << "Turn 4" <<endl;
      game.update();
      game.printGrid();
      cout << "Turn 5" <<endl;
      game.update();
      game.printGrid();
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
      Game game(7,9);
      game.addCreature(SOUTH, TRAP, 0, 0);
      game.addCreature(EAST, HOPPER, 3, 2);
      game.addCreature(NORTH, ROVER, 5, 4);
      game.addCreature(WEST, TRAP, 6, 8);
      cout << "Start" <<endl;
      game.printGrid();
      for (int i = 0; i < 5; i++) {
        cout << "Turn "<< i <<endl;
        game.update();
        game.printGrid();
        
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
      direction wnes [] = {WEST, NORTH, EAST, SOUTH};
      Game game(72,72);

      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,HOPPER,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,ROVER,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,TRAP,x,y);
      }
      
      cout << "Turn 0" <<endl;
      game.printGrid();
      cout<<endl;
      for (int i = 1; i < 1001; i++) {
        game.update();
        if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
        }
      }
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
	direction wnes [] = {WEST, NORTH, EAST, SOUTH};
      Game game(72,72);

      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,HOPPER,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,ROVER,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,TRAP,x,y);
      }
      for (int i = 0; i < 10; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,BEST,x,y);
      }
      
      cout << "Turn 0" <<endl;
      game.printGrid();
      cout<<endl;
      for (int i = 1; i < 1001; i++) {
        game.update();
        if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
        }
      }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
  
  try {
    cout << "*** Darwin 8x8 ***" << endl;
    srand(0);
    Game game(8,8);
    game.addCreature(NORTH, ROVER, 5, 4);
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 0; i < 20; i++) {
      cout << "Turn "<< i <<endl;
      game.update();
      game.printGrid();
      
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
  
  try {
    cout << "*** Darwin 8x8 ***" << endl;
    srand(0);
    Game game(8,8);
    game.addCreature(SOUTH, BEST, 4, 4);
    game.addCreature(NORTH, BEST, 5, 4);
    game.addCreature(SOUTH, FOOD, 3, 4);
    game.addCreature(SOUTH, FOOD, 6, 4);
    game.addCreature(SOUTH, FOOD, 4, 3);
    game.addCreature(SOUTH, FOOD, 4, 5);


    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 0; i < 5; i++) {
      cout << "Turn "<< i <<endl;
      game.update();
      game.printGrid();
      
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    
    try {
    cout << "*** Darwin 72x72 One BEST, lots of FOOD ***" << endl;
    srand(0);
    Game game(72,72);
    direction wnes [] = {WEST, NORTH, EAST, SOUTH};
    for (int i = 0; i < 500; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
    int pos = rand() % 5184;
    int x = pos / 72;
    int y = pos % 72;
    game.addCreature(wnes[rand() % 4], BEST, x,y);
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 1; i < 301; i++) {
      game.update();
      if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
      }
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    
    try {
    cout << "*** Darwin 72x72 BEST vs TRAP ***" << endl;
    srand(0);
    Game game(72,72);
    direction wnes [] = {WEST, NORTH, EAST, SOUTH};
    for (int i = 0; i < 500; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
    for (int i = 0; i < 50; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,BEST,x,y);
      }
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,TRAP,x,y);
      }
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 1; i < 501; i++) {
      game.update();
      if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
      }
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    
    
    try {
    cout << "*** Darwin 72x72 ROVER vs TRAP***" << endl;
    srand(0);
    Game game(72,72);
    direction wnes [] = {WEST, NORTH, EAST, SOUTH};
    for (int i = 0; i < 500; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,ROVER,x,y);
      }
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,TRAP,x,y);
      }
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 1; i < 501; i++) {
      game.update();
      if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
      }
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    
    try {
    cout << "*** Darwin 72x72 BEST vs TRAP vs ROVER***" << endl;
    srand(0);
    Game game(72,72);
    direction wnes [] = {WEST, NORTH, EAST, SOUTH};
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,ROVER,x,y);
      }
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,BEST,x,y);
      }
    for (int i = 0; i < 100; i++) {
        int pos = rand() % 5184;
        int x = pos / 72;
        int y = pos % 72;
        direction d = wnes[rand() % 4];
        game.addCreature(d,TRAP,x,y);
      }
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 1; i < 1001; i++) {
      game.update();
      if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
      }
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    
    try {
    cout << "*** Darwin 72x72 BEST vs ROVER II***" << endl;
    srand(0);
    Game game(50,50);
    direction wnes [] = {WEST, NORTH, EAST, SOUTH};
    for (int i = 0; i < 10; i++) {
        int pos = rand() % 2500;
        int x = pos / 50;
        int y = pos % 50;
        direction d = wnes[rand() % 4];
        game.addCreature(d,FOOD,x,y);
      }
    for (int i = 0; i < 10; i++) {
        int pos = rand() % 2500;
        int x = pos / 50;
        int y = pos % 50;
        direction d = wnes[rand() % 4];
        game.addCreature(d,BEST,x,y);
      }
    for (int i = 0; i < 10; i++) {
        int pos = rand() % 2500;
        int x = pos / 50;
        int y = pos % 50;
        direction d = wnes[rand() % 4];
        game.addCreature(d,ROVER,x,y);
      }
    cout << "Start" <<endl;
    game.printGrid();
    for (int i = 1; i < 301; i++) {
      game.update();
      if (i % 100 == 0 ) {
          cout << "Turn " << i<<endl;
          game.printGrid();
          cout<<endl;
      }
    }
  }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}
    return 0;}
