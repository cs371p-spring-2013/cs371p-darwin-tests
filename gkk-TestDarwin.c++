#include <algorithm> // count
#include <iostream>  // ios_base
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define class struct
#define private public
#define protected public

#include "Darwin.h"

using namespace std;

struct TestDarwin : CppUnit::TestFixture {
    // --------
    // test_location
    // --------

    void test_location_eq()
    {
        Location a(10, 10);
        Location b(10, 10);
        CPPUNIT_ASSERT(a == b);
    }

    void test_location_sort()
    {
        vector<Location> locations;
        locations.push_back(Location(1, 0));
        locations.push_back(Location(0, 1));
        locations.push_back(Location(0, 0));
        sort(locations.begin(), locations.end());
        CPPUNIT_ASSERT(locations[0].x == 0 && locations[0].y == 0);
        CPPUNIT_ASSERT(locations[1].x == 1 && locations[1].y == 0);
        CPPUNIT_ASSERT(locations[2].x == 0 && locations[2].y == 1);
    }

    void test_location_get_front()
    {
        Location a(10, 10, NORTH);
        Location b = a.get_front();
        CPPUNIT_ASSERT(a.x == 10 && a.y == 10);
        CPPUNIT_ASSERT(b.x == 10 && b.y == 9);
    }

    void test_location_move_forward()
    {
        Location a(10, 10, NORTH);
        a.move_forward();
        CPPUNIT_ASSERT(a.x == 10 && a.y == 9);
    }

    void test_location_turn_left()
    {
        Location a(10, 10, NORTH);
        a.turn_left();
        CPPUNIT_ASSERT(a.d == WEST);
        a.turn_left();
        CPPUNIT_ASSERT(a.d == SOUTH);
        a.turn_left();
        CPPUNIT_ASSERT(a.d == EAST);
        a.turn_left();
        CPPUNIT_ASSERT(a.d == NORTH);
    }

    void test_location_turn_right()
    {
        Location a(10, 10, NORTH);
        a.turn_right();
        CPPUNIT_ASSERT(a.d == EAST);
        a.turn_right();
        CPPUNIT_ASSERT(a.d == SOUTH);
        a.turn_right();
        CPPUNIT_ASSERT(a.d == WEST);
        a.turn_right();
        CPPUNIT_ASSERT(a.d == NORTH);
    }

    void test_species_add_instruction()
    {
        Species a('a');
        CPPUNIT_ASSERT(a.instructions.size() == 0);

        a.add_instruction(GO, 15);
        CPPUNIT_ASSERT(a.instructions.size() == 1);
        CPPUNIT_ASSERT(a.instructions[0].type == GO);
        CPPUNIT_ASSERT(a.instructions[0].jumpval == 15);
    }

    void test_species_get_action()
    {
        Species a('a');
        a.add_instruction(HOP);
        a.add_instruction(LEFT);
        a.add_instruction(GO, 0);
        int pc = 0;
        CPPUNIT_ASSERT(a.get_action(EMPTY, pc) == HOP);
        CPPUNIT_ASSERT(a.get_action(EMPTY, pc) == LEFT);
        CPPUNIT_ASSERT(a.get_action(EMPTY, pc) == HOP);
    }

    void test_creature_get_action()
    {
        Species a('a');
        a.add_instruction(HOP);
        a.add_instruction(LEFT);
        a.add_instruction(GO, 0);
        Creature c(a, 10, 10, NORTH);
        CPPUNIT_ASSERT(c.get_action(EMPTY) == HOP);
        CPPUNIT_ASSERT(c.get_action(EMPTY) == LEFT);
        CPPUNIT_ASSERT(c.get_action(EMPTY) == HOP);
    }

    void test_creature_get_front()
    {
        Species a('a');
        Creature c(a, 10, 10, NORTH);
        Location l = c.get_front();
        CPPUNIT_ASSERT(c.location.x == 10 && c.location.y == 10);
        CPPUNIT_ASSERT(l.x == 10 && l.y == 9);
    }

    void test_creature_intersects()
    {
        Species a('a');
        Creature c(a, 10, 10, NORTH);
        Location l1(10, 10, NORTH);
        Location l2(10, 9, NORTH);
        CPPUNIT_ASSERT(c.intersects(l1));
        CPPUNIT_ASSERT(!c.intersects(l2));
    }

    void test_creature_is_allied()
    {
        Species a('a');
        Species b('b');
        Creature c1(a, 10, 10, NORTH);
        Creature c2(a, 10, 9, NORTH);
        Creature c3(b, 10, 8, NORTH);
        CPPUNIT_ASSERT(c1.is_allied(c2));
        CPPUNIT_ASSERT(!c1.is_allied(c3));
    }

    void test_creature_move_forward()
    {
        Species a('a');
        Creature c(a, 10, 10, NORTH);
        c.move_forward();
        CPPUNIT_ASSERT(c.location.x == 10 && c.location.y == 9);
    }

    void test_creature_turn_left()
    {
        Species a('a');
        Creature c(a, 10, 10, NORTH);
        c.turn_left();
        CPPUNIT_ASSERT(c.location.d == WEST);
        c.turn_left();
        CPPUNIT_ASSERT(c.location.d == SOUTH);
        c.turn_left();
        CPPUNIT_ASSERT(c.location.d == EAST);
        c.turn_left();
        CPPUNIT_ASSERT(c.location.d == NORTH);
    }

    void test_creature_turn_right()
    {
        Species a('a');
        Creature c(a, 10, 10, NORTH);
        c.turn_right();
        CPPUNIT_ASSERT(c.location.d == EAST);
        c.turn_right();
        CPPUNIT_ASSERT(c.location.d == SOUTH);
        c.turn_right();
        CPPUNIT_ASSERT(c.location.d == WEST);
        c.turn_right();
        CPPUNIT_ASSERT(c.location.d == NORTH);
    }

    void test_creature_infect()
    {
        Species a('a');
        Species b('b');
        Creature c1(a, 10, 10, NORTH);
        Creature c2(b, 10, 9, NORTH);
        c2.pc = 5;
        c1.infect(c2);
        CPPUNIT_ASSERT(c2.species == c1.species);
        CPPUNIT_ASSERT(c2.pc == 0);
    }

    void test_world_add_creature()
    {
        World world(1, 1);
        Species a('a');
        world.add_creature(Creature(a, 0, 0, NORTH));
        CPPUNIT_ASSERT(world.creatures.size() == 1);
        CPPUNIT_ASSERT(world.creatures[0].species == &a);
    }

    void test_world_run_turn()
    {
        World world(2, 2);
        Species a('a');
        a.add_instruction(HOP);
        a.add_instruction(GO, 0);
        Species b('b');
        b.add_instruction(LEFT);
        b.add_instruction(GO, 0);
        world.add_creature(Creature(a, 0, 0, SOUTH));
        world.add_creature(Creature(b, 1, 1, NORTH));
        world.run_turn();
        CPPUNIT_ASSERT(world.creatures[0].location.x == 0);
        CPPUNIT_ASSERT(world.creatures[0].location.y == 1);
        CPPUNIT_ASSERT(world.creatures[1].location.x == 1);
        CPPUNIT_ASSERT(world.creatures[1].location.y == 1);
        CPPUNIT_ASSERT(world.turn == 1);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_location_eq);
    CPPUNIT_TEST(test_location_sort);
    CPPUNIT_TEST(test_location_get_front);
    CPPUNIT_TEST(test_location_move_forward);
    CPPUNIT_TEST(test_location_turn_left);
    CPPUNIT_TEST(test_location_turn_right);
    CPPUNIT_TEST(test_species_add_instruction);
    CPPUNIT_TEST(test_species_get_action);
    CPPUNIT_TEST(test_creature_get_action);
    CPPUNIT_TEST(test_creature_get_front);
    CPPUNIT_TEST(test_creature_intersects);
    CPPUNIT_TEST(test_creature_is_allied);
    CPPUNIT_TEST(test_creature_move_forward);
    CPPUNIT_TEST(test_creature_turn_left);
    CPPUNIT_TEST(test_creature_turn_right);
    CPPUNIT_TEST(test_creature_infect);
    CPPUNIT_TEST(test_world_add_creature);
    CPPUNIT_TEST(test_world_run_turn);
    CPPUNIT_TEST_SUITE_END();};

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
