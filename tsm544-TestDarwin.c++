/*
 * TestDarwin.c++
 *
 * @author Taylor Mckinney, tsm544
 */

#include <iostream>  // ios_base
#include <sstream>
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

  void runCreatureProgram01 () {
    GameMap m (1, 1);
    Creature c0 ("food", North);
    m.addCreature(c0, 0, 0);
    CreatureData& cd0 = m.gameMap.find(point(0, 0))->second;

    CPPUNIT_ASSERT(cd0.creature.direction == North);
    CPPUNIT_ASSERT(!cd0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd0.x == 0);
    CPPUNIT_ASSERT(cd0.y == 0);
    CPPUNIT_ASSERT(cd0.creature.currentLineNumber == 0);
    CPPUNIT_ASSERT(cd0.creature.instructions[0] == "left");
    
    m.runCreatureProgram(cd0);
    
    CPPUNIT_ASSERT(cd0.creature.direction == West);
    CPPUNIT_ASSERT(cd0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd0.x == 0);
    CPPUNIT_ASSERT(cd0.y == 0);
    CPPUNIT_ASSERT(cd0.creature.currentLineNumber == 1);
  }
  
  void runCreatureProgram02 () {
    GameMap m (1, 1);
    Creature c0 ("hopper", North);
    m.addCreature(c0, 0, 0);
    CreatureData& cd0 = m.gameMap.find(point(0, 0))->second;

    CPPUNIT_ASSERT(cd0.creature.direction == North);
    CPPUNIT_ASSERT(!cd0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd0.x == 0);
    CPPUNIT_ASSERT(cd0.y == 0);
    CPPUNIT_ASSERT(cd0.creature.currentLineNumber == 0);
    CPPUNIT_ASSERT(cd0.creature.instructions[0] == "hop");
    
    m.runCreatureProgram(cd0);
    
    CPPUNIT_ASSERT(cd0.creature.direction == North);
    CPPUNIT_ASSERT(cd0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd0.x == 0);
    CPPUNIT_ASSERT(cd0.y == 0);
    CPPUNIT_ASSERT(cd0.creature.currentLineNumber == 1);
  }
  
  void runCreatureProgram03 () {
    GameMap m (5, 5);
    Creature c0 ("hopper", North);
    m.addCreature(c0, 4, 0);
    CreatureData cd0 = m.gameMap.find(point(4, 0))->second;

    CPPUNIT_ASSERT(cd0.creature.direction == North);
    CPPUNIT_ASSERT(!cd0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd0.x == 4);
    CPPUNIT_ASSERT(cd0.y == 0);
    CPPUNIT_ASSERT(cd0.creature.currentLineNumber == 0);
    CPPUNIT_ASSERT(cd0.creature.instructions[0] == "hop");
    
    m.runCreatureProgram(cd0);

    CreatureData cd1 = m.gameMap.find(point(3, 0))->second;
    
    CPPUNIT_ASSERT(cd1.creature.direction == North);
    CPPUNIT_ASSERT(cd1.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(cd1.x == 3);
    CPPUNIT_ASSERT(cd1.y == 0);
    CPPUNIT_ASSERT(cd1.creature.currentLineNumber == 1);
  }

  // TODO Must test overloaded ostream operator
  void ostreamOperator01 () {
    GameMap m (1, 1);
    ostringstream oss;
    string expectedResult = "  0\n0 .\n";
    
    oss << m;

    CPPUNIT_ASSERT(oss.str() == expectedResult);
  }
  
  void ostreamOperator02 () {
    GameMap m (1, 1);
    Creature c ("hopper", North);
    m.addCreature(c, 0, 0);
    
    ostringstream oss;
    string expectedResult = "  0\n0 h\n";
    
    oss << m;

    CPPUNIT_ASSERT(oss.str() == expectedResult);
  }

  void ostreamOperator03 () {
    GameMap m (5, 5);

    Creature c0 ("hopper", North);
    Creature c1 ("food", North);
    Creature c2 ("rover", North);
    Creature c3 ("trap", North);

    m.addCreature(c0, 0, 0);
    m.addCreature(c1, 1, 1);
    m.addCreature(c2, 2, 2);
    m.addCreature(c3, 3, 3);
    
    ostringstream oss;
    string expectedResult = "  01234\n0 h....\n1 .f...\n2 ..r..\n3 ...t.\n4 .....\n";
    
    oss << m;

    CPPUNIT_ASSERT(oss.str() == expectedResult);
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

  CPPUNIT_TEST(runCreatureProgram01);
  CPPUNIT_TEST(runCreatureProgram02);
  CPPUNIT_TEST(runCreatureProgram03);

  CPPUNIT_TEST(ostreamOperator01);
  CPPUNIT_TEST(ostreamOperator02);
  CPPUNIT_TEST(ostreamOperator03);
  
  CPPUNIT_TEST_SUITE_END();
};

struct TestDarwin : CppUnit::TestFixture {
  // Only one constructor with only one path of execution
  void constructor01 () {
    ostringstream w;
    Darwin d(0, 0, w);

    CPPUNIT_ASSERT(d.map.height == 0);
    CPPUNIT_ASSERT(d.map.width == 0);
    CPPUNIT_ASSERT(d.output == w);
  }

  void constructor02 () {
    ostringstream w;
    int x = rand() % 1000000;
    int y = rand() % 1000000;

    Darwin d (x, y, w);

    CPPUNIT_ASSERT(d.map.height == x);
    CPPUNIT_ASSERT(d.map.width == y);
    CPPUNIT_ASSERT(d.output == w);
  }

  void addCreature01 () {
    ostringstream w;
    Darwin d(1, 1, w);
    Creature c0("hopper", North);

    d.addCreature(c0, 0, 0);

    CPPUNIT_ASSERT(d.map.gameMap.find(point(0, 0)) != d.map.gameMap.end());
    
    CreatureData& test0 = d.map.gameMap.find(point(0, 0))->second;

    CPPUNIT_ASSERT(test0.creature.species == "hopper");
    CPPUNIT_ASSERT(test0.creature.direction == North);
    CPPUNIT_ASSERT(test0.x == 0);
    CPPUNIT_ASSERT(test0.y == 0);
    CPPUNIT_ASSERT(!test0.alreadyMovedThisTurn);
  }

  void addCreature02 () {
    ostringstream w;
    Darwin d (1, 1, w);
    Creature c0 ("hopper", North);
    Creature c1 ("rover", South);

    d.addCreature(c0, 0, 0);
    d.addCreature(c1, 0, 0);

    CPPUNIT_ASSERT(d.map.gameMap.find(point(0, 0)) != d.map.gameMap.end());
    
    CreatureData& test0 = d.map.gameMap.find(point(0, 0))->second;

    CPPUNIT_ASSERT(test0.creature.species == "hopper");
    CPPUNIT_ASSERT(test0.creature.direction == North);
    CPPUNIT_ASSERT(test0.x == 0);
    CPPUNIT_ASSERT(test0.y == 0);
    CPPUNIT_ASSERT(!test0.alreadyMovedThisTurn);
  }

  void addCreature03 () {
    ostringstream w;
    Darwin d (4, 4, w);
    Creature c0 ("hopper", North);
    Creature c1 ("rover", South);
    Creature c2 ("food", East);
    Creature c3 ("trap", West);

    d.addCreature(c0, 0, 0);
    d.addCreature(c1, 1, 1);
    d.addCreature(c2, 2, 2);
    d.addCreature(c3, 3, 3);

    CPPUNIT_ASSERT(d.map.gameMap.find(point(0, 0)) != d.map.gameMap.end());
    CPPUNIT_ASSERT(d.map.gameMap.find(point(1, 1)) != d.map.gameMap.end());
    CPPUNIT_ASSERT(d.map.gameMap.find(point(2, 2)) != d.map.gameMap.end());
    CPPUNIT_ASSERT(d.map.gameMap.find(point(3, 3)) != d.map.gameMap.end());
    
    CreatureData& test0 = d.map.gameMap.find(point(0, 0))->second;
    CreatureData& test1 = d.map.gameMap.find(point(1, 1))->second;
    CreatureData& test2 = d.map.gameMap.find(point(2, 2))->second;
    CreatureData& test3 = d.map.gameMap.find(point(3, 3))->second;

    CPPUNIT_ASSERT(test0.creature.species == "hopper");
    CPPUNIT_ASSERT(test0.creature.direction == North);
    CPPUNIT_ASSERT(test0.x == 0);
    CPPUNIT_ASSERT(test0.y == 0);
    CPPUNIT_ASSERT(!test0.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(test1.creature.species == "rover");
    CPPUNIT_ASSERT(test1.creature.direction == South);
    CPPUNIT_ASSERT(test1.x == 1);
    CPPUNIT_ASSERT(test1.y == 1);
    CPPUNIT_ASSERT(!test1.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(test2.creature.species == "food");
    CPPUNIT_ASSERT(test2.creature.direction == East);
    CPPUNIT_ASSERT(test2.x == 2);
    CPPUNIT_ASSERT(test2.y == 2);
    CPPUNIT_ASSERT(!test2.alreadyMovedThisTurn);
    CPPUNIT_ASSERT(test3.creature.species == "trap");
    CPPUNIT_ASSERT(test3.creature.direction == West);
    CPPUNIT_ASSERT(test3.x == 3);
    CPPUNIT_ASSERT(test3.y == 3);
    CPPUNIT_ASSERT(!test3.alreadyMovedThisTurn);
  }

  void run01 () {
    ostringstream w;
    Darwin d (1, 1, w);
    Creature c0 ("food", North);

    d.addCreature(c0, 0, 0);

    Creature& cr0 = d.map.gameMap.find(point(0, 0))->second.creature;
    CPPUNIT_ASSERT(cr0.direction == North);

    d.run(1, 1);

    CPPUNIT_ASSERT(cr0.direction == West);
  }

  void run02 () {
    ostringstream w;
    Darwin d (2, 1, w);
    Creature c0 ("hopper", North);

    d.addCreature(c0, 1, 0);

    CreatureData& cdr0 = d.map.gameMap.find(point(1, 0))->second;
    CPPUNIT_ASSERT(cdr0.creature.direction == North);

    d.run(1, 1);

    CPPUNIT_ASSERT(d.map.gameMap.find(point(0, 0)) != d.map.gameMap.end());

    CreatureData& cdrt0 = d.map.gameMap.find(point(0, 0))->second;
    CPPUNIT_ASSERT(cdrt0.x == 0);
    CPPUNIT_ASSERT(cdrt0.y == 0);
  }

  void run03 () {
    ostringstream w;
    Darwin d (2, 2, w);
    Creature c0 ("food", North);
    Creature c1 ("rover", North);

    d.addCreature(c0, 0, 0);
    d.addCreature(c1, 1, 0);

    CreatureData& cdr0 = d.map.gameMap.find(point(0, 0))->second;
    CreatureData& cdr1 = d.map.gameMap.find(point(1, 0))->second;
    CPPUNIT_ASSERT(cdr1.creature.direction == North);

    d.run(1, 1);

    CPPUNIT_ASSERT(d.map.gameMap.find(point(0, 0)) != d.map.gameMap.end());
    CPPUNIT_ASSERT(d.map.gameMap.find(point(1, 0)) != d.map.gameMap.end());

    CreatureData& cdrt0 = d.map.gameMap.find(point(0, 0))->second;
    CreatureData& cdrt1 = d.map.gameMap.find(point(1, 0))->second;

    CPPUNIT_ASSERT(cdrt0.creature.species == "rover");
    CPPUNIT_ASSERT(cdrt1.creature.species == "rover");
  }

  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestDarwin);

  CPPUNIT_TEST(constructor01);
  CPPUNIT_TEST(constructor02);

  CPPUNIT_TEST(addCreature01);
  CPPUNIT_TEST(addCreature02);
  CPPUNIT_TEST(addCreature03);

  CPPUNIT_TEST(run01);
  CPPUNIT_TEST(run02);
  CPPUNIT_TEST(run03);
  
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
