public class NaiveStringMatching
  {
    public static int[] search(String text, String pattern)
    {
      int M = pattern.length();
      int N = text.length();
      int[] result = new int[N - M + 1];
      int index = 0;

      for(int i = 0; i <= N - M; i++)
        {
          int j;
          for(j = 0; j < M; j++)
            {
              if(text.charAt(i+j) != pattern.charAt(j))
              {
                break;
              }
            }
          if(j == M) {
            result[index++] = i;
          }
        }
      return Arrays.copyOf(result, index);
    }
    public static void main(String[] args)
    {
      String text = "AABAACAADAABAAABAA";
      String pattern = "AABA";
      int[] indices = search(text, pattern);
      if(indices.length == 0) {
        System.out.println("Pattern not found");
      }
      else
      {
        System.out.print("Pattern found at indices: ");
        for(int index : indices) {
          System.out.print(index + " ");
        }
      }
    }
  }
