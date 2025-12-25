/*
lets start from basic

1.Core Idea of Simple Encryption
Takes plain text
Applies a repeatable transformation
Uses a key
Produces cipher text
Can be reversed using the same key

2.Plain Text and Cipher Text

Plain text: Original readable data
Example: HELLO

Cipher text: Encrypted unreadable form
Example: KHOOR


3. The Role of the Key

The key controls the transformation.
Think of the key as:
A number
A character
A string (password)
Without the correct key:
Decryption should be difficult
Output should appear random


4. Character-Based Encryption
Most simple algorithms work character by character.
Concept:
Take one character
Convert it to a numeric value (like ASCII)
Modify the value using the key
Convert it back to a character
This keeps encryption predictable and reversible.

5. Substitution-Based Encryption
Each character is replaced with another character.
Concept
A becomes D
B becomes E
And so on…
Rules:
Replacement must be consistent
Mapping must be reversible
Weakness:
Patterns remain visible
Easy to break with frequency analysis

6. Shift (Offset) Encryption
Characters are shifted forward or backward.
Concept
Add a fixed number to each character value
Wrap around when limits are reached
Example idea:
Key = 3
A → D, B → E, Z → C
Decryption:
Subtract the same number
This is one of the simplest encryption concepts.

7. XOR-Based Encryption
Uses a bitwise XOR operation.
Concept
Combine each character with a key using XOR
XOR has a special property:
Applying XOR twice with the same key restores original data
Advantages:
Very simple
Reversible
Works for any binary data
Weakness:
Weak if key is short or reused

8. Reversibility (Most Important Rule)
A valid encryption algorithm must
Be fully reversible
Restore the exact original data
Lose no information
If information is lost, decryption becomes impossible.

9. Deterministic Behavior
Given:
The same input
The same key
The output must always be:
Exactly the same
This ensures reliable encryption and decryption.

10. Handling Non-Letter Characters
Simple algorithms must decide:
Encrypt all characters?
Leave spaces and symbols unchanged?
Handle uppercase and lowercase separately?
These rules must be consistent.

11. Why Simple Encryption Is Weak
Simple encryption is good for learning, but not security.

Reasons:
Small key space
Predictable transformations
Easy to brute-force
Vulnerable to pattern analysis

12. Purpose of Simple Encryption
Simple encryption algorithms are mainly used to:
Learn cryptographic thinking
Understand reversibility
Practice data transformation
Prepare for advanced encryption concept



Plan the Program Flow (Very Important)

Write the logic in plain language:

Start program

Ask user for text

Ask user for key

Encrypt the text

Display encrypted text

Ask if decryption is needed

Decrypt using the same key

Display original text

End program

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Substution Method

void encryption(char *str_enc, int key_enc)
{
    int i;
    // loop will stop at last so '\0'
    for (i = 0; str_enc[i] != '\0'; i++)
    {
        // its ignore the newline and continue
        if (str_enc[i] != '\n')
        {
            str_enc[i] += key_enc;
        }
    }

    printf("String after encryption is : %s", str_enc);
}

// simple encryptio just increasing the ascii value and changing alphabate
int main()
{
    char *str_enc;
    int size_str = 500;
    int key_enc;
    int i;

    str_enc = (char *)malloc(size_str * sizeof(char));

    // checking memory
    if (str_enc == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter the text to encrypt :");
    // take input until : specific char is reached , a neewline \n is read,eof end of file is reached   stdin for keyboard input , can use file pointer to read from file File pointer → file input
    // stdin → read from user input .File stream → read from a file
    fgets(str_enc, size_str, stdin);

    printf("Enter Encryption Key for the encryption :");
    scanf("%d", &key_enc);

    printf("String for encryption is :");
    printf("%s", str_enc);

    printf("Encryption key is :");
    printf("%d\n", key_enc);

    encryption(str_enc, key_enc);
    free(str_enc);

    return 0;
}
