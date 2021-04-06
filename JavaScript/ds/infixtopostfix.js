/*
 This project converts infix expression to postfix expression in JavaScript.

 Infix expression:-  The expression of the form a op b. 
 When an operator is in-between every pair of operands.

 Postfix expression:-  An expression is called the postfix expression
  if the operator appears in the expression after the operands. 
  Simply of the form (operand1 operand2 operator). 

*/

var stackarr=[];
var topp=-1;

// function for push  in stack
function push(e)
{
   topp++;
   stackarr[topp]=e;
}

// function for pop from stack
function pop()
{
    if(topp==-1)
    return 0;
    else
    {
        var popped_ele=stackarr[topp];
        topp--;
        return popped_ele;
    }
}

// function operator for checking isoperator
function operator(op)
{
    return ((op=='+' || op=='-' || op=='^' || op=='*' || op=='/' || op=='(' || op==')')? true:false);
}

// function for precedency
function precedency(pre)
{
    if(pre=='@' || pre=='(' || pre==')')
    {
        return 1;
    }
    else if(pre=='+' || pre=='-')
    {
        return 2;
    }
    else if (pre=='/' || pre=='*')
    {
        return 3;
    }
    else if(pre=='^')
    {
        return 4;
    }
    else
    return 0;
}

// function that convert infix to postfix
function InfixtoPostfix(infixval)
{
    var postfix=[];
    var temp=0;
    push('@');
   
    
    for(var i=0;i<infixval.length;i++)
    {
        var el=infixval[i];
        if(operator(el))
        {
            if (el ==')') {
                while (stackarr[topp] != "(") {
                  postfix[temp++] = pop();
                }
          pop();
            }
            else if(el=='(')
            {
                push(el);
            }
  // compare precedency 
            else if(precedency(el)>precedency(stackarr[topp]))
            {
                push(el);
            }
            else
            {
                while(precedency(el)<=precedency(stackarr[topp])&&topp>-1)
                {
                     postfix[temp++]=pop();
                }
                push(el);
            }
        }
        else{
            postfix[temp++]=el;
        }

        
    }
    while(stackarr[topp]!='@')
    {
        postfix[temp++]=pop();
    }
    var st="";
    for(var j=0;j<postfix.length;j++)
    {
        st+=postfix[j];
    }    

    // Print postfix expression in console
    
    console.log("Postfix Expression:- "+st);
 }
 
//  Caling Function InfixtoPostfix

 InfixtoPostfix("((a+b)*c)");




 /*
OutPut:
ab+c*

Time Complexity:O(N)
Space Complexity: O(N)

Input:
A+B*C/(E-F)

Output:
ABC*EF-/+


Input:
a+b*(c^d-e)^(f+g*h)-i

Output:
abcd^e-fgh*+^*+i-
 */
