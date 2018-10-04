#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis.h"

char * ReverseChars(char * Start, char * End)
{
	if (NULL == Start || NULL == End)
		return NULL;

	char * String = Start;
	
	while (End > Start)
	{
		char temp = *Start;
		*Start = *End;
		*End = temp;

		Start++;
		End--;
	}

	return String;
}

char * ReversePhrase(char * phrase)
{
	if (NULL == phrase)
		return NULL;

	char * Start = phrase;
	char * End = phrase;

	while (*End != '\0')
	{
		if (*End == ' ')
		{
			ReverseChars(Start, End - 1);
			Start = End + 1;
		}
		End++;
	}

	//Revese last word
	ReverseChars(Start, End-1);
	//Reverse the whole sentence
	ReverseChars(phrase, End - 1);

	return phrase;
}

void FrequencyCount(char s[], int count[]) {
    int c = 0;

    while (s[c] != '\0') {
        if(s[c] >= 'a' && s[c] <= 'z')
            count[s[c]-'a']++;
        c++;
    }
}


int Compare (void const *a, void const *b)
{
   letter_occ *l1 = (letter_occ *)a;
   letter_occ *l2 = (letter_occ *)b;
    return ( l2->count - l1->count);
}