// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;
    while (*str) {
        if (isalpha(*str)) {
            inWord = true;
        }
        else if (isdigit(*str)) {
            hasDigit = true;
        }
        else if (*str==' ') {
            if (!hasDigit && inWord) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        }
        str++;
    }
    if (*str == '\0') {
        if (!hasDigit && inWord) {
            count++;
        }
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool isCapital = false;
    bool isRight = false;
    while (*str) {
        if (isupper(*str)) {
            if (inWord && isCapital) {
                isRight = false;
                isCapital = false;
            }
            else {
                inWord = true;
                isCapital = true;
            }
        }
        else if (islower(*str)) {
            if (inWord && isCapital) {
                isRight = true;
            }
            else isRight = false;
        }
        else if (!isupper(*str) && !islower(*str) && isRight) {
            count++;
            inWord = false;
            isCapital = false;
            isRight = false;
        }
        str++;
    }
    if (*str == '\0') {
        if (isRight) {
            count++;
        }
    }
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int countWords = 0;
    unsigned int count = 0;
    unsigned int SumOfLetters = 0;
    bool inWord = false;
    double result;
    while (*str) {
        if (*str != ' ') {
            inWord = true;
        }
        if (inWord) {
            if (*str != ' ') {
                count++;
            }
            else {
                inWord = false;
                countWords++;
                SumOfLetters += count;
                count = 0;
            }
        }
        str++;
    }
    if (*str == '\0') {
        countWords++;
        SumOfLetters += count;
    }
    result = round(float(SumOfLetters) / countWords);
    return result;
}
