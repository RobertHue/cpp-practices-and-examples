#EECS 268: Fall 2016
##Laboratory 1

Due: This lab is due before your next lab begins.

In this lab, you will 
(i) read a file that contains voter registration information, 
(ii) store the data in a dynamically allocated array, and 
(iii) process interactive queries on this data.

###Specifics

You should define two classes for this project: 
class Executive and class VoterRegistrationRecord. 
All instance variables in all classes must be private. 

The constructor for the Executive class will take a file name (from argv[1]), open the file, and read all records into a dynamically allocated array. 

Implement a run method in class Executive that prompts for and reads from the console directives to be applied to this stored data. The main program need only be something like:

int main(int argc, char* argv[])
{
    Executive exec(argv[1]);
    exec.run();
    return 0;
}

When the Executive constructor is called, it will open the file, read the number of records, dynamically allocate an array of VoterRegistrationRecord of the correct size, and coordinate the reading of the data into the array. (The array itself must be an instance variable of class Executive since it will also be accessed by the run method.)

When the run method is called, it will loop, prompting the user for one of the following requests:

    Print all VoterRegistrationRecord instances for people with a given last name. (Prompt for the name after the user indicates they want to use this query.)
    Print all VoterRegistrationRecord instances for people whose ages are between two given ages. (Prompt for the ages after the user indicates they want to use this query.)
    Print all VoterRegistrationRecord instances for people with a given party affiliation. (Prompt for the affiliation after the user indicates they want to use this query.)
    Report the number of people with a given party affiliation. (Prompt for the affiliation after the user indicates they want to use this query.)
    Quit the program

The input file will be structured as:
first-name last-name age affiliation

The "affiliation" will be one of: Democrat, Green, Independent, Libertarian, Republican, Unspecified.

For example:

4
Chris Jones 19 Republican
Pat Smith 23 Green
Kyle Howard 31 Democrat
Samantha Pratter 27 Democrat

A larger "real" input file is here.

A sample interactive session (input typed at console shown in red) might look something like:

1: Query last name
2: Query age range
3: Query affiliations
4: Report number of people with affiliation
5: Quit
1
Enter last name: Jones
Record: Chris Jones; age 19; Registered as Republican
1: Query last name
2: Query age range
3: Query registered voters
4: Report number of people with affiliation
5: Quit
5

Thanks for checking voter registrations!
Bye.

Grading Criteria

Grades will be assigned according to the following criteria:

    Appropriate class implementations (Executive and VoterRegistrationRecord): 35%
    Correct results from directives (including error detection and recovery): 35%
    Programming Style (header and body comments): 15%
    Modularity: 15%

##Submission

Once you have created the tarball with your submission files, email it to your TA. The email subject line must look like "[EECS 268] SubmissionName" as follows:
[EECS 268] Lab 01

Note that the subject should be exactly like the line above. Do not leave out any of the spaces, or the bracket characters ("[" and "]"). In the body of your email, include your name and student ID. 
