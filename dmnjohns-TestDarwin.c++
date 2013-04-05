#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#include "Darwin.h"

// -----------
// TestVoting
// -----------

struct TestDarwin : CppUnit::TestFixture {

    // ----
    // is_control
    // ----

    void test_is_control_1 () {
        Instruction i(HOP);
        CPPUNIT_ASSERT(!i.is_control());
        }
        
    void test_is_control_2 () {
        Instruction i(100);
        CPPUNIT_ASSERT(!i.is_control());
        }
        
    void test_is_control_3 () {
        Instruction i(GO, 0);
        CPPUNIT_ASSERT(i.is_control());
        }
        
    // ----
    // Instruction::print
    // ----

    void test_iprint_1 () {
        Instruction i(HOP);
        std::ostringstream oss;
        i.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "hop\n") == 0);
        }
        
    void test_iprint_2 () {
        Instruction i(100);
        std::ostringstream oss;
        i.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "\n") == 0);
        }
        
    void test_iprint_3 () {
        Instruction i(GO, 0);
        std::ostringstream oss;
        i.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "go 0\n") == 0);
        }
        
    // ----
    // Species::operator!= and ==
    // ----

    void test_op_eq_1 () {
        Species s1('s');
        Species s2('s');
        CPPUNIT_ASSERT(s1 == s2);
        }
        
    void test_op_eq_2 () {
        Species s1('s');
        Species s2('t');
        CPPUNIT_ASSERT(s1 != s2);
        }
        
    void test_op_eq_3 () {
        Species s1('s');
        s1.program.push_back(Instruction(HOP));
        Species s2('s');
        CPPUNIT_ASSERT(s1 != s2);
        }    
    
    // ----
    // Species::add_instruction
    // ----

    void test_add_inst_1 () {
        Species s('s');
        s.add_instruction(HOP);
        Instruction i(HOP);
        CPPUNIT_ASSERT(s.program.size() == 1);
        CPPUNIT_ASSERT(s.program[0].command == i.command);
        CPPUNIT_ASSERT(s.program[0].target == i.target);
        }
        
    void test_add_inst_2 () {
        Species s('s');
        s.add_instruction(GO, 0);
        s.add_instruction(HOP);
        Instruction i1(GO, 0);
        Instruction i2(HOP);
        CPPUNIT_ASSERT(s.program.size() == 2);
        CPPUNIT_ASSERT(s.program[0].command == i1.command);
        CPPUNIT_ASSERT(s.program[0].target == i1.target);
        CPPUNIT_ASSERT(s.program[1].command == i2.command);
        CPPUNIT_ASSERT(s.program[1].target == i2.target);
        }
        
    void test_add_inst_3 () {
        Species s('s');
        Instruction i(HOP);
        s.add_instruction(i);
        CPPUNIT_ASSERT(s.program.size() == 1);
        CPPUNIT_ASSERT(s.program[0].command == i.command);
        CPPUNIT_ASSERT(s.program[0].target == i.target);
        CPPUNIT_ASSERT(&s.program[0] != &i);
        }
        
    // ----
    // Species::line
    // ----

    void test_line_1 () {
        Species s('s');
        s.add_instruction(Instruction(HOP));
        CPPUNIT_ASSERT(s.line(0).command == s.program[0].command);
        CPPUNIT_ASSERT(s.line(0).target == s.program[0].target);
        }
        
    void test_line_2 () {
        Species s('s');
        try {
            Instruction i = s.line(100);
            CPPUNIT_ASSERT(false);
        } catch (...) {
            CPPUNIT_ASSERT(s.program.size() == 0);
        }
        }
        
    void test_line_3 () {
        Species s('s');
        s.add_instruction(Instruction(HOP));
        s.add_instruction(Instruction(GO, 0));
        CPPUNIT_ASSERT(s.line(1).command == Instruction(GO, 0).command);
        CPPUNIT_ASSERT(s.line(1).target == Instruction(GO, 0).target);
        }
        
    // ----
    // Species::print
    // ----

    void test_sprint_1 () {
        Species s('s');
        s.add_instruction(HOP);
        std::ostringstream oss;
        s.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "0. hop\n") == 0);
        }
        
    void test_sprint_2 () {
        Species s('s');
        s.add_instruction(HOP);
        s.add_instruction(GO, 0);
        std::ostringstream oss;
        s.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "0. hop\n1. go 0\n") == 0);
        }
        
    void test_sprint_3 () {
        Species s('s');
        std::ostringstream oss;
        s.print(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "") == 0);
        }
        
    // ----
    // Creature::print_symbol
    // ----

    void test_print_symbol_1 () {
        Creature c(Species('s'));
        std::ostringstream oss;
        c.print_symbol(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "s") == 0);
        }
        
    void test_print_symbol_2 () {
        Creature c(Species('t'));
        std::ostringstream oss;
        c.print_symbol(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "t") == 0);
        }
        
    void test_print_symbol_3 () {
        Creature c(Species('s'));
        c.species.symbol = 'v';
        std::ostringstream oss;
        c.print_symbol(oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "v") == 0);
        }
        
    // ----
    // Creature::morph
    // ----

    void test_morph_1 () {
        Creature c1(Species('s'));
        Creature c2(Species('t'));
        c1.morph(c2);
        CPPUNIT_ASSERT(c2.species.symbol == 't');
        CPPUNIT_ASSERT(c1.species.symbol == 't');
        CPPUNIT_ASSERT(c1.programCounter == 0);
        }
        
    void test_morph_2 () {
        Creature c1(Species('s'));
        Creature c2(Species('s'));
        c1.morph(c2);
        CPPUNIT_ASSERT(c1.programCounter == 0);
        }
        
    void test_morph_3 () {
        Creature c1(Species('s'));
        Creature c2(Species('v'));
        c1.morph(c2);
        CPPUNIT_ASSERT(c2.species.symbol == 'v');
        CPPUNIT_ASSERT(c1.species.symbol == 'v');
        CPPUNIT_ASSERT(c1.programCounter == 0);
        }
    
    // ----
    // Creature::ask
    // ----

    void test_ask_1 () {
        Creature c(Species('s'));
        c.species.add_instruction(HOP);
        Instruction i = c.ask();
        CPPUNIT_ASSERT(i.command == HOP);
        }
        
    void test_ask_2 () {
        Creature c(Species('s'));
        c.species.add_instruction(HOP);
        c.species.add_instruction(GO, 0);
        c.programCounter = 1;
        Instruction i = c.ask();
        CPPUNIT_ASSERT(i.command == GO);
        CPPUNIT_ASSERT(i.target == 0);
        }
        
    void test_ask_3 () {
        Creature c(Species('s'));
        try {
            Instruction i = c.ask();
            CPPUNIT_ASSERT(false);
        } catch (...) {
            // ...
        }
        }
    
    // ----
    // Creature::tell
    // ----

    void test_tell_1 () {
        Creature c(Species('s'));
        c.tell(Instruction(HOP), true);
        CPPUNIT_ASSERT(c.programCounter == 0);
        }
        
    void test_tell_2 () {
        Creature c(Species('s'));
        c.species.add_instruction(Instruction(HOP));
        c.species.add_instruction(Instruction(GO, 0));
        c.tell(Instruction(HOP), false);
        CPPUNIT_ASSERT(c.programCounter == 1);
        }
        
    void test_tell_3 () {
        Creature c(Species('s'));
        c.programCounter = 100;
        c.tell(Instruction(GO, 0), true);
        CPPUNIT_ASSERT(c.programCounter == 0);
        }
        
    // ----
    // Darwin::add_creature
    // ----

    void test_add_creature_1 () {
        Darwin d(1,1);
        Creature c(Species('s'));
        d.add_creature(c, NORTH, 0, 0);
        CPPUNIT_ASSERT(d.board[0][0].creature.species.symbol == 's');
        }
        
    void test_add_creature_2 () {
        Darwin d(1,1);
        Creature c(Species('s'));
        d.add_creature(c, NORTH, 10, 10);
        CPPUNIT_ASSERT(d.board[0][0].valid == false);
        }
        
    void test_add_creature_3 () {
        Darwin d(1,1);
        Creature c(Species('t'));
        d.add_creature(c, NORTH, 0, 0);
        CPPUNIT_ASSERT(d.board[0][0].creature.species.symbol == 't');
        }
        
    // ----
    // Darwin::print_board
    // ----

    void test_print_board_1 () {
        Darwin d(1,1);
        std::ostringstream oss;
        d.print_board(0, oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "Turn = 0.\n  0\n0 .\n") == 0);
        }
        
    void test_print_board_2 () {
        Darwin d(1,1);
        Creature c(Species('s'));
        d.add_creature(c, NORTH, 0, 0);
        std::ostringstream oss;
        d.print_board(0, oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "Turn = 0.\n  0\n0 s\n") == 0);
        }
        
    void test_print_board_3 () {
        Darwin d(0,0);
        std::ostringstream oss;
        d.print_board(0, oss);
        CPPUNIT_ASSERT(std::strcmp(oss.str().c_str(), "Turn = 0.\n  \n") == 0);
        }
        
    // ----
    // Darwin::run, tested by acceptance tests
        
    // ----
    // Darwin::turn, tested by acceptance tests
    
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_is_control_1);
    CPPUNIT_TEST(test_is_control_2);
    CPPUNIT_TEST(test_is_control_3);
    CPPUNIT_TEST(test_iprint_1);
    CPPUNIT_TEST(test_iprint_2);
    CPPUNIT_TEST(test_iprint_3);
    CPPUNIT_TEST(test_op_eq_1);
    CPPUNIT_TEST(test_op_eq_2);
    CPPUNIT_TEST(test_op_eq_3);
    CPPUNIT_TEST(test_add_inst_1);
    CPPUNIT_TEST(test_add_inst_2);
    CPPUNIT_TEST(test_add_inst_3);
    CPPUNIT_TEST(test_line_1);
    CPPUNIT_TEST(test_line_2);
    CPPUNIT_TEST(test_line_3);
    CPPUNIT_TEST(test_sprint_1);
    CPPUNIT_TEST(test_sprint_2);
    CPPUNIT_TEST(test_sprint_3);
    CPPUNIT_TEST(test_print_symbol_1);
    CPPUNIT_TEST(test_print_symbol_2);
    CPPUNIT_TEST(test_print_symbol_3);
    CPPUNIT_TEST(test_morph_1);
    CPPUNIT_TEST(test_morph_2);
    CPPUNIT_TEST(test_morph_3);
    CPPUNIT_TEST(test_ask_1);
    CPPUNIT_TEST(test_ask_2);
    CPPUNIT_TEST(test_ask_3);
    CPPUNIT_TEST(test_tell_1);
    CPPUNIT_TEST(test_tell_2);
    CPPUNIT_TEST(test_tell_3);
    CPPUNIT_TEST(test_add_creature_1);
    CPPUNIT_TEST(test_add_creature_2);
    CPPUNIT_TEST(test_add_creature_3);
    CPPUNIT_TEST(test_print_board_1);
    CPPUNIT_TEST(test_print_board_2);
    CPPUNIT_TEST(test_print_board_3);
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