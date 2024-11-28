#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

class Expense {
public:
    std::string description;
    std::string category;
    double amount;

    Expense(const std::string& desc, const std::string& cat, double amt)
        : description(desc), category(cat), amount(amt) {}
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;
    const std::string fileName = "expenses.txt";

    void saveToFile() {
        std::ofstream file(fileName);
        if (file.is_open()) {
            for (const auto& exp : expenses) {
                file << exp.description << "," << exp.category << "," << exp.amount << "\n";
            }
            file.close();
        }
    }

    void loadFromFile() {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string desc, cat;
            double amt;
            while (file >> std::ws, std::getline(file, desc, ',') &&
                   std::getline(file, cat, ',') &&
                   (file >> amt)) {
                expenses.emplace_back(desc, cat, amt);
                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            file.close();
        }
    }

public:
    ExpenseTracker() {
        loadFromFile();
    }

    ~ExpenseTracker() {
        saveToFile();
    }

    void addExpense() {
        std::string desc, cat;
        double amt;

        std::cout << "Enter description: ";
        std::getline(std::cin, desc);
        std::cout << "Enter category: ";
        std::getline(std::cin, cat);

        while (true) { // Loop to ensure valid numeric input
            std::cout << "Enter amount: ";
            std::cin >> amt;

            if (std::cin.fail()) { // Check if the input is invalid
                std::cin.clear(); // Clear the failure state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid amount. Please enter a numeric value.\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                break; // Exit the loop if input is valid
            }
        }

        expenses.emplace_back(desc, cat, amt);
        std::cout << "Expense added!\n";
    }

    void viewExpenses() const {
        if (expenses.empty()) {
            std::cout << "No expenses recorded yet.\n";
            return;
        }

        std::cout << "\nAll Expenses:\n";
        std::cout << std::setw(20) << "Description" << std::setw(20) << "Category"
                  << std::setw(10) << "Amount\n";
        std::cout << "----------------------------------------------------------\n";

        for (const auto& exp : expenses) {
            std::cout << std::setw(20) << exp.description
                      << std::setw(20) << exp.category
                      << std::setw(10) << exp.amount << "\n";
        }
    }

    void searchByCategory() const {
        std::string cat;
        std::cout << "Enter category to search: ";
        std::getline(std::cin, cat);

        bool found = false;
        for (const auto& exp : expenses) {
            if (exp.category == cat) {
                if (!found) {
                    std::cout << "\nExpenses in category \"" << cat << "\":\n";
                    std::cout << std::setw(20) << "Description" << std::setw(20)
                              << "Amount\n";
                    std::cout << "-------------------------------------------\n";
                }
                found = true;
                std::cout << std::setw(20) << exp.description
                          << std::setw(20) << exp.amount << "\n";
            }
        }

        if (!found) {
            std::cout << "No expenses found in this category.\n";
        }
    }

    void run() {
        int choice;
        do {
            std::cout << "\nExpense Tracker Menu:\n";
            std::cout << "1. Add Expense\n";
            std::cout << "2. View All Expenses\n";
            std::cout << "3. Search by Category\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case 1:
                    addExpense();
                    continue;;
                case 2:
                    viewExpenses();
                    break;
                case 3:
                    searchByCategory();
                    break;
                case 4:
                    std::cout << "Exiting Expense Tracker. Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.run();
    return 0;
}
