#include <iostream>
#include <iomanip>
using namespace std;

const int DIGIT_COUNT = 4;
const int MAX_DIGIT = 9;

unsigned getDigitsCount(unsigned n)
{
    if (n == 0)
        return 1;
    unsigned count = 0;

    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

unsigned countDigitOccurrences(unsigned n, unsigned digit)
{
    if (digit == 0 && n == 0)
        return 1;

    unsigned count = 0;
    while (n != 0)
    {
        int lastDigit = n % 10;
        if (lastDigit == digit)
            count++;
        n /= 10;
    }
    return count;
}

bool areAllDistinctDigits(unsigned n)
{
    for (int i = 0; i <= MAX_DIGIT; i++)
    {
        if (countDigitOccurrences(n, i) > 1)
            return false;
    }
    return true;
}

bool isValidInput(unsigned n)
{
    return areAllDistinctDigits(n) && getDigitsCount(n) == DIGIT_COUNT;
}

unsigned userInput()
{
    unsigned n;
    do
    {
        cout << "Enter a 4-digit number with distinct digits: ";
        cin >> n;

        if (!isValidInput(n))
        {
            cout << "Invalid input. Please make sure to enter a 4-digit number with distinct digits." << endl;
        }

    } while (!isValidInput(n));

    return n;
}

unsigned getCows(unsigned toGuess, unsigned myGuess)
{
    unsigned sum = 0;
    while (toGuess != 0)
    {
        int lastDigit = toGuess % 10;

        bool contains = countDigitOccurrences(myGuess, lastDigit) == 1;

        if (contains)
            sum++;

        toGuess /= 10;
    }
    return sum;
}

unsigned getBulls(unsigned toGuess, unsigned myGuess)
{
    unsigned bulls = 0;
    while (toGuess != 0)
    {
        if (toGuess % 10 == myGuess % 10)
            bulls++;
        toGuess /= 10;
        myGuess /= 10;
    }
    return bulls;
}

void getBullsAndCows(unsigned toGuess, unsigned myGuess, unsigned& bulls, unsigned& cows)
{
    bulls = getBulls(toGuess, myGuess);
    cows = getCows(toGuess, myGuess) - bulls;
}
void printPyramid(int n) {
    // Ensure n is odd
    if (n % 2 == 0) {
        std::cout << "Please enter an odd number." << std::endl;
        return;
    }

    // Upper part of the pyramid
    for (int i = n; i > 0; i -= 2) {
        int whiteSpacesCount = (n - i) / 2;

        // Print leading white spaces
        for (int j = 0; j < whiteSpacesCount; j++) {
            std::cout << ' ';
        }

        // Print asterisks
        for (int j = 0; j < i; j++) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }

    // Lower part of the pyramid
    for (int i = 3; i <= n; i += 2) {
        int whiteSpacesCount = (n - i) / 2;

        // Print leading white spaces
        for (int j = 0; j < whiteSpacesCount; j++) {
            std::cout << ' ';
        }

        // Print asterisks
        for (int j = 0; j < i; j++) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }
}

int main()
{
    cout << "Welcome to Bulls and Cows!" << endl;
    cout << endl;
    cout << "Try to guess the 4-digit number with distinct digits." << endl;
    cout << "Feedback will be provided after each guess:" << endl;
    cout << endl;
    cout << "- Bulls: Correct digits in the correct position." << endl;
    cout << "- Cows: Correct digits in the wrong position." << endl;
    cout << endl;

    unsigned toGuess = userInput();

    printPyramid(29);
    cout << "Success! Now, try and guess it." << endl;

    unsigned bulls, cows;
    do
    {
        unsigned myGuess = userInput();
        getBullsAndCows(toGuess, myGuess, bulls, cows);
        cout << "Bulls: " << bulls << " Cows: " << cows << endl;

    } while (bulls != DIGIT_COUNT);

    cout << "Congratulations! You've guessed the number." << endl;
    return 0;
}