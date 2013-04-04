#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public
#include "Darwin.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture
{
  // ---------
  // TestSuite
  // ---------

  void test1 ()
  {
    DarwinCreature testCreature;
    CPPUNIT_ASSERT (testCreature.mySpecies == -1);
    CPPUNIT_ASSERT (testCreature.myDirection == -1);
    CPPUNIT_ASSERT (testCreature.myProgramCounter == -1);
    CPPUNIT_ASSERT (testCreature.myTurn == -1);
  }

  void test2 ()
  {
    DarwinCreature testCreature (3, 14);
    CPPUNIT_ASSERT (testCreature.mySpecies == 3);
    CPPUNIT_ASSERT (testCreature.myDirection == 14);
    CPPUNIT_ASSERT (testCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCreature.myTurn == 0);
  }

  void test3 ()
  {
    DarwinCreature aCreature (3, 14, 15);
    CPPUNIT_ASSERT (aCreature.mySpecies == 3);
    CPPUNIT_ASSERT (aCreature.myDirection == 14);
    CPPUNIT_ASSERT (aCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (aCreature.myTurn == 15);
    DarwinCreature anotherCreature (aCreature);
    CPPUNIT_ASSERT (aCreature.mySpecies == anotherCreature.mySpecies);
    CPPUNIT_ASSERT (aCreature.myDirection == anotherCreature.myDirection);
    CPPUNIT_ASSERT (aCreature.myProgramCounter == anotherCreature.myProgramCounter);
    CPPUNIT_ASSERT (aCreature.myTurn == anotherCreature.myTurn);
  }

  void test4 ()
  {
    DarwinBoardCell testCell;
    CPPUNIT_ASSERT (!testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == -1);
  }

  void test5 ()
  {
    DarwinBoardCell testCell;
    testCell.place (3, 14);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == 3);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == 14);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == 0);
  }

  void test6 ()
  {
    DarwinBoardCell testCell;
    testCell.place (3, 14, 15);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == 3);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == 14);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == 15);
  }

  void test7 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (3, 14, 15);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == 3);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == 14);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == 15);
  }

  void test8 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (3, 14, 15);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
  }

  void test9 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (3, 14, 15);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    testCell.incTurn ();
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == 16);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
  }

  void test10 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (FOOD, NORTH);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.getResponse () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == WEST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
  }

  void test11 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (HOPPER, NORTH);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.getResponse () == HOP);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
  }

  void test12 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (ROVER, NORTH);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.getResponse () == ENEM9);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1); 
  }

  void test13 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (FOOD, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.getResponse () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
    CPPUNIT_ASSERT (testCell.getResponse () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == WEST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
  }

  void test14 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (FOOD, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.goNext () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
  }

  void test15 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (HOPPER, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.goNext () == HOP);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == EAST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 1);
  }

  void test16 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (ROVER, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.goNext () == EMPTY7);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == EAST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 2);
  }

  void test17 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (TRAP, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.goNext () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 2);
  }

  void test18 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (ROVER, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.go3 () == -1);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == NORTH);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 4);
  }

  void test19 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (TRAP, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.go3 () == INFECT);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == EAST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 4);
  }

  void test20 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (ROVER, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.go7 () == HOP);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == EAST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 8);
  }

  void test21 ()
  {
    DarwinBoardCell testCell;
    DarwinCreature aCreature (ROVER, EAST);
    testCell.place (aCreature);
    CPPUNIT_ASSERT (testCell.occupied);
    CPPUNIT_ASSERT (testCell.myCreature.mySpecies == testCell.getSpecies ());
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == testCell.getDirection ());
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testCell.myCreature.myTurn == testCell.getTurn ());
    CPPUNIT_ASSERT (testCell.go9 () == INFECT);
    CPPUNIT_ASSERT (testCell.myCreature.myDirection == EAST);
    CPPUNIT_ASSERT (testCell.myCreature.myProgramCounter == 10);
  }

  void test22 ()
  {
    DarwinBoard testBoard;
    CPPUNIT_ASSERT (testBoard.myCells.size () == 0);
    CPPUNIT_ASSERT (testBoard.numRows == 0);
    CPPUNIT_ASSERT (testBoard.numCols == 0);
    CPPUNIT_ASSERT (testBoard.turn == 0);
  }

  void test23 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
  }

  void test24 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    DarwinCreature aCreature;
    testBoard.place (0, 0, aCreature);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.mySpecies == aCreature.mySpecies);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myDirection == aCreature.myDirection);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myProgramCounter == aCreature.myProgramCounter);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myTurn == aCreature.myTurn);
  }

  void test25 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (0, 0, 0, NORTH));
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.mySpecies == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myDirection == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myProgramCounter == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].myCreature.myTurn == 0);
    CPPUNIT_ASSERT (!testBoard.place (0, 0, 0, NORTH));
  }

  void test26 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    std::ostringstream outStream;
    testBoard.simulate (0, 0, outStream);
    CPPUNIT_ASSERT (outStream.str () == "Turn = 0.\n  01\n0 ..\n1 ..\n\n");
    CPPUNIT_ASSERT (testBoard.turn == 0);
  }

  void test27 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    std::ostringstream outStream;
    testBoard.simulate (1, 1, outStream);
    CPPUNIT_ASSERT (outStream.str () == "Turn = 0.\n  01\n0 ..\n1 ..\n\nTurn = 1.\n  01\n0 ..\n1 ..\n\n");
    CPPUNIT_ASSERT (testBoard.turn == 1);
  }

  void test28 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (1, 0, HOPPER, NORTH));
    std::ostringstream outStream;
    testBoard.simulate (1, 1, outStream);
    CPPUNIT_ASSERT (outStream.str () == "Turn = 0.\n  01\n0 ..\n1 h.\n\nTurn = 1.\n  01\n0 h.\n1 ..\n\n");
    CPPUNIT_ASSERT (testBoard.turn == 1);
  }

  void test29 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (1, 0, HOPPER, NORTH));
    std::ostringstream outStream;
    testBoard.simulate (1, 2, outStream);
    CPPUNIT_ASSERT (outStream.str () == "Turn = 0.\n  01\n0 ..\n1 h.\n\n");
    CPPUNIT_ASSERT (testBoard.turn == 1);
  }

  void test30 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (1, 0, HOPPER, NORTH));
    std::ostringstream outStream;
    testBoard.simulate (4, 2, outStream);
    CPPUNIT_ASSERT (outStream.str () == "Turn = 0.\n  01\n0 ..\n1 h.\n\nTurn = 2.\n  01\n0 h.\n1 ..\n\nTurn = 4.\n  01\n0 h.\n1 ..\n\n");
    CPPUNIT_ASSERT (testBoard.turn == 4);
  }

  void test31 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    testBoard.move ();
    CPPUNIT_ASSERT (testBoard.turn == 0);
  }

  void test32 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (1, 0, HOPPER, NORTH));
    testBoard.move ();
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [0] [1].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [1].occupied);
  }

  void test33 ()
  {
    DarwinBoard testBoard (2, 2);
    CPPUNIT_ASSERT (testBoard.myCells.size () == 2);
    CPPUNIT_ASSERT (testBoard.myCells [0].size () == 2);
    CPPUNIT_ASSERT (testBoard.numRows == 2);
    CPPUNIT_ASSERT (testBoard.numCols == 2);
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied == false);
    CPPUNIT_ASSERT (testBoard.place (1, 0, HOPPER, NORTH));
    testBoard.move ();
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [0] [1].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [1].occupied);
    testBoard.move ();
    CPPUNIT_ASSERT (testBoard.turn == 0);
    CPPUNIT_ASSERT (testBoard.myCells [0] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [0] [1].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [0].occupied);
    CPPUNIT_ASSERT (!testBoard.myCells [1] [1].occupied);
  }

  void test34 ()
  {
    DarwinCreature aCreature;
    std::ostringstream outStream;
    outStream << aCreature;
    CPPUNIT_ASSERT (outStream.str () == "?");
  }

  void test35 ()
  {
    DarwinCreature aCreature (FOOD, NORTH);
    std::ostringstream outStream;
    outStream << aCreature;
    CPPUNIT_ASSERT (outStream.str () == "f");
  }

  void test36 ()
  {
    DarwinBoardCell aCell;
    std::ostringstream outStream;
    outStream << aCell;
    CPPUNIT_ASSERT (outStream.str () == ".");
  }

  void test37 ()
  {
    DarwinBoardCell aCell;
    aCell.place (FOOD, NORTH);
    std::ostringstream outStream;
    outStream << aCell;
    CPPUNIT_ASSERT (outStream.str () == "f");
  }

  void test38 ()
  {
    DarwinBoard aBoard;
    std::ostringstream outStream;
    outStream << aBoard;
    CPPUNIT_ASSERT (outStream.str () == "");
  }

  void test39 ()
  {
    DarwinBoard aBoard (2, 2);
    std::ostringstream outStream;
    outStream << aBoard;
    CPPUNIT_ASSERT (outStream.str () == "  01\n0 ..\n1 ..\n");
  }

  void test40 ()
  {
    DarwinBoard aBoard (2, 2);
    CPPUNIT_ASSERT (aBoard.place (0, 0, FOOD, NORTH));
    CPPUNIT_ASSERT (aBoard.place (0, 1, HOPPER, NORTH));
    CPPUNIT_ASSERT (aBoard.place (1, 0, TRAP, NORTH));
    CPPUNIT_ASSERT (aBoard.place (1, 1, ROVER, NORTH));
    std::ostringstream outStream;
    outStream << aBoard;
    CPPUNIT_ASSERT (outStream.str () == "  01\n0 fh\n1 tr\n");
  }

  CPPUNIT_TEST_SUITE (TestDarwin);
  CPPUNIT_TEST (test1);
  CPPUNIT_TEST (test2);
  CPPUNIT_TEST (test3);
  CPPUNIT_TEST (test4);
  CPPUNIT_TEST (test5);
  CPPUNIT_TEST (test6);
  CPPUNIT_TEST (test7);
  CPPUNIT_TEST (test8);
  CPPUNIT_TEST (test9);
  CPPUNIT_TEST (test10);
  CPPUNIT_TEST (test11);
  CPPUNIT_TEST (test12);
  CPPUNIT_TEST (test13);
  CPPUNIT_TEST (test14);
  CPPUNIT_TEST (test15);
  CPPUNIT_TEST (test16);
  CPPUNIT_TEST (test17);
  CPPUNIT_TEST (test18);
  CPPUNIT_TEST (test19);
  CPPUNIT_TEST (test20);
  CPPUNIT_TEST (test21);
  CPPUNIT_TEST (test22);
  CPPUNIT_TEST (test23);
  CPPUNIT_TEST (test24);
  CPPUNIT_TEST (test25);
  CPPUNIT_TEST (test26);
  CPPUNIT_TEST (test27);
  CPPUNIT_TEST (test28);
  CPPUNIT_TEST (test29);
  CPPUNIT_TEST (test30);
  CPPUNIT_TEST (test31);
  CPPUNIT_TEST (test32);
  CPPUNIT_TEST (test33);
  CPPUNIT_TEST (test34);
  CPPUNIT_TEST (test35);
  CPPUNIT_TEST (test36);
  CPPUNIT_TEST (test37);
  CPPUNIT_TEST (test38);
  CPPUNIT_TEST (test39);
  CPPUNIT_TEST (test40);
  CPPUNIT_TEST_SUITE_END ();
};

int main ()
{
  using namespace std;
  ios_base::sync_with_stdio (false);
  cout << "TestDarwin.c++" << endl;

  CppUnit::TextTestRunner testDarwin;
  testDarwin.addTest (TestDarwin::suite ());
  testDarwin.run ();

  cout << "Done." << endl;
  return 0;
}