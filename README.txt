HOMEWORK 6: BATTLESHIP RECURSION


NAME:  Nicholas Jung



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Justin

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  30



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of ships (s)? 
The total number of occupied cells (o) or open water (w)? 
The number of constraints (c)? 
The number of unknown sums (u) or unspecified ship types (t)? 
Etc. 

	My algorithm is based on the ships given for the board. I start with the largest ship and place it on the board, and 
	keep placing the largest ship until there are no ships left. 
	I believe the order notation is O((s*(w*h))*c) 
	I did not do the unknown sums/unspecified ship types correctly, hence I left it out of the order notation.
	Since I have a double for loop to check the validity of placing the largest ship on the table, I have the width times
	the height. Then, the ship will be tested on each square of the board hence s*(w*h), and that s value depends on the number
	of ships contained to loop through the double for loop. Finally, I check through the table (the correct table) to see if the 
	constraint is correct in the table.

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles for a single solution or all solutions.

	Almost all of the puzzles take less than a second to run. However, finding all solutions
	to puzzle 9 and 10 were much more difficult and did not complete running. 
	Puzzle sample: 2 solutions, .000001... seconds
	p1: 1 solution, .0001.. seconds
	p2: 1 solution, .0001... seconds
	p3: 1 solution, .0001... seconds
	p4: 1 solution, .0001... seconds
	p5: 2 solutions, .001... seconds
	p6: 24 solutions, .1718 seconds
	p7: 14 solutions, .046 seconds
	p8: 2 solutions, .54 seconds
	p9: didnt run
	p10: didnt run


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


