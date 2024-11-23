# My Algorithm List 
> Bắt chước Um_nik

## Fundamentals
- Complexity analysis
- Recursion
- Binary search
- Binary search on answer
- Modular arithmetic
  
## Graphs
### Basic
- DFS
- BFS
- Dijkstra
  - Dijkstra in $O(V^2)$
  - Dijkstra in $O(ElogV)$ with heap
- MST Kruskal
### Directed graphs
- Topological ordering
  
## Trees
### Data structures
- Lowest common ancestor (LCA) via binary jumps
- Using binary jumps for something other than LCA
- Small-to-large
- Virtual tree

## Matchings and Flows
### Basic concepts and algorithms
- Ford-Fulkerson theorem (max-flow = min-cut)
- Ford-Fulkerson max flow
- Edmonds-Karp max flow
- Min-Cost-Max-Flow

## Data structures
### Conceps
- Array
- Stack
- Queue
- Vector
- Priority Queue
- Set
- Map
- Bitset
### Built-in
- ```std::vector```
- ```std::priority_queue```
- ```std::set```
- ```std::map```
- ```std::unordered_set``` ```std::unordered_map```
- ```std::bitset```
### Basic
- Prefix sums
- Disjoint Set Union (DSU)
### Tree-like
- Segment tree (ST)
- ST with lazy propagation
- Walk on ST

## Geometry
### Basic
- Class Point

## Number theory
### Basic
- Euclidean algorithm
- Extended Euclidean algorithm
- Sieve of Eratosthenes in $O(nlogn)$
- Fundamental theorem of arithmetic
- Binary exponentiation
- Modular inverse
- Primality testing in $O(\sqrt n)$
- Factorization in $O(\sqrt n)$
### Multiplicative functions
- Euler's totient function $\varphi(n)$
### Fun facts
- Prime number theorem (distribution of primes)
- Prime gaps
- Goldbach's conjecture

## Combinatorics
### Methods
- Mathematical induction
- Bijective proof
- Inclusion-exclusion principle
- Pigeonhole principle
### Binomial coefficients
- Binomial coefficients
- Precalculating factorials and inverses in $O(n)$
- Pascal's triangle
- Binomial theorem
### Important identities with $\binom{n}{k}$
- $\sum_{k=0}^{n} \binom{n}{k} = 2^{n}$
### Number sequences
- Fibonacci numbers

## Dynamic Programming
- The idea of Dynamic Programming (DP) - reducing to smaller subtasks of the same form
- Backtracking with memoizations as DP
- Restoring answer from DP
- What are "states" and "transitions" in DP
### DP indifferent "mediums"
- Submask DP
  - Iterating over submasks in $O(submasks) = O(2^{popcount(mask)})$
- Subtree DP
  - DP with "directed edge" as a stage (subtree DP for all roots)
- DP on DAG
- Digit DP
### Using data structures and other ideas to reduce complexity in DP
- Prefix sums in DP
- Segment tree in DP
- Matrix exponentiation in DP
### Classic DP problems
- Knapsack
- Subset sum
- Number of paths through the grid
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
  - LIS in $O(n^2)$
  - LIS in $O(nlogn)$ with binary search
  - LIS in $O(nlogn)$ with segment tree
### DP with update queries
- Storing DP in segment tree

## Sqrt ideas
- Primality testing in $O(\sqrt{n})$
- Factorization in $O(\sqrt{n})$
- Mo's Algorithm

## Binary search -esque ideas
- Binary search on answer
- Ternary search

## Sorting
- Bubble sort
- Quicksort
- Mergesort
- Heapsort
- Counting sort

## General Ideas (which are not simple and basic, but not big enough to have their own section)
- Divide-and-Conquer
- Meet-in-the-middle
