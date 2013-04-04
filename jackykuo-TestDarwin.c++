// --------
// includes
// --------
#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner
#define protected public
#define private public
#define class struct
#include "Darwin.h"



using namespace std;   
    struct TestDarwin : CppUnit::TestFixture {

    // ---------
    // Specie's constructor
    // ---------

	void test_one(){
	Specie test1("test1");
	CPPUNIT_ASSERT((test1.name).compare("test1")==0);

	}
	void test_two(){
	Specie test2("");
	CPPUNIT_ASSERT((test2.name).compare("")==0);
	}
	void test_three(){
	Specie test3("42");
	CPPUNIT_ASSERT((test3.name).compare("42")==0);
	}
    // ---------
    // Specie's addStep
    // ---------

	void test_four(){
	Specie test1("test1");
	test1.addStep("", 0);
	CPPUNIT_ASSERT((test1.program[0]).compare("")==0);	
	CPPUNIT_ASSERT((test1.programD[0]) == 0);

	}
	void test_five(){
	Specie test2("test2");
	test2.addStep("jump",0);
	test2.addStep("step",1);
	CPPUNIT_ASSERT((test2.program[1]).compare("step")==0);	
	CPPUNIT_ASSERT((test2.programD[1]) == 1);

	}
	void test_six(){
	Specie test3("test3");
	test3.addStep("jump",0);
	test3.addStep("step",2);
	test3.addStep("fly",0);
	CPPUNIT_ASSERT((test3.program[1]).compare("step")==0);	
	CPPUNIT_ASSERT((test3.programD[2]) == 0);
	}
    // ---------
    // Specie's instuction getter methods(instruction and instructionI)
    // ---------

	void test_getterS1(){
	Specie test1("test1");
	test1.addStep("", 0);
	CPPUNIT_ASSERT((test1.instruction(0)).compare("")==0);

	}
	void test_getterS2(){
	Specie test2("test2");
	test2.addStep("jump",0);
	test2.addStep("step",1);
	CPPUNIT_ASSERT((test2.instruction(1)).compare("step")==0);

	}
	void test_getterS3(){
	Specie test3("test3");
	test3.addStep("jump",0);
	test3.addStep("step",2);
	test3.addStep("fly",0);
	CPPUNIT_ASSERT((test3.instruction(2)).compare("fly")==0);
	}
	
	void test_getterI1(){
	Specie test1("test1");
	test1.addStep("", 0);
	CPPUNIT_ASSERT((test1.instructionI(0))==0);

	}
	void test_getterI2(){
	Specie test2("test2");
	test2.addStep("jump",0);
	test2.addStep("step",1);
	CPPUNIT_ASSERT((test2.instructionI(1))==1);

	}
	void test_getterI3(){
	Specie test3("test3");
	test3.addStep("jump",0);
	test3.addStep("step",2);
	test3.addStep("fly",0);
	CPPUNIT_ASSERT((test3.instructionI(2))==0);
	}

    // ---------
    // Specie's name getter
    // ---------

	void test_myName1(){
	Specie test1("test1");
	CPPUNIT_ASSERT((test1.myName()).compare("test1")==0);

	}
	void test_myName2(){
	Specie test2("");
	CPPUNIT_ASSERT((test2.myName()).compare("")==0);
	}
	void test_myName3(){
	Specie test3("42");
	CPPUNIT_ASSERT((test3.myName()).compare("42")==0);
	}
	
    // ---------
    // Creature's Constructor
    // ---------
	

	
	void test_Creature1(){
	Specie test1("test1");
	Creature test(test1, 0,0,0);
	CPPUNIT_ASSERT(test.mySpecie==&test1);

	}
	void test_Creature2(){
	Specie test2("");
	Creature test(test2, 0,1,0);
	CPPUNIT_ASSERT(test.y == 1);

	}
	void test_Creature3(){
	Specie test2("");
	Creature test(test2, 0,0,3);
	CPPUNIT_ASSERT((test.direction)==3);
	}
	
    // ---------
    // Creature's mySpecieName()
    // ---------


	
	void test_CreatureName1(){
	Specie test1("test1");
	Creature test(test1, 0,0,0);
	CPPUNIT_ASSERT((test.mySpecieName()).compare("test1")==0);

	}
	void test_CreatureName2(){
	Specie test2("");
	Creature test(test2, 0,0,0);
	CPPUNIT_ASSERT((test.mySpecieName()).compare("")==0);

	}
	void test_CreatureName3(){
	Specie test3("42");
	Creature test(test3, 0,0,0);
	CPPUNIT_ASSERT((test.mySpecieName()).compare("42")==0);
	}
	
	
    // ---------
    // Creature's getInfected
    // ---------
	
	void test_CreatureInfect1(){
	Specie test1("test1");
	Specie test2("test2");
	Creature test(test1, 0,0,0);
	test.getInfected(&test2);
	CPPUNIT_ASSERT((test.mySpecieName()).compare("test2")==0);

	}
	void test_CreatureInfect2(){
	Specie test1("test1");
	Specie test2("test2");
	Creature test(test1, 0,0,0);
	test.PC = 3;
	test.getInfected(&test2);
	CPPUNIT_ASSERT(test.PC==0);
	}
	void test_CreatureInfect3(){
	Specie test1("test1");
	Specie test2("");
	Creature test(test1, 0,0,0);
	test.PC = 3;
	test.getInfected(&test2);
	CPPUNIT_ASSERT((test.mySpecieName()).compare("")==0);
	}

    // ---------
    // Creature's step
    // ---------
	
	void test_CreatureStep1(){
	World world1(4,4);
	Specie test1("test1");
	test1.addStep("if_enemy",5 );
	Creature test(test1, 0,0,2);
	world1.put(test,0,0);
	test.step(world1.grid, world1.hasSetWorld);
	CPPUNIT_ASSERT(test.PC == 1);
	}
	void test_CreatureStep2(){
	World world1(4,4);
	Specie test1("test1");
	test1.addStep("hop",-1 );
	Creature test(test1, 0,0,2);
	world1.put(test,0,0);
	test.step(world1.grid, world1.hasSetWorld);
	CPPUNIT_ASSERT(test.PC == 1);
	}
	void test_CreatureStep3(){
	World world1(4,4);
	Specie test1("test1");
	test1.addStep("if_wall",3 );
	Creature test(test1, 0,0,0);
	world1.put(test,0,0);
	test.step(world1.grid, world1.hasSetWorld);
	CPPUNIT_ASSERT(test.PC == 3);
	}
	
    // ---------
    // World's Constructor
    // ---------
	void test_World1(){
	World world1(4,4);
	CPPUNIT_ASSERT(world1.w == 4);
	CPPUNIT_ASSERT(world1.h == 4);

	}
	void test_World2(){
	World world1(4,4);
	CPPUNIT_ASSERT(world1.grid.size() == 4);
	CPPUNIT_ASSERT(world1.grid[0].size() == 4);

	}
	void test_World3(){
	World world1(4,4);
	CPPUNIT_ASSERT(world1.hasSetWorld.size() == 4);
	CPPUNIT_ASSERT(world1.hasSetWorld[0].size() == 4);
	}
	
    // ---------
    // World's put
    // ---------
	void test_WorldPut1(){
	World world1(4,4);
	Specie test1("test1");
	Creature test(test1, 0,0,0);
	world1.put(test,0,0);
	CPPUNIT_ASSERT((world1.grid[0][0]) == &test);
	}
	void test_WorldPut2(){
	World world1(4,4);
	Specie test1("test1");
	Creature test(test1, 2,2,0);
	world1.put(test,2,2);
	CPPUNIT_ASSERT((world1.grid[2][2]) == &test);
	}
	void test_WorldPut3(){
	World world1(4,4);
	Specie test1("test1");
	Creature test(test1, 2,2,0);
	world1.put(test,2,2);
	CPPUNIT_ASSERT(((world1.grid[2][2])->mySpecieName()).compare("test1")==0);
	}

    // ---------
    // World's simulate
    // ---------
	void test_WorldSimulate1(){
	World world1(4,4);
	Specie test1("test1");
	test1.addStep("hop",-1);
	Creature test(test1, 0,0,2);
	world1.put(test,0,0);
	world1.simulate(1,-1);
	CPPUNIT_ASSERT((world1.grid[0][1]) == &test);
	}

	void test_WorldSimulate2(){
	World world1(4,4);
	Specie test1("test1");
	test1.addStep("hop",-1);
	Creature test(test1, 0,0,2);
	world1.put(test,0,0);
	world1.simulate(1,-1);
	CPPUNIT_ASSERT((world1.hasSetWorld[0][1]) == 0);
	}

	void test_WorldSimulate3(){
	World world1(4,4);
	Specie food("food");
	food.addStep("left",-1);
	Specie infector("test");
	infector.addStep("infect",-1);
	Creature food1(food, 0,0,0);
	Creature test(infector,0,1,0);
	world1.put(food1,0,0);
	world1.put(test,0,1);
	world1.simulate(1,-1);
	CPPUNIT_ASSERT(((world1.grid[0][0])->mySpecieName()).compare("test")==0);
	}

    // ---------
    // World's print
    // ---------
	//To test the print method in World would require assertions about the 		standard out stream; unable to test here. 
    // ---------
    // TestSuite
    // ---------

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_one);
    CPPUNIT_TEST(test_two);
    CPPUNIT_TEST(test_three);
    CPPUNIT_TEST(test_four);
    CPPUNIT_TEST(test_five);
    CPPUNIT_TEST(test_six);
    CPPUNIT_TEST(test_getterS1);
    CPPUNIT_TEST(test_getterS2);
    CPPUNIT_TEST(test_getterS3);
    CPPUNIT_TEST(test_getterI1);
    CPPUNIT_TEST(test_getterI2);
    CPPUNIT_TEST(test_getterI3);
    CPPUNIT_TEST(test_myName1);
    CPPUNIT_TEST(test_myName2);
    CPPUNIT_TEST(test_myName3);
    CPPUNIT_TEST(test_Creature1);
    CPPUNIT_TEST(test_Creature2);
    CPPUNIT_TEST(test_Creature3);
    CPPUNIT_TEST(test_CreatureName1);
    CPPUNIT_TEST(test_CreatureName2);
    CPPUNIT_TEST(test_CreatureName3);
    CPPUNIT_TEST(test_CreatureInfect1);
    CPPUNIT_TEST(test_CreatureInfect2);
    CPPUNIT_TEST(test_CreatureInfect3);
    CPPUNIT_TEST(test_CreatureStep1);
    CPPUNIT_TEST(test_CreatureStep2);
    CPPUNIT_TEST(test_CreatureStep3);
    CPPUNIT_TEST(test_World1);
    CPPUNIT_TEST(test_World2);
    CPPUNIT_TEST(test_World3);
    CPPUNIT_TEST(test_WorldPut1);
    CPPUNIT_TEST(test_WorldPut2);
    CPPUNIT_TEST(test_WorldPut3);    
    CPPUNIT_TEST(test_WorldSimulate1);
    CPPUNIT_TEST(test_WorldSimulate2);
    CPPUNIT_TEST(test_WorldSimulate3);
    
    

    CPPUNIT_TEST_SUITE_END();


   
   };   



// ----
// main
// ----
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
