## Segment Tree

A C++ template of Segment Tree.

### Single-point update + Segment query

You should prepare two functions to use this template.

Note: The `T` below means the type you want to use in the segment tree.

1. Fuction `T pushup(T a, T b)`, get two elements `a` and `b`, return the operation you want to perform in the segment tree (like `sum`, `max` or `min`) of `a` and `b`.

Example:
```cpp
int pushup(int a, int b) {
    return a + b;
}
```

2. Function `void change(T &p, T delta)`, get two elements `p` and `delta`, change `p` with `delta`.

Example:
```cpp
void change(T &p, T delta) {
    p += delta;
}
```

Then you can create a segment tree like this:

```cpp
SegmentTree<int, pushup, change> t;
```

What can I do when the segment tree was created?

1. Initialize

```cpp
// Change the segment tree's size to 10
t.resize(10);
```

2. Build segment tree

```cpp
// Build the segment tree with zeros
t.build(1, n);
// Build the segment tree with a prepared array
t.build(a, 1, n);
```

3. Change a single element

```cpp
// Add 3 to the 5th element
t.update(5, 3);
```

4. Get the operation defined in function `pushup` of continous elements

```cpp
// Get the sum of (7, 10)
t.query(7, 10);
```

**To be continued**