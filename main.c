//Gilma Sebastian-Mihai 315CA
#include "stdio.h"
#include "functions_heap.h"
#include "case_function.h"
#include "string.h"
#include "stdlib.h"


int main(int argc, char ** argv)
{
    int n;
    nods v[200] = {0};
    
    FILE* in = fopen(argv[2], "rt");
    FILE* out = fopen(argv[3], "wt");
    
    fscanf(in,"%d", &n);


    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &(v[i].value));
        fscanf(in, "%s", v[i].name);
    }
    min_heap* vec = create_min_heap(v, n);
    vec->root = vec->arr[0];


    if (strcmp(argv[1], "-c1") == 0) {
        function_c1(vec, out);
    }
    if (strcmp(argv[1], "-c2") == 0) {
        function_c2(vec, in, out);
    }
    if (strcmp(argv[1], "-c3") == 0) {
        function_c3(vec, in, out);
    }
    if (strcmp(argv[1], "-c4") == 0) {
        function_c4(vec, in, out);
    }
    free_min_heap(vec);
}