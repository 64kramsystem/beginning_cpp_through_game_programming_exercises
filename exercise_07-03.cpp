#include <iostream>

using namespace std;

int main()
{
  int a = 10;
  int& b = a;
  int* c = &b;

  // Address of `a`
  cout << &a << endl;

  // In this context, as reference behaves as the referenced object [the string];
  // therefore, using the `&` operator returns the address of the string.
  cout << &b << endl;

  // address of `a`: `*` dereferences the reference, yielding the string, then,
  // `&` returns the address [of the string]
  cout << &(*c) << endl;

  return 0;
}
