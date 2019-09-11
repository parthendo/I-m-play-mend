# Course - DSA

This is my solutions to the most famous and acclaimed courses taught at IIIT-B by Prof. V N Muralidhara

## Nomenclature

1. The name of each file starts with the date the problem was taught in the lecture. Each of the day, date and month is separated by an underscore. The second parameter is the problem number. The third argument is the approach listed as app$. The approaches are enumerated in the increasing order of the efficiency in the solution.
2. For each of the file defined in the above point, the problem statement and the approach used with the analysis is stated in each file.
3. For each problem, test files are also provide. The files are in the folder test with the first two arguments same as that of the problems the files are provided for.

Please let me know if you find an error or a better approach.

## Questions:

_Date: 08/08/19_

1. Given an unsorted array with distinct integers and a rank R, find the element having that ranking by using the partition method. The pivot in the partition method should be calculated using the deterministic method by calculating the median of 5 elements. Compare and contrast by making a group of more than 5 elements (7,1000) and less than 5 elements. Compute and compare the running time on file sample1.txt. 

2. We are given an unsorted array of N elements, (1<=N<=1000000) and another array of elements. The size of second array is M, (1<=M<=10000). Find the rank of all the elements in second array, in the first array.

_Date: 10/08/19_

1. Implement a binary heap. It supports the following functionality.
* build_heap(): Converts a vector into a heap. O(n)
* insert():     Inserts an element into the heap. O(logn)
* delete():	Delete the topmost element. O(logn)
* search(X):	Search and element in the heap. O(n)
* s_delete(X):	Search the element X. If found, delete it. O(logn)

2. Implement a data structure which supports the two functionalities in minimum possible complexity:
* Add(x):	Add element _x_ to the collection O(logn)
* DeleteM():	Return the median of the collection and delete it. O(logn)

* Add(x):	Add element _x_ to the collection O(logn)
* DeleteG():	Delete all the numbers greater than the median. 

3. K-Sorted List Problem: Given K sorted lists in ascending order, find the _x_ th smallest number in the collection.

4. Count the number of inversion pairs in an array.

5. Given an array count the number of pairs such that for indeces _i_ and _j_, i<.j and Aj> Ai+10

6. Generalize the above problem for Aj>Ai+k. 

_Date: 17/08/19_

1. Check if an array has a majority element. A majority element is the one which repeats n/2+1 number of times.

2. Generalize the above problem for n/k+1 number of times.

3. Given an array, find maximum difference between any two elements. O(n)

4. Find 

5. 

_Date: 22/08/19_

1. Binomial Heap

_Date: 24/08/19_

1. Fibonacci Heap

_Date: 29/08/19_

1. AVL Tree with Zig-Zag and Zig-Zig implementation.

_Date: 31/08/19_

1. Implement Red Black Tree using the Zig-Zag and the Zig-Zig representation.

2. Define a dynamic data set such that it stores _N_ elements initially. It also supports a findRank(x) which tells the rank of element _x_ in this collection. This element may or maynot exist in the data set. O(logn)

3. In the above dynamic data set, take two elements _L_ and _R_ which may or may not exist in the data set. Now find the number of elements between the two of these. Try to achieve this in O(logn).

4. In the above dynamic data set, find the prefix sum of _x_ i.e. sum of all the numbers smaller than _x_. O(logn)

5. In the above dynamic data set, take two elements _x_ and _y_ which may or may not exist in the data set and find the sum of all the elements between _x_ and _y_ which exist in the data set.

6. Given an array Arr = {1,7,9,20,21,43,98}; not necessarily sorted, define two functions:
* minGap(): minimum difference between two elements. O(1)  
* maxGap(): maximum difference between two elements. O(logn)
* minGap(x,y): minimum difference between the elements in this range. X and Y may or may not exist in the collection. 
* minGap(x,y): maximum difference between the elements in this range. X and Y may or may not exist on the collection.

_Date: 10/09/19_

1. Given an array, you need to perform two operations:
* update(i,x): Update Arr{i} with x
* query{i}: Output the index of element with least index having value greater than the Arr{i}

e.g. Arr[] = {43, 33, 58, 12, 6 , 4, 8, 93, 41, 51, 63}
      Q[]  = { 2, 2 , 7 , 7 , 6 , 6, 7, 11, 9 , 10, 11}

2. Given an array, you need to perform two operations:
* update(i,x): Update Arr{i} with x
* rangeM(l,r): Output the minimum element in the range L,R

