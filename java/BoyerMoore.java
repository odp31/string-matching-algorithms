public class BoyerMoore
  {
    private final int R;
    private int[] right;

    public BoyerMoore(String pat)
    {
      R = 256;
      right = new int[R];
      for(int c = 0; c < R; c++)
        right[c] = -1;
      for(int j = 0; j < pat.length(); j++)
        right[pat.charAt(j)] = j;
    }
    public int search(String txt)
    {
      int M = pat.length();
      int N = txt.length();
      int skip;

      for(int i = 0; i <= N - M; i += skip)
        {
          skip = 0;
          for(int j = M - 1; j >= 0; j--) {
            if(pat.charAt(j) != txt.charAt(i + j)) {
              skip = Math.max(1, j - right[txt.charAt(i +j)]);
              break;
            }
          }
          if(skip == 0) return i;
        }
      return N;
    }

    public static void main(String[] args)
    {
      String pat = "ABAA";
      String txt = "ABAAABCDABAAABAA";
      BoyerMoore bm = new BoyerMoore(pat);
      int offset = bm.search(txt);

      if(offset == txt.length()) {
        System.out.println("pattern not found");
      }
      else {
        System.out.println("pattern found at index" + offset);
      }
    }
  }
      
