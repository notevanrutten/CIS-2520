Name:        Evan Rutten
ID:          1189483
Assignment:  #2

[Windows]
To compile both programs:  mingw32-make
To execute each program:   .\q1.exe
                           .\q2.exe 'argument'
[Linux]
To compile both programs:  make
To execute each program:   ./q1
                           ./q2 'argument'

Q1 sample output:
--------------------------------------------------------------------------
(1) add a new car to the available-for-rent list
(2) add a returned car to the available-for-rent list
(3) add a returned car to the repair list
(4) transfer a car from the repair list to the available-for-rent list
(5) rent the first available car
(6) print all the lists
(7) quit

Transaction code: 6

[Available for rent]
2Z45LY1, 55683, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
RZK7EKN, 85514, 0

[Rented]
RX0HWGS, 62152, 221028
UCWRNN0, 72892, 221104
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
TTFMN33, 80769, 0
VKZMDQC, 97069, 0

Transaction code: 1
Plate number: SWYAZ9S
Mileage: 52838

[SWYAZ9S, 52838, 0] was added to the available-for-rent list

Transaction code: 6

[Available for rent]
SWYAZ9S, 52838, 0
2Z45LY1, 55683, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
RZK7EKN, 85514, 0

[Rented]
RX0HWGS, 62152, 221028
UCWRNN0, 72892, 221104
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
TTFMN33, 80769, 0
VKZMDQC, 97069, 0

Transaction code: 2
Plate number: RX0HWGS
Mileage: 63923

Charge: $315.65

[RX0HWGS, 62152, 221028] was removed from the rented list
[RX0HWGS, 63923, 0] was added to the available-for-rent list

Transaction code: 6

[Available for rent]
SWYAZ9S, 52838, 0
2Z45LY1, 55683, 0
RX0HWGS, 63923, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
RZK7EKN, 85514, 0

[Rented]
UCWRNN0, 72892, 221104
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
TTFMN33, 80769, 0
VKZMDQC, 97069, 0

Transaction code: 3
Plate number: UCWRNN0
Mileage: 73931

Charge: $205.85

[UCWRNN0, 72892, 221104] was removed from the rented list
[UCWRNN0, 73931, 0] was added to the repair list

Transaction code: 6

[Available for rent]
SWYAZ9S, 52838, 0
2Z45LY1, 55683, 0
RX0HWGS, 63923, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
RZK7EKN, 85514, 0

[Rented]
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
UCWRNN0, 73931, 0
TTFMN33, 80769, 0
VKZMDQC, 97069, 0

Transaction code: 4
Plate number: TTFMN33

[TTFMN33, 80769, 0] was removed from the repair list
[TTFMN33, 80769, 0] was added to the available-for-rent list

Transaction code: 6

[Available for rent]
SWYAZ9S, 52838, 0
2Z45LY1, 55683, 0
RX0HWGS, 63923, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
TTFMN33, 80769, 0
RZK7EKN, 85514, 0

[Rented]
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
UCWRNN0, 73931, 0
VKZMDQC, 97069, 0

Transaction code: 5
Return date: 221230

[SWYAZ9S, 52838, 0] was removed from the available-for-rent list
[SWYAZ9S, 52838, 221230] was added to the rented list

Transaction code: 6

[Available for rent]
2Z45LY1, 55683, 0
RX0HWGS, 63923, 0
JYS53CV, 64961, 0
A7KPM5O, 67970, 0
MNJ91YI, 78895, 0
TTFMN33, 80769, 0
RZK7EKN, 85514, 0

[Rented]
3CD89YU, 91036, 221113
K4EK9MR, 94345, 221120
DZ5FFKE, 99115, 221205
SWYAZ9S, 52838, 221230

[In repair]
F5J2VCA, 60928, 0
3F2L8WO, 62710, 0
GV5YCKF, 72294, 0
UCWRNN0, 73931, 0
VKZMDQC, 97069, 0

Transaction code: 7

Total income: $521.50

[Press any key to quit]
--------------------------------------------------------------------------

Q2 sample output:
--------------------------------------------------------------------------
Input: 73-2*21+/
Output: 2.67

[Press any key to quit]
--------------------------------------------------------------------------

((7-3)*2)/(2+1) = 8/3 = 2.67