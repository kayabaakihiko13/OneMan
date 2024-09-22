#include <stdio.h>
#include "../include/utils.h"

#define TRAINING_SAMPLES 42000
#define TEST_SAMPLES 28000
#define INPUT_SIZE 784
#define EPOCHS 50
#define LEARNING_RATE 0.005

int main(){
    Matrix trainData;
    Matrix testData;
    initializeMatrix(&trainData, TRAINING_SAMPLES, INPUT_SIZE);
    initializeMatrix(&testData, TEST_SAMPLES, INPUT_SIZE);
    printf("result of image train data\n");
    printMatrixf(&trainData, TRAINING_SAMPLES);
    printf("\n");
    return 0;
}