/* -----------------------------------------------------------------------------
 *
 * File Name:  ConvertTemperature.java
 * Author: Henry Nguyen h724n828@ku.edu 
 * Assignment:   EECS-168/169 Lab 2
 * Description:  This program will convert the input temperature from Fahrenheit to Celsius.
 * Date: 09/09/13
 *
 ---------------------------------------------------------------------------- */
//Start your program.

import java.util.Scanner;

public class ConvertTemperature
{
	public static void main(String[] args)
	{
		//Variable Declarations
		double fahrenheit;
		double celsius;
		
		//Asks and obtains user input into fahrenheit
		System.out.println("Enter the temperature in Fahrenheit:"); //Sets up scanner
		Scanner input = new Scanner(System.in);
		fahrenheit = input.nextDouble(); //Obtains the next double value

		//Converts fahrenheit to celsius
		celsius = 5*(fahrenheit - 32)/9;

		//Displays output
		System.out.println("*Conversion:\n" + fahrenheit + " degrees Fahrenheit = " + celsius + " degrees Celsius");
	}
}
