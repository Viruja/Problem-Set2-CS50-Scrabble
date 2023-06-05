#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// capital alphabet
int capital_alphabet[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
//simple alphabet
int simple_alphabet[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0; //score
    for(int i = 0; i < strlen(word); i++) //goes through every letter of the inputs
    {
        if(isupper(word[i])) //checks whether the letter is a capital
        {
            for(int j = 0; j < sizeof(capital_alphabet); j++)
            {
                if (word[i] == capital_alphabet[j]) //checks the index of the letter of input with the array of capital letters
                {
                    score+=POINTS[j]; //increases the value of scores with the points assigned with the index of capital alphabebt array
                    break; //breaks the loop to avoid the increment of value of "j"
                }
            }
        }
        else if (islower(word[i])) //checks whether the letter is a simple
        {
            for(int k = 0; k < sizeof(simple_alphabet); k++)
            {
                if(word[i] == simple_alphabet[k]) //checks the index of the letter of input with the array of simple letters
                {
                    score+=POINTS[k]; //increases the value of scores with the points assigned with the index of simple alphabebt array
                    break; //breaks the loop to avoid the increment of value of "j"
                }
            }
        }
        else{
            i++; //increases the value of "i" to go through the other letters of the input
        }
    }
    return score;
}
