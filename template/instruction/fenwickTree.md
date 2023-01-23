## Fenwick Tree

A C++ template of Fenwick Tree.

How to use:

1. Initalize

```cpp
// Create a Fenwick Tree with 10 integers
fenwickTree<int> t(10);
```

2. Add a number to one of the elements

```cpp
// Add 5 to the 1st element
t.add(1, 5);
```

3. Change one of the elements

```cpp
// Change 2nd element to 10
t.change(2, 10);
```

4. Get one of the elements

```cpp
// Get the 3rd element
t.get(3);
```

5. Get the prefix sum of the array

```cpp
// Get the sum of (1, 4)
t.getsum(4);
```

6. Get the sum of continous elements

```cpp
// Get the sum of (5, 8)
t.sum(5, 8);
```