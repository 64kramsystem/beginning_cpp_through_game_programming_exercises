#include <iostream>

using namespace std;

int main()
{
  const int minNumber = 0;
  const int maxNumber = 100;

  int secretNumber;
  
  cout << "Welcome!" << endl << endl;

  do
  {
    cout << "Enter the secret number (min=" << minNumber << ", max=" << maxNumber << "): ";
    cin >> secretNumber;
  } while (secretNumber < minNumber || maxNumber < secretNumber);

  int attempts = 0;
  int minGuess = minNumber;
  int maxGuess = maxNumber;

  while (true)
  {
    int guess = (minGuess + maxGuess) / 2;
    ++attempts;

    cout << "Guess: " << guess << " => ";

    if (guess > secretNumber)
    {
      cout << "Too high!" << endl;
      maxGuess = guess - 1;
    }
    else if (guess < secretNumber)
    {
      cout << "Too low!" << endl;
      minGuess = guess + 1;
    }
    else
    {
      cout << "Success! Got it in " << attempts << " attempts." << endl;
      break;
    }
  }
}
