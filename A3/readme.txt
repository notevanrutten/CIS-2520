Name:        Evan Rutten
ID:          1189483
Assignment:  #3

To compile the program:  make q1
To execute the program:  ./q1 'argument'

NOTE:  80% option was used (postorder input)

[Sample Input]
----------------------------------------
| ./q1 '2.00 x1 1.00 - * x2 3.00 / +'  |
----------------------------------------

[Sample Output]
----------------------------------------
| Input postorder:                     |
| 2.00 x1 1.00 - * x2 3.00 / +         |
|                                      |
| Output inorder:                      |
| ((2.00*(x1-1.00))+(x2/3.00))         |
|                                      |
| Press any key to quit:               |
| >                                    |
----------------------------------------