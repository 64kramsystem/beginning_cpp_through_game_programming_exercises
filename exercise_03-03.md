The size of the dimensions of the array are inverted; it should be:

```cpp
const int ROWS = 2, COLUMNS = 3;
char board[ROWS][COLUMNS] = { {'O', 'X', 'O'}, {' ', 'X', 'X'} };
```
