## Stack: Definition

A **Stack** is a linear data structure that stores elements in an ordered manner, following the:

> **LIFO (Last In, First Out) principle**,
> which means the **last element inserted into the stack will be the first element to be removed**.

It behaves like a **stack of plates** where:

* You **add plates on the top (Push)**.
* You **remove plates from the top (Pop)**.

---

## Key Operations

1️⃣ **Push**:
Add an element to the **top of the stack**.

2️⃣ **Pop**:
Remove the **top element from the stack**.

3️⃣ **Peek (Top)**:
View the **top element without removing it**.

4️⃣ **isEmpty**:
Check if the stack has no elements.

5️⃣ **isFull**:
Check if the stack is full (for fixed-size implementations).

---
## Representation

Stacks can be implemented using:

* **Arrays**: with a fixed maximum size.
* **Linked Lists**: for dynamic size, allowing unlimited growth based on memory.

---

## Example

**Operations:**

```
Push(5)
Push(10)
Push(15)
Pop()
```

Now the stack will be:

```
Top -> 10
       5
```

(15 was removed because it was the last inserted).

---

## Applications of Stack

* Expression evaluation and conversion (infix to postfix/prefix).
* Function call and recursion handling (call stack).
* Undo operations in editors.
* Parenthesis matching in compilers.
* Backtracking algorithms (maze solving, puzzles).
* Reversing data (strings, arrays).

---

## Advantages

✅ Simple and easy to implement.
✅ Useful for managing data requiring **LIFO** order.
✅ Efficient for last-in, first-out data processing.

---

## Disadvantages

❌ Only the top element can be accessed directly.
❌ Fixed size in array implementation can limit flexibility.

---

## Diagram

```
+------+
|  15  |  <- Top (last pushed)
+------+
|  10  |
+------+
|   5  |
+------+
```
