// Cameron Bielstein, UTEID: ctb677, CSID: cameronb

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner


// Defined to reveal private and protected elements for testing
#define private public
#define protected public
#define class struct

#include "Darwin.h"

// -------------
// TestAllocator
// -------------

struct TestDarwin : CppUnit::TestFixture {

    // --------------------------
    // Test Creature Constructors
    // --------------------------

        // these tests combined because any more than one for each would be hugely redundant

        // ---------------------------
        // test_creature_constructor_1
        // ---------------------------
        void test_creature_constructor_1 () {
            Creature x(NULL, 0, {1, 2, WEST});
            CPPUNIT_ASSERT(x.board == NULL);
            CPPUNIT_ASSERT(x.species == 0);
            CPPUNIT_ASSERT(x.loc.x == 1);
            CPPUNIT_ASSERT(x.loc.y == 2);
            CPPUNIT_ASSERT(x.loc.dir == WEST);
            CPPUNIT_ASSERT(x.pc == 0);}
        // ---------------------------
        // test_creature_constructor_2
        // ---------------------------
        void test_creature_constructor_2 () {
            Creature x(NULL, FOOD, {1, 2, WEST});
            CPPUNIT_ASSERT(x.board == NULL);
            CPPUNIT_ASSERT(x.species == 4);
            CPPUNIT_ASSERT(x.loc.x == 1);
            CPPUNIT_ASSERT(x.loc.y == 2);
            CPPUNIT_ASSERT(x.loc.dir == WEST);
            CPPUNIT_ASSERT(x.pc == 0);}
        // ---------------------------
        // test_creature_constructor_3
        // ---------------------------
        void test_creature_constructor_3 () {
            Location l;
            l.x = 1;
            l.y = 2;
            l.dir = WEST;
            Creature x(NULL, HOPPER, l);
            CPPUNIT_ASSERT(x.board == NULL);
            CPPUNIT_ASSERT(x.species == 5);
            CPPUNIT_ASSERT(x.loc.x == 1);
            CPPUNIT_ASSERT(x.loc.y == 2);
            CPPUNIT_ASSERT(x.loc.dir == WEST);
            CPPUNIT_ASSERT(x.pc == 0);}

    // -------------
    // Test toChar()
    // -------------
        // -------------
        // test_toChar_1
        // -------------
        void test_toChar_1 () {
            Creature x(NULL, FOOD, {1, 2, WEST});
            CPPUNIT_ASSERT(x.toChar() == 'f');}
        // -------------
        // test_toChar_2
        // -------------
        void test_toChar_2 () {
            Creature x(NULL, ROVER, {1, 2, WEST});
            CPPUNIT_ASSERT(x.toChar() == 'r');}
        // -------------
        // test_toChar_3
        // -------------
        void test_toChar_3 () {
            Creature x(NULL, TRAP, {1, 2, WEST});
            CPPUNIT_ASSERT(x.toChar() == 't');}

    // --------------------------
    // Test GameBoard Constructor
    // --------------------------
        // -------------------
        // test_gb_construct_1
        // -------------------
        void test_gb_construct_1 () {
            GameBoard x(2,2, std::cout);
            CPPUNIT_ASSERT(x.height == 2);
            CPPUNIT_ASSERT(x.width == 2);
            CPPUNIT_ASSERT(x.board.size() == 2);
            CPPUNIT_ASSERT(x.board[0].size() == 2);
            CPPUNIT_ASSERT(x.board[0][0] == NULL);}
        // -------------------
        // test_gb_construct_2
        // -------------------
        void test_gb_construct_2 () {
            GameBoard x(0,0, std::cout);
            CPPUNIT_ASSERT(x.height == 0);
            CPPUNIT_ASSERT(x.width == 0);
            CPPUNIT_ASSERT(x.board.size() == 0);}
        // -------------------
        // test_gb_construct_3
        // -------------------
        void test_gb_construct_3 () {
            GameBoard x(1,2, std::cout);
            CPPUNIT_ASSERT(x.height == 1);
            CPPUNIT_ASSERT(x.width == 2);
            CPPUNIT_ASSERT(x.board.size() == 1);
            CPPUNIT_ASSERT(x.board[0].size() == 2);
            CPPUNIT_ASSERT(x.board[0][0] == NULL);}
        // ------------------
        // test_isSpaceWall_1
        // ------------------
        void test_isSpaceWall_1 () {
            GameBoard x(2,2, std::cout);
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,NORTH}) );
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,WEST}) );
            CPPUNIT_ASSERT( !x.isSpaceWall({0,0,SOUTH}) );
            CPPUNIT_ASSERT( !x.isSpaceWall({0,0,EAST}) );}
        // ------------------
        // test_isSpaceWall_2
        // ------------------
        void test_isSpaceWall_2 () {
            GameBoard x(1,1, std::cout);
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,NORTH}) );
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,WEST}) );
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,EAST}) );
            CPPUNIT_ASSERT( x.isSpaceWall({0,0,EAST}) );}
        // ------------------
        // test_isSpaceWall_3
        // ------------------
        void test_isSpaceWall_3 () {
            GameBoard x(5,5, std::cout);
            CPPUNIT_ASSERT( !x.isSpaceWall({3,3,NORTH}) );
            CPPUNIT_ASSERT( !x.isSpaceWall({3,3,WEST}) );
            CPPUNIT_ASSERT( !x.isSpaceWall({3,3,EAST}) );
            CPPUNIT_ASSERT( !x.isSpaceWall({3,3,EAST}) );}

    // ---------------------------
    // Test GameBoard isSpaceEmpty
    // ---------------------------
        // -------------------
        // test_isSpaceEmpty_1
        // -------------------
        void test_isSpaceEmpty_1 () {
            GameBoard x(1,1, std::cout);
            CPPUNIT_ASSERT(x.isSpaceEmpty({0,0,-1}));}
        // -------------------
        // test_isSpaceEmpty_2
        // -------------------
        void test_isSpaceEmpty_2 () {
            GameBoard x(1,1, std::cout);
            Creature temp(&x, FOOD, {0,0,NORTH});
            x.board[0][0] = &temp;
            CPPUNIT_ASSERT(!x.isSpaceEmpty({0,0,-1}));}
        // -------------------
        // test_isSpaceEmpty_3
        // -------------------
        void test_isSpaceEmpty_3 () {
            GameBoard x(5,5, std::cout);
            CPPUNIT_ASSERT(!x.isSpaceEmpty({4,4,EAST}));}


    // --------------------------
    // Test GameBoard placeCreature
    // --------------------------
        // ---------------
        // test_placeCreature_1
        // ---------------
        void test_placeCreature_1 () {
            GameBoard x(2,2, std::cout);
            Creature y(&x, FOOD, {0,0,NORTH});
            bool test = x.placeCreature(&y, {0,0,NORTH});
            CPPUNIT_ASSERT(test);
            CPPUNIT_ASSERT(x.board[0][0] == &y);}
        // ---------------
        // test_placeCreature_2
        // ---------------
        void test_placeCreature_2 () {
            GameBoard x(2,2, std::cout);
            Creature y(&x, FOOD, {0,0,NORTH});
            Creature z(&x, HOPPER, {0,0,NORTH});
            bool test = x.placeCreature(&y, {0,0,NORTH});
            CPPUNIT_ASSERT(test);
            CPPUNIT_ASSERT(x.board[0][0] == &y);
            test = x.placeCreature(&z, {0,0,NORTH});
            CPPUNIT_ASSERT(!test);
            CPPUNIT_ASSERT(x.board[0][0] == &y);}
        // ---------------
        // test_placeCreature_3
        // ---------------
        void test_placeCreature_3 () {
            GameBoard x(2,2, std::cout);
            Creature y(&x, FOOD, {0,0,NORTH});
            Creature z(&x, HOPPER, {1,1,EAST});
            bool test = x.placeCreature(&y, {0,0,NORTH});
            CPPUNIT_ASSERT(test);
            CPPUNIT_ASSERT(x.board[0][0] == &y);
            test = x.placeCreature(&z, {1,1,EAST});
            CPPUNIT_ASSERT(test);
            CPPUNIT_ASSERT(x.board[1][1] == &z);}

    // --------------------------
    // Test GameBoard Print
    // --------------------------
        // ---------------
        // test_gb_print_1
        // ---------------
        void test_gb_print_1 () {
            std::ostringstream w;
            GameBoard x(2,2, w);
            x.print();
            CPPUNIT_ASSERT(w.str() == "  01\n0 ..\n1 ..\n");}
        // ---------------
        // test_gb_print_2
        // ---------------
        void test_gb_print_2 () {
            std::ostringstream w;
            GameBoard x(2,2, w);
            Creature y(&x, FOOD, {0,0,NORTH});
            x.placeCreature(&y, {0,0,NORTH});
            x.print();
            CPPUNIT_ASSERT(w.str() == "  01\n0 f.\n1 ..\n");}
        // ---------------
        // test_gb_print_3
        // ---------------
        void test_gb_print_3 () {
            std::ostringstream w;
            GameBoard x(2,2, w);
            Creature y(&x, FOOD, {0,0,NORTH});
            Creature z(&x, HOPPER, {1,1,EAST});
            x.placeCreature(&y, {0,0,NORTH});
            x.placeCreature(&z, {1,1,EAST});
            x.print();
            CPPUNIT_ASSERT(w.str() == "  01\n0 f.\n1 .h\n");}
        // ---------------
        // test_gb_print_4
        // ---------------
        void test_gb_print_4 () {
            std::ostringstream w;
            GameBoard x(2,2, w);
            Creature y(&x, HOPPER, {0,0,SOUTH});
            Creature z(&x, FOOD, {1,1,EAST});
            x.placeCreature(&y, {0,0,SOUTH});
            x.placeCreature(&z, {1,1,EAST});
            x.executeMove(y.turn());
            x.print();
            CPPUNIT_ASSERT(w.str() == "  01\n0 ..\n1 hf\n");}

    // --------------------------
    // Test GameBoard isSpaceEnemy
    // --------------------------
        // -------------------
        // test_isSpaceEnemy_1
        // -------------------
        void test_isSpaceEnemy_1 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( !x.isSpaceEnemy(l, z.toChar()) );}
        // -------------------
        // test_isSpaceEnemy_2
        // -------------------
        void test_isSpaceEnemy_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( !x.isSpaceEnemy(l, z.toChar()) );}            
        // -------------------
        // test_isSpaceEnemy_3
        // -------------------
        void test_isSpaceEnemy_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {1,0,NORTH};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            CPPUNIT_ASSERT( x.isSpaceEnemy(l, z.toChar()) );}
        // -------------------
        // test_isSpaceEnemy_4
        // -------------------
        void test_isSpaceEnemy_4 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {1,0,NORTH};
            Creature y(&x, HOPPER, l2);
            x.placeCreature(&y, l2);
            CPPUNIT_ASSERT( !x.isSpaceEnemy(l, z.toChar()) );}

    // --------------------------------
    // Test GameBoard isCorrectLocation
    // --------------------------------
        // ------------------------
        // test_isCorrectLocation_1
        // ------------------------
        void test_isCorrectLocation_1 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( x.isCorrectLocation(l, z.toChar()) );}
        // ------------------------
        // test_isCorrectLocation_2
        // ------------------------
        void test_isCorrectLocation_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( !x.isCorrectLocation({1,1,EAST}, z.toChar()) );}
        // ------------------------
        // test_isCorrectLocation_3
        // ------------------------        
        void test_isCorrectLocation_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( !x.isCorrectLocation({1,1,EAST}, z.toChar()) );}
        // ------------------------
        // test_isCorrectLocation_4
        // ------------------------        
        void test_isCorrectLocation_4 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            Creature y(&x, FOOD, {0,1,NORTH});
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( !x.isCorrectLocation(l, y.toChar()) );}

    // ------------------------
    // Test GameBoard turnOrder
    // ------------------------
        // ------------------------
        // test_turnOrder_1
        // ------------------------
        void test_turnOrder_1 () {
            GameBoard x(2,2, std::cout);
            CPPUNIT_ASSERT( x.turnOrder().size() == 0 );}
        // ------------------------
        // test_turnOrder_2
        // ------------------------
        void test_turnOrder_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            queue<Creature*> to = x.turnOrder();
            CPPUNIT_ASSERT( to.size() == 1 );
            CPPUNIT_ASSERT( to.front() == &z );}
        // ------------------------
        // test_turnOrder_3
        // ------------------------
        void test_turnOrder_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,NORTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            l = {1,1,EAST};
            Creature y(&x, FOOD, {0,1,NORTH});
            x.placeCreature(&y, l);
            l = {1,0,EAST};
            Creature w(&x, TRAP, l);
            x.placeCreature(&w, l);
            queue<Creature*> to = x.turnOrder();
            CPPUNIT_ASSERT( to.size() == 3 );
            CPPUNIT_ASSERT( to.front() == &z );
            to.pop();
            CPPUNIT_ASSERT( to.front() == &w );
            to.pop();
            CPPUNIT_ASSERT( to.front() == &y );}

    // ------------------------
    // Test GameBoard isValidMove
    // ------------------------
        // ------------------------
        // test_isValidMove_1
        // ------------------------
        void test_isValidMove_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( x.isValidMove({HOP, l}, z.toChar()) );}
        // ------------------------
        // test_isValidMove_2
        // ------------------------
        void test_isValidMove_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( x.isValidMove({RIGHT, l}, z.toChar()) );}
        // ------------------------
        // test_isValidMove_3
        // ------------------------
        void test_isValidMove_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,SOUTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            l = {0,1,EAST};
            Creature y(&x, FOOD, l);
            x.placeCreature(&y, l);
            CPPUNIT_ASSERT( x.isValidMove({INFECT, {0,0,SOUTH}}, z.toChar()) );}

    // ------------------------
    // Test GameBoard executeMove
    // ------------------------
        // ------------------------
        // test_executeMove_1
        // ------------------------
        void test_executeMove_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,SOUTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( x.board[0][0] == &z );
            CPPUNIT_ASSERT( x.executeMove({HOP, l}) );
            CPPUNIT_ASSERT( x.board[0][0] == NULL );
            CPPUNIT_ASSERT( x.board[1][0] == &z );}
        // ------------------------
        // test_executeMove_2
        // ------------------------
        void test_executeMove_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            CPPUNIT_ASSERT( x.board[0][0] == &z );
            CPPUNIT_ASSERT( x.executeMove({RIGHT, l}) );
            CPPUNIT_ASSERT( x.board[0][0] == &z );}
        // ------------------------
        // test_executeMove_3
        // ------------------------
        void test_executeMove_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,SOUTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {0,1,NORTH};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            CPPUNIT_ASSERT( x.board[1][0] != NULL && x.board[1][0]->toChar() == 'f' );
            CPPUNIT_ASSERT( x.executeMove({INFECT, l}) );
            CPPUNIT_ASSERT( x.board[1][0] != NULL && x.board[1][0]->toChar() == 'h' );
            CPPUNIT_ASSERT( x.board[1][0] != NULL && x.board[1][0]->pc == 0 );
            CPPUNIT_ASSERT( x.board[1][0] == &y && x.board[1][0] != &z );}

    // ---------------------
    // Creature MoveRequests
    // ---------------------
        // ------------------------
        // test_hop_1
        // ------------------------
        void test_hop_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.hop();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == HOP);}
        // ------------------------
        // test_hop_2
        // ------------------------
        void test_hop_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.hop();
            CPPUNIT_ASSERT(mr.loc.x == 0 && mr.loc.y == 0 && mr.loc.dir == 0);
            CPPUNIT_ASSERT(mr.move == 0);}
        // ------------------------
        // test_hop_3
        // ------------------------
        void test_hop_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,SOUTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {0,1,EAST};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            MoveRequest mr = z.hop();
            CPPUNIT_ASSERT(mr.loc.x == 0 && mr.loc.y == 0 && mr.loc.dir == 0);
            CPPUNIT_ASSERT(mr.move == 0);}
        // ------------------------
        // test_right_1
        // ------------------------
        void test_right_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.right();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == RIGHT);}
        // ------------------------
        // test_right_2
        // ------------------------
        void test_right_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.right();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == RIGHT);}
        // ------------------------
        // test_right_3
        // ------------------------
        void test_right_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {0,1,EAST};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            MoveRequest mr = z.right();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == RIGHT);}
        // ------------------------
        // test_left_1
        // ------------------------
        void test_left_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.left();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == LEFT);}
        // ------------------------
        // test_left_2
        // ------------------------
        void test_left_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.left();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == LEFT);}
        // ------------------------
        // test_left_3
        // ------------------------
        void test_left_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {0,1,EAST};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            MoveRequest mr = z.left();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == LEFT);}
        // ------------------------
        // test_infect_1
        // ------------------------
        void test_infect_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.infect();
            CPPUNIT_ASSERT(mr.loc.x == 0 && mr.loc.y == 0 && mr.loc.dir == 0);
            CPPUNIT_ASSERT(mr.move == 0);}
        // ------------------------
        // test_infect_2
        // ------------------------
        void test_infect_2 () {
            GameBoard x(1,1, std::cout);
            Location l = {0,0,EAST};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            MoveRequest mr = z.infect();
            CPPUNIT_ASSERT(mr.loc.x == 0 && mr.loc.y == 0 && mr.loc.dir == 0);
            CPPUNIT_ASSERT(mr.move == 0);}
        // ------------------------
        // test_infect_3
        // ------------------------
        void test_infect_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0,0,SOUTH};
            Creature z(&x, HOPPER, l);
            x.placeCreature(&z, l);
            Location l2 = {0,1,EAST};
            Creature y(&x, FOOD, l2);
            x.placeCreature(&y, l2);
            MoveRequest mr = z.infect();
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(mr.move == INFECT);}

    // --------------
    // Creature::turn
    // --------------
        // -----------
        // test_turn_1
        // -----------
        void test_turn_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, SOUTH};
            Creature h(&x, HOPPER, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.turn();
            CPPUNIT_ASSERT(mr.move == HOP);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);      
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 1 && h.loc.dir == SOUTH);}
        // -----------
        // test_turn_2
        // -----------
        void test_turn_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, EAST};
            Creature h(&x, FOOD, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.turn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == 1);}
        // -----------
        // test_turn_3
        // -----------
        void test_turn_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, EAST};
            Creature h(&x, TRAP, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.turn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 2);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == 1);}


    // -----------
    // Creature::HopperTurn
    // -----------
        // -----------------
        // test_hopperturn_1
        // -----------------
        void test_hopperturn_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, SOUTH};
            Creature h(&x, HOPPER, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.HopperTurn();
            CPPUNIT_ASSERT(mr.move == HOP);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 1 && h.loc.dir == SOUTH);}
        // -----------------
        // test_hopperturn_2
        // -----------------
        void test_hopperturn_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0,NORTH};
            Creature h(&x, HOPPER, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.HopperTurn();
            CPPUNIT_ASSERT(mr.move == 0);
            CPPUNIT_ASSERT(mr.loc.x == 0 && mr.loc.y == 0 && mr.loc.dir == 0);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == NORTH);}
        // -----------------
        // test_hopperturn_3
        // -----------------
        void test_hopperturn_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, SOUTH};
            Creature h(&x, HOPPER, l);
            h.pc = 1;
            x.placeCreature(&h, l);
            MoveRequest mr = h.HopperTurn();
            CPPUNIT_ASSERT(mr.move == HOP);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 1 && h.loc.dir == SOUTH);}

    // -----------
    // Creature::FoodTurn
    // -----------

        // -----------------
        // test_foodturn_1
        // -----------------
        void test_foodturn_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, EAST};
            Creature h(&x, FOOD, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.FoodTurn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == 1);}
        // -----------------
        // test_hopperturn_2
        // -----------------
        void test_foodturn_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0,NORTH};
            Creature h(&x, FOOD, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.FoodTurn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == WEST);}
        // -----------------
        // test_foodturn_3
        // -----------------
        void test_foodturn_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {1, 1, WEST};
            Creature h(&x, FOOD, l);
            h.pc = 1;
            x.placeCreature(&h, l);
            MoveRequest mr = h.FoodTurn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 1);
            CPPUNIT_ASSERT(h.loc.x == 1 && h.loc.y == 1 && h.loc.dir == SOUTH);}

    // -----------
    // Trap::TrapTurn
    // -----------

        // -----------------
        // test_trapturn_1
        // -----------------
        void test_trapturn_1 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, EAST};
            Creature h(&x, TRAP, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.TrapTurn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 2);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == 1);}
        // -----------------
        // test_trapturn_2
        // -----------------
        void test_trapturn_2 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, SOUTH};
            Creature h(&x, TRAP, l);
            x.placeCreature(&h, l);
            Creature f(&x, FOOD, {0, 1,NORTH});
            x.placeCreature(&f, {0,1,NORTH});
            MoveRequest mr = h.TrapTurn();
            CPPUNIT_ASSERT(mr.move == INFECT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 4);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == SOUTH);}
        // -----------------
        // test_trapturn_3
        // -----------------
        void test_trapturn_3 () {
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, WEST};
            Creature h(&x, TRAP, l);
            x.placeCreature(&h, l);
            Creature f(&x, FOOD, {0, 1,NORTH});
            x.placeCreature(&f, {0,1,NORTH});
            MoveRequest mr = h.TrapTurn();
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 2);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == SOUTH);
            mr = h.turn();
            l = mr.loc;
            CPPUNIT_ASSERT(mr.move == INFECT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 4);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == SOUTH);}

    // -----------
    // Creature::RoverTurn
    // -----------

        // -----------------
        // test_roverturn_1
        // -----------------
        void test_roverturn_1 () {
            srand(0);
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, EAST};
            Creature h(&x, ROVER, l);
            x.placeCreature(&h, l);
            MoveRequest mr = h.RoverTurn();
            CPPUNIT_ASSERT(mr.move == HOP);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 8);
            CPPUNIT_ASSERT(h.loc.x == 1 && h.loc.y == 0 && h.loc.dir == EAST);}
        // -----------------
        // test_roverturn_2
        // -----------------
        void test_roverturn_2 () {
            srand(0);
            GameBoard x(2,2, std::cout);
            Location l = {0, 0, SOUTH};
            Creature h(&x, ROVER, l);
            x.placeCreature(&h, l);
            Creature f(&x, FOOD, {0, 1,NORTH});
            x.placeCreature(&f, {0,1,NORTH});
            MoveRequest mr = h.RoverTurn();
            CPPUNIT_ASSERT(mr.move == INFECT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 10);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == SOUTH);}
        // -----------------
        // test_roverturn_3
        // -----------------
        void test_roverturn_3 () {
            srand(0);
            GameBoard x(2,2, std::cout);
            Location l = {0, 0,NORTH};
            Creature h(&x, ROVER, l);
            x.placeCreature(&h, l);
            Creature f(&x, ROVER, {1, 0,NORTH});
            x.placeCreature(&f, {1,0,NORTH});
            MoveRequest mr = h.RoverTurn();
            CPPUNIT_ASSERT(mr.move == RIGHT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && mr.loc.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 6);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == EAST);
            mr = h.turn();
            l = mr.loc;
            CPPUNIT_ASSERT(mr.move == LEFT);
            CPPUNIT_ASSERT(mr.loc.x == l.x && mr.loc.y == l.y && l.dir == l.dir);
            CPPUNIT_ASSERT(h.pc == 4);
            CPPUNIT_ASSERT(h.loc.x == 0 && h.loc.y == 0 && h.loc.dir == NORTH);}

    // ----------
    // Game::Game
    // ----------
        // -----------
        // test_game_1
        // -----------
        void test_game_1 () {
            Game g(1,2,std::cout);
            CPPUNIT_ASSERT(g.gameBoard.height == 1);
            CPPUNIT_ASSERT(g.gameBoard.width == 2);
            CPPUNIT_ASSERT(g.roundNum == 0);
            CPPUNIT_ASSERT(g.w == std::cout);}
        // -----------
        // test_game_2
        // -----------
        void test_game_2 () {
            Game g(8,8,std::cout);
            CPPUNIT_ASSERT(g.gameBoard.height == 8);
            CPPUNIT_ASSERT(g.gameBoard.width == 8);
            CPPUNIT_ASSERT(g.roundNum == 0);
            CPPUNIT_ASSERT(g.w == std::cout);}
        // -----------
        // test_game_3
        // -----------
        void test_game_3 () {
            Game g(8,8,std::cout);
            CPPUNIT_ASSERT(g.gameBoard.height == 8);
            CPPUNIT_ASSERT(g.gameBoard.width == 8);
            CPPUNIT_ASSERT(g.roundNum == 0);
            CPPUNIT_ASSERT(g.w == std::cout);}

    // ----------
    // Game::addCreature
    // ----------
        // ------------------
        // test_addCreature_1
        // ------------------
        void test_addCreature_1 () {
            Game g(1,2,std::cout);
            Location l = {0,0,NORTH};
            CPPUNIT_ASSERT(g.addCreature(FOOD, l));
            CPPUNIT_ASSERT(g.creatures.front().toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == &g.creatures.front());
        }
        // ------------------
        // test_addCreature_2
        // ------------------
        void test_addCreature_2 () {
            Game g(1,2,std::cout);
            Location l = {0,0,NORTH};
            CPPUNIT_ASSERT(g.addCreature(FOOD, l));
            CPPUNIT_ASSERT(g.creatures.front().toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == &g.creatures.front());
            l = {0,1,EAST};
            CPPUNIT_ASSERT(g.addCreature(HOPPER, l));
            CPPUNIT_ASSERT(g.creatures.back().toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] != NULL && g.gameBoard.board[0][1]->toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] == &g.creatures.back());
        }
        // ------------------
        // test_addCreature_3
        // ------------------
        void test_addCreature_3 () {
            Game g(1,2,std::cout);
            Location l = {0,0,NORTH};
            CPPUNIT_ASSERT(g.addCreature(FOOD, l));
            CPPUNIT_ASSERT(g.creatures.front().toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == &g.creatures.front());
            try{
                CPPUNIT_ASSERT(!g.addCreature(HOPPER, l));
                assert(false);
            }
            catch(const invalid_argument&) {
                assert(true);
            }
            CPPUNIT_ASSERT(g.creatures.front().toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == &g.creatures.front());
            CPPUNIT_ASSERT(g.creatures.size() == 1);
        }

    // ----------
    // Game::runRound
    // ----------
        // ------------------
        // test_runRound_1
        // ------------------
        void test_runRound_1 () {
            Game g(1,2,std::cout);
            Location l = {0,0,EAST};
            g.addCreature(HOPPER, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'h');
            g.runRound();
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] != NULL && g.gameBoard.board[0][1]->toChar() == 'h');}
        // ------------------
        // test_runRound_2
        // ------------------
        void test_runRound_2 () {
            Game g(2,2,std::cout);
            Location l = {0,0,EAST};
            g.addCreature(HOPPER, l);
            l = {1,0,NORTH};
            g.addCreature(FOOD, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'h');
            g.runRound();
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] != NULL && g.gameBoard.board[0][1]->toChar() == 'h');}
        // ------------------
        // test_runRound_2
        // ------------------
        void test_runRound_3 () {
            Game g(2,2,std::cout);
            Location l = {0,0,EAST};
            g.addCreature(HOPPER, l);
            l = {1,0,NORTH};
            g.addCreature(FOOD, l);
            l = {1,1,NORTH};
            g.addCreature(TRAP, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'h');
            g.runRound();
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] != NULL && g.gameBoard.board[0][1]->toChar() == 't');
            CPPUNIT_ASSERT(g.gameBoard.board[1][0] != NULL && g.gameBoard.board[1][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[1][1] != NULL && g.gameBoard.board[1][1]->toChar() == 't');}

    // ----------
    // Game::runNRounds
    // ----------
        // ------------------
        // test_runNRounds_1
        // ------------------
        void test_runNRounds_1 () {
            Game g(1,3,std::cout);
            Location l = {0,0,EAST};
            g.addCreature(HOPPER, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'h');
            g.runNRounds(2,0);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][2] != NULL && g.gameBoard.board[0][2]->toChar() == 'h');}
        // ------------------
        // test_runNRounds_2
        // ------------------
        void test_runNRounds_2 () {
            Game g(1,3,std::cout);
            Location l = {0,0,EAST};
            g.addCreature(FOOD, l);
            l = {0,1,NORTH};
            g.addCreature(TRAP, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            g.runNRounds(3,0);
            CPPUNIT_ASSERT(g.gameBoard.board[0][1] != NULL && g.gameBoard.board[0][1]->toChar() == 't');
            CPPUNIT_ASSERT(g.gameBoard.board[0][2] == NULL);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 't');}
        // ------------------
        // test_runNRounds_3
        // ------------------
        void test_runNRounds_3 () {
            Game g(3,3,std::cout);
            Location l = {0,0,SOUTH};
            g.addCreature(HOPPER, l);
            l = {1,1,WEST};
            g.addCreature(TRAP, l);
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'h');
            g.runNRounds(3,0);
            CPPUNIT_ASSERT(g.gameBoard.board[1][0] != NULL && g.gameBoard.board[1][0]->toChar() == 't');
            CPPUNIT_ASSERT(g.gameBoard.board[2][0] == NULL);}

        void test_run_1 () {
            Game g(8,8,std::cout);
            g.addCreature(FOOD, {0,0,EAST});
            g.addCreature(HOPPER, {3,3,NORTH});
            g.addCreature(HOPPER, {3,4,EAST});
            g.addCreature(HOPPER, {4,4,SOUTH});
            g.addCreature(HOPPER, {4,3,WEST});
            g.addCreature(FOOD, {7,7,NORTH});
            g.runNRounds(5,0);
            CPPUNIT_ASSERT(g.gameBoard.board[0][3] != NULL && g.gameBoard.board[0][3]->toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[3][7] != NULL && g.gameBoard.board[3][7]->toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[4][0] != NULL && g.gameBoard.board[4][0]->toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[7][4] != NULL && g.gameBoard.board[7][4]->toChar() == 'h');
            CPPUNIT_ASSERT(g.gameBoard.board[0][0] != NULL && g.gameBoard.board[0][0]->toChar() == 'f');
            CPPUNIT_ASSERT(g.gameBoard.board[7][7] != NULL && g.gameBoard.board[7][7]->toChar() == 'f');
        }
        void test_run_2 () {
            Game g(7,9,std::cout);
            g.addCreature(TRAP, {0,0,SOUTH});
            g.addCreature(HOPPER, {3,2,EAST});
            g.addCreature(ROVER, {5,4,NORTH});
            g.addCreature(TRAP, {6,8,WEST});
            g.runNRounds(2,0);
            CPPUNIT_ASSERT(g.gameBoard.board[3][4] != NULL && g.gameBoard.board[3][4]->toChar() == 'r');
            CPPUNIT_ASSERT(g.gameBoard.board[3][4] != NULL && g.gameBoard.board[3][4]->loc.dir == EAST);
        }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_toChar_1);
    CPPUNIT_TEST(test_toChar_2);
    CPPUNIT_TEST(test_toChar_3);
    CPPUNIT_TEST(test_gb_construct_1);
    CPPUNIT_TEST(test_gb_construct_2);
    CPPUNIT_TEST(test_gb_construct_3);
    CPPUNIT_TEST(test_isSpaceWall_1);
    CPPUNIT_TEST(test_isSpaceWall_2);
    CPPUNIT_TEST(test_isSpaceWall_3);
    CPPUNIT_TEST(test_isSpaceEmpty_1);
    CPPUNIT_TEST(test_isSpaceEmpty_2);
    CPPUNIT_TEST(test_isSpaceEmpty_3);
    CPPUNIT_TEST(test_placeCreature_1);
    CPPUNIT_TEST(test_placeCreature_2);
    CPPUNIT_TEST(test_placeCreature_3);
    CPPUNIT_TEST(test_gb_print_1);
    CPPUNIT_TEST(test_gb_print_2);
    CPPUNIT_TEST(test_gb_print_3);
    CPPUNIT_TEST(test_gb_print_4);
    CPPUNIT_TEST(test_isSpaceEnemy_1);
    CPPUNIT_TEST(test_isSpaceEnemy_2);
    CPPUNIT_TEST(test_isSpaceEnemy_3);
    CPPUNIT_TEST(test_isSpaceEnemy_4);
    CPPUNIT_TEST(test_isCorrectLocation_1);
    CPPUNIT_TEST(test_isCorrectLocation_2);
    CPPUNIT_TEST(test_isCorrectLocation_3);
    CPPUNIT_TEST(test_isCorrectLocation_4);
    CPPUNIT_TEST(test_turnOrder_1);
    CPPUNIT_TEST(test_turnOrder_2);
    CPPUNIT_TEST(test_turnOrder_3);
    CPPUNIT_TEST(test_isValidMove_1);
    CPPUNIT_TEST(test_isValidMove_2);
    CPPUNIT_TEST(test_isValidMove_3);
    CPPUNIT_TEST(test_executeMove_1);
    CPPUNIT_TEST(test_executeMove_2);
    CPPUNIT_TEST(test_executeMove_3);
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_right_1);
    CPPUNIT_TEST(test_right_2);
    CPPUNIT_TEST(test_right_3);
    CPPUNIT_TEST(test_left_1);
    CPPUNIT_TEST(test_left_2);
    CPPUNIT_TEST(test_left_3);
    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);
    CPPUNIT_TEST(test_turn_1);
    CPPUNIT_TEST(test_turn_2);
    CPPUNIT_TEST(test_turn_3);
    CPPUNIT_TEST(test_hopperturn_1);
    CPPUNIT_TEST(test_hopperturn_2);
    CPPUNIT_TEST(test_hopperturn_3);
    CPPUNIT_TEST(test_foodturn_1);
    CPPUNIT_TEST(test_foodturn_2);
    CPPUNIT_TEST(test_foodturn_3);
    CPPUNIT_TEST(test_trapturn_1);
    CPPUNIT_TEST(test_trapturn_2);
    CPPUNIT_TEST(test_trapturn_3);
    CPPUNIT_TEST(test_roverturn_1);
    CPPUNIT_TEST(test_roverturn_2);
    CPPUNIT_TEST(test_roverturn_3);
    CPPUNIT_TEST(test_game_1);
    CPPUNIT_TEST(test_game_2);
    CPPUNIT_TEST(test_game_3);
    CPPUNIT_TEST(test_addCreature_1);
    CPPUNIT_TEST(test_addCreature_2);
    CPPUNIT_TEST(test_addCreature_3);
    CPPUNIT_TEST(test_runRound_1);
    CPPUNIT_TEST(test_runRound_2);
    CPPUNIT_TEST(test_runRound_3);
    CPPUNIT_TEST(test_runNRounds_1);
    CPPUNIT_TEST(test_runNRounds_2);
    CPPUNIT_TEST(test_runNRounds_3);
    CPPUNIT_TEST(test_run_1);
    CPPUNIT_TEST(test_run_2);
    CPPUNIT_TEST_SUITE_END();};


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
    return 0;}