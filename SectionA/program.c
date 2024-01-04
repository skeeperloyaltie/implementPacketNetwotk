#include <stdio.h>
#include <stdlib.h>

// Function to parse and print IP address
void printIPAddress(int section1, int section2, int section3) {
    printf("%d.%d.%d.0/25\n", section1, section2, section3);
}

int main() {
    char studentNumber[8];
    printf("Enter your student number (uxxxxxxx): ");
    scanf("%s", studentNumber);

    // First section of IP
    int firstSection = (studentNumber[0] - '0') * 100 + (studentNumber[1] - '0') * 10 + (studentNumber[2] - '0');
    if (firstSection < 223) {
        // Second section of IP
        int secondSection = (studentNumber[3] - '0') * 10 + (studentNumber[4] - '0');
        if (secondSection == 0) {
            secondSection = 11;
        }

        // Third section of IP
        int thirdSection = (studentNumber[5] - '0') * 10 + (studentNumber[6] - '0');
        if (thirdSection == 0) {
            thirdSection = 11;
        }

        // Print the IP address using the custom function
        printIPAddress(firstSection, secondSection, thirdSection);
    } else {
        // If first three digits are more than 223, use 191 as the first section of IP address
        printIPAddress(191, 0, 0);
    }

    return 0;
}
