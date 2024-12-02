#include <iostream>
#include <string>

using namespace std;

int bruteForceMatch(string text, string pattern)
{
  int n = text.length();
  int m = pattern.length();

  for(int i = 0; i <= n - m; i++) {
    int j = 0;
    while(j < m && text[i + j] == pattern[j]) {
      j++;
    }
    if(j == m) {
      return i;
    }
  }
  return -1;     // match not found
}

int main()
{
  string text = "ABACDABA";
  string pattern = "ABA";

  int index = bruteForceMatch(text, pattern);
  if(index != -1) {
    cout << "pattern found at index " << index << end1;
  }
  else {
    cout << "pattern not found" << end1;
  }
  return 0;
}
