#include<stdio.h>
#include<math.h>
struct stack
{
    int arr[10];
    int top;
};
int main()
{
    char postfix[10];
    int ans;
    printf("\nenter the postfix expression:-");
    scanf("%s",&postfix);
    ans=solve(postfix);
    printf("answer of the expression is:-");
    printf("%d",ans);
    return 0;
}
int isoperand(char ch)
{
    if(ch>=48&&ch<=57)
    {
        return 1;
    }
    return 0;
}
int calculate(int op1,int op2,char ch)
{
    switch(ch)
    {
        case '+': return (op2+op1);
        case '-': return (op2-op1);
        case '*': return (op2*op1);
        case '/': return (op2/op1);
        case '%': return (fmod(op2,op1));
        default: return -1;
    }
}
void push(struct stack *p,int ele)
{
    p->top=p->top+1;
    p->arr[p->top]=ele;
}
int pop(struct stack *p)
{
    int x;
    x=p->arr[p->top];
    p->top=p->top-1;
    return x;
}
int solve(char postfix[])
{
    struct stack s;
    s.top=-1;
    int i,op1,op2;
    int res;
    char ch;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isoperand(ch)==1)
        {
            push(&s,(int)ch-48);
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            res=calculate(op1,op2,ch);
            push(&s,res);
        }
    }
    res=pop(&s);
    return res;
}
