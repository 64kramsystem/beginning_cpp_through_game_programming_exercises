#include <iostream>
#include <string>

using std::cin;
using std::cout;

using std::string;

const string DEFAULT_PROMPT = "Number please!: ";

int returnNumber(string prompt = DEFAULT_PROMPT)
{
  int number;

  cout << prompt;
  cin >> number;

  return number;
}

// It's not clear what the books intends with "using function overloading, write
// a function that achieves the same results", as we can't overload the original
// function.
// A reasonable guess is that two, overloaded, functions need to be written,
// achieving the same functionality as a single function with a default parameter.
//
int altReturnNumber()
{
  altReturnNumber(DEFAULT_PROMPT); // hehe
}

int altReturnNumber(string prompt)
{
  int number;

  cout << prompt;
  cin >> number;

  return number;
}

int main()
{
  return 0;
}
