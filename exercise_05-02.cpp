// Poorly refactored version of Hangman.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

vector<string> generateWords()
{
  vector<string> words;  // collection of possible words to guess

  words.push_back("GUESS");
  words.push_back("HANGMAN");
  words.push_back("DIFFICULT");

  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(words.begin(), words.end());

  return words;
}

void printIntroduction()
{
  cout << "Welcome to Hangman.  Good luck!\n";
}

void printStatus(int wrong, string used, string soFar)
{
  cout << "\n\nYou have " << (MAX_WRONG - wrong);
  cout << " incorrect guesses left.\n";
  cout << "\nYou've used the following letters:\n" << used << endl;
  cout << "\nSo far, the word is:\n" << soFar << endl;
}

char askGuess(string promptPrefix)
{
  char guess;

  cout << "\n" << promptPrefix;
  cout << "Enter your guess: ";
  cin >> guess;
  guess = toupper(guess);

  return guess;
}

void printGuessIsCorrect(char guess)
{
  cout << "That's right! " << guess << " is in the word.\n";
}

void updateSoFar(const string THE_WORD, char guess, string soFar)
{
  // update soFar to include newly guessed letter
  for (unsigned int i = 0; i < THE_WORD.length(); ++i)
  {
    if (THE_WORD[i] == guess)
    {
      soFar[i] = guess;
    }
  }
}

void printGuessIsIncorrect(char guess)
{
  cout << "Sorry, " << guess << " isn't in the word.\n";
}

void shutDown(int wrong, const string THE_WORD)
{
  // shut down
  if (wrong == MAX_WRONG)
    cout << "\nYou've been hanged!";
  else
    cout << "\nYou guessed it!";
  
  cout << "\nThe word was " << THE_WORD << endl;
}

int main()
{
    vector<string> words = generateWords();

    const string THE_WORD = words[0];            // word to guess
    int wrong = 0;                               // number of incorrect guesses
    string soFar(THE_WORD.size(), '-');          // word guessed so far
    string used = "";                            // letters already guessed

    printIntroduction();

    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
      printStatus(wrong, used, soFar);

      char guess = askGuess("\n");

      while (used.find(guess) != string::npos)
      {
        guess = askGuess("You've already guessed " + string(1, guess) + "\n");
      }

      used += guess;

      if (THE_WORD.find(guess) != string::npos)
      {
        printGuessIsCorrect(guess);
        updateSoFar(THE_WORD, guess, soFar);
      }
      else
      {
        printGuessIsIncorrect(guess);
        ++wrong;
      }
    }

  shutDown(wrong, THE_WORD);

  return 0;
}
