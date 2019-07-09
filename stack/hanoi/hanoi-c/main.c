#include <stdio.h>
#include <stdlib.h>

/**********************************
问题：Hanoi塔问题 
***********************************/

void move(char x, int n, char y) {
	printf("move disk %d from %c to %c\n", n, x, y);
}

void hanoi(int n, char x, char y, char z) {
	if (n == 1) {
		move(x, 1, z);
	}
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

int main(void) {
	hanoi(3, 'x', 'y', 'z');
	return 0;
}
