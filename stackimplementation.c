#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

char sc[100]; // stack for operators
int topc=-1;
int sn[100]; //stack for numbers
int topn=-1;

//defining push and pop for stack c=operands, n=numbers.....

void pushc(char c)
{
    sc[++topc]=c;
}

void pushn(int a)
{
    sn[++topn]=a;
}

char popc()
{
    return sc[topc--];
}

int popn()
{
    return sn[topn--];
}

int priority(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return 0;
    }
}

void conversion(char in[],char out[]) //infix to postfix
{
    char *e=in;
    char f;

    while(*e!=0) //null char
    {
        if(isdigit(*e))
            {
                while(isdigit(*e))
                {
                    strncat(out, e, 1);
                    e++;
                }
        strcat(out, " ");
        continue;
            }

        else if(*e=='(')
            pushc(*e);

        else if(*e==')')
        {
            while((f=popc())!='(')
            {
                strncat(out,&f,1);
                strcat(out," ");
            }
        }
        else
        {
            while(topc!=-1 && priority(sc[topc])>=priority(*e))
            {
                f=popc();
                strncat(out,&f,1);
                strcat(out," ");
            }
            pushc(*e);
        }
        e++;
    }
    while(topc!=-1)
    {
        f=popc();
        strncat(out,&f,1);
        strcat(out," ");
    }
}

int evaluation(char out[])
{
    char* e=out;
    int a,b,n=0;

    while(*e!=0)
    {
        if(isdigit(*e))
        {
            while(isdigit(*e))
            {
                n=n*10+(*e-'0');
                e++;
            }
        pushn(n);
        n=0;
        }
        else if(*e==' ')
            e++;
        else
        {
            b=popn();
            a=popn();
            switch (*e)
            {
                case '+':
                    pushn(a+b);
                    break;
                case '-':
                    pushn(a-b);
                    break;
                case '*':
                    pushn(a*b);
                    break;
                case '/':
                    pushn(a/b);
                    break;
                case '^':
                    pushn((int)pow(b,a));
                    break;
            }
            e++;
        }
    }
    return popn();
}

int main()
{
    char input[100], output[100]="";
    printf("Enter the expression that you wish to have evaluated:");
    scanf("%[^\n]s",input);
    conversion(input,output);

    printf("Result=\t%d",evaluation(output));
}
