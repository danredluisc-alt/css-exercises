#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the main menu
void showMenu() {
    cout << "\n=========================\n";
    cout << "      TO-DO LIST\n";
    cout << "=========================\n";
    cout << "1. Add a Task\n";
    cout << "2. View All Tasks\n";
    cout << "3. Delete a Task\n";
    cout << "4. Exit Program\n";
    cout << "-------------------------\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<string> todoList; // Dynamic array to store tasks
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        // Fixes input issues if a user types letters instead of a number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n[!] Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        // 1. ADD TASK
        if (choice == 1) {
            string newTask;
            cout << "\nEnter the task name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, newTask); // Allows spaces in task name
            todoList.push_back(newTask);
            cout << "[+] Task added successfully!\n";
        }
        // 2. VIEW TASKS
        else if (choice == 2) {
            if (todoList.empty()) {
                cout << "\n[-] Your To-Do List is empty!\n";
            } else {
                cout << "\n--- CURRENT TASKS ---\n";
                for (size_t i = 0; i < todoList.size(); ++i) {
                    cout << i + 1 << ". " << todoList[i] << "\n";
                }
            }
        }
        // 3. DELETE TASK
        else if (choice == 3) {
            if (todoList.empty()) {
                cout << "\n[-] Nothing to delete. Your list is empty!\n";
            } else {
                int taskNumber;
                cout << "\nEnter the number of the task to delete: ";
                cin >> taskNumber;

                // Validate task number bounds
                if (taskNumber > 0 && taskNumber <= static_cast<int>(todoList.size())) {
                    todoList.erase(todoList.begin() + (taskNumber - 1));
                    cout << "[-] Task deleted successfully!\n";
                } else {
                    cout << "[!] Invalid task number.\n";
                }
            }
        }
        // 4. EXIT
        else if (choice == 4) {
            cout << "\nGoodbye! Have a productive day.\n";
            break;
        }
        // INVALID MENU SELECTION
        else {
            cout << "\n[!] Invalid option. Please choose 1, 2, 3, or 4.\n";
        }
    }

    return 0;
}

