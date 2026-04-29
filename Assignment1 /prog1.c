#include <stdio.h>
#include <string.h>
#define SIZE 50 
typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}
int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow\n");
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE; 
    cb->count++;
}
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow\n");
        return '\0'; 
    }
    char data = cb->buffer[cb->head];
    // تحريك مؤشر القراءة بشكل دائري
    cb->head = (cb->head + 1) % SIZE; 
    cb->count--;
    return data;
}
int main() {
    CircularBuffer cb;
    init(&cb); 

    char name[100];
    printf("أدخل اسمك: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        name[strcspn(name, "\n")] = 0; 
    }
    strcat(name, "CE-ESY");
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("\nالبيانات المقروءة من المخزن الدائري: ");
    while (!isEmpty(&cb)) {
        char c = read(&cb);
        if (c != '\0') {
            printf("%c", c);
        }
    }
    printf("\n");
    if (isEmpty(&cb)) {
        printf("DONE\n");
    }

    return 0;
}
