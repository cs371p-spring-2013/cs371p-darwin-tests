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

#include "Darwin.h"  // catastrophic failure without this
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

     // darwin 4x4
    try {
        cout << "*** Darwin 4x4 ***" << endl;
        Darwin test;
        srand(0);

        test.createMap(4,4);
        vector< Creature > creatures;

        test.newCreature(creatures, HOPPER, 3, 3, 0);
        test.newCreature(creatures, HOPPER, 1, 1, 1);
        
        cout << "Turn = 0." << endl;
        test.printMap(cout);

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << "." << endl;
            test.runMap(creatures);
            test.printMap(cout);

            cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


     // darwin 4x4
    try {
        cout << "*** Darwin 4x4 ***" << endl;
        Darwin test;
        srand(0);

        test.createMap(4,4);
        vector< Creature > creatures;

        test.newCreature(creatures, ROVER, 0, 0, 2);
        test.newCreature(creatures, HOPPER, 3, 3, 0);
        test.newCreature(creatures, HOPPER, 1, 1, 1);
        
        cout << "Turn = 0." << endl;
        test.printMap(cout);

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << "." << endl;
            test.runMap(creatures);
            test.printMap(cout);

            cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

     // darwin 4x4
    try {
        cout << "*** Darwin 4x4 ***" << endl;
        Darwin test;
        srand(0);

        test.createMap(4,4);
        vector< Creature > creatures;

        test.newCreature(creatures, ROVER, 0, 0, 2);
        test.newCreature(creatures, HOPPER, 3, 3, 0);
        test.newCreature(creatures, HOPPER, 1, 1, 1);
        test.newCreature(creatures, TRAP, 3, 2, 2);
        
        cout << "Turn = 0." << endl;
        test.printMap(cout);

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << "." << endl;
            test.runMap(creatures);
            test.printMap(cout);

            cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


     // darwin 10x10
    try {
        cout << "*** Darwin 10x10 ***" << endl;
        Darwin test;
        srand(0);

        test.createMap(10,10);
        vector< Creature > creatures;

        test.newCreature(creatures, ROVER, 0, 0, 2);
        test.newCreature(creatures, HOPPER, 3, 3, 0);
        test.newCreature(creatures, HOPPER, 3,9, 1);
        test.newCreature(creatures, TRAP, 3, 2, 2);
        test.newCreature(creatures, ROVER, 0, 6, 2);
        test.newCreature(creatures, HOPPER, 6, 3, 0);
        test.newCreature(creatures, HOPPER, 8, 1, 1);
        test.newCreature(creatures, TRAP, 6, 5, 2);
        test.newCreature(creatures, ROVER, 7, 2, 2);
        test.newCreature(creatures, HOPPER, 4, 6, 0);
        test.newCreature(creatures, HOPPER, 8, 2, 1);
        test.newCreature(creatures, TRAP, 9, 1, 2);
        
        cout << "Turn = 0." << endl;
        test.printMap(cout);
        cout << endl;

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << "." << endl;

            test.runMap(creatures);
            test.printMap(cout);

            cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

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
        Darwin eights;

        eights.createMap(8,8);
        vector< Creature > creatures;

        eights.newCreature(creatures, FOOD, 0, 0, 2);
        eights.newCreature(creatures, HOPPER, 3, 3, 1);
        eights.newCreature(creatures, HOPPER, 3, 4, 2);
        eights.newCreature(creatures, HOPPER, 4, 4, 3);
        eights.newCreature(creatures, HOPPER, 4, 3, 0);
        eights.newCreature(creatures, FOOD, 7, 7, 1);
        
        cout << "Turn = 0." << endl;
        eights.printMap(cout);
        cout << endl;

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << "." << endl;

            eights.runMap(creatures);
            eights.printMap(cout);

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
        Darwin round2;

        round2.createMap(7,9);
        vector< Creature > creatures;

        round2.newCreature(creatures, TRAP, 0, 0, 3);
        round2.newCreature(creatures, HOPPER, 3, 2, 2);
        round2.newCreature(creatures, ROVER, 5, 4, 1);
        round2.newCreature(creatures, TRAP, 6, 8, 0);

        cout << "Turn = 0." << endl;
        round2.printMap(cout);
        cout << endl;

        for (int i = 0; i < 5; i++){
            cout << "Turn = "<< i + 1 << endl;

            round2.runMap(creatures);
            round2.printMap(cout);

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
    //     /*
    //     Randomly place the following creatures facing randomly.
    //     Call rand(), mod it with 5184 (72x72), and use that for the position
    //     in a row-major order grid.
    //     Call rand() again, mod it with 4 and use that for it's direction with
    //     the ordering: west, north, east, south.
    //     Do that for each kind of creature.
    //     10 Food
    //     10 Hopper
    //     10 Rover
    //     10 Trap
    //     Simulate 1000 moves.
    //     Print every 100th grid.
    //     */
        Darwin seventytwonob;

        seventytwonob.createMap(72, 72);
        vector< Creature > creatures;

        for (int i = 0; i < 10; i ++) {
            int pos = (rand() % 5184);
            int r = pos / 72;
            int c = pos % 72;
            seventytwonob.newCreature(creatures, FOOD, r, c, rand() %4);
        }
        
        for (int i = 0; i < 10; i ++) {
            int pos = (rand() % 5184);
            int r = pos / 72;
            int c = pos % 72;
            seventytwonob.newCreature(creatures, HOPPER, r, c, rand() %4);
        }

        for (int i = 0; i < 10; i ++) {
            int pos = (rand() % 5184);
            int r = pos / 72;
            int c = pos % 72;
            seventytwonob.newCreature(creatures, ROVER, r, c, rand() %4);
        }

        for (int i = 0; i < 10; i ++) {
            int pos = (rand() % 5184);
            int r = pos / 72;
            int c = pos % 72;
            seventytwonob.newCreature(creatures, TRAP, r, c, rand() %4);
        }

        cout << "Turn = 0." << endl;
        seventytwonob.printMap(cout);
        cout << endl;

        for (int i = 1; i < 1001; i++){

            seventytwonob.runMap(creatures);       
            if ( (i  % 100) == 0) {
                cout << "\nTurn = " << i  << "." << endl;
                seventytwonob.printMap(cout);
            }
         }   
        }
    
    
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

