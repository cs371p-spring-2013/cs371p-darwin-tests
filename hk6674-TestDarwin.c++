//---------------
// cs371p/cs371p-darwin
// Copyright (C) 2013
// Hyunchel Kim
//---------------

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
#include <vector>   // vector

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#include "Darwin.h"


// #define class struct
// #extern vector
using namespace std;
// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

    // -----
    // position
    // -----

    void testing_1 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        // test contructor
        // x_size and y_size are decremented by 1 (indices)
        CPPUNIT_ASSERT(pos1.x_size == x-1);
        CPPUNIT_ASSERT(pos1.y_size == y-1);
        CPPUNIT_ASSERT(x == pos1.board.size());
        CPPUNIT_ASSERT(y == pos1.board[0].size());
    }

    void testing_2 () {
        int x = 1000;
        int y = 1000;
        darwin_position pos1(x, y);
        // test contructor
        // x_size and y_size are decremented by 1 (indices)
        CPPUNIT_ASSERT(pos1.x_size == x-1);
        CPPUNIT_ASSERT(pos1.y_size == y-1);

        CPPUNIT_ASSERT(x == pos1.board.size());
        CPPUNIT_ASSERT(y == pos1.board[0].size());
    }

    void testing_3 () {
        int x = 1;
        int y = 1;
        darwin_position pos1(x, y);
        // test contructor
        // x_size and y_size are decremented by 1 (indices)
        CPPUNIT_ASSERT(pos1.x_size == x-1);
        CPPUNIT_ASSERT(pos1.y_size == y-1);

        CPPUNIT_ASSERT(x == pos1.board.size());
        CPPUNIT_ASSERT(y == pos1.board[0].size());
    }

    void testing_4 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        // tes for valid orig
        CPPUNIT_ASSERT(pos1.board[0][0] == '.');
        CPPUNIT_ASSERT(pos1.board[5][5] == '.');
        CPPUNIT_ASSERT(pos1.board[7][7] == '.');
    }

    void testing_5 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_valid_move(0,0,2));
        CPPUNIT_ASSERT(pos1.darwin_valid_move(0,0,3));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(0,0,0));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(0,0,1));
    }
    
    void testing_6 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_valid_move(7,0,0));
        CPPUNIT_ASSERT(pos1.darwin_valid_move(7,0,3));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(7,0,1));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(7,0,2));
    }    

    void testing_7 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_valid_move(7,7,1));
        CPPUNIT_ASSERT(pos1.darwin_valid_move(7,7,0));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(7,7,2));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(7,7,3));
    }

    void testing_8 () {
        int x = 8;
        int y = 8;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_valid_move(0,7,1));
        CPPUNIT_ASSERT(pos1.darwin_valid_move(0,7,2));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(0,7,0));
        CPPUNIT_ASSERT(!pos1.darwin_valid_move(0,7,3));
    }
    
    void testing_9 () {
        int x = 4;
        int y = 4;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_access_board(5,5) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(4,4) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(2,7) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(12,1) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(0,0) == '.');
        CPPUNIT_ASSERT(pos1.darwin_access_board(3,3) == '.'); 
        CPPUNIT_ASSERT(pos1.darwin_access_board(2,3) == '.');
    }

    void testing_10 () {
        int x = 4;
        int y = 4;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_access_board(25,52) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(4,3) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(22,7) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(12,12) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(1,0) == '.');
        CPPUNIT_ASSERT(pos1.darwin_access_board(3,3) == '.'); 
        CPPUNIT_ASSERT(pos1.darwin_access_board(0,3) == '.');
    }

    void testing_11 () {
        int x = 10;
        int y = 10;
        darwin_position pos1(x, y);
        CPPUNIT_ASSERT(pos1.darwin_access_board(15,15) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(14,14) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(12,7) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(2,11) == 'z');
        CPPUNIT_ASSERT(pos1.darwin_access_board(0,0) == '.');
        CPPUNIT_ASSERT(pos1.darwin_access_board(3,3) == '.'); 
        CPPUNIT_ASSERT(pos1.darwin_access_board(9,9) == '.');
    }  

    void testing_12 () {
        int x = 7;
        int y = 7;
        darwin_position pos1(x, y);

        CPPUNIT_ASSERT(pos1.board[0][0] == '.');
        pos1.darwin_modify_pos('h', 0, 0, 1, 1);
        CPPUNIT_ASSERT(pos1.board[1][1] == 'h');

        CPPUNIT_ASSERT(pos1.board[5][5] == '.');
        pos1.darwin_modify_pos('h', 5, 5, 5, 2);
        CPPUNIT_ASSERT(pos1.board[5][2] == 'h');
    }

    void testing_13 () {
        int x = 7;
        int y = 7;
        darwin_position pos1(x, y);

        CPPUNIT_ASSERT(pos1.board[2][2] == '.');
        pos1.darwin_modify_pos('r', 2, 2, 6, 6);
        CPPUNIT_ASSERT(pos1.board[6][6] == 'r');

        CPPUNIT_ASSERT(pos1.board[3][3] == '.');
        pos1.darwin_modify_pos('r', 3, 3, 6, 0);
        CPPUNIT_ASSERT(pos1.board[6][0] == 'r');
    }      

    void testing_14 () {
        int x = 7;
        int y = 7;
        darwin_position pos1(x, y);

        CPPUNIT_ASSERT(pos1.board[0][6] == '.');
        pos1.darwin_modify_pos('u', 0, 6, 6, 1);
        CPPUNIT_ASSERT(pos1.board[6][1] == 'u');

        CPPUNIT_ASSERT(pos1.board[1][5] == '.');
        pos1.darwin_modify_pos('u', 1, 5, 4, 3);
        CPPUNIT_ASSERT(pos1.board[4][3] == 'u');
    } 


    // -----
    // creatures
    // -----

    void testing_15 () {
        char identity = 'f';
        int direction = 0;
        int x = 0;
        int y = 0;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);                  
    }

    void testing_16 () {
        char identity = 'h';
        int direction = 0;
        int x = 10;
        int y = 10;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);                  
    } 

    void testing_17 () {
        char identity = 'r';
        int direction = 3;
        int x = -1;
        int y = -1;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);                  
    }  

    void testing_18 () {
        char identity = 't';
        int direction = 2;
        int x = 123;
        int y = 123;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);                  
    } 

    void testing_19 () {
        char identity = 'u';
        int direction = 1;
        int x = 12345;
        int y = -12345;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);                  
    } 

    void testing_20 () {
        char identity = 'f';
        int direction = 1;
        int x = 12345;
        int y = -12345;
        darwin_creatures c0(identity, direction, x, y);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);               
        CPPUNIT_ASSERT(c0.infected_something == false);
        CPPUNIT_ASSERT(c0.enemy_index_value == -1);
    } 

    void testing_21 () {
        char identity = 'f';
        int direction = 1;
        int x0 = 5;
        int y0 = 5;
        int x1 = 10;
        int y1 = 10;
        int x2 = 15;
        int y2 = 15;
        darwin_creatures c0(identity, direction, x0, y0);
        darwin_creatures c1(identity, direction, x1, y1);
        darwin_creatures c2(identity, direction, x2, y2);
        CPPUNIT_ASSERT(c0.identity == identity);
        CPPUNIT_ASSERT(c0.direction == direction);  
        CPPUNIT_ASSERT(c0.pos_x == x0);
        CPPUNIT_ASSERT(c0.pos_y == y0);               
        CPPUNIT_ASSERT(c0.infected_something == false);
        CPPUNIT_ASSERT(c0.enemy_index_value == -1);
        CPPUNIT_ASSERT(c1.identity == identity);
        CPPUNIT_ASSERT(c1.direction == direction);  
        CPPUNIT_ASSERT(c1.pos_x == x1);
        CPPUNIT_ASSERT(c1.pos_y == y1);               
        CPPUNIT_ASSERT(c1.infected_something == false);
        CPPUNIT_ASSERT(c1.enemy_index_value == -1);
        CPPUNIT_ASSERT(c2.identity == identity);
        CPPUNIT_ASSERT(c2.direction == direction);  
        CPPUNIT_ASSERT(c2.pos_x == x2);
        CPPUNIT_ASSERT(c2.pos_y == y2);               
        CPPUNIT_ASSERT(c2.infected_something == false);
        CPPUNIT_ASSERT(c2.enemy_index_value == -1);
    } 

   void testing_22 () {
        char identity0 = 'f';
        char identity1 = 'r';
        char identity2 = 't';

        int direction0 = 0;
        int direction1 = 1;
        int direction2 = 2;

        int x0 = 1;
        int y0 = 3;
        int x1 = 5;
        int y1 = 7;
        int x2 = 9;
        int y2 = 11;
        darwin_creatures c0(identity0, direction0, x0, y0);
        darwin_creatures c1(identity1, direction1, x1, y1);
        darwin_creatures c2(identity2, direction2, x2, y2);
        CPPUNIT_ASSERT(c0.identity == identity0);
        CPPUNIT_ASSERT(c0.direction == direction0);  
        CPPUNIT_ASSERT(c0.pos_x == x0);
        CPPUNIT_ASSERT(c0.pos_y == y0);               
        CPPUNIT_ASSERT(c0.infected_something == false);
        CPPUNIT_ASSERT(c0.enemy_index_value == -1);
        CPPUNIT_ASSERT(c1.identity == identity1);
        CPPUNIT_ASSERT(c1.direction == direction1);  
        CPPUNIT_ASSERT(c1.pos_x == x1);
        CPPUNIT_ASSERT(c1.pos_y == y1);               
        CPPUNIT_ASSERT(c1.infected_something == false);
        CPPUNIT_ASSERT(c1.enemy_index_value == -1);
        CPPUNIT_ASSERT(c2.identity == identity2);
        CPPUNIT_ASSERT(c2.direction == direction2);  
        CPPUNIT_ASSERT(c2.pos_x == x2);
        CPPUNIT_ASSERT(c2.pos_y == y2);               
        CPPUNIT_ASSERT(c2.infected_something == false);
        CPPUNIT_ASSERT(c2.enemy_index_value == -1);
    } 

    void testing_23 () {
        char identity = 't';
        int direction = 0;
        int x = 0;
        int y = 0;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.wall == false);
        c0.darwin_eval(pos0);
        CPPUNIT_ASSERT(c0.wall == true);
    } 

    void testing_24 () {
        char identity = 'r';
        int direction = 0;
        int x = 5;
        int y = 5;
        darwin_creatures c1(identity, direction, x, y);
        darwin_position pos0(8,8);


        CPPUNIT_ASSERT(c1.wall == false);
        c1.darwin_eval(pos0);
        CPPUNIT_ASSERT(c1.wall == false);
    } 

    void testing_25 () {
        char identity = 'f';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c2(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c2.empty == false);
        c2.darwin_eval(pos0);
        CPPUNIT_ASSERT(c2.empty == true);
    } 
    
    void testing_26 () {
        char identity = 'f';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);

    /*  MY Instructions
        1 = hop
        2 = left
        3 = right
        4 = infect
        5 = if_empty
        6 = if_wall
        7 = if_random
        8 = if_enemy
        9 = go 0; 
    */
        c0.darwin_load (identity);
        CPPUNIT_ASSERT(c0.instruction[0][0] == 2);
        CPPUNIT_ASSERT(c0.instruction[1][0] == 9);
    } 

    void testing_27 () {
        char identity = 'h';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);

    /*  MY Instructions
        1 = hop
        2 = left
        3 = right
        4 = infect
        5 = if_empty
        6 = if_wall
        7 = if_random
        8 = if_enemy
        9 = go 0; 
    */
        c0.darwin_load (identity);
        CPPUNIT_ASSERT(c0.instruction[0][0] == 1);
        CPPUNIT_ASSERT(c0.instruction[1][0] == 9);
    }

    void testing_28 () {
        char identity = 'r';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);

    /*  MY Instructions
        1 = hop
        2 = left
        3 = right
        4 = infect
        5 = if_empty
        6 = if_wall
        7 = if_random
        8 = if_enemy
        9 = go 0; 
    */
        c0.darwin_load (identity);
        CPPUNIT_ASSERT(c0.instruction[0][0] == 8);
        CPPUNIT_ASSERT(c0.instruction[0][1] == 9);
        CPPUNIT_ASSERT(c0.instruction[1][0] == 5);
        CPPUNIT_ASSERT(c0.instruction[1][1] == 7);
        CPPUNIT_ASSERT(c0.instruction[2][0] == 7);
        CPPUNIT_ASSERT(c0.instruction[2][1] == 5);
        CPPUNIT_ASSERT(c0.instruction[3][0] == 2);
        CPPUNIT_ASSERT(c0.instruction[4][0] == 9);                
        CPPUNIT_ASSERT(c0.instruction[5][0] == 3);                
        CPPUNIT_ASSERT(c0.instruction[6][0] == 9);                
        CPPUNIT_ASSERT(c0.instruction[7][0] == 1);                
        CPPUNIT_ASSERT(c0.instruction[8][0] == 9);                
        CPPUNIT_ASSERT(c0.instruction[9][0] == 4);                
        CPPUNIT_ASSERT(c0.instruction[10][0] == 9);                

    }

    void testing_29 () {
        char identity = 't';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);

    /*  MY Instructions
        1 = hop
        2 = left
        3 = right
        4 = infect
        5 = if_empty
        6 = if_wall
        7 = if_random
        8 = if_enemy
        9 = go 0; 
    */
        c0.darwin_load (identity);
        CPPUNIT_ASSERT(c0.instruction[0][0] == 8);
        CPPUNIT_ASSERT(c0.instruction[0][1] == 3);
        CPPUNIT_ASSERT(c0.instruction[1][0] == 2);
        CPPUNIT_ASSERT(c0.instruction[2][0] == 9);
        CPPUNIT_ASSERT(c0.instruction[3][0] == 4);
        CPPUNIT_ASSERT(c0.instruction[4][0] == 9);
    }

    void testing_30 () {
        char identity = 'u';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);

    /*  MY Instructions
        1 = hop
        2 = left
        3 = right
        4 = infect
        5 = if_empty
        6 = if_wall
        7 = if_random
        8 = if_enemy
        9 = go 0; 
    */
        c0.darwin_load (identity);
        CPPUNIT_ASSERT(c0.instruction[0][0] == 8);
        CPPUNIT_ASSERT(c0.instruction[0][1] == 9);
        CPPUNIT_ASSERT(c0.instruction[1][0] == 5);
        CPPUNIT_ASSERT(c0.instruction[1][1] == 10);
        CPPUNIT_ASSERT(c0.instruction[2][0] == 7);
        CPPUNIT_ASSERT(c0.instruction[2][1] == 7);
        CPPUNIT_ASSERT(c0.instruction[3][0] == 2);
        CPPUNIT_ASSERT(c0.instruction[4][0] == 9);
        CPPUNIT_ASSERT(c0.instruction[5][0] == 1);
        CPPUNIT_ASSERT(c0.instruction[6][0] == 9);
        CPPUNIT_ASSERT(c0.instruction[7][0] == 3);
        CPPUNIT_ASSERT(c0.instruction[8][0] == 9);
        CPPUNIT_ASSERT(c0.instruction[9][0] == 4);
        CPPUNIT_ASSERT(c0.instruction[10][0] == 9);
    }

    void testing_31 () {
        char identity = 'f';
        int direction = 0;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
        // change in eval
        c0.possible_x = 3;
        c0.possible_y = 5;
        c0.empty = true;
        c0.darwin_action_hop();
        CPPUNIT_ASSERT(c0.pos_x == 3);
        CPPUNIT_ASSERT(c0.pos_y == 5);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
    }

    void testing_32 () {
        char identity = 'r';
        int direction = 1;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
        // change in eval
        c0.possible_x = 2;
        c0.possible_y = 5;
        c0.empty = true;
        c0.darwin_action_hop();
        CPPUNIT_ASSERT(c0.pos_x == 2);
        CPPUNIT_ASSERT(c0.pos_y == 5);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
    }

    void testing_33 () {
        char identity = 't';
        int direction = 3;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
        // change in eval
        c0.possible_x = 7;
        c0.possible_y = 7;
        c0.empty = true;
        c0.darwin_action_hop();
        CPPUNIT_ASSERT(c0.pos_x == 7);
        CPPUNIT_ASSERT(c0.pos_y == 7);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
    }

    void testing_34 () {
        char identity = 't';
        int direction = 3;
        int x = 2;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
        // change in eval
        c0.possible_x = 7;
        c0.possible_y = 7;
        c0.empty = false;
        c0.darwin_action_hop();
        CPPUNIT_ASSERT(c0.pos_x == x);
        CPPUNIT_ASSERT(c0.pos_y == y);
        CPPUNIT_ASSERT(c0.prev_x == x);
        CPPUNIT_ASSERT(c0.prev_y == y);
    }

    void testing_35 () {
        char identity = 'h';
        int direction = 1;
        int x = 7;
        int y = 7;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.direction == 1);
        // change in eval
        // non required
        c0.darwin_action_left();
        CPPUNIT_ASSERT(c0.direction == 0);
    }

    void testing_36 () {
        char identity = 't';
        int direction = 0;
        int x = 7;
        int y = 7;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        // c0.darwin_load (identity);
        // c0.darwin_execute(pos0);
        CPPUNIT_ASSERT(c0.direction == 0);
        // change in eval
        // non required
        c0.darwin_action_left();
        CPPUNIT_ASSERT(c0.direction == 3);
    }

    void testing_37 () {
        char identity = 'f';
        int direction = 3;
        int x = 7;
        int y = 7;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.direction == 3);
        // change in eval
        // non required
        c0.darwin_action_left();
        CPPUNIT_ASSERT(c0.direction == 2);
    }

    void testing_38 () {
        char identity = 'r';
        int direction = 0;
        int x = 2;
        int y = 0;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.direction == 0);
        // change in eval
        // non required
        c0.darwin_action_right();
        CPPUNIT_ASSERT(c0.direction == 1);
    }

    void testing_39 () {
        char identity = 'f';
        int direction = 2;
        int x = 2;
        int y = 7;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.direction == 2);
        // change in eval
        // non required
        c0.darwin_action_right();
        CPPUNIT_ASSERT(c0.direction == 3);
    }

    void testing_40 () {
        char identity = 'u';
        int direction = 3;
        int x = 2;
        int y = 7;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.direction == 3);
        // change in eval
        // non required
        c0.darwin_action_right();
        CPPUNIT_ASSERT(c0.direction == 0);
    }

    void testing_41 () {
        char identity = 'u';
        int direction = 1;
        int x = 1;
        int y = 1;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.infected_something == false);
        // change in eval
        c0.enemy = true;
        c0.darwin_action_infect();
        CPPUNIT_ASSERT(c0.infected_something == true);
    }

    void testing_42 () {
        char identity = 'u';
        int direction = 3;
        int x = 6;
        int y = 5;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.infected_something == false);
        // change in eval
        c0.enemy = false;
        c0.darwin_action_infect();
        CPPUNIT_ASSERT(c0.infected_something == false);
    }

    void testing_43 () {
        char identity = 'u';
        int direction = 0;
        int x = 2;
        int y = 3;
        darwin_creatures c0(identity, direction, x, y);
        darwin_position pos0(8,8);
        CPPUNIT_ASSERT(c0.infected_something == false);
        // change in eval
        c0.enemy = true;
        c0.darwin_action_infect();
        CPPUNIT_ASSERT(c0.infected_something == true);
    }

    // -----
    // suite
    // -----


    CPPUNIT_TEST_SUITE(TestDarwin);

 
    CPPUNIT_TEST(testing_1);
    CPPUNIT_TEST(testing_2);
    CPPUNIT_TEST(testing_3);
    CPPUNIT_TEST(testing_4);
    CPPUNIT_TEST(testing_5);
    CPPUNIT_TEST(testing_6);
    CPPUNIT_TEST(testing_7);        
    CPPUNIT_TEST(testing_8);
    CPPUNIT_TEST(testing_9);
    CPPUNIT_TEST(testing_10);
    CPPUNIT_TEST(testing_11);
    CPPUNIT_TEST(testing_12);
    CPPUNIT_TEST(testing_13);
    CPPUNIT_TEST(testing_14);
    CPPUNIT_TEST(testing_15);
    CPPUNIT_TEST(testing_16);
    CPPUNIT_TEST(testing_17);
    CPPUNIT_TEST(testing_18);
    CPPUNIT_TEST(testing_19);
    CPPUNIT_TEST(testing_20);
    CPPUNIT_TEST(testing_21);
    CPPUNIT_TEST(testing_22);
    CPPUNIT_TEST(testing_23);
    CPPUNIT_TEST(testing_24);
    CPPUNIT_TEST(testing_25);
    CPPUNIT_TEST(testing_26);
    CPPUNIT_TEST(testing_27);
    CPPUNIT_TEST(testing_28);
    CPPUNIT_TEST(testing_29);
    CPPUNIT_TEST(testing_30);
    CPPUNIT_TEST(testing_31);
    CPPUNIT_TEST(testing_32);
    CPPUNIT_TEST(testing_33);
    CPPUNIT_TEST(testing_34);
    CPPUNIT_TEST(testing_35);
    CPPUNIT_TEST(testing_36);
    CPPUNIT_TEST(testing_37);
    CPPUNIT_TEST(testing_38);
    CPPUNIT_TEST(testing_39);
    CPPUNIT_TEST(testing_40);
    CPPUNIT_TEST(testing_41);
    CPPUNIT_TEST(testing_42);
    CPPUNIT_TEST(testing_43);

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