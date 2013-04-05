// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------
using namespace std;

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
#include "Darwin.c++"

// ----
// spawn
// ----

void spawn(int&r, int& c, directions_t& d) {
    int random = rand() % 5184;
    r = random / 72;
    c = random % 72;

    int foo = rand() % 4;
    switch (foo) {
        case WEST:
            foo = WEST;
            break;
        case NORTH:
            foo = NORTH;
            break;
        case EAST:
            foo = EAST;
            break;
        default:
            foo = SOUTH;
            break;
    }
}

// ----
// main
// ----

int main () {
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ----
    // food
    // ----

    static Species food('f', 2);
    food.addInstruction(Instruction(LEFT));
    food.addInstruction(Instruction(GO, 0));

    // ------
    // hopper
    // ------

    static Species hopper('h', 2);
    hopper.addInstruction(Instruction(HOP));
    hopper.addInstruction(Instruction(GO, 0));

    // -----
    // rover
    // -----

    static Species rover('r', 11);
    rover.addInstruction(Instruction(IF_ENEMY, 9));
    rover.addInstruction(Instruction(IF_EMPTY, 7));
    rover.addInstruction(Instruction(IF_RANDOM, 5));
    rover.addInstruction(Instruction(LEFT));
    rover.addInstruction(Instruction(GO, 0));
    rover.addInstruction(Instruction(RIGHT));
    rover.addInstruction(Instruction(GO, 0));
    rover.addInstruction(Instruction(HOP));
    rover.addInstruction(Instruction(GO, 0));
    rover.addInstruction(Instruction(INFECT));
    rover.addInstruction(Instruction(GO, 0));

    // ----
    // trap
    // ----

    static Species trap('t', 5);
    trap.addInstruction(Instruction(IF_EMPTY, 3));
    trap.addInstruction(Instruction(LEFT));
    trap.addInstruction(Instruction(GO, 0));
    trap.addInstruction(Instruction(INFECT));
    trap.addInstruction(Instruction(GO, 0));

    static Species best('b', 15);
    best.addInstruction(Instruction(IF_ENEMY, 9));  // 00
    best.addInstruction(Instruction(IF_EMPTY, 3));  // 01
    best.addInstruction(Instruction(IF_RANDOM, 11)); // 02
    best.addInstruction(Instruction(LEFT));         // 03
    best.addInstruction(Instruction(GO, 0));        // 04
    best.addInstruction(Instruction(RIGHT));        // 05
    best.addInstruction(Instruction(GO, 0));        // 06
    best.addInstruction(Instruction(HOP));          // 07
    best.addInstruction(Instruction(GO, 0));        // 08
    best.addInstruction(Instruction(INFECT));       // 09
    best.addInstruction(Instruction(GO, 0));        // 10
    best.addInstruction(Instruction(IF_EMPTY, 15)); // 11
    best.addInstruction(Instruction(LEFT));         // 12
    best.addInstruction(Instruction(GO, 0));        // 13
    best.addInstruction(Instruction(INFECT));       // 14
    best.addInstruction(Instruction(GO, 0));        // 15

    // ----------
    // darwin 1x5
    // ----------

    try {
        cout << "*** Darwin 1x5 ***" << endl;
        World w(1, 5);

        w.addCreature(&rover, 0, 0, EAST);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 5x1
    // ----------

    try {
        cout << "*** Darwin 5x1 ***" << endl;
        World w(5, 1);

        w.addCreature(&rover, 0, 0, SOUTH);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 2x4
    // ----------

    try {
        cout << "*** Darwin 2x4 ***" << endl;
        World w(2, 4);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&food ,1, 3, WEST);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 4x2
    // ----------

    try {
        cout << "*** Darwin 4x2 ***" << endl;
        World w(4, 2);

        w.addCreature(&hopper, 0, 0, SOUTH);
        w.addCreature(&food, 3, 1, NORTH);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 4x4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
        World w(4, 4);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&rover, 0, 3, SOUTH);
        w.addCreature(&trap, 3, 0, WEST);
        w.addCreature(&trap, 3, 3, NORTH);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 5x5
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        World w(5, 5);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&hopper, 0, 4, SOUTH);
        w.addCreature(&hopper, 4, 0, WEST);
        w.addCreature(&hopper, 4, 4, NORTH);
        w.addCreature(&rover, 2, 2, NORTH);

        w.printWorld();

        for (int i = 0; i < 10; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 6x6
    // ----------

    try {
        cout << "*** Darwin 6x6 ***" << endl;
        World w(6, 6);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&hopper, 0, 4, SOUTH);
        w.addCreature(&hopper, 4, 0, WEST);
        w.addCreature(&hopper, 4, 4, NORTH);
        w.addCreature(&rover, 1, 1, NORTH);
        w.addCreature(&rover, 2, 2, SOUTH);
        w.addCreature(&rover, 3, 3, EAST);
        w.addCreature(&rover, 5, 5, WEST);

        w.printWorld();

        for (int i = 0; i < 10; i++) {
            w.stepForward();
            w.printWorld();
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
        World w(8, 8);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&hopper, 0, 4, SOUTH);
        w.addCreature(&hopper, 4, 0, WEST);
        w.addCreature(&hopper, 4, 4, NORTH);
        w.addCreature(&rover, 1, 1, NORTH);
        w.addCreature(&rover, 2, 2, SOUTH);
        w.addCreature(&rover, 3, 3, EAST);
        w.addCreature(&rover, 5, 5, WEST);
        w.addCreature(&food, 3, 1, NORTH);
        w.addCreature(&food, 1, 3, WEST);

        w.printWorld();

        for (int i = 0; i < 10; i++) {
            w.stepForward();
            w.printWorld();
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
        World w(8, 8);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&hopper, 0, 4, SOUTH);
        w.addCreature(&hopper, 4, 0, WEST);
        w.addCreature(&hopper, 4, 4, NORTH);
        w.addCreature(&rover, 1, 1, NORTH);
        w.addCreature(&rover, 2, 2, SOUTH);
        w.addCreature(&rover, 3, 3, EAST);
        w.addCreature(&rover, 5, 5, WEST);
        w.addCreature(&food, 3, 1, NORTH);
        w.addCreature(&food, 1, 3, WEST);
        w.addCreature(&trap, 6, 7, WEST);
        w.addCreature(&trap, 7, 6, NORTH);

        w.printWorld();

        for (int i = 0; i < 10; i++) {
            w.stepForward();
            w.printWorld();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 12x12
    // ------------

    try {
        cout << "*** Darwin 12x12 ***" << endl;
        World w(12, 12);

        w.addCreature(&hopper, 0, 0, EAST);
        w.addCreature(&hopper, 1, 1, SOUTH);
        w.addCreature(&hopper, 2, 2, WEST);
        w.addCreature(&hopper, 3, 3, NORTH);
        w.addCreature(&rover, 4, 4, NORTH);
        w.addCreature(&rover, 5, 5, SOUTH);
        w.addCreature(&rover, 6, 6, EAST);
        w.addCreature(&rover, 7, 7, WEST);
        w.addCreature(&food, 8, 8, NORTH);
        w.addCreature(&food, 9, 9, WEST);
        w.addCreature(&trap, 10, 10, WEST);
        w.addCreature(&trap, 11, 11, NORTH);

        w.printWorld();

        for (int i = 0; i < 10; i++) {
            w.stepForward();
            w.printWorld();
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
        World w(8, 8);
        w.addCreature(&food, 0, 0, EAST);
        w.addCreature(&hopper, 3, 3, NORTH);
        w.addCreature(&hopper, 3, 4, EAST);
        w.addCreature(&hopper, 4, 4, SOUTH);
        w.addCreature(&hopper, 4, 3, WEST);
        w.addCreature(&food, 7, 7, NORTH);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
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
        World w(7, 9);
        w.addCreature(&trap, 0, 0, SOUTH);
        w.addCreature(&hopper, 3, 2, EAST);
        w.addCreature(&rover, 5, 4, NORTH);
        w.addCreature(&trap, 6, 8, WEST);

        w.printWorld();

        for (int i = 0; i < 5; i++) {
            w.stepForward();
            w.printWorld();
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

        World w(72, 72);
        int r;
        int c;
        directions_t d;

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&food, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&hopper, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&rover, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&trap, r, c, d);
        }

        w.printWorld();

        for(int i = 0; i < 1001; i++) {
            w.stepForward();

            if((i % 100) == 0) {
                w.printWorld();
            }   
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

        World w(72, 72);
        int r;
        int c;
        directions_t d;

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&food, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&hopper, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&rover, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&trap, r, c, d);
        }

        for(int i = 0; i < 10; i++) {
            spawn(r, c, d);
            w.addCreature(&best, r, c, d);
        }

        w.printWorld();

        for(int i = 0; i < 1001; i++) {
            w.stepForward();

            if((i % 100) == 0) {
                w.printWorld();
            }   
        }
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}