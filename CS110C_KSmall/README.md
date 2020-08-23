KSmall was the first homework of CS 110C Data Structures & Algorithms: C++
The homework was to create enough of the quicksort algorithm to find the Kth smallest entry in an array. Resursive programming was explicitly required. Also the function had to have a specific name and take specific inputs, only one function was allowed.

The input required were:
	1. an int that was the index+1 we were looking for (k).
	2. a pointer to the integer array.
	3. an int that denoted the first index of the array.
	4. an int that denoted the last index of the array.

This was my first time writing recursively, so I decided it would be fun to try and not use any loops. To get around the lack of loops I made some functions that essientally iterated though the array until a condition was met. Of course the problem with using multiple functions was that we were only allowed one. I realized that the 3 integers were always going to be 0 or greater, due to them refering to array indexs, so I could flip them to negitive numbers (minding the fact that 0 * -1 is still 0) and have my function communicate with itself and know which sections of code to run. This got my 8 states to have my function talk with itself, though I only used 3.
