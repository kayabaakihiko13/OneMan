#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
// include system library
#include <stdio.h>
#include <math.h>
#include <omp.h>
// own matrix
#include "../utils.h"

#define NUM_THEREAT 4
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


void LogisticRegression(Matrix* X, Matrix* y, float* weights, float* bias, float learningRate, int epochs) {
    int n = X->rows;
    int m = X->cols; 

    // Initialize gradient storage
    float* gradient_weight = (float*)calloc(m, sizeof(float));  // Gradient for weights

    // Loop for each epoch
    for (int epoch = 0; epoch < epochs; epoch++) {
        // Reset gradient
        for (int j = 0; j < m; j++) {
            gradient_weight[j] = 0;
        }
        float db = 0;  // Reset gradient for bias

        // Parallelize the loop over the data points
        #pragma omp parallel for reduction(+:db)
        for (int i = 0; i < n; i++) {
            float y_hat = predict(X, weights, *bias, i);  // Predict y_hat for data point i

            // Use critical to prevent race conditions on gradient_weight updates
            #pragma omp critical
            {
                for (int j = 0; j < m; j++) {
                    gradient_weight[j] += (y_hat - y->data[i]) * X->data[i * X->cols + j];  // Gradient w.r.t weights
                }
            }
            db += (y_hat - y->data[i]);  // Gradient w.r.t bias
        }

        // Update weights and bias
        for (int j = 0; j < m; j++) {
            // Update weights
            weights[j] -= learningRate * gradient_weight[j] / n;  
        }
        // update bias
        *bias -= learningRate * db / n;  
    }

    // Clean up allocated memory
    free(gradient_weight);
}

void predictAll(Matrix* X, float* weights, float bias) {
    printf("Predictions:\n");
    for (int i = 0; i < X->rows; i++) {
        float prob = predict(X, weights, bias, i);  // Probabilitas dari sigmoid
        printf("Data %d => Probabilitas: %.4f\n", i, prob);
    }
}
#endif