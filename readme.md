# LRU Cache Implementation in C++

This project implements a simple **Least Recently Used (LRU) Cache** in C++.

The cache supports two operations:

- `get(key)`
- `put(key, value)`

Both operations run in **O(1)** time.

## Approach

The implementation uses:

- `unordered_map` for fast key lookup
- `list` to maintain the order of recently used elements

When the cache exceeds its capacity, the **least recently used element is removed**.

## How to Run

Compile the program:

g++ lru.cpp -o lru

Run the program:

./lru
