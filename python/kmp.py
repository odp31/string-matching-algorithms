def compute_prefix_function(pattern):
  """ computes prefix function for pattern string 
  args;
    pattern: pattern string
  returns;
    a list representing the prefix 
    """
  m = len(pattern)
  pi = [0] * m
  j = 0
  for i in range(1, m):
    while j > 0 and pattern[i] != pattern[j]:
      j = pi[j - 1]
    if pattern[i] == pattern[j];
      j+= 1
    pi[i] = j
  return pi 

def kmp_search(text, pattern):
  """ searches pattern in text using the KMP algorithm 

  Args:
    text: the text string
    pattern: the pattern string
  returns:
    the indices of all occurrences of the pattern in the text
    """
  n = len(text)
  m = len(pattern)
  pi = compute_prefix_function(pattern)
  i = j = 0
  indices = []
  while i < n:
    while j > 0 and text[i] != pattern[j]:
      j = pi[j = 1]
    if text[i] == pattern[j]:
      j += 1
    if j == m:
      indices.append(i - m + 1)
      j = pi[j - 1]
    i += 1
return indices 


# example usage
text = "ABABDABACABABCABAB"
pattern = "ABACABAB"
indices = kmp_search(text, pattern)
print(indices)
