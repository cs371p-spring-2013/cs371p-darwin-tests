// -----------------------------
// cs371p-darwin/RunDarwin.c++
// Copyright (C) 2013
// Kartik Hattangadi
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
#include <ostream>  // cout, endl
#include <sstream>  // cout, endl
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

        Grid g(8, 8);
        std::ostringstream o;
        Creature f1(Creature::EAST, "food");
        Creature h1(Creature::NORTH, "hopper");
        Creature h2(Creature::EAST, "hopper");
        Creature h3(Creature::SOUTH, "hopper");
        Creature h4(Creature::WEST, "hopper");
        Creature f2(Creature::NORTH, "food");
        g.add_creature(f1, 0, 0);
        g.add_creature(h1, 3, 3);
        g.add_creature(h2, 3, 4);
        g.add_creature(h3, 4, 4);
        g.add_creature(h4, 4, 3);
        g.add_creature(f2, 7, 7);
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");


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

        Grid g(7, 9);
        std::ostringstream o;
        Creature t1(Creature::SOUTH, "trap");
        Creature h1(Creature::EAST, "hopper");
        Creature r1(Creature::NORTH, "rover");
        Creature t2(Creature::WEST, "trap");
        g.add_creature(t1, 0, 0);
        g.add_creature(h1, 3, 2);
        g.add_creature(r1, 5, 4);
        g.add_creature(t2, 6, 8);
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");
        g.next_move();
        g.print_grid(o);
        std::cout << o.str();
        o.str("");

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
        Grid g(72, 72);
        std::ostringstream o;
        for (int j = 0; j < 4; j++) {
          std::string species;
          if (j == 0)
            species = "food";
          else if (j == 1)
            species = "hopper";
          else if (j == 2)
            species = "rover";
          else
            species = "trap";
          for (int i = 0; i < 10; i++) {
            int pos = rand() % 5184;
            int dir = rand() % 4;
            if (dir == 0)
              dir = Creature::WEST;
            else if (dir == 1)
              dir = Creature::NORTH;
            else if (dir == 2)
              dir = Creature::EAST;
            else if (dir == 3)
              dir = Creature::SOUTH;
            Creature f(dir, species);
            g.add_creature(f, pos/72, pos%72);
          }
        }
        for (int i = 0; i < 1001; i++) {
          if (i%100 == 0) {
            g.print_grid(o);
            std::cout << o.str();
            o.str("");
          }
          g.next_move();
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
        Grid g(72, 72);
        std::ostringstream o;
        for (int j = 0; j < 5; j++) {
          std::string species;
          if (j == 0)
            species = "food";
          else if (j == 1)
            species = "hopper";
          else if (j == 2)
            species = "rover";
          else if (j == 3)
            species = "trap";
          else
            species = "best";
          for (int i = 0; i < 10; i++) {
            int pos = rand() % 5184;
            int dir = rand() % 4;
            if (dir == 0)
              dir = Creature::WEST;
            else if (dir == 1)
              dir = Creature::NORTH;
            else if (dir == 2)
              dir = Creature::EAST;
            else if (dir == 3)
              dir = Creature::SOUTH;
            Creature f(dir, species);
            g.add_creature(f, pos/72, pos%72);
          }
        }
        for (int i = 0; i < 1001; i++) {
          if (i%100 == 0) {
            g.print_grid(o);
            std::cout << o.str();
            o.str("");
          }
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // with rover
    // ------------

    try {
        cout << "*** Darwin 1x1 with Rover ***" << endl;
        srand(0);
        Grid g(1, 1);
        std::ostringstream o;
        Creature f(Creature::NORTH, "rover");
        g.add_creature(f, 0, 0);
        for (int i = 0; i < 6; i++) {
          g.print_grid(o);
          std::cout << o.str();
          o.str("");
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 2x2
    // with rover
    // ------------

    try {
        cout << "*** Darwin 2x2 with Rover ***" << endl;
        srand(0);
        Grid g(2, 2);
        std::ostringstream o;
        Creature r1(Creature::NORTH, "rover");
        Creature r2(Creature::NORTH, "rover");
        Creature r3(Creature::NORTH, "rover");
        Creature r4(Creature::NORTH, "rover");
        g.add_creature(r1, 0, 0);
        g.add_creature(r2, 1, 0);
        g.add_creature(r3, 0, 1);
        g.add_creature(r4, 1, 1);
        for (int i = 0; i < 6; i++) {
          g.print_grid(o);
          std::cout << o.str();
          o.str("");
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 1x3
    // with rover
    // ------------

    try {
        cout << "*** Darwin 1x3 with Rover ***" << endl;
        srand(0);
        Grid g(1, 3);
        std::ostringstream o;
        Creature r1(Creature::NORTH, "rover");
        Creature r2(Creature::NORTH, "rover");
        Creature r3(Creature::NORTH, "rover");
        g.add_creature(r1, 0, 0);
        g.add_creature(r2, 0, 1);
        g.add_creature(r3, 0, 2);
        for (int i = 0; i < 6; i++) {
          g.print_grid(o);
          std::cout << o.str();
          o.str("");
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 3x1
    // with rover
    // ------------

    try {
        cout << "*** Darwin 1x3 with Rover ***" << endl;
        srand(0);
        Grid g(3, 1);
        std::ostringstream o;
        Creature r1(Creature::NORTH, "rover");
        Creature r2(Creature::NORTH, "rover");
        Creature r3(Creature::NORTH, "rover");
        g.add_creature(r1, 0, 0);
        g.add_creature(r2, 1, 0);
        g.add_creature(r3, 2, 0);
        for (int i = 0; i < 6; i++) {
          g.print_grid(o);
          std::cout << o.str();
          o.str("");
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 100x100
    // with best
    // ------------

    try {
        cout << "*** Darwin 100x100 with Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 10000 (100x100), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        30 Food
        30 Hopper
        30 Rover
        30 Trap
        30 Best
        Simulate 1000 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
        Grid g(100, 100);
        std::ostringstream o;
        for (int j = 0; j < 5; j++) {
          std::string species;
          if (j == 0)
            species = "food";
          else if (j == 1)
            species = "hopper";
          else if (j == 2)
            species = "rover";
          else if (j == 3)
            species = "trap";
          else
            species = "best";
          for (int i = 0; i < 30; i++) {
            int pos = rand() % 10000;
            int dir = rand() % 4;
            if (dir == 0)
              dir = Creature::WEST;
            else if (dir == 1)
              dir = Creature::NORTH;
            else if (dir == 2)
              dir = Creature::EAST;
            else if (dir == 3)
              dir = Creature::SOUTH;
            Creature f(dir, species);
            g.add_creature(f, pos/100, pos%100);
          }
        }
        for (int i = 0; i < 1001; i++) {
          if (i%100 == 0) {
            g.print_grid(o);
            std::cout << o.str();
            o.str("");
          }
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------
    // darwin 5x5
    // with best
    // ------------

    try {
        cout << "*** Darwin 5x5 with Best ***" << endl;
        srand(0);
        Grid g(5, 5);
        std::ostringstream o;
        Creature f1(Creature::NORTH, "food");
        Creature f2(Creature::NORTH, "food");
        Creature f3(Creature::NORTH, "food");
        Creature f4(Creature::NORTH, "food");
        Creature b1(Creature::NORTH, "best");
        Creature b2(Creature::EAST, "best");
        Creature b3(Creature::WEST, "best");
        Creature b4(Creature::SOUTH, "best");
        Creature r1(Creature::NORTH, "rover");
        Creature r2(Creature::EAST, "rover");
        Creature r3(Creature::WEST, "rover");
        Creature r4(Creature::SOUTH, "rover");
        g.add_creature(f1, 0, 0);
        g.add_creature(f2, 4, 4);
        g.add_creature(f3, 4, 0);
        g.add_creature(f4, 0, 4);
        g.add_creature(b1, 2, 0);
        g.add_creature(b2, 3, 1);
        g.add_creature(b3, 4, 2);
        g.add_creature(b4, 2, 3);
        g.add_creature(r1, 1, 0);
        g.add_creature(r2, 3, 4);
        g.add_creature(r3, 1, 2);
        g.add_creature(r4, 3, 2);
        for (int i = 0; i < 11; i++) {
          g.print_grid(o);
          std::cout << o.str();
          o.str("");
          g.next_move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    return 0;}
