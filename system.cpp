#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int i, j = 0;
    string text, old, first_password, second_password, third_password, pass, name, user, first_word;
    string creds[2], cp[2];

    cout << "Login or Register? " << endl << endl;
    cout << "-------------------" << endl;
    cout << "1. Login           " << endl;
    cout << "2. Register        " << endl;
    cout << "3. Change password " << endl;
    cout << "4. Exit            " << endl;
    cout << "-------------------" << endl << endl;

    do {
        cout << "Enter your choice: ";
        cin >> i;
        switch (i) {
            case 1: {
                j = 0;
                cout << "--------Login-------" << endl;

                ifstream file("database.txt");
                cout << "Enter your username: ";
                cin >> user;
                cout << "Enter your password: ";
                cin >> pass;
                if (file.is_open()) {
                    while (getline(file, text)) {
                        istringstream iss(text);
                        iss >> first_word;
                        creds[j] = first_word;
                        j++;
                    }
                    if (user == creds[0] && pass == creds[1]) {
                        cout << "Welcome, " << creds[0] << "!" << endl;
                    } else {
                        cout << "Wrong username or password!" << endl;
                        cout << "You can choose login or change password options!" << endl;
                    }

                }
                file.close();
                break;
            }

            case 2: {
                cout << "--------Register-------" << endl;
                cout << "Enter your username: ";
                cin >> user;
                cout << "Enter your password: ";
                cin >> first_password;
                cout << "Enter your name: ";
                cin >> name;
                ofstream file;
                file.open("database.txt");
                if (file.is_open()) {
                    file << name << "\n";
                    file << first_password;
                    cout << "You have successfully registered!" << endl;
                }
                file.close();
                break;
            }

            case 3: {
                j = 0;
                cout << "--------Change password-------" << endl;
                ifstream file("database.txt");
                cout << "Enter your username: ";
                cin >> user;
                cout << "Enter your old password: ";
                cin >> old;
                if (file.is_open()) {
                    while (getline(file, text)) {
                        istringstream iss(text);
                        iss >> first_word;
                        cp[j] = first_word;
                        j++;
                    }
                }
                file.close();
                if (old == cp[1]) {
                    cout << "Enter your new password: ";
                    cin >> second_password;
                    cout << "Enter your new password again: ";
                    cin >> third_password;
                    if (second_password == third_password) {
                        cp[1] = third_password;
                        ofstream file("database.txt");
                        if (file.is_open()) {
                            file << cp[0] << "\n";
                            file << cp[1];
                            cout << "You have successfully changed your password!" << endl;
                        }
                        file.close();
                    } else {
                        cout << "Passwords do not match!" << endl;
                    }
                }
                break;
            }

            case 4: {
                cout << "Goodbye!" << endl;
                break;
            }

            default: {
                cout << "Enter your choice!" << endl;
                break;
            }
        }
    } while (i != 4);

    return 0;
}
