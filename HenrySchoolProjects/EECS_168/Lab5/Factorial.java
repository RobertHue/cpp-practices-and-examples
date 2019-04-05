/* -----------------------------------------------------------------------------
 *
 * File Name:  Factorial.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 5 Exercise 2
 * Description:  This program will take the user input of an positive integer and then output the summation of odd integers up to the end value.
 * Date: 9-30-13
 *
 ---------------------------------------------------------------------------- */
//Imports Scanner package
import java.util.Scanner;

public class Factorial
{

	public static void main(String[] args)
	{
		//Initialization
		//Obtains user input for positive integer as end value
		int userFactorialInput;
		System.out.print("Enter the number to compute factorial: ");
		Scanner input = new Scanner(System.in);
		userFactorialInput = input.nextInt();
		
		//While the user input is negative then keep asking for a non-negative number
		while(userFactorialInput < 0)
		{
			System.out.print("Please enter a non-negative number: ");
			userFactorialInput = input.nextInt();
		}
		
		//Generates factorial value
		//Initialize counter variable and ending factorial variable
		int counter = 1;
		int factorial = 1;
		//Loops until it reaches user factorial goal
		while(counter <=userFactorialInput)
		{
			//Multiply factorial with current counter value
			factorial = factorial * counter;
			counter = counter + 1; //Increment counter variable
		}
		
		//Outputs factorial for user
		System.out.println("The factorial is " + factorial);
	}

}
