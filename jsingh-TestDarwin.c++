//---------------
// Jasneet Singh
// TestDarwin.c++
// --------------

// --------
// includes
// --------

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" //CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" //TestFixture
#include "cppunit/TextTestRunner.h" //TestRunner


// -------
// defines
// -------

#define private public
#define protected public
#define class struct


#include "Darwin.h"

using namespace std;


struct TestDarwin: CppUnit::TestFixture{

    
    //Instruction

    void test_Instruction(){
        Instruction test(instruc::RIGHT);
        CPPUNIT_ASSERT(test._name == instruc::RIGHT);
        CPPUNIT_ASSERT(test._line == -1);
    }

    void test_Instruction1(){
        Instruction test(instruc::IF_ENEMY, 5);
        CPPUNIT_ASSERT(test._name == instruc::IF_ENEMY);
        CPPUNIT_ASSERT(test._line == 5);
    }

    void test_Instruction2(){
        Instruction test(instruc::GO, 0);
        CPPUNIT_ASSERT(test._name == instruc::GO);
        CPPUNIT_ASSERT(test._line == 0);
    }


    void test_retrieveValue(){
        Instruction test(instruc::GO, 0);
        CPPUNIT_ASSERT(test.retrieveValue() == instruc::GO);
    }

    void test_retrieveValue2(){
        Instruction test(instruc::IF_ENEMY);
        CPPUNIT_ASSERT(test.retrieveValue() == instruc::IF_ENEMY);
    }

    void test_retrieveValue3(){
        Instruction test(instruc::HOP, 1);
        CPPUNIT_ASSERT(test.retrieveValue() == instruc::HOP);
    }

    void test_retrieveLine(){
        Instruction test(instruc::HOP, 1);
        CPPUNIT_ASSERT(test.retrieveLine() == 1);
    }

    void test_retrieveLine2(){
        Instruction test(instruc::HOP);
        CPPUNIT_ASSERT(test.retrieveLine() == -1);
    }

    void test_retrieveLine3(){
        Instruction test(instruc::IF_ENEMY, 20000);
        CPPUNIT_ASSERT(test.retrieveLine() == 20000);
    }
    

    //Species

    void test_Species(){
        Species food('f',3);
        CPPUNIT_ASSERT(food._name == 'f');
        CPPUNIT_ASSERT(food.program.size() == 3);
    }

    void test_Species2(){
        Species animal('A',200);
        CPPUNIT_ASSERT(animal._name == 'A');
        CPPUNIT_ASSERT(animal.program.size() == 200);
    }

    

    void test_Species3(){
        Species trap('t',1);
        CPPUNIT_ASSERT(trap._name == 't');
        CPPUNIT_ASSERT(trap.program.size() == 1);
    }


    void test_addInstruction(){
        Species food('t',2);
        Instruction test(instruc::GO);
        food.addInstruction(1, test);
        
        CPPUNIT_ASSERT(food.program[1]._line == -1);
        CPPUNIT_ASSERT(food.program[1]._name == instruc::GO);

    }

    void test_addInstruction2(){
        Species test('f', 3);
        Instruction enemy5(instruc::IF_ENEMY, 5);
        test.addInstruction(0, enemy5);

        CPPUNIT_ASSERT(test.program[0]._line = 5);
        CPPUNIT_ASSERT(test.program[0]._name == instruc::IF_ENEMY);

    }

    void test_addInstruction3(){
        Species jasneet('j', 1);
        Instruction test(instruc::HOP);
        jasneet.addInstruction(0, test);

        CPPUNIT_ASSERT(jasneet.program[0]._line == -1);
        CPPUNIT_ASSERT(jasneet.program[0]._name == instruc::HOP);
    }

    void test_carryOut(){
        Species jasneet('j', 1);
        Instruction test(instruc::HOP);
        jasneet.addInstruction(0, test);

        CPPUNIT_ASSERT(jasneet.carryOutInstructions(0)._line == -1);
        CPPUNIT_ASSERT(jasneet.carryOutInstructions(0)._name == instruc::HOP);
    }

    void test_carryOut2(){
        Species test('f' ,3);
        Instruction enemy5(instruc::IF_ENEMY, 5);
        test.addInstruction(2, enemy5);

        CPPUNIT_ASSERT(test.carryOutInstructions(2)._line == 5);
        CPPUNIT_ASSERT(test.carryOutInstructions(2)._name == instruc::IF_ENEMY);
    }

    void test_carryOut3(){
        Species test('z', 10);
        Instruction go(instruc::GO);
    
        test.addInstruction(9, go);
        CPPUNIT_ASSERT(test.carryOutInstructions(9)._line == -1);
        CPPUNIT_ASSERT(test.carryOutInstructions(9)._name == instruc::GO);
    }

    void test_lessless(){
        Species test(97,3);
        ostringstream w;

        test << w;
        CPPUNIT_ASSERT(w.str() == "a");
    }

    
    void test_lessless2(){
        Species test('a', 4);
        ostringstream w;

        test << w;
        CPPUNIT_ASSERT(w.str() == "a");
    }

    void test_lessless3(){
        Species test('*',5);
        ostringstream w;

        test << w;
        CPPUNIT_ASSERT(w.str() == "*");
    }

    void test_equalSpecies(){
        Species test1('c', 2);
        Species test2('C', 2);

        CPPUNIT_ASSERT(!(test1==test2));
    }

    void test_equalSpecies2(){
        Species test1('a', 3);
        Species test2(97, 5);

        CPPUNIT_ASSERT(test1 == test2);
    }

    void test_equalSpecies3(){
        Species test1('!', 3);
        Species test2('!', 5);

        CPPUNIT_ASSERT(test1 == test2);
    }


    // Grid

    void test_Grid(){
        Grid test(5, 6);
        CPPUNIT_ASSERT(test.location.first == 5);
        CPPUNIT_ASSERT(test.location.second == 6);
    }


    void test_Grid2(){
        Grid test(0,0);
        CPPUNIT_ASSERT(test.location.first == 0);
        CPPUNIT_ASSERT(test.location.second == 0);
    }

    void test_Grid3(){
        Grid test(9999,9999);
        CPPUNIT_ASSERT(test.location.first == 9999);
        CPPUNIT_ASSERT(test.location.second == 9999);
    }


    void test_equalGrid(){
        Grid test(0,0);
        Grid test1(0,0);

        CPPUNIT_ASSERT(test==test1);
    }

    void test_equalGrid2(){
        Grid test(5, 6);
        Grid test1(6, 5);
        CPPUNIT_ASSERT(!(test==test1));
    }

    void test_equalGrid3(){
        Grid test(999,999);
        Grid test1(999, 999);

        CPPUNIT_ASSERT(test==test1);
    }

    void test_updateLocation(){
        Grid test(5,7);
        test.updateLocation(8,9);
        
        CPPUNIT_ASSERT(test.location.first == 8);
        CPPUNIT_ASSERT(test.location.second == 9);

    }

    void test_updateLocation2(){
        Grid test(1, 2);
        test.updateLocation(1,2);

        CPPUNIT_ASSERT(test.location.first == 1);
        CPPUNIT_ASSERT(test.location.second == 2);

    }

    void test_updateLocation3(){
        Grid test(0, 0);
        test.updateLocation(999, 9999);
        CPPUNIT_ASSERT(test.location.first == 999);
        CPPUNIT_ASSERT(test.location.second == 9999);

    }

    void test_getX(){
        Grid test(5, 6);
        CPPUNIT_ASSERT(test.getX() == 5);
    }

    void test_getX2(){
        Grid test(0, 8);
        CPPUNIT_ASSERT(test.getX() == 0);
    }

    void test_getX3(){
        Grid test(9999, 3);
        CPPUNIT_ASSERT(test.getX() == 9999);
    }

    void test_getY(){
        Grid test(6, 5);
        CPPUNIT_ASSERT(test.getY() == 5);
    }

    void test_getY2(){
        Grid test(8, 0);
        CPPUNIT_ASSERT(test.getY() == 0);
    }

    void test_getY3(){
        Grid test(3, 9999);
        CPPUNIT_ASSERT(test.getY() == 9999);
    }
    

    //Creature

    void test_Creature(){
        Species food('f',2);
        Creature creature(food, Direction::NORTH);
        CPPUNIT_ASSERT(creature.program_counter == 0);
        CPPUNIT_ASSERT(creature._type == food);
        CPPUNIT_ASSERT(creature._direction == Direction::NORTH);
    }

    void test_Creature2(){
        Species eat('e', 5);
        Creature creature(eat, Direction::SOUTH);
        CPPUNIT_ASSERT(creature._type._name == 'e');
        CPPUNIT_ASSERT(creature._type.program.size() == 5);
    }

    void test_Creature3(){
        Species rover('r', 6);
        Creature creature(rover, Direction::EAST);
        CPPUNIT_ASSERT(creature._type == rover);
        CPPUNIT_ASSERT(creature.program_counter == 0);
    }

    void test_changeDirection(){
        Species rover('r', 6);
        Creature creature(rover, Direction::SOUTH);
        creature.changeDirection(Direction::SOUTH);
        CPPUNIT_ASSERT(creature._direction == Direction::SOUTH);
    }

    void test_changeDirection2(){
        Species rover('r', 6);
        Creature creature(rover, Direction::SOUTH);
        creature.changeDirection(Direction::WEST);
        CPPUNIT_ASSERT(creature._direction == Direction::WEST);
    }

    void test_changeDirection3(){
        Species rover('r', 6);
        Creature creature(rover, Direction::SOUTH);
        creature.changeDirection(Direction::EAST);
        CPPUNIT_ASSERT(creature._direction == Direction::EAST);
    }

    void test_creaturelessless(){
        Species rover('r', 6);
        Creature creature(rover, Direction::SOUTH);
        ostringstream w;
        
        creature << w;
        CPPUNIT_ASSERT(w.str() == "r");
    }

    void test_creaturelessless2(){
        Species rover('B', 8);
        Creature c(rover, Direction::NORTH);
        ostringstream w;

        c << w;
        CPPUNIT_ASSERT(w.str() == "B");
    }

    void test_creaturelessless3(){
        Species rover('*', 9);
        Creature c(rover, Direction::EAST);
        ostringstream w;
        
        c << w;
        CPPUNIT_ASSERT(w.str() == "*");
    }

    void test_retrieveSpecies(){
        Species rover('3', 3);
        Creature c(rover ,Direction::NORTH);
        CPPUNIT_ASSERT(c.retrieveSpecies() == rover);
    }


    void test_retrieveSpecies2(){
        Species rover('a', 3);
        Creature c(rover ,Direction::NORTH);
        c.changeDirection(Direction::SOUTH);
        CPPUNIT_ASSERT(c.retrieveSpecies() == rover);
    }
    
    void test_retrieveSpecies3(){
        Species rover('3', 3);
        Creature c(rover ,Direction::NORTH);
        ostringstream w;
        c << w;
        CPPUNIT_ASSERT(c.retrieveSpecies() == rover);
    }


    void test_resetCreature(){
        Species rover('r', 3);
        Species trap('t', 3);

        Creature c(rover, Direction::SOUTH);
        c.program_counter = 5;
        
        c.resetCreature(trap);
        CPPUNIT_ASSERT(c._type == trap);
        CPPUNIT_ASSERT(c._direction == Direction::SOUTH);
        CPPUNIT_ASSERT(c.program_counter == 0);
    }

    void test_resetCreature2(){
        Species rover('r', 3);
        
        Creature c(rover, Direction::SOUTH);
        c.program_counter = 5;
        
        c.resetCreature(rover);
        CPPUNIT_ASSERT(c._type == rover);
        CPPUNIT_ASSERT(c.program_counter == 0);
        CPPUNIT_ASSERT(c._direction == Direction::SOUTH);
    }


    void test_resetCreature3(){
        Species rover('r', 3);
        Species trap('t', 10);

        Creature c(trap, Direction::SOUTH);
        c.program_counter = 5;
        
        c.resetCreature(rover);
        CPPUNIT_ASSERT(c._type == rover);
        CPPUNIT_ASSERT(c._direction == Direction::SOUTH);
        CPPUNIT_ASSERT(c.program_counter == 0);
    }


    //-----
    // Game
    // -----

    void test_Game(){
    
        Game test(5, 6);
        CPPUNIT_ASSERT(test._height == 5);
        CPPUNIT_ASSERT(test._width == 6);
        CPPUNIT_ASSERT(test._id == 0);
        CPPUNIT_ASSERT(test._numCreatures == 0);
        CPPUNIT_ASSERT(test._turn == 0);
    } 
    
    void test_Game2(){

        Game test(1, 1);
        CPPUNIT_ASSERT(test._height == 1);
        CPPUNIT_ASSERT(test._width == 1);
        CPPUNIT_ASSERT(test._id == 0);
        CPPUNIT_ASSERT(test._numCreatures == 0);
        CPPUNIT_ASSERT(test._turn == 0);
    } 


    void test_Game3(){
    
        Game test(999, 9999);
        CPPUNIT_ASSERT(test._height == 999);
        CPPUNIT_ASSERT(test._width == 9999);
        CPPUNIT_ASSERT(test._id == 0);
        CPPUNIT_ASSERT(test._numCreatures == 0);
        CPPUNIT_ASSERT(test._turn == 0);
    } 

    void test_gameprint(){
        Game test(5,5);
        ostringstream w;
        test.printBoard(w);

        string result = "Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n\n";

        CPPUNIT_ASSERT(w.str() == result);
    }

    void test_gameprint2(){
        Game test(5,5);

        Species jasneet('j', 4);
        Creature toAdd(jasneet, Direction::NORTH);
        test.addCreature(toAdd, Grid(2,2));

        ostringstream w;
        test.printBoard(w);

        string result = "Turn = 0.\n  01234\n0 .....\n1 .....\n2 ..j..\n3 .....\n4 .....\n\n";


        CPPUNIT_ASSERT(w.str() == result);
    }

    void test_gameprint3(){

        Game test(5,5);

        Species jasneet('j', 2);
        Species killer('k', 2);
        Creature toAdd(jasneet, Direction::NORTH);
        Creature override(killer, Direction::SOUTH);

        test.addCreature(toAdd, Grid(2,2));
        test.addCreature(override, Grid(2,2));
        ostringstream w;

        test.printBoard(w);

        string result = "Turn = 0.\n  01234\n0 .....\n1 .....\n2 ..k..\n3 .....\n4 .....\n\n";
        
        CPPUNIT_ASSERT(w.str() == result);
    }


    
    

    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestDarwin);

    CPPUNIT_TEST(test_Instruction);
    CPPUNIT_TEST(test_Instruction1);
    CPPUNIT_TEST(test_Instruction2);
    CPPUNIT_TEST(test_retrieveValue);
    CPPUNIT_TEST(test_retrieveValue2);
    CPPUNIT_TEST(test_retrieveValue3);
    CPPUNIT_TEST(test_retrieveLine);
    CPPUNIT_TEST(test_retrieveLine2);
    CPPUNIT_TEST(test_retrieveLine3);
    

    CPPUNIT_TEST(test_Species);
    CPPUNIT_TEST(test_Species2);
    CPPUNIT_TEST(test_Species3);
    CPPUNIT_TEST(test_addInstruction);
    CPPUNIT_TEST(test_addInstruction2);
    CPPUNIT_TEST(test_addInstruction3);
    CPPUNIT_TEST(test_carryOut);
    CPPUNIT_TEST(test_carryOut2);
    CPPUNIT_TEST(test_carryOut3);
    CPPUNIT_TEST(test_lessless);
    CPPUNIT_TEST(test_lessless2);
    CPPUNIT_TEST(test_lessless3);
    CPPUNIT_TEST(test_equalSpecies);
    CPPUNIT_TEST(test_equalSpecies2);
    CPPUNIT_TEST(test_equalSpecies3);
    
    CPPUNIT_TEST(test_Grid);
    CPPUNIT_TEST(test_Grid2);
    CPPUNIT_TEST(test_Grid3);
    CPPUNIT_TEST(test_equalGrid);
    CPPUNIT_TEST(test_equalGrid2);
    CPPUNIT_TEST(test_equalGrid3);
    CPPUNIT_TEST(test_updateLocation);
    CPPUNIT_TEST(test_updateLocation2);
    CPPUNIT_TEST(test_updateLocation3);
    CPPUNIT_TEST(test_getX);
    CPPUNIT_TEST(test_getX2);
    CPPUNIT_TEST(test_getX3);
    CPPUNIT_TEST(test_getY);
    CPPUNIT_TEST(test_getY2);
    CPPUNIT_TEST(test_getY3);

    CPPUNIT_TEST(test_Creature);
    CPPUNIT_TEST(test_Creature2);
    CPPUNIT_TEST(test_Creature3);
    CPPUNIT_TEST(test_changeDirection);
    CPPUNIT_TEST(test_changeDirection2);
    CPPUNIT_TEST(test_changeDirection3);
    CPPUNIT_TEST(test_creaturelessless);
    CPPUNIT_TEST(test_creaturelessless2);
    CPPUNIT_TEST(test_creaturelessless3);
    CPPUNIT_TEST(test_retrieveSpecies);
    CPPUNIT_TEST(test_retrieveSpecies2);
    CPPUNIT_TEST(test_retrieveSpecies3);
    CPPUNIT_TEST(test_resetCreature);
    CPPUNIT_TEST(test_resetCreature2);
    CPPUNIT_TEST(test_resetCreature3);
    
    CPPUNIT_TEST(test_Game);
    CPPUNIT_TEST(test_Game2);
    CPPUNIT_TEST(test_Game3);
    CPPUNIT_TEST(test_gameprint);
    CPPUNIT_TEST(test_gameprint2);
    CPPUNIT_TEST(test_gameprint3);
    
    CPPUNIT_TEST_SUITE_END();
};



// -----
// main
// -----

int main(){

    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());   
    tr.run();
    cout << "Done." << endl;
    return 0;
}

