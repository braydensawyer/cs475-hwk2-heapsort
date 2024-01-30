#include <stdio.h>
#include "employee.h"
#include "heap.h"

// constant to set array size
#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee employees[MAX_EMPLOYEES];
	
    //scan employee information to store in the array
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Salary: ");
        scanf("%d", &employees[i].salary);

        printf("\n");
	}

	// Print the unsorted list
    printf("Before:");
    printList(employees, MAX_EMPLOYEES);

    // Sort the list using heapsort
    heapSort(employees, MAX_EMPLOYEES);

    // Print the sorted list
    printf("After:");
    printList(employees, MAX_EMPLOYEES);

	return 0;
}
