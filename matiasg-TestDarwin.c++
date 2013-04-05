
/*
 To test the program:
 % ls /usr/include/cppunit/
 ...
 TestFixture.h
 ...
 % locate libcppunit.a
 /usr/lib/libcppunit.a
 % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl
 % valgrind TestCollatz >& TestCollatz.out
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
#define class struct
#include "Darwin.h"


struct TestDarwin : CppUnit::TestFixture {

  void test_creature() {
    Creature c;
    CPPUNIT_ASSERT(c._specName==FOOD);
    CPPUNIT_ASSERT(c._pc==0);}

  void test_creature_2() {
    Creature c(NORTH, FOOD, 0, 4,5);
    CPPUNIT_ASSERT(c._specName == FOOD);
    CPPUNIT_ASSERT(c._pc == 0);
    CPPUNIT_ASSERT(c._d == NORTH);
    CPPUNIT_ASSERT(c._pos.first == 4);
    CPPUNIT_ASSERT(c._pos.second == 5);
  }

  void test_creature_3() {
    Creature c(SOUTH,ROVER,0,0,0);
    CPPUNIT_ASSERT(c._specName == ROVER);
  }
 
  void test_creature_move() {
    Creature c(NORTH, FOOD, 0, 0,0);
    c.move('.');
    CPPUNIT_ASSERT(c._d == WEST);
  }

  void test_creature_move_2() {
    Creature c(NORTH, FOOD, 0, 0,0);
    Instruction i = c.move('.');
    CPPUNIT_ASSERT(i.cmd == LEFT);
    CPPUNIT_ASSERT(i.dir == WEST);
  }
  void test_creature_move_3() {
    Creature c(SOUTH, ROVER, 0, 0,0);
    Instruction i = c.move('e');
    CPPUNIT_ASSERT(i.cmd == INFECT);
    CPPUNIT_ASSERT(i.dir == SOUTH);;
  }
  void test_creature_computeFront() {
    Creature c(SOUTH, ROVER, 0, 0,0);
    std::pair<int,int> x = c.computeFront(std::make_pair(0,0));
    CPPUNIT_ASSERT(x.second == 1);
  }
  void test_creature_computeFront_2() {
    Creature c(EAST, ROVER, 0, 0,0);
    std::pair<int,int> x = c.computeFront(std::make_pair(0,0));
    CPPUNIT_ASSERT(x.first == 1);
    CPPUNIT_ASSERT(x.second == 0);
  }
  void test_creature_computeFront_3() {
    Creature c(NORTH, ROVER, 0, 0,5);
    std::pair<int,int> x = c.computeFront(std::make_pair(0,5));
    CPPUNIT_ASSERT(x.first == 0);
    CPPUNIT_ASSERT(x.second == 4);
  }
  void test_creature_isEnemy(){
    Creature c;
    Creature d(NORTH, ROVER, 0,0,0);
    CPPUNIT_ASSERT(c.isEnemy(d));
  }
  void test_creature_isEnemy_2(){
    Creature c;
    Creature d(NORTH, FOOD, 0,0,0);
    CPPUNIT_ASSERT(!c.isEnemy(d));
  }
  void test_creature_isEnemy_3(){
    Creature c(SOUTH,TRAP,0,0,1);
    Creature d(NORTH, FOOD, 0,0,0);
    CPPUNIT_ASSERT(c.isEnemy(d));
  }
  void test_creature_infect(){
    Creature c(NORTH,ROVER,1,2,3);
    Creature d(NORTH, FOOD, 0,0,0);
    c.infect(d);
    CPPUNIT_ASSERT(c._specName == d._specName);
  }
  void test_creature_infect_2(){
    Creature c(NORTH,ROVER,1,2,3);
    Creature d(NORTH, TRAP, 10,0,0);
    d.infect(c);
    CPPUNIT_ASSERT(d._specName == c._specName);
    CPPUNIT_ASSERT(c._pc == 0);
  }
  void test_creature_infect_3(){
    Creature c(NORTH,ROVER,1,2,3);
    Creature d(NORTH, ROVER, 4,0,0);
    c.infect(d);
    CPPUNIT_ASSERT(c._specName == d._specName);
    CPPUNIT_ASSERT(d._pc == 4);
  }
  void test_game() {
    Game g;
    CPPUNIT_ASSERT(g._x == 10);
    CPPUNIT_ASSERT(g._y == 10);
  }
  void test_game_2() {
    Game g(8,8);
    CPPUNIT_ASSERT(g._x == 8);
    CPPUNIT_ASSERT(g._y == 8);
  }
  void test_game_3() {
    Game g(5,10);
    CPPUNIT_ASSERT(g._x == 5);
    CPPUNIT_ASSERT(g._y == 10);
  }
  void test_game_addcreature() {
    Game g;
    g.addCreature(NORTH, FOOD,  0, 0);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'f');
  }
  void test_game_addcreature_2() {
    Game g;
    g.addCreature(NORTH, FOOD,  0, 0);
    CPPUNIT_ASSERT(g.seen[g.world[std::make_pair(0,0)]] == false);
  }
  void test_game_addcreature_3() {
    Game g;
    g.addCreature(NORTH, ROVER,  0, 0);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'r');
  }
  void test_game_addcreature_4() {
    Game g;
    g.addCreature(NORTH, ROVER,  0, 0);
    g.addCreature(NORTH, BEST,  0, 0);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'b');
  }
  void test_game_update() {
    Game g;
    g.addCreature(SOUTH,HOPPER,  0,0);
    g.update();
    CPPUNIT_ASSERT(g.world.count(std::make_pair(0,0)) == 0);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,1)]] == 'h');
  }
  void test_game_update_2() {
    Game g;
    g.addCreature(SOUTH,FOOD,  0,0);
    g.update();
    CPPUNIT_ASSERT(g.creatures[g.world[std::make_pair(0,1)]]._d == EAST);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'f');
  }
  void test_game_update_3() {
    Game g;
    g.addCreature(SOUTH,FOOD,  0,0);
    g.addCreature(NORTH,BEST,1,0);
    g.update();
    CPPUNIT_ASSERT(g.creatures[g.world[std::make_pair(0,0)]]._specName == BEST);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'b');
  }
  void test_game_hop() {
    Game g;
    g.addCreature(SOUTH,ROVER,  0,0);
    g.hop(std::make_pair(0,0), SOUTH);
    CPPUNIT_ASSERT(g.world.count(std::make_pair(0,0)) == 0);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,1)]] == 'r');
  }
  
  void test_game_hop_2() {
    Game g;
    g.addCreature(SOUTH,ROVER,  0,0);
    g.hop(std::make_pair(0,0), NORTH);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'r');
  }
  void test_game_hop_3() {
    Game g;
    g.addCreature(NORTH, FOOD,  1, 0);
    g.addCreature(SOUTH, ROVER, 0, 0);
    g.hop(std::make_pair(0,0), SOUTH);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'r');
  }
  void test_game_infect() {
    Game g;
    g.addCreature(NORTH, FOOD,  1, 0);
    g.addCreature(SOUTH,ROVER,  0,0);
    g.infect(std::make_pair(1,0),NORTH);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] != 'f');
  }
  void test_game_infect_2() {
    Game g;
    g.addCreature(NORTH, FOOD,  1, 0);
    g.addCreature(SOUTH, ROVER, 0, 0);
    g.infect(std::make_pair(0,0), SOUTH);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,1)]] == 'r');
  }
  void test_game_infect_3() {
    Game g;
    g.addCreature(NORTH, ROVER,  1, 0);
    g.addCreature(SOUTH, BEST, 0, 0);
    g.infect(std::make_pair(0,0), SOUTH);
    CPPUNIT_ASSERT(g.graphics[g.world[std::make_pair(0,0)]] == 'b');
  }
  // -----
  // suite
  // -----
  
  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST(test_creature);
  CPPUNIT_TEST(test_creature_2);
  CPPUNIT_TEST(test_creature_3);
  CPPUNIT_TEST(test_creature_move);
  CPPUNIT_TEST(test_creature_move_2);
  CPPUNIT_TEST(test_creature_move_3);
  CPPUNIT_TEST(test_creature_computeFront);
  CPPUNIT_TEST(test_creature_computeFront_2);
  CPPUNIT_TEST(test_creature_computeFront_3);
  CPPUNIT_TEST(test_creature_isEnemy);
  CPPUNIT_TEST(test_creature_isEnemy_2);
  CPPUNIT_TEST(test_creature_isEnemy_3);
  CPPUNIT_TEST(test_creature_infect); 
  CPPUNIT_TEST(test_creature_infect_2);
  CPPUNIT_TEST(test_creature_infect_3);
  CPPUNIT_TEST(test_game);
  CPPUNIT_TEST(test_game_2);
  CPPUNIT_TEST(test_game_3);
  CPPUNIT_TEST(test_game_addcreature);
  CPPUNIT_TEST(test_game_addcreature_2);
  CPPUNIT_TEST(test_game_addcreature_3);
  CPPUNIT_TEST(test_game_addcreature_4);
  CPPUNIT_TEST(test_game_update);
  CPPUNIT_TEST(test_game_update_2);
  CPPUNIT_TEST(test_game_update_3);
  CPPUNIT_TEST(test_game_hop);
  CPPUNIT_TEST(test_game_hop_2);
  CPPUNIT_TEST(test_game_hop_3);
  CPPUNIT_TEST(test_game_infect);
  CPPUNIT_TEST(test_game_infect_2);
  CPPUNIT_TEST(test_game_infect_3);
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

