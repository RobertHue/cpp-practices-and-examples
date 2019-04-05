/* -----------------------------------------------------------------------------
 *
 * File Name:  MyCircleTest.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 8 Exercise 1 Part 2
 * Description:  This program will test the MyCircle class that is to be compiled along with this;
 * Date: 10-28-13
 *
 ---------------------------------------------------------------------------- */

public class MyCircleTest {
	public static void main(String[] args) {
		
                // Declare a new circle called myCircle
				MyCircle myCircle = new MyCircle();
                //Assign the radius a value of 5.5
				myCircle.radius = 5.5;
                //Display a message to the screen that says "My circle has a radius of <put the radius here>"
				System.out.println("My circle has a radius of " + myCircle.radius);
                //Declare two doubles, theArea and theCircum
				double theArea = 0.0;
				double theCircum = 0.0;
                //Use the method area() from myCircle to store the area in theArea                         
				theArea = myCircle.giveArea();
                //Use the method circumference() from myCircle to store the area in theCircum
				theCircum = myCircle.giveCircumference();
                //Display a message to the screen "The area is <put the area here>"
				System.out.println("The area is " + theArea);
                //Display a message to the screen "The circumference is <put the circumference here>"
				System.out.println("The circumference is " + theCircum);
                //Using only a method call to diameter(), write a message to the screen "The diameter is <put the diameter here>"
				System.out.println("The diameter is " + myCircle.giveDiameter());
	}

}
