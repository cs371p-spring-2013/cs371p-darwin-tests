
// --------
// includes
// --------

#include <algorithm> //count
#include <iostream> // ios_base
#include <memory> //allocator
#include <sstream> //string stream
#include <stdexcept> //exceptions

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner



#define protected public
#define private public

#include "Darwin.h"

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {
    void testInstructionsGetInstrucSet() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        CPPUNIT_ASSERT(result[0].compare(testInstructs[0]) == 0);
    }
    
    void testInstructionsGetInstrucSet2() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        testInstructs.push_back("test2");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        CPPUNIT_ASSERT(result[1].compare(testInstructs[1]) == 0);
    }
    
    void testInstructionsGetInstrucSet3() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreatur");
        CPPUNIT_ASSERT(result[0].compare("empty") == 0);
    }
    
    void testInstructionsAddSet() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        testInstructs.push_back("test2");
        inst.addSet("testCreature2", testInstructs);
        CPPUNIT_ASSERT(inst.instructionSets.size() == 2);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 1);
        std::vector<std::string> result = inst.getInstrucSet("testCreature2");
        CPPUNIT_ASSERT(result[1].compare("test2") == 0);
    }
    
    void testInstructionsAddSet2() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        CPPUNIT_ASSERT(inst.instructionSets.size() == 1);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 1);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        CPPUNIT_ASSERT(result[0].compare("test1") == 0);
    }
    
    void testInstructionsAddSet3() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        testInstructs.push_back("test2");
        inst.addSet("testCreature", testInstructs);
        CPPUNIT_ASSERT(inst.instructionSets.size() == 1);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 1);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        CPPUNIT_ASSERT(result[1].compare(testInstructs[1]) == 0);
    }
    
    void testInstructionsDeleteSet() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        inst.deleteSet("testCreature");
        CPPUNIT_ASSERT(inst.instructionSets.size() == 0);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 0);
    }
    
    void testInstructionsDeleteSet2() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("test1");
        inst.addSet("testCreature", testInstructs);
        testInstructs.push_back("test2");
        inst.addSet("testCreature2", testInstructs);
        inst.deleteSet("testCreature");
        CPPUNIT_ASSERT(inst.instructionSets.size() == 1);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 0);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature2") == 1);
    }
    
    void testInstructionsDeleteSet3() {
        Instructions inst;
        inst.deleteSet("testCreature");
        CPPUNIT_ASSERT(inst.instructionSets.size() == 0);
        CPPUNIT_ASSERT(inst.instructionSets.count("testCreature") == 0);
    }
    
    void testSpeciesIsAction() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("hop");
        testInstructs.push_back("left");
        testInstructs.push_back("right");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(x.isAction(result[0]));
        CPPUNIT_ASSERT(x.isAction(result[1]));
        CPPUNIT_ASSERT(x.isAction(result[2]));
    }
    
    void testSpeciesIsAction2() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("go 0");
        testInstructs.push_back("if_wall 0");
        testInstructs.push_back("if_empty 0");
        testInstructs.push_back("if_enemy 0");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(!x.isAction(result[0]));
        CPPUNIT_ASSERT(!x.isAction(result[1]));
        CPPUNIT_ASSERT(!x.isAction(result[2]));
        CPPUNIT_ASSERT(!x.isAction(result[3]));
    }
    
    void testSpeciesIsAction3() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("");
        testInstructs.push_back("infect");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(!x.isAction(result[0]));
        CPPUNIT_ASSERT(x.isAction(result[1]));
    }
    
    void testSpeciesDefConstructor() {
        Species x;
        CPPUNIT_ASSERT(x.getName() == '.');
    }
    
    void testSpeciesNormConstructor() {
        addCreatures();
        Species x = Species("food");
        CPPUNIT_ASSERT(x.getName() == 'f');
        CPPUNIT_ASSERT(x.instructions[0].compare("left") == 0);
    }
    
    void testSpeciesDebugConstructor() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back(" ");
        testInstructs.push_back("infect");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(x.getName() == 't');
        CPPUNIT_ASSERT(x.instructions[0].compare(" ") == 0);
    }
    
    void testSpeciesGetName() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("infect");
        inst.addSet("testCreature", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(x.getName() == 't');
    }
    
    void testSpeciesGetName2() {
        Species x = Species();
        CPPUNIT_ASSERT(x.getName() == '.');
    }
    
    void testSpeciesGetName3() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("infect");
        inst.addSet("348", testInstructs);
        std::vector<std::string> result = inst.getInstrucSet("testCreature");
        Species x = Species("348", inst);
        CPPUNIT_ASSERT(x.getName() == '3');
    }
    
    void testSpeciesGetAction() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("infect");
        inst.addSet("testCreature", testInstructs);
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(x.getAction(0).compare("infect") == 0);
    }
    
    void testSpeciesGetAction2() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("testInstruction");
        inst.addSet("testCreature", testInstructs);
        Species x = Species("testCreature", inst);
        CPPUNIT_ASSERT(x.getAction(0).compare("testInstruction") == 0);
    }
    
    void testSpeciesGetAction3() {
        Instructions inst;
        std::vector<std::string> testInstructs;
        testInstructs.push_back("infect");
        inst.addSet("testCreature", testInstructs);
        Species x = Species("testCreature", inst);
        try {
            CPPUNIT_ASSERT(x.getAction(1).compare("infect") == 0);
            CPPUNIT_ASSERT(false);
        } catch (const std::out_of_range& oor) {
            CPPUNIT_ASSERT(x.getAction(0).compare("infect") == 0);
        }
    }
    
    void testSpeciesGoToNextAction() {
        addCreatures();
        Species x = Species("rover");
        int next = x.goToNextAction(0, ENEMY);
        CPPUNIT_ASSERT(next == 9);
    }
    
    void testSpeciesGoToNextAction2() {
        addCreatures();
        Species x = Species("best");
        int next = x.goToNextAction(0, WALL);
        CPPUNIT_ASSERT(next == 2);
    }
    
    void testSpeciesGoToNextAction3() {
        addCreatures();
        Species x = Species("hopper");
        int next = x.goToNextAction(1, EMPTY);
        CPPUNIT_ASSERT(next == 0);
    }
    
    void testCreatureTurnLeft() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.turnLeft();
        CPPUNIT_ASSERT(c.direction == EAST);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureTurnLeft2() {
        addCreatures();
        Creature c = Creature(Species("rover"), WEST, 2, 2);
        c.turnLeft();
        CPPUNIT_ASSERT(c.direction == SOUTH);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureTurnLeft3() {
        addCreatures();
        Creature c = Creature(Species("rover"), EAST, 2, 2);
        c.turnLeft();
        CPPUNIT_ASSERT(c.direction == NORTH);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureTurnRight() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.turnRight();
        CPPUNIT_ASSERT(c.direction == WEST);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureTurnRight2() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.turnRight();
        c.turnRight();
        CPPUNIT_ASSERT(c.direction == NORTH);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureTurnRight3() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.turnRight();
        c.turnRight();
        c.turnRight();
        CPPUNIT_ASSERT(c.direction == EAST);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureHop() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.hop(1,1);
        CPPUNIT_ASSERT(c.y == 1 && c.x == 1);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureHop2() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.hop(1,111);
        CPPUNIT_ASSERT(c.y == 1 && c.x == 111);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureHop3() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.hop(0,0);
        CPPUNIT_ASSERT(c.y == 0 && c.x == 0);
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureInfect() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        c.infect();
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureInfect2() {
        addCreatures();
        Creature c = Creature(Species("best"), SOUTH, 2, 2);
        c.infect();
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureInfect3() {
        addCreatures();
        Creature c = Creature(Species("trap"), SOUTH, 2, 2);
        c.infect();
        CPPUNIT_ASSERT(c.moved);
    }
    
    void testCreatureGetAction() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("rover"), SOUTH, 2, 2);
        std::string action = world.grid[2][2].getAction();
        world.clear();
        CPPUNIT_ASSERT(action.compare("hop") == 0);
    }
    
    void testCreatureGetAction2() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("rover"), SOUTH, 2, 2);
        world.add(Species("food"), SOUTH, 3, 2);
        std::string action = world.grid[2][2].getAction();
        world.clear();
        CPPUNIT_ASSERT(action.compare("infect") == 0);
    }
    
    void testCreatureGetAction3() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("trap"), SOUTH, 2, 2);
        std::string action = world.grid[2][2].getAction();
        world.clear();
        CPPUNIT_ASSERT(action.compare("left") == 0);
    }
    
    void testCreatureGetRep() {
        addCreatures();
        Creature c = Creature(Species("best"), SOUTH, 2, 2);
        char r = c.getRep();
        CPPUNIT_ASSERT(r == 'b');
    }
    
    void testCreatureGetRep2() {
        addCreatures();
        Creature c = Creature(Species("rover"), SOUTH, 2, 2);
        char r = c.getRep();
        CPPUNIT_ASSERT(r == 'r');
    }
    
    void testCreatureGetRep3() {
        addCreatures();
        Creature c = Creature(Species("trap"), SOUTH, 2, 2);
        char r = c.getRep();
        CPPUNIT_ASSERT(r == 't');
    }
    
    void testWorldAdd() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("best"), WEST, 0, 0);
        world.add(Species("rover"), EAST, 2, 2);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(c.getRep() == 'b');
        c = world.grid[2][2];
        CPPUNIT_ASSERT(c.getRep() == 'r');
    }
    
    void testWorldAdd2() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("food"), WEST, 0, 0);
        world.add(Species("trap"), EAST, 2, 2);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(c.getRep() == 'f');
        c = world.grid[2][2];
        CPPUNIT_ASSERT(c.getRep() == 't');
    }
    
    void testWorldAdd3() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("best"), WEST, 0, 0);
        world.add(Species("rover"), EAST, 2, 2);
        world.add(Species("food"), EAST, 2, 2);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(c.getRep() == 'b');
        c = world.grid[2][2];
        CPPUNIT_ASSERT(c.getRep() == 'f');
    }
    
    void testWorldGetFrontSpace() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("best"), EAST, 0, 0);
        world.add(Species("rover"), SOUTH, 0, 1);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(world.getFrontSpace(c.y, c.x, c.direction) == ENEMY);
        c = world.grid[0][1];
        CPPUNIT_ASSERT(world.getFrontSpace(c.y, c.x, c.direction) == EMPTY);
    }
    
    void testWorldGetFrontSpace2() {
        addCreatures();
        world = World(1, 1);
        world.add(Species("rover"), WEST, 0, 0);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(world.getFrontSpace(c.y, c.x, c.direction) == WALL);
    }
    
    void testWorldGetFrontSpace3() {
        addCreatures();
        world = World(5, 5);
        world.add(Species("best"), NORTH, 0, 0);
        world.add(Species("rover"), SOUTH, 4, 4);
        Creature c = world.grid[0][0];
        CPPUNIT_ASSERT(world.getFrontSpace(c.y, c.x, c.direction) == WALL);
        c = world.grid[4][4];
        CPPUNIT_ASSERT(world.getFrontSpace(c.y, c.x, c.direction) == WALL);
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(testInstructionsGetInstrucSet);
    CPPUNIT_TEST(testInstructionsGetInstrucSet2);
    CPPUNIT_TEST(testInstructionsGetInstrucSet3);
    CPPUNIT_TEST(testInstructionsAddSet);
    CPPUNIT_TEST(testInstructionsAddSet2);
    CPPUNIT_TEST(testInstructionsAddSet3);
    CPPUNIT_TEST(testInstructionsDeleteSet);
    CPPUNIT_TEST(testInstructionsDeleteSet2);
    CPPUNIT_TEST(testInstructionsDeleteSet3);
    CPPUNIT_TEST(testSpeciesIsAction);
    CPPUNIT_TEST(testSpeciesIsAction2);
    CPPUNIT_TEST(testSpeciesIsAction3);
    CPPUNIT_TEST(testSpeciesDefConstructor);
    CPPUNIT_TEST(testSpeciesNormConstructor);
    CPPUNIT_TEST(testSpeciesDebugConstructor);
    CPPUNIT_TEST(testSpeciesGetName);
    CPPUNIT_TEST(testSpeciesGetName2);
    CPPUNIT_TEST(testSpeciesGetName3);
    CPPUNIT_TEST(testSpeciesGetAction);
    CPPUNIT_TEST(testSpeciesGetAction2);
    CPPUNIT_TEST(testSpeciesGetAction3);
    CPPUNIT_TEST(testSpeciesGoToNextAction);
    CPPUNIT_TEST(testSpeciesGoToNextAction2);
    CPPUNIT_TEST(testSpeciesGoToNextAction3);
    CPPUNIT_TEST(testCreatureTurnLeft);
    CPPUNIT_TEST(testCreatureTurnLeft2);
    CPPUNIT_TEST(testCreatureTurnLeft3);
    CPPUNIT_TEST(testCreatureTurnRight);
    CPPUNIT_TEST(testCreatureTurnRight2);
    CPPUNIT_TEST(testCreatureTurnRight3);
    CPPUNIT_TEST(testCreatureHop);
    CPPUNIT_TEST(testCreatureHop2);
    CPPUNIT_TEST(testCreatureHop3);
    CPPUNIT_TEST(testCreatureInfect);
    CPPUNIT_TEST(testCreatureInfect2);
    CPPUNIT_TEST(testCreatureInfect3);
    CPPUNIT_TEST(testCreatureGetAction);
    CPPUNIT_TEST(testCreatureGetAction2);
    CPPUNIT_TEST(testCreatureGetAction3);
    CPPUNIT_TEST(testCreatureGetRep);
    CPPUNIT_TEST(testCreatureGetRep2);
    CPPUNIT_TEST(testCreatureGetRep3);
    CPPUNIT_TEST(testWorldAdd);
    CPPUNIT_TEST(testWorldAdd2);
    CPPUNIT_TEST(testWorldAdd3);
    CPPUNIT_TEST(testWorldGetFrontSpace);
    CPPUNIT_TEST(testWorldGetFrontSpace2);
    CPPUNIT_TEST(testWorldGetFrontSpace3);
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

    tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
