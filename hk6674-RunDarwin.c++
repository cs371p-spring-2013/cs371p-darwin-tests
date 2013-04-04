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

        // number of columns, number of rows, number of creatures
        // darwin_position pos1(8,8, 6);


        //      N
        //      1 
        //      |
        // W 0-   -2 E
        //      |
        //      3
        //      S  

       vector<darwin_creatures> creatures1;

        // (identity, col, row)

        //Food,   facing east,  at (0, 0)
        darwin_creatures thing1 ('f', 2, 0, 0);
        creatures1.push_back(thing1);

        //Food,   facing north, at (7, 7)
        darwin_creatures thing2 ('f', 1, 7, 7);
        creatures1.push_back(thing2);
  
        //Hopper, facing north, at (3, 3)
        darwin_creatures thing3 ('h', 1, 3, 3);
        creatures1.push_back(thing3);

        //Hopper, facing east,  at (3, 4)
        darwin_creatures thing4 ('h', 2, 4, 3);
        creatures1.push_back(thing4);
        
        //Hopper, facing south, at (4, 4)
        darwin_creatures thing5 ('h', 3, 4, 4);
        creatures1.push_back(thing5);
        
        //Hopper, facing west,  at (4, 3)
        darwin_creatures thing6 ('h', 0, 3, 4);
        creatures1.push_back(thing6);


        darwin_start_given(5, 2, 4, 0, 0, 0, creatures1, 8, 8, 1);
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

        //      N
        //      1 
        //      |
        // W 0-   -2 E
        //      |
        //      3
        //      S  

       vector<darwin_creatures> creatures2;
   
        // Hopper, facing east,  at (3, 2)
        darwin_creatures thing7 ('h', 2, 2, 3);
        creatures2.push_back(thing7);

        // Rover,  facing north, at (5, 4)
        darwin_creatures thing8 ('r', 1, 4, 5);
        creatures2.push_back(thing8);

        // Trap,   facing west,  at (6, 8)
        darwin_creatures thing9 ('t', 0, 8, 6);
        creatures2.push_back(thing9);

         // Trap,   facing south, at (0, 0)
        darwin_creatures thing10 ('t', 3, 0, 0);
        creatures2.push_back(thing10);


        //  ALWAYS!!
        //  given = (row, col)
        //  need = (col, row)
        //  must switch!!!
        
        darwin_start_given(5, 0, 1, 1, 2, 0, creatures2, 9, 7, 1);
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

        // need an emtpy creatures
        vector<darwin_creatures> creatures3;

        darwin_start_random(500, 10, 10, 10, 10, 0, creatures3, 72, 72, 100);
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
        
        vector<darwin_creatures> creatures4;

        darwin_start_random(1000, 10, 10, 10, 10, 10, creatures4, 72, 72, 100);


        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

