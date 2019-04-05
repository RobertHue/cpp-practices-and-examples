// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount1PA.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class inherits MakeAccount1PAT
// class and adds savings account
// interest functionality.
//

public class MakeAccount1PATS extends MakeAccount1PAT {
	private double interestRate = 0.0;
	
	public MakeAccount1PATS(double value, String pass, double rate) {
		super(value, pass);
		interestRate = rate;
	}
	
	public void interest(String pass) {
		if (!correctPassword(pass)) {
			System.out.println("Incorrect Password");
		} else {
			// Calculate amount of interest earned with current rate
			double interest = this.balance * interestRate;
			// Deposit interest to current balance
			this.deposit(pass, interest);
		}
	}
	
}
