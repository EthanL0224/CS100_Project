[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9905209&assignment_repo_type=AssignmentRepo)

# Task Scheduler
 
 > Authors: [Abel Challa](https://github.com/abelchalla), [Ethan Lingad](https://github.com/EthanL0224), [Anjali Daryani](https://github.com/adary001), [Siyu Li](https://github.com/slialex)

> ### Project Description
> * Description: In this application, a user can create tasks including a title, description, priority, duration and due date. Some of these
features can also be optional. Users can also create task lists where each list includes
multiple tasks. Task lists can represent larger tasks that have subtasks within them.
Users can display, edit, and delete tasks and task lists. Users should also be able to
undo these operations. 


> ### Important or interesting to us
> * As a college student there are many assignments and projects every week. To complete these assignments efficiently and on time, we need to have a proper planning for these projects. Therefore, a task scheduler is necessary for us. This application can help us to schedule our time properly. This way, we can avoid missing or not being able to finish our assignments due to lack of time and unorganization. It also helps us to prioritize our assignments according to their complexity and deadline, so that we don't have too many assignments to start with.

> ### Tools and Languages
> * C++ - Programming Language Used
> * Github - Tool used for host of remote repository
> * CMake - Tool used to compile and run code
> * Googletest - Tool for writing and running unit tests
> * Make - Tool to build executables 
> * Draw.io - Tool used to make UML diagrams
> * Valgrind - Tool used for memory access error and leak detections

> ### Inputs:
>Creating a new task: The task's title, description, priority, duration, and due date would all be values that the user would supply. Some of these parameters might not be required.
>Creating a new task list: The task list would be given a title, description, priority, duration, and due date by the user.
>Adding a task to a task list: The task and task list would be specified by the user.
>Removing a task from a task list: The task and task list to be removed from would be specified by the user.
>Editing a task: The job to update and the new values for its characteristics would be specified by the user.
>Deleting a task: The job to remove would be specified by the user.
>Displaying a task list: The task list to display would be chosen by the user.
>Undoing an operation: The action to undo would be specified by the user.

> ### Outputs:
>The task lists and their tasks would be displayed as the application's outputs. The application might, for instance, output the name of the task list together with the title, description, priority, duration, and due date of each item in the list when showing a task list. In addition, the program would provide any necessary confirmations or error messages, such as "Task successfully added to task list."

> ### Features
> * The user of the program will be able to enter subtasks integrated inside of the task. As an example, if the user creates a task that's called "Clean Kitchen", then the user can also create subtasks within that task such as "Wash Dishes", "Take Out Trash", "Clean Out Refrigerator", or "Wipe Counters". Users will be prompted to enter the name of the task, a description of the task, the status of the task, and the deadline for the task. Users can prioritize tasks by ranking them in order of importance. Depending on each task's priority, the program would output the tasks in a particular format. The user can evaluate whether task is more significant than the other by viewing it in a specific manner. Users can be able to edit and delete tasks. The user has the flexibility to alter the name, description, due date, and status whenever they want. A user has the option to delete a task if they decide they no longer want it to be visible. Users have the option to undo their activity if they accidentally edit tasks in the wrong way. The user won't have to delete and start a brand-new task as a result.

## Class Diagram
 ![](images/UML_CS100P.png)
 > There are five classes in our class diagram. The subtask and Task classes will inherit the traits from the Basic class. A name, description, and status are frequent characteristics shared by subtasks and tasks. As a class job is more significant than a subtask, it has the priority and deadline that a subtask does not. There is a compositional link between the Task class and the vector that stores its many subtasks. In case the user wants to combine tasks together and have subtasks inside them, the class Project is another one that will contain a vector that keeps several tasks in one location. If the user wants to create several projects, it helps arrange the number of them. The single responsibility concept, another SOLID element, was added to our project. The user interface is solely the responsibility of our main file, which will also output all content to the terminal. However, while our ProjectManager class is designed to manage several projects, it also functions as a single responsibility job. Liskov's Substitution Principle is another SOLID concept that we have included into our software. Any child class, such as our Task class, will inherit the same qualities and characteristics from our Subtask class, which acts as a base class. The Liskov Substitution Principle (LSP) is the idea that objects from a superclass should be able to be substituted with objects from its subclasses without the application being broken. In other words, our goal is to have our subclass objects behave identically to our superclass objects, which is what our subtask and task are doing.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 > <img width="567" alt="Screen Shot 2023-03-15 at 3 38 28 PM" src="https://user-images.githubusercontent.com/79858435/225485210-6efe534b-c0fb-411b-a56f-cf262da36173.png">
 > <img width="593" alt="Screen Shot 2023-03-15 at 3 47 52 PM" src="https://user-images.githubusercontent.com/79858435/225485249-bfc80255-e376-4f4a-a045-a7926857dd2a.png">
 > <img width="487" alt="Screen Shot 2023-03-15 at 3 50 06 PM" src="https://user-images.githubusercontent.com/79858435/225485263-a3d96251-4d33-48f5-b303-64afc4db39d2.png">
 > * A
 > 
 > When the user picks A, the user is prompted to enter values for the Project name and description. Then the Project Menu appears for further options.
 > * O
 > 
 > When the user selects O, the program retrieves all the existing projects from the project inventory and displays them to the user. The specific implementation of how the projects are displayed will depend on the design of the program, but one possible way to do it is to print out a list of all the projects with their names and descriptions,  After displaying the list of projects, the program could return the user to the Project Menu to allow them to choose another option.
> * D
> 
> When the user selects this option, the program prompts the user to enter the name of the project they want to delete. The program then searches the project inventory for a project with that name and, if it is found, deletes it from the inventory. The program then returns them to the Project Menu.
> * S
>
> When the user selects this option, the program retrieves the number of projects in the inventory and displays it to the user. The program then returns the user to the Project Menu.
> * E
>
>When the user selects this option, the program prompts the user to enter the name of the project they want to edit or inspect. The program then searches the project inventory for a project with that name and, if it is found, displays the project information to the user. The program then presents the Project Edit Menu, which allows the user to edit or delete the project, add tasks to the project, go back to the main Project Menu and more.
>
><img width="633" alt="Screen Shot 2023-03-17 at 5 21 02 AM" src="https://user-images.githubusercontent.com/79858435/225903470-d303608e-c0ac-4325-8f6e-d86941edf526.png">
> <img width="549" alt="Screen Shot 2023-03-17 at 5 25 39 AM" src="https://user-images.githubusercontent.com/79858435/225904221-a958bf21-ec6c-4679-a0a3-42e5da717cdf.png">
> <img width="664" alt="Screen Shot 2023-03-17 at 5 26 13 AM" src="https://user-images.githubusercontent.com/79858435/225904288-bce918dc-d740-4c3a-9a86-d8435b344dcc.png">
> <img width="463" alt="Screen Shot 2023-03-17 at 6 00 12 AM" src="https://user-images.githubusercontent.com/79858435/225911822-f00d2f22-9181-4292-a393-af4650493252.png">
> 
> * A 
> 
> When the user selects A, the user is prompted to enter the details of the task, such as its name, description, deadline, priority, etc. After the task is added to the current project. Then, the user is presented with the Project Menu again for further options.

> * P
> 
> When the user selects P, the user is prompted to edit the name or description of the current project. After the user enters the updated details, the project is updated and the user is presented with the Project Menu again for further options.

> * E
> 
> When the user selects E, the application undoes any changes made to the project name or description since the last time the project was saved. Then, the user is presented with the Project Menu again for further options.

> * B 
> 
> When the user selects B, the application takes the user back to the main Project Menu.

> * O 
> 
> When the user selects O, the application outputs all the tasks in the current project. The user is prompted to select the format in which they want to view the tasks, such as a Priority or Deadline.

> * D 
> 
> When the user selects D, the application prompts the user to select the task they want to delete. After the user selects the task, the application deletes the selected task from the current project. 

> * T 
> 
> When the user selects T, the application prompts the user to select the task they want to edit or inspect. After the user selects the task, the user is presented with the Task Menu, which allows them to perform actions on the selected task, such as editing its details, making a subtask, marking it as complete, etc.

> * S 
> 
> When the user selects S, the application outputs the number of tasks in the current project that have been marked as complete.
> <img width="1113" alt="Screen Shot 2023-03-17 at 7 18 19 AM" src="https://user-images.githubusercontent.com/79858435/225931556-ef0c8908-4159-4141-8952-8972df58a574.png">
> <img width="819" alt="Screen Shot 2023-03-17 at 7 19 35 AM" src="https://user-images.githubusercontent.com/79858435/225931631-48319821-9db1-48b3-a26e-d5094c2ab5e1.png">
> <img width="381" alt="Screen Shot 2023-03-17 at 7 22 33 AM" src="https://user-images.githubusercontent.com/79858435/225933098-1a1e8d38-b60c-4b44-a162-17c9fa7acc49.png">
> 
> <img width="543" alt="Screen Shot 2023-03-17 at 7 23 06 AM" src="https://user-images.githubusercontent.com/79858435/225933707-2ef03b49-ab9e-4464-a676-013f4284683f.png">
> <img width="461" alt="Screen Shot 2023-03-17 at 7 23 31 AM" src="https://user-images.githubusercontent.com/79858435/225933751-9c0342c3-6ef1-4f88-8a14-e5719670e6c4.png">
> <img width="550" alt="Screen Shot 2023-03-17 at 7 23 46 AM" src="https://user-images.githubusercontent.com/79858435/225933841-d1ad995b-a498-49fb-9ed9-84bdbfed88f0.png">

> * B
>
> When the user picks B, the application or task menu will take them back to the previous page.

> * A
>
> When the user picks A, the user will be prompted to enter the details of a new subtask, such as its name and description. Once completed, the Task and Subtask Menu will appear with further options.

> * E
>
> When the user picks E, the user will be prompted to enter updated details for the current task, such as its name, description, deadline, priority and status. Once completed, the Project Menu will appear with further options.

> * S
>
> When the user picks S, the user will be prompted to select the subtask they want to edit and then enter the updated details for that subtask. Once completed, the Project Menu will appear with further options.

> * U
>
> When the user picks U, the application will prompt the user to confirm whether they want to undo any changes made to the current task.

> * C
>
> When the user picks C, the user will be prompted to select the subtask they want to undo changes for and then confirm whether the undo was successful.

> * D
>
> When the user picks D, the user will be prompted to select the subtask they want to delete and then confirm whether they want to delete it or not.

> * P
>
> When the user picks P, the application will display the priority of the current task. And Subtask Menu will appear with further options.

> * Z
>
> When the user picks Z, the application will display the deadline of the current task. And Subtask Menu will appear with further options.

> * O
>
> When the user picks O, an output of a list of all subtasks will be presented to the user. And Subtask Menu will appear with further options.


 ## Installation/Usage
 > Instructions on installing and running your application
 > 1. Recursively clone this repository onto your local machine with git clone --recursive <https://github.com/cs100/final-project-vowels>
 > 2. Change directory into the local repository you just created using cd
 > 3. Once inside the local repository, run cmake .
 > 4. run make
 > 5. run ./runAllFiles
 > 6. You should be now prompted with the main menu. (The specifics of how to navigate through the menu is explained with the screenshots above)
 ## Testing
 > How was your project tested/validated?
 
 >Our project was tested using the Google Test framework. The tests are testing classes and their methods, including the Task, Subtask, Project, and ProjectManager classes. The tests are checking that the methods of these classes are functioning correctly and producing the expected outputs.

 >We also tested our project using Valgrind for memory debugging, leak detection, and profiling. The Makefile compiles all the necessary source files and links them together to create an executable named "runAllFiles" which is then run under the Valgrind tool.
