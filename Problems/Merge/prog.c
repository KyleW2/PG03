#include <stdio.h>
#include <stdlib.h>

int get_input_length(char* input_file) {
    int length;
    FILE* fp = fopen(input_file, "r");

    fscanf(fp, "%d", &length);

    fclose(fp);
    //printf("length: %d\n", length);
    return length;
}

void load_input_to_array(char* input_file, float* array) {
    FILE* fp = fopen(input_file, "r");

    int skip;
    fscanf(fp, "%d", &skip);

    int i = 0;
    float holder;
    while(fscanf(fp, "%f", &holder) != EOF) {
        array[i] = holder;
        //printf("%f\n", array[i]);
        i++;
    }

    fclose(fp);
}

void merge(float* arr, int l, int m, int r)
{
    // Get the index of each half
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Make temp arrays
    float L[n1];
    float R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge temp arrays
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(float* arr, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void write_array(char* output_file, int length, float* array) {
    FILE* fp = fopen(output_file, "w");

    fprintf(fp, "%d\n", length);

    for(int i = 0; i < length; i++) {
        fprintf(fp, "%f\n", array[i]);
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    switch(argc) {
        case 1:
            printf("Please enter an input and output file.");
            break;
        case 2:
            printf("Please enter an input and output file.");
            break;
        case 3:;
            // Get file names
            char* input_file = argv[1];
            char* output_file = argv[2];

            // Create array
            int length_of_array = get_input_length(input_file);
            float* array = (float*)malloc(sizeof(float) * length_of_array);
            load_input_to_array(input_file, array);

            // Sort array
            merge_sort(array, 0, length_of_array - 1);

            // Write to output
            write_array(output_file, length_of_array, array);
           break;
    };
    return 0;
}