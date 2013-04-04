// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <vector> //vector

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
    // test creature default constructor
    void test_creature_default_creature_1 (){
        Creature x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_creature_default_creature_2 (){
        Creature x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_creature_default_creature_3 (){
        Creature x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }
	
	//test creature int constructor
	
	void test_creature_int_constuctors_1 (){
		Creature x(0);
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }
	
	void test_creature_int_constuctors_2 (){
		Creature x(1);
        CPPUNIT_ASSERT(x.direction == 1);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }
	
	void test_creature_int_constuctors_3 (){
		Creature x(2);
        CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "C");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test creature reset

    void test_creature_reset_1 (){
        Creature x(2);
		x.toRead = false;
		CPPUNIT_ASSERT(x.toRead == false);
		x.reset();
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_creature_reset_2 (){
        Creature x(1);
		x.toRead = false;
		CPPUNIT_ASSERT(x.toRead == false);
		x.reset();
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_creature_reset_3 (){
        Creature x(3);
		x.toRead = false;
		CPPUNIT_ASSERT(x.toRead == false);
		x.reset();
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test creature getName

    void test_creature_getName_1 (){
        Creature x(3);
		CPPUNIT_ASSERT(x.name == "C");
		CPPUNIT_ASSERT(x.getName() == "C");
    }

    void test_creature_getName_2 (){
        Creature x(0);
		CPPUNIT_ASSERT(x.name == "C");
		CPPUNIT_ASSERT(x.getName() == "C");
    }

    void test_creature_getName_3 (){
        Creature x(1);
		CPPUNIT_ASSERT(x.name == "C");
		CPPUNIT_ASSERT(x.getName() == "C");
    }

    // test creature getDirection

    void test_creature_getDirection_1(){
        Creature x(2);
		CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.getDirection()== 2);
    }

    void test_creature_getDirection_2(){
        Creature x(0);
		CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.getDirection()== 0);
    }

    void test_creature_getDirection_3(){
        Creature x(3);
		CPPUNIT_ASSERT(x.direction == 3);
        CPPUNIT_ASSERT(x.getDirection()== 3);
    }

    // test creature setD

    void test_creature_setD_1(){
        Creature x;
        CPPUNIT_ASSERT(x.direction == 0);
		CPPUNIT_ASSERT(x.getDirection() == 0);
		x.setD(3);
        CPPUNIT_ASSERT(x.direction == 3);
		CPPUNIT_ASSERT(x.getDirection()== 3);
    }

    void test_creature_setD_2(){
        Creature x(2);
        CPPUNIT_ASSERT(x.direction == 2);
		CPPUNIT_ASSERT(x.getDirection() == 2);
		x.setD(1);
        CPPUNIT_ASSERT(x.direction == 1);
		CPPUNIT_ASSERT(x.getDirection()== 1);
    }

    void test_creature_setD_3(){
        Creature x(1);
        CPPUNIT_ASSERT(x.direction == 1);
		CPPUNIT_ASSERT(x.getDirection() == 1);
		x.setD(0);
        CPPUNIT_ASSERT(x.direction == 0);
		CPPUNIT_ASSERT(x.getDirection()== 0);
    }

    // test creature virtual action

    void test_creature_virtual_action_1(){
		Creature a;
		Creature b;
		Creature c;
        Creature* x = &a;
        Creature* y = &b;
		bool bo = true;
		CPPUNIT_ASSERT(c.action(x,y,true,bo) == false);
    }

    void test_creature_virtual_action_2(){
		Creature a;
		Creature b;
		Creature c;
        Creature* x = &a;
        Creature* y = &b;
		bool bo = false;
		CPPUNIT_ASSERT(c.action(x,y,false,bo) == false);
    }

    void test_creature_virtual_action_3(){
		Creature a;
		Creature b;
		Creature c;
        Creature* x = &a;
        Creature* y = &b;
		bool bo = false;
		CPPUNIT_ASSERT(c.action(x,y,true,bo) == false);
    }

    // test creature left
    void test_creature_left_1(){
        Creature x;
        CPPUNIT_ASSERT(x.direction == 0);
		CPPUNIT_ASSERT(x.getDirection() == 0);
        x.left();
        CPPUNIT_ASSERT(x.direction == 3);
		CPPUNIT_ASSERT(x.getDirection() == 3);
    }

    void test_creature_left_2(){
        Creature x(2);
        CPPUNIT_ASSERT(x.direction == 2);
		CPPUNIT_ASSERT(x.getDirection() == 2);
        x.left();
        CPPUNIT_ASSERT(x.direction == 1);
		CPPUNIT_ASSERT(x.getDirection() == 1);
    }

    void test_creature_left_3(){
        Creature x(1);
        CPPUNIT_ASSERT(x.direction == 1);
		CPPUNIT_ASSERT(x.getDirection() == 1);
        x.left();
        CPPUNIT_ASSERT(x.direction == 0);
		CPPUNIT_ASSERT(x.getDirection() == 0);
    }

    // test creature right
    void test_creature_right_1(){
        Creature x(3);
        CPPUNIT_ASSERT(x.direction == 3);
		CPPUNIT_ASSERT(x.getDirection() == 3);
        x.right();
        CPPUNIT_ASSERT(x.direction == 0);
		CPPUNIT_ASSERT(x.getDirection() == 0);
    }

    void test_creature_right_2(){
        Creature x(2);
        CPPUNIT_ASSERT(x.direction == 2);
		CPPUNIT_ASSERT(x.getDirection() == 2);
        x.right();
        CPPUNIT_ASSERT(x.direction == 3);
		CPPUNIT_ASSERT(x.getDirection() == 3);
    }

    void test_creature_right_3(){
        Creature x(1);
        CPPUNIT_ASSERT(x.direction == 1);
		CPPUNIT_ASSERT(x.getDirection() == 1);
        x.right();
        CPPUNIT_ASSERT(x.direction == 2);
		CPPUNIT_ASSERT(x.getDirection() == 2);
    }
	
	// test creature hop

    void test_creature_hop_1 (){
        Game<3,3,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n\n");
		Hopper h = 1;
        g.put(h,2,2);
		g.printGrid(beforeHop);
		CPPUNIT_ASSERT(beforeHop.str() == "0 ...\n1 ...\n2 ..h\n\n");
        g.run(dummy);
		g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 ...\n1 ..h\n2 ...\n\n");
    }

    void test_creature_hop_2 (){
        Game<5,5,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
		Hopper h = 2;
        g.put(h,4,2);
		// g.printGrid(cout);
		g.printGrid(beforeHop);
		CPPUNIT_ASSERT(beforeHop.str() == "0 .....\n1 .....\n2 .....\n3 .....\n4 ..h..\n\n");
        g.run(dummy);
		g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 .....\n1 .....\n2 .....\n3 .....\n4 ...h.\n\n");
    }

    void test_creature_hop_3 (){
        Game<2,2,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 ..\n\n");
		Hopper h = 0;
        g.put(h,1,1);
		g.printGrid(beforeHop);
		CPPUNIT_ASSERT(beforeHop.str() == "0 ..\n1 .h\n\n");
        g.run(dummy);
		g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 ..\n1 h.\n\n");
    }
	
	//test creature isEnemy

	void test_creature_isEnemy_1 (){
        Game<2,2,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 ..\n\n");
		Creature* x;
		Creature* y;
		Food f1 = 0;
		Rover r2 = 1;
		x = &f1;
		y = &r2;
		g.put(f1,0,1);
        g.put(r2,1,1);
		g.printGrid(beforeHop);
		// g.printGrid(cout);
		CPPUNIT_ASSERT(beforeHop.str() == "0 .f\n1 .r\n\n");
        g.run(dummy);
		CPPUNIT_ASSERT(r2.isEnemy(x, y) == true);
		g.printGrid(afterHop);
		// g.printGrid(cout);
		CPPUNIT_ASSERT(afterHop.str() == "0 .r\n1 .r\n\n");
    }

    void test_creature_isEnemy_2 (){
        Game<3,3,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n\n");
        Creature* x;
        Creature* y;
        Trap t1 = 0;
        Rover r2 = 1;
        x = &t1;
        y = &r2;
        g.put(t1,2,2);
        g.put(r2,1,1);
        g.printGrid(beforeHop);
        CPPUNIT_ASSERT(beforeHop.str() == "0 ...\n1 .r.\n2 ..t\n\n");
        g.run(dummy);
        CPPUNIT_ASSERT(r2.isEnemy(x, y) == true);
        g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 .r.\n1 ...\n2 ..t\n\n");
    }

    void test_creature_isEnemy_3 (){
        Game<4,4,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ....\n1 ....\n2 ....\n3 ....\n\n");
        Creature* x;
        Creature* y;
        Creature* z;
        Food f1 = 0;
        Rover r2 = 1;
        x = &f1;
        y = &r2;
        z = NULL;
        g.put(f1,0,1);
        g.put(r2,1,1);
        g.printGrid(beforeHop);
        CPPUNIT_ASSERT(beforeHop.str() == "0 .f..\n1 .r..\n2 ....\n3 ....\n\n");
        g.run(dummy);
        CPPUNIT_ASSERT(r2.isEnemy(x, y) == true);
        CPPUNIT_ASSERT(r2.isEnemy(x, z) == false);
        g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 .r..\n1 .r..\n2 ....\n3 ....\n\n");
    }

    // test creature isEmpty

    void test_creature_isEmpty_1 (){
        Game<4,4,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(before.str() == "0 ....\n1 ....\n2 ....\n3 ....\n\n");
        Creature* x;
        Creature* y;
        Creature* z;
        Food f1 = 0;
        Rover r2 = 1;
        Hopper h1 = 2;
        x = &f1;
        y = &r2;
        z = &h1;
        g.put(f1,0,1);
        g.put(r2,1,1);
        g.put(h1,2,2);
        g.printGrid(beforeHop);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(beforeHop.str() == "0 .f..\n1 .r..\n2 ..h.\n3 ....\n\n");
        g.run(dummy);
        CPPUNIT_ASSERT(r2.isEmpty(x, y) == false);
        y = NULL;
        CPPUNIT_ASSERT(h1.isEmpty(z, y) == true);
        g.printGrid(afterHop);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(afterHop.str() == "0 .r..\n1 .r..\n2 ...h\n3 ....\n\n");
    }
    void test_creature_isEmpty_2 (){
        Creature* x;
        Creature* y;
        Creature* z;
        Food f1 = 0;
        Rover r2 = 1;
        Hopper h1 = 2;
        x = &f1;
        y = &r2;
        z = &h1;
        
        CPPUNIT_ASSERT(r2.isEmpty(x, y) == false);
        z = NULL;
        CPPUNIT_ASSERT(h1.isEmpty(x, z) == true);
        x = NULL;
        CPPUNIT_ASSERT(f1.isEmpty(z, x) == true);
    }

    void test_creature_isEmpty_3 (){
        Creature* x;
        Creature* y;
        Creature* z;
        Food f1 = 0;
        Rover r2 = 1;
        Hopper h1 = 2;
        x = &f1;
        y = &r2;
        z = &h1;
        
        CPPUNIT_ASSERT(r2.isEmpty(x, y) == false);
        z = NULL;
        CPPUNIT_ASSERT(h1.isEmpty(x, z) == true);
        x = NULL;
        CPPUNIT_ASSERT(f1.isEmpty(z, x) == true);
        y = NULL;
        x = &r2;
        CPPUNIT_ASSERT(f1.isEmpty(y, x) == false);

    }

    // test food default constructor 

    void test_food_default_constructor_1 (){
        Food x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_food_default_constructor_2 (){
        Food x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_food_default_constructor_3 (){
        Food x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test food int constructor
    void test_food_int_constructor_1 (){
        Food x(2);
        CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_food_int_constructor_2 (){
        Food x(3);
        CPPUNIT_ASSERT(x.direction == 3);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_food_int_constructor_3 (){
        Food x = 1;
        CPPUNIT_ASSERT(x.direction == 1);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "f");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    //test food getName

    void test_food_getName_1 (){
        Food x = 1;
        CPPUNIT_ASSERT(x.getName() == "f");
    }

    void test_food_getName_2 (){
        Food x = 2;
        CPPUNIT_ASSERT(x.getName() == "f");
    }

    void test_food_getName_3 (){
        Food x = 3;
        CPPUNIT_ASSERT(x.getName() == "f");
    }
    
    // test food action

    void test_food_action_1 (){
        Game<2,2,1,1> g;
        Food x = 2;
        Food y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream u;
        g.run(u);
        CPPUNIT_ASSERT(x.getDirection() == 1);
        CPPUNIT_ASSERT(y.getDirection() == 2);
    }

    void test_food_action_2 (){
        Game<2,2,1,1> g;
        Food x = 0;
        Food y = 1;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream u;
        g.run(u);
        CPPUNIT_ASSERT(x.getDirection() == 3);
        CPPUNIT_ASSERT(y.getDirection() == 0);
    }

    void test_food_action_3 (){
        Game<2,2,1,1> g;
        Food x = 1;
        Food y = 2;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream u;
        g.run(u);
        CPPUNIT_ASSERT(x.getDirection() == 0);
        CPPUNIT_ASSERT(y.getDirection() == 1);
    }

    // hopper food default constructor 

    void test_hopper_default_constructor_1 (){
        Hopper x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_hopper_default_constructor_2 (){
        Hopper x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_hopper_default_constructor_3 (){
        Hopper x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test food int constructor
    void test_hopper_int_constructor_1 (){
        Hopper x(2);
        CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_hopper_int_constructor_2 (){
        Hopper x(3);
        CPPUNIT_ASSERT(x.direction == 3);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_hopper_int_constructor_3 (){
        Hopper x = 1;
        CPPUNIT_ASSERT(x.direction == 1);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "h");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    //test food getName

    void test_hopper_getName_1 (){
        Hopper x;
        CPPUNIT_ASSERT(x.getName() == "h");
    }

    void test_hopper_getName_2 (){
        Hopper x = 2;
        CPPUNIT_ASSERT(x.getName() == "h");
    }

    void test_hopper_getName_3 (){
        Hopper x(3);
        CPPUNIT_ASSERT(x.getName() == "h");
    }

    // test hopper action

    void test_hopper_action_1 (){
        Game<2,2,1,1> g;
        Hopper x = 3;
        Hopper y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 hh\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ..\n1 hh\n\n");
    }

    void test_hopper_action_2 (){
        Game<3,3,1,1> g;
        Hopper x = 3;
        Hopper y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 hh.\n2 ...\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ...\n1 ...\n2 hh.\n\n");
    }

    void test_hopper_action_3 (){
        Game<2,2,1,1> g;
        Hopper x = 0;
        Hopper y = 0;
        g.put(x,1,1);
        g.put(y,0,1);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 .h\n1 .h\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 h.\n1 h.\n\n");
    }

        // test rover default constructor 

    void test_rover_default_constructor_1 (){
        Rover x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_rover_default_constructor_2 (){
        Rover x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_rover_default_constructor_3 (){
        Rover x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test rover int constructor
    void test_rover_int_constructor_1 (){
        Rover x(2);
        CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_rover_int_constructor_2 (){
        Rover x(3);
        CPPUNIT_ASSERT(x.direction == 3);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_rover_int_constructor_3 (){
        Rover x = 1;
        CPPUNIT_ASSERT(x.direction == 1);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "r");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    //test food getName

    void test_rover_getName_1 (){
        Rover x;
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    void test_rover_getName_2 (){
        Rover x = 2;
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    void test_rover_getName_3 (){
        Rover x(3);
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    // test rover action

    void test_rover_action_1 (){
        Game<2,2,1,1> g;
        Rover x = 3;
        Rover y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 rr\n\n");
        g.run(u);
        // g.printGrid(cout);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ..\n1 rr\n\n");
    }

    void test_rover_action_2 (){
        Game<2,2,1,1> g;
        Rover x = 1;
        Rover y = 1;
        Food a = 0;
        Food b = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        g.put(a,0,0);
        g.put(b,0,1);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ff\n1 rr\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 rr\n1 rr\n\n");
    }

    void test_rover_action_3 (){
        Game<2,2,1,1> g;
        Rover a = 1;
        Rover b = 1;
        g.put(a,1,1);
        g.put(b,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 rr\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 rr\n1 ..\n\n");
    }

    // test Trap default constructor 

    void test_trap_default_constructor_1 (){
        Trap x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_trap_default_constructor_2 (){
        Trap x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_trap_default_constructor_3 (){
        Trap x;
        CPPUNIT_ASSERT(x.direction == 0);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    // test rover int constructor
    void test_trap_int_constructor_1 (){
        Trap x(2);
        CPPUNIT_ASSERT(x.direction == 2);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_trap_int_constructor_2 (){
        Trap x(3);
        CPPUNIT_ASSERT(x.direction == 3);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    void test_trap_int_constructor_3 (){
        Trap x = 1;
        CPPUNIT_ASSERT(x.direction == 1);
        CPPUNIT_ASSERT(x.program_counter == 0);
        CPPUNIT_ASSERT(x.name == "t");
        CPPUNIT_ASSERT(x.toRead == true);
    }

    //test trap getName

    void test_trap_getName_1 (){
        Rover x;
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    void test_trap_getName_2 (){
        Rover x = 2;
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    void test_trap_getName_3 (){
        Rover x(3);
        CPPUNIT_ASSERT(x.getName() == "r");
    }

    // test trap action

    void test_trap_action_1 (){
        Game<2,2,1,1> g;
        Trap x = 3;
        Trap y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 tt\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ..\n1 tt\n\n");
    }

    void test_trap_action_2 (){
        Game<2,2,1,1> g;
        Trap x = 3;
        Trap y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 tt\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ..\n1 tt\n\n");
    }

    void test_trap_action_3 (){
        Game<2,2,1,1> g;
        Trap x = 3;
        Trap y = 3;
        g.put(x,1,1);
        g.put(y,1,0);
        ostringstream before, after,u;
        // g.printGrid(cout);
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ..\n1 tt\n\n");
        g.run(u);
        g.printGrid(after);
        CPPUNIT_ASSERT(after.str() == "0 ..\n1 tt\n\n");
    }

    // test Game default constructor

    void test_game_default_1 (){
        Game<2,2,1,1> g;     
        CPPUNIT_ASSERT(g._Height == 2);
        CPPUNIT_ASSERT(g._Width == 2);
        CPPUNIT_ASSERT(g.turn == 0);
        CPPUNIT_ASSERT(g.Food_index == 0);
        CPPUNIT_ASSERT(g.Hopper_index == 0);
        CPPUNIT_ASSERT(g.Rover_index == 0);
        CPPUNIT_ASSERT(g.Trap_index == 0);
        CPPUNIT_ASSERT(g.Best_index == 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
        CPPUNIT_ASSERT(g.isMoved[0][0] == false);
    }

    void test_game_default_2 (){
        Game<5,5,1,1> g;     
        CPPUNIT_ASSERT(g._Height == 5);
        CPPUNIT_ASSERT(g._Width == 5);
        CPPUNIT_ASSERT(g.turn == 0);
        CPPUNIT_ASSERT(g.Food_index == 0);
        CPPUNIT_ASSERT(g.Hopper_index == 0);
        CPPUNIT_ASSERT(g.Rover_index == 0);
        CPPUNIT_ASSERT(g.Trap_index == 0);
        CPPUNIT_ASSERT(g.Best_index == 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
        CPPUNIT_ASSERT(g.isMoved[0][0] == false);
    }

    void test_game_default_3 (){
        Game<4,4,1,1> g;     
        CPPUNIT_ASSERT(g._Height == 4);
        CPPUNIT_ASSERT(g._Width == 4);
        CPPUNIT_ASSERT(g.turn == 0);
        CPPUNIT_ASSERT(g.Food_index == 0);
        CPPUNIT_ASSERT(g.Hopper_index == 0);
        CPPUNIT_ASSERT(g.Rover_index == 0);
        CPPUNIT_ASSERT(g.Trap_index == 0);
        CPPUNIT_ASSERT(g.Best_index == 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
        CPPUNIT_ASSERT(g.isMoved[0][0] == false);
    }

    // test game put

    void test_game_put_1 (){
        Game<4,4,1,1> g;
        Food a = 1;
        Trap b = 1;
        Rover c = 1;
        Hopper d = 1;
        g.put(a,1,1);
        g.put(b,2,1);
        g.put(c,3,1);
        g.put(d,4,1);
        CPPUNIT_ASSERT(g._grid[1][1] == &a);
        CPPUNIT_ASSERT(g._grid[2][1] == &b);
        CPPUNIT_ASSERT(g._grid[3][1] == &c);
        CPPUNIT_ASSERT(g._grid[4][1] == &d);
    }

    void test_game_put_2 (){
        Game<4,4,1,1> g;
        Food a = 1;
        Trap b = 1;
        Rover c = 1;
        Hopper d = 1;
        Food f;
        Trap j;
        Hopper h;
        g.put(a,1,1);
        g.put(b,2,1);
        g.put(c,3,1);
        g.put(d,4,1);
        g.put(f,2,2);
        g.put(j,3,3);
        g.put(h,3,2);
        CPPUNIT_ASSERT(g._grid[1][1] == &a);
        CPPUNIT_ASSERT(g._grid[2][1] == &b);
        CPPUNIT_ASSERT(g._grid[3][1] == &c);
        CPPUNIT_ASSERT(g._grid[4][1] == &d);
        CPPUNIT_ASSERT(g._grid[2][2] == &f);
        CPPUNIT_ASSERT(g._grid[3][3] == &j);
        CPPUNIT_ASSERT(g._grid[3][2] == &h);
    }

    void test_game_put_3 (){
        Game<4,4,1,1> g;
        Food a = 1;
        Trap b = 1;
        Rover c = 1;
        Hopper d = 1;
        g.put(a,1,1);
        g.put(b,2,1);
        g.put(c,3,1);
        g.put(d,0,1);
        ostringstream before, after,u;
        g.printGrid(before);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(before.str() == "0 .h..\n1 .f..\n2 .t..\n3 .r..\n\n");
        CPPUNIT_ASSERT(g._grid[1][1] == &a);
        CPPUNIT_ASSERT(g._grid[2][1] == &b);
        CPPUNIT_ASSERT(g._grid[3][1] == &c);
        CPPUNIT_ASSERT(g._grid[0][1] == &d);
    }

    void test_run_put_1 (){
        Game<3,3,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n\n");

        Trap t1 = 0;
        Rover r1 = 1;
        Trap t2 = 2;
        Trap t3 = 3;
        Trap t4 = 3;
        Trap t5 = 2;
        Rover r2 = 1;
        Rover r3 = 1;
        Rover r4 = 0;
        g.put(t1,2,2);
        g.put(r2,1,1);
        g.put(r1,0,0);
        g.put(t2,0,1);
        g.put(r3,0,2);
        g.put(t3,1,2);
        g.put(t4,2,0);
        g.put(r4,2,1);
        g.put(t5,1,0);
        g.printGrid(beforeHop);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(beforeHop.str() == "0 rtr\n1 trt\n2 trt\n\n");
        g.run(dummy);
        // g.printGrid(cout);
        g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 rtt\n1 ttt\n2 rtt\n\n");

    }

    void test_run_put_2 (){
        Game<3,3,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n\n");

        Trap t1 = 0;
        Rover r1 = 1;
        Trap t2 = 2;
        Trap t3 = 3;
        Trap t4 = 3;
        Trap t5 = 2;
        Rover r2 = 1;
        Rover r3 = 1;
        Rover r4 = 0;
        g.put(t1,2,2);
        g.put(r2,1,1);
        g.put(r1,0,0);
        g.put(t2,0,1);
        g.put(r3,0,2);
        g.put(t3,1,2);
        g.put(t4,2,0);
        g.put(r4,2,1);
        g.put(t5,1,0);
        g.printGrid(beforeHop);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(beforeHop.str() == "0 rtr\n1 trt\n2 trt\n\n");
        g.run(dummy);
        // g.printGrid(cout);
        g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 rtt\n1 ttt\n2 rtt\n\n");
        
    }

    void test_run_put_3 (){
        Game<3,3,1,1> g;
        ostringstream before, beforeHop, dummy, afterHop;
        g.printGrid(before);
        CPPUNIT_ASSERT(before.str() == "0 ...\n1 ...\n2 ...\n\n");

        Trap t1 = 0;
        Rover r1 = 1;
        Trap t2 = 2;
        Trap t3 = 3;
        Trap t4 = 3;
        Trap t5 = 2;
        Rover r2 = 1;
        Rover r3 = 1;
        Rover r4 = 0;
        g.put(t1,2,2);
        g.put(r2,1,1);
        g.put(r1,0,0);
        g.put(t2,0,1);
        g.put(r3,0,2);
        g.put(t3,1,2);
        g.put(t4,2,0);
        g.put(r4,2,1);
        g.put(t5,1,0);
        g.printGrid(beforeHop);
        // g.printGrid(cout);
        CPPUNIT_ASSERT(beforeHop.str() == "0 rtr\n1 trt\n2 trt\n\n");
        g.run(dummy);
        // g.printGrid(cout);
        g.printGrid(afterHop);
        CPPUNIT_ASSERT(afterHop.str() == "0 rtt\n1 ttt\n2 rtt\n\n");
        
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    
    // test creature default constructor
    CPPUNIT_TEST(test_creature_default_creature_1);
    CPPUNIT_TEST(test_creature_default_creature_2);
    CPPUNIT_TEST(test_creature_default_creature_3);

    // test creature int constructor
    CPPUNIT_TEST(test_creature_int_constuctors_1);
    CPPUNIT_TEST(test_creature_int_constuctors_2);
    CPPUNIT_TEST(test_creature_int_constuctors_3);

    // test creature reset
    CPPUNIT_TEST(test_creature_reset_1);
    CPPUNIT_TEST(test_creature_reset_2);
    CPPUNIT_TEST(test_creature_reset_3);

    // test creature getName
    CPPUNIT_TEST(test_creature_getName_1);
    CPPUNIT_TEST(test_creature_getName_2);
    CPPUNIT_TEST(test_creature_getName_3);

    //test creature getDirection
    CPPUNIT_TEST(test_creature_getDirection_1);
    CPPUNIT_TEST(test_creature_getDirection_2);
    CPPUNIT_TEST(test_creature_getDirection_3);

    // test creature setD
    CPPUNIT_TEST(test_creature_setD_1);
    CPPUNIT_TEST(test_creature_setD_2);
    CPPUNIT_TEST(test_creature_setD_3);
	
	// test creature virtual action
	CPPUNIT_TEST(test_creature_virtual_action_1);
	CPPUNIT_TEST(test_creature_virtual_action_1);
	CPPUNIT_TEST(test_creature_virtual_action_1);
	
    // test creature turn left
    CPPUNIT_TEST(test_creature_left_1);
    CPPUNIT_TEST(test_creature_left_2);
    CPPUNIT_TEST(test_creature_left_3);

    // test creature turn right
    CPPUNIT_TEST(test_creature_right_1);
    CPPUNIT_TEST(test_creature_right_2);
    CPPUNIT_TEST(test_creature_right_3);

    // test creature hop
    CPPUNIT_TEST(test_creature_hop_1);
    CPPUNIT_TEST(test_creature_hop_2);
	CPPUNIT_TEST(test_creature_hop_3);
	
	// test creature isEnemy
	CPPUNIT_TEST(test_creature_isEnemy_1);
    CPPUNIT_TEST(test_creature_isEnemy_2);
    CPPUNIT_TEST(test_creature_isEnemy_3);

    // test creature isEmpty
    CPPUNIT_TEST(test_creature_isEmpty_1);
    CPPUNIT_TEST(test_creature_isEmpty_2);
    CPPUNIT_TEST(test_creature_isEmpty_3);

    // test food default constructor
    CPPUNIT_TEST(test_food_default_constructor_1);
    CPPUNIT_TEST(test_food_default_constructor_2);
    CPPUNIT_TEST(test_food_default_constructor_3);

    //test food int constructor
    CPPUNIT_TEST(test_food_int_constructor_1);
    CPPUNIT_TEST(test_food_int_constructor_2);
    CPPUNIT_TEST(test_food_int_constructor_3);

    //test food getName
    CPPUNIT_TEST(test_food_getName_1);
    CPPUNIT_TEST(test_food_getName_2);
    CPPUNIT_TEST(test_food_getName_3);

    // test food action
    CPPUNIT_TEST(test_food_action_1);
    CPPUNIT_TEST(test_food_action_2);
    CPPUNIT_TEST(test_food_action_3);

    //test hopper default constructor
    CPPUNIT_TEST(test_hopper_default_constructor_1);
    CPPUNIT_TEST(test_hopper_default_constructor_2);
    CPPUNIT_TEST(test_hopper_default_constructor_3);

    // test hopper int constructor
    CPPUNIT_TEST(test_hopper_int_constructor_1);
    CPPUNIT_TEST(test_hopper_int_constructor_2);
    CPPUNIT_TEST(test_hopper_int_constructor_3);

    //test hopper getName
    CPPUNIT_TEST(test_hopper_getName_1);
    CPPUNIT_TEST(test_hopper_getName_2);
    CPPUNIT_TEST(test_hopper_getName_3);

    //test hopper action
    CPPUNIT_TEST(test_hopper_action_1);
    CPPUNIT_TEST(test_hopper_action_2);
    CPPUNIT_TEST(test_hopper_action_3);

    //test rover default constructor
    CPPUNIT_TEST(test_rover_default_constructor_1);
    CPPUNIT_TEST(test_rover_default_constructor_2);
    CPPUNIT_TEST(test_rover_default_constructor_3);

    // test rover int constructor
    CPPUNIT_TEST(test_rover_int_constructor_1);
    CPPUNIT_TEST(test_rover_int_constructor_2);
    CPPUNIT_TEST(test_rover_int_constructor_3);

    //test rover getName
    CPPUNIT_TEST(test_rover_getName_1);
    CPPUNIT_TEST(test_rover_getName_2);
    CPPUNIT_TEST(test_rover_getName_3);

    //test rover action
    CPPUNIT_TEST(test_rover_action_1);
    CPPUNIT_TEST(test_rover_action_2);
    CPPUNIT_TEST(test_rover_action_3);

    //test trap default constructor
    CPPUNIT_TEST(test_trap_default_constructor_1);
    CPPUNIT_TEST(test_trap_default_constructor_2);
    CPPUNIT_TEST(test_trap_default_constructor_3);

    // test trap int constructor
    CPPUNIT_TEST(test_trap_int_constructor_1);
    CPPUNIT_TEST(test_trap_int_constructor_2);
    CPPUNIT_TEST(test_trap_int_constructor_3);

    //test trap getName
    CPPUNIT_TEST(test_trap_getName_1);
    CPPUNIT_TEST(test_trap_getName_2);
    CPPUNIT_TEST(test_trap_getName_3);

    //test trap action
    CPPUNIT_TEST(test_trap_action_1);
    CPPUNIT_TEST(test_trap_action_2);
    CPPUNIT_TEST(test_trap_action_3);

    // test game default constructor
    CPPUNIT_TEST(test_game_default_1);
    CPPUNIT_TEST(test_game_default_2);
    CPPUNIT_TEST(test_game_default_3);

    // test game put 
    CPPUNIT_TEST(test_game_put_1);
    CPPUNIT_TEST(test_game_put_2);
    CPPUNIT_TEST(test_game_put_3);

    //test game run
    CPPUNIT_TEST(test_run_put_1);
    CPPUNIT_TEST(test_run_put_2);
    CPPUNIT_TEST(test_run_put_3);

    // //test_infect_helper
    // CPPUNIT_TEST(test_infect_helper_1);
    // CPPUNIT_TEST(test_infect_helper_2);
    // CPPUNIT_TEST(test_infect_helper_3);

    // // test action inst
    // CPPUNIT_TEST(test_action_inst_1);
    // CPPUNIT_TEST(test_action_inst_2);
    // CPPUNIT_TEST(test_action_inst_3);

    // // if empty
    // CPPUNIT_TEST(test_empty_1);
    // CPPUNIT_TEST(test_empty_2);
    // CPPUNIT_TEST(test_empty_3);

    // // test if wall
    // CPPUNIT_TEST(test_if_wall_1);
    // CPPUNIT_TEST(test_if_wall_2);
    // CPPUNIT_TEST(test_if_wall_3);

    // // test if random
    // CPPUNIT_TEST(test_if_random_1);
    // CPPUNIT_TEST(test_if_random_2);
    // CPPUNIT_TEST(test_if_random_3);

    // // test if enemy
    // CPPUNIT_TEST(test_if_enemy_1);
    // CPPUNIT_TEST(test_if_enemy_2);
    // CPPUNIT_TEST(test_if_enemy_3);

    // // test go
    // CPPUNIT_TEST(test_go_1);
    // CPPUNIT_TEST(test_go_2);
    // CPPUNIT_TEST(test_go_3);

    // // test run game
    // CPPUNIT_TEST(test_run_game_1);
    // CPPUNIT_TEST(test_run_game_2);
    // CPPUNIT_TEST(test_run_game_3);
    // CPPUNIT_TEST(test_run_game_4);

    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}