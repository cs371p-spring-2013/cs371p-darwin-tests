// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector> //vector

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
    // test creature constructor
    void test_creature_constuctors_1 (){
        Creature x (NORTH, 0, 2, FOOD);
        CPPUNIT_ASSERT(x.dir == 1);
        CPPUNIT_ASSERT(x.coord[0] == 0);
        CPPUNIT_ASSERT(x.coord[1] == 2);
        CPPUNIT_ASSERT(x.pc == 0);
        CPPUNIT_ASSERT(x.species == 'f');
        CPPUNIT_ASSERT(x.turnDone == false);
        CPPUNIT_ASSERT(x.si == food);
    }

    void test_creature_constuctors_2 (){
        Creature x (WEST, 0, 2, HOPPER);
        CPPUNIT_ASSERT(x.dir == 0);
        CPPUNIT_ASSERT(x.species == 'h');
        CPPUNIT_ASSERT(x.si == hopper);
    }

    void test_creature_constuctors_3 (){
        Creature x (SOUTH, 0, 2, ROVER);
        CPPUNIT_ASSERT(x.dir == 3);
        CPPUNIT_ASSERT(x.species == 'r');
        CPPUNIT_ASSERT(x.si == rover);
    }

    void test_creature_constuctors_4 (){
        Creature x (EAST, 0, 2, TRAP);
        CPPUNIT_ASSERT(x.dir == 2);
        CPPUNIT_ASSERT(x.species == 't');
        CPPUNIT_ASSERT(x.si == trap);
    }

    // test game constructor

    void test_game_constructor_1 (){
        Game g (2, 2);
        ostringstream w;
        w << g;
        CPPUNIT_ASSERT(w.str() == "0 ..\n1 ..\n");
        CPPUNIT_ASSERT(g.dimensions[0] == 2);
        CPPUNIT_ASSERT(g.dimensions[1] == 2);
        CPPUNIT_ASSERT(g.creatures.size() == 0);
    }

    void test_game_constructor_2 (){
        Game g (2, 3);
        ostringstream w;
        w << g;
        CPPUNIT_ASSERT(w.str() == "0 ...\n1 ...\n");
        CPPUNIT_ASSERT(g.dimensions[0] == 2);
        CPPUNIT_ASSERT(g.dimensions[1] == 3);
        CPPUNIT_ASSERT(g.creatures.size() == 0);
    }

    void test_game_constructor_3 (){
        Game g (3, 2);
        ostringstream w;
        w << g;
        CPPUNIT_ASSERT(w.str() == "0 ..\n1 ..\n2 ..\n");
        CPPUNIT_ASSERT(g.dimensions[0] == 3);
        CPPUNIT_ASSERT(g.dimensions[1] == 2);
        CPPUNIT_ASSERT(g.creatures.size() == 0);
    }

    // test turn decider

    void test_turnDecider_1 (){
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (SOUTH, 0, 1, HOPPER);
        CPPUNIT_ASSERT(turnDecider(x, y));
    }

    void test_turnDecider_2 (){
        Creature x (NORTH, 0, 1, FOOD);
        Creature y (SOUTH, 0, 0, HOPPER);
        CPPUNIT_ASSERT(!turnDecider(x, y));
    }

    void test_turnDecider_3 (){
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (SOUTH, 1, 0, HOPPER);
        CPPUNIT_ASSERT(turnDecider(x, y));
    }

    void test_turnDecider_4 (){
        Creature x (NORTH, 1, 0, FOOD);
        Creature y (SOUTH, 0, 1, HOPPER);
        CPPUNIT_ASSERT(!turnDecider(x, y));
    }

    // test add creature

    void test_addCreature_1(){
        Creature x (NORTH, 0, 0 , FOOD);
        Game g (2, 2);
        g.addCreature(x);
        CPPUNIT_ASSERT(g.creatures[0] == x);
    }

    void test_addCreature_2(){
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (SOUTH, 0, 1, FOOD);
        Game g (2, 2);
        g.addCreature(x);
        g.addCreature(y);
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
    }

    void test_addCreature_3(){
        Creature x (NORTH, 0, 0 , FOOD);
        Creature y (SOUTH, 0, 1, FOOD);
        Game g (2, 2);
        g.addCreature(x);
        g.addCreature(y);
        g.addCreature(x);
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
        CPPUNIT_ASSERT(g.creatures[2] == x);
    }

    // test insert game pieces

    void test_insertGamePieces_1(){
        Creature x (NORTH, 0, 0, FOOD);
        Game g (2, 2);
        ostringstream before, middle, after;
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 ..\n");

        g.addCreature(x);
        middle << g;
        CPPUNIT_ASSERT(middle.str() == "0 ..\n1 ..\n");
        CPPUNIT_ASSERT(middle.str() == before.str());

        g.insertGamePieces();
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 f.\n1 ..\n");
    }

    void test_insertGamePieces_2(){
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (NORTH, 0, 1, HOPPER);
        Game g (2, 2);
        ostringstream before, after;
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 ..\n");

        g.addCreature(x);
        g.addCreature(y);
        g.insertGamePieces();

        after << g;
        CPPUNIT_ASSERT(after.str() == "0 fh\n1 ..\n");
    }

    void test_insertGamePieces_3(){
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (NORTH, 1, 1, HOPPER);
        Creature z (NORTH, 2, 2, ROVER);
        Game g (3, 3);
        ostringstream before, after;
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n");

        g.addCreature(x);
        g.addCreature(y);
        g.addCreature(z);
        g.insertGamePieces();

        after << g;
        CPPUNIT_ASSERT(after.str() == "0 f..\n1 .h.\n2 ..r\n");
    }

    // test sort turn order

    void test_sortTurnOrder_1(){
        Creature x (NORTH, 0, 1, FOOD);
        Creature y (SOUTH, 1, 0, HOPPER);
        Game g (2, 2);
        g.addCreature(x);
        g.addCreature(y);
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
        g.sortTurnOrder();
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
    }

    void test_sortTurnOrder_2(){
        Creature x (NORTH, 1, 1, FOOD);
        Creature y (SOUTH, 0, 0, HOPPER);
        Game g (2, 2);
        g.addCreature(x);
        g.addCreature(y);
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
        g.sortTurnOrder();
        CPPUNIT_ASSERT(g.creatures[0] == y);
        CPPUNIT_ASSERT(g.creatures[1] == x);
    }

    void test_sortTurnOrder_3(){
        Creature x (NORTH, 2, 1, FOOD);
        Creature y (SOUTH, 1, 0, HOPPER);
        Creature z (SOUTH, 0, 0, HOPPER);
        Game g (3, 3);
        g.addCreature(x);
        g.addCreature(y);
        g.addCreature(z);
        CPPUNIT_ASSERT(g.creatures[0] == x);
        CPPUNIT_ASSERT(g.creatures[1] == y);
        CPPUNIT_ASSERT(g.creatures[2] == z);
        g.sortTurnOrder();
        CPPUNIT_ASSERT(g.creatures[0] == z);
        CPPUNIT_ASSERT(g.creatures[1] == y);
        CPPUNIT_ASSERT(g.creatures[2] == x);
    }

    // test left
    void test_left_1(){
        Creature x (NORTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == NORTH);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == WEST);
    }

    void test_left_2(){
        Creature x (SOUTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == SOUTH);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == EAST);
    }

    void test_left_3(){
        Creature x (NORTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == NORTH);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == WEST);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == SOUTH);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == EAST);
        g.left(x);
        CPPUNIT_ASSERT(x.dir == NORTH);
    }

    // test right
    void test_right_1(){
        Creature x (NORTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == NORTH);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == EAST);
    }

    void test_right_2(){
        Creature x (SOUTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == SOUTH);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == WEST);
    }

    void test_right_3(){
        Creature x (NORTH, 0, 0, FOOD);
        Game g (2, 2);
        CPPUNIT_ASSERT(x.dir == NORTH);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == EAST);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == SOUTH);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == WEST);
        g.right(x);
        CPPUNIT_ASSERT(x.dir == NORTH);
    }

    void test_hop_1 (){
        Creature x (NORTH, 2, 2, FOOD);
        Game g (3, 3);
        ostringstream before, beforeHop, afterHop;
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n");
        g.addCreature(x);
        g.insertGamePieces();
        beforeHop << g;
        CPPUNIT_ASSERT(beforeHop.str() == "0 ...\n1 ...\n2 ..f\n");
        g.hop(x);
        afterHop << g;
        CPPUNIT_ASSERT(afterHop.str() == "0 ...\n1 ..f\n2 ...\n");
    }

    void test_hop_2(){
        Game g (3, 3);
        Creature x (WEST, 2, 2, FOOD);
        ostringstream w, h;
        g.addCreature(x);
        g.insertGamePieces();
        g.hop(x);
        h << g;
        CPPUNIT_ASSERT(h.str() == "0 ...\n1 ...\n2 .f.\n");
        g.hop(x);
        g.hop(x);
        g.hop(x);
        w << g;
        CPPUNIT_ASSERT(w.str() == "0 ...\n1 ...\n2 f..\n");
    }

    void test_hop_3(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        Creature y (SOUTH, 1, 2, HOPPER);
        ostringstream w, h;
        g.addCreature(x);
        g.addCreature(y);
        g.insertGamePieces();
        h << g;
        CPPUNIT_ASSERT(h.str() == "0 ...\n1 ..h\n2 ..f\n");
        g.hop(x);
        w << g;
        CPPUNIT_ASSERT(w.str() == "0 ...\n1 ..h\n2 ..f\n");
    }

    void test_hop_4(){
        Game g (3, 3);
        Creature x (EAST, 2, 0, FOOD);
        ostringstream before, after;
        g.addCreature(x);
        g.insertGamePieces();
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 f..\n");
        g.hop(x);
        g.hop(x);
        g.hop(x);
        g.hop(x);
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 ...\n1 ...\n2 ..f\n");
    }

    void test_hop_5(){
        Game g (3, 3);
        Creature x (SOUTH, 0, 1, FOOD);
        ostringstream before, after;
        g.addCreature(x);
        g.insertGamePieces();
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 .f.\n1 ...\n2 ...\n");
        g.hop(x);
        g.hop(x);
        g.hop(x);
        g.hop(x);
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 ...\n1 ...\n2 .f.\n");
    }

    void test_infect_helper_1(){

        Game g(3,3);
        Creature x (SOUTH, 0, 1, HOPPER);
        Creature y (SOUTH, 1, 1, FOOD);
        ostringstream before, after;
        g.addCreature(x); g.addCreature(y);
        g.insertGamePieces();
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 .h.\n1 .f.\n2 ...\n");
        g.infect(x);
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 .h.\n1 .h.\n2 ...\n");
        CPPUNIT_ASSERT(g.creatures[0].species == g.creatures[1].species);
    }

    void test_infect_helper_2(){
        Game g (3, 3);
        Creature x (NORTH, 0, 0, HOPPER);
        Creature y (NORTH, 1, 0, FOOD);
        ostringstream before, afterX, afterY;
        g.addCreature(x); g.addCreature(y);
        g.insertGamePieces();
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 h..\n1 f..\n2 ...\n");
        g.infect(x);
        afterX << g;
        CPPUNIT_ASSERT(afterX.str() == before.str());
        g.infect(y);
        afterY << g;
        CPPUNIT_ASSERT(afterY.str() == "0 f..\n1 f..\n2 ...\n");
    }

    void test_infect_helper_3(){
        Game g (3, 3);
        Creature x(NORTH, 0, 2, ROVER);
        Creature y(NORTH, 1, 2, FOOD);
        Creature z(NORTH, 2, 2, TRAP);

        ostringstream before, after;
        g.addCreature(x);
        g.addCreature(y);
        g.addCreature(z);
        g.insertGamePieces();
        before << g;
        CPPUNIT_ASSERT(before.str() == "0 ..r\n1 ..f\n2 ..t\n");
        g.infect(g.creatures[0]);
        g.infect(g.creatures[1]);
        g.infect(g.creatures[2]);
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 ..f\n1 ..t\n2 ..t\n");
    }

    // test action inst
    void test_action_inst_1(){
        Game g(2, 2);
        Creature x (NORTH, 0, 0, FOOD);
        g.addCreature(x);
        g.insertGamePieces();

        g.actionInst(x);
        CPPUNIT_ASSERT(x.pc == 1);
        CPPUNIT_ASSERT(x.turnDone);
    }

    void test_action_inst_2(){
        Game g(2, 2);
        Creature x (NORTH, 0, 0, FOOD);
        x.pc = 1;
        g.addCreature(x);
        g.insertGamePieces();

        g.actionInst(x);
        CPPUNIT_ASSERT(x.pc == 2);
        CPPUNIT_ASSERT(x.turnDone);
    }

    void test_action_inst_3(){
        Game g(2, 2);
        Creature x (NORTH, 0, 0, FOOD);
        x.pc = 4;
        x.turnDone = true;
        g.addCreature(x);
        g.insertGamePieces();

        g.actionInst(x);
        CPPUNIT_ASSERT(x.pc == 5);
        CPPUNIT_ASSERT(x.turnDone);
    }

    // if empty
    void test_empty_1(){
        Game g (3, 3);
        Creature x(NORTH, 2, 2, FOOD);

        g.if_empty(x, 5);
        CPPUNIT_ASSERT(x.pc == 5);
    }

    void test_empty_2(){
        Game g (3, 3);
        Creature x(NORTH, 0, 0, FOOD);

        g.if_empty(x, 5);
        CPPUNIT_ASSERT(x.pc == 1);
    }

    void test_empty_3(){
        Game g (3, 3);
        Creature x(NORTH, 2, 2, FOOD);
        Creature y(NORTH, 1, 2, FOOD);
        g.addCreature(x);
        g.addCreature(y);
        g.insertGamePieces();
        g.if_empty(x, 5);
        CPPUNIT_ASSERT(x.pc == 1);
    }

    void test_if_wall_1(){
        Game g (3, 3);
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (EAST, 0, 0, FOOD);

        g.if_wall(x, 9);
        CPPUNIT_ASSERT(x.pc == 9);

        g.if_wall(y, 9);
        CPPUNIT_ASSERT(y.pc == 1);
    }

    void test_if_wall_2(){
        Game g (1, 1);
        Creature x (NORTH, 0, 0, FOOD);
        Creature y (EAST, 0, 0, FOOD);
        Creature z (WEST, 0, 0, FOOD);
        Creature b (SOUTH, 0, 0, FOOD);

        g.if_wall(x, 9);
        g.if_wall(y, 9);
        g.if_wall(z, 9);
        g.if_wall(b, 9);

        CPPUNIT_ASSERT(x.pc == 9);
        CPPUNIT_ASSERT(y.pc == 9);
        CPPUNIT_ASSERT(z.pc == 9);
        CPPUNIT_ASSERT(b.pc == 9);
    }

    void test_if_wall_3(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, HOPPER);
        g.if_wall(x, 8);
        CPPUNIT_ASSERT(x.pc == 1);
    }

    void test_if_random_1(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        srand(0);
        g.if_random(x, 8);
        CPPUNIT_ASSERT(x.pc == 8);
    }

    void test_if_random_2(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        srand(0);
        g.if_random(x, 8);
        CPPUNIT_ASSERT(x.pc == 8);
        g.if_random(x, 20);
        CPPUNIT_ASSERT(x.pc == 9);
    }

    void test_if_random_3(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        srand(0);
        g.if_random(x, 8);
        CPPUNIT_ASSERT(x.pc == 8);
        g.if_random(x, 20);
        CPPUNIT_ASSERT(x.pc == 9);
        g.if_random(x, 20);
        CPPUNIT_ASSERT(x.pc == 20);      
    }

    // test if enemy
    void test_if_enemy_1(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        Creature y (SOUTH, 1, 2, HOPPER);
        g.addCreature(x);
        g.addCreature(y);
        g.insertGamePieces();

        g.if_enemy(x, 5);
        g.if_enemy(y, 7);

        CPPUNIT_ASSERT(x.pc == 5);
        CPPUNIT_ASSERT(y.pc == 7);
    }

    void test_if_enemy_2(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        Creature y (SOUTH, 1, 2, FOOD);
        g.addCreature(x);
        g.addCreature(y);
        g.insertGamePieces();

        g.if_enemy(x, 5);
        g.if_enemy(y, 7);

        CPPUNIT_ASSERT(x.pc == 1);
        CPPUNIT_ASSERT(y.pc == 1);
    }

    void test_if_enemy_3(){
        Game g (3, 3);
        Creature x (NORTH, 2, 2, FOOD);
        g.addCreature(x);
        g.insertGamePieces();

        g.if_enemy(x, 5);

        CPPUNIT_ASSERT(x.pc == 1);
    }

    // test go
    void test_go_1(){
        Game g (1, 1);
        Creature x (NORTH, 0, 0, FOOD);
        g.go (x, 8);
        CPPUNIT_ASSERT(x.pc == 8);
    }

    void test_go_2(){
        Game g (1, 1);
        Creature x (EAST, 0, 0, HOPPER);
        g.go (x, 9);
        CPPUNIT_ASSERT(x.pc == 9);
    }

    void test_go_3(){
        Game g (1, 1);
        Creature x (SOUTH, 0, 0, ROVER);
        g.go (x, 9);
        CPPUNIT_ASSERT(x.pc == 9);
    }

    // test run game
    void test_run_game_1(){
        Game g (3, 3);
        g.addCreature(Creature(NORTH, 2, 2, TRAP));
        g.addCreature(Creature(EAST, 1, 2, FOOD));
        g.addCreature(Creature(EAST, 0, 0, HOPPER));
        g.insertGamePieces();
        ostringstream before, after;

        before << g;
        CPPUNIT_ASSERT(before.str() == "h..\n..f\n..t\n");
        g.runGame(2,1);
        after << g;
        CPPUNIT_ASSERT(after.str() == "..t\n..t\n..t\n");
        CPPUNIT_ASSERT(g.creatures[0].dir == 2);
        CPPUNIT_ASSERT(g.creatures[1].dir == 1);
        CPPUNIT_ASSERT(g.creatures[2].dir == 0);
    }

    void test_run_game_2(){
        Game g (8, 8);
        Creature one (EAST, 0, 0, FOOD); g.addCreature(one);
        Creature two (NORTH, 3, 3, HOPPER); g.addCreature(two);
        Creature three (EAST, 3, 4, HOPPER); g.addCreature(three);
        Creature four (SOUTH, 4, 4, HOPPER); g.addCreature(four);
        Creature five (WEST, 4, 3, HOPPER); g.addCreature(five);
        Creature six (NORTH, 7, 7, FOOD); g.addCreature(six);
        g.insertGamePieces();
        g.runGame(5,1);
        ostringstream after;
        after << g;
        CPPUNIT_ASSERT(after.str() == "0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n");
    }

    void test_run_game_3(){
        Game g (7, 9);
        srand(0);
        Creature one (SOUTH, 0, 0, TRAP); g.addCreature(one);
        Creature two (EAST, 3, 2, HOPPER); g.addCreature(two);
        Creature three (NORTH, 5, 4, ROVER); g.addCreature(three);
        Creature four (WEST, 6, 8, TRAP); g.addCreature(four);
        g.insertGamePieces();
        g.runGame(5,1);
        ostringstream after;
        after << g;
    
        CPPUNIT_ASSERT(after.str() == "0 f..h....\n1 ........\n2 ........\n3 .......h\n4 h.......\n5 ........\n6 ........\n7 ....h..f\n");
    }
    void test_run_game_4(){

        Game g (72,72);
        int r = (std::rand() % 5184);
        int x = r / 72;
        int y = (r- (x*72));

        Creature one(std::rand()%4, x , y, FOOD);
        g.addCreature(one);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature two(std::rand()%4, x , y, FOOD);
        g.addCreature(two);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature three(std::rand()%4, x , y, FOOD);
        g.addCreature(three);
        
        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature four(std::rand()%4, x , y, FOOD);
        g.addCreature(four);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature five(std::rand()%4, x , y, FOOD);
        g.addCreature(five);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature six(std::rand()%4, x , y, FOOD);
        g.addCreature(six);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature seven(std::rand()%4, x , y, FOOD);
        g.addCreature(seven);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature eight(std::rand()%4, x , y, FOOD);
        g.addCreature(eight);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature nine(std::rand()%4, x , y, FOOD);
        g.addCreature(nine);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature ten(std::rand()%4, x , y, FOOD);
        g.addCreature(ten);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature eleven(std::rand()%4, x , y, HOPPER);
        g.addCreature(eleven);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twelve(std::rand()%4, x , y, HOPPER);
        g.addCreature(twelve);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(twelve);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature fourteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(fourteen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature fifteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(fifteen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature sixteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(sixteen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature seventeen(std::rand()%4, x , y, HOPPER);
        g.addCreature(seventeen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature eighteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(eighteen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature nineteen(std::rand()%4, x , y, HOPPER);
        g.addCreature(nineteen);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twenty(std::rand()%4, x , y, HOPPER);
        g.addCreature(twenty);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentyone(std::rand()%4, x , y, ROVER);
        g.addCreature(twentyone);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentytwo(std::rand()%4, x , y, ROVER);
        g.addCreature(twentytwo);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentythree(std::rand()%4, x , y, ROVER);
        g.addCreature(twentythree);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentyfour(std::rand()%4, x , y, ROVER);
        g.addCreature(twentyfour);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentyfive(std::rand()%4, x , y, ROVER);
        g.addCreature(twentyfive);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentysix(std::rand()%4, x , y, ROVER);
        g.addCreature(twentysix);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentyseven(std::rand()%4, x , y, ROVER);
        g.addCreature(twentyseven);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentyeight(std::rand()%4, x , y, ROVER);
        g.addCreature(twentyeight);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature twentynine(std::rand()%4, x , y, ROVER);
        g.addCreature(twentynine);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirty(std::rand()%4, x , y, ROVER);
        g.addCreature(thirty);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtytwo(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtytwo);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtythree(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtythree);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtyfour(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtyfour);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtyfive(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtyfive);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtysix(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtysix);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtyseven(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtyseven);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtyeight(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtyeight);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature thirtynine(std::rand()%4, x , y, TRAP);
        g.addCreature(thirtynine);

        r = (std::rand() % 5184);
        x = r / 72;
        y = (r- (x*72));
        Creature forty(std::rand()%4, x , y, TRAP);
        g.addCreature(forty);


        g.insertGamePieces();

        g.runGame(100,100);

        ostringstream before;

        before << g;

        //cout << before.str();


    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    
    // test creature constructor
    CPPUNIT_TEST(test_creature_constuctors_1);
    CPPUNIT_TEST(test_creature_constuctors_2);
    CPPUNIT_TEST(test_creature_constuctors_3);
    CPPUNIT_TEST(test_creature_constuctors_4);

    // test game constructor
    CPPUNIT_TEST(test_game_constructor_1);
    CPPUNIT_TEST(test_game_constructor_2);
    CPPUNIT_TEST(test_game_constructor_3);

    // test operator char
    CPPUNIT_TEST(test_turnDecider_1);
    CPPUNIT_TEST(test_turnDecider_2);
    CPPUNIT_TEST(test_turnDecider_3);
    CPPUNIT_TEST(test_turnDecider_4);

    // test add creature
    CPPUNIT_TEST(test_addCreature_1);
    CPPUNIT_TEST(test_addCreature_2);
    CPPUNIT_TEST(test_addCreature_3);

    //test insert game pieces
    CPPUNIT_TEST(test_insertGamePieces_1);
    CPPUNIT_TEST(test_insertGamePieces_2);
    CPPUNIT_TEST(test_insertGamePieces_3);

    // test sort turn order
    CPPUNIT_TEST(test_sortTurnOrder_1);
    CPPUNIT_TEST(test_sortTurnOrder_2);
    CPPUNIT_TEST(test_sortTurnOrder_3);

    // test turn left
    CPPUNIT_TEST(test_left_1);
    CPPUNIT_TEST(test_left_2);
    CPPUNIT_TEST(test_left_3);

    // test turn right
    CPPUNIT_TEST(test_right_1);
    CPPUNIT_TEST(test_right_2);
    CPPUNIT_TEST(test_right_3);

    // test hop
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_hop_4);
    CPPUNIT_TEST(test_hop_5);

    //test_infect_helper
    CPPUNIT_TEST(test_infect_helper_1);
    CPPUNIT_TEST(test_infect_helper_2);
    CPPUNIT_TEST(test_infect_helper_3);

    // test action inst
    CPPUNIT_TEST(test_action_inst_1);
    CPPUNIT_TEST(test_action_inst_2);
    CPPUNIT_TEST(test_action_inst_3);

    // if empty
    CPPUNIT_TEST(test_empty_1);
    CPPUNIT_TEST(test_empty_2);
    CPPUNIT_TEST(test_empty_3);

    // test if wall
    CPPUNIT_TEST(test_if_wall_1);
    CPPUNIT_TEST(test_if_wall_2);
    CPPUNIT_TEST(test_if_wall_3);

    // test if random
    CPPUNIT_TEST(test_if_random_1);
    CPPUNIT_TEST(test_if_random_2);
    CPPUNIT_TEST(test_if_random_3);

    // test if enemy
    CPPUNIT_TEST(test_if_enemy_1);
    CPPUNIT_TEST(test_if_enemy_2);
    CPPUNIT_TEST(test_if_enemy_3);

    // test go
    CPPUNIT_TEST(test_go_1);
    CPPUNIT_TEST(test_go_2);
    CPPUNIT_TEST(test_go_3);

    // // test run game
    // CPPUNIT_TEST(test_run_game_1);
    // CPPUNIT_TEST(test_run_game_2);
    // CPPUNIT_TEST(test_run_game_3);
    // CPPUNIT_TEST(test_run_game_4);

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