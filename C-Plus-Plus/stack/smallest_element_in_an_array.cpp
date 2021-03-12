// Program to find the minimum element of an array using stack in O(1) space complexity and time complexity.
#include <bits/stdc++.h>
using namespace std;


//Creating a user-defined structure for operation on stack;
class UserStack
{ 
    private:
    stack<int> s; 
    int min;
    
    public:
    int getMin() 
    { 
        if (s.empty()) 
        {
            return INT_MAX;   //Invalid operation hence returning -1;
        } 
  
        else
        {
            return min;
        }
           
    } 
    
    
     void push(int x) 
    { 
       
        if (s.empty()) 
        { 
            min = x; 
            s.push(x); 
            return; 
        } 
        
        
     // If new number to be pushed is less than min
        if (x < min) 
        { 
            s.push(2*x - min); 
            min = x; 
        } 

        else
        {
             s.push(x); 
  
        }
          
    }
    
    
    void peek() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty "; 
            return; 
        } 
  
        int t = s.top();  
  
  
  // If t < min means min stores value of t.
  
        cout << "Top Most Element is:"; 
           if(t<min)
           {
               cout<<min<<"\n";
           }
           else
           {
               cout<<t<<"\n";
           }
        
       
    } 
    
    
    void pop() 
    { 
        if (s.empty()) 
        { 
            cout << "Stack is empty can't do pop operation\n"; 
            return; 
        } 
  
        
        int t = s.top(); 
        s.pop(); 
  
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if (t < min) 
        { 
             
            min = 2*min - t; 
        } 
  
         
    } 
    
    
    
    
    
};
int main()
{
    int size;
    cout<<"Enter the size of array of which you want to find minimum\n";
    cin>>size;
    
    int A[size];
    
    cout<<"Enter the elements of array\n";
    
    for(int i=0;i<size;i++)
    {
        cin>>A[i];
    }
   
   //Creating an object of UserStack class defined by us
   UserStack S;
   
   for(int i=0;i<size;i++)
   {
       S.push(A[i]);
   }
   
   
   if(S.getMin()==INT_MAX)
   {
       cout<<"Stack is empty\n";
   }
   else
   {
        cout<<"The minimum element of the array using stack is:"<<S.getMin()<<"\n";
   
   }
  
   
    return 0;
}
