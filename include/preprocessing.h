#ifndef PREPROCESSING_H
#define PREPROCESSING_H

// import utils.h
#include "utils.h"
// function for normazalization
void Normalization(Matrix* Mat){
    const int rows = Mat->rows;
    const int cols = Mat->cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            Mat->data[i*cols+j] /= 255.0f;
        }
    }
}
// and how to reversed value
void ReversedNormalization(Matrix* Mat){
    const int rows = Mat->rows;
    const int cols = Mat->cols;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            Mat->data[i*cols+j] *=255.0f;
        }
    }
}

#endif