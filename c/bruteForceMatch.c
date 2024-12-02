#include <stdio.h>
#include <string.h>

int bruteForceMatch(char *text, char *pattern)
{
  int n = strlen(text);
  int m = strlen(pattern);

  for(int i = 0; i <= n - m; i++) {
    int j = 0;
    while (j < m && text[i + j] == pattern[j]) {
      j++;
    }
    if(j == m) {
      return i;
    }
  }
  return -1;
}

int main()
{
  char text[] = "ABACDABA";
  char pattern[] = "ABA";

  int index = bruteForceMatch(text, pattern);
  if(index != -1) {
    printf("pattern found at index %d\n", index);
  }
  else {
    printf("pattern not found\n");
  }
  return 0;
}
