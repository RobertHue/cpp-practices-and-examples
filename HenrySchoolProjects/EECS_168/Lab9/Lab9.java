/* -----------------------------------------------------------------------------
 *
 * File Name:  Lab9.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 9
 * Description:  This program creates an integer array accordingly to user input of size and contents. It then calculates and prints the sum, average, largest and smallest number in the array.
 * Date: 11-4-13
 *
 ---------------------------------------------------------------------------- */
//Imports Scanner package

import java.util.Scanner;

public class Lab9 {

	public static void main(String[] args) {
		//Initialize array size
		int numToStore = 0;
		//Declare scanner input
		Scanner input = new Scanner(System.in);
		//Takes input for array size that is larger than 0
		System.out.println("Input an array size: ");
		numToStore = input.nextInt();
		while(numToStore < 1)				//while loop ensures user inputs a larger than 0 integer
		{
			System.out.println("Sorry that array size is invalid. Please input a valid array size: ");
			numToStore = input.nextInt();
		}
		
		///////////////////////////////////////////////////////
		//Creates the array accordingly to desired array size//
		///////////////////////////////////////////////////////
		int[] theArray = new int[numToStore];
		
		
		///////////////
		//ARRAY INPUT//
		///////////////
		System.out.println("Now please enter " + (numToStore) + " numbers");
		for(int i=0;i<theArray.length;i++)	//Reads in incrementing fashion
		{
			System.out.print("Input a number into your array: ");
			theArray[i] = input.nextInt();	//Obtains array element for element number
		}
		
		//////////////////////////////////////
		//Resulting variables initialization//
		//////////////////////////////////////
		int sum = 0;
		int average = 0;
		int largest=theArray[0];
		int smallest=theArray[0];
		
		////////////////
		//ARRAY OUTPUT//
		////////////////
		System.out.println("Here are all the numbers in your array:");
		for(int i=(theArray.length-1);i>=0;i--) //Reads in decrementing fashion
		{
			int element = theArray[i]; 		//Stores current array element into a variable for comparison
			
			System.out.println(element);	//Prints array content
			sum+=element; 					//Adds element to summation
			if(element>largest) 			//Compares element to smallest and largest number
			{
				largest = element;	
			}
			if(element<smallest)
			{
				smallest = element;
			}
		}
		average = sum / theArray.length; 	//Calculates average by summation divided by number of entries
		System.out.println("The sum of all values is: " + sum);
		System.out.println("The average of all values is: " + average);
		System.out.println("The largest value is: "  + largest);
		System.out.println("The smallest value is: " + smallest);
	}

}
