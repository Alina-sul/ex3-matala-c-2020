// Alina Sulkovsky 316015247
#include <stdio.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */
int* calcIncoming(int arr[], int length, int a, int b, int* pNewLength);

/* ------------------------------- */
// no need to change the main function for matala 1.
// 
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{   
	int a, b, n;
	
	printf("Enter n: \n");
	scanf_s("%d", &n);
	printf("Enter a: \n");
	scanf_s("%d", &a);
	printf("Enter b: \n");
	scanf_s("%d", &b);

	int* arr;
	arr = (int*)calloc(n, sizeof(int));
	int newLength = 0;
	int* pNewLength = &newLength;

	if (arr != NULL) {
		printf("Enter array one number at a time: \n");
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &arr[i]);
		}
	}

	int *incoming = calcIncoming(arr, n, a, b, pNewLength);

	printf("newLength %d\n", newLength);
	printf("New array is: \n");
	for (int i = 0; i < newLength; i++) {
		if(i == newLength - 1) printf("%d \n", *(incoming + i));
		else printf("%d, ", *(incoming + i));
	}
	




	
}

int* calcIncoming(int arr[], int length, int a, int b, int *pNewLength)
{  
	*pNewLength = 3;
	int* incoming;
	incoming = (int*)calloc(*pNewLength, sizeof(int));
	if (incoming != NULL) {
		printf("Enter array one number at a time: \n");
		for (int i = 0; i < *pNewLength; i++) {
			scanf_s("%d", &incoming[i]);
		}
	}

	
	return incoming;
}
void Ex2() {}
void Ex3() {}
void Ex4() {}
void Ex5() {}