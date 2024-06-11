//ToDoList

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ToDoList {
    int id;
    string task;
};

int ID = 0;
void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();

int main() {
    while (true) {
        banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Task";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t6. Exit";
        cout << "\nEnter Your Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTask();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

void banner() {
    cout << "________________________________" << endl;
    cout << "\t   My ToDo" << endl;
    cout << "_________________________________" << endl;
}

void addTask() {
    system("cls");
    banner();
    ToDoList todo;
    cout << "Enter New Task: " << endl;
    cin.ignore();
    getline(cin, todo.task);

    char save;
    cout << "Save? (Y/N): ";
    cin >> save;

    if (save == 'y' || save == 'Y') {
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << ID << endl;
        fout << todo.task << endl;
        fout.close();

        char more;
        cout << "Add more tasks? (Y/N): ";
        cin >> more;

        if (more == 'y' || more == 'Y') {
            addTask();
        } else {
            system("cls");
            cout << "Added Successfully!" << endl;
            return;
        }
    }
    system("cls");
}

void showTask() {
    system("cls");
    banner();
    ToDoList todo;
    ifstream fin;
    fin.open("todo.txt");

    cout << "Tasks: " << endl;

    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (!todo.task.empty()) {
            cout << "\t" << todo.id << ": " << todo.task << endl;
        }
    }

    fin.close();
    char exit;
    cout << "Exit? (Y/N): ";
    cin >> exit;

    if (exit != 'y' && exit != 'Y') {
        showTask();
    }
    system("cls");
}

int searchTask() {
    system("cls");
    banner();
    int id;
    cout << "Enter Task ID: ";
    cin >> id;
    ToDoList todo;
    ifstream fin;
    fin.open("todo.txt");

    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls");
            cout << "\t" << todo.id << ": " << todo.task << endl;
            fin.close();
            return id;
        }
    }
    fin.close();
    system("cls");
    cout << "Not Found!" << endl;
    return 0;
}

void deleteTask() {
    system("cls");
    int id = searchTask();

    if (id != 0) {
        char del;
        cout << "\n\tDelete? (Y/N): ";
        cin >> del;

        if (del == 'y' || del == 'Y') {
            ToDoList todo;
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");

            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) {
                    tempFile << todo.id << endl;
                    tempFile << todo.task << endl;
                }
            }

            fin.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout << "\n\tDeleted Successfully!" << endl;
        } else {
            system("cls");
            cout << "Not Deleted!" << endl;
        }
    }
}

