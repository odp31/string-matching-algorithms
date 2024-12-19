function boyerMooreSearch(text: string, pattern: string): number[] {
  const results: number[] = [];

  // preprocessing; create bad character shift table
  const badCharShift = new Map<string, number>();
  for(let i = 0; i < pattern.length - 1; i++) {
    badCharShift.set(pattern[i], pattern.length - i - 1);
  }

  // preprocessing; create good suffix shift table
  const goodSuffixShift = new Array(pattern.length).fill(pattern.length);
  let suffix = new Array(pattern.length).fill(false);
  for(let i = pattern.length - 1, j = pattern.length - 1; i >= 0; i--, j--) {
    if(pattern[i] === pattern[j]) {
      suffix[i] = true;
      goodSuffixShift[i] = goodSuffixShift[i + 1];
    } else {
      goodSuffixShift[i] = j - i;
      j = pattern.length - 1;
    }
  }

  // search phase
  let i = 0;
  while(i <= text.length - pattern.length) {
    let j = pattern.length - 1;
    while(j >= 0 && text[i + j] === pattern[j]) {
      j--;
    }
    if(j < 0) {
      results.push(i);
      i += goodSuffixShift[0];
    } else {
      i += Math.max(goodSuffixShift[j + 1], badCharShift.get(text[i + j]) || pattern.length);
    }
  }
  return results;
}
