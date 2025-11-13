// Description:
//  This file contains the main entry point for the console-based
//  restaurant kitchen simulation. The main program provides an
//  interactive menu that allows the kitchen manager to perform
//   all system operations, including adding new orders, starting
//   food preparation, completing orders, and serving finished
//  meals.
// created by Jovhems Jean-Baptiste 11/7/25

   


#include <iostream>
#include <string>
#include "KitchenManager.h"

int main() {
    KitchenManager manager;
    int choice;
    std::string desc;
    int typeChoice;
    OrderType type;

    while (true) {
        std::cout << "\n======= Kitchen Management System Menu ======="
                  << "\n1. Add New Order"
                  << "\n2. Start Preparing Next Order"
                  << "\n3. Mark Order as Complete"
                  << "\n4. Serve/Pickup Order"
                  << "\n5. View Prep Queue"
                  << "\n6. View Completed Stack"
                  << "\n7. Exit"
                  << "\nEnter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter order description: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, desc);
                std::cout << "Enter order type (1 for Dine-In, 2 for Takeout): ";
                std::cin >> typeChoice;
                type = (typeChoice == 1) ? OrderType::DineIn : OrderType::Takeout;
                manager.addNewOrder(desc, type);
                break;

            case 2:
                manager.startPreparingNextOrder();
                break;

            case 3:
                manager.markOrderAsComplete();
                break;

            case 4:
                manager.servePickupOrder();
                break;

            case 5:
                manager.viewPrepQueue();
                break;

            case 6:
                manager.viewCompletedStack();
                break;

            case 7:
                std::cout << "Exiting system.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
