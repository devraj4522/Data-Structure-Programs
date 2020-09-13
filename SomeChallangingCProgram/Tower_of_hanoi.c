#include <stdio.h> 

// Function Recursion for Tower of Hanoi
void tower_of_hanoi(int n, char stack_A, char stack_result, char stack_aux) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move number at  1 from stack %c to stack %c", stack_A, stack_result); 
		return; 
	} 
	tower_of_hanoi(n-1, stack_A, stack_aux, stack_aux); 
	printf("\n Move number %d from stack %c to stack %c", n, stack_A, stack_result); 
	tower_of_hanoi(n-1, stack_aux, stack_result, stack_A); 
} 

int main() 
{ 
	int n; 
    printf("Enter the number of values to be moved");
    scanf("%d", &n);
	tower_of_hanoi(n, 'A', 'C', 'B'); 
	return 0; 
} 
