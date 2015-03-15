/* -----------------------------------------------------------------------------
 *
 * File Name:  CircleArray.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 10
 * Description:  This program generates N amount of circles and randomly moves the circle one-by-one
 * Date: 11-11-13
 *
 ---------------------------------------------------------------------------- */
package edu.ku.eecs168.circleArray;

import android.os.Bundle;

import java.util.Random;
import android.graphics.Color;
public class CircleArray extends AbsCircleArray {
	private Random random;
	
	// TODO: Declare the instance variables that you will need to complete the assignment here.
	private int MAX_RAND_INT;		//Circle Position Boundary
	private int circleDiameter;
	private int[] x;
	private int[] y;
	private int[] color;
	private int N_circles;			//Maximum circles
	private int cur_circle;			//Circle selector
	
	public CircleArray() {
		// Instantiate an object of class Random
		// This allows me to get random numbers by calling random.nextInt(MAX_RAND_INT), where MAX_RAND_INT is the highest possible value
		random = new Random();
		
		// TODO: Initialize your instance variables here
		MAX_RAND_INT = 500;
		N_circles = 20;
		circleDiameter = 100;
		
		//Initializes both x and y arrays with random positions
		setNCircles(N_circles);
	}
	
	
	@Override
	public void paint(Graphics canvas) {
		// Clear the canvas (don't change this part)
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		// TODO: Add your code for painting the screen here.
		
		for(int i=0; i < N_circles;++i)
		{
			
			//Draw colored fill. Use array to retain color info for specific circle
			canvas.setColor(color[i]);
			canvas.fillOval(x[i], y[i], circleDiameter, circleDiameter);
			
			//Draw black outline
			canvas.setColor(Color.BLACK);
			canvas.drawOval(x[i], y[i], circleDiameter, circleDiameter);	
		}
		
		x[cur_circle] = random.nextInt(canvas.getWidth());
		y[cur_circle] = random.nextInt(canvas.getHeight());
		
		
		//Change selector to next oldest circle
		cur_circle++;
		if(cur_circle >= N_circles)
			cur_circle = 0;
		
	}
	
	@Override
	public void onDialogReturned(int num) {
		// You must call super.onDialogReturned to start the simulation
		super.onDialogReturned(num);
		
		// onDialogReturned is called when the user uses the "Add Shapes" button to change the number of circles.
		// TODO: Add your code to update the number of circles here.
		setNCircles(num);
	}
	
	private void setNCircles(int N)
	{
		//Set Selector to beginning
		cur_circle = 0;
		
		//Sets new array size for x and y
		N_circles = N;
		x = new int[N_circles];
		y = new int[N_circles];
		color = new int[N_circles];
		
		//Assign random position and color to each element
		for(int i = 0; i < N_circles;++i) 
		{
			x[i] = random.nextInt(MAX_RAND_INT);
			y[i] = random.nextInt(MAX_RAND_INT);
			color[i] = rgbToColor(random.nextInt(256), random.nextInt(256) , random.nextInt(256), 255);
		}
	}
	
	// The setColor method of the Graphics class expects color to be specified as a single int.
	// This routine converts RGBalpha values into a single int that setColor can understand.
	// Specify the red, green, blue and alpha values as integers between 0 and 255.
	// Alpha is a transparency component - an alpha of 255 is fully opaque, 
	//   while an alpha of 0 is transparent.
	// The output of rgbToColor is an integer that is in the format expected by setColor,
	// which is specified by a hexidecimal value of the format 0xAARRGGBB
	static public int rgbToColor(int red, int green, int blue, int alpha) {
		int color = 0;
		color += blue;
		color += 256*green;
		color += 256*256*red;
		color += 256*256*256*alpha;
		return color;
	}
}
