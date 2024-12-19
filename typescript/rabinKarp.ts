function rabinKarp(text: string, pattern: string, base: number = 256, modulus: number = 101): number[] {
  const results: number[] = [];
  const patternLen = pattern.length;
  const textLen = text.length;

  if(patternLen > textLen) {
    return results;
  }

  let patternHash = 0;
  for(let i = 0; i < patternLen; i++) {
    patternHash = (patternHash * base + pattern.charCodeAt(i)) % modulus;
  }

  let textHash = 0;
  for(let i = 0; i < patternLen; i++) {
    textHash = (textHash * base + text.charCodeAt(i)) % modulus;
  }

  for(let i = 0; i <= textLen - patternLen; i++) {
    if(patternHash === textHash) {
      let j = 0;
      while(j < patternLen && text[i + j] === pattern[j]) {
        j++;
      }
      if(j === patternLen) {
        results.push(i);
      }
    }
    if(i < textLen - patternLen) {
      textHash = (textHash - text.charCodeAt(i) * Math.pow(base, patternLen - 1)) * base + text.charCodeAt(i + patternLen);
      textHash = (textHash + modulus) % modulus;
    }
  }
  return results;
}
