 package mypack;
/*    Tribonacci Series:
 
  Tribonacci series is a generalisatoin of Fibonacci series where the current element(greater than 0) is the sum of preceding three elements,
  Let T be the Tribonacci series upto n terms then, T(n)=T(n-1)+T(n-2)+T(n-3).  */

/*    Approach:

   A term is the sum of preceding three terms in this series. The sum of three preceding variables will be stored in "sum" variable.
   The first of the three variable terms will be overrided by second variable term which in turn will be overrided by third one and the third term will be 
   overrided by the sum. This process will continue till n terms.  */ 

 import java.util.Scanner;
 public class tribonacci 
 {
    public static void main(String [] args)
    { 

        Scanner scan = new Scanner(System.in);
        long num;
	long first=0,second=0,third=1,sum=0,count=0;
        System.out.println("Enter the number upto which the series is to be printed");
        num=scan.nextLong();

        while(num>0)	
        {
            count++;
            if(count==1)	
            System.out.print(0);
            else if(count==2)
            System.out.print(", "+0);
            else if(count==3)
            System.out.print(", "+1);
            else    //Applicable to all the terms other than the first three terms of the series.
            {
            sum=first+second+third;	
            System.out.print(", "+sum);
            first=second;second=third;third=sum;  //Storing the values of succeeding terms in respective variables.
            }
         num--;    //Decreasing the value of total number of terms by one after each iteration.
        }
    }
 }

 /*                                              OUTPUT:

 Test Case 1:

 Enter the number upto which the series is to be printed
 23
 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415

 Test Case 2:

 Enter the number upto which the series is to be printed
 5
 0, 0, 1, 1, 2

 Space Complexity: O(1)
 Time Complexity: O(n)

 */
 
