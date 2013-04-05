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
    Species food('f');
    food.add_instruction("left");
    food.add_instruction("go 0");

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Species hopper('h');
    hopper.add_instruction("hop");
    hopper.add_instruction("go 0");

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
    Species rover('r');
    rover.add_instruction("if_enemy 9");
    rover.add_instruction("if_empty 7");
    rover.add_instruction("if_random 5");
    rover.add_instruction("left");
    rover.add_instruction("go 0");
    rover.add_instruction("right");
    rover.add_instruction("go 0");
    rover.add_instruction("hop");
    rover.add_instruction("go 0");
    rover.add_instruction("infect");
    rover.add_instruction("go 0");

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
    Species trap('t');
    trap.add_instruction("if_enemy 3");
    trap.add_instruction("left");
    trap.add_instruction("go 0");
    trap.add_instruction("infect");
    trap.add_instruction("go 0");
    
    // ----
    // best
    // ----
    Species best('b');
    best.add_instruction("if_empty 6");
    best.add_instruction("if_enemy 4");
    best.add_instruction("left");
    best.add_instruction("go 0");
    best.add_instruction("infect");
    best.add_instruction("go 0");
    best.add_instruction("hop");
    best.add_instruction("go 0");
    

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
        Grid<8, 8> grid;
        Creature f1(food, 2);
        grid.add_creature(f1, 0, 0);
        Creature f2(food, 1);
        grid.add_creature(f2, 7, 7);
        Creature h1(hopper, 1);
        grid.add_creature(h1, 3, 3);
        Creature h2(hopper, 2);
        grid.add_creature(h2, 3, 4);
        Creature h3(hopper, 3);
        grid.add_creature(h3, 4, 4);
        Creature h4(hopper, 0);
        grid.add_creature(h4, 4, 3);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
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
        Grid<7, 9> grid;
        Creature t1(trap, 3);
        grid.add_creature(t1, 0, 0);
        Creature h1(hopper, 2);
        grid.add_creature(h1, 3, 2);
        Creature r1(rover, 1);
        grid.add_creature(r1, 5, 4);
        Creature t2(trap, 0);
        grid.add_creature(t2, 6, 8);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // darwin 1x1
    // ----------
    try {
	cout << "*** Darwin 1x1 ***" << endl;
    /*
    1x1 Darwin
    Trap,   facing west, at (0, 0)
    Simulate 5 moves.
    Print every grid.
         */
	Grid<1,1> grid;
	Creature t1(trap, 0);
	grid.add_creature(t1, 0, 0);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
       
    // ----------
    // darwin 1x2
    // ----------
    try {
	cout << "*** Darwin 1x2 ***" << endl;
    /*
    7x9 Darwin
    Hopper, facing east,  at (0, 0)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<1,2> grid;
	Creature h1(hopper, 2);
	grid.add_creature(h1, 0, 0);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
       
    // ----------
    // darwin 2x2
    // ----------
    try {
	cout << "*** Darwin 2x2 ***" << endl;
    /*
    2x2 Darwin
    Rover, facing east,  at (0, 0)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<2,2> grid;
	Creature r1(rover, 2);
	grid.add_creature(r1, 0, 0);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
       
    // ----------
    // darwin 2x2
    // ----------
    try {
	cout << "*** Darwin 2x2 ***" << endl;
    /*
    2x2 Darwin
    Food, facing south,  at (0, 0)
    Trap, facing west,   at (0, 1)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<2,2> grid;
	Creature f1(food, 3);
	grid.add_creature(f1, 0, 0);
	Creature t1(trap, 0);
	grid.add_creature(t1, 0, 1);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
	assert(false);}

    // ----------
    // darwin 2x2
    // ----------
    try {
	cout << "*** Darwin 2x2 ***" << endl;
    /*
    2x2 Darwin
    Food, facing south,  at (0, 0)
    Food, facing west,   at (1, 1)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<2,2> grid;
	Creature f1(food, 3);
	grid.add_creature(f1, 0, 0);
	Creature f2(food, 0);
	grid.add_creature(f2, 1, 1);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
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
    /*
    5x5 Darwin
    Simulate 5 moves.
    Print every grid.
    */
	Grid<5,5> grid;
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
	assert(false);}
    catch (const out_of_range&) {
	assert(false);}

    // ----------
    // darwin 3x3
    // ----------
    try {
	cout << "*** Darwin 3x3 ***" << endl;
    /*
    3x3 Darwin
    Hopper, facing west,  at (0, 2)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<3,3> grid;
	Creature h1(hopper, 0);
	grid.add_creature(h1, 0, 2);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
	assert(false);}

    // ----------
    // darwin 2x2
    // ----------
    try {
	cout << "*** Darwin 2x2 ***" << endl;
    /*
    2x2 Darwin
    Food,   facing west,  at (0, 0)
    Hopper, facing west,  at (0, 1)
    Trap,   facing west,  at (1, 0)
    Rover,  facing west,  at (1, 1)
    Simulate 5 moves.
    Print every grid.
    */
	Grid<2,2> grid;
	Creature f1(food, 0);
	grid.add_creature(f1, 0, 0);
        Creature h1(hopper, 0);
	grid.add_creature(h1, 0, 1);
        Creature t1(trap, 0);
	grid.add_creature(t1, 1, 0);
        Creature r1(rover, 0);
	grid.add_creature(r1, 1, 1);
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 5; ++i) {
            grid.execute_turn();
            cout << "Turn " << i << endl;
            grid.print();
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
	Grid<72, 72> grid;
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(food, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(hopper, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(rover, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(trap, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 1000; ++i) {
            grid.execute_turn();
            if(i % 100 == 0) { 
	        cout << "Turn " << i << endl;
                grid.print();
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
	Grid<72, 72> grid;
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(food, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(hopper, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(rover, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(trap, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
	for(int i = 0; i < 10; ++i) {
	    int position = rand() % 5184;
	    Creature creature(best, rand() % 4);
	    grid.add_creature(creature, position / 72, position % 72);
        }
        cout << "Turn 0" << endl;
        grid.print();
        for(int i = 1; i <= 1000; ++i) {
            grid.execute_turn();
            if(i % 100 == 0) { 
	        cout << "Turn " << i << endl;
                grid.print();
	    }
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
