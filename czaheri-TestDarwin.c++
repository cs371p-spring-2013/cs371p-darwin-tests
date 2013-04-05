
#define private public

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture {

	// Test species
	void test_species_instructionAt_1()
	{
		Food food;
		Species *species = &food;
		Instruction instruction = species->instructionAt(0);
		assert(instruction.id == leftID);
		assert(instruction.argument == NIL_ARGUMENT);
		assert(instruction.isAction == true);
	}

	void test_species_instructionAt_2()
	{
		Hopper hopper;
		Species *species = &hopper;
		Instruction instruction = species->instructionAt(0);
		assert(instruction.id == hopID);
		assert(instruction.argument == NIL_ARGUMENT);
		assert(instruction.isAction == true);
	}

	void test_species_instructionAt_3()
	{
		Trap trap;
		Species *species = &trap;
		Instruction instruction = species->instructionAt(0);
		assert(instruction.id == if_enemyID);
		assert(instruction.argument == 3);
		assert(instruction.isAction == false);
	}

	void test_species_speciesName_1()
	{
		Trap trap;
		Species *species = &trap;
		string name = species->speciesName();
		assert(name.compare("t") == 0);
	}

	void test_species_speciesName_2()
	{
		Food food;
		Species *species = &food;
		string name = species->speciesName();
		assert(name.compare("f") == 0);
	}

	void test_species_speciesName_3()
	{
		Rover rover;
		Species *species = &rover;
		string name = species->speciesName();
		assert(name.compare("r") == 0);
	}

	// Test Creature
	void test_creature_creature_1()
	{
		Creature creature;
		assert(creature.creatureName().compare("") == 0);
		assert(creature.species() == 0);
	}

	void test_creature_creature_2()
	{
		Rover rover;
		Species *species = &rover;
		Creature creature(species);
		assert(creature.creatureName().compare("r") == 0);
		assert(creature.species() == &rover);
	}

	void test_creature_creature_3()
	{
		Food food;
		Species *species = &food;
		Creature creature(species);
		assert(creature.creatureName().compare("f") == 0);
		assert(creature.species() == &food);;
	}

	void test_creature_infectWithSpecies_1()
	{
		Food food;
		Species *species = &food;
		Creature creature(species);
		Rover rover;
		creature.infectWithSpecies(&rover);
		assert(creature.creatureName().compare("r") == 0);
		assert(creature.species() == &rover);
	}

	void test_creature_infectWithSpecies_2()
	{
		Trap trap;
		Species *species = &trap;
		Creature creature(species);
		Hopper hopper;
		creature.infectWithSpecies(&hopper);
		assert(creature.creatureName().compare("h") == 0);
		assert(creature.species() == &hopper);
	}

	void test_creature_infectWithSpecies_3()
	{
		Rover rover;
		Species *species = &rover;
		Creature creature(species);
		Hopper hopper;
		creature.infectWithSpecies(&hopper);
		assert(creature.creatureName().compare("h") == 0);
		assert(creature.species() == &hopper);
	}

	void test_creature_species_1()
	{
		Rover rover;
		Creature creature(&rover);
		assert(creature.species() == &rover);
	}

	void test_creature_species_2()
	{
		Hopper hopper;
		Creature creature(&hopper);
		assert(creature.species() == &hopper);
	}

	void test_creature_species_3()
	{
		Food food;
		Creature creature(&food);
		assert(creature.species() == &food);
	}

	void test_creature_creatureName_1()
	{
		Rover rover;
		Creature creature(&rover);
		assert(creature.creatureName().compare("r") == 0);
	}

	void test_creature_creatureName_2()
	{
		Hopper hopper;
		Creature creature(&hopper);
		assert(creature.creatureName().compare("h") == 0);
	}

	void test_creature_creatureName_3()
	{
		Food food;
		Creature creature(&food);
		assert(creature.creatureName().compare("f") == 0);
	}

	void test_creature_currentInstruction_1()
	{
		Food food;
		Creature creature(&food);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == leftID);
		assert(currentInstruction.argument == NIL_ARGUMENT);
		assert(currentInstruction.isAction == true);
	}

	void test_creature_currentInstruction_2()
	{
		Rover rover;
		Creature creature(&rover);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == if_enemyID);
		assert(currentInstruction.argument == 9);
		assert(currentInstruction.isAction == false);
	}

	void test_creature_currentInstruction_3()
	{
		Trap trap;
		Creature creature(&trap);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == if_enemyID);
		assert(currentInstruction.argument == 3);
		assert(currentInstruction.isAction == false);
	}

	void test_creature_executeCurrentInstruction_1()
	{
		Food food;
		Creature creature(&food);
		creature.executeCurrentInstruction(true);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == goID);
		assert(currentInstruction.argument == 0);
		assert(currentInstruction.isAction == false);
	}

	void test_creature_executeCurrentInstruction_2()
	{
		Trap trap;
		Creature creature(&trap);
		creature.executeCurrentInstruction(false);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == leftID);
		assert(currentInstruction.argument == NIL_ARGUMENT);
		assert(currentInstruction.isAction == true);
	}

	void test_creature_executeCurrentInstruction_3()
	{
		Hopper hopper;
		Creature creature(&hopper);
		creature.executeCurrentInstruction(true);
		Instruction currentInstruction = creature.currentInstruction();
		assert(currentInstruction.id == goID);
		assert(currentInstruction.argument == 0);
		assert(currentInstruction.isAction == false);
	}

	// Test World
	void test_world_world_1()
	{
		World world;
		WorldSize size = world.size();
		assert(size.numRows == 0);
		assert(size.numColumns == 0);
	}

	void test_world_world_2()
	{
		World world(2, 3);
		WorldSize size = world.size();
		assert(size.numRows == 2);
		assert(size.numColumns == 3);
	}

	void test_world_world_3()
	{
		World world(5, 7);
		WorldSize size = world.size();
		assert(size.numRows == 5);
		assert(size.numColumns == 7);
	}

	void test_world_size_1()
	{
		World world;
		WorldSize size = world.size();
		assert(size.numRows == 0);
		assert(size.numColumns == 0);
	}

	void test_world_size_2()
	{
		World world(2, 3);
		WorldSize size = world.size();
		assert(size.numRows == 2);
		assert(size.numColumns == 3);
	}

	void test_world_size_3()
	{
		World world(5, 7);
		WorldSize size = world.size();
		assert(size.numRows == 5);
		assert(size.numColumns == 7);
	}

	void test_world_addCreature_1()
	{
		Food food;
		Creature creature(&food);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, North);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creature.creatureName().compare(creatureInfo.creature.creatureName()) == 0);
		assert(creatureInfo.direction == North);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_addCreature_2()
	{
		Hopper hopper;
		Creature creature(&hopper);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, South);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creature.creatureName().compare(creatureInfo.creature.creatureName()) == 0);
		assert(creatureInfo.direction == South);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_addCreature_3()
	{
		Rover rover;
		Creature creature(&rover);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, North);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creature.creatureName().compare(creatureInfo.creature.creatureName()) == 0);
		assert(creatureInfo.direction == North);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_creatureInfoAtCoordinate_1()
	{
		Food food;
		Creature creature(&food);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, North);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.creature.creatureName().compare(creature.creatureName()) == 0);
		assert(creatureInfo.direction == North);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_creatureInfoAtCoordinate_2()
	{
		Hopper hopper;
		Creature creature(&hopper);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, South);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.creature.creatureName().compare(creature.creatureName()) == 0);
		assert(creatureInfo.direction == South);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_creatureInfoAtCoordinate_3()
	{
		Rover rover;
		Creature creature(&rover);
		World world(3, 3);
		world.addCreature(creature, {0, 0}, North);
		CreatureInfo creatureInfo = world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.creature.creatureName().compare(creature.creatureName()) == 0);
		assert(creatureInfo.direction == North);
		assert(creatureInfo.lastTurnExecuted == 0);
	}

	void test_world_coodinateForForwardSpace_1()
	{
		World world(3, 4);
		WorldCoordinate forwardSpace = world.coordinateForForwardSpace({1, 0}, North);
		assert(forwardSpace.row == 0);
		assert(forwardSpace.column == 0);
	}

	void test_world_coodinateForForwardSpace_2()
	{
		World world(3, 4);
		WorldCoordinate forwardSpace = world.coordinateForForwardSpace({1, 1}, East);
		assert(forwardSpace.row == 1);
		assert(forwardSpace.column == 2);
	}

	void test_world_coodinateForForwardSpace_3()
	{
		World world(3, 4);
		WorldCoordinate forwardSpace = world.coordinateForForwardSpace({0, 1}, South);
		assert(forwardSpace.row == 1);
		assert(forwardSpace.column == 1);
	}

	void test_world_coordinateIsInWorld_1()
	{
		World world(3, 3);
		assert(world.coordinateIsInWorld({4, 4}) == false);
	}

	void test_world_coordinateIsInWorld_2()
	{
		World world(5, 3);
		assert(world.coordinateIsInWorld({4, 4}) == false);
	}

	void test_world_coordinateIsInWorld_3()
	{
		World world(6, 7);
		assert(world.coordinateIsInWorld({3, 4}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingEnemy_1()
	{
		Food food;
		Hopper hopper;
		Creature one(&food);
		Creature two(&hopper);
		World world(2, 2);
		world.addCreature(two, {0, 0}, East);
		world.addCreature(one, {0, 1}, North);
		assert(world.creatureAtCoordinateIsFacingEnemy({0, 0}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingEnemy_2()
	{
		Food food;
		Hopper hopper;
		Creature one(&food);
		Creature two(&hopper);
		World world(3, 3);
		world.addCreature(two, {1, 1}, South);
		world.addCreature(one, {2, 1}, North);
		assert(world.creatureAtCoordinateIsFacingEnemy({1, 1}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingEnemy_3()
	{
		Food food;
		Hopper hopper;
		Creature one(&food);
		Creature two(&hopper);
		World world(4, 4);
		world.addCreature(two, {0, 0}, North);
		world.addCreature(one, {0, 1}, North);
		assert(world.creatureAtCoordinateIsFacingEnemy({0, 0}) == false);
	}

	void test_world_creatureAtCoordinateIsFacingWall_1()
	{
		World world(1, 1);
		Food food;
		Creature creature(&food);
		world.addCreature(creature, {0, 0}, North);
		assert(world.creatureAtCoordinateIsFacingWall({0, 0}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingWall_2()
	{
		World world(4, 4);
		Food food;
		Creature creature(&food);
		world.addCreature(creature, {3, 3}, South);
		assert(world.creatureAtCoordinateIsFacingWall({3, 3}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingWall_3()
	{
		World world(5, 5);
		Food food;
		Creature creature(&food);
		world.addCreature(creature, {3, 2}, North);
		assert(world.creatureAtCoordinateIsFacingWall({3, 2}) == false);
	}

	void test_world_creatureAtCoordinateIsFacingEmptySpace_1()
	{
		World world(5, 5);
		Food food;
		Creature creature(&food);
		world.addCreature(creature, {3, 2}, North);
		assert(world.creatureAtCoordinateIsFacingEmptySpace({3, 2}) == true);
	}

	void test_world_creatureAtCoordinateIsFacingEmptySpace_2()
	{
		World world(1, 1);
		Food food;
		Creature creature(&food);
		world.addCreature(creature, {0, 0}, North);
		assert(world.creatureAtCoordinateIsFacingEmptySpace({0, 0}) == false);
	}

	void test_world_creatureAtCoordinateIsFacingEmptySpace_3()
	{
		World world(5, 5);
		Food food;
		Hopper hopper;
		Creature two(&hopper);
		Creature creature(&food);
		world.addCreature(creature, {3, 2}, North);
		world.addCreature(two, {2, 2}, South);
		assert(world.creatureAtCoordinateIsFacingEmptySpace({3, 2}) == false);
	}

	void test_world_print_1()
	{
		World world(1, 1);
		stringstream s;
		s << "  0\n0 .\n"; 
		ostringstream o;
		world.print(o);
		assert(s.str().compare(o.str()) == 0);
	}

	void test_world_print_2()
	{
		World world(1, 1);
		stringstream s;
		s << "  0\n0 .\n"; 
		ostringstream o;
		world.print(o);
		assert(s.str().compare(o.str()) == 0);
	}

	void test_world_print_3()
	{
		World world(1, 1);
		stringstream s;
		s << "  0\n0 .\n"; 
		ostringstream o;
		world.print(o);
		assert(s.str().compare(o.str()) == 0);
	}

	// Test Darwin
	void test_darwin_darwin_1()
	{
		Darwin darwin(3, 3, 3, cout, 1);
		assert(darwin._currentSimulationNum == 0);
		assert(darwin._numSimulations == 3);
		assert(darwin._printRule == 1);
	}

	void test_darwin_darwin_2()
	{
		Darwin darwin(3, 9, 6, cout, 4);
		assert(darwin._currentSimulationNum == 0);
		assert(darwin._numSimulations == 6);
		assert(darwin._printRule == 4);
	}

	void test_darwin_darwin_3()
	{
		Darwin darwin(5, 6, 4, cout, 2);
		assert(darwin._currentSimulationNum == 0);
		assert(darwin._numSimulations == 4);
		assert(darwin._printRule == 2);
	}

	void test_darwin_addCreatureToWorld_1()
	{
		Darwin darwin(5, 6, 4, cout, 2);
		darwin.addCreatureToWorld(Food_Type, {0, 0}, North);
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.creature.creatureName().compare("f") == 0); 
	}

	void test_darwin_addCreatureToWorld_2()
	{
		Darwin darwin(6, 6, 4, cout, 2);
		darwin.addCreatureToWorld(Hopper_Type, {1, 1}, North);
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({1, 1});
		assert(creatureInfo.creature.creatureName().compare("h") == 0); 
	}

	void test_darwin_addCreatureToWorld_3()
	{
		Darwin darwin(5, 6, 4, cout, 2);
		darwin.addCreatureToWorld(Rover_Type, {2, 2}, North);
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({2, 2});
		assert(creatureInfo.creature.creatureName().compare("r") == 0); 
	}

	void test_darwin_runSimulations_1() 
	{
		stringstream o;
		Darwin darwin(1, 1, 1, o, 1);
		darwin.addCreatureToWorld(Food_Type, {0, 0}, North);
		darwin.runSimulations();
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.direction == West);
	}

	void test_darwin_runSimulations_2() 
	{
		stringstream o;
		Darwin darwin(1, 2, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, East);
		darwin.runSimulations();
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		assert(creatureInfo.creature.creatureName().compare("h") == 0);
	}

	void test_darwin_runSimulations_3() 
	{
		stringstream o;
		Darwin darwin(1, 1, 1, o, 1);
		darwin.addCreatureToWorld(Trap_Type, {0, 0}, North);
		darwin.runSimulations();
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.creature.creatureName().compare("t") == 0);
		assert(creatureInfo.direction == West);
	}

	void test_darwin_executeCreatureProgramAtCoordinate_1()
	{
		stringstream o;
		Darwin darwin(1, 1, 1, o, 1);
		darwin.addCreatureToWorld(Trap_Type, {0, 0}, North);
		darwin.executeCreatureProgramAtCoordinate({0, 0});
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.direction == West);
	}

	void test_darwin_executeCreatureProgramAtCoordinate_2()
	{
		stringstream o;
		Darwin darwin(1, 1, 1, o, 1);
		darwin.addCreatureToWorld(Food_Type, {0, 0}, North);
		darwin.executeCreatureProgramAtCoordinate({0, 0});
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(creatureInfo.direction == West);
	}

	void test_darwin_executeCreatureProgramAtCoordinate_3()
	{
		
		stringstream o;
		Darwin darwin(1, 2, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, East);
		darwin.executeCreatureProgramAtCoordinate({0, 0});
		CreatureInfo creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		assert(creatureInfo.creature.creatureName().compare("h") == 0);
	}

	void test_darwin_executeHopInstruction_1()
	{
		stringstream o;
		Darwin darwin(1, 2, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, East);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeHopInstruction(creatureInfo, {0, 0});
		CreatureInfo newCreatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		assert(newCreatureInfo.creature.creatureName().compare("h") == 0);
	}

	void test_darwin_executeHopInstruction_2()
	{
		stringstream o;
		Darwin darwin(2, 2, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 1}, West);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		darwin.executeHopInstruction(creatureInfo, {0, 1});
		CreatureInfo newCreatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		assert(newCreatureInfo.creature.creatureName().compare("h") == 0);
	}

	void test_darwin_executeHopInstruction_3()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, South);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeHopInstruction(creatureInfo, {0, 0});
		CreatureInfo newCreatureInfo = darwin._world.creatureInfoAtCoordinate({1, 0});
		assert(newCreatureInfo.creature.creatureName().compare("h") == 0);
	}

	void test_darwin_executeLeftInstruction_1()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, North);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeLeftInstruction(creatureInfo);
		assert(creatureInfo.direction == West);
	}

	void test_darwin_executeLeftInstruction_2()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, East);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeLeftInstruction(creatureInfo);
		assert(creatureInfo.direction == North);
	}

	void test_darwin_executeLeftInstruction_3()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, South);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeLeftInstruction(creatureInfo);
		assert(creatureInfo.direction == East);
	}

		void test_darwin_executeRightInstruction_1()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, North);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeRightInstruction(creatureInfo);
		assert(creatureInfo.direction == East);
	}

	void test_darwin_executeRightInstruction_2()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, East);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeRightInstruction(creatureInfo);
		assert(creatureInfo.direction == South);
	}

	void test_darwin_executeRightInstruction_3()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Hopper_Type, {0, 0}, South);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeRightInstruction(creatureInfo);
		assert(creatureInfo.direction == West);
	}

	void test_darwin_executeInfectInstruction_1()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Food_Type, {0, 1}, South);
		darwin.addCreatureToWorld(Rover_Type, {0, 0}, East);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeInfectInstruction(creatureInfo, {0, 0});
		CreatureInfo enemyCreatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		assert(enemyCreatureInfo.creature.creatureName().compare("r") == 0);
	}

	void test_darwin_executeInfectInstruction_2()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Food_Type, {1, 0}, South);
		darwin.addCreatureToWorld(Rover_Type, {0, 0}, South);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeInfectInstruction(creatureInfo, {0, 0});
		CreatureInfo enemyCreatureInfo = darwin._world.creatureInfoAtCoordinate({1, 0});
		assert(enemyCreatureInfo.creature.creatureName().compare("r") == 0);
	}

	void test_darwin_executeInfectInstruction_3()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Food_Type, {0, 1}, South);
		darwin.addCreatureToWorld(Trap_Type, {0, 0}, East);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeInfectInstruction(creatureInfo, {0, 0});
		CreatureInfo enemyCreatureInfo = darwin._world.creatureInfoAtCoordinate({0, 1});
		assert(enemyCreatureInfo.creature.creatureName().compare("t") == 0);
	}

	void test_darwin_executeControlInstruction_1()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Rover_Type, {0, 0}, South);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeControlInstruction(creatureInfo, {0, 0});
		assert(creatureInfo.creature._programCounter == 1);
	}

	void test_darwin_executeControlInstruction_2()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Rover_Type, {0, 0}, East);
		darwin.addCreatureToWorld(Food_Type, {0, 1}, North);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeControlInstruction(creatureInfo, {0, 0});
		assert(creatureInfo.creature._programCounter == 9);
	}

	void test_darwin_executeControlInstruction_3()
	{
		stringstream o;
		Darwin darwin(3, 3, 1, o, 1);
		darwin.addCreatureToWorld(Trap_Type, {0, 0}, East);
		darwin.addCreatureToWorld(Food_Type, {0, 1}, North);
		CreatureInfo& creatureInfo = darwin._world.creatureInfoAtCoordinate({0, 0});
		darwin.executeControlInstruction(creatureInfo, {0, 0});
		assert(creatureInfo.creature._programCounter == 3);
	}


	CPPUNIT_TEST_SUITE(TestDarwin);

	// Species
	CPPUNIT_TEST(test_species_instructionAt_1);
	CPPUNIT_TEST(test_species_instructionAt_2);
	CPPUNIT_TEST(test_species_instructionAt_3);

	CPPUNIT_TEST(test_species_speciesName_1);
	CPPUNIT_TEST(test_species_speciesName_2);
	CPPUNIT_TEST(test_species_speciesName_3);

	//Creature
	CPPUNIT_TEST(test_creature_creature_1);
	CPPUNIT_TEST(test_creature_creature_2);
	CPPUNIT_TEST(test_creature_creature_3);

	CPPUNIT_TEST(test_creature_infectWithSpecies_1);
	CPPUNIT_TEST(test_creature_infectWithSpecies_2);
	CPPUNIT_TEST(test_creature_infectWithSpecies_3);

	CPPUNIT_TEST(test_creature_species_1);
	CPPUNIT_TEST(test_creature_species_2);
	CPPUNIT_TEST(test_creature_species_3);

	CPPUNIT_TEST(test_creature_creatureName_1);
	CPPUNIT_TEST(test_creature_creatureName_2);
	CPPUNIT_TEST(test_creature_creatureName_3);

	CPPUNIT_TEST(test_creature_currentInstruction_1);
	CPPUNIT_TEST(test_creature_currentInstruction_2);
	CPPUNIT_TEST(test_creature_currentInstruction_3);

	CPPUNIT_TEST(test_creature_executeCurrentInstruction_1);
	CPPUNIT_TEST(test_creature_executeCurrentInstruction_2);
	CPPUNIT_TEST(test_creature_executeCurrentInstruction_3);

	// World
	CPPUNIT_TEST(test_world_world_1);
	CPPUNIT_TEST(test_world_world_2);
	CPPUNIT_TEST(test_world_world_3);

	CPPUNIT_TEST(test_world_size_1);
	CPPUNIT_TEST(test_world_size_2);
	CPPUNIT_TEST(test_world_size_3);

	CPPUNIT_TEST(test_world_addCreature_1);
	CPPUNIT_TEST(test_world_addCreature_2);
	CPPUNIT_TEST(test_world_addCreature_3);

	CPPUNIT_TEST(test_world_creatureInfoAtCoordinate_1);
	CPPUNIT_TEST(test_world_creatureInfoAtCoordinate_2);
	CPPUNIT_TEST(test_world_creatureInfoAtCoordinate_3);

	CPPUNIT_TEST(test_world_coodinateForForwardSpace_1);
	CPPUNIT_TEST(test_world_coodinateForForwardSpace_2);
	CPPUNIT_TEST(test_world_coodinateForForwardSpace_3);

	CPPUNIT_TEST(test_world_coordinateIsInWorld_1);
	CPPUNIT_TEST(test_world_coordinateIsInWorld_2);
	CPPUNIT_TEST(test_world_coordinateIsInWorld_3);

	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEnemy_1);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEnemy_2);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEnemy_3);

	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingWall_1);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingWall_2);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingWall_3);

	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEmptySpace_1);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEmptySpace_2);
	CPPUNIT_TEST(test_world_creatureAtCoordinateIsFacingEmptySpace_3);

	CPPUNIT_TEST(test_world_print_1);
	CPPUNIT_TEST(test_world_print_2);
	CPPUNIT_TEST(test_world_print_3);

	// Darwin
	CPPUNIT_TEST(test_darwin_darwin_1);
	CPPUNIT_TEST(test_darwin_darwin_2);
	CPPUNIT_TEST(test_darwin_darwin_3);

	CPPUNIT_TEST(test_darwin_addCreatureToWorld_1);
	CPPUNIT_TEST(test_darwin_addCreatureToWorld_2);
	CPPUNIT_TEST(test_darwin_addCreatureToWorld_3);

	CPPUNIT_TEST(test_darwin_runSimulations_1);
	CPPUNIT_TEST(test_darwin_runSimulations_2);
	CPPUNIT_TEST(test_darwin_runSimulations_3);

	CPPUNIT_TEST(test_darwin_executeCreatureProgramAtCoordinate_1);
	CPPUNIT_TEST(test_darwin_executeCreatureProgramAtCoordinate_2);
	CPPUNIT_TEST(test_darwin_executeCreatureProgramAtCoordinate_3);

	CPPUNIT_TEST(test_darwin_executeHopInstruction_1);
	CPPUNIT_TEST(test_darwin_executeHopInstruction_2);
	CPPUNIT_TEST(test_darwin_executeHopInstruction_3);

	CPPUNIT_TEST(test_darwin_executeLeftInstruction_1);
	CPPUNIT_TEST(test_darwin_executeLeftInstruction_2);
	CPPUNIT_TEST(test_darwin_executeLeftInstruction_3);

	CPPUNIT_TEST(test_darwin_executeRightInstruction_1);
	CPPUNIT_TEST(test_darwin_executeRightInstruction_2);
	CPPUNIT_TEST(test_darwin_executeRightInstruction_3);

	CPPUNIT_TEST(test_darwin_executeInfectInstruction_1);
	CPPUNIT_TEST(test_darwin_executeInfectInstruction_2);
	CPPUNIT_TEST(test_darwin_executeInfectInstruction_3);

	CPPUNIT_TEST(test_darwin_executeControlInstruction_1);
	CPPUNIT_TEST(test_darwin_executeControlInstruction_2);
	CPPUNIT_TEST(test_darwin_executeControlInstruction_3);

	CPPUNIT_TEST_SUITE_END();};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}