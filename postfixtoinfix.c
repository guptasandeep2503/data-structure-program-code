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

    char postfix[20];
    printf("\nenter the postfix expression:-");
    scanf("%s",&postfix);
    convert(postfix);
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
void convert(char postfix[])
{
    int n,i,j=0;
    char ch;
    char infix[20];
    struct stack s;
    s.top=-1;
    n=strlen(postfix);
    for( i=0;i<20;i++)
    {
        infix[i]='\0';
    }
    for(i=n-1;i>=0;i--)
    {
        ch=postfix[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='$')
        {
            push(&s,ch);
        }
        else
        {
            infix[j]=ch;
            j++;
            if(s.top!=-1)
            {
                infix[j]=pop(&s);
                j++;
            }
        }
    }
    strrev(infix);
    printf("\n%s",infix);

}

