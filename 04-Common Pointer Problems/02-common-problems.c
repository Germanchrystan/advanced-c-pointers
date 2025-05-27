#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem 1: freeing already freed memory.
// NOTE: if you are luchy, the C run time will trap this. on the other hand, it it doesn't and you are in a large and complex progream.
// you can be in for a very long debugging session.
void problem1() {
    char *b;

    b = (char *)malloc(10 * sizeof(char));
    free(b);
    free(b); // This line causes undefined behavior, as b is freed twice. It causes an exception in Visual Studio.
}

// Problem 2: memory leak.
void problem2() {
    char *b;

    for (int i = 0; i < 10; i++) {
        b = (char*)malloc(10);
    }

    free(b);
    // now we have lost 9 * 10 bytes of memory.
    // we can't free them because we dont have a pointer to the memory any longer
}

void problem2_fixed() {
  char *b[10]; // Array of pointers to track all allocations

  for (int i = 0; i < 10; i++) {
      b[i] = (char *)malloc(10); // Allocate memory and store the pointer
  }

  for (int i = 0; i < 10; i++) {
      free(b[i]); // Free each allocated block
  }
}

// Problem 3: re-use of memmory that is freed.
void problem3() {
  char *b, *c;

  b = (char *)malloc(100);
  c = b;

  free(b); // Free the memory pointed to by b
  strcpy(c, "hello");
  printf("c is %s\n", c);
  // This will cause undefined behavior because c points to freed memory.
  // The program may crash or print garbage values.
}

// Problem 4: pointer out of scope.
char *problem4() {
  char b[20];

  printf("Enter your name: ");
  gets(b);
  return b;
  // When this function returns 'b', will be overwritten by the next function call.
  // so even though I have a pointer to it, it does not contain my name.
}

/*
Why is this a problem?
Local Variable Scope:

The array b is a local variable, allocated on the stack.
When the function problem4 returns, the memory for b is no longer valid because it goes out of scope.
Returning a pointer to this memory (b) results in undefined behavior. The memory may be overwritten by subsequent function calls or other operations.
Undefined Behavior:

The returned pointer points to memory that is no longer valid.
Accessing or using this pointer (e.g., printing its contents) can lead to crashes, garbage values, or unpredictable behavior.
Unsafe Input Handling:

The use of gets is inherently unsafe because it does not check for buffer overflows.
If the user enters more than 19 characters (leaving space for the null terminator), it will overwrite adjacent memory, causing further undefined behavior.
*/
char *problem4_fixed() {
  char *b = (char *)malloc(20 * sizeof(char)); // Allocate memory on the heap

  if (b == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  printf("Enter your name: ");
  fgets(b, 20, stdin); // Use fgets instead of gets for safer input handling
  b[strcspn(b, "\n")] = '\0'; // Remove the newline character if present

  return b; // Return the pointer to the dynamically allocated memory
}
/*
Why this works: The memory allocated by malloc is on the heap, so it remains valid until explicitly freed using free.
Important: The caller of problem4_fixed must free the memory when it is no longer needed to avoid memory leaks.

Never return a pointer to a local variable, as it goes out of scope when the function ends.
Use dynamic memory allocation (malloc) if the memory needs to persist beyond the function's scope.
Prefer safer input functions like fgets over gets to avoid buffer overflows.
*/

// Problem 5: trying to use a null pointer.
// This is called 'dereferencing a null pointer'.
// This is cause an instant exception on most oses.
void problem5() {
    char *b;
    b = (char*)malloc(10);
    b = NULL;
    b[0] = 1;
}

int main() {
    printf("Problem 1: freeing already freed memory.\n");
    problem1();

    printf("\nProblem 2: memory leak.\n");
    problem2();
    problem2_fixed();

    printf("\nProblem 3: re-use of memory that is freed.\n");
    problem3();

    printf("\nProblem 4: pointer out of scope.\n");
    char *name = problem4_fixed();
    if (name) {
        printf("Your name is: %s\n", name);
        free(name); // Free the allocated memory
    }

    printf("\nProblem 5: trying to use a null pointer.\n");
    problem5();

    printf("That's all folks!\n");
  
    return 0;
}