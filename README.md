# Expense Tracker

A simple C++ program to manage personal expenses. This application allows users to add, view, and search expenses by category, with data persistence using a text file.

## Features
- Add expenses with a description, category, and amount.
- View all expenses in a tabular format.
- Search expenses by category.
- Save and load expenses automatically using a file.

## Requirements
- C++17 or higher.
- A C++ compiler like `clang++` or `g++`.
- [VS Code](https://code.visualstudio.com/) with Code Runner extension (optional).

## How to Run
1. Clone the repository to your local machine:
```bash
   git clone https://github.com/YOUR_GITHUB_USERNAME/ExpenseExample.git
   cd ExpenseExample
```
2. Create expenses.txt file in the repository
```bash
   touch expenses.txt
```
3. Compile & Run the program
```bash
   clang++ -std=c++17 ExpenseTracker.cpp -o ExpenseTracker
```
## How to Use
1. On running the program you'll see a menu:
```bash
   Expense Tracker Menu:
   1. Add Expense
   2. View All Expenses
   3. Search by Category
   4. Exit
```
2. Choose an option by entering the corresponding number:
    - Add a new expense by entering a description, category, and amount.
    - 2: View all recorded expenses.
    - 3: Search for expenses by entering a category name.
    - 4: Exit the program and save all data.

3. Data is automatically saved in expenses.txt and will be reloaded the next time you run the program.