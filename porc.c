#include <stdio.h>

int main() {
    int ch;

    printf("Սեղմեք մի ստեղն (ESC՝ դուրս գալու համար):\n");
    while (1) {
        ch = getchar();  // Կարդում է սիմվոլը
        printf("Սեղմված ստեղնի կոդը՝ %d\n", ch);

        if (ch == 27) { // ESC ստեղնի ASCII արժեքը՝ 27
            break;
        }
    }

    return 0;
}
