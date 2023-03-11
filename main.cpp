#include <iostream>
#include "header/Project.hpp"
#include "header/Task.hpp"
#include "header/ProjectManager.hpp"
#include "header/Subtask.hpp"
#include <stdlib.h>
#include <cctype>
#include <string>
using namespace std;
void editTask(string);
void editSubtask(string,string);

int main()
{
    ProjectManager* mainProgram = new ProjectManager();
    char userOption = '0';
    while(toupper(userOption) != 'Q')
    {
        system("CLS");
        userOption = '0';
        cout << "Project Menu: " << endl;
        cout << "Enter O to output all projects:" << endl;
        cout << "Enter D to delete a project:" << endl;
        cout << "Enter A to add a new project:" << endl;
        cout << "Enter S to get the amount of projects you have in your inventory:" << endl;
        cout << "Enter E if you would like to edit/inspect a project:" << endl;
        cout << "Enter Q to quit program" << endl;
        cin >> userOption;
        if(toupper(userOption) == 'O')
        {
            if(mainProgram->ProjectSize() > 0)
            {
                cout << mainProgram->outputProject() << endl;
            }
            else
            {
                cout << "You have no projects in your inventory" << endl;
            }
        }
        else if(toupper(userOption) == 'D')
        {
            if(mainProgram->ProjectSize() > 0)
            {
                cout << mainProgram->outputProjects() << endl;
                cout << "Enter the name of the Project you would like to delete or type C to cancel:" << endl;
                string ProjectToDelete = "0";
                cin >> ProjectToDelete;
                while(true)
                {
                    if(mainProgram->doesProjectExist(ProjectToDelete) == true)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Project does not exist, try again:" << endl;
                        cin >> ProjectToDelete;
                    }
                }
                Project* tmp = mainProgram->getProject(ProjectToDelete);
                mainProgram->deleteProject(tmp);
            }
            else
            {
                cout << "You have no projects in your inventory" << endl;
            }
        
            
        }
        else if(toupper(userOption) == 'A')
        {
            string nameForNewProject = "0";
            cout << "Enter the name that you would like to call this project:" << endl;
            cin >> nameForNewProject;
            string descriptionForNewProject = "0";
            cin.ignore();
            cout << "Enter a description for the project:" << endl;
            getline(cin, descriptionForNewProject);
            mainProgram->addProject(nameForNewProject, descriptionForNewProject);
        }
        else if(toupper(userOption) == 'S')
        {
            cout << "You have " << mainProgram->ProjectSize() << " projects in your inventory" << endl;
        }
        else if(toupper(userOption) == 'E')
        {
            Project* projectToEdit = nullptr;
            cout << mainProgram->outputProjects() << endl;
            while(true)
            {
                string findProject = "0";
                cout << "Enter the name of the project you would like to edit:" << endl;
                cin >> findProject;
                if(mainProgram->doesProjectExist(findProject) == false)
                {
                    cout << "Project does not exist:" << endl;
                }
                else
                {
                    projectToEdit = mainProgram->getProject(findProject);
                    break;
                }
            }
            char optionsForProject = '0';
            while(toupper(optionsForProject) != 'B')
            {
                system("CLS");
                cout << "Enter P to edit the project's name or description:" << endl;
                cout << "Enter E to undo an edit for the project's name or description:" << endl;
                cout << "Enter B to go back to the Project Menu:" << endl;
                cout << "Enter O to output all task in this project:" << endl;
                cout << "Enter A to add a task in this project:" << endl;
                cout << "Enter T to edit/inspect a task in this project:" << endl;
                cout << "Enter S to get the amount of complete task for this project:" << endl;
                cin >> optionsForProject;
                optionsForProject = toupper(optionsForProject);
                if(optionsForProject == 'P')
                {
                    char optionsForProjectNameOrDescription = '0';
                    while(true)
                    {
                        cout << "Enter N to edit the name of the project or D to edit the description of the project:" << endl;
                        cin >> optionsForProjectNameOrDescription;
                        optionsForProjectNameOrDescription = toupper(optionsForProjectNameOrDescription);
                        if(optionsForProjectNameOrDescription == 'N')
                        {
                            string newProjectName = "0";
                            cout << "Enter the new name you want for this project:" << endl;
                            cin >> newProjectName;
                            projectToEdit->editProjectName(newProjectName);
                            break;
                        }
                        else if(optionsForProjectNameOrDescription == 'D')
                        {
                            string newProjectDescription = "0";
                            cout << "Enter the new description you want for this project:" << endl;
                            getline(cin, newProjectDescription);
                            projectToEdit->editProject_Description(newProjectDescription);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Option, Try Again" << endl;
                        }
                    }
                }
                else if(optionsForProject == 'E')
                {
                    char optionsForUndoProject = '0';
                    cout << "Enter N to undo name of Project or D to undo description of Project:" << endl;
                    cin >> optionsForUndoProject;
                    optionsForUndoProject = toupper(optionsForUndoProject);
                    while(true)
                    {
                        if(optionsForUndoProject == 'N')
                        {
                            projectToEdit->undo_Names();
                            cout << "Successfully Undo Project Name" << endl;
                            break;
                        }
                        else if(optionsForUndoProject == 'D')
                        {
                            projectToEdit->undo_Description();
                            cout << "Successfully Undo Project Description" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Incorrect Option, Try Again" << endl;
                            cin >> optionsForUndoProject;
                        }
                    }
                }
                else if(optionsForProject == 'O')
                {
                    char optionForOutputtingFormat = '0';
                    while(true)
                    {
                        cout << "Enter 1 to output tasks according to deadline or 2 to output tasks according to priority:" << endl;
                        cin >> optionForOutputtingFormat;
                        if(optionForOutputtingFormat == '1')
                        {
                            cout << projectToEdit->outputTasks(true) << endl;
                            break;
                        }
                        else if(optionForOutputtingFormat == '2')
                        {
                            cout << projectToEdit->outputTasks(false) << endl;
                            break;
                        }
                        else
                        {
                            cout << "Invalid option, Try Again" << endl;
                        }
                    }
                
                }
                else if(optionsForProject == 'A')
                {
                    string nameForNewTask = "0";
                    string descriptionForNewTask = "0";
                    bool statusForNewTask = false;
                    string deadlineForNewTask = 0;
                    string priorityForNewTask = 0;
                    cout << "Enter a name for the new task:" << endl;
                    cin >> nameForNewTask;
                    cout << "Enter a description for the new task:" << endl;
                    cin.ignore();
                    getline(cin, descriptionForNewTask);
                    bool correctDeadlineInput = false;
                    while(correctDeadlineInput == false)
                    {   
                        bool isValidInputForDeadline = true;
                        cout << "Enter a deadline for this task: FORMAT(YYYYMMDD):" << endl;
                        cout << "EX: 20220122 = January 21st, 2022:" << endl;
                        cin >> deadlineForNewTask;
                        for(int i = 0; i < deadlineForNewTask.size(); ++i)
                        {
                            if(!isdigit(deadlineForNewTask.at(i)))
                            {
                                isValidInputForDeadline = false;
                            }
                        }
                        if(isValidInputForDeadline == true)
                        {
                            correctDeadlineInput = true;
                        }
                        else
                        {
                            cout << "Invalid Option, Try Again" << endl;
                        }
                    }
                    bool correctPriorityInput = false;
                    while(correctPriorityInput == false)
                    {
                        bool isvalidInputForPriority = true;
                        cout << "Enter a priority for the task:" << endl;
                        cin >> priorityForNewTask;
                        for(int i = 0; i < priorityForNewTask.size(); ++i)
                        {
                            if(!isdigit(priorityForNewTask.at(i)))
                            {
                                isvalidInputForPriority = false;
                            }
                        }
                        if(isvalidInputForPriority == true)
                        {
                            correctPriorityInput = true;
                        }
                        else
                        {
                            cout << "Invalid Option, Try Again:" << endl;
                        }
                    }
                    projectToEdit->addTask(nameForNewTask, descriptionForNewTask, stoi(deadlineForNewTask), stoi(priorityForNewTask), statusForNewTask);
                }
                else if(optionsForProject == 'T')
                {
                    Task* taskForUserToEdit = nullptr;
                    cout << projectToEdit->outputTasks() << endl;
                    while(true)
                    {
                        string taskToEdit = "0";
                        cout << "Enter the name of the Task you would like to edit:" << endl;
                        cin >> taskToEdit;
                        if(mainProgram->doesTaskExist(taskToEdit) == true)
                        {
                            taskForUserToEdit = projectToEdit->getTask(taskToEdit);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input, Try Again" << endl;
                        }
                    }
                    char optionsForTasks = '0';
                    while(optionsForTasks != 'B')
                    {
                        system("CLS");
                        cout << "Enter B to go back to previous page:" << endl;
                        cout << "Enter A to add subtask for this task:" << endl;
                        cout << "Enter E to edit a feature of the Task:" << endl;
                        cout << "Enter S to edit a feature of the subtask:" << endl;
                        cout << "Enter U to undo changes for the task:" << endl;
                        cout << "Enter C to undo changes for a subtask:" << endl;
                        cout << "Enter D to delete a subtask:" << endl;
                        cout << "Enter P to get the priority of this task:" << endl;
                        cout << "Enter Z to get the deadline of this task:" << endl;
                        cout << "Enter O to output all the subtasks in this task:" <<endl;
                        cin >> optionsForTasks;
                        optionsForTasks = toupper(optionsForTasks);
                        if(optionsForTasks == 'E')
                        {
                            editTask(taskForUserToEdit->GetName());
                        }
                        else if(optionsForTasks == 'S')
                        {
                            cout << taskForUserToEdit->outputsubs() << endl;
                            string findSubtask = "0";
                            while(true)
                            {
                                findSubtask = "0";
                                cout << "Enter the name of the subtask you want to edit:" << endl;
                                cin >> findSubtask;
                                if(taskForUserToEdit->doesSubtaskExist(findSubtask)==true)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Incorrect Option, Try Again:" << endl;
                                }

                            }
                            editSubtask(findSubtask, taskForUserToEdit->GetName());
                        }
                        else if(optionsForTasks == 'A')
                        {
                            string newNameForSubtask = "";
                            string newDescriptionForSubtask = "";
                            bool newStatusForSubtask = false;
                            cout << "Enter the name for this subtask:" << endl;
                            cin >> newNameForSubtask;
                            cout << "Enter the description for this subtask:" << endl;
                            cin.ignore();
                            getline(cin, newDescriptionForSubtask);
                            taskForUserToEdit->addSubtask(newNameForSubtask, newDescriptionForSubtask, newStatusForSubtask);
                        }
                        else if(optionsForTasks == 'C')
                        {
                            string findSubtask = "0";
                            cout << taskForUserToEdit->outputsubs() << endl;
                            while(true)
                            {
                                findSubtask = "0";
                                cout << "Enter the name of the subtask you want to undo:" << endl;
                                cin >> findSubtask;
                                if(taskForUserToEdit->doesSubtaskExist(findSubtask)==true)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Incorrect Option, Try Again:" << endl;
                                }

                            }
                            Subtask* subtaskForUserToEdit = taskForUserToEdit->getSubtask(findSubtask);
                            while(true)
                            {
                                char optionsForUndoSubtask = '0';
                                cout << "Enter N to undo name, D to undo description, or S for status of the subtask:" << endl;
                                cin >> optionsForUndoSubtask;
                                optionsForUndoSubtask = toupper(optionsForUndoSubtask);
                                if(optionsForUndoSubtask == 'N')
                                {
                                    subtaskForUserToEdit->undoName();
                                    cout << "Successfully Undo Subtask Name" << endl;
                                    break;
                                }
                                else if(optionsForUndoSubtask == 'D')
                                {
                                    subtaskForUserToEdit->undo_Description();
                                    cout << "Successfully Undo Subtask Name" << endl;
                                    break;
                                }
                                else if(optionsForUndoSubtask == 'S')
                                {
                                    subtaskForUserToEdit->undoStatus();
                                    cout << "Successfully Undo Subtask Status" << end;
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Option, Try Again" << endl;
                                }
                            }
                        }
                        else if(optionsForTasks == 'D')
                        {
                            string findSubtask = "0";
                            while(true)
                            {
                                findSubtask = "0";
                                cout << "Enter the name of the subtask you want to undo:" << endl;
                                cin >> findSubtask;
                                if(taskForUserToEdit->doesSubtaskExist(findSubtask)==true)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Incorrect Option, Try Again" << endl;
                                }

                            }
                            taskForUserToEdit->deleteSubtask(findSubtask);
                        }
                        else if(optionsForTasks == 'P')
                        {
                            cout << "The priority of this task is " << taskForUserToEdit->getpriority() << endl;
                        }
                        else if(optionsForTasks == 'O')
                        {
                            cout << taskForUserToEdit->outputsubs() << endl;
                        }
                        
                    }
                    

                }
                else if(optionsForProject == 'S')
                {
                    cout << "You have " << projectToEdit->completedTasks() << " in you project" << endl;
                }
                else if(optionsForProject == 'Z')
                {
                    string nameToGetDeadline = "";
                    cout << projectToEdit->outputTasks() << endl;
                    while(true)
                    {
                        cout << "Enter the name of the name of the task you want the deadline for:" << endl;
                        cin >> nameToGetDeadline;
                        if(doesTaskExist(nameToGetDeadline) == true)
                        {
                            Task* deadlineForUser = projectToEdit->getTask(nameToGetDeadline);
                            cout << "The deadline for this task is " << deadlineForUser->getDeadline() << endl;
                        }
                    }
                }
                else
                {
                    cout << "Invalid Option, Try Again" << endl;
                }

            }
        }
        else
        {
            cout << "Invalid Option, Try Again" << endl;
        }
    }
    delete mainProgram;
    return 0;
}

void editTask(string nameOfTask){
    Task* tmp = getTask(nameOfTask);
    string whichToChange = "";
    cout << "Enter 'name' to modify name, 'description' to modify description, 'deadline' to modify deadline, 'status' to modify status, or 'priority' to change priority:" << endl;
    cin >> whichToChange;
    while(true)
    {
        if(whichToChange == "name")
        {
            string NewName;
            cout << "Enter the name you want to change: " << endl;
            cin >> NewName;
            tmp->changeName(NewName);
            break;
        }
        else if(whichToChange == "description")
        {
            string newDescription;
            cout << "Enter the new description you want to change: " <<endl;
            getline(cin, newDescription);
            tmp->changeDescriptions(newDescription);
            break;
        }
        else if(whichToChange == "deadline")
        {
            string newDeadline = "0";
            bool correctDeadlineInput = false;
            while(correctDeadlineInput == false)
            {   
                bool isValidInputForDeadline = true;
                cout << "Enter the new deadline you want to change: FORMAT(YYYYMMDD):" << endl;
                cout << "EX: 20220122 = January 21st, 2022:" << endl;
                cin >> newDeadline;
                for(int i = 0; i < newDeadline.size(); ++i)
                {
                    if(!isdigit(newDeadline.at(i)))
                    {
                        isValidInputForDeadline = false;
                    }
                }
                if(isValidInputForDeadline == true)
                {
                    correctDeadlineInput = true;
                }
                else
                {
                    cout << "Invalid Option, Try Again" << endl;
                }
            }
            tmp->changeDeadline(stoi(newDeadline));
            break;
        }
        else if(whichToChange == "status")
        {
            bool status;
            string option;
            cout << "Enter one if you want to make the status of task " <<  tmp->GetName()
            << " complete or zero if status is uncomplete: " << endl;
            cin >> option;
            while(true)
            {
                if(option == "1")
                {
                    tmp->changeStatus(true);
                    break;
                }
                else if(option == "0"){
                    tmp->changeStatus(false);
                    break;
                }
                else{
                    cout << "Incorrect value, Try Again: " << endl;
                    cin >> option;
                }
                
            }
            break;
        }
        else if(whichToChange == "priority")
        {
            string newPriority = "0";
            bool correctPriorityInput = false;
            while(correctPriorityInput == false)
            {
                bool isvalidInputForPriority = true;
                cout << "Enter the new priority of this task in digits:" << endl;
                cin >> newPriority;
                for(int i = 0; i < newPriority.size(); ++i)
                {
                    if(!isdigit(newPriority.at(i)))
                    {
                        isvalidInputForPriority = false;
                    }
                }
                if(isvalidInputForPriority == true)
                {
                    correctPriorityInput = true;
                }
                else
                {
                    cout << "Invalid Option, Try Again:" << endl;
                }
            }
            tmp->changePriority(stoi(newPriority));
            break;
            
        }
        else
        {
            cout << "Incorrect option, Try Again" << endl;
            cin >> whichToChange;
        }

    }
}

void editSubtask(string nameOfSubtask, string nameOfTaskForEditSubtask)
{
    Task* tmp = getTask(nameOfTaskForEditSubtask);
    Subtask* Sub = tmp->getSubtask(nameOfSubtask);
    string whichToChange = "";
    cout << "Enter 'name' to modify name, 'description' to modify description, or 'status' to modify status" << endl;
    cin >> whichToChange;
    while(true)
    {
        if(whichToChange == "name")
        {
            string NewName;
            cout << "Enter the name you want to change: " << endl;
            cin >> NewName;
            Sub->changeName(NewName);
            break;
        }
        else if(whichToChange == "description")
        {
            string newDescription;
            cout << "Enter the new description you want to change: " <<endl;
            getline(cin, newDescription);
            Sub->changeDescriptions(newDescription);
            break;
        }
        else if(whichToChange == "status")
        {
            bool status;
            string option;
            cout << "Enter one if you want to make the status of task " <<  tmp->GetName()
            << " complete or zero if status is uncomplete: " << endl;
            cin >> option;
            while(true)
            {
                if(option == "1")
                {
                    tmp->changeStatus(true);
                    break;
                }
                else if(option == "0"){
                    Sub->changeStatus(false);
                    break;
                }
                else{
                    cout << "Incorrect value, Try Again: " << endl;
                    cin >> option;
                }
                
            }
            break;
        }
        else
        {
            cout << "Incorrect option, Try Again" << endl;
            cin >> whichToChange;
        }

    }
}