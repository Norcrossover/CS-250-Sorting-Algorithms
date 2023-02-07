#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n = 100;

// --------------- helpers ----------------------

int create_random_number() { return floor(1000 * drand48()); }

int get_array_size() {
  int size = 0, result;
  printf("Please enter in the size of the array: ");
  result = scanf("%d", &size);
  if (result == -1) 
    return 0;
  return size;
}

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
  printf("[");
  for (int i = 0; i < n; i++) {
    if (i != (n-1))
      printf("%d, ", list[i]);
    else      
      printf("%d", list[i]);
  }
  printf("]");
}

int check_sort(int list[]) {
  int sorted = 1;
  
  printf("\n\nChecking sorting algorithm correctness...");
  
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
  
  if (sorted == 0)
    printf("List is not sorted, check algorithm again.");
  
  else
    printf("\nLIST IS SORTED! GOOD JOB :D");
  
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
    if ((li < left_end) && (ri >= right_end) || (temp[li] <= temp[ri])) {
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

void smart_sort(int list[], int low, int high) {
  int pivot = list[low]; // the value we would like to set in the middle
  int left = (low + 1), right = high; // indices to navigate list
  int left_stop = 0, right_stop = 0; // 0 = false, 1 = true
  int temporary = 0;

  // BASE CASE
  if (low >= high)
    return;

  while (left != right) {
    // check list elements to see if they need to halt or increment/decrement
    if (left_stop == 0 && left != right) {
      if (list[left] > pivot)
        left_stop = 1;
      else
        left++;
    }
    if (right_stop == 0 && left != right) {
      if (list[right] < pivot)
        right_stop = 1;
      else 
        right--;
    }

    // SWAP and RESET indices
    if (left_stop == 1 && right_stop == 1) {
      temporary = list[right];
      list[right] = list[left];
      list[left] = temporary;
      left_stop = 0;
      right_stop = 0;
    }
  }

  // swap the pivot with correct finishing element
  if (list[right] < pivot) {
    list[low] = list[right];
    list[right] = pivot;
  }
  else {  // if list[right] >= pivot
    list[low] = list[right-1];
    list[right-1] = pivot;
    right--;
  }

    smart_sort(list, low, right-1);
    smart_sort(list, right+1, high);
}

// --------------- sorting algorithms ---------------------


// ------------------------- Sort subroutines --------
void selection_sort_driver() {
  int list[n], sorted;
  create_array_random(list);
  printf("\nInitial list:\n");
  print_array(list);
  printf("\n\nSelection sort... \n");
  selection_sort(list);
  printf("Final List:\n");
  print_array(list);
  check_sort(list);
  printf("\n\n");
}

void mergesort_driver() {
  int list[n];
  
// compile with: cc *.c -lm
// run with: ./a.out < input.txt
  
  create_array_file(list);
  printf("\nInitial list:\n");
  print_array(list);
  printf("\n\nMergesorting... \n\n");
  mergesort(list, 0, (n-1));
  printf("Final List:\n");
  print_array(list);
  check_sort(list);
  printf("\n\n");
}

void smart_sort_driver() {
  int list[n];
  create_array_random(list);
  printf("\nInitial list:\n");
  print_array(list);
  printf("\n\nSmart sorting... \n\n");
  smart_sort(list, 0, (n-1));
  printf("Final List:\n");
  print_array(list);
  check_sort(list);
  printf("\n\n");
}

// ------------------------- Sort subroutines --------


int main(void) {
  n = get_array_size();
  smart_sort_driver();
  //mergesort_driver();
  return 0;
}