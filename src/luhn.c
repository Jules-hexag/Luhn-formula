#include <unistd.h>
#include "my.h"

static int verify_input(int const argc, char const * const *argv)
{
    int i = 1;
    if (argc < 2) return -1;
    while (i < argc) {
        if (!my_getnbr(argv[i])) {
            write(2, "Please enter only numbers.\n", 28);
            return -1;
        }
        i++;
    }
    return 0;
}

static int digits_number(int number)
{
    int sum = 0;
    while (number != 0) {
        sum++;
        number /= 10;
    }
    return sum;
}

static int number_validity(int sum)
{
    if (sum % 10 == 0) {
        write(1, "The number is valid.\n", 22);
        return 0;
    } else {
        write(1, "The number is not valid.\n", 26);
        return 0;
    }
}

int luhn(int const argc, char const * const *argv)
{
    int sum = 0;
    int number = 0;
    int arg_len = 0;
    if (verify_input(argc, argv)) {
        return -1;
    }
    if (!my_strncmp(argv[1], "-h", 2)) {
        write(1, "USAGE\n\tthe number must be divided in groups of even numbers of digits\n\
        \tgroups of digits cannot be only 0's\n", 0);
        return 0;
    }
    for (int i = argc; i > 1; i--) {
        number = my_getnbr(argv[i - 1]);
        arg_len = digits_number(number);
        for (int j = 1; j != arg_len + 1; j++) {
            if (j % 2 && number > 9) {
                sum += number % 10;
                number /= 10;
            } else if (!(j % 2) && number > 9) {
                int two_times = 2 * (number % 10);
                sum += two_times >= 10 ? ((two_times % 10) + (two_times / 10)): two_times;
                number /= 10;
            } else {
                sum += (j % 2) ? number : ((2 * number >= 10) ? (2 * number % 10 + 2 * number / 10) : (2 * number));
            }
        }
    }
    my_printf("%d\n", sum);
    number_validity(sum);
    return 0;
}