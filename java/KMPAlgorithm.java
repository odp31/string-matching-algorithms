public class KMPAlgorithm
{
  public static int[] computeLPSArray(String pat)
  {
    int M = pat.length();
    int lps[] = new int[M];
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while(i < M)
      {
        if(pat.charAt(i) == pat.charAt(len))
        {
          len++;
          lps[i] = len;
          i++;
        }
        else
        {
          if(len != 0) {
            len = lps[len - 1];
          }
          else
          {
            lps[i] = len;
            i++;
          }
        }
      }
    return lps;
  }

  public static void KMPSearch(String pat, String txt)
  {
    int M = pat.length();
    int N = txt.length();
    int lps[] = computeLPSArray(pat);

    int i = 0;
    int j = 0;
    while (i < N)
      {
        if(pat.charAt(j) == txt.charAt(i)) {
          j++;
          i++;
        }
        if(j == M) 
        {
          System.out.println("found pattern at index" + (i - j));
          j = lps[j - 1];
        }
        else if (i < N && pat.charAt(j) != txt.charAt(i))
          if(j!=0)
            j = lps[j - 1]
          else
            i = i - 1
              }
  }

  public static void main(String args[])
  { 
    String txt = "ABABDABACDABACABA";
    String pat = "ABABCABAB";
    KMPSearch(pat, txt);
  }
  



