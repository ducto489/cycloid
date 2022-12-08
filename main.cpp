#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<cmath>
#include<stdio.h>
#define WIDTH_OF_SCREEN 700
#define CENTER_OF_YINTERCEPTS 275
#define SPEED_OF_CAR 3

//As the number decreased, the accuracy of the cycloid line increased. (with ACCURACY > 0)
#define ACCURACY 0.1

void drawCycloidLineAndStraightLine(double max);
void drawCircle(void);
void drawCar(void);
void drawLetters();
void drawThanks();

const int RADIUS = 15, SMALL_RADIUS = RADIUS - 13;
int globalY = 0;

int main()
{
    system("cls");
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    drawLetters();
    setbkcolor(WHITE);
    drawCar();
    drawThanks();

    getch();
    closegraph();
    return 0;
}

void drawCycloidLineAndStraightLine(double max)
{
    setcolor(BLACK);
    line(0, CENTER_OF_YINTERCEPTS, WIDTH_OF_SCREEN, CENTER_OF_YINTERCEPTS);
    int previous_x = 0, previous_y = 0;
    setcolor(BLUE);
    //delay(10);
    for(double t = 0; t < max/RADIUS; t = t + ACCURACY)
    {
        //"0.9" make Cycloid line shorter.
        int x = round(RADIUS*(t - sin(t)) - 0.9);
        int y = CENTER_OF_YINTERCEPTS - round(RADIUS*(1 - cos(t)));

        //Saving the location of y-intercepts in order to calculate the center of circle
        if(t == 0)
            globalY = y;

        line(previous_x, previous_y, x, y);
        previous_x = x;
        previous_y = y;
    }
}

void drawCircle(void)
{
    for(double i = 15; i < WIDTH_OF_SCREEN; i++)
    {
        drawCycloidLineAndStraightLine(i);
        setcolor(GREEN);
        circle(i, -RADIUS + globalY, RADIUS);
        delay(25);
        cleardevice();
    }
}

void drawCar(void)
{
    // Code adapted from GeeksForGeeks:
    // https://www.geeksforgeeks.org/draw-a-moving-car-using-computer-graphics-programming-in-c/ 
    for (int i = -50; i < WIDTH_OF_SCREEN; i+=SPEED_OF_CAR)
    {
        drawCycloidLineAndStraightLine(i+65);

        setcolor(LIGHTGRAY);
        // Draw bonnet and body of the car
        line(0 + i, CENTER_OF_YINTERCEPTS - 45, 210 + i, CENTER_OF_YINTERCEPTS - 45);
        line(50 + i, CENTER_OF_YINTERCEPTS - 45, 75 + i, CENTER_OF_YINTERCEPTS - 75);
        line(75 + i, CENTER_OF_YINTERCEPTS - 75, 150 + i, CENTER_OF_YINTERCEPTS - 75);
        line(150 + i, CENTER_OF_YINTERCEPTS - 75, 165 + i, CENTER_OF_YINTERCEPTS - 45);
        line(0 + i, CENTER_OF_YINTERCEPTS - 45, 0 + i, CENTER_OF_YINTERCEPTS - 15);
        line(210 + i, CENTER_OF_YINTERCEPTS - 45, 210 + i, CENTER_OF_YINTERCEPTS - 15);

        setlinestyle(0,0,3);
        setcolor(RED);
        // For left wheel of car
        circle(65 + i, CENTER_OF_YINTERCEPTS - 15, RADIUS);

        setlinestyle(0,0,1);
        setcolor(LIGHTGRAY);
        circle(65 + i, CENTER_OF_YINTERCEPTS - 15, SMALL_RADIUS);

        // For right wheel of car
        circle(145 + i, CENTER_OF_YINTERCEPTS - 15, RADIUS);
        circle(145 + i, CENTER_OF_YINTERCEPTS - 15, SMALL_RADIUS);

        // Line left of left wheel
        line(0 + i, CENTER_OF_YINTERCEPTS - 15, 50 + i, CENTER_OF_YINTERCEPTS - 15);

        // Line middle of both wheel
        line(80 + i, CENTER_OF_YINTERCEPTS - 15, 130 + i, CENTER_OF_YINTERCEPTS - 15);

        // Line right of right wheel
        line(210 + i, CENTER_OF_YINTERCEPTS - 15, 160 + i, CENTER_OF_YINTERCEPTS - 15);

        delay(100);
        cleardevice();
    }
}

void drawLetters()
{
        setcolor(LIGHTGREEN);
        settextstyle(8,HORIZ_DIR,2);
        outtextxy(40,200,"Made By A Student From Ngo Quyen High School :))");
        delay(7000);
        cleardevice();
}

void drawThanks()
{
        setcolor(BLUE);
        settextstyle(7,HORIZ_DIR,8);
        outtextxy(80,190,"THANKS!");
        delay(4000);
        cleardevice();
}
