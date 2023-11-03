#include <iostream>
#include <stdbool.h>
#include <cstdlib>
#include <string>

using namespace std;

bool invalid(int);
int getwinner(int, int);

const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;
const int DRAW = 3;
const int INVALID = 4;

int main()
{
  // Get computer choice
  srand((unsigned)time(NULL));
  int cpuchoice = rand() % 3;

  int choice = 0;
  cout << "1. Rock\n2. Paper\n3. Scissors\n\n";

  while (invalid(choice))
  {
    cout << "Your pick (1~3): ";
    cin >> choice;
    choice -= 1;
    if (invalid(choice))
      cout << "Invalid input. Try again!" << endl;
  }

  string move[3] = {"Rock", "Paper", "Scissors"};
  cout << "Your choice is " << move[choice] << endl;
  cout << "CPU's choice is " << move[cpuchoice] << endl;

  switch (getwinner(choice, cpuchoice))
  {
  case ROCK:
    cout << "Rock wins!" << endl;
    break;

  case PAPER:
    cout << "Paper wins!" << endl;
    break;

  case SCISSORS:
    cout << "Scissors wins!" << endl;
    break;

  case DRAW:
    cout << "Draw!" << endl;
    break;

  default:
    cout << "Something unexpected happened" << endl;
    break;
  }

  return 0;
}

bool invalid(int choice)
{
  return choice < 1 || choice > 3;
}

int getwinner(int choice1, int choice2)
{
  if (choice1 == choice2)
    return DRAW;
  else if (choice1 == ROCK && choice2 == PAPER)
    return PAPER;
  else if (choice1 == ROCK && choice2 == SCISSORS)
    return ROCK;
  else if (choice1 == PAPER && choice2 == ROCK)
    return PAPER;
  else if (choice1 == PAPER && choice2 == SCISSORS)
    return SCISSORS;
  else if (choice1 == SCISSORS && choice2 == ROCK)
    return ROCK;
  else if (choice1 == SCISSORS && choice2 == PAPER)
    return SCISSORS;
  else
    return INVALID;
}