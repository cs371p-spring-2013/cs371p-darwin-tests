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


// ----------
// TestDarwin
// ----------


#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3

#define FOOD 	vector<pair<string,int > > food_program;food_program.push_back(make_pair("left", -1));food_program.push_back(make_pair("go", 0));pair<char, vector<pair<string, int> > > food;food.first = 'f';food.second = food_program;	

#define HOPPER vector<pair<string,int > > hopper_program;hopper_program.push_back(make_pair("hop", -1));hopper_program.push_back(make_pair("go", 0));	pair<char, vector<pair<string, int> > > hopper;hopper.first = 'h';hopper.second = hopper_program;

#define ROVER 	vector<pair<string,int > > rover_program;rover_program.push_back(make_pair("if_enemy", 9));rover_program.push_back(make_pair("if_empty", 7));rover_program.push_back(make_pair("if_random", 5));rover_program.push_back(make_pair("left", -1));rover_program.push_back(make_pair("go", 0));rover_program.push_back(make_pair("right", -1));rover_program.push_back(make_pair("go", 0));rover_program.push_back(make_pair("hop", -1));rover_program.push_back(make_pair("go", 0));rover_program.push_back(make_pair("infect", -1));rover_program.push_back(make_pair("go", 0));pair<char, vector<pair<string, int> > > rover;rover.first = 'r';rover.second = rover_program;

#define TRAP	 vector<pair<string,int > > trap_program;trap_program.push_back(make_pair("if_enemy", 3));trap_program.push_back(make_pair("left", -1));trap_program.push_back(make_pair("go", 0));trap_program.push_back(make_pair("infect", -1));trap_program.push_back(make_pair("go", 0));pair<char, vector<pair<string, int> > > trap;trap.first = 't';trap.second = trap_program;

#define BEST vector<pair<string,int > > best_program;best_program.push_back(make_pair("if_enemy", 6));best_program.push_back(make_pair("if_empty", 4));best_program.push_back(make_pair("if_wall", 8));best_program.push_back(make_pair("go", 0));best_program.push_back(make_pair("hop", -1));best_program.push_back(make_pair("go", 0));best_program.push_back(make_pair("infect", -1));best_program.push_back(make_pair("go", 0));best_program.push_back(make_pair("left", -1));best_program.push_back(make_pair("if_enemy", 12));best_program.push_back(make_pair("left", -1));best_program.push_back(make_pair("go", 0));best_program.push_back(make_pair("infect", -1));best_program.push_back(make_pair("left", -1));best_program.push_back(make_pair("go", 0));pair<char, vector<pair<string, int> > > best;best.first = 'b';best.second = best_program;


struct TestDarwin : CppUnit::TestFixture {
	// ----------
	// Creature
	// ----------

	void test_front_location1(){
		ROVER
		Creature c(rover, NORTH);

		CPPUNIT_ASSERT(c.front_location(make_pair(0, 0)) == make_pair(-1, 0));
	}

	void test_front_location2(){
		ROVER
		Creature c(rover, EAST);

		CPPUNIT_ASSERT(c.front_location(make_pair(0, 0)) == make_pair(0, 1));
	}

	void test_front_location3(){
		ROVER
		Creature c(rover, SOUTH);

		CPPUNIT_ASSERT(c.front_location(make_pair(0, 0)) == make_pair(1, 0));
	}

	void test_front_location4(){
		ROVER
		Creature c(rover, WEST);

		CPPUNIT_ASSERT(c.front_location(make_pair(0, 0)) == make_pair(0, -1));
	}
	
	void test_execute1(){
		ROVER
		Creature c(rover, NORTH);

		CPPUNIT_ASSERT(c.execute(0) == 0);
	}	

	void test_execute2(){
		ROVER
		Creature c(rover, NORTH);

		CPPUNIT_ASSERT(c.execute(1) == 1);
	}

	void test_execute3(){
		ROVER
		Creature c(rover, NORTH);

		CPPUNIT_ASSERT(c.execute(2) == 2);
	}

	void test_reset_species1(){
		ROVER
		TRAP
		Creature c(rover, NORTH);
		c.reset_species(trap);

		CPPUNIT_ASSERT(c.printSelf() == 't');
	}

	void test_reset_species2(){
		ROVER
		BEST
		Creature c(rover, NORTH);
		c.reset_species(best);

		CPPUNIT_ASSERT(c.printSelf() == 'b');
	}

	void test_reset_species3(){
		ROVER
		Creature c(rover, NORTH);
		c.reset_species(rover);

		CPPUNIT_ASSERT(c.printSelf() == 'r');
	}

	void test_infect1(){
		ROVER
		FOOD
		Creature c1(rover, NORTH);
		Creature c2(food, NORTH);
		c1.infect(c2);

		CPPUNIT_ASSERT(c1.printSelf() == 'r');
		CPPUNIT_ASSERT(c2.printSelf() == 'r');
	}

	void test_infect2(){
		ROVER
		FOOD
		Creature c1(rover, NORTH);
		Creature c2(food, NORTH);
		c2.infect(c1);

		CPPUNIT_ASSERT(c1.printSelf() == 'f');
		CPPUNIT_ASSERT(c2.printSelf() == 'f');
	}

	void test_infect3(){
		ROVER
		FOOD
		Creature c1(rover, NORTH);
		Creature c2(food, NORTH);
		c1.infect(c2);
		c2.infect(c1);

		CPPUNIT_ASSERT(c1.printSelf() == 'r');
		CPPUNIT_ASSERT(c2.printSelf() == 'r');
	}

	void test_printSelf1(){
		ROVER
		Creature c(rover, NORTH);

		CPPUNIT_ASSERT(c.printSelf() == 'r');
	}

	void test_printSelf2(){
		HOPPER
		Creature c(hopper, NORTH);

		CPPUNIT_ASSERT(c.printSelf() == 'h');
	}

	void test_printSelf3(){
		TRAP
		Creature c(trap, NORTH);

		CPPUNIT_ASSERT(c.printSelf() == 't');
	}	

	void test_printSelf4(){
		FOOD
		Creature c(food, NORTH);

		CPPUNIT_ASSERT(c.printSelf() == 'f');
	}	

	void test_printSelf5(){
		BEST
		Creature c(best, NORTH);

		CPPUNIT_ASSERT(c.printSelf() == 'b');
	}	

	// ----------
	// Grid
	// ----------
	
	void test_at1(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, NORTH);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(-1, 0));
	}

	void test_at2(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, EAST);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(0, 1));
	}

	void test_at3(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, SOUTH);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(1, 0));
	}
	
	void test_at4(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, WEST);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(0, -1));
	}

	void test_add1(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, NORTH);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(-1, 0));
		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));
	}

	void test_add2(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, EAST);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(0, 1));
		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));	
	}

	void test_add3(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, SOUTH);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(1, 0));
		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));		
	}
	
	void test_add4(){
		ROVER
		Grid<Creature> g(1 , 1);
		Creature c(rover, WEST);
		g.add(make_pair(0,0), c);
		pair<int, int> loc = make_pair(0, 0);
		CPPUNIT_ASSERT(g.at(loc).front_location(loc) == make_pair(0, -1));
		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));		
	}

	void test_isValid1(){
		Grid<Creature> g(1, 1);

		CPPUNIT_ASSERT(g.isValid(make_pair(0, 0)));
	}	

	void test_isValid2(){
		Grid<Creature> g(100, 100);

		CPPUNIT_ASSERT(g.isValid(make_pair(99, 99)));
	}

	void test_isValid3(){
		Grid<Creature> g(100, 100);

		CPPUNIT_ASSERT(!g.isValid(make_pair(100, 100)));
	}	

	void test_isOccupied1(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(99, 99);
		g.add(loc, c);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));
	}

	void test_isOccupied2(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(99, 99);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(!g.isOccupied(loc));
	}

	void test_isOccupied3(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(99, 99);
		pair<int, int> loc2 = make_pair(0, 0);
		g.add(loc, c);

		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(!g.isOccupied(loc2));
	}

	void test_remove1(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(0, 0);
		g.add(loc, c);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));

		g.remove(loc);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(!g.isOccupied(loc));
	}

	void test_remove2(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(13, 92);
		g.add(loc, c);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));

		g.remove(loc);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(!g.isOccupied(loc));
	}

	void test_remove3(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc = make_pair(99, 99);
		g.add(loc, c);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(g.isOccupied(loc));

		g.remove(loc);

		CPPUNIT_ASSERT(g.isValid(loc));
		CPPUNIT_ASSERT(!g.isOccupied(loc));
	}
	
	void test_move1(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc1 = make_pair(0, 0);
		pair<int, int> loc2 = make_pair(99, 99);
		g.add(loc1, c);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(!g.isOccupied(loc2));

		g.move(loc1, loc2);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(!g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(g.isOccupied(loc2));
	}

	void test_move2(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc1 = make_pair(12, 7);
		pair<int, int> loc2 = make_pair(13, 96);
		g.add(loc1, c);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(!g.isOccupied(loc2));

		g.move(loc1, loc2);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(!g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(g.isOccupied(loc2));
	}

	void test_move3(){
		ROVER
		Grid<Creature> g(100, 100);
		Creature c(rover, NORTH);
		pair<int, int> loc1 = make_pair(99, 99);
		pair<int, int> loc2 = make_pair(1, 1);
		g.add(loc1, c);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(!g.isOccupied(loc2));

		g.move(loc1, loc2);

		CPPUNIT_ASSERT(g.isValid(loc1));
		CPPUNIT_ASSERT(!g.isOccupied(loc1));
		CPPUNIT_ASSERT(g.isValid(loc2));
		CPPUNIT_ASSERT(g.isOccupied(loc2));
	}

	// ----------
	// Simulator
	// ----------	

	void test_addCreature1(){
		HOPPER
		Creature h(hopper, NORTH);
		std::ostringstream o;
		Simulator s(1, 1);
		s.addCreature(0, 0, h);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 h\n\n");
	

	}

	

	void test_addCreature2(){
		ROVER
		Creature r(rover, NORTH);
		std::ostringstream o;
		Simulator s(1, 1);
		s.addCreature(0, 0, r);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 r\n\n");
	

	}

	

	void test_addCreature3(){
		BEST
		Creature b(best, NORTH);
		std::ostringstream o;
		Simulator s(1, 1);
		s.addCreature(0, 0, b);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 b\n\n");
	

	}

	void test_run1(){
		HOPPER
		Creature h(hopper, EAST);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.run(2, 2, o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0123\n0 h...\n\nTurn = 2.\n  0123\n0 ..h.\n\n");
	}

	void test_run2(){
		HOPPER
		Creature h(hopper, EAST);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.run(2, 1, o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0123\n0 h...\n\nTurn = 1.\n  0123\n0 .h..\n\nTurn = 2.\n  0123\n0 ..h.\n\n");
	}

	void test_run3(){
		HOPPER
		Creature h(hopper, NORTH);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.run(2, 2, o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0123\n0 h...\n\nTurn = 2.\n  0123\n0 h...\n\n");
	}

	void test_print1(){
		std::ostringstream o;
		Simulator s(0, 0);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  \n\n");
	}

	void test_print2(){
		std::ostringstream o;
		Simulator s(1, 1);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 .\n\n");	
	}

	void test_print3(){
		FOOD
		Creature f(food, NORTH);
		std::ostringstream o;
		Simulator s(1, 1);
		s.addCreature(0, 0, f);
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 f\n\n");	
	}	

	void processTurn1(){
		HOPPER
		Creature h(hopper, EAST);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.processTurn();
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 1.\n  0123\n0 .h..\n\n");
	}

	void processTurn2(){
		HOPPER
		Creature h(hopper, EAST);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.processTurn();
		s.processTurn();
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 2.\n  0123\n0 ..h.\n\n");
	}

	void processTurn3(){
		HOPPER
		Creature h(hopper, NORTH);
		std::ostringstream o;
		Simulator s(1, 4);
		s.addCreature(0, 0, h);
		s.processTurn();
		s.processTurn();
		s.print(o);
		CPPUNIT_ASSERT(o.str() == "Turn = 2.\n  0123\n0 h...\n\n");
	}

    // ---------
    // TestSuite
    // ---------

	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_front_location1);
	CPPUNIT_TEST(test_front_location2);
	CPPUNIT_TEST(test_front_location3);
	CPPUNIT_TEST(test_front_location4);
	CPPUNIT_TEST(test_execute1);
	CPPUNIT_TEST(test_execute2);
	CPPUNIT_TEST(test_execute3);
	CPPUNIT_TEST(test_reset_species1);
	CPPUNIT_TEST(test_reset_species2);
	CPPUNIT_TEST(test_reset_species3);
	CPPUNIT_TEST(test_infect1);
	CPPUNIT_TEST(test_infect2);
	CPPUNIT_TEST(test_infect3);
	CPPUNIT_TEST(test_printSelf1);
	CPPUNIT_TEST(test_printSelf2);
	CPPUNIT_TEST(test_printSelf3);
	CPPUNIT_TEST(test_printSelf4);
	CPPUNIT_TEST(test_printSelf5);
	CPPUNIT_TEST(test_at1);
	CPPUNIT_TEST(test_at2);
	CPPUNIT_TEST(test_at3);
	CPPUNIT_TEST(test_at4);
    	CPPUNIT_TEST(test_add1);
	CPPUNIT_TEST(test_add2);
	CPPUNIT_TEST(test_add3);
	CPPUNIT_TEST(test_add4);
	CPPUNIT_TEST(test_isValid1);
	CPPUNIT_TEST(test_isValid2);
	CPPUNIT_TEST(test_isValid3);
	CPPUNIT_TEST(test_isOccupied1);
	CPPUNIT_TEST(test_isOccupied2);
	CPPUNIT_TEST(test_isOccupied3);
	CPPUNIT_TEST(test_remove1);
	CPPUNIT_TEST(test_remove2);
	CPPUNIT_TEST(test_remove3);
	CPPUNIT_TEST(test_move1);
	CPPUNIT_TEST(test_move2);
	CPPUNIT_TEST(test_move3);
	CPPUNIT_TEST(test_print1);
	CPPUNIT_TEST(test_print2);
	CPPUNIT_TEST(test_print3);
    	CPPUNIT_TEST(test_addCreature1);
	CPPUNIT_TEST(test_addCreature2);
	CPPUNIT_TEST(test_addCreature3);
	CPPUNIT_TEST(test_run1);
	CPPUNIT_TEST(test_run2);
	CPPUNIT_TEST(test_run3);
	CPPUNIT_TEST(test_print1);
	CPPUNIT_TEST(test_print2);
	CPPUNIT_TEST(test_print3);
	CPPUNIT_TEST(processTurn1);
	CPPUNIT_TEST(processTurn2);
	CPPUNIT_TEST(processTurn3);
	CPPUNIT_TEST_SUITE_END();
};


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();
    cout << "Done." << endl;

    return 0;
}

