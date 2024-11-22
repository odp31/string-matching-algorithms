#include <iostream>
#include <string>

using namespace std;

void rabinKarp(string pat, string txt)
{
  int M = pat.length();
  int N = txt.length();
  int i, j;
  int p = 0;
  int t = 0;

  int h = 1;

  for(i = 0; i < M - 1; i++)
    h = (h * d) % q; 

  for(i = 0; i < M; i++) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }
  for(i = 0; i <= N; i++) {
    if(p == t) {
      for(j = 0; j < M; j++) {
        if(txt[i+j] != pat[j])
          break;
      }
      if(j == M)
        cout << "pattern found at index " << i << end1;
    }
    if(i < N - M) {
      t = (d * (t - txt[i] * h) + txt[i + M]) % q;
      if(t < 0)
        t = (t + q);
    }
  }
}
int main()
{
  string txt = "GEEKS FOR GEEKS";
  string pat = "GEEK";

  int q = 101;
  rabinkKarp(pat, txt);
  return 0;
}
