#define private public
#define protected public

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture{
  std::vector<CreatureContainer> cc_vector;     
  std::vector<Instruction*> program;

  //Overriding setUp allows us to setup some variables before every test
  void setUp(){
    cc_vector = std::vector<CreatureContainer>();
    program = std::vector<Instruction*>();
    srand(0);
  }

  void tearDown(){
    Instruction::_game = NULL;
  }

  void test_game_round1(){
    //Test that multiple creatures all get a turn
    Hop hop;
    Go go(0);
    program.push_back(&hop);
    program.push_back(&go);
    Species hopper('h', program);

    Creature c1(&hopper);
    Creature c2(&hopper);

    CreatureContainer cc1(EAST, 0, c1);
    CreatureContainer cc2(EAST, 5, c2);

    cc_vector.push_back(cc1);
    cc_vector.push_back(cc2);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    CreatureContainer& g_cc2 = game.creature_containers[1];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL(0, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][0] == &g_cc1);
    CPPUNIT_ASSERT_EQUAL(5, g_cc2._position);
    CPPUNIT_ASSERT(game.grid[1][1] == &g_cc2);

    game.round();

    //assert postcondition
    CPPUNIT_ASSERT_EQUAL(1, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][1] == &g_cc1);
    CPPUNIT_ASSERT_EQUAL(6, g_cc2._position);
    CPPUNIT_ASSERT(game.grid[1][2] == &g_cc2);
  }
  void test_game_round2(){
    //Test that creatures only move once per turn
    Hop hop;
    Go go(0);
    program.push_back(&hop);
    program.push_back(&go);
    Species hopper('h', program);

    Creature c1(&hopper);

    CreatureContainer cc1(SOUTH, 0, c1);

    cc_vector.push_back(cc1);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL(0, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][0] == &g_cc1);

    game.round();

    //assert postcondition
    CPPUNIT_ASSERT_EQUAL(4, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[1][0] == &g_cc1);
  }
  void test_game_round3(){
    //Test ordering of turn taking
    Infect infect;
    Go go(0);
    program.push_back(&infect);
    program.push_back(&go);
    Species infector1('w', program);
    Species infector2('l', program);

    Creature c1(&infector1);
    Creature c2(&infector2);

    CreatureContainer cc1(EAST, 0, c1);
    CreatureContainer cc2(WEST, 1, c2);

    cc_vector.push_back(cc1);
    cc_vector.push_back(cc2);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    CreatureContainer& g_cc2 = game.creature_containers[1];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL('w', g_cc1._creature._species->_name);
    CPPUNIT_ASSERT_EQUAL('l', g_cc2._creature._species->_name);

    game.round();

    //assert postcondition
    CPPUNIT_ASSERT_EQUAL('w', g_cc1._creature._species->_name);
    CPPUNIT_ASSERT_EQUAL('w', g_cc2._creature._species->_name);
  }

  void test_game_play1(){
    Hop hop;
    Go go(0);
    program.push_back(&hop);
    program.push_back(&go);
    Species hopper('h', program);

    Creature c1(&hopper);

    CreatureContainer cc1(EAST, 0, c1);

    cc_vector.push_back(cc1);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL(0, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][0] == &g_cc1);
    
    std::ostringstream w;
    game.play(3, 0, w);

    CPPUNIT_ASSERT_EQUAL((size_t)0, w.str().size());
  }
  void test_game_play2(){
    Hop hop;
    Go go(0);
    program.push_back(&hop);
    program.push_back(&go);
    Species hopper('h', program);

    Creature c1(&hopper);

    CreatureContainer cc1(EAST, 0, c1);

    cc_vector.push_back(cc1);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL(0, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][0] == &g_cc1);
    
    std::ostringstream w;
    game.play(3, 0, w);

    CPPUNIT_ASSERT_EQUAL(3, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][3] == &g_cc1);
  }
  void test_game_play3(){
    Hop hop;
    Go go(0);
    program.push_back(&hop);
    program.push_back(&go);
    Species hopper('h', program);

    Creature c1(&hopper);

    CreatureContainer cc1(EAST, 0, c1);

    cc_vector.push_back(cc1);

    Game game(cc_vector, 4,4);
    Instruction::setGame(game);

    CreatureContainer& g_cc1 = game.creature_containers[0];
    //assert precondition
    CPPUNIT_ASSERT_EQUAL(0, g_cc1._position);
    CPPUNIT_ASSERT(game.grid[0][0] == &g_cc1);
    
    std::ostringstream w;
    game.play(3, 1, w);

    std::string expected = 
                           "Turn = 0.\n"
                           "  0123\n"
                           "0 h...\n"
                           "1 ....\n"
                           "2 ....\n"
                           "3 ....\n"
                           "\n"
                           "Turn = 1.\n"
                           "  0123\n"
                           "0 .h..\n"
                           "1 ....\n"
                           "2 ....\n"
                           "3 ....\n"
                           "\n"
                           "Turn = 2.\n"
                           "  0123\n"
                           "0 ..h.\n"
                           "1 ....\n"
                           "2 ....\n"
                           "3 ....\n"
                           "\n"
                           "Turn = 3.\n"
                           "  0123\n"
                           "0 ...h\n"
                           "1 ....\n"
                           "2 ....\n"
                           "3 ....\n"
                           "\n";

    CPPUNIT_ASSERT_EQUAL(expected, w.str());
  }

  void test_game_print_blank(){
    //std::cout << std::endl;
    std::ostringstream w;
    Game game(cc_vector, 4,4);
    game.print(w);
    std::string expected = "  0123\n0 ....\n1 ....\n2 ....\n3 ....\n\n";
    CPPUNIT_ASSERT(expected == w.str());
  }

  //test printing with more than 10 columns/rows
  void test_game_print_extra_columns(){
    //std::cout << std::endl;
    std::ostringstream w;
    Game game(cc_vector, 20, 20);
    game.print(w);
    std::string expected = 
       "  01234567890123456789\n"
       "0 ....................\n"
       "1 ....................\n"
       "2 ....................\n"
       "3 ....................\n"
       "4 ....................\n"
       "5 ....................\n"
       "6 ....................\n"
       "7 ....................\n"
       "8 ....................\n"
       "9 ....................\n"
       "0 ....................\n"
       "1 ....................\n"
       "2 ....................\n"
       "3 ....................\n"
       "4 ....................\n"
       "5 ....................\n"
       "6 ....................\n"
       "7 ....................\n"
       "8 ....................\n"
       "9 ....................\n"
       "\n";
    CPPUNIT_ASSERT(expected == w.str());
  }

  void test_game_print_one_creature(){
    std::cout << std::endl;
    Species species('f', program);
    Creature creature(&species);
    CreatureContainer container(NORTH, 0, creature); 
    cc_vector.push_back(container);
    Game game(cc_vector, 4, 4);
    std::ostringstream w;
    game.print(w);
    std::string expected = "  0123\n0 f...\n1 ....\n2 ....\n3 ....\n\n";
    CPPUNIT_ASSERT(expected == w.str());
  }

  //3 tests for front_coordinates 
  void test_front_coordinates_edge_x(){
    Species species('f', program);
    Creature creature(&species);

    //Create a creature at the right end of the board, facing off of the board
    CreatureContainer container(EAST, 3, creature); 

    cc_vector.push_back(container);
    Game game(cc_vector, 4, 4);
    game.current_creature_container = &container;

    int x;
    int y;
    bool result;
    //test with direction facing off board (fails)
    result = game.front_coordinates(x, y);
    CPPUNIT_ASSERT(!result);
    CPPUNIT_ASSERT_EQUAL(4, x);
    CPPUNIT_ASSERT_EQUAL(0, y);

    //test with direction facing into the board(succeeds)
    container = CreatureContainer(WEST, 3, creature); 
    game.current_creature_container = &container;
    result = game.front_coordinates(x, y);

    CPPUNIT_ASSERT_EQUAL(2, x);
    CPPUNIT_ASSERT_EQUAL(0, y);
    CPPUNIT_ASSERT(result);
  }
  void test_front_coordinates_edge_y(){
    Species species('f', program);
    Creature creature(&species);

    //test with direction facing off board (fails)
    CreatureContainer container(NORTH, 2, creature);

    cc_vector.push_back(container);
    Game game(cc_vector, 4, 4);
    game.current_creature_container = &container;

    int x;
    int y;
    bool result;
    
    result = game.front_coordinates(x, y);
    CPPUNIT_ASSERT(!result);
    CPPUNIT_ASSERT_EQUAL(2, x);
    CPPUNIT_ASSERT_EQUAL(-1, y);
    //test with direction facing into the board(succeeds)
    container = CreatureContainer(SOUTH, 2, creature);

    result = game.front_coordinates(x, y);
    CPPUNIT_ASSERT(result);
    CPPUNIT_ASSERT_EQUAL(2, x);
    CPPUNIT_ASSERT_EQUAL(1, y);

  }

  //Test that we don't get false negatives
  void test_front_coordinates_center(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    int x;
    int y;

    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;
    CPPUNIT_ASSERT(game.front_coordinates(x, y));

    container = CreatureContainer(SOUTH, 5, creature);
    game.current_creature_container = &container;
    CPPUNIT_ASSERT(game.front_coordinates(x, y));

    container = CreatureContainer(EAST, 5, creature);
    game.current_creature_container = &container;
    CPPUNIT_ASSERT(game.front_coordinates(x, y));

    container = CreatureContainer(WEST, 5, creature);
    game.current_creature_container = &container;
    CPPUNIT_ASSERT(game.front_coordinates(x, y));

  }
  //need 3 tests for enemy_in_front
  void test_game_enemy_in_front1(){
    //Test that enemies return true and friends return false
    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_enemy(&species2);
    Creature c_friend(&species);

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(EAST, 2, c_enemy);
    CreatureContainer container3(EAST, 0, c_friend);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(game.enemy_in_front());
    container._direction = SOUTH;
    CPPUNIT_ASSERT(!game.enemy_in_front());
    container._direction = WEST;
    CPPUNIT_ASSERT(!game.enemy_in_front());
  }
  void test_game_enemy_in_front2(){
    //Test that emptiness returns false
    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(EAST, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.enemy_in_front());
  }
  void test_game_enemy_in_front3(){
    //Test that walls return false
    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(NORTH, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.enemy_in_front());
  }

  void test_game_wall_in_front1(){
    //Test that other creatures return false
    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_wall(&species2);
    Creature c_friend(&species);

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(EAST, 2, c_wall);
    CreatureContainer container3(EAST, 0, c_friend);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.wall_in_front());
    container._direction = WEST;
    CPPUNIT_ASSERT(!game.wall_in_front());
  }
  void test_game_wall_in_front2(){
    //Test that emptiness returns false 
    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(EAST, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.wall_in_front());
  }
  void test_game_wall_in_front3(){
    //Test that walls return true 

    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(NORTH, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(game.wall_in_front());
  }

  //tests for empty_in_front
  void test_game_empty_in_front1(){
    //Test that other creatures return false
    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_empty(&species2);
    Creature c_friend(&species);

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(EAST, 2, c_empty);
    CreatureContainer container3(EAST, 0, c_friend);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.empty_in_front());
    container._direction = WEST;
    CPPUNIT_ASSERT(!game.empty_in_front());
  }
  void test_game_empty_in_front2(){
    //Test that emptiness returns true 
    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(EAST, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(game.empty_in_front());
  }
  void test_game_empty_in_front3(){
    //Test that walls return false

    Species species('f', program);

    Creature creature(&species);

    CreatureContainer container(NORTH, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!game.empty_in_front());
  }

  void test_game_left1(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;

    game.left();
    CPPUNIT_ASSERT_EQUAL(WEST, container._direction);
  }
  void test_game_left2(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(WEST, 5, creature);
    game.current_creature_container = &container;

    game.left();
    CPPUNIT_ASSERT_EQUAL(SOUTH, container._direction);
  }
  void test_game_left3(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(SOUTH, 5, creature);
    game.current_creature_container = &container;

    game.left();
    CPPUNIT_ASSERT_EQUAL(EAST, container._direction);
  }
  void test_game_left4(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(EAST, 5, creature);
    game.current_creature_container = &container;

    game.left();
    CPPUNIT_ASSERT_EQUAL(NORTH, container._direction);
  }

  void test_game_right1(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(WEST, 5, creature);
    game.current_creature_container = &container;

    game.right();
    CPPUNIT_ASSERT_EQUAL(NORTH, container._direction);
  }
  void test_game_right2(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(SOUTH, 5, creature);
    game.current_creature_container = &container;

    game.right();
    CPPUNIT_ASSERT_EQUAL(WEST, container._direction);
  }
  void test_game_right3(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(EAST, 5, creature);
    game.current_creature_container = &container;

    game.right();
    CPPUNIT_ASSERT_EQUAL(SOUTH, container._direction);
  }
  void test_game_right4(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;

    game.right();
    CPPUNIT_ASSERT_EQUAL(EAST, container._direction);
  }

  void test_game_hop1(){
    Species species('f', program);
    Creature creature(&species);

    Game game(cc_vector, 4, 4);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;

    game.hop();
    CPPUNIT_ASSERT_EQUAL(1, container._position);
    game.hop();
    CPPUNIT_ASSERT_EQUAL(1, container._position);
    
  }

  void test_game_hop2(){
  //make sure the location hopped from is empty
    Species species('f', program);
    Creature creature(&species);

    
    CreatureContainer container(NORTH, 5, creature);
    cc_vector.push_back(container);
    Game game(cc_vector, 4, 4);
    game.current_creature_container = &cc_vector[0];

    game.hop();
    CPPUNIT_ASSERT_EQUAL(1, cc_vector[0]._position);
    CPPUNIT_ASSERT(NULL == game.grid[1][1]);
  }

  //make sure that you can't hop into a spot occupied by another creature.
  void test_game_hop3(){
    Species species1('f', program);
    Species species2('g', program);
    Species species3('h', program);

    Creature creature1(&species1);
    Creature creature2(&species2);
    Creature creature3(&species3);

    
    CreatureContainer container1(EAST, 5, creature1);
    CreatureContainer container2(NORTH, 4, creature2);
    CreatureContainer container3(NORTH, 6, creature3);

    cc_vector.push_back(container1);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    game.current_creature_container = &container1;

    game.hop();
    CPPUNIT_ASSERT_EQUAL(5, container1._position);

    container1._direction = WEST;
    game.hop();
    CPPUNIT_ASSERT_EQUAL(5, container1._position);
  }

  void test_game_infect1(){
    Species species('f', program);
    Species victim_species('v', program);

    Creature creature(&species);
    Creature victim_creature(&victim_species);
    victim_creature._pc = 11;

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer victim_container(EAST, 2, victim_creature);
    cc_vector.push_back(container);
    cc_vector.push_back(victim_container);

    Game game(cc_vector, 4, 4);
    game.current_creature_container = &container;

    game.infect();

    //victim will be at index 1 in the game's vector of creature containers
    CreatureContainer & infected_container = game.creature_containers[1];
    CPPUNIT_ASSERT_EQUAL('f', infected_container._creature._species->_name);
    CPPUNIT_ASSERT_EQUAL(0, infected_container._creature._pc);
    CPPUNIT_ASSERT_EQUAL(EAST, infected_container._direction);
  }
  void test_game_infect2(){
    Species species('f', program);

    Creature creature(&species);
    
    Creature creature_friend(&species);
    creature_friend._pc = 11;

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer friend_container(EAST, 2, creature_friend);
    cc_vector.push_back(container);
    cc_vector.push_back(friend_container);

    Game game(cc_vector, 4, 4);
    game.current_creature_container = &container;

    game.infect();

    CPPUNIT_ASSERT_EQUAL('f', friend_container._creature._species->_name);
    CPPUNIT_ASSERT_EQUAL(11, friend_container._creature._pc);
    CPPUNIT_ASSERT_EQUAL(EAST, friend_container._direction);
  }
  void test_game_infect3(){
    Species species('f', program);
    Creature creature(&species);
    
    CreatureContainer container(EAST, 1, creature);
    cc_vector.push_back(container);

    Game game(cc_vector, 4, 4);
    game.current_creature_container = &game.creature_containers[0];

    game.infect();
    CPPUNIT_ASSERT(NULL == game.grid[0][2]);
    //The creature we started with shouldn't have moved
    CPPUNIT_ASSERT(&game.creature_containers[0] == game.grid[0][1]);
  }

  //test IfEnemy
  void test_if_enemy_query(){
    IfEnemy ifenemy(1337);

    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_enemy(&species2);
    Creature c_friend(&species);

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(EAST, 2, c_enemy);
    CreatureContainer container3(EAST, 0, c_friend);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(ifenemy.query());
    container._direction = SOUTH;
    CPPUNIT_ASSERT(!ifenemy.query());
    container._direction = WEST;
    CPPUNIT_ASSERT(!ifenemy.query());
  }

  void test_if_enemy_query_wall(){
    IfEnemy ifenemy(1337);

    Species species('f', program);

    Creature creature(&species);

    //We're as far north as we can be so the creature must be facing a wall
    CreatureContainer container(NORTH, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!ifenemy.query());
  }

  void test_if_enemy_ctrl_query(){
    IfEnemy ifenemy(1337);
    Control* ctrl = &ifenemy;

    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_enemy(&species2);
    Creature c_friend(&species);

    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(EAST, 2, c_enemy);
    CreatureContainer container3(EAST, 0, c_friend);
    cc_vector.push_back(container2);
    cc_vector.push_back(container3);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(ctrl->query());
    container._direction = SOUTH;
    CPPUNIT_ASSERT(!ctrl->query());
    container._direction = WEST;
    CPPUNIT_ASSERT(!ctrl->query());
  }

  void test_if_enemy_execute_false(){
    IfEnemy ifenemy(1337);

    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);

    CreatureContainer container(WEST, 1, creature);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    int pc = 10;
    ifenemy.execute(pc);
    CPPUNIT_ASSERT_EQUAL(11, pc);
  }

  void test_if_enemy_execute_true(){
    IfEnemy ifenemy(1337);

    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_enemy(&species2);

    CreatureContainer container(WEST, 1, creature);
    CreatureContainer container_enemy(WEST, 0, c_enemy);
    cc_vector.push_back(container_enemy);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    int pc = 10;
    ifenemy.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  void test_if_enemy_execute_pointer(){
    IfEnemy ifenemy(1337);
    Control* ctrl = &ifenemy;
    Instruction* instr = &ifenemy;

    Species species('f', program);
    Species species2('v', program);

    Creature creature(&species);
    Creature c_enemy(&species2);

    CreatureContainer container(WEST, 1, creature);
    CreatureContainer container_enemy(WEST, 0, c_enemy);
    cc_vector.push_back(container_enemy);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    int pc = 10;
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);

    pc = 10;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  //test IfWall
  void test_if_wall_query(){
    IfWall ifwall(1337);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(ifwall.query());

    container._direction = SOUTH;

    CPPUNIT_ASSERT(!ifwall.query());
  }

  void test_if_wall_query_corner(){
    IfWall ifwall(1337);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(SOUTH, 15, creature);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(ifwall.query());
    container._direction = EAST;
    CPPUNIT_ASSERT(ifwall.query());
    container._direction = WEST;
    CPPUNIT_ASSERT(!ifwall.query());
    container._direction = NORTH;
    CPPUNIT_ASSERT(!ifwall.query());
  }

  void test_if_wall_ctrl_query(){
    IfWall ifwall(1337);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    Control * ctrl = &ifwall;

    CPPUNIT_ASSERT(ctrl->query());
    container._direction = SOUTH;
    CPPUNIT_ASSERT(!ctrl->query());
  }

  void test_if_wall_execute(){
    IfWall ifwall(1337);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;
  
    int pc = 107;
    ifwall.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);

    //Query should return false and pc should be incremented instead of being
    //set to 1337
    container._direction = SOUTH;
    ifwall.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1338, pc);
  }

  void test_if_wall_ctrl_execute(){
    IfWall ifwall(1337);
    Control * ctrl = &ifwall;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;
  
    int pc = 107;
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);

    container._direction = SOUTH;

    //Query should return false and pc should be incremented instead of being
    //set to 1337
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1338, pc);
  }

  void test_if_wall_instr_execute(){
    IfWall ifwall(1337);
    Instruction* instr = &ifwall;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;
  
    int pc = 107;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);

    //Query should return false and pc should be incremented instead of being
    //set to 1337
    container._direction = SOUTH;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1338, pc);
  }

  //test IfEmpty
  void test_if_empty_query(){
    IfEmpty ifempty(1337);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!ifempty.query());

    container._direction = SOUTH;

    CPPUNIT_ASSERT(ifempty.query());
  }

  void test_if_empty_query_ctrl(){
    IfEmpty ifempty(1337);
    Control* ctrl = &ifempty;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!ctrl->query());

    container._direction = SOUTH;

    CPPUNIT_ASSERT(ctrl->query());
  }
  
  void test_if_empty_query_ctrl2(){
    IfEmpty ifempty(1337);
    Control* ctrl = &ifempty;

    Species species('f', program);
    Creature creature(&species);
    Creature creature2(&species);
    CreatureContainer container(EAST, 1, creature);
    CreatureContainer container2(SOUTH, 2, creature2);

    cc_vector.push_back(container2);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;

    CPPUNIT_ASSERT(!ctrl->query());

    container._direction = SOUTH;

    CPPUNIT_ASSERT(ctrl->query()); 
  }

  void test_if_empty_execute(){
    IfEmpty ifempty(1337);
    int pc = 1234;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    ifempty.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1235, pc);

    container._direction = SOUTH;

    ifempty.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  void test_if_empty_execute_ctrl(){
    IfEmpty ifempty(1337);
    int pc = 1234;
    Control* ctrl = &ifempty;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1235, pc);

    container._direction = SOUTH;

    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  void test_if_empty_execute_instr(){
    IfEmpty ifempty(1337);
    int pc = 1234;
    Instruction* instr = &ifempty;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    CreatureContainer container(NORTH, 1, creature);
    game.current_creature_container = &container;

    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1235, pc);

    container._direction = SOUTH;

    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  //test IfRandom
  void test_if_random_execute(){
    //srand(0) called in setup, so this should perfrom the same way every time
    //The first time you call rand(), it returns 1804289383
    //std::cout << "RANDOM OUTPUT: " << rand() << std::endl;
    //test odd
    int pc = 1306;
    IfRandom ifrandom(1337);
    ifrandom.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);

    //test even - calling rand() again with srand(0) gives an even number
    pc = 1306;
    ifrandom.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1307, pc);
  }

  void test_if_random_ctrl_execute(){
    int pc = 1306;
    IfRandom ifrandom(1337);
    Control* ctrl = &ifrandom;
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
    
    //test even - calling rand() again with srand(0) gives an even number
    pc = 1306;
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1307, pc);
  }
  
  void test_if_random_instr_execute(){
    int pc = 1306;
    IfRandom ifrandom(1337);
    Instruction* instr = &ifrandom;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
    
    //test even - calling rand() again with srand(0) gives an even number
    pc = 1306;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1307, pc);
  }

  void test_if_random_query(){
    //test even
    IfRandom ifrandom(1337);
    CPPUNIT_ASSERT(ifrandom.query());

    //test odd
    CPPUNIT_ASSERT(!ifrandom.query());
  }

  void test_if_random_ctrl_query(){
    //test even
    IfRandom ifrandom(1337);
    Control* ctrl = &ifrandom;
    CPPUNIT_ASSERT(ctrl->query());

    //test odd
    CPPUNIT_ASSERT(!ctrl->query());
  }

  void test_if_random_query2(){
    //test even
    IfRandom ifrandom(7331);
    CPPUNIT_ASSERT(ifrandom.query());

    //test odd
    CPPUNIT_ASSERT(!ifrandom.query());
  }
  
  //test Go
  void test_go_query1(){
    Go go(1337);   
    CPPUNIT_ASSERT(go.query());
  }
  void test_go_query2(){
    Go go(1024);   
    CPPUNIT_ASSERT(go.query());
  }
  void test_go_ctrl_query(){
    Go go(1337);   
    Control* ctrl = &go;
    CPPUNIT_ASSERT(ctrl->query());
  }

  void test_go_execute(){
    Go go(1337);
    int pc = -1;
    go.execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  void test_go_ctrl_execute(){
    Go go(1337);
    int pc = -1;
    Control* ctrl = & go;
    ctrl->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  void test_go_instr_execute(){
    Go go(1337);
    int pc = -1;
    Instruction* instr= & go;
    instr->execute(pc);
    CPPUNIT_ASSERT_EQUAL(1337, pc);
  }

  //test Hop
  void test_hop_execute_empty_in_front(){
    Hop hop;
    Action * action = &hop;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);

    int start_pos = 2;
    
    CreatureContainer container(EAST, start_pos, creature);
    game.current_creature_container = &container;
    
    int pc = 12345;
    action->execute(pc); 
    CPPUNIT_ASSERT_EQUAL(start_pos+1, container._position);
    CPPUNIT_ASSERT_EQUAL(12346, pc);
  }

  void test_hop_execute_wall_in_front(){
    Hop hop;
    Action * action = &hop;

    Species species('f', program);
    Creature creature(&species);
    int start_pos = 2;
    CreatureContainer container(NORTH, start_pos, creature);
    
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);

    game.current_creature_container = &container;
    
    int pc = 12345;
    action->execute(pc); 
    //Creature shouldn't have moved
    CPPUNIT_ASSERT_EQUAL(start_pos, container._position);
    CPPUNIT_ASSERT_EQUAL(12346, pc);
  }

  void test_hop_execute_creature_in_front(){
    Hop hop;
    Action * action = &hop;

    Species species('f', program);
    Creature creature(&species);
    Creature creature2(&species);
    
    int start_pos = 5;
    CreatureContainer container(WEST, start_pos, creature);
    CreatureContainer container2(EAST, 4, creature2);
    cc_vector.push_back(container2);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container;
    
    int pc = 12345;
    action->execute(pc); 
    CPPUNIT_ASSERT_EQUAL(start_pos, container._position);
    CPPUNIT_ASSERT_EQUAL(12346, pc);
  }

  //test infect action
  void test_infect_action1(){
    Infect infect;

    Species spec1('f', program);
    Species spec2('v', program);

    Creature creature1(&spec1);
    Creature creature2(&spec2);
    creature2._pc = 2;

    CreatureContainer container1(EAST, 1, creature1);
    CreatureContainer container2(WEST, 2, creature2);

    cc_vector.push_back(container2);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container1;

    infect.act();
    Creature& victim = game.creature_containers[0]._creature;
    CPPUNIT_ASSERT_EQUAL('f', victim._species->_name);
    CPPUNIT_ASSERT_EQUAL(0, victim._pc);
  }

  void test_infect_action2(){
    Infect infect;

    Species spec1('f', program);

    Creature creature1(&spec1);
    Creature creature2(&spec1);
    creature2._pc = 2;

    CreatureContainer container1(EAST, 1, creature1);
    CreatureContainer container2(WEST, 2, creature2);

    cc_vector.push_back(container2);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container1;

    infect.act();
    Creature& victim = game.creature_containers[0]._creature;
    CPPUNIT_ASSERT_EQUAL('f', victim._species->_name);
    CPPUNIT_ASSERT_EQUAL(2, victim._pc);
  }

  void test_infect_action3(){
    Infect infect;

    Species spec1('f', program);

    Creature creature1(&spec1);
    creature1._pc = 2;
    CreatureContainer container1(EAST, 1, creature1);

    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    game.current_creature_container = &container1;

    infect.act();
    CPPUNIT_ASSERT_EQUAL('f', creature1._species->_name);
    CPPUNIT_ASSERT_EQUAL(2, creature1._pc);
    CPPUNIT_ASSERT(NULL == game.grid[0][2]);
  }

  //test Left
  void test_left_action1(){
    Left left;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;
    
    left.act();
    CPPUNIT_ASSERT_EQUAL(WEST, container._direction);
  }
  void test_left_action2(){
    Left left;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(WEST, 5, creature);
    game.current_creature_container = &container;
    
    left.act();
    CPPUNIT_ASSERT_EQUAL(SOUTH, container._direction);
  }
  void test_left_action3(){
    Left left;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(SOUTH, 5, creature);
    game.current_creature_container = &container;
    
    left.act();
    CPPUNIT_ASSERT_EQUAL(EAST, container._direction);
  }
  void test_left_action4(){
    Left left;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(EAST, 5, creature);
    game.current_creature_container = &container;
    
    left.act();
    CPPUNIT_ASSERT_EQUAL(NORTH, container._direction);
  }

  //test Right
  void test_right_action1(){
    Right right;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(WEST, 5, creature);
    game.current_creature_container = &container;
    
    right.act();
    CPPUNIT_ASSERT_EQUAL(NORTH, container._direction);
  }
  void test_right_action2(){
    Right right;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(SOUTH, 5, creature);
    game.current_creature_container = &container;
    
    right.act();
    CPPUNIT_ASSERT_EQUAL(WEST, container._direction);
  }
  void test_right_action3(){
    Right right;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(EAST, 5, creature);
    game.current_creature_container = &container;
    
    right.act();
    CPPUNIT_ASSERT_EQUAL(SOUTH, container._direction);
  }
  void test_right_action4(){
    Right right;

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;
    
    right.act();
    CPPUNIT_ASSERT_EQUAL(EAST, container._direction);
  }

  //test Species
  //test species.execute()
  void test_species_execute1(){
    int pc = 0;
    Go go(10);
    program.push_back(&go);

    Species species('f', program);
    species.execute(pc);

    CPPUNIT_ASSERT_EQUAL(10, pc);
  }

  void test_species_execute2(){
    int pc = 0;
    Hop hop;
    program.push_back(&hop);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;
    
    species.execute(pc);

    CPPUNIT_ASSERT_EQUAL(1, pc);
  }

  void test_species_execute3(){
    int pc = 0;
    Left left;
    program.push_back(&left);

    Species species('f', program);
    Creature creature(&species);
    Game game(cc_vector, 4, 4);
    Instruction::setGame(game);
    
    CreatureContainer container(NORTH, 5, creature);
    game.current_creature_container = &container;
    
    species.execute(pc);

    CPPUNIT_ASSERT_EQUAL(1, pc);
  }

  void test_species_print1(){
    Species s1('v', program);

    std::ostringstream w;
    s1.print(w);
    std::string expected = "v";
    CPPUNIT_ASSERT(expected == w.str());
  }
  void test_species_print2(){
    Species s1('r', program);

    std::ostringstream w;
    s1.print(w);
    std::string expected = "r";
    CPPUNIT_ASSERT(expected == w.str());
  }
  void test_species_print3(){
    Species s1('f', program);

    std::ostringstream w;
    s1.print(w);
    std::string expected = "f";
    CPPUNIT_ASSERT(expected == w.str());
  }

  //test Creature's infect
  void test_creature_infect1(){
    //Make sure that the species is overwritten 
    std::vector<Instruction*> program2;
    Species spec1('f', program);
    Species spec2('v', program2);

    assert(&spec1._program != &spec2._program);

    Creature creature1(&spec1);
    Creature creature2(&spec2);

    creature1.infect(creature2);

    CPPUNIT_ASSERT_EQUAL(creature1._species, creature2._species);
  }

  void test_creature_infect2(){
    //Make sure that the PC is reset
    std::vector<Instruction*> program2;
    Species spec1('f', program);
    Species spec2('v', program2);

    assert(&spec1._program != &spec2._program);

    Creature creature1(&spec1);
    Creature creature2(&spec2);
    creature2._pc = 9000;

    creature1.infect(creature2);

    CPPUNIT_ASSERT_EQUAL(0, creature2._pc);
    CPPUNIT_ASSERT_EQUAL(creature1._species, creature2._species);

  }

  void test_creature_infect3(){
    //Verify that two creatures of the same species won't infect each other
    Species spec1('f', program);
    Creature creature1(&spec1);
    Creature creature2(&spec1);

    CPPUNIT_ASSERT_EQUAL(creature1._species, creature2._species);

    creature2._pc = 9000;
    creature1.infect(creature2);

    CPPUNIT_ASSERT_EQUAL(9000, creature2._pc);
    CPPUNIT_ASSERT_EQUAL(creature1._species, creature2._species);
  }

  void test_creature_enemy1(){
    //Verify that it returns true when it should
    Species spec1('f', program);
    Species spec2('v', program);

    Creature c1(&spec1);
    Creature c2(&spec2);
    CPPUNIT_ASSERT(c1.enemy(c2));
    CPPUNIT_ASSERT(c2.enemy(c1));
  }
  void test_creature_enemy2(){
    //Verify that it returns false when it should
    Species spec1('f', program);
    Creature c1(&spec1);
    Creature c2(&spec1);

    CPPUNIT_ASSERT(!c1.enemy(c2));
    CPPUNIT_ASSERT(!c2.enemy(c1));
  }
  void test_creature_enemy3(){
    Species spec1('f', program);
    Species spec2('f', program);

    Creature c1(&spec1);
    Creature c2(&spec2);
    CPPUNIT_ASSERT(c1.enemy(c2));
    CPPUNIT_ASSERT(c2.enemy(c1));
  }

  void test_creature_print_species1(){
    Species s1('f', program);
    Creature c1(&s1);

    std::ostringstream stream;
    c1.print_species(stream);

    CPPUNIT_ASSERT(stream.str() == "f");
  }

  void test_creature_print_species2(){
    Species s1('3', program);
    Creature c1(&s1);

    std::ostringstream stream;
    c1.print_species(stream);

    CPPUNIT_ASSERT(stream.str() == "3");
  }
  void test_creature_print_species3(){
    Species s1('1', program);
    Species s2('2', program);
    Creature c1(&s1);
    Creature c2(&s2);


    std::ostringstream stream;
    c1.print_species(stream);

    CPPUNIT_ASSERT(stream.str() == "1");

    std::ostringstream stream2;
    c2.infect(c1);
    c1.print_species(stream2);
    CPPUNIT_ASSERT(stream2.str() == "2");
  }

  //Test species print
  
  CPPUNIT_TEST_SUITE(TestDarwin);

  //Game functions:
  CPPUNIT_TEST(test_game_round1);
  CPPUNIT_TEST(test_game_round2);
  CPPUNIT_TEST(test_game_round3);

  CPPUNIT_TEST(test_game_play1);
  CPPUNIT_TEST(test_game_play2);
  CPPUNIT_TEST(test_game_play3);

  CPPUNIT_TEST(test_game_enemy_in_front1);
  CPPUNIT_TEST(test_game_enemy_in_front2);
  CPPUNIT_TEST(test_game_enemy_in_front3);

  CPPUNIT_TEST(test_game_wall_in_front1);
  CPPUNIT_TEST(test_game_wall_in_front2);
  CPPUNIT_TEST(test_game_wall_in_front3);

  CPPUNIT_TEST(test_game_empty_in_front1);
  CPPUNIT_TEST(test_game_empty_in_front2);
  CPPUNIT_TEST(test_game_empty_in_front3);

  CPPUNIT_TEST(test_game_print_blank);
  CPPUNIT_TEST(test_game_print_extra_columns);
  CPPUNIT_TEST(test_game_print_one_creature);

  CPPUNIT_TEST(test_front_coordinates_edge_x);
  CPPUNIT_TEST(test_front_coordinates_edge_y);
  CPPUNIT_TEST(test_front_coordinates_center);

  CPPUNIT_TEST(test_game_left1);
  CPPUNIT_TEST(test_game_left2);
  CPPUNIT_TEST(test_game_left3);
  CPPUNIT_TEST(test_game_left4);

  CPPUNIT_TEST(test_game_right1);
  CPPUNIT_TEST(test_game_right2);
  CPPUNIT_TEST(test_game_right3);

  CPPUNIT_TEST(test_game_hop1);
  CPPUNIT_TEST(test_game_hop2);
  CPPUNIT_TEST(test_game_hop3);

  CPPUNIT_TEST(test_game_infect1);
  CPPUNIT_TEST(test_game_infect2);
  CPPUNIT_TEST(test_game_infect3);

  ////////////////
  //Game Control tests
  ////////////////

  CPPUNIT_TEST(test_go_query1);
  CPPUNIT_TEST(test_go_query2);
  CPPUNIT_TEST(test_go_ctrl_query);

  CPPUNIT_TEST(test_go_execute);
  CPPUNIT_TEST(test_go_ctrl_execute);
  CPPUNIT_TEST(test_go_instr_execute);

  CPPUNIT_TEST(test_if_random_execute);
  CPPUNIT_TEST(test_if_random_ctrl_execute);
  CPPUNIT_TEST(test_if_random_instr_execute);
  
  CPPUNIT_TEST(test_if_random_query);
  CPPUNIT_TEST(test_if_random_ctrl_query);
  CPPUNIT_TEST(test_if_random_query2);

  CPPUNIT_TEST(test_if_wall_ctrl_query);
  CPPUNIT_TEST(test_if_wall_query);
  CPPUNIT_TEST(test_if_wall_query_corner);

  CPPUNIT_TEST(test_if_wall_execute);
  CPPUNIT_TEST(test_if_wall_ctrl_execute);
  CPPUNIT_TEST(test_if_wall_instr_execute);

  CPPUNIT_TEST(test_if_empty_query);
  CPPUNIT_TEST(test_if_empty_query_ctrl);
  CPPUNIT_TEST(test_if_empty_query_ctrl2);
 
  CPPUNIT_TEST(test_if_empty_execute);
  CPPUNIT_TEST(test_if_empty_execute_ctrl);
  CPPUNIT_TEST(test_if_empty_execute_instr);

  CPPUNIT_TEST(test_if_enemy_query);
  CPPUNIT_TEST(test_if_enemy_ctrl_query);
  CPPUNIT_TEST(test_if_enemy_query_wall);
  
  CPPUNIT_TEST(test_if_enemy_execute_false);
  CPPUNIT_TEST(test_if_enemy_execute_true);

  ////////////////////////////////
  //Action Request Tests
  ////////////////////////////////

  CPPUNIT_TEST(test_infect_action1);
  CPPUNIT_TEST(test_infect_action2);
  CPPUNIT_TEST(test_infect_action3);

  CPPUNIT_TEST(test_hop_execute_creature_in_front);
  CPPUNIT_TEST(test_hop_execute_wall_in_front);
  CPPUNIT_TEST(test_hop_execute_empty_in_front);

  CPPUNIT_TEST(test_left_action1);
  CPPUNIT_TEST(test_left_action2);
  CPPUNIT_TEST(test_left_action3);
  CPPUNIT_TEST(test_left_action4);

  CPPUNIT_TEST(test_right_action1);
  CPPUNIT_TEST(test_right_action2);
  CPPUNIT_TEST(test_right_action3);
  CPPUNIT_TEST(test_right_action4);

  CPPUNIT_TEST(test_species_execute1);
  CPPUNIT_TEST(test_species_execute2);
  CPPUNIT_TEST(test_species_execute3);

  //test species print
  CPPUNIT_TEST(test_species_print1);
  CPPUNIT_TEST(test_species_print2);
  CPPUNIT_TEST(test_species_print3);

  //test creature infect
  CPPUNIT_TEST(test_creature_infect1);
  CPPUNIT_TEST(test_creature_infect2);
  CPPUNIT_TEST(test_creature_infect3);

  //test creature print_species
  CPPUNIT_TEST(test_creature_print_species1);
  CPPUNIT_TEST(test_creature_print_species2);
  CPPUNIT_TEST(test_creature_print_species3);

  //test creature enemy
  CPPUNIT_TEST(test_creature_enemy1);
  CPPUNIT_TEST(test_creature_enemy2);
  CPPUNIT_TEST(test_creature_enemy3);

  CPPUNIT_TEST_SUITE_END();
};

int main(){
  using namespace std;
  ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
  cout << "TestDarwin.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestDarwin::suite());
  tr.run();

  cout << "Done." << endl;
  return 0;
}
