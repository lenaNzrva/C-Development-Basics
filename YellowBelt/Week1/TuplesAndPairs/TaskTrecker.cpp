#include <iostream>
#include <map>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks {
public:
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
    return M.at(person);
  }
  
  void AddNewTask(const string& person)
  {
    M[person][TaskStatus::NEW] ++;
  }

  void PerformPersonTasks(const string& person, int task_count)
  {
    map<TaskStatus, int> CopyForIteration = M[person];
    for (auto &i : CopyForIteration)
    {
      if (i.second != 0 && task_count !=0)
      {
        if ((i.second-task_count)>0 || (i.second-task_count)==0)
        {
          M[person][i.first] -= task_count;
          task_count = 0;
        }else
        {
          M[person][i.first] -= i.second;
          task_count -= i.second;
        }
      }
    }
  }

private:
  map<string, TasksInfo> M;
  // map<string, TasksInfo> CopyForIteration;
};

int main()
{
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  tasks.PerformPersonTasks("Ivan", 2);
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    return 0;
}