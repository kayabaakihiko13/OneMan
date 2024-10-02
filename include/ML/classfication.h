#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
// include system library
#include <stdio.h>
#include <math.h>
// own matrix
#include "../utils.h"


// for logitic regression
float sigmoid(float z){
    return 1/(1+exp(-z));
}

float predict(Matrix* X,float* weights,float bias,int rows){
    float z = bias;
    for (int i = 0; i < X->cols; i++) {
        // w*x + b
        z += X->data[rows * X->cols + i] * weights[i];
    }
    return sigmoid(z);
}


void LogisticRegression(Matrix* X, Matrix* y, float learningRate, int epochs, float* weights, float* bias){
    int n = X->rows;
    int m = X->cols;
    // looping berdasarkan learning rate
    for(int epoch=0;epoch<epochs;epoch++){
        float weight[m];
        float db = 0;
        // inisial gradien
        for(int j=0;j<m;j++){
            weight[j] = 0; 
        }
        // iterasi pada tiap data
        for (int i = 0; i < n; i++) {
            float y_hat = predict(X, weights, *bias, i); // Prediksi y_hat

            // Hitung gradien
            for (int j = 0; j < m; j++) {
                weight[j] += (y_hat - y->data[i]) * X->data[i * X->cols + j]; // Gradient w.r.t weights
            }
            db += (y_hat - y->data[i]);  // Gradient w.r.t bias
        }
        // update bias dan weight
        for(int j=0;j<m;j++){
            weights[j] -= learningRate*weight[j]/n;
        }
        *bias -= learningRate * db/ n;
    }
}
void predictAll(Matrix* X, float* weights, float bias) {
    printf("Predictions:\n");
    for (int i = 0; i < X->rows; i++) {
        float prob = predict(X, weights, bias, i);  // Probabilitas dari sigmoid
        int pred = prob >= 0.5 ? 1 : 0;  // Klasifikasi biner (0 atau 1)
        printf("Data %d => Probabilitas: %.4f, Prediksi: %d\n", i, prob, pred);
    }
}


#endif