#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store vowel counts
struct VowelCounts {
    int a, e, i, o, u, other, total;
};

void initializeCounts(struct VowelCounts *counts) {
    counts->a = 0;
    counts->e = 0;
    counts->i = 0;
    counts->o = 0;
    counts->u = 0;
    counts->other = 0;
    counts->total = 0;
}

int main() {
    FILE *outputFile = fopen("myword.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    struct VowelCounts counts;
    initializeCounts(&counts);

    printf("Enter words (Ctrl+D to end input):\n");

    char word[100];
    while (scanf("%s", word) != EOF) { //check the word using switch case
        int totalLetters = 0;

        for (int i = 0; word[i] != '\0'; i++) {
            char currentChar = tolower(word[i]);

            if (isalpha(currentChar)) {
                totalLetters++;

                switch (currentChar) {
                    case 'a':
                        counts.a++;
                        break;
                    case 'e':
                        counts.e++;
                        break;
                    case 'i':
                        counts.i++;
                        break;
                    case 'o':
                        counts.o++;
                        break;
                    case 'u':
                        counts.u++;
                        break;
                    default:
                        counts.other++;
                        break;
                }
            }
        }

        fprintf(outputFile, "%s %d %d %d %d %d %d %d\n", word, counts.a, counts.e, counts.i, counts.o, counts.u, counts.other, totalLetters);
        
        initializeCounts(&counts); //reset value for next word
    }

    fclose(outputFile);
    printf("Results written to 'myword.txt'.\n");

    return 0;
}
