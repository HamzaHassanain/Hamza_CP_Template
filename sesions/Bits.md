# Bit Manipulation

- [Bit Manipulation](#bit-manipulation)

  - [C++ Bitset](#c-bitset)
  - [Bitwise Operators](#bitwise-operators)
  - [Bitwise AND](#bitwise-and)
  - [Bitwise OR](#bitwise-or)
  - [Bitwise XOR](#bitwise-xor)
  - [Bitwise NOT](#bitwise-not)
  - [Left Shift](#left-shift)
  - [Right Shift](#right-shift)
  - [Check if a number is even or odd](#check-if-a-number-is-even-or-odd)
  - [Check if the nth bit is set](#check-if-the-nth-bit-is-set)
  - [Set the nth bit](#set-the-nth-bit)
  - [Unset the nth bit](#unset-the-nth-bit)
  - [Toggle the nth bit](#toggle-the-nth-bit)
  - [Count the number of set bits](#count-the-number-of-set-bits)
  - [Count the number of bits to be flipped to convert A to B](#count-the-number-of-bits-to-be-flipped-to-convert-a-to-b)
  - [Generate all possible subsets of a set](#generate-all-possible-subsets-of-a-set)
  - [Find the one non-repeating element in an array where every other element repeats twice](#find-the-one-non-repeating-element-in-an-array-where-every-other-element-repeats-twice)

- [Extra Materials](#extra-materials)
- [Problems](#problems)

## C++ Bitset

The `bitset` class in C++ is a part of the C++ Standard Library. It is a class template of the C++ Standard Library that provides a simple way to manipulate individual bits in an array of bits. A `bitset` stores bits (elements with only two possible values: 0 or 1) and supports a variety of operations that can be performed on them.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {

    // Create a bitset of size 8
    bitset<8> b;

    // Set the 0th bit
    b[0] = 1;

    // Set the 2nd bit
    b[2] = 1;

    // Set the 4th bit
    b[4] = 1;

    // Set the 6th bit
    b[6] = 1;

    // Print the bitset
    cout << b << endl; // 10101010

    return 0;
}
```

## Bitwise Operators

Bitwise operators are used to perform bit-level operations on integers. These operations are fast and can be used to perform some tasks more efficiently than their alternatives.

- `&` (AND)
- `|` (OR)
- `^` (XOR)
- `~` (NOT)
- `<<` (Left Shift)
- `>>` (Right Shift)

## Bitwise AND

The bitwise AND operator `&` compares each bit of the first operand to the corresponding bit of the second operand. If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

```cpp

int a = 5; // 101
int b = 3; // 011

cout << bitset<8>(a) << endl; // 00000101
cout << bitset<8>(b) << endl; // 00000011

int c = a & b; // 1 & 1 = 1, 0 & 1 = 0, 1 & 0 = 0
cout << bitset<8>(c) << endl; // 00000001

```

## Bitwise OR

The bitwise OR operator `|` compares each bit of the first operand to the corresponding bit of the second operand. If either bit is 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

```cpp

int a = 5; // 101
int b = 3; // 011

cout << bitset<8>(a) << endl; // 00000101
cout << bitset<8>(b) << endl; // 00000011

int c = a | b; // 1 | 1 = 1, 0 | 1 = 1, 1 | 0 = 1
cout << bitset<8>(c) << endl; // 00000111

```

## Bitwise XOR

The bitwise XOR operator `^` compares each bit of the first operand to the corresponding bit of the second operand. If the bits are different, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

XOR = Binary Addition without carry
XOR is used to toggle bits.

```cpp

int a = 5; // 101
int b = 3; // 011

cout << bitset<8>(a) << endl; // 00000101
cout << bitset<8>(b) << endl; // 00000011

int c = a ^ b; // 1 ^ 1 = 0, 0 ^ 1 = 1, 1 ^ 0 = 1
cout << bitset<8>(c) << endl; // 00000110


```

## Bitwise NOT

The bitwise NOT operator `~` inverts each bit of the operand. It changes 1 to 0 and 0 to 1.

```cpp

int a = 5; // 101

cout << bitset<8>(a) << endl; // 00000101

int b = ~a; // ~101 = 010
cout << b  << endl; // -6
cout << bitset<8>(b) << endl; // 11111010

```

## Left Shift

The left shift operator `<<` shifts the bits of the operand to the left by a specified number of positions. The leftmost bits are discarded, and the rightmost bits are filled with zeros.
Left Shift is equivalent to multiplying the number by 2^n.

```cpp

int a = 5; // 101

cout << bitset<8>(a) << endl; // 00000101

int b = a << 1; // 101 << 1 = 1010
int c = a * 2; // 5 * 2 = 10
cout << bitset<8>(b) << endl; // 00001010


int b2 = a << 4; // 101 << 4 = 1010000
int c2 = a * pow(2, 4); // 5 * 16 = 80

cout << bitset<8>(b2) << endl; // 01010000
cout << c2 << endl; // 80

```

## Right Shift

The right shift operator `>>` shifts the bits of the operand to the right by a specified number of positions. The rightmost bits are discarded, and the leftmost bits are filled with zeros.

Right Shift is equivalent to dividing the number by 2^n.

```cpp

int a = 20; // 10100

cout << bitset<8>(a) << endl; // 00010100

int b = a >> 1; // 10100 >> 1 = 1010
int c = a / 2; // 20 / 2 = 10
cout << bitset<8>(b) << endl; // 00001010

int b2 = a >> 4; // 10100 >> 4 = 0000
int c2 = a / pow(2, 4); // 20 / 16 = 1

cout << bitset<8>(b2) << endl; // 00000000
cout << c2 << endl; // 1

```

## Check if a number is even or odd

To check if a number is even or odd, we can use the bitwise AND operator `&`. If the least significant bit of the number is 0, the number is even; otherwise, it is odd.

```cpp

int n = 5; // 101
if(n & 1) {
    cout << "Odd" << endl;
} else {
    cout << "Even" << endl;
}


n = 6; // 110
if(n & 1) {
    cout << "Odd" << endl;
} else {
    cout << "Even" << endl;
}
```

## Check if the nth bit is set

To check if the nth bit of a number is set (1) or not set (0), we can use the bitwise AND operator `&` with a mask that has only the nth bit set.

```cpp

int n = 5; // 101
int k = 1; // Check the 1st bit, zero-based index

if(n & (1 << k)) { // shift 1 to the left by k positions
    cout << "The " << k << "th bit is set" << endl;
} else {
    cout << "The " << k << "th bit is not set" << endl;
}

if((n >> k) & 1) { // shift n to the right by k positions
    cout << "The " << k << "th bit is set" << endl;
} else {
    cout << "The " << k << "th bit is not set" << endl;
}

```

## Set the nth bit

To set the nth bit of a number, we can use the bitwise OR operator `|` with a mask that has only the nth bit set.

```cpp

int n = 5; // 101
int k = 1; // Set the 1st bit, zero-based index
// 1 << k = 010
n = n | (1 << k); // set the kth bit
n |= (1 << k); // set the kth bit
```

## Unset the nth bit

To unset the nth bit of a number, we can use the bitwise AND operator `&` with a mask that has all bits set except the nth bit.

```cpp

int n = 5; // 101
int k = 2; // Unset the 2nd bit, zero-based index
// ~(1 << k) = 1111011
n = n & ~(1 << k); // unset the kth bit

n &= ~(1 << k); // unset the kth bit

```

## Toggle the nth bit

To toggle the nth bit of a number, we can use the bitwise XOR operator `^` with a mask that has only the nth bit set.

```cpp

int n = 5; // 101
int k = 1; // Toggle the 1st bit, zero-based index
// 1 << k = 010
n = n ^ (1 << k); // toggle the kth bit
// n = 101 ^ 010 = 111
n ^= (1 << k); // toggle the kth bit
// n = 111 ^ 010 = 101

```

## Count the number of set bits

```cpp

int n = 5; // 101
int count = 0;

while(n) {
    if(n & 1) {
        count++;
    }
    n >>= 1; // is the same as n = n / 2
}

cout << count << endl; // 2

cout << __builtin_popcount(5) << endl; // 2
cout << __builtin_popcountll(5LL) << endl; // 2
```

## Count the number of bits to be flipped to convert A to B

General Idea:

- XOR A and B
- Count the number of set bits in the result

```cpp

int a = 5; // 101
int b = 3; // 011

int c = a ^ b; // 101 ^ 011 = 110

int count = 0;
while(c) {
    if(c & 1) {
        count++;
    }
    c >>= 1;
}

cout << count << endl; // 2

```

## Generate all possible subsets of a set

General Idea:

- For each number from 0 to 2^n - 1
  - Convert the number to binary
  - For each bit in the binary representation
    - If the bit is set, add the corresponding element to the subset

```cpp

vector<int> arr = {1, 2, 3};
int n = arr.size();
int N = 1 << n;
for(int i = 0; i < N; i++) {
    vector<int> subset;
    for(int j = 0; j < n; j++) {
        if(i & (1 << j)) {
            subset.push_back(arr[j]);
        }
    }
    for(int x : subset) {
        cout << x << " ";
    }
    cout << endl;

    /*
{}
{1}
{2}
{1, 2}
{3}
{1, 3}
{2, 3}
{1, 2, 3}
    */
}
```

## Find the one non-repeating element in an array where every other element repeats twice

General Idea:

- XOR all the elements of the array
- The result will be the non-repeating element, Why?
  - XOR of two same numbers is 0
  - XOR of a number with 0 is the number itself

```cpp

vector<int> arr = {1, 2, 2, 3, 3, 4, 4};
int result = 0;
for(int x : arr) {
    result ^= x;
}

cout << result << endl; // 1

```

## Extra Materials

- [CodeNCode (English):](https://youtube.com/playlist?list=PL5DyztRVgtRUVORP3AXvX91uovcaZv0q9&si=UlAIS0vE_HgqrECM)
- [Mr Algorithm (Arabic):](https://youtube.com/playlist?list=PLR5x_RGTMNNWh2TcvDlyf9BY2k2ZsLVOx&si=I83FP4ZtOifa1kVc)
- [Basic Topics (Geeks Blog):](https://www.geeksforgeeks.org/bits-manipulation-important-tactics/)

## Problems

- [Add Binary](https://leetcode.com/problems/add-binary/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY)
- [Single Number](https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY)
- [Power of Two](https://leetcode.com/problems/power-of-two/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY)
- [Sum in Binary Tree](https://codeforces.com/problemset/problem/1843/C)
- [Min Or Sum](https://codeforces.com/contest/1635/problem/A)
- [We Need the Zero](https://codeforces.com/contest/1805/problem/A)
- [Hamon Odyssey](https://codeforces.com/contest/1847/problem/B)
- [XOR Sequences](https://codeforces.com/contest/1979/problem/B)
- [AND Reconstruction](https://codeforces.com/contest/1991/problem/B)
- [StORage room](https://codeforces.com/contest/1903/problem/B)
- [Friendly Arrays](https://codeforces.com/contest/1870/problem/B)
