// -----------------------------
// projects/darwin/RunDarwin.c++
// CopyR (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunCollatz.c++ -o RunCollatz.c++.app
    % valgrind RunDarwin.c++.app &gt; RunDarwin.out

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
#include <iostream>
#include "Darwin.h"

// ----
// main
// ----

int main () {
	using namespace std;
	ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

	// -------
	// Food
	// -------

	std::vector<Instruction> fprogram;
	fprogram.push_back(Instruction(LEFT));
	fprogram.push_back(Instruction(GO, 0));

	Species food(fprogram);

	// -------
	// Hopper
	// -------

	std::vector<Instruction> hprogram;
	hprogram.push_back(Instruction(HOP));
	hprogram.push_back(Instruction(GO, 0));

	Species hopper(hprogram);

	// -------
	// Rover
	// -------

	std::vector<Instruction> rprogram;
	rprogram.push_back(Instruction(IF_ENEMY, 9));
	rprogram.push_back(Instruction(IF_EMPTY, 7));
	rprogram.push_back(Instruction(IF_RANDOM, 5));
	rprogram.push_back(Instruction(LEFT));
	rprogram.push_back(Instruction(GO, 0));
	rprogram.push_back(Instruction(RIGHT));
	rprogram.push_back(Instruction(GO, 0));
	rprogram.push_back(Instruction(HOP));
	rprogram.push_back(Instruction(GO, 0));
	rprogram.push_back(Instruction(INFECT));
	rprogram.push_back(Instruction(GO, 0));
	Species rover(rprogram);

	// -------
	// Trap
	// -------

	std::vector<Instruction> tprogram;
	tprogram.push_back(Instruction(IF_ENEMY, 3));
	tprogram.push_back(Instruction(LEFT));
	tprogram.push_back(Instruction(GO, 0));
	tprogram.push_back(Instruction(INFECT));
	tprogram.push_back(Instruction(GO, 0));

	Species trap(tprogram);

	// -------
	// Best
	// -------

	std::vector<Instruction> bprogram;
	bprogram.push_back(Instruction(IF_ENEMY, 6));
	bprogram.push_back(Instruction(IF_EMPTY, 4));
	bprogram.push_back(Instruction(LEFT));
	bprogram.push_back(Instruction(GO, 0));
	bprogram.push_back(Instruction(HOP));
	bprogram.push_back(Instruction(GO, 0));
	bprogram.push_back(Instruction(INFECT));
	bprogram.push_back(Instruction(GO, 1));

	Species best(bprogram);


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

	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&food, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 'f';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, SOUTH));
	s.r = 4;
	s.c = 4;
	s.direction = SOUTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&hopper, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'h';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = NORTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	// create board
	Board<8, 8> b(c, sv, 5);

	// run sim
	b.run_sim();
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
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&trap, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 2;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&rover, NORTH));
	s.r = 5;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'r';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&trap, WEST));
	s.r = 6;
	s.c = 8;
	s.direction = WEST;
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);

	// create board
	Board<7, 9> b(c, sv, 5);

	// run sim
	b.run_sim();

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
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	for (int x = 0; x < 10; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'f';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&food, s.direction));
	}

	for (int x = 10; x < 20; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'h';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&hopper, s.direction));
	}

	for (int x = 20; x < 30; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'r';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&rover, s.direction));
	}

	for (int x = 30; x < 40; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 't';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&trap, s.direction));
	}

	// create board
	Board<72, 72> b(c, sv, 1000);

	// run sim
	b.run_sim();
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
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	for (int x = 0; x < 10; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'f';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&food, s.direction));
	}

	for (int x = 10; x < 20; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'h';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&hopper, s.direction));
	}

	for (int x = 20; x < 30; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'r';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&rover, s.direction));
	}

	for (int x = 30; x < 40; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 't';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&trap, s.direction));
	}

	for (int x = 40; x < 50; ++x)
	{
		int random = rand() % 5184;
		s.r = random / 72;
		s.c = random % 72;
		s.direction = Direction(rand() % 4);
		s.name = 'b';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&best, s.direction));
	}

	// create board
	Board<72, 72> b(c, sv, 1000);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 5 x 5
    // ------------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&trap, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, EAST));
	s.r = 4;
	s.c = 4;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 4;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&trap, WEST));
	s.r = 4;
	s.c = 0;
	s.direction = WEST;
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&hopper, WEST));
	s.r = 1;
	s.c = 1;
	s.direction = WEST;
	s.name = 'h';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&hopper, SOUTH));
	s.r = 3;
	s.c = 3;
	s.direction = SOUTH;
	s.name = 'h';
	s.cidx = 5;
	sv.push_back(s);

	// create board
	Board<5, 5> b(c, sv, 6);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 3 x 3
    // ------------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&trap, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 1;
	s.c = 2;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&food, EAST));
	s.r = 2;
	s.c = 0;
	s.direction = EAST;
	s.name = 'f';
	s.cidx = 2;
	sv.push_back(s);

	// create board
	Board<3, 3> b(c, sv, 7);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // darwin 15 x 15
    // --------------

    try {
        cout << "*** Darwin 15x15 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = (rand() % 225) / 15;
	s.c = (rand() % 225) % 15;
	s.direction = Direction(rand() % 4);
	s.name = 'f';
	s.cidx = 0;
	sv.push_back(s);
	c.push_back(Creature(&food, s.direction));

	s.r = (rand() % 225) / 15;
	s.c = (rand() % 225) % 15;
	s.direction = Direction(rand() % 4);
	s.name = 'h';
	s.cidx = 1;
	sv.push_back(s);
	c.push_back(Creature(&hopper, s.direction));

	s.r = (rand() % 225) / 15;
	s.c = (rand() % 225) % 15;
	s.direction = Direction(rand() % 4);
	s.name = 'r';
	s.cidx = 2;
	sv.push_back(s);
	c.push_back(Creature(&rover, s.direction));


	s.r = (rand() % 225) / 15;
	s.c = (rand() % 225) % 15;
	s.direction = Direction(rand() % 4);
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);
	c.push_back(Creature(&trap, s.direction));

	for (int x = 4; x < 6; ++x)
	{
		s.r = (rand() % 225) / 15;
		s.c = (rand() % 225) % 15;
		s.direction = Direction(rand() % 4);
		s.name = 'b';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&best, s.direction));
	}

	// create board
	Board<15, 15> b(c, sv, 15);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 1 x 1
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&rover, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 'r';
	s.cidx = 0;
	sv.push_back(s);

	// create board
	Board<1, 1> b(c, sv, 2);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // darwin 10 x 10
    // --------------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	for (int x = 0; x < 5; ++x)
	{
		s.r = (rand() % 100) / 10;
		s.c = (rand() % 100) % 10;
		s.direction = Direction(rand() % 4);
		s.name = 'r';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&rover, s.direction));
	}

	for (int x = 5; x < 10; ++x)
	{
		s.r = (rand() % 100) / 10;
		s.c = (rand() % 100) % 10;
		s.direction = Direction(rand() % 4);
		s.name = 'b';
		s.cidx = x;
		sv.push_back(s);
		c.push_back(Creature(&best, s.direction));
	}

	// create board
	Board<10, 10> b(c, sv, 20);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 2 x 3
    // ------------

    try {
        cout << "*** Darwin 2x3 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&best, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 'b';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 2;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 1;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 2;
	sv.push_back(s);

	// create board
	Board<2, 3> b(c, sv, 10);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 5 x 3
    // ------------

    try {
        cout << "*** Darwin 5x3 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&food, SOUTH));
	s.r = 0;
	s.c = 1;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&food, EAST));
	s.r = 4;
	s.c = 2;
	s.direction = EAST;
	s.name = 'f';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 0;
	s.c = 2;
	s.direction = NORTH;
	s.name = 'f';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&trap, WEST));
	s.r = 3;
	s.c = 0;
	s.direction = WEST;
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&best, SOUTH));
	s.r = 1;
	s.c = 1;
	s.direction = SOUTH;
	s.name = 'b';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 2;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 5;
	sv.push_back(s);

	// create board
	Board<5, 3> b(c, sv, 7);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 7 x 7
    // ------------

    try {
        cout << "*** Darwin 7x7 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&food, SOUTH));
	s.r = 0;
	s.c = 1;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&best, EAST));
	s.r = 4;
	s.c = 2;
	s.direction = EAST;
	s.name = 'b';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&rover, NORTH));
	s.r = 0;
	s.c = 2;
	s.direction = NORTH;
	s.name = 'r';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, WEST));
	s.r = 3;
	s.c = 2;
	s.direction = WEST;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	// create board
	Board<7, 7> b(c, sv, 5);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -------------
    // darwin 10 x 3
    // -------------

    try {
        cout << "*** Darwin 10x3 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&trap, SOUTH));
	s.r = 0;
	s.c = 0;
	s.direction = SOUTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, EAST));
	s.r = 4;
	s.c = 2;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 1;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&trap, WEST));
	s.r = 9;
	s.c = 0;
	s.direction = WEST;
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&hopper, WEST));
	s.r = 3;
	s.c = 1;
	s.direction = WEST;
	s.name = 'h';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 0;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 5;
	sv.push_back(s);

	c.push_back(Creature(&hopper, SOUTH));
	s.r = 6;
	s.c = 2;
	s.direction = SOUTH;
	s.name = 'h';
	s.cidx = 6;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 7;
	s.c = 0;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 7;
	sv.push_back(s);

	c.push_back(Creature(&best, EAST));
	s.r = 9;
	s.c = 1;
	s.direction = EAST;
	s.name = 'b';
	s.cidx = 8;
	sv.push_back(s);

	// create board
	Board<10, 3> b(c, sv, 11);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 5 x 5
    // ------------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	c.push_back(Creature(&best, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 'b';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 1;
	s.c = 1;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&trap, SOUTH));
	s.r = 0;
	s.c = 1;
	s.direction = SOUTH;
	s.name = 't';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&trap, EAST));
	s.r = 1;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 3;
	sv.push_back(s);

	// create board
	Board<2, 2> b(c, sv, 4);

	// run sim
	b.run_sim();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
