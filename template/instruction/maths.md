## Maths

A C++ template of Maths.

How to use:

First, you need to decide if you want to use module or not. If you need module, you need to put the following code in front of including `maths.h`.

```cpp
#define __MOD
```

Now, you can enjoy coding with our template.

What does this template include?

1. Set module number

Example:
```cpp
// Set module number with 1e9+7
setMod(1e9 + 7);
```

2. Addition & Subtraction

Example:
```cpp
// Add x with y
add(x, y);
// Subtract x with y
sub(x, y);
```

3. Maths functions

Example:
```cpp
gcd(5, 7) = 1
lcm(5, 7) = 35
lowbit(16) = 16
ctz(14) = 1
ctzll(1145141919810LL) = 1
popcount(112) = 3
qpow(2, 4) = 16
// For more information, please read source header
```

4. Combination Maths

Note: If you don't want to use this part, please put the following code in front of including `maths.h`.

```cpp
#define __DO_NOT_CREATE_COMBMATHS_CLASS
```

Example:
```cpp
C(5, 2) = 10
A(5, 2) = 20
```

5. Binary search

(1) Interger

Example:
```cpp
bool check(int x) {
    if (x <= 233) return true;
    else return false;
}
//           l   r
binarySearch(1, 1000, check) = 233
```

(2) Double (Real)

Example:
```cpp
bool check(double x) {
    if (x <= 233.333) return true;
    else return false;
}
//           l   r           eps
binarySearch(1, 1000, check, 1e-8) = 233.333
```

6. Get divisor

Example:
```cpp
// (1)
int a[100];
int sz = getDivisor(a, 1000);
// (2)
vector<int> a;
int sz = getDivisor(a, 1000);
// (3)
vector<int> a;
a = getDivisor(1000);
```
