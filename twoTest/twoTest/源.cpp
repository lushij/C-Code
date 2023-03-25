#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long long str2ll(const char* str) {
    long long num = 0;
    int sign = 1;

    while (isspace(*str)) {
        str++;
    }

    if (*str == '+') {
        str++;
    }
    else if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str && isdigit(*str)) {
        num = num * 10 + (*str - '0');
        str++;
    }

    return num * sign;
}

int main() {
    char str[] = "124567890";
    long long num = str2ll(str);
    printf("%lld\n", num);

    return 0;
}