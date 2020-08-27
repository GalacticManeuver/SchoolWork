Text and Morse Code Translator was made as an Honors project for CS 110B Programming Fundamentals: C++
The object accepts a string as input, discerns if the input is text or morse code, and then translates the inputted message into the other format.

The project goal was to investigate different program structures for efficient use of memory and/or efficient use of time.
I selected a binary tree for translating morse code into text. The corresponding letter is found by progressing once on the tree for each dot and dash of morse code.
I selected a map for translating text into morse code. And used the character datatype and manually assigned 1s and 0s to represent dots and dash to minimize memory usage.
