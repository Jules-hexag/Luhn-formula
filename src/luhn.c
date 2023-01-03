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

int luhn(int const argc, char const * const *argv)
{
    int sum = 0;
    int number = 0;
    int arg_len = 0;
    if (verify_input(argc, argv)) {
        write(2, "Invalid input.\n", 16);
        return -1;
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
    my_printf("Luhn sum : %d\n", sum);
    return 0;
}