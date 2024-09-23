#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10000

typedef struct {
    int rows;
    int cols;
    float* data;
} Matrix;
void printMatrixf(Matrix *Mat,const int size){
    for(int i=0;i<size;i++){
        for(int j =0;j<Mat->cols;j++){
            printf("%.4f",Mat->data[i*Mat->cols+j]);
        }
    }
}
void initializeMatrix(Matrix* matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (float*)malloc(rows * cols * sizeof(float));
    if (matrix->data == NULL) {
        fprintf(stderr, "Error allocating memory for matrix\n");
        exit(1);
    }
}

void freeMatrix(Matrix* mat) {
    free(mat->data);
    mat->rows = 0;
    mat->cols = 0;
    mat->data = NULL;
}

void loadMNISTData(const char* trainFile, const char* testFile, 
                   Matrix* trainingImages, int* trainingLabels, 
                   Matrix* testImages, int* testLabels, 
                   int trainingSize, int testSize) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    char* token;

    // Load training data
    file = fopen(trainFile, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening training file\n");
        exit(1);
    }

    // Skip header
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading header from training file\n");
        fclose(file);
        exit(1);
    }
    // mengambil row yang diambil pada data training
    for (int i = 0; i < trainingSize; i++) {
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            fprintf(stderr, "Error reading line %d from training file\n", i + 1);
            fclose(file);
            exit(1);
        }
        // token ini kita ambil pas ada headernya dengan tipe data character
        token = strtok(line, ",");
        if (token == NULL) {
            fprintf(stderr, "Error parsing label in line %d of training file\n", i + 1);
            fclose(file);
            exit(1);
        }
        trainingLabels[i] = atoi(token);
        // mengatur kolom yang diambil
        for (int j = 0; j < 784; j++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                fprintf(stderr, "Error parsing pixel %d in line %d of training file\n", j + 1, i + 1);
                fclose(file);
                exit(1);
            }
            trainingImages->data[i * trainingImages->cols + j] = atof(token);
        }
    }
    fclose(file);

//     // Load test data
    file = fopen(testFile,"r");
    if(file==NULL){
        fprintf(stderr,"Error opening test file csv\n");
        exit(1);
    }
    // skip header
    if(fgets(line,MAX_LINE_LENGTH,file)==NULL){
        fprintf(stderr, "Error reading header from test file\n");
        fclose(file);
        exit(1);
    }

    for(int i=0;i<testSize;i++){
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            fprintf(stderr, "Error reading line %d from test file\n", i + 1);
            fclose(file);
            exit(1);
        }
        for(int j =0;j<784;j++){
            token = strtok(j == 0 ? line : NULL, ",");
            if (token == NULL) {
                fprintf(stderr, "Error parsing pixel %d in line %d of test file\n", j + 1, i + 1);
                fclose(file);
                exit(1);
            }
            testImages->data[i * testImages->cols + j] = atof(token);
        }
    }


    printf("MNIST data loaded from CSV files\n");
}

#endif // UTILS_H