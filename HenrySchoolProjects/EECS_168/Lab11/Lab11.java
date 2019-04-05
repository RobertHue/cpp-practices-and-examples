/* -----------------------------------------------------------------------------
 *
 * File Name:  Lab11.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 11
 * Description:  Utilizes included BubbleSort class to sort a randomly generated array and reports the time it takes to sort.
 * Date: 12-2-13
 *
 ---------------------------------------------------------------------------- */

import java.util.Random;
import java.util.Scanner;

public class Lab11
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		Random random = new Random();
		int MAX_RANDOM = 256;	//Random only picks values from 0 to 255
		int arraySize;
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Ask user for array size
		do
		{
		System.out.println("How many random numbers do you want to make?");
		arraySize = input.nextInt();
			if(arraySize <= 0)
			{
				System.out.println("Sorry that input value is invalid. Please re-input your array size");
			}
		}	//Ensures array size is greater than 0
		while(arraySize <= 0);
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Obtain ascending order or descending order
		int choice = -1;
		do
		{
			//User chooses ascending order or descending order
			System.out.print("\nWould you like to sort the array in ascending or descending order? (0 for ascending, 1 for descending):");
			choice = input.nextInt();
			
			if(choice > 1 || choice < 0)
			{
				System.out.println("Sorry that is an invalid answer. Please re-input your choice");
			}
		}	//Ensures choice is either 1 or 0. If not then ask user to re-input choice
		while(choice > 1 || choice < 0);
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Generates random value array
		System.out.println("\nUnsorted Array:");
		int[] array = new int[arraySize];
		
		for(int i = 0 ; i < arraySize; i++)
		{
			//Input random value
			array[i] = random.nextInt(MAX_RANDOM);
			System.out.print(array[i] + " ");
		}
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Create object for sorting and declare timer related variables then sort
		BubbleSort bubbleSorter = new BubbleSort();
		long startTime = 0;
		long endTime = 0 ;
		
		if(choice == 0) //Sort by ascending
		{
			//Start timer
			startTime = System.nanoTime();
			System.out.println("\n\nStarting sort at "+ startTime);
			
			//Sort
			bubbleSorter.ascendingSort(array);
			
			//End timer
			endTime = System.nanoTime();
			System.out.println("Stopping sort at " + endTime + "\n");
		}
		else if(choice == 1) //Sort by descending
		{
			//Start timer
			startTime = System.nanoTime();
			System.out.println("\n\nStarting sort at "+ startTime);
			
			//Sort
			bubbleSorter.descendingSort(array);
			
			//End timer
			endTime = System.nanoTime();
			System.out.println("Stopping sort at " + endTime + "\n");
		}
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Prints out sorted array results
		System.out.println("Sorted Array: ");
		for(int i = 0 ; i < arraySize; i++)
		{
			System.out.print(array[i] + " ");
		}
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Reports how long the sorting took
		long elapsedTime = endTime - startTime;
		System.out.print("\nThis sort took a total of " + elapsedTime + " nanoseconds or ");
		System.out.printf("%f seconds.", (elapsedTime/1000000000.0));
		
	}

}
