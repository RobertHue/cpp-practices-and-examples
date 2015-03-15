/* -----------------------------------------------------------------------------
 *
 * File Name: Color.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment: EECS-168/169 Lab 3
 * Description: Obtains the user input value of wavelength and returns which color is associated with that value.
 * Date: 09/16/13
 *
 ---------------------------------------------------------------------------- */

import java.util.Scanner; //Imports Scanner package

public class Color
{
	public static void main(String[] args)
	{
		double wavelength;
		
		System.out.println("Enter a wavelength in nm:"); //Prompts user for wavelength input and sets up user double-typed input
		Scanner input = new Scanner(System.in);
		wavelength = input.nextDouble();
		
		//Differentiates between visible spectrum wavelengths and not-visible
		if(wavelength >= 380 && wavelength <= 750) 
		{
			//Differentiates wavelengths between dark and light colors
			if(wavelength <= 570) 			//DARK COLORS//
			{
				if(wavelength <= 450) 		//Identifies wavelength as Violet between 380-450
					System.out.println("The color is Violet.");
				else if(wavelength <= 495) 	//Identifies wavelength as Blue between 450-495
					System.out.println("The color is Blue.");
				else 						//Identifies wavelength as Green between 495-570
					System.out.println("The color is Green.");
			}			
			else							//LIGHT COLORS//
			{
				if(wavelength < 590)		//Identifies wavelength as Yellow between 570-590
					System.out.println("The color is Yellow.");
				else if(wavelength < 620)	//Identifies wavelength as Orange between 590-620
					System.out.println("The color is Orange.");
				else						//Identifies wavelength as Red between 620-750
					System.out.println("The color is Red.");
			}
		}
		else	//NOT VISIBLE
			System.out.println("The entered wavelength is not a part of the visible spectrum.");

	}
}
