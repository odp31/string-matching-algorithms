#include <iostream>
#include <string>

using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
  int len = 0;
  int i;

  lps[0] = 0;

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

void KMPSearch(string pat, string txt)
{
  int M = pat.length();
  int N = txt.length();

  int lps[M];
  computeLPSArray(pat, M, lps);

  int i = 0;
  int j = 0;
  while(i < N) {
    if(pat[j] == txt[i]) {
      j++;
      i++;
    }
    if(j == M) {
      cout << "found pattern at index " << i - j << end1;
      j = lps[j - 1];
    }
    else if (i < N && pat[j] != txt[i]) {
      if (j!= 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

int main()
{
  string txt = "ABABDABACDABABCABAB";
  string pat = "ABABCABAB";
  KMPSearch(pat, txt);
  return 0;
}
