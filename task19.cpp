#include <iostream>
#include "G.h"

int main() {
    Group* group = nullptr;

    int choice;

    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Create group\n";
        std::cout << "2. Add student\n";
        std::cout << "3. Delete student\n";
        std::cout << "4. Show students\n";
        std::cout << "0. Exit\n";
        std::cout << "Your choice: ";

        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice) {

        case 1: {
            delete group;
            group = new Group();

            char name[100];

            std::cout << "Enter group name: ";
            std::cin.getline(name, 100);

            group->setGroupName(name);

            std::cout << "Group created\n";
            break;
        }

        case 2:
            if (group != nullptr) {
                group->addStudent();
            }
            else {
                std::cout << "Create a group first\n";
            }
            break;

        case 3:
            if (group != nullptr) {
                int index;

                std::cout << "Enter student number: ";
                std::cin >> index;
                std::cin.ignore(1000, '\n');

                group->deleteStudent(index - 1);
            }
            else {
                std::cout << "Create a group first\n";
            }
            break;

        case 4:
            if (group != nullptr) {
                group->showStudents();
            }
            else {
                std::cout << "Create a group first\n";
            }
            break;

        case 0:
            std::cout << "Goodbye\n";
            break;

        default:
            std::cout << "Wrong choice\n";
        }

    } while (choice != 0);

    delete group;

    return 0;
}

