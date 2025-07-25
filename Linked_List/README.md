# Linked List Overview

## 1️⃣ What is a Linked List?

A **Linked List** is a **linear data structure** where elements are stored in **nodes**, and each node points to the **next node** in the sequence.

Unlike arrays:

* Elements are **not stored in contiguous memory**.
* Dynamic size (can easily grow or shrink).
* Easy insertion/deletion without shifting elements.

---

## 2️⃣ Structure of a Node

Each **Node** in a linked list typically contains:

* **Data**: The value you want to store.
* **Next**: A pointer/reference to the next node.

Example in C-style structure:

```c
struct Node {
    int data;
    struct Node* next;
};
```

---

## 3️⃣ Types of Linked Lists

### Singly Linked List

* Each node points to the next node.
* Traversal is **one-way**.

### Doubly Linked List

* Each node has `next` and `prev` pointers.
* Traversal is possible **both forward and backward**.

### Circular Linked List

* The last node points back to the first node.
* Can be **singly or doubly circular**.

---

## 4️⃣ Basic Operations

### ➡️ Insertion

* At the beginning.
* At the end.
* At a specific position.

### ➡️ Deletion

* From the beginning.
* From the end.
* A specific value or position.

### ➡️ Traversal

* Visiting each node to access or display data.

---

## 5️⃣ Advantages of Linked Lists

✅ Dynamic memory allocation (no wasted memory).

✅ Easy insertion/deletion operations.

✅ No need to define size in advance.

---

## 6️⃣ Disadvantages of Linked Lists

❌ Extra memory for pointers.

❌ No direct/random access (need to traverse sequentially).

❌ More complex implementation than arrays.

---

## 7️⃣ When to use a Linked List?

Use Linked Lists when:

* Frequent **insertions and deletions** are needed.
* You do not know the exact size of the list in advance.
* Memory utilization needs to be flexible.
