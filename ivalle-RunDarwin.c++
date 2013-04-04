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
        Game darwin(8,8);

	Food food(Direction::WEST, 0,0);
	Hopper hopper(Direction::NORTH, 3, 3);
    Hopper hopper2(Direction::EAST, 3, 4);
	Hopper hopper3(Direction::SOUTH, 4, 4);
    Hopper hopper4(Direction::WEST, 4, 3);
    Food food2(Direction::NORTH, 7, 7);

    darwin.addCreature(food);
	darwin.addCreature(hopper);
	darwin.addCreature(hopper2);
    darwin.addCreature(hopper3);
    darwin.addCreature(hopper4);
    darwin.addCreature(food2);
    darwin.simulate(5, 1);
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

        Game darwin(7,9);

        Trap trap(Direction::SOUTH, 0, 0);
        Hopper hopper(Direction::EAST, 3, 2);
        Rover rover(Direction::NORTH, 5, 4);
        Trap trap2(Direction::WEST, 6, 8);

        darwin.addCreature(trap);
        darwin.addCreature(hopper);
        darwin.addCreature(rover);
        darwin.addCreature(trap2);

        darwin.simulate(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);

        Game darwin(1, 1);

        Hopper hopper(Direction::EAST, 0, 0);

        darwin.addCreature(hopper);

        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    try {
        cout << "*** Darwin 5x1 ***" << endl;
        srand(0);

        Game darwin(5, 1);
        Hopper hopper(Direction::SOUTH, 0, 0);
        darwin.addCreature(hopper);
        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    try {
        cout << "*** Darwin 1x5 ***" << endl;
        srand(0);

        Game darwin(1, 5);
        Hopper hopper(Direction::EAST, 0, 0);
        darwin.addCreature(hopper);
        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    try {
        cout << "*** Darwin 5x5 without Best***" << endl;
        srand(0);

        Game darwin(5, 5);
        Hopper hopper(Direction::SOUTH, 0, 0);
        Food food(Direction::NORTH, 2, 3);
        Rover rover(Direction::EAST, 4, 4);
        darwin.addCreature(hopper);
        darwin.addCreature(food);
        darwin.addCreature(rover);

        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    try {
        cout << "*** Darwin 5x5 with Best ***" << endl;
        srand(0);

        Game darwin(5, 5);
        Hopper hopper(Direction::SOUTH, 0, 0);
        Food food(Direction::NORTH, 2, 3);
        Rover rover(Direction::EAST, 4, 4);
        Best best(Direction::NORTH, 3, 2);
        darwin.addCreature(hopper);
        darwin.addCreature(food);
        darwin.addCreature(rover);
        darwin.addCreature(best);

        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    try {
        cout << "*** Darwin 5x5 with  All Best and one Rover***" << endl;
        srand(0);

        Game darwin(5, 5);
        Best one(Direction::EAST, 0, 0);
        Best two(Direction::NORTH, 2, 3);
        Best three(Direction::SOUTH, 4, 4);
        Rover rover(Direction::NORTH, 3, 3);
        darwin.addCreature(one);
        darwin.addCreature(two);
        darwin.addCreature(three);
        darwin.addCreature(rover);

        darwin.simulate(5, 1);
    }

    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }


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

        Game darwin(72, 72);

        vector<Food> foods;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            foods.push_back(Food(direction, x, y));
        }

        vector<Hopper> hoppers;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            hoppers.push_back(Hopper(direction, x, y));
        }

        vector<Rover> rovers;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            rovers.push_back(Rover(direction, x, y));
        }

        vector<Trap> traps;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            traps.push_back(Trap(direction, x, y));
        }

        for(int i=0; i<10; i++)
        {
            darwin.addCreature(foods[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(hoppers[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(rovers[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(traps[i]);
        }
        darwin.simulate(1000, 100);


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

	Game darwin(72, 72);

        vector<Food> foods;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            foods.push_back(Food(direction, x, y));
        }

        vector<Hopper> hoppers;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            hoppers.push_back(Hopper(direction, x, y));
        }

        vector<Rover> rovers;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            rovers.push_back(Rover(direction, x, y));
        }

        vector<Trap> traps;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            traps.push_back(Trap(direction, x, y));
        }

	vector<Best> bests;
        for(int i=0; i<10; i++)
        {
            int position = rand() % 5184;
            int x = position / 72;
            int y = position % 72;

            int direction = rand() % 4;

            bests.push_back(Best(direction, x, y));
        }

        for(int i=0; i<10; i++)
        {
            darwin.addCreature(foods[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(hoppers[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(rovers[i]);
        }
        for(int i=0; i<10; i++)
        {
            darwin.addCreature(traps[i]);
        }
	for(int i=0; i<10; i++)
        {
            darwin.addCreature(bests[i]);
        }
        darwin.simulate(1000, 100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
