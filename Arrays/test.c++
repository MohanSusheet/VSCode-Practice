#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;    

    cout << "Enter your name: ";
    cin >> name; // If you want full name with spaces, use getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
    system("pause");
    return 0;
}
