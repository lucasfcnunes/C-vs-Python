#include <stdio.h>
//#include <stdbool.h>

typedef enum
{
    false,
    true
} bool;

#define EOS '\0' // end of string
#define SENTINEL ' '
#define MAX_LENGTH 80
#define MAX_WORD_COUNT MAX_LENGTH / 2 + 1

#define DEBUG 1

#define OK 0
#define ARGC_ERR 1
#define TEXT_SIZE_ERR 2

struct words_summary
{
    char word[MAX_LENGTH + 1];
    short unsigned quantity;
};

int main(int argc, const char *argv[])
{
    if (DEBUG)
        printf("argc == %i, argv == \"%s\"\n", argc, argv[1]);

    short unsigned text_char_index, word_char_index, text_size, words_count, sentinel_count;
    short int words_index;
    const char *text; // ! allocate text
    char *word;
    char current_char;
    bool is_eos, new_word;
    char words[MAX_WORD_COUNT][MAX_LENGTH + 1];

    if (argc == 2)
        text = argv[1];
    else if (true)
    {
        char input_text[MAX_LENGTH + 1];
        printf("Digite a frase: ");
        gets(input_text); // ! use getline ater
        // getline(&input_text, &(MAX_LENGTH), stdin);
        // scanf("%s", input_text);
        text = input_text;
    }
    else
        return ARGC_ERR;

    // get words
    for (is_eos = false, new_word = false, sentinel_count = 0,
        text_char_index = 0, words_index = -1, word_char_index = 0;
         !is_eos && text_char_index < MAX_LENGTH;
         text_char_index++)
    {
        current_char = text[text_char_index];
        // detect new words
        if (current_char == SENTINEL)
        {
            sentinel_count++;
            continue;
        }
        else if (current_char == EOS)
            is_eos = true;
        else if (sentinel_count || !text_char_index)
        {
            sentinel_count = 0;
            new_word = true;
        }

        if (is_eos || new_word)
        {
            new_word = false;
            // end previous word
            if (words_index > 0)
                word[word_char_index] = EOS;

            if (DEBUG && words_index >= 0)
                printf("words[%u] == \"%s\"\n", words_index, word);
            if (is_eos)
                break;

            // spliting
            word_char_index = 0;
            words_index++;
            word = words[words_index];
        }

        word[word_char_index] = current_char;
        word_char_index++;
    }
    words_count = words_index + 1;
    text_size = text_char_index + 1; // with EOS ending

    if (text_size > MAX_LENGTH + 1 || !words_count)
        return TEXT_SIZE_ERR;

    // word
    struct words_summary summary[words_count];
    for (words_index = 0; words_index < words_count; words_count++)
    {
    }

    if (DEBUG)
        printf("\n");
    return OK;
}
