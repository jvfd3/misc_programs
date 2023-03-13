#include <stdio.h>
#include <stdlib.h>
// https://dotnettutorials.net/lesson/finding-duplicates-in-a-string-using-bitwise-operations-in-c/
int main() {
    // char B[] = "riding";
    char B[] = "abcdefg";
    int H = 0, x = 0;
    printf("String is \"% s\"\n", B);
    for (int i = 0; B[i] != '\0'; i++) {
        x = 1;
        // printf("(%d)\n", x);
        x = x << (B[i] - 97);
        // printf("(%d)\n", x);
        printf("(%d) & (%d) = (%d)\n", x, H, (x & H));
        if ((x & H) > 0) {
            printf("% c is Duplicate", B[i]);
        } else {
            H = x | H;
        }
    }
    return 0;
}