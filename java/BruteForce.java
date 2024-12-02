// iterates over each character of the text and compares it with the first character of the pattern
// if match is found, continues comparing subsequent characters 
// if a mismatch occurs, pattern is shifted to the next character in the text 

public class BruteForce
  {
    public static int bruteForceMatch(String text, String pattern)
    {
      int n = text.length();
      int m = pattern.length();

      for(int i = 0; i <= n - m; i++) {
        int j = 0;
        while(j < m && text.charAt(i + j) == pattern.charAt(j)) {
          j++;
        }
        if(j == m) {
          return i;
        }
      }
      return -1; // match not found
    }
    public static void main(String[] args)
    {
      String text = "ABACDABA";
      String pattern = "ABA";
      int index = bruteForceMatch(text, pattern);
      if(index != -1) {
        System.out.println("pattern found at index " + index);
      }
      else {
        System.out.println("pattern not found);
      }
    }
  }
