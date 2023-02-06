#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// compile with: cc hw2NorcrossKobe.c -lm
// run with: ./a.out < input.txt

int n = 100;

// --------------- helpers ----------------------
int create_random_number() { return floor(1000 * drand48()); }

void create_array_random(int list[]) {
  for (int i = 0; i < n; i++) {
    list[i] = create_random_number();
  }
}

void create_array_file(int list[]) {
  int num, result = 0;

  // get the first n value
  result = scanf("%d", &n);
  if (result != 1) {
    printf("ERROR!");
    exit(-1);
  }
  
  // get the list
  for (int i = 0; i < n; i++) {
    result = scanf("%d\n", &num);
    
    if (result != 1) {
      printf("ERROR!");
      exit(-1);
    }
    
    list[i] = num;
  }
}

void print_array(int list[]) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", list[i]);
  }
}

int check_sort(int list[]) {
  int sorted = 1;
  for (int i = 0; i < n - 1; i++) {
    if (list[i] <= list[i + 1])
      continue;
    else {
      printf("\nHERE IS THE ERRORRRRR\n");
      sorted = 0;
      break;
    }
  }
  printf("\n");
  if (sorted == 0) {
    printf("List is not sorted, check algorithm again.");
  } else {
    printf("LIST IS SORTED! GOOD JOB :D");
  }
  printf("\n");
}

void set_array(int list[]) {
  for (int i = 0; i < n; i++) {
    list[i] = 0;
  }
  return;
}
// --------------- helpers ----------------------

// --------------- sorting algorithms ----------------------
void selection_sort(int list[]) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (list[i] > list[j]) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
}

void merge(int list[], int lo, int mid, int hi) {
  int temp[n],            // temp array
      left_end = (mid+1), // end of half 1
      li = (lo),          // left index
      right_end = (hi+1), // end of half 2
      ri = (mid + 1),     // right index
      mi = lo;            // merged list index

  // sets array to all zero values foro error checking
  set_array(temp);

  // copies everything needed into the temp array
  for (int i = lo; i < right_end; i++) {
    temp[i] = list[i];
  }

  // main sorting algorithm
  while (mi < hi) {
    if ((li < left_end) 
        && (ri >= right_end) 
        || (temp[li] <= temp[ri])) {
      list[mi] = temp[li];
      li++;
    } else {
      list[mi] = temp[ri];
      ri++;
    }
    mi++;
  }

  // continue the filling the list with the remaining temp variables
  while (li < left_end) {
    list[mi] = temp[li];
    li++;
  }
  while (ri < right_end) {
    list[mi] = temp[ri];
    ri++;
  }
}

void mergesort(int list[], int lo, int hi) {
  int mid = 0;
  
  if (lo < hi) {
    mid = (lo + (hi - lo) / 2);
    mergesort(list, lo, mid);
    mergesort(list, mid + 1, hi);
    merge(list, lo, mid, hi);
  }
}

// --------------- sorting algorithms ---------------------

int main(void) {
  int list[n], sorted;

  // create_array_random(list);
  create_array_file(list);

  printf("\nInitial list:\n");
  print_array(list);

  printf("\n\nMergesorting... \n\n");
  mergesort(list, 0, (n-1));

  /*
  printf("\n\nSelection sort... \n");
  selection_sort(list);
  */

  printf("Final List:\n");
  print_array(list);

  check_sort(list);

  printf("\n\n");
  return 0;
}