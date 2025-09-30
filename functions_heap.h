//Gilma Sebastian-Mihai 315CA
#pragma once
#include "stdio.h"


typedef struct nods {
    int value;
    char name[250];
    struct nods* right;
    struct nods* left;
} nods;

// struct pentru min_heap
typedef struct {
    nods** arr; // vector de pointeri la nods
    int size;
    nods* root;
} min_heap;

// Function declarations
void sort_heap(min_heap* heap);

nods* extract_min(min_heap* heap);

void insert_heap(min_heap* heap, nods* node);

min_heap* create_min_heap(nods *v, int n);

void search_2_recursive(nods* root, char s[200][200], int n, char *best_match, int *min_length);

void search_2(nods* root, char s[200][200], int n, FILE *out);

void search(nods* root, char *s, char *for_print, FILE *out);

void free_min_heap(min_heap* heap);

void free_tree(nods* node);


