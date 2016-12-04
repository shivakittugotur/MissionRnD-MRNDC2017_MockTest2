/*

Four kids sat in a circle like around a carrom board. Between them there is an image.
Each will get a chance to throw the coin which contains L, R

If coin shows L, The image is rotated anticlockwise direction i.e, -90 deg
If coin shows R, The image is rotated clockwise direction i.e, +90 deg

Input is the 2-D Array where each integer represents each pixel of an image,

All the coin throws are given in form of string like "LLRLLRRLR" (case insensitive)

How would the image look after applying all the rotations ?

Example: If the string is "LL",

Then after one rotation .

1	2	3				3	6	9
4	5	6    ---->			2	5	8
7	8	9				1	4	7

Another one left rotation

3	6	9				9	8	7
2	5	8	----->			6	5	4
1	4	7				3	2	1

So final answer after applying "LL" rotations is

1	2	3	  o/p			9	8	7
4	5	6    ---->			6	5	4
7	8	9				3	2	1

NOTES:
1. Dice throws is case insensitive ex: "lRrL"
2. Given 2-D array is square array.
3. Order of matrix can be < 500.
4. No need to return anything. Manipulate input array itself.
5. Len is the number of rows/cols of the 2d array.

Constraints :
0<=len<=500
0<=strlen(seq)<=500
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void rrotatematrix(int**a, int l){
	int **b = (int**)malloc(l*sizeof(int*));
	for (int i = 0; i < l; i++){
		b[i] = (int*)malloc(l*sizeof(int));
	}
	for (int i = l - 1; i >= 0; i--)
		for (int j = 0; j<l; j++)
			b[j][l - i - 1] = a[i][j];
	for (int i = 0; i < l; i++){
		for (int j = 0; j < l; j++){
			a[i][j] = b[i][j];
		}
	}

}
void lrotateMatrix(int **a, int l)
{
	for (int x = 0; x < l / 2; x++){
		for (int y = x; y < l - x - 1; y++){
			int t = a[x][y];
			a[x][y] = a[y][l - 1 - x];
			a[y][l - 1 - x] = a[l - 1 - x][l - 1 - y];
			a[l - 1 - x][l - 1 - y] = a[l - 1 - y][x];
			a[l - 1 - y][x] = t;
		}
	}
}
void rotateArray(int **arr, int len, char *seq)
{
	//Manipulate input array for output
	if (len < 500){
		if (arr == NULL || len <= 0)
			return ;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < strlen(seq); i++){
			if (seq[i] == 'l' || seq[i] == 'L')
				c1++;
			else if (seq[i] == 'r' || seq[i] == 'R')
				c2++;

		}
		if (c1 == c2)
			return;
		if (c1 > c2){
			for (int i = 0; i < c1 - c2; i++){
				lrotateMatrix(arr, len);
			}
		}
		else{
			for (int i = 0; i < c2 - c1; i++){
				rrotatematrix(arr, len);
			}
		}


	}

}
