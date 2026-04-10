# SPEEDEATS---FOOD-DELIVERY-SIMULATOR

**Team Members:**

- Muhammad Hasan Dad Khan (24K-0525)
- Ali Zeeshan (24K-0749)
- Zaid Amir (24K-0813)

**Course:** Data Structures  
**Instructor:** Ms. Fizza Aqeel  
**Date:** 9/10/25

## Overview

A console-based food delivery simulator built in C++ that demonstrates the use of various data structures including Linked Lists, Queues, Stacks, Binary Search Trees, Priority Queues, and Graphs with Dijkstra's Algorithm. Set in Karachi, Pakistan with real street names and locations.

## How to Run

**Compile and Run:**

```bash
g++ project.cpp -o temp
.\temp
rm temp.exe
```

Or using PowerShell one-liner:

```powershell
g++ project.cpp -o temp ; if ($?) { .\temp ; rm temp.exe }
```

> **Note:** The project runs directly from source code (`project.cpp`). No permanent exe files are kept in the repository.

## Features

✅ CSV auto-loading for nodes/edges, restaurants, and agents  
✅ Dynamic user creation on order placement  
✅ Dispatcher with Priority Queue for urgent orders and FIFO Queue for backlog  
✅ Shortest-path routing via Dijkstra's Algorithm with path visualization  
✅ Separate distance (km) and ETA (minutes) calculations  
✅ Undo last assignment using Stack  
✅ Order history stored in Linked List  
✅ BST for restaurant search by name  
✅ ASCII network map visualization with restaurant indicators

## Data Structures Used

### 1. **Linked List (Singly)**

- Stores users, agents, restaurants, and order history
- O(n) insertion and search

### 2. **Queue (FIFO)**

- Manages backlog for non-urgent or waiting orders
- O(1) enqueue and dequeue

### 3. **Stack (LIFO)**

- Event history for undo functionality
- O(1) push and pop

### 4. **Binary Search Tree**

- Stores restaurants keyed by name
- O(log n) average search time
- In-order traversal for sorted display

### 5. **Priority Queue**

- Schedules urgent/VIP orders (priority >= 5)
- Higher priority orders processed first

### 6. **Graph (Adjacency List)**

- Models road network with weighted edges
- Dijkstra's algorithm computes shortest paths and ETAs

## File Structure

```
project.cpp           - Main implementation
nodes.csv            - Graph nodes
edges.csv            - Graph edges (source, destination, weight)
restaurants.csv      - Restaurant data (id, name, nodeId)
users.csv            - User data (id, name, nodeId)
agents.csv           - Delivery agent data (id, name, nodeId)
```

## How to Compile and Run

### On Windows (PowerShell):

```powershell
g++ project.cpp -o simulator.exe
.\simulator.exe
```

### On Linux/Mac:

```bash
g++ project.cpp -o simulator
./simulator
```

## Usage Guide

### Step 1: Load Data

1. Select option **1** to load the map (nodes and edges)
   - Enter: `nodes.csv`
   - Enter: `edges.csv`
2. Select option **2** to load restaurants
   - Enter: `restaurants.csv`
3. Select option **3** to load users
   - Enter: `users.csv`
4. Select option **4** to load agents
   - Enter: `agents.csv`

### Step 2: View Data

- Option **5**: Display all restaurants (in-order traversal of BST)
- Option **6**: Search for a specific restaurant by name
- Option **7**: Display all users
- Option **8**: Display all agents

### Step 3: Create Orders

- Option **9**: Create a new order
  - Enter User ID (1-5)
  - Enter Restaurant ID (1-5)
  - Enter Priority (1-10, where ≥5 is urgent)

### Step 4: Dispatch Orders

- Option **10**: Dispatch orders
  - Processes urgent orders first (from Priority Queue)
  - Then processes backlog orders (from FIFO Queue)
  - Finds nearest available agent using Dijkstra's algorithm
  - Calculates ETA based on shortest path
  - Unavailable urgent orders move to backlog

### Step 5: Manage Orders

- Option **11**: Undo last assignment (pops from Stack)
- Option **12**: View order history (Linked List)
- Option **13**: View pending orders count

## CSV File Formats

### nodes.csv

```
nodeId
0
1
2
...
```

### edges.csv

```
source,destination,weight
0,1,4
1,2,1
...
```

### restaurants.csv

```
id,name,nodeId
1,Pizza Palace,0
2,Burger King,2
...
```

### users.csv

```
id,name,nodeId
1,Alice,1
2,Bob,3
...
```

### agents.csv

```
id,name,nodeId
1,Agent Smith,0
2,Agent Jones,4
...
```

## Example Test Scenario

1. Load all CSV files (options 1-4)
2. Create an urgent order: User 1, Restaurant 1, Priority 8
3. Create a regular order: User 2, Restaurant 2, Priority 3
4. Dispatch orders (option 10)
   - System finds nearest agent to restaurant using Dijkstra
   - Calculates ETA to user location
   - Assigns agent and updates status
5. Try undo (option 11) to revert last assignment
6. View order history (option 12)

## Algorithms

### Dijkstra's Shortest Path

- **Time Complexity:** O(V²) where V is the number of vertices
- **Space Complexity:** O(V)
- Used for finding nearest agent and calculating ETAs

### BST Operations

- **Insert:** O(log n) average, O(n) worst case
- **Search:** O(log n) average, O(n) worst case
- **In-order Traversal:** O(n)

## Key Implementation Details

1. **Agent Selection:** Uses Dijkstra to find nearest available agent from restaurant location
2. **ETA Calculation:** Computes shortest path from restaurant to user
3. **Order Priority:** Priority ≥5 goes to urgent queue, <5 goes to backlog
4. **Undo Functionality:** Stack stores last assignment for reversal
5. **Order Tracking:** Linked list maintains complete order history

## Notes

- All file paths should be relative to the executable location
- Graph is undirected (edges work both ways)
- Agents become unavailable after assignment
- Undo makes agent available again
- Priority range: 1-10 (higher = more urgent)

## Future Enhancements

- Real-time order tracking
- Agent completion and availability reset
- Multi-order assignment per agent
- Advanced routing with traffic simulation
- GUI interface

---

**Developed as part of Data Structures course final project**

