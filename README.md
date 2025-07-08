# 👥 Social Network Friend Suggestion System

A C++ program that models a social network and suggests friends using **Breadth-First Search (BFS)** based on mutual connections. The system uses **graph data structures**, follows **OOP principles**, and provides an **interactive CLI menu** for ease of use.

---

## 🚀 Features

- Add users to the social network  
- Create bidirectional friendships between users  
- Display current network with user connections  
- Suggest friends based on mutual connections (via BFS up to 2 levels deep)  
- Efficient graph representation using `unordered_map` and `unordered_set`  
- Menu-driven and interactive CLI interface  

---

## 🛠 Tech Stack

- **Language:** C++  
- **Concepts Used:** OOP, Graphs, BFS, STL (`unordered_map`, `unordered_set`, `queue`, `vector`)

---

## 🖥️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/Raj-Ankit4/social-network-friend-suggestion.git
cd social-network-friend-suggestion

### 📸 Sample Interaction

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

