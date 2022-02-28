#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <sstream>

using namespace std;

enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

ostream& operator <<(ostream& out, const TaskStatus& status) {
    string statusName;
    switch (status) {
        case TaskStatus::NEW:
            statusName = "\"NEW\"";
            break;
        case TaskStatus::IN_PROGRESS:
            statusName = "\"IN_PROGRESS\"";
            break;
        case TaskStatus::TESTING:
            statusName = "\"TESTING\"";
            break;
        case TaskStatus::DONE:
            statusName = "\"DONE\"";
            break;
    }
    return out << statusName;
}


class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const{return M.at(person);}

    void AddNewTask(const string& person){M[person][TaskStatus::NEW] ++;}

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
    {
        TasksInfo updated;
        TasksInfo NOTupdated = M[person];
        TasksInfo MCopy = M[person];
        int task;

        if (M.count(person) == 0){return {updated, NOTupdated};}

        int i = 0;
        while (task_count > 0 && i < iter.size()-1)
        {
            task = MCopy[iter[i]];
            if(task-task_count > 0)
            {
                M[person][iter[i]] -= task_count;
                M[person][iter[i+1]] += task_count;
                updated[iter[i+1]] += task_count;
                NOTupdated[iter[i]] -= task_count;
                task_count = 0;
            }
            else if(task-task_count < 0)
            {
                M[person][iter[i+1]] += task;
                updated[iter[i+1]] += task;
                M[person][iter[i]] -= task;
                NOTupdated[iter[i]] -= task;
                task_count -= task;

            }else if(task-task_count == 0)
            {
                M[person][iter[i+1]] += task;
                updated[iter[i+1]] += task;
                M[person][iter[i]] -= task;
                NOTupdated[iter[i]] -= task;
                task_count = 0;
            }
            NOTupdated.erase(TaskStatus::DONE);
            if (M[person][iter[i]] == 0){M[person].erase(iter[i]);}
            if (updated[iter[i]] == 0){updated.erase(iter[i]);}
            if (updated[iter[i+1]] == 0){updated.erase(iter[i+1]);}
            if (NOTupdated[iter[i]] == 0){NOTupdated.erase(iter[i]);}

            i ++;
        }
        return {updated, NOTupdated};
    }

private:
    map<string, TasksInfo> M;
    vector<TaskStatus> iter = {TaskStatus::NEW, TaskStatus::IN_PROGRESS,
    TaskStatus::TESTING, TaskStatus::DONE};
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}


