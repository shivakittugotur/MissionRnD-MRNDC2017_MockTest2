/*

Akash is genius reverse engineer, invented a world demanded machine and Kept in a secret building with a passkey.
Sam is very excited to see his wonderful creation. So, she went to the building with the pass key which is a
numeric code example "547". But there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door.

First door pass key is the largest number that can be formed by given passkey -> 754
Second door pass key is the next largest number that can be formed -> 745
Third door opens for next largest number ->574



Find which Nth door's room contains the machine or How many doors should Sam cross ?

Given input is in form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

explanation: (1) 875 (2) 857 (3) 785 (4) 758

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

Return NULL for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *prev;
	struct node *next;
};
int fact(int n){
	if (n == 1)
		return 1;
	else
		return n*fact(n - 1);
}
int countdigits(int num){
	int i;
	while (num != 0){
		i++;
		num /= 10;
	}
	return i;
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
int countmax(int *arr, int c, int a){
	int c1= 0;
	for (int i = 0; i < c; i++){
		if (arr[i]>a)
			c1++;
	}
	return c1;
}

int doorstoCross(struct node *passKey)
{
	int c = 0;
	struct node* curr;
	curr = passKey;
	int val = 0;
	while (curr != NULL){
		val = val * 10 + curr->num;
		curr = curr->next;
	}
	
	c = countdigits(val);
	int * arr1 = (int*)malloc(c*sizeof(int));
	int * arr2 = (int*)malloc(c*sizeof(int));
	curr = passKey;
	int i = 0;
	while (curr != NULL){
		arr1[i] = curr->num;
		arr2[i++] = curr->num;
		curr = curr->next;
	}
	if (c > 12)
		return -1;
	bubbleSort(arr2, c);
	int m = 0, n = 0, k = 0, g = c;;
	for (k = 0; k < c; k++){
		for (m = 0; m < c&&arr2[m]>arr1[k]; m++){
			int p = countmax(arr2, c, arr2[m]);
			n = n + p*g - 1;
		}
		for (int i = 0; i < c; i++){
			if (arr2[i] != arr1[k]){
				i++;
			}
			else{
				for (int j = i; j + 1 < c; j++){
					arr2[j] = arr2[j + 1];
				}
				g--;
				break;
			}
		}
	}
	return n+1;

	
}
