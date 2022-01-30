#include <iostream>

using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(string NewSpecialization){value = NewSpecialization;}
};

struct Course
{
    string value;
    explicit Course(string NewCourse){value = NewCourse;}
};

struct Week
{
    string value;
    explicit Week(string NewWeek){value = NewWeek;}
};

struct LectureTitle 
{
    string specialization, course, week;

    LectureTitle(Specialization NewSpecialization, Course NewCourse, Week NewWeek)
    {
        specialization = NewSpecialization.value;
        course = NewCourse.value;
        week = NewWeek.value;
    }
};

int main()
{
    // LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th")); // compile
    // LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}}; //not compile
    
    // cout << title.course << " " ;
    return 0;
}