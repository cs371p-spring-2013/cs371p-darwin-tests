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
    food.add_instruction(LEFT);
    food.add_instruction(GO, 0);

    Species hopper('h');
    hopper.add_instruction(HOP);
    hopper.add_instruction(GO, 0);

    Species rover('r');
    rover.add_instruction(IF_ENEMY, 9);
    rover.add_instruction(IF_EMPTY, 7);
    rover.add_instruction(IF_RANDOM, 5);
    rover.add_instruction(LEFT);
    rover.add_instruction(GO, 0);
    rover.add_instruction(RIGHT);
    rover.add_instruction(GO, 0);
    rover.add_instruction(HOP);
    rover.add_instruction(GO, 0);
    rover.add_instruction(INFECT);
    rover.add_instruction(GO, 0);

    Species trap('t');
    trap.add_instruction(IF_ENEMY, 3);
    trap.add_instruction(LEFT);
    trap.add_instruction(GO, 0);
    trap.add_instruction(INFECT);
    trap.add_instruction(GO, 0);

    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "*** Darwin 8x8 ***" << endl;

        World world(8, 8);
        world.add_creature(Creature(food, 0, 0, EAST));
        world.add_creature(Creature(hopper, 3, 3, NORTH));
        world.add_creature(Creature(hopper, 4, 3, EAST));
        world.add_creature(Creature(hopper, 4, 4, SOUTH));
        world.add_creature(Creature(hopper, 3, 4, WEST));
        world.add_creature(Creature(food, 7, 7, NORTH));
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
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

        World world(9, 7);
        world.add_creature(Creature(trap, 0, 0, SOUTH));
        world.add_creature(Creature(hopper, 2, 3, EAST));
        world.add_creature(Creature(rover, 4, 5, NORTH));
        world.add_creature(Creature(trap, 8, 6, WEST));
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
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
        World world(72, 72);
        for (int i = 0; i < 10; i++)
        {
            int position = rand() % 5184;
            int d = rand() % 4;
            int x = position % 72;
            int y = position / 72;
            world.add_creature(Creature(food, x, y, d));
        }
        for (int i = 0; i < 10; i++)
        {
            int position = rand() % 5184;
            int d = rand() % 4;
            int x = position % 72;
            int y = position / 72;
            world.add_creature(Creature(hopper, x, y, d));
        }
        for (int i = 0; i < 10; i++)
        {
            int position = rand() % 5184;
            int d = rand() % 4;
            int x = position % 72;
            int y = position / 72;
            world.add_creature(Creature(rover, x, y, d));
        }
        for (int i = 0; i < 10; i++)
        {
            int position = rand() % 5184;
            int d = rand() % 4;
            int x = position % 72;
            int y = position / 72;
            world.add_creature(Creature(trap, x, y, d));
        }
        world.print();

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 100; j++)
                world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Alone like my heart ***" << endl;

        World world(1, 1);
        world.add_creature(Creature(hopper, 0, 0, NORTH));
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** One of these foods is not like the other ***" << endl;

        World world(2, 2);
        world.add_creature(Creature(food, 0, 0, NORTH));
        world.add_creature(Creature(food, 0, 1, NORTH));
        world.add_creature(Creature(food, 1, 0, NORTH));
        world.add_creature(Creature(trap, 1, 1, NORTH)); // TRAPOCALYPSE!
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Ping pong ***" << endl;
        srand(0);

        World world(5, 1);
        world.add_creature(Creature(food, 0, 0, NORTH));
        world.add_creature(Creature(food, 4, 0, NORTH));
        world.add_creature(Creature(rover, 2, 0, EAST));
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Pong ping ***" << endl;
        srand(0);

        World world(1, 5);
        world.add_creature(Creature(food, 0, 0, NORTH));
        world.add_creature(Creature(food, 0, 4, NORTH));
        world.add_creature(Creature(rover, 0, 2, NORTH));
        world.print();

        for (int i = 0; i < 5; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Delicious corners ***" << endl;
        srand(0);

        World world(5, 4);
        world.add_creature(Creature(food, 0, 0, NORTH));
        world.add_creature(Creature(food, 4, 0, NORTH));
        world.add_creature(Creature(food, 0, 3, NORTH));
        world.add_creature(Creature(food, 4, 3, NORTH));
        world.add_creature(Creature(rover, 2, 1, NORTH));
        world.add_creature(Creature(rover, 2, 2, SOUTH));
        world.print();

        for (int i = 0; i < 10; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Oh they trap and they trap and they trap trap trap trap trap ***" << endl;

        World world(32, 32);
        world.add_creature(Creature(trap, 0, 0, NORTH));
        for (int x = 1; x < 32; x++)
            world.add_creature(Creature(food, x, 0, NORTH));
        for (int y = 1; y < 32; y++)
            for (int x = 0; x < 32; x++)
                world.add_creature(Creature(food, x, y, NORTH));
        world.print();

        for (int i = 0; i < 10; i++)
        {
            world.run_turn();
            world.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
