#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class SocialNetwork {
private:
    unordered_map<string, unordered_set<string>> graph;

public:
    void addUser(const string& username) {
        graph[username]; // Ensures user is added
        cout << "User '" << username << "' added.\n";
    }

    void addFriendship(const string& user1, const string& user2) {
        if (graph.count(user1) == 0 || graph.count(user2) == 0) {
            cout << "Both users must exist in the network.\n";
            return;
        }
        if (user1 == user2) {
            cout << "A user cannot befriend themselves.\n";
            return;
        }
        graph[user1].insert(user2);
        graph[user2].insert(user1);
        cout << "Friendship added between " << user1 << " and " << user2 << ".\n";
    }

    void showNetwork() const {
        cout << "\nCurrent Social Network:\n";
        for (const auto& [user, friends] : graph) {
            cout << "- " << user << " → ";
            if (friends.empty()) {
                cout << "(no friends)";
            } else {
                for (const auto& f : friends) {
                    cout << f << " ";
                }
            }
            cout << "\n";
        }
    }

    void suggestFriends(const string& username) {
        if (graph.count(username) == 0) {
            cout << "User '" << username << "' does not exist.\n";
            return;
        }

        unordered_set<string> visited;
        queue<string> q;
        unordered_map<string, int> mutualCount;
        vector<string> suggestions;

        visited.insert(username);
        q.push(username);

        int level = 0;

        while (!q.empty() && level < 2) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                for (const auto& neighbor : graph[curr]) {
                    if (!visited.count(neighbor)) {
                        if (level == 1 && !graph[username].count(neighbor)) {
                            mutualCount[neighbor]++;
                        }
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            level++;
        }

        cout << "\nFriend Suggestions for " << username << ":\n";
        if (mutualCount.empty()) {
            cout << "No suggestions available.\n";
        } else {
            for (const auto& [user, count] : mutualCount) {
                cout << "- " << user << " (Mutual friends: " << count << ")\n";
            }
        }
    }
};

void showMenu() {
    cout << "\n========== Social Network Menu ==========\n";
    cout << "1. Add User\n";
    cout << "2. Add Friendship\n";
    cout << "3. Show Social Network\n";
    cout << "4. Suggest Friends\n";
    cout << "5. Exit\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    SocialNetwork sn;
    int choice;
    string user1, user2;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> user1;
                sn.addUser(user1);
                break;

            case 2:
                cout << "Enter first username: ";
                cin >> user1;
                cout << "Enter second username: ";
                cin >> user2;
                sn.addFriendship(user1, user2);
                break;

            case 3:
                sn.showNetwork();
                break;

            case 4:
                cout << "Enter username to get suggestions: ";
                cin >> user1;
                sn.suggestFriends(user1);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
