# Graph Data Structure

## 1. What is a Graph in DSA?
A **Graph** is a **non-linear data structure** that consists of:

- **Vertices (Nodes):** Represent entities (like cities, people, webpages).
- **Edges (Connections):** Represent relationships/links between entities.

👉 **Real-life Example:**
- Vertices = People on Facebook  
- Edges = Friend connections between them  

---

## 2. Purpose of a Graph
Graphs are used to model **relationships** and **networks** where data is interconnected.  
They help solve problems like:

- Finding shortest path (**Google Maps**).  
- Social connections (**Facebook, LinkedIn**).  
- Web navigation (**search engines use graphs**).  
- Task scheduling (**dependency graphs**).  

👉 **Example:**  
Google Maps uses graphs where **vertices = locations** and **edges = roads with weights (distance/time)**.

---

## 3. Types of Graphs in DSA

### 1. Undirected Graph
- **Definition:** Edges have no direction.  
- If A is connected to B, then B is also connected to A.  

📌 **Real-life Example:** Facebook friendship (if you’re my friend, I’m your friend too).  

**Visualization:**
```
A —— B
|     
C
```
(A is connected to B and C. The connections are two-way.)

---

### 2. Directed Graph (Digraph)
- **Definition:** Edges have direction (arrows).  
- If A → B, it doesn’t mean B → A.  

📌 **Real-life Example:** Instagram follow system (you can follow someone who doesn’t follow you back).  

**Visualization:**
```
A → B
↑    
C
```
(A follows B, C follows A. Direction matters.)

---

### 3. Weighted Graph
- **Definition:** Edges have weights (cost, distance, time).  
- Used when relationships have value.  

📌 **Real-life Example:** Google Maps (weights = distance/time between two locations).  

**Visualization:**
```
A —5— B
|     
2     
C
```
(A to B has weight 5, A to C has weight 2.)

---

### 4. Unweighted Graph
- **Definition:** Edges have no weights, only connection exists.  

📌 **Real-life Example:** LinkedIn connection (just connected or not, no distance/weight).  

**Visualization:**
```
A —— B
|
C
```
(Only connections, no weights.)

---

### 5. Cyclic Graph
- **Definition:** Contains at least one cycle (a path where you can come back to starting node).  

📌 **Real-life Example:** Road network in a city block (you can loop around and return).  

**Visualization:**
```
A —— B
|     |
C ————
```
(A → B → C → A forms a cycle.)

---

### 6. Acyclic Graph
- **Definition:** No cycles present.  
- You can’t return to the starting node once you move forward.  

📌 **Real-life Example:** Family tree (child can’t be parent of ancestor).  

**Visualization:**
```
A → B → C
```
(No cycles, just a straight/branching path.)

---

### 7. Connected Graph
- **Definition:** There is a path between every pair of vertices.  

📌 **Real-life Example:** Airline network where every airport is reachable (maybe with connecting flights).  

**Visualization:**
```
A —— B —— C
     |
     D
```
(Every node is reachable from any other node.)

---

### 8. Disconnected Graph
- **Definition:** Some vertices are not reachable from others.  

📌 **Real-life Example:** Two separate WhatsApp groups (no link between members).  

**Visualization:**
```
A —— B      C —— D
```
(Graph has two separate components, no full connection.)

---

## 4. Graph Representations
We usually store graphs in two ways:

### Adjacency Matrix
- 2D array of size V × V (V = number of vertices).  
- Easy but takes more space.  
- **Example:** Social network where `matrix[i][j] = 1` means person i is friend with j.  

### Adjacency List
- Array of lists where each index stores the neighbors of a node.  
- Space efficient for sparse graphs.  
- **Example:** Road map where each city stores a list of connected cities.  

---

## 5. Real-Life Applications of Graphs
- **Social Networks:** Model relationships (Facebook, LinkedIn).  
- **Maps & GPS:** Finding shortest/fastest routes (Google Maps).  
- **Search Engines:** Webpages linked via hyperlinks (Google PageRank).  
- **Airline Routes:** Airports as nodes, flights as edges.  
- **Recommendation Systems:** Netflix uses graphs for recommending movies (users connected to movies).  
- **Computer Networks:** Routers as vertices, connections as edges.  
- **Project Scheduling:** Using DAG for dependencies.  
