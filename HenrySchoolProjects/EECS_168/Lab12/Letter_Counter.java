/* -----------------------------------------------------------------------------
 *
 * File Name:  Letter_Counter.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 12
 * Description:  Program takes user input for a input filename. It then reads and analyzes data and creates and output file based on that data.
 * Date: 12-9-13
 *
 ---------------------------------------------------------------------------- */


import java.io.*;
import java.util.*;

public class Letter_Counter {

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		FileReader fstream;
		BufferedReader in;
		String filename;
		
		
		//Begin reading input file
		System.out.println("Enter a file name:");
		filename = input.nextLine();
		try
		{
			fstream = new FileReader(filename);
			in = new BufferedReader(fstream);
			int[] results = new int[52];
			
			//Keeps reading next line until line is null
			String line = in.readLine();
			while(line != null)
			{
				
				//Parse through every character of the line
				for(int i = 0; i<line.length(); i++)
				{
					char selected_character = line.charAt(i);
					  //Place letters in bucket array
					  //If character is between capital letters A-Z
					if((int)selected_character >= 65 && (int)selected_character <= 90)
					{
						results[(int)selected_character - 65]++;
					}//If character is between lowercase letters a-z
					else if((int)selected_character >= 95 && (int)selected_character <= 122)
					{
						results[(int)selected_character - 71]++;
					}
				}
				
				//Continue to next line
				line = in.readLine();
			}
			//Close buffered reader
			in.close();
			
			//Begin writing output file.
			try
			{
				FileWriter fstream2 = new FileWriter("output.txt");
				BufferedWriter out = new BufferedWriter(fstream2);
			
				out.write("\nThe file contains the following letters:");
				//Count
				for(int i = 0; i < results.length; i++)
				{
					//lowercase letters
					if(i >= 26)
					{
						out.write("\n" + (char)(i+71) + ": " + results[i]);
					}
					else //uppercase letters
					{
						out.write("\n" + (char)(i+65) + ": " + results[i]);
					}
				}
				out.close();
				System.out.println("output.txt created.");
			}
			
			catch (Exception e)
			{
				System.err.println("Error: " + e.getMessage());
			}
			
		}
		catch(Exception e)
		{
			
		}
		
		

	}

}
