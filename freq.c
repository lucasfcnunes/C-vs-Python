#include <stdio.h>
#include <string.h>
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

#define DEBUG 0

#define OK 0
#define ARGC_ERR 1
#define TEXT_SIZE_ERR 2
#define NO_WORDS_ERR 3

typedef struct WordSummary
{
    char word[MAX_LENGTH + 1];
    short unsigned quantity;
} WordSummary;

int main(int argc, const char *argv[])
{
    if (DEBUG)
        printf("argc == %i, argv == \"%s\"\n", argc, argv[1]);

    short unsigned text_char_index, word_char_index, text_size, words_count, sentinel_count, summary_index, unique_words_count;
    short words_index;
    const char *text;
    char *word, current_char, words[MAX_WORD_COUNT][MAX_LENGTH + 1];
    bool is_eos, new_word;

    if (argc == 2)
        text = argv[1];
    else if (true)
    {
        char input_text[MAX_LENGTH + 1];
        printf("Type text to be split by \"%c\": ", SENTINEL);
        gets(input_text); // ! use getline
        // getline(&input_text, &(MAX_LENGTH), stdin);
        // scanf("%s", input_text);
        text = input_text;
    }
    else
        return ARGC_ERR;

    // get words
    for (is_eos = false, new_word = false, sentinel_count = 0,
        text_char_index = 0, words_index = -1, word_char_index = 0;
         ;
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
            // end previous word
            if (words_index >= 0)
            {
                word[word_char_index] = EOS;
                if (DEBUG)
                    printf("words[%u] == \"%s\"\n", words_index, word);
            }

            if (is_eos)
                break;

            // spliting
            new_word = false;
            word_char_index = 0;
            word = words[++words_index];
        }

        word[word_char_index++] = current_char;
    }
    words_count = words_index + 1;
    text_size = text_char_index + 1; // with EOS ending
    if (DEBUG)
        printf("\n");

    if (text_size > MAX_LENGTH + 1)
    {
        printf("ERR: Text size is greater than %u...\n", MAX_LENGTH);
        return TEXT_SIZE_ERR;
    }
    if (words_count < 1)
    {
        printf("ERR: No words in input...\n");
        return NO_WORDS_ERR;
    }

    // make summary
    WordSummary summaries[words_count], *summary;
    long long unsigned matches;
    short unsigned matching_index; //...
    for (words_index = 0, summary_index = -1, matches = 0;
         words_index < words_count;
         words_index++)
    {
        if (1 & (matches >> words_index))
            continue;
        matches += 1 << words_index;
        word = words[words_index];
        summary = &summaries[++summary_index];
        strcpy(summary->word, word);
        summary->quantity = 1;

        for (matching_index = words_index + 1; matching_index < words_count; matching_index++)
        {
            if (1 & (matches >> matching_index))
                continue;
            if (!strcmp(word, words[matching_index]))
            {
                matches += 1 << matching_index;
                summary->quantity++;
            }
        }

        if (DEBUG)
            printf("summaries[%u] == %ux \"%s\"\n", summary_index, summary->quantity, summary->word);
    }
    unique_words_count = summary_index + 1;
    if (DEBUG)
        printf("\n");
    // output
    printf("Words frequencies (as split by greedy \"%c\"):\n", SENTINEL);
    for (summary_index = 0; summary_index < unique_words_count; summary_index++)
    {
        summary = &summaries[summary_index];
        printf("\t%ux \"%s\"\n", summary->quantity, summary->word);
    }

    return OK;
}
