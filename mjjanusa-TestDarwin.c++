/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Voting.c++ TestVoting.c++ -o TestVoting.c++.app
    % valgrind TestVoting.c++.app >& TestVoting.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <vector>
#include <map>

#include <algorithm>
#include <iostream>

#include <string> //string
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"

// -----------
// Test
// -----------

struct TestDarwin: CppUnit::TestFixture {
	 
	// ----
	// Species Class Tests
	// ----
	 	
	 	// ----
	 	// Species Constructor 
	 	// ----
		void test_species_construct1 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() == std::string("f"));
			CPPUNIT_ASSERT(foodSpecies.get_instruction(0) == std::string("left"));
		}
		
		void test_species_construct2 () {
			std::string foodProgram [2] = {"right", "if_wall 9"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() == std::string("h"));
			CPPUNIT_ASSERT(foodSpecies.get_instruction(1) == std::string("if_wall 9"));
		}
		
		void test_species_construct3 () {
			std::string foodProgram [3] = {"left", "go 3", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("b"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() == std::string("b"));
			CPPUNIT_ASSERT(foodSpecies.get_instruction(2) == std::string("go 0"));
		}
		
		
		// ----
	 	// get_name 
	 	// ----
		void test_species_name1 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() == std::string("f"));
		}
		void test_species_name2 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("food"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() == std::string("food"));
		}
		void test_species_name3 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_name() != std::string("f"));
		}
	
		// ----
	 	// get_instruction 
	 	// ----
		void test_species_instruction1 () {
			std::string foodProgram [3] = {"left", "go 0", "if_wall 3"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("food"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_instruction(0) == std::string("left"));
		}
		void test_species_instruction2 () {
			std::string foodProgram [3] = {"left", "go 0", "if_wall 3"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("food"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_instruction(1) == std::string("go 0"));
		}
		void test_species_instruction3 () {
			std::string foodProgram [3] = {"left", "go 0", "if_wall 3"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("food"); 
			species foodSpecies(name, foodProgram_v);  		
			CPPUNIT_ASSERT(foodSpecies.get_instruction(2) == std::string("if_wall 3"));
		}
		


	// ----
	// Game Class Tests 
	// ----
		
		// ----
		// Game Constructor 
		// ----
		void test_game_construct1(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}

		void test_game_construct2(){
			int w, h;
			w = 100;
			h = 100;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}
		void test_game_construct3(){

			int w, h;
			w = 1;
			h = 1;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}

		// ----
		// Game addCreature 
		// ----
		void test_game_addCreature1(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}

		void test_game_addCreature2(){
			int w, h;
			w = 100;
			h = 100;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}
		void test_game_addCreature3(){

			int w, h;
			w = 1;
			h = 1;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(!world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h) );
		}

		// ----
		// Game ifWall 
		// ----
		void test_game_ifWall1(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(world.ifWall(0, 0));
			assert(world.ifWall(3, 0));
		}

		void test_game_ifWall2(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(world.ifWall(1, 35));
			assert(world.ifWall(2, 35));
		}
		void test_game_ifWall3(){

			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			assert(world.ifWall(0, 5));
			assert(world.ifWall(1, 5));
		}

		// ----
		// Game move 
		// ----
		void test_game_move1(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h);
			assert(world.move(0, 10));
			assert(world.move(3, 20));
		}

		void test_game_move2(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h);
			assert(world.move(1, 35));
			assert(world.move(2, 35));
		}
		void test_game_move3(){

			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			world.addCreature(SpeciesTable.find(std::string("t"))->second, 0, w, h);
			assert(world.move(3, 23));
			assert(world.move(1, 4));
		}

		// ----
		// Game ifRandom 
		// ----
		void test_game_ifRandom1(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			bool isRand = world.ifRandom();
			assert(!isRand||isRand); //excluded middlulz, not really.
		}

		void test_game_ifRandom2(){
			int w, h;
			w = 36;
			h = 36;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			bool isRand = world.ifRandom();
			assert(!isRand||isRand); //deterministic of size? nope.
		}

		void test_game_ifRandom3(){
			int w, h;
			w = 6;
			h = 6;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			bool isRand = world.ifRandom();
			assert(!isRand||isRand); 
		}

		// ----
		// Game step 
		// ----

		void test_game_step1 (){
			std::string foodProgram [2] = {"hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == false);
		}

		void test_game_step2 (){
			std::string foodProgram [2] = {"hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == false);
		}

		void test_game_step3 (){
			std::string foodProgram [2] = {"hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == false);
		}

		// ----
		// Game sortBoard
		// ----
		
		void test_game_sortBoard1(){
			using namespace std;
			ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
				map<std::string, species> SpeciesTable;
			string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			string bestProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","left",	"go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> bestProgram_v(std::begin(bestProgram), std::end(bestProgram));
			string trapProgram [5] = {"if_enemy 3", "left", "go 0", "infect", "go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( pair<string, species>( string("f"), species( string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("h"), species( string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("r"), species( string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("b"), species( string("b"), bestProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("t"), species( string("t"), trapProgram_v ) ) );
			game world( 8, 8, SpeciesTable );
			world.addCreature(SpeciesTable.find(string("f"))->second, 1, 0, 0);
			world.addCreature(SpeciesTable.find(string("h"))->second, 0, 3, 3);
			world.addCreature(SpeciesTable.find(string("h"))->second, 1, 4, 3);
			world.addCreature(SpeciesTable.find(string("h"))->second, 2, 4, 4);
			world.addCreature(SpeciesTable.find(string("h"))->second, 3, 3, 4);
			world.addCreature(SpeciesTable.find(string("f"))->second, 0, 7, 7);
			world.sortBoard();
			assert(world.getCreature(0).speciesName().compare("f") == 0);
		}

		void test_game_sortBoard2(){
			using namespace std;
			ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
				map<std::string, species> SpeciesTable;
			string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			string bestProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","left",	"go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> bestProgram_v(std::begin(bestProgram), std::end(bestProgram));
			string trapProgram [5] = {"if_enemy 3", "left", "go 0", "infect", "go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( pair<string, species>( string("f"), species( string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("h"), species( string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("r"), species( string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("b"), species( string("b"), bestProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("t"), species( string("t"), trapProgram_v ) ) );
			game world( 8, 8, SpeciesTable );
			world.addCreature(SpeciesTable.find(string("f"))->second, 1, 4, 0);
			world.addCreature(SpeciesTable.find(string("h"))->second, 0, 0, 0);
			world.addCreature(SpeciesTable.find(string("h"))->second, 1, 4, 3);
			world.addCreature(SpeciesTable.find(string("h"))->second, 2, 4, 4);
			world.addCreature(SpeciesTable.find(string("h"))->second, 3, 3, 4);
			world.addCreature(SpeciesTable.find(string("f"))->second, 0, 7, 7);
			world.sortBoard();
			assert(world.getCreature(0).speciesName().compare("h") == 0);
		}

		void test_game_sortBoard3(){
			using namespace std;
			ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
				map<std::string, species> SpeciesTable;
			string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			string bestProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","left",	"go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> bestProgram_v(std::begin(bestProgram), std::end(bestProgram));
			string trapProgram [5] = {"if_enemy 3", "left", "go 0", "infect", "go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( pair<string, species>( string("f"), species( string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("h"), species( string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("r"), species( string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("b"), species( string("b"), bestProgram_v ) ) );
			SpeciesTable.insert( pair<string, species>( string("t"), species( string("t"), trapProgram_v ) ) );
			game world( 8, 8, SpeciesTable );
			world.addCreature(SpeciesTable.find(string("h"))->second, 3, 5);
			world.addCreature(SpeciesTable.find(string("h"))->second, 0, 19);
			world.addCreature(SpeciesTable.find(string("h"))->second, 1, 22);
			world.addCreature(SpeciesTable.find(string("h"))->second, 2, 33);
			world.addCreature(SpeciesTable.find(string("h"))->second, 3, 44);
			world.addCreature(SpeciesTable.find(string("f"))->second, 0, 55);
			world.sortBoard();
			assert(world.getCreature(55).speciesName().compare("f") == 0);
		}


		// ----
		// Game getCreature
		// ----

		void test_game_getCreature1(){
			int w, h;
			w = 8;
			h = 8;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 3, 0);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 0, 19);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 1, 30);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 2, 5);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 3, 8);
			world.addCreature(SpeciesTable.find(std::string("f"))->second, 0, 54);
			assert(world.getCreature(19).speciesName().compare("h") == 0);
		}
		void test_game_getCreature2(){
			int w, h;
			w = 8;
			h = 8;
			std::map<std::string, species> SpeciesTable;
			std::string foodProgram [2] = {"left","go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string hopperProgram [2] = {"hop","go 0"};
			std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
			std::string roverProgram [11] = {"if_enemy 9","if_empty 7","if_random 5","left","go 0","right","go 0","hop","go 0","infect","go 0"};
			std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
			std::string trapProgram [5] = {"if_enemy 3","left","go 0","infect","go 0"};
			std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
			SpeciesTable.insert( std::pair<std::string, species>( std::string("f"), species( std::string("f"), foodProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"), species( std::string("h"), hopperProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("r"), species( std::string("r"), roverProgram_v ) ) );
			SpeciesTable.insert( std::pair<std::string, species>( std::string("t"), species( std::string("t"), trapProgram_v ) ) );
			game world( w, h, SpeciesTable );
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 3, 0);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 0, 1);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 1, 4);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 2, 3);
			world.addCreature(SpeciesTable.find(std::string("h"))->second, 3, 13);
			world.addCreature(SpeciesTable.find(std::string("f"))->second, 0, 2);
			assert(world.getCreature(4).speciesName().compare("h") == 0);
		}
		
	// ----
	// Creature
	// ----
		
		// ----
		// Creature constructor
		// ----

		void test_creature_constructor1 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);
			creature myCreature(foodSpecies, 2, 15); 
			CPPUNIT_ASSERT(myCreature.isAt(15) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == true);
		}
		void test_creature_constructor2 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856); 
			CPPUNIT_ASSERT(myCreature.isAt(856) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
		}
		void test_creature_constructor3 () {
			creature myCreature; 
			CPPUNIT_ASSERT(myCreature.isAt(-1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == true);
		}
		
		// ----
		// Creature Copy Assignment  
		// ----
		void test_creature_copy1 () {
			creature myCreature;
			creature myCreature2 = myCreature;
			CPPUNIT_ASSERT(myCreature2.isAt(-1) == true);
			CPPUNIT_ASSERT(myCreature2.isNull() == true);
			CPPUNIT_ASSERT(&myCreature2 != &myCreature);
		}
		void test_creature_copy2 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			creature myCreature2 = myCreature; 
			CPPUNIT_ASSERT(myCreature2.isAt(856) == true);
			CPPUNIT_ASSERT(myCreature2.isNull() == false);
			CPPUNIT_ASSERT(&myCreature2 != &myCreature);
		}
		void test_creature_copy3 () {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f"); 
			species foodSpecies(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 8486);
			creature myCreature2 = myCreature; 
			CPPUNIT_ASSERT(myCreature2.isAt(8486) == true);
			CPPUNIT_ASSERT(myCreature2.isNull() == false);
			CPPUNIT_ASSERT(&myCreature2 != &myCreature);
		}
		
		// ----
		// Execute Turn  
		// ----
		void test_creature_turn1() {
			std::string foodProgram [2] = {"hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == false);
		}
		void test_creature_turn2() {
			std::string foodProgram [2] = {"right", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(0) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == false);
		}
		void test_creature_turn3() {
			std::string foodProgram [4] = {"if_wall 2", "hop", "right", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 0, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(0) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == false);
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(world.getCreature(0).isNull() == true);
			CPPUNIT_ASSERT(world.getCreature(1).isNull() == false);
		}

		
		// ----
		// Reset Species  
		// ----		
		void test_creature_reset1() {
			std::string foodProgram [2] = {"left", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856); 
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
			myCreature.resetSpecies(foodSpecies2); 
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == false);
		}
		void test_creature_reset2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 1, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(0) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(SpeciesTable.find("h")->second) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
			myCreature.resetSpecies(foodSpecies2);
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(0) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(SpeciesTable.find("h")->second) == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == true);
		}
		void test_creature_reset3() {
			std::string foodProgram [2] = {"right", "go 0"};
			std::string foodProgram2 [3] = {"hop", "right", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::vector<std::string> foodProgram2_v(std::begin(foodProgram2), std::end(foodProgram2));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram2_v);
			std::map<std::string, species> SpeciesTable;
			SpeciesTable.insert( std::pair<std::string, species>( std::string("h"),  foodSpecies) );; 
			game world(3, 3, SpeciesTable); 
			world.addCreature(SpeciesTable.find("h")->second, 0, 0, 0); 
			creature myCreature = world.getCreature(0); 
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(0) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(SpeciesTable.find("h")->second) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
			myCreature.resetSpecies(foodSpecies2);
			myCreature.executeTurn(&world);
			CPPUNIT_ASSERT(myCreature.isAt(1) == true);
			CPPUNIT_ASSERT(myCreature.isNull() == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(SpeciesTable.find("h")->second) == false);
		}
		
		// ----
		// Is Friend  
		// ----		
		void test_creature_friend1() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);  
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
		}
		void test_creature_friend2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies2, 3, 45);  
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == true);
		}
		void test_creature_friend3() {
			std::string foodProgram [2] = {"right", "go 0"};
			std::string foodProgram2 [3] = {"hop", "right", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::vector<std::string> foodProgram2_v(std::begin(foodProgram2), std::end(foodProgram2));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram2_v);
			creature myCreature(foodSpecies, 1, 856);  
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == true);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == false);
			myCreature.resetSpecies(foodSpecies2);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies) == false);
			CPPUNIT_ASSERT(myCreature.isFriend(foodSpecies2) == true);
		}
		
		// ----
		// Less than operator  
		// ----		
		void test_creature_less1() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			creature myCreature2(foodSpecies2, 1, 1000);
			CPPUNIT_ASSERT(myCreature < myCreature2);
		}
		void test_creature_less2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 46);
			creature myCreature2(foodSpecies2, 3, 45);
			CPPUNIT_ASSERT(!(myCreature < myCreature2));
		}
		void test_creature_less3() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 46);
			creature myCreature2(foodSpecies2, 3, 45);
			CPPUNIT_ASSERT(myCreature2 < myCreature);
		}
		
		// ----
		// Is At  
		// ----	
		void test_creature_at1() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			CPPUNIT_ASSERT(myCreature.isAt(856));
			
		}
		void test_creature_at2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies, 3, 31);
			CPPUNIT_ASSERT(myCreature.isAt(31));
			
		}
		void test_creature_at3() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h"); 
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name, foodProgram_v);
			creature myCreature(foodSpecies2, 2, 500);
			CPPUNIT_ASSERT(myCreature.isAt(500));
			
		}
		
		// ----
		// Species Name  
		// ----	
		void test_creature_name1() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			CPPUNIT_ASSERT(myCreature.speciesName() == std::string("h"));
		}
		void test_creature_name2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature(foodSpecies2, 1, 856);
			CPPUNIT_ASSERT(myCreature.speciesName() == std::string("f"));
		}
		void test_creature_name3() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			CPPUNIT_ASSERT(myCreature.speciesName() == std::string("h"));
			myCreature.resetSpecies(foodSpecies2);
			CPPUNIT_ASSERT(myCreature.speciesName() == std::string("f"));
		}
		
		// ----
		// Is Null Test  
		// ----	
		void test_creature_null1() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature(foodSpecies, 1, 856);
			CPPUNIT_ASSERT(!myCreature.isNull());
		}
		void test_creature_null2() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature;
			CPPUNIT_ASSERT(myCreature.isNull());
		}
		void test_creature_null3() {
			std::string foodProgram [3] = {"right", "hop", "go 0"};
			std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
			std::string name = std::string("h");
			std::string name2 = std::string("f");
			species foodSpecies(name, foodProgram_v);
			species foodSpecies2(name2, foodProgram_v);
			creature myCreature;
			CPPUNIT_ASSERT(myCreature.isNull());
			creature myCreature2(foodSpecies, 1, 856);
			myCreature = myCreature2;
			CPPUNIT_ASSERT(!myCreature.isNull());
		}
		
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_species_construct1);
    CPPUNIT_TEST(test_species_construct2);
    CPPUNIT_TEST(test_species_construct3);
    CPPUNIT_TEST(test_species_name1);
    CPPUNIT_TEST(test_species_name2);
    CPPUNIT_TEST(test_species_name3);
    CPPUNIT_TEST(test_species_instruction1);
    CPPUNIT_TEST(test_species_instruction2);
    CPPUNIT_TEST(test_species_instruction3);

    CPPUNIT_TEST(test_creature_constructor1);
    CPPUNIT_TEST(test_creature_constructor2);
    CPPUNIT_TEST(test_creature_constructor3);
    CPPUNIT_TEST(test_creature_copy1);
    CPPUNIT_TEST(test_creature_copy2);
    CPPUNIT_TEST(test_creature_copy3);
    CPPUNIT_TEST(test_creature_turn1);
    CPPUNIT_TEST(test_creature_turn2);
    CPPUNIT_TEST(test_creature_turn3);
    CPPUNIT_TEST(test_creature_reset1);
    CPPUNIT_TEST(test_creature_reset2);
    CPPUNIT_TEST(test_creature_reset3);
    CPPUNIT_TEST(test_creature_friend1);
    CPPUNIT_TEST(test_creature_friend2);
    CPPUNIT_TEST(test_creature_friend3);
    CPPUNIT_TEST(test_creature_less1);
    CPPUNIT_TEST(test_creature_less2);
    CPPUNIT_TEST(test_creature_less3);
    CPPUNIT_TEST(test_creature_at1);
    CPPUNIT_TEST(test_creature_at2);
    CPPUNIT_TEST(test_creature_at3);
    CPPUNIT_TEST(test_creature_name1);
    CPPUNIT_TEST(test_creature_name2);
    CPPUNIT_TEST(test_creature_name3);
    CPPUNIT_TEST(test_creature_null1);
    CPPUNIT_TEST(test_creature_null2);
    CPPUNIT_TEST(test_creature_null3);

	CPPUNIT_TEST(test_game_construct1);
	CPPUNIT_TEST(test_game_construct2);
	CPPUNIT_TEST(test_game_construct3);
	CPPUNIT_TEST(test_game_addCreature1);
	CPPUNIT_TEST(test_game_addCreature2);
	CPPUNIT_TEST(test_game_addCreature3);
	CPPUNIT_TEST(test_game_ifWall1);
	CPPUNIT_TEST(test_game_ifWall2);
	CPPUNIT_TEST(test_game_ifWall3);
	CPPUNIT_TEST(test_game_move1);
	CPPUNIT_TEST(test_game_move2);
	CPPUNIT_TEST(test_game_move3);
	CPPUNIT_TEST(test_game_ifRandom1);
	CPPUNIT_TEST(test_game_ifRandom2);
	CPPUNIT_TEST(test_game_ifRandom3);
	CPPUNIT_TEST(test_game_step1);
	CPPUNIT_TEST(test_game_step2);
	CPPUNIT_TEST(test_game_step3);
	CPPUNIT_TEST(test_game_sortBoard1);
	CPPUNIT_TEST(test_game_sortBoard2);
	CPPUNIT_TEST(test_game_sortBoard3);
	CPPUNIT_TEST(test_game_getCreature1);
	CPPUNIT_TEST(test_game_getCreature2);

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
