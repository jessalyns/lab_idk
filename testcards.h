// testcards.h
//Authors: Jessalyn Sebastian and Rebecca Embar
//All test declarations go here

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_append();
void test_node_operators();
void test_card_list();
void test_card_list_operators();
void test_get_next();
void test_find();
void test_find_and_remove();

// Test cases
void test_append_empty_list();
void test_append_single_element_list();
void test_empty_node_double_equal();
void test_node_double_equal();
void test_card_list_copy_constructor();
void test_card_list_copy_assignment();
void test_empty_list_double_equal();
void test_card_list_double_equal();
void test_nullptr_empty_list();
void test_nullptr_two_element_list();
void test_firstptr_two_element_list();
void test_lastptr_two_element_list();
void test_find_empty_list();
void test_find_in_list();
void test_find_not_in_list();
void test_remove_empty_list();
void test_remove_in_list();
void test_remove_not_in_list();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(Node* expected, Node* actual, string testDescription){
  if (expected == actual) {
    cout << "PASSED " << endl;
  } else {
    cout << "  FAILED: " << testDescription << endl << "  Expected: " << expected <<
      " Actual: " << actual << endl;
  }
}

void assertEquals(bool expected, bool actual, string testDescription) {
  if (expected == actual) {
    cout << "PASSED " << endl;
  } else {
    cout << "  FAILED: " << testDescription << endl << "  Expected: " << expected <<
      " Actual: " << actual << endl;
  }
}

void assertEquals(Node& expected, Node& actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(CardList expected, CardList actual, string testDescription) {
  if (expected == actual) {
    cout << "PASSED " << endl;
  } else {
    cout << "  FAILED: " << testDescription << endl << "  Expected: " << expected <<
      " Actual: " << actual << endl;
  }
}


#endif
