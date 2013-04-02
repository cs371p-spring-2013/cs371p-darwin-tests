/*	
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/
// --------
// defines
// --------

#define private public
// --------
// includes
// --------

#include <iostream>  // ios_base
#include <sstream>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#include "Darwin.h"
// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {


    // --------------
    // test_execute_1
    // --------------
    void test_execute_1()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	int temp = WALL;
	CPPUNIT_ASSERT(b1._creatures[0].execute(temp) == NORTH);
    }

    // --------------
    // test_execute_2
    // --------------
    void test_execute_2()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	int temp = EMPTY;
	CPPUNIT_ASSERT(b1._creatures[1].execute(temp) == HOP);
    }

    // --------------
    // test_execute_3
    // --------------
    void test_execute_3()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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
    	// Trap
    	// -------

    	std::vector<Instruction> tprogram;
    	tprogram.push_back(Instruction(IF_ENEMY, 3));
    	tprogram.push_back(Instruction(LEFT));
    	tprogram.push_back(Instruction(GO, 0));
    	tprogram.push_back(Instruction(INFECT));
    	tprogram.push_back(Instruction(GO, 0));

    	Species trap(tprogram);

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
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
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	int temp = FOE;
	CPPUNIT_ASSERT(b1._creatures[0].execute(temp) == INFECT);
    }

    // -------------
    // test_infect_1
    // -------------
    void test_infect_1()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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
    	// Trap
    	// -------

    	std::vector<Instruction> tprogram;
    	tprogram.push_back(Instruction(IF_ENEMY, 3));
    	tprogram.push_back(Instruction(LEFT));
    	tprogram.push_back(Instruction(GO, 0));
    	tprogram.push_back(Instruction(INFECT));
    	tprogram.push_back(Instruction(GO, 0));

    	Species trap(tprogram);

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1._creatures[0].infect(b1._creatures[2]));
    }

    // -------------
    // test_infect_2
    // -------------
    void test_infect_2()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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
    	// Trap
    	// -------

    	std::vector<Instruction> tprogram;
    	tprogram.push_back(Instruction(IF_ENEMY, 3));
    	tprogram.push_back(Instruction(LEFT));
    	tprogram.push_back(Instruction(GO, 0));
    	tprogram.push_back(Instruction(INFECT));
    	tprogram.push_back(Instruction(GO, 0));

    	Species trap(tprogram);

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1._creatures[0].infect(b1._creatures[5]));
    }

    // -------------
    // test_infect_3
    // -------------
    void test_infect_3()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1._creatures[4].infect(b1._creatures[0]));
    }

    // -------------------
    // test_init_display_1
    // -------------------
    void test_init_display_1()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	// -------
    	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);

	c.push_back(Creature(&food, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 'f';
	s.cidx = 0;
	sv.push_back(s);

	char temp[2][2] = {{'f', '.'}, {'.', '.'}};

	Board<2, 2> b1(c, sv, 5);

	b1.init_display();
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			CPPUNIT_ASSERT(temp[i][j] == b1._display[i][j]);
    }

    // -------------------
    // test_init_display_2
    // -------------------
    void test_init_display_2()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	std::vector<State> sv;

	char temp[2][2] = {{'.', '.'}, {'.', '.'}};

	Board<2, 2> b1(c, sv, 5);

	b1.init_display();
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			CPPUNIT_ASSERT(temp[i][j] == b1._display[i][j]);
    }

    // -------------------
    // test_init_display_3
    // -------------------
    void test_init_display_3()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	// -------
    	// Hopper
    	// -------

    	std::vector<Instruction> hprogram;
    	hprogram.push_back(Instruction(HOP));
    	hprogram.push_back(Instruction(GO, 0));

    	Species hopper(hprogram);

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

	c.push_back(Creature(&hopper, EAST));
	s.r = 1;
	s.c = 2;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, EAST));
	s.r = 2;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	char temp[3][3] = {{'.', '.', '.'}, 
			   {'.', '.', 'h'},
			   {'t', '.', '.'}};

	Board<3, 3> b1(c, sv, 5);

	b1.init_display();
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			CPPUNIT_ASSERT(temp[i][j] == b1._display[i][j]);
    }

    // --------------------
    // test_state_compare_1
    // --------------------
    void test_state_compare_1()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1.state_compare(sv[0], sv[1]));
    }

    // --------------------
    // test_state_compare_2
    // --------------------
    void test_state_compare_2()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(!(b1.state_compare(sv[3], sv[2])));
    }

    // --------------------
    // test_state_compare_3
    // --------------------
    void test_state_compare_3()
    {
	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1.state_compare(sv[2], sv[5]));
    }

    // --------------------
    // test_check_inFront_1
    // --------------------
    void test_check_inFront_1()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, EAST));
	s.r = 0;
	s.c = 0;
	s.direction = EAST;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1.check_inFront(sv[0]) == EMPTY);
    }

    // --------------------
    // test_check_inFront_2
    // --------------------
    void test_check_inFront_2()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
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

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1.check_inFront(sv[0]) == WALL);
    }

    // --------------------
    // test_check_inFront_3
    // --------------------
    void test_check_inFront_3()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	CPPUNIT_ASSERT(b1.check_inFront(sv[3]) == FRIEND);
    }

    // ---------------------
    // test_check_creature_1
    // ---------------------
    void test_check_creature_1()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();

	std::pair<int, int> temp (2, 2);
	CPPUNIT_ASSERT(std::get<0>(b1.check_creature(b1._state[3])) == std::get<0> (temp));
    }

    // ---------------------
    // test_check_creature_2
    // ---------------------
    void test_check_creature_2()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();

	std::pair<int, int> temp (2, 2);
	CPPUNIT_ASSERT(std::get<0>(b1.check_creature(b1._state[3])) == std::get<0> (temp));
    }

    // ---------------------
    // test_check_creature_3
    // ---------------------
    void test_check_creature_3()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();

	std::pair<int, int> temp (0, 0);
	CPPUNIT_ASSERT(!(std::get<0>(b1.check_creature(b1._state[0])) == std::get<0> (temp)));
    }

    // ----------------------
    // test_update_location_1
    // ----------------------
    void test_update_location_1()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_location(b1._state[2]);
	CPPUNIT_ASSERT(b1._state[2].c == 5);
    }

    // ----------------------
    // test_update_location_2
    // ----------------------
    void test_update_location_2()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_location(b1._state[2]);
	CPPUNIT_ASSERT(b1._display[3][4] == '.');
    }

    // ----------------------
    // test_update_location_3
    // ----------------------
    void test_update_location_3()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_location(b1._state[2]);
	CPPUNIT_ASSERT(b1._display[3][5] == 'h');
    }

    // ------------------
    // test_update_name_1
    // ------------------
    void test_update_name_1()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_name(b1._state[4], b1._state[5]);
	CPPUNIT_ASSERT(b1._state[4].name == b1._state[5].name);
    }

    // ------------------
    // test_update_name_2
    // ------------------
    void test_update_name_2()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_name(b1._state[4], b1._state[5]);
	CPPUNIT_ASSERT(b1._display[b1._state[4].r][b1._state[4].c] == b1._display[b1._state[5].r][b1._state[5].c]);
    }

    // ------------------
    // test_update_name_3
    // ------------------
    void test_update_name_3()
    {
    	// create creatures and state vector
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

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

	c.push_back(Creature(&trap, NORTH));
	s.r = 0;
	s.c = 0;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 0;
	sv.push_back(s);

	c.push_back(Creature(&trap, NORTH));
	s.r = 3;
	s.c = 3;
	s.direction = NORTH;
	s.name = 't';
	s.cidx = 1;
	sv.push_back(s);

	c.push_back(Creature(&hopper, EAST));
	s.r = 3;
	s.c = 4;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 2;
	sv.push_back(s);

	c.push_back(Creature(&hopper, NORTH));
	s.r = 4;
	s.c = 4;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 3;
	sv.push_back(s);

	c.push_back(Creature(&rover, WEST));
	s.r = 4;
	s.c = 3;
	s.direction = WEST;
	s.name = 'r';
	s.cidx = 4;
	sv.push_back(s);

	c.push_back(Creature(&food, NORTH));
	s.r = 7;
	s.c = 7;
	s.direction = SOUTH;
	s.name = 'f';
	s.cidx = 5;
	sv.push_back(s);

	Board<8, 8> b1(c, sv, 5);

	b1.init_display();
	b1.update_name(b1._state[0], b1._state[2]);
	CPPUNIT_ASSERT(b1._state[0].name == b1._state[2].name);
    }

    // ------------------------------
    // test_Instruction_Constructor_1
    // -------------------------------
    void test_Instruction_Constructor_1()
    {
	Instruction x = Instruction();
	CPPUNIT_ASSERT(x._opcode == GO);
	CPPUNIT_ASSERT(x._target == -1);
    }

    // -------------------------------
    // test_Instruction_Constructor_2
    // -------------------------------
    void test_Instruction_Constructor_2()
    {
	Instruction x(IF_EMPTY, 3);
	CPPUNIT_ASSERT(x._opcode == IF_EMPTY);
	CPPUNIT_ASSERT(x._target == 3);
    }

    // -------------------------------
    // test_Instruction_Constructor_3
    // -------------------------------
    void test_Instruction_Constructor_3()
    {
	Instruction x(INFECT);
	CPPUNIT_ASSERT(x._opcode == INFECT);
	CPPUNIT_ASSERT(x._target == -1);
    }

    // -------------------------------
    // test_Species_Constructor_1
    // -------------------------------
    void test_Species_Constructor_1()
    {
	Species r = Species();
	CPPUNIT_ASSERT(r._program.size() == 0);
    }

    // -------------------------------
    // test_Species_Constructor_2
    // -------------------------------
    void test_Species_Constructor_2()
    {
	// -------
   	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);
	CPPUNIT_ASSERT(food._program.size() == 2);
	CPPUNIT_ASSERT(food._program[0]._opcode == LEFT);
	CPPUNIT_ASSERT(food._program[0]._target == -1);
	CPPUNIT_ASSERT(food._program[1]._opcode == GO);
	CPPUNIT_ASSERT(food._program[1]._target == 0);
    }

    // -------------------------------
    // test_Instruction_Constructor_3
    // -------------------------------
    void test_Species_Constructor_3()
    {
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

	CPPUNIT_ASSERT(trap._program.size() == 5);
	CPPUNIT_ASSERT(trap._program[0]._opcode == IF_ENEMY);
	CPPUNIT_ASSERT(trap._program[0]._target == 3);
	CPPUNIT_ASSERT(trap._program[1]._opcode == LEFT);
	CPPUNIT_ASSERT(trap._program[1]._target == -1);
	CPPUNIT_ASSERT(trap._program[2]._opcode == GO);
	CPPUNIT_ASSERT(trap._program[2]._target == 0);
	CPPUNIT_ASSERT(trap._program[3]._opcode == INFECT);
	CPPUNIT_ASSERT(trap._program[3]._target == -1);
	CPPUNIT_ASSERT(trap._program[4]._opcode == GO);
	CPPUNIT_ASSERT(trap._program[4]._target == 0);
    }

    // -------------------------------
    // test_Creature_Constructor_1
    // -------------------------------
    void test_Creature_Constructor_1()
    {
	Creature x = Creature();
	CPPUNIT_ASSERT(x._species == NULL);
	CPPUNIT_ASSERT(x._direction == WEST);
	CPPUNIT_ASSERT(x._pc == 0);
    }  

    // -------------------------------
    // test_Creature_Constructor_2
    // -------------------------------
    void test_Creature_Constructor_2()
    {
	// -------
	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);

	Creature x = Creature(&food, EAST);
	CPPUNIT_ASSERT(x._species == &food);
	CPPUNIT_ASSERT(x._direction == EAST);
	CPPUNIT_ASSERT(x._pc == 0);
    }

    // -------------------------------
    // test_Creature_Constructor_3
    // -------------------------------
    void test_Creature_Constructor_3()
    {
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

	Creature x = Creature(&rover);
	CPPUNIT_ASSERT(x._species == &rover);
	CPPUNIT_ASSERT(x._direction == WEST);
	CPPUNIT_ASSERT(x._pc == 0);
    }

    // -------------------------------
    // test_Board_Constructor_1
    // -------------------------------
    void test_Board_Constructor_1()
    {
	// -------
    	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);
	
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	Board<1, 1> x(c, sv, 1);
	CPPUNIT_ASSERT(x._creatures.size() == 1);
	CPPUNIT_ASSERT(x._state.size() == 1);
	CPPUNIT_ASSERT(x._round == 1);
	CPPUNIT_ASSERT(x._display[0][0] == '.');
	CPPUNIT_ASSERT(x._state[0].r == 0);
	CPPUNIT_ASSERT(x._state[0].c == 0);
	CPPUNIT_ASSERT(x._state[0].direction == WEST);
	CPPUNIT_ASSERT(x._state[0].name == 'f');
	CPPUNIT_ASSERT(x._state[0].cidx == 0);
    }

    // -------------------------------
    // test_Board_Constructor_2
    // -------------------------------
    void test_Board_Constructor_2()
    {
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

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	s.r = 1;
	s.c = 1;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 1;
	c.push_back(Creature(&hopper, NORTH));
	sv.push_back(s);

	Board<2, 2> x(c, sv, 2);
	CPPUNIT_ASSERT(x._creatures.size() == 2);
	CPPUNIT_ASSERT(x._state.size() == 2);
	CPPUNIT_ASSERT(x._round == 2);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			CPPUNIT_ASSERT(x._display[i][j] == '.');

	CPPUNIT_ASSERT(x._state[0].r == 0);
	CPPUNIT_ASSERT(x._state[0].c == 0);
	CPPUNIT_ASSERT(x._state[0].direction == WEST);
	CPPUNIT_ASSERT(x._state[0].name == 'f');
	CPPUNIT_ASSERT(x._state[0].cidx == 0);

	CPPUNIT_ASSERT(x._state[1].r == 1);
	CPPUNIT_ASSERT(x._state[1].c == 1);
	CPPUNIT_ASSERT(x._state[1].direction == NORTH);
	CPPUNIT_ASSERT(x._state[1].name == 'h');
	CPPUNIT_ASSERT(x._state[1].cidx == 1);
    }

    // -------------------------------
    // test_Board_Constructor_3
    // -------------------------------
    void test_Board_Constructor_3()
    {
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

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	s.r = 1;
	s.c = 1;
	s.direction = NORTH;
	s.name = 'h';
	s.cidx = 1;
	c.push_back(Creature(&hopper, NORTH));
	sv.push_back(s);

	s.r = 2;
	s.c = 2;
	s.direction = SOUTH;
	s.name = 'h';
	s.cidx = 2;
	c.push_back(Creature(&hopper, SOUTH));
	sv.push_back(s);

	s.r = 3;
	s.c = 3;
	s.direction = EAST;
	s.name = 'h';
	s.cidx = 3;
	c.push_back(Creature(&hopper, EAST));
	sv.push_back(s);

	Board<5, 5> x(c, sv, 3);
	CPPUNIT_ASSERT(x._creatures.size() == 4);
	CPPUNIT_ASSERT(x._state.size() == 4);
	CPPUNIT_ASSERT(x._round == 3);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			CPPUNIT_ASSERT(x._display[i][j] == '.');

	CPPUNIT_ASSERT(x._state[0].r == 0);
	CPPUNIT_ASSERT(x._state[0].c == 0);
	CPPUNIT_ASSERT(x._state[0].direction == WEST);
	CPPUNIT_ASSERT(x._state[0].name == 'f');
	CPPUNIT_ASSERT(x._state[0].cidx == 0);

	CPPUNIT_ASSERT(x._state[1].r == 1);
	CPPUNIT_ASSERT(x._state[1].c == 1);
	CPPUNIT_ASSERT(x._state[1].direction == NORTH);
	CPPUNIT_ASSERT(x._state[1].name == 'h');
	CPPUNIT_ASSERT(x._state[1].cidx == 1);

	CPPUNIT_ASSERT(x._state[2].r == 2);
	CPPUNIT_ASSERT(x._state[2].c == 2);
	CPPUNIT_ASSERT(x._state[2].direction == SOUTH);
	CPPUNIT_ASSERT(x._state[2].name == 'h');
	CPPUNIT_ASSERT(x._state[2].cidx == 2);

	CPPUNIT_ASSERT(x._state[3].r == 3);
	CPPUNIT_ASSERT(x._state[3].c == 3);
	CPPUNIT_ASSERT(x._state[3].direction == EAST);
	CPPUNIT_ASSERT(x._state[3].name == 'h');
	CPPUNIT_ASSERT(x._state[3].cidx == 3);
    }

    // -------------------------------
    // test_print_display_1
    // -------------------------------
    void test_print_display_1()
    {
	// -------
	// Food
	// -------

	std::vector<Instruction> fprogram;
	fprogram.push_back(Instruction(LEFT));
	fprogram.push_back(Instruction(GO, 0));

	Species food(fprogram);

	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	Board<1, 1> x(c, sv, 1);

	std::ostringstream w1;
	std::ostringstream w2;

	x.print_display(0, w1);
	w2 << "Turn = " << 0 << "." << std::endl << " ";
	w2 << "0" << std::endl << "0";
	w2 << "." << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());
    }

   // -------------------------------
   // test_print_display_2
   // -------------------------------
   void test_print_display_2()
   {
	// -------
    	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);
	
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	Board<2, 2> x(c, sv, 1);
	x.init_display();
	std::ostringstream w1;
	std::ostringstream w2;

	x.print_display(0, w1);
	w2 << "Turn = " << 0 << "." << std::endl;
	w2 << " 01" << std::endl;
	w2 << "0f." << std::endl;
	w2 << "1.." << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());	
   }

   // -------------------------------
   // test_print_display_3
   // -------------------------------
   void test_print_display_3()
   {
	// -------
    	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);
	
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	s.r = 2;
	s.c = 3;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 1;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	Board<3, 4> x(c, sv, 1);
	x.init_display();
	std::ostringstream w1;
	std::ostringstream w2;

	x.print_display(0, w1);
	w2 << "Turn = " << 0 << "." << std::endl;
	w2 << " 0123" << std::endl;
	w2 << "0f..." << std::endl;
	w2 << "1...." << std::endl;
	w2 << "2...f" << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());	
    }

   // -------------------------------
   // test_run_sim_1
   // -------------------------------
   void test_run_sim_1()
   {
	// -------
    	// Food
    	// -------

    	std::vector<Instruction> fprogram;
    	fprogram.push_back(Instruction(LEFT));
    	fprogram.push_back(Instruction(GO, 0));

    	Species food(fprogram);
	
	std::vector<Creature> c;
	struct State s;
	std::vector<State> sv;

	s.r = 0;
	s.c = 0;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 0;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	s.r = 2;
	s.c = 3;
	s.direction = WEST;
	s.name = 'f';
	s.cidx = 1;
	c.push_back(Creature(&food, WEST));
	sv.push_back(s);

	Board<3, 4> x(c, sv, 2);
	std::ostringstream w1;
	std::ostringstream w2;

	x.run_sim(w1);
	w2 << "Turn = " << 0 << "." << std::endl;
	w2 << " 0123" << std::endl;
	w2 << "0f..." << std::endl;
	w2 << "1...." << std::endl;
	w2 << "2...f" << std::endl << std::endl;

	w2 << "Turn = " << 1 << "." << std::endl;
	w2 << " 0123" << std::endl;
	w2 << "0f..." << std::endl;
	w2 << "1...." << std::endl;
	w2 << "2...f" << std::endl << std::endl;

	w2 << "Turn = " << 2 << "." << std::endl;
	w2 << " 0123" << std::endl;
	w2 << "0f..." << std::endl;
	w2 << "1...." << std::endl;
	w2 << "2...f" << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());	
    }

    // -------------------------------
    // test_run_sim_2
    // -------------------------------
    void test_run_sim_2()
    {
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

	Board<2, 2> x(c, sv, 3);
	std::ostringstream w1;
	std::ostringstream w2;

	x.run_sim(w1);
	w2 << "Turn = " << 0 << "." << std::endl;
	w2 << " 01" << std::endl;
	w2 << "0bt" << std::endl;
	w2 << "1tt" << std::endl << std::endl;

	w2 << "Turn = " << 1 << "." << std::endl;
	w2 << " 01" << std::endl;
	w2 << "0bt" << std::endl;
	w2 << "1tt" << std::endl << std::endl;

	w2 << "Turn = " << 2 << "." << std::endl;
	w2 << " 01" << std::endl;
	w2 << "0bt" << std::endl;
	w2 << "1tt" << std::endl << std::endl;

	w2 << "Turn = " << 3 << "." << std::endl;
	w2 << " 01" << std::endl;
	w2 << "0tt" << std::endl;
	w2 << "1tt" << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());	
    }

    // -------------------------------
    // test_run_sim_3
    // -------------------------------
    void test_run_sim_3()
    {
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

	Board<2, 3> x(c, sv, 6);

	std::ostringstream w1;
	std::ostringstream w2;

	x.run_sim(w1);
	w2 << "Turn = " << 0 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0btt" << std::endl;
	w2 << "1..." << std::endl << std::endl;

	w2 << "Turn = " << 1 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tt" << std::endl;
	w2 << "1b.." << std::endl << std::endl;

	w2 << "Turn = " << 2 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tt" << std::endl;
	w2 << "1b.." << std::endl << std::endl;

	w2 << "Turn = " << 3 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tt" << std::endl;
	w2 << "1.b." << std::endl << std::endl;

	w2 << "Turn = " << 4 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tt" << std::endl;
	w2 << "1..b" << std::endl << std::endl;

	w2 << "Turn = " << 5 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tt" << std::endl;
	w2 << "1..b" << std::endl << std::endl;

	w2 << "Turn = " << 6 << "." << std::endl;
	w2 << " 012" << std::endl;
	w2 << "0.tb" << std::endl;
	w2 << "1..b" << std::endl << std::endl;

	CPPUNIT_ASSERT(w1.str() == w2.str());	
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_execute_1);
    CPPUNIT_TEST(test_execute_2);
    CPPUNIT_TEST(test_execute_3);
    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);
    CPPUNIT_TEST(test_init_display_1);
    CPPUNIT_TEST(test_init_display_2);
    CPPUNIT_TEST(test_init_display_3);
    CPPUNIT_TEST(test_state_compare_1);
    CPPUNIT_TEST(test_state_compare_2);
    CPPUNIT_TEST(test_state_compare_3);
    CPPUNIT_TEST(test_check_inFront_1);
    CPPUNIT_TEST(test_check_inFront_2);
    CPPUNIT_TEST(test_check_inFront_3);
    CPPUNIT_TEST(test_check_creature_1);
    CPPUNIT_TEST(test_check_creature_2);
    CPPUNIT_TEST(test_check_creature_3);
    CPPUNIT_TEST(test_update_location_1);
    CPPUNIT_TEST(test_update_location_2);
    CPPUNIT_TEST(test_update_location_3);
    CPPUNIT_TEST(test_update_name_1);
    CPPUNIT_TEST(test_update_name_2);
    CPPUNIT_TEST(test_update_name_3);
    CPPUNIT_TEST(test_Instruction_Constructor_1);
    CPPUNIT_TEST(test_Instruction_Constructor_2);
    CPPUNIT_TEST(test_Instruction_Constructor_3);
    CPPUNIT_TEST(test_Species_Constructor_1);
    CPPUNIT_TEST(test_Species_Constructor_2);
    CPPUNIT_TEST(test_Species_Constructor_3);
    CPPUNIT_TEST(test_Creature_Constructor_1);
    CPPUNIT_TEST(test_Creature_Constructor_2);
    CPPUNIT_TEST(test_Creature_Constructor_3);
    CPPUNIT_TEST(test_Board_Constructor_1);
    CPPUNIT_TEST(test_Board_Constructor_2);
    CPPUNIT_TEST(test_Board_Constructor_3);
    CPPUNIT_TEST(test_print_display_1);
    CPPUNIT_TEST(test_print_display_2);
    CPPUNIT_TEST(test_print_display_3);
    CPPUNIT_TEST(test_run_sim_1);
    CPPUNIT_TEST(test_run_sim_2);
    CPPUNIT_TEST(test_run_sim_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite()); // uncomment!

    tr.run();

    cout << "Done." << endl;
    return 0;}
