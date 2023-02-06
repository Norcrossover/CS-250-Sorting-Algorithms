#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n = 100;

int create_random_number() {
  return floor(1000*drand48());
}

void create_array_random(int list[]) {
  for (int i = 0; i < n; i++) {
    list[i] = create_random_number();
  }
}

void create_array_file(int list[]) {
  int * num;

  n = scanf();
  
  for (int i = 0; i < n; i++) {
    scanf("%d\n", num);
    list[i] = *num;
  }
}

void print_array(int list[]) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", list[i]);
  }
}

void selection_sort(int list[]) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (list[i] > list[j]) {
        temp = list[i];
        list[i] = list[j]; 
        list[j] = temp;
      }
    }
  }
}

int check_sort(int list[]) {
  int sorted = 1;
  for (int i = 0; i < n-1; i++) {
    if (list[i] <= list[i+1])
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
  }
  else {
    printf("LIST IS SORTED! GOOD JOB :D");
  }
  printf("\n");
}

int main(void) {
  int list[n], sorted;

  //create_array_random(list);
  
  printf("Initial list:\n");
  print_array(list);
  
  /*
  printf("\n\nSelection sort... \n");
  selection_sort(list);
  */
  
  print_array(list);

  //check_sort(list);
 
  return 0;
}