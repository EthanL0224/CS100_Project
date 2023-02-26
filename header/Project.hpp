#ifndef PROJECT_HPP
#define PROJECT_HPP
#include <vector>
#include <iostream>

class Project{
    private:
        vector<string> names;
        vector<Task*> tasks;
        vector<string> descriptions;
        string name;
        string description;
    public:
        Project(string, string);
        ~Project();
        void addTask(string,string,string,int,bool);
        int completedTasks();
        bool iscompleted(string);
        void editProjectName(string);
        void editTask();
        void editSubtask();
        void editProject_Description(string);
        void undo_Names();
        void undo_Description();
        void deleteTask();
        Task getTask();
        void outputTasks();
        void sortByPriority();
};
#endif