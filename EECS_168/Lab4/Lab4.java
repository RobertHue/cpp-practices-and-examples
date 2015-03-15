/* -----------------------------------------------------------------------------
 *
 * File Name:  Lab4.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 4
 * Description:  This program will draw and animate a smiley face that will switch to a frown face and back to the smiley face in a looping fashion
 * Date: 9-23-13
 *
 ---------------------------------------------------------------------------- */

package edu.ku.eecs168.lab4;

import android.graphics.Color;
import edu.ku.swingemu.AndroidJApplet;

public class Lab4 extends AndroidJApplet {
	//The value of counter has been initialized to help keep track of current frame
	public int counter=0;

	public void paint(Graphics canvas) {
		// TODO write your code here
		
        //this line clears the screen every time the screen is refreshed
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

        //The following lines draws the smiley face on screen when counter==0 is true
		if(counter==0){
			//Fill face background
			canvas.setColor(Color.YELLOW);
			canvas.fillOval(100, 50, 400, 400);
			//Draw face outline
			canvas.setColor(Color.BLACK);
			canvas.drawOval(100, 50, 400, 400);
			//Draw Eyes
            canvas.fillOval(245, 175, 20, 40);
            canvas.fillOval(320, 175, 20, 40);	
            //Draw Smile
            canvas.drawArc(223, 260, 150, 100, 180, 180);
                counter = 1;
		}else{ //If the counter is not 0 then don't draw anything

			counter=0; //Set up the next frame to draw frown face
			//Fill face background
			canvas.setColor(Color.YELLOW);
			canvas.fillOval(500, 50, 400, 400);
			//Draw face outline
			canvas.setColor(Color.BLACK);
			canvas.drawOval(500, 50, 400, 400);
			//Draw Eyes
            canvas.fillOval(645, 175, 20, 40);
            canvas.fillOval(720, 175, 20, 40);
            //Draw Frown
		    canvas.drawArc(623, 260, 150, 100, 180, -180);
		}
		
	}

}
