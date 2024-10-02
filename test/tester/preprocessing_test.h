#ifndef PREPROCESSING_TEST_H
#define PREPROCESSING_TEST_H

#include "../../include/utils.h"
#include "../../include/preprocessing.h"
#include <stdio.h>

void NormalizationTester(void){
    Matrix data;
    float arrVal[8]={0.0,0.0,1.0,0.0,0.0,1.0,1.0,1.0}; 
    initializeMatrix(&data, 4, 2);
    for(int i =0;i<data.rows;i++){
        for(int j =0;j<data.cols;j++){
            data.data[i*data.cols+j] = arrVal[i*data.cols+j];
        }
    }
    printf("-- data sebelum di normalization --\n");
    printMatrixf(&data);
    printf("\n");
    printf("-- data setelah di normalization --\n");
    Normalization(&data);
    printMatrixf(&data);
    printf("-- data reveese normalization --\n");
    ReversedNormalization(&data);
    printMatrixf(&data);
    printf("\n");
}

#endif