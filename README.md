# 👥 Social Network Friend Suggestion System

A C++ program that simulates a social network and suggests friends using **Breadth-First Search (BFS)** based on mutual connections. It uses efficient **graph data structures**, follows **OOP principles**, and provides an **interactive CLI menu**.

---

## 🚀 Features

- Add users to the network
- Create bidirectional friendships
- View all users and their connections
- Suggest friends using mutual connections (BFS up to 2 levels)
- Efficient graph with `unordered_map` and `unordered_set`

---

## 🛠 Tech Stack

- **Language:** C++
- **Concepts:** Graphs, BFS, OOP, STL (map, set, queue, vector)

---

## 📸 Sample Interaction
========== Social Network Menu ==========
1. Add User
2. Add Friendship
3. Show Social Network
4. Suggest Friends
5. Exit
   
=========================================

Enter your choice: 1
Enter username: Alice
User 'Alice' added.

Enter your choice: 1
Enter username: Bob
User 'Bob' added.

Enter your choice: 1
Enter username: Charlie
User 'Charlie' added.

Enter your choice: 1
Enter username: David
User 'David' added.

Enter your choice: 2
Enter first username: Alice
Enter second username: Bob
Friendship added between Alice and Bob.

Enter your choice: 2
Enter first username: Bob
Enter second username: Charlie
Friendship added between Bob and Charlie.

Enter your choice: 2
Enter first username: Charlie
Enter second username: David
Friendship added between Charlie and David.

Enter your choice: 3

Current Social Network:
- Alice → Bob
- Bob → Alice Charlie
- Charlie → Bob David
- David → Charlie

Enter your choice: 4
Enter username to get suggestions: Alice

Friend Suggestions for Alice:
- Charlie (Mutual friends: 1)

Enter your choice: 5
Exiting...

