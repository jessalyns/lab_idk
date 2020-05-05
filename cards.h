//cards.h
//Authors: Rebecca Embar and Jessalyn Sebastian
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;


class Node { 
    public:
        Node() { card = {'\0', '\0'}; next = 0; }
        // constructor initializes node to empty
        // default destructor, copy constructor, copy assignment are acceptable.

        friend ostream& operator<<(std::ostream& out, const  Node& n);
        // OVERLOADED << OPERATOR
        // precondition: called with parameter of class Node
        // postcondition: if called with cout as ostream parameter, will print
        // card in format suit [space] rank

        bool operator==(const Node& n2);
        // OVERLOADED == OPERATOR
        // precondition: two valid nodes (can be empty)
        // postcondition: returns true if both suit and rank of card are equal

        // PlayingCard is public struct - needs to be accessed by Cardlist
        struct PlayingCard {
          char suit;
          char rank;
        };

      PlayingCard card;
      Node* next;
};


class CardList{
    public:
      CardList() { first = 0; }
      // constructor initializes to empty CardList
    
      ~CardList();
      // deletes all nodes
    
      CardList(const CardList& source); 
      // copy constructor (deep copy)
    
      CardList& operator=(const CardList& source); 
      // OVERLOADED = OPERATOR
      // copy assignment (deep copy)

      friend ostream& operator<<(std::ostream& out, const CardList& c); 
      // OVERLOADED << OPERATOR
      // precondition: valid cardlist
      // postcondition: prints cardlist to terminal with endlines between the cards
    
      bool operator==(const CardList& c2); 
      // OVERLOADED == OPERATOR
      // precondition: two valid cardlists
      // postcondition: returns true if the lists contain the same cards in the same order
  
      void append(Node::PlayingCard p);
      // precondition: valid cardlist and playingcard
      // postcondition: adds the playingcard to the end of the cardlist
 
      Node* getNext(Node* n);
      // precondition: called on a cardlist, and using parameter node* type.
      // postconditions: if parameter n is nullptr, will return pointer
      //                 to first node in the list
      //                 if parameter is node in the list, will return
      //                 pointer to the next node
      //                 if parameter is last node in the list, will return nullptr

      
      Node* find(Node* n);
      // precondition: valid cardlist and pointer to a node
      // postcondition: returns a pointer to the node in the cardlist that contains the same card as *n

      bool find_and_remove(Node* n);
      // precondition: valid cardlist and pointer to node
      // postcondition: if card in *n not found in cardlist, returns false, no changes to list.
      //                if card found, removes card and returns true.

    private:
      Node *first; // pointer to first node in list
};



class Player{
 public:
      Player(); 
      // default constructor (had issues setting default values in parameterized constructor)
    
      Player(string nm, CardList hd, bool t){
            // parameterized constructor w defaults
          name = nm;
          hand = hd;
          turn = t;
      }
      // parameterized constructor

      void switchTurns();
      // precondition: a valid player object
      // postcondition: changes turn from true to false or vice versa

      friend void playGame(Player& player1, Player& player2);
      // precondition: two players with valid cardlists
      // postcondition: starts the go fish game, returns nothing, only prints. players take turns
      //                 searching for matches in each other's hands, game ends when there are no more matches.

      friend void takeTurn(Player& active, Player& opponent, Node*& start);
      // precondition: two players playing the game, and a pointer to a node in the active player's hand
      //               which indicates where they are to start the search (so they start where they left off each round
      // postcondition: a player (active) takes their turn against their opponent. ends when a match is found and the 
      //                matching card is removed from both players' hands.

    
      // playGame and takeTurn are friends so that they can easily access private member variables of the players.
    
    
   private:
      string name;
        // the name of the player, i.e. Alice or Bob.

      CardList hand;
        // the list of cards in their hand.

      bool turn;
        // whether or not it is the player's turn.
};

#endif

