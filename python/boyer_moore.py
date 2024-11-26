# highly efficient string search algorithm that utilizes two heuristics to skip parts of the text 
# bad charater heuristic; when a mistmatch occurs, algorithm shifts pattern to align the mismatched
# character with the next occurrence of that character in the pattern 
# good suffix heuristic; when a partial match is found, algorithm shifts pattern to align 
# longest suffix of the pattern that matches a suffix in the text


def boyer_moore(text, pattern):
  """ returns a list of indices where the pattern is ofund in the text """
  m = len(pattern)
  n = len(text) 

  # preprocess pattern to create the bad character and good suffix tables
  bad_char = {}
  for i in range(m - 1):
    bad_char[pattern[i]] = i

  good_suffix = [m] * m
  suffix = [0] * m
  j = m - 1
  for i in range(m - 1, -1, -1):
    if i == j:
      while j >= 0 and pattern[j] == pattern[j - i]:
        j -= 1
      good_suffix[i] = i - j
      j = i - 1
    else:
      good_suffix[i] = good_suffix[i + m - 1 - j]
  for i in range(m - 1):
    suffix[i] = good_suffix[i + 1]
  i = 0
  while i <= n - m:
    j = m - 1
    while j >= 0 and pattern[j] == text[i + j]:
      j -= 1
    if j < 0:
      yield i
      i += good_suffix[0]
    else:
      i += max(good_suffxi[j + 1], j - bad_char.get(text[i + j], -1))

# example usage
text = "ABAAABCDABAAABAA"
pattern = "ABAA" 
for match in boyer_moore(text, pattern):
  print(f"Pattern found at index {match}")
  
