#ifndef UTILS_TEST_H
#define UTILS_TEST_H

#include "../../include/utils.h"
#include "../../include/preprocessing.h"
#include <stdio.h>

void TransposeMatrixTester(void){
    Matrix data;
    float arrVal[4]={2.0,1.0,4.0,3.0}; 
    initializeMatrix(&data, 2, 2);
    for(int i =0;i<data.rows;i++){
        for(int j =0;j<data.cols;j++){
            data.data[i*data.cols+j] = arrVal[i*data.cols+j];
        }
    }
    printf("-- data sebelum di Transpotasi --\n");
    printMatrixf(&data);
    printf("\n");
    printf("-- data setelah di Transpotasi --\n");
    TransposeMatrix(&data);
    printMatrixf(&data);
    printf("\n");
}

#endif