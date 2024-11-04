#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>



void sleep(long ms) {
  struct timespec ts;
  int res;
  
  ts.tv_sec = ms / 1000;
  ts.tv_nsec = (ms % 1000) * 1000000;

  do {
    res = nanosleep(&ts, &ts);
  } while (res == EINTR);
}


int main() {
  // init the prandom generator
  srandom(time(NULL));
  
  // getting the tree size
  int treeY;
  printf("type in the size of the tree:\n");
  scanf("%d", &treeY);
  int treeX = (2 * treeY) - 1;

  // generate tree
  int tree[treeY][treeX];
    // populating
    // a positive number is the tree, 
    // -1 means its empty space
  int s = 1;
  for (int y = 0; y < treeY; y++) {
    for (int x = 0; x < treeX; x++) {
      if (x < s) {
        tree[y][x] = 1;
      } else {
        tree[y][x] = -1;
      }
    }
    s = s + 2;
  }
  
  // displaying tree
  printf("\x1b[2J");
  while (1) {
    printf("\x1b[H");
    for (int y = 0; y < treeY; y++) {
      
      // ((n*2-1) `div` 2) - (x `div` 2)
      for (int i = 0; i < ((treeY*2-1) / 2) - (((y + 1)*2 - 1) / 2); i++) {
        printf(" ");
      }

      for (int x = 0; x < treeX; x++) {
        if (tree[y][x] != -1) {

          if (x == 0 && y == 0) {
            printf("\x1b[38;2;212;175;55m*\x1b[0m");

          } else if (60 < random() % 100) { // about 40% chance for a light
            printf("\x1b[38;2;%ld;%ld;%ldm*\x1b[0m", random() % 255, random() % 255, random() % 255);

          } else { // dark green for unlit parts of tree
            printf("\x1b[38;2;0;100;0m*\x1b[0m");

          }
        }
      }
      printf("\n");
    }
    sleep(300);
  }
  return 0;
}

