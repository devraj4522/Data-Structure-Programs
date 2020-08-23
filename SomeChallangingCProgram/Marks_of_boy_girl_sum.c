// ********* Sample Input 0 ********

// 3
// 3
// 2
// 5
// b

// **********Sample Output  *************

// 8

// ******* Explanation *********
// marks = [3, 2, 5] and gender = b (b for Boy and g for girl)
// Even posion of array = marks of boy and 
// Odd position of Array is the marks of girl
// So marks of Boy in this case = marks[0] + marks[2] 
// So Output = 3 + 5 = 8

// *********** Program ***********

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int sum =0;
  for (int i = 0; i < number_of_students; i++)
  {
      if (gender=='b' && i%2 ==0)
      {
          sum = sum + *(marks + i);
      }
      else if (gender =='g' && i%2 !=0)
      {
          sum = sum + *(marks + i);
      }
  }
    return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}
