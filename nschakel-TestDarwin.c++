
// --------
// includes
// --------

#include <algorithm> //count
#include <iostream> // ios_base
#include <memory> //allocator
#include <sstream> //string stream

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner



#define protected public
#define private public
#define class struct

#include "Darwin.h"

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture 
{

    void testIsAction()
    {
      Instruction i(Instruction::HOP);
      CPPUNIT_ASSERT(i.isAction());
    }

    void testIsAction2()
    {
      Instruction i(Instruction::GO, 7, 0);
      CPPUNIT_ASSERT(!i.isAction());
    }

    void testIsAction3()
    {
      Instruction i(Instruction::IF_EMPTY, 9, 0);
      CPPUNIT_ASSERT(!i.isAction());
      
    }

    void testSpeciesGetInstruction()
    {
      Species s = buildFood();
      CPPUNIT_ASSERT(s.getInstruction(0).isAction());
      CPPUNIT_ASSERT(!s.getInstruction(1).isAction());
    }

    void testSpeciesGetInstruction2()
    {
      Species s = buildHopper();
      CPPUNIT_ASSERT(s.getInstruction(0).isAction());
    }

    void testSpeciesGetInstruction3()
    {
      Species s = buildRover();
      CPPUNIT_ASSERT(!s.getInstruction(10).isAction());
      CPPUNIT_ASSERT(s.getInstruction(5).isAction());
    }

    void testCreatureNextInstruction()
    {
      Species s = buildHopper();
      Creature c(s, Creature::NORTH);
      CPPUNIT_ASSERT(c.nextInstruction().isAction());
      CPPUNIT_ASSERT(!c.nextInstruction().isAction());
      CPPUNIT_ASSERT(c.direction == Creature::NORTH);
    }

    void testCreatureNextInstruction2()
    {
      Species s = buildRover();
      Creature c(s, Creature::SOUTH);
      CPPUNIT_ASSERT(!c.nextInstruction().isAction());
      CPPUNIT_ASSERT(c.nextInstruction(5).isAction());
    }

    void testCreatureNextInstruction3()
    {
      Species s = buildRover();
      Creature c(s, Creature::EAST);
      CPPUNIT_ASSERT(!c.nextInstruction().isAction());
      CPPUNIT_ASSERT(c.nextInstruction(5).isAction());
      CPPUNIT_ASSERT(!c.nextInstruction().isAction());
      CPPUNIT_ASSERT(!c.nextInstruction(0).isAction());
      CPPUNIT_ASSERT(c.nextInstruction(9).isAction());
    }

    void testCreatureEquals()
    {
      Creature c1(buildRover(), Creature::EAST);
      Creature c2(buildRover(), Creature::NORTH);
      Creature c3(buildFood(), Creature::WEST);

      CPPUNIT_ASSERT(c1.speciesEqual(c2));
      CPPUNIT_ASSERT(!c1.speciesEqual(c3));

    }

    void testCreatureInfect()
    {
      Creature c1 (buildRover(), Creature::EAST);
      Creature c2 (buildFood(), Creature::SOUTH);
      Creature c3 (buildRover(), Creature::WEST);
      Creature c4 (buildFood(), Creature::NORTH);

      c1.infect(c2);
      CPPUNIT_ASSERT(c2.speciesEqual(c3));
      CPPUNIT_ASSERT(c2.pc == 0);
      c2.nextInstruction();
      c1.infect(c2);
      CPPUNIT_ASSERT(c2.pc == 1);
      CPPUNIT_ASSERT(c2.speciesEqual(c1));
      CPPUNIT_ASSERT(!c2.speciesEqual(c4));
    }

    void testCreatureLeftRight()
    {
      Creature c1 (buildRover(), Creature::NORTH);
      CPPUNIT_ASSERT(c1.direction == Creature::NORTH);

      c1.right(); c1.right();
      CPPUNIT_ASSERT(c1.direction == Creature::SOUTH);

      c1.right(); c1.right();
      CPPUNIT_ASSERT(c1.direction == Creature::NORTH);

      c1.left(); c1.left();
      CPPUNIT_ASSERT(c1.direction == Creature::SOUTH);

      c1.left(); c1.left();
      CPPUNIT_ASSERT(c1.direction == Creature::NORTH);

      c1.left(); c1.left(); c1.right(); c1.right();
      CPPUNIT_ASSERT(c1.direction == Creature::NORTH);
    }

    void testGameAddCreature()
    {
      Game g(4,5);
      Species s = buildRover();
      Creature c(s, Creature::EAST);
      g.addCreature(0,0,c);
      CPPUNIT_ASSERT(!g.board[0][0].isEmpty());
      CPPUNIT_ASSERT(g.board[4][3].isEmpty());
    }

    void testGameAddCreature2()
    {
      Game g(2,2);
      Species rover = buildRover();
      Species food = buildFood();
      Species hopper = buildHopper();

      Creature c1(rover, Creature::EAST);
      Creature c2(rover, Creature::NORTH);
      Creature c3(rover, Creature::SOUTH);

      g.addCreature(0,0,c1);
      g.addCreature(0,1,c2);
      g.addCreature(1,0,c3);

      CPPUNIT_ASSERT(!g.board[0][0].isEmpty());
      CPPUNIT_ASSERT(!g.board[1][0].isEmpty());
      CPPUNIT_ASSERT(!g.board[1][0].isEmpty());
      CPPUNIT_ASSERT(g.board[1][1].isEmpty());
    }

    void testGameAddCreature3()
    {
      Game g(2,2);
      Species rover = buildRover();
      Species food = buildFood();
      Species hopper = buildHopper();

      Creature c1(rover, Creature::EAST);
      Creature c2(rover, Creature::NORTH);
      Creature c3(rover, Creature::SOUTH);

      g.addCreature(0,0,c1);
      g.addCreature(0,1,c2);
      g.addCreature(1,0,c3);
      g.addCreature(1,1,c3);

      CPPUNIT_ASSERT(!g.board[0][0].isEmpty());
      CPPUNIT_ASSERT(!g.board[1][0].isEmpty());
      CPPUNIT_ASSERT(!g.board[1][0].isEmpty());
      CPPUNIT_ASSERT(!g.board[1][1].isEmpty());
    }

    void testExecuteControl()
    {
      Game g = buildTestGame();
      Creature north(buildRover(), Creature::NORTH);
      Creature east(buildRover(), Creature::EAST);
      Creature west(buildRover(), Creature::WEST);
      Creature north2(buildFood(), Creature::NORTH);
      Creature east2(buildRover(), Creature::EAST);

      g.addCreature(3,6,north);
      g.addCreature(3,7,east);
      g.addCreature(3,8,north2);
      g.addCreature(0,12,west);
      g.addCreature(0,13,east2);

      Instruction i1(Instruction::IF_ENEMY, 7, 15);
      Instruction i2(Instruction::IF_WALL, 7, 15);

      //rover facing rover, if enemy
      int returnVal = g.executeControl(i1, 3, 6, north);
      CPPUNIT_ASSERT(returnVal == 16);

      //rover facing nothing, if enemy
      returnVal = g.executeControl(i1, 3, 7, east);
      CPPUNIT_ASSERT(returnVal == 16);

      //food facing rover, if enemy
      returnVal = g.executeControl(i1, 3, 8, north2);
      CPPUNIT_ASSERT(returnVal == 7);

      //rover facing wall, if wall
      returnVal = g.executeControl(i2, 0, 12, west);
      CPPUNIT_ASSERT(returnVal == 7);

      //rover facing nothing, if wall
      returnVal = g.executeControl(i2, 0, 13, east2);
      CPPUNIT_ASSERT(returnVal == 16);
      
    }

    void testExecuteControl2()
    {
      Game g = buildTestGame();
      Creature north(buildRover(), Creature::NORTH);
      Creature east(buildRover(), Creature::EAST);
      Creature south(buildRover(), Creature::SOUTH);

      g.addCreature(3,6,north);
      g.addCreature(14,8,east);
      g.addCreature(2,2,south);

      Instruction i(Instruction::IF_EMPTY, 7, 15);

      //rover facing rover, if empty
      int returnVal = g.executeControl(i,3,6,north);
      CPPUNIT_ASSERT(returnVal == 16);

      //rover facing wall, if empty
      returnVal = g.executeControl(i,14,8,east);
      CPPUNIT_ASSERT(returnVal == 16);

      //rover facing nothing, if empty
      returnVal = g.executeControl(i,2,2,south);
      CPPUNIT_ASSERT(returnVal == 7);
    }

    void testExecuteControl3()
    {
      srand(0);
      Game g = buildTestGame();
      Creature north(buildRover(), Creature::NORTH);
      g.addCreature(3,6,north);

      Instruction i1(Instruction::IF_RANDOM, 7, 15);
      Instruction i2(Instruction::GO, 7, 15);

      //random
      int returnVal = g.executeControl(i1, 3, 6, north);
      CPPUNIT_ASSERT(returnVal == 7 || returnVal == 16);

      //go
      returnVal = g.executeControl(i2, 3, 6, north);
      CPPUNIT_ASSERT(returnVal == 7);
    }

    void testExecuteAction()
    {
      //left and right
      Game g = buildTestGame();
      Creature& c1 = g.board[5][3];
      Creature& c2 = g.board[5][6];
      Instruction right(Instruction::RIGHT);
      Instruction left(Instruction::LEFT);

      g.executeAction(right, 3, 5, c1);
      g.executeAction(left, 6, 5, c2);

      CPPUNIT_ASSERT(g.board[5][3].direction == Creature::SOUTH);
      CPPUNIT_ASSERT(g.board[5][6].direction == Creature::WEST);
    }

    void testExecuteAction2()
    {
      //hop
      Game g = buildTestGame();
      Creature compareHopper(buildHopper(), 1);
      Creature compareRover(buildRover(), 1);

      //test1, blocked by creature
      Creature test1(buildHopper(), Creature::NORTH);
      g.addCreature(3,6,test1);
      Instruction i1(Instruction::HOP);
      g.executeAction(i1, 3, 6, g.board[6][3]);
      CPPUNIT_ASSERT(g.board[6][3].speciesEqual(compareHopper));
      CPPUNIT_ASSERT(g.board[5][3].speciesEqual(compareRover));
      
      //test2, no blockage
      Creature test2(buildHopper(), Creature::EAST);
      g.addCreature(6, 6, test2);
      g.executeAction(i1, 6, 6, g.board[6][6]);
      CPPUNIT_ASSERT(g.board[6][6].isEmpty());
      CPPUNIT_ASSERT(g.board[6][7].speciesEqual(compareHopper));
      CPPUNIT_ASSERT(g.board[5][6].speciesEqual(compareRover));

      //test3, blocked by wall
      Creature test3(buildHopper(), Creature::SOUTH);
      g.addCreature(0,14, test3);
      g.executeAction(i1, 0, 14, g.board[14][0]);
      CPPUNIT_ASSERT(g.board[14][0].speciesEqual(compareHopper));
    }

    void testExecuteAction3()
    {
      //infect
      Game g = buildTestGame();
      Creature compareRover(buildRover(), 1);

      //normal infection
      Creature food1(buildFood(), Creature::EAST);
      g.addCreature(6, 4, food1);
      Instruction infect(Instruction::INFECT);
      g.executeAction(infect, 6, 5, g.board[5][6]);
      CPPUNIT_ASSERT(g.board[4][6].speciesEqual(compareRover));
      CPPUNIT_ASSERT(g.board[5][6].speciesEqual(compareRover));

      //empty infection
      g.executeAction(infect, 3, 5, g.board[5][3]);
      CPPUNIT_ASSERT(g.board[5][3].speciesEqual(compareRover));
      CPPUNIT_ASSERT(!g.board[5][4].speciesEqual(compareRover) && g.board[5][4].isEmpty());
      
      //wall infection
      Creature wallCreature(buildRover(), Creature::WEST);
      g.addCreature(0,0,wallCreature);
      g.executeAction(infect, 0, 0, wallCreature);
      CPPUNIT_ASSERT(g.board[0][0].speciesEqual(compareRover));


    }

    void executeActionBug()
    {
      Game g(8,8);
      Creature east(buildHopper(), Creature::EAST);
      g.addCreature(4,3,east);

      Creature original = g.board[3][4];
      CPPUNIT_ASSERT(original.pc == 0);
      CPPUNIT_ASSERT(original.direction == Creature::EAST);

      g.move();
      CPPUNIT_ASSERT(g.board[3][4].isEmpty());

      Creature c;
      for (int x = 0; x < g.width; x++)
      {
        for (int y = 0; y < g.height; y++)
        {
           if (!g.board[y][x].isEmpty())
             c = g.board[y][x];
        }
      }

      CPPUNIT_ASSERT(c.direction == Creature::EAST);


      CPPUNIT_ASSERT(!g.board[3][5].isEmpty());

    }

    //hopper gets stuck on food
    void testGameMove()
    {
      Game g (3, 3);
      Creature food(buildFood(), Creature::EAST);
      Creature hopper(buildHopper(), Creature::NORTH);
      g.addCreature(0,0,food);
      g.addCreature(0,2,hopper);

      g.move();
      CPPUNIT_ASSERT(g.board[0][0].speciesEqual(food));
      CPPUNIT_ASSERT(g.board[0][0].direction == Creature::NORTH);
      CPPUNIT_ASSERT(g.board[1][0].speciesEqual(hopper));

      g.move();
      CPPUNIT_ASSERT(g.board[0][0].speciesEqual(food));
      CPPUNIT_ASSERT(g.board[0][0].direction == Creature::WEST);
      CPPUNIT_ASSERT(g.board[1][0].speciesEqual(hopper));
    }

    //rover test to see if it can infect food
    void testGameMove2()
    {
      Game g (3, 3);
      Creature rover(buildRover(), Creature::NORTH);
      Creature food(buildFood(), Creature::NORTH);
      g.addCreature(0,0,food);
      g.addCreature(2,0,food);
      g.addCreature(0,2,rover);
      g.addCreature(2,2,rover);

      g.move();
      g.move();

      Creature& food1 = g.board[0][0];
      Creature& food2 = g.board[0][2];
      Creature& rover1 = g.board[1][0];
      Creature& rover2 = g.board[1][2];

      CPPUNIT_ASSERT(food1.direction == Creature::SOUTH);
      CPPUNIT_ASSERT(food1.speciesEqual(rover));
      CPPUNIT_ASSERT(rover1.direction == Creature::NORTH);
      CPPUNIT_ASSERT(rover1.speciesEqual(rover));


      CPPUNIT_ASSERT(food2.direction == Creature::SOUTH);
      CPPUNIT_ASSERT(food2.speciesEqual(rover));
      CPPUNIT_ASSERT(rover2.direction == Creature::NORTH);
      CPPUNIT_ASSERT(rover2.speciesEqual(rover));
      
    }

    //small board test
    void testGameMove3()
    {
      Game g(1,1);
      Creature hopper(buildHopper(), Creature::NORTH);
      g.addCreature(0,0,hopper);

      for (int i = 0; i < 99; i++)
        g.move();

      CPPUNIT_ASSERT(g.board[0][0].speciesEqual(hopper));
      CPPUNIT_ASSERT(g.board[0][0].direction == Creature::NORTH);
    }

    void testGameToString()
    {
      using namespace std;
      Game g(2,2);
      Creature r(buildRover(), 1);
      g.addCreature(0,0,r);

      stringstream s;
      s << "Turn = 0." << endl;
      s << "  01" << endl;
      s << "0 r." << endl;
      s << "1 .." << endl;
      CPPUNIT_ASSERT(s.str().compare(g.toString()) == 0);
    }

    void testGameToString2()
    {
      using namespace std;
      Game g(2,2);
      Creature h(buildHopper(), Creature::SOUTH);
      g.addCreature(0,0,h);
      g.move(); g.move();

      stringstream s;
      s << "Turn = 2." << endl;
      s << "  01" << endl;
      s << "0 .." << endl;
      s << "1 h." << endl;
      CPPUNIT_ASSERT(s.str().compare(g.toString()) == 0);
    }

    void testGameToString3()
    {
      using namespace std;
      Game g(1,1);
      Creature f(buildFood(), Creature::SOUTH);
      g.addCreature(0,0,f);
      g.move();

      stringstream s;
      s << "Turn = 1." << endl;
      s << "  0" << endl;
      s << "0 f" << endl;

      CPPUNIT_ASSERT(s.str().compare(g.toString()) == 0);
    }
    
    Game buildTestGame()
    {
      Game g(15,15);
      Species rover = buildRover();
      Species food = buildFood();
      Species hopper = buildHopper();

      Creature c1(rover, Creature::EAST);
      Creature c2(rover, Creature::NORTH);
      Creature c3(rover, Creature::SOUTH);

      g.addCreature(3,5,c1);
      g.addCreature(6,5,c2);
      g.addCreature(9,5,c3);

      return g;
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(testIsAction);
    CPPUNIT_TEST(testIsAction2);
    CPPUNIT_TEST(testIsAction3);
    CPPUNIT_TEST(testSpeciesGetInstruction);
    CPPUNIT_TEST(testSpeciesGetInstruction2);
    CPPUNIT_TEST(testSpeciesGetInstruction3);
    CPPUNIT_TEST(testCreatureNextInstruction);
    CPPUNIT_TEST(testCreatureNextInstruction2);
    CPPUNIT_TEST(testCreatureNextInstruction3);
    CPPUNIT_TEST(testCreatureEquals);
    CPPUNIT_TEST(testCreatureInfect);
    CPPUNIT_TEST(testCreatureLeftRight);
    CPPUNIT_TEST(testGameAddCreature);
    CPPUNIT_TEST(testGameAddCreature2);
    CPPUNIT_TEST(testGameAddCreature3);
    CPPUNIT_TEST(testExecuteControl);
    CPPUNIT_TEST(testExecuteControl2);
    CPPUNIT_TEST(testExecuteControl3);
    CPPUNIT_TEST(testExecuteAction);
    CPPUNIT_TEST(testExecuteAction2);
    CPPUNIT_TEST(testExecuteAction3);
    CPPUNIT_TEST(testGameMove);
    CPPUNIT_TEST(testGameMove2);
    CPPUNIT_TEST(testGameMove3);
    CPPUNIT_TEST(testGameToString);
    CPPUNIT_TEST(testGameToString2);
    CPPUNIT_TEST(testGameToString3);
    CPPUNIT_TEST(executeActionBug);
    CPPUNIT_TEST_SUITE_END();
};


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
