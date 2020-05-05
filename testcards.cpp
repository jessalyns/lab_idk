// This file should contain unit tests for all the 
// public inxterfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_node_operators();
  test_card_list();
  test_card_list_operators();
  test_get_next();
  test_find();
  test_find_and_remove();
}

// --- TESTS ---
void test_append() {
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");
}

void test_node_operators(){
  START_TEST("test_node_operators");
  test_empty_node_double_equal();
  test_node_double_equal();
  END_TEST("test_node_operators");
}

void test_card_list() {
  START_TEST("test_card_list");
  test_card_list_copy_constructor();
  test_card_list_copy_assignment();
  END_TEST("test_card_list");
}

void test_card_list_operators() {
  START_TEST("test_card_list_operators");
  test_empty_list_double_equal();
  test_card_list_double_equal();
  END_TEST("test_card_list_operators");
}

void test_get_next() {
  START_TEST("test_get_next");
  test_nullptr_empty_list();
  test_nullptr_two_element_list();
  test_firstptr_two_element_list();
  test_lastptr_two_element_list();
  END_TEST("test_get_next");
 }

void test_find() {
  START_TEST("test_find");
  test_find_empty_list();
  test_find_not_in_list();
  test_find_in_list();
  END_TEST("test_find");
}

void test_find_and_remove() {
  START_TEST("test_find_and_remove");
  test_remove_empty_list();
  test_remove_not_in_list();
  test_remove_in_list();
  END_TEST("test_find_and_remove");
 }

// --- TEST CASES ---
// Tests for test_append
void test_append_empty_list() {
  string testname = "case 0: empty list";
  CardList c1; // empty list
  Node::PlayingCard p{'h','3'};
  Node *n1 = new Node;
  n1 -> card = p; // test node
  c1.append(p);
  assertEquals(*(c1.getNext(nullptr)),*n1, testname); // check first node
  // against test node
}

void test_append_single_element_list() {
  string testname = "case 1: single element list";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  Node *n1 = new Node;
  n1 -> card = p2; // test node
  c1.append(p1); 
  c1.append(p2);
  assertEquals(*(c1.getNext(nullptr) -> next), *n1, testname); // check second
  // node against test node
}

// Tests for test_node_operators
void test_empty_node_double_equal() {
  string testname = "case 0: empty nodes";
  Node *n1 = new Node;
  Node *n2 = new Node;
  assertEquals(*n1, *n2, testname);
}

void test_node_double_equal() {
  string testname = "case 1: nodes with same PlayingCard";
  Node *n1 = new Node;
  Node *n2 = new Node;
  Node::PlayingCard p{'h','3'};
  n1 -> card = p;
  n2 -> card = p; // add same card to both nodes
  assertEquals(*n1, *n2, testname);
}

// Tests for test_card_list
void test_card_list_copy_constructor() {
  string testname = "case 0: copy constructor on three element list";
  CardList c1;
  Node::PlayingCard p1{'h', 3}, p2{'c', 2}, p3{'s', 9};
  c1.append(p1);
  c1.append(p2);
  c1.append(p3);
  CardList c2(c1); // call to copy constructor
  assertEquals(c1, c2, testname);
}

void test_card_list_copy_assignment() {
  string testname = "case 1: copy assignment on three element list";
  CardList c1, c2;
  Node::PlayingCard p1{'h', 3}, p2{'c', 2}, p3{'s', 9};
  c1.append(p1);
  c1.append(p2);
  c1.append(p3);
  c2 = c1; // call to copy assignment
  assertEquals(c1, c2, testname);
}

// Tests for test_card_list_operators
void test_empty_list_double_equal() {
  string testname = "case 0: empty lists";
  CardList c1, c2;
  assertEquals(c1, c2, testname);
}

void test_card_list_double_equal() {
  string testname = "case 1: two element lists with same PlayingCards in same order";
  CardList c1, c2;
  Node::PlayingCard p1{'h', 3}, p2{'c', 2};
  c1.append(p1);
  c2.append(p1);
  c1.append(p2);
  c2.append(p2); // add same two cards to both lists
  assertEquals(c1, c2, testname);
}

//Tests for test_get_next
void test_nullptr_empty_list() {
  string testname = "case 0: empty list";
  CardList c1;
  Node *p = c1.getNext(nullptr);
  assertEquals(p, 0, testname);
}

void test_nullptr_two_element_list() {
  string testname = "case 1: called on two element list with nullptr";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  Node *n1 = new Node;
  n1 -> card = p1; // test node
  c1.append(p1);
  c1.append(p2);
  Node *n2 = c1.getNext(nullptr); // should point to first node
  assertEquals(*n1, *n2, testname);
}

void test_firstptr_two_element_list() {
  string testname = "case 2: called on two element list with pointer to first node";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  Node *n1 = new Node;
  n1 -> card = p2; // test node
  c1.append(p1);
  c1.append(p2);
  Node *n2 = c1.getNext(nullptr); // should point to first node
  Node *n3 = c1.getNext(n2); // should point to second node
  assertEquals(*n1, *n3, testname);
}

void test_lastptr_two_element_list() {
  string testname = "case 2: called on two element list with pointer to last node";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  c1.append(p1);
  c1.append(p2);
  Node *n1 = c1.getNext(nullptr); // should point to first node
  Node *n2 = c1.getNext(n1); // should point to second node
  Node *n3 = c1.getNext(n2); // should be nullptr
  assertEquals(n3, 0, testname);
}

// Tests for test_find
void test_find_empty_list() {
  string testname = "case 0: empty list";
  CardList c1;
  Node::PlayingCard p{'h','3'};
  Node *n = new Node;
  n -> card = p;
  assertEquals(c1.find(n), false, testname);
}

void test_find_not_in_list() {
  string testname = "case 1: find card not in list";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  c1.append(p1);
  Node *n = new Node;
  n -> card = p2;
  assertEquals(c1.find(n), false, testname);
}

void test_find_in_list() {
  string testname = "case 2: find card in list";
  CardList c1;
  Node::PlayingCard p1{'h','3'}, p2{'c','2'};
  c1.append(p1);
  c1.append(p2);
  Node *n = new Node;
  n -> card = p2;
  assertEquals(c1.find(n), true, testname);
}

// Tests for test_find_and_remove
void test_remove_empty_list() {
  string testname = "case 0: empty list";
  CardList c1, c2;
  Node::PlayingCard p{'h', 3};
  Node *n = new Node;
  n -> card = p;
  c1.find_and_remove(n); // should do nothing
  assertEquals(c1, c2, testname); // empty lists still equal
}

void test_remove_not_in_list() {
  string testname = "case 1: remove card not in list";
  CardList c1;
  Node::PlayingCard p1{'h',3}, p2{'c', 2}, p3{'s', 9};
  c1.append(p1);
  c1.append(p2);
  Node *n = new Node;
  n -> card = p3;
  CardList c2(c1);
  c1.find_and_remove(n); // should do nothing
  assertEquals(c1, c2, testname); // test lists still equal
}

void test_remove_in_list() {
  string testname = "case 2: remove card in list";
  CardList c1, c2;
  Node::PlayingCard p1{'h',3}, p2{'c', 2}, p3{'s', 9};
  c1.append(p1);
  c1.append(p2);
  c1.append(p3);
  c2.append(p1);
  c2.append(p3); // c2 does not have point p2
  Node *n = new Node;
  n -> card = p2;
  c1.find_and_remove(n); // removes point p2 from c1
  assertEquals(c1, c2, testname); // lists should now be equal
}





