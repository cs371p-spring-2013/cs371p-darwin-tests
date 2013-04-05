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

int main ()
{
  using namespace std;
  ios_base::sync_with_stdio (false); // turn off synchronization with C I/O

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

  try
  {
    cout << "*** Darwin 8x8 ***" << endl;
    srand (0);

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

    DarwinBoard myBoard (8, 8);

    myBoard.place (0, 0, FOOD, EAST);
    myBoard.place (3, 3, HOPPER, NORTH);
    myBoard.place (3, 4, HOPPER, EAST);
    myBoard.place (4, 4, HOPPER, SOUTH);
    myBoard.place (4, 3, HOPPER, WEST);
    myBoard.place (7, 7, FOOD, NORTH);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  // ----------
  // darwin 7x9
  // ----------

  try
  {
    cout << "*** Darwin 7x9 ***" << endl;
    srand (0);

    /*
     7x9 Darwin
     Trap,   facing south, at (0, 0)
     Hopper, facing east,  at (3, 2)
     Rover,  facing north, at (5, 4)
     Trap,   facing west,  at (6, 8)
     Simulate 5 moves.
     Print every grid.
    */

    DarwinBoard myBoard (7, 9);

    myBoard.place (0, 0, TRAP, SOUTH);
    myBoard.place (3, 2, HOPPER, EAST);
    myBoard.place (5, 4, ROVER, NORTH);
    myBoard.place (6, 8, TRAP, WEST);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  // ------------
  // darwin 72x72
  // without best
  // ------------

  try
  {
    cout << "*** Darwin 72x72 without Best ***" << endl;
    cout << "..." << endl << endl;
    srand (0);
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

    DarwinBoard myBoard (72, 72);
 
    int ndx, rnd, row, col, dir;
    bool didPlace;
    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, FOOD, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, FOOD, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, HOPPER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, HOPPER, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, ROVER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, ROVER, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, TRAP, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, TRAP, dir);
      }
    }

    myBoard.simulate (1000, 100, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  // ------------
  // darwin 72x72
  // with best
  // ------------

  try
  {
    cout << "*** Darwin 72x72 with Best ***" << endl;
    cout << "..." << endl;
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

    DarwinBoard myBoard (72, 72);
 
    int ndx, rnd, row, col, dir;
    bool didPlace;
    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, FOOD, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, FOOD, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, HOPPER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, HOPPER, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, ROVER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, ROVER, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, TRAP, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, TRAP, dir);
      }
    }

    for (ndx = 0; ndx < 10; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, BEST, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, BEST, dir);
      }
    }

    myBoard.simulate (1000, 100, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 2x2 ***" << endl;
    srand (0);

    DarwinBoard myBoard (2, 2);

    myBoard.place (0, 0, TRAP, WEST);
    myBoard.place (0, 1, ROVER, WEST);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 2x2 ***" << endl;
    srand (0);

    DarwinBoard myBoard (2, 2);

    myBoard.place (0, 0, ROVER, WEST);
    myBoard.place (0, 1, TRAP, WEST);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 2x2 ***" << endl;
    srand (0);

    DarwinBoard myBoard (2, 2);

    myBoard.place (0, 0, ROVER, EAST);
    myBoard.place (0, 1, TRAP, WEST);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 72x72 without Best ***" << endl;
    cout << "..." << endl;
    srand(0);

    DarwinBoard myBoard (72, 72);
 
    int ndx, rnd, row, col, dir;
    bool didPlace;
    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, FOOD, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, FOOD, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, HOPPER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, HOPPER, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, ROVER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, ROVER, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, TRAP, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, TRAP, dir);
      }
    }

    myBoard.simulate (1000, 100, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 72x72 with Best ***" << endl;
    cout << "..." << endl;
    srand(0);

    DarwinBoard myBoard (72, 72);
 
    int ndx, rnd, row, col, dir;
    bool didPlace;
    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, FOOD, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, FOOD, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, HOPPER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, HOPPER, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, ROVER, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, ROVER, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, TRAP, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, TRAP, dir);
      }
    }

    for (ndx = 0; ndx < 20; ++ndx)
    {
      rnd = (rand() % 5184) - 1;
      row = rnd / 72;
      col = rnd % 72; 
      dir = (rand() % 4);
      didPlace = myBoard.place (row, col, BEST, dir);
      while (!didPlace)
      {
        rnd = (rand() % 5184) - 1;
        row = rnd / 72;
        col = rnd % 72; 
        dir = (rand() % 4);
        didPlace = myBoard.place (row, col, BEST, dir);
      }
    }

    myBoard.simulate (1000, 100, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 8x8 ***" << endl;
    srand (0);

    DarwinBoard myBoard (2, 2);

    myBoard.place (0, 0, ROVER, WEST);
    myBoard.place (0, 1, TRAP, WEST);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 8x8 ***" << endl;
    srand (0);

    DarwinBoard myBoard (8, 8);

    myBoard.place (0, 0, FOOD, EAST);
    myBoard.place (0, 1, ROVER, WEST);
    myBoard.place (3, 3, HOPPER, NORTH);
    myBoard.place (3, 4, BEST, EAST);
    myBoard.place (4, 4, HOPPER, SOUTH);
    myBoard.place (4, 3, HOPPER, WEST);
    myBoard.place (6, 3, TRAP, WEST);
    myBoard.place (7, 7, FOOD, NORTH);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 8x8 ***" << endl;
    srand (0);

    DarwinBoard myBoard (8, 8);

    myBoard.place (0, 0, ROVER, EAST);
    myBoard.place (3, 3, BEST, NORTH);
    myBoard.place (3, 4, ROVER, EAST);
    myBoard.place (4, 4, BEST, SOUTH);
    myBoard.place (4, 3, ROVER, WEST);
    myBoard.place (7, 7, BEST, NORTH);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  try
  {
    cout << "*** Darwin 8x8 ***" << endl;
    srand (0);

    DarwinBoard myBoard (8, 8);

    myBoard.place (0, 0, BEST, EAST);
    myBoard.place (3, 3, ROVER, NORTH);
    myBoard.place (3, 4, BEST, EAST);
    myBoard.place (4, 4, ROVER, SOUTH);
    myBoard.place (4, 3, BEST, WEST);
    myBoard.place (7, 7, ROVER, NORTH);

    myBoard.simulate (5, 1, cout);
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  return 0;
}