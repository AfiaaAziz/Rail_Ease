#include <iostream>
#include <stdexcept>
#include "User.h"
#include "Admin.h"
#include "TrainManager.h"
#include "TicketManager.h"

using namespace std;

int main()
{
    TrainManager* trainManager = new TrainManager();    // Create a single instance of TrainManager
    TicketManager* ticketManager = new TicketManager(); // Create a single instance of TicketManager

    int choice;
    do
    {
        cout << "\n\t\t\t*********************** Welcome to Train Ticket Management System ***********************\n";
        cout << "\t\t\t\t\t\t\t1. User Panel\n";
        cout << "\t\t\t\t\t\t\t2. Admin Panel\n";
        cout << "\t\t\t\t\t\t\t3. Exit\n";
        cout << "\t\t\t\t\t\t\tEnter your choice: ";

        try
        {
            if (!(cin >> choice)) // Check if the input is valid
            {
                throw invalid_argument("Invalid input. Please enter a number.");
            }

            switch (choice)
            {
            case 1:
                showUserOptions(trainManager, ticketManager); // Pass the TrainManager instance
                break;
            case 2:
                adminPanel(trainManager); // Pass the TrainManager instance
                break;
            case 3:
                cout << "\n\t\t\t*********************** Thank you for using the system. Goodbye! ***********************\n";
                break;
            default:
                cout << "\t\t\t\t\t\t\tInvalid choice. Please try again.\n";
            }
        }
        catch (const invalid_argument& e)
        {
            cout << "\t\t\t\t\t\t\t" << e.what() << "\n";
            cin.clear();                // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }

    } while (choice != 3);

    delete trainManager;  // Clean up
    delete ticketManager; // Clean up
    return 0;
}
