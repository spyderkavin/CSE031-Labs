#include <stdio.h>

int main() {
    int x = 0, y = 0, *px, *py;
    int arr[10] = {0};

    //print intial values of x and y
    printf("%d\n", x);
    printf("%d\n", y);

    //print addresses of x and y
    printf("%p\n", &x);
    printf("%p\n", &y);

    //initialize values of px and py
    px = &x;
    py = &y;

    //print values of px and py
    printf("%p\n", px);
    printf("%p\n", py);
    printf("%p\n", &px);
    printf("%p\n", &py);

    //print values of arr using pointers
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(arr + i));
    }

    //print address of arr in different ways
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr);

    //print address of arr using pointer
    printf("%p\n", &arr);

    return 0;
}