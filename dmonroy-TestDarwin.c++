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
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// -------------
// TestAllocator
// -------------

struct TestDarwin : CppUnit::TestFixture {


    // --------
    // test_construct
    // --------

    void World_World1 () {
        World x(8, 8);
       

       // x.print();
    }

    void World_World2 () {
        World x(4,4);
       

       // x.print();
    }

    void World_World3 () {
        World x(3,2);
       

       // x.print();
    }

    // --------
    // test_addCreature
    // --------

    void World_addCreature1(){
        World x(6, 8);
        x.addCreature(0, 1, 5, 4);
        CPPUNIT_ASSERT(x.creatures.at(0).direction == 1);
        CPPUNIT_ASSERT(x.creatures.at(0).position[0] == 5);
        CPPUNIT_ASSERT(x.creatures.at(0).position[1] == 4);


        //x.print();
    }

    void World_addCreature2(){
        World x(8, 8);
        x.addCreature(0, 1, 5, 4);
        CPPUNIT_ASSERT(x.creatures.at(0).direction == 1);

        CPPUNIT_ASSERT(x.creatures.at(0).position[0] == 5);
        CPPUNIT_ASSERT(x.creatures.at(0).position[1] == 4);


        x.addCreature(1, 2, 3, 4);
 
        CPPUNIT_ASSERT(x.creatures.at(1).direction == 2);
        CPPUNIT_ASSERT(x.creatures.at(1).position[0] == 3);
        CPPUNIT_ASSERT(x.creatures.at(1).position[1] == 4);

        x.addCreature(2, 3, 6, 7);

        CPPUNIT_ASSERT(x.creatures.at(2).direction ==3);
        CPPUNIT_ASSERT(x.creatures.at(2).position[0] == 6);
        CPPUNIT_ASSERT(x.creatures.at(2).position[1] == 7);

        x.addCreature(3, 4, 0, 2);

        CPPUNIT_ASSERT(x.creatures.at(3).direction == 4);
        CPPUNIT_ASSERT(x.creatures.at(3).position[0] == 0);
        CPPUNIT_ASSERT(x.creatures.at(3).position[1] == 2);

     //   x.print();
    }

    void World_addCreature3(){
        World x(7, 7);
        x.addCreature(2, 1, 3, 4);
        CPPUNIT_ASSERT(x.creatures.at(0).direction == 1);

        CPPUNIT_ASSERT(x.creatures.at(0).position[0] == 3);
        CPPUNIT_ASSERT(x.creatures.at(0).position[1] == 4);

        x.addCreature(3, 4, 1, 2);
   
        CPPUNIT_ASSERT(x.creatures.at(1).direction == 4);
        CPPUNIT_ASSERT(x.creatures.at(1).position[0] == 1);
        CPPUNIT_ASSERT(x.creatures.at(1).position[1] == 2);


        //x.print();
    }

    // --------
    // test_hasCreature
    // --------
    void World_hasCreature1(){
        World x(7, 7);
        x.addCreature(2, 1, 0,0);
        CPPUNIT_ASSERT(x.hasCreature(0,0));
    }

    void World_hasCreature2(){
        World x(7, 3);
        x.addCreature(4, 1, 1,0);
        CPPUNIT_ASSERT(x.hasCreature(1,0));

    }

    void World_hasCreature3(){
        World x(3, 37);
        x.addCreature(2, 1, 2,33);
        CPPUNIT_ASSERT(!x.hasCreature(1,33));

    }

    // --------
    // test_findCreature
    // --------
    void World_findCreature1(){
        World x(7, 7);

        Creature temp;

        x.addCreature(2, 1, 0,0);
        x.addCreature(3, 2, 1,1);
        temp = x.findCreature(1,1);
        CPPUNIT_ASSERT(temp.direction == 2);

    }

    void World_findCreature2(){
        World x(7, 7);

        Creature temp;

        x.addCreature(2, 1, 0,0);
        x.addCreature(3, 2, 1,1);
        x.addCreature(1, 3, 2,1);
        x.addCreature(0, 4, 3,5);

        temp = x.findCreature(3,5);
        CPPUNIT_ASSERT(temp.direction == 4);

    }

    void World_findCreature3(){
        World x(7, 7);

        Creature temp;

        x.addCreature(2, 1, 0,2);
        temp = x.findCreature(0,2);
        CPPUNIT_ASSERT(temp.direction == 1);

    }

    // --------
    // test_whatIsAhead
    // --------

    void World_whatIsAhead1()
    {
        World x(3, 3);
        x.addCreature(2, 1, 1, 1);
        x.addCreature(1, 3, 1, 0);

        Creature temp = x.findCreature(1,1);
        CPPUNIT_ASSERT(x.whatIsAhead(temp)==5);



       // x.print();
    }
    void World_whatIsAhead2()
    {
        World x(3, 3);
        x.addCreature(2, 0, 1, 1);
        x.addCreature(1, 3, 1, 0);

        Creature temp = x.findCreature(1,1);
        CPPUNIT_ASSERT(x.whatIsAhead(temp)==8);



      //  x.print();
    }
    void World_whatIsAhead3()
    {
        World x(3, 3);
        x.addCreature(2, 2, 1, 2);
        x.addCreature(1, 3, 1, 0);

        Creature temp = x.findCreature(1,2);
        CPPUNIT_ASSERT(x.whatIsAhead(temp)==6);



       // x.print();
    }
    void World_whatIsAhead4()
    {
        World x(3, 3);
        x.addCreature(2, 0, 1, 1);
        x.addCreature(2, 3, 1, 0);

        Creature temp = x.findCreature(1,1);
        CPPUNIT_ASSERT(x.whatIsAhead(temp)==0);
        CPPUNIT_ASSERT(x.whatIsAhead(temp)!=5);




       // x.print();
    }


    // --------
    // test_play
    // --------

    void World_play1()
    {
        World x(3,3);

        Creature temp;

        x.addCreature(1, 1, 1,1);
        

        x.play();
        temp = x.findCreature(0,1);
        
        CPPUNIT_ASSERT(temp.position[0] == 0);
        CPPUNIT_ASSERT(temp.position[1] == 1);
        
    }

    void World_play2()
    {
        World x(3,3);

        Creature temp;

        x.addCreature(1, 0, 1,1);
        

        x.play();
        temp = x.findCreature(1,0);
        
        CPPUNIT_ASSERT(temp.position[0] == 1);
        CPPUNIT_ASSERT(temp.position[1] == 0);
        
    }

    void World_play3()
    {
        World x(3,3);

        Creature temp;

        x.addCreature(1, 3, 1,1);
        x.addCreature(0, 3, 1,0);        

        x.play();
        temp = x.findCreature(2,1);
        
        CPPUNIT_ASSERT(temp.position[0] == 2);
        CPPUNIT_ASSERT(temp.position[1] == 1);
        
    }

    // --------
    // test_reset
    // --------

    void World_reset1(){
    World x(7, 7);
    x.addCreature(1, 2, 1, 1);
    Creature& temp = x.findCreature(1,1);

    temp.hasMoved = true;

    x.reset();

    CPPUNIT_ASSERT(temp.hasMoved == false);
    }
    void World_reset2(){
	World x(7, 7);
	x.addCreature(1, 2, 1, 1);
	x.addCreature(2, 3, 2, 1);
	x.addCreature(3, 1, 6, 4);

	Creature& temp = x.findCreature(1,1);
	Creature& temp2 = x.findCreature(2,1);
	Creature& temp3 = x.findCreature(6,4);
	temp.hasMoved = true;
	temp2.hasMoved = true;
	temp3.hasMoved = true;

	x.reset();


	CPPUNIT_ASSERT(temp.hasMoved == false);
	CPPUNIT_ASSERT(temp2.hasMoved == false);
	CPPUNIT_ASSERT(temp3.hasMoved == false);
    }

    void World_reset3(){
	World x(7, 7);
	x.addCreature(1, 2, 1, 1);
	x.addCreature(2, 3, 2, 1);
	x.addCreature(3, 1, 6, 4);
	Creature& temp = x.findCreature(1,1);
	Creature& temp2 = x.findCreature(2,1);
	Creature& temp3 = x.findCreature(6,4);

	//reset is called at the end of the method play()
	x.play();

	CPPUNIT_ASSERT(temp.hasMoved == false);
	CPPUNIT_ASSERT(temp2.hasMoved == false);
	CPPUNIT_ASSERT(temp3.hasMoved == false);
    }

    // --------
    // test_update
    // --------
    
    void World_update1(){
	World x(9,9);
	x.addCreature(1, 2, 1, 1);
	Creature& temp = x.findCreature(1,1);
	
	temp.hop(5);
	
	x.update(1, temp, 1, 1);
	CPPUNIT_ASSERT(temp.position[0] == 1);
	CPPUNIT_ASSERT(temp.position[1] == 2);
	CPPUNIT_ASSERT(x.map[1][2] == 'h');
    }
    
    void World_update2(){
	World x(9, 9);
	x.addCreature(0, 3, 3, 3);
	x.addCreature(2, 2, 4, 3);

	Creature& temp = x.findCreature(3,3);
	
	int infected = temp.executeInstruction(4);
	x.update(infected, temp, 3, 3); 
	
	CPPUNIT_ASSERT(x.map[4][3] == 'r');
	
	Creature& temp2 = x.findCreature(4,3);
	
	temp2.hop(5);
	
	x.update(1, temp2, 4, 3);
	CPPUNIT_ASSERT(temp2.position[0] == 4);
	CPPUNIT_ASSERT(temp2.position[1] == 4);
    }
    
    void World_update3(){
	World x(9,9);
	x.addCreature(1, 2, 1, 1);
	Creature& temp = x.findCreature(1,1);

	x.update(1, temp, 1, 1);
	
	CPPUNIT_ASSERT(x.map[1][1] == 'h');
    }

    // --------
    // test_findCreaturePos
    // --------

    void World_findCreaturePos1()
    {
        World x(3,3);
        x.addCreature(1, 3, 1,1); //0
        x.addCreature(0, 3, 1,0); //1

        int posi = x.findCreaturePos(1,1);
        //cout << position << endl;
        CPPUNIT_ASSERT(posi == 0);

    }

    void World_findCreaturePos2()
    {
        World x(3,3);
        x.addCreature(1, 3, 1,1); //0
        x.addCreature(0, 3, 1,0); //1

        int posi = x.findCreaturePos(1,0);
        //cout << position << endl;
        CPPUNIT_ASSERT(posi == 1);

    }

    void World_findCreaturePos3()
    {
        World x(3,6);
        x.addCreature(3, 1, 1,5); //0
        x.addCreature(0, 3, 1,0); //1
        x.addCreature(2, 3, 1,2); //1

        int posi = x.findCreaturePos(1,5);
        //cout << position << endl;
        CPPUNIT_ASSERT(posi == 0);

    }



    // --------
    // test_Creature
    // --------

    void Creature_Creature1()
    {
        Creature c(0,1,2,3);
        CPPUNIT_ASSERT(c.counter == 0);
        CPPUNIT_ASSERT(c.species._type == 0);
        CPPUNIT_ASSERT(c.direction == 1);
        CPPUNIT_ASSERT(c.position[0] == 2);
        CPPUNIT_ASSERT(c.position[1] == 3);
        CPPUNIT_ASSERT(c.hasMoved == false);

    }

    void Creature_Creature2()
    {
        Creature c(1,2,5,4);
        CPPUNIT_ASSERT(c.counter == 0);
        CPPUNIT_ASSERT(c.species._type == 1);
        CPPUNIT_ASSERT(c.direction == 2);
        CPPUNIT_ASSERT(c.position[0] == 5);
        CPPUNIT_ASSERT(c.position[1] == 4);
        CPPUNIT_ASSERT(c.hasMoved == false);

    }

    void Creature_Creature3(){
        Creature c(3, 1, 1, 1);

        CPPUNIT_ASSERT(c.counter == 0);
        CPPUNIT_ASSERT(c.species._type == 3);
        CPPUNIT_ASSERT(c.position[0] == 1);
        CPPUNIT_ASSERT(c.position[1] == 1);
        CPPUNIT_ASSERT(c.direction == 1);
        CPPUNIT_ASSERT(c.hasMoved == false);

    }

    void Creature_Creature4(){
        Creature c(2, 2, 2, 2);

        CPPUNIT_ASSERT(c.counter == 0);
        CPPUNIT_ASSERT(c.species._type == 2);
        CPPUNIT_ASSERT(c.position[0] ==2);
        CPPUNIT_ASSERT(c.position[1] == 2);
        CPPUNIT_ASSERT(c.direction == 2);
        CPPUNIT_ASSERT(c.hasMoved == false);

    }

    // --------
    // test_hop
    // --------

    void Creature_hop0()
    {
        Creature c(1,0,3,3);
        c.hop(5);
        CPPUNIT_ASSERT(c.position[0] == 3);
        CPPUNIT_ASSERT(c.position[1] == 2);

    }

    void Creature_hop1()
    {
        Creature c(2,1,3,3);
        c.hop(5);
        CPPUNIT_ASSERT(c.position[0] == 2);
        CPPUNIT_ASSERT(c.position[1] == 3);

    }

    void Creature_hop2(){
        Creature c(0,2,1,1);
        c.hop(5);
        CPPUNIT_ASSERT(c.position[0] == 1);
        CPPUNIT_ASSERT(c.position[1] == 2);
    }

    void Creature_hop3(){
        Creature c(0,3,1,1);
        c.hop(5);
        CPPUNIT_ASSERT(c.position[0] == 2);
        CPPUNIT_ASSERT(c.position[1] == 1);
    }

    void Creature_hop4()
    {
        Creature c(2,1,3,3);
        c.hop(0);
        CPPUNIT_ASSERT(c.position[0] == 3);
        CPPUNIT_ASSERT(c.position[1] == 3);

    }


    // --------
    // test_right
    // --------

    void Creature_right0()
    {
        Creature c(2,0,3,3);
        c.right();
        CPPUNIT_ASSERT(c.direction == 1);

    }

    void Creature_right1()
    {
        Creature c(2,1,3,3);
        c.right();
        CPPUNIT_ASSERT(c.direction == 2);

    }

    void Creature_right2()
    {
        Creature c(2,2,3,3);
        c.right();
        CPPUNIT_ASSERT(c.direction == 3);

    }

    void Creature_right3()
    {
        Creature c(2,3,3,3);
        c.right();
        CPPUNIT_ASSERT(c.direction == 0);

    }

    // --------
    // test_left
    // --------

    void Creature_left1(){
        Creature c(0, 0, 1, 1);
        c.left();
        CPPUNIT_ASSERT(c.direction == 3); 
    }

    void Creature_left2(){
        Creature c(0, 1, 1, 1);
        c.left();
        CPPUNIT_ASSERT(c.direction == 0); 
    }

    void Creature_left3(){
        Creature c(0, 2, 1, 1);
        c.left();
        CPPUNIT_ASSERT(c.direction == 1); 
    }

    void Creature_left4(){
        Creature c(0, 3, 1, 1);
        c.left();
        CPPUNIT_ASSERT(c.direction == 2); 
    }

    // --------
    // test_executeInstruction
    // --------

    void Creature_executeInstruction1()
    {
        Creature c(0, 0, 5, 5);
        c.executeInstruction(5);
        CPPUNIT_ASSERT(c.direction == 3);
    }


    void Creature_executeInstruction2()
    {
        Creature c(2, 1, 5, 5);
        c.counter = 1;
        c.executeInstruction(5);
        CPPUNIT_ASSERT(c.position[0] == 4);
        CPPUNIT_ASSERT(c.position[1] == 5);
        CPPUNIT_ASSERT(c.counter == 8);
    }

    void Creature_executeInstruction3()
    {
        srand(0);
        Creature c(2, 1, 5, 5);
        c.counter = 2;
        c.executeInstruction(5);
        CPPUNIT_ASSERT(c.direction == 2);
    }


    // --------
    // test_Species
    // --------

    void Species_Species0()
    {
        Species s(0);

        CPPUNIT_ASSERT(s.instructions.at(0) == 2);
        CPPUNIT_ASSERT(s.instructions.at(1) == 9);
        CPPUNIT_ASSERT(s.ifarray.at(0) == -1);
        CPPUNIT_ASSERT(s.ifarray.at(1) == 0);

    }

    void Species_Species1(){
        Species s(1);

        CPPUNIT_ASSERT(s.instructions[0] == 1);
        CPPUNIT_ASSERT(s.instructions[1] == 9);
        CPPUNIT_ASSERT(s.ifarray[0] == -1);
        CPPUNIT_ASSERT(s.ifarray[1] == 0);
    }
    void Species_Species2()
    {
        Species s(2);
        CPPUNIT_ASSERT(s.instructions.at(0) == 8);
        CPPUNIT_ASSERT(s.instructions.at(1) == 5);
        CPPUNIT_ASSERT(s.instructions.at(2) == 7);
        CPPUNIT_ASSERT(s.instructions.at(3) == 2);
        CPPUNIT_ASSERT(s.instructions.at(4) == 9);
        CPPUNIT_ASSERT(s.instructions.at(5) == 3);
        CPPUNIT_ASSERT(s.instructions.at(6) == 9);
        CPPUNIT_ASSERT(s.instructions.at(7) == 1);
        CPPUNIT_ASSERT(s.instructions.at(8) == 9);
        CPPUNIT_ASSERT(s.instructions.at(9) == 4);
        CPPUNIT_ASSERT(s.instructions.at(10) == 9);
        CPPUNIT_ASSERT(s.ifarray.at(0) == 9);
        CPPUNIT_ASSERT(s.ifarray.at(1) == 7);
        CPPUNIT_ASSERT(s.ifarray.at(2) == 5);
        CPPUNIT_ASSERT(s.ifarray.at(3) == -1);
        CPPUNIT_ASSERT(s.ifarray.at(4) == 0);
        CPPUNIT_ASSERT(s.ifarray.at(5) == -1);
        CPPUNIT_ASSERT(s.ifarray.at(6) == 0);
        CPPUNIT_ASSERT(s.ifarray.at(7) == -1);
        CPPUNIT_ASSERT(s.ifarray.at(8) == 0);
        CPPUNIT_ASSERT(s.ifarray.at(9) == -1);
        CPPUNIT_ASSERT(s.ifarray.at(10) == 0);

    }

    void Species_Species3(){
        Species s(3);

        CPPUNIT_ASSERT(s.instructions[0] == 8);
        CPPUNIT_ASSERT(s.instructions[1] == 2);
        CPPUNIT_ASSERT(s.instructions[2] == 9);
        CPPUNIT_ASSERT(s.instructions[3] == 4);
        CPPUNIT_ASSERT(s.instructions[4] == 9);
        CPPUNIT_ASSERT(s.ifarray[0] == 3);
        CPPUNIT_ASSERT(s.ifarray[1] == -1);
        CPPUNIT_ASSERT(s.ifarray[2] == 0);
        CPPUNIT_ASSERT(s.ifarray[3] == -1);
        CPPUNIT_ASSERT(s.ifarray[4] == 0);
    }




    CPPUNIT_TEST_SUITE(TestDarwin);
  
    CPPUNIT_TEST(World_World1);
    CPPUNIT_TEST(World_World2);
    CPPUNIT_TEST(World_World3);
    CPPUNIT_TEST(World_addCreature1);
    CPPUNIT_TEST(World_addCreature2);
    CPPUNIT_TEST(World_addCreature3);
    CPPUNIT_TEST(World_hasCreature1);
    CPPUNIT_TEST(World_hasCreature2);
    CPPUNIT_TEST(World_hasCreature3);
    CPPUNIT_TEST(World_findCreature1);
    CPPUNIT_TEST(World_findCreature2);
    CPPUNIT_TEST(World_findCreature3);
    CPPUNIT_TEST(World_whatIsAhead1);
    CPPUNIT_TEST(World_whatIsAhead2);
    CPPUNIT_TEST(World_whatIsAhead3);
    CPPUNIT_TEST(World_whatIsAhead4);
    CPPUNIT_TEST(World_play1);
    CPPUNIT_TEST(World_play2);
    CPPUNIT_TEST(World_play3);
    CPPUNIT_TEST(World_findCreaturePos1);
    CPPUNIT_TEST(World_findCreaturePos2);
    CPPUNIT_TEST(World_findCreaturePos3);
    CPPUNIT_TEST(World_update1);
    CPPUNIT_TEST(World_update2);
    CPPUNIT_TEST(World_update3);
    CPPUNIT_TEST(World_reset1);
    CPPUNIT_TEST(World_reset2);
    CPPUNIT_TEST(World_reset3);
    CPPUNIT_TEST(Creature_Creature1);
    CPPUNIT_TEST(Creature_Creature2);
    CPPUNIT_TEST(Creature_Creature3);
    CPPUNIT_TEST(Creature_Creature4);
    CPPUNIT_TEST(Creature_hop0);
    CPPUNIT_TEST(Creature_hop1);
    CPPUNIT_TEST(Creature_hop2);
    CPPUNIT_TEST(Creature_hop3);
    CPPUNIT_TEST(Creature_hop4);
    CPPUNIT_TEST(Creature_right0);
    CPPUNIT_TEST(Creature_right1);
    CPPUNIT_TEST(Creature_right2);
    CPPUNIT_TEST(Creature_right3);
    CPPUNIT_TEST(Creature_left1);
    CPPUNIT_TEST(Creature_left2);
    CPPUNIT_TEST(Creature_left3);
    CPPUNIT_TEST(Creature_left4);
    CPPUNIT_TEST(Creature_executeInstruction1);
    CPPUNIT_TEST(Creature_executeInstruction2);
    CPPUNIT_TEST(Creature_executeInstruction3);
    CPPUNIT_TEST(Species_Species0);
    CPPUNIT_TEST(Species_Species1);
    CPPUNIT_TEST(Species_Species2);
    CPPUNIT_TEST(Species_Species3);



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