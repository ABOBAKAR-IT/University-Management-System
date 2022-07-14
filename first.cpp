// University Management System Complete Project in C++
#include <iostream>
using namespace std;
struct Student
{
    string courses[5];
    string name, roll, contact, department;
    int semester;
};
class University
{
private:
    int count;
    int total;
    Student s[100];

public:
    University();
    void menu();
    friend istream &operator>>(istream &in, Student &s1);
    friend ostream &operator<<(ostream &out, Student &s1);
    void get();
    void show();
    void search();
    void update();
    void del();
    void noOfStudents();
    void semester(int smpt);
    void totalStudents();//Search number of students in University
    void CS(int smpt);
    void SE(int smpt);
    void IT(int smpt);
    void departmentStudents();//search total number fo student in a department
    void totalSemester(int smpt);//earch total number of students in a semester

} u;
// Students Management System
University::University() : count(0), total(0) {}
void University::menu()
{
    int choice;
    while (1)
    {
        cout << "1.  Enter Data";
        cout << "\n2.  Show Data";
        cout << "\n3.  Search Data";
        cout << "\n4.  Update Data";
        cout << "\n5.  Delete Data";
        cout << "\n6.  No Of Students";
        cout << "\n7.  Exit the Program";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            u.get();
            break;
        case 2:
            u.show();
            break;
        case 3:
            u.search();
            break;
        case 4:
            u.update();
            break;
        case 5:
            u.del();
            break;
        case 6:
            u.noOfStudents();
            break;
        case 7:
            exit(1);
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}
istream &operator>>(istream &in, Student &s1)
{
    in.ignore();
    cout << "Enter Your Name: ";
    getline(in, s1.name);
    cout << "Enter Roll No: ";
    in >> s1.roll;
    cout << "Enter Courses of this Semester: ";
    for (int a = 0; a < 5; a++)
    {
        in >> s1.courses[a];
    }
    cout << "Enter Your Semester: ";
    in >> s1.semester;
    cout << "Enter Your Department: ";
    in >> s1.department;
    cout << "Enter your Contact No: ";
    in >> s1.contact;
    return in;
}
ostream &operator<<(ostream &out, Student &s1)
{
    out << "Name: " << s1.name << endl;
    out << "Roll No: " << s1.roll << endl;
    out << "courses: ";
    for (int a = 0; a < 5; a++)
    {
        out << s1.courses[a] << endl;
    }
    out << "Semester: " << s1.semester << endl;
    out << "Department: " << s1.department << endl;
    out << "Contact No: " << s1.contact << endl;
    return out;
}
void University::get()
{
    int n;
    cout << "How many students do you want to enter: ";
    cin >> n;
    for (int a = total; a < total + n; a++)
    {
        cout << "Enter data of Students " << a + 1 << endl;
        cin >> s[a];
    }
    total = total + n;
}
void University::show()
{
    if (total != 0)
    {
        for (int a = 0; a < total; a++)
        {
            cout << "Data of Student " << a + 1 << endl;
            cout << s[a];
        }
    }
    else
    {
        cout << "Your Data Buses are Empty\n";
    }
}
void University::search()
{
    string rollNo;
    cout << "Enter Roll No of Student which yo want to search: ";
    cin >> rollNo;
    if (total != 0)
    {
        for (int a = 0; a < total; a++)
        {
            if (rollNo == s[a].roll)
            {
                cout << s[a];
                break;
            }
            else if (a == total - 1)
            {
                cout << "\aInvalid Choice\n";
            }
        }
    }
    else
    {
        cout << "Your Data Buses are Empty\n";
    }
}
void University::update()
{
    string roll;
    cout << "Enter Roll No of Students which you want to update: ";
    cin >> roll;
    if (total != 0)
    {
        for (int a = 0; a < total; a++)
        {
            if (roll == s[a].roll)
            {
                cin >> s[a];
            }
            else
            {
                cout << "\aInvalid Roll No\n";
            }
        }
    }
    else
    {
        cout << "Your Data Buses are Empty\n";
    }
}
void University::del()
{
    string rollNo;
    int choice;
    cout << "Enter 1 to Delete Full Record";
    cout << "\nEnter 2 to Delete Specific Record";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        total = 0;
        cout << "All Record is Deleted.......\n";
        break;
    case 2:
        cout << "Enter Roll No of Student which ou want to Delete: ";
        cin >> rollNo;
        for (int a = 0; a < total; a++)
        {
            if (rollNo == s[a].roll)
            {
                for (int b = a; b < total; b++)
                {
                    s[a] = s[b + 1];
                }
                total--;
                cout << "Your Required Record is Deleted.......\n";
            }
            else
            {
                cout << "\aInvalid Roll No\n";
            }
        }
        break;
    default:
        cout << "\aInvalid Choice\n";
        break;
    }
}
void University::noOfStudents()
{
    int choice;
    cout << "1.  1st Semester Students";
    cout << "\n2.  2nd Semester Students";
    cout << "\n3.  3rd Semester Students";
    cout << "\n4.  4th Semester Students";
    cout << "\n5.  5th Semester Students";
    cout << "\n6.  6th Semester Students";
    cout << "\n7.  7th Semester Students";
    cout << "\n8.  8th Semester Students";
    cout << "\n9.  Total Students";
    cout << "\n10.  Total Students in a Department";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    if (choice < 9 && choice > 0)
    {
        semester(choice);
    }
    else if (choice == 9)
    {
        totalStudents();
    }
    else if (choice == 10)
    {
        departmentStudents();
    }
    else
    {
        cout << "Invalid Choice\n";
    }
}
void University::semester(int smpt)
{
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total " << smpt << " Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        u.CS(smpt);
        break;
    case 2:
        u.SE(smpt);
        break;
    case 3:
        u.IT(smpt);
        break;
    case 4:
        totalSemester(smpt);
        break;
    default:
        cout << "\aInvalid Choice\n";
        break;
    }
}

void University::totalStudents()
{

    cout << "No Of Students: " << total << endl;
}
void University::CS(int smpt)
{
    int total_stuent = 0;
    for (int a = 0; a < total; a++)
    {
        cout << "semester : " << u.s[a].semester << endl;
        if ((u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS") && u.s[a].semester == smpt)
        {
            total_stuent++;
        }
    }
    cout << "No of Students of CS: " << total_stuent << endl;
    total_stuent = 0;
}
void University::SE(int smpt)
{
    int total_stuent = 0;
    for (int a = 0; a < total; a++)
    {
        cout << "semester : " << u.s[a].semester << endl;
        if ((u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE") && u.s[a].semester == smpt)
        {
            total_stuent++;
        }
    }
    cout << "No of Students of SE: " << total_stuent << endl;
    total_stuent = 0;
}
void University::IT(int smpt)
{
    int total_stuent = 0;
    for (int a = 0; a < total; a++)
    {
        cout << "semester : " << u.s[a].semester << endl;
        if ((u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT") && u.s[a].semester == smpt)
        {
            total_stuent++;
        }
    }
    cout << "No of Students of IT: " << total_stuent << endl;
    total_stuent = 0;
}
void University::totalSemester(int smpt)
{
    int total_stuent = 0;
    for (int a = 0; a < total; a++)
    {
        if (s[a].semester == smpt)
        {
            total_stuent++;
        }
    }
    cout << "No of Students: " << total_stuent << endl;
    u.count = 0;
}
void University::departmentStudents()//search number fo student in a department
{
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    int total_stuent = 0;
    string dpt;
    for (int a = 0; a < total; a++)
    {
        if (choice == 1)
        {dpt="CS";
            if (s[a].department == "CS" || s[a].department == "cs" || s[a].department == "Cs" || s[a].department == "cS")
            {
                total_stuent++;
            }
        }
        if (choice == 2)
        {dpt="IT";
            if (s[a].department == "IT" || s[a].department == "it" || s[a].department == "It" || s[a].department == "iT")
            {
                total_stuent++;
            }
        }
        if (choice == 3)
        {dpt="SE";
            if (s[a].department == "SE" || s[a].department == "se" || s[a].department == "Se" || s[a].department == "sE")
            {
                total_stuent++;
            }
        }
    }
    cout << "No of Students "<<dpt<< ": " << total_stuent << endl;
}
int main()
{
    u.menu();
    return 0;
}