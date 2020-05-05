//cards.cpp
//Authors: Rebecca Embar and Jessalyn Sebastian 
//Implementation of the classes defined and described in cards.h

#include <iostream>
#include "cards.h"
using namespace std;



// IMPLEMENTATIONS FOR CLASS NODE

ostream& operator<<(std::ostream& out, const Node& n) {
  out << n.card.suit << " " << n.card.rank;
  return out;
}

bool Node::operator==(const Node& n2) {
  if (card.suit == n2.card.suit && card.rank == n2.card.rank) 
    return true;
  return false;
}




// IMPLEMENTATIONS FOR CLASS CARDLIST

CardList::~CardList() {
  while (first) {
    Node *n = first -> next;
    delete first;
    first = n;
  }
}

CardList::CardList(const CardList& source) {
  Node* n = source.first;
  first = 0;
  while (n) {
    append(n -> card);
    n = n -> next;
  }
}

CardList& CardList::operator=(const CardList& source) {
  CardList temp = source;
  std::swap(first, temp.first);
  return *this;
}

bool CardList::operator==(const CardList& c2) {
  Node *n = first;
  Node *n2 = c2.first;
  while (n) {
    if (!n2 || !(*n == *n2)) {
      return false;
    }
    n = n->next;
    n2 = n2->next;
  }
  if (!n2) {
    return true;
  }
  return false;
}

ostream& operator<<(std::ostream &out, const CardList& c) {
  Node *n = c.first;
  while (n) {
    cout << *n << endl;
    n = n->next;
  }
  return out;
}

void CardList::append(Node::PlayingCard p) {
  if (first == 0) { // empty list
    first = new Node;
    first -> card = p;
    first -> next = 0;
  }
  else {
    Node *n = first;
    while (n -> next) // not last node yet
      n = n -> next;
    n -> next = new Node;
    n -> next -> card = p;
    n -> next -> next = 0;
  }
}

Node* CardList::getNext(Node* n) {
  if (n == nullptr) {
    return first;
  }
  if (n && n->next) {
    return n->next;
  }
  return 0;
}

Node* CardList::find(Node* n){
  Node* f = first;
  while (f) {
    if (*f == *n) {
      return f;}
    f = f -> next;
  }
  return nullptr;
}

bool CardList::find_and_remove(Node* n){
  Node* found = find(n);
  if (!found) return false;
  Node* f = first;
  while (!(*(f -> next) == *found)){
    f = f -> next;
  }
  f -> next = f -> next -> next;
  delete found;
  return true;
}



// IMPLEMENTATIONS FOR CLASS PLAYER

void playGame(Player& player1, Player& player2){ // no return, simply prints. PLAYER 1 GOES FIRST. (alice, for our purposes.)

    Node* a = player1.hand.getNext(nullptr); // pointers to the start of the players' hands to keep track of where to start
    Node* b = player2.hand.getNext(nullptr); 

    player1.turn = true; // player1 gets the first turn
    player2.turn = false;

    while (a && b){ // game continues until either a or b is a null pointer
        if (player1.turn == true && player2.turn == false){
            takeTurn(player1, player2, a); 
            // player1 will start in their hand at pointer a
        }
        if (player2.turn == true && player1.turn == false){
            takeTurn(player2, player1, b);
            // player2 will start in their hand at pointer b
        }
        player1.switchTurns();
        player2.switchTurns();
    }
    cout << " " << endl;
    cout << player1.name << "'s cards: " << endl;
    cout << player1.hand << endl;
    cout << " " << endl;
    cout << player2.name << "'s cards: " << endl;
    cout << player2.hand << endl;
}

void Player::switchTurns(){
  turn = !turn;
}

void takeTurn(Player& active, Player& opponent, Node*& start){
    // active player is taking their turn looking through opponent's cards
    // start indicates where in the active player's hand they will begin searching
    // needs to be a reference to a pointer so the value of the pointer is changed
    if (start){
      if (opponent.hand.find_and_remove(start)){
          active.hand.find_and_remove(start);
          cout << active.name << " picked matching card " << *start << endl;
          start = start -> next;
      }
      else{
          start = start -> next;
          takeTurn(active, opponent, start);
      }
    }
}

