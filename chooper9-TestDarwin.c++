// ---
// includes
// ---

#include <iostream>
#include <sstream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#include "Darwin.h"

using namespace std;

extern vector<vector<Creature> > board;

// ---
// TestDarwin
// ---

struct TestDarwin : CppUnit::TestFixture {
  // ---
  // Species tests
  // ---

  void test_species_constructor_1 () {
    Species::Species sp (NOT_A_CREATURE);
    CPPUNIT_ASSERT(sp.name == NOT_A_CREATURE);
    CPPUNIT_ASSERT(sp.representation == '.');
    CPPUNIT_ASSERT(sp.program.empty());
  }

  void test_species_constructor_2 () {
    Species::Species sp (FOOD);
    vector<int> v;
    v.push_back(100);
    v.push_back(800);
    CPPUNIT_ASSERT(sp.name == FOOD);
    CPPUNIT_ASSERT(sp.representation == 'f');
    CPPUNIT_ASSERT(sp.program == v);
  }

  void test_species_constructor_3 () {
    Species::Species sp (ROVER);
    vector<int> v;
    v.push_back(709);
    v.push_back(407);
    v.push_back(605);
    v.push_back(100);
    v.push_back(800);
    v.push_back(200);
    v.push_back(800);
    v.push_back(0);
    v.push_back(800);
    v.push_back(300);
    v.push_back(800);
    CPPUNIT_ASSERT(sp.name == ROVER);
    CPPUNIT_ASSERT(sp.representation == 'r');
    CPPUNIT_ASSERT(sp.program == v);
  }

  // ---
  // Creature tests
  // ---

  void test_creature_constructor_1 () {
    Creature cr (FOOD, NORTH, 0, 0);
    CPPUNIT_ASSERT(cr.sp.name == FOOD);
    CPPUNIT_ASSERT(cr.row == 0);
    CPPUNIT_ASSERT(cr.column == 0);
    CPPUNIT_ASSERT(cr.counter == 0);
    CPPUNIT_ASSERT(cr.direction == NORTH);
    CPPUNIT_ASSERT(cr.action_performed == false);
  }

  void test_creature_constructor_2 () {
    Creature cr (TRAP, EAST, 1, 3);
    CPPUNIT_ASSERT(cr.sp.name == TRAP);
    CPPUNIT_ASSERT(cr.row == 1);
    CPPUNIT_ASSERT(cr.column == 3);
    CPPUNIT_ASSERT(cr.counter == 0);
    CPPUNIT_ASSERT(cr.direction == EAST);
    CPPUNIT_ASSERT(cr.action_performed == false);
  }

  void test_creature_constructor_3 () {
    Creature cr (ROVER, WEST, 8, 4);
    CPPUNIT_ASSERT(cr.sp.name == ROVER);
    CPPUNIT_ASSERT(cr.row == 8);
    CPPUNIT_ASSERT(cr.column == 4);
    CPPUNIT_ASSERT(cr.counter == 0);
    CPPUNIT_ASSERT(cr.direction == WEST);
    CPPUNIT_ASSERT(cr.action_performed == false);
  }

  void test_creature_toChar_1 () {
    Creature cr (FOOD, SOUTH, 0, 3);
    CPPUNIT_ASSERT(cr.toChar() == 'f');
  }

  void test_creature_toChar_2 () {
    Creature cr (FOOD, WEST, 7, 1);
    CPPUNIT_ASSERT(cr.toChar() == 'f');
  }

  void test_creature_toChar_3 () {
    Creature cr (NOT_A_CREATURE, NORTH, 2, 2);
    CPPUNIT_ASSERT(cr.toChar() == '.');
  }

  // ---
  // Game tests
  // ---

  // hop

  void test_hop_1 () {
    Creature cr1 (HOPPER, NORTH, 3, 3);
    Creature cr2 (NOT_A_CREATURE, NORTH, 2, 3);
    CPPUNIT_ASSERT(cr1.sp.name == HOPPER);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 3);    
    hop(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == NOT_A_CREATURE);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 3);
    CPPUNIT_ASSERT(cr2.sp.name == HOPPER);
    CPPUNIT_ASSERT(cr2.row == 2);
    CPPUNIT_ASSERT(cr2.column == 3);
  }

  void test_hop_2 () {
    Creature cr1 (HOPPER, SOUTH, 3, 3);
    Creature cr2 (NOT_A_CREATURE, NORTH, 4, 3);
    CPPUNIT_ASSERT(cr1.sp.name == HOPPER);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 3);
    hop(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == NOT_A_CREATURE);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 3);
    CPPUNIT_ASSERT(cr2.sp.name == HOPPER);
    CPPUNIT_ASSERT(cr2.row == 4);
    CPPUNIT_ASSERT(cr2.column == 3);
  }

  void test_hop_3 () {
    Creature cr1 (ROVER, EAST, 3, 4);
    Creature cr2 (NOT_A_CREATURE, NORTH, 3, 5);
    CPPUNIT_ASSERT(cr1.sp.name == ROVER);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 4);
    hop(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == NOT_A_CREATURE);
    CPPUNIT_ASSERT(cr1.row == 3);
    CPPUNIT_ASSERT(cr1.column == 4);
    CPPUNIT_ASSERT(cr2.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.row == 3);
    CPPUNIT_ASSERT(cr2.column == 5);
  }

  // left

  void test_left_1 () {
    Creature cr (FOOD, NORTH, 0, 0);
    CPPUNIT_ASSERT(cr.direction == NORTH);
    left(cr);
    CPPUNIT_ASSERT(cr.direction == WEST);
  }

  void test_left_2 () {
    Creature cr (FOOD, WEST, 1, 2);
    CPPUNIT_ASSERT(cr.direction == WEST);
    left(cr);
    CPPUNIT_ASSERT(cr.direction == SOUTH);
  }

  void test_left_3 () {
    Creature cr (ROVER, EAST, 1, 1);
    CPPUNIT_ASSERT(cr.direction == EAST);
    left(cr);
    CPPUNIT_ASSERT(cr.direction == NORTH);
    CPPUNIT_ASSERT(cr.row == 1);
    CPPUNIT_ASSERT(cr.column == 1);
  }

  // right

  void test_right_1 () {
    Creature cr (FOOD, NORTH, 0, 0);
    CPPUNIT_ASSERT(cr.direction == NORTH);
    right(cr);
    CPPUNIT_ASSERT(cr.direction == EAST);
  }

  void test_right_2 () {
    Creature cr (FOOD, SOUTH, 0, 0);
    CPPUNIT_ASSERT(cr.direction == SOUTH);
    right(cr);
    CPPUNIT_ASSERT(cr.direction == WEST);
  }

  void test_right_3 () {
    Creature cr (ROVER, EAST, 1, 1);
    CPPUNIT_ASSERT(cr.direction == EAST);
    right(cr);
    CPPUNIT_ASSERT(cr.direction == SOUTH);
    CPPUNIT_ASSERT(cr.row == 1);
    CPPUNIT_ASSERT(cr.column == 1);
  }

  // infect

  void test_infect_1 () {
    Creature cr1 (ROVER, NORTH, 1, 0);
    Creature cr2 (FOOD, NORTH, 0, 0);
    CPPUNIT_ASSERT(cr1.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.sp.name == FOOD);
    infect(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.sp.name == ROVER);
  }

  void test_infect_2 () {
    Creature cr1 (ROVER, NORTH, 1, 0);
    Creature cr2 (TRAP, NORTH, 0, 0);
    cr2.counter = 2;
    CPPUNIT_ASSERT(cr1.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.sp.name == TRAP);
    CPPUNIT_ASSERT(cr2.counter == 2);
    infect(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.sp.name == ROVER);
    CPPUNIT_ASSERT(cr2.counter == 0);
  }

  void test_infect_3 () {
    Creature cr1 (TRAP, EAST, 1, 1);
    Creature cr2 (ROVER, NORTH, 1, 2);
    CPPUNIT_ASSERT(cr1.sp.name == TRAP);
    CPPUNIT_ASSERT(cr2.sp.name == ROVER);
    infect(cr1, cr2);
    CPPUNIT_ASSERT(cr1.sp.name == TRAP);
    CPPUNIT_ASSERT(cr2.sp.name == TRAP);
  }

  // gameSetup

  void test_gameSetup_1 () {
    gameSetup(3, 3);
    CPPUNIT_ASSERT(board.size() == 3);
    CPPUNIT_ASSERT(board[0].size() == 3);
  }

  void test_gameSetup_2 () {
    gameSetup(72, 72);
    CPPUNIT_ASSERT(board.size() == 72);
    CPPUNIT_ASSERT(board[0].size() == 72);
  }

  void test_gameSetup_3 () {
    gameSetup(7, 9);
    CPPUNIT_ASSERT(board.size() == 7);
    CPPUNIT_ASSERT(board[0].size() == 9);
  }

  // addCreature

  void test_addCreature_1 () {
    gameSetup(3, 3);
    Creature* crp = &(board[1][1]);
    CPPUNIT_ASSERT((*crp).toChar() == '.');
    addCreature(FOOD, NORTH, 1, 1);
    CPPUNIT_ASSERT((*crp).toChar() == 'f');
  }

  void test_addCreature_2 () {
    gameSetup(3, 3);
    Creature* crp = &(board[1][1]);
    CPPUNIT_ASSERT((*crp).toChar() == '.');
    addCreature(FOOD, NORTH, 1, 1);
    CPPUNIT_ASSERT((*crp).toChar() == 'f');
    addCreature(TRAP, EAST, 1, 1);
    CPPUNIT_ASSERT((*crp).toChar() == 'f');
  }

  void test_addCreature_3 () {
    gameSetup(3, 3);
    Creature* crp = &(board[1][1]);
    Creature* crp2 = &(board[0][1]);
    CPPUNIT_ASSERT((*crp).toChar() == '.');
    CPPUNIT_ASSERT((*crp2).toChar() == '.');
    addCreature(FOOD, NORTH, 1, 1);
    addCreature(ROVER, SOUTH, 0, 1);
    CPPUNIT_ASSERT((*crp).toChar() == 'f');
    CPPUNIT_ASSERT((*crp2).toChar() == 'r');
  }

  // processInstruction

  void test_processInstruction_1 () {
    int instr;
    gameSetup(3, 3);
    addCreature(FOOD, NORTH, 1, 1);
    Creature* crp = &(board[1][1]);
    CPPUNIT_ASSERT((*crp).direction == NORTH);
    instr = (*crp).sp.program[(*crp).counter];
    processInstruction(*crp, instr);
    CPPUNIT_ASSERT((*crp).direction == WEST);
  }

  void test_processInstruction_2 () {
    int instr;
    gameSetup(3, 3);
    addCreature(ROVER, NORTH, 1, 1);
    Creature* crp = &(board[1][1]);
    CPPUNIT_ASSERT((board[1][1]).toChar() == 'r');
    instr = (*crp).sp.program[(*crp).counter];
    processInstruction(*crp, instr);
    CPPUNIT_ASSERT((board[1][1]).toChar() == 'r');
  }

    void test_processInstruction_3 () {
    int instr;
    gameSetup(3, 3);
    addCreature(ROVER, NORTH, 1, 1);
    Creature* crp = &(board[1][1]);
    CPPUNIT_ASSERT((board[1][1]).toChar() == 'r');
    instr = (*crp).sp.program[(*crp).counter];
    processInstruction(*crp, instr);
    instr = (*crp).sp.program[(*crp).counter];
    processInstruction(*crp, instr);
    instr = (*crp).sp.program[(*crp).counter];
    processInstruction(*crp, instr);
    CPPUNIT_ASSERT((board[1][1]).toChar() == '.');
    CPPUNIT_ASSERT((board[0][1]).toChar() == 'r');
  }

  // play_turn

  void test_play_turn_1 () {
    gameSetup(3, 3);
    addCreature(FOOD, NORTH, 1, 1);
    CPPUNIT_ASSERT(board[1][1].direction == NORTH);
    play_turn();
    CPPUNIT_ASSERT(board[1][1].direction == WEST);
  }

  void test_play_turn_2 () {
    gameSetup(3, 3);
    addCreature(ROVER, NORTH, 1, 1);
    CPPUNIT_ASSERT(board[1][1].toChar() == 'r');
    play_turn();
    CPPUNIT_ASSERT(board[1][1].toChar() == '.');
    CPPUNIT_ASSERT(board[0][1].toChar() == 'r');
  }

  void test_play_turn_3 () {
    gameSetup(3, 3);
    addCreature(HOPPER, NORTH, 0, 0);
    CPPUNIT_ASSERT(board[0][0].toChar() == 'h');
    play_turn();
    CPPUNIT_ASSERT(board[0][0].toChar() == 'h');
  }

  // next_turn

  void test_next_turn_1 () {
    gameSetup(3, 3);
    addCreature(FOOD, NORTH, 1, 1);
    play_turn();
    CPPUNIT_ASSERT(board[1][1].action_performed == true);
    next_turn();
    CPPUNIT_ASSERT(board[1][1].action_performed == false);
  }

  // ---
  // suite
  // ---

  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST(test_species_constructor_1);
  CPPUNIT_TEST(test_species_constructor_2);
  CPPUNIT_TEST(test_species_constructor_3);
  CPPUNIT_TEST(test_creature_constructor_1);
  CPPUNIT_TEST(test_creature_constructor_2);
  CPPUNIT_TEST(test_creature_constructor_3);
  CPPUNIT_TEST(test_creature_toChar_1);
  CPPUNIT_TEST(test_creature_toChar_2);
  CPPUNIT_TEST(test_creature_toChar_3);
  CPPUNIT_TEST(test_hop_1);
  CPPUNIT_TEST(test_hop_2);
  CPPUNIT_TEST(test_hop_3);
  CPPUNIT_TEST(test_left_1);
  CPPUNIT_TEST(test_left_2);
  CPPUNIT_TEST(test_left_3);
  CPPUNIT_TEST(test_right_1);
  CPPUNIT_TEST(test_right_2);
  CPPUNIT_TEST(test_right_3);
  CPPUNIT_TEST(test_infect_1);
  CPPUNIT_TEST(test_infect_2);
  CPPUNIT_TEST(test_infect_3);
  CPPUNIT_TEST(test_gameSetup_1);
  CPPUNIT_TEST(test_gameSetup_2);
  CPPUNIT_TEST(test_gameSetup_3);
  CPPUNIT_TEST(test_addCreature_1);
  CPPUNIT_TEST(test_addCreature_2);
  CPPUNIT_TEST(test_addCreature_3);
  CPPUNIT_TEST(test_processInstruction_1);
  CPPUNIT_TEST(test_processInstruction_2);
  CPPUNIT_TEST(test_processInstruction_3);
  CPPUNIT_TEST(test_play_turn_1);
  CPPUNIT_TEST(test_play_turn_2);
  CPPUNIT_TEST(test_play_turn_3);
  CPPUNIT_TEST(test_next_turn_1);
  CPPUNIT_TEST_SUITE_END();
};

// ---
// main
// ---

int main () {
  ios_base::sync_with_stdio(false);
  cout << "TestDarwin.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestDarwin::suite());
  tr.run();

  cout << "Done." << endl;
  return 0;
}
