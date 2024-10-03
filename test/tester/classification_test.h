#ifndef CLASSIFICATION_TEST_H
#define CLASSIFICATION_TEST_H

#include "../../include/utils.h"
#include "../../include/preprocessing.h"
#include "../../include/ML/classfication.h"
#include <stdio.h>

void LogisticRegressionTest(void) {
    // Inisialisasi data X dan y
    Matrix X;
    Matrix y;
    float arrVal[8] = {0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0};  // Data input X (4 sampel, 2 fitur)
    float y_data[] = {0.0, 0.0, 1.0, 1.0};  // Label y (4 sampel)

    // Inisialisasi matrix X (4x2) dan y (4x1)
    initializeMatrix(&X, 4, 2);
    initializeMatrix(&y, 4, 1);

    // Mengisi nilai X dengan data arrVal[]
    for (int i = 0; i < X.rows; i++) {
        for (int j = 0; j < X.cols; j++) {
            X.data[i * X.cols + j] = arrVal[i * X.cols + j];
        }
    }

    // Mengisi nilai y dengan data y_data[]
    for (int i = 0; i < y.rows; i++) {
        y.data[i] = y_data[i];  // y hanya memiliki satu kolom
    }

    // Cetak data X dan y untuk pengecekan
    printf("Input Data X:\n");
    printMatrixf(&X);
    printf("Label y:\n");
    printMatrixf(&y);

    // Hyperparameters
    float learningRate = 0.001;
    int epochs = 100;

    // Inisialisasi weights dan bias
    float* weights = (float*)calloc(X.cols, sizeof(float));  // Inisialisasi weights dengan 0
    float bias = 0;  // Inisialisasi bias dengan 0

    // Train model Logistic Regression
    LogisticRegression(&X, &y, weights, &bias, learningRate, epochs);

    // Cetak bobot hasil pelatihan
    printf("Trained Weights:\n");
    for (int i = 0; i < X.cols; i++) {
        printf("Weight %d: %.4f\n", i, weights[i]);
    }
    printf("Trained Bias: %.4f\n", bias);

    // Lakukan prediksi
    printf("Predictions:\n");
    predictAll(&X, weights, bias);  // Melakukan prediksi pada seluruh data

    // Bersihkan memori
    free(weights);
}


#endif