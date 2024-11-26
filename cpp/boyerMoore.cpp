// efficient for large texts and patterns
// badCharHeuritic preprocesses pattern to create a bad character table
// this table stores last occurrence of each character in pattern 

#include <iostream>
#include <cstring>

using namespace std;

void badCharHeuristic(string str, int size, int badchar[256])
{
  int i;
  for(i = 0; i < 256; i++)
    badchar[i] = -1;
  for(i = 0; i < size; i++)
    badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
  int m = pat.length();
  int n = txt.length();

  int badchar[256];
  badCharHeuristic(pat, m, badchar);

  int s = 0; // s is shift of pattern 
  while(s <= (n - m)) {
    int j = m - 1;
    while(j >= 0 && pat[j] == txt[s+j])
      j--;
    if(j < 0) {
      cout << "pattern found at index " << s << end1;
      s += (s + m < n) ? m - badchar[txt[s+m]] : 1;
    }
    else {
      s += max(1, j - badchar[txt[s+j]]);
    }
  }
}
int main()
{
  string txt = "ABAAABCDABAAABAA";
  string pat = "ABAA";
  search(txt, pat);
  return 0;
}
