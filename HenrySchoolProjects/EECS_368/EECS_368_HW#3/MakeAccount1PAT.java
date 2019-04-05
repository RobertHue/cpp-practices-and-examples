// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: MakeAccount1PA.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This class inherits MakeAccount1PA
// class and adds account transfer
// functionality.
//

public class MakeAccount1PAT extends MakeAccount1PA {
	
	public MakeAccount1PAT(double value, String pass) {
		super(value, pass);
	}
	
	public void transfer(String pass, MakeAccount1PAT destAccount, String destPass) {
		// Transfer only if both passwords are correct
		if (this.correctPassword(pass) && destAccount.correctPassword(destPass)) {
			// Assign transfer amount from fromAcc balance
			double transfer = this.balance;
			// Withdraw transfer from fromAcc
			this.withdraw(pass, transfer);
			// Deposit transfer to toAcc
			destAccount.deposit(destPass, transfer);
		} else {
			System.out.println("Incorrect Password");
		}
	}

}
