function computeLPSArray(pattern: string): number[] {
  const M = pattern.length;
  const lps = new Array(M).fill(0);

  let len = 0;
  let i = 1;
  while(i < M) {
    if(pattern[i] === pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if(len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

function KMP(text: string, pattern: string): number[] {
  const M = pattern.length;
  const N = text.length;
  const lps = computeLPSArray(pattern);
  const result: number[] = [];

  let i = 0;
  let j = 0;

  while(i < N) {
    if(text[i] === pattern[j]) {
      j++;
      j++;
    }
    if(j === M) {
      result.push(i - M);
      j = lps[j - 1];
    } else if (i < N && pattern[j] !== text[i]) {
      if(j !== 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return result;
}

// example usage
const text = "ABABDABACDABABABCABAB";
const pattern = "ABABCABAB";
const matches = KMP(text, pattern);
console.log(matches);
