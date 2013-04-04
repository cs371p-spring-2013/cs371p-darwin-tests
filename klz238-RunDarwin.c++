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
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert> // assert
#include <cstdlib> // rand, srand
#include <iostream> // cout, endl
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
    Program p_food;
    p_food.addInstruction(LEFT);
    p_food.addInstruction(GO, 0);
    Species s_food("food", 'f', p_food);

    // ------
    // hopper
    // ------

    /*
0: hop
1: go 0
*/
    Program p_hopper;
    p_hopper.addInstruction(HOP);
    p_hopper.addInstruction(GO, 0);
    Species s_hopper("hopper", 'h', p_hopper);

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
    Program p_rover;
    p_rover.addInstruction(IFENEMY, 9);
    p_rover.addInstruction(IFEMPTY, 7);
    p_rover.addInstruction(IFRANDOM, 5);
    p_rover.addInstruction(LEFT);
    p_rover.addInstruction(GO, 0);
    p_rover.addInstruction(RIGHT);
    p_rover.addInstruction(GO, 0);
    p_rover.addInstruction(HOP);
    p_rover.addInstruction(GO, 0);
    p_rover.addInstruction(INFECT);
    p_rover.addInstruction(GO, 0);
    Species s_rover("rover", 'r', p_rover);

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
    Program p_trap;
    p_trap.addInstruction(IFENEMY, 3);
    p_trap.addInstruction(LEFT);
    p_trap.addInstruction(GO, 0);
    p_trap.addInstruction(INFECT);
    p_trap.addInstruction(GO, 0);
    Species s_trap("trap", 't', p_trap);

    // ----
    // best
    // ---

    /*
    0: if_enemy 6
    1: if_empty 4
    2: right
    3: go 0
    4: hop
    5: go 0
    6: infect
    7: go 0
    */
    Program p_best;
    p_best.addInstruction(IFENEMY, 6);
    p_best.addInstruction(IFEMPTY, 4);
    p_best.addInstruction(RIGHT);
    p_best.addInstruction(GO, 0);
    p_best.addInstruction(HOP);
    p_best.addInstruction(GO, 0);
    p_best.addInstruction(INFECT);
    p_best.addInstruction(GO, 0);
    Species s_best("best", 'b', p_best);

    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        /*
		8x8 Darwin
		Food, facing east, at (0, 0)
		Hopper, facing north, at (3, 3)
		Hopper, facing east, at (3, 4)
		Hopper, facing south, at (4, 4)
		Hopper, facing west, at (4, 3)
		Food, facing north, at (7, 7)
		Simulate 5 moves.
		Print every grid.
		*/
        Creature food1(s_food, EAST);
        Creature hopper1(s_hopper, NORTH);
        Creature hopper2(s_hopper, EAST);
        Creature hopper3(s_hopper, SOUTH);
        Creature hopper4(s_hopper, WEST);
        Creature food2(s_food, NORTH);
        Game g(8,8);
        g.addCreature(&food1, 0, 0);
        g.addCreature(&hopper1, 3, 3);
        g.addCreature(&hopper2, 3, 4);
        g.addCreature(&hopper3, 4, 4);
        g.addCreature(&hopper4, 4, 3);
        g.addCreature(&food2, 7, 7);
        for(int i = 0; i < 5; ++i)
        {
            cout << g << "\n\n";
            g.simulate(1);
        }
        cout << g;
        cout << "\n\n";
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
		Trap, facing south, at (0, 0)
		Hopper, facing east, at (3, 2)
		Rover, facing north, at (5, 4)
		Trap, facing west, at (6, 8)
		Simulate 5 moves.
		Print every grid.
		*/
		Creature trap1(s_trap, SOUTH);
		Creature hopper1(s_hopper, EAST);
		Creature rover1(s_rover, NORTH);
		Creature trap2(s_trap, WEST);
		Game g(7,9);
		g.addCreature(&trap1, 0, 0);
		g.addCreature(&hopper1, 3, 2);
		g.addCreature(&rover1, 5, 4);
		g.addCreature(&trap2, 6, 8);

		for(int i = 0; i < 5; i++) {
			cout << g << "\n\n";
			g.simulate(1);
		}				
        cout << g;
		cout << "\n\n";
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
        srand(0);
        /*
		7x9 Darwin
		Trap, facing south, at (0, 0)
		Hopper, facing east, at (2, 2)
		Simulate 5 moves.
		Print every grid.
		*/
		Creature trap1(s_trap, SOUTH);
		Creature hopper1(s_hopper, WEST);
		Game g(3,3);
		g.addCreature(&trap1, 0, 0);
		g.addCreature(&hopper1, 2, 2);
		for(int i = 0; i < 5; i++) {
			cout << g << "\n\n";
			g.simulate(1);
		}				
        cout << g;
		cout << "\n\n";
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 1x10
    // ----------

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        srand(0);
        /*
		Hopper, facing east, at (0, 0)
		Simulate 6 moves.
		Print every grid.
		*/
		Creature hopper1(s_hopper, EAST);
		Game g(1,10);
		g.addCreature(&hopper1, 0, 0);
		for(int i = 0; i < 6; i++) {
			cout << g << "\n\n";
			g.simulate(1);
		}				
        cout << g;
		cout << "\n\n";
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 10x1
    // ----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
		Hopper, facing east, at (9, 0)
		Simulate 5 moves.
		Print every grid.
		*/
		Creature hopper1(s_hopper, NORTH);
		Game g(10,1);
		g.addCreature(&hopper1, 9, 0);
		for(int i = 0; i <= 6; i++) {
			cout << g << "\n\n";
			g.simulate(1);
		}				
        cout << g;
		cout << "\n\n";
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 10x10
    // ----------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        /*
		Rover, facing east, at (9, 0)
		Simulate 6 moves.
		Print every grid.
		*/
		Creature rover1(s_rover, EAST);
		Game g(10,10);
		g.addCreature(&rover1, 9, 0);
		for(int i = 0; i < 6; i++) {
			cout << g << "\n\n";
			g.simulate(10);
		}				
        cout << g;
	    cout << "\n\n";	
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
        vector<Creature> food;
        food.reserve(10);
        vector<Creature> hopper;
        hopper.reserve(10);
        vector<Creature> rover;
        rover.reserve(10);
        vector<Creature> trap;
        trap.reserve(10);
        Game g(72,72);
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature f(s_food, (EDirection)(rand() % 4));
            food.push_back(f);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&food.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature h(s_hopper, (EDirection)(rand() % 4));
            hopper.push_back(h);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&hopper.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature r(s_rover, (EDirection)(rand() % 4));
            rover.push_back(r);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&rover.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature t(s_trap, (EDirection)(rand() % 4));
            trap.push_back(t);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&trap.at(i), row, col);
        }
		for(int i = 0; i < 10; i++) {
    		cout << g << "\n\n";
            cout.flush();
			g.simulate(100);
		}				
        cout << g;
        cout << "\n\n";

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
        vector<Creature> food;
        food.reserve(10);
        vector<Creature> hopper;
        hopper.reserve(10);
        vector<Creature> rover;
        rover.reserve(10);
        vector<Creature> trap;
        trap.reserve(10);
        vector<Creature> best;
        best.reserve(10);
        Game g(72,72);
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature f(s_food, (EDirection)(rand() % 4));
            food.push_back(f);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&food.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature h(s_hopper, (EDirection)(rand() % 4));
            hopper.push_back(h);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&hopper.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature r(s_rover, (EDirection)(rand() % 4));
            rover.push_back(r);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&rover.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature t(s_trap, (EDirection)(rand() % 4));
            trap.push_back(t);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&trap.at(i), row, col);
        }
        for(int i = 0; i < 10; ++i)
        {
            size_t pos = rand() % 5184;
            Creature b(s_best, (EDirection)(rand() % 4));
            best.push_back(b);
            size_t col = pos % 72;
            size_t row = (pos - col) / 72;
            g.addCreature(&best.at(i), row, col);
        }
        for(int i = 0; i < 10; i++) {
    		cout << g << "\n\n";
            cout.flush();
			g.simulate(100);
		}				
        cout << g;
        cout << "\n\n";

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 50x50 ***\n";
        srand(0);

        vector<Creature> food;
        food.reserve(500);
        Game g(50,50);
        for(size_t i = 0; i < 500; ++i)
        {
            size_t pos = rand() % 2500;
            Creature f(s_food, (EDirection)(rand() % 4));
            food.push_back(f);
            size_t col = pos % 50;
            size_t row = (pos - col) / 50;
            while (!g.addCreature(&food.at(i), row, col))
            {
                pos = rand() % 2500;
                col = pos % 50;
                row = (pos - col) / 50;
            }
        }
        Creature z(s_best);
        size_t pos = rand() % 2500;
        size_t col = pos % 50;
        size_t row = (pos - col) / 50;
        while (!g.addCreature(&z, row, col))
        {
            pos = rand() % 2500;
            col = pos % 50;
            row = (pos - col) / 50;
        }
        for(int i = 0; i < 10; ++i)
        {
            cout << g << "\n\n";
            g.simulate(100);
        }
        cout << g;
        cout << "\n\n";
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 50x50 ***\n";
        srand(0);

        vector<Creature> cs;
        cs.reserve(500);
        Game g(50,50);
        for(size_t i = 0; i < 500; ++i)
        {
            size_t pos = rand() % 2500;
            EDirection d = (EDirection)(rand() % 4);
            size_t col = pos % 50;
            size_t row = (pos - col) / 50;
            Creature c((i < 100 ? s_food : (i < 200 ? s_hopper : (i < 300 ? s_rover : (i < 400 ? s_trap : s_best)))), d);
            cs.push_back(c);
            while (!g.addCreature(&cs.at(i), row, col))
            {
                pos = rand() % 2500;
                col = pos % 50;
                row = (pos - col) / 50;
            }
        }
        for(int i = 0; i < 10; ++i)
        {
            cout << g << "\n\n";
            g.simulate(100);
        }
        cout << g;
        cout << "\n\n";
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

return 0;}
