// ...existing code...
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s){ s->top = -1; }
int is_empty(const Stack *s){ return s->top == -1; }
int is_full(const Stack *s){ return s->top == MAX - 1; }

int push(Stack *s, int val){
    if (is_full(s)) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s, int *val){
    if (is_empty(s)) return 0;
    *val = s->data[s->top--];
    return 1;
}

int peek(const Stack *s, int *val){
    if (is_empty(s)) return 0;
    *val = s->data[s->top];
    return 1;
}

void display(const Stack *s){
    if (is_empty(s)){ printf("Stack is empty\n"); return; }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; --i) printf("%d ", s->data[i]);
    printf("\n");
}

int main(void){
    Stack st;
    init(&st);
    int choice, val;

    while (1){
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\nChoose: ");
        if (scanf("%d", &choice) != 1){
            printf("Invalid input\n");
            // clear stdin
            int c; while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice){
            case 1:
                printf("Value to push: ");
                if (scanf("%d", &val) != 1){
                    printf("Invalid input\n");
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    break;
                }
                if (push(&st, val)) printf("%d pushed\n", val);
                else printf("Stack overflow\n");
                break;
            case 2:
                if (pop(&st, &val)) printf("Popped: %d\n", val);
                else printf("Stack underflow\n");
                break;
            case 3:
                if (peek(&st, &val)) printf("Top: %d\n", val);
                else printf("Stack is empty\n");
                break;
            case 4:
                display(&st);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
// ...existing code...