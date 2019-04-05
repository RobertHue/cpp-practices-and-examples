/*File Name: Triangles.java
*	Author: Henry Nguyen
*   KUID: 2465007
*	Email Address: h724n828@ku.edu
*	Lab Assignment: 06
*	Description: Program draws a pyramid of triangles and resizes according to user input of # of triangles on bottom row
*	Last Changed: 10-07-2013
* 
*   Base Code created by Justin Dawson (JDawson@ku.edu)
*/
package edu.ku.eecs168.triangles;


import java.util.Random;

import android.graphics.Color;
import android.os.Bundle;


public class Triangles extends AbsTriangles {

    private int numTriangles = 10; 
    private Random ranGen;
    private int colorType;
    
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		ranGen = new Random();
	}
	
	@Override
	public void onDialogReturned(int num) {
		numTriangles = num;
		repaint();
	}
	

    @Override
    public void colorRows() {
        colorType = 1;
        repaint();
    }

    @Override
    public void colorRandom() {
        colorType = 2;
        repaint();
    }

    @Override
    public void colorGradient() {
        colorType = 3;
        repaint();
    }
	
	// The setColor method of the Graphics class expects color to be specified as a single int.
	// This routine converts RGBalpha values into a single int that setColor can understand.
	// Specify the red, green, blue and alpha values as integers between 0 and 255.
	// Alpha is a transparency component - an alpha of 255 is fully opaque, 
	//   while an alpha of 0 is transparent.
	// The output of rgbToColor is an integer that is in the format expected by setColor,
	// which is specified by a hexidecimal value of the format 0xAARRGGBB
	public int rgbToColor(int red, int green, int blue, int alpha) {
		int color = 0;
		color += blue;
		color += 256*green;
		color += 256*256*red;
		color += 256*256*256*alpha;
		return color;
	}
	
	
	@Override
	public void paint(Graphics canvas) {
		//clear the screen before we draw
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		///////////////////////////////////////////////////////////////
		//Beginning portion of code by Henry Nguyen (h724n828@ku.edu)//
		///////////////////////////////////////////////////////////////
		
		/////////////
		//CONSTANTS//
		/////////////
		final int INITIAL_POSITION_X = 0;
		final int INITIAL_POSITION_Y = canvas.getHeight();
		
		/////////////
		//Variables//
		/////////////
		int position_X = INITIAL_POSITION_X;
		int position_Y = INITIAL_POSITION_Y;
		int screenDivideWidth = canvas.getWidth()/numTriangles; //Divides the screen by number of triangles requested for height and width
		int screenDivideHeight = canvas.getHeight()/numTriangles;
		int triangleSize; //1:1 ratio width and height for triangle
		int row;
		int column;
		
		//Colors the triangles greenish color
		canvas.setColor(rgbToColor(0, 181, 181, 255));

		//Manages triangle size to avoid "squished" look
		if(screenDivideWidth > screenDivideHeight)
		{
			triangleSize = screenDivideHeight;
		}
		else
		{
			triangleSize = screenDivideWidth;
		}
		
		//Required two for loops nested which draw the triangles by row and column
		for(row=numTriangles;row>=0;row--) //Assigns the number of rows to the number of triangles input by user
		{
			for(column=row-1;column>=0;column--) //Dynamically changes columns according to rows
			{
				//Draws triangle
				canvas.drawIsoTriangle(position_X,position_Y,triangleSize,triangleSize);
				position_X = position_X + triangleSize; //Addition because it is traversing right on the X axis
			}
			//Resets X position back after finished with row
			position_X = INITIAL_POSITION_X; 
			position_Y = position_Y - triangleSize; //Must be subtraction since it is traversing up on the Y axis
		}
		
		///////////////
		//End portion//
		///////////////
	}
}