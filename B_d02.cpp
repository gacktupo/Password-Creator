/******************************************************************************
# Author:           Courtney T.
# Lab:              Discussion #2
# Date:             July 5th, 2023
# Description:      This progam prompts user for a name, 4 integers, and symbol
to create a password.
# Input:            char word, char symbol, char number
# Output:           char password
# Sources:          None
#******************************************************************************/
#include <cstring>
#include <iostream>

using namespace std;

// function prototypes
void welcome();
void createPassword(const char *word, const char *number, const char *symbol, char *password);
bool isValidWord(const char *word);
bool isValidNumber(const char *number);
bool isValidSymbol(const char *symbol);
void goodbye();

const int MAX_LENGTH = 20;

// main function
int main() {
  char word[MAX_LENGTH];
  char number[MAX_LENGTH];
  char symbol[MAX_LENGTH];
  char password[MAX_LENGTH];

  welcome();

  // prompt user for words
  cout << "Enter a word or phrase: ";
  cin.getline(word, MAX_LENGTH);
  // remove word after space if applicable
  char *spacePos = strchr(word, ' ');
  if (spacePos != nullptr)
    *spacePos = '\0';
  while (!isValidWord(word)) {
    cout << "\nInvalid word or phrase. (?︵?) Please enter letters: ";
    cin.getline(word, MAX_LENGTH);
  }

  // prompt user for 4 integers
  cout << "\nEnter a 4-digit number: ";
  cin.getline(number, MAX_LENGTH);
  // input validation for 4 numbers
  while (!isValidNumber(number)) {
    cout << "\nInvalid number. (?︵?) Please enter a 4-digit number: ";
    cin.getline(number, MAX_LENGTH);
  }

  // prompt user for symbol
  cout << "\nEnter a symbol: ";
  cin.getline(symbol, MAX_LENGTH);
  // input validation for symbol
  while (!isValidSymbol(symbol)) {
    cout
        << "\nInvalid symbol. (?︵?) Please enter a single special character: ";
    cin.getline(symbol, MAX_LENGTH);
  }

  // call createPassword function to create word based on user input
  createPassword(word, number, symbol, password);
  // display unique password
  cout << "\nYour strong password is: " << password << endl;

  // exit message
  goodbye();

  return 0;
}

// welcome message
void welcome() {
  cout << "----------------------------------------\n"
       << "|          ♡〜٩( ˃▿˂ )۶〜♡             |\n"
       << "|    Welcome to the Password Maker!    |\n"
       << "|             ✩˖ ࣪‧₊˚໒꒱⋆✩              |\n"
       << "----------------------------------------\n";
  cout << endl;
}

// create the password
void createPassword(const char *word, const char *number, const char *symbol,
                    char *password) {
  strcpy(password, word);   // copy the word to the password array
  strcat(password, number); // concatenate the number to the password array
  strcat(password, symbol); // concatenate the symbol to the password array
}

bool isValidWord(const char *word) {
  size_t length = strlen(word);

  for (size_t i = 0; i < length; i++) {
    if (!isalpha(word[i])) {
      return false; // If any non-alphabetic character is found, return false
    }
  }

  return true; // If all characters are alphabetic, return true
}

// validate the number
bool isValidNumber(const char *number) {
  // Check if the number is a 4-digit number
  if (strlen(number) != 4)
    return false;

  // check if all characters are digits
  for (int i = 0; i < 4; i++) {
    if (!isdigit(number[i]))
      return false;
  }

  return true;
}

bool isValidSymbol(const char *symbol) {
  // check if symbol is a single character
  if (strlen(symbol) != 1)
    return false;

  // check if symbol is readily available on the keyboard
  if (!ispunct(symbol[0]))
    return false;

  return true;
}

// exit message
void goodbye() {
  cout << endl;
  cout << "----------------------------------------\n"
       << "|                                      |\n"
       << "|    TY for Using the Password Maker!  |\n"
       << "|              (ʘ‿ʘ)╯                  |\n"
       << "----------------------------------------\n";
}
