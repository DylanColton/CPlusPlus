#include <iostream>
#include <random>
#include "List.h"
#include "ListNode.h"

using namespace std;

int* insertionSort(int* a, int N) {
	for (int i = 1; i < N; i++) {
		int item = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > item) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = item;
	}
	return a;
}

int rLargest(int* pi, int N, int r) {
	if (r < 1 && r > N) {
		cout << "Invalid r." << " 1 <= r <= N" << endl;
		exit(1);
	}

	pi = insertionSort(pi, N);
	return pi[N - r];
}

int main1() {
	int size = 5;
	int* pi = new int[size];
	for (int i = 0; i < size; i++) 
		pi[i] = rand() % 20;

	cout << "The 1st largest number is: " << rLargest(pi, size, 1) << endl;
	cout << "The 5th largest number is: " << rLargest(pi, size, 5) << endl;

	cout << "The complexity of rLargest is " << "O(N^2), where N is size" << endl;
	return 0;
}

void quickSort(int* a, int first, int last) {
	int i = first, j = last;
	int pivot = a[(first + last) / 2];
	
	while (i <= j) {
		while (a[i] < pivot) 
			i++;
		while (a[j] > pivot) 
			j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	}
	
	if (first < i - 1) 
		quickSort(a, first, i - 1);
	if (i < last) 
		quickSort(a, i, last);
}

int rLargestQuick(int* pi, int N, int r) {
	if (r < 1 && r > N) {
		cout << "Invalid r." << " 1 <= r <= N" << endl;
		exit(1);
	}

	quickSort(pi, 0, N - 1);
	return pi[N - r];
}

int main2() {
	int size = 5;
	int* pi = new int[size];
	for (int i = 0; i < size; i++)
		pi[i] = rand() % 25;

	cout << "The 1st largest number is: " << rLargestQuick(pi, size, 1) << endl;
	cout << "The 5th largest number is: " << rLargestQuick(pi, size, 5) << endl;

	cout << "The complexity of rLargestQuick is " << "O(Nlog(N)), where N is size" << endl;

	return 0;
}

template <typename T>
void quickSort_(List<T>* list, int first, int last) {
	int i = first, j = last;
	int pivot = list->get((first + last) / 2);

	while (i <= j) {
		while (list->get(i) < pivot)
			i++;
		while (list->get(j) > pivot)
			j--;

		if (i <= j) {
			int temp = list->get(i);
			list->set(i, list->get(j));
			list->set(j, temp);
			i++; j--;
		}
	}

	if (first < i - 1)
		quickSort_(list, first, i - 1);
	if (i < last)
		quickSort_(list, i, last);
}

int main() {
	int N = 50;
	List<int>* l = new List<int>();
	for (int i = 0; i < N; i++)
		l->insert_end(rand() % 100);

	l->print();

	quickSort_(l, 0, l->size() - 1);

	l->print();

	return 0;
}