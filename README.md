<div align="center">

# SpeedEats — Food Delivery Simulator

A high-performance C++ food delivery routing simulator utilizing custom Abstract Data Types (ADTs) and graph algorithms to optimize order queues, shortest-path rider dispatch, and ETA calculation.

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%2F20-00599C.svg?style=flat&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/)
[![Course](https://img.shields.io/badge/Course-Data%20Structures-orange.svg?style=flat)](https://nu.edu.pk/)
[![Algorithm](https://img.shields.io/badge/Algorithm-Dijkstra's%20Shortest%20Path-green.svg?style=flat)](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
[![Data Structures](https://img.shields.io/badge/ADT-Built%20From%20Scratch-blue.svg?style=flat)](#data-structures--complexity)

</div>

---

### Navigation

[Overview](#project-overview) · [Core Data Structures](#core-data-structures--complexity) · [Network Model](#network-model--routing) · [Features](#key-capabilities) · [Project Structure](#project-structure) · [Routing & Dispatch](#algorithmic-routing--dispatch-architecture) · [Simulation Lifecycle](#simulation-lifecycle--functional-architecture) · [Author](#author)

---

## Project Overview

Logistics and on-demand delivery networks require low-latency dispatching, shortest-path traversal, and robust queue management under variable operational loads. 

**SpeedEats** simulates a metropolitan delivery network (set in Karachi, Pakistan) that models real-world road intersections, restaurant hubs, customer delivery points, and active delivery agents. The system is written entirely in **C++** without reliance on Standard Template Library (STL) container abstractions (`std::vector`, `std::queue`, `std::stack`, `std::map`). Every core Abstract Data Type—including singly linked lists, FIFO queues, LIFO event stacks, binary search trees, priority queues, and weighted graphs—is implemented natively from scratch using C++ templates and explicit pointer manipulation.

> **Academic Note:** Developed as part of the Data Structures (DSA) coursework at FAST-NUCES under the instruction of Ms. Fizza Aqeel.

---

## Core Data Structures & Complexity

All ADTs are implemented with custom generic templates located directly in `project.cpp`.

```mermaid
flowchart TD
    Order["New Order Placed"] --> Check{"Priority >= 5?"}
    Check -->|"Yes (Urgent / VIP)"| PQ["PriorityQueue (Max-Priority)"]
    Check -->|"No (Standard)"| FIFO["Queue (FIFO Backlog)"]
    
    PQ --> Dispatcher["Dispatcher Engine"]
    FIFO --> Dispatcher
    
    Dispatcher --> GraphQuery["Query Graph via Dijkstra"]
    GraphQuery --> FindAgent["Find Nearest Available Agent"]
    FindAgent --> CalculateETA["Calculate Shortest Path and ETA"]
    
    CalculateETA --> Commit["Assign Rider and Update State"]
    Commit --> Stack["Push to Stack (Undo History)"]
    Commit --> List["Append to LinkedList (Order History)"]
```

### ADT Specifications

| Data Structure | Implementation Details | Operations Supported | Time Complexity | Purpose in System |
|---|---|---|:---:|---|
| **`LinkedList<T>`** | Dynamic node-linked linear chain with head/tail tracking | `insert()`, `display()`, `find()`, `remove()` | Insertion: $O(1)$<br>Search: $O(n)$ | Manages user directories, delivery agents, restaurant catalog, and persistent order histories. |
| **`Queue<T>`** | Linked FIFO queue with front and rear pointers | `enqueue()`, `dequeue()`, `peek()`, `isEmpty()` | Enqueue: $O(1)$<br>Dequeue: $O(1)$ | Buffers non-urgent delivery orders and backlogs when riders are busy. |
| **`Stack<T>`** | Linked LIFO stack with top-pointer push/pop | `push()`, `pop()`, `top()`, `isEmpty()` | Push: $O(1)$<br>Pop: $O(1)$ | Tracks dispatch transactions to power an instant single-step "Undo" operation (reverting assignments and agent availability). |
| **`PriorityQueue`** | Array-backed dynamic max-heap based on order urgency (1–10) | `enqueue(order, priority)`, `dequeue()`, `peek()` | Enqueue: $O(\log n)$<br>Extract-Max: $O(\log n)$ | Schedules urgent orders (priority $\ge 5$) ahead of standard orders. |
| **`BST`** | Binary Search Tree ordered alphabetically by restaurant name | `insert()`, `search()`, `inorder()` | Search (avg): $O(\log n)$<br>Search (worst): $O(n)$ | Enables fast search and alphabetical listing of restaurants. |
| **`Graph`** | Weighted undirected adjacency list representation | `addEdge()`, `dijkstra()`, `printGraph()` | Dijkstra: $O(V^2)$<br>Edge Lookup: $O(E)$ | Models street topologies, computes exact road distance (km), and derives estimated delivery times (ETA). |

---

## Network Model & Routing

The simulation models an undirected road network composed of 10 primary nodes connected by weighted road edges representing Karachi thoroughfares:

### Network Topology

```text
  [0: Pizza Palace] -------(5 km)------- [1: Burger King] -------(4 km)------- [2: Sushi Station]
          |                                      |                                      |
       (8 km)                                 (7 km)                                 (5 km)
          |                                      |                                      |
  [5: Green Valley]                      [6: Blue Heights]                      [7: Red Square]
                                                                                        |
  [4: Pasta Paradise] ----(4 km)---- [3: Taco Town] -------(9 km)------- [8: Golden Plaza]
                                                                                        |
                                                                                     (3 km)
                                                                                        |
                                                                                [9: Silver Street]
```

- **Restaurant Hubs (Nodes 0–4):** Pizza Palace (0), Burger King (1), Sushi Station (2), Taco Town (3), Pasta Paradise (4).
- **Delivery Zones (Nodes 5–9):** Green Valley (5), Blue Heights (6), Red Square (7), Golden Plaza (8), Silver Street (9).
- **Routing Engine:** Employs Dijkstra's Single-Source Shortest Path algorithm to find the closest idle agent to the restaurant node, then calculates the shortest route and ETA from the restaurant to the user destination.

---

## Key Capabilities

- **Pure ADT Design:** Zero dependence on STL container classes (`vector`, `queue`, `stack`, `map`) for internal operational storage.
- **Dual-Queue Priority Dispatching:** Orders with priority $\ge 5$ are queued into the `PriorityQueue` for expedited dispatch, while standard orders reside in a FIFO `Queue`.
- **Dijkstra-Powered Dispatch:** Dynamically evaluates all available delivery agents and assigns the one with the minimal travel distance to the fulfillment restaurant.
- **Distance & ETA Modeling:** Computes travel distances in kilometers and translates road weights into realistic travel times (minutes) based on route complexity.
- **Single-Step Undo System:** Any accidental or misallocated rider assignment can be instantly undone via the LIFO `Stack`, returning the order to the queue and freeing the agent.
- **BST Restaurant Indexing:** Binary Search Tree implementation enabling logarithmic-time search by restaurant name and alphabetical directory printing via in-order traversal.
- **CSV Data Ingestion:** Automated ingestion for road topologies, restaurant directories, delivery agents, and user records from structured CSV files.

---

## Project Structure

```text
SPEEDEATS---FOOD-DELIVERY-SIMULATOR/
├── project.cpp           # Complete source: custom ADT templates, Graph, and Simulator engine
├── nodes.csv             # Graph vertices (intersections and hub IDs)
├── edges.csv             # Weighted undirected edges (source, destination, distance in km)
├── restaurants.csv       # Restaurant catalog (id, name, nodeId)
├── users.csv             # Customer directory (id, name, nodeId)
├── agents.csv            # Delivery rider directory (id, name, nodeId)
├── orders.csv            # Order records
├── NETWORK_GUIDE.md      # Street connection and node topology guide
├── QUICK_START.md        # Quick reference for compilation and commands
├── USER_GUIDE.md         # Full feature walkthrough and test scenarios
└── README.md             # Project documentation
```

---

## Algorithmic Routing & Dispatch Architecture

SpeedEats models real-time order scheduling and agent routing through formal algorithmic invariants:

- **Dual-Queue Priority Partitioning:** Incoming orders are assigned an integer urgency weight $w \in [1, 10]$. Orders with $w \ge 5$ are treated as priority/VIP deliveries and inserted into the max-heap `PriorityQueue` with logarithmic insertion $O(\log n)$, guaranteeing expedited dispatch. Orders with $w < 5$ are appended to the standard FIFO `Queue` with $O(1)$ enqueue time.
- **Shortest-Path Traversal (Dijkstra's Algorithm):** The city road network is represented as a weighted undirected graph $G = (V, E)$. When an order is dispatched, Dijkstra's algorithm computes the shortest path distance $d(u, v) = \min \sum_{(i,j) \in P} w_{ij}$ from all available delivery agents $a \in A$ to the fulfillment restaurant node $r$. The agent minimizing $d(a, r)$ is selected.
- **Dual-Leg Trip & Dynamic ETA Formulation:** Total delivery route duration is modeled as a two-leg journey: agent transit to restaurant ($d_1 = d(a, r)$) and food delivery to destination ($d_2 = d(r, c)$). Estimated Time of Arrival (ETA) is derived from cumulative road weights and distance metrics:
  $$\text{ETA} = \left(\frac{d(a, r) + d(r, c)}{v_{\text{urban}}}\right) + t_{\text{prep}}$$
- **State Reversibility via LIFO Stack Invariant:** Every dispatch transaction pushes an immutable state token onto the `Stack<T>`. An instant "Undo" operation pops the latest transaction, restoring the delivery agent to the active pool and re-enqueuing the order without corrupting global network states or history logs.

---

## Simulation Lifecycle & Functional Architecture

The simulator coordinates data flow across discrete operational subsystems:

1. **Topology & Catalog Initialization:** Streams vertices, weighted edges, restaurant metadata, user coordinates, and agent initial locations directly into internal linked lists, graphs, and binary search trees.
2. **BST Restaurant Lookup & Traversal:** Indexes restaurant records alphabetically by name within a custom Binary Search Tree, supporting $O(\log n)$ average search complexity and sorted lexicographic directory output via in-order traversal.
3. **Dispatch & Routing Pipeline:** Coordinates priority queue extraction, Dijkstra shortest path calculations across active agents, and agent state transitions.
4. **Historical Audit & Inspection:** Maintains complete transactional order lineages within a persistent `LinkedList` for delivery auditing, state tracking, and backlog metrics.

---

## Author

**Muhammad Hasan Dad Khan**  
Computer Science — FAST-NUCES  

*Project developed in collaboration with Ali Zeeshan and Zaid Amir as part of the Data Structures (DSA) coursework at FAST-NUCES under the instruction of Ms. Fizza Aqeel.*\n