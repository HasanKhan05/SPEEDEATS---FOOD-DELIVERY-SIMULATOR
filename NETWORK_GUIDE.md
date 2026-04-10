# Food Delivery Network Guide

## Network Structure

### 📍 **10-Node Graph Network**

The delivery network consists of 10 nodes divided into two categories:

#### **Restaurants (Nodes 0-4)**

- Node 0: **Pizza Palace**
- Node 1: **Burger King**
- Node 2: **Sushi Station**
- Node 3: **Taco Town**
- Node 4: **Pasta Paradise**

#### **Delivery Points (Nodes 5-9)**

- Node 5: **Green Valley**
- Node 6: **Blue Heights**
- Node 7: **Red Square**
- Node 8: **Golden Plaza**
- Node 9: **Silver Street**

---

## Street Network

The nodes are connected by the following streets:

| From               | To                 | Street Name     | Distance (km) |
| ------------------ | ------------------ | --------------- | ------------- |
| Pizza Palace (0)   | Burger King (1)    | Main Street     | 5             |
| Pizza Palace (0)   | Green Valley (5)   | Oak Avenue      | 8             |
| Burger King (1)    | Sushi Station (2)  | Park Road       | 4             |
| Burger King (1)    | Blue Heights (6)   | Elm Street      | 7             |
| Sushi Station (2)  | Taco Town (3)      | Maple Drive     | 6             |
| Sushi Station (2)  | Red Square (7)     | Pine Lane       | 5             |
| Taco Town (3)      | Pasta Paradise (4) | Cedar Way       | 4             |
| Taco Town (3)      | Golden Plaza (8)   | Birch Boulevard | 9             |
| Pasta Paradise (4) | Silver Street (9)  | Willow Path     | 6             |
| Green Valley (5)   | Blue Heights (6)   | First Avenue    | 3             |
| Blue Heights (6)   | Red Square (7)     | Second Avenue   | 4             |
| Red Square (7)     | Golden Plaza (8)   | Third Avenue    | 5             |
| Golden Plaza (8)   | Silver Street (9)  | Fourth Avenue   | 3             |
| Pizza Palace (0)   | Sushi Station (2)  | Express Highway | 10            |

---

## How the System Works

### **1. Creating an Order**

When you create an order (Menu Option 6):

1. The system shows available **delivery points** (nodes 5-9)
2. You enter your **name**
3. You select a **delivery point** (where you want food delivered)
4. You choose a **restaurant** (1-5)
5. You set the **priority** (1-10, where ≥5 is urgent)

**Example:**

```
Enter your name: John Smith
Select delivery point (5-9): 7
Delivery Location: Red Square

Enter Restaurant ID (1-5): 2
Priority: 8
```

### **2. Dispatching Orders**

When orders are dispatched (Menu Option 7):

The system uses **Dijkstra's Shortest Path Algorithm** to:

1. Find the **optimal route** from restaurant to delivery point
2. Calculate the **total distance** in kilometers
3. Display the **complete path** with street names
4. Show **estimated delivery time** (based on distance)

**Example Output:**

```
╔════════════════════════════════════════╗
║     ORDER DISPATCHED SUCCESSFULLY!     ║
╚════════════════════════════════════════╝

[URGENT ORDER #1]
Customer: John Smith
Restaurant: Burger King
Agent: Agent Jones
Estimated Time: 11 minutes

========== Route Details ==========
From: Burger King (Restaurant)
To: Red Square (Delivery Point)
Total Distance: 11 km

Path:
  1. Burger King --> [Park Road, 4 km] -->
  2. Sushi Station --> [Pine Lane, 5 km] -->
  3. Red Square --> [Second Avenue, 4 km] -->
  4. Blue Heights
===================================
```

### **3. Viewing the Network Map**

Select **Menu Option 1** to see:

- All restaurants and their locations
- All delivery points and their locations
- All street connections with distances
- Complete network topology

---

## Shortest Path Algorithm

### **Dijkstra's Algorithm Implementation**

The system uses Dijkstra's algorithm to:

- Find the shortest path from any restaurant to any delivery point
- Calculate the minimum total distance
- Track the exact route taken
- Display each street segment of the journey

**Algorithm Features:**

- ✅ Time Complexity: O(V²) where V = 10 nodes
- ✅ Guarantees shortest path
- ✅ Handles weighted edges (different street distances)
- ✅ Stores parent nodes for path reconstruction
- ✅ Works on undirected graph (streets work both ways)

---

## Usage Tips

### **Best Practices:**

1. **View the Network Map First** (Option 1)

   - Understand the layout
   - See all available locations
   - Check street connections

2. **Choose Nearby Restaurants**

   - Shorter paths = faster delivery
   - Lower costs for customers

3. **Use Priority Wisely**

   - Priority ≥5: Goes to urgent queue (processed first)
   - Priority <5: Goes to backlog queue

4. **Monitor Orders**
   - Option 9: View order history
   - Option 10: Check pending orders

### **Example Delivery Scenarios:**

**Fast Delivery:**

- Restaurant: Sushi Station (2)
- Delivery: Red Square (7)
- Route: Sushi Station → Red Square via Pine Lane
- Distance: 5 km ✅ Direct route!

**Longer Delivery:**

- Restaurant: Pizza Palace (0)
- Delivery: Silver Street (9)
- Route: Multiple streets, optimized by Dijkstra
- Distance: Calculated automatically

---

## CSV File Structure

### **nodes.csv**

```csv
nodeId,name,type
0,Pizza Palace,restaurant
1,Burger King,restaurant
...
5,Green Valley,delivery
...
```

### **edges.csv**

```csv
source,destination,weight,streetName
0,1,5,Main Street
0,5,8,Oak Avenue
...
```

### **restaurants.csv**

```csv
id,name,nodeId
1,Pizza Palace,0
2,Burger King,1
...
```

---

## Technical Details

### **Data Structures Used:**

1. **Graph (Adjacency List)** - Network representation
2. **Vector** - Distance and parent tracking in Dijkstra
3. **Linked List** - Adjacency list edges
4. **Priority Queue** - Urgent order processing
5. **Regular Queue** - Backlog order processing
6. **Stack** - Undo functionality
7. **Binary Search Tree** - Restaurant searching

### **Path Display Features:**

- Shows complete route step-by-step
- Displays street names for each segment
- Shows distance for each street
- Calculates total distance
- Formats output clearly

---

## Compile and Run

```powershell
# Compile
g++ project.cpp -o simulator.exe

# Run
.\simulator.exe
```

---

**Enjoy your food delivery simulation! 🍕🍔🍣🌮🍝**
