#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

using std::string;
using std::vector;

int main()
{
  enum possibleChoice { LIST = 'l', ADD = 'a', REMOVE = 'r', QUIT = 'q' };

  vector<string> games;
  bool exit = false;

  do
  {
    char choice;

    cout << endl;

    cout << "Choose:" << endl;
    cout << "- list (" << (char)LIST << ")" << endl;
    cout << "- add (" << (char)ADD << ")" << endl;
    cout << "- remove (" << (char)REMOVE << ")" << endl;
    cout << "- quit (" << (char)QUIT << ")" << endl;
    cin >> choice;

    cout << endl;

    switch(choice)
    {
      case LIST:
        if (games.empty())
        {
          cout << "No games in the list!" << endl;
        }
        else
        {
          cout << "Games:" << endl;

          for (unsigned int gamesIdx = 0; gamesIdx < games.size(); ++gamesIdx)
          {
            cout << gamesIdx << ") " << *(games.begin() + gamesIdx) << endl;
          }
        }

        break;
      case ADD:
      {
        string newGameTitle;

        cout << "Enter the game title: ";

        // In very poor form, the book not only implies the use of an API unexplained at this point,
        // but such API has also a complexity not obvious to a beginner.
        cin.ignore();
        getline(cin, newGameTitle);

        // Unrequested but cool.
        vector<string>::const_iterator gamesIter = upper_bound(games.begin(), games.end(), newGameTitle);

        games.insert(gamesIter, newGameTitle);

        break;
      }
      case REMOVE:
      {
        unsigned int removeGameIndex;

        if (games.empty())
        {
          cout << "No games in the list!" << endl;
        }
        else
        {
          cout << "Enter the index of the game to remove (0-" << games.size() - 1 << "): " << endl;
          cin >> removeGameIndex;

          if (removeGameIndex >= games.size())
          {
            cout << "Index too high!" << endl;
          }
          else
          {
            games.erase(games.begin() + removeGameIndex);
          }
        }
        break;
      }
      case QUIT:
        exit = true;

        break;
      default:
        cout << "Invalid choice!" << endl;

        break;
    }
  } while (!exit);
  
  return 0;
}
