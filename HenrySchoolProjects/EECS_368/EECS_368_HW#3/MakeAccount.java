// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class performs basic banking
// functions such as view, withdraw,
// and deposit.
//

public class MakeAccount {
	public double balance; 
	
	public MakeAccount(double value) {
		// Assign starting value of balance
		this.balance = value;
	}
	
	public void view() {
		// Display the current balance
		System.out.println("Balance:" + this.balance);
	}
	
	public void withdraw(double value) {
		
		if (this.balance < value) {
			// Display message that shows requested amount exceeds balance
			System.out.println("Insufficient Funds");
		} else {
			// Perform withdraw operation
			this.balance -= value;
			// Show current balance
			view();
		}
	}
	
	public void deposit(double value) {
		// Perform deposit operation
		this.balance += value;
		// Show current balance
		view();
	}
}
