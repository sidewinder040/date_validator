/*  
    Date Validator Helper
    Author: Mark Crouch
    Date: 29/06/2024
*/
#include "date_validator_helper.h"

/// @brief Validates a date
/// @param dd = day
/// @param mm = month
/// @param yy = year as 2024 (full = yyyy)
/// @return int: 0 if valid, 1 if invalid

int date_validator_helper(int dd, int mm, int yy) {
    
    int isValid = 1; // result bool flag - default is false

    if (yy >= 1900 && yy <= 9999) {
        // Check month
        if (mm >= 1 && mm <= 12) {
            // Check days in 31 day months
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)) {
                // printf("Date is valid.\n");
                isValid = 0;
            }
            // check days in 30 day months
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
                // printf("Date is valid.\n");
                isValid = 0;
            }
            // check days in 28 day feburary
            else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
                // printf("Date is valid.\n");
                isValid = 0;
            }
            // check days in 29 day feburary
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) {
                // printf("Date is valid.\n");
                isValid = 0;
            }
            else {
                printf("Day is invalid.\n");
                // isValid = 1;
            }
        } else {
            printf("Month is not valid.\n");
            // isValid = 1;
        }
    } else {
        printf("Year is not valid.\n");
        // isValid = 1;
    }

    return isValid;
}
    