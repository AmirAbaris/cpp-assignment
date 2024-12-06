#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

// DOES'T COMPARE LOWERCASE VS UPPERCASE => L = l
int checkMatchString(string s1, string s2) {
    // when we compare 2 different strings, char, etc, we use two nested loops and init the second loop we start with j + j
    // this is looks like a bubble sort! but we check for 2 strings here, thats why we wrote i + j in the if check
    for (int i = 0; i < s1.length(); i++) {
        bool match = false;

        // and for the target loop (second one) we track its index with j:
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i + j] == s2[j]) {
                match = true;
                break;
            }
            // NOTE: we can add another condition if we want to compare the word it self, not just a letter
            // with this condition: s1[j + j + 1] == s2[j + 1] so the if condition will be:
            // if (s1[i + j] == s2[j] && s[j + j + 1] == s2[j + 1]) {}
            // but for the simplicity, i sticked to just checking the letter
        }

        if (match)
            return i;
    }

    // not a match
    return -1;
};

// DOES'T COMPARE LOWERCASE VS UPPERCASE => L = l
int checkMatchChar(char s1[40], char s2[15]) {
    for (int i = 0; i < 40; i++) {
        bool match = false;
        for (int j = 0; j < 15; j++) {
            if (s1[i + j] == s2[j]) {
                match = true;
                break; // performance boost
            }
        }

        if (match)
            return i;
    }

    // not a match
    return -1;
}

// COMPARES LOWERCASE VS UPPERCASE => L != l
int checkMatchStringCmp(char s1[40], char s2[15]) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);

    for (int i = 0; i < s1Length - s2Length; i++) {
        // using strncmp you can limit the search, so that it doesn't reach non-accessible memory.
        if (strncmp(&s1[i], s2, s2Length) == 0)
            return i;
    }

    return -1;
}

int main() {
    string s1 = "lamiz is awesome";
    string s2 = "lamiz";

    char s1Char[40] = "lamiz is awesome";
    char s2Char [15] = "lamiz";
    
    int stringIndex = checkMatchString(s1, s2);
    int charIndex = checkMatchChar(s1Char, s2Char);
    int strCmpIndex = checkMatchStringCmp(s1Char, s2Char);

    if (stringIndex != -1 || charIndex != -1 || strCmpIndex != -1) {
        cout << "The first string index of '" << s2 << "' in '" << s1 << "' is: " << stringIndex << endl;
        cout << "The first char index of '" << s2 << "' in '" << s1 << "' is: " << charIndex << endl;
        cout << "The first str char index of '" << s2 << "' in '" << s1 << "' is: " << strCmpIndex << endl;
    } else {
        cout << "'" << s2 << "' not found in '" << s1 << "'" << endl;
    }
    
    return 0;
}