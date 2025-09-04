#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(string desc) {
    tasks.push_back({desc, false});
    cout << "Task added successfully!\n";
}

void viewTasks() {
    cout << "\n--- To-Do List ---\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    string desc;
    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                addTask(desc);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                int num;
                cout << "Enter task number to mark completed: ";
                cin >> num;
                markTaskCompleted(num-1);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> num;
                removeTask(num-1);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);
}
