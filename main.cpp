#include <iostream>
#include <algorithm>

#include "LinkedList.h"

#define INPUT_ERROR "Please supply a single string between 10 and 15 characters."
#define TAX_RATE 1.032

void reverse_string(std::string &str);
std::string double_characters(std::string &str);
void calculate_cost_with_tax(std::string &str);

int main(int argc, char* argv[]) {
    try {
        std::string input = "";

        if (argc == 1) {
            // Prompt for an input string.
            std::cout << "Enter a string between 10 and 15 characters in length: ";
            std::getline(std::cin, input); // Read the entire line as input
        } else if (argc == 2) {
            input = argv[1];
        } else {
            std::string err = INPUT_ERROR;
            err += "\nUsage: ./stax_takehome [string]";
            throw std::invalid_argument(err);
        }

        // Validate the length of the input.
        if (input.length() < 10 || input.length() > 15) {
            throw std::out_of_range("Input length must be between 10 and 15 characters.");
        }

        if (input.length() % 2 == 0) {
            // Length divisible by 2
            if (input.length() % 3 == 0) {
                // length divisible by 2 and by 3
                calculate_cost_with_tax(input);
            } else {
                reverse_string(input);
            }
        } else if (input.length() % 3 == 0) {
            // Length divisible by 3
            std::cout << double_characters(input) << std::endl;
        } else {
            throw std::invalid_argument("Input length must be evenly divisible by 2 or by 3, or by both.");
        }

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// Reverse the order of the given string, in-place.
void reverse_string(std::string &str) {
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
}

// Double the characters in the string, using a linked list as an intermediate storage type.
std::string double_characters(std::string &str) {
    LinkedList list{};

    for (int x = 0; x < str.length(); x++) {
        list.push_item(str[x]);
        list.push_item(str[x]);
    }

    return list.get_string();
}

// Calculate the 'cost' of a string, where each character is worth $1, and tax is added in the amount of 3.2%.
void calculate_cost_with_tax(std::string &str) {
    std::cout << "$" << str.length() * TAX_RATE << std::endl;
}