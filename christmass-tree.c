#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void msleep(long ms) {
    usleep(ms * 1000);
}

int main() {
    srand((unsigned int)time(NULL));

    int treeY;
    printf("Taille du sapin :\n");
    scanf("%d", &treeY);
    int treeX = (2 * treeY) - 1;

    while (1) {
        printf("\033[2J\033[H");  // Efface l'écran et déplace le curseur
        for (int y = 0, s = 1; y < treeY; y++, s += 2) {
            int offset = (treeX - s) / 2;
            for (int i = 0; i < offset; i++) printf(" ");
            for (int x = 0; x < s; x++) {
                if (y == 0 && x == 0) {
                    printf("\033[38;2;212;175;55m*\033[0m");
                } else if (rand() % 100 < 40) {
                    printf("\033[38;2;%d;%d;%dm*\033[0m", rand() % 255, rand() % 255, rand() % 255);
                } else {
                    printf("\033[38;2;0;100;0m*\033[0m");
                }
            }
            printf("\n");
        }
        msleep(300);
    }
    return 0;
}
