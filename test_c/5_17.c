#define SIZE 2048

void copyij(int s[SIZE][SIZE], int t[SIZE][SIZE]) {
  int i, j;

  for (i = 0; i < SIZE; ++i) {
    for (j = 0; j < SIZE; ++j) s[i][j] = t[i][j];
  }
}

void copyji(int s[SIZE][SIZE], int t[SIZE][SIZE]) {
  int i, j;

  for (j = 0; j < SIZE; ++j) {
    for (i = 0; i < SIZE; ++i) s[i][j] = t[i][j];
  }
}
