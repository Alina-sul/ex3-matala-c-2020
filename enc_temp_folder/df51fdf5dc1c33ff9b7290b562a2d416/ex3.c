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
int repetition(int arr[], int n);

/*..Helpers..*/
int* swap(int arr[], int i, int j);

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

/*...Q1..........................*/

void Ex1()
{   
	int a, b, n;
	char c;

	printf("Enter n: \n");
	if (scanf_s("%d%c", &n, &c) != 2 || c != '\n')
		return printf("This is not an integer, Try again.\n\n");
	printf("Enter a: \n");
	if (scanf_s("%d%c", &a, &c) != 2 || c != '\n')
		return printf("This is not an integer, Try again.\n\n");
	printf("Enter b: \n");
	if (scanf_s("%d%c", &b, &c) != 2 || c != '\n')
		return printf("This is not an integer, Try again.\n\n");

	int* arr;
	arr = (int*)calloc(n, sizeof(int));
	int newLength = 0;
	int* pNewLength = &newLength;

	if (arr != NULL) {
		printf("Enter array one number at a time: \n");
		for (int i = 0; i < n; i++) {
			if (scanf_s("%d%c", &arr[i], &c) != 2 || c != '\n')
				return printf("This is not an integer, Try again.\n\n");
				
		}
	}

	

	int *incoming = calcIncoming(arr, n, a, b, pNewLength);

	printf("newLength %d\n", newLength);
	printf("New array is: \n");
	for (int i = 0; i < newLength; i++) {
		if(i == newLength - 1) printf("%d \n", *(incoming + i));
		else printf("%d, ", *(incoming + i));
	}

	free(arr);

}
int* calcIncoming(int arr[], int length, int a, int b, int *pNewLength)
{  
	int count = 0, j; // will be used in calculations for length of new array
	
	for (int i = 0; i < length; i++) { //calculate new array length
		if (arr[i] >= a && arr[i] <= b) {
			//search for a number in range [a,b], if there is,
			//increase count and move the value to the start of the array
			//to decrease next run to [count] runs

			swap(arr, i, (0 + count));

			count++;


		};
	}

	*pNewLength = count;

	int* incoming;
	incoming = (int*)calloc(*pNewLength, sizeof(int));

	if (incoming != NULL) { //initialize new array
		for (int i = 0; i < *pNewLength; i++) {

			for (int j = i; j < *pNewLength; j++) {
				if (arr[j] < arr[i]) { //selection sort
					swap(arr, i, j);
				}
				
				incoming[i] = arr[i];
			}
			
		}
	}
	return incoming;
}

/*...Q2..........................*/

void Ex2() {

	int n;
	int* arr;
	char c;

	printf("Enter n: ");
	if (scanf_s("%d%c", &n, &c) != 2 || c != '\n') 
		return printf("This is not an integer. Try again \n");
	
	arr = (int*)calloc(n, sizeof(int));

	if (arr != NULL) {
		printf("Enter array, one number at a time: \n");
		for (int i = 0; i < n; i++) {
			if (scanf_s("%d%c", &arr[i], &c) != 2 || c != '\n')
				return ("This is not an integer. Try again \n");
			if (arr[i] < 0 || arr[i] > 3 * n)
				return 	printf("Invalid input, value should be between 0 to 3n. Try again. \n");
		}
	}

	int checkRepitition = repetition(arr,n);

	(checkRepitition != -1) ? printf("First repetitive number is: %d \n", checkRepitition) :
		printf("No repetitive numbers: %d \n", checkRepitition);

}

int repetition(int arr[], int n) {

	int result = -1; //default result
	int count = 0;

	for (int i = 0; i < n - 1 ; i++) {

		for (int j = n - 1; j > i+1 ; j--) { 
			// check if value in place i == i+1 or i == j or i+1 == j
			// that way we check at once three numbers at a time and reduce the amount 
			// of the function runs

			if (arr[i] == arr[i + 1] || arr[i] == arr[j]) {
				return arr[i];
			}
			if (arr[i + 1] == arr[j]) {
				return arr[i + 1];
			}
			printf("count %d\n", count++);

		}

	}

	return result;

};

/*...Q3..........................*/

void Ex3() {}
void Ex4() {}
void Ex5() {}

/*...HELPER FUNCTIONS..........................*/

int* swap(int arr[], int i, int j) {

	int temp = 0;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

};
