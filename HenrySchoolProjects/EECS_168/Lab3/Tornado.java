/* -----------------------------------------------------------------------------
 *
 * File Name: Tornado.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment: EECS-168/169 Lab 3
 * Description: Obtains the user input value of wavelength and returns which color is associated with that value.
 * Date: 09/16/13
 *
 ---------------------------------------------------------------------------- */

import java.util.Scanner; //Imports Scanner package

public class Tornado
{
	public static void main(String[] args)
	{
		double windSpeed;
		
		System.out.println("Enter the wind speed:"); //Prompts user for wind speed input and sets up user double-typed input
		Scanner input = new Scanner(System.in);
		windSpeed = input.nextDouble();
		
		//Differentiates between and identifies to the user the possible Fujita wind speeds and values that cannot be categorized.
		if(windSpeed >= 40 && windSpeed <= 318)
		{
			if(windSpeed <= 157) //Splits types above or below F-3 category
			{
				if(windSpeed <= 72)										//40 - 72 MPH - F-0 
					System.out.println("The tornado is a F-0 tornado."); 
				else if(windSpeed <= 112)								//72 - 112 MPH - F-1 (72 excluded, 112 included) 
					System.out.println("The tornado is a F-1 tornado.");
				else													//112 - 157 MPH - F-2 
					System.out.println("The tornado is a F-2 tornado.");
			}
			else
			{
				if(windSpeed <= 205)									//157 - 205 MPH - F-3 
					System.out.println("The tornado is a F-3 tornado.");
				else if(windSpeed <= 260)								//205 - 260 MPH - F-4 
					System.out.println("The tornado is a F-4 tornado.");
				else													//260 - 318 MPH - F-5 
					System.out.println("The tornado is a F-5 tornado.");
			}
		}
		else
		{	//NOT A FUJITA TORNADO
			System.out.println("This value cannot be categorized as one of the six Fujita categories of tornados.");
		}
		
		
	}

}
