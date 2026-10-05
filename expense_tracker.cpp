#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Expense {
    int id;
    double amount;
    string category;
    string description;
};

vector<Expense> expenses;

// Add a new expense
void addExpense() {
    Expense expense;

    cout << "\n--- Add Expense ---\n";

    cout << "Enter Expense ID: ";
    while (!(cin >> expense.id) || expense.id <= 0) {
        cout << "Invalid ID. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Amount: ";
    while (!(cin >> expense.amount) || expense.amount <= 0) {
        cout << "Invalid amount. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Category: ";
    getline(cin, expense.category);

    while (expense.category.empty()) {
        cout << "Category cannot be empty. Enter category: ";
        getline(cin, expense.category);
    }

    cout << "Enter Description: ";
    getline(cin, expense.description);

    while (expense.description.empty()) {
        cout << "Description cannot be empty. Enter description: ";
        getline(cin, expense.description);
    }

    expenses.push_back(expense);

    cout << "\nExpense added successfully!\n";
}

// Display all expenses
void listExpenses() {
    cout << "\n--- Expense List ---\n";

    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(12) << "Amount"
         << setw(15) << "Category"
         << "Description\n";

    cout << string(55, '-') << "\n";

    for (const Expense& expense : expenses) {
        cout << left
             << setw(8) << expense.id
             << setw(12) << fixed << setprecision(2) << expense.amount
             << setw(15) << expense.category
             << expense.description << "\n";
    }
}

// Calculate total for a category
void categoryTotal() {
    if (expenses.empty()) {
        cout << "\nNo expenses recorded.\n";
        return;
    }

    string category;
    double total = 0.0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter category: ";
    getline(cin, category);

    for (const Expense& expense : expenses) {
        if (expense.category == category) {
            total += expense.amount;
        }
    }

    cout << "Total for " << category << ": ₹"
         << fixed << setprecision(2) << total << "\n";
}

// Calculate overall total
void overallTotal() {
    double total = 0.0;

    for (const Expense& expense : expenses) {
        total += expense.amount;
    }

    cout << "\n--- Overall Total ---\n";
    cout << "Total Expenses: ₹"
         << fixed << setprecision(2) << total << "\n";
}

// Display menu
void displayMenu() {
    cout << "\n=================================\n";
    cout << "     EXPENSE TRACKER\n";
    cout << "=================================\n";
    cout << "1. Add Expense\n";
    cout << "2. List Expenses\n";
    cout << "3. Category Total\n";
    cout << "4. Overall Total\n";
    cout << "5. Exit\n";
    cout << "=================================\n";
}

int main() {
    int choice;

    cout << "Welcome to Reliable Command-Line Expense Tracker!\n";

    while (true) {
        displayMenu();

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                listExpenses();
                break;

            case 3:
                categoryTotal();
                break;

            case 4:
                overallTotal();
                break;

            case 5:
                cout << "\nThank you for using Expense Tracker!\n";
                return 0;

            default:
                cout << "Invalid choice. Please select 1 to 5.\n";
        }
    }

    return 0;
}
