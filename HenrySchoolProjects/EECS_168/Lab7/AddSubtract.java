/* -----------------------------------------------------------------------------
 *
 * File Name:  AddSubtract.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 7 Exercise 1
 * Description:  This program will take the user input of two integers and print the sum and difference using different method calls.
 * Date: 10-21-13
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;

public class AddSubtract {
	public static void main(String[] args) {
		
		//Initialize initial variables
		int x;
		int y;
		int repeat = 1;
		
		do
		{
			Scanner input = new Scanner(System.in); //Takes input for x and y from the user
			System.out.println("Please enter the 1st No:");
			x=input.nextInt();
			System.out.println("Please enter the 2nd No:");
			y=input.nextInt();
		
			addSub(x,y); //Calls addSub() method which calls add() and sub() method within
		
			System.out.println("\nNow you are calling 2 different methods add and sub which return values as");
			int sum=add(x,y);
			int difference=sub(x,y);
			System.out.println("Sum="+sum+"\nDifference="+difference);
			
			do //Request if user wants to repeat until valid answer
			{
				System.out.println("It was fun right! Want to do again?(y=1/n=0):");
				repeat=input.nextInt();
			}
			while(repeat < 0 || repeat > 1);
		}
		while(repeat==1); //Loop as long as the user wants to repeat
		
		System.out.println("Enough of Addition and Subtraction. I am not in Elementary School any more!");
	}
	
	public static void addSub(int firstTerm, int secondTerm){ //Does not return anything
		int sum=add(firstTerm,secondTerm); //Assign sum and difference using the add() and sub() functions
		int difference=sub(firstTerm,secondTerm);
		System.out.println("You are inside Method addSub where Sum="+sum+" and Difference="+difference);
	}

	public static int add(int firstTerm, int secondTerm){ //Returns summation of two unique integers
		return firstTerm + secondTerm;
	}
	
	public static int sub(int firstTerm, int secondTerm){ //Returns difference of two unique integers
		return firstTerm - secondTerm;
	}
}
