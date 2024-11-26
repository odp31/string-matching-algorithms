#include <iostream>
#include <cstring>

using namespace std;

void naive_pattern_search(string txt, string pat)
{
  int M = pat.length();
  int N = txt.length();

  for(int i = 0; i <= N; i++) {
    int j;
    for(j = 0; j < M; j++) {
      if(txt[i + j] != pat[j]) {
        break;
      }
    }
    if(j == M) {
      cout << "pattern found at index " << i << end1;
    }
  }
}
int main()
{
  string txt = "AABAACAADAABAAABAA";
  string pat = "AABA";
  naive_pattern_search(txt, pat);
  return 0;
}
