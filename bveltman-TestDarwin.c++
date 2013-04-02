
#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner


#define private public
#include "Darwin.h"
#include "Darwin.c++"

struct TestDarwin : CppUnit::TestFixture {

    void test_creature_program_get_next_move_1 () {
        CreatureProgram a;
        char Around[4] = {};
        a.getNextMove(HOPPER, 0, EMPTY, Around);
        CPPUNIT_ASSERT (*(Around + 1) == HOP);
        CPPUNIT_ASSERT (*(Around + 2) == 1);
    }
    
	void test_creature_program_get_next_move_2 () {
        CreatureProgram a;
        char Around[4] = {};
        a.getNextMove(FOOD, 0, EMPTY, Around);
        CPPUNIT_ASSERT (*(Around + 1) == LEFT);
        CPPUNIT_ASSERT (*(Around + 2) == 1);
    }
    
    void test_creature_program_get_next_move_3 () {
        CreatureProgram a;
        char Around[4] = {ENEMY, ENEMY, ENEMY, ENEMY};
        a.getNextMove(ROVER, 0, ENEMY, Around);
        CPPUNIT_ASSERT (*(Around + 1) == INFECT);
        CPPUNIT_ASSERT (*(Around + 2) == 10);
    }
    
    //test Creature default constructor
    void test_creature_default_constructor_1 () {
    Creature a;
    CPPUNIT_ASSERT (a.species == EMPTY);
    CPPUNIT_ASSERT (a.direction == 0);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    }
    
    void test_creature_default_constructor_2 () {
    Creature b;
    CPPUNIT_ASSERT (b.species == EMPTY);
    CPPUNIT_ASSERT (b.direction == 0);
    CPPUNIT_ASSERT (b.pCounter == 0);
    CPPUNIT_ASSERT (b.turn == 0);
    }
    
    void test_creature_default_constructor_3 () {
    Creature c;
    CPPUNIT_ASSERT (c.species == EMPTY);
    CPPUNIT_ASSERT (c.direction == 0);
    CPPUNIT_ASSERT (c.pCounter == 0);
    CPPUNIT_ASSERT (c.turn == 0);
    }
    
    //test creature constructor
    void test_creature_constructor_1 () {
    Creature a (HOPPER, WEST);
    CPPUNIT_ASSERT (a.species == HOPPER);
    CPPUNIT_ASSERT (a.direction == WEST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    }

	void test_creature_constructor_2 () {
    Creature b (FOOD, NORTH);
    CPPUNIT_ASSERT (b.species == FOOD);
    CPPUNIT_ASSERT (b.direction == NORTH);
    CPPUNIT_ASSERT (b.pCounter == 0);
    CPPUNIT_ASSERT (b.turn == 0);
    }

    void test_creature_constructor_3 () {
    Creature c (ROVER, SOUTH);
    CPPUNIT_ASSERT (c.species == ROVER);
    CPPUNIT_ASSERT (c.direction == SOUTH);
    CPPUNIT_ASSERT (c.pCounter == 0);
    CPPUNIT_ASSERT (c.turn == 0);
    }
    
    //test takeTurn
    void test_creature_take_turn_1 () {
    Creature a (HOPPER, WEST);
    CPPUNIT_ASSERT (a.species == HOPPER);
    CPPUNIT_ASSERT (a.direction == WEST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    
    char Around [4] = {EMPTY, EMPTY, EMPTY, EMPTY};
    a.TakeTurn(Around, a.pCounter);
    CPPUNIT_ASSERT (*Around == WEST);
    CPPUNIT_ASSERT (*(Around + 1) == HOP);
    CPPUNIT_ASSERT (*(Around + 2) == 1);
    CPPUNIT_ASSERT (a.pCounter == 1);
    CPPUNIT_ASSERT (a.species == HOPPER);
    }
    
	void test_creature_take_turn_2 () {
    Creature a (FOOD, WEST);
    CPPUNIT_ASSERT (a.species == FOOD);
    CPPUNIT_ASSERT (a.direction == WEST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    
    char Around [4] = {WALL, EMPTY, EMPTY, EMPTY};
    a.TakeTurn(Around, a.pCounter);
    CPPUNIT_ASSERT (*Around == WEST);
    CPPUNIT_ASSERT (*(Around + 1) == LEFT);
    CPPUNIT_ASSERT (*(Around + 2) == 1);
    CPPUNIT_ASSERT (a.pCounter == 1);
    CPPUNIT_ASSERT (a.species == FOOD);
    CPPUNIT_ASSERT (a.direction == SOUTH);
    }
    
    void test_creature_take_turn_3 () {
    Creature a (ROVER, EAST);
    CPPUNIT_ASSERT (a.species == ROVER);
    CPPUNIT_ASSERT (a.direction == EAST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    
    char Around [4] = {ENEMY, ENEMY, ENEMY, ENEMY};
    a.TakeTurn(Around, a.pCounter);
    CPPUNIT_ASSERT (*Around == EAST);
    CPPUNIT_ASSERT (*(Around + 1) == INFECT);
    CPPUNIT_ASSERT (*(Around + 2) == 10);
    CPPUNIT_ASSERT (a.pCounter == 10);
    CPPUNIT_ASSERT (a.species == ROVER);
    CPPUNIT_ASSERT (a.direction == EAST);
    }
    
    //print species
    void test_creature_print_species_1 () {
    Creature a (ROVER, EAST);
    CPPUNIT_ASSERT (a.species == ROVER);
    CPPUNIT_ASSERT (a.direction == EAST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    char type = a.printSpecies();
    CPPUNIT_ASSERT (type == 'r');
    }
    
    void test_creature_print_species_2 () {
    Creature a (HOPPER, EAST);
    CPPUNIT_ASSERT (a.species == HOPPER);
    CPPUNIT_ASSERT (a.direction == EAST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    char type = a.printSpecies();
    CPPUNIT_ASSERT (type == 'h');
    }
    
    void test_creature_print_species_3 () {
    Creature a (BEST, EAST);
    CPPUNIT_ASSERT (a.species == BEST);
    CPPUNIT_ASSERT (a.direction == EAST);
    CPPUNIT_ASSERT (a.pCounter == 0);
    CPPUNIT_ASSERT (a.turn == 0);
    char type = a.printSpecies();
    CPPUNIT_ASSERT (type == 'b');
    }
    
    
    //isSame Test
    void test_creature_is_same_1 () {
    Creature a (BEST, EAST);
    CPPUNIT_ASSERT (a.species == BEST);
    Creature b (BEST, WEST);
    CPPUNIT_ASSERT (b.species == BEST);
    CPPUNIT_ASSERT (a.isSame(b));
    }
    
    void test_creature_is_same_2 () {
    Creature a (HOPPER, EAST);
    CPPUNIT_ASSERT (a.species == HOPPER);
    Creature b (HOPPER, WEST);
    CPPUNIT_ASSERT (b.species == HOPPER);
    CPPUNIT_ASSERT (a.isSame(b));
    }
    
	void test_creature_is_same_3 () {    
	Creature a (ROVER, EAST);
    CPPUNIT_ASSERT (a.species == ROVER);
    Creature b (ROVER, WEST);
    CPPUNIT_ASSERT (b.species == ROVER);
    CPPUNIT_ASSERT (a.isSame(b));
    }
    
    //test infect
    void test_creature_infect_1 () {
    Creature a (ROVER, EAST);
    CPPUNIT_ASSERT (a.species == ROVER);
    Creature b (ROVER, WEST);
    CPPUNIT_ASSERT (b.species == ROVER);
    a.infect(b);
    CPPUNIT_ASSERT (b.species == ROVER);
    }
    
    //test infect
    void test_creature_infect_2 () {
    Creature a (ROVER, EAST);
    CPPUNIT_ASSERT (a.species == ROVER);
    Creature b (HOPPER, WEST);
    CPPUNIT_ASSERT (b.species == HOPPER);
    b.pCounter = 5;
    a.infect(b);
    CPPUNIT_ASSERT (b.species == ROVER);
    CPPUNIT_ASSERT (b.pCounter == 0);
    }
    
    void test_creature_infect_3 () {
    Creature a (FOOD, EAST);
    CPPUNIT_ASSERT (a.species == FOOD);
    Creature b (HOPPER, WEST);
    CPPUNIT_ASSERT (b.species == HOPPER);
    b.pCounter = 5;
    a.infect(b);
    CPPUNIT_ASSERT (b.species == FOOD);
    CPPUNIT_ASSERT (b.pCounter == 0);
    }
    
    //test isNull
    void test_creature_is_null_1 () {
        Creature a (FOOD, EAST);
        CPPUNIT_ASSERT (!a.isNull());
    }
    
    void test_creature_is_null_2 () {
        Creature a (ROVER, NORTH);
        CPPUNIT_ASSERT (!a.isNull());
    }
    
    void test_creature_is_null_3 () {
        Creature a;
        CPPUNIT_ASSERT (a.isNull());
    }
    
    //test copy
    void test_creature_copy_1 () {
        Creature a (BEST, EAST);
        CPPUNIT_ASSERT (a.species == BEST);
        CPPUNIT_ASSERT (a.direction == EAST);
        CPPUNIT_ASSERT (a.pCounter == 0);
        CPPUNIT_ASSERT (a.turn == 0);
        Creature b;
        a.copy(b);
        CPPUNIT_ASSERT (a.species == EMPTY);
        CPPUNIT_ASSERT (a.direction == 0);
        CPPUNIT_ASSERT (a.pCounter == 0);
        CPPUNIT_ASSERT (a.turn == 0);
    }
    
    void test_creature_copy_2 () {
        Creature a (BEST, EAST);
        CPPUNIT_ASSERT (a.species == BEST);
        CPPUNIT_ASSERT (a.direction == EAST);
        CPPUNIT_ASSERT (a.pCounter == 0);
        CPPUNIT_ASSERT (a.turn == 0);
        Creature b;
        b.copy(a);
        CPPUNIT_ASSERT (b.species == BEST);
        CPPUNIT_ASSERT (b.direction == EAST);
        CPPUNIT_ASSERT (b.pCounter == 0);
        CPPUNIT_ASSERT (b.turn == 0);
    }
    
	void test_creature_copy_3 () {
        Creature a (BEST, EAST);
        CPPUNIT_ASSERT (a.species == BEST);
        CPPUNIT_ASSERT (a.direction == EAST);
        CPPUNIT_ASSERT (a.pCounter == 0);
        CPPUNIT_ASSERT (a.turn == 0);
        Creature b (HOPPER, WEST);
        b.copy(a);
        CPPUNIT_ASSERT (b.species == BEST);
        CPPUNIT_ASSERT (b.direction == EAST);
        CPPUNIT_ASSERT (b.pCounter == 0);
        CPPUNIT_ASSERT (b.turn == 0);
    }
    
    //tests for DarwinGame
    
    //constructor tests
    void test_darwin_game_constructor_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
    }
    
    void test_darwin_game_constructor_2 () {
        DarwinGame <100,100> a;
        for (int i = 0; i < 100; ++i){
            for (int j = 0; j < 100; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
    }
    
    void test_darwin_game_constructor_3 () {
        DarwinGame <2,2> a;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
    }
    
    //test add creature
    void test_darwin_game_add_creature_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 0, 0);
        CPPUNIT_ASSERT (a.board[0][0].species == HOPPER);
        CPPUNIT_ASSERT (a.board[0][0].direction == WEST);
    }
    
     //test add creature
	void test_darwin_game_add_creature_2 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(ROVER, EAST, 2, 3);
        CPPUNIT_ASSERT (a.board[2][3].species == ROVER);
        CPPUNIT_ASSERT (a.board[2][3].direction == EAST);
    }
    
    //test add creature
    void test_darwin_game_add_creature_3 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(BEST, NORTH, 5, 5);
        CPPUNIT_ASSERT (a.board[5][5].species == BEST);
        CPPUNIT_ASSERT (a.board[5][5].direction == NORTH);
    }
    
    //test lookAround
    void test_darwin_game_look_around_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 0, 0);
        CPPUNIT_ASSERT (a.board[0][0].species == HOPPER);
        CPPUNIT_ASSERT (a.board[0][0].direction == WEST);
        char Around[4];
        a.lookAround(Around, 0, 0);
        CPPUNIT_ASSERT (*Around == WALL);
        CPPUNIT_ASSERT (*(Around + 1) == WALL);
        CPPUNIT_ASSERT (*(Around + 2) == EMPTY);
        CPPUNIT_ASSERT (*(Around + 3) == EMPTY);
        
    }
    
    void test_darwin_game_look_around_2 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 4, 4);
        CPPUNIT_ASSERT (a.board[4][4].species == HOPPER);
        CPPUNIT_ASSERT (a.board[4][4].direction == WEST);
        char Around[4];
        a.lookAround(Around, 4, 4);
        CPPUNIT_ASSERT (*Around == EMPTY);
        CPPUNIT_ASSERT (*(Around + 1) == EMPTY);
        CPPUNIT_ASSERT (*(Around + 2) == EMPTY);
        CPPUNIT_ASSERT (*(Around + 3) == EMPTY); 
    }
    
    void test_darwin_game_look_around_3 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 4, 4);
        CPPUNIT_ASSERT (a.board[4][4].species == HOPPER);
        CPPUNIT_ASSERT (a.board[4][4].direction == WEST);
        a.addCreature(ROVER, EAST, 3, 4);
        a.addCreature(ROVER, EAST, 5, 4);
        a.addCreature(ROVER, EAST, 4, 3);
        a.addCreature(ROVER, EAST, 4, 5);
        char Around[4];
        a.lookAround(Around, 4, 4);
        CPPUNIT_ASSERT (*Around == ENEMY);
        CPPUNIT_ASSERT (*(Around + 1) == ENEMY);
        CPPUNIT_ASSERT (*(Around + 2) == ENEMY);
        CPPUNIT_ASSERT (*(Around + 3) == ENEMY); 
    }
    
    
    //test playRound
    void test_darwin_game_play_round_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, EAST, 1, 1);
        CPPUNIT_ASSERT (a.board[1][1].species == HOPPER);
        CPPUNIT_ASSERT (a.board[1][1].direction == EAST);
        a.playRound();
        CPPUNIT_ASSERT (a.currentTurn == 1);
        CPPUNIT_ASSERT (a.board[1][1].isNull());
        CPPUNIT_ASSERT (a.board[1][2].species == HOPPER);
        CPPUNIT_ASSERT (a.board[1][2].direction == EAST);
    }
    
    void test_darwin_game_play_round_2 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(FOOD, EAST, 1, 1);
        CPPUNIT_ASSERT (a.board[1][1].species == FOOD);
        CPPUNIT_ASSERT (a.board[1][1].direction == EAST);
        a.playRound();
        CPPUNIT_ASSERT (a.currentTurn == 1);
        CPPUNIT_ASSERT (a.board[1][1].species == FOOD);
        CPPUNIT_ASSERT (a.board[1][1].direction == NORTH);
    }
    
    void test_darwin_game_play_round_3 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(ROVER, WEST, 4, 4);
        a.addCreature(FOOD, EAST, 3, 4);
        a.addCreature(FOOD, EAST, 5, 4);
        a.addCreature(FOOD, EAST, 4, 3);
        a.addCreature(FOOD, EAST, 4, 5);
        CPPUNIT_ASSERT (a.board[4][4].species == ROVER);
        CPPUNIT_ASSERT (a.board[4][4].direction == WEST);
        std::string w;
        w = a.printBoard();
        std::cout << w;
        a.playRound();
        w = a.printBoard();
        std::cout << w;
        CPPUNIT_ASSERT (a.currentTurn == 1);
        CPPUNIT_ASSERT (a.board[4][3].species == ROVER);
        CPPUNIT_ASSERT (a.board[4][3].direction == NORTH);
    }
    
    //hop creature test
    void test_darwin_game_hop_creature_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(ROVER, WEST, 4, 4);
        a.hopCreature(a.board[4][4], WEST, 4, 4);
        CPPUNIT_ASSERT(a.board[4][4].isNull());
        CPPUNIT_ASSERT(a.board[4][3].species == ROVER);
    }
    
    void test_darwin_game_hop_creature_2 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, EAST, 0, 0);
        a.hopCreature(a.board[0][0], EAST, 0, 0);
        CPPUNIT_ASSERT(a.board[0][0].isNull());
        CPPUNIT_ASSERT(a.board[0][1].species == HOPPER);
    }
    
    void test_darwin_game_hop_creature_3 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 0, 0);
        a.hopCreature(a.board[0][0], WEST, 0, 0);
        CPPUNIT_ASSERT(!(a.board[0][0].isNull()));
        CPPUNIT_ASSERT(a.board[0][0].species == HOPPER);
    }
    
    
    //test checkSpace
    void test_darwin_game_check_space_1 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, WEST, 0, 0);
        Creature c;
        a.checkSpace(c, WEST, 0, 0);
        CPPUNIT_ASSERT(c.isNull());
    }
    
    void test_darwin_game_check_space_2 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, EAST, 0, 0);
        Creature c;
        a.checkSpace(c, EAST, 0, 0);
        CPPUNIT_ASSERT(c.isNull());
    }
    
    void test_darwin_game_check_space_3 () {
        DarwinGame <8,8> a;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                CPPUNIT_ASSERT(a.board[i][j].isNull());
            }
        }
        CPPUNIT_ASSERT (a.currentTurn == 0);
        
        a.addCreature(HOPPER, EAST, 0, 0);
        Creature c;
        a.checkSpace(c, WEST, 0, 1);
        CPPUNIT_ASSERT(c.species == HOPPER);
        CPPUNIT_ASSERT(c.direction == EAST);
    }

    //tests for printBoard
    void test_darwin_game_print_board_1 () {
        DarwinGame <2,2> a;
        std::string w = a.printBoard();
        std::cout << w;
        CPPUNIT_ASSERT(w.compare("Turn = 0.\n 01\n0..\n1..\n\n") == 0);
    }
    
    void test_darwin_game_print_board_2 () {
        DarwinGame <3,3> a;
        a.addCreature(FOOD, NORTH, 0, 0);
        std::string w = a.printBoard();
        std::cout << w;
        CPPUNIT_ASSERT(w.compare("Turn = 0.\n 012\n0f..\n1...\n2...\n\n") == 0);
    }
    
    void test_darwin_game_print_board_3 () {
        DarwinGame <3,3> a;
        a.addCreature(FOOD, NORTH, 0, 0);
        a.addCreature(FOOD, SOUTH, 2, 2);
        a.addCreature(HOPPER, WEST, 1, 1);
        std::string w = a.printBoard();
        std::cout << w;
        CPPUNIT_ASSERT(w.compare("Turn = 0.\n 012\n0f..\n1.h.\n2..f\n\n") == 0);
    }
    
    //tests for playGame
    
    void test_darwin_game_play_game_1 () {
        DarwinGame <3,3> a;
        a.addCreature(FOOD, NORTH, 0, 0);
        a.addCreature(FOOD, WEST, 2, 2);
        CPPUNIT_ASSERT(a.currentTurn == 0);
        CPPUNIT_ASSERT(a.board[0][0].species == FOOD);
        CPPUNIT_ASSERT(a.board[2][2].species == FOOD);
        CPPUNIT_ASSERT(a.board[0][0].direction == NORTH);
        CPPUNIT_ASSERT(a.board[2][2].direction == WEST);
        a.playGame(3, 3);
        CPPUNIT_ASSERT(a.currentTurn == 3);
        CPPUNIT_ASSERT(a.board[0][0].species == FOOD);
        CPPUNIT_ASSERT(a.board[2][2].species == FOOD);
        CPPUNIT_ASSERT(a.board[0][0].direction == EAST);
        CPPUNIT_ASSERT(a.board[2][2].direction == NORTH);      
    }
    
    void test_darwin_game_play_game_2 () {
        DarwinGame <3,3> a;
        a.addCreature(FOOD, NORTH, 0, 0);
        a.addCreature(FOOD, WEST, 2, 2);
        a.addCreature(HOPPER, EAST, 1, 0);
        CPPUNIT_ASSERT(a.currentTurn == 0);
        CPPUNIT_ASSERT(a.board[0][0].species == FOOD);
        CPPUNIT_ASSERT(a.board[2][2].species == FOOD);
        CPPUNIT_ASSERT(a.board[1][0].species == HOPPER);
        CPPUNIT_ASSERT(a.board[0][0].direction == NORTH);
        CPPUNIT_ASSERT(a.board[2][2].direction == WEST);
        CPPUNIT_ASSERT(a.board[1][0].direction == EAST);
        a.playGame(3, 3);
        CPPUNIT_ASSERT(a.currentTurn == 3);
        CPPUNIT_ASSERT(a.board[0][0].species == FOOD);
        CPPUNIT_ASSERT(a.board[2][2].species == FOOD);
        CPPUNIT_ASSERT(a.board[1][2].species == HOPPER);
        CPPUNIT_ASSERT(a.board[0][0].direction == EAST);
        CPPUNIT_ASSERT(a.board[2][2].direction == NORTH);
        CPPUNIT_ASSERT(a.board[1][2].direction == EAST);
    }
    
    void test_darwin_game_play_game_3 () {
        DarwinGame <2, 2> a;
        a.addCreature(ROVER, EAST, 0, 0);
        a.addCreature(FOOD, EAST, 0, 1);
        CPPUNIT_ASSERT(a.board[0][0].species == ROVER);
        CPPUNIT_ASSERT(a.board[0][1].species == FOOD);
        CPPUNIT_ASSERT(a.board[0][0].direction == EAST);
        CPPUNIT_ASSERT(a.board[0][1].direction == EAST);
        a.playGame(1, 1);
        CPPUNIT_ASSERT(a.board[0][0].species == ROVER);
        CPPUNIT_ASSERT(a.board[0][1].species == ROVER);
        CPPUNIT_ASSERT(a.board[0][0].direction == EAST);
        
    }

    //------
    // suite
    //------

    CPPUNIT_TEST_SUITE(TestDarwin);
    	CPPUNIT_TEST(test_creature_program_get_next_move_1);
		CPPUNIT_TEST(test_creature_program_get_next_move_2);
		CPPUNIT_TEST(test_creature_program_get_next_move_3);
		CPPUNIT_TEST(test_creature_default_constructor_1);
		CPPUNIT_TEST(test_creature_default_constructor_2);
		CPPUNIT_TEST(test_creature_default_constructor_3);
		CPPUNIT_TEST(test_creature_constructor_1);
		CPPUNIT_TEST(test_creature_constructor_2);
		CPPUNIT_TEST(test_creature_constructor_3);
		CPPUNIT_TEST(test_creature_take_turn_1);
		CPPUNIT_TEST(test_creature_take_turn_2);
		CPPUNIT_TEST(test_creature_take_turn_3);
		CPPUNIT_TEST(test_creature_print_species_1);
		CPPUNIT_TEST(test_creature_print_species_2);
		CPPUNIT_TEST(test_creature_print_species_3);
		CPPUNIT_TEST(test_creature_is_same_1);
		CPPUNIT_TEST(test_creature_is_same_2);
		CPPUNIT_TEST(test_creature_is_same_3);
		CPPUNIT_TEST(test_creature_infect_1);
		CPPUNIT_TEST(test_creature_infect_2);
		CPPUNIT_TEST(test_creature_infect_3);
		CPPUNIT_TEST(test_creature_is_null_1);
		CPPUNIT_TEST(test_creature_is_null_2);
		CPPUNIT_TEST(test_creature_is_null_3);
		CPPUNIT_TEST(test_creature_copy_1);
		CPPUNIT_TEST(test_creature_copy_2);
		CPPUNIT_TEST(test_creature_copy_3);
		CPPUNIT_TEST(test_darwin_game_constructor_1);
		CPPUNIT_TEST(test_darwin_game_constructor_2);
		CPPUNIT_TEST(test_darwin_game_constructor_3);
		CPPUNIT_TEST(test_darwin_game_add_creature_1);
		CPPUNIT_TEST(test_darwin_game_add_creature_2);
		CPPUNIT_TEST(test_darwin_game_add_creature_3);
		CPPUNIT_TEST(test_darwin_game_look_around_1);
		CPPUNIT_TEST(test_darwin_game_look_around_2);
		CPPUNIT_TEST(test_darwin_game_look_around_3);
		CPPUNIT_TEST(test_darwin_game_play_round_1);
		CPPUNIT_TEST(test_darwin_game_play_round_2);
		CPPUNIT_TEST(test_darwin_game_play_round_3);
		CPPUNIT_TEST(test_darwin_game_hop_creature_1);
		CPPUNIT_TEST(test_darwin_game_hop_creature_2);
		CPPUNIT_TEST(test_darwin_game_hop_creature_3);
		CPPUNIT_TEST(test_darwin_game_check_space_1);
		CPPUNIT_TEST(test_darwin_game_check_space_2);
		CPPUNIT_TEST(test_darwin_game_check_space_3);
		CPPUNIT_TEST(test_darwin_game_print_board_1);
		CPPUNIT_TEST(test_darwin_game_print_board_2);
		CPPUNIT_TEST(test_darwin_game_print_board_3);
		CPPUNIT_TEST(test_darwin_game_play_game_1);
		CPPUNIT_TEST(test_darwin_game_play_game_2);
		CPPUNIT_TEST(test_darwin_game_play_game_3);
    CPPUNIT_TEST_SUITE_END();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}