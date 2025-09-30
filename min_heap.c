//Gilma Sebastian-Mihai 315CA
#include "functions_heap.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void sort_heap(min_heap* heap) {
    int n = heap->size;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (heap->arr[i]->value > heap->arr[j]->value ||
                (heap->arr[i]->value == heap->arr[j]->value &&
                 strcmp(heap->arr[i]->name, heap->arr[j]->name) > 0)) {
                // Swap
                nods* temp = heap->arr[i];
                heap->arr[i] = heap->arr[j];
                heap->arr[j] = temp;
            }
        }
    }
}

nods* extract_min(min_heap* heap) {
    sort_heap(heap); // sortam

    nods* min_node = heap->arr[0];

    for (int i = 1; i < heap->size; i++) {
        heap->arr[i - 1] = heap->arr[i];
    }

    heap->size--;

    return min_node;
}


void insert_heap(min_heap* heap, nods* node) {
    heap->arr[heap->size] = node;
    heap->size++;
    sort_heap(heap);
}



min_heap* create_min_heap(nods* v, int n) {
    min_heap* heap = malloc(sizeof(min_heap));
    heap->arr = malloc(sizeof(nods*) * (2 * n - 1));
    heap->size = n;

    for (int i = 0; i < n; i++) {
        heap->arr[i] = malloc(sizeof(nods));
        *(heap->arr[i]) = v[i];
        heap->arr[i]->left = NULL;
        heap->arr[i]->right = NULL;
    }

    sort_heap(heap);

    while (heap->size > 1) {
        nods* left = extract_min(heap);
        nods* right = extract_min(heap);

        nods* parent = malloc(sizeof(nods));
        parent->left = left;
        parent->right = right;
        parent->value = left->value + right->value;

        parent->name[0] = '\0';  // Initializare pentru strcat
        strcat(parent->name, left->name);
        strcat(parent->name, right->name);

        insert_heap(heap, parent);
    }

    heap->root = heap->arr[0];
    return heap;
    
}


void search_2_recursive(nods* root, char s[200][200], int n, char *best_match, int *min_length) {
    if (root == NULL) return;

    int all_found = 1;
    for (int i = 0; i < n; i++) {
        if (strstr(root->name, s[i]) == NULL) {
            all_found = 0;
            break;
        }
    }

    if (all_found) {
        int len = strlen(root->name);
        if (len < *min_length) {
            *min_length = len;
            strcpy(best_match, root->name);
        }
    }

    search_2_recursive(root->left, s, n, best_match, min_length);
    search_2_recursive(root->right, s, n, best_match, min_length);
}

void search_2(nods* root, char s[200][200], int n, FILE *out) {
    char best_match[200] = "";
    int min_length = 1e9;

    search_2_recursive(root, s, n, best_match, &min_length);

    if (strlen(best_match) > 0) {
        fprintf(out, "%s\n", best_match);
    }
}

void free_tree(nods* node) {
    if (node == NULL) return;

    free_tree(node->left);
    free_tree(node->right);

    // Eliberam nodul doar daca a fost alocat dinamic
    free(node);
}
void free_min_heap(min_heap* heap) {
    if (heap == NULL) return;
    
    // Eliberam toate nodurile din array (doar root-ul e relevant, restul sunt duplicate)
    if (heap->size > 0) {
        free_tree(heap->root); // Elibereaza intregul arbore
    }
    
    free(heap->arr);
    free(heap);
}

void search(nods* root, char *s, char *for_print, FILE *out) 
{
    
    if (root != NULL) {
        char left[200], right[200];
        
        strcpy(left, for_print);
        strcat(left, "0");
        
        strcpy(right, for_print);
        strcat(right, "1");
        
        if (strcmp(root->name, s) == 0) 
            fprintf(out, "%s", for_print);
        
        search(root->left, s, left, out);
        search(root->right, s, right, out);
    }
}

