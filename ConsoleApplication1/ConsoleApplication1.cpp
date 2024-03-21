﻿#include <iostream>

using namespace std;

int main() {
    // Завдання 1
    char symbol;
    int length, speed, orientation;

    cout << "Enter symbol: ";
    cin >> symbol;

    cout << "Enter length: ";
    cin >> length;

    cout << "Choose speed (0 - slow, 1 - normal, 2 - fast): ";
    cin >> speed;

    cout << "Choose orientation (0 - horizontal, 1 - vertical): ";
    cin >> orientation;

    if (orientation == 0) {
        for (int i = 0; i < length; ++i) {
            cout << symbol;
            for (int j = 0; j < (speed == 0 ? 500000 : (speed == 1 ? 100000 : 10000)); ++j) {}
        }
        cout << endl;
    }
    else if (orientation == 1) {
        for (int i = 0; i < length; ++i) {
            cout << symbol << endl;
            for (int j = 0; j < (speed == 0 ? 500000 : (speed == 1 ? 100000 : 10000)); ++j) {}
        }
    }
    else {
        cout << "Invalid choice." << endl;
    } 

    // Завдання 2
    srand(time(0));

    int playerScore = 0, computerScore = 0;

    cout << "The game 'Dice'!\n";
    cout << "The player and the computer take turns rolling the dice.\n";
    cout << "The winner is the one who has the highest score after 3 throws.\n\n";

    for (int i = 0; i < 3; ++i) {
        cout << "Round " << i + 1 << ":\n";

        cout << "The player rolls the dice...\n";
        int playerRoll1 = rand() % 6 + 1;
        int playerRoll2 = rand() % 6 + 1;
        int playerTotal = playerRoll1 + playerRoll2;
        cout << "The player threw " << playerRoll1 << " and " << playerRoll2 << " (sum: " << playerTotal << ")\n";
        playerScore += playerTotal;

        cout << "The computer rolls the dice...\n";
        int computerRoll1 = rand() % 6 + 1;
        int computerRoll2 = rand() % 6 + 1;
        int computerTotal = computerRoll1 + computerRoll2;
        cout << "The computer threw " << computerRoll1 << " and " << computerRoll2 << " (sum: " << computerTotal << ")\n";
        computerScore += computerTotal;

        cout << endl;
    }

    cout << "Result:\n";
    cout << "Player: " << playerScore << ", Computer: " << computerScore << endl;

    if (playerScore > computerScore)
        cout << "The player has won!\n";
    else if (computerScore > playerScore)
        cout << "The computer has won!\n";
    else
        cout << "A draw!\n";


    srand(time(0));

    // Завдання 1
    const int SIZE = 10; int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    } cout << endl;

    int minElement = arr[0], maxElement = arr[0];

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "The minimum element: " << minElement << endl;
    cout << "Maximum element: " << maxElement << endl << endl;

    // Завдання 2
    const int MONTHS = 12; int profits[MONTHS];

    for (int i = 0; i < MONTHS; ++i) {
        cout << "Enter profit for month " << i + 1 << ": "; cin >> profits[i];
    }

    int startMonth, endMonth;
    cout << endl << "Enter start month of the range: "; cin >> startMonth;
    cout << "Enter end month of the range: "; cin >> endMonth; cout << endl;


    int maxProfit = profits[startMonth - 1], minProfit = profits[startMonth - 1];
    int maxMonth = startMonth, minMonth = startMonth;

    for (int i = startMonth; i <= endMonth; ++i) {
        if (profits[i - 1] > maxProfit) {
            maxProfit = profits[i - 1];
            maxMonth = i;
        }
        if (profits[i - 1] < minProfit) {
            minProfit = profits[i - 1];
            minMonth = i;
        }
    }
    cout << "The maximum profit was in month " << maxMonth << ": " << maxProfit << endl;
    cout << "The minimum profit was in month " << minMonth << ": " << minProfit << endl;

    // Завдання 3
    const int N = 10; double arr[N];

    cout << "Enter " << N << " real numbers:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    double sumNegative = 0, productMinMax = 1, productEvenIndexes = 1, sumBetweenFirstLastNegative = 0;
    int firstNegativeIndex = -1, lastNegativeIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            sumNegative += arr[i];
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            productMinMax *= arr[i];
        }
    }

    for (int i = 0; i < N; i += 2) {
        productEvenIndexes *= arr[i];
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            sumBetweenFirstLastNegative += arr[i];
        }
    }

    cout << "Sum of negative elements: " << sumNegative << endl;
    cout << "Product of elements between first and last negative elements: " << productMinMax << endl;
    cout << "Product of elements with even indexes: " << productEvenIndexes << endl;
    cout << "Sum of elements between first and last negative elements: " << sumBetweenFirstLastNegative << endl;