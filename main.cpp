#include <iostream>
#include <cstring>
using namespace std;

#pragma region Section A
int checkMatch(char s1[40], char s2[15]) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);

    for (int i = 0; i <= s1Length - s2Length; i++) {
        char temp[15];
        strncpy(temp, &s1[i], s2Length);
        temp[s2Length] = '\0'; 

        if (strcmp(temp, s2) == 0)
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
        char temp[15];
        strncpy(temp, &s1[i], s2Length);
        temp[s2Length] = '\0'; 

        if (strcmp(temp, s2) == 0) {
            count++;
        }
    }

    return count;
}
#pragma endregion

int main() {
    char s1[40] = "is lamiz and lamiz";
    char s2[15] = "lamiz";
    int strCmpIndex = checkMatch(s1, s2);
    int substringCount = countSubstrings(s1, s2);

    // Section A
    if (strCmpIndex != -1) {
        cout << "The first occurrence of '" << s2 << "' in '" << s1 << "' starts at index: " << strCmpIndex << endl;
    } else {
        cout << "'" << s2 << "' not found in '" << s1 << "'" << endl;
    }

    // Section B
    cout << "The substring '" << s2 << "' appears " << substringCount << " times in '" << s1 << "'." << endl;

    return 0;
}
