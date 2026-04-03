#include <stdio.h>
#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initial stack is empty

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot pop.\n");
        return -1; // Return -1 to indicate stack is empty
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

// Function to view the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from the stack\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
