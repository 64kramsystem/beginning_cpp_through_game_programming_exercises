The textbook code doesn't perform dereferencing, therefore, it increments the iterator instead of the referenced value.

Correct code:

```cpp
  for (iter = scores.begin(); iter != scores.end(); ++iter)
  {
    (*iter)++;
  }
```
