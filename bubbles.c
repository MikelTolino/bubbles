#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#define RADIO 30
#define NUM 30

typedef struct circles
{
	int x;
	int y;
	int color;
	int dx;
	int dy;
} circles;

void check_coordinates(circles *c, int maxx, int maxy)
{
	if (c->x + RADIO == maxx)
	{
		c->dx = -1;
	}
	if (c->x - RADIO == 0)
	{
		c->dx = 1;
	}
	if (c->y + RADIO == maxy)
	{
		c->dy = -1;
	}
	if (c->y - RADIO == 0)
	{
		c->dy = 1;
	}
	c->x += c->dx;
	c->y += c->dy;
}

int set_location(int max)
{
	return (rand() % (max - RADIO));
}
int color()
{
	return (rand() % 15);
}

int main(int argc, char **argv)
{
	int gd = DETECT;
	int gm;
	int maxx;
	int maxy;
	circles c[NUM];
	int i = 0;
	initgraph(&gd, &gm, NULL);
	maxx = getmaxx();
	maxy = getmaxy();
	while (i < NUM)
	{
		setcolor(c[i].color = color());
		circle(c[i].x = set_location(maxx),c[i].y = set_location(maxy), RADIO);
		if (rand() % 2)
			c[i].dx = 1;
		else
			c[i].dx = -1;
		if (rand() % 2)
			c[i].dy = 1;
		else
			c[i].dy = -1;
		i++;
	}
	i = 0;
	while (1)
	{
		if (i >= NUM)
		{
			i = 0;
			delay(50);
			cleardevice();
		}
		check_coordinates(&c[i], maxx, maxy);
		circle(c[i].x, c[i].y, RADIO);
		i++;
	}
	//delay(50000);
	closegraph();
	return 0;
}
