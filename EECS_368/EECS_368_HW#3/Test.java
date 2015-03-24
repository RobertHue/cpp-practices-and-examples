// ==============================
// Name: Henry C. Nguyen
// Assignment: EECS 368 Program 3
// File: Test.java
// Professor: Frank Brown
// Date: 03-24-2015
// ==============================
// Program Summary:
// This test class performs all the required
// tests to receive a printed output in the
// format the homework assignment requires.
//


public class Test {

	public static void main(String[] args) {
		// Test for Part 1
		System.out.println("----------------PART1--------------------");
		MakeAccount acc = new MakeAccount(100);
		acc.view();
		acc.withdraw(50);
		acc.withdraw(60);
		acc.deposit(40);
		acc.withdraw(60);
		MakeAccount acc2 = new MakeAccount(00);
		acc2.deposit(17);
		
		// Test for Part 2
		System.out.println();
		System.out.println("----------------PART2--------------------");
		MakeAccount1 acc1 = new MakeAccount1(100);
		acc1.view();
		acc1.withdraw(40);
		acc1.deposit(55);
		acc1.show();
		
		// Test for Part 3
		System.out.println();
		System.out.println("----------------PART3--------------------");
		MakeAccount1P acc1p = new MakeAccount1P(100,"secret");
		acc1p.view("secret");
		acc1p.withdraw("secret",40);
		acc1p.deposit("rosebud",55);
		acc1p.show("secret");
		
		// Test for Part 4
		System.out.println();
		System.out.println("----------------PART4--------------------");
		MakeAccount1PA acc1pa = new MakeAccount1PA(100,"secret");
		acc1pa.withdraw("secret", 60);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		acc1pa.withdraw("rosebud", 55);
		
		// Test for Part 5
		System.out.println();
		System.out.println("----------------PART5--------------------");
		MakeAccount1PAT fromAcc = new MakeAccount1PAT(300, "secret");
		MakeAccount1PAT toAcc = new MakeAccount1PAT(200, "rosebud");
		fromAcc.transfer("secret", toAcc, "secret");
		fromAcc.show("secret");
		fromAcc.transfer("secret", toAcc, "rosebud");
		fromAcc.show("secret");
		toAcc.show("rosebud");
		
		// Test for Part 6
		System.out.println();
		System.out.println("----------------PART6--------------------");
		MakeAccount1PATS sav = new MakeAccount1PATS(100, "rosebud", 0.05);
		sav.interest("bananas");
		sav.interest("rosebud");
		sav.deposit("rosebud", 0);
	}

}
