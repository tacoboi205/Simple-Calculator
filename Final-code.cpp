#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "complex-function.c"
#include <graphics.h>
#include <conio.h>
#include "graphics-code.c"
#include "matrix-code.c"
double sine(double a)       //finding sine value of the given angle
{
    a=a*0.0174533;
    a=sin(a);
    return a;
}
double cosine(double a)    //finding cosine value of the given angle
{
    a=a*0.0174533;
    a=cos(a);
    return a;
}
double tangent(double a)    //finding tangent value of the given angle
{
    a=a*0.0174533;
    a=tan(a);
    return a;
}
double nlog(double a)       //natural log
{
    a=log(a);
    return a;
}
double logar(double a, double b)    //finding logarithmic value for the given number and base
{
    return log(a)/log(b);
}
double power(double a, double b)    //finding a^b
{
    return pow(a,b);
}
double expo(double a)               //finding e^a
{
    return exp(a);
}
float celsius(float f)  //fahrenheit to celsius
{
    return (f-32.0)*(5.0/9.0);
}
float fahrenheit(float c)   //celsius to fahrenheit
{
    return (c*(9.0/5.0))+32;
}
float add(float x, float y)     //implementing addition function of 2 numbers
{
    return x + y;
}

float subtract(float x, float y) //implementing subtraction function of 2 numbers
{
    return x - y;
}

float multiply(float x, float y) //implementing multiplication function of 2 numbers
{
    return x * y;
}

float divide(float x, float y) //implementing division function of 2 numbers
{
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int modulus(int a, int b)   //implementing modulus function of 2 numbers
{
    if (b != 0) return a % b;
    printf("Error: Modulus by zero!\n");
    return 0;
}

void quadratic()        //finding roots of a quadratic equation
{
    int a,b,c;
    float x1,x2,d;
    printf("enter a quadratic equation in the form of ax^2 + bx + c = 0\n");
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("c=");
    scanf("%d",&c);
    d=(b*b)-(4)*(a)*(c);
    if(d<0)
        {
            printf("imaginary roots");
            exit(0);
        }
    x1= (((-1)*b)+sqrt(d))/(2*a);
    x2= (((-1)*b)-sqrt(d))/(2*a);
    printf("solutions of the equation are %f and %f",x1,x2);
}
double metric(double a,int c, int t)    //metric convertions
{
    double ans;
    double units[]={1e-9,1e-6,1e-3,1e-2,1e0,1e3,1e6,1e9,1e12};
    ans=a*(units[t-1]/units[c-1]);
    return ans;
}

double imperial(int conv, double a)     //imperial convertions
{
    switch (conv)
    {
        case 1:
            return a/12.0;
        case 2:
            return a/3.0;
        case 3:
            return a*1.60934;
        case 4:
            return a*0.453592;
        case 5:
            return a*28.3495;
        case 6:
            return a*3.78541;

        default:
            return -1;
    }
}

void Header()   //calculator display header
{
    printf("\n=====================================\n");
    printf("         SIMPLE C CALCULATOR \n");
    printf("=====================================\n");
}


void Menu()     //calculator functions and display
{
    printf("------ MENU ------             _____________________\n");
    printf("1. Add                        |  _________________  |\n");
    printf("2. Subtract                   | |                 | |\n");
    printf("3. Multiply                   | |_________________| |\n");
    printf("4. Divide                     |  ___ ___ ___   ___  |\n");
    printf("5. Modulus                    | | 7 | 8 | 9 | | + | |\n");
    printf("6. Celsius to Fahrenheit      | |___|___|___| |___| |\n");
    printf("7. Fahrenheit to Celsius      | | 4 | 5 | 6 | | - | |\n");
    printf("8. Sine                       | |___|___|___| |___| |\n");
    printf("9. Cosine                     | | 1 | 2 | 3 | | * | |\n");
    printf("10. Tangent                   | |___|___|___| |___| |\n");
    printf("11. Natural Log               | | 0 | . | = | | / | |\n");
    printf("12. Log base b                | |___|___|___| |___| |\n");
    printf("13. Power                     |_____________________|\n");
    printf("14. Exponential\n");
    printf("15. Determinant 2x2\n");
    printf("16. Determinant 3x3\n");
    printf("17. Quadratic Solver\n");
    printf("18. All Complex Functions\n");
    printf("19. All unit conversions\n");
    printf("0. Exit\n");
    printf("-------------------\n");

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(BLACK);                  //to set the background colour
    cleardevice();
    setcolor(YELLOW);                   //to set the buttons colour
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    outtextxy(100, 85, "Welcome.Press any key to start!");
    calculator_graphic();               //calling the calculator graphics function
    getch();                            //to close the calculator graphic
    closegraph();
    int choice;
    double a, b;
    int A2x2[2][2], B2x2[2][2], sum2x2[2][2], diff2x2[2][2], prod2x2[2][2];
    int A3x3[3][3], B3x3[3][3], sum3x3[3][3], diff3x3[3][3], prod3x3[3][3];
    int i, j;
    struct complex c1;
    struct complex c2;
    struct complex sum;
    struct complex sub;
    struct complex multi;
    struct complex div;

    double x;
    int c,t;
    char unitnames[9][9]={"nano","micro","milli","centi","base","kilo","mega","giga","tera"};


    while (1)
        {   L2:
            Header();   //to get the heading for the calculator
            Menu();
                //to get the menu of the calculator
            printf("Choose an operation (0 to exit): ");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Enter number-1: ");
                    scanf("%lf",&a);
                    printf("Enter number-2: ");
                    scanf("%lf",&b);
                    printf("Result: %.2f\n", add(a, b));
                    break;

                case 2:
                    printf("Enter number-1: ");
                    scanf("%lf",&a);
                    printf("Enter number-2: ");
                    scanf("%lf",&b);
                    printf("Result: %.2f\n", subtract(a, b));
                    break;

                case 3:
                    printf("Enter number-1: ");
                    scanf("%lf",&a);
                    printf("Enter number-2: ");
                    scanf("%lf",&b);
                    printf("Result: %.2f\n", multiply(a, b));
                    break;

                case 4:
                    printf("Enter number-1: ");
                    scanf("%lf",&a);
                    printf("Enter number-2: ");
                    scanf("%lf",&b);
                    printf("Result: %.2f\n", divide(a, b));
                    break;

                case 5:
                    printf("Enter number-1: ");
                    scanf("%lf",&a);
                    printf("Enter number-2: ");
                    scanf("%lf",&b);
                    printf("Result: %d\n", modulus((int)a, (int)b));
                    break;

                case 6:
                    printf("Enter temperature in Celsius: ");
                    scanf("%lf", &a);
                    printf("Temperature in Fahrenheit= %.2f\n", fahrenheit(a));
                    break;

                case 7:
                    printf("Enter temperature in Fahrenheit: ");
                    scanf("%lf", &a);
                    printf("Temperature in Celsius= %.2f\n", celsius(a));
                    break;

                case 8:
                    printf("Enter angle in degrees: ");
                    scanf("%lf", &a);
                    printf("Sine = %.4lf\n", sine(a));
                    break;

                case 9:
                    printf("Enter angle in degrees: ");
                    scanf("%lf", &a);
                    printf("Cosine = %.4lf\n", cosine(a));
                    break;

                case 10:
                    printf("Enter angle in degrees: ");
                    scanf("%lf", &a);
                    printf("Tangent = %.4lf\n", tangent(a));
                    break;

                case 11:
                    printf("Enter value: ");
                    scanf("%lf", &a);
                    printf("Natural log = %.4lf\n", nlog(a));
                    break;

                case 12:
                    printf("Enter number: ");
                    scanf("%lf",&a);
                    printf("Enter base: ");
                    scanf("%lf",&b);
                    printf("Log base %.2lf of %.2lf = %.4lf\n", b, a, logar(a, b));
                    break;

                case 13:
                    printf("Enter base: ");
                    scanf("%lf",&a);
                    printf("Enter exponent: ");
                    scanf("%lf",&b);
                    printf("Result: %.4lf\n", power(a, b));
                    break;

                case 14:
                    printf("Enter exponent: ");
                    scanf("%lf", &a);
                    printf("e^%.2lf = %.4lf\n", a, expo(a));
                    break;

                case 15:
                    printf("Enter elements of Matrix A (2x2):\n");
                    for (i = 0; i < 2; i++)
                        for (j = 0; j < 2; j++)
                            scanf("%d", &A2x2[i][j]);
                    printf("Enter elements of Matrix B (2x2):\n");
                    for (i = 0; i < 2; i++)
                        for (j = 0; j < 2; j++)
                            scanf("%d", &B2x2[i][j]);
                    add2x2(A2x2, B2x2, sum2x2);
                    subtract2x2(A2x2, B2x2, diff2x2);
                    multiply2x2(A2x2, B2x2, prod2x2);
                    printf("\nSum:\n");
                    displayMatrix2x2(sum2x2);
                    printf("\nDifference (A - B):\n");
                    displayMatrix2x2(diff2x2);
                    printf("\nProduct (A * B):\n");
                    displayMatrix2x2(prod2x2);
                    printf("\nDeterminant of Matrix A: %d\n", determinant2x2(A2x2));
                    printf("Determinant of Matrix B: %d\n", determinant2x2(B2x2));
                    break;

                case 16:
                    printf("Enter elements of Matrix A (3x3):\n");
                    for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                            scanf("%d", &A3x3[i][j]);
                    printf("Enter elements of Matrix B (3x3):\n");
                    for (i = 0; i < 3; i++)
                        for (j = 0; j < 3; j++)
                            scanf("%d", &B3x3[i][j]);
                    add3x3(A3x3, B3x3, sum3x3);
                    subtract3x3(A3x3, B3x3, diff3x3);
                    multiply3x3(A3x3, B3x3, prod3x3);
                    printf("\nSum:\n");
                    displayMatrix3x3(sum3x3);
                    printf("\nDifference (A - B):\n");
                    displayMatrix3x3(diff3x3);
                    printf("\nProduct (A * B):\n");
                    displayMatrix3x3(prod3x3);
                    printf("\nDeterminant of Matrix A: %d\n", determinant3x3(A3x3));
                    printf("Determinant of Matrix B: %d\n", determinant3x3(B3x3));
                    break;

                case 17:
                    quadratic();
                    break;

                case 18:
                    printf("enter real part of number 1:");
                    scanf("%f",&c1.rp);
                    printf("enter imaginary part of number 1:");
                    scanf("%f",&c1.ip);
                    printf("enter real part of number 2:");
                    scanf("%f",&c2.rp);
                    printf("enter imaginary part of number 2:");
                    scanf("%f",&c2.ip);
                    printf("number 1: %.2f+%.2fi\n",c1.rp,c1.ip);
                    printf("number 2: %.2f+%.2fi\n",c2.rp,c2.ip);
                    sum=addComplex(c1,c2);
                    sub=subComplex(c1,c2);
                    multi=mulComplex(c1,c2);
                    div=divComplex(c1,c2);
                    printf("addition=%.2f+%.2fi\n",sum.rp,sum.ip);
                    printf("subtraction=%.2f+%.2fi\n",sub.rp,sub.ip);
                    printf("multiplication=%.2f+%.2fi\n",multi.rp,multi.ip);
                    printf("division=%.2f+%.2fi\n",div.rp,div.ip);
                    break;

                case 19:
                    printf("\n--- Unit Conversion Menu ---\n\n");
                    printf("\n\nAvailable units:\n");
                    printf("\n1. Metric\n2. Imperial\n3. Exit.....\nEnter Choice (1-3):");
                    scanf("%d",&choice);
                    switch (choice)
                        {
                            case 1:
                            printf("\n\nMetric Conversion:\n");
                            for(i=0;i<9;i++)
                                {
                                    printf("%d. %s\n",i+1,unitnames[i]);
                                }

                            printf("10. Exit.....");
                            while(1)
                                {
                                    printf("\nEnter the value to be converted:");
                                    scanf("%lf",&a);
                                    L1:
                                    printf("Enter the current unit(1-9)\nor 10 to exit:");
                                    scanf("%d",&c);
                                    if(c==10)
                                    {
                                        system("cls");
                                        goto L2;
                                    }
                                    printf("Enter the target unit(1-9):");
                                    scanf("%d",&t);
                                    if(c<1 || c>9 || t<1 || t>9)
                                        {
                                            printf("Invalid Selection, try again.");
                                            goto L1;
                                        }
                                printf("Value after conversion=%lf\n",metric(a,c,t));
                                }
                                break;
                            case 2:
                                int conv;
                                printf("\nImperial Conversion:\n");
                                printf("\nAvailable Conversions:\n");
                                printf("1. Inches to Feet\n");
                                printf("2. Feet to Yards\n");
                                printf("3. Miles to Kilometers\n");
                                printf("4. Pounds to Kilograms\n");
                                printf("5. Ounces to Grams\n");
                                printf("6. Gallons to Liters\n");
                                printf("7. Exit.....\n");
                                while(1)
                                {
                                    printf("\nEnter choice of conversion:");
                                    scanf("%d",&conv);
                                        if(conv<1 || conv>6)
                                            goto L2;
                                    printf("Enter the value to be converted:");
                                    scanf("%lf",&a);
                                    printf("\nValue after conversion:%lf\n\n",imperial(conv,a));
                                }
                            break;
                        default:
                            printf("Exiting......\n\n");
                            system("cls");
                            goto L2;
                    }

                case 0:
                    printf("END!GOODBYE!\n");
                    exit(0);

                default:
                    printf("Invalid choice.Try again\n");
            }
        printf("\nPress Enter to continue...");
        getchar();              //first getchar() to clear the buffer, second getchar() to wait for the user's input
        getchar();
        system("cls");         //to clear the screen and start over again
    }
}
