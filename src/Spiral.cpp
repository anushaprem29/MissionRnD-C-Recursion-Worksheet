/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void down(int **arr, int start_rows, int end_rows, int start_columns, int end_columns, int pos_x, int pos_y, int *answer, int pos, int size);
void right(int **arr, int start_rows, int end_rows, int start_columns, int end_columns, int pos_x, int pos_y, int *answer, int pos, int size){
	answer[pos] = arr[pos_x][pos_y];
	if (pos_y == end_columns){
		if (pos == size)	return;
		down(arr, start_rows + 1, end_rows, start_columns, end_columns, pos_x + 1, pos_y, answer, pos + 1, size);
	}
	else
		right(arr, start_rows, end_rows, start_columns, end_columns, pos_x, pos_y + 1, answer, pos + 1, size);
}

void up(int **arr, int start_rows, int end_rows, int start_columns, int end_columns, int pos_x, int pos_y, int *answer, int pos, int size){
	answer[pos] = arr[pos_x][pos_y];

	if (pos_x == start_rows){
		right(arr, start_rows, end_rows, start_columns + 1, end_columns, pos_x, pos_y + 1, answer, pos + 1, size);
	}
	else
		up(arr, start_rows, end_rows, start_columns, end_columns, pos_x - 1, pos_y, answer, pos + 1, size);
}
void left(int **arr, int start_rows, int end_rows, int start_columns, int end_columns, int pos_x, int pos_y, int *answer, int pos, int size){
	answer[pos] = arr[pos_x][pos_y];
	if (pos_y == start_columns){
		up(arr, start_rows, end_rows - 1, start_columns, end_columns, pos_x - 1, pos_y, answer, pos + 1, size);
	}
	else
		left(arr, start_rows, end_rows, start_columns, end_columns, pos_x, pos_y - 1, answer, pos + 1, size);
}
void down(int **arr, int start_rows, int end_rows, int start_columns, int end_columns, int pos_x, int pos_y, int *answer, int pos, int size){
	answer[pos] = arr[pos_x][pos_y];
	if (pos_x == end_rows){
		if (pos == size) return;
		left(arr, start_rows, end_rows, start_columns, end_columns - 1, pos_x, pos_y - 1, answer, pos + 1, size);
	}
	else
		down(arr, start_rows, end_rows, start_columns, end_columns, pos_x + 1, pos_y, answer, pos + 1, size);
}

int *spiral(int rows, int columns, int **input_array)
{
	int *answer;
	if (rows <= 0 || columns <= 0 || input_array == NULL)	return NULL;
	answer = (int *)malloc(sizeof(int)*(rows*columns));
	right(input_array, 0, rows - 1, 0, columns - 1, 0, 0, answer, 0, (rows*columns) - 1);
	return answer;
}