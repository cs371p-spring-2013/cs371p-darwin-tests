/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app
    % valgrind TestDarwin.c++.app >& TestDarwin.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#define class struct
#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
        
        //dw.simulate();
    

    // void test_Creature1() {
    //    }


    //*************//
    // Board Tests //
    //*************//
    void test_Board() {

    }

    /* Board is_enemy tests*/
    void test_Board_is_enemy1()
    {
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_enemy(3,3, &c2) == true);
    }
    void test_Board_is_enemy2()
    {
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_enemy(3,3, &c1) == false);
    }
    void test_Board_is_enemy3()
    {
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_enemy(0,0, &c5) == false);
    }

    /* Board is_empty tests*/
    void test_Board_is_empty_space1(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_empty_space(3,1) == true);
    }
    void test_Board_is_empty_space2(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
         CPPUNIT_ASSERT(b.is_empty_space(3,3) == false);
    }

    void test_Board_is_empty_space3(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
         CPPUNIT_ASSERT(b.is_empty_space(0,0) == false);
    }

    /* Board place_peice tests */
    void test_Board_place_piece1() {
        Food f1 = Food();
        Hopper h1 = Hopper();
        Rover r1 = Rover();
        Species* sp1;
        sp1 = &h1;
        Creature cr1 = Creature(3,3, NORTH, sp1);
        sp1 = &f1;
        Creature cr2 = Creature(0,0, EAST, sp1);
        sp1 = &r1;
        Creature cr3 = Creature(1,1, SOUTH, sp1);
        Board b1 = Board(8, 8);
        CPPUNIT_ASSERT(b1.place_piece(3, 3, &cr1, NORTH) == true);
    }

     void test_Board_place_piece2() {
        Food f1 = Food();
        Hopper h1 = Hopper();
        Rover r1 = Rover();
        Species* sp1;
        sp1 = &h1;
        Creature cr1 = Creature(3,3, NORTH, sp1);
        sp1 = &f1;
        Creature cr2 = Creature(0,0, EAST, sp1);
        sp1 = &r1;
        Creature cr3 = Creature(1,1, SOUTH, sp1);
        Board b1 = Board(8, 8);
        CPPUNIT_ASSERT(b1.place_piece(3, 3, &cr1, NORTH) == true); 
        CPPUNIT_ASSERT(b1.place_piece(0, 0, &cr2, EAST) == true );
    }

    void test_Board_place_piece3() {
        Food f1 = Food();
        Hopper h1 = Hopper();
        Rover r1 = Rover();
        Species* sp1;
        sp1 = &h1;
        Creature cr1 = Creature(3,3, NORTH, sp1);
        sp1 = &f1;
        Creature cr2 = Creature(0,0, EAST, sp1);
        sp1 = &r1;
        Creature cr3 = Creature(1,1, SOUTH, sp1);
        Board b1 = Board(8, 8);
        CPPUNIT_ASSERT(b1.place_piece(3, 3, &cr1, NORTH) == true); 
        CPPUNIT_ASSERT(b1.place_piece(0, 0, &cr2, EAST) == true );
        CPPUNIT_ASSERT(b1.place_piece(0, 0, &cr3, SOUTH) == false);
    }

    /* Board is_edge tests */
    void test_Board_is_edge1(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_edge(8,6) == true);
    }
    void test_Board_is_edge2(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_edge(6,6) == false);
    }
    void test_Board_is_edge3(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT(b.is_edge(-1,6) == true);
    }

    /* Board next_space tests */
    void test_Board_next_space1(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        int i = 2;
        int j = 3; 
        int change_i = 0;
        int change_j = 0; 
        b.next_space(i, j, change_i, change_j, NORTH);
        CPPUNIT_ASSERT(change_i == 1);
        CPPUNIT_ASSERT(change_j == 3);
    }
    void test_Board_next_space2(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        int i = 2;
        int j = 3; 
        int change_i = 0;
        int change_j = 0; 
        b.next_space(i, j, change_i, change_j, EAST);
        CPPUNIT_ASSERT(change_i == 2);
        CPPUNIT_ASSERT(change_j == 4);
    }
    void test_Board_next_space3(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        int i = 2;
        int j = 3; 
        int change_i = 0;
        int change_j = 0; 
        b.next_space(i, j, change_i, change_j, EAST);
        b.next_space(change_i, change_j, change_i, change_j, WEST);
        CPPUNIT_ASSERT(change_i == 2);
        CPPUNIT_ASSERT(change_j == 3);
    }
    /* Board same_species tests */
    void test_Board_same_species1(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT( b.same_species(3 ,3, 0 , 0) == false);
    }
    void test_Board_same_species2(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT( b.same_species(3 ,3, 1 , 1) == false);
    }
    void test_Board_same_species3(){
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, NORTH, sp);
        sp = &f;
        Creature c5 = Creature(0,0, EAST, sp);
        sp = &r;
        Creature c2 = Creature(1,1, SOUTH, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, NORTH); 
        b.place_piece(0, 0, &c5, EAST);
        b.place_piece(1,1, &c2, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 5, 1, &b);
        CPPUNIT_ASSERT( b.same_species(3 ,3, 3 , 3) == true);
    }

    void test_Board_take_turn1(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        //Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        //b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        b.take_turn(0);
		Creature* c1p = &c1; 
		CPPUNIT_ASSERT(c1p == static_cast<Creature*>(b.pieces[3][2]));
    }
	
	void test_Board_take_turn2(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        b.take_turn(0);
		b.take_turn(1);
		Creature* c1p = &c1;
		Creature* c2p = &c2; 
		CPPUNIT_ASSERT(c1p == static_cast<Creature*>(b.pieces[3][1]));
		CPPUNIT_ASSERT(c2p == static_cast<Creature*>(b.pieces[3][6]));
    }
	
	void test_Board_take_turn3(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 3, 1, &b);
        b.take_turn(0);
		b.take_turn(1);
		b.take_turn(2);
		b.take_turn(3);
		Creature* c1p = &c1;
		Creature* c2p = &c2; 
		CPPUNIT_ASSERT(c1p == static_cast<Creature*>(b.pieces[3][0]));
		CPPUNIT_ASSERT(c2p == static_cast<Creature*>(b.pieces[3][7]));
    }
    

    //****************//
    // Creature Tests //
    //****************//
    
    void test_creature_hop1() {
       Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
		Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
		c1.hop(bp, c1._row, c1._col);
		Creature* c1p = &c1; 
		CPPUNIT_ASSERT(c1._row == 4);
    }

    void test_creature_hop2(){
         Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        CPPUNIT_ASSERT(c1._row == 6);
    }

    void test_creature_hop3(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        c1.hop(bp, c1._row, c1._col);
        CPPUNIT_ASSERT(c1._row == 7); 
    }

    void test_creature_left1 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.left();
        CPPUNIT_ASSERT(c1._dir == EAST);

    }

    void test_creature_left2 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.left();
        c1.left();
        CPPUNIT_ASSERT(c1._dir == NORTH);;
    }
     void test_creature_left3 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.left();
        c1.left();
        c1.left();
        c1.left();
        CPPUNIT_ASSERT(c1._dir == SOUTH);
    }

    void test_creature_infect1() {
        Hopper h = Hopper();
        Rover r = Rover(); 
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        sp = &r; 
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c2.infect(bp);
        CPPUNIT_ASSERT(c1._sp == c2._sp);
    }

    void test_creature_infect2() {
        Hopper h = Hopper();
        Rover r = Rover(); 
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, EAST, sp);
        sp = &r; 
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, EAST);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.infect(bp);
        CPPUNIT_ASSERT(c1._sp == c2._sp);
    }
    void test_creature_infect3() {
        Food f = Food();
        Rover r = Rover(); 
        Species* sp;
        sp = &f;
        Creature c1 = Creature(3,3, EAST, sp);
        sp = &r; 
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, EAST);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.infect(bp);
        CPPUNIT_ASSERT(c1._sp == c2._sp);
    }
    void test_creature_right1 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.right();
        CPPUNIT_ASSERT(c1._dir == WEST);
    }
    void test_creature_right2 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.right();
        c1.right();
        CPPUNIT_ASSERT(c1._dir == NORTH);
    }

    void test_creature_right3 () {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.right();
        c1.right();
        c1.right();
        c1.right();
        CPPUNIT_ASSERT(c1._dir == SOUTH);
    }

    void test_creature_if_enemy1() {
        Hopper h = Hopper();
        Rover r = Rover(); 
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, SOUTH, sp);
        sp = &r; 
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, SOUTH);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c2.if_enemy(bp, 11);
        CPPUNIT_ASSERT(c2._pc == 11);
    }
    void test_creature_if_enemy2() {
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, EAST, sp);
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, EAST);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.infect(bp);
        c1.if_enemy(bp, 22);
        CPPUNIT_ASSERT(c2._pc != 22);
    }

    void test_creature_if_enemy3() {
        Hopper h = Hopper();
        Rover r = Rover();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, EAST, sp);
        sp = &r;
        Creature c2 = Creature(3,4, WEST, sp);
        Board b = Board(8, 8);
        Board* bp = &b;
        b.place_piece(3, 3, &c1, EAST);
        b.place_piece(3, 4, &c2, WEST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        c1.infect(bp);
        c1.if_enemy(bp, 25);
        CPPUNIT_ASSERT(c2._pc != 25);
    }
    void test_Creature_take_turn1(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        //Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        //b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 2, &b);
        Board* bp = &b;
        c1.take_turn(c1._row, c1._col, bp, 0);
        CPPUNIT_ASSERT(c1._col == 2 );
    }
    
    void test_Creature_take_turn2(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 2, 1, &b);
        Board* bp = &b;
        c1.take_turn(c1._row, c1._col, bp, 0);
        c2.take_turn(c2._row, c2._col, bp, 0);
        c1.take_turn(c1._row, c1._col, bp, 1);
        CPPUNIT_ASSERT(c1._col == 1 );
        CPPUNIT_ASSERT(c2._col == 5 );
    }
    
    void test_Creature_take_turn3(){
        Hopper h = Hopper();
        Species* sp;
        sp = &h;
        Creature c1 = Creature(3,3, WEST, sp);
        Creature c2 = Creature(3,4, EAST, sp);
        Board b = Board(8, 8);
        b.place_piece(3, 3, &c1, WEST); 
        b.place_piece(3, 4, &c2, EAST);
        DarwinsWorld dw = DarwinsWorld(8, 8, 3, 1, &b);
        Board* bp = &b;
        c1.take_turn(c1._row, c1._col, bp, 0);
        c2.take_turn(c2._row, c2._col, bp, 0);
        c1.take_turn(c1._row, c1._col, bp, 1);
        c2.take_turn(c2._row, c2._col, bp, 1);
        c1.take_turn(c1._row, c1._col, bp, 2);
        c2.take_turn(c2._row, c2._col, bp, 2);
        c1.take_turn(c1._row, c1._col, bp, 3);
        c2.take_turn(c2._row, c2._col, bp, 3);
        CPPUNIT_ASSERT(c1._col == 0 );
        CPPUNIT_ASSERT(c2._col == 7 );
    }
//}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_Board_is_enemy1);
    CPPUNIT_TEST(test_Board_is_enemy2);
    CPPUNIT_TEST(test_Board_is_enemy3);
    CPPUNIT_TEST(test_Board_is_empty_space1);
    CPPUNIT_TEST(test_Board_is_empty_space2);
    CPPUNIT_TEST(test_Board_is_empty_space3);
    CPPUNIT_TEST(test_Board_place_piece1);
    CPPUNIT_TEST(test_Board_place_piece2);
    CPPUNIT_TEST(test_Board_place_piece3);
    CPPUNIT_TEST(test_Board_is_edge1);
    CPPUNIT_TEST(test_Board_is_edge2);
    CPPUNIT_TEST(test_Board_is_edge3);
    CPPUNIT_TEST(test_Board_next_space1);
    CPPUNIT_TEST(test_Board_next_space2);
    CPPUNIT_TEST(test_Board_next_space3);
    CPPUNIT_TEST(test_Board_same_species1);
    CPPUNIT_TEST(test_Board_same_species2);
    CPPUNIT_TEST(test_Board_same_species3);
    CPPUNIT_TEST(test_Board_take_turn1);
	CPPUNIT_TEST(test_Board_take_turn2);
	CPPUNIT_TEST(test_Board_take_turn3);
    CPPUNIT_TEST(test_creature_hop1);
    CPPUNIT_TEST(test_creature_hop2);
    CPPUNIT_TEST(test_creature_hop3);
    CPPUNIT_TEST(test_creature_infect1);
    CPPUNIT_TEST(test_creature_infect2);
    CPPUNIT_TEST(test_creature_infect3);
    CPPUNIT_TEST(test_creature_left1);
    CPPUNIT_TEST(test_creature_left2);
    CPPUNIT_TEST(test_creature_left3);
    CPPUNIT_TEST(test_creature_right1);
    CPPUNIT_TEST(test_creature_right2);
    CPPUNIT_TEST(test_creature_right3);
    CPPUNIT_TEST(test_creature_if_enemy1);
    CPPUNIT_TEST(test_creature_if_enemy2);
    CPPUNIT_TEST(test_creature_if_enemy3);
    CPPUNIT_TEST(test_Creature_take_turn1);
    CPPUNIT_TEST(test_Creature_take_turn2);
    CPPUNIT_TEST(test_Creature_take_turn3);
    CPPUNIT_TEST_SUITE_END();};

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
    return 0;}
