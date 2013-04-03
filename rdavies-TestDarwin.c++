// ------------------------------
// Reece Davies and Eric Carrillo
// ------------------------------


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

// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {
 
  // --------------
  // parseDirection
  // --------------

  void test_parseDirection_1() {
    Direction d = NORTH;
    int row = 3;
    int col = 7;
    parseDirection(row, col, d);
    CPPUNIT_ASSERT(row == 2);
    CPPUNIT_ASSERT(col == 7);
  }

  void test_parseDirection_2() {
    Direction d = EAST;
    int row = 1;
    int col = 10;
    parseDirection(row, col, d);
    CPPUNIT_ASSERT(row == 1);
    CPPUNIT_ASSERT(col == 11);
  }

  void test_parseDirection_3() {
    Direction d = SOUTH;
    int row = 101;
    int col = 14;
    parseDirection(row, col, d);
    CPPUNIT_ASSERT(row == 102);
    CPPUNIT_ASSERT(col == 14);
  }

  // ---------
  // updateDir
  // ---------

  void test_updateDir_1() {
    Actions a = LEFT;
    Direction d = NORTH;
    CPPUNIT_ASSERT(updateDir(a, d) == WEST);
  }

  void test_updateDir_2() {
    Actions a = RIGHT;
    Direction d = WEST;
    CPPUNIT_ASSERT(updateDir(a, d) == NORTH);
  }

  void test_updateDir_3() {
    Actions a = LEFT;
    Direction d = EAST;
    CPPUNIT_ASSERT(updateDir(a, d) == NORTH);
  }

  // ---------
  // GameBoard
  // ---------

  void test_GameBoard_1() {
    GameBoard g(5, 5);
    CPPUNIT_ASSERT(g._board.size() == 5);
    CPPUNIT_ASSERT(g._board[0].size() == 5);
  }

  void test_GameBoard_2() {
    GameBoard g(10, 15);
    CPPUNIT_ASSERT(g._board.size() == 10);
    CPPUNIT_ASSERT(g._board[0].size() == 15);
  }

  void test_GameBoard_3() {
    GameBoard g(80, 97);
    CPPUNIT_ASSERT(g._board.size() == 80);
    CPPUNIT_ASSERT(g._board[0].size() == 97);
  }

  // --------
  // Creature
  // --------

  void test_Creature_1() {
    Creature c(NORTH, "food");
    CPPUNIT_ASSERT(c.species == "food");
    CPPUNIT_ASSERT(c.dir == NORTH);
    CPPUNIT_ASSERT(c._pc == 0);
    CPPUNIT_ASSERT(c.turnNum == 0);
    CPPUNIT_ASSERT(c._pg == Creature::food);
  }

  void test_Creature_2() {
    Creature c(SOUTH, "trap");
    CPPUNIT_ASSERT(c.species == "trap");
    CPPUNIT_ASSERT(c.dir == SOUTH);
    CPPUNIT_ASSERT(c._pc == 0);
    CPPUNIT_ASSERT(c.turnNum == 0);
    CPPUNIT_ASSERT(c._pg == Creature::trap);
  }

  void test_Creature_3() {
    Creature c(EAST, "rover");
    CPPUNIT_ASSERT(c.species == "rover");
    CPPUNIT_ASSERT(c.dir == EAST);
    CPPUNIT_ASSERT(c._pc == 0);
    CPPUNIT_ASSERT(c.turnNum == 0);
    CPPUNIT_ASSERT(c._pg == Creature::rover);
  }

  // --------------
  // createCreature
  // --------------

  void test_createCreature_1() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, NORTH, "food");
    CPPUNIT_ASSERT(g._board[0][0].species == "food");
    CPPUNIT_ASSERT(g._board[0][0].dir == NORTH);
    CPPUNIT_ASSERT(g._board[0][0].turnNum == 0);
  }

  void test_createCreature_2() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, EAST, "trap");
    g.createCreature(1, 2, SOUTH, "rover");
    CPPUNIT_ASSERT(g._board[0][0].species == "trap");
    CPPUNIT_ASSERT(g._board[0][0].dir == EAST);
    CPPUNIT_ASSERT(g._board[0][0].turnNum == 0);

    CPPUNIT_ASSERT(g._board[1][2].species == "rover");
    CPPUNIT_ASSERT(g._board[1][2].dir == SOUTH);
    CPPUNIT_ASSERT(g._board[1][2].turnNum == 0);
  }

  void test_createCreature_3() {
    GameBoard g(3, 5);
    g.createCreature(1, 1, NORTH, "food");
    g.createCreature(2, 2, WEST, "best");
    CPPUNIT_ASSERT(g._board[1][1].species == "food");
    CPPUNIT_ASSERT(g._board[1][1].dir == NORTH);
    CPPUNIT_ASSERT(g._board[1][1].turnNum == 0);

    CPPUNIT_ASSERT(g._board[2][2].species == "best");
    CPPUNIT_ASSERT(g._board[2][2].dir == WEST);
    CPPUNIT_ASSERT(g._board[2][2].turnNum == 0);
  }

  // -------
  // isDummy
  // -------

  void test_isDummy_1() {
    Creature c(NORTH, "food");
    CPPUNIT_ASSERT(!c.isDummy());
  }

  void test_isDummy_2() {
    Creature c(SOUTH, "dummy");
    CPPUNIT_ASSERT(c.isDummy());
  }

  void test_isDummy_3() {
    Creature c(NORTH, "rover");
    CPPUNIT_ASSERT(!c.isDummy());
  }


  // -------------------
  // Creature& operator=
  // -------------------
    // note: this is not called for infect

  void test_creatureAssign_1() {
    Creature a(NORTH, "food");
    Creature b(EAST, "trap");
    a = b;
    CPPUNIT_ASSERT(a.species == "trap");
    CPPUNIT_ASSERT(a.dir == EAST);
    CPPUNIT_ASSERT(a._pg == Creature::trap);
  }

  void test_creatureAssign_2() {
    Creature a(SOUTH, "best");
    Creature b(EAST, "hopper");
    a = b;
    CPPUNIT_ASSERT(a.species == "hopper");
    CPPUNIT_ASSERT(a.dir == EAST);
    CPPUNIT_ASSERT(a._pg == Creature::hopper);
  }

  void test_creatureAssign_3() {
    Creature a(NORTH, "trap");
    Creature b(WEST, "rover");
    a = b;
    CPPUNIT_ASSERT(a.species == "rover");
    CPPUNIT_ASSERT(a.dir == WEST);
    CPPUNIT_ASSERT(a._pg == Creature::rover);
  }

  // --------
  // takeTurn
  // --------

  void test_takeTurn_1() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, NORTH, "food");
    Actions a = g._board[0][0].takeTurn(0, 0, &(g._board));
    CPPUNIT_ASSERT(a == LEFT);
  }

  void test_takeTurn_2() {
    GameBoard g(10, 10);
    g.createCreature(0, 0, EAST, "food");
    g.createCreature(0, 1, WEST, "trap");
    Actions a = g._board[0][1].takeTurn(0, 1, &(g._board));
    CPPUNIT_ASSERT(a == INFECT);
  }

  void test_takeTurn_3() {
    GameBoard g(4, 4);
    srand(0);
    g.createCreature(3, 3, SOUTH, "rover");
    Actions a = g._board[3][3].takeTurn(3, 3, &(g._board));
    CPPUNIT_ASSERT(a == RIGHT);
  }

  // ------
  // Action
  // ------

  void test_Action_1() {
    Action act(0, 1, LEFT);
    CPPUNIT_ASSERT(act._row == 0);
    CPPUNIT_ASSERT(act._col == 1);
    CPPUNIT_ASSERT(act._a == LEFT);
  }

  void test_Action_2() {
    Action act(79, 67, INFECT);
    CPPUNIT_ASSERT(act._row == 79);
    CPPUNIT_ASSERT(act._col == 67);
    CPPUNIT_ASSERT(act._a == INFECT);
  }

  void test_Action_3() {
    Action act(15, 15, HOP);
    CPPUNIT_ASSERT(act._row == 15);
    CPPUNIT_ASSERT(act._col == 15);
    CPPUNIT_ASSERT(act._a == HOP);
  }

  // --------
  // doAction
  // --------

  void test_doAction_1() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, NORTH, "food");
    Actions a = g._board[0][0].takeTurn(0, 0, &(g._board));
    Action act(0, 0, a);
    act.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[0][0].dir == WEST);
    CPPUNIT_ASSERT(g._board[0][0]._pc == 1);
  }

  void test_doAction_2() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, SOUTH, "trap");
    g.createCreature(1, 0, EAST, "best");
    Actions a = g._board[0][0].takeTurn(0, 0, &(g._board));
    Action act(0, 0, a);
    act.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[0][0].dir == SOUTH);
    CPPUNIT_ASSERT(g._board[0][0]._pc == 4);
  }

  void test_doAction_3() {
    GameBoard g(5, 5);
    g.createCreature(0, 0, SOUTH, "hopper");
    Actions a = g._board[0][0].takeTurn(0, 0, &(g._board));
    Action act(0, 0, a);
    act.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[1][0].dir == SOUTH);
    CPPUNIT_ASSERT(g._board[1][0].species == "hopper");
  }

  // ------
  // infect
  // ------

  void test_infect_1() {
    GameBoard g(4, 4);
    g.createCreature(0, 0, EAST, "food");
    g.createCreature(0, 1, WEST, "trap");
    Action act(0, 1, INFECT);
    act.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[0][0].species == "trap");
    CPPUNIT_ASSERT(g._board[0][0]._pc == 0);
    CPPUNIT_ASSERT(g._board[0][0]._pg == Creature::trap);
    CPPUNIT_ASSERT(g._board[0][0].dir == EAST);
  }

  void test_infect_2() {
    GameBoard g(3, 3);
    g.createCreature(1, 1, SOUTH, "best");
    g.createCreature(2, 1, NORTH, "trap");
    Action act(2, 1, INFECT);
    act.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[1][1].species == "trap");
    CPPUNIT_ASSERT(g._board[1][1]._pc == 0);
    CPPUNIT_ASSERT(g._board[1][1]._pg == Creature::trap);
    CPPUNIT_ASSERT(g._board[1][1].dir == SOUTH);
  }

  void test_infect_3() {
    GameBoard g(3, 3);
    g.createCreature(2, 1, NORTH, "food");
    g.createCreature(1, 1, SOUTH, "best");
    Action act1(2, 1, LEFT);
    act1.doAction(&g._board);
    Action act2(1, 1, INFECT);
    act2.doAction(&g._board);
    CPPUNIT_ASSERT(g._board[2][1].species == "best");
    CPPUNIT_ASSERT(g._board[2][1]._pc == 0);
    CPPUNIT_ASSERT(g._board[2][1]._pg == Creature::best);
    CPPUNIT_ASSERT(g._board[2][1].dir == WEST);
  }

  // -------
  // doRound
  // -------

  void test_doRound_1() {
    GameBoard g(2, 2);
    g.createCreature(0, 0, NORTH, "food");
    g.doRound(0);
    CPPUNIT_ASSERT(g._board[0][0].dir == WEST);
    CPPUNIT_ASSERT(g._board[0][0].turnNum == 1);
  }

  void test_doRound_2() {
    GameBoard g(2, 2);
    g.createCreature(0, 0, NORTH, "food");
    g.createCreature(0, 1, WEST, "trap");
    g.doRound(0);
    CPPUNIT_ASSERT(g._board[0][0].dir == WEST);
    CPPUNIT_ASSERT(g._board[0][0].turnNum == 1);
    CPPUNIT_ASSERT(g._board[0][0].species == "trap");

    CPPUNIT_ASSERT(g._board[0][1].dir == WEST);
    CPPUNIT_ASSERT(g._board[0][1].turnNum == 1);
  }

  void test_doRound_3() {
    GameBoard g(3, 3);
    g.createCreature(0, 0, NORTH, "hopper");
    g.createCreature(1, 1, SOUTH, "hopper");
    g.doRound(0);
    CPPUNIT_ASSERT(g._board[0][0].dir == NORTH);
    CPPUNIT_ASSERT(g._board[0][0].turnNum == 1);

    CPPUNIT_ASSERT(g._board[2][1].dir == SOUTH);
    CPPUNIT_ASSERT(g._board[2][1].turnNum == 1);
  }

  // -------------------
  // ostream& operator<<
  // -------------------

  void test_printCreature_1() {
    Creature c(NORTH, "food");
    ostringstream w;
    w << c;
    CPPUNIT_ASSERT(w.str() == "f");
  }

  void test_printCreature_2() {
    Creature c(EAST, "best");
    ostringstream w;
    w << c;
    CPPUNIT_ASSERT(w.str() == "b");
  }

  void test_printCreature_3() {
    Creature c(SOUTH, "rover");
    ostringstream w;
    w << c;
    CPPUNIT_ASSERT(w.str() == "r");
  }

  // ----------
  // printBoard
  // ----------

  void test_printBoard_1() {
    GameBoard g(2, 2);
    ostringstream w;
    g.printBoard(w);
    string result = "  01\n0 ..\n1 ..\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_printBoard_2() {
    GameBoard g(2, 2);
    g.createCreature(0, 0, NORTH, "food");
    ostringstream w;
    g.printBoard(w);
    string result = "  01\n0 f.\n1 ..\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_printBoard_3() {
    GameBoard g(3, 2);
    g.createCreature(0, 1, NORTH, "rover");
    g.createCreature(1, 1, NORTH, "best");
    ostringstream w;
    g.printBoard(w);
    string result = "  01\n0 .r\n1 .b\n2 ..\n";
    CPPUNIT_ASSERT(w.str() == result);
  }



  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST(test_parseDirection_1);
  CPPUNIT_TEST(test_parseDirection_2);
  CPPUNIT_TEST(test_parseDirection_3);
  CPPUNIT_TEST(test_updateDir_1);
  CPPUNIT_TEST(test_updateDir_2);
  CPPUNIT_TEST(test_updateDir_3);
  CPPUNIT_TEST(test_GameBoard_1);
  CPPUNIT_TEST(test_GameBoard_2);
  CPPUNIT_TEST(test_GameBoard_3);
  CPPUNIT_TEST(test_Creature_1);
  CPPUNIT_TEST(test_Creature_2);
  CPPUNIT_TEST(test_Creature_3);
  CPPUNIT_TEST(test_createCreature_1);
  CPPUNIT_TEST(test_createCreature_2);
  CPPUNIT_TEST(test_createCreature_3);
  CPPUNIT_TEST(test_isDummy_1);
  CPPUNIT_TEST(test_isDummy_2);
  CPPUNIT_TEST(test_isDummy_3);
  CPPUNIT_TEST(test_creatureAssign_1);
  CPPUNIT_TEST(test_creatureAssign_2);
  CPPUNIT_TEST(test_creatureAssign_3);
  CPPUNIT_TEST(test_takeTurn_1);
  CPPUNIT_TEST(test_takeTurn_2);
  CPPUNIT_TEST(test_takeTurn_3);
  CPPUNIT_TEST(test_Action_1);
  CPPUNIT_TEST(test_Action_2);
  CPPUNIT_TEST(test_Action_3);
  CPPUNIT_TEST(test_doAction_1);
  CPPUNIT_TEST(test_doAction_2);
  CPPUNIT_TEST(test_doAction_3);
  CPPUNIT_TEST(test_infect_1);
  CPPUNIT_TEST(test_infect_2);
  CPPUNIT_TEST(test_infect_3);
  CPPUNIT_TEST(test_doRound_1);
  CPPUNIT_TEST(test_doRound_1);
  CPPUNIT_TEST(test_doRound_3);
  CPPUNIT_TEST(test_printCreature_1);
  CPPUNIT_TEST(test_printCreature_2);
  CPPUNIT_TEST(test_printCreature_3);
  CPPUNIT_TEST(test_printBoard_1);
  CPPUNIT_TEST(test_printBoard_2);
  CPPUNIT_TEST(test_printBoard_3);
  CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
  using namespace std;
  ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
  cout << "TestDarawin.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestDarwin::suite());
  tr.run();

  cout << "Done." << endl;
  return 0;
}
