# User Guide - Updated Features

## What's Changed?

### 1. **Users CSV File is Now Dynamic**

- The `users.csv` file starts empty (only contains the header)
- Users are added dynamically when placing orders
- Each new user is automatically assigned a unique User ID

### 2. **Creating an Order - New Flow**

When you select **Option 5: Create New Order**, you will be prompted for:

1. **Your Name**: Enter the customer's name

   ```
   Enter your name: John Doe
   ```

2. **Your Location (Node ID)**: Enter a node ID from 0 to 9 (based on the map)

   ```
   Enter your location (Node ID 0-9): 3
   ```

   - The system validates the node ID
   - If invalid, an error message is shown

3. **Restaurant ID**: Select which restaurant to order from

   ```
   Enter Restaurant ID: 2
   ```

4. **Priority**: Set the order priority (1-10)
   ```
   Enter Priority (1-10, >=5 is urgent): 7
   ```

### 3. **What Happens Behind the Scenes**

1. A new user is created with:

   - Auto-generated User ID
   - The name you entered
   - The node location you specified

2. The user is saved to `users.csv` file

3. An order is created and linked to this new user

4. The order is added to either:
   - **Priority Queue** (if priority ≥ 5)
   - **Backlog Queue** (if priority < 5)

### Example Session:

```
========== Create New Order ==========
Enter your name: Sarah Ahmed
Enter your location (Node ID 0-9): 5

User created successfully! User ID: 1

Enter Restaurant ID: 3
Enter Priority (1-10, >=5 is urgent): 8

Urgent order created and added to priority queue.
Order ID: 1, User: 1, Restaurant: 3, Agent: -1, Priority: 8, Status: Pending
```

### 4. **Viewing Users**

Select **Option 3: Display All Users** to see all users who have placed orders.

The list will grow as more orders are placed!

### 5. **users.csv File Format**

After users place orders, the file will look like:

```csv
id,name,nodeId
1,Sarah Ahmed,5
2,Ali Khan,2
3,Fatima Shah,7
```

## Benefits

✅ No need to manually manage user data  
✅ Each customer gets a unique ID automatically  
✅ User data is persistent (saved to CSV)  
✅ More realistic food delivery simulation  
✅ Location-based order routing

## Notes

- User IDs start from 1 and increment automatically
- Node IDs must be valid (0 to 9 for the default map)
- The system prevents invalid node IDs
- All user data is preserved in `users.csv` for future reference
