#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

vector<Task> todoList;

void addTask() {
    string taskDesc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, taskDesc);
    todoList.push_back({taskDesc, false});
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". [" << (todoList[i].isCompleted ? "✔" : " ") << "] " << todoList[i].description << "\n";
    }
    cout << endl;
}

void markCompleted() {
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number!\n";
    } else {
        todoList[index - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask() {
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number!\n";
    } else {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
}

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "-------------------\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid option! Please choose again.\n";
        }

    } while (choice != 5);

    return 0;
}
