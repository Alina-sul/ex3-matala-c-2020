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
int isConsecutive(int arr[], int n);

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
	
	free(arr);
}
int repetition(int arr[], int n) {

	int result = -1; //default result

	int* numbersRange = (int*)calloc((n*3)+1, sizeof(int)); 
	//helper array - includes all the possible n values as its index

	if (numbersRange != NULL) {
		for (int i = 0; i < n; i++) {

			numbersRange[arr[i]] ++; // count the appearnce of the arr[i] value

			if (numbersRange[arr[i]] > 1) { 
				// if the count for this value is bigger than 1, 
				//that means it has already apeard, break loop
				result = arr[i]; 
				break;
			}


		}
	}

	free(numbersRange);

	return result;

};

/*...Q3..........................*/

void Ex3() {
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
				return printf("This is not an integer. Try again \n");
			if (arr[i] < 0)
				return printf("Number should be positive. Try again \n");
		}
	}

	int consecutive = isConsecutive(arr, n);

	(consecutive != -1) ? printf("Numbers are consecutive: %d \n", consecutive) :
		printf("Numbers are not consecutive: %d \n", consecutive);

	free(arr);
}

int isConsecutive(int arr[], int n) {

	//find maximum and minimum values
	int min = arr[0], max = arr[0];

	for (int i = 0; i < n; i++) {
		
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		if (i == n - 1 && max == min) return 0; //that means the array has the same value in each sell, 
		//therefore is not consecutive and we return 0;

	}

	//create helper array
	int length = max - min, position = 0, result = 1;
	int* helper;
	helper = (int*)calloc(length, sizeof(int));

	helper[0] = 1; //min value exists, therefore counted as 1
	helper[length - 1] = 1; //max value exists, therefore counted as 1

	//new array length is the range between min to max,
	//for example min = 42, max = 50, length = 8
	//if 43 exists, helper[1] will count +1
	for(int i = 0; i < n; i++) {
		
		position = arr[i] - min;
		helper[position]++;

	}

	//check if any helper value is 0, if so, not a consecutive nubmers array
	for (int i = 0; i < length; i ++) {
		if (helper[i] = 0) {
			result = 0;
			break;
		}
	}

	free(helper);

	return result;
}

/*...Q4..........................*/
void Ex4() {}


void Ex5() {}

/*...HELPER FUNCTIONS..........................*/

int* swap(int arr[], int i, int j) {

	int temp = 0;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

};
