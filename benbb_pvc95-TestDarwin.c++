// -----------------------------
// Ben Bowley-Bryant
// benbb
// Paul Carroll
// pvc95
// -----------------------------


/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestDarwin >& TestDarwin.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public

//For convienence
#define FOOD 0
#define HOPPER 1
#define ROVER 2
#define TRAP 3
#define BEST 4

#include "Darwin.h"

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------

	// --------
	// Creature Tests
	// --------
    
    // --------
    // test_Creature_left
    // --------

    void test_Creature_left () {
        Creature A(0, 0, 1);
        CPPUNIT_ASSERT(A._facing == 1);
        A.left();
        CPPUNIT_ASSERT(A._facing == 0);
    }
    
    // --------
    // test_Creature_left_Overflow
    // --------

    void test_Creature_left_Overflow () {
        Creature A(0, 0, 0);
        CPPUNIT_ASSERT(A._facing == 0);
        A.left();
        CPPUNIT_ASSERT(A._facing == 3);
    }
    
    // --------
    // test_Creature_right
    // --------

    void test_Creature_right () {
        Creature A(0, 0, 0);
        CPPUNIT_ASSERT(A._facing == 0);
        A.right();
        CPPUNIT_ASSERT(A._facing == 1);
    }
    
    // --------
    // test_Creature_right_Overflow
    // --------

    void test_Creature_right_Overflow () {
        Creature A(0, 0, 3);
        CPPUNIT_ASSERT(A._facing == 3);
        A.right();
        CPPUNIT_ASSERT(A._facing == 0);
    }
    
    // --------
    // test_Creature_infect
    // --------

    void test_Creature_infect () {
    	Game g(2,2);
        g.creatures.push_back(CreatureContainer(&g,0,0,0,0));
        g.creatures.push_back(CreatureContainer(&g,1,1,0,1));
        
        CreatureContainer& Food = g.creatures[0];
        CreatureContainer& NotFood = g.creatures[1];
        
        Food.A._program_counter = 1;
        
        CPPUNIT_ASSERT(Food.A._species == 0);
        CPPUNIT_ASSERT(Food.A._program_counter == 1);
        
        NotFood.A.infect();
        
        CPPUNIT_ASSERT(Food.A._species == 1);
        CPPUNIT_ASSERT(Food.A._program_counter == 0);
    }
    
    // --------
    // test_Creature_infect_fail_wrong_dir
    // --------

    void test_Creature_infect_fail_wrong_dir () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,0,0,0,0));
        g.creatures.push_back(CreatureContainer(&g,1,1,0,0));
        
        CreatureContainer& Food = g.creatures[0];
        CreatureContainer& NotFood = g.creatures[1];
        
        Food.A._program_counter = 1;
        
        CPPUNIT_ASSERT(Food.A._species == 0);
        CPPUNIT_ASSERT(Food.A._program_counter == 1);
        
        NotFood.A.infect();
        
        CPPUNIT_ASSERT(Food.A._species == 0);
        CPPUNIT_ASSERT(Food.A._program_counter == 1);
    }
    
    // --------
    // test_Creature_infect_fail_same_species
    // --------

    void test_Creature_infect_fail_same_species () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,1,0,0,0));
        g.creatures.push_back(CreatureContainer(&g,1,0,1,1));
        
        CreatureContainer& Food = g.creatures[0];
        CreatureContainer& NotFood = g.creatures[1];
        
        Food.A._program_counter = 1;
        
        CPPUNIT_ASSERT(Food.A._species == 1);
        CPPUNIT_ASSERT(Food.A._program_counter == 1);
        
        NotFood.A.infect();
        
        CPPUNIT_ASSERT(Food.A._species == 1);
        CPPUNIT_ASSERT(Food.A._program_counter == 1);
    }

    // --------
    // test_Creature_hop
    // --------

    void test_Creature_hop () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(Hopper.x == 0);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
        Hopper.A.hop();
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
    }
    
    // --------
    // test_Creature_hop_fail_wall
    // --------

    void test_Creature_hop_fail_wall () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,1,1,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
        Hopper.A.hop();
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
    }
    
    // --------
    // test_Creature_hop_fail_enemy
    // --------

    void test_Creature_hop_fail_enemy () {
    	Game g(2,2);
    	
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
        g.creatures.push_back(CreatureContainer(&g,1,1,0,1));
        
        CreatureContainer& Hopper = g.creatures[1];
        
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
        Hopper.A.hop();
        
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
    }
    
    // --------
    // test_Creature_same_species
    // --------

    void test_Creature_same_species () {   	
        Creature A(0, 0, 0);
        Creature B(0, 0, 0);
        
        CPPUNIT_ASSERT(A.is_same_species(&B));
        
    }
    
    // --------
    // test_Creature_same_species_fail
    // --------

    void test_Creature_same_species_fail () {   	
        Creature A(0, 0, 0);
        Creature B(0, 1, 0);
        
        CPPUNIT_ASSERT(!A.is_same_species(&B));
        
    }
    
    // --------
    // test_Creature_equals
    // --------

    void test_Creature_equals () {   	
        Creature A(0, 0, 0);
        Creature B(0,0,0);
        
        B._id = A._id;
        
        CPPUNIT_ASSERT(A == B);
        
    }
    
    // --------
    // test_Creature_==_fail
    // --------

    void test_Creature_equals_fail () {   	
        Creature A(0, 0, 0);
        Creature B(0, 0, 0);

        
        CPPUNIT_ASSERT(!(A == B));
        
    }
    
    //-------
    //Hopper Actions
    //-------
    
    void test_Creature_hopper_actions()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,HOPPER,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        CPPUNIT_ASSERT(Hopper.A._program_counter == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 1);
		CPPUNIT_ASSERT(Hopper.y == 0);
    }

	void test_Creature_hopper_actions_3_steps()
    {
    	Game g(3,2);
    	
        g.creatures.push_back(CreatureContainer(&g,HOPPER,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        CPPUNIT_ASSERT(Hopper.A._program_counter == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 1);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 2);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 2);
		CPPUNIT_ASSERT(Hopper.y == 0);
    }
    
    void test_Creature_hopper_actions_5_steps()
    {
    	Game g(6,2);
    	
        g.creatures.push_back(CreatureContainer(&g,HOPPER,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        CPPUNIT_ASSERT(Hopper.A._program_counter == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 1);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 2);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 3);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 4);
		CPPUNIT_ASSERT(Hopper.y == 0);
		Hopper.A.act();
		CPPUNIT_ASSERT(Hopper.A._program_counter == 1);
		CPPUNIT_ASSERT(Hopper.x == 5);
		CPPUNIT_ASSERT(Hopper.y == 0);
    }
    
    //--------
    //Trap Actions
    //--------
    
    void test_Creature_trap_actions()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,TRAP,0,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
    }
    
    void test_Creature_trap_actions_3_steps()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,TRAP,0,0,2));
        g.creatures.push_back(CreatureContainer(&g,FOOD,1,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        
        
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 1);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 0);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == 0);
    }
    
    void test_Creature_trap_actions_5_steps()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,TRAP,0,0,2));
        g.creatures.push_back(CreatureContainer(&g,FOOD,1,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 1);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 0);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 3);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 4);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == Trap.A._species);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 4);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 2);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
    }
    
    //--------
    //Food Actions
    //--------
    
    void test_Creature_Food_actions()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,FOOD,0,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
    }
    
    void test_Creature_Food_actions_3_steps()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,FOOD,0,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 1);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 0);
    }
    
    void test_Creature_Food_actions_5_steps()
    {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,FOOD,0,0,3));
        
        CreatureContainer& Trap = g.creatures[0];
        
        CPPUNIT_ASSERT(Trap.A._program_counter == 0);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 1);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 0);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 3);
		
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		Trap.A.act();
		CPPUNIT_ASSERT(Trap.A._program_counter == 1);
		CPPUNIT_ASSERT(Trap.x == 0);
		CPPUNIT_ASSERT(Trap.y == 0);
		CPPUNIT_ASSERT(Trap.A._facing == 2);
    }
    
    //--------
    //Rover Actions
    //--------
    
    void test_Creature_Rover_actions()
    {
    	Game g(6,6);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,ROVER,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,5,2,0));
        
        CreatureContainer& Rover = g.creatures[0];
        CPPUNIT_ASSERT(Rover.A._program_counter == 0);
        CPPUNIT_ASSERT(Rover.x == 2);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 3);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
    }
    
    void test_Creature_Rover_actions_3_steps()
    {
    	Game g(6,6);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,ROVER,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,5,2,0));
        
        CreatureContainer& Rover = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        CPPUNIT_ASSERT(Rover.A._program_counter == 0);
        CPPUNIT_ASSERT(Rover.x == 2);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		Rover.A.act();
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 3);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 10);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == Rover.A._species);
    }
    
    void test_Creature_Rover_actions_5_steps()
    {
    	Game g(6,6);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,ROVER,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,5,2,0));
        
        CreatureContainer& Rover = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        CPPUNIT_ASSERT(Rover.A._program_counter == 0);
        CPPUNIT_ASSERT(Rover.x == 2);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		Rover.A.act();
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 3);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 10);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == Rover.A._species);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 10);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 6);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 2);
		CPPUNIT_ASSERT(Rover.A._facing == 0);
		
		CPPUNIT_ASSERT(Rover.A._program_counter == 6);
		Rover.A.act();
		CPPUNIT_ASSERT(Rover.A._program_counter == 8);
		CPPUNIT_ASSERT(Rover.x == 4);
		CPPUNIT_ASSERT(Rover.y == 1);
		CPPUNIT_ASSERT(Rover.A._facing == 0);
    }

    //--------
    //Best Actions
    //--------
    
    void test_Creature_Best_actions()
    {
    	Game g(5,5);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,BEST,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,4,2,0));
        
        CreatureContainer& Best = g.creatures[0];
        CPPUNIT_ASSERT(Best.A._program_counter == 0);
        CPPUNIT_ASSERT(Best.x == 2);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 3);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
    }
    
    void test_Creature_Best_actions_3_steps()
    {
    	Game g(6,6);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,BEST,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,5,2,0));
        
        CreatureContainer& Best = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        CPPUNIT_ASSERT(Best.A._program_counter == 0);
        CPPUNIT_ASSERT(Best.x == 2);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		Best.A.act();
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 3);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == Best.A._species);
    }
    
    void test_Creature_Best_actions_5_steps()
    {
    	Game g(6,6);
    	srand(0);
        g.creatures.push_back(CreatureContainer(&g,BEST,2,2,3));
        g.creatures.push_back(CreatureContainer(&g,FOOD,5,2,0));
        
        CreatureContainer& Best = g.creatures[0];
        CreatureContainer& Food = g.creatures[1];
        
        CPPUNIT_ASSERT(Best.A._program_counter == 0);
        CPPUNIT_ASSERT(Best.x == 2);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		Best.A.act();
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 3);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 3);
		CPPUNIT_ASSERT(Food.A._species == Best.A._species);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 2);
		CPPUNIT_ASSERT(Best.A._facing == 2);
		
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		Best.A.act();
		CPPUNIT_ASSERT(Best.A._program_counter == 1);
		CPPUNIT_ASSERT(Best.x == 4);
		CPPUNIT_ASSERT(Best.y == 3);
		CPPUNIT_ASSERT(Best.A._facing == 2);
    }
    
    // --------
    // Game_Tests
    // --------
    
    // --------
    // test_Creature_hop
    // --------

    void test_Game_hop () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(Hopper.x == 0);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
        g.hop(Hopper.A);
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
    }
    
    // --------
    // test_Game_hop_fail_wall
    // --------

    void test_Game_hop_fail_wall () {
    	Game g(2,2);
    	
        g.creatures.push_back(CreatureContainer(&g,1,0,1,2));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(Hopper.x == 0);
        CPPUNIT_ASSERT(Hopper.y == 1);
        
        g.hop(Hopper.A);
        
        CPPUNIT_ASSERT(Hopper.x == 0);
        CPPUNIT_ASSERT(Hopper.y == 1);
        
    }
    
    // --------
    // test_Game_hop_fail_enemy
    // --------

    void test_Game_hop_fail_enemy () {
    	Game g(2,2);
    	
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
        g.creatures.push_back(CreatureContainer(&g,1,1,0,1));
        
        CreatureContainer& Hopper = g.creatures[1];
        
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
        g.hop(Hopper.A);
        
        
        CPPUNIT_ASSERT(Hopper.x == 1);
        CPPUNIT_ASSERT(Hopper.y == 0);
        
    }
    
    void test_Game_empty_ahead () {
    	Game g(2,2);
    	
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(g.empty_ahead(Hopper.A));
        
    }
    
    void test_Game_empty_ahead_fail_wall () {
    	Game g(2,2);
    	
    	g.creatures.push_back(CreatureContainer(&g,1,0,1,2));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(!g.empty_ahead(Hopper.A));
        
    }
    
    void test_Game_empty_ahead_fail_enemy () {
    	Game g(2,2);
    	
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
    	g.creatures.push_back(CreatureContainer(&g,1,1,0,1));
        
        CreatureContainer& Hopper = g.creatures[0];
        
        
        CPPUNIT_ASSERT(!g.empty_ahead(Hopper.A));
        
    }
    
    void test_Game_print_board()
    {
    	Game g(2,2);
    	ostringstream s;
    	g.printBoard(s);
    	
    	CPPUNIT_ASSERT(s.str() == "  01\n0 ..\n1 ..\n\n");
    	
    }
    
    void test_Game_print_board_1_Hopper()
    {
    	Game g(2,2);
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
    	ostringstream s;
    	
    	//cout << endl;
    	
    	
    	g.printBoard(s);
    	/*cout <<s.str();
    	for(int i = 0;i<s.str().length();++i)
    	{
    		cout << (int)s.str()[i] << " ";
    	}
    	cout << endl << endl;*/
    	CPPUNIT_ASSERT(s.str() == "  01\n0 h.\n1 ..\n\n");
    	
    }
    
    void test_Game_print_board_1_Hopper_1_Food_3x3()
    {
    	Game g(3,3);
    	g.creatures.push_back(CreatureContainer(&g,1,0,0,3));
    	g.creatures.push_back(CreatureContainer(&g,0,2,2,3));
    	ostringstream s;
    	
    	g.printBoard(s);
    	CPPUNIT_ASSERT(s.str() == "  012\n0 h..\n1 ...\n2 ..f\n\n");
    }
    
    void test_Game_start()
    {
    	Game g(3,3);
    	g.add_creature(HOPPER,0,0,0);
    	g.add_creature(FOOD,0,1,0);
    	g.add_creature(BEST,0,2,0);
    	g.add_creature(TRAP,0,0,1);
    	g.add_creature(ROVER,0,0,2);
    	ostringstream s,s2;
    	for(unsigned i = 0;i<g.creatures.size();++i)
    	{
    		s << Creature::species_char(g.creatures[i].A);
    	}
    	CPPUNIT_ASSERT(s.str() == "hfbtr");
    	
    	g.start();
    	
    	for(unsigned i = 0;i<g.creatures.size();++i)
    	{
    		s2 << Creature::species_char(g.creatures[i].A);
    	}
    	CPPUNIT_ASSERT(s2.str() == "htrfb");
    }
    
    void test_Game_start_improper_sort_fix()
    {
    	Game g(72,72);
    	g.add_creature(FOOD,0,1,0);
    	g.add_creature(HOPPER,0,0,33);
    	ostringstream s,s2;
    	for(unsigned i = 0;i<g.creatures.size();++i)
    	{
    		s << Creature::species_char(g.creatures[i].A);
    	}
    	CPPUNIT_ASSERT(s.str() == "fh");
    	
    	g.start();
    	
    	for(unsigned i = 0;i<g.creatures.size();++i)
    	{
    		s2 << Creature::species_char(g.creatures[i].A);
    	}
    	CPPUNIT_ASSERT(s2.str() == "hf");
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    //Creature Tests
    CPPUNIT_TEST(test_Creature_left);
    CPPUNIT_TEST(test_Creature_right);
    CPPUNIT_TEST(test_Creature_left_Overflow);
    CPPUNIT_TEST(test_Creature_right_Overflow);
    CPPUNIT_TEST(test_Creature_infect);
    CPPUNIT_TEST(test_Creature_infect_fail_same_species);
	CPPUNIT_TEST(test_Creature_infect_fail_wrong_dir);
	CPPUNIT_TEST(test_Creature_hop);
	CPPUNIT_TEST(test_Creature_hop_fail_wall);
	CPPUNIT_TEST(test_Creature_hop_fail_enemy);
	CPPUNIT_TEST(test_Creature_same_species);
	CPPUNIT_TEST(test_Creature_same_species_fail);
	CPPUNIT_TEST(test_Creature_equals);
	CPPUNIT_TEST(test_Creature_equals_fail);
	CPPUNIT_TEST(test_Creature_hopper_actions);
	CPPUNIT_TEST(test_Creature_hopper_actions_3_steps);
	CPPUNIT_TEST(test_Creature_hopper_actions_5_steps);
	CPPUNIT_TEST(test_Creature_trap_actions);
	CPPUNIT_TEST(test_Creature_trap_actions_3_steps);
	CPPUNIT_TEST(test_Creature_trap_actions_5_steps);
	CPPUNIT_TEST(test_Creature_Food_actions);
	CPPUNIT_TEST(test_Creature_Food_actions_3_steps);
	CPPUNIT_TEST(test_Creature_Food_actions_5_steps);
	CPPUNIT_TEST(test_Creature_Rover_actions);
	CPPUNIT_TEST(test_Creature_Rover_actions_3_steps);
	CPPUNIT_TEST(test_Creature_Rover_actions_5_steps);
	CPPUNIT_TEST(test_Creature_Best_actions);
	CPPUNIT_TEST(test_Creature_Best_actions_3_steps);
	CPPUNIT_TEST(test_Creature_Best_actions_5_steps);
	CPPUNIT_TEST(test_Game_start);
	CPPUNIT_TEST(test_Game_start_improper_sort_fix);
	//Game Tests
	CPPUNIT_TEST(test_Game_hop);
	CPPUNIT_TEST(test_Game_hop_fail_wall);
	CPPUNIT_TEST(test_Game_hop_fail_enemy);
	CPPUNIT_TEST(test_Game_empty_ahead);
	CPPUNIT_TEST(test_Game_empty_ahead_fail_enemy);
	CPPUNIT_TEST(test_Game_empty_ahead_fail_wall);
	CPPUNIT_TEST(test_Game_print_board);
	CPPUNIT_TEST(test_Game_print_board_1_Hopper);
	CPPUNIT_TEST(test_Game_print_board_1_Hopper_1_Food_3x3);
	CPPUNIT_TEST(test_Game_start);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestAllocator.c++" << endl;

    CppUnit::TextTestRunner tr;

  	tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
