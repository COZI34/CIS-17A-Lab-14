// David Duong
#include <iostream>

using namespace std;

// Function Prototypes
void add_name(char* name, int length);
void print_name(const char* name, int length);
void find_char(const char* name, int length);

int main() {
    char* name = NULL;
    int length = 0;
    int choice;

    do {
		// menu for user to select from
        cout << "Please select from the following choices:\n";
        cout << "1) Enter a new name\n";
        cout << "2) Print last name entered\n";
        cout << "3) Search for character in name\n";
        cout << "4) Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // delete old array if one already exists
            if (name != NULL) {
                delete[] name;
            }
			// get length of name from user
            cout << "\nHow many letters are in this name: ";
            cin >> length;

			// create a dynamic array to hold the name
            name = new char[length];

            // call function to fill array
            add_name(name, length);

            break;

        case 2:
            print_name(name, length);
            break;

        case 3:
            find_char(name, length);
            break;

        case 4:
            cout << "\nExiting Program\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

	} while (choice != 4); // loop until user chooses to exit

	// delete dynamic array before exiting program to prevent memory leak
    if (name != NULL) {
        delete[] name;
    }

	system("pause");
    return 0;
}

// function to enter name
void add_name(char* name, int length) {
	// fill array with user input
    for (int i = 0; i < length; i++) {
        cout << "Enter letter " << i + 1 << ": ";
        cin >> name[i];
    }
}

// function to print name
void print_name(const char* name, int length) {
    if (name == NULL) {
        cout << "No name has been entered.\n";
        return;
    }
	// Print name by looping through array
    for (int i = 0; i < length; i++) {
        cout << name[i];
    }
    cout << endl;
}

// function to search for character
void find_char(const char* name, int length) {
	// Check if name has been entered
    if (name == NULL) {
        cout << "No name has been entered yet.\n";
        return;
    }
	// get character to search for from user
    char search;
    bool found = false;

    cout << "\nEnter the character you would like to search for in the current name: ";
    cin >> search;
	// Search for character in name
    for (int i = 0; i < length; i++) {
        if (name[i] == search) {
            cout << "Character \"" << search
                << "\" found at position "
                << i + 1 << endl;

            found = true;
        }
    }
	// check if character was found
    if (!found) {
        cout << "Character not found in name.\n";
    }
}
