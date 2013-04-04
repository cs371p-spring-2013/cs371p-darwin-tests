/*
 * TestDarwin.c++
 *
 * @author Taylor Mckinney, tsm544
 */

#include <iostream>  // ios_base
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"
#include "GameMap.h"
#include "Creature.h"


struct TestCreature : CppUnit::TestFixture {

  void constructor01 () {
    Creature c ("food", North);
    CPPUNIT_ASSERT(c.species == "food");
    CPPUNIT_ASSERT(c.direction == North);
    CPPUNIT_ASSERT(c.instructions[0] == "left");
    CPPUNIT_ASSERT(c.instructions[1] == "go 0");
  }

  void constructor02 () {
    Creature c ("hopper", South);
    CPPUNIT_ASSERT(c.species == "hopper");
    CPPUNIT_ASSERT(c.direction == South);
    CPPUNIT_ASSERT(c.instructions[0] == "hop");
    CPPUNIT_ASSERT(c.instructions[1] == "go 0");
  }

  void constructor03 () {
    Creature c ("rover", East);
    CPPUNIT_ASSERT(c.species == "rover");
    CPPUNIT_ASSERT(c.direction == East);
    CPPUNIT_ASSERT(c.instructions[0] == "if_enemy 9");
    CPPUNIT_ASSERT(c.instructions[1] == "if_empty 7");
    CPPUNIT_ASSERT(c.instructions[2] == "if_random 5");
    CPPUNIT_ASSERT(c.instructions[3] == "left");
    CPPUNIT_ASSERT(c.instructions[4] == "go 0");
    CPPUNIT_ASSERT(c.instructions[5] == "right");
    CPPUNIT_ASSERT(c.instructions[6] == "go 0");
    CPPUNIT_ASSERT(c.instructions[7] == "hop");
    CPPUNIT_ASSERT(c.instructions[8] == "go 0");
    CPPUNIT_ASSERT(c.instructions[9] == "infect");
    CPPUNIT_ASSERT(c.instructions[10] == "go 0");
  }
  
  void constructor04 () {
    Creature c ("trap", West);
    CPPUNIT_ASSERT(c.species == "trap");
    CPPUNIT_ASSERT(c.direction == West);
    CPPUNIT_ASSERT(c.instructions[0] == "if_enemy 3");
    CPPUNIT_ASSERT(c.instructions[1] == "left");
    CPPUNIT_ASSERT(c.instructions[2] == "go 0");
    CPPUNIT_ASSERT(c.instructions[3] == "infect");
    CPPUNIT_ASSERT(c.instructions[4] == "go 0");
  }

  void left01 () {
    Creature c("food", North);
    CPPUNIT_ASSERT(c.direction == North);
    c.left();
    CPPUNIT_ASSERT(c.direction == West);
  }
  
  void left02 () {
    Creature c("food", West);
    CPPUNIT_ASSERT(c.direction == West);
    c.left();
    CPPUNIT_ASSERT(c.direction == South);
  }
  
  void left03 () {
    Creature c("food", South);
    CPPUNIT_ASSERT(c.direction == South);
    c.left();
    CPPUNIT_ASSERT(c.direction == East);
  }
  
  void left04 () {
    Creature c("food", East);
    CPPUNIT_ASSERT(c.direction == East);
    c.left();
    CPPUNIT_ASSERT(c.direction == North);
  }
  
  void right01 () {
    Creature c("food", North);
    CPPUNIT_ASSERT(c.direction == North);
    c.right();
    CPPUNIT_ASSERT(c.direction == East);
  }
  
  void right02 () {
    Creature c("food", East);
    CPPUNIT_ASSERT(c.direction == East);
    c.right();
    CPPUNIT_ASSERT(c.direction == South);
  }
  
  void right03 () {
    Creature c("food", South);
    CPPUNIT_ASSERT(c.direction == South);
    c.right();
    CPPUNIT_ASSERT(c.direction == West);
  }
  
  void right04 () {
    Creature c("food", West);
    CPPUNIT_ASSERT(c.direction == West);
    c.right();
    CPPUNIT_ASSERT(c.direction == North);
  }

  void infect01 () {
    Creature c0 ("rover", North);
    Creature c1 ("food", South);
    c1.currentLineNumber = 1;

    CPPUNIT_ASSERT(c0.species == "rover");
    CPPUNIT_ASSERT(c1.species == "food");
    CPPUNIT_ASSERT(c1.currentLineNumber == 1);

    c0.infect(c1);

    CPPUNIT_ASSERT(c0.species == "rover");
    CPPUNIT_ASSERT(c1.species == "rover");
    CPPUNIT_ASSERT(c1.currentLineNumber == 0);   
  }

  void infect02 () {
    Creature c0 ("food", North);
    Creature c1 ("food", South);
    c1.currentLineNumber = 1;

    CPPUNIT_ASSERT(c0.species == "food");
    CPPUNIT_ASSERT(c1.species == "food");
    CPPUNIT_ASSERT(c1.currentLineNumber == 1);
    CPPUNIT_ASSERT(c1.direction == South);

    c0.infect(c1);

    CPPUNIT_ASSERT(c0.species == "food");
    CPPUNIT_ASSERT(c1.species == "food");
    CPPUNIT_ASSERT(c1.currentLineNumber == 0);
    CPPUNIT_ASSERT(c1.direction == South);
  }

  void infect03 () {
    Creature c0 ("rover", North);
    Creature c1 ("hopper", South);
    c1.currentLineNumber = 1;

    CPPUNIT_ASSERT(c0.species == "rover");
    CPPUNIT_ASSERT(c1.species == "hopper");
    CPPUNIT_ASSERT(c1.currentLineNumber == 1);
    CPPUNIT_ASSERT(c1.direction == South);

    c0.infect(c1);

    CPPUNIT_ASSERT(c0.species == "rover");
    CPPUNIT_ASSERT(c1.species == "rover");
    CPPUNIT_ASSERT(c1.currentLineNumber == 0); 
    CPPUNIT_ASSERT(c1.direction == South);
  }

  void getNextAction01 () {
    Creature c ("food", North);
    string s = c.getNextAction(false, false, false);
    CPPUNIT_ASSERT(s == "left");
  }

  void getNextAction02 () {
    Creature c ("rover", North);
    string s = c.getNextAction(false, false, false);
    CPPUNIT_ASSERT(s == "left" || s == "right");
  }

  void getNextAction03 () {
    Creature c ("hopper", North);
    string s = c.getNextAction(false, false, false);
    CPPUNIT_ASSERT(s == "hop");
  }

  // Simple but unavoidable getters
  // Only one test each
  void getSpecies01 () {
    Creature c ("hopper", North);
    CPPUNIT_ASSERT(c.getSpecies() == c.species);
  }

  void getDirection01 () {
    Creature c ("hopper", North);
    CPPUNIT_ASSERT(c.getDirection() == c.direction);
  }
   
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestCreature);

  CPPUNIT_TEST(constructor01);
  CPPUNIT_TEST(constructor02);
  CPPUNIT_TEST(constructor03);
  CPPUNIT_TEST(constructor04);

  CPPUNIT_TEST(left01);
  CPPUNIT_TEST(left02);
  CPPUNIT_TEST(left03);
  CPPUNIT_TEST(left04);

  CPPUNIT_TEST(right01);
  CPPUNIT_TEST(right02);
  CPPUNIT_TEST(right03);
  CPPUNIT_TEST(right04);

  CPPUNIT_TEST(infect01);
  CPPUNIT_TEST(infect02);
  CPPUNIT_TEST(infect03);

  CPPUNIT_TEST(getNextAction01);
  CPPUNIT_TEST(getNextAction02);
  CPPUNIT_TEST(getNextAction03);

  CPPUNIT_TEST(getSpecies01);
  CPPUNIT_TEST(getDirection01);


  CPPUNIT_TEST_SUITE_END();
};

// Only one constructor
// with only one execution path
// Just testing it once
struct TestCreatureData : CppUnit::TestFixture {
  void constructor01 () {
    Creature c0 ("food", North);
    CreatureData c (c0, 0, 0);
    CPPUNIT_ASSERT(c.creature.species == c0.species);
    CPPUNIT_ASSERT(c.creature.direction == c0.direction);
    CPPUNIT_ASSERT(c.x == 0);
    CPPUNIT_ASSERT(c.y == 0);
    CPPUNIT_ASSERT(!c.alreadyMovedThisTurn);
  }

  CPPUNIT_TEST_SUITE(TestCreatureData);
  CPPUNIT_TEST(constructor01);
  CPPUNIT_TEST_SUITE_END();
};

struct TestGameMap : CppUnit::TestFixture {

  // Constructor has only one path of execution
  void constructor01 () {
    GameMap m (0, 0);
    CPPUNIT_ASSERT(m.height == 0);
    CPPUNIT_ASSERT(m.width == 0);
  }
  
  void constructor02 () {
    srand(0);
    int x1 = rand() % 1000000;
    int y1 = rand() % 1000000;
    GameMap m (x1, y1);
    CPPUNIT_ASSERT(m.height == x1);
    CPPUNIT_ASSERT(m.width == y1);
  }

  void addCreature01 () {
    GameMap m (1, 1);
    Creature c ("hopper", North);
    m.addCreature(c, 0, 0);

    CPPUNIT_ASSERT(m.gameMap.find(point(0, 0))->second.creature.species == "hopper");
    CPPUNIT_ASSERT(m.gameMap.find(point(0, 0))->second.creature.direction == North);
  }
  
  void addCreature02 () {
    GameMap m (5, 5);
    Creature c ("hopper", North);
    m.addCreature(c, 2, 2);

    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.species == "hopper");
    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.direction == North);
  }

  void addCreature03 () {
    GameMap m (5, 5);
    Creature c0 ("hopper", North);
    Creature c1 ("food", South);
    
    m.addCreature(c0, 2, 2);
    m.addCreature(c1, 2, 2);

    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.species == "hopper");
    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.direction == North);
  }

  void addCreature04 () {
    GameMap m (5, 5);
    Creature c0 ("hopper", North);
    Creature c1 ("food", South);
    Creature c2 ("trap", West);
    Creature c3 ("rover", East);
    
    m.addCreature(c0, 2, 2);
    m.addCreature(c1, 3, 2);
    m.addCreature(c2, 2, 3);
    m.addCreature(c3, 3, 3);

    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.species == "hopper");
    CPPUNIT_ASSERT(m.gameMap.find(point(2, 2))->second.creature.direction == North);
    CPPUNIT_ASSERT(m.gameMap.find(point(3, 2))->second.creature.species == "food");
    CPPUNIT_ASSERT(m.gameMap.find(point(3, 2))->second.creature.direction == South);
    CPPUNIT_ASSERT(m.gameMap.find(point(2, 3))->second.creature.species == "trap");
    CPPUNIT_ASSERT(m.gameMap.find(point(2, 3))->second.creature.direction == West);
    CPPUNIT_ASSERT(m.gameMap.find(point(3, 3))->second.creature.species == "rover");
    CPPUNIT_ASSERT(m.gameMap.find(point(3, 3))->second.creature.direction == East);
  }

  void resetCreatureTurns01 () {
    GameMap m(0, 0);
    // No-op, just making sure we don't crash
    m.resetCreatureTurns();
  }

  void resetCreatureTurns02 () {
    GameMap m(1, 1);

    Creature c ("hopper", North);
    m.addCreature (c, 0, 0);
    bool& test = m.gameMap.find(point(0, 0))->second.alreadyMovedThisTurn;
    test = true;
    CPPUNIT_ASSERT(test == true);
    m.resetCreatureTurns();
    CPPUNIT_ASSERT(test == false);
  }

  void resetCreatureTurns03 () {
    GameMap m(5, 5);

    Creature c0 ("hopper", North);
    m.addCreature (c0, 0, 0);
    bool& test0 = m.gameMap.find(point(0, 0))->second.alreadyMovedThisTurn;

    Creature c1 ("food", North);
    m.addCreature (c1, 1, 1);
    bool& test1 = m.gameMap.find(point(1, 1))->second.alreadyMovedThisTurn;

    Creature c2 ("rover", North);
    m.addCreature (c2, 2, 2);
    bool& test2 = m.gameMap.find(point(2, 2))->second.alreadyMovedThisTurn;

    Creature c3 ("rover", North);
    m.addCreature (c3, 3, 3);
    bool& test3 = m.gameMap.find(point(3, 3))->second.alreadyMovedThisTurn;
        
    test0 = true;
    test1 = true;
    test2 = true;
    test3 = true;
    CPPUNIT_ASSERT(test0 == true);
    CPPUNIT_ASSERT(test1 == true);
    CPPUNIT_ASSERT(test2 == true);
    CPPUNIT_ASSERT(test3 == true);
    m.resetCreatureTurns();
    CPPUNIT_ASSERT(test0 == false);
    CPPUNIT_ASSERT(test1 == false);
    CPPUNIT_ASSERT(test2 == false);
    CPPUNIT_ASSERT(test3 == false);
  }

  void runStep01() {
    GameMap m (0, 0);
    // No-op, just making sure we don't crash
    m.runStep();
  }

  void runStep02 () {
    GameMap m (1, 1);
    
    Creature c0 ("food", North);
    m.addCreature(c0, 0, 0);
    bool& test0 = m.gameMap.find(point(0, 0))->second.alreadyMovedThisTurn;

    CPPUNIT_ASSERT(!test0);
    m.runStep();
    CPPUNIT_ASSERT(!test0);
  }

  void runStep03 () {
    GameMap m (1, 1);
    
    Creature c0 ("food", North);
    m.addCreature(c0, 0, 0);
    bool& test0 = m.gameMap.find(point(0, 0))->second.alreadyMovedThisTurn;
    test0 = true;

    CPPUNIT_ASSERT(test0);
    m.runStep();
    CPPUNIT_ASSERT(!test0);
  }
  
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestGameMap);
  
  CPPUNIT_TEST(constructor01);
  CPPUNIT_TEST(constructor02);

  CPPUNIT_TEST(addCreature01);
  CPPUNIT_TEST(addCreature02);
  CPPUNIT_TEST(addCreature03);
  CPPUNIT_TEST(addCreature04);

  CPPUNIT_TEST(resetCreatureTurns01);
  CPPUNIT_TEST(resetCreatureTurns02);
  CPPUNIT_TEST(resetCreatureTurns03);

  CPPUNIT_TEST(runStep01);
  CPPUNIT_TEST(runStep02);
  CPPUNIT_TEST(runStep03);
  
  CPPUNIT_TEST_SUITE_END();
};

struct TestDarwin : CppUnit::TestFixture {


  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST_SUITE_END();
};

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
  CppUnit::TextTestRunner tr;

  tr.addTest(TestDarwin::suite());
  tr.addTest(TestCreatureData::suite());
  tr.addTest(TestGameMap::suite());
  tr.addTest(TestCreature::suite());

  tr.run();
  return 0;
}
