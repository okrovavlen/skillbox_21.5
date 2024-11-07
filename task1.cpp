#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

struct Entry {
    std::string name;
    std::string date;
    int amount;
};

std::vector<Entry> read_entries(const std::string& filename) {
    std::vector<Entry> entries;
    std::ifstream file(filename);

    if (file.is_open()) {
        Entry entry;
        while (file >> entry.name) {
            if (file.fail()) {
                std::cerr << "Error reading name.\n";
                break;
            }
            if (!(file >> entry.date >> entry.amount)) {
                std::cerr << "Error reading date or amount.\n";
                break;
            }
            entries.push_back(entry);
        }
        file.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }

    return entries;
}

void add_entry(const std::string& filename, const Entry& new_entry) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        file << new_entry.name << " " << new_entry.date << " " << new_entry.amount << std::endl;
        file.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

int main() {
    std::string filename = "vedomost.txt";
    std::string command;

    std::cout << "Enter command (list or add): ";
    std::cin >> command;

    if (command == "list") {
        std::vector<Entry> entries = read_entries(filename);
        for (const auto &entry: entries) {
            std::cout << entry.name << " " << entry.date << " " << entry.amount << std::endl;
        }
    } else if (command == "add") {
        Entry new_entry;
        std::cout << "Enter full name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, new_entry.name);
        std::cout << "Enter date (DD.MM.YYYY): ";
        std::cin >> new_entry.date;
        std::cout << "Enter amount: ";
        while (!(std::cin >> new_entry.amount)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        add_entry(filename, new_entry);
        std::cout << "Entry added!" << std::endl;
    } else {
        std::cout << "Unknown command!" << std::endl;
    }

    return 0;
}