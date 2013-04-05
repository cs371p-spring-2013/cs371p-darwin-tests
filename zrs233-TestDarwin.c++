// --------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin -lcppunit -ldl
% valgrind TestDarwin >& TestDarwin.out
*/

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // stringstream

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

	void test_addCreature1() {
		Darwin game = Darwin(20, 20);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0) == true);
	}

	void test_addCreature2() {
		Darwin game = Darwin(20, 20);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0) == true);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0) == false);
	}

	void test_addCreature3() {
		Darwin game = Darwin(1, 1);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0) == true);
	}

	void test_addCreature4() {
		Darwin game = Darwin(20, 20);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0, 0) == true);
	}

	void test_addCreature5() {
		Darwin game = Darwin(20, 20);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0, 0) == true);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0, 0) == false);
	}

	void test_addCreature6() {
		Darwin game = Darwin(1, 1);
		CPPUNIT_ASSERT(game.addCreature(Species::best(), 0, 0, 0) == true);
	}

	void test_doTurn1() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		game.doTurn();
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\n");
	}

	void test_doTurn2() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		game.doTurn();
		game.doTurn();
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f.......\n1 ...h....\n2 ........\n3 ......h.\n4 .h......\n5 ........\n6 ....h...\n7 .......f\n\n");
	}

	void test_doTurn3() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		game.doTurn();
		game.doTurn();
		game.doTurn();
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n\n");
	}

	void test_printSimulation1() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		std::stringstream out;
		game.printSimulation(2, false, 1, out);
		std::string rout = "Turn = 1.\n  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\nTurn = 2.\n  01234567\n0 f.......\n1 ...h....\n2 ........\n3 ......h.\n4 .h......\n5 ........\n6 ....h...\n7 .......f\n\n";
		std::string got = out.str();
		out.flush();
		CPPUNIT_ASSERT(rout == got);
	}

	void test_printSimulation2() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		std::stringstream out;
		game.printSimulation(1, false, 1, out);
		std::string rout = "Turn = 1.\n  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\n";
		CPPUNIT_ASSERT(out.str() == rout);
	}

	void test_printSimulation3() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		std::stringstream out;
		game.printSimulation(3, false, 1, out);
		std::string rout = "Turn = 1.\n  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\nTurn = 2.\n  01234567\n0 f.......\n1 ...h....\n2 ........\n3 ......h.\n4 .h......\n5 ........\n6 ....h...\n7 .......f\n\nTurn = 3.\n  01234567\n0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n\n";
		CPPUNIT_ASSERT(out.str() == rout);
	}

	void test_printBoard1() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f.......\n1 ........\n2 ........\n3 ...hh...\n4 ...hh...\n5 ........\n6 ........\n7 .......f\n\n");
	}

	void test_printBoard2() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		game.doTurn();
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f.......\n1 ........\n2 ...h....\n3 .....h..\n4 ..h.....\n5 ....h...\n6 ........\n7 .......f\n\n");
	}

	void test_printBoard3() {
		Darwin game(8, 8);
		game.addCreature(Species::food(), EAST, 0, 0);
		game.addCreature(Species::hopper(), NORTH, 3, 3);
		game.addCreature(Species::hopper(), EAST, 3, 4);
		game.addCreature(Species::hopper(), SOUTH, 4, 4);
		game.addCreature(Species::hopper(), WEST, 4, 3);
		game.addCreature(Species::food(), NORTH, 7, 7);
		game.doTurn();
		game.doTurn();
		std::stringstream out;
		game.printBoard(out);
		CPPUNIT_ASSERT(out.str() == "  01234567\n0 f.......\n1 ...h....\n2 ........\n3 ......h.\n4 .h......\n5 ........\n6 ....h...\n7 .......f\n\n");
	}

	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_addCreature1);
	CPPUNIT_TEST(test_addCreature2);
	CPPUNIT_TEST(test_addCreature3);
	CPPUNIT_TEST(test_addCreature4);
	CPPUNIT_TEST(test_addCreature5);
	CPPUNIT_TEST(test_addCreature6);
	CPPUNIT_TEST(test_doTurn1);
	CPPUNIT_TEST(test_doTurn2);
	CPPUNIT_TEST(test_doTurn3);
	CPPUNIT_TEST(test_printSimulation1);
	CPPUNIT_TEST(test_printSimulation2);
	CPPUNIT_TEST(test_printSimulation3);
	CPPUNIT_TEST(test_printBoard1);
	CPPUNIT_TEST(test_printBoard2);
	CPPUNIT_TEST(test_printBoard3);
	CPPUNIT_TEST_SUITE_END();
    
};

struct TestBoard : CppUnit::TestFixture {

	// bool addCreature(int, int)
	void test_addCreature1() {
		Board b = Board(20, 20);
		CPPUNIT_ASSERT(b.addCreature(0, 0) == true);
	}

	void test_addCreature2() {
		Board b = Board(20, 20);
		CPPUNIT_ASSERT(b.addCreature(0, 0) == true);
		CPPUNIT_ASSERT(b.addCreature(0, 0) == false);
	}

	void test_addCreature3() {
		Board b = Board(0, 0);
		CPPUNIT_ASSERT(b.addCreature(0, 0) == false);
	}

	// bool hop(int)
	void test_hop1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.hop(0) == true);
	}

	void test_hop2() {
		Board b = Board(20, 20);
		b.addCreature(0, 1);
		CPPUNIT_ASSERT(b.hop(0) == false);
	}

	void test_hop3() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		b.addCreature(1, 0);
		CPPUNIT_ASSERT(b.hop(0) == false);
	}

	// bool turnLeft(int);
	void test_turnLeft1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.turnLeft(0) == true);
	}

	void test_turnLeft2() {
		Board b = Board(20, 20);
		b.addCreature(0, 1);
		CPPUNIT_ASSERT(b.turnLeft(1) == false);
	}

	void test_turnLeft3() {
		Board b = Board(2, 2);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.turnLeft(10) == false);
	}

	// bool turnRight(int);
	void test_turnRight1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.turnRight(0) == true);
	}

	void test_turnRight2() {
		Board b = Board(20, 20);
		b.addCreature(0, 1);
		CPPUNIT_ASSERT(b.turnRight(1) == false);
	}

	void test_turnRight3() {
		Board b = Board(2, 2);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.turnRight(10) == false);
	}

	// bool if_empty(int) const;
	void test_if_empty1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.if_empty(0) == true);
	}

	void test_if_empty2() {
		Board b = Board(20, 20);
		b.addCreature(0, 1);
		CPPUNIT_ASSERT(b.if_empty(0) == false);
	}

	void test_if_empty3() {
		Board b = Board(2, 2);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.if_empty(10) == false);
	}

	// bool if_enemy(int) const;
	void test_if_enemy1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.if_enemy(0) == false);
	}

	void test_if_enemy2() {
		Board b = Board(2, 2);
		b.addCreature(0, 3);
		b.addCreature(2, 1);
		CPPUNIT_ASSERT(b.if_enemy(0) == true);
	}

	void test_if_enemy3() {
		Board b = Board(1, 1);
		b.addCreature(0, 0);
		CPPUNIT_ASSERT(b.if_enemy(0) == false);
	}

	// bool if_wall(int) const;
	void test_if_wall1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.if_wall(0) == false);
	}

	void test_if_wall2() {
		Board b = Board(2, 2);
		b.addCreature(0, 3);
		b.addCreature(2, 1);
		CPPUNIT_ASSERT(b.if_wall(0) == false);
	}

	void test_if_wall3() {
		Board b = Board(2, 2);
		b.addCreature(0, 0);
		CPPUNIT_ASSERT(b.if_wall(0) == true);
	}

	// bool isPosInvalid(int) const;
	void test_isPosInvalid1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.isPosInvalid(0) == false);
	}

	void test_isPosInvalid2() {
		Board b = Board(2, 2);
		b.addCreature(0, 3);
		CPPUNIT_ASSERT(b.isPosInvalid(4) == true);
	}

	void test_isPosInvalid3() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.isPosInvalid(0) == false);
	}

	// bool getPosInFront(int) const;
	void test_getPosInFront1() {
		Board b = Board(20, 20);
		b.addCreature(0, 2);
		CPPUNIT_ASSERT(b.getPosInFront(0) == 1);
	}

	void test_getPosInFront2() {
		Board b = Board(2, 2);
		b.addCreature(0, 3);
		CPPUNIT_ASSERT(b.getPosInFront(0) == 2);
	}

	void test_getPosInFront3() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getPosInFront(-1) == -1);
	}

	// int getRow(int) const;
	void test_getRow1() {
		Board b = Board(20, 20);
		CPPUNIT_ASSERT(b.getRow(0) == 0);
	}

	void test_getRow2() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getRow(2) == 1);
	}

	void test_getRow3() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getRow(-1) == -1);
	}

	// int getCol(int) const;
	void test_getCol1() {
		Board b = Board(20, 20);
		CPPUNIT_ASSERT(b.getCol(0) == 0);
	}

	void test_getCol2() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getCol(3) == 1);
	}

	void test_getCol3() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getCol(-1) == -1);
	}

	// int getPos(int, int) const;
	void test_getPos1() {
		Board b = Board(20, 20);
		CPPUNIT_ASSERT(b.getPos(0, 4) == 4);
	}

	void test_getPos2() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getPos(1, 1) == 3);
	}

	void test_getPos3() {
		Board b = Board(2, 2);
		CPPUNIT_ASSERT(b.getPos(-1, 1) == -1);
	}

	CPPUNIT_TEST_SUITE(TestBoard);
	CPPUNIT_TEST(test_addCreature1);
	CPPUNIT_TEST(test_addCreature2);
	CPPUNIT_TEST(test_addCreature3);
	CPPUNIT_TEST(test_hop1);
	CPPUNIT_TEST(test_hop2);
	CPPUNIT_TEST(test_hop3);
	CPPUNIT_TEST(test_turnLeft1);
	CPPUNIT_TEST(test_turnLeft2);
	CPPUNIT_TEST(test_turnLeft3);
	CPPUNIT_TEST(test_turnRight1);
	CPPUNIT_TEST(test_turnRight2);
	CPPUNIT_TEST(test_turnRight3);
	CPPUNIT_TEST(test_if_empty1);
	CPPUNIT_TEST(test_if_empty2);
	CPPUNIT_TEST(test_if_empty3);
	CPPUNIT_TEST(test_if_enemy1);
	CPPUNIT_TEST(test_if_enemy2);
	CPPUNIT_TEST(test_if_enemy3);
	CPPUNIT_TEST(test_if_wall1);
	CPPUNIT_TEST(test_if_wall2);
	CPPUNIT_TEST(test_if_wall3);
	CPPUNIT_TEST(test_isPosInvalid1);
	CPPUNIT_TEST(test_isPosInvalid2);
	CPPUNIT_TEST(test_isPosInvalid3);
	CPPUNIT_TEST(test_getPosInFront1);
	CPPUNIT_TEST(test_getPosInFront2);
	CPPUNIT_TEST(test_getPosInFront3);
	CPPUNIT_TEST(test_getRow1);
	CPPUNIT_TEST(test_getRow2);
	CPPUNIT_TEST(test_getRow3);
	CPPUNIT_TEST(test_getCol1);
	CPPUNIT_TEST(test_getCol2);
	CPPUNIT_TEST(test_getCol3);
	CPPUNIT_TEST(test_getPos1);
	CPPUNIT_TEST(test_getPos2);
	CPPUNIT_TEST(test_getPos3);
	CPPUNIT_TEST_SUITE_END();
};

struct TestInstruction : CppUnit::TestFixture {

	// int run() const;
	void test_run1() {
		Instruction i = Instruction(HOP);
		CPPUNIT_ASSERT(i.run() == HOP);
	}

	void test_run2() {
		Instruction i = Instruction(GO, 20);
		CPPUNIT_ASSERT(i.run() == GO);
	}

	void test_run3() {
		Instruction i = Instruction(LEFT);
		CPPUNIT_ASSERT(i.run() == LEFT);
		i = Instruction(RIGHT);
		CPPUNIT_ASSERT(i.run() == RIGHT);
		i = Instruction(INFECT);
		CPPUNIT_ASSERT(i.run() == INFECT);
		i = Instruction(IF_EMPTY, 0);
		CPPUNIT_ASSERT(i.run() == IF_EMPTY);
		i = Instruction(IF_WALL, 0);
		CPPUNIT_ASSERT(i.run() == IF_WALL);
		i = Instruction(IF_ENEMY, 0);
		CPPUNIT_ASSERT(i.run() == IF_ENEMY);
	}

	// bool isAction() const;
	void test_isAction1() {
		Instruction i = Instruction(HOP);
		CPPUNIT_ASSERT(i.isAction() == true);
	}

	void test_isAction2() {
		Instruction i = Instruction(GO, 20);
		CPPUNIT_ASSERT(i.isAction() == false);
	}

	void test_isAction3() {
		Instruction i = Instruction(LEFT);
		CPPUNIT_ASSERT(i.isAction() == true);
		i = Instruction(RIGHT);
		CPPUNIT_ASSERT(i.isAction() == true);
		i = Instruction(INFECT);
		CPPUNIT_ASSERT(i.isAction() == true);
		i = Instruction(IF_EMPTY, 0);
		CPPUNIT_ASSERT(i.isAction() == false);
		i = Instruction(IF_WALL, 0);
		CPPUNIT_ASSERT(i.isAction() == false);
		i = Instruction(IF_ENEMY, 0);
		CPPUNIT_ASSERT(i.isAction() == false);
	}

	// int lineNumber() const;
	void test_lineNumber1() {
		Instruction i = Instruction(GO, 0);
		CPPUNIT_ASSERT(i.lineNumber() == 0);
	}

	void test_lineNumber2() {
		Instruction i = Instruction(GO, 20);
		CPPUNIT_ASSERT(i.lineNumber() == 20);
	}

	void test_lineNumber3() {
		Instruction i = Instruction(IF_EMPTY, 1000);
		CPPUNIT_ASSERT(i.lineNumber() == 1000);
		i = Instruction(IF_WALL, 1);
		CPPUNIT_ASSERT(i.lineNumber() == 1);
		i = Instruction(IF_ENEMY, 10);
		CPPUNIT_ASSERT(i.lineNumber() == 10);
	}

	CPPUNIT_TEST_SUITE(TestInstruction);
	CPPUNIT_TEST(test_run1);
	CPPUNIT_TEST(test_run2);
	CPPUNIT_TEST(test_run3);
	CPPUNIT_TEST(test_isAction1);
	CPPUNIT_TEST(test_isAction2);
	CPPUNIT_TEST(test_isAction3);
	CPPUNIT_TEST(test_lineNumber1);
	CPPUNIT_TEST(test_lineNumber2);
	CPPUNIT_TEST(test_lineNumber3);
	CPPUNIT_TEST_SUITE_END();
    
};

struct TestCreature : CppUnit::TestFixture {

	// Instruction takeTurn(const Board&, int);
	void test_takeTurn1() {
		Creature c(Species::food());
		std::vector<Creature> list = std::vector<Creature>(1);
		list[0] = c;
		Board b(2, 2);
		b.addCreature(0, 1);
		Instruction i = c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(i.run() == LEFT);
	}

	void test_takeTurn2() {
		Creature c(Species::hopper());
		std::vector<Creature> list = std::vector<Creature>(1);
		list[0] = c;
		Board b(2, 2);
		b.addCreature(1, 3);
		Instruction i = c.takeTurn(b, 1, list);
		CPPUNIT_ASSERT(i.run() == HOP);
	}

	void test_takeTurn3() {
		Creature c(Species::trap());
		Creature d(Species::trap());
		std::vector<Creature> list = std::vector<Creature>(2);
		list[0] = c;
		list[1] = d;
		Board b(2, 2);
		b.addCreature(0, 2);
		b.addCreature(1, 1);
		Instruction i = c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(i.run() != INFECT);
	}

	// void infect(Creature&);
	void test_infect1() {
		Creature c(Species::food());
		std::vector<Creature> list = std::vector<Creature>(1);
		list[0] = c;
		Board b(2, 2);
		b.addCreature(0, 1);
		Instruction i = c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(i.run() != INFECT);
	}

	void test_infect2() {
		Creature c(Species::trap());
		Creature d(Species::trap());
		std::vector<Creature> list = std::vector<Creature>(2);
		list[0] = c;
		list[1] = d;
		Board b(2, 2);
		b.addCreature(0, 2);
		b.addCreature(1, 1);
		Instruction i = c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(i.run() != INFECT);
	}

	void test_infect3() {
		Creature c(Species::trap());
		Creature d(Species::trap());
		std::vector<Creature> list = std::vector<Creature>(2);
		list[0] = c;
		list[1] = d;
		Board b(2, 2);
		b.addCreature(0, 1);
		b.addCreature(1, 1);
		Instruction i = c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(i.run() != INFECT);
	}

	// bool exists() const;
	void test_exists1() {
		Creature c(Species::food());
		CPPUNIT_ASSERT(c.exists() == true);
	}

	void test_exists2() {
		Creature c(Species::trap());
		CPPUNIT_ASSERT(c.exists() == true);
	}

	void test_exists3() {
		Creature c = Creature();
		CPPUNIT_ASSERT(c.exists() == false);
	}

	// bool hasTakenTurn() const;
	void test_hasTakenTurn1() {
		Creature c(Species::food());
		CPPUNIT_ASSERT(c.hasTakenTurn() == false);
	}

	void test_hasTakenTurn2() {
		Creature c(Species::food());
		std::vector<Creature> list = std::vector<Creature>(1);
		list[0] = c;
		Board b(2, 2);
		b.addCreature(0, 1);
		c.takeTurn(b, 0, list);
		CPPUNIT_ASSERT(c.hasTakenTurn() == true);
	}

	void test_hasTakenTurn3() {
		Creature c = Creature();
		CPPUNIT_ASSERT(c.hasTakenTurn() == false);
	}

	// void endTurn();
	void test_endTurn1() {
		Creature c(Species::food());
		c.endTurn();
		CPPUNIT_ASSERT(c.hasTakenTurn() == false);
	}

	void test_endTurn2() {
		Creature c(Species::food());
		std::vector<Creature> list = std::vector<Creature>(1);
		list[0] = c;
		Board b(2, 2);
		b.addCreature(0, 1);
		c.takeTurn(b, 0, list);
		c.endTurn();
		CPPUNIT_ASSERT(c.hasTakenTurn() == false);
	}

	void test_endTurn3() {
		Creature c = Creature();
		c.endTurn();
		CPPUNIT_ASSERT(c.hasTakenTurn() == false);
	}

	//	char type() const;
	void test_type1() {
		Creature c(Species::food());
		CPPUNIT_ASSERT(c.type() == 'f');
	}

	void test_type2() {
		Creature c(Species::best());
		CPPUNIT_ASSERT(c.type() == 'B');
	}

	void test_type3() {
		Creature c = Creature();
		CPPUNIT_ASSERT(c.type() == '.');
	}

	CPPUNIT_TEST_SUITE(TestCreature);
	CPPUNIT_TEST(test_takeTurn1);
	CPPUNIT_TEST(test_takeTurn2);
	CPPUNIT_TEST(test_takeTurn3);
	CPPUNIT_TEST(test_infect1);
	CPPUNIT_TEST(test_infect2);
	CPPUNIT_TEST(test_infect3);
	CPPUNIT_TEST(test_exists1);
	CPPUNIT_TEST(test_exists2);
	CPPUNIT_TEST(test_exists3);
	CPPUNIT_TEST(test_hasTakenTurn1);
	CPPUNIT_TEST(test_hasTakenTurn2);
	CPPUNIT_TEST(test_hasTakenTurn3);
	CPPUNIT_TEST(test_endTurn1);
	CPPUNIT_TEST(test_endTurn2);
	CPPUNIT_TEST(test_endTurn3);
	CPPUNIT_TEST(test_type1);
	CPPUNIT_TEST(test_type2);
	CPPUNIT_TEST(test_type3);
	CPPUNIT_TEST_SUITE_END();
    
};

struct TestSpecies : CppUnit::TestFixture {

	// static Species& food();
	void test_food1() {
		Species& food = Species::food();
		CPPUNIT_ASSERT(&food == &Species::food());
	}

	void test_food2() {
		Species& food1 = Species::food();
		Species& food2 = Species::food();
		CPPUNIT_ASSERT(&food1 == &food2);
	}

	void test_food3() {
		Species& food1 = Species::food();
		CPPUNIT_ASSERT(&food1 == &Species::food());
	}

	// static Species& hopper();
	void test_hopper1() {
		Species& hopper = Species::hopper();
		CPPUNIT_ASSERT(&hopper == &Species::hopper());
	}

	void test_hopper2() {
		Species& hopper1 = Species::hopper();
		Species& hopper2 = Species::hopper();
		CPPUNIT_ASSERT(&hopper1 == &hopper2);
	}

	void test_hopper3() {
		Species& hopper1 = Species::hopper();
		CPPUNIT_ASSERT(&hopper1 == &Species::hopper());
	}

	// static Species& rover();
	void test_rover1() {
		Species& rover = Species::rover();
		CPPUNIT_ASSERT(&rover == &Species::rover());
	}

	void test_rover2() {
		Species& rover1 = Species::rover();
		Species& rover2 = Species::rover();
		CPPUNIT_ASSERT(&rover1 == &rover2);
	}

	void test_rover3() {
		Species& rover1 = Species::rover();
		CPPUNIT_ASSERT(&rover1 == &Species::rover());
	}

	// static Species& trap();
	void test_trap1() {
		Species& trap = Species::trap();
		CPPUNIT_ASSERT(&trap == &Species::trap());
	}

	void test_trap2() {
		Species& trap1 = Species::trap();
		Species& trap2 = Species::trap();
		CPPUNIT_ASSERT(&trap1 == &trap2);
	}

	void test_trap3() {
		Species& trap1 = Species::trap();
		CPPUNIT_ASSERT(&trap1 == &Species::trap());
	}

	//	static Species& best();
	void test_best1() {
		Species& best = Species::best();
		CPPUNIT_ASSERT(&best == &Species::best());
	}

	void test_best2() {
		Species& best1 = Species::best();
		Species& best2 = Species::best();
		CPPUNIT_ASSERT(&best1 == &best2);
	}

	void test_best3() {
		Species& best1 = Species::best();
		CPPUNIT_ASSERT(&best1 == &Species::best());
	}

	// bool isValid() const;
	void test_isValid1() {
		Species best = Species::best();
		CPPUNIT_ASSERT(best.isValid() == true);
	}

	void test_isValid2() {
		Species spec(0);
		CPPUNIT_ASSERT(spec.isValid() == false);
	}

	void test_isValid3() {
		Species spec(FOOD);
		CPPUNIT_ASSERT(spec.isValid() == true);
	}

	// Instruction getInstruction(int);
	void test_getInstruction1() {
		Species hopper = Species::hopper();
		CPPUNIT_ASSERT(hopper.getInstruction(0).run() == HOP);
	}

	void test_getInstruction2() {
		Species hopper = Species::hopper();
		CPPUNIT_ASSERT(hopper.getInstruction(1).run() == GO &&  hopper.getInstruction(1).lineNumber() == 0 );
	}

	void test_getInstruction3() {
		Species rover = Species::rover();
		CPPUNIT_ASSERT(rover.getInstruction(9).run() == INFECT);
	}

	// char type() const;
	void test_type1() {
		Species hopper = Species::hopper();
		CPPUNIT_ASSERT(hopper.type() == 'h');
	}

	void test_type2() {
		Species rover = Species::rover();
		CPPUNIT_ASSERT(rover.type() == 'r');
	}

	void test_type3() {
		Species spec(NONE);
		CPPUNIT_ASSERT(spec.type() == '.');
	}

	CPPUNIT_TEST_SUITE(TestSpecies);
	CPPUNIT_TEST(test_food1);
	CPPUNIT_TEST(test_food2);
	CPPUNIT_TEST(test_food3);
	CPPUNIT_TEST(test_hopper1);
	CPPUNIT_TEST(test_hopper2);
	CPPUNIT_TEST(test_hopper3);
	CPPUNIT_TEST(test_rover1);
	CPPUNIT_TEST(test_rover2);
	CPPUNIT_TEST(test_rover3);
	CPPUNIT_TEST(test_trap1);
	CPPUNIT_TEST(test_trap2);
	CPPUNIT_TEST(test_trap3);
	CPPUNIT_TEST(test_best1);
	CPPUNIT_TEST(test_best2);
	CPPUNIT_TEST(test_best3);
	CPPUNIT_TEST(test_isValid1);
	CPPUNIT_TEST(test_isValid2);
	CPPUNIT_TEST(test_isValid3);
	CPPUNIT_TEST(test_getInstruction1);
	CPPUNIT_TEST(test_getInstruction2);
	CPPUNIT_TEST(test_getInstruction3);
	CPPUNIT_TEST(test_type1);
	CPPUNIT_TEST(test_type2);
	CPPUNIT_TEST(test_type3);
	CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
	using namespace std;
	cout << "TestDarwin.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestDarwin::suite());
	tr.addTest(TestBoard::suite());
	tr.addTest(TestInstruction::suite());
	tr.addTest(TestCreature::suite());
	tr.addTest(TestSpecies::suite());

	tr.run();

	cout << "Done." << endl;
	return 0;}
