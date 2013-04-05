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
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <algorithm> // count
#include <iostream>  // ios_base
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// -------------
// TestDarwin
// -------------

struct TestCreature : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------
    typedef Creature::descriptor descriptor;
    
    // ----------------
    // test_constructor
    // ----------------
    
    void test_constructor_1 () {
        const species s = FOOD;
        const direction d = WEST;
        const descriptor x = std::make_pair(0, 0);
        Creature v(s, d, x, NULL);
        CPPUNIT_ASSERT(v.s        ==    s);
        CPPUNIT_ASSERT(v.d        ==    d);
        CPPUNIT_ASSERT(v.c        ==    x);
        CPPUNIT_ASSERT(v.p.size() ==    2);
        CPPUNIT_ASSERT(v.g        == NULL);
    }
    
    void test_constructor_2 () {
        const species s = HOPPER;
        const direction d = WEST;
        const descriptor x = std::make_pair(2, 1);
        Grid g(3, 3);
        Creature v(s, d, x, &g);
        CPPUNIT_ASSERT(v.s        ==    s);
        CPPUNIT_ASSERT(v.d        ==    d);
        CPPUNIT_ASSERT(v.c.first  ==    2);
        CPPUNIT_ASSERT(v.c.second ==    1);
        CPPUNIT_ASSERT(v.p.size() ==    2);
        CPPUNIT_ASSERT(v.g        != NULL);
    }
    
    void test_constructor_3 () {
        const species s = ROVER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        Creature v(s, d, x, &g);
        CPPUNIT_ASSERT(v.s        ==    s);
        CPPUNIT_ASSERT(v.d        ==    d);
        CPPUNIT_ASSERT(v.c.first  ==    1);
        CPPUNIT_ASSERT(v.c.second ==    1);
        CPPUNIT_ASSERT(v.p.size() ==   11);
        CPPUNIT_ASSERT(v.g        != NULL);
    }
    
    // --------
    // test_hop
    // --------
    
    void test_hop_1 () {
        const species s = HOPPER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(g.g[1][1].first);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.s        == s);
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 1);
        v.hop();
        CPPUNIT_ASSERT(!g.g[1][1].first);
        Creature& w = g.g[1][0].second;
        CPPUNIT_ASSERT(g.g[1][0].first);
        CPPUNIT_ASSERT(w.s        == s);
        CPPUNIT_ASSERT(w.c.first  == 1);
        CPPUNIT_ASSERT(w.c.second == 0);
    }
    
    void test_hop_2 () {
        const species s = HOPPER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(g.g[1][1].first);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.s        == s);
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 1);
        v.hop();
        CPPUNIT_ASSERT(!g.g[1][1].first);
        Creature& w = g.g[0][1].second;
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(w.s        == s);
        CPPUNIT_ASSERT(w.c.first  == 0);
        CPPUNIT_ASSERT(w.c.second == 1);
    }
    
    void test_hop_3 () {
        const species s = HOPPER;
        const direction d = EAST;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(g.g[1][1].first);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.s        == s);
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 1);
        v.hop();
        CPPUNIT_ASSERT(!g.g[1][1].first);
        Creature& w = g.g[1][2].second;
        CPPUNIT_ASSERT(g.g[1][2].first);
        CPPUNIT_ASSERT(w.s        == s);
        CPPUNIT_ASSERT(w.c.first  == 1);
        CPPUNIT_ASSERT(w.c.second == 2);
    }
    
    void test_hop_4 () {
        const species s = HOPPER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(g.g[1][1].first);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.s        == s);
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 1);
        v.hop();
        CPPUNIT_ASSERT(!g.g[1][1].first);
        Creature& w = g.g[2][1].second;
        CPPUNIT_ASSERT(g.g[2][1].first);
        CPPUNIT_ASSERT(w.s        == s);
        CPPUNIT_ASSERT(w.c.first  == 2);
        CPPUNIT_ASSERT(w.c.second == 1);
    }
    
    // ---------
    // test_left
    // ---------
    
    void test_left_1 () {
        const species s = HOPPER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.left();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d == SOUTH);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_left_2 () {
        const species s = HOPPER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.left();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d ==  WEST);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_left_3 () {
        const species s = HOPPER;
        const direction d = EAST;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.left();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d == NORTH);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_left_4 () {
        const species s = HOPPER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.left();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d ==  EAST);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    // ----------
    // test_right
    // ----------
    
    void test_right_1 () {
        const species s = HOPPER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.right();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d == NORTH);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_right_2 () {
        const species s = HOPPER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.right();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d ==  EAST);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_right_3 () {
        const species s = HOPPER;
        const direction d = EAST;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.right();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d == SOUTH);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    void test_right_4 () {
        const species s = HOPPER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Creature v(s, d, x, NULL);
        v.right();
        CPPUNIT_ASSERT(v.s ==     s);
        CPPUNIT_ASSERT(v.d ==  WEST);
        CPPUNIT_ASSERT(v.c ==     x);
    }
    
    // -----------
    // test_infect
    // -----------
    
    void test_infect_1 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        const species s2 = FOOD;
        const direction d2 = SOUTH;
        const descriptor x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s2);
        g.g[1][1].second.infect();
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s1);
    }
    
    void test_infect_2 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const descriptor x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s1, d2, x2);
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s1);
        g.g[1][1].second.infect();
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s1);
    }
    
    void test_infect_3 () {
        const species s = ROVER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(!g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s);
        g.g[1][1].second.infect();
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(!g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s);
    }
    
    // -------------
    // test_if_empty
    // -------------
    
    void test_if_empty_1 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const descriptor x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s1, d2, x2);
        Creature& v1 = g.g[1][1].second;
        v1.pc = 2;
        v1.if_empty(5);
        CPPUNIT_ASSERT(v1.d  == WEST);
        CPPUNIT_ASSERT(v1.pc == 4);
    }
    
    void test_if_empty_2 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        Creature& v1 = g.g[1][1].second;
        v1.pc = 2;
        v1.if_empty(7);
        CPPUNIT_ASSERT(v1.d        == NORTH);
        CPPUNIT_ASSERT(v1.pc       ==     8);
        CPPUNIT_ASSERT(v1.c.first  ==     0);
        CPPUNIT_ASSERT(v1.c.second ==     1);
    }
    
    void test_if_empty_3 () {
        const species s1 = ROVER;
        const direction d1 = WEST;
        const descriptor x1 = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        Creature& v1 = g.g[1][1].second;
        v1.pc = 2;
        v1.if_empty(7);
        CPPUNIT_ASSERT(v1.d        ==  WEST);
        CPPUNIT_ASSERT(v1.pc       ==     8);
        CPPUNIT_ASSERT(v1.c.first  ==     1);
        CPPUNIT_ASSERT(v1.c.second ==     0);
    }
    
    // ------------
    // test_if_wall
    // ------------
    
    void test_if_wall_1 () {
        const species s = ROVER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v1 = g.g[0][1].second;
        v1.if_wall(5);
        CPPUNIT_ASSERT(v1.d        ==  EAST);
        CPPUNIT_ASSERT(v1.pc       ==     6);
        CPPUNIT_ASSERT(v1.c.first  ==     0);
        CPPUNIT_ASSERT(v1.c.second ==     1);
    }
    
    void test_if_wall_2 () {
        const species s1 = ROVER;
        const direction d1 = WEST;
        const descriptor x1 = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        Creature& v1 = g.g[1][1].second;
        v1.pc = 2;
        v1.if_wall(5);
        CPPUNIT_ASSERT(v1.d        ==  SOUTH);
        CPPUNIT_ASSERT(v1.pc       ==      4);
        CPPUNIT_ASSERT(v1.c.first  ==      1);
        CPPUNIT_ASSERT(v1.c.second ==      1);
    }
    
    void test_if_wall_3 () {
        const species s = ROVER;
        const direction d = WEST;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v1 = g.g[0][0].second;
        v1.if_wall(5);
        CPPUNIT_ASSERT(v1.d        ==  NORTH);
        CPPUNIT_ASSERT(v1.pc       ==      6);
        CPPUNIT_ASSERT(v1.c.first  ==      0);
        CPPUNIT_ASSERT(v1.c.second ==      0);
    }
    
    // --------------
    // test_if_random
    // --------------
    
    void test_if_random_1 () {
        srand(0);
        const species s = ROVER;
        const direction d = WEST;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.pc = 2;
        v.if_random(5);
        CPPUNIT_ASSERT(v.d == NORTH || v.d == SOUTH);
    }
    
    void test_if_random_2 () {
        srand(0);
        const species s = ROVER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.pc = 2;
        v.if_random(5);
        CPPUNIT_ASSERT(v.d == WEST || v.d == EAST);
    }
    
    void test_if_random_3 () {
        srand(0);
        const species s = ROVER;
        const direction d = EAST;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.pc = 2;
        v.if_random(5);
        CPPUNIT_ASSERT(v.d == NORTH || v.d == SOUTH);
    }
    
    // -------------
    // test_if_enemy
    // -------------
    
    void test_if_enemy_1 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        const species s2 = FOOD;
        const direction d2 = SOUTH;
        const descriptor x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s2);
        g.g[1][1].second.if_enemy(3);
        CPPUNIT_ASSERT(g.g[1][1].second.d == WEST);
    }
    
    void test_if_enemy_2 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const descriptor x1 = std::make_pair(1, 1);
        const species s2 = ROVER;
        const direction d2 = SOUTH;
        const descriptor x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        CPPUNIT_ASSERT(g.g[1][1].first);
        CPPUNIT_ASSERT(g.g[0][1].first);
        CPPUNIT_ASSERT(g.g[1][1].second.s == s1);
        CPPUNIT_ASSERT(g.g[0][1].second.s == s2);
        g.g[1][1].second.pc = 4;
        g.g[1][1].second.if_enemy(3);
        CPPUNIT_ASSERT(g.g[1][1].second.d == EAST);
    }
    
    void test_if_enemy_3 () {
        const species s = ROVER;
        const direction d = NORTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.pc = 4;
        v.if_enemy(3);
        CPPUNIT_ASSERT(v.d == EAST);
    }
    
    // -------
    // test_go
    // -------
    
    void test_go_1 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.go(3);
        CPPUNIT_ASSERT(v.d == EAST);
    }
    
    void test_go_2 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.go(5);
        CPPUNIT_ASSERT(v.d == WEST);
    }
    
    void test_go_3 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.go(7);
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 0);
    }
    
    // --------------
    // test_reprogram
    // --------------
    
    void test_reprogram_1 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.p.size() ==    11);
        CPPUNIT_ASSERT(v.s        == ROVER);
        v.reprogram(FOOD);
        CPPUNIT_ASSERT(v.p.size() ==    2);
        CPPUNIT_ASSERT(v.s        == FOOD);
        
    }
    
    void test_reprogram_2 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.p.size() ==    11);
        CPPUNIT_ASSERT(v.s        == ROVER);
        v.reprogram(TRAP);
        CPPUNIT_ASSERT(v.p.size() ==    5);
        CPPUNIT_ASSERT(v.s        == TRAP);
    }
    
    void test_reprogram_3 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[1][1].second;
        CPPUNIT_ASSERT(v.p.size() ==    11);
        CPPUNIT_ASSERT(v.s        == ROVER);
        v.reprogram(ROVER);
        CPPUNIT_ASSERT(v.p.size() ==    11);
        CPPUNIT_ASSERT(v.s        == ROVER);
    }
    
    // ------------
    // test_execute
    // ------------
    
    void test_execute_1 () {
        const species s = ROVER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[1][1].second;
        v.pc = 3;
        v.execute();
        CPPUNIT_ASSERT(v.d == SOUTH);
    }
    
    void test_execute_2 () {
        const species s = ROVER;
        const direction d = WEST;
        const descriptor x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[1][1].second;
        v.pc = 5;
        v.execute();
        CPPUNIT_ASSERT(v.d == NORTH);
    }
    
    void test_execute_3 () {
        const species s = ROVER;
        const direction d = SOUTH;
        const descriptor x = std::make_pair(0, 0);
        Grid g(3, 3);
        g.add(s, d, x);
        Creature& v = g.g[0][0].second;
        v.pc = 7;
        v.execute();
        CPPUNIT_ASSERT(v.c.first  == 1);
        CPPUNIT_ASSERT(v.c.second == 0);
    }
    
    // ----------
    // test_print
    // ----------
    
    void test_print_1 () {
        Creature v(ROVER, WEST, descriptor(0,0), NULL);
        std::ostringstream w;
        v.print(w);
        CPPUNIT_ASSERT(w.str() == "r");
    }
    
    void test_print_2 () {
        Creature v(FOOD, WEST, descriptor(0,0), NULL);
        std::ostringstream w;
        v.print(w);
        CPPUNIT_ASSERT(w.str() == "f");
    }
    
    void test_print_3 () {
        Creature v(TRAP, WEST, descriptor(0,0), NULL);
        std::ostringstream w;
        v.print(w);
        CPPUNIT_ASSERT(w.str() == "t");
    }
    
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestCreature);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_left_1);
    CPPUNIT_TEST(test_left_2);
    CPPUNIT_TEST(test_left_3);
    CPPUNIT_TEST(test_left_4);
    CPPUNIT_TEST(test_right_1);
    CPPUNIT_TEST(test_right_2);
    CPPUNIT_TEST(test_right_3);
    CPPUNIT_TEST(test_right_4);
    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);
    CPPUNIT_TEST(test_if_empty_1);
    CPPUNIT_TEST(test_if_empty_2);
    CPPUNIT_TEST(test_if_empty_3);
    CPPUNIT_TEST(test_if_wall_1);
    CPPUNIT_TEST(test_if_wall_2);
    CPPUNIT_TEST(test_if_wall_3);
    CPPUNIT_TEST(test_if_random_1);
    CPPUNIT_TEST(test_if_random_2);
    CPPUNIT_TEST(test_if_random_3);
    CPPUNIT_TEST(test_if_enemy_1);
    CPPUNIT_TEST(test_if_enemy_2);
    CPPUNIT_TEST(test_if_enemy_3);
    CPPUNIT_TEST(test_go_1);
    CPPUNIT_TEST(test_go_2);
    CPPUNIT_TEST(test_go_3);
    CPPUNIT_TEST(test_reprogram_1);
    CPPUNIT_TEST(test_reprogram_2);
    CPPUNIT_TEST(test_reprogram_3);
    CPPUNIT_TEST(test_execute_1);
    CPPUNIT_TEST(test_execute_2);
    CPPUNIT_TEST(test_execute_3);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();};

struct TestGrid : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------
    
    void test_constructor_1 () {
        Grid x(2, 3);
        CPPUNIT_ASSERT(x.g.size()         == 2);
        CPPUNIT_ASSERT(x.g.front().size() == 3);
        CPPUNIT_ASSERT(x.n                == 0);
    }
    
    void test_constructor_2 () {
        Grid x(21, 21);
        CPPUNIT_ASSERT(x.g.size()         == 21);
        CPPUNIT_ASSERT(x.g.front().size() == 21);
        CPPUNIT_ASSERT(x.n                ==  0);
    }
    
    void test_constructor_3 () {
        Grid x(0, 0);
        CPPUNIT_ASSERT(x.g.size()         == 0);
        CPPUNIT_ASSERT(x.n                == 0);
    }
    
    // --------
    // test_add
    // --------
    
    void test_add_1 () {
        try {
            const species             s = HOPPER;
            const direction           d = WEST;
            const std::pair<int, int> x = std::make_pair(1, 1);
            Grid g(3, 3);
            g.add(s, d, x);
            CPPUNIT_ASSERT(g.g[1][1].first);
            Creature& v = g.g[1][1].second;
            CPPUNIT_ASSERT(v.s        == s);
            CPPUNIT_ASSERT(v.c.first  == 1);
            CPPUNIT_ASSERT(v.c.second == 1);
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_add_2 () {
        try {
            const species             s = HOPPER;
            const direction           d = WEST;
            const std::pair<int, int> x = std::make_pair(4, 1);
            Grid g(3, 3);
            g.add(s, d, x);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {}
    }
    
    void test_add_3 () {
        try {
            const species             s = HOPPER;
            const direction           d = WEST;
            const std::pair<int, int> x = std::make_pair(1, 1);
            Grid g(3, 3);
            g.add(s, d, x);
            g.add(s, d, x);
            CPPUNIT_ASSERT(false);
            
        }
        catch (...) {}
    }
    
    // -----------
    // test_remove
    // -----------
    
    void test_remove_1 () {
        try {
            const species             s = HOPPER;
            const direction           d = WEST;
            const std::pair<int, int> x = std::make_pair(1, 1);
            Grid g(3, 3);
            g.add(s, d, x);
            CPPUNIT_ASSERT(g.g[1][1].first);
            Creature& v = g.g[1][1].second;
            CPPUNIT_ASSERT(v.s        == s);
            CPPUNIT_ASSERT(v.c.first  == 1);
            CPPUNIT_ASSERT(v.c.second == 1);
            g.remove(x);
        }
        catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_remove_2 () {
        try {
            const species             s = HOPPER;
            const direction           d = WEST;
            const std::pair<int, int> x = std::make_pair(1, 1);
            Grid g(3, 3);
            g.add(s, d, x);
            g.remove(x);
            g.remove(x);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {}
    }
    
    void test_remove_3 () {
        try {
            const std::pair<int, int> x = std::make_pair(1, 1);
            Grid g(3, 3);
            g.remove(x);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {}
    }
    
    // ------------
    // test_is_wall
    // ------------
    
    void test_is_wall_1 () {
        Grid g(3, 3);
        CPPUNIT_ASSERT(g.is_wall(std::make_pair(3, 3)));
    }
    
    void test_is_wall_2 () {
        Grid g(3, 3);
        CPPUNIT_ASSERT(!g.is_wall(std::make_pair(0, 0)));
    }
    
    void test_is_wall_3 () {
        Grid g(3, 3);
        CPPUNIT_ASSERT(g.is_wall(std::make_pair(0, 3)));
    }
    
    // -------------
    // test_is_empty
    // -------------
    
    void test_is_empty_1 () {
        const species             s = HOPPER;
        const direction           d = WEST;
        const std::pair<int, int> x = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s, d, x);
        CPPUNIT_ASSERT(!g.is_empty(std::make_pair(1, 1)));
    }
    
    void test_is_empty_2 () {
        Grid g(3, 3);
        CPPUNIT_ASSERT(g.is_empty(std::make_pair(0, 0)));
    }
    
    void test_is_empty_3 () {
        Grid g(3, 3);
        CPPUNIT_ASSERT(g.is_empty(std::make_pair(2, 2)));
        CPPUNIT_ASSERT(g.is_wall(std::make_pair(3, 3)));
    }
    
    // -------------
    // test_is_enemy
    // -------------
    
    void test_is_enemy_1 () {
        const species s1 = ROVER;
        const species s2 = TRAP;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const std::pair<int, int> x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        CPPUNIT_ASSERT(g.is_enemy(x1, x2) != NULL);
        CPPUNIT_ASSERT(g.is_enemy(x2, x1) != NULL);
    }
    
    void test_is_enemy_2 () {
        const species s1 = ROVER;
        const species s2 = TRAP;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const std::pair<int, int> x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        CPPUNIT_ASSERT(g.is_enemy(x1, x2) != NULL);
        CPPUNIT_ASSERT(g.is_enemy(x2, x1) != NULL);
        g.g[1][1].second.infect();
        CPPUNIT_ASSERT(g.is_enemy(x1, x2) == NULL);
        CPPUNIT_ASSERT(g.is_enemy(x2, x1) == NULL);
    }
    
    void test_is_enemy_3 () {
        const species s1 = ROVER;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        CPPUNIT_ASSERT(g.is_enemy(x1, x1) == NULL);
    }
    
    // -------------
    // test_displace
    // -------------
    
    void test_displace_1 () {
        std::pair<int, int> x(1, 1);
        Grid g(0, 0);
        std::pair<int, int> y = g.displace(WEST, x);
        CPPUNIT_ASSERT(x.first  == 1);
        CPPUNIT_ASSERT(x.second == 1);
        CPPUNIT_ASSERT(y.first  == 1);
        CPPUNIT_ASSERT(y.second == 0);
    }
    
    void test_displace_2 () {
        std::pair<int, int> x(1, 1);
        Grid g(0, 0);
        std::pair<int, int> y = g.displace(SOUTH, x);
        CPPUNIT_ASSERT(x.first  == 1);
        CPPUNIT_ASSERT(x.second == 1);
        CPPUNIT_ASSERT(y.first  == 2);
        CPPUNIT_ASSERT(y.second == 1);
    }
    
    void test_displace_3 () {
        std::pair<int, int> x(1, 1);
        Grid g(0, 0);
        std::pair<int, int> y = g.displace(NORTH, x);
        CPPUNIT_ASSERT(x.first  == 1);
        CPPUNIT_ASSERT(x.second == 1);
        CPPUNIT_ASSERT(y.first  == 0);
        CPPUNIT_ASSERT(y.second == 1);
    }
    
    // ---------
    // test_list
    // ---------
    
    void test_list_1 () {
        const species s1 = ROVER;
        const species s2 = TRAP;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const std::pair<int, int> x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        Creature& v1 = g.g[1][1].second;
        Creature& v2 = g.g[0][1].second;
        std::list<Creature*> l = g.list();
        CPPUNIT_ASSERT(l.size()  ==   2);
        CPPUNIT_ASSERT(l.front() == &v2);
        CPPUNIT_ASSERT(l.back()  == &v1);
    }
    
    void test_list_2 () {
        const species s1 = ROVER;
        const species s2 = TRAP;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const std::pair<int, int> x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        Creature& v1 = g.g[1][1].second;
        Creature& v2 = g.g[0][1].second;
        std::list<Creature*> l = g.list();
        CPPUNIT_ASSERT(l.size()  ==   2);
        CPPUNIT_ASSERT(l.front() == &v2);
        CPPUNIT_ASSERT(l.back()  == &v1);
        g.remove(x2);
        CPPUNIT_ASSERT(l.size()  ==   2);
        CPPUNIT_ASSERT(l.front() == &v2);
        CPPUNIT_ASSERT(l.back()  == &v1);
        l = g.list();
        CPPUNIT_ASSERT(l.size()   ==   1);
        CPPUNIT_ASSERT(l.front()  == &v1);
    }
    
    void test_list_3 () {
        const species s1 = ROVER;
        const species s2 = TRAP;
        const direction d1 = NORTH;
        const std::pair<int, int> x1 = std::make_pair(1, 1);
        const direction d2 = SOUTH;
        const std::pair<int, int> x2 = std::make_pair(0, 1);
        Grid g(3, 3);
        g.add(s1, d1, x1);
        g.add(s2, d2, x2);
        Creature& v1 = g.g[1][1].second;
        Creature& v2 = g.g[0][1].second;
        std::list<Creature*> l = g.list();
        CPPUNIT_ASSERT(l.size()  ==   2);
        CPPUNIT_ASSERT(l.front() == &v2);
        CPPUNIT_ASSERT(l.back()  == &v1);
        g.add(s1, d1, std::make_pair(1, 0));
        CPPUNIT_ASSERT(l.size()  ==   2);
        CPPUNIT_ASSERT(l.front() == &v2);
        CPPUNIT_ASSERT(l.back()  == &v1);
        l = g.list();
        CPPUNIT_ASSERT(l.size()  ==   3);
    }
    
    // ----------
    // test_print
    // ----------
    
    void test_print_1 () {
        std::ostringstream w;
        Grid g(3, 3);
        std::string s = "  012\n0 ...\n1 ...\n2 ...\n";
        g.print(w);
        CPPUNIT_ASSERT(w.str() == s);
    }
    
    void test_print_2 () {
        std::ostringstream w;
        Grid g(3, 3);
        g.add(FOOD, WEST, std::make_pair(0,0));
        std::string s = "  012\n0 f..\n1 ...\n2 ...\n";
        g.print(w);
        CPPUNIT_ASSERT(w.str() == s);
    }
    
    void test_print_3 () {
        std::ostringstream w;
        Grid g(3, 3);
        g.add(FOOD, WEST, std::make_pair(0,0));
        g.add(ROVER, WEST, std::make_pair(2,2));
        std::string s = "  012\n0 f..\n1 ...\n2 ..r\n";
        g.print(w);
        CPPUNIT_ASSERT(w.str() == s);
    }
    
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestGrid);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_add_1);
    CPPUNIT_TEST(test_add_2);
    CPPUNIT_TEST(test_add_3);
    CPPUNIT_TEST(test_remove_1);
    CPPUNIT_TEST(test_remove_2);
    CPPUNIT_TEST(test_remove_3);
    CPPUNIT_TEST(test_is_wall_1);
    CPPUNIT_TEST(test_is_wall_2);
    CPPUNIT_TEST(test_is_wall_3);
    CPPUNIT_TEST(test_is_empty_1);
    CPPUNIT_TEST(test_is_empty_2);
    CPPUNIT_TEST(test_is_empty_3);
    CPPUNIT_TEST(test_is_enemy_1);
    CPPUNIT_TEST(test_is_enemy_2);
    CPPUNIT_TEST(test_is_enemy_3);
    CPPUNIT_TEST(test_displace_1);
    CPPUNIT_TEST(test_displace_2);
    CPPUNIT_TEST(test_displace_3);
    CPPUNIT_TEST(test_list_1);
    CPPUNIT_TEST(test_list_2);
    CPPUNIT_TEST(test_list_3);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();};

struct TestDarwin : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------
    
    void test_constructor_1 () {
        Darwin d(3, 3);
        CPPUNIT_ASSERT(d.g.g.size() == 3);
        CPPUNIT_ASSERT(d.g.g.front().size() == 3);
    }
    
    void test_constructor_2 () {
        Darwin d(21, 16);
        CPPUNIT_ASSERT(d.g.g.size() == 21);
        CPPUNIT_ASSERT(d.g.g.front().size() == 16);
    }
    
    void test_constructor_3 () {
        Darwin d(0, 0);
        CPPUNIT_ASSERT(d.g.g.size() == 0);
    }
    
    // -----------
    // test_create
    // -----------
    
    void test_create_1 () {
        Darwin d(8, 8);
        d.create(FOOD, WEST, 1, 2);
        Creature& v = d.g.g[1][2].second;
        CPPUNIT_ASSERT(v.s        == FOOD);
        CPPUNIT_ASSERT(v.d        == WEST);
        CPPUNIT_ASSERT(v.c.first  ==    1);
        CPPUNIT_ASSERT(v.c.second ==    2);
    }
    
    void test_create_2 () {
        Darwin d(8, 8);
        d.create(FOOD, WEST, 1, 2);
        d.create(HOPPER, NORTH, 2, 1);
        Creature& v2 = d.g.g[2][1].second;
        CPPUNIT_ASSERT(v2.s        == HOPPER);
        CPPUNIT_ASSERT(v2.d        ==  NORTH);
        CPPUNIT_ASSERT(v2.c.first  ==     2);
        CPPUNIT_ASSERT(v2.c.second ==     1);
    }
    
    void test_create_3 () {
        Darwin d(8, 8);
        try {
            d.create(BEST, WEST, 9, 9);
            CPPUNIT_ASSERT(false);
        }
        catch (...) {};
    }
    
    // -------------
    // test_simulate
    // -------------
    
    void test_simulate_1 () {
        Darwin d(3, 3);
        d.create(FOOD, SOUTH, 0, 0);
        d.create(FOOD, NORTH, 2, 2);
        std::ostringstream w;
        d.simulate(0, 1, w);
        CPPUNIT_ASSERT(d.g.list().size()    ==    2);
        CPPUNIT_ASSERT(d.g.g[0][0].second.d == SOUTH);
        CPPUNIT_ASSERT(d.g.g[2][2].second.d == NORTH);
    }
    
    void test_simulate_2 () {
        Darwin d(3, 3);
        d.create(FOOD, SOUTH, 0, 0);
        d.create(FOOD, NORTH, 2, 2);
        std::ostringstream w;
        d.simulate(1, 1, w);
        CPPUNIT_ASSERT(d.g.list().size()    ==    2);
        CPPUNIT_ASSERT(d.g.g[0][0].second.d == EAST);
        CPPUNIT_ASSERT(d.g.g[2][2].second.d == WEST);
    }
    
    void test_simulate_3 () {
        Darwin d(3, 3);
        d.create(FOOD, SOUTH, 0, 0);
        d.create(FOOD, NORTH, 2, 2);
        std::ostringstream w;
        d.simulate(2, 1, w);
        CPPUNIT_ASSERT(d.g.list().size()    ==    2);
        CPPUNIT_ASSERT(d.g.g[0][0].second.d == NORTH);
        CPPUNIT_ASSERT(d.g.g[2][2].second.d == SOUTH);
    }
    
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_create_1);
    CPPUNIT_TEST(test_create_2);
    CPPUNIT_TEST(test_create_3);
    CPPUNIT_TEST(test_simulate_1);
    CPPUNIT_TEST(test_simulate_2);
    CPPUNIT_TEST(test_simulate_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    
    tr.addTest(TestCreature::suite());
    tr.addTest(TestGrid::suite());
    tr.addTest(TestDarwin::suite());
    
    tr.run();
    
    cout << "Done." << endl;
    return 0;}