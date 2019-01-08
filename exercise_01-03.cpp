#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  float score1, score2, score3;

  cout << "Type score 1: ";
  cin >> score1;

  cout << "Type score 2: ";
  cin >> score2;

  cout << "Type score 3: ";
  cin >> score3;

  const float average = (score1 + score2 + score3) / 3;

  cout << "The average is: " << average << endl;

  return 0;
}
