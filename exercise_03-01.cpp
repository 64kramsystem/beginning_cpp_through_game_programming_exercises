#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(static_cast<unsigned int>(time(0)));

  enum fields {WORD, HINT};
  const int NUM_FIELDS = 2, NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][NUM_FIELDS] = {
    {"wall", "Do you feel you're banging your head against something?"},
    {"glasses", "These might help you see the answer."},
    {"labored", "Going slowly, is it?"},
    {"persistent", "Keep at it."},
    {"jumble", "It's what the game is all about."}
  };
  const int HINT_COST = 2;

  int score = 0;

  int choice = (rand() % NUM_WORDS);
  string theWord = WORDS[choice][WORD];  // word to guess
  string theHint = WORDS[choice][HINT];  // hint for word

  string jumble = theWord;  // jumbled version of word
  int length = jumble.size();
  for (int i=0; i<length; ++i)
  {
    int index1 = (rand() % length);
    int index2 = (rand() % length);
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
  cout << "Unscramble the letters to make a word." << endl;
  cout << "Enter 'hint' for a hint." << endl;
  cout << "Enter 'quit' to quit the game." << endl << endl;
  cout << "The jumble is: " << jumble;

  string guess;
  cout << endl << endl << "Your guess: ";
  cin >> guess;

  while ((guess != theWord) && (guess != "quit"))
  {
    bool hintGiven = false;

    if (guess == "hint")
		{
      cout << theHint;

      if (!hintGiven)
      {
        score -= HINT_COST;
        hintGiven = true;
      }
		}
    else
		{
      cout << "Sorry, that's not it.";
		}

    cout << endl << endl << "Your guess: ";
    cin >> guess;
  }

  if (guess == theWord)
	{
    cout << endl << "That's it!  You guessed it!" << endl;
    score += theWord.size();
	}

  cout << endl << "Thanks for playing. Your score: " << score << endl;

  return 0;
}
