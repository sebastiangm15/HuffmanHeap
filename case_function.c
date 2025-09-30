//Gilma Sebastian-Mihai 315CA
#include "functions_heap.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct queue_node {
    nods* tree_node;
    int level;
} queue_node;

void function_c1(min_heap *heap, FILE *out) {
    if (!heap || !heap->root) return;

    // Coada pentru BFS
    queue_node bfs_queue[1000];
    int start = 0, end = 0;

    int last_printed_level = -1;

    // Adaugam radacina la nivelul 0
    bfs_queue[end++] = (queue_node){heap->root, 0};

    while (start < end) {
        queue_node current = bfs_queue[start++];
        nods* node = current.tree_node;
        int level = current.level;

        // Daca am trecut la un nivel nou începem o linie noua
        if (level != last_printed_level) {
            if (last_printed_level != -1) {
                fprintf(out, "\n");
            }
            last_printed_level = level;
        }

        // Afisam valoarea și numele nodului
        fprintf(out, "%d-%s ", node->value, node->name);

        // Adaugam copii în coada daca exista
        if (node->left) {
            bfs_queue[end++] = (queue_node){node->left, level + 1};
        }
        if (node->right) {
            bfs_queue[end++] = (queue_node){node->right, level + 1};
        }
    }

    fprintf(out, "\n");
}



void function_c2(min_heap *vec, FILE *in, FILE *out) 
{
    int n;
    fscanf(in, "%d", &n);

    for (int i = 0; i < n; i++) {
        char k[1001];  // conform restrictiei: codificare <= 1000 caractere
        fscanf(in, "%s", k);

        nods* root = vec->root;
        int len = strlen(k);

        for (int j = 0; j < len; j++) {
            if (k[j] == '0') {
                root = root->left;
            } else if (k[j] == '1') {
                root = root->right;
            }

            // daca am ajuns intr-o frunza o afisam si resetam
            if (root->left == NULL && root->right == NULL) {
                fprintf(out, "%s ", root->name);
                root = vec->root;
            }
        }

        fprintf(out, "\n");
    }
}


void function_c3(min_heap *vec, FILE *in, FILE *out) 
{
    int n;
    fscanf(in,"%d", &n);

    for(int i = 0; i < n; i++) {
        char s[20], k[20] = {0};
        fscanf(in, "%s", s);
        search(vec->root, s, k, out);

    }
    fprintf(out, "\n");

}

void function_c4(min_heap *vec, FILE *in,FILE *out) 
{
    int n;
    char mat[200][200];
    fscanf(in,"%d", &n);

    for(int i = 0; i < n; i++) {
        
        char s[200];
        
        fscanf(in, "%s", s);
        strcpy(mat[i], s);

    }
    search_2(vec->root, mat, n, out);
    printf("\n");

}