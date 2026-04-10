#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 999999;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void insert(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    Node<T> *getHead() { return head; }
    int getSize() { return size; }

    T *find(int id)
    {
        Node<T> *temp = head;
        while (temp)
        {
            if (temp->data.id == id)
            {
                return &(temp->data);
            }
            temp = temp->next;
        }
        return nullptr;
    }

    ~LinkedList()
    {
        Node<T> *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue()
    {
        if (!front)
        {
            throw runtime_error("Queue is empty");
        }
        Node<T> *temp = front;
        T data = front->data;
        front = front->next;
        if (!front)
        {
            rear = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    bool isEmpty() { return front == nullptr; }
    int getSize() { return size; }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop()
    {
        if (!top)
        {
            throw runtime_error("Stack is empty");
        }
        Node<T> *temp = top;
        T data = top->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    bool isEmpty() { return top == nullptr; }
    int getSize() { return size; }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

template <typename T>
class PriorityQueue
{
private:
    struct PQNode
    {
        T data;
        int priority;
        PQNode *next;

        PQNode(T d, int p) : data(d), priority(p), next(nullptr) {}
    };

    PQNode *head;
    int size;

public:
    PriorityQueue() : head(nullptr), size(0) {}

    void enqueue(T data, int priority)
    {
        PQNode *newNode = new PQNode(data, priority);

        if (!head || priority > head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            PQNode *temp = head;
            while (temp->next && temp->next->priority >= priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    T dequeue()
    {
        if (!head)
        {
            throw runtime_error("Priority Queue is empty");
        }
        PQNode *temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    bool isEmpty() { return head == nullptr; }
    int getSize() { return size; }

    ~PriorityQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

struct Restaurant
{
    int id;
    string name;
    int nodeId;

    Restaurant() : id(0), name(""), nodeId(0) {}
    Restaurant(int i, string n, int nid) : id(i), name(n), nodeId(nid) {}

    friend ostream &operator<<(ostream &os, const Restaurant &r)
    {
        os << "Restaurant ID: " << r.id << ", Name: " << r.name << ", Node: " << r.nodeId;
        return os;
    }
};

class BSTNode
{
public:
    Restaurant data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(Restaurant r) : data(r), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    BSTNode *root;

    BSTNode *insertHelper(BSTNode *node, Restaurant r)
    {
        if (!node)
        {
            return new BSTNode(r);
        }

        if (r.name < node->data.name)
        {
            node->left = insertHelper(node->left, r);
        }
        else
        {
            node->right = insertHelper(node->right, r);
        }
        return node;
    }

    void inorderHelper(BSTNode *node)
    {
        if (node)
        {
            inorderHelper(node->left);
            cout << node->data << endl;
            inorderHelper(node->right);
        }
    }

    Restaurant *searchHelper(BSTNode *node, string name)
    {
        if (!node)
        {
            return nullptr;
        }

        if (name == node->data.name)
        {
            return &(node->data);
        }
        else if (name < node->data.name)
        {
            return searchHelper(node->left, name);
        }
        else
        {
            return searchHelper(node->right, name);
        }
    }

    void destroyTree(BSTNode *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Restaurant r)
    {
        root = insertHelper(root, r);
    }

    void inorderTraversal()
    {
        inorderHelper(root);
    }

    Restaurant *search(string name)
    {
        return searchHelper(root, name);
    }

    ~BST()
    {
        destroyTree(root);
    }
};

struct Edge
{
    int dest;
    int weight;
    string streetName;

    Edge(int d, int w, string name = "") : dest(d), weight(w), streetName(name) {}
};

struct NodeInfo
{
    int id;
    string name;
    string type;

    NodeInfo() : id(0), name(""), type("") {}
    NodeInfo(int i, string n, string t) : id(i), name(n), type(t) {}
};

class Graph
{
private:
    int vertices;
    LinkedList<Edge> *adjList;
    vector<NodeInfo> nodeInfo;

public:
    Graph(int v) : vertices(v)
    {
        adjList = new LinkedList<Edge>[v];
        nodeInfo.resize(v);
    }

    friend class FoodDeliverySimulator;

    void setNodeInfo(int id, string name, string type)
    {
        if (id >= 0 && id < vertices)
        {
            nodeInfo[id] = NodeInfo(id, name, type);
        }
    }

    string getNodeName(int id)
    {
        if (id >= 0 && id < vertices)
        {
            return nodeInfo[id].name;
        }
        return "Unknown";
    }

    void addEdge(int src, int dest, int weight, string streetName = "")
    {
        adjList[src].insert(Edge(dest, weight, streetName));
        adjList[dest].insert(Edge(src, weight, streetName));
    }

    pair<vector<int>, vector<int>> dijkstraWithPath(int source, int destination)
    {
        vector<int> dist(vertices, INF);
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);

        dist[source] = 0;

        for (int count = 0; count < vertices - 1; count++)
        {
            int u = -1;
            int minDist = INF;

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            Node<Edge> *temp = adjList[u].getHead();
            while (temp)
            {
                int v = temp->data.dest;
                int weight = temp->data.weight;

                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
                temp = temp->next;
            }
        }

        return make_pair(dist, parent);
    }

    string getStreetName(int from, int to)
    {
        Node<Edge> *temp = adjList[from].getHead();
        while (temp)
        {
            if (temp->data.dest == to)
            {
                return temp->data.streetName;
            }
            temp = temp->next;
        }
        return "Unknown Street";
    }

    void displayPath(int source, int destination, vector<int> &parent, int totalDistance)
    {
        vector<int> path;
        int current = destination;

        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        int eta = (totalDistance * 60) / 30;

        cout << "\n========== Route Details ==========" << endl;
        cout << "From: " << getNodeName(source) << " (Restaurant)" << endl;
        cout << "To: " << getNodeName(destination) << " (Delivery Point)" << endl;
        cout << "Total Distance: " << totalDistance << " km" << endl;
        cout << "Estimated Time (ETA): " << eta << " minutes" << endl;
        cout << "\nPath:" << endl;

        for (int i = 0; i < path.size(); i++)
        {
            cout << "  " << (i + 1) << ". " << getNodeName(path[i]);
            if (i < path.size() - 1)
            {
                string street = getStreetName(path[i], path[i + 1]);
                int segmentDist = 0;

                Node<Edge> *temp = adjList[path[i]].getHead();
                while (temp)
                {
                    if (temp->data.dest == path[i + 1])
                    {
                        segmentDist = temp->data.weight;
                        break;
                    }
                    temp = temp->next;
                }

                cout << " --> [" << street << ", " << segmentDist << " km] -->";
            }
            cout << endl;
        }
        cout << "===================================" << endl;
    }

    vector<int> dijkstra(int source)
    {
        vector<int> dist(vertices, INF);
        vector<bool> visited(vertices, false);

        dist[source] = 0;

        for (int count = 0; count < vertices - 1; count++)
        {
            int u = -1;
            int minDist = INF;

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            Node<Edge> *temp = adjList[u].getHead();
            while (temp)
            {
                int v = temp->data.dest;
                int weight = temp->data.weight;

                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
                temp = temp->next;
            }
        }

        return dist;
    }

    int getVertices() { return vertices; }

    ~Graph()
    {
        delete[] adjList;
    }
};

struct User
{
    int id;
    string name;
    int nodeId;

    User() : id(0), name(""), nodeId(0) {}
    User(int i, string n, int nid) : id(i), name(n), nodeId(nid) {}

    friend ostream &operator<<(ostream &os, const User &u)
    {
        os << "User ID: " << u.id << ", Name: " << u.name << ", Node: " << u.nodeId;
        return os;
    }
};

struct Agent
{
    int id;
    string name;
    int nodeId;
    bool available;

    Agent() : id(0), name(""), nodeId(0), available(true) {}
    Agent(int i, string n, int nid) : id(i), name(n), nodeId(nid), available(true) {}

    friend ostream &operator<<(ostream &os, const Agent &a)
    {
        os << "Agent ID: " << a.id << ", Name: " << a.name
           << ", Node: " << a.nodeId << ", Status: " << (a.available ? "Available" : "Busy");
        return os;
    }
};

struct Order
{
    int orderId;
    int userId;
    int restaurantId;
    int agentId;
    int priority;
    string status;

    Order() : orderId(0), userId(0), restaurantId(0), agentId(-1), priority(0), status("Pending") {}
    Order(int oid, int uid, int rid, int p)
        : orderId(oid), userId(uid), restaurantId(rid), agentId(-1), priority(p), status("Pending") {}

    friend ostream &operator<<(ostream &os, const Order &o)
    {
        os << "Order ID: " << o.orderId << ", User: " << o.userId
           << ", Restaurant: " << o.restaurantId << ", Agent: " << o.agentId
           << ", Priority: " << o.priority << ", Status: " << o.status;
        return os;
    }
};

struct Assignment
{
    int orderId;
    int agentId;

    Assignment() : orderId(0), agentId(0) {}
    Assignment(int oid, int aid) : orderId(oid), agentId(aid) {}
};

class FoodDeliverySimulator
{
private:
    Graph *graph;
    LinkedList<User> users;
    LinkedList<Agent> agents;
    BST restaurants;
    LinkedList<Order> orderHistory;
    PriorityQueue<Order> urgentOrders;
    Queue<Order> backlogOrders;
    Stack<Assignment> assignmentHistory;

    int nextOrderId;
    int nextUserId;
    int numNodes;

public:
    FoodDeliverySimulator() : graph(nullptr), nextOrderId(1), nextUserId(1), numNodes(0)
    {
        loadGraph("nodes.csv", "edges.csv");
        loadRestaurants("restaurants.csv");
        clearUsersFile();
        loadAgents("agents.csv");
        loadOrderHistory("orders.csv");
    }

    ~FoodDeliverySimulator()
    {
        saveOrderHistory("orders.csv");
        if (graph)
        {
            delete graph;
        }
    }

    void loadGraph(string nodesFile, string edgesFile)
    {
        ifstream nodeIn(nodesFile);
        if (!nodeIn)
        {
            cout << "Error: Could not open nodes file: " << nodesFile << endl;
            return;
        }

        string line;
        getline(nodeIn, line);

        numNodes = 0;
        vector<string> nodeNames;
        vector<string> nodeTypes;

        while (getline(nodeIn, line))
        {
            stringstream ss(line);
            string id, name, type;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, type, ',');

            nodeNames.push_back(name);
            nodeTypes.push_back(type);
            numNodes++;
        }
        nodeIn.close();

        graph = new Graph(numNodes);

        for (int i = 0; i < numNodes; i++)
        {
            graph->setNodeInfo(i, nodeNames[i], nodeTypes[i]);
        }

        ifstream edgeIn(edgesFile);
        if (!edgeIn)
        {
            cout << "Error: Could not open edges file: " << edgesFile << endl;
            return;
        }

        getline(edgeIn, line);

        while (getline(edgeIn, line))
        {
            stringstream ss(line);
            string src, dest, weight, streetName;

            getline(ss, src, ',');
            getline(ss, dest, ',');
            getline(ss, weight, ',');
            getline(ss, streetName, ',');

            graph->addEdge(stoi(src), stoi(dest), stoi(weight), streetName);
        }
        edgeIn.close();

        cout << "Graph loaded successfully with " << numNodes << " nodes." << endl;
    }

    void loadRestaurants(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Error: Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, nodeId;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, nodeId, ',');

            Restaurant r(stoi(id), name, stoi(nodeId));
            restaurants.insert(r);
        }
        file.close();

        cout << "Restaurants loaded successfully." << endl;
    }

    void clearUsersFile()
    {
        ofstream file("users.csv", ios::trunc);
        if (file)
        {
            file << "id,name,nodeId\n";
            file.close();
            cout << "Users file cleared successfully." << endl;
        }
        else
        {
            cout << "Error: Could not clear users file." << endl;
        }
    }

    void loadUsers(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Error: Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, nodeId;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, nodeId, ',');

            users.insert(User(stoi(id), name, stoi(nodeId)));
        }
        file.close();

        cout << "Users loaded successfully." << endl;
    }

    int addUser(string name, int nodeId)
    {
        int userId = nextUserId++;
        User newUser(userId, name, nodeId);
        users.insert(newUser);

        ofstream file("users.csv", ios::app);
        if (file)
        {
            file << userId << "," << name << "," << nodeId << "\n";
            file.close();
        }
        else
        {
            cout << "Error: Could not save user to file." << endl;
        }

        return userId;
    }

    void loadAgents(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Error: Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, nodeId;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, nodeId, ',');

            agents.insert(Agent(stoi(id), name, stoi(nodeId)));
        }
        file.close();

        cout << "Agents loaded successfully." << endl;
    }

    void loadOrderHistory(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string orderId, userId, restaurantId, agentId, priority, status;

            getline(ss, orderId, ',');
            getline(ss, userId, ',');
            getline(ss, restaurantId, ',');
            getline(ss, agentId, ',');
            getline(ss, priority, ',');
            getline(ss, status, ',');

            Order order;
            order.orderId = stoi(orderId);
            order.userId = stoi(userId);
            order.restaurantId = stoi(restaurantId);
            order.agentId = stoi(agentId);
            order.priority = stoi(priority);
            order.status = status;

            orderHistory.insert(order);

            if (order.orderId >= nextOrderId)
            {
                nextOrderId = order.orderId + 1;
            }
        }
        file.close();
    }

    void saveOrderHistory(string filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Error: Could not save order history to " << filename << endl;
            return;
        }

        file << "orderId,userId,restaurantId,agentId,priority,status" << endl;

        Node<Order> *temp = orderHistory.getHead();
        while (temp)
        {
            file << temp->data.orderId << ","
                 << temp->data.userId << ","
                 << temp->data.restaurantId << ","
                 << temp->data.agentId << ","
                 << temp->data.priority << ","
                 << temp->data.status << endl;
            temp = temp->next;
        }
        file.close();
    }

    void displayRestaurants()
    {
        cout << "\n========== All Restaurants ==========" << endl;
        restaurants.inorderTraversal();
        cout << "=====================================" << endl;
    }

    void displayUsers()
    {
        cout << "\n========== All Users ==========" << endl;
        users.display();
        cout << "===============================" << endl;
    }

    void displayAgents()
    {
        cout << "\n========== All Agents ==========" << endl;
        agents.display();
        cout << "================================" << endl;
    }

    void createOrder()
    {
        string userName;
        int nodeId, restaurantId, priority;

        cout << "\n========== Create New Order ==========" << endl;

        cout << "\nAvailable Delivery Points in Karachi:" << endl;
        cout << "  1. Clifton Block 2" << endl;
        cout << "  3. Gulshan-e-Iqbal" << endl;
        cout << "  5. DHA Phase 5" << endl;
        cout << "  7. Bahria Town" << endl;
        cout << "  8. North Nazimabad" << endl;

        cout << "\nEnter your name: ";
        cin.ignore();
        getline(cin, userName);

        cout << "Select delivery point (1, 3, 5, 7, or 8): ";
        cin >> nodeId;

        if (nodeId != 1 && nodeId != 3 && nodeId != 5 && nodeId != 7 && nodeId != 8)
        {
            cout << "\nError: Invalid delivery point! Please select from the available options." << endl;
            return;
        }

        int userId = addUser(userName, nodeId);
        cout << "\nUser created successfully!" << endl;
        cout << "User ID: " << userId << endl;
        cout << "Delivery Location: " << graph->getNodeName(nodeId) << endl;

        cout << "\nAvailable Restaurants in Karachi:" << endl;
        displayRestaurants();

        cout << "\nEnter Restaurant ID (1-5): ";
        cin >> restaurantId;

        if (restaurantId < 1 || restaurantId > 5)
        {
            cout << "\nError: Invalid restaurant ID! Must be between 1 and 5." << endl;
            return;
        }

        cout << "Enter Priority (1-10, >=5 is urgent): ";
        cin >> priority;

        Order order(nextOrderId++, userId, restaurantId, priority);

        if (priority >= 5)
        {
            urgentOrders.enqueue(order, priority);
            cout << "\nUrgent order created and added to priority queue." << endl;
        }
        else
        {
            backlogOrders.enqueue(order);
            cout << "\nRegular order created and added to backlog queue." << endl;
        }

        cout << order << endl;
    }

    Agent *findNearestAgent(int restaurantNode)
    {
        if (!graph)
        {
            cout << "Graph not loaded!" << endl;
            return nullptr;
        }

        vector<int> distances = graph->dijkstra(restaurantNode);

        Agent *nearestAgent = nullptr;
        int minDist = INF;

        Node<Agent> *temp = agents.getHead();
        while (temp)
        {
            if (temp->data.available && distances[temp->data.nodeId] < minDist)
            {
                minDist = distances[temp->data.nodeId];
                nearestAgent = &(temp->data);
            }
            temp = temp->next;
        }

        return nearestAgent;
    }

    void dispatchOrders()
    {
        if (!graph)
        {
            cout << "Graph not loaded! Cannot dispatch orders." << endl;
            return;
        }

        int dispatched = 0;

        while (!urgentOrders.isEmpty())
        {
            Order order = urgentOrders.dequeue();

            User *user = users.find(order.userId);
            if (!user)
            {
                cout << "User not found for order " << order.orderId << endl;
                continue;
            }

            int restaurantNode = order.restaurantId - 1;

            Agent *agent = findNearestAgent(restaurantNode);

            if (agent)
            {
                order.agentId = agent->id;
                order.status = "Assigned";
                agent->available = false;

                auto result = graph->dijkstraWithPath(restaurantNode, user->nodeId);
                vector<int> distances = result.first;
                vector<int> parent = result.second;
                int distance = distances[user->nodeId];
                int eta = (distance * 60) / 30;

                cout << "\n============================================" << endl;
                cout << "     ORDER DISPATCHED SUCCESSFULLY!        " << endl;
                cout << "============================================" << endl;

                cout << "\n[URGENT ORDER #" << order.orderId << "]" << endl;
                cout << "Customer: " << user->name << endl;
                cout << "Restaurant: " << graph->getNodeName(restaurantNode) << endl;
                cout << "Agent: " << agent->name << endl;
                cout << "Distance: " << distance << " km" << endl;
                cout << "ETA: " << eta << " minutes" << endl;

                graph->displayPath(restaurantNode, user->nodeId, parent, distance);

                orderHistory.insert(order);
                assignmentHistory.push(Assignment(order.orderId, agent->id));
                dispatched++;
            }
            else
            {
                cout << "\nNo agent available for urgent order " << order.orderId
                     << ". Moving to backlog." << endl;
                backlogOrders.enqueue(order);
            }
        }

        int backlogProcessed = 0;
        Queue<Order> tempQueue;

        while (!backlogOrders.isEmpty() && backlogProcessed < 5)
        {
            Order order = backlogOrders.dequeue();

            User *user = users.find(order.userId);
            if (!user)
            {
                cout << "User not found for order " << order.orderId << endl;
                continue;
            }

            int restaurantNode = order.restaurantId - 1;
            Agent *agent = findNearestAgent(restaurantNode);

            if (agent)
            {
                order.agentId = agent->id;
                order.status = "Assigned";
                agent->available = false;

                auto result = graph->dijkstraWithPath(restaurantNode, user->nodeId);
                vector<int> distances = result.first;
                vector<int> parent = result.second;
                int distance = distances[user->nodeId];
                int eta = (distance * 60) / 30;

                cout << "\n============================================" << endl;
                cout << "     ORDER DISPATCHED SUCCESSFULLY!        " << endl;
                cout << "============================================" << endl;

                cout << "\n[BACKLOG ORDER #" << order.orderId << "]" << endl;
                cout << "Customer: " << user->name << endl;
                cout << "Restaurant: " << graph->getNodeName(restaurantNode) << endl;
                cout << "Agent: " << agent->name << endl;
                cout << "Distance: " << distance << " km" << endl;
                cout << "ETA: " << eta << " minutes" << endl;

                graph->displayPath(restaurantNode, user->nodeId, parent, distance);

                orderHistory.insert(order);
                assignmentHistory.push(Assignment(order.orderId, agent->id));
                dispatched++;
                backlogProcessed++;
            }
            else
            {
                tempQueue.enqueue(order);
            }
        }

        while (!backlogOrders.isEmpty())
        {
            tempQueue.enqueue(backlogOrders.dequeue());
        }
        while (!tempQueue.isEmpty())
        {
            backlogOrders.enqueue(tempQueue.dequeue());
        }

        if (dispatched > 0)
        {
            cout << "\n>> " << dispatched << " order(s) dispatched successfully!" << endl;
            saveOrderHistory("orders.csv");
        }
        else
        {
            cout << "\nNo orders dispatched. No available agents or no pending orders." << endl;
        }
    }

    void undoLastAssignment()
    {
        if (assignmentHistory.isEmpty())
        {
            cout << "\nNo assignments to undo." << endl;
            return;
        }

        Assignment lastAssignment = assignmentHistory.pop();

        Agent *agent = agents.find(lastAssignment.agentId);
        if (agent)
        {
            agent->available = true;
            cout << "\nUndo successful! Agent " << agent->name << " is now available." << endl;
            cout << "Order " << lastAssignment.orderId << " assignment reverted." << endl;
        }
        else
        {
            cout << "\nAgent not found for undo operation." << endl;
        }
    }

    void displayOrderHistory()
    {
        cout << "\n========== Order History ==========" << endl;
        if (orderHistory.getSize() == 0)
        {
            cout << "No orders in history." << endl;
        }
        else
        {
            orderHistory.display();
        }
        cout << "===================================" << endl;
    }

    void displayPendingOrders()
    {
        cout << "\n========== Pending Orders ==========" << endl;
        cout << "Urgent orders in queue: " << urgentOrders.getSize() << endl;
        cout << "Backlog orders in queue: " << backlogOrders.getSize() << endl;
        cout << "====================================" << endl;
    }

    void displayNetworkMap()
    {
        if (!graph)
        {
            cout << "Graph not loaded!" << endl;
            return;
        }

        cout << "\n============================================" << endl;
        cout << "      KARACHI DELIVERY NETWORK MAP         " << endl;
        cout << "============================================" << endl;

        cout << "\n--- RESTAURANTS ---" << endl;
        cout << "  [0] Burns Road Food Street" << endl;
        cout << "  [2] Boat Basin Cafe" << endl;
        cout << "  [4] Saddar Tikka House" << endl;
        cout << "  [6] Tariq Road Broast" << endl;
        cout << "  [9] Zamzama BBQ Tonight" << endl;

        cout << "\n--- DELIVERY POINTS ---" << endl;
        cout << "  [1] Clifton Block 2" << endl;
        cout << "  [3] Gulshan-e-Iqbal" << endl;
        cout << "  [5] DHA Phase 5" << endl;
        cout << "  [7] Bahria Town" << endl;
        cout << "  [8] North Nazimabad" << endl;

        cout << "\n============================================" << endl;
        cout << "          KARACHI NETWORK GRAPH             " << endl;
        cout << "============================================" << endl;
        cout << "Legend: [R] = Restaurant, [D] = Delivery Point" << endl;
        cout << endl;
        cout << "                    [0][R] Burns Road Food Street" << endl;
        cout << "                     |  \\                    \\" << endl;
        cout << "         (8km)       |   \\                    \\ (10km)" << endl;
        cout << "    Shahrah-e-Faisal |    \\ MA Jinnah Rd       \\ Clifton Bridge" << endl;
        cout << "                     |     \\ (6km)              \\" << endl;
        cout << "                     |      \\                    \\" << endl;
        cout << "                     v       v                     v" << endl;
        cout << "          [1][D] Clifton  [4][R] Saddar  [2][R] Boat Basin" << endl;
        cout << "              |   \\          |              |" << endl;
        cout << "              |    \\         |              |" << endl;
        cout << "    (8km)     |     \\        | (9km)        | (7km)" << endl;
        cout << "  Korangi Rd  |      \\       | Sharae       | University Rd" << endl;
        cout << "              |       \\      | Quaideen     |" << endl;
        cout << "              |    (5km)      |              |" << endl;
        cout << "              |  Khayaban     |              |" << endl;
        cout << "              |  Shamsheer    |              |" << endl;
        cout << "              v       \\      v              v" << endl;
        cout << "        [5][D] DHA      >--[2][R]    [3][D] Gulshan-e-Iqbal" << endl;
        cout << "           |   \\                           |    \\" << endl;
        cout << "           |    \\                          |     \\" << endl;
        cout << "      (6km)|     \\(12km)             (4km) |      \\ (6km)" << endl;
        cout << "    Tariq  |      \\Sunset            Rashid|       \\ Jail" << endl;
        cout << "      Rd   |       \\Blvd             Minhas|        \\ Chowrangi" << endl;
        cout << "           |        \\                  Rd  |         \\" << endl;
        cout << "           v         \\                     v          v" << endl;
        cout << "      [6][R] Tariq Road <---------------[4][R]  [6][R] (same)" << endl;
        cout << "           |                                " << endl;
        cout << "           |" << endl;
        cout << "           | (11km) Super Highway" << endl;
        cout << "           |" << endl;
        cout << "           v" << endl;
        cout << "      [7][D] Bahria Town" << endl;
        cout << "           |" << endl;
        cout << "           | (5km) Abul Hasan Isphani Rd" << endl;
        cout << "           |" << endl;
        cout << "           v" << endl;
        cout << "      [8][D] North Nazimabad" << endl;
        cout << "           |" << endl;
        cout << "           | (7km) Nishtar Rd" << endl;
        cout << "           |" << endl;
        cout << "           v" << endl;
        cout << "      [9][R] Zamzama BBQ Tonight" << endl;
        cout << endl;

        cout << "\n--- STREET CONNECTIONS TABLE ---" << endl;
        cout << "------------------------------------------------" << endl;

        bool displayed[10][10] = {false};
        for (int i = 0; i < numNodes; i++)
        {
            Node<Edge> *temp = graph->adjList[i].getHead();
            while (temp)
            {
                int j = temp->data.dest;
                if (!displayed[i][j] && !displayed[j][i])
                {
                    cout << "[" << i << "] " << graph->getNodeName(i);
                    int padding = 25 - graph->getNodeName(i).length();
                    for (int p = 0; p < padding; p++)
                        cout << " ";
                    cout << " <---> [" << j << "] " << graph->getNodeName(j) << endl;
                    cout << "     via " << temp->data.streetName << " (" << temp->data.weight << " km)" << endl;
                    cout << endl;
                    displayed[i][j] = displayed[j][i] = true;
                }
                temp = temp->next;
            }
        }
        cout << "================================================" << endl;
    }
};

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForBack()
{
    cout << "\n\nPress Enter to go back to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayMenu()
{
    clearScreen();
    cout << "\n";
    cout << "============================================" << endl;
    cout << "   MINI FOOD-DELIVERY SIMULATOR" << endl;
    cout << "============================================" << endl;
    cout << "1. View Network Map" << endl;
    cout << "2. Display All Restaurants" << endl;
    cout << "3. Display All Users" << endl;
    cout << "4. Display All Agents" << endl;
    cout << "5. Create New Order" << endl;
    cout << "6. Dispatch Orders" << endl;
    cout << "7. Undo Last Assignment" << endl;
    cout << "8. Display Order History" << endl;
    cout << "9. Display Pending Orders" << endl;
    cout << "0. Exit" << endl;
    cout << "============================================" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    FoodDeliverySimulator simulator;
    int choice;

    clearScreen();
    cout << "Mini Food-Delivery Simulator ***" << endl;

    while (true)
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
            cout << "\nInvalid input! Please enter a number." << endl;
            waitForBack();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clearScreen();

        switch (choice)
        {
        case 1:
            simulator.displayNetworkMap();
            waitForBack();
            break;
        case 2:
            simulator.displayRestaurants();
            waitForBack();
            break;
        case 3:
            simulator.displayUsers();
            waitForBack();
            break;
        case 4:
            simulator.displayAgents();
            waitForBack();
            break;
        case 5:
            simulator.createOrder();
            waitForBack();
            break;
        case 6:
            simulator.dispatchOrders();
            waitForBack();
            break;
        case 7:
            simulator.undoLastAssignment();
            waitForBack();
            break;
        case 8:
            simulator.displayOrderHistory();
            waitForBack();
            break;
        case 9:
            simulator.displayPendingOrders();
            waitForBack();
            break;
        case 0:
            clearScreen();
            cout << "\nThank you for using the Food Delivery Simulator!" << endl;
            return 0;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
            waitForBack();
        }
    }

    return 0;
}
