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

    Food food = Food();

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Hopper hopper = Hopper();

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

    Rover rover = Rover();

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

     Trap trap = Trap();
     
    // ----
    // best
    // ----
    
    /*
     0: if_enemy 3
     1: if_empty 6
     2: right
     3: go 0
     4: infect
     5: go 0
     6: hop
     7: left
     8: go 0
    */
    
     Best best = Best();

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
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(8, 8);
        Creature f1 = Creature(&food, 0, 0, EAST);
        Creature h1 = Creature(&hopper, 3, 3, NORTH);
        Creature h2 = Creature(&hopper, 3, 4, EAST);
        Creature h3 = Creature(&hopper, 4, 4, SOUTH);
        Creature h4 = Creature(&hopper, 4, 3, WEST);
        Creature f2 = Creature(&food, 7, 7, NORTH);

        d.place_creature(&f1, 0, 0);
        d.place_creature(&h1, 3, 3);
        d.place_creature(&h2, 3, 4);
        d.place_creature(&h3, 4, 4);
        d.place_creature(&h4, 4, 3);
        d.place_creature(&f2, 7, 7);

        d.print(cout, 0);
        for (int i = 1; i <= 5; ++i) {
            d.step();

            d.print(cout, i);
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
        // 0:west, 1:north, 2:east, 3:south.


        Darwin d = Darwin(7, 9);
        Creature t1 = Creature(&trap, 0, 0, SOUTH);
        Creature h1 = Creature(&hopper, 3, 2, EAST);
        Creature r1 = Creature(&rover, 5, 4, NORTH);
        Creature t2 = Creature(&trap, 6, 8, WEST);
        
        d.place_creature(&t1, 0, 0);
        d.place_creature(&h1, 3, 2);
        d.place_creature(&r1, 5, 4);
        d.place_creature(&t2, 6, 8);
        
        d.print(cout, 0);
        for (int i = 1; i <= 5; ++i) {
            d.step();

            d.print(cout, i);
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
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(72, 72);
        
        vector<Creature> creatures;
        
        
        // make food.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&food, position / 72, position % 72, direction));
        }
        
        // make hopper.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&hopper, position / 72, position % 72, direction));
        }
        
        // make rover.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&rover, position / 72, position % 72, direction));
        }
        
        // make trap.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&trap, position / 72, position % 72, direction));
        }
        
        // place all creatures on the board.
        for (int i = 0; i < (int)creatures.size(); ++i) {
        	Creature c = creatures[i];
        	pair<int, int> coordinates = c.get_coordinates();
        	d.place_creature(&creatures[i], coordinates.first, coordinates.second);
        }
        
        d.print(cout, 0);
        
        for (int i = 1; i <= 1000; ++i) {
            d.step();

			if (i % 100 == 0) {
				d.print(cout, i);
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
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(72, 72);
        
        vector<Creature> creatures;
        
        
        // make food.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&food, position / 72, position % 72, direction));
        }
        
        // make hopper.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&hopper, position / 72, position % 72, direction));
        }
        
        // make rover.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&rover, position / 72, position % 72, direction));
        }
        
        // make trap.
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&trap, position / 72, position % 72, direction));
        }
        
        // make best
        for (int i = 0; i < 10; ++i) {
        	int position = rand() % 5184;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&best, position / 72, position % 72, direction));
        }
        
        // place all creatures on the board.
        for (int i = 0; i < (int)creatures.size(); ++i) {
        	Creature c = creatures[i];
        	pair<int, int> coordinates = c.get_coordinates();
        	d.place_creature(&creatures[i], coordinates.first, coordinates.second);
        }
        
        d.print(cout, 0);
        
        
        for (int i = 1; i <= 1000; ++i) {
            d.step();

			if (i % 100 == 0) {
				d.print(cout, i);
			}
        }
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 13x2
    // ----------

    try {
        cout << "*** Darwin 13x2 ***" << endl;
        /*
        13x2 Darwin
        Hopper, facing north, at (12, 0)
        Hopper, facing north,  at (12, 1)
        Simulate 13 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(13, 2);
        Creature h1 = Creature(&hopper, 12, 0, NORTH);
        Creature h2 = Creature(&hopper, 12, 1, NORTH);

        d.place_creature(&h1, 12, 0);
        d.place_creature(&h2, 12, 1);

        d.print(cout, 0);
        for (int i = 1; i <= 13; ++i) {
            d.step();

            d.print(cout, i);
        }
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ----------
    // darwin 5x16
    // ----------

    try {
        cout << "*** Darwin 5x16 ***" << endl;
        /*
        5x16 Darwin
        Food,   facing east,  at (0, 10)
        Rover, facing north, at (3, 3)
        Hopper, facing west,  at (3, 14)
        Trap, facing south, at (4, 4)
        Rover, facing west,  at (4, 3)
        Food,   facing north, at (2, 7)
        Simulate 7 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(5, 16);
        
        Creature f1 = Creature(&food, 0, 10, EAST);
        Creature r1 = Creature(&rover, 3, 3, NORTH);
        Creature h1 = Creature(&hopper, 3, 14, WEST);
        Creature t1 = Creature(&trap, 4, 4, SOUTH);
        Creature r2 = Creature(&rover, 4, 3, WEST);
        Creature f2 = Creature(&food, 2, 7, NORTH);

        d.place_creature(&f1, 0, 10);
        d.place_creature(&r1, 3, 3);
        d.place_creature(&h1, 3, 14);
        d.place_creature(&t1, 4, 4);
        d.place_creature(&r2, 4, 3);
        d.place_creature(&f2, 2, 7);

        d.print(cout, 0);
        for (int i = 1; i <= 7; ++i) {
            d.step();

            d.print(cout, i);
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
        /*
        6x6 Darwin
        Rover, facing east, at (0, 0);
        Rover, facing south, at (1, 1);
        Rover, facing south, at (2, 2);
        Rover, facing north, at (3, 3);
        Rover, facing north, at (4, 4);
        Simulate 5 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(6, 6);
        
		Creature r1 = Creature(&rover, 0, 0, EAST);
		Creature r2 = Creature(&rover, 1, 1, SOUTH);
		Creature r3 = Creature(&rover, 2, 2, SOUTH);
		Creature r4 = Creature(&rover, 3, 3, NORTH);
		Creature r5 = Creature(&rover, 4, 4, NORTH);
		
		d.place_creature(&r1, 0, 0);
		d.place_creature(&r2, 1, 1);
		d.place_creature(&r3, 2, 2);
		d.place_creature(&r4, 3, 3);
		d.place_creature(&r5, 4, 4);

        d.print(cout, 0);
        for (int i = 1; i <= 5; ++i) {
            d.step();

            d.print(cout, i);
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
        /*
        6x6 Darwin
        Rover, facing east, at (0, 0);
        Rover, facing south, at (1, 1);
        Rover, facing south, at (2, 2);
        Hopper, facing north, at (3, 3);
        Hopper, facing north, at (4, 4);
        Simulate 5 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(6, 6);
        
		Creature r1 = Creature(&rover, 0, 0, EAST);
		Creature r2 = Creature(&rover, 1, 1, SOUTH);
		Creature r3 = Creature(&rover, 2, 2, SOUTH);
		Creature h1 = Creature(&hopper, 3, 3, NORTH);
		Creature h2 = Creature(&hopper, 4, 4, NORTH);
		
		d.place_creature(&r1, 0, 0);
		d.place_creature(&r2, 1, 1);
		d.place_creature(&r3, 2, 2);
		d.place_creature(&h1, 3, 3);
		d.place_creature(&h2, 4, 4);

        d.print(cout, 0);
        for (int i = 1; i <= 5; ++i) {
            d.step();

            d.print(cout, i);
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
        /*
        6x6 Darwin
        Trap, facing east, at (0, 0);
        Rover, facing south, at (1, 1);
        Trap, facing south, at (2, 2);
        Rover, facing north, at (3, 3);
        Hopper, facing north, at (4, 4);
        Simulate 5 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(6, 6);
        
		Creature t1 = Creature(&trap, 0, 0, EAST);
		Creature r1 = Creature(&rover, 1, 1, SOUTH);
		Creature t2 = Creature(&trap, 2, 2, SOUTH);
		Creature r2 = Creature(&rover, 3, 3, NORTH);
		Creature h1 = Creature(&hopper, 4, 4, NORTH);
		
		d.place_creature(&t1, 0, 0);
		d.place_creature(&r1, 1, 1);
		d.place_creature(&t2, 2, 2);
		d.place_creature(&r2, 3, 3);
		d.place_creature(&h1, 4, 4);

        d.print(cout, 0);
        for (int i = 1; i <= 5; ++i) {
            d.step();

            d.print(cout, i);
        }

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
        /*
        10x10 Darwin
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 100 (10x10), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        2 Food
        2 Hopper
        2 Rover
        2 Trap
        Simulate 10 moves.
        Print every grid.
        */
        // 0:west, 1:north, 2:east, 3:south.

        Darwin d = Darwin(10, 10);
        
		vector<Creature> creatures;
        
        
        // make food.
        for (int i = 0; i < 2; ++i) {
        	int position = rand() % 100;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&food, position / 10, position % 10, direction));
        }
        
        // make hopper.
        for (int i = 0; i < 2; ++i) {
        	int position = rand() % 100;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&hopper, position / 10, position % 10, direction));
        }
        
        // make rover.
        for (int i = 0; i < 2; ++i) {
        	int position = rand() % 100;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&rover, position / 10, position % 10, direction));
        }
        
        // make trap.
        for (int i = 0; i < 2; ++i) {
        	int position = rand() % 100;
        	int direction = rand() % 4;
        	creatures.push_back(Creature(&trap, position / 10, position % 10, direction));
        }
        
        // place all creatures on the board.
        for (int i = 0; i < (int)creatures.size(); ++i) {
        	Creature c = creatures[i];
        	pair<int, int> coordinates = c.get_coordinates();
        	d.place_creature(&creatures[i], coordinates.first, coordinates.second);
        }

        d.print(cout, 0);
        for (int i = 1; i <= 10; ++i) {
            d.step();

            d.print(cout, i);
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
