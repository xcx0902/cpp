## Matrix

A C++ template of Matrix.

Including:

1. Matrix input & output
2. Matrix addition
3. Matrix multiplication
4. Matrix power 

How to use:

Put `matrix.cpp` in your C++ program's head to use its features.

1. Create a matrix.

```cpp
// Create a 3*5 matrix
int r = 3, c = 5;
Matrix mtx;
mtx.resize(r, c); // r means rows, c means columns
```

2. Input & output matrix

```cpp
mtx.read(); // Input the matrix
mtx.print(); // Output the matrix
mtx.print(1); // Output the matrix with (r, c) in the first line
```

3. Matrix addition & multiplication & power

```cpp
// Addition
ans = a + b;
// Multiplication
ans = a * b;
// Power
ans = a ^ b;
```