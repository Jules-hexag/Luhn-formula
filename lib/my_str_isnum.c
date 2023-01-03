int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
        i++;
    }
    if (i == 0)
        return 0;
    return 1;
}
