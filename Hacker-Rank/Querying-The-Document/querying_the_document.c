/*  Problem Statement: https://www.hackerrank.com/challenges/querying-the-document/problem
    Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

static char* get_input_text(void);
static char**** get_document(char*);
static char* kth_word_in_mth_sentence_of_nth_paragraph(char****,int,int,int);
static char** kth_sentence_in_mth_paragraph(char****,int,int);
static char*** kth_paragraph(char****,int);
static void print_word(char*);
static void print_sentence(char**);
static void print_paragraph(char***);
// static void free_memory(char****);

int main(void) {
    char* text = get_input_text();
    char**** document = get_document(text);
    int q;
    scanf("%d", &q);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }
        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }
        else {
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
    free(text);
    // free_memory(document);
    return EXIT_SUCCESS;
}

static char* get_input_text(void) {	
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

static char**** get_document(char* text) {
    size_t raw_doc_len = strlen(text);
    char temp_container[MAX_CHARACTERS];
    char *encountered_word = NULL;
    char **total_words = NULL;
    char ***total_sentences = NULL;
    char ****total_paragraphs = NULL;
    size_t word_count,sentence_count,paragraph_count;
    paragraph_count = sentence_count = word_count = 0;
    memset(temp_container,'\0',(sizeof(char)*MAX_CHARACTERS));
    for(size_t i = 0, index = 0; i <= raw_doc_len; ++i) {
        switch(text[i]) {
            case ' ':
                ++word_count;
                temp_container[index] = '\0';
                size_t word_len = strlen(temp_container) + 1;
                encountered_word = calloc(word_len,sizeof(char));
                if(encountered_word) {
                    memcpy(encountered_word,temp_container,(sizeof(char) * word_len));
                    memset(temp_container,'\0',(sizeof(char) * MAX_CHARACTERS));
                    total_words = realloc(total_words,(sizeof(char*) * word_count));
                    if(total_words) {
                        total_words[word_count - 1] = encountered_word;
                        index = 0;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate the memory to **total_words\n", __LINE__);
                    }
                } else {
                    fprintf(stderr,"%u: Not able to allocate %lu bytes of memory to *encountered_word\n", __LINE__,(sizeof(char) * word_len));
                }
                break;
            case '.':
                ++sentence_count;
                ++word_count;
                temp_container[index] = '\0';
                word_len = strlen(temp_container) + 1;
                encountered_word = calloc(word_len,sizeof(char));
                if(encountered_word) {
                    memcpy(encountered_word,temp_container,(sizeof(char) * word_len));
                    memset(temp_container,'\0',(sizeof(char) * MAX_CHARACTERS));
                    total_words = realloc(total_words,(sizeof(char*) * word_count));
                    if(total_words) {
                        total_words[word_count - 1] = encountered_word;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate memory to **total_words\n", __LINE__);
                    }
                } else {
                    fprintf(stderr,"%u: Not able to allocate memory %lu bytes of memory to *encountered_word\n", __LINE__,(sizeof(char) * word_len));
                }
                total_sentences = realloc(total_sentences,(sizeof(char**) * sentence_count));
                if(total_sentences) {
                    total_sentences[sentence_count - 1] = total_words;
                    total_words = NULL;
                } else {
                    fprintf(stderr,"%u: Not able to allocate memory to **total_sentences\n", __LINE__);
                }
                word_count = 0;
                index = 0;
                break;
            case '\n':
            case '\0':
                ++paragraph_count;
                total_paragraphs = realloc(total_paragraphs,(sizeof(char***) * paragraph_count));
                if(total_paragraphs) {
                    total_paragraphs[paragraph_count - 1] = total_sentences;
                    total_sentences = NULL;
                    sentence_count = 0;
                } else {
                    fprintf(stderr,"%u: Not able to allocate memory to ***total_paragraphs\n", __LINE__);
                }
                break;
            default:
                temp_container[index++] = text[i];
                break;
        }
    }
    return total_paragraphs;
}

static char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

static char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m - 1][k - 1];
}

static char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

static void print_word(char* word) {
    printf("%s", word);
}

static void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

static void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}