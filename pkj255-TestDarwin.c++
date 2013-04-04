// ------------------------------------
// projects/allocator/TestDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// ------------------------------------



// --------
// includes
// --------


#include <algorithm> // count
#include "Darwin.h"
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner






struct TestDarwin : CppUnit::TestFixture {
	
	// -----
	// front
	// -----
	void test_front1()
	{
		int r = 1;
		int c = 1;
		int dir = WEST;
		front(r,c,dir);
		CPPUNIT_ASSERT(r == 1);
		CPPUNIT_ASSERT(c == 0);
		CPPUNIT_ASSERT(dir == WEST);
	}
	void test_front2()
	{
		int r = 1;
		int c = 1;
		int dir = NORTH;
		front(r,c,dir);
		CPPUNIT_ASSERT(r == 0);
		CPPUNIT_ASSERT(c == 1);
		CPPUNIT_ASSERT(dir == NORTH);
	}
	void test_front3()
	{
		int r = 1;
		int c = 1;
		int dir = EAST;
		front(r,c,dir);
		CPPUNIT_ASSERT(r == 1);
		CPPUNIT_ASSERT(c == 2);
		CPPUNIT_ASSERT(dir == EAST);
	}
	void test_front4()
	{
		int r = 1;
		int c = 1;
		int dir = SOUTH;
		front(r,c,dir);
		CPPUNIT_ASSERT(r == 2);
		CPPUNIT_ASSERT(c == 1);
		CPPUNIT_ASSERT(dir == SOUTH);
	}
	
	// -----
	// Instruction getInstr
	// -----
	
	void test_getInstr1()
	{
		Instruction i(0, 0);
		CPPUNIT_ASSERT(i.getInstr() == HOP);
	}

	void test_getInstr2()
	{
		Instruction i(0, 5);
		CPPUNIT_ASSERT(i.getInstr() == HOP);
	}

	void test_getInstr3()
	{
		Instruction i(5, 5);
		CPPUNIT_ASSERT(i.getInstr() == IF_WALL);
	}

	// -----
	// Instruction getLine
	// -----
	
	void test_getLine1()
	{
		Instruction i(0, 0);
		CPPUNIT_ASSERT(i.getLine() == 0);
	}

	void test_getLine2()
	{
		Instruction i(0, 5);
		CPPUNIT_ASSERT(i.getLine() == 5);
	}

	void test_getLine3()
	{
		Instruction i(5, 10);
		CPPUNIT_ASSERT(i.getLine() == 10);
	}

	// -----
	// Creature program
	// -----
	
	void test_program1()
	{
		Creature t = Creature(5, 5, WEST, 't');
		CPPUNIT_ASSERT(IF_ENEMY == t.program());
	}

	void test_program2()
	{
		Creature f = Creature(5, 5, WEST, 'f');
		CPPUNIT_ASSERT(LEFT == f.program());
	}

	void test_program3()
	{
		Creature h = Creature(5, 5, WEST, 'h');
		CPPUNIT_ASSERT(HOP == h.program());
	}
	
	// -----
	// Creature process
	// -----

	void test_process1()
	{
		Game x;
		stringstream w;
		Creature t = Creature(5, 5, WEST, 't');
		x.addCreature(5, 5, WEST, 't', t);
		CPPUNIT_ASSERT(IF_ENEMY == t.program());
		t.process(false);
		CPPUNIT_ASSERT(LEFT == t.program());
	}
	
	void test_process2()
	{
		Game x;
		stringstream w;
		Creature r = Creature(0, 0, WEST, 'r');
		x.addCreature(0, 0, WEST, 'r', r);
		CPPUNIT_ASSERT(IF_ENEMY == r.program());
		r.process(false);
		CPPUNIT_ASSERT(IF_EMPTY == r.program());
	
	}

	void test_process3()
	{
		Game x;
		stringstream w;
		Creature t = Creature(5, 5, WEST, 't');
		x.addCreature(5, 5, WEST, 't', t);
		Creature f = Creature(5, 4, WEST, 'f');
		x.addCreature(5, 4, WEST, 'f', f);
		CPPUNIT_ASSERT(IF_ENEMY == t.program());
		t.process(true);
		CPPUNIT_ASSERT(INFECT == t.program());
	}


	// -----
	// Game print
	// -----
	void test_GamePrint1()
	{
		Game x;
		stringstream w;
		x.print(w);
		string out = "\n*** Darwin 10x10 ***\nTurn = 0.\n  0123456789\n0 ..........\n1 ..........\n2 ..........\n3 ..........\n4 ..........\n5 ..........\n6 ..........\n7 ..........\n8 ..........\n9 ..........\n";

		CPPUNIT_ASSERT(w.str() == out );
	}
	
	void test_GamePrint2()
	{
		Game x(4, 5);
		stringstream w;
		string out = "\n*** Darwin 4x5 ***\nTurn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n";
		x.print(w);
		CPPUNIT_ASSERT(w.str() == out );

	}
	
	void test_GamePrint3()
	{
		Game x(1, 9);
		stringstream w;
		string out = "\n*** Darwin 1x9 ***\nTurn = 0.\n  012345678\n0 .........\n";
		
		x.print(w);
		CPPUNIT_ASSERT(w.str() == out );
	}
	void test_play1()
	{
		Game x(10, 10);
		stringstream w;
		Creature c = Creature(5, 5, WEST, 'h');
		x.addCreature(5, 5, WEST, 'h', c);
		x.play(6, 1, w);
	}
	void test_play2()
	{
		Game x(10, 10);
		stringstream w;
		Creature c = Creature(5, 5, WEST, 'h');
		x.addCreature(5, 5, WEST, 'h', c);
		x.play(100, 5, w);
	}
	void test_play3()
	{
		srand(0);
		Game x(20, 20);
		stringstream w;
		Creature c = Creature(10, 10, WEST, 'r');
		x.addCreature(10, 10, WEST, 'r', c);
		Creature d = Creature(10, 9, WEST, 'f');
		x.addCreature(10, 9, WEST, 'f', d);
		x.play(6, 1, w);
	}
	void test_play4()
	{
		srand(0);
		Game x(20, 20);
		stringstream w;
		Creature c = Creature(10, 10, WEST, 't');
		x.addCreature(10, 10, WEST, 't', c);
		Creature d = Creature(10, 9, WEST, 'f');
		x.addCreature(10, 9, WEST, 'f', d);
		Creature e = Creature(10, 8, WEST, 'f');
		x.addCreature(10, 8, WEST, 'f', e);
		x.play(15, 1, w);
	}
	
    // -----
    // suite
    // -----

	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_front1);
	CPPUNIT_TEST(test_front2);
	CPPUNIT_TEST(test_front3);
	CPPUNIT_TEST(test_front4);
	CPPUNIT_TEST(test_getInstr1);
	CPPUNIT_TEST(test_getInstr2);
	CPPUNIT_TEST(test_getInstr3);
	CPPUNIT_TEST(test_getLine1);
	CPPUNIT_TEST(test_getLine2);
	CPPUNIT_TEST(test_getLine3);
	CPPUNIT_TEST(test_program1);
	CPPUNIT_TEST(test_program2);
	CPPUNIT_TEST(test_program3);
	CPPUNIT_TEST(test_process1);
	CPPUNIT_TEST(test_process2);
	CPPUNIT_TEST(test_process3);
	CPPUNIT_TEST(test_GamePrint1);
	CPPUNIT_TEST(test_GamePrint2);
	CPPUNIT_TEST(test_GamePrint3);
	CPPUNIT_TEST(test_play1);
	CPPUNIT_TEST(test_play2);
	CPPUNIT_TEST(test_play3);
	CPPUNIT_TEST(test_play4);
	CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;


    tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;
}

