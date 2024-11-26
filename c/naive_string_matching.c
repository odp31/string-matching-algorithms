#include <stdio.h>
#include <string.h>

void naive_pattern_search(char *pat, char *txt)
{
  int M = strlen(pat);
  int N = strlen(txt);

  int i, j;
  for(i = 0; i <= N - M; i++) {
    for(j = 0; j < M; j++) {
      if(txt[i + j] != pat[j]) {
        break;
      }
    }
    if(j == M) {
      printf("pattern found at index %d \n", i);
    }
  }
}

int main()
{
  char txt[] = "AABAACAADAABAAABAA";
  char pat[] = "AABA";

  naive_pattern_search(pat, txt);
  return 0;
}
