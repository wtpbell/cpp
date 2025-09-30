# 📌 Rule of Thumb: `push_back` vs `emplace_back` vs `std::move`

## 1. `push_back`
👉 **Use when you already have the object** you want to insert.  

```cpp
std::vector<int> v;
int x = 42;

v.push_back(x);            // copies x
v.push_back(std::move(x)); // moves x

## 2. `emplace_back`
👉 **Use when you want to construct the object directly inside the container.** you want to insert.

```cpp
std::vector<std::pair<int, int>> v;

v.emplace_back(1, 2);                // constructs pair<int,int>(1, 2) in place
v.emplace_back(std::move(a), b);     // forwards arguments to constructor

```cpp
pairs.push_back({seq_one, seq_two});   // ✅ works
pairs.emplace_back({seq_one, seq_two}); // ❌ doesn’t compile
pairs.emplace_back(seq_one, seq_two);   // ✅ works


## 3. `std::move`
👉 **Use when you no longer need the variable.**

```cpp
std::vector<std::string> v;
std::string s = "hello";

v.push_back(std::move(s));    // moves string into vector
v.emplace_back(std::move(s)); // also moves
