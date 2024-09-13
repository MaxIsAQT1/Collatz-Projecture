/**
 * This program implements the Collatz conjecture, which involves iterating on a starting number n.
 * If n is even, it is divided by 2; if odd, it is multiplied by 3 and incremented by 1.
 * The program performs these operations until a repeated number (loop) is encountered or a safeguard limit is reached.
 * It outputs the sequence of numbers generated and the number of iterations performed.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>

const int MAX_ITERATIONS = 1000000;  // Safeguard limit for iterations
const bool SAFEGUARD_ENABLED = true; // Enable or disable safeguard

int ComputeCollatzSequence(int startNumber, std::vector<int>& collatzSequence) {
    std::unordered_set<int> encounteredNumbers;  // Track numbers to detect loops

    collatzSequence.push_back(startNumber);  // Start with the initial number
    encounteredNumbers.insert(startNumber);

    int iterationCount = 0;
    int currentNumber = startNumber;

    while (true) {
        iterationCount++;

        // Exit if safeguard limit is exceeded
        if (SAFEGUARD_ENABLED && iterationCount > MAX_ITERATIONS) {
            std::cout << "Max iterations reached. Exiting.\n";
            break;
        }

        // Apply Collatz rules
        if (currentNumber % 2 == 0) {
            currentNumber = currentNumber / 2;  // Even: divide by 2
        } else {
            currentNumber = currentNumber * 3 + 1;  // Odd: multiply by 3, add 1
        }

        // Exit if a loop is detected
        if (encounteredNumbers.find(currentNumber) != encounteredNumbers.end()) {
            break;
        }

        collatzSequence.push_back(currentNumber);  // Store current number in sequence
        encounteredNumbers.insert(currentNumber);
    }

    return iterationCount;  // Return total iterations
}

void PrintCollatzResults(const std::vector<int>& collatzSequence, int iterationCount) {
    std::cout << "Sequence:\n";

    // Output the sequence of numbers
    std::cout << collatzSequence.front();
    for (size_t i = 1; i < collatzSequence.size(); ++i) {
        std::cout << "->" << collatzSequence[i];
    }

    // Output the number of iterations performed
    std::cout << '\n' << "Reached a loop in " << iterationCount << " iterations.";
}

int ValidateUserInput(){
    // Get user input for starting number
    int inputNumber;    

    for (;;) {
        std::cout << "Enter a number: ";
        if (std::cin >> inputNumber) {
            return inputNumber;
            break;
        } else {
            std::cout << "Invalid input. Try again,\n";
            std::cin.clear();  // Clear input error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        }
    }
}

int main() {
    std::vector<int> collatzSequence;       // Store the Collatz sequence
    int inputNumber = ValidateUserInput();  // Starting number

    // Perform calculations and output the results
    int totalIterations = ComputeCollatzSequence(inputNumber, collatzSequence);
    PrintCollatzResults(collatzSequence, totalIterations);

    return 0;
}
