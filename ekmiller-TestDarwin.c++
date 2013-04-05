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

// --------
// includes
// --------

#include <iostream> // cout, endl, ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public

#include "Darwin.h"


// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
	// ----
	// Darwin
	// ----

	void test_darwin_1 () {
		Darwin darwin(1,1);
		CPPUNIT_ASSERT(darwin.size_cols == 1);
		CPPUNIT_ASSERT(darwin.size_rows == 1); }

	void test_darwin_2 () {
		Darwin darwin(10,10);
		CPPUNIT_ASSERT(darwin.size_cols == 10);
		CPPUNIT_ASSERT(darwin.size_rows == 10); }

	void test_darwin_3 () {
		Darwin darwin(72,1);
		CPPUNIT_ASSERT(darwin.size_cols == 1);
		CPPUNIT_ASSERT(darwin.size_rows == 72); }

	// ----
	// add_creature
	// ----

	void test_add_creature_1 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),4);
		CPPUNIT_ASSERT(darwin.creatures.size() == 1);
		CPPUNIT_ASSERT(darwin.is_creature_at(4)); }

	void test_add_creature_2 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),1);
		darwin.add_creature(Creature(0,0),2);
		darwin.add_creature(Creature(0,0),3);
		CPPUNIT_ASSERT(darwin.creatures.size() == 3);
		CPPUNIT_ASSERT(darwin.is_creature_at(1));
		CPPUNIT_ASSERT(darwin.is_creature_at(2));
		CPPUNIT_ASSERT(darwin.is_creature_at(3)); }

	void test_add_creature_3 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(1,0),1);
		darwin.add_creature(Creature(0,3),3);
		CPPUNIT_ASSERT(darwin.creatures.size() == 2);
		CPPUNIT_ASSERT(darwin.is_creature_at(1));
		CPPUNIT_ASSERT(darwin.is_creature_at(3)); }

	// ----
	// row_major
	// ----

	void test_row_major_1 () {
		Darwin darwin(3,3);
		int s = darwin.row_major(1,1);
		CPPUNIT_ASSERT(s == 4); }

	void test_row_major_2 () {
		Darwin darwin(3,3);
		int s = darwin.row_major(0,0);
		CPPUNIT_ASSERT(s == 0); }

	void test_row_major_3 () {
		Darwin darwin(3,3);
		int s = darwin.row_major(2,2);
		CPPUNIT_ASSERT(s == 8); }

	// ----
	// is_creature_at
	// ----

	void test_is_creature_at_1 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),0);
		CPPUNIT_ASSERT(darwin.is_creature_at(0)); }

	void test_is_creature_at_2 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),1);
		CPPUNIT_ASSERT(darwin.is_creature_at(1)); }

	void test_is_creature_at_3 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),8);
		CPPUNIT_ASSERT(darwin.is_creature_at(8)); }

	// ----
	// sort_creatures
	// ----

	void test_sort_creatures_1 () {
		Darwin darwin(3,3);
		darwin.creatures.push_back(make_pair(Creature(0,0),8));
		darwin.creatures.push_back(make_pair(Creature(0,0),0));
		darwin.sort_creatures();
		CPPUNIT_ASSERT(darwin.creatures[0].second == 0);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 8); }

	void test_sort_creatures_2 () {
		Darwin darwin(3,3);
		darwin.creatures.push_back(make_pair(Creature(0,0),5));
		darwin.creatures.push_back(make_pair(Creature(0,0),4));
		darwin.sort_creatures();
		CPPUNIT_ASSERT(darwin.creatures[0].second == 4);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 5); }

	void test_sort_creatures_3 () {
		Darwin darwin(3,3);
		darwin.creatures.push_back(make_pair(Creature(0,0),2));
		darwin.creatures.push_back(make_pair(Creature(0,0),3));
		darwin.creatures.push_back(make_pair(Creature(0,0),1));
		darwin.sort_creatures();
		CPPUNIT_ASSERT(darwin.creatures[0].second == 1);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 2);
		CPPUNIT_ASSERT(darwin.creatures[2].second == 3); }
	// ----
	// hop
	// ----

	void test_hop_1 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(2,3),0);
		darwin.add_creature(Creature(2,0),2);
		darwin.add_creature(Creature(2,2),6);
		darwin.add_creature(Creature(2,1),8);
		darwin.hop(darwin.creatures[0]);
		darwin.hop(darwin.creatures[1]);
		darwin.hop(darwin.creatures[2]);
		darwin.hop(darwin.creatures[3]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._direction == 3);
		CPPUNIT_ASSERT(darwin.creatures[0].second == 3);
		CPPUNIT_ASSERT(darwin.creatures[1].first._direction == 0);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 1);
		CPPUNIT_ASSERT(darwin.creatures[2].first._direction == 2);
		CPPUNIT_ASSERT(darwin.creatures[2].second == 7);
		CPPUNIT_ASSERT(darwin.creatures[3].first._direction == 1);
		CPPUNIT_ASSERT(darwin.creatures[3].second == 5); }

	void test_hop_2 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(2,1),0);
		darwin.add_creature(Creature(2,2),2);
		darwin.add_creature(Creature(2,0),6);
		darwin.add_creature(Creature(2,3),8);
		darwin.hop(darwin.creatures[0]);
		darwin.hop(darwin.creatures[1]);
		darwin.hop(darwin.creatures[2]);
		darwin.hop(darwin.creatures[3]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._direction == 1);
		CPPUNIT_ASSERT(darwin.creatures[0].second == 0);
		CPPUNIT_ASSERT(darwin.creatures[1].first._direction == 2);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 2);
		CPPUNIT_ASSERT(darwin.creatures[2].first._direction == 0);
		CPPUNIT_ASSERT(darwin.creatures[2].second == 6);
		CPPUNIT_ASSERT(darwin.creatures[3].first._direction == 3);
		CPPUNIT_ASSERT(darwin.creatures[3].second == 8); }

	void test_hop_3 () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(2,2),0);
		darwin.add_creature(Creature(2,1),4);
		darwin.hop(darwin.creatures[0]);
		darwin.hop(darwin.creatures[1]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._direction == 2);
		CPPUNIT_ASSERT(darwin.creatures[0].second == 1);
		CPPUNIT_ASSERT(darwin.creatures[1].first._direction == 1);
		CPPUNIT_ASSERT(darwin.creatures[1].second == 4); }

	// ----
	// left
	// ----

	void test_left () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),0);
		darwin.add_creature(Creature(0,1),1);
		darwin.add_creature(Creature(0,2),2);
		darwin.add_creature(Creature(0,3),3);
		darwin.left(darwin.creatures[0]);
		darwin.left(darwin.creatures[1]);
		darwin.left(darwin.creatures[2]);
		darwin.left(darwin.creatures[3]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._direction == 3);
		CPPUNIT_ASSERT(darwin.creatures[1].first._direction == 0);
		CPPUNIT_ASSERT(darwin.creatures[2].first._direction == 1);
		CPPUNIT_ASSERT(darwin.creatures[3].first._direction == 2); }

	// ----
	// right
	// ----

	void test_right () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),0);
		darwin.add_creature(Creature(0,1),1);
		darwin.add_creature(Creature(0,2),2);
		darwin.add_creature(Creature(0,3),3);
		darwin.right(darwin.creatures[0]);
		darwin.right(darwin.creatures[1]);
		darwin.right(darwin.creatures[2]);
		darwin.right(darwin.creatures[3]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._direction == 1);
		CPPUNIT_ASSERT(darwin.creatures[1].first._direction == 2);
		CPPUNIT_ASSERT(darwin.creatures[2].first._direction == 3);
		CPPUNIT_ASSERT(darwin.creatures[3].first._direction == 0); }


	// ----
	// infect
	// ----

	void test_infect () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,2),0);
		darwin.add_creature(Creature(1,0),1);
		darwin.add_creature(Creature(4,0),2);
		darwin.add_creature(Creature(2,1),3);
		darwin.infect(darwin.creatures[0]);
		darwin.infect(darwin.creatures[1]);
		darwin.infect(darwin.creatures[2]);
		darwin.infect(darwin.creatures[3]);
		CPPUNIT_ASSERT(darwin.creatures[0].first._species.symbol == 'h');
		CPPUNIT_ASSERT(darwin.creatures[1].first._species.symbol == 'b');
		CPPUNIT_ASSERT(darwin.creatures[2].first._species.symbol == 'b');
		CPPUNIT_ASSERT(darwin.creatures[3].first._species.symbol == 'h'); }

	// ----
	// if_empty
	// ----

	void test_if_empty () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,0),4);
		CPPUNIT_ASSERT(darwin.if_empty(darwin.creatures[0]));
		darwin.left(darwin.creatures[0]);
		CPPUNIT_ASSERT(darwin.if_empty(darwin.creatures[0]));
		darwin.left(darwin.creatures[0]);
		CPPUNIT_ASSERT(darwin.if_empty(darwin.creatures[0]));
		darwin.left(darwin.creatures[0]);
		CPPUNIT_ASSERT(darwin.if_empty(darwin.creatures[0]));
		darwin.add_creature(Creature(0,0),1);
		darwin.add_creature(Creature(0,0),5);
		darwin.add_creature(Creature(0,0),7);
		darwin.add_creature(Creature(0,0),3);
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_empty(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_empty(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_empty(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_empty(darwin.creatures[2]));

		Darwin darwin2(1,1);
		darwin2.add_creature(Creature(0,0),0);
		CPPUNIT_ASSERT(!darwin2.if_empty(darwin2.creatures[0]));
		darwin2.left(darwin2.creatures[0]);
		CPPUNIT_ASSERT(!darwin2.if_empty(darwin2.creatures[0]));
		darwin2.left(darwin2.creatures[0]);
		CPPUNIT_ASSERT(!darwin2.if_empty(darwin2.creatures[0]));
		darwin2.left(darwin2.creatures[0]);
		CPPUNIT_ASSERT(!darwin2.if_empty(darwin2.creatures[0]));	}

	// ----
	// if_wall
	// ----

	void test_if_wall () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,1),1);
		darwin.add_creature(Creature(0,0),3);
		darwin.add_creature(Creature(0,0),4);
		darwin.add_creature(Creature(0,2),5);
		darwin.add_creature(Creature(0,3),7);
		CPPUNIT_ASSERT(darwin.if_wall(darwin.creatures[0]));
		CPPUNIT_ASSERT(darwin.if_wall(darwin.creatures[1]));
		CPPUNIT_ASSERT(darwin.if_wall(darwin.creatures[3]));
		CPPUNIT_ASSERT(darwin.if_wall(darwin.creatures[4]));
		CPPUNIT_ASSERT(!darwin.if_wall(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_wall(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_wall(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(!darwin.if_wall(darwin.creatures[2])); }

	// ----
	// if_enemy
	// ----

	void test_if_enemy () {
		Darwin darwin(3,3);
		darwin.add_creature(Creature(0,1),1);
		darwin.add_creature(Creature(1,0),3);
		darwin.add_creature(Creature(0,1),4);
		darwin.add_creature(Creature(1,2),5);
		darwin.add_creature(Creature(1,3),7);
		CPPUNIT_ASSERT(!darwin.if_enemy(darwin.creatures[0]));
		CPPUNIT_ASSERT(!darwin.if_enemy(darwin.creatures[1]));
		CPPUNIT_ASSERT(!darwin.if_enemy(darwin.creatures[3]));
		CPPUNIT_ASSERT(!darwin.if_enemy(darwin.creatures[4]));
		CPPUNIT_ASSERT(!darwin.if_enemy(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(darwin.if_enemy(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(darwin.if_enemy(darwin.creatures[2]));
		darwin.left(darwin.creatures[2]);
		CPPUNIT_ASSERT(darwin.if_enemy(darwin.creatures[2])); }

	// -----
	// species
	// -----

	void test_species () {
		Species food(0);
		Species trap(1);
		Species hopper(2);
		Species rover(3);
		Species best(4);
		CPPUNIT_ASSERT(food.symbol == 'f');
		CPPUNIT_ASSERT(trap.symbol == 't');
		CPPUNIT_ASSERT(hopper.symbol == 'h');
		CPPUNIT_ASSERT(rover.symbol == 'r');
		CPPUNIT_ASSERT(best.symbol == 'b'); }

	// -----
	// getSymbol
	// -----

	void test_getSymbol () {
		Species food(0);
		Species trap(1);
		Species hopper(2);
		Species rover(3);
		Species best(4);
		CPPUNIT_ASSERT(food.getSymbol() == 'f');
		CPPUNIT_ASSERT(trap.getSymbol() == 't');
		CPPUNIT_ASSERT(hopper.getSymbol() == 'h');
		CPPUNIT_ASSERT(rover.getSymbol() == 'r');
		CPPUNIT_ASSERT(best.getSymbol() == 'b'); }

	// -----
	// creature
	// -----

	void test_creature () {
		Creature creature1(0,0);
		Creature creature2(1,1);
		Creature creature3(2,2);
		Creature creature4(3,3);
		Creature creature5(4,0);
		CPPUNIT_ASSERT(creature1._species.symbol == 'f');
		CPPUNIT_ASSERT(creature2._species.symbol == 't');
		CPPUNIT_ASSERT(creature3._species.symbol == 'h');
		CPPUNIT_ASSERT(creature4._species.symbol == 'r');
		CPPUNIT_ASSERT(creature5._species.symbol == 'b'); }

	// -----
	// creature left
	// -----

	void test_creature_left () {
		Creature creature1(0,0);
		Creature creature2(1,0);
		Creature creature3(2,0);
		Creature creature4(3,0);
		Creature creature5(4,0);
		creature1.left();
		creature2.left();
		creature3.left();
		creature4.left();
		creature5.left();
		CPPUNIT_ASSERT(creature1._direction == 3);
		CPPUNIT_ASSERT(creature2._direction == 3);
		CPPUNIT_ASSERT(creature3._direction == 3);
		CPPUNIT_ASSERT(creature4._direction == 3);
		CPPUNIT_ASSERT(creature5._direction == 3);
		creature1.left();
		creature2.left();
		creature3.left();
		creature4.left();
		creature5.left();
		CPPUNIT_ASSERT(creature1._direction == 2);
		CPPUNIT_ASSERT(creature2._direction == 2);
		CPPUNIT_ASSERT(creature3._direction == 2);
		CPPUNIT_ASSERT(creature4._direction == 2);
		CPPUNIT_ASSERT(creature5._direction == 2);
		creature1.left();
		creature2.left();
		creature3.left();
		creature4.left();
		creature5.left();
		CPPUNIT_ASSERT(creature1._direction == 1);
		CPPUNIT_ASSERT(creature2._direction == 1);
		CPPUNIT_ASSERT(creature3._direction == 1);
		CPPUNIT_ASSERT(creature4._direction == 1);
		CPPUNIT_ASSERT(creature5._direction == 1);
		creature1.left();
		creature2.left();
		creature3.left();
		creature4.left();
		creature5.left();
		CPPUNIT_ASSERT(creature1._direction == 0);
		CPPUNIT_ASSERT(creature2._direction == 0);
		CPPUNIT_ASSERT(creature3._direction == 0);
		CPPUNIT_ASSERT(creature4._direction == 0);
		CPPUNIT_ASSERT(creature5._direction == 0); }

	// -----
	// creature right
	// -----

	void test_creature_right () {
		Creature creature1(0,0);
		Creature creature2(1,0);
		Creature creature3(2,0);
		Creature creature4(3,0);
		Creature creature5(4,0);
		creature1.right();
		creature2.right();
		creature3.right();
		creature4.right();
		creature5.right();
		CPPUNIT_ASSERT(creature1._direction == 1);
		CPPUNIT_ASSERT(creature2._direction == 1);
		CPPUNIT_ASSERT(creature3._direction == 1);
		CPPUNIT_ASSERT(creature4._direction == 1);
		CPPUNIT_ASSERT(creature5._direction == 1);
		creature1.right();
		creature2.right();
		creature3.right();
		creature4.right();
		creature5.right();
		CPPUNIT_ASSERT(creature1._direction == 2);
		CPPUNIT_ASSERT(creature2._direction == 2);
		CPPUNIT_ASSERT(creature3._direction == 2);
		CPPUNIT_ASSERT(creature4._direction == 2);
		CPPUNIT_ASSERT(creature5._direction == 2);
		creature1.right();
		creature2.right();
		creature3.right();
		creature4.right();
		creature5.right();
		CPPUNIT_ASSERT(creature1._direction == 3);
		CPPUNIT_ASSERT(creature2._direction == 3);
		CPPUNIT_ASSERT(creature3._direction == 3);
		CPPUNIT_ASSERT(creature4._direction == 3);
		CPPUNIT_ASSERT(creature5._direction == 3);
		creature1.right();
		creature2.right();
		creature3.right();
		creature4.right();
		creature5.right();
		CPPUNIT_ASSERT(creature1._direction == 0);
		CPPUNIT_ASSERT(creature2._direction == 0);
		CPPUNIT_ASSERT(creature3._direction == 0);
		CPPUNIT_ASSERT(creature4._direction == 0);
		CPPUNIT_ASSERT(creature5._direction == 0); }

	// -----
	// creature go
	// -----

	void test_creature_go () {
		Creature creature(0,0);
		creature.go(1);
		CPPUNIT_ASSERT(creature._program_counter == 1);
		creature.go(10);
		CPPUNIT_ASSERT(creature._program_counter == 10);
		creature.go(6);
		CPPUNIT_ASSERT(creature._program_counter == 6); }




    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_darwin_1);
    CPPUNIT_TEST(test_darwin_2);
    CPPUNIT_TEST(test_darwin_3);
    CPPUNIT_TEST(test_add_creature_1);
    CPPUNIT_TEST(test_add_creature_2);
    CPPUNIT_TEST(test_add_creature_3);
    CPPUNIT_TEST(test_row_major_1);
    CPPUNIT_TEST(test_row_major_2);
    CPPUNIT_TEST(test_row_major_3);
    CPPUNIT_TEST(test_is_creature_at_1);
    CPPUNIT_TEST(test_is_creature_at_2);
    CPPUNIT_TEST(test_is_creature_at_3);
    CPPUNIT_TEST(test_sort_creatures_1);
    CPPUNIT_TEST(test_sort_creatures_2);
    CPPUNIT_TEST(test_sort_creatures_3);
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_left);
    CPPUNIT_TEST(test_right);
    CPPUNIT_TEST(test_infect);
    CPPUNIT_TEST(test_if_empty);
    CPPUNIT_TEST(test_if_wall);
    CPPUNIT_TEST(test_if_enemy);
    CPPUNIT_TEST(test_species);
    CPPUNIT_TEST(test_getSymbol);
    CPPUNIT_TEST(test_creature);
    CPPUNIT_TEST(test_creature_left);
    CPPUNIT_TEST(test_creature_right);
    CPPUNIT_TEST(test_creature_go);
    CPPUNIT_TEST_SUITE_END(); };

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0; }
