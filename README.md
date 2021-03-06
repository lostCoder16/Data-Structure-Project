# Indentation Checker
## Data-Structure-Project
* This project is a implementation of a **Indentation checker** which check for valid indentation in a input file.
<!-- * This project is with the guidlines for the **Innovative Project work** for the **Subject - Data Structure** in **III semester** -->
<!-- * This project is shared by `Prabhpreet Singh - 2K19/CO/277` and  `Mohmmad Arshad - 2K19/CO/235` -->

## Usage
* Checks the indentation errors in the file
* Notifies the line number on which indentation errors are present 

## Demo
![](https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/Demo.gif)

## Algorithmic Implementation
* This implementation is based on counting the no of prefix spaces in a line
* We use file handling to open the file that we want to check and maintain a pointer to the current location in the file.
* We maintain a **required_spaces** variable which tells us that how much spaces should be present in the current line 
* Every time a we enter a function or if/while/for conditions (line closes with a **{**) we increment this variable by the intended amount and everytime we exit a function or while/if/for conditions (a line starts with a **}** bracket) we decrement this amount as same.
* Therefore, we count the prefix spaces in the current line and if **prefix_spaces are not equal to required_spaces** then we say this line has a error else we say this line is fine and print it accordinly
* At the end, the program notifies the user of a list of lines **that encountered the indentation error** while check.

## Different Use Case

### 1. Checking on a nested Indentation
<img src="https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/p2.png" alt="alt text" width="1000" height="500">

### 2. Testing on a file with custom indent space
`Note that this image has two different runs one without any custom indent space and other specifying a custom indent`

<img src="https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/p1.png" alt="alt text" width="1000" height="500">

## Testing the Project 
* Clone this repository using command `git clone https://github.com/prabh1601/Data-Structure-Project.git` or download this repository [using this link](https://github.com/prabh1601/Data-Structure-Project/archive/main.zip)
* Run command `gcc main.c -o 'your_preffered_name'` to make a executable with the 'your_preffered_name' (for eg : running command `gcc main.c -o project will` make a executable file with the name `project`
* Run command  `./'your_executable_name' 'file_to_be_checked' 'intended width of a space if required'` to run the indentation check on the file provided to the program
* `Note that the file you want to check should be in the same directory as of the executable file`
* For example if you want to check a **file name : test.txt** with the your **executable file name : project** and want to give the indentation checker a **predefined space width : 'x'**, then **run the command `./project text.txt x`** to get the output of the errors in your indentation.

## Complexity Analysis
### Time Complexity 
 * Since we iterate over each character without doing any work for a specific time heavy work and hence we say that our program runs in linear time 
 * Therefore the upper bound complexity of program is **O(n) where n stands for the no of characters in the file**
### Space Complexity 
 * We have two array (one integer type array storing errors and another as character type for printing the file)
 * Therefore again we limit the upper bound the space complexity of our program as **O(n) where n stands for the no of characters in the file**
