HOMEWORK 6: BATTLESHIP CONTEST


NAME: Nicholas Jung



COLLABORATORS AND OTHER RESOURCES:
Stack overflow



DESCRIPTION OF ANY PERFORMANCE IMPROVEMENTS/OPTIMIZATIONS:
I optimized by ordering the ship list from max to minimum size,
then placed ships on the board starting from max ship to min ship.
Also, if I have duplicate ships of the same size, I check if the board follows
the path of a  previous board and return if it does.




DESCRIBE INTERESTING NEW PUZZLES YOU CREATED:
I created new puzzles which would make my code run slower, meaning multiple ships of same size
I also created smaller and larger boards, and tested corresponding constraints with it. Since my
unknown tests are still buggy, I left those out.


SUMMARY OF YOUR PERFORMANCE ON ALL PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles for a single solution or all solutions.

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
	test1: 1 solutions 0.00001... secs
	test2: 1 solution .0156 seconds
	test3: 7 solutions .03125 seconds
	test4(test3 with constraint): 1 solution .03 seconds
