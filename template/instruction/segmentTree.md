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
SegmentTree<T, pushup, change> t;
```

What can I do with the segment tree?

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

### Segment update + Segment query (With LazyTag)

You should prepare three functions to use this template.

Note: The `Tdat` below means the data type you want to use in the segment tree, and `Tlazy` means that of lazy tag.

1. Fuction `Tdat pushup(Tdat, Tdat)`, get two elements `a` and `b`, return the operation you want to perform in the segment tree (like `sum`, `max` or `min`) of `a` and `b`.

Example:
```cpp
int pushup(int a, int b) {
    return a + b;
}
```

2. Function `void change(unsigned, unsigned, Tdat&, Tlazy&, Tdat)`, do like the example.

Example:
```cpp
void change(unsigned l, unsigned r, int &d, int &add, int delta) {
    d += (r - l + 1) * delta;
    add += delta;
}
```

3. Function `void pushdown(unsigned, unsigned, Tdat&, Tdat&, Tlazy&, Tlazy&, Tlazy&)`, do like the example.

Example:
```cpp
void pushdown(unsigned l, unsigned r, int &ld, int &rd, int &add, int &ladd, int &radd) {
    if (add) {
        int mid = (l + r) >> 1;
        ladd += add, radd += add;
        ld += add * (mid - l + 1);
        rd += add * (r - mid);
        add = 0;
    }
}
```

Then you can create a segment tree like this:

```cpp
LazySegmentTree<Tdat, Tlazy, pushup, change> t;
```

What can I do with the segment tree?

1. Initalize

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

4. Change continous elements

```cpp
// Add 3 to (2, 8)
t.secupdate(2, 8, 3);
```

5. Get the operation defined in function `pushup` of continous elements

```cpp
// Get the sum of (7, 10)
t.query(7, 10);
```
