#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"


using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // creating two linkedlists, alice's cards and bob's cards
  CardList alicecards, bobcards;

  // Read and store each card in helper playingcard p 
  // and then append to alice or bob's linkedlist
  Node::PlayingCard p;

  while (getline (cardFile1, line) && (line.length() > 0)){
    // the first char in the line is the suit, and then a space,
    // and the third is the rank
    p = {line[0], line[2]};
    alicecards.append(p);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    p = {line[0], line[2]};
    bobcards.append(p);
  }
  cardFile2.close();

  // now we store alice's and bob's hands in their player objects:
  Player Alice{"Alice", alicecards, false};
  Player Bob{"Bob", bobcards, false};

  // and then we start the game!
  // the game function is a friend function
  // for the player class, and can be found in cards.cpp
  playGame(Alice, Bob);

  return 0;
}
