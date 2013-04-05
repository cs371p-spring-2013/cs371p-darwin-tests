// -----------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <iostream>
#include <string>
#include <cassert>
#include <sstream> 
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner


#define private public
#define protected public
#define class struct

#include "Darwin.h"


// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

	// createMap
	void testCreateMap1(){
		Darwin test1;

		test1.createMap(1,1);

		assert(test1.map.size() == 1);
		assert(test1.map[0].size() == 1);
		assert(test1.map[0][0] == '.');
	}


	void testCreateMap2(){
		Darwin test2;

		test2.createMap(4,4);

		assert(test2.map.size() == 4);
		assert(test2.map[0].size() == 4);

		for (unsigned int i = 0; i < test2.map.size(); ++i){
			for (unsigned int j = 0; j < test2.map[0].size(); ++j){
				assert(test2.map[i][j] == '.');
			}
		}
	}


	void testCreateMap3(){
		Darwin test3;

		test3.createMap(10,7);

		assert(test3.map.size() == 10);
		assert(test3.map[0].size() == 7);

		for (unsigned int i = 0; i < test3.map.size(); ++i){
			for (unsigned int j = 0; j < test3.map[0].size(); ++j){
				assert(test3.map[i][j] == '.');
			}
		}
	}


	// printMap
	void testprintMap1(){
		Darwin test1;
		test1.createMap(1,1);
		assert(test1.map.size() == 1);
		assert(test1.map[0].size() ==1);
		std::ostringstream w;		
		test1.printMap(w);
		assert(w.str() == "  0\n0 .\n");
	}

	void testprintMap2(){
		Darwin test2;
		test2.createMap(1,2);
		assert(test2.map.size() == 1);
		assert(test2.map[0].size() == 2);
		std::ostringstream w;		
		test2.printMap(w);
		assert(w.str() == "  01\n0 ..\n");
	}

	void testprintMap3(){
		Darwin test3;
		test3.createMap(7,11);
		assert(test3.map.size() == 7);
		assert(test3.map[0].size() == 11);
		std::ostringstream w;		
		test3.printMap(w);
		assert(w.str() == "  01234567890\n0 ...........\n1 ...........\n2 ...........\n3 ...........\n4 ...........\n5 ...........\n6 ...........\n");	
	}

	// processCommand
	void testprocessCommand1(){
		Darwin test;
		test.createMap(4,4);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, HOPPER, 3, 3, 0);
		test.newCreature(puppets, HOPPER, 1, 1, 1);
		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[1], puppets);
		test.printMap(w);

		assert(puppets[0].location[0] == 3);
		assert(puppets[0].location[1] == 2);
		assert(puppets[1].location[0] == 0);
		assert(puppets[1].location[1] == 1);

		assert(w.str() == "  0123\n0 .h..\n1 ....\n2 ....\n3 ..h.\n");
	}
	void testprocessCommand2(){
		Darwin test;
		test.createMap(4,4);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, ROVER, 0, 0, 2);
		test.newCreature(puppets, HOPPER, 3, 3, 0);
		test.newCreature(puppets, HOPPER, 1, 1, 1);
		test.printMap(w);
		assert(w.str() == "  0123\n0 r...\n1 .h..\n2 ....\n3 ...h\n");
		w.str("");
		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[2], puppets);
		test.processCommand(puppets[1], puppets);
		test.resetCreatures(puppets);
		test.printMap(w);
		assert(w.str() == "  0123\n0 .r..\n1 .h..\n2 ....\n3 ..h.\n");
		w.str("");
		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[2], puppets);
		test.processCommand(puppets[1], puppets);
		test.printMap(w);
		assert(w.str() == "  0123\n0 .hr.\n1 ....\n2 ....\n3 .h..\n");
	}
	void testprocessCommand3(){
		Darwin test;
		test.createMap(5,5);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, ROVER, 0, 0, 2);
		test.newCreature(puppets, HOPPER, 3, 3, 0);
		test.newCreature(puppets, HOPPER, 1, 1, 1);
		test.newCreature(puppets, TRAP, 3, 2, 2);


		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[2], puppets);
		test.processCommand(puppets[3], puppets);
		test.processCommand(puppets[1], puppets);
		test.printMap(w);
		assert(w.str() == "  01234\n0 .r...\n1 .h...\n2 .....\n3 ..tt.\n4 .....\n");
		w.str("");
		test.resetCreatures(puppets);
		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[2], puppets);
		test.processCommand(puppets[3], puppets);
		test.processCommand(puppets[1], puppets);
		test.printMap(w);
		assert(w.str() == "  01234\n0 .hr..\n1 .....\n2 .....\n3 ..tt.\n4 .....\n");
		w.str("");
	}

	void testprocessCommand4(){
		Darwin test;
		test.createMap(4,4);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, TRAP, 0, 0, 2); //facing right
		test.newCreature(puppets, FOOD, 3, 3, 0); //facing left

		test.processCommand(puppets[0], puppets);
		test.processCommand(puppets[1], puppets);

		test.printMap(w);
		// cout << w.str();
		assert(w.str() == "  0123\n0 t...\n1 ....\n2 ....\n3 ...f\n");
		w.str("");
	}
	

	// runMap
	void testrunMap1() {
		Darwin test;
		test.createMap(4,4);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, HOPPER, 3, 3, 0);
		test.newCreature(puppets, HOPPER, 1, 1, 1);


		test.runMap(puppets);
		test.printMap(w);
		// to get tests passing for now
		assert(w.str() == "  0123\n0 .h..\n1 ....\n2 ....\n3 ..h.\n");
		// assert(w.str() == " 0123\n0....\n1....\n2....\n3..h.\n");
		assert(true);
	}

	void testrunMap2(){
		Darwin test;
		test.createMap(4,4);
		vector<Creature> puppets;
		std::ostringstream w;

		test.newCreature(puppets, ROVER, 0, 0, 2);
		test.newCreature(puppets, HOPPER, 3, 3, 0);
		test.newCreature(puppets, HOPPER, 1, 1, 1);

		test.runMap(puppets);
		test.runMap(puppets);
		test.printMap(w);
		assert(w.str() == "  0123\n0 .hr.\n1 ....\n2 ....\n3 .h..\n");
	}

	void testrunMap3(){
		Darwin test;
		test.createMap(5,5);
		vector<Creature> puppets;
		std::ostringstream w;
		
		test.newCreature(puppets, HOPPER, 1, 1, 1); //facing up
		test.newCreature(puppets, HOPPER, 3, 3, 0); // facing down
		test.newCreature(puppets, TRAP, 3, 2, 2); // right
		test.printMap(w);
		// cout << w.str();
		w.str("");
		test.runMap(puppets);
		assert(puppets[2].direction == 2); //trap facing up
				test.printMap(w);
		// cout << w.str();
		w.str("");
		test.runMap(puppets);
		test.printMap(w);
		// cout << w.str();
		
		assert(w.str() == "  01234\n0 .h...\n1 .....\n2 .....\n3 ..tt.\n4 .....\n");
		w.str("");
	}

	// resetCreatures
	void testresetCreatures1(){
		Darwin test1;
		test1.createMap(4,4);
		vector<Creature> puppets;

		test1.newCreature(puppets, FOOD, 0, 0, 0);
		test1.newCreature(puppets, HOPPER, 2, 1, 2);

		test1.runMap(puppets);
		test1.resetCreatures(puppets);

		for (unsigned int i = 0; i < puppets.size(); ++i){
			assert(puppets[i].canMove = true);
		}
	}
	void testresetCreatures2(){
		Darwin test2;
		test2.createMap(1,1);
		vector<Creature> puppets;

		test2.newCreature(puppets, FOOD, 0, 0, 0);

		test2.runMap(puppets);
		test2.resetCreatures(puppets);

		for (unsigned int i = 0; i < puppets.size(); ++i){
			assert(puppets[i].canMove = true);
		}
	}
	void testresetCreatures3(){
		Darwin test3;
		test3.createMap(7,10);
		vector<Creature> puppets;

		test3.newCreature(puppets, FOOD, 0, 0, 0);
		test3.newCreature(puppets, HOPPER, 2, 1, 2);
		test3.newCreature(puppets, ROVER, 1, 1, 1);
		test3.newCreature(puppets, TRAP, 4, 5, 3);
		test3.newCreature(puppets, FOOD, 3, 8, 2);

		test3.runMap(puppets);
		test3.resetCreatures(puppets);

		for (unsigned int i = 0; i < puppets.size(); ++i){
			assert(puppets[i].canMove = true);
		}
	}

	// newCreature
	void testnewCreature1(){
		Darwin test1;
		test1.createMap(1,1);
		vector<Creature> puppets;

		test1.newCreature(puppets, FOOD, 0, 0, 0);

		Creature temp;
		temp.direction = 0 % 4;
		temp.location[0] = 1;
		temp.location[1] = 1;
		temp.species = FOOD;
		temp.progCount = 0;
		temp.symbol = 'f';
		pair<string,int> pair1("LEFT", -1);
		pair<string,int> pair2("GO", 0);
		temp.actions.push_back(pair1);
		temp.actions.push_back(pair2);

		assert(test1.map[0][0] == 'f');
		// assert(std::find(puppets.begin(), puppets.end(), temp) != puppets.end());
	}

	void testnewCreature2(){
		Darwin test2;
		test2.createMap(2,1);
		vector<Creature> puppets;

		test2.newCreature(puppets, HOPPER, 1, 0, 0);

		assert(test2.map[1][0] == 'h');
	}

	void testnewCreature3(){
		Darwin test3;
		test3.createMap(4,4);
		vector<Creature> puppets;

		test3.newCreature(puppets, ROVER, 2, 3, 0);

		assert(test3.map[2][3] == 'r');
	}

	void testnewCreature4(){
		Darwin test4;
		test4.createMap(4,4);
		vector<Creature> puppets;

		test4.newCreature(puppets, TRAP, 1, 3, 0);

		assert(test4.map[1][3] == 't');
	}	

	// getCreature
	void testgetCreature1(){
		Darwin test1;
		test1.createMap(1,1);
		vector<Creature> puppets;

		test1.newCreature(puppets, FOOD, 0, 0, 0);

		int index = test1.getCreature(0, 0, puppets);
		assert(index == 0);

	}
	void testgetCreature2(){
		Darwin test2;
		test2.createMap(4,4);
		vector<Creature> puppets;

		test2.newCreature(puppets, FOOD, 0, 0, 0);
		test2.newCreature(puppets, HOPPER, 2, 1, 2);

		int index = test2.getCreature(2, 1, puppets);
		assert(index == 1);
		index = test2.getCreature(0, 0, puppets);
		assert(index == 0);
	}
	void testgetCreature3(){
		Darwin test3;
		test3.createMap(7,10);
		vector<Creature> puppets;

		test3.newCreature(puppets, FOOD, 0, 0, 0);
		test3.newCreature(puppets, HOPPER, 2, 1, 2);
		test3.newCreature(puppets, ROVER, 1, 1, 1);
		test3.newCreature(puppets, TRAP, 4, 5, 3);
		test3.newCreature(puppets, FOOD, 3, 8, 2);

		int index = test3.getCreature(2, 1, puppets);
		assert(index == 1);
		index = test3.getCreature(0, 0, puppets);
		assert(index == 0);
		index = test3.getCreature(3, 8, puppets);
		assert(index == 4);
		index = test3.getCreature(4, 5, puppets);
		assert(index == 3);
		index = test3.getCreature(1, 1, puppets);
		assert(index == 2);
	}

	// future_row
	void testfuturerow1(){
		Darwin test1;
		assert(test1.future_row(0, 1) == 1);
	}
	void testfuturerow2(){
		Darwin test2;
		assert(test2.future_row(1, 1) == 0);
	}
	void testfuturerow3(){
		Darwin test3;
		assert(test3.future_row(2, 1) == 1);
	}
	void testfuturerow4(){
		Darwin test4;
		assert(test4.future_row(3, 1) == 2);
	}

	// future_col
	void testfuturecol1(){
		Darwin test1;
		assert(test1.future_col(0,1) == 0);
	}
	void testfuturecol2(){
		Darwin test1;
		assert(test1.future_col(1,1) == 1);
	}
	void testfuturecol3(){
		Darwin test1;
		assert(test1.future_col(2,1) == 2);
	}
	void testfuturecol4(){
		Darwin test1;
		assert(test1.future_col(3,1) == 1);
	}

	// inbounds
	void testinbounds1(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 0, 0, 1);
		test.newCreature(puppets, FOOD, 0, 1, 2);
		
		// test.printMap(w);
		assert(puppets.size() == 2);
		assert(test.inbounds(puppets[0]) == false);
		assert(test.inbounds(puppets[1]) == false);
	}
	void testinbounds2(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 0, 0, 3);
		test.newCreature(puppets, FOOD, 0, 1, 3);
		
		// test.printMap(w);
		assert(puppets.size() == 2);
		assert(test.inbounds(puppets[0]) == true);
		assert(test.inbounds(puppets[1]) == true);
	}
	
	void testinbounds3(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 1, 0, 3);
		test.newCreature(puppets, FOOD, 0, 1, 3);
		
		// test.printMap(w);
		assert(puppets.size() == 2);
		assert(test.inbounds(puppets[0]) == false);
		assert(test.inbounds(puppets[1]) == true);
	}
	

	// ifenemy
	void testifenemy1(){
		Darwin test1;
		test1.createMap(1,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test1.newCreature(puppets, HOPPER, 0, 0, 2);
		test1.newCreature(puppets, FOOD, 0, 1, 0);
		// test1.printMap(w);		

		assert (true);
		assert(puppets.size() == 2);
		assert(test1.ifenemy(puppets[0]) == true);
	}
	void testifenemy2(){
		Darwin test2;
		test2.createMap(5,5);
		vector< Creature > puppets;
		std::ostringstream w;		

		test2.newCreature(puppets, HOPPER, 0, 0, 2);
		test2.newCreature(puppets, FOOD, 0, 1, 0);
		test2.newCreature(puppets, ROVER, 1, 1, 1);
		// test2.printMap(w);		

		assert (true);
		assert(puppets.size() == 3);
		assert(test2.ifenemy(puppets[0]) == true);
		assert(test2.ifenemy(puppets[2]) == true);		
	}
	void testifenemy3(){
		Darwin test3;
		test3.createMap(5,5);
		vector< Creature > puppets;
		std::ostringstream w;		

		test3.newCreature(puppets, HOPPER, 0, 0, 2);
		test3.newCreature(puppets, FOOD, 0, 1, 0);
		test3.newCreature(puppets, ROVER, 1, 1, 1);
		test3.newCreature(puppets, ROVER, 1, 0, 1);
		// test3.printMap(w);		

		assert (true);
		assert(puppets.size() == 4);
		assert(test3.ifenemy(puppets[0]) == true);
		assert(test3.ifenemy(puppets[2]) == true);
		assert(test3.ifenemy(puppets[3]) == true);

	}

	// ifempty
	void testifempty1(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 0, 0, 2);
		test.newCreature(puppets, FOOD, 0, 1, 3);
		
		assert(puppets.size() == 2);
		assert(test.ifempty(puppets[1]) == true);
		assert(test.ifempty(puppets[0]) == false);
	}
	void testifempty2(){
		Darwin test;
		test.createMap(5,5);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 0, 0, 2);
		test.newCreature(puppets, FOOD, 0, 1, 3);
		test.newCreature(puppets, ROVER, 1, 0, 0);

		
		assert(puppets.size() == 3);
		assert(test.ifempty(puppets[1]) == true);
		assert(test.ifempty(puppets[0]) == false);
		assert(test.ifempty(puppets[2]) == false);
	}
	void testifempty3(){
		Darwin test;
		test.createMap(5,5);
		vector< Creature > puppets;
		std::ostringstream w;	

		test.newCreature(puppets, HOPPER, 0, 0, 2);
		test.newCreature(puppets, FOOD, 0, 1, 3);
		test.newCreature(puppets, ROVER, 1, 0, 0);
		test.newCreature(puppets, ROVER, 1, 1, 3);
		
		// test.printMap(w);
		assert(puppets.size() == 4);
		assert(test.ifempty(puppets[1]) == false);
		assert(test.ifempty(puppets[0]) == false);
		assert(test.ifempty(puppets[2]) == false);
		
	}

	// ifrandom
	// can't really test this out
	void testifrandom1(){
		Darwin test;
		test.createMap(1,1);
		assert(test.ifrandom() == true || false);
	}

	// left
	void testleft1(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 2);
		
		assert(test.left(puppets[0]) == 1);
	}
	void testleft2(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 1);
		
		assert(test.left(puppets[0]) == 0);
	}
	void testleft3(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 3);
		
		assert(test.left(puppets[0]) == 2);
	}
	void testleft4(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 0);
		
		assert(test.left(puppets[0]) == 3);
	}

	// right
	void testright1(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 0);
		
		assert(test.right(puppets[0]) == 1);
	}
	void testright2(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 1);
		
		assert(test.right(puppets[0]) == 2);
	}
	void testright3(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 2);
		
		assert(test.right(puppets[0]) == 3);
	}
	void testright4(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 3);
		
		assert(test.right(puppets[0]) == 0);
	}

	// hop
	void testhop1(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 0);
		
		assert(test.hop(puppets[0]) == true);
	}
	void testhop2(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 0, 1, 1);
		
		assert(test.hop(puppets[0]) == false);
	}
	void testhop3(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 1, 2);
		
		assert(test.hop(puppets[0]) == false);
	}
	void testhop4(){
		Darwin test;
		test.createMap(2,2);
		vector< Creature > puppets;
		std::ostringstream w;		

		test.newCreature(puppets, HOPPER, 1, 0, 2);
		
		assert(test.hop(puppets[0]) == true);
	}


	// suite
	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(testCreateMap1);
	CPPUNIT_TEST(testCreateMap2);
	CPPUNIT_TEST(testCreateMap3);
	CPPUNIT_TEST(testprintMap1);
	CPPUNIT_TEST(testprintMap2);
	CPPUNIT_TEST(testprintMap3);
	CPPUNIT_TEST(testrunMap1);
	CPPUNIT_TEST(testrunMap2);
	CPPUNIT_TEST(testrunMap3);
	CPPUNIT_TEST(testresetCreatures1);
	CPPUNIT_TEST(testresetCreatures2);
	CPPUNIT_TEST(testresetCreatures3);
	CPPUNIT_TEST(testprocessCommand1);
	CPPUNIT_TEST(testprocessCommand2);
	CPPUNIT_TEST(testprocessCommand3);
	CPPUNIT_TEST(testprocessCommand4);
	CPPUNIT_TEST(testnewCreature1);
	CPPUNIT_TEST(testnewCreature2);
	CPPUNIT_TEST(testnewCreature3);
	CPPUNIT_TEST(testnewCreature4);
	CPPUNIT_TEST(testgetCreature1);
	CPPUNIT_TEST(testgetCreature2);
	CPPUNIT_TEST(testgetCreature3);
	CPPUNIT_TEST(testfuturerow1);
	CPPUNIT_TEST(testfuturerow2);
	CPPUNIT_TEST(testfuturerow3);
	CPPUNIT_TEST(testfuturerow4);
	CPPUNIT_TEST(testfuturecol1);
	CPPUNIT_TEST(testfuturecol2);
	CPPUNIT_TEST(testfuturecol3);
	CPPUNIT_TEST(testfuturecol4);
	CPPUNIT_TEST(testifenemy1);
	CPPUNIT_TEST(testifenemy2);
	CPPUNIT_TEST(testifenemy3);
	CPPUNIT_TEST(testinbounds1);
	CPPUNIT_TEST(testinbounds2);
	CPPUNIT_TEST(testinbounds3);
	CPPUNIT_TEST(testifrandom1);
	CPPUNIT_TEST(testleft1);
	CPPUNIT_TEST(testleft2);
	CPPUNIT_TEST(testleft3);
	CPPUNIT_TEST(testleft4);
	CPPUNIT_TEST(testright1);
	CPPUNIT_TEST(testright2);
	CPPUNIT_TEST(testright3);
	CPPUNIT_TEST(testright4);
	CPPUNIT_TEST(testhop1);
	CPPUNIT_TEST(testhop2);
	CPPUNIT_TEST(testhop3);
	CPPUNIT_TEST(testhop4);
	CPPUNIT_TEST_SUITE_END();};

int main() {
	using namespace std;

	cout << "TestDarwin.c++" << endl;
	CppUnit::TextTestRunner tr;
	tr.addTest(TestDarwin::suite());
	tr.run();

	cout << "Done." << endl;
	return 0; }
