//
// Created by engmrgh on 12/6/19.
//

int intlen(int num){
    int count = 0;
    /* Run loop till num is greater than 0 */
    while(num != 0) {
        /* Increment digit count */
        count++;
        /* Remove last digit of 'num' */
        num /= 10;
    }
}

int power(int base, int power){
    int result = 1;
    for (int i = 0; i < power; ++i)
        result *= base;
    return result;
}