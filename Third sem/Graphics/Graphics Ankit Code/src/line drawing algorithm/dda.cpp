#include<stdio.h>
#include<graphics.h>
#include<math.h>

void lineDDA(int x1, int y1, int x2, int y2) {
	int i, steps, dx, dy;
	float xinc, yinc, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) >= abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / steps;
	yinc = dy / steps;

	x = x1;
	y = y1;
	for (i = 0;i < steps;i++) {
		putpixel(x, y, WHITE);
		x += xinc;
		y += yinc;
		delay(10);
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	
	lineDDA(100, 100, 300, 300);
	lineDDA(10, 10, 200, 100);
	lineDDA(10, 10, 100, 200);
	
	getch();
	closegraph();
	return 0;
}
