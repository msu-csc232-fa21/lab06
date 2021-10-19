# LAB06 - Safe Memory Management Using Smart Pointers

## Background

Standard class templates provide us with smart pointers. To incorporate them, you need the following directive:

```c++
#include <memory>
```

In this lab, we cover two of the three types of smart-pointer templates available in C++, namely

* `unique_ptr`
* `shared_ptr`
* `weak_ptr` (not covered in this lab)

Specifically, you'll see examples of these two types of smart pointers. You'll "break" the code in intentional ways to help you catalog and remember the ways in which these pointers can (and cannot) be used.

See C++ Interlude 4: Safe Memory Using Smart Pointers (pp. 291-306) for additional reading on smart pointers. See also, [http://en.cppreference.com/w/cpp/memory](http://en.cppreference.com/w/cpp/memory)

### Unique Pointers

A `unique_ptr` does not share its pointer. It cannot be copied to another `unique_ptr`, passed by value to a function, or used in any Standard Template Library (STL) algorithm that requires copies to be made. A `unique_ptr` can only be moved. This means that the ownership of the memory resource is transferred to another `unique_ptr` and the original `unique_ptr` no longer owns it. It is recommended that you restrict an object to one owner, because multiple ownership adds complexity to the program logic. Therefore, when you need a smart pointer for a plain C++ object, use `unique_ptr`, and when you construct a `unique_ptr`, use the `make_unique` helper function.

### Shared Pointers

The `shared_ptr` type is a smart pointer in the C++ standard library that is designed for scenarios in which more than one owner might have to manage the lifetime of the object in memory. After you initialize a `shared_ptr` you can copy it, pass it by value in function arguments, and assign it to other `shared_ptr` instances. All the instances point to the same object, and share access to one "control block" that increments and decrements the reference count whenever a new `shared_ptr` is added, goes out of scope, or is reset. When the reference count reaches zero, the control block deletes the memory resource and itself.

## Tasks

As usual, accept the [GitHub Assignment Link](https://classroom.github.com/a/mpsxwVaL). Once your repo is created, clone it to your local machine and create a develop branch within which to do your work.

### Part 1: Working with Unique Pointers

In this part of the lab, we'll be working with `lab06a.cpp`. As such, let's make sure it compiles. Issue the following commands to compile and execute the files needed in this first part (bearing in mind that the '$' character is not typed; it's the command line prompt):

```bash
$ g++ -std=c++14 lab06a.cpp Song.cpp
$ ./a.exe
$
```

If all goes well, your session should appear as shown above. (I'm also assuming you're doing this from a Cygwin terminal window. If you're using a Linux-based operating system like Mac OS X, Ubuntu, etc., you'll execute `a.out` instead of `a.exe`.)

Now open `lab06a.cpp` in your favorite text editor to make a variety of changes. These changes may intentionally cause the program to not work correctly, or even not to compile. Regardless, after each of the following suggested changes (which are also marked with TODO: comments in the source), answer the questions found in `questions.txt` and commit your changes as instructed.

1. Add your name to the header comments. Save your changes and compile. If there are no compiler errors, commit your change with an appropriate commit message.
1. Locate, and follow, the next TODO (Part 1, Step 2) in `lab06a.cpp`. In `main()`, uncomment the call to `demoMoveUniquePtr();`. Recompile your program and note the output. You should see the name `Diana Krall` printed twice, each on a separate line.
1. Locate, and follow, the next TODO (Part 1, Step 3a and Step 3b). That is, change from "moving" ownership of the pointer to assigning the `ptrA` to `ptrB`. Recompile the program. Record the compiler error message in Question 1 in the `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 1, Step 3"
1. Undo the changes you made in the previous step. Recompile and run to make sure you've actually undid the changes. After having restored your program to working order, locate, and follow, the next TODO (Part 1, Step 4). Save your changes, recompile and execute your program. After executing your program, answer Question 2 in the `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 1, Step 4"
1. Go back to the `main()` function and comment out the call to `demoMoveUniquePtr()` and uncomment the call to `makeSongs()`. Study this method to see more examples one the use of `unique_ptr`. Recompile and execute the your program (which should only be calling `makeSongs()` at this point). Answer question 3 in `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 1, Step 5"
1. Go back to the `main()` function and locate, and follow, TODO (Part 1, Step 6a). Recompile and run your program (which should only be executing `songVector()` at this point. Next, locate, and follow TODO (Part 1, Step 6b). Save your changes and recompile your program. Record the compiler error message in Question 4 in the `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 1, Step 6".
1. Finally, study the next two examples in the source code (`demoUniqueOwnership()` and `demoUniqueArray()`) for still more uses of the `unique_ptr`.

### Part 2: Working with Shared Pointers

In this part of the lab, we'll be working with `lab06b.cpp`. As such, let's make sure it compiles. Issue the following commands to compile and execute the files needed in this first part (bearing in mind that the '$' character is not typed; it's the command line prompt):

```bash
$ g++ -std=c++14 lab06b.cpp Song.cpp
$ ./a.exe
$
```

If all goes well, your session should appear as shown above. (I'm also assuming you're doing this from a Cygwin terminal window. If you're using a Linux-based operating system like Mac OS X, Ubuntu, etc., you'll execute `a.out` instead of `a.exe`.)

Now open `lab06b.cpp` in your favorite text editor to make a variety of changes. These changes may intentionally cause the program to not work correctly, or even not to compile. Regardless, after each of the following suggested changes (which are also marked with TODO: comments in the source), answer the questions found in `questions.txt` and commit your changes as instructed.

1. Add your name to the header comments. Save your changes and compile. If there are no compiler errors, commit your change with an appropriate commit message.
2. Locate, and follow, the next TODO (Part 2, Step 2a) in `lab06b.cpp`. In `main()`, uncomment the call to `demoCreation();`. Recompile your program and note the output. You should see four lines of text printed out, with the last two being identical ("Elton John, I'm still Standing").
3. Locate, and follow, the next TODO (Part 2, Step 2b). Add the called for assignment statement, recompile and re-execute. Answer Question 1 in Part 2 of `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 2, Step 2".
4. Locate and follow TODO Part 2, Step 3a, that is, comment out the call to `demoCreation()` and uncomment the call to `demoShareSwap()`. Recompile and execute your program (which at this point, should only be executing the call to `demoShareSwap()`). You should see "Lady Gaga, Just Dance" printed three times, each on a separate line.
5. Locate and follow TODO Part 2, Step 3b. Recompile and execute your program. When done, answer Question 2 in Part 2 of `questions.txt`. Commit your changes to `questions.txt` (see the instructions in `questions.txt`, lines 8-10) with the commit message "CSC232-LAB06 - Completed Part 2, Step 3".
6. Locate and follow TODO Part 2, Step 3c. Recompile and execute your program to make sure it runs now without issue.
7. Go back to the `main()` function and comment out the call to `demoShareSwap()`. Following the TODO Part 2, Step 4, uncomment the call to `demoSharedPtrsWithSTL()`. Study the code in this function and speculate on what it is doing. NOTE: I don't expect you completely understand this code as it is using features of C++ that we haven't covered. Compile and execute your program and see if the output is as you expected.

When you have completed these steps, create a pull request for merging your develop branch into your trunk branch and add your instructor (Jim Daehn) as the sole reviewer for the pull request (if he isn't added already). The only file whose changes I'm interested in is the `questions.txt` file. Each question is worth 0.5 points.

## Due Date

This lab is due by the end of the lab period.
