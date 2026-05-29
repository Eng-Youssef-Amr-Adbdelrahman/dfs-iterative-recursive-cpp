# 🔍 Depth-First Search — Iterative & Recursive

> **Course:** Data Structures and Problem Solving  
> **Assignment:** Q50 &nbsp;|&nbsp; **Author:** Youssef Amr Abdelrahman (ID: 23P0257)  
> **Language:** C++17 &nbsp;|&nbsp; **University:** Ain Shams University

---

## 📌 Problem Statement

Traverse an **undirected graph** of 11 nodes using the **Depth-First Search (DFS)** algorithm — implemented in two different ways:

1. **Iterative DFS** — using an explicit stack data structure
2. **Recursive DFS** — using the system call stack via recursion

Both implementations use an **adjacency list** to represent the graph and handle **disconnected components**.

---

## 📂 Repository Structure

```
dfs-iterative-recursive-cpp/
│
├── README.md
│
├── code/
│   ├── dfs_iterative.cpp     ← Iterative DFS using explicit stack
│   └── dfs_recursive.cpp     ← Recursive DFS using function call stack
│
└── report/
    └── DFS_Report.pdf        ← Full assignment report (problem + solution + analysis)
```

---

## 🧠 Graph Used

Both implementations run on the same undirected graph:

```
Edges: {0,1}, {0,4}, {1,2}, {1,3}, {3,5}, {4,6}, {4,7}, {6,8}, {7,9}, {8,10}, {9,10}
Total nodes: 11
```

```
        0
       / \
      1   4
     / \ / \
    2  3 6  7
       |  |  |
       5  8  9
           \ /
            10
```

---

## ⚙️ Implementations

### 1. Iterative DFS

Uses an **explicit stack** to simulate the recursion manually.

```cpp
void iterativeDFS(Graph const &graph, int start, vector<bool> &visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int vertex = s.top(); s.pop();
        if (visited[vertex]) continue;
        visited[vertex] = true;
        cout << vertex << " ";

        for (auto it = graph.adjList[vertex].rbegin();
             it != graph.adjList[vertex].rend(); ++it)
            if (!visited[*it]) s.push(*it);
    }
}
```

**Key advantage:** No risk of stack overflow on large graphs.

---

### 2. Recursive DFS

Uses the **system call stack** — cleaner and simpler code.

```cpp
void recursiveDFS(Graph const &graph, int vertex, vector<bool> &visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : graph.adjList[vertex])
        if (!visited[neighbor])
            recursiveDFS(graph, neighbor, visited);
}
```

**Key advantage:** Simpler and more readable. Best for small to medium graphs.

---

## ✅ Output

Both implementations produce the same traversal result:

```
0 1 2 3 5 4 6 8 10 9 7
```

---

## 📊 Comparison

| Feature | Iterative | Recursive |
|---|---|---|
| Uses | Explicit stack | System call stack |
| Code complexity | Moderate | Simple |
| Stack overflow risk | ❌ None | ⚠️ Large graphs |
| Time complexity | O(V + E) | O(V + E) |
| Space complexity | O(V) | O(V) |
| Best for | Large graphs | Small/medium graphs |

---

## 🚀 How to Run

**Prerequisites:** C++17 compiler (`g++`, `clang++`, or MSVC)

```bash
# Clone the repo
git clone https://github.com/Eng-Youssef-Amr-Adbdelrahman/dfs-iterative-recursive-cpp.git
cd dfs-iterative-recursive-cpp/code

# Compile iterative
g++ -std=c++17 -O2 -o dfs_iterative dfs_iterative.cpp

# Compile recursive
g++ -std=c++17 -O2 -o dfs_recursive dfs_recursive.cpp

# Run
./dfs_iterative
./dfs_recursive
```

---

## 🎬 Demo Videos

### Iterative DFS
[![Iterative DFS](https://img.youtube.com/vi/piG--yt7CfM/maxresdefault.jpg)](https://youtu.be/piG--yt7CfM?si=2WN3O2DnKZsZ7_Sk)

### Recursive DFS
[![Recursive DFS](https://img.youtube.com/vi/FTprJ2DyT9M/maxresdefault.jpg)](https://youtu.be/FTprJ2DyT9M?si=4ue-PQIX8VT3ou7T)

---

## 📚 Report

The full assignment report covers the problem description, solution overview, code walkthrough, complexity analysis, and advantages of each approach.

📄 [View the full report →](report/DFS_Report.pdf)

---

<div align="center">

**Data Structures and Problem Solving &nbsp;|&nbsp; Ain Shams University &nbsp;|&nbsp; Assignment Q50**

</div>
