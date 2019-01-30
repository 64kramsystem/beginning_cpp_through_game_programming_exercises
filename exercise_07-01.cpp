#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string myString = "c64";
  string* pMyString = &myString;
  string** ppMyString = &(pMyString);

  cout << (*ppMyString)->size() << endl;

  return 0;
}
