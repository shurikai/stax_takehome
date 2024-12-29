## Take Home Assignment
The assignment, as provided:

>We would like for you to write a simple string manipulation application in C++ using the following requirements:
>Ingest a string of 10-15 characters into your application.
>* If the string length is divisible only by two, output the string backwards.  e.g. if the string is 'Test', you should output 'tseT'
>* If the string length is divisible only by three, add the string to linked list, then iterate over the list and double each character.  E.g. if the string is 'Test' you should output 'TTeesstt'
>* If the string length is by both two and three, assume the length of the string is its monetary value in dollars (e.g. if the string is 'Test', that would $4).  Calculate the total cost of the string with 3.2% tax added.  For instance, if the string were 1000 characters long, the output value would be 1032.  
>
>The application should accept the string as an input parameter, then on the next line output the result of the above conditional.
>The application should include any necessary comments, error handling (errors may just output to the console), and unit tests.

## Solution
I developed the program as requested, and committed it to this repository. Due to the timing of this work taking place over the holidays,
I did the best with what I was given. However, under normal circumstances, there were a few unclear requirements that I would have asked for
clarification on. The questions that came to mind are:
1. Given a string of length 12 (evenly divisible by both 2 and 3), should the application process the input string and provide the output as if it has a length of 2 and 3, as well as the price output?
    1. The solution as written will only output the taxed price if the length is 12.
    2. An error is printed if the length is neither divisible by 2 nor 3.
2. Should the application accept an input as a command-line argument, or after a prompt?
   1. The solution as given will accept either a command-line argument or will prompt for input if none is given.
   2. If the user gives no arguments or more than one, an error is printed.
## Prerequisites
1. C++ compiler with support for at least C++ 20
2. CMake installed and on the path
3. Make installed and on the path.

## Build and Run
First, clone this repository and cd into the root directory.

`cd ./stax_takehome`

Second, run the following commands to generate the Makefile and compile the program:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

To run the unit tests as they have been written, run the ll_test executable:  
```
$ ./ll_test
Running main() from /Users/jason/CLionProjects/stax_takehome/googletest/googletest/src/gtest_main.cc
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from LLTest
[ RUN      ] LLTest.ComputesLength
[       OK ] LLTest.ComputesLength (0 ms)
[ RUN      ] LLTest.HandlesStrings
[       OK ] LLTest.HandlesStrings (0 ms)
[ RUN      ] LLTest.HasIterator
[       OK ] LLTest.HasIterator (0 ms)
[ RUN      ] LLTest.CanUseIndexOperator
[       OK ] LLTest.CanUseIndexOperator (0 ms)
[----------] 4 tests from LLTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 4 tests.
```

To run the solution, execute it from the local directory:
```
$ ./stax_takehome
Enter a string between 10 and 15 characters in length: __ABCDEFGHIJ___
JIHGFEDCBA
```
