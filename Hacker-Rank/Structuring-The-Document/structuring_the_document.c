/*  Problem Statement: https://www.hackerrank.com/challenges/structuring-the-document/problem
    Author: striker
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count; //denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data;
    int sentence_count; //denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count; //denotes number of paragraphs in a document
};

typedef struct word word_t;
typedef struct sentence sentence_t;
typedef struct paragraph paragraph_t;
typedef struct document document_t;

static document_t get_document(char*);
static word_t kth_word_in_mth_sentence_of_nth_paragraph(document_t,int,int,int);
static sentence_t kth_sentence_in_mth_paragraph(document_t,int,int);
static paragraph_t kth_paragraph(document_t,int);
static void print_word(word_t);
static void print_sentence(sentence_t);
static void print_paragraph(paragraph_t);
static char* get_input_text(void);
static void free_memory(document_t*);

int main(void) {
    char* text = get_input_text();
    struct document Doc = get_document(text);  
    int q;
    scanf("%d", &q);
    while (q--) {
        int type;
        scanf("%d", &type);
        if(type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }
        else if(type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }
        else {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
   free(text);
   free_memory(&Doc);
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

static struct document get_document(char* text) {
    int w_count,sen_count,para_count;
    w_count = sen_count = para_count = 0;
    word_t *total_words = NULL;
    sentence_t *total_sentences = NULL;
    paragraph_t *total_paragraphs = NULL;
    size_t text_len = strlen(text);
    char *const temp_container = calloc(sizeof(char),MAX_CHARACTERS);
    if(temp_container) {
        for(int i = 0, index = 0; i <= text_len; ++i) {
            switch(text[i]) {
                case ' ':
                    temp_container[index] = '\0';
                    size_t word_len = strlen(temp_container);
                    char *encountered_word = calloc(sizeof(char),(word_len + 1));
                    memcpy(encountered_word,temp_container,(sizeof(char) * word_len + 1));
                    memset(temp_container,'\0',(sizeof(char) * MAX_CHARACTERS));
                    index = 0;
                    ++w_count;
                    total_words = realloc(total_words,(sizeof(word_t) * w_count));
                    if(total_words) {
                        total_words[w_count - 1].data = encountered_word;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate memort to *total-words\n", __LINE__);
                    }
                    break;
                case '.':
                    ++sen_count;
                    temp_container[index] = '\0';
                    word_len = strlen(temp_container);
                    encountered_word = calloc(sizeof(char),(word_len + 1));
                    memcpy(encountered_word,temp_container,(sizeof(char) * word_len + 1));
                    memset(temp_container,'\0',(sizeof(char) * MAX_CHARACTERS));
                    ++w_count;
                    total_words = realloc(total_words,(sizeof(word_t) * w_count));
                    if(total_words) {
                        total_words[w_count - 1].data = encountered_word;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate memory to *total-words\n", __LINE__);
                    }
                    total_sentences = realloc(total_sentences,(sizeof(sentence_t) * sen_count));
                    if(total_sentences) {
                        total_sentences[sen_count - 1].data = total_words;
                        total_sentences[sen_count - 1].word_count = w_count;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate memory to *total-sentences\n", __LINE__);
                    }
                    w_count = 0;
                    total_words = NULL;
                    index = 0;
                    break;
                case '\n':
                case '\0':
                    ++para_count;
                    total_paragraphs = realloc(total_paragraphs,(sizeof(paragraph_t) * para_count));
                    if(total_paragraphs) {
                        total_paragraphs[para_count - 1].data = total_sentences;
                        total_paragraphs[para_count - 1].sentence_count = sen_count;
                    } else {
                        fprintf(stderr,"%u: Not able to allocate memory to *total-paragraphs\n", __LINE__);
                    }
                    total_sentences = NULL;
                    sen_count = 0;
                    break;
                default:
                    temp_container[index++] = text[i];
                    break;
            }
        }
    } else {
        fprintf(stderr,"%u: Not able to allocate %lu bytes of memory to *temp-containter\n", __LINE__,(sizeof(char) * MAX_CHARACTERS));
    }
    document_t doc;
    doc.data = total_paragraphs;
    doc.paragraph_count = para_count;
    free(temp_container);
    return doc;
}

static struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

static struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

static struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

static void print_word(struct word w) {
    printf("%s", w.data);
}

static void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

static void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++) {
        print_sentence(para.data[i]);
        printf(".");
    }
}

static void free_memory(document_t *doc) {
    size_t i,j,k;
    for(i = 0; i < (doc->paragraph_count); ++i) {
        for(j = 0; j < (doc->data[i].sentence_count); ++j) {
            for(k = 0; k < (doc->data[i].data[j].word_count); ++k) {
                free(doc->data[i].data[j].data[k].data);
            }
            free(doc->data[i].data[j].data);
        }
        free(doc->data[i].data);
    }
    free(doc->data);
}