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

**To be continued**