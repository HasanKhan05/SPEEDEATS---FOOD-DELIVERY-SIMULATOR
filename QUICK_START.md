# 🚀 Quick Start Guide

## Running the Simulator

```powershell
# Compile
g++ project.cpp -o simulator.exe

# Run
.\simulator.exe
```

---

## 📋 Test Scenario - Step by Step

### **Test 1: View the Network**

1. When menu appears, press `1`
2. You'll see:
   - All 5 restaurants (nodes 0-4)
   - All 5 delivery points (nodes 5-9)
   - All 14 street connections
3. Press Enter to go back

---

### **Test 2: Create Your First Order**

1. From menu, press `6` (Create New Order)
2. **Enter your name:** `Sarah Khan`
3. You'll see available delivery points:
   ```
   5. Green Valley
   6. Blue Heights
   7. Red Square
   8. Golden Plaza
   9. Silver Street
   ```
4. **Select delivery point:** `7` (Red Square)
5. You'll see available restaurants (1-5)
6. **Enter Restaurant ID:** `2` (Burger King)
7. **Enter Priority:** `8` (urgent - will be processed first)
8. Press Enter to go back

---

### **Test 3: Dispatch the Order & See the Path!**

1. From menu, press `7` (Dispatch Orders)
2. Watch the magic! You'll see:

   ```
   ╔════════════════════════════════════════╗
   ║     ORDER DISPATCHED SUCCESSFULLY!     ║
   ╚════════════════════════════════════════╝

   [URGENT ORDER #1]
   Customer: Sarah Khan
   Restaurant: Burger King
   Agent: Agent Jones
   Estimated Time: 9 minutes

   ========== Route Details ==========
   From: Burger King (Restaurant)
   To: Red Square (Delivery Point)
   Total Distance: 9 km

   Path:
     1. Burger King --> [Park Road, 4 km] -->
     2. Sushi Station --> [Pine Lane, 5 km] -->
     3. Red Square
   ===================================
   ```

3. This shows:

   - The complete route
   - Every street name the driver takes
   - Distance for each segment
   - Total distance

4. Press Enter to go back

---

### **Test 4: Create Multiple Orders**

Create 2-3 more orders with different combinations:

**Order 2:**

- Name: `Ali Ahmed`
- Delivery Point: `9` (Silver Street)
- Restaurant: `1` (Pizza Palace)
- Priority: `3` (regular)

**Order 3:**

- Name: `Fatima Siddiqui`
- Delivery Point: `5` (Green Valley)
- Restaurant: `1` (Pizza Palace)
- Priority: `9` (urgent)

Now dispatch again (Option 7) and see multiple orders processed!

---

### **Test 5: View All Users**

1. From menu, press `4` (Display All Users)
2. You'll see all users who placed orders
3. Notice how they were automatically saved!

---

### **Test 6: View Order History**

1. From menu, press `9` (Display Order History)
2. See all completed orders with their details

---

### **Test 7: Undo Last Assignment**

1. From menu, press `8` (Undo Last Assignment)
2. The last dispatched order's agent becomes available again
3. You can dispatch again to reassign

---

## 🎯 Understanding the Output

### When you see a path like:

```
1. Pizza Palace --> [Oak Avenue, 8 km] -->
2. Green Valley
```

This means:

- **Start:** Pizza Palace (Restaurant)
- **Travel:** Via Oak Avenue for 8 km
- **Arrive:** At Green Valley (Delivery Point)

### For longer paths:

```
1. Burger King --> [Park Road, 4 km] -->
2. Sushi Station --> [Pine Lane, 5 km] -->
3. Red Square
```

This means:

- **Start:** Burger King
- **Step 1:** Drive on Park Road for 4 km to reach Sushi Station
- **Step 2:** Drive on Pine Lane for 5 km to reach Red Square
- **Total:** 9 km

---

## 🔍 Key Points

### Restaurants vs Delivery Points

- **Restaurants (0-4):** Where food is prepared
- **Delivery Points (5-9):** Where customers are located
- You can only deliver TO delivery points (not to restaurants!)

### Priority System

- **Priority 1-4:** Regular orders (go to backlog queue)
- **Priority 5-10:** Urgent/VIP orders (processed first)

### Agents

- 3 agents are available initially
- After assignment, agents become "Busy"
- Use "Undo" to free them up for testing

---

## 📊 Sample Paths to Try

Want to see different routes? Try these combinations:

| Restaurant       | Delivery Point    | Expected Path Length |
| ---------------- | ----------------- | -------------------- |
| Pizza Palace (1) | Green Valley (5)  | 8 km (direct)        |
| Burger King (2)  | Red Square (7)    | 9 km (2 segments)    |
| Taco Town (4)    | Silver Street (9) | 10 km (2 segments)   |
| Pizza Palace (1) | Silver Street (9) | Long route!          |

---

## ❓ Troubleshooting

**Q: No agents available?**  
A: Use Option 8 to undo assignments and free up agents

**Q: Can't create order?**  
A: Make sure you select delivery point 5-9 (not 0-4)

**Q: Want to start fresh?**  
A: Delete `users.csv` content (keep header only) and restart

---

## 🎓 What This Demonstrates

1. ✅ **Graph Data Structure** - Network of nodes and edges
2. ✅ **Dijkstra's Algorithm** - Shortest path calculation
3. ✅ **Binary Search Tree** - Restaurant search
4. ✅ **Priority Queue** - Urgent order processing
5. ✅ **Stack** - Undo functionality
6. ✅ **Queue** - Backlog management
7. ✅ **Linked List** - User/Agent/Order storage

---

**Have fun testing! 🍕🚗💨**
