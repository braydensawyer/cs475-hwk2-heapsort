/*
 * heapsort.c
 *
 *  Created on: Jan 24, 2024
 *      Author: Brayden Sawyer
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);

	while (n > 0) 
	{
        // Swap the root with the last element
		swap(&A[0], &A[n-1]);
		n--;
		heapify(A, 0, n);
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// Start from the last non-leaf node and heapify each node in reverse order
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(A, i, n);
	}
}

// get the index of the left child of element i
int left_child(int i)
{
    return 2 * i + 1;
}

// get the index of the right child of element i
int right_child(int i)
{
    return 2 * i + 2;
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	int left = left_child(i);
	int right = right_child(i);
	int smaller = i;

    // Find the index of the smallest element among the current node, left child, and right child
	if (left < n && A[left].salary < A[smaller].salary)
	{
		smaller = left;
	}
	if (right < n && A[right].salary < A[smaller].salary)
    {
        smaller = right;
    }

	// If the smallest element is not the current node, swap them and recursively heapify
	if (smaller != i)
	{
		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		printf("id=%s sal=%.2d", A[i].name, A[i].salary);
        if (i < n - 1)
        {
            printf(" ");
        }
	}
	printf("]\n");
}
