
/* -----------------------------------------------------------------------------
 *
 * File Name:  Summation.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 5 Exercise 3
 * Description:  This program will calculate and output the summation between the beginning and ending values given by the user.
 * Date: 9-30-13
 *
 ---------------------------------------------------------------------------- */
//Imports Scanner package
import java.util.Scanner;

public class Summation
{

	public static void main(String[] args)
	{
		//Gives user brief description of program
		System.out.println("Welcome! This program calculates the summation of consecutive integers.\n");
		
		//Obtains initial value
		int initial;
		System.out.print("Please input a positive integer as the initial value: ");
		Scanner input = new Scanner(System.in);
		initial = input.nextInt();
		
		//Checks if initial is negative value and continues to prompt user until it is a positive value
		while(initial < 0)
		{
			System.out.print("Please input a positive integer as the initial value: ");
			initial = input.nextInt();
		}
		
		//Obtains end value
		int end;
		System.out.print("Please input a positive integer as the end value: ");

		end = input.nextInt();
		
		//Checks if end is negative value and continues to prompt user until it is a positive value
		while(end < initial)
		{
			System.out.println("\nThe end value is invalid. Please input a positive integer greater than initial value as the end value: ");
			end = input.nextInt();
		}
		
		//Initializes variables for for loop
		int counter;
		int sum = 0;
		
		for(counter = initial; counter <= end; ++counter)
		{
			sum = sum + counter; //Obtains summation while incrementing counter variable
		}
		
		//Outputs summation for user
		System.out.println("\nThe summation is : " + sum);
	}

}
