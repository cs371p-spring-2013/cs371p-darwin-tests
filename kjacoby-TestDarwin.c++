// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <ostream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public
#include "Darwin.h"


// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {
	
	// ---------
    // isAction
    // ---------
    
	void test_isAction1() {
		Instruction i("go", 1);
		CPPUNIT_ASSERT(!i.isAction());
	}
	void test_isAction2() {
		Instruction i("hop");
		CPPUNIT_ASSERT(i.isAction());
	}
	void test_isAction3() {
		Instruction i("right");
		CPPUNIT_ASSERT(i.isAction());
	}
		
		
	// ---------
    // addInstruction
    // ---------
	
	void test_addInstruction1() {
		Species food('f');
		food.addInstruction("go", 0);
		CPPUNIT_ASSERT(food._program.size() == 1);
	}
    
	void test_addInstruction2() {
		Species food('f');
		food.addInstruction("go", 0);
		Instruction i("hop");
		food.addInstruction(i);
		CPPUNIT_ASSERT(food._program.size() == 2);
	}
	
	void test_addInstruction3() {
		Species food('f');
		CPPUNIT_ASSERT(food._program.size() == 0);
	}
	
	// ---------
    // nextInstruction
    // ---------
	
 	void test_nextInstruction1() {
 	 	Instruction i("hop");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(i.nextInstruction(f1._pc, SOUTH) == 0);
 	}
 	
 	void test_nextInstruction2() {
 	 	Instruction i("hop");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(food._program.size() == 2);
 		CPPUNIT_ASSERT(i.nextInstruction(f1._pc, WEST) == 0);
 	}
 	
 	void test_nextInstruction3() {
 	 	Instruction i("hop");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(food._program.size() == 2);
 		CPPUNIT_ASSERT(i.nextInstruction(f1._pc, EAST) == 0);
 	}
 	
 	// ---------
    // nextInstruction
    // ---------
	
 	void test_nextAction1() {
 	 	Instruction i("hop");
 	 	Instruction i2("left");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction(i2);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(f1._direction == 1);
 		CPPUNIT_ASSERT(food._program.size() == 3);
 	}
 	
 	void test_nextAction2() {
 	 	Instruction i("hop");
 	 	Instruction i2("left");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction(i2);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(f1.nextAction(EAST) == 0);
 		CPPUNIT_ASSERT(food._program.size() == 3);
 	}
 	
 	void test_nextAction3() {
 	 	Instruction i("hop");
 	 	Instruction i2("left");
 		Species food('f');
 		food.addInstruction(i);
 		food.addInstruction(i2);
 		food.addInstruction("go", 0);
 		Creature f1(&food, 1);
 		CPPUNIT_ASSERT(f1.nextAction(WEST) == 0);
 		CPPUNIT_ASSERT(food._program.size() == 3);
 	}
 	
 	// ---------
    // deactivate
    // ---------
	
 	void test_deactivate1() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		CPPUNIT_ASSERT(h1._activated == false);
 	}
	
	void test_deactivate2() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		h1.activate();
 		CPPUNIT_ASSERT(h1._activated == true);
 	}
 	
 	void test_deactivate3() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		h1.activate();
 		h1.deactivate();
 		CPPUNIT_ASSERT(h1._activated == false);
 	}
	
	// ---------
    // activate
    // ---------
	
 	void test_activate1() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		h1.activate();
 		CPPUNIT_ASSERT(h1._activated == true);
 	}
	
	void test_activate2() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		h1.activate();
 		h1.deactivate();
 		h1.activate();
 		CPPUNIT_ASSERT(h1._activated == true);
 	}
 	
 	void test_activate3() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		h1.activate();
 		h1.deactivate();
 		CPPUNIT_ASSERT(h1._activated == false);
 	}
 	
 	// ---------
    // infect
    // ---------
	
 	void test_infect1() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		Species food('f');
 		Creature f1(&food, EAST);
 		h1.infect(&f1);
 		CPPUNIT_ASSERT('h' == 'h');
 	}
 	
 	void test_infect2() {
 		Species best('b');
 		Creature b1(&best, WEST);
 		Species food('f');
 		Creature f1(&food, EAST);
 		b1.infect(&f1);
 		CPPUNIT_ASSERT('b' == 'b');
 	}
 	
 	void test_infect3() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		Creature h2(&hopper, EAST);
 		h1.infect(&h2);
 		CPPUNIT_ASSERT('h' == 'h');
 	}
 	
 	// ---------
    // isEnemy
    // ---------
	
	void test_isEnemy1() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		Species food('f');
 		Creature f1(&food, EAST);
 		CPPUNIT_ASSERT(f1.isEnemy(&h1));
 	}
 	
 	void test_isEnemy2() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		Creature h2(&hopper, EAST);
 		CPPUNIT_ASSERT(!h1.isEnemy(&h2));
 	}
 	
 	void test_isEnemy3() {
 		Species hopper('h');
 		Creature h1(&hopper, WEST);
 		Creature h2(&hopper, EAST);
 		Species best('b');
 		Creature b1(&best, NORTH);
 		CPPUNIT_ASSERT(b1.isEnemy(&h2));
 	}
 	
 	// ---------
    // printGrid
    // ---------
	
	void test_printGrid1() {
 		Grid g(0, 0);
 	}
 	
 	void test_printGrid2() {
 		Grid g(10, 10);
 	}
 	
 	void test_printGrid3() {
 		Grid g(20, 20);
 		//g.printGrid();
 	}
	
	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_isAction1);
	CPPUNIT_TEST(test_isAction2);
	CPPUNIT_TEST(test_isAction3);
	CPPUNIT_TEST(test_nextInstruction1);
	CPPUNIT_TEST(test_nextInstruction2);
	CPPUNIT_TEST(test_nextInstruction3);
	CPPUNIT_TEST(test_addInstruction1);
	CPPUNIT_TEST(test_addInstruction2);
	CPPUNIT_TEST(test_addInstruction3);
	CPPUNIT_TEST(test_nextAction1);
	CPPUNIT_TEST(test_nextAction2);
	CPPUNIT_TEST(test_nextAction3);
	CPPUNIT_TEST(test_deactivate1);
	CPPUNIT_TEST(test_deactivate2);
	CPPUNIT_TEST(test_deactivate3);
	CPPUNIT_TEST(test_activate1);
	CPPUNIT_TEST(test_activate2);
	CPPUNIT_TEST(test_activate3);
	CPPUNIT_TEST(test_infect1);
	CPPUNIT_TEST(test_infect2);
	CPPUNIT_TEST(test_infect3);
	CPPUNIT_TEST(test_isEnemy1);
	CPPUNIT_TEST(test_isEnemy2);
	CPPUNIT_TEST(test_isEnemy3);
	CPPUNIT_TEST(test_printGrid1);
	CPPUNIT_TEST(test_printGrid2);
	CPPUNIT_TEST(test_printGrid3);
	
	CPPUNIT_TEST_SUITE_END();
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;

	
	
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}