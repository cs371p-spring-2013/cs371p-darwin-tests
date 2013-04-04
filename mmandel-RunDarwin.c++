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
    // darwin 8x8 - Acceptance test 1
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


	Game game = Game(8, 8);
	Species f("food");
	Species h("hopper");
	game.add_Creature(f, 1, 0, 0);
	game.add_Creature(h, 0, 3, 3);
	game.add_Creature(h, 1, 3, 4);
	game.add_Creature(h, 2, 4, 4);
	game.add_Creature(h, 3, 4, 3);
	game.add_Creature(f, 0, 7, 7);
	game.start_game(5, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9 - Acceptance test 2
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


	Game game = Game(7, 9);
	Species t("trap");
	Species h("hopper");
	Species r("rover");
	game.add_Creature(t, 2, 0, 0);
	game.add_Creature(h, 1, 3, 2);
	game.add_Creature(r, 0, 5, 4);
	game.add_Creature(t, 3, 6, 8);
	game.start_game(5, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 5x5 - Acceptance test 3
    // ----------

    try {
        cout << "*** Darwin 5x5 just rovers ***" << endl;
        srand(0);
        /*
        5x5 Darwin
        Rover,   facing south, at (0, 2)
        Rover, facing east,  at (2, 0)
        Rover,  facing north, at (2, 4)
        Rover,   facing west,  at (4, 2)
        Simulate 5 moves.
        Print every grid.
        */

	Game game = Game(5, 5);
	Species r("rover");
	game.add_Creature(r, 2, 0, 2);
	game.add_Creature(r, 1, 2, 0);
	game.add_Creature(r, 3, 2, 4);
	game.add_Creature(r, 0, 4, 2);
	game.start_game(5, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------
    // darwin 72x72 - Acceptance test 4
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


	Game game = Game(72, 72);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	game.start_game(1000, 100, cout);


        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72 - Acceptance test 5
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

	Game game = Game(72, 72);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	Species b("best");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(b, d, rando, c);
	}
	game.start_game(1000, 100, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------
    // darwin 72x72 - Acceptance test 6
    // without best
    // ------------

    //**Prints out the first 10 boards of the 72x72 case

    try {
        cout << "*** Darwin 72x72 without Best - 10 boards only ***" << endl;
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

	Game game = Game(72, 72);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 5184;
	  rando = pos / 72;
	  c = pos % 72;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	game.start_game(10, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 20x20 - Acceptance test 7
    // without best
    // ------------

    try {
        cout << "*** Darwin 20x20 without Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 400 (20x20), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        10 Best
        Simulate 100 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 10th grid.
        */

	Game game = Game(20, 20);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 6; ++i) {
	  pos = rand() % 400;
	  rando = pos / 20;
	  c = pos % 20;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 6; ++i) {
	  pos = rand() % 400;
	  rando = pos / 20;
	  c = pos % 20;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 6; ++i) {
	  pos = rand() % 400;
	  rando = pos / 20;
	  c = pos % 20;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 6; ++i) {
	  pos = rand() % 400;
	  rando = pos / 20;
	  c = pos % 20;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	game.start_game(100, 10, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------
    // darwin 10x10 - Acceptance test 8
    // with best
    // ------------

    try {
        cout << "*** Darwin 10x10 with Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 100 (10x10), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        10 Best
        Simulate 100 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 10th grid.
        */

	Game game = Game(10, 10);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	Species b("best");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 3; ++i) {
	  pos = rand() % 100;
	  rando = pos / 10;
	  c = pos % 10;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 3; ++i) {
	  pos = rand() % 100;
	  rando = pos / 10;
	  c = pos % 10;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 3; ++i) {
	  pos = rand() % 100;
	  rando = pos / 10;
	  c = pos % 10;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 3; ++i) {
	  pos = rand() % 100;
	  rando = pos / 10;
	  c = pos % 10;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	for (i = 0; i < 3; ++i) {
	  pos = rand() % 100;
	  rando = pos / 10;
	  c = pos % 10;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(b, d, rando, c);
	}
	game.start_game(100, 10, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------
    // darwin 5x5 - Acceptance test 9
    // without best
    // ------------

    try {
        cout << "*** Darwin 5x5 without Best ***" << endl;
        srand(0);	

        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 25 (5x5), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        Simulate 100 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 10th grid.
        */

	Game game = Game(5, 5);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 2; ++i) {
	  pos = rand() % 25;
	  rando = pos / 5;
	  c = pos % 5;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 2; ++i) {
	  pos = rand() % 25;
	  rando = pos / 5;
	  c = pos % 5;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 2; ++i) {
	  pos = rand() % 25;
	  rando = pos / 5;
	  c = pos % 5;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 2; ++i) {
	  pos = rand() % 25;
	  rando = pos / 5;
	  c = pos % 5;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	game.start_game(100, 10, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------
    // darwin 50x50 - Acceptance test 10
    // with best
    // ------------

    try {
        cout << "*** Darwin 50x50 with Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 2500 (50x50), and use that for the position
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

	Game game = Game(50, 50);
	Species f("food");
	Species h("hopper");
	Species r("rover");
	Species t("trap");
	Species b("best");
	int i = 0;
	int pos = 0;
	int rando = 0;
	int c = 0;
	int d = 0;

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 2500;
	  rando = pos / 50;
	  c = pos % 50;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(f, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 2500;
	  rando = pos / 50;
	  c = pos % 50;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(h, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 2500;
	  rando = pos / 50;
	  c = pos % 50;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(r, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 2500;
	  rando = pos / 50;
	  c = pos % 50;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(t, d, rando, c);
	}

	for (i = 0; i < 10; ++i) {
	  pos = rand() % 2500;
	  rando = pos / 50;
	  c = pos % 50;
	  d = rand() % 4;
	  if(d == 0)
		d = 3;
	  else 
		d -=1;
	  game.add_Creature(b, d, rando, c);
	}
	game.start_game(1000, 100, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 7x9 with Best - Acceptance test 11
    // ----------

    try {
        cout << "*** Darwin 7x9 with Best***" << endl;
        srand(0);
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Best,  facing north, at (5, 4)
        Simulate 5 moves.
        Print every grid.
        */

	Game game = Game(7, 9);
	Species t("trap");
	Species h("hopper");
	Species b("best");
	game.add_Creature(t, 2, 0, 0);
	game.add_Creature(h, 1, 3, 2);
	game.add_Creature(b, 0, 5, 4);
	game.start_game(5, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 4x6 with Best - Acceptance test 12
    // ----------

    try {
        cout << "*** Darwin 4x6 with Best***" << endl;
        srand(0);
        /*
        4x6 Darwin
        Food,   facing north, at (0, 0)
	Food,   facing south, at (0, 5)
	Food,   facing east, at (3, 0)
	Food,   facing west, at (3, 5)
        Best,  facing north, at (2, 3)
        Simulate 5 moves.
        Print every grid.
        */

	Game game = Game(4, 6);
	Species f("food");
	Species b("best");
	game.add_Creature(f, 0, 0, 0);
	game.add_Creature(f, 2, 0, 5);
	game.add_Creature(f, 1, 3, 0);
	game.add_Creature(f, 3, 3, 5);
	game.add_Creature(b, 0, 2, 3);
	game.start_game(20, 2, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 4x6 with Best - Acceptance test 13
    // ----------

    try {
        cout << "*** Darwin 4x6 with Best***" << endl;
        srand(0);
        /*
        7x9 Darwin
        Food,   facing north, at (0, 0)
	Trap,   facing south, at (0, 5)
	Trap,   facing east, at (3, 0)
	Rover,   facing west, at (3, 5)
        Best,  facing north, at (2, 3)
        Simulate 5 moves.
        Print every grid.
        */

	Game game = Game(4, 6);
	Species f("food");
	Species t("trap");
	Species r("rover");
	Species b("best");
	game.add_Creature(f, 0, 0, 0);
	game.add_Creature(t, 2, 0, 5);
	game.add_Creature(t, 1, 3, 0);
	game.add_Creature(r, 3, 3, 5);
	game.add_Creature(b, 0, 2, 3);
	game.start_game(20, 2, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 3x3 with Best - Acceptance test 14
    // ----------

    try {
        cout << "*** Darwin 3x3 with Best***" << endl;
        srand(0);
        /*
        7x9 Darwin
        Food,   facing north, at (0, 0)
        Food,   facing south, at (1, 1)
        Food,   facing north, at (2, 2)
	Trap,   facing south, at (0, 1)
	Trap,   facing east, at (1, 2)
	Rover,   facing east, at (1, 0)
	Rover,   facing north, at (2, 1)
        Best,  facing west, at (0, 2)
        Best,  facing north, at (2, 0)
        Simulate 5 moves.
        Print every grid.
        */

	Game game = Game(3, 3);
	Species f("food");
	Species t("trap");
	Species r("rover");
	Species b("best");
	game.add_Creature(f, 0, 0, 0);
	game.add_Creature(f, 2, 1, 1);
	game.add_Creature(f, 0, 2, 2);
	game.add_Creature(t, 2, 0, 1);
	game.add_Creature(t, 1, 1, 2);
	game.add_Creature(r, 1, 1, 0);
	game.add_Creature(r, 0, 2, 1);
	game.add_Creature(b, 3, 0, 2);
	game.add_Creature(b, 0, 2, 0);
	game.start_game(10, 1, cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
