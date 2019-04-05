// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount1.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class inherits the MakeAccount
// class and adds the ledger history
// functionality.
//

import java.util.ArrayList;

public class MakeAccount1 extends MakeAccount {
	private ArrayList<String> history = null;
	
	public MakeAccount1(double value) {
		// Call super constructor
		super(value);
		// Create data structure to keep history of operations
		history = new ArrayList<String>();
		// Add starting balance to history
		history.add("(start = " + this.balance + " ) ");
	}
	
	public void withdraw(double value) {
		// Call super implementation of withdraw
		super.withdraw(value);
		// Add operation to history
		history.add("(- " + value + " = " + " " + this.balance + " ) ");
	}
	
	public void deposit(double value) {
		// Call super implementation of deposit
		super.deposit(value);
		// Add operation to history
		history.add("(+ " + value + " = " + " " + this.balance + " ) ");
	}
	
	public void show() {
		// Print beginning of ledger
		System.out.print("Ledger:'(");
		
		// Print all ledger operations
		for(int i = 0; i < history.size(); ++i) {
			String element = null;
			element = history.get(i);
			System.out.print(element);
		}
		
		// Print ending of ledger
		System.out.print(")\n");
	}

}
