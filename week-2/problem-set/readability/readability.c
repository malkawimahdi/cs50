#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Counts the number letters within a string.
int letterCount(const string text)
{
    int text_length = strlen(text);

    int letter_count = 0;

    for (int counter = 0; counter <= text_length; ++counter)
    {
        //Converts characters to ASCII equavialents to perform check.
        if ((text[counter] >= 'a' && text[counter] <= 'z') | (text[counter] >= 'A' && text[counter] <= 'Z'))
        {
            ++letter_count;
        }
    }

    return letter_count;
}

//Counts the number of words within a string.
int wordCount(const string text)
{
    int text_length = strlen(text);

    int space_count = 0;

    for (int counter = 0; counter <= text_length; ++counter)
    {
        //Checks for ASCII space character.
        if (text[counter] == 32)
        {
            ++space_count;
        }
    }

    return space_count + 1;
}

//Counts the number of sentences within a string.
int sentenceCount(const string text)
{
    int text_length = strlen(text);

    int sentence_count = 0;

    for (int counter = 0; counter <= text_length; ++counter)
    {
        //Checks for these symbols: !, ?, .
        if ((text[counter] == 33) | (text[counter] == 46) | (text[counter] == 63))
        {
            ++sentence_count;
        }
    }

    return sentence_count;
}

//Coleman-Liau Index to calculate reading age.
float colemanLiauIndex(int letter_count, int word_count, int sentence_count)
{
    float average_words_per_sentence = (float) sentence_count / (float) word_count;

    float average_letters_per_word = (float) letter_count / (float) word_count;

    float L = average_letters_per_word * 100.0;
    float S = average_words_per_sentence * 100.0;

//Coleman-Liau Index formula.
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    return index;
}

int main(void)
{
    string text = get_string("Text: ");

//Conditional statements to check the reading age.
    if ((int) round(colemanLiauIndex(letterCount(text), wordCount(text), sentenceCount(text))) < 1)
    {
        printf("Before Grade 1\n");
    }

    else if ((int) round(colemanLiauIndex(letterCount(text), wordCount(text), sentenceCount(text))) >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %d\n", (int) round(colemanLiauIndex(letterCount(text), wordCount(text), sentenceCount(text))));
    }
}

