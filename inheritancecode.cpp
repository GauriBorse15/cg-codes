#include <iostream>
using namespace std;

// Base class 'publication'
class Publication {
protected:
    string name;
    float price;

public:
    Publication() : name("None"), price(0.0) {}

    void getData(const string& itemType) {
        cout << "\nEnter the name of the " << itemType << ": ";
        cin >> name;

        while (true) {
            cout << "\nEnter the price of the " << itemType << ": ";
            cin >> price;
            if (price > 0) break;
            else {
                cout << "\nInvalid price! Price must be greater than 0.";
                price = 0.0; // Reset the invalid price
            }
        }
    }

    string getName() const { return name; }
    float getPrice() const { return price; }
};

// Derived class 'book' inheriting from 'publication'
class Book : public Publication {
private:
    int pages;

public:
    Book() : pages(0) {}

    void getPages() {
        while (true) {
            cout << "\nEnter the number of pages: ";
            cin >> pages;
            if (pages > 0) break;
            else {
                cout << "\nInvalid number of pages! It must be greater than 0.";
                pages = 0; // Reset the invalid number of pages
            }
        }
    }

    void display() const {
        cout << "\nBook Details:";
        cout << "\nName: " << getName();
        cout << "\nPages: " << pages;
        cout << "\nPrice: " << getPrice() << endl;
    }
};

// Derived class 'tape' inheriting from 'publication'
class Tape : public Publication {
private:
    float time; // Playing time in minutes

public:
    Tape() : time(0.0) {}

    void getTime() {
        while (true) {
            cout << "\nEnter the playing time of the tape in minutes: ";
            cin >> time;
            if (time > 0) break;
            else {
                cout << "\nInvalid time! Time must be greater than 0 minutes.";
                time = 0.0; // Reset the invalid time
            }
        }
    }

    void display() const {
        cout << "\nTape Details:";
        cout << "\nName: " << getName();
        cout << "\nPlaying time: " << time << " minutes";
        cout << "\nPrice: " << getPrice() << endl;
    }
};

int main() {
    int choice;
    Book objB;
    Tape objT;

    cout << "\nWelcome to the Inheritance Program\n";
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a Book\n";
        cout << "2. Insert an Audio Cassette\n";
        cout << "3. Display Book Details\n";
        cout << "4. Display Audio Cassette Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                objB.getData("Book");
                objB.getPages();
                cout << "\nBook is being added...\n";
                break;

            case 2:
                objT.getData("Audio Cassette");
                objT.getTime();
                cout << "\nAudio Cassette is being added...\n";
                break;

            case 3:
                if (objB.getName() == "none") {
                    cout << "\nNo book data entered yet.\n";
                } else {
                    objB.display();
                }
                break;

            case 4:
                if (objT.getName() == "none") {
                    cout << "\nNo audio cassette data entered yet.\n";
                } else {
                    objT.display();
                }
                break;

            case 5:
                cout << "\nThank you for using the program. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}