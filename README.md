# -> Relations <-

## About

Relations is an application developed for an assignment of a Discrete Mathematics class. It determines the definition and classification of a relation between sets.

## Technologies

* C Language
* CLion IDE

## Setup

### File Structure
The program will search for a file called ```set.txt```, that have to be with the executable code, or in the folder before. The file structure should be one of these that follows:

```
project
│   executable.exe
│   set.txt    
│
```
or

```
project
│   set.txt
│
└───folder
    │   executable.exe
    │   
```


### Formatting ```set.txt``` 

The file ```set.txt``` have to be written in a specific format so the program can function.  
Each line of this file should contain a definition of a `Set`.
   
```
A = {1, 87, 4, -1, 43}
```  
*A single capitalized letter, followed by an equal sign, open brackets, n elements separated by a comma, close brackets.*  
  
>Spaces are disconsidered.  

## Usage
When the program starts, it shows the Sets founded in the file ```set.txt```.  
```
------------------------------------------------
 SETS:
       A = {0, 1, 2, 3, 4}
       B = {2, 7, 3, 4}
       C = {9, 0, 10, 2, 3}

------------------------------------------------
```  

With these, you can choose one of the following `RELATIONS` and executing them accordingly to the operator assigned to it:

|    RELATIONS   |   OPERATOR  |
| :------------  | :---------: |
| Greather than  |      >      |
| Less than      |      <      |
| Equals         |      =      |
| Square of      |      *      |
| Square root of |      /      |


After given an `OPERATION STRING`, the program returns:
- The Relation
- The ordered pairs of the relation
- Domain
- Image
- If Functional
- If Injective
- If Total
- If Surjective
- If Epimorphism
- If Monomorphism
- If Isomorphism

### Example
Given Sets `A = {0, 1, 2, 3, 4}` and `B = {2, 7, 3, 4}`, then:
```
------------------------------------------------
OPERATION STRING: A > B
------------------------------------------------
R: A -> B
<3,2>,<4,2>,<4,3>
Domain: {3, 4}
Image: {2, 3}
Functional: false
Injective: false
Total: false
Surjective: false
------------------------------------------------
```
## More
For further information visit the [Wiki](https://github.com/LBeghini/Relations/wiki).
