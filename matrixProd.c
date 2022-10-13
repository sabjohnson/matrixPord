//
//  hw2task3b.c
//  workspace
//
//  Created by Sabrina Johnson on 10/5/22.
//

#include <stdio.h>


void ArrayMult(int rowOrig, int colOrig, int orig[rowOrig][colOrig], int trans[colOrig][rowOrig], int (*prod)[rowOrig][rowOrig]){
    int sum = 0;
    
    // multiplies and places values in array
    for(int row = 0; row < rowOrig; row++){ // incriments the rows
        for(int col = 0; col < rowOrig; col++){ // increments the columns
            sum = 0;
            for(int k = 0; k < colOrig; k++){
                //printf("(%d * %d) + ", orig[row][k], trans[k][col]);
                sum += (orig[row][k] * trans[k][col]);
            }
            (*prod)[row][col] = sum;
            //printf("%d ", sum);
        }
    }
    
    
    
}

void transpose(int row, int col, int arr[row][col], int (*ptr)[col][row]){
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            (*ptr)[j][i] = arr[i][j];
        }
    }
    
    printf("transpose array: \n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            int x = (*ptr)[i][j];
            printf("%d ", x);
        }
        printf("\n");
    }
    printf("\n");
    
}

int main (void) {
    int arr[3][2] = {
        {1, 3},    // row 1
        {2, 3}, // row 2
        {4, 1}  // row 3
    };
    
    printf("original array: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // create transpose array
    int (*ptr)[2][3];
    int arrNew[2][3];
    ptr = &arrNew;
    transpose(3, 2, arr, ptr);
    
    // create product array
    int (*prod)[3][3];
    int arrProd[3][3];
    prod = &arrProd;
    ArrayMult(3, 2, arr, arrNew, prod);
    
    // print arr
    printf("prod array: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arrProd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
