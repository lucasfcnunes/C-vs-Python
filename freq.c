#include <stdio.h>
//#include <stdbool.h>

typedef enum
{
    false,
    true
} bool;

#define EOS '\0'
#define MAX_LENGTH 80

#define DEBUG 1

#define OK 0
#define ARGC_ERR 1

int main(int argc, const char *argv[])
{
    if (DEBUG)
        printf("argc=%i argv=%s\n", argc, *argv);

    unsigned text_char_index, words_index, word_char_index;
    const char *text;
    char *word;
    bool new_word = true;
    bool terminate = false;
    char words[MAX_LENGTH + 1][MAX_LENGTH + 1]; // assume it's filled with EOSs

    if (argc >= 1)
        text = argv[1];
    else
        return ARGC_ERR;

    // get words
    for (
        text_char_index = 0, words_index = 0;
        text[text_char_index] != EOS ||
        text_char_index < MAX_LENGTH;
        text_char_index++)
    {
        // spliting
        if (text[text_char_index] == ' ')
        {
            new_word = true;
            continue;
        }
        // start new word
        if (new_word)
        {
            if (words_index > 0)
            {
                word[word_char_index + 1] = EOS;
                if (DEBUG)
                    printf("word #%u: %s\n", words_index, word);
            }
            //
            new_word = false;
            words_index++;
            word_char_index = 0;
            word = words[words_index];
            // end previous word
        }

        word[word_char_index] = text[text_char_index];
        word_char_index++;
    }
    //word[word_char_index + 1] = EOS;

    return OK;
}
