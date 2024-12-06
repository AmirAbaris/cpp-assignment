#include <iostream>
#include <cstring> 
using namespace std;

 #pragma region Section A
// LOWERCASE VS UPPERCASE => L != l
int checkMatch(char s1[40], char s2[15]) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);

    for (int i = 0; i < s1Length - s2Length; i++) {
        // using strncmp you can limit the search, so that it doesn't reach non-accessible memory.
        if (strncmp(&s1[i], s2, s2Length) == 0)
            return i;
    }

    return -1;
}
#pragma endregion

 #pragma region Section B
int countSubstrings(char s1[40], char s2[15]) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);
    int count = 0;

    for (int i = 0; i <= s1Length - s2Length; i++) {
        // compares the substrings of s2 in s1
        if (strncmp(&s1[i], s2, s2Length) == 0) {
            count++;
        }
    }

    return count;
}
#pragma endregion

int main() {
    char s1[40] = "lamiz is awesome";
    char s2 [15] = "lamiz";
    int strCmpIndex = checkMatch(s1, s2);
    int substringCount = countSubstrings(s1, s2);

    // Section A
    if (strCmpIndex != -1) {
        cout << "The first str char index of '" << s2 << "' in '" << s1 << "' is: " << strCmpIndex << endl;
    } else {
        cout << "'" << s2 << "' not found in '" << s1 << "'" << endl;
    }

    // Section B
    cout << "The substring '" << s1 << "' appears " << substringCount << " times in '" << s2 << "'." << endl;
    
    return 0;
}