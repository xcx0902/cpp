## DSU

A C++ template of DSU (Disjoint set union).

How to use:

1. Initalize

```cpp
// Create a DSU with 5 elements
dsu f(5);
```

2. Find father

```cpp
// Find father of 3rd element
f.find(3);
```

3. Merge two elements

```cpp
// Merge 2nd and 4th elements
f.merge(2, 4);
```

4. Judge if two elements are in a same set

```cpp
// Judge if 1st and 5th elements are in a same set
f.same(1, 5);
```

5. Get the size of a set

```cpp
// Get the size of the set belonging to 3rd element
f.size(3);
```