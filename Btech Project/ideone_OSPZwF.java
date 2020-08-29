/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
	       int arr[][]=new int[10][2];
        int dest,fl=0,c0=0,c2,c1,buffer=0,sample=0,buffc;
        int b=1,s=1,p=0;    /*these are the quantity of required sample and buffer needed for each mixture*/
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter the concentration of the sample: ");
        buffc=scanner.nextInt();
        c2=c1=buffc;
        System.out.println("Enter the density you want: ");
        dest=scanner.nextInt();
        System.out.println("\tc0\t\tc2\t\tc1");
        while(c2!=dest) {
            arr[fl][0] = c0;
            arr[fl][1] = c1;
            ++fl;
            c2 = (c0 + c1) / 2;
            System.out.println(fl + "\t" + arr[fl - 1][0] + "\t\t" + c2 + "\t\t" + arr[fl - 1][1]);
            if (dest < c2) {
                c1 = c2;                        /*if the concentration needed <c2*/
            } else if (dest > c2) {
                c0 = c2;                        /*if the concentration needed >c2*/

            }
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        for(int i=fl-2;i>=0;i--)
        {
            if(arr[i][0]==arr[i+1][0]) {
                //++b;
                s=(s+1) / 2;
                b=b+s;
            }
            else
            {
                //++s;
                b=(b+1)/2;
                s=s+b;
            }
            System.out.println("b= "+b+" s= "+s);

        }
        sample=s;
        buffer=b;
        /*if(dest>buffc/2)
            sample+=1;
        else if(dest<buffc/2)
            buffer+=1;*/
        System.out.println("\nBuffer: "+buffer+" Sample: "+sample);
 	// your code goes here
	}
}