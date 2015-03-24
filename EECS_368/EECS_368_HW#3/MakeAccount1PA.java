// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount1PA.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class inherits MakeAccount1P
// class and adds attempt monitoring
// functionality.
//

public class MakeAccount1PA extends MakeAccount1P {
	private int attempts = 0;
	
	public MakeAccount1PA(double value, String pass) {
		super(value, pass);
		attempts = 0;
	}
	
	public void view(String pass) {
		if (checkAttempt(pass)) {
			super.view(pass);
		}
	}
	
	public void withdraw(String pass, double value) {
		if (checkAttempt(pass)) {
			super.withdraw(pass, value);
		}
	}
	
	public void deposit(String pass, double value) {
		if (checkAttempt(pass)) {
			super.deposit(pass, value);
		}
	}
	
	public void show(String pass) {
		if(checkAttempt(pass)) {
			super.show(pass);
		}
	}
	
	private boolean checkAttempt(String pass) {
		if (!correctPassword(pass)) {
			++attempts;
			
			// Call the cops if incorrect attempts exceed 7 times
			if (attempts > 7) {
				System.out.println("Cops called");
			} else {
				System.out.println("Incorrect password");
			}
			return false;
		}
		// Reset incorrect attempts if correct password
		attempts = 0;
		return true;
	}
}
