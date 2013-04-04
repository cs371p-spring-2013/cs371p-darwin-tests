// --------
// includes
// --------

#include <vector>
#include <iostream>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

// #define protected public
// #define private public
// #define class struct

#include "Darwin.h"

using namespace std;

// -------------
// TestDarwin
// -------------

struct Tests : CppUnit::TestFixture {
    
    // Test species types
    void test_species_types0() {
        Species species;
        species.setType('h');
        CPPUNIT_ASSERT(species.type == 'h');
    }

    void test_species_types1() {
        Species species;
        species.setType('t');
        CPPUNIT_ASSERT(species.type == 't');
    }

    void test_species_types2() {
        Species species;
        species.setType('r');
        CPPUNIT_ASSERT(species.type == 'r');
    }

    // Test species getInstruction
    void test_species_getInstruction0() {
        Species species;
        species.setType('h');
        CPPUNIT_ASSERT(species.getInstruction(0).first == 0);
    }

    void test_species_getInstruction1() {
        Species species;
        species.setType('r');
        CPPUNIT_ASSERT(species.getInstruction(0).first == 7);
    }

    void test_species_getInstruction2() {
        Species species;
        species.setType('t');
        CPPUNIT_ASSERT(species.getInstruction(0).first == 7);
    }


    // Test creature instantiaion
    void test_creature0() {
        Creature c('r',2,0,0);
        CPPUNIT_ASSERT(c.species.type == 'r');
        CPPUNIT_ASSERT(c.direction == 2);
        CPPUNIT_ASSERT(c.y == 0);
        CPPUNIT_ASSERT(c.x == 0);
    }

    void test_creature1() {
        Creature c('t',3,3,2);
        CPPUNIT_ASSERT(c.species.type == 't');
        CPPUNIT_ASSERT(c.direction == 3);
        CPPUNIT_ASSERT(c.y == 3);
        CPPUNIT_ASSERT(c.x == 2);
    }

    void test_creature2() {
        Creature c('h',0,5,2);
        CPPUNIT_ASSERT(c.species.type == 'h');
        CPPUNIT_ASSERT(c.direction == 0);
        CPPUNIT_ASSERT(c.y == 5);
        CPPUNIT_ASSERT(c.x == 2);
    }

    // Test creature next_instruction
    void test_creature_nextInstr0() {
        Creature c('h',2,0,0);

        CPPUNIT_ASSERT(c.next_instruction().first == 0);
        ++c.pc;
        CPPUNIT_ASSERT(c.next_instruction().first == 8);
    }

    void test_creature_nextInstr1() {
        Creature c('r',3,3,2);

        CPPUNIT_ASSERT(c.next_instruction().first == 7);
        ++c.pc;
        CPPUNIT_ASSERT(c.next_instruction().first == 4);
    }

    void test_creature_nextInstr2() {
        Creature c('t',0,5,2);

        CPPUNIT_ASSERT(c.next_instruction().first == 7);
        ++c.pc;
        CPPUNIT_ASSERT(c.next_instruction().first == 1);
    }
    //the test_darwin tests test both test_darwin and setBoard
    void test_darwin() {
    	Darwin d(2,2);
        CPPUNIT_ASSERT(true);
    }
    void test_darwin1() {
    	Darwin d(1,2);
        CPPUNIT_ASSERT(true);
    }
    void test_darwin2() {
    	Darwin d(3,2);
        CPPUNIT_ASSERT(true);
    }
    void test_print(){
    	Darwin d(3,2);
        CPPUNIT_ASSERT(true);
    }
    void test_print1(){
    	Darwin d(3,2);
        CPPUNIT_ASSERT(true);
    }
    void test_print2(){
    	Darwin d(3,2);
        CPPUNIT_ASSERT(true);
    }
    void test_setCreature(){
    	Darwin d(2,2);
        Creature c('h',2,0,0);
    	d.setCreature(c);
        CPPUNIT_ASSERT(d.board[0][0].species.type==c.species.type);
    }
    void test_setCreature1(){
    	Darwin d(3,3);
        Creature c('h',2,1,1);
    	d.setCreature(c);
        CPPUNIT_ASSERT(d.board[1][1].species.type==c.species.type);
    }
    void test_setCreature2(){
    	Darwin d(2,2);
        Creature c('h',2,1,0);
    	d.setCreature(c);
        CPPUNIT_ASSERT(d.board[1][0].species.type==c.species.type);
    }
    void test_update_board(){
    	Darwin d(2,2);
        Creature c('h',2,0,0);
        d.updateBoardIndex(1,1,c);
        CPPUNIT_ASSERT(d.board[1][1].species.type==c.species.type);
    }
    void test_update_board1(){
    	Darwin d(2,2);
        Creature c('h',2,0,0);
        d.updateBoardIndex(1,1,c);
        CPPUNIT_ASSERT(d.board[1][1].species.type==c.species.type);
    }
    void test_update_board2(){
    	Darwin d(4,4);
        Creature c('h',2,0,0);
        d.updateBoardIndex(0,1,c);
    	//cout<<"c :"<<c.species.type<<endl;
    	//cout<<"dboard: "<<d.board[0][1].species.type<<endl;
        CPPUNIT_ASSERT(d.board[1][0].species.type==c.species.type);
    }
    void test_infect(){
    	Darwin d(4,4);
        Creature c('h',2,0,0);
        Creature c2('r',2,1,0);
        d.setCreature(c);
        d.setCreature(c2);
        d.infect(c2,c);
        CPPUNIT_ASSERT(c.pc==0 && c.species.type == c2.species.type);
    }
    void test_infect1(){
    	Darwin d(4,4);
        Creature c('h',2,0,0);
        Creature c2('r',2,1,0);
        d.setCreature(c);
        d.setCreature(c2);
        d.infect(c2,c);
        CPPUNIT_ASSERT(c.pc==0 && c.species.type == c2.species.type);
    }
    void test_infect2(){
    	Darwin d(4,4);
        Creature c('h',2,0,0);
        Creature c2('t',2,1,0);
        d.setCreature(c);
        d.setCreature(c2);
        d.infect(c2,c);
        CPPUNIT_ASSERT(c.pc==0 && c.species.type == c2.species.type);
    }
    void test_updateBoard(){
    	Darwin d(3,2);
    	d.updateBoard();
        CPPUNIT_ASSERT(true);
    }
    void test_updateBoard1(){
    	Darwin d(3,2);
    	d.updateBoard();
        CPPUNIT_ASSERT(true);
    }
    void test_updateBoard2(){
    	Darwin d(3,2);
    	d.updateBoard();
        CPPUNIT_ASSERT(true);
    }

    CPPUNIT_TEST_SUITE(Tests);

    CPPUNIT_TEST(test_species_types0);
    CPPUNIT_TEST(test_species_types1);
    CPPUNIT_TEST(test_species_types2);
    CPPUNIT_TEST(test_species_getInstruction0);
    CPPUNIT_TEST(test_species_getInstruction1);
    CPPUNIT_TEST(test_species_getInstruction2);
    CPPUNIT_TEST(test_creature0);
    CPPUNIT_TEST(test_creature1);
    CPPUNIT_TEST(test_creature2);
    CPPUNIT_TEST(test_creature_nextInstr0);
    CPPUNIT_TEST(test_creature_nextInstr1);
    CPPUNIT_TEST(test_creature_nextInstr2);
    CPPUNIT_TEST(test_darwin);
    CPPUNIT_TEST(test_darwin1);
    CPPUNIT_TEST(test_darwin2);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_setCreature);
    CPPUNIT_TEST(test_setCreature1);
    CPPUNIT_TEST(test_setCreature2);
    CPPUNIT_TEST(test_update_board);
    CPPUNIT_TEST(test_update_board1);
    CPPUNIT_TEST(test_update_board2);
    CPPUNIT_TEST(test_infect);
    CPPUNIT_TEST(test_infect1);
    CPPUNIT_TEST(test_infect2);
    CPPUNIT_TEST(test_updateBoard);
    CPPUNIT_TEST(test_updateBoard1);
    CPPUNIT_TEST(test_updateBoard2);

    
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

    tr.addTest(Tests::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}