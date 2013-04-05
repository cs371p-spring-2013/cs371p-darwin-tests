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
#include <set>
#include <string>
#include "./Darwin.h"

typedef std::pair<int, int> point;

void addCreature(const string& species, set<point>& fullPoints, Darwin& d) {
  bool posBad = true;
  point p;
  while (posBad) {
    int pos = rand() % 5184;
    p = point(pos / 72, pos % 72);
    if (fullPoints.find(p) == fullPoints.end()) posBad = false;
  }

  int dir = rand() % 4;
  Direction direction;

  switch (dir) {
    case 0:
      direction = North;
      break;
    case 1:
      direction = East;
      break;
    case 2:
      direction = South;
      break;
    case 3:
      direction = West;
      break;
  }

  d.addCreature(Creature(species, direction), p.first, p.second);
}

// ----
// main
// ----

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O

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
    Darwin d(8, 8, cout);

    d.addCreature(Creature("food", East), 0, 0);
    d.addCreature(Creature("hopper", North), 3, 3);
    d.addCreature(Creature("hopper", East), 3, 4);
    d.addCreature(Creature("hopper", South), 4, 4);
    d.addCreature(Creature("hopper", West), 4, 3);
    d.addCreature(Creature("food", North), 7, 7);

    d.run(5, 1);
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

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
    Darwin d(7, 9, cout);

    d.addCreature(Creature("trap", South), 0, 0);
    d.addCreature(Creature("hopper", East), 3, 2);
    d.addCreature(Creature("rover", North), 5, 4);
    d.addCreature(Creature("trap", West), 6, 8);

    d.run(5, 1);
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

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
    set<point> usedPoints;
    Darwin d(72, 72, cout);

    for (int i = 0; i < 10; ++i) {
      addCreature("food", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("hopper", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("rover", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("trap", usedPoints, d);
    }

    d.run(1000, 100);
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

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
    set<point> usedPoints;
    Darwin d(72, 72, cout);

    for (int i = 0; i < 10; ++i) {
      addCreature("food", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("hopper", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("rover", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("trap", usedPoints, d);
    }
    for (int i = 0; i < 10; ++i) {
      addCreature("best", usedPoints, d);
    }

    d.run(1000, 100);
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  return 0;
}
