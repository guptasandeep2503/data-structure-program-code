#include<stdio.h>
#include<string.h>
struct stack
{
    char arr[20];
    int top;
};
void convert(char *);
void infixtopostfix(char *);
int main()
{
    char prefix[20];
    printf("enter the prefix notation:-");
    scanf("%s",&prefix);
    convert(prefix);
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
void infixtopostfix(char infix[])
{
    int i,j=0;
    char ch;
    struct stack s;
    s.top=-1;
    char postfix[20];
    for(i=0;i<20;i++)
    {
        postfix[i]='\0';
    }
    for(i=0;i<infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            postfix[j]=ch;
            j++;
        }
        else
        {
            while(s.top!=-1)
            {
                if(preced(ch)<=preced(s.arr[s.top]))
                {
                    postfix[j]=pop(&s);
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
        postfix[j]=pop(&s);
        j++;
    }
    printf("%s",postfix);
}

void convert(char prefix[])
{
    int i,j=0,n;
    char ch;
    struct stack s;
    char infix[20];
    s.top=-1;
    n=strlen(prefix);
    for(i=0;i<20;i++)
    {
      infix[i]='\0';
    }
    for(i=0;i<n;i++)
    {
        ch=prefix[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='$')
        {
            push(&s,ch);
        }
        else
        {
            infix[j]=ch;
            j++;
            infix[j]=pop(&s);
            j++;
        }
    }
    infixtopostfix(infix);
}
