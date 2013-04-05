//Christopher Word
//eid:cword
//csid:word

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
  EXTRACT_ALL      = YES
  EXTRACT_PRIVATE    = YES
  EXTRACT_STATIC     = YES
  GENERATE_LATEX     = NO

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

using namespace std;

//enum Dir { WEST , NORTH, EAST, SOUTH};

// ----
// main
// ----

int main () {
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O


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

    Game g = Game(8, 8, 1, 5);
    g.addCreature(0,0, EAST, FOOD);
    g.addCreature(3,3, NORTH, HOPPER);
    g.addCreature(4,3, EAST, HOPPER);
    g.addCreature(4,4, SOUTH, HOPPER);
    g.addCreature(3,4, WEST, HOPPER);
    g.addCreature(7,7, NORTH, FOOD);
    g.start();
    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  //----------
  //darwin 7x9
  //----------

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
    Game g = Game(7, 9, 1, 5);
    g.addCreature(0,0, SOUTH, TRAP);
    g.addCreature(2,3, EAST, HOPPER);
    g.addCreature(4,5, NORTH, ROVER);
    g.addCreature(8,6, WEST, TRAP);
    g.start();



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
    Game g = Game(72, 72, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , TRAP );
    }
    g.start();


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

    Game g = Game(72, 72, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 1
  // ------------

  try {
    cout << "*** Darwin 1 ***" << endl;
    srand(0);

    Game g = Game(50, 50, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 2
  // ------------

  try {
    cout << "*** Darwin 2 ***" << endl;
    srand(0);

    Game g = Game(20, 20, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 3
  // ------------

  try {
    cout << "*** Darwin 3 ***" << endl;
    srand(0);

    Game g = Game(30, 30, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 4
  // ------------

  try {
    cout << "*** Darwin 4 ***" << endl;
    srand(0);

    Game g = Game(72, 72, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}


  // ------------
  // darwin 5
  // ------------

  try {
    cout << "*** Darwin 5 ***" << endl;
    srand(0);

    Game g = Game(50, 50, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 6
  // ------------

  try {
    cout << "*** Darwin 6 ***" << endl;
    srand(0);

    Game g = Game(20, 20, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 7
  // ------------

  try {
    cout << "*** Darwin 7 ***" << endl;
    srand(0);

    Game g = Game(30, 30, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 900;
      g.addCreature(pos%30, pos / 30, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 8
  // ------------

  try {
    cout << "*** Darwin 8 ***" << endl;
    srand(0);

    Game g = Game(72, 72, 100, 1000);
    //10 food
    for(int i = 0; i < 10; i++){
      int pos = rand() % 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //10 Hopper
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 5184;
      g.addCreature(pos%72, pos / 72, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 9
  // ------------

  try {
    cout << "*** Darwin 9 ***" << endl;
    srand(0);

    Game g = Game(50, 50, 100, 1000);
    //30 food
    for(int i = 0; i < 30; i++){
      int pos = rand() % 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //30 Hopper
    for(int i = 0; i < 30; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //30 Rover
    for(int i = 0; i < 30; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //30 Trap
    for(int i = 0; i < 30; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //30 Best
    for(int i = 0; i < 30; i++){
      int pos = rand()% 2500;
      g.addCreature(pos%50, pos / 50, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}

  // ------------
  // darwin 10
  // ------------

  try {
    cout << "*** Darwin 10 ***" << endl;
    srand(0);

    Game g = Game(20, 20, 100, 1000);
    //20 food
    for(int i = 0; i < 20; i++){
      int pos = rand() % 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , FOOD );
    }
    //20 Hopper
    for(int i = 0; i < 20; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , HOPPER );
    }
    //10 Rover
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , ROVER );
    }
    //10 Trap
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , TRAP );
    }

    //10 Best
    for(int i = 0; i < 10; i++){
      int pos = rand()% 400;
      g.addCreature(pos%20, pos / 20, static_cast<Direction>(rand() % 4) , BEST );
    }


    g.start();

    }
  catch (const invalid_argument&) {
    assert(false);}
  catch (const out_of_range&) {
    assert(false);}


  return 0;}
