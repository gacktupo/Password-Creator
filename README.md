# Password-Creator
This program prompts user for a name, 4 integers, and symbol to create a password.

SAMPLE RUN:
----------------------------------------
|          ♡〜٩( ˃▿˂ )۶〜♡             |
|    Welcome to the Password Maker!    |
|             ✩˖ ࣪‧₊˚໒꒱⋆✩              |
----------------------------------------

Enter a word or phrase: fef

Enter a 4-digit number: fdf

Invalid number. (?︵?) Please enter a 4-digit number: 453

Invalid number. (?︵?) Please enter a 4-digit number: 4534 

Enter a symbol: )   

Your strong password is: fef4534)

----------------------------------------
|                                      |
|    TY for Using the Password Maker!  |
|              (ʘ‿ʘ)╯                  |
----------------------------------------

===========================================================
DESIGN:

a) Inputs

word- char
number- char.
symbol- char.
-----------------------------------------------------------
b) Outputs

password- char

-----------------------------------------------------------
c) Calculations

removes any characters after a space in the word input.
validates the number input to ensure it is a 4-digit number.
validates the symbol input to ensure it is a single special character.
concatenates the validated word, number, and symbol together to form the password.
-----------------------------------------------------------
d) Pseudocode

DECLARE word[MAX_LENGTH], number[MAX_LENGTH], symbol[MAX_LENGTH], password[MAX_LENGTH]

FUNCTION welcome()
    DISPLAY "----------------------------------------"
    DISPLAY "|          ♡〜٩( ˃▿˂ )۶〜♡             |"
    DISPLAY "|    Welcome to the Password Maker!    |"
    DISPLAY "|             ✩˖ ࣪‧₊˚໒꒱⋆✩              |"
    DISPLAY "----------------------------------------"
    DISPLAY newline

FUNCTION createPassword(word, number, symbol, password)
    SET password as empty string
    CONCATENATE word to password
    CONCATENATE number to password
    CONCATENATE symbol to password

FUNCTION isValidNumber(number)
    IF length of number is not equal to 4
        RETURN false
    FOR each character in number
        IF character is not a digit
            RETURN false
    RETURN true

FUNCTION isValidSymbol(symbol)
    IF length of symbol is not equal to 1
        RETURN false
    IF symbol is not a readily available special character
        RETURN false
    RETURN true

FUNCTION goodbye()
    DISPLAY newline
    DISPLAY "----------------------------------------"
    DISPLAY "|                                      |"
    DISPLAY "|    TY for Using the Password Maker!  |"
    DISPLAY "|              (ʘ‿ʘ)╯                  |"
    DISPLAY "----------------------------------------"

FUNCTION main()
    CALL welcome()

    DISPLAY "Enter a word or phrase: "
    INPUT word

    SET spacePos as pointer to the first occurrence of ' ' in word
    IF spacePos is not nullptr
        SET the character at spacePos to '\0'

    DISPLAY "Enter a 4-digit number: "
    INPUT number

    WHILE NOT isValidNumber(number)
        DISPLAY "Invalid number. (?︵?) Please enter a 4-digit number: "
        INPUT number

    DISPLAY "Enter a symbol: "
    INPUT symbol

    WHILE NOT isValidSymbol(symbol)
        DISPLAY "Invalid symbol. (?︵?) Please enter a single special character: "
        INPUT symbol

    CALL createPassword(word, number, symbol, password)
    DISPLAY "Your strong password is: " + password

    CALL goodbye()
    
    RETURN 0
