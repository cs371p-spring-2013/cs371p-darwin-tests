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

int getDirection(int x)
{
  if (x == 0)
    return Creature::WEST;
  if (x == 1)
    return Creature::NORTH;
  if (x == 2)
    return Creature::EAST;
  if (x == 3)
    return Creature::SOUTH;
  return 0;
}

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

        Game g(8,8);
        Creature food1(buildFood(), Creature::EAST);
        Creature hopper1(buildHopper(), Creature::NORTH);
        Creature hopper2(buildHopper(), Creature::EAST);
        Creature hopper3(buildHopper(), Creature::SOUTH);
        Creature hopper4(buildHopper(), Creature::WEST);
        Creature food2(buildFood(), Creature::NORTH);

        g.addCreature(0,0,food1);
        g.addCreature(3,3,hopper1);
        g.addCreature(4,3,hopper2);
        g.addCreature(4,4,hopper3);
        g.addCreature(3,4,hopper4);
        g.addCreature(7,7,food2);

        for (int i = 0; i <= 5; i++)
        {
          cout << g.toString() << endl;
          g.move();
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


        Game g(9,7);
        Creature trap1(buildTrap(), Creature::SOUTH);
        Creature hopper1(buildHopper(), Creature::EAST);
        Creature rover1(buildRover(), Creature::NORTH);
        Creature trap2(buildTrap(), Creature::WEST);


        g.addCreature(0,0,trap1);
        g.addCreature(2,3,hopper1);
        g.addCreature(4,5,rover1);
        g.addCreature(8,6,trap2);


        for (int i = 0; i <= 5; i++)
        {
          cout << g.toString() << endl;
          g.move();
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

        Game g(72,72);
        
        //Food
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature food(buildFood(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col, row, food);
        }

        //Hopper
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature hopper(buildHopper(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, hopper);
        }

        //Rover
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature rover(buildRover(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, rover);
        }

        //Trap
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature trap(buildTrap(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, trap);
        }


        for (int i = 0; i <= 1000; i ++)
        {
          if (i % 100 == 0)
            cout << g.toString() << endl;
          g.move();
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
        Game g(72,72);
        
        //Food
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature food(buildFood(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col, row, food);
        }

        //Hopper
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature hopper(buildHopper(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, hopper);
        }

        //Rover
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature rover(buildRover(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, rover);
        }

        //Trap
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature trap(buildTrap(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, trap);
        }

        //Best
        for (int i = 0; i < 10; i++)
        {
          int total = rand() % 5184;
          int row = total / 72;
          int col = total % 72;
          int dir = getDirection(rand() % 4);
          Creature best(buildBest(), dir);
          while (!g.board[row][col].isEmpty())
          {
            total = rand() % 5184;
            row = total / 72;
            col = total % 72;
          }
          g.addCreature(col,row, best);
        }
        for (int i = 0; i <= 1000; i ++)
        {
          if (i % 100 == 0)
            cout << g.toString() << endl;
          g.move();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        Game g(1,1);
        Creature rover(buildRover(), Creature::NORTH);
        g.addCreature(0,0,rover);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 3x1 ***" << endl;
        srand(0);
        Game g(1,3);
        Creature rover(buildRover(), Creature::NORTH);
        g.addCreature(0,0,rover);
        g.addCreature(0,1,rover);
        g.addCreature(0,2,rover);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 1x3 ***" << endl;
        srand(0);
        Game g(3,1);
        Creature rover(buildRover(), Creature::NORTH);
        g.addCreature(0,0,rover);
        g.addCreature(1,0,rover);
        g.addCreature(2,0,rover);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 2x2 Best ***" << endl;
        srand(0);
        Game g(2,2);
        Creature best(buildBest(), Creature::NORTH);
        g.addCreature(0,0,best);
        g.addCreature(1,0,best);
        g.addCreature(0,1,best);
        g.addCreature(1,1,best);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin short with trap***" << endl;
        srand(0);
        Game g(1,2);
        Creature trap(buildTrap(), Creature::NORTH);
        g.addCreature(0,0,trap);
        g.addCreature(0,1,trap);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin short with best ***" << endl;
        srand(0);
        Game g(2,1);
        Creature best(buildBest(), Creature::NORTH);
        g.addCreature(0,0,best);
        g.addCreature(1,0,best);
        for (int i = 0; i < 10; i++)
        {
          cout << g.toString() << endl;
          g.move();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}






    return 0;}
