#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis.h"


int main()
{
    // A 50*1000 words + 1000 spaces max size phrase
    char phrase[51000];
    
    // get user input
    printf("Enter your Phrase:\n");
    scanf("%[^\n]%*c", phrase);

    // Reverse every word and then reverse the whole 
    ReversePhrase(phrase);

    printf("Reversed phrase: %s\n", phrase);

    int count[50000] = {0};
    letter_occ occurrences[26];
    
    // Letter frequency sort
    printf("\nFrequency by letter \n");
    FrequencyCount(phrase, count);

    for (int c=0; c<26; c++)
        if(count[c]!=0) {
            printf("%c \t%d\n", c + 'a', count[c]);
            occurrences[c].letter = c + 'a';
            occurrences[c].count = count[c];
        }

    // Sorting by occurrences
    qsort(occurrences, 26, sizeof(letter_occ), *Compare);

    printf("\nFrequency by occurrence \n");
    for(int i=0; i<26; i++){
        if(occurrences[i].count !=0){
            printf("%c \t%i\n", occurrences[i].letter, occurrences[i].count);
        }
    }

	return 0;
}
