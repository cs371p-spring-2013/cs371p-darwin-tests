#include <queue>
#include <vector>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
//#define class struct

#include "Darwin.h"

using namespace std;

struct TestDarwin : CppUnit::TestFixture {

    
    void test_bounds_1() {
        Board b(5, 5);
        CPPUNIT_ASSERT(b.outOfBounds(make_pair(0,0)) == false);
    }

    void test_bounds_2() {
        Board b(3, 3);
        CPPUNIT_ASSERT(b.outOfBounds(make_pair(0, 3)) == true);
    }

    void test_bounds_3() {
        Board b(4, 4);
        CPPUNIT_ASSERT(b.outOfBounds(make_pair(100, 100)) == true);
    }
        
    void test_species_1() {
        Creature c(food);
        CPPUNIT_ASSERT(c == 'f'); 
    }

    void test_species_2() {
        Creature c;
        CPPUNIT_ASSERT(c == '.');
    }
  
    void test_species_3() {
        Creature c(hopper);
        CPPUNIT_ASSERT(c == 'h');
    }

    void test_place_1() {
        Board b(3,3);
        b.placeCreature(Creature(food), north, 0, 0);
        CPPUNIT_ASSERT(b.board[0][0] == 'f');
        CPPUNIT_ASSERT(b.board[0][1] == '.');
    }

    void test_place_2() {
        Board b(3,3);
        b.placeCreature(Creature(hopper), north, 0, 0);
        b.placeCreature(Creature(food), north, 0, 1);
        CPPUNIT_ASSERT(b.board[0][0] == 'h');
        CPPUNIT_ASSERT(b.board[0][1] == 'f');
    }

    void test_place_3() {
        Board b(2,2);
        b.placeCreature(Creature(rover), north, 1, 1);
        CPPUNIT_ASSERT(b.board[1][1] == 'r');
        ostringstream o;
        o << b;
        CPPUNIT_ASSERT(o.str() == "  01\n0 ..\n1 .r\n\n");
    } 

    void test_control_1() {
        Board b(3, 3);
     
        // the current coordinates at which the board calculates incoming control and action requests
        // is initially set to 0,0
        b.placeCreature(Creature(hopper), north, 0, 0);

        CPPUNIT_ASSERT(b.checkControl(if_wall) == true);
        CPPUNIT_ASSERT(b.checkControl(if_enemy) == false);
        CPPUNIT_ASSERT(b.checkControl(if_empty) == false);
    }

    void test_control_2() {
        Board b(3,3);
        b.placeCreature(Creature(hopper), south, 0, 0);
        CPPUNIT_ASSERT(b.checkControl(if_wall)  == false);
        CPPUNIT_ASSERT(b.checkControl(if_enemy) == false);
        CPPUNIT_ASSERT(b.checkControl(if_empty) == true);
    }

    void test_control_3() {
        Board b(3,3);
        b.placeCreature(Creature(hopper), east, 0, 0);
        b.placeCreature(Creature(food), south, 0, 1);

        CPPUNIT_ASSERT(b.checkControl(if_wall) == false);
        CPPUNIT_ASSERT(b.checkControl(if_enemy) == true);
        CPPUNIT_ASSERT(b.checkControl(if_empty) == false);
    }

    void test_action_1() {
        Board b(3,3);
        // food is used to emphasize that the actual creature program is not running
        b.placeCreature(Creature(food), south, 0, 0);
        bool success = b.tryAction(hop);
     
        CPPUNIT_ASSERT(success = true);
        CPPUNIT_ASSERT(b.board[0][0] == '.');
        CPPUNIT_ASSERT(b.board[0][0] != 'f');
        CPPUNIT_ASSERT(b.board[1][0] == 'f');
        CPPUNIT_ASSERT(b.board[1][0].dir == south);
    }


    void test_action_2() {
        Board b(3,3);
        b.placeCreature(Creature(hopper), south, 0, 0);
        bool success = b.tryAction(turnleft);

        CPPUNIT_ASSERT(true == success);
        CPPUNIT_ASSERT(b.board[0][0] == 'h');
        CPPUNIT_ASSERT(b.board[0][0].dir == east);
        
        success = b.tryAction(turnleft);
        CPPUNIT_ASSERT(true == success);
        CPPUNIT_ASSERT(b.board[0][0].dir == north);
    
        success = b.tryAction(hop);
        CPPUNIT_ASSERT(false == success);
        CPPUNIT_ASSERT(b.board[0][0] == 'h');
        CPPUNIT_ASSERT(b.board[0][0].dir == north);
      
    }

    void test_action_3() {
        Board b(3,3);
        
        b.placeCreature(Creature(hopper), south, 0, 0);
        b.placeCreature(Creature(food), north, 1, 0);
    
        bool success = b.tryAction(infect);
        CPPUNIT_ASSERT(true == success);
        CPPUNIT_ASSERT(b.board[0][0] == 'h');
        CPPUNIT_ASSERT(b.board[1][0] == 'h');
    }

    void test_move_1() {
        Board b (3,3);
	b.placeCreature(Creature(food), south, 0, 0);
	b.board[0][0].move(&b);
	CPPUNIT_ASSERT(b.board[0][0].dir == east);
        CPPUNIT_ASSERT(b.board[0][0].pc ==1);
    }  
   
    void test_move_2() {
        Board b (3,3);
	b.placeCreature(Creature(hopper), east, 0, 0);
	b.board[0][0].move(&b);
        CPPUNIT_ASSERT(b.board[0][1] == 'h');
        CPPUNIT_ASSERT(b.board[0][0] == '.');
	CPPUNIT_ASSERT(b.board[0][1].dir == east);
        CPPUNIT_ASSERT(b.board[0][1].pc ==1);
    }  

    void test_move_3() {
        Board b (3,3);
	b.placeCreature(Creature(rover), south, 0, 0);
	b.board[0][0].move(&b);
        CPPUNIT_ASSERT(b.board[1][0] == 'r');
        CPPUNIT_ASSERT(b.board[0][0] == '.');
	CPPUNIT_ASSERT(b.board[1][0].dir == south);
        CPPUNIT_ASSERT(b.board[1][0].pc ==8);
    }  

    void test_ahead_1() {
        Board b (3,3);
	b.placeCreature(Creature(food), south, 0, 0);
	pair<int, int> spaceAhead = b.getSpaceAhead();
	CPPUNIT_ASSERT(spaceAhead.first == 1);
	CPPUNIT_ASSERT(spaceAhead.second == 0);
    }

    void test_ahead_2() {
        Board b (3,3);
	b.placeCreature(Creature(food), east, 0, 0);
	pair<int, int> spaceAhead = b.getSpaceAhead();
	CPPUNIT_ASSERT(spaceAhead.first == 0);
	CPPUNIT_ASSERT(spaceAhead.second == 1);
    }

    void test_ahead_3() {
        Board b (3,3);
	b.placeCreature(Creature(food), west, 2, 2);
	b.currentCoords.first = 2;
	b.currentCoords.second = 2;
	pair<int, int> spaceAhead = b.getSpaceAhead();
	CPPUNIT_ASSERT(spaceAhead.first == 2);
	CPPUNIT_ASSERT(spaceAhead.second == 1);
    }

    CPPUNIT_TEST_SUITE(TestDarwin);
    
    CPPUNIT_TEST(test_bounds_1);
    CPPUNIT_TEST(test_bounds_2);
    CPPUNIT_TEST(test_bounds_3);
    CPPUNIT_TEST(test_species_1);
    CPPUNIT_TEST(test_species_2);
    CPPUNIT_TEST(test_species_3);
    CPPUNIT_TEST(test_place_1);
    CPPUNIT_TEST(test_place_2);
    CPPUNIT_TEST(test_place_3);
    CPPUNIT_TEST(test_control_1);
    CPPUNIT_TEST(test_control_2);
    CPPUNIT_TEST(test_control_3);
    CPPUNIT_TEST(test_action_1);
    CPPUNIT_TEST(test_action_2);
    CPPUNIT_TEST(test_action_3); 
    CPPUNIT_TEST(test_move_1);
    CPPUNIT_TEST(test_move_2);
    CPPUNIT_TEST(test_move_3);
    CPPUNIT_TEST(test_ahead_1); 
    CPPUNIT_TEST(test_ahead_2); 
    CPPUNIT_TEST(test_ahead_3); 

 
    CPPUNIT_TEST_SUITE_END();
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();
   
    cout << "Done." << endl;
    return 0;
}
