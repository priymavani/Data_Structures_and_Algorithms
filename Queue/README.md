## ✅ Queue: Definition

A **Queue** is a **linear data structure** that stores elements in an ordered manner, following the:

> **FIFO (First In, First Out) principle**,
> which means the **first element inserted into the queue will be the first element to be removed**.

It behaves like a **queue at a ticket counter** where:

* You **add elements at the rear (enqueue)**.
* You **remove elements from the front (dequeue)**.

---

## Key Operations

1️⃣ **Enqueue**:
Insert an element at the **rear of the queue**.

2️⃣ **Dequeue**:
Remove the **front element from the queue**.

3️⃣ **Front (Peek)**:
View the **front element without removing it**.

4️⃣ **isEmpty**:
Check if the queue has no elements.

5️⃣ **isFull**:
Check if the queue is full (for fixed-size implementations).

---

## Representation

Queues can be implemented using:

* **Arrays**: with a fixed maximum size.
* **Linked Lists**: for dynamic size, allowing flexible growth based on memory.

There are also **circular queues** to efficiently utilize space in array-based implementations.

---

## Example

**Operations:**

```
Enqueue(5)
Enqueue(10)
Enqueue(15)
Dequeue()
```

Now the queue will be:

```
Front -> 10
          15 <- Rear
```

(5 was removed because it was the first inserted).

---

## Types of Queue

* **Simple Queue** (FIFO).
* **Circular Queue**.
* **Priority Queue** (elements are removed based on priority, not just order).
* **Double Ended Queue (Deque)** (insertion and deletion can occur at both ends).

---

## Applications of Queue

* Managing **requests in CPU scheduling**.
* Handling **printer spooling**.
* **Data buffering** (IO buffers, network data packets).
* Handling **real-life waiting lines** (ticket counters, customer support systems).
* **Breadth-First Search (BFS)** in graph algorithms.

---

## Advantages

✅ Simple structure and easy to implement.
✅ Useful for handling real-world scenarios requiring **FIFO**.
✅ Efficient for processing elements in the order they arrive.

---

## Disadvantages

❌ Fixed size in array implementation can lead to **wasted space** if not using circular queue.
❌ Only allows access to the **front and rear elements directly**.

---

## Diagram

```
Front -> [ 5 ] [ 10 ] [ 15 ] <- Rear
```

After one **Dequeue()**:

```
Front -> [ 10 ] [ 15 ] <- Rear
```
