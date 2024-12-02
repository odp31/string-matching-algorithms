def brute_force_match(text, pattern):
  """
  Performs brute force string matching
  Args:
    text: text string to search in
    pattern: pattern to search for
  Returns:
    index of first occurrence of pattern in the text, or -1 if not found
  """
  n = len(text)
  m = len(pattern)

  for i in range(n - m + 1):
    j = 0
    while j < m and text[i + j] == pattern[j]:
      j += 1
    if j == m:
      return i
  return -1

# example usage
text = "ABACDABA"
pattern = "ABA"
index = brute_force_match(text, pattern)

if index != -1:
  print("pattern found at index", index)
else:
  print("pattern not found")
