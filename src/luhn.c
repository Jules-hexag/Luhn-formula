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

int luhn(int const argc, char const * const *argv)
{
    int sum = 0;
    if (verify_input(argc, argv)) {
        write(2, "Invalid input.\n", 16);
        return -1;
    }
    return 0;
}