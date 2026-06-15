// A document is represented as a collection paragraphs, a paragraph is represented as a collection of sentences, a sentence is represented as a collection of words and a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters.

// You will convert a raw text document into its component paragraphs, sentences and words. To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.

// Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:

// A word is described by char *word.
// A sentence is described by char **sentence. The words in the sentence are separated by one space (" "). The last word does not end with a space(" ").
// A paragraph is described by char ***paragraph. The sentences in the paragraph are separated by one period (".").
// A document is described by char ****document. The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(
    char**** document, int k, int m, int n) 
{
    return document[n - 1][m - 1][k - 1];
}
char** kth_sentence_in_mth_paragraph(
    char**** document, int k, int m) 
{
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char**** get_document(char* text) {
    char**** document = NULL;
    int p_count = 0;

    char *save_p;
    char *paragraph = strtok_r(text, "\n", &save_p);

    while (paragraph) {
        document = realloc(document, (p_count + 1) * sizeof(char***));
        document[p_count] = NULL;

        int s_count = 0;
        char *save_s;
        char *sentence = strtok_r(paragraph, ".", &save_s);

        while (sentence) {
            document[p_count] = realloc(
                document[p_count],
                (s_count + 1) * sizeof(char**)
            );
            document[p_count][s_count] = NULL;

            int w_count = 0;
            char *save_w;
            char *word = strtok_r(sentence, " ", &save_w);

            while (word) {
                document[p_count][s_count] = realloc(
                    document[p_count][s_count],
                    (w_count + 1) * sizeof(char*)
                );

                document[p_count][s_count][w_count] = malloc(strlen(word) + 1);
                strcpy(document[p_count][s_count][w_count], word);

                w_count++;
                word = strtok_r(NULL, " ", &save_w);
            }

            s_count++;
            sentence = strtok_r(NULL, ".", &save_s);
        }

        p_count++;
        paragraph = strtok_r(NULL, "\n", &save_p);
    }

    return document;

}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}