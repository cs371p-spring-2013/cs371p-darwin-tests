
#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 
#include<map>
#include "math.h"
#include <string.h>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE,CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#define class struct
#include "Darwin.c++"

using namespace std;

struct TestDarwin : CppUnit::TestFixture{ 

	void test_creature_incrementCounter_1(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "s", 1, loc1);
		cr.incrementCounter();
		CPPUNIT_ASSERT(cr.programCounter == 1);
	}

	void test_creature_incrementCounter_2(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr1 = Creature("t", "s", 1, loc1);

		vector<int> loc2;
		loc2.resize(2);
		loc2[0] = 3;
		loc2[1] = 2;
		Creature cr2 = Creature("h", "e", 2, loc2);
		cr1.incrementCounter();
		cr2.incrementCounter();
		CPPUNIT_ASSERT(cr1.programCounter == 1);
		CPPUNIT_ASSERT(cr2.programCounter == 1);
	}

	void test_creature_incrementCounter_3(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("r", "s", 1, loc1);//rover
		cr.programCounter = 10;
		cr.incrementCounter();
		CPPUNIT_ASSERT(cr.programCounter == 0);
	}

	void test_creature_hop_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		cr.hop(b.positionGrid, b.IDGrid);

		CPPUNIT_ASSERT(b.positionGrid[1][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[1][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);
	}

	void test_creature_hop_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		cr.hop(b.positionGrid, b.IDGrid);
		CPPUNIT_ASSERT(b.positionGrid[1][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[1][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		cr.hop(b.positionGrid, b.IDGrid);
		CPPUNIT_ASSERT(b.positionGrid[2][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[2][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);
	}

	void test_creature_hop_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before hopping		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		//before hopping
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature cr1 = b.creatureList[0];
		Creature cr2 = b.creatureList[1];

		cr1.hop(b.positionGrid, b.IDGrid);
		cr2.hop(b.positionGrid, b.IDGrid);
		//after hopping
		CPPUNIT_ASSERT(b.positionGrid[1][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[1][0] == 1);
		//after hopping
		CPPUNIT_ASSERT(b.positionGrid[0][2] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][2] == 2);
	}

	void test_creature_left_1(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "s", 1, loc1);
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "e");
	}

	void test_creature_left_2(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "n", 1, loc1);
		cr.left();
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "s");
	}

	void test_creature_left_3(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "n", 1, loc1);
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "w");
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "s");
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "e");
		cr.left();
		CPPUNIT_ASSERT(cr.direction == "n");
	}

	void test_creature_right_1(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "s", 1, loc1);
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "w");
	}

	void test_creature_right_2(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "n", 1, loc1);
		cr.right();
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "s");
	}

	void test_creature_right_3(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "n", 1, loc1);
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "e");
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "s");
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "w");
		cr.right();
		CPPUNIT_ASSERT(cr.direction == "n");
	}

	void test_creature_infect_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before infecting		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		//before infecting
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature& cr1 = b.creatureList[0];
		Creature& cr2 = b.creatureList[1];

		cr1.infect(b.positionGrid, b.IDGrid, b.creatureList);
		//after infecting
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);
		CPPUNIT_ASSERT(cr2.species == "t");
		CPPUNIT_ASSERT(cr2.programCounter == 0);
	}

	void test_creature_infect_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before infecting		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		//before infecting
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature& cr1 = b.creatureList[0];
		Creature& cr2 = b.creatureList[1];
		cr2.programCounter = 1;

		//this should not change anything since trap is not facing food
		cr1.infect(b.positionGrid, b.IDGrid, b.creatureList);
		//after failed attempt at infecting
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);
		CPPUNIT_ASSERT(cr2.species == "f");
		CPPUNIT_ASSERT(cr2.programCounter == 1);
	}

	void test_creature_infect_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "w";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before infecting		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		//before infecting
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature& cr1 = b.creatureList[0];
		Creature& cr2 = b.creatureList[1];
		
		//this infect should turn the food into the trap
		cr1.infect(b.positionGrid, b.IDGrid, b.creatureList);
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);
		CPPUNIT_ASSERT(cr2.species == "t");
		CPPUNIT_ASSERT(cr2.programCounter == 0);

		cr1.programCounter = 2;
		//this infect should fail since the food is now trap and same species can't infect
		cr2.infect(b.positionGrid, b.IDGrid, b.creatureList);
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(cr1.species == "t");
		//if for some reason infect worked when it should fail, then pc should be set to 0
		CPPUNIT_ASSERT(cr1.programCounter == 2);
		//after infecting
	}

	void test_creature_if_empty_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool empty = cr.if_empty(b.positionGrid);
		CPPUNIT_ASSERT(empty);
	}

	void test_creature_if_empty_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "n";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool empty = cr.if_empty(b.positionGrid);
		//not empty since the hopper is facing the wall
		CPPUNIT_ASSERT(!empty);
	}

	void test_creature_if_empty_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature cr = b.creatureList[0];
		bool empty = cr.if_empty(b.positionGrid);
		//not empty since the hopper is facing an another creature
		CPPUNIT_ASSERT(!empty);		
	}

	void test_creature_if_wall_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool wall = cr.if_wall(b.positionGrid);
		//since there is no wall in front
		CPPUNIT_ASSERT(!wall);
	}

	void test_creature_if_wall_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "n";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool wall = cr.if_wall(b.positionGrid);
		//returns true since the hopper is facing the wall
		CPPUNIT_ASSERT(wall);
	}

	void test_creature_if_wall_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature cr = b.creatureList[0];
		bool wall = cr.if_wall(b.positionGrid);
		//returns false since there is no wall in front, although there is another creature
		CPPUNIT_ASSERT(!wall);		
	}

	void test_creature_if_enemy_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool enemy = cr.if_enemy(b.positionGrid);
		//since there is no enemy in front
		CPPUNIT_ASSERT(!enemy);
	}

	void test_creature_if_enemy_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "n";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);		
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.orderOfExecution[0] == 1);

		Creature cr = b.creatureList[0];
		bool enemy = cr.if_enemy(b.positionGrid);
		//returns false since the hopper is facing the wall
		CPPUNIT_ASSERT(!enemy);
	}

	void test_creature_if_enemy_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "1";//column
        listOfCreatureInfo[1][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'f');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);

		Creature cr = b.creatureList[0];
		bool enemy = cr.if_enemy(b.positionGrid);
		//returns true since there is another creature in front
		CPPUNIT_ASSERT(enemy);		
	}

	void test_creature_go_1(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("f", "s", 1, loc1);
		cr.go(2);
		CPPUNIT_ASSERT(cr.programCounter == 2);
	}

	void test_creature_go_2(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr1 = Creature("t", "s", 1, loc1);

		vector<int> loc2;
		loc2.resize(2);
		loc2[0] = 3;
		loc2[1] = 2;
		Creature cr2 = Creature("h", "e", 2, loc2);
		cr1.go(3);
		cr2.go(3);
		//asserts true even though hopper has program counter length of 2,
		//since go does not implement the modulo logic 
		CPPUNIT_ASSERT(cr1.programCounter == 3);
		CPPUNIT_ASSERT(cr2.programCounter == 3);
	}

	void test_creature_go_3(){
		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr = Creature("r", "s", 1, loc1);//rover
		cr.programCounter = 10;
		cr.go(-1);
		//go changes the program line to wherever it gets assigned.
		CPPUNIT_ASSERT(cr.programCounter == -1);
	}

	void test_creature_executeTurn_1(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "e";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before executing the turn for the hopper
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);

		//execute turn
		Creature& cr = b.creatureList[0];		
		cr.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);

		//after executing the turn for the hopper
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 1);
	}

	void test_creature_executeTurn_2(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "1";//column
        listOfCreatureInfo[0][3] = "e";//direction
  
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "0";//column
        listOfCreatureInfo[1][3] = "s";//direction
      
        Board b(4, 4, 5, listOfCreatureInfo, false);
		//before executing the turn for the hopper
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 1);
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 2);

		//execute turn
		Creature& cr1 = b.creatureList[0];		
		cr1.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);
		Creature& cr2 = b.creatureList[1];		
		cr2.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);

		//after executing the turn for the hoppers
		CPPUNIT_ASSERT(b.positionGrid[0][2] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][2] == 1);
		CPPUNIT_ASSERT(b.positionGrid[1][0] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[1][0] == 2);
	}

	void test_creature_executeTurn_3(){
		std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);


        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
  
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "0";//row
        listOfCreatureInfo[1][2] = "2";//column
        listOfCreatureInfo[1][3] = "w";//direction
      
        Board b(4, 4, 5, listOfCreatureInfo, false);
		Creature& TRAP = b.creatureList[0];
		Creature& HOPPER = b.creatureList[1];
		//before executing the turns
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(TRAP.programCounter == 0);
		CPPUNIT_ASSERT(TRAP.direction == "s");
		
		CPPUNIT_ASSERT(b.positionGrid[0][2] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][2] == 2);
		CPPUNIT_ASSERT(HOPPER.programCounter == 0);
		CPPUNIT_ASSERT(HOPPER.direction == "w");
		//trap
		/*
		 0: if_enemy 3
		 1: left
		 2: go 0
		 3: infect
		 4: go 0
		*/
		//hopper
		/*
		 0: hop
		 1: go 0
		*/

		//execute turn1	
		TRAP.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);	
		HOPPER.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);

		//after executing turn1
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(TRAP.programCounter == 2);
		CPPUNIT_ASSERT(TRAP.direction == "e");//after turning left

		CPPUNIT_ASSERT(b.positionGrid[0][1] == 'h');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);
		CPPUNIT_ASSERT(HOPPER.programCounter == 1);
		CPPUNIT_ASSERT(HOPPER.direction == "w");

		//execute turn2	
		TRAP.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);//this infects the hopper	
		HOPPER.executeTurn(b.positionGrid, b.IDGrid, b.creatureList);

		//after executing turn2
		CPPUNIT_ASSERT(b.positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(TRAP.programCounter == 4);
		CPPUNIT_ASSERT(TRAP.direction == "e");//after turning left
		//because it has been infected as trap already before executing turn,
		//its program counter should be reset to 0, and executes "left", and program counter should be 2
		CPPUNIT_ASSERT(b.positionGrid[0][1] == 't');
		CPPUNIT_ASSERT(b.IDGrid[0][1] == 2);
		CPPUNIT_ASSERT(HOPPER.programCounter == 2);//its name is misleading now since it has been infected.
		CPPUNIT_ASSERT(HOPPER.direction == "s");
	}




    void test_creature_construct_1(){
        string species = "f";
        string direction = "e";
        int identityNum = 1;
        std::vector<int> location;
        location.resize(2);
        location[0] = 2;
        location[1] = 3;
        std::vector<string> food;
        food.resize(2);
        food[0] = "left";
        food[1] = "go 0";
        Creature c = Creature(species, direction, identityNum, location);
        CPPUNIT_ASSERT(c.species == "f");
        CPPUNIT_ASSERT(c.direction == "e");
        CPPUNIT_ASSERT(c.id == 1);
        CPPUNIT_ASSERT(c.location[0] == 2);
        CPPUNIT_ASSERT(c.location[1] == 3);
        CPPUNIT_ASSERT(c.currentSpecies == food);

    }

    void test_creature_construct_2(){
        string species = "t";
        string direction = "s";
        int identityNum = 10;
        std::vector<int> location;
        location.resize(2);
        location[0] = 10;
        location[1] = 11;
        std::vector<string> trap;
        trap.resize(5);
        trap[0] = "if_enemy 3";
        trap[1] = "left";
        trap[2] = "go 0";
        trap[3] = "infect";
        trap[4] = "go 0";
        Creature c = Creature(species, direction, identityNum, location);
        CPPUNIT_ASSERT(c.species == "t");
        CPPUNIT_ASSERT(c.direction == "s");
        CPPUNIT_ASSERT(c.id == 10);
        CPPUNIT_ASSERT(c.location[0] == 10);
        CPPUNIT_ASSERT(c.location[1] == 11);
        CPPUNIT_ASSERT(c.currentSpecies == trap);


    }

    void test_creature_construct_3(){
        string species = "h";
        string direction = "n";
        int identityNum = 2;
        std::vector<int> location;
        location.resize(2);
        location[0] = 33;
        location[1] = 33;
        std::vector<string> hopper;
        hopper.resize(2);
        hopper[0] = "hop";
        hopper[1] = "go 0";
        Creature c = Creature(species, direction, identityNum, location);
        CPPUNIT_ASSERT(c.species == "h");
        CPPUNIT_ASSERT(c.direction == "n");
        CPPUNIT_ASSERT(c.id == 2);
        CPPUNIT_ASSERT(c.location[0] == 33);
        CPPUNIT_ASSERT(c.location[1] == 33);
        CPPUNIT_ASSERT(c.currentSpecies == hopper);}

	// -----------------
	// Board Constructor
	// -----------------

    void test_board_construct_1 () {
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
        vector<vector<char> > positionGrid = b.positionGrid;
        vector<Creature> creatureList = b.creatureList;
        vector<vector<int> > IDGrid = b.IDGrid;
        vector<int> orderOfExecution = b.orderOfExecution;
		
		CPPUNIT_ASSERT(positionGrid[0][0] == 'f');
		CPPUNIT_ASSERT(IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(orderOfExecution[0] == 1);

		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr1 = Creature("f", "s", 1, loc1);

		Creature cr2 = creatureList[0];
		
		CPPUNIT_ASSERT(cr1.species == cr2.species);
		CPPUNIT_ASSERT(cr1.location == cr2.location);
		CPPUNIT_ASSERT(cr1.id == cr2.id);
		CPPUNIT_ASSERT(cr1.direction == cr2.direction);
    }

    void test_board_construct_2 () {
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";
        listOfCreatureInfo[1][1] = "3";
        listOfCreatureInfo[1][2] = "2";
        listOfCreatureInfo[1][3] = "e";
        
        Board b(4, 4, 5, listOfCreatureInfo, false);
        vector<vector<char> > positionGrid = b.positionGrid;
        vector<Creature> creatureList = b.creatureList;
        vector<vector<int> > IDGrid = b.IDGrid;
        vector<int> orderOfExecution = b.orderOfExecution;
		
		CPPUNIT_ASSERT(positionGrid[0][0] == 't');
		CPPUNIT_ASSERT(positionGrid[3][2] == 'h');

		CPPUNIT_ASSERT(IDGrid[0][0] == 1);
		CPPUNIT_ASSERT(IDGrid[3][2] == 2);

		CPPUNIT_ASSERT(orderOfExecution[0] == 1);
		CPPUNIT_ASSERT(orderOfExecution[1] == 2);



		vector<int> loc1;
		loc1.resize(2);
		loc1[0] = 0;
		loc1[1] = 0;
		Creature cr1 = Creature("t", "s", 1, loc1);

		vector<int> loc2;
		loc2.resize(2);
		loc2[0] = 3;
		loc2[1] = 2;
		Creature cr2 = Creature("h", "e", 2, loc2);

		Creature cr3 = creatureList[0];
		Creature cr4 = creatureList[1];
		
		CPPUNIT_ASSERT(cr1.species == cr3.species);
		CPPUNIT_ASSERT(cr1.location == cr3.location);
		CPPUNIT_ASSERT(cr1.id == cr3.id);
		CPPUNIT_ASSERT(cr1.direction == cr3.direction);

		CPPUNIT_ASSERT(cr2.species == cr4.species);
		CPPUNIT_ASSERT(cr2.location == cr4.location);
		CPPUNIT_ASSERT(cr2.id == cr4.id);
		CPPUNIT_ASSERT(cr2.direction == cr4.direction);
    }

    




    void test_board_construct_random () {
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

		int cnt = 0;
		//generate food randomly
		while(cnt < 1)
		{
		    listOfCreatureInfo[cnt].resize(4);
		    listOfCreatureInfo[cnt][0] = "f";//species
		    listOfCreatureInfo[cnt][1] = "0";//row
		    listOfCreatureInfo[cnt][2] = "0";//column
		    listOfCreatureInfo[cnt][3] = "0";//direction
			cnt++;
		}   
        
        Board b(4, 4, 5, listOfCreatureInfo, true);
        vector<vector<char> > positionGrid = b.positionGrid;
        vector<Creature> creatureList = b.creatureList;
        vector<vector<int> > IDGrid = b.IDGrid;
        vector<int> orderOfExecution = b.orderOfExecution;
		
		Creature c = creatureList[0];
		int row = c.location[0];
		int col = c.location[1];
	
		CPPUNIT_ASSERT(creatureList.size() == 1);
		CPPUNIT_ASSERT(positionGrid[row][col] == 'f');
		CPPUNIT_ASSERT(IDGrid[row][col] == 1);
    }

	void test_board_print_1(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(1, 1, 1, listOfCreatureInfo, false);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.printRound(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0\n0 f\n\n");		
	}

	void test_board_print_2(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "1";//row
        listOfCreatureInfo[1][2] = "2";//column
        listOfCreatureInfo[1][3] = "s";//direction
        
        Board b(3, 3, 1, listOfCreatureInfo, false);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.printRound(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 f..\n1 ..h\n2 ...\n\n");		
	}

	void test_board_print_random(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(1, 1, 1, listOfCreatureInfo, true);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.printRound(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0\n0 f\n\n");		
	}

	void test_board_executeRounds_1(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction
        
        Board b(1, 1, 1, listOfCreatureInfo, false);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.executeRounds(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  0\n0 f\n\nTurn = 1.\n  0\n0 f\n\n");		
	}

	void test_board_executeRounds_2(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "1";//row
        listOfCreatureInfo[1][2] = "2";//column
        listOfCreatureInfo[1][3] = "s";//direction
        
        Board b(3, 3, 2, listOfCreatureInfo, false);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.executeRounds(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 f..\n1 ..h\n2 ...\n\nTurn = 1.\n  012\n0 f..\n1 ...\n2 ..h\n\nTurn = 2.\n  012\n0 f..\n1 ...\n2 ..h\n\n");		
	}

	void test_board_executeRounds_3(){
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "2";//row
        listOfCreatureInfo[0][2] = "2";//column
        listOfCreatureInfo[0][3] = "n";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";//species
        listOfCreatureInfo[1][1] = "1";//row
        listOfCreatureInfo[1][2] = "2";//column
        listOfCreatureInfo[1][3] = "s";//direction
        
        Board b(3, 3, 2, listOfCreatureInfo, false);

		istringstream r("Turn = 0.");
		ostringstream w;
		b.executeRounds(w);
		CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ..h\n2 ..t\n\nTurn = 1.\n  012\n0 ...\n1 ..t\n2 ..t\n\nTurn = 2.\n  012\n0 ...\n1 ..t\n2 ..t\n\n");		
	}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);

	//CPPUNIT_TEST(test_board_construct_1);
	CPPUNIT_TEST(test_creature_construct_1);
	CPPUNIT_TEST(test_creature_construct_2);
	CPPUNIT_TEST(test_creature_construct_3);

	CPPUNIT_TEST(test_creature_incrementCounter_1);
	CPPUNIT_TEST(test_creature_incrementCounter_2);
	CPPUNIT_TEST(test_creature_incrementCounter_3);
	CPPUNIT_TEST(test_creature_hop_1);
	CPPUNIT_TEST(test_creature_hop_2);
	CPPUNIT_TEST(test_creature_hop_3);
	CPPUNIT_TEST(test_creature_left_1);
	CPPUNIT_TEST(test_creature_left_2);
	CPPUNIT_TEST(test_creature_left_3);
	CPPUNIT_TEST(test_creature_right_1);
	CPPUNIT_TEST(test_creature_right_2);
	CPPUNIT_TEST(test_creature_right_3);
	CPPUNIT_TEST(test_creature_infect_1);
	CPPUNIT_TEST(test_creature_infect_2);
	CPPUNIT_TEST(test_creature_infect_3);
	CPPUNIT_TEST(test_creature_if_empty_1);
	CPPUNIT_TEST(test_creature_if_empty_2);
	CPPUNIT_TEST(test_creature_if_empty_3);
	CPPUNIT_TEST(test_creature_if_wall_1);
	CPPUNIT_TEST(test_creature_if_wall_2);
	CPPUNIT_TEST(test_creature_if_wall_3);
	CPPUNIT_TEST(test_creature_if_enemy_1);
	CPPUNIT_TEST(test_creature_if_enemy_2);
	CPPUNIT_TEST(test_creature_if_enemy_3);
	CPPUNIT_TEST(test_creature_go_1);
	CPPUNIT_TEST(test_creature_go_2);
	CPPUNIT_TEST(test_creature_go_3);
	CPPUNIT_TEST(test_creature_executeTurn_1);
	CPPUNIT_TEST(test_creature_executeTurn_2);
	CPPUNIT_TEST(test_creature_executeTurn_3);

	CPPUNIT_TEST(test_board_construct_1);
	CPPUNIT_TEST(test_board_construct_2);
	CPPUNIT_TEST(test_board_construct_random);
	CPPUNIT_TEST(test_board_print_1);
	CPPUNIT_TEST(test_board_print_2);
	CPPUNIT_TEST(test_board_print_random);
	CPPUNIT_TEST(test_board_executeRounds_1);
	CPPUNIT_TEST(test_board_executeRounds_2);
	CPPUNIT_TEST(test_board_executeRounds_3);

    CPPUNIT_TEST_SUITE_END();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

