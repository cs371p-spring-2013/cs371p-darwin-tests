// ------------------------------------
// projects/allocator/TestAllocator.c++
// Copyright (C) 2013
// Glenn P. Downing
// ------------------------------------

/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
% valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream> // ios_base
#include <memory> // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#define class struct
#define private public
#define protected public
#include "Darwin.h"

using namespace std;
struct TestDarwin : CppUnit::TestFixture
{
    void test_facing_1()
	{
        Species s('s');
        Creature c(&s, north);
        CPPUNIT_ASSERT(c.facing() == north);
    }
    void test_facing_2()
    {
        Species s('s');
        Creature c(&s, east);
        CPPUNIT_ASSERT(c.facing() == east);
    }
    void test_facing_3()
    {
        Species s('s');
        Creature c(&s, south);
        CPPUNIT_ASSERT(c.facing() == south);
    }
    void test_facing_4()
    {
        Species s('s');
        Creature c(&s, west);
        CPPUNIT_ASSERT(c.facing() == west);
    }

    void test_checkWall_1()
    {
        Species s('s');
        Creature c(&s, north);
        CPPUNIT_ASSERT(c.checkWall(1, 1, 0, 0));
    }
    void test_checkWall_2()
    {
        Species s('s');
        Creature c(&s, east);
        CPPUNIT_ASSERT(c.checkWall(5, 5, 0, 4));
    }
    void test_checkWall_3()
    {
        Species s('s');
        Creature c(&s, south);
        CPPUNIT_ASSERT(c.checkWall(5, 5, 4, 4));
    }
    void test_checkWall_4()
    {
        Species s('s');
        Creature c(&s, west);
        CPPUNIT_ASSERT(!c.checkWall(5, 5, 2, 2));
    }

    void test_finishTurn_1()
    {
        Species s('s');
        Creature c(&s, north);
        c._done = true;
        c.finishTurn();
        CPPUNIT_ASSERT(c._done == false);
    }
    void test_finishTurn_2()
    {
        Species s('s');
        Creature c(&s, north);
        c._done = false;
        c.finishTurn();
        CPPUNIT_ASSERT(c._done == false);
    }
    void test_finishTurn_3()
    {
        Species s('s');
        Creature c(&s, east);
        c._done = true;
        c.finishTurn();
        CPPUNIT_ASSERT(c._done == false);
    }

    void test_nextAction_1()
    {
        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c(&rover, east);

        c.nextAction(5, 5, 2, 2, NULL);
        CPPUNIT_ASSERT(c._pc == 8);
        CPPUNIT_ASSERT(c._done == true);
        CPPUNIT_ASSERT(c._dir == east);
        CPPUNIT_ASSERT(c._species == &rover);
    }
    void test_nextAction_2()
    {
        Species hopper('h');
        hopper.addInstruction(hop);
        hopper.addInstruction(go, 0);

        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c1(&rover, east);
        Creature c2(&hopper, east);

        c1.nextAction(5, 5, 2, 2, &c2);
        CPPUNIT_ASSERT(c1._pc == 10);
        CPPUNIT_ASSERT(c1._done == false);
        CPPUNIT_ASSERT(c1._dir == east);
        CPPUNIT_ASSERT(c1._species == &rover);

        CPPUNIT_ASSERT(c2._pc == 0);
        CPPUNIT_ASSERT(c2._done == false);
        CPPUNIT_ASSERT(c2._dir == east);
        CPPUNIT_ASSERT(c2._species == &rover);
    }
    void test_nextAction_3()
    {
        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c1(&rover, east);
        Creature c2(&rover, east);

        c1.nextAction(5, 5, 2, 2, &c2);
        CPPUNIT_ASSERT(c1._pc == 4 || c1._pc == 6);
        CPPUNIT_ASSERT(c1._done == false);
        CPPUNIT_ASSERT(c1._dir != east);
        CPPUNIT_ASSERT(c1._species == &rover);

        CPPUNIT_ASSERT(c2._pc == 0);
        CPPUNIT_ASSERT(c2._done == false);
        CPPUNIT_ASSERT(c2._dir == east);
        CPPUNIT_ASSERT(c2._species == &rover);
    }

    void test_adjacent_1()
    {
        Species s('s');
        Creature c1(&s, east);
        Creature c2(&s, east);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 1, &c2);
        
        CPPUNIT_ASSERT(g.adjacent(0,0) == &c2);
    }
    void test_adjacent_2()
    {
        Species s('s');
        Creature c1(&s, east);
        Creature c2(&s, east);
        Grid<5,5> g;
        g.addCreature(1, 1, &c1);
        
        CPPUNIT_ASSERT(g.adjacent(1,1) == NULL);
    }
    void test_adjacent_3()
    {
        Species s('s');
        Creature c1(&s, north);
        Creature c2(&s, east);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 1, &c2);
        
        CPPUNIT_ASSERT(g.adjacent(0,0) == NULL);
    }
    
    void test_move_1()
    {
        Species rover('r');
        Creature c1(&rover, east);
        Creature c2(&rover, east);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 1, &c2);
        g.move(0, 1);
        CPPUNIT_ASSERT(g._grid[0][1] == NULL);
        CPPUNIT_ASSERT(g._grid[0][2] == &c2);
    }
    void test_move_2()
    {
        Species rover('r');
        Creature c1(&rover, south);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.move(0, 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
        CPPUNIT_ASSERT(g._grid[1][0] == &c1);
    }
    void test_move_3()
    {
        Species rover('r');
        Creature c1(&rover, south);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.move(0, 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
        CPPUNIT_ASSERT(g._grid[1][0] == &c1);
    }
    
    void test_addCreature_1()
    {
        Species rover('r');
        Creature c1(&rover, south);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        
        CPPUNIT_ASSERT(g._grid[0][0] == &c1);
    }
    void test_addCreature_2()
    {
        Species rover('r');
        Creature c1(&rover, east);
        Creature c2(&rover, east);
        Grid<5,5> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 1, &c2);
        CPPUNIT_ASSERT(g._grid[0][0] == &c1);
        CPPUNIT_ASSERT(g._grid[0][1] == &c2);
    }
    void test_addCreature_3()
    {
        Species rover('r');
        Creature c1(&rover, south);
        Creature c2(&rover, south);
        Grid<1,1> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 0, &c2);
        
        CPPUNIT_ASSERT(g._grid[0][0] == &c2);
    }
    void test_addCreature_4()
    {
        Species rover('r');
        Creature c1(&rover, south);
        Creature c2(&rover, south);
        Creature c3(&rover, south);
        Creature c4(&rover, south);
        Grid<2,2> g;
        g.addCreature(0, 0, &c1);
        g.addCreature(0, 1, &c2);
        g.addCreature(1, 0, &c3);
        g.addCreature(1, 1, &c4);
        
        CPPUNIT_ASSERT(g._grid[0][0] == &c1);
        CPPUNIT_ASSERT(g._grid[0][1] == &c2);
        CPPUNIT_ASSERT(g._grid[1][0] == &c3);
        CPPUNIT_ASSERT(g._grid[1][1] == &c4);
    }
    
    void test_oneTurn_1()
    {
        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c(&rover, east);
        Grid<2,2> g;
        g.addCreature(0, 0, &c);
        g.oneTurn();
        CPPUNIT_ASSERT(c._pc == 8);
        CPPUNIT_ASSERT(c._done == false);
        CPPUNIT_ASSERT(c._dir == east);
        CPPUNIT_ASSERT(c._species == &rover);
    }
    void test_oneTurn_2()
    {
        Species hopper('h');
        hopper.addInstruction(hop);
        hopper.addInstruction(go, 0);

        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c1(&rover, north);
        Creature c2(&hopper, east);
        
        Grid<4, 4> g;
        g.addCreature(1, 2, &c1);
        g.addCreature(2, 2, &c2);
        g.oneTurn();

        CPPUNIT_ASSERT(c1._pc == 8);
        CPPUNIT_ASSERT(c1._done == false);
        CPPUNIT_ASSERT(c1._dir == north);
        CPPUNIT_ASSERT(c1._species == &rover);

        CPPUNIT_ASSERT(c2._pc == 1);
        CPPUNIT_ASSERT(c2._done == false);
        CPPUNIT_ASSERT(c2._dir == east);
        CPPUNIT_ASSERT(c2._species == &hopper);
    }
    void test_oneTurn_3()
    {
        Species hopper('h');
        hopper.addInstruction(hop);
        hopper.addInstruction(go, 0);

        Species rover('r');
        rover.addInstruction(enemy, 9);
        rover.addInstruction(empty, 7);
        rover.addInstruction(ran, 5);
        rover.addInstruction(lft);
        rover.addInstruction(go, 0);
        rover.addInstruction(rgt);
        rover.addInstruction(go, 0);
        rover.addInstruction(hop);
        rover.addInstruction(go, 0);
        rover.addInstruction(infect);
        rover.addInstruction(go, 0);
        Creature c1(&rover, south);
        Creature c2(&hopper, east);
        
        Grid<4, 4> g;
        g.addCreature(2, 2, &c1);
        g.addCreature(3, 2, &c2);
        g.oneTurn();

        CPPUNIT_ASSERT(c1._pc == 10);
        CPPUNIT_ASSERT(c1._done == false);
        CPPUNIT_ASSERT(c1._dir == south);
        CPPUNIT_ASSERT(c1._species == &rover);

        CPPUNIT_ASSERT(c2._pc == 8);
        CPPUNIT_ASSERT(c2._done == false);
        CPPUNIT_ASSERT(c2._dir == east);
        CPPUNIT_ASSERT(c2._species == &rover);
        
        CPPUNIT_ASSERT(g._grid[2][2] == &c1);
        CPPUNIT_ASSERT(g._grid[3][2] == NULL);
        CPPUNIT_ASSERT(g._grid[3][3] == &c2);
    }
    
    void test_addInstruction_1()
    {
        Species rover('r');
        rover.addInstruction(enemy, 9);
        
        CPPUNIT_ASSERT(rover._program[0].first == enemy);
        CPPUNIT_ASSERT(rover._program[0].second == 9);
    }
    void test_addInstruction_2()
    {
        Species rover('r');
        rover.addInstruction(go);
        
        CPPUNIT_ASSERT(rover._program[0].first == go);
        CPPUNIT_ASSERT(rover._program[0].second == -1);
    }
    void test_addInstruction_3()
    {
        Species rover('r');
        rover.addInstruction(ran, 9);
        rover.addInstruction(ran, 9);
        
        CPPUNIT_ASSERT(rover._program[0].first == ran);
        CPPUNIT_ASSERT(rover._program[0].second == 9);
        CPPUNIT_ASSERT(rover._program[1].first == ran);
        CPPUNIT_ASSERT(rover._program[1].second == 9);
    }
    void test_next_1()
    {
        Species rover('r');
        rover.addInstruction(ran, 9);
        rover.addInstruction(ran, 9);
        
        CPPUNIT_ASSERT(rover.next(0).first == ran);
        CPPUNIT_ASSERT(rover.next(0).second == 9);
    }
    void test_next_2()
    {
        Species rover('r');
        rover.addInstruction(ran, 9);
        rover.addInstruction(ran, 9);
        
        CPPUNIT_ASSERT(rover.next(1).first == ran);
        CPPUNIT_ASSERT(rover.next(1).second == 9);
    }
    void test_next_3()
    {
        Species rover('r');
        rover.addInstruction(go);
        
        CPPUNIT_ASSERT(rover.next(0).first == go);
        CPPUNIT_ASSERT(rover.next(0).second == -1);
    }

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_addInstruction_1);
    CPPUNIT_TEST(test_addInstruction_2);
    CPPUNIT_TEST(test_addInstruction_3);
    CPPUNIT_TEST(test_next_1);
    CPPUNIT_TEST(test_next_2);
    CPPUNIT_TEST(test_next_3);
    CPPUNIT_TEST(test_checkWall_1);
    CPPUNIT_TEST(test_checkWall_2);
    CPPUNIT_TEST(test_checkWall_3);
    CPPUNIT_TEST(test_checkWall_4);
    CPPUNIT_TEST(test_nextAction_1);
    CPPUNIT_TEST(test_nextAction_2);
    CPPUNIT_TEST(test_nextAction_3);
    CPPUNIT_TEST(test_facing_1);
    CPPUNIT_TEST(test_facing_2);
    CPPUNIT_TEST(test_facing_3);
    CPPUNIT_TEST(test_facing_4);
    CPPUNIT_TEST(test_finishTurn_1);
    CPPUNIT_TEST(test_finishTurn_2);
    CPPUNIT_TEST(test_finishTurn_3);
    CPPUNIT_TEST(test_adjacent_1);
    CPPUNIT_TEST(test_adjacent_2);
    CPPUNIT_TEST(test_adjacent_3);
    CPPUNIT_TEST(test_move_1);
    CPPUNIT_TEST(test_move_2);
    CPPUNIT_TEST(test_move_3);
    CPPUNIT_TEST(test_addCreature_1);
    CPPUNIT_TEST(test_addCreature_2);
    CPPUNIT_TEST(test_addCreature_3);
    CPPUNIT_TEST(test_addCreature_4);
    CPPUNIT_TEST(test_oneTurn_1);
    CPPUNIT_TEST(test_oneTurn_2);
    CPPUNIT_TEST(test_oneTurn_3);
    CPPUNIT_TEST_SUITE_END();
};

int main()
{
    using namespace std;
    cout << "TestDarwin.c++" << endl;
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
