#include<stdio.h>
#include<string.h>
struct stack
{
    char arr[20];
    int top;
};
void convert(char *);
int main()
{
    char infix[20];
    printf("\nenter the infix expression:-");
    scanf("%s",&infix);
    convert(infix);
    return 0;
}
int isoperand(char ch)
{
    if((ch>=65&&ch<=90)||(ch>=96&&ch<=122)||(ch>=48&&ch<=57))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *p,char ch)
{
    p->top=p->top+1;
    p->arr[p->top]=ch;
}
char pop(struct stack *p)
{
    char ele;
    ele=p->arr[p->top];
    p->top=p->top-1;
    return ele;
}
int preced(char ch)
{
    if(ch=='+'||ch=='-')
    {
        return 1;
    }
    else if(ch=='*'||ch=='/'||ch=='%')
    {
        return 2;
    }
    else if(ch=='$')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void convert(char infix[])
{
    int i,j=0;
    char ch;
    char prefix[20];
    struct stack s;
    s.top=-1;
    for(i=0;i<=20;i++)
    {
        prefix[i]='\0';
    }
    for(i=strlen(infix)-1;i>=0;i--)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            prefix[j]=ch;
            j++;
        }
        else
        {
            while(s.top!=-1)
            {
                if(preced(ch)<preced(s.arr[s.top]))
                {
                    prefix[j]=pop(&s);
                    j++;
                }
                else
                {
                    break;
                }
            }
            push(&s,ch);
        }
    }
    while(s.top!=-1)
    {
        prefix[j]=pop(&s);
        j++;
    }
    strrev(prefix);
    printf("\n%s",prefix);
}
