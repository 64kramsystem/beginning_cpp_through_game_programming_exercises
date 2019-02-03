It leaks; the old pointed value memory is not freed before it's reassigned to the new value (`new int(1000)`)

```cpp
int* pScore = new int;
*pScore = 500;
pScore = new int(1000); // pScore should be freed before
```
