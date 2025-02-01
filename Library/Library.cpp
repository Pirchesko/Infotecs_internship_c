#include "Library.h"

void StringTools::sortAndReplace(std::string& str) {
    std::vector<char>digits;
    std::string new_str;

    // Сначала на всякий случай берём из строки только цифры (хотя всё равно предполагается, что будут только они)
    for (size_t i = 0; i < str.length(); i++) {
        char symbol = str[i];
        if (symbol >= '0' && symbol <= '9') {
            digits.push_back(symbol);
        }
    }

    std::sort(digits.rbegin(), digits.rend());

    for (size_t i = 0; i < digits.size(); i++) {
        if ((digits[i] - '0') % 2 == 0) {
            new_str += "KB";
        }
        else {
            new_str += digits[i];
        }
    }

    str = new_str;
}

int StringTools::calculateSum(const std::string str) {
    int sum = 0;

    for (size_t i = 0; i < str.length(); i++) {
        int digit = str[i] - '0';
        if (digit >= 0 && digit <= 9) {
            sum += digit;
        }
    }

    return sum;
}

bool StringTools::analyzeString(const std::string str) {
    if (str.length() > 2 && str.length() % 32 == 0) {
        return true;
    }
    else {
        return false;
    }
}
