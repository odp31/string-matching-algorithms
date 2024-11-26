#include <stdio.h>
#include <string.h>

void badCharHeuristic(char *str, int size, int badchar[256])
{
  int i;
  for(i = 0; i < 256; i++)
    badchar[i] = -1;
  for(i = 0; i < size; i++)
    badchar[(int)str[i]] = i;
}

void search(char *txt, char *pat)
{
  int m = strlen(pat);
  int n = strlen(txt);

  int badchar[256];
  badCharHeuristic(pat, m, badchar);

  int s = 0; 
  while (s <= (n - m)) {
    int j = m - 1;
    while (j >= 0 && pat[j] == txt[s + j])
      j--;
    if(j < 0) {
      printf("\nPattern found at index %d \n", s);
      s += (s + m < n) ? m - badchar[txt[s+m]] : 1;
    }
    else
      s += max(1, j = badchar[txt[s + j]]);
  }
}

int main()
{
  char txt[] = "ABAAABCDABAAABAA";
  char pat[] = "ABAA";
  search(txt, pat);
  return 0;
}
