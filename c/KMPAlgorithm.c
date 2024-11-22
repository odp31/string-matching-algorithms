#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps)
{
  int len = 0;
  int i;

  for(i = 1; i < M; i++) {
    if(pat[i] == pat[len]) {
      len++;
      lps[i] = len;
    }
    else {
      if(len!=0) {
        len = lps[len - 1];
        i--;
      }
      else {
        lps[i] = len;
      }
    }
  }
}

void KMPSearch(char* pat, char* txt)
{
  int M = strlen(pat);
  int N = strlen(txt);

  int lps[M];
  computeLPSArray(pat, M, lps);

  int i = 0; 
  int j = 0; 
  while(j < N) {
    if(pat[j] == txt[i]) {
      j++;
      i++;
    }
    if(j == M) {
      printf("found pattern at index %d \n", i - j);
      j = lps[j - 1];
    }
    else if (i < N && pat[j] != txt[i]) {
      if(j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}
int main()
{
  char txt[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABAB";
  KMPSearch(pat, txt);
  return 0;
}
