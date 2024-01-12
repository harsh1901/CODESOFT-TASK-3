#include <iostream>
#include <vector>

using namespace std;

// Function to display the to-do list
void displayList(const vector<string>& todoList) 
{
    if (todoList.empty()) 
    {
        cout << "To-Do List is empty." << endl;
    } 
    else 
    {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < todoList.size(); ++i) 
        {
            cout << i + 1 << ". " << todoList[i] << endl;
        }
    }
    cout << endl;
}

// Function to add a task to the to-do list
void addTask(vector<string>& todoList) 
{
    string task;
    cout << "Enter the task:\n ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, task);
    todoList.push_back(task);
    cout << "Task added successfully!" << endl;
}

// Function to delete a task from the to-do list
void deleteTask(vector<string>& todoList) {
    if (todoList.empty()) {
        cout << "To-Do List is already empty." << endl;
    } else {
        displayList(todoList);
        int index;
        cout << "Enter the task number to delete: ";
        cin >> index;

        if (index >= 1 && static_cast<size_t>(index) <= todoList.size()) {
            todoList.erase(todoList.begin() + index - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }
}

int main() 
{
    vector<string> todoList;
    int choice;

    do {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task:\n" << endl;
        cout << "2. View Tasks:\n" << endl;
        cout << "3. Delete Task:\n" << endl;
        cout << "4. Exit :\n" << endl;
        cout << "Enter your choice:\n ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addTask(todoList);
                break;
            case 2:
                displayList(todoList);
                break;
            case 3:
                deleteTask(todoList);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
