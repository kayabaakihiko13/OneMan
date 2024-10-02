#ifndef CLASSIFICATION_TEST_H
#define CLASSIFICATION_TEST_H

#include "../../include/utils.h"
#include "../../include/preprocessing.h"
#include "../../include/ML/classfication.h"
#include <stdio.h>

void LogisticRegressionTest(void){
    Matrix X;
    Matrix y;
    float arrVal[8]={0.0,0.0,1.0,0.0,0.0,1.0,1.0,1.0}; 
    float y_data[] = {0, 0, 1, 0};
    initializeMatrix(&X, 4, 2);
    initializeMatrix(&y, 4, 1);
    for(int i =0;i<X.rows;i++){
        for(int j =0;j<X.cols;j++){
            X.data[i*X.cols+j] = arrVal[i*X.cols+j];
     
        }
    }
    for(int i =0;i<y.rows;i++){
        for(int j =0;j<y.cols;j++){
            y.data[i*y.cols+j] = arrVal[i*y.cols+j];
     
        }
    }
    printMatrixf(&X);
    // Inisialisasi bobot dan bias
    float weights[X.cols];
    for (int i = 0; i < X.cols; i++) {
        weights[i] = 0;
    }
    float bias = 0;

    // Hyperparameters
    float learningRate = 0.001;
    int epochs = 100;

    // Train model
    LogisticRegression(&X, &y, learningRate, epochs, weights, &bias);

    // Prediksi untuk data setelah training
    predictAll(&X, weights, bias);

}  

#endif