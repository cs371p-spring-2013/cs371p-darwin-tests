// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Clare Dominique Coleman
// Manoj Dhanapal
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

#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;
    //ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ----
    // food
    // ----

    /*
     0: look_left
     1: go 0
    */

    Species food('f');
    food.add_program(look_left);
    food.add_program(go, 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Species hopper('h');
    hopper.add_program(hop);
    hopper.add_program(go, 0);

    // -----
    // rover
    // -----

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: look_left
     4: go 0
     5: look_right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    Species rover('r');
    rover.add_program(if_enemy, 9);
    rover.add_program(if_empty, 7);
    rover.add_program(if_random, 5);
    rover.add_program(look_left);
    rover.add_program(go, 0);
    rover.add_program(look_right);
    rover.add_program(go, 0);
    rover.add_program(hop);
    rover.add_program(go, 0);
    rover.add_program(infect);
    rover.add_program(go, 0);


    // ----
    // trap
    // ----

    /*
     0: if_enemy 3
     1: look_left
     2: go 0
     3: infect
     4: go 0
    */

    Species trap('t');
    trap.add_program(if_enemy, 3);
    trap.add_program(look_left);
    trap.add_program(go, 0);
    trap.add_program(infect);
    trap.add_program(go, 0);

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
         World w(8,8);
         w.add_creature(&food,east,0,0);
         w.add_creature(&hopper,north,3,3);
         w.add_creature(&hopper,east,3,4);
         w.add_creature(&hopper,south,4,4);
         w.add_creature(&hopper,west,4,3);
         w.add_creature(&food,north,7,7);
         w.execute(5, 1);
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
         World w(7,9);
         w.add_creature(&trap,south,0,0);
         w.add_creature(&hopper,east,3,2);
         w.add_creature(&rover,north,5,4);
         w.add_creature(&trap,west,6,8);
         w.execute(5, 1);
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
      World w(72, 72);
      int r1;
      direction r2;
      for(int i = 0; i < 4; ++i) {
         for(int j = 0; j < 10; ++j) {
            r1 = rand() % 5184;
            r2 = (direction)(rand() % 4);
            switch(i) {
               case 0:
                  w.add_creature(&food, r2, r1/72, r1%72);
                  break;
               case 1:
                  w.add_creature(&hopper, r2, r1/72, r1%72);
                  break;
               case 2:
                  w.add_creature(&rover, r2, r1/72, r1%72);
                  break;
               case 3:
                  w.add_creature(&trap, r2, r1/72, r1%72);
                  break;
               default:
                  assert (false);
            }
         }
      }
      w.execute(1000, 100);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----
    // best
    // -----

    Species best('b');
    best.add_program(go, 0);

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
      World w(72, 72);
      int r1;
      direction r2;
      for(int i = 0; i < 5; ++i) {
         for(int j = 0; j < 10; ++j) {
            r1 = rand() % 5184;
            r2 = (direction)(rand() % 4);
            switch(i) {
               case 0:
                  w.add_creature(&food, r2, r1/72, r1%72);
                  break;
               case 1:
                  w.add_creature(&hopper, r2, r1/72, r1%72);
                  break;
               case 2:
                  w.add_creature(&rover, r2, r1/72, r1%72);
                  break;
               case 3:
                  w.add_creature(&trap, r2, r1/72, r1%72);
                  break;
               case 4:
                  w.add_creature(&best, r2, r1/72, r1%72);
                  break;
               default:
                  assert (false);
            }
         }
      }
      w.execute(1000, 100);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 9x7
    // ------------
    
    try {
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);
        /*
        9x7 Darwin
        Food,   facing south, at (0, 0)
        Trap,   facing south, at (1, 1)
        Hopper, facing north, at (2, 2)
        Trap,   facing north, at (2, 5)
        Rover,  facing north, at (4, 4)
        Rover,  facing east,  at (6, 5)
        Simulate 5 moves.
        Print every grid.
        */
         World w(9,7);
         w.add_creature(&food,south,0,0);
         w.add_creature(&trap,south,1,1);
         w.add_creature(&hopper,north,2,2);
         w.add_creature(&trap,north,2,5);
         w.add_creature(&rover,north,4,4);
         w.add_creature(&rover,east,6,5);
         w.execute(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);

        World w(1, 1);
        w.add_creature(&food, west, 0, 0);
        w.execute(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1x1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);

        World w(1, 1);
        w.add_creature(&hopper, west, 0, 0);
        w.execute(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 2 x 2
    // ------------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);

        World w(2, 2);
        w.add_creature(&rover, west, 0, 0);
        w.add_creature(&food, east, 1, 0);
        w.add_creature(&hopper, east, 0, 1);
        w.add_creature(&food, east, 1, 1);
        w.execute(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 3 x 3
    // ------------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);

        World w(3, 3);
        w.execute(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 5 x 5
    // ------------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
        int r1, r2;
        World w(5, 5);
        r1 = rand(), r2 = rand()%25;
        w.add_creature(&best, (direction)(r1%4), r2/5, r2%5); 
        r1 = rand(), r2 = rand()%25;
        w.add_creature(&best, (direction)(r1%4), r2/5, r2%5); 
        r1 = rand(), r2 = rand()%25;
        w.add_creature(&rover, (direction)(r1%4), r2/5, r2%5); 
        r1 = rand(), r2 = rand()%25;
        w.add_creature(&rover, (direction)(r1%4), r2/5, r2%5); 
        w.execute(6, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
