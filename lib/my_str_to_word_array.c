#include "my.h"
#include <stdlib.h>

#define MAX_WORDS 100

char **my_str_to_word_array(char *str)
{
    char **word_array = malloc(sizeof (char *) * MAX_WORDS);
    if (word_array == NULL)
        return NULL;
    size_t word_count = 0;
    size_t word_len = 0;
    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\0')
            word_len++;
        if (str[i] == ' ' || str[i] == '\0') {
            word_array[word_count] = malloc((word_len + 1) * sizeof(char));
            my_strncpy(word_array[word_count], &str[i - word_len], word_len);
            word_array[word_count][word_len] = '\0';
            word_count++;
            word_len = 0;
        }
    }
    word_array[word_count] = NULL;
    return word_array;
}
