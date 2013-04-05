// ------------------------------------
// TestDarwin.c++
// Tim Simmons
// ------------------------------------

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <cstdlib>
#include <cassert>   // assert
#include <vector>


#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private   public
#include "Darwin.h"
#undef private

// -------------
// TestDarwin
// -------------
struct TestDarwin : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------

	// --------
    // Test Instruction Class
    // --------

    void test1 () {
        Instruction i(0, -1);
        CPPUNIT_ASSERT(i.instruct() == 0);
        CPPUNIT_ASSERT(i.line() == -1);
    }

    void test2() {
        Instruction i(1, -1);
        CPPUNIT_ASSERT(i.instruct() == 1);
        CPPUNIT_ASSERT(i.line() == -1);
    }

    void test3() {
        Instruction i(1, 2);
        CPPUNIT_ASSERT(i.instruct() == 1);
        CPPUNIT_ASSERT(i.line() == 2);
    }

    void test4() {
        Instruction i(1);
        CPPUNIT_ASSERT(i.instruct() == 1);
        CPPUNIT_ASSERT(i.line() == -1);
    }

    void test5() {
        Instruction i(4);
        CPPUNIT_ASSERT(i.instruct() == 4);
        CPPUNIT_ASSERT(i.line() == -1);
    }

    void test6() {
        Instruction i(2);
        CPPUNIT_ASSERT(i.instruct() == 2);
        CPPUNIT_ASSERT(i.line() == -1);
    }

    void test7(){
        Instruction i(2);
        Instruction j(3);
        CPPUNIT_ASSERT(i.equals(j) == false);
    }

    void test31(){
        Instruction i(2);
        Instruction j(2);
        CPPUNIT_ASSERT(i.equals(j) == true);
    }

    void test32(){
        Instruction i(2, 2);
        Instruction j(2, 2);
        CPPUNIT_ASSERT(i.equals(j) == true);
    }

//-------
// Test Species
//-------

    void test8(){
        Instruction i(0, -1);
        Species s(i, 't');
        CPPUNIT_ASSERT(s.print() == 't');
        CPPUNIT_ASSERT(s.get(0).instruct() == 0);
        CPPUNIT_ASSERT(s.get(0).line() == -1);
    }

    void test9(){
        Instruction i(2, 2);
        Species s(i, 't');
        CPPUNIT_ASSERT(s.print() == 't');
        CPPUNIT_ASSERT(s.get(0).instruct() == 2);
        CPPUNIT_ASSERT(s.get(0).line() == 2);
    }

    void test10(){
        Instruction i(0, 0);
        Species s(i, 'a');
        CPPUNIT_ASSERT(s.print() == 'a');
        CPPUNIT_ASSERT(s.get(0).instruct() == 0);
        CPPUNIT_ASSERT(s.get(0).line() == 0);
    }

    void test11(){
        Instruction i(0, -1);
        Instruction j(2, 2); 
        Species s(i, 't');
        s.add(j);
        CPPUNIT_ASSERT(s.get(0).instruct() == 0);
        CPPUNIT_ASSERT(s.get(0).line() == -1);
        CPPUNIT_ASSERT(s.get(1).instruct() == 2);
        CPPUNIT_ASSERT(s.get(1).line() == 2);
    }

    void test12(){
        Instruction i(0, -1);
        Instruction j(2, 2); 
        Species s(i, 't');
        s.add(j);
        s.add(i);
        CPPUNIT_ASSERT(s.get(2).instruct() == 0);
        CPPUNIT_ASSERT(s.get(2).line() == -1);
        CPPUNIT_ASSERT(s.get(1).instruct() == 2);
        CPPUNIT_ASSERT(s.get(1).line() == 2);
    }

    void test13(){
        Instruction i(0, -1);
        Instruction j(2, 2); 
        Species s(i, 't');
        s.add(j);
        s.add(j);
        s.add(j);
        CPPUNIT_ASSERT(s.get(3).instruct() == 2);
        CPPUNIT_ASSERT(s.get(3).line() == 2);
    }

    void test14(){
        Instruction i(0, -1);
        Species s(i, 't');
        CPPUNIT_ASSERT(s.equals(s) == true);
    }

    void test15(){
        Instruction i(0, -1);
        Species s(i, 't');
        Species j(i, 't');
        CPPUNIT_ASSERT(s.equals(j) == true);
    }

     void test16(){
        Instruction i(0, -1);
        Species s(i, 't');
        Species j(i, 'l');
        CPPUNIT_ASSERT(s.equals(j) == false);
    }

    void test17(){
        Instruction i(0, -1);
        Instruction j(2, 2); 
        Species s(i, 't');
        Species a(j, 't');
        CPPUNIT_ASSERT(s.equals(a) == false);
    }

//---------
// Test Position
//---------

    void test18(){
        Position p(1, 1, 1);
        CPPUNIT_ASSERT(p.xPos() == 1);
        CPPUNIT_ASSERT(p.yPos() == 1);
        CPPUNIT_ASSERT(p.dir() == 1);
    }

    void test19(){
        Position p;
        CPPUNIT_ASSERT(p.xPos() == 0);
        CPPUNIT_ASSERT(p.yPos() == 0);
        CPPUNIT_ASSERT(p.dir() == 0);
    }

    void test20(){
        Position p(1, 1, 1);
        p.change(2, 2);
        p.change(2);
        CPPUNIT_ASSERT(p.xPos() == 2);
        CPPUNIT_ASSERT(p.yPos() == 2);
        CPPUNIT_ASSERT(p.dir() == 2);
    }

    void test21(){
        Position p;
        p.change(2, 2);
        p.change(2);
        CPPUNIT_ASSERT(p.xPos() == 2);
        CPPUNIT_ASSERT(p.yPos() == 2);
        CPPUNIT_ASSERT(p.dir() == 2);
    }

    void test22(){
        Position p(1, 1, 1);
        Position p2;
        p.change(2, 2);
        p.change(2);
        p2.change(1, 1);
        p2.change(1);
        CPPUNIT_ASSERT(p.xPos() == 2);
        CPPUNIT_ASSERT(p.yPos() == 2);
        CPPUNIT_ASSERT(p.dir() == 2);
        CPPUNIT_ASSERT(p2.xPos() == 1);
        CPPUNIT_ASSERT(p2.yPos() == 1);
        CPPUNIT_ASSERT(p2.dir() == 1);
    }

//-----
// Test Creature
//-----

    void test23() {
        Instruction i(0, -1);
        Species s(i, 't');
        Creature c(s, 10, 2, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(j.instruct() == 0);
        CPPUNIT_ASSERT(j.line() == -1);
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 10);
        CPPUNIT_ASSERT(p.yPos() == 2);
        CPPUNIT_ASSERT(c.exists() == true);
        CPPUNIT_ASSERT(c.print() == 't');
    }

    void test24() {
        Instruction i(2, 2);
        Species s(i, 'f');
        Creature c(s, 1, 1, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(j.instruct() == 2);
        CPPUNIT_ASSERT(j.line() == 2);
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 1);
        CPPUNIT_ASSERT(p.yPos() == 1);
        CPPUNIT_ASSERT(c.exists() == true);
        CPPUNIT_ASSERT(c.print() == 'f');
    }

    void test25() {
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(j.instruct() == 3);
        CPPUNIT_ASSERT(j.line() == 3);
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 10);
        CPPUNIT_ASSERT(p.yPos() == 10);
        CPPUNIT_ASSERT(c.exists() == true);
        CPPUNIT_ASSERT(c.print() == 't');
    }

    void test26(){
        Creature c;
        CPPUNIT_ASSERT(c.exists() == false);
    }

    void test27() {
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);

        Instruction j(2, 2);
        Creature c2(s, 3, 3, 3); 

        Species t(j, 'f');
        Creature c3(t, 2, 2, 2);
        
        CPPUNIT_ASSERT(c.spEqual(c2) == true);
        c3.change(c2);
        CPPUNIT_ASSERT(c.spEqual(c2) == false);
        CPPUNIT_ASSERT(c3.spEqual(c2) == true);
    }

    void test28() {
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);

        Instruction j(2, 2);
        Species t(j, 'f');
        Creature c3(t, 2, 2, 2);
        
        CPPUNIT_ASSERT(c.spEqual(c3) == false);
        c.change(c3);
        CPPUNIT_ASSERT(c.spEqual(c3) == true);
    }

    void test29() {
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);

        Instruction j(2, 2);
        Species t(j, 'f');
        Creature c3(t, 2, 2, 2);
        
        CPPUNIT_ASSERT(c.spEqual(c) == true);
        c.change(c);
        CPPUNIT_ASSERT(c.spEqual(c) == true);
    }

    void test30() {
        Instruction i(3, 3);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_x(true);

        CPPUNIT_ASSERT(c.getCounter() == 3);
    }

    void test33(){
        Instruction i(3, 0);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_x(true);

        CPPUNIT_ASSERT(c.getCounter() == 0);
    }

    void test34(){
        Instruction i(3, 0);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_x(false);

        CPPUNIT_ASSERT(c.getCounter() == 1);
    }

    void test35(){
        Instruction i(3, 0);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_random();

        CPPUNIT_ASSERT(c.getCounter() == 1 || c.getCounter() == 0);
    }

    void test36(){
        Instruction i(3, 1);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_random();

        CPPUNIT_ASSERT(c.getCounter() == 1);
    }

    void test37(){
        Instruction i(3, -1);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.if_random();

        CPPUNIT_ASSERT(c.getCounter() == 1 || c.getCounter() == -1);
    }

    void test38(){
        Instruction i(3, 0);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.go();

        CPPUNIT_ASSERT(c.getCounter() == 0);
    }

    void test39(){
        Instruction i(3, 2);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.go();

        CPPUNIT_ASSERT(c.getCounter() == 2);
    }

    void test40(){
        Instruction i(3, -1);
        Species s(i, 't');
        Instruction j(2, 2);
        Creature c(s, 10, 10, 1);
        c.setCounter(1);
        c.go();

        CPPUNIT_ASSERT(c.getCounter() == -1);
    }

    void test41(){
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 10);
        CPPUNIT_ASSERT(p.yPos() == 10);
        
        c.setPos(1, 1);
        p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 1);
        CPPUNIT_ASSERT(p.yPos() == 1);
    }

    void test42(){
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 10);
        CPPUNIT_ASSERT(p.yPos() == 10);
        
        c.setPos(2, 2);
        p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 2);
        CPPUNIT_ASSERT(p.yPos() == 2);
    }

    void test43(){
        Instruction i(3, 3);
        Species s(i, 't');
        Creature c(s, 10, 10, 1);
        Instruction j = c.instr();
        Position p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 10);
        CPPUNIT_ASSERT(p.yPos() == 10);
        
        c.setPos(11, 11);
        p = c.getPos();
        CPPUNIT_ASSERT(p.dir() == 1);
        CPPUNIT_ASSERT(p.xPos() == 11);
        CPPUNIT_ASSERT(p.yPos() == 11);
    }

    //-------
    // Test Darwin  // print is tested by obviously printing which I won't do here
    //-------

    void test44(){
        Darwin d(2, 2);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,0,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == true);
    }

    void test45(){
        Darwin d(3, 3);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(2,2,0)) == true);
    }

    void test46(){
        Darwin d(1, 1);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == true);
    }

    void test47(){
        Instruction i(0, -1);
        Species s(i, 't');

        Darwin d(2, 2);
        d.addCreature(s, 0, 0, 2);
        d.addCreature(s, 1, 1, 1);

        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == false);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == false);
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(1,1)) == true);
    }

    void test48(){
        Instruction i(0, -1);
        Species s(i, 't');

        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        Creature c1(s, 1, 1, 1);
        d.addCreature(c);
        d.addCreature(c1);

        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == false);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == false);
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(1,1)) == true);
    }

    void test49(){
        Instruction i(0, -1);
        Species s(i, 't');

        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        d.addCreature(c);
        d.addCreature(s, 1, 1, 1);

        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == false);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == false);
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(1,1)) == true);
    }

    void test50(){
        Darwin d(2, 2);
        CPPUNIT_ASSERT(d.checkWall(Position(-1, 0, 1)) == true);
    }

    void test51(){
        Darwin d(2, 2);
        CPPUNIT_ASSERT(d.checkWall(Position(0, 0, 1)) == false);
    }

    void test52(){
        Darwin d(2, 2);
        CPPUNIT_ASSERT(d.checkWall(Position(2, 2, 1)) == true);
    }

    void test53(){
        Instruction i(0, -1);
        Species s(i, 't');
        Species j(i, 'j');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        d.addCreature(c);
        d.addCreature(j, 1, 1, 1);
        CPPUNIT_ASSERT(d.checkCreature(c, Position(1,1,1)) == true);
    }

    void test54(){
        Instruction i(0, -1);
        Species s(i, 't');
        Species j(i, 'j');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        d.addCreature(c);
        d.addCreature(j, 1, 1, 1);
        CPPUNIT_ASSERT(d.checkCreature(c, Position(0,0,1)) == false);
    }

    void test55(){
        Instruction i(0, -1);
        Species s(i, 't');
        Species j(i, 'j');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        d.addCreature(c);
        d.addCreature(j, 1, 1, 1);
        CPPUNIT_ASSERT(d.checkCreature(c, Position(0,1,1)) == false);
    }

    void test56() {
        //if wall 1
        Instruction i(5, 1);
        Species s(i, 'o');
        //left
        s.add(1, -1);
        //hop
        s.add(0, -1);
        Creature c(s, 0, 1, 1);
        Darwin d(2, 2);
        d.addCreature(c);        
        d.giveTurn(d.get(0,1));
        d.giveTurn(d.get(0,1));        //succesful turn and hop
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
    }

    void test57() {

        // if wall 1
        Instruction i(5, 2);
        Species s(i, 'o');
        //if empty 2
        s.add(4, 2);
 
        //hop
        s.add(0, -1);
        Creature c(s, 0, 1, 3);
        Darwin d(2, 2);
        d.addCreature(c);
        // d.print();
        
        d.giveTurn(d.get(0,1));
        // d.print();

        //succesful  hop
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
    }

    void test58() {
        Instruction i(1, -1);
        Species food(i, 'f');
        food.add(8,0);
        Instruction j(7, 3); // if enemy 3
        Species hopChomp(j, 'h');
        hopChomp.add(0, -1);   // hop
        hopChomp.add(8,0);     // go 0
        hopChomp.add(3, -1);   // infect
        hopChomp.add(8, 0);    // go 0

        Darwin d(5, 5);

        Creature f(food, 2, 2, 2);
        Creature h(hopChomp, 4, 2, 1);
        d.addCreature(f);
        d.addCreature(h);
        d.giveTurn(h);//d.get(4,2));
        d.giveTurn(h);//d.get(3,2));
        d.giveTurn(d.get(3,2));
        CPPUNIT_ASSERT(d.get(3,2).spEqual(d.get(2,2)) == true);
    }

    void test59() {
        Instruction i(1, -1);
        Species food(i, 'f');
        food.add(8,0);
        Instruction j(7, 3); // if enemy 3
        Species hopChomp(j, 'h');
        hopChomp.add(0, -1);   // hop
        hopChomp.add(8,0);     // go 0
        hopChomp.add(3, -1);   // infect
        hopChomp.add(8, 0);    // go 0

        Darwin d(5, 5);

        Creature f(food, 2, 2, 2);
        Creature h(hopChomp, 4, 2, 1);
        d.addCreature(f);
        d.addCreature(h);
        d.simulate(3, 1);
        CPPUNIT_ASSERT(d.get(2,1).spEqual(d.get(2,2)) == true);


    }

    void test60(){

        // if wall 1
        Instruction i(5, 2);
        Species s(i, 'o');
        //if empty 2
        s.add(4, 2);
 
        //hop
        s.add(0, -1);
        Creature c(s, 0, 1, 3);
        Darwin d(2, 2);
        d.addCreature(c);
        // d.print();
        
        d.simulate(1, 100);
        // d.print();

        //succesful hop
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
    }

    void test61(){
        Instruction i(5, 1);
        Species s(i, 'o');
        //left
        s.add(1, -1);
        //hop
        s.add(0, -1);
        Creature c(s, 0, 1, 1);
        Darwin d(2, 2);
        d.addCreature(c);        
        d.simulate(2, 100);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
    }

    void test62(){
        Instruction i(0, -1);
        Species s(i, 't');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 3);
        Creature c1(s, 1, 1, 1);
        d.addCreature(c);
        d.addCreature(c1);
        // d.print();
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,0,0)) == true);
        d.hop(c);
        d.hop(c1);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == true);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == true);
    }

    void test73(){
        Instruction i(0, -1);
        Species s(i, 't');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 3);
        d.addCreature(c);
        // d.print();
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,1,0)) == true);
        d.hop(c);
        CPPUNIT_ASSERT(d.checkEmpty(Position(0,0,0)) == true);
    }

    void test63(){
        Instruction i(0, -1);
        Species s(i, 't');
        Darwin d(2, 2);
        Creature c1(s, 1, 1, 1);
        d.addCreature(c1);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,0,0)) == true);
        d.hop(c1);
        CPPUNIT_ASSERT(d.checkEmpty(Position(1,1,0)) == true);
    }

    void test64() {
        Instruction i(0, -1);
        Species s(i, 't');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        d.addCreature(c);
        Position& p = c.getPosRef();
        CPPUNIT_ASSERT(p.dir() == 2);
        d.left(c);
        CPPUNIT_ASSERT(p.dir() == 1);
        d.left(c);
        CPPUNIT_ASSERT(p.dir() == 4);
        d.left(c);
        CPPUNIT_ASSERT(p.dir() == 3);
    }

    void test65() {
        Instruction i(0, -1);
        Species s(i, 't');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 3);
        d.addCreature(c);
        Position& p = c.getPosRef();
        CPPUNIT_ASSERT(p.dir() == 3);
        d.right(c);
        CPPUNIT_ASSERT(p.dir() == 4);
        d.right(c);
        CPPUNIT_ASSERT(p.dir() == 1);
        d.right(c);
        CPPUNIT_ASSERT(p.dir() == 2);
    }

    void test66() {
        Instruction i(0, -1);
        Species s(i, 'o');
        Species s2(i, 'i');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        Creature cc(s2, 0, 1, 1);
        d.addCreature(c);
        d.addCreature(cc);
        d.infect(c);
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(0,1)) == true);
    }

    void test67() {
        Instruction i(0, -1);
        Species s(i, 'o');
        Species s2(i, 'i');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        Creature cc(s2, 0, 1, 4);
        d.addCreature(c);
        d.addCreature(cc);
        d.infect(d.get(0, 1));
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(0,1)) == true);
    }

    void test68() {
        Instruction i(0, -1);
        Species s(i, 'o');
        Species s2(i, 'i');
        Darwin d(2, 2);
        Creature c(s, 0, 0, 2);
        Creature cc(s2, 0, 1, 4);
        d.addCreature(c);
        d.addCreature(cc);
        d.infect(d.get(0,0));
        CPPUNIT_ASSERT(d.get(0,0).spEqual(d.get(0,1)) == true);
    }

    void test69() {
        Darwin d(2,2);
        Position p(1, 1, 2);
        Position pp = d.posHelper(p);
        CPPUNIT_ASSERT(pp.xPos() == 1);
        CPPUNIT_ASSERT(pp.yPos() == 2);
        CPPUNIT_ASSERT(pp.dir() == 2);
    }

    void test70() {
        Darwin d(2,2);
        Position p(1, 1, 3);
        Position pp = d.posHelper(p);
        CPPUNIT_ASSERT(pp.xPos() == 2);
        CPPUNIT_ASSERT(pp.yPos() == 1);
        CPPUNIT_ASSERT(pp.dir() == 3);
    }

    void test71() {
        Darwin d(2,2);
        Position p(1, 1, 1);
        Position pp = d.posHelper(p);
        CPPUNIT_ASSERT(pp.xPos() == 0);
        CPPUNIT_ASSERT(pp.yPos() == 1);
        CPPUNIT_ASSERT(pp.dir() == 1);
    }

    void test72() {
        Darwin d(2,2);
        Position p(1, 1, 4);
        Position pp = d.posHelper(p);
        CPPUNIT_ASSERT(pp.xPos() == 1);
        CPPUNIT_ASSERT(pp.yPos() == 0);
        CPPUNIT_ASSERT(pp.dir() == 4);
    }

    void test(){
        for (int i = 1; i < 74; ++i)
        {
            cout << "CPPUNIT_TEST(test" << i << ");" << endl;
        }
    }
   


    

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test4);
    CPPUNIT_TEST(test5);
    CPPUNIT_TEST(test6);
    CPPUNIT_TEST(test7);
    CPPUNIT_TEST(test8);
    CPPUNIT_TEST(test9);
    CPPUNIT_TEST(test10);
    CPPUNIT_TEST(test11);
    CPPUNIT_TEST(test12);
    CPPUNIT_TEST(test13);
    CPPUNIT_TEST(test14);
    CPPUNIT_TEST(test15);
    CPPUNIT_TEST(test16);
    CPPUNIT_TEST(test17);
    CPPUNIT_TEST(test18);
    CPPUNIT_TEST(test19);
    CPPUNIT_TEST(test20);
    CPPUNIT_TEST(test21);
    CPPUNIT_TEST(test22);
    CPPUNIT_TEST(test23);
    CPPUNIT_TEST(test24);
    CPPUNIT_TEST(test25);
    CPPUNIT_TEST(test26);
    CPPUNIT_TEST(test27);
    CPPUNIT_TEST(test28);
    CPPUNIT_TEST(test29);
    CPPUNIT_TEST(test30);
    CPPUNIT_TEST(test31);
    CPPUNIT_TEST(test32);
    CPPUNIT_TEST(test33);
    CPPUNIT_TEST(test34);
    CPPUNIT_TEST(test35);
    CPPUNIT_TEST(test36);
    CPPUNIT_TEST(test37);
    CPPUNIT_TEST(test38);
    CPPUNIT_TEST(test39);
    CPPUNIT_TEST(test40);
    CPPUNIT_TEST(test41);
    CPPUNIT_TEST(test42);
    CPPUNIT_TEST(test43);
    CPPUNIT_TEST(test44);
    CPPUNIT_TEST(test45);
    CPPUNIT_TEST(test46);
    CPPUNIT_TEST(test47);
    CPPUNIT_TEST(test48);
    CPPUNIT_TEST(test49);
    CPPUNIT_TEST(test50);
    CPPUNIT_TEST(test51);
    CPPUNIT_TEST(test52);
    CPPUNIT_TEST(test53);
    CPPUNIT_TEST(test54);
    CPPUNIT_TEST(test55);
    CPPUNIT_TEST(test56);
    CPPUNIT_TEST(test57);
    CPPUNIT_TEST(test58);
    CPPUNIT_TEST(test59);
    CPPUNIT_TEST(test60);
    CPPUNIT_TEST(test61);
    CPPUNIT_TEST(test62);
    CPPUNIT_TEST(test63);
    CPPUNIT_TEST(test64);
    CPPUNIT_TEST(test65);
    CPPUNIT_TEST(test66);
    CPPUNIT_TEST(test67);
    CPPUNIT_TEST(test68);
    CPPUNIT_TEST(test69);
    CPPUNIT_TEST(test70);
    CPPUNIT_TEST(test71);
    CPPUNIT_TEST(test72);
    CPPUNIT_TEST(test73);
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
    return 0;
}

