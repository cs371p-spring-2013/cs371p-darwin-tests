// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <cstring>   // ==
#include <map>      // map
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner
#include <string.h> 
#define private public
#include "Darwin.h"

// ----------
// TestDarwin
// ----------



// -----------------
// TestDarwinSpecies
// -----------------
struct TestDarwinSpecies : CppUnit::TestFixture {
    
    // ------------------------
    // test_species_constructor
    // ------------------------
    void test_species_constructor_1() {
        Species food;
        CPPUNIT_ASSERT(food._name == '.');
        CPPUNIT_ASSERT(food._program.size() == 0);
    }
     
    // ------------
    // test_species
    // ------------
    void test_species_1() {
        Species food ('f');
        CPPUNIT_ASSERT(food._name == 'f');
    }
    
    void test_species_2() {
        Species hopper('h');
        CPPUNIT_ASSERT(hopper._name == 'h');
    }
    
    void test_species_3() {
        Species trap('t');
        CPPUNIT_ASSERT(trap._name == 't');
    }
      
    // --------------------
    // test_add_instruction
    // --------------------
    void test_add_instruction_1() {
        Species food('f');
        CPPUNIT_ASSERT(food._program.size() == 0);
        food.add_instruction("hi");
        CPPUNIT_ASSERT(food._program.size() == 1);
   }
    
    void test_add_instruction_2() {
        Species food('f');
        CPPUNIT_ASSERT(food._program.size() == 0);
        food.add_instruction("hi");
        food.add_instruction("bye");
        CPPUNIT_ASSERT(food._program.size() == 2);
        
    }
    
    void test_add_instruction_3() {
        Species food('f');
	CPPUNIT_ASSERT(food._program.size() == 0);
	food.add_instruction("hi");
	food.add_instruction("bye");
	food.add_instruction("hey");
	CPPUNIT_ASSERT(food._program.size() == 3);
    }
    

   //-------------------
   // test_name_function
   //--------------------
    void test_name_function1() {
        Species hopper('h');
        CPPUNIT_ASSERT(hopper.name() == 'h');
    }

     void test_name_function2() {
        Species hopper1('f');
        CPPUNIT_ASSERT(hopper1.name() == 'f');
    }

      void test_name_function3() {
        Species hopper2('t');
        CPPUNIT_ASSERT(hopper2.name() == 't');
    }

    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestDarwinSpecies);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_1);
    CPPUNIT_TEST(test_species_2);
    CPPUNIT_TEST(test_species_3);
     CPPUNIT_TEST(test_add_instruction_1);
    CPPUNIT_TEST(test_add_instruction_2);
    CPPUNIT_TEST(test_add_instruction_3);
    CPPUNIT_TEST(test_name_function1);
    CPPUNIT_TEST(test_name_function2);
    CPPUNIT_TEST(test_name_function3);
   CPPUNIT_TEST_SUITE_END();
};



// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwinSpecies::suite());
    tr.run();
    
    cout << "Done." << endl;
    return 0;
}
