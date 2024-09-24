function bin(integer, withPaddingLength) {
  let str = integer.toString(2);
  return str.padStart(withPaddingLength, "0");
}
