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
        /// Test 1
        cout << "*** Darwin 8x8 ***" << endl;
        Darwin darwin(8, 8, 5, cout, 1);

        darwin.addCreatureToWorld(Food_Type, {0, 0}, East);
        darwin.addCreatureToWorld(Hopper_Type, {3, 3}, North);
        darwin.addCreatureToWorld(Hopper_Type, {3, 4}, East);
        darwin.addCreatureToWorld(Hopper_Type, {4, 4}, South);
        darwin.addCreatureToWorld(Hopper_Type, {4, 3}, West);
        darwin.addCreatureToWorld(Food_Type, {7, 7}, North);

        darwin.runSimulations();
        
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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        /// Test 2
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);
        Darwin darwin(7, 9, 5, cout, 1);

        darwin.addCreatureToWorld(Trap_Type, {0, 0}, South);
        darwin.addCreatureToWorld(Hopper_Type, {3, 2}, East);
        darwin.addCreatureToWorld(Rover_Type, {5, 4}, North);
        darwin.addCreatureToWorld(Trap_Type, {6, 8}, West);

        darwin.runSimulations();

        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
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
        // Test 3
        cout << "*** Darwin 72x72 without Best ***" << endl;
        srand(0);
        Darwin darwin(72, 72, 1000, cout, 100);

        /// Add Food
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Food_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Hopper
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Hopper_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Rover
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Trap
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Trap_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

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
        // Test 4
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
        Darwin darwin(72, 72, 1000, cout, 100);

        /// Add Food
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Food_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Hopper
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Hopper_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Rover
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Trap
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Trap_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Batman
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        // Test 5
        cout << "*** Battle Royal: Darwin 72x72 with Best & Rover x50***" << endl;
        srand(0);
        Darwin darwin(72, 72, 1000, cout, 100);

        /// Add Rover
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        /// Add Batman
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % 5184;
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/72, randValPosition % 72}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        // Test 6
        cout << "*** Death Alley: Darwin 100x20 with Best ***" << endl;
        srand(0);
        Darwin darwin(100, 20, 1000, cout, 100);

        /// Add Rover
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (2000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/20, randValPosition % 20}, static_cast<Direction>(randValDirection));
        }

        /// Add Batman
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (2000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/20, randValPosition % 20}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        // Test 7
        cout << "*** Food Fight: Darwin 100x100 with Best ***" << endl;
        srand(0);
        Darwin darwin(100, 100, 1000, cout, 100);

        /// Add Rover
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        /// Add Food
        for(int i = 0; i < 100; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Food_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        /// Add Batman
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        // Test 8
        cout << "*** BestvRover, 10v10: Darwin 100x100 ***" << endl;
        srand(0);
        Darwin darwin(100, 100, 3000, cout, 100);

        // Food
        for(int i = 0; i < 300; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Food_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        // Rover
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        /// Add Batman
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (10000);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/100, randValPosition % 100}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        // Test 9
        cout << "*** BestvTrapvRover, 10v10v100: Darwin 60x60 ***" << endl;
        srand(0);
        Darwin darwin(60, 60, 1000, cout, 100);

        // Trap
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (3600);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Trap_Type, {randValPosition/60, randValPosition % 60}, static_cast<Direction>(randValDirection));
        }

        /// Add Rover
        for(int i = 0; i < 100; i++) {
            int randValPosition = rand() % (3600);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/60, randValPosition % 60}, static_cast<Direction>(randValDirection));
        }

        // Add Batman
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (3600);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/60, randValPosition % 60}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        // Test 10
        cout << "*** BestvTrapvRovervHopper, 10v10v50v50: Darwin 80x80 ***" << endl;
        srand(0);
        Darwin darwin(80, 80, 1000, cout, 100);

        // Trap
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (6400);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Trap_Type, {randValPosition/80, randValPosition % 80}, static_cast<Direction>(randValDirection));
        }

        // Add Hopper
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (6400);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Hopper_Type, {randValPosition/80, randValPosition % 80}, static_cast<Direction>(randValDirection));
        }

        /// Add Rover
        for(int i = 0; i < 50; i++) {
            int randValPosition = rand() % (6400);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Rover_Type, {randValPosition/80, randValPosition % 80}, static_cast<Direction>(randValDirection));
        }

        // Add Batman
        for(int i = 0; i < 10; i++) {
            int randValPosition = rand() % (6400);
            int randValDirection = rand() % 4;
            darwin.addCreatureToWorld(Batman_Type, {randValPosition/80, randValPosition % 80}, static_cast<Direction>(randValDirection));
        }

        darwin.runSimulations();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
