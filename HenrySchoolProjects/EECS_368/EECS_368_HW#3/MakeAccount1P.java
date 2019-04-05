// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount1P.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class inherits the MakeAccount1
// class and adds password functionality.
//

public class MakeAccount1P extends MakeAccount1 {
	private String password = null;
	
	public MakeAccount1P(double value, String pass) {
		// Initialize starting balance with given value
		super(value);
		// Assign password to given string
		password = pass;
	}
	
	// Function checks if password is correct
	public boolean correctPassword(String pass) {
		if (pass != password) {
			return false;
		}
		return true;
	}
	
	public void view(String pass) {
		if (!correctPassword(pass)) {
			System.out.println("Incorrect Password");
		} else {
			super.view();
		}
	}
	
	public void withdraw(String pass, double value) {
		if (!correctPassword(pass)) {
			System.out.println("Incorrect Password");
		} else {
			super.withdraw(value);
		}
	}
	
	public void deposit(String pass, double value) {
		if (!correctPassword(pass)) {
			System.out.println("Incorrect Password");
		} else {
			super.deposit(value);
		}
	}
	
	public void show(String pass) {
		if (!correctPassword(pass)) {
			System.out.println("Incorrect Password");
		} else {
			super.show();
		}
	}
}
