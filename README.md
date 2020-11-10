# Indentation Checker
## Data-Structure-Project
* This project is a implementation of a **Indentation checker** which check for valid indentation in a input file.
* This project is with the guidlines for the **Innovative Project work** for the **Subject - Data Structure** in **III semester**
* This project is shared by `Prabhpreet Singh - 2K19/CO/277` and  `Mohmmad Arshad - 2K19/CO/235`

## Usage
* Checks the indentation errors in the file
* Notifies the line number on which indentation errors are present 

## Testing the Project 
* Clone this repository using command `git clone https://github.com/prabh1601/Data-Structure-Project.git` or download this repository [using this link](https://github.com/prabh1601/Data-Structure-Project/archive/main.zip)
* Run command `gcc main.c -o 'your_preffered_name'` to make a executable with the 'your_preffered_name' (for eg : running command `gcc main.c -o project will` make a executable file with the name `project`
* Run command  `./'your_executable_name' 'file_to_be_checked' 'intended width of a space if required'` to run the indentation check on the file provided to the program
* `Note that the file you want to check should be in the same directory as of the executable file`
* For example if you want to check a **file name : test.txt** with the your **executable file name : project** and want to give the indentation checker a **predefined space width : 'x'**, then **run the command `./project text.txt x`** to get the output of the errors in your indentation.

## Demo
![](https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/Demo.gif)

## Different Use Case

### 1. Checking on a nested Indentation
<img src="https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/p2.png" alt="alt text" width="1000" height="500">

### 2. Testing on a file with custom indent space
`Note that this image has two different runs one without any custom indent space and other specifying a custom indent`

<img src="https://github.com/prabh1601/Data-Structure-Project/blob/main/Shots/p1.png" alt="alt text" width="1000" height="500">

## Complexity Analysis
### Time Complexity 
 * Since we iterate over each character without doing any work for a specific time heavy work and hence we say that our program runs in linear time 
 * Therefore the upper bound complexity of program is **O(n) where n stands for the no of characters in the file**
### Space Complexity 
 * We have two array (one integer type array storing errors and another as character type for printing the file)
 * Therefore again we limit the upper bound the space complexity of our program as **O(n) where n stands for the no of characters in the file**
