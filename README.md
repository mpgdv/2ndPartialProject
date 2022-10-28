# 2ndPartialProject
---

## LIBRARY MANAGEMENT SYSTEM

### Description
---
`Link to video:` https://drive.google.com/file/d/1VSl-Zyss_vPTRNJDClK-5ZHhN3l4oeew/view?usp=sharing

A system to record the existing books within a library. Said books will be of one of three types: novel, comic or textbook. It also manage the book loans.

There is a class Book, which inherites to Novel, Comic and Textbook. 
The main attributes are: 
  <ul>
  <li>Title</li>
  <li>Author</li>
  <li>Publication Year</li>
  <li>Loan State: this will determine wheter a book has been lent or not</li>
  <li>Loan registration: a file that includes a book's information and all loans with their duration</li>
  </ul>
The books will be stored in a map, in which the key will be the book's title on lower case for better access.

Threads are used to keep track of the time a certain book is lent. Every time a book is borrowed, a thread is created, in which a countdown, according to the days borrowed, starts. Every ten seconds correspond to a day, and during the time that thread exists, said book will have it's loan state on true, which means it has been lent, and therefore will not be available for loan.   

### When using the program
---
First, the login menu will appear with two options of login: student and librarian.

The librarian will be able to do the following:
  <ol>
  <li>View Booklist: shows all the inventory of books</li>
  <li>Search for a Book's Registration: shows the file with the book's information and loan registration</li>
  <li>Add Book: add a novel, textbook or comic</li>
  <li>Delete Book: the book and it's file will be deleted</li>
  <li>Go to main manu: to the login menu</li>
  <li>Close Program: in addition to terminating the program, all files will be deleted</li>
  </ol>
The student:
  <ol>
  <li>View Booklist</li>
  <li>Books available for loan</li>
  <li>Borrow a Book: when a book is borrowed, the thread is created</li>
  <li>Go to main manu: to the login menu</li>
  <li>Close Program: in addition to terminating the program, all files will be deleted</li>
  </ol>
  
  ### For compiling
`g++ 1.cpp -pthread -o main`



    
