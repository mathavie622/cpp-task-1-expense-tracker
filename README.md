# Reliable Command-Line Expense Tracker

## Task

C++ Programming – TASK-1

## Objective

A beginner-friendly command-line expense tracker built using C++.

The program demonstrates:

* Variables
* Structures
* Collections
* Functions
* Loops and conditional statements
* Input validation
* Defensive input handling

## Features

1. Add Expense
2. List Expenses
3. Calculate Category Total
4. Calculate Overall Total
5. Exit the application

## Expense Fields

Each expense contains:

* Expense ID
* Amount
* Category
* Description

## Input Validation

The program validates:

* Invalid menu choices
* Non-numeric input
* Negative or zero expense amounts
* Invalid expense IDs
* Empty category
* Empty description

Invalid input is handled without crashing the program.

## How to Run

Compile:

```bash
g++ expense_tracker.cpp -o expense_tracker
```

Run:

```bash
./expense_tracker
```

On Windows:

```bash
expense_tracker.exe
```

## Sample Categories

* Food
* Travel
* Education
* Shopping
* Other

## Sample Output

```text
=================================
     EXPENSE TRACKER
=================================
1. Add Expense
2. List Expenses
3. Category Total
4. Overall Total
5. Exit
=================================
Enter your choice: 1

--- Add Expense ---
Enter Expense ID: 1
Enter Amount: 150
Enter Category: Food
Enter Description: Lunch

Expense added successfully!
```

## Conclusion

This project implements a reliable menu-driven expense tracker using C++. It uses focused functions and defensive input validation to provide readable and safe command-line interaction.
