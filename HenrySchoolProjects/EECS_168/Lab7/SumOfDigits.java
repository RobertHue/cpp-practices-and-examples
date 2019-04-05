/* -----------------------------------------------------------------------------
 *
 * File Name:  SumOfDigits.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 7 Exercise 2
 * Description: This program will take the user input of an integer and print the summation of the digits of said integer
 * Date: 10-21-13
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;

public class SumOfDigits {

	public static void main(String[] args)
	{
		//Initialize variables
		int initialNumber;
		int repeat = 1;
		
		do
		{
			//Takes user input for initial number
			Scanner input = new Scanner(System.in);
			System.out.println("Please enter a No:");
			initialNumber = input.nextInt();
			addDigits(initialNumber); //Calls the method which calculates and prints the result
			
			do //Request if user wants to repeat until valid answer
			{
				System.out.println("Want to try again?(y=1/n=0):");
				repeat = input.nextInt();
			}
			while(repeat < 0 || repeat > 1);
		}
		while(repeat == 1); //Loop as long as the user wants to repeat
		
		System.out.println("Thank you!");
	}
	
	
	public static void addDigits(int x)
	{
		int sum = 0;
		int remainderDigits = x;
		do
		{
			sum+= remainderDigits%10; //Add current digit to sum
			remainderDigits = remainderDigits/10; //Remove rightmost digit
		}
		while(remainderDigits!=0); //Loop while the reminaingDigits exist. *Note use != 0 in order to incorporate negative number summation

		System.out.println("The sum of the digits is:"+sum+"\n");
	}

}
