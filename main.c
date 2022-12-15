#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty();
void push(int*, int);
void pop(int*);
void Top(int*);
void size();
void print(int*);

void menu(int*);

int top = -1, max = 5;
int main(void) {

  int *arr = (int *) calloc(max, sizeof(int)), choice = 0, value = 0;
  
  while (true) {
    menu(&choice);

    if (choice == 1) {
      printf("Enter your value: "), scanf("%d", &value);
    }
    
    switch(choice) {
      case 0: exit(0);
      case 1: push(arr, value); break;
      case 2: pop(arr); break;
      case 3: Top(arr); break;
      case 4: size(); break;
      case 5: {
        do {
          printf("Enter your new array size: "), scanf("%d", &max);
        } while (max < 5);

        arr = (int *) realloc(arr, max * sizeof(int));

        if (top > max) top = max-1;
      } break;
      case 6: print(arr); break;
    }
  }
  
  return 0;
}

void menu(int *choice) {
  do {
    printf("0.Exit\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Top\n");
    printf("4.Size\n");
    printf("5.Resize array\n");
    printf("6.Print array\n");

    printf("> "), scanf("%d", choice);
  } while(!(*choice >= 0 && *choice < 7));
}

bool isEmpty() {
  return top+1;
}

void push (int *arr, int v) {
  if (top == max-1) {
    printf("You stack is full\n");
    return;
  }

  arr[++top] = v;
}

void pop(int *arr) {
  if (!isEmpty()) {
    printf("You stack is empty\n");
    return;
  }

  printf("Top: %d\n", arr[top--]);
}

void Top(int *arr) {
  if (!isEmpty()) {
    printf("You stack is empty\n");
    return;
  }
  printf("Top: %d\n", arr[top]);
}

void size() {
  printf("Size: %d\n", top+1);
}

void print(int *arr) {
  for (int i = 0; i <= top; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
}

