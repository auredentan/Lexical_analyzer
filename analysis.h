#ifndef ANALYSIS_H_
#define ANALYSIS_H_

typedef struct {
    int count;
    char letter;
} letter_occ;

// Reverse characters
char * ReverseChars(char * Start, char * End);

// Reverse phrase
char * ReversePhrase(char * phrase);

// Return the number of occurence of each letter 
// in alphabetical order
void FrequencyCount(char s[], int count[]);

// Comparison function to give to qsort
// (we sort by letter count here)
int Compare (void const *a, void const *b);

#endif