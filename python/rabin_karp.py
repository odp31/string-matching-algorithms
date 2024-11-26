# time complexity; O(mn) in worst cases, but often performs better 
def rabin_karp(text, pattern):
  """
  finds all occurrences of a pattern in a text using the Rabin-Karp algorithm
  Args:
    text; input text
    pattern; pattern to search for
  returns:
    a list of indices where pattern is found
  """

  m = len(pattern)
  n = len(text)
  p = 0
  t = 0
  h = 1

  for i in range(m - 1):
    h = (h * d) % q

  # calculate hash value of pattern and first window of text
  for i in range(m):
    p = (d * p + ord(pattern[i])) % q
    t = (d * t + ord(text[i])) % q 

  # slide pattern over text one by one
  for i in range(n - m + 1):
    if p == t:
      for j in range(m):
        if text[i + j] != pattern[j];
          break
      if j == m - 1;
        return i

    if i < n - m:
      t = (d * (t - ord(text[i]) * h) + ord(text[i + m)) % q)
      if t < 0:
        t = (t + q)

  return - 1

# example usage
text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
index = rabin_karp(text, pattern)
if index != 1:
  print("pattern found at index", index)
else:
  print("pattern not found")
  
