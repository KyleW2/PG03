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

void swap(float *a, float *b) {
  float t = *a;
  *a = *b;
  *b = t;
}

void bubble_sort(float* array, int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
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
            bubble_sort(array, length_of_array);

            // Write to output
            write_array(output_file, length_of_array, array);
           break;
    };
    return 0;
}