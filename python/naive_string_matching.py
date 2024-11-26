# slides pattern over text character by character and compares characters at each position 

def naive_string_matching(text, pattern):
  M = len(pattern)
  N = len(text)

  for i in range(N - M + 1):
    j = 0
    while j < M:
      if text[i + j] != pattern[j]:
        break
      j += 1
    if j == M:
      yield i 

# example usage
text = "AABAACAADAABAAABAA"
pattern = "AABA"
for match in naive_string_matching(text, pattern):
  print(f"pattern found at index {match}")
  
