#ifndef MY_LIB_
    #define MY_LIB_

    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    int my_str_isnum(char const *str);
    char **my_str_to_word_array(char *str);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_printf(char *str, ...);

#endif /* MY_LIB_ */
