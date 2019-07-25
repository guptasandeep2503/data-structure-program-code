#include<stdio.h>
#include<string.h>
struct stack
{
    char arr[20];
    int top;
};
void convert(char *);
void push(struct stack *,char ch);
char pop(struct stack *);
int main()
{
    char prefix[20];
    printf("\nenter the prefix expression:-");
    scanf("%s",&prefix);
    convert(prefix);
    return 0;
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
    printf("\n%s",infix);
}
