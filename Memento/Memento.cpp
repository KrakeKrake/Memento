#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

using namespace std;

class Person {
public:
    string name;
    int age;
    string description;
    Person(string name, int year, string description) {
        this->name = name;
        this->age = 2026 - year;
        this->description = description;
    }
    class Memory {
    public:
        string date;
        string title;
        string memory;
        Memory(string date, string title, string memory) {
            this->date = date;
            this->title = title;
            this->memory = memory;
        }
    };

    vector<Memory> memories;
    void create_memory() {
        string date, title, memory;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter todays date: ";
        getline(cin, date);
        cout << endl;
        cout << "Enter a short title of this memory: ";
        getline(cin, title);
        cout << endl;
        cout << "Enter a description of this memory: ";
        getline(cin, memory);
        cout << endl;
        memories.push_back(Memory(date, title, memory));
        cout << "Memory created and stored!" << endl;
    }
    void view_memories() {
        for (int i = 0; i < memories.size(); i++) {
            cout << memories[i].date << " - " << memories[i].title << "\n" << memories[i].memory << endl;
        }
    }
    void view_self() {
        cout << "Name: " << name << "\nAge: " << age << "\nDescription: " << description << endl;
    }


};


int query(int min = 1, int max = 5) {
    int response;
    while (true) {
        cout << "Please enter an option (" << min << " - " << max << "): ";
        cin >> response;
        if (response >= min && response <= max) {
            return response;
        }
        cout << "Invalid input of " << response << ". Please enter a number between " << min << " and " << max << "." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "Hello, World!\n";
    cout << "This program helps you be you if you forget like that movie Memento (or like Dory in Finding Nemo)\n";
    string name;
    int year;
    string desc;
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Please enter your year of birth: ";
    while (true) {
        cin >> year;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number for your year of birth." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    cout << "Please tell me about yourself! Your job, where you live or a special interest: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, desc);
    Person myself(name, year, desc);
    cout << "Hello, " << myself.name << "! You are " << myself.age << " years old.\nAnd you are " << myself.description << "." << endl;
    while (true) {
        cout << "What would you like to do?\n";
        cout << "1. Add a memory\n";
        cout << "2. View memories\n";
        cout << "3. View Self Description\n";
        cout << "4. Exit\n";
        int option = query(1, 4);
        switch (option) {
        case 1:
            cout << "Enter a new memory" << endl;
            myself.create_memory();
            break;
        case 2:
            cout << "View memories" << endl;
            myself.view_memories();
            break;
        case 3:
            cout << "Viewing self description" << endl;
            myself.view_self();
            break;
        case 4:
            cout << "Exiting, I hope you rememember..." << endl;
            return 0;
        }
    }
    return 0;
}
