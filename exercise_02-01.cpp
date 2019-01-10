#include <iostream>

using namespace std;

int main()
{
  enum difficulty { EASY=1, NORMAL, HARD };

  cout << "Difficulty Levels" << endl << endl;
  cout << EASY << " - Easy" << endl;
  cout << NORMAL << " - Normal" << endl;
  cout << HARD << " - Hard" << endl << endl;

  int choice;
  cout << "Choice: ";
  cin >> choice;

  switch (choice)
  {
    case EASY:
      cout << "You picked Easy.\n";
      break;
    case NORMAL:
      cout << "You picked Normal.\n";
      break;
    case HARD:
      cout << "You picked Hard.\n";
      break;
    default:
      cout << "You made an illegal choice.\n";
  }
  return 0;
}