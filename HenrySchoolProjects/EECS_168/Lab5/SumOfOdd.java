/* -----------------------------------------------------------------------------
 *
 * File Name:  SumOfOdd.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 5 Exercise 1
 * Description:  This program will take the user input of an positive integer and then output the summation of odd integers up to the end value.
 * Date: 9-30-13
 *
 ---------------------------------------------------------------------------- */
//Imports Scanner package
import java.util.Scanner;


public class SumOfOdd
{

	public static void main(String[] args)
	{
 
		//Obtains user input for positive integer as end value
		int posEndValue;
		System.out.print("Please input a positive integer as the end value: ");
		Scanner input = new Scanner(System.in);
		posEndValue = input.nextInt();
 
		//Sets up counter and sum variables for addition and incrementing
		int counter = 1;
		int sum = 0;
		
		while((counter)<=posEndValue)
		{
			
			sum=sum+counter; //Add counter value to summation
			counter=counter+2; //Skips counter once in order to get odd values
		}
		
		//Outputs summation
		System.out.print("The summation is: " + sum);
	}
}
