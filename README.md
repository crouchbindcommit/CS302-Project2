# CS302-Project2
This repository was created by Mak Mckinney under the guidance of Dr Scott Emrich to satisfy the requirements for Project 1 in CS302: Data Structures and Algorithims II at the University of Tennessee. This project is in progress and will be completed on or before 2/17/2023. 

This project is a CPP project to implement various sorts and to understand their time complexities. 


The following Benchmark was drafted in order to display the time complexities. 

--------------------------------------
| Mode    | Size     | Elapsed Time  |
|---------|----------|---------------|
| STL     | 10       | 0.003         | 
| STL     | 100      | 0.003         | 
| STL     | 1000     | 0.005         |
| STL     | 10000    | 0.026         |
| STL     | 100000   | 1.047         |
| STL     | 1000000  | 7.777         |
| STL     | 10000000 | 1.28.74       |
|---------|----------|---------------|
| QSORT   | 10       | 0.003         | 
| QSORT   | 100      | 0.003         | 
| QSORT   | 1000     | 0.005         |
| QSORT   | 10000    | 0.022         |
| QSORT   | 100000   | 0.901         |
| QSORT   | 1000000  | 8.963         |
| QSORT   | 10000000 | ....          |
|---------|----------|---------------|
| MERGE   | 10       | 0.003         | 
| MERGE   | 100      | 0.003         | 
| MERGE   | 1000     | 0.005         |
| MERGE   | 10000    | 0.025         |
| MERGE   | 100000   | 1.141         |
| MERGE   | 1000000  | ...           |
| MERGE   | 10000000 | ...           |
|---------|----------|---------------|
| QUICK   | 10       | 0.001         | 
| QUICK   | 100      | 0.002         | 
| QUICK   | 1000     | 0.004         |
| QUICK   | 10000    | 0.023         |
| QUICK   | 100000   | 1.116         |
| QUICK   | 1000000  | 11.189        |
| QUICK   | 10000000 | 1.56.08       |
--------------------------------------

For lists containing less than 1000 integers, there was no notable difference in speed. The STL::Sort was the most consistent, although merge was slightly faster. The Qsort and Merge were larger than the local directory, and the stack was not large enough to handle their sorts. For the majority, the real times were similar to their theoretical O(nlogn) times. 

I personally argue that the STD::Sort is the most efficient. The time difference between each sort is very miniscule, but STL::Sort is the easiest and quickest method to employ. 

I was greatly assisted by my colleages Maria Auxiliadora Hernadez and Alec Merkle on this project. I completed the code, but both helped to guide my logic so that I could finish. Officially, I did this project as an individual rather than as a group. 
