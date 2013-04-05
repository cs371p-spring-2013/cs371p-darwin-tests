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

    Species food('f');
    food.addInstruction(lft);
    food.addInstruction(go, 0);

    Species hopper('h');
    hopper.addInstruction(hop);
    hopper.addInstruction(go, 0);

    Species trap('t');
    trap.addInstruction(enemy, 3);
    trap.addInstruction(lft);
    trap.addInstruction(go, 0);
    trap.addInstruction(infect);
    trap.addInstruction(go, 0);

    Species rover('r');
    rover.addInstruction(enemy, 9);
    rover.addInstruction(empty, 7);
    rover.addInstruction(ran, 5);
    rover.addInstruction(lft);
    rover.addInstruction(go, 0);
    rover.addInstruction(rgt);
    rover.addInstruction(go, 0);
    rover.addInstruction(hop);
    rover.addInstruction(go, 0);
    rover.addInstruction(infect);
    rover.addInstruction(go, 0);

    //Best Species removed from public repo

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
      Grid<8,8> g;

      Creature c1(&food, east);
      Creature c2(&hopper, north);
      Creature c3(&hopper, east);
      Creature c4(&hopper, south);
      Creature c5(&hopper, west);
      Creature c6(&food, north);
      
      g.addCreature(0, 0, &c1);
      g.addCreature(3, 3, &c2);
      g.addCreature(3, 4, &c3);
      g.addCreature(4, 4, &c4);
      g.addCreature(4, 3, &c5);
      g.addCreature(7, 7, &c6);

      for (int i = 0; i < 5; ++i) {
        g.printGrid();
        g.oneTurn();
      }
      g.printGrid();
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
        Grid<7,9> g;
      
        Creature c1(&trap, south);
        Creature c2(&hopper, east);
        Creature c3(&rover, north);
        Creature c4(&trap, west);

        g.addCreature(0, 0, &c1);
        g.addCreature(3, 2, &c2);
        g.addCreature(5, 4, &c3);
        g.addCreature(6, 8, &c4);
        
        g.printGrid();
        for (int i = 0; i < 5; ++i) {
          g.oneTurn();
          g.printGrid();
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
        Grid<72, 72> g;
        
        Creature creatures[40];
        Directions directions[4] = {west, north, east, south};
        for (int i = 0; i < 10; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&food, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 10; i < 20; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&hopper, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 20; i < 30; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&rover, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 30; i < 40; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&trap, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        
        g.printGrid();
        for (int i = 1; i <= 1000; ++i) {
          g.oneTurn();
          if (i %100 == 0)
            g.printGrid();
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
        Grid<72, 72> g;
        
        Creature creatures[50];
        Directions directions[4] = {west, north, east, south};
        for (int i = 0; i < 10; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&food, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 10; i < 20; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&hopper, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 20; i < 30; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&rover, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 30; i < 40; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&trap, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        for (int i = 40; i < 50; ++i) {
          int r = rand() % 5184;
          int d = rand();
          int x = r/72;
          int y = r % 72;
          Creature c(&best, directions[d % 4]);
          creatures[i] = c;
          g.addCreature(x, y, &creatures[i]);
        }
        
        g.printGrid();
        for (int i = 1; i <= 1000; ++i) {
          g.oneTurn();
          if (i %100 == 0)
            g.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

////////////////////////////////////////////////////////////////////////
//////////////////////       USER TESTS      ///////////////////////////
////////////////////////////////////////////////////////////////////////

        // Test 1
        // Multiple adds to one spot, last creature gets the spot
        try {
                cout << "*** Test 1 ***" << endl;
                srand(0);

                Grid<1,1> g;

                Creature c1(&rover, south);
                Creature c2(&hopper, east);
                Creature c3(&rover, north);
                Creature c4(&trap, west);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 0, &c2);
                g.addCreature(0, 0, &c3);
                g.addCreature(0, 0, &c4);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 2
        // Adding off the grid
        try {
                cout << "*** Test 2 ***" << endl;
                srand(0);

                Grid<2,2> g;

                Creature c1(&rover, south);
                Creature c2(&hopper, east);
                Creature c3(&rover, north);
                Creature c4(&trap, west);

                g.addCreature(2, 2, &c1);
                g.addCreature(3, 2, &c2);
                g.addCreature(5, 4, &c3);
                g.addCreature(6, 8, &c4);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 3
        // All should become rovers
        try {
                cout << "*** Test 3 ***" << endl;
                srand(0);

                Grid<2,2> g;

                Creature c1(&rover, south);
                Creature c2(&hopper, east);
                Creature c3(&hopper, north);
                Creature c4(&hopper, west);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 1, &c2);
                g.addCreature(1, 0, &c3);
                g.addCreature(1, 1, &c4);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 4
        // All should become traps
        try {
                cout << "*** Test 4 ***" << endl;
                srand(0);

                Grid<2,2> g;

                Creature c1(&hopper, south);
                Creature c2(&hopper, east);
                Creature c3(&hopper, north);
                Creature c4(&trap, west);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 1, &c2);
                g.addCreature(1, 0, &c3);
                g.addCreature(1, 1, &c4);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 5
        // Hoppers should not move, stuck in corner
        try {
                cout << "*** Test 5 ***" << endl;
                srand(0);

                Grid<3,3> g;

                Creature c1(&hopper, north);
                Creature c2(&hopper, east);
                Creature c3(&hopper, west);
                Creature c4(&hopper, south);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 2, &c2);
                g.addCreature(2, 0, &c3);
                g.addCreature(2, 2, &c4);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 6
        // Rectangular test
        try {
                cout << "*** Test 6 ***" << endl;
                srand(0);

                Grid<1,5> g;

                Creature c1(&rover, south);
                Creature c2(&hopper, east);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 3, &c2);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 7
        // Big and empty
        try {
                cout << "*** Test 7 ***" << endl;
                srand(0);

                Grid<100,100> g;

                g.printGrid();
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 8
        // Hopper Trapped
        try {
                cout << "*** Test 8 ***" << endl;
                srand(0);

                Grid<3,3> g;

                Creature c1(&trap, south);
                Creature c2(&trap, east);
                Creature c3(&trap, north);
                Creature c4(&trap, north);
                Creature c5(&trap, north);
                Creature c6(&trap, north);
                Creature c7(&trap, north);
                Creature c8(&trap, north);
                Creature c9(&hopper, east);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 1, &c2);
                g.addCreature(0, 2, &c3);
                g.addCreature(1, 2, &c4);
                g.addCreature(2, 2, &c5);
                g.addCreature(2, 1, &c6);
                g.addCreature(2, 0, &c7);
                g.addCreature(1, 0, &c8);
                g.addCreature(1, 1, &c9);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 9
        // Some rovers go left some go right (all facing north at start)
        try {
                cout << "*** Test 9 ***" << endl;
                srand(0);

                Grid<1,50> g;

                Creature c1(&rover, north);
                Creature c2(&rover, north);
                Creature c3(&rover, north);
                Creature c4(&rover, north);
                Creature c5(&rover, north);

                g.addCreature(0, 0, &c1);
                g.addCreature(0, 10, &c2);
                g.addCreature(0, 20, &c3);
                g.addCreature(0, 30, &c4);
                g.addCreature(0, 40, &c5);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}

        // Test 10
        // Best Movement
        try {
                cout << "*** Test 10 ***" << endl;
                srand(0);

                Grid<5,5> g;

                Creature c1(&best, south);
                g.addCreature(2, 2, &c1);

                g.printGrid();
                for (int i = 0; i < 5; ++i) {
                        g.oneTurn();
                        g.printGrid();
                }
        }
        catch (const invalid_argument&) {
                assert(false);}
        catch (const out_of_range&) {
                assert(false);}


    return 0;}
