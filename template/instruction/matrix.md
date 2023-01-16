## Matrix

A C++ template of Matrix.

Including:

1. Matrix input & output
2. Matrix addition
3. Matrix multiplication
4. Matrix power 

How to use:

Put `matrix.cpp` in your C++ program's head to use its features.

1. Set mod

```cpp
useMod(mod1); // Set mod with 10007
useMod(mod2); // Set mod with 1e9 + 7
useMod(mod3); // Set mod with 998244353 (AtCoder number)
useMod(1145141919810LL); // Set mod with the number you want
```

2. Create a matrix.

```cpp
// Create a 3*5 matrix
int r = 3, c = 5;
Matrix mtx;
mtx.resize(r, c); // r means rows, c means columns
```

3. Input & output matrix

```cpp
mtx.read(); // Input the matrix
mtx.print(); // Output the matrix
mtx.print(1); // Output the matrix with (r, c) in the first line
```

4. Matrix addition & multiplication & power

```cpp
// Addition
ans = a + b;
// Multiplication
ans = a * b;
// Power
ans = a ^ b;
```

Note:

Considering the input is very large, the multiplication will be overflow. We used a function `mul` to prevent this.

```cpp
int mul(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}
// L40-49 in matrix.cpp
```

If you think it makes your program slow, you can change it to:

```cpp
int mul(int a, int b) {
    return a * b;
}
```
Or, you can delete `mul` function and change `mul(a[i][k], b[k][j])` in Line 69 of the origin `matrix.cpp` to `a[i][k] * b[k][j]`.