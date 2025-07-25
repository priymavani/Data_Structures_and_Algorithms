## Tree: Definition

A **Tree** is a **non-linear hierarchical data structure** consisting of nodes connected by edges, where:

> **A tree is a collection of nodes, with one node designated as the root, and the remaining nodes partitioned into disjoint subsets, each of which is a subtree of the root.**

It follows a **parent-child relationship** where each child has only one parent, and it forms a hierarchical structure with no cycles.

---


## Basic Terminology

* **Node:** The fundamental part of a tree that contains data.
* **Root:** The topmost node of the tree.
* **Parent:** A node that has one or more child nodes.
* **Child:** A node that has a parent node above it.
* **Leaf:** A node with no children.
* **Edge:** The connection between two nodes.
* **Level:** The distance from the root node.
* **Height:** The length of the longest path from the root to a leaf.
* **Depth:** The distance from the root to a particular node.
* **Subtree:** A tree formed by a node and its descendants.

---

## Properties of Tree

* A tree with **n nodes has (n - 1) edges**.
* There is **one and only one path between any two nodes**.
* It is a **non-linear data structure**, unlike arrays and linked lists.

---

## Types of Trees

* **Binary Tree:** Each node has at most two children.
* **Binary Search Tree (BST):** A binary tree with the left child having values less than the parent and the right child having values greater than the parent.
* **AVL Tree:** A self-balancing binary search tree.
* **Heap:** A complete binary tree following the heap property.
* **B-Tree:** A balanced tree used in databases and file systems.
* **Trie:** A tree used for efficient retrieval, commonly used in dictionaries.

---

## Example

```
        10  <- Root
       /  \
      5    15
     / \   / \
    2   7 12 20
```

* Root: 10
* Children of 10: 5, 15
* Leaf nodes: 2, 7, 12, 20

---

## Applications of Tree

* **Hierarchical data representation** (file systems, organization charts).
* **Binary Search Trees** for fast search operations.
* **Expression trees** for parsing expressions in compilers.
* **Routing algorithms in networks**.
* **Tries** for efficient word searching in dictionaries.
* **Heaps** in priority queues and sorting.
* **Databases and indexing (B-Trees, B+ Trees)**.

---

## Advantages

✅ Reflects a **hierarchical structure naturally**.
✅ Supports **fast search, insertion, and deletion** (in BSTs and balanced trees).
✅ Useful in implementing **efficient algorithms**.

---

## Disadvantages

❌ Requires **more memory** due to pointers.
❌ Complex implementation for **balancing and traversal**.

---

## Tree Traversal Methods

* **Inorder (Left, Root, Right)**
* **Preorder (Root, Left, Right)**
* **Postorder (Left, Right, Root)**
* **Level Order (Breadth-First)**

Traversal helps in **accessing and processing each node systematically**.

---

## Diagram

```
        [10]
        /  \
     [5]    [15]
     / \    /  \
   [2] [7][12] [20]
```


