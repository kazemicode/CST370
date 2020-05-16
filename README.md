# CST 370: Design and Analysis of Algorithms

## HW 1
Tasks: 

- [x] **Write a C++ program called hw1_1.cpp that reads an input file name from a user. Note that the input file contains several integer numbers. After reading the numbers from the file, your program should display the closest distance between two numbers among the numbers. For example, if the input numbers are -1, 10, 3, -15, 7, 20, 150, 200, 50, and 4, the answer should be 1 because the distance between 3 and 4 is 1. Note that the distance between two numbers is always positive.**

## HW 2

Tasks:

- [x] **Write a C++ program called sieve.cpp that implements the sieve of Eratosthenes algorithm in our textbook (page 6 ~ 7). Your program should use the dynamic memory for array(s).**

Test cases for the sieve.cpp:
```
Test case 1: Input number 2 -> 2
Test case 2: Input number 10 -> 2, 3, 5, 7
Test case 3: Input number 25 -> 2, 3, 5, 7, 11, 13, 17, 19, 23
Test case 4: Input number 101 -> 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
61, 67, 71, 73, 79, 83, 89, 97, 101
```

- [x] **Write a C++ program palindrome.cpp that reads a string of characters from user and determines if the string is a palindrome or not. For the program, you should store each character of the string in an array (use dynamic memory to create array(s)) and follow the algorithm described in the lecture. See attached file palindrome.cpp
Palindrome is a string that reads the same from both the beginning and the end.** 

Here are sample test cases:

```
(1) Input string 1: racecar
Output: Yes, it’s a palindrome

(2) Input string 2: abcdefghijihgfedcba 
Output: Yes, it’s a palindrome`

(3) Input string 3: CSUMB
Output: No, it’s not a palindrome
```

## HW 3
Tasks:

- [x] **Write a C++ program called power.cpp to compute 2n for a nonnegative integer n. In this program, you have to develop a recursive function to calculate it. And also, you can’t use a library in the program.
For the problem, you can assume that the user always enter a correct integer number which is greater than or equal to zero.**
1. Using two index variables, i and j, to keep track of our position in arrays A and B, we initialize both i
and j to 0.
2. While i is less than the length of A AND j is less than the length of B do the following:
3. If the elements A[i] and B[j] are equivalent, output element A[i] onto the terminal. Increment both
index variables i and j by 1 and go back to Step 2.
4. Otherwise, if A[i] and B[j] are NOT equivalent:
• If element A[i] is less than the element B[j], increment index variable i by 1 and go back to Step 2.
If the element B[j] is less than the element A[i], increment index variable j by 1 and go back to Step 2.
Page 4 of 6

Here are some sample test cases:

```
Test case 1 Enter a number: 0 Result: 1
Test case 2 Enter a number: 4 Result: 16
Test case 3
- We read your program and check if it uses a recursive function.
```

- [x] **Write a C++ program called all_subsets.cpp which displays all subsets of a set. In the problem, your program should read n characters from a user and display all subsets of the characters. In the program, you can assume that the number of input characters is less than or equal to 15. Your program should ask a user to enter the number of input characters. After that, it should read the characters. For the problem, you can assume that the input characters are always distinct.**

```
Test case 1
Number of input characters: 1 Enter 1 characters: a
===== All Subsets =====
empty
{a}
Test case 2
Number of input characters: 2 Enter 2 characters: s t
===== All Subsets =====
empty
{s}
{t}
{s,t}
Test case 3
Number of input characters: 3 Enter 3 characters: c b a
=====
All Subsets =====
empty
{a}
{b}
{c}
{a,b}
{b,c}
{a,c}
{a,b,c}
Page 5 of 6
Test case 4
Number of input characters: 4 Enter 4 characters: v x y z ===== All Subsets =====
empty
{v}
{x}
{y}
...
{v,x,y,z}
Test case 5
Number of input characters: 10
Enter 10 characters: a b c d e f g h i j ===== All Subsets =====
empty
{a}
{b}
{c}
...
{a,b,c,d,e,f,g,h,i,j}
```

## HW 4
Tasks:

- [x] **Write a program called select-sort-k.cpp that modifies the selection sort algorithm to sort the first k smallest elements of the array with n elements (k <= n, the value of k will be entered by the user). Your program should read the integer numbers from an input file, store them in an array (dynamic), and display the k smallest elements in sorted order. Your algorithm must run in O(n*k) time. When you write the program, don’t forget to include “Title”, “Abstract”, “ID (A four-digit number)”, “Name”, and “Date”.**

Sample input file (Note that the first line 10 indicates the number of integers in the file):
```
      10
       4
       6
       8
       15
       20
       22
       10
       3
       9
       2
```

Sample Run 1:
```
Enter a file name: ./t1.txt
Enter the value k: 4 Output: 2, 3, 4, 6
```

Sample Run 2:
```
Enter a file name: ./t1.txt
Enter the value k: 6 Output: 2, 3, 4, 6, 8, 9
```

- [x] **Write a C++ program called BFS.cpp that implements the Breadth-First Search (BFS) algorithm. Your program should read an input file name and a starting node from a user. After that, your program should display the list of vertices visited. In the problem, you can assume that the number of vertices in the input file is less than or equal to 25. When you write the program, don’t forget to include “Title”, “Abstract”, “ID (A four-digit number)”, “Name”, and “Date”.
[Hint: Since the maximum number of vertices is less than or equal to 25, you can use a simple array- based queue for the BFS algorithm. Or you can use a STL queue library. For more info, refer to http://www.cplusplus.com/reference/queue/queue/pop/**

Input file format: 

![Screenshot](/HW4/divide_and_conquer_largestN/Screen%20Shot%202020-05-15%20at%204.49.23%20PM.png)


The first line (= 3 in the example) indicates that there are three vertices in the graph. For the homework, we can assume that the first vertex starts from the number 0. Thus, t1.txt describes a graph like below:

![Screenshot](/HW4/divide_and_conquer_largestN/Screen%20Shot%202020-05-15%20at%204.49.26%20PM.png)


One blank space is used to delimiter the data. Note that there’s no blank space at the end of each line. If
your program does not read the file properly, your program will get no credit.

This is a sample run:
```
Enter filename: ./t1.txt 
Enter a start vertex: 0 
BFS order: 0 -> 1 -> 2
```

In the program, your program has to follow our convention (= ascending order). This is another sample input file called t2.txt.

![Screenshot](/HW4/divide_and_conquer_largestN/Screen%20Shot%202020-05-15%20at%204.49.31%20PM.png)

This is a sample run:
```
Enter filename: ./t2.txt
Enter a start vertex: 0
BFS order: 0 -> 2 -> 1 -> 3 -> 4
```

- [x] **Write a C++ program called assignment.cpp that solves the Assignment Problem in Chap 3.4. Your program should read the assignment costs of each person from a user and determine the best assignment. In the program, you can assume that the number of all jobs is less than 15. To get the full credits, your program should display all combinations of assignments. However, the sequence of combinations to be displayed on the screen is not important.**

This is a sample run:
```
Enter number of jobs: 2
Enter assignment costs of 2 persons: Person 1: 2 5
Person 2: 4 6
Output:
Permutation 1: <1, 2> => total cost: 8 Permutation 2: <2, 1> => total cost: 9
Solution: <1, 2> => total cost: 8
```

This is another sample run
```
Enter number of jobs: 3
Enter assignment costs of 3 persons: Person 1: 2 5 3
Person 2: 4 6 9
Person 3: 7 2 4
Permutation 1: <1, 2, 3> => total cost: 12 Permutation 2: <1, 3, 2> => total cost: 13 Permutation 3: <2, 1, 3> => total cost: 13 Permutation 4: <2, 3, 1> => total cost: 21 Permutation 5: <3, 1, 2> => total cost: 9 Permutation 6: <3, 2, 1> => total cost: 16
Solution: <3, 1, 2> => total cost: 9
```

## HW 5
Tasks:

- [x] **Write a C++ program called [ts.cpp](https://github.com/kazemicode/CST370/blob/master/HW5/topological-sorting/ts.cpp) that implements the topological sorting algorithm based on the source-removal algorithm. Your program should read an input file name. Then it should display the topological ordering. In the problem, you can assume that the number of vertices in the input file is less than 50. Additionally, you can assume that the input graph is always a DAG (= Directed Acyclic Graph).**

Input file format: 

![Screenshot](/HW5/topological-sorting/Screen%20Shot%202020-05-15%20at%205.14.37%20PM.png)

The first line (= 3 in the example) indicates that there are three vertices in the graph. For the homework, we can assume that the first vertex starts from the number 0. Thus, t1.txt describes a directed graph like below:

![Screenshot](/HW5/topological-sorting/Screen%20Shot%202020-05-15%20at%205.14.41%20PM.png)

One blank space is used to delimiter the data. Note that there’s no blank space at the end of each line. If your program does not read the file properly, your program will get no credit.

The following presents a sample run of the program. Your program should be compiled and executed exactly like this.

```
Enter filename: C:\\tmp\\t1.txt 
Topological sort: 0 -> 1 -> 2
```

In the program, your program has to follow our convention (= ascending order). This is another sample input file called t2.txt.


![Screenshot](/HW5/topological-sorting/Screen%20Shot%202020-05-15%20at%205.14.46%20PM.png)

This is a sample run:

```
Enter filename: C:\\tmp\\t2.txt 
Topological sort: 0 -> 1 -> 2 -> 3 -> 4
```

Again, your program must follow our convention (= ascending order). So, your program should remove the vertex 0 first between the two source vertices 0 and 1.

## HW 6
Tasks:

- [x] **Write a C++ program called heap.cpp to conduct heap operations. When the program starts, it should read a set of numbers from a user and store them in an array (starting from index 1) in the order the numbers are entered. After that, your program should display if the array representation is a heap or not. If it’s not a heap, your program should construct a heap (heapify) using the bottom-up algorithm. In addition, your program should support 3 operations that a user can select, as shown below.**

This is a sample run:
```
Input size: 5
Enter numbers: 20 7 8 1 3 This is a heap.
Select an operation
1: Insert a number 2. Delete the max 3. Heapsort & Quit
1
Enter a number: 5 Updated heap: 20 7 8 1
Select an operation 1: Insert a number 2. Delete the max 3. Heapsort & Quit
2
3 5
Updated heap: 8 7 5 1 3
Select an operation 
1. Insert a number 
2. Delete the max 
3. Heapsort & Quit
2
      Updated heap: 7 3 5 1
Select an operation 1: Insert a number 2. Delete the max 3. Heapsort & Quit
3
      Heapsort: 7 5 3 1
      Bye!
```

This is another sample run.
```
Input size: 3
Enter numbers: 1 3 7 This is NOT a heap. Heap constructed: 7 3 1 Select an operation
1: Insert a number 2. Delete the max 3. Heapsort & Quit
1
Enter a number: 100 Updated heap: 100 7 1 3
Select an operation 
1. Insert a number 
2. Delete the max 
3. Heapsort & Quit
3
      Heapsort: 100 7 3 1
      Bye!
      
```

- [x] **Write a C++ program called prim.cpp that implements the Prim’s algorithm to calculate the minimum spanning tree (MST) from an input graph. Your program should ask a user for an input file name that includes the input graph information. Then, your program should present the edges to be added one-by-one to construct the MST. In the problem, you can assume that the maximum number of vertices (= nodes) in the input graph is less than or equal to 20. You can also assume that the input graph is always connected.**

Input file format: 

![Screenshot](/HW6/untitled/Screen%20Shot%202020-05-15%20at%205.06.04%20PM.png)

The first line (= 4 in the example) indicates that there are four vertices (=nodes) in the graph. The second line (= 5 in the example) presents the number of edges in the graph. The remaining five lines present the edge information (= starting vertex, ending vertex, cost) in the graph. For the homework, you should assume that the first vertex starts from the number 1. Thus, t1.txt describes a graph like below:

![Screenshot](/HW6/untitled/Screen%20Shot%202020-05-15%20at%205.06.23%20PM.png)


 For the homework, you have to assume that a blank space is used to delimiter the values in the edge information. However, there’s no space at the end of each line. If your program does not read the file properly, your program will get no credit. And also, do not assume that the starting vertex is always 1. Your program has to ask the user for the starting vertex.
Page 7 of 8

This is a sample run

```
Enter a file name: ./t1.txt
Enter the first vertex to start: 1
(1) New edge: 1,2 – cost 2 
(2) New edge: 2,4 – cost 3 
(3) New edge: 3,4 – cost 1
```

At the result, the sequence of vertices in an edge is not important. For example, the following is fine:

```
(1) New edge: 1,2 – cost 2
```

OR

```
(1) New edge: 2,1 – cost 2
```
