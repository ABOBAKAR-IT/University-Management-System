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
    /* void semester2();
     void semester3();
     void semester4();
     void semester5();
     void semester6();
     void semester7();
     void semester8();*/
    void totalStudents();
    void CS(int smpt);
    void SE(int smpt);
    void IT(int smpt);
    void totalFirst();
    // void totalSecond();
    // void totalThird();
    // void totalFourth();
    // void totalFifth();
    // void totalSixth();
    // void totalSeventh();
    // void totalEigth();
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
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    if(choice<9&&choice>0){
    semester(choice);
    }
else if(choice==9){
    totalStudents();
}
    else{
        cout<<"Invalid Choice\n";
    }

    /*switch(choice){
        case 1:
            u.semester1();
            break;
        case 2:
            u.semester2();
            break;
        case 3:
            u.semester3();
            break;
        case 4:
            u.semester4();
            break;
        case 5:
            u.semester5();
            break;
        case 6:
            u.semester6();
            break;
        case 7:
            u.semester7();
            break;
        case 8:
            u.semester8();
            break;
        case 9:
            u.totalStudents();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }*/
}
void University::semester(int smpt)
{
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total First Semester Students";
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
        totalFirst();
        break;
    default:
        cout << "\aInvalid Choice\n";
        break;
    }
}
/*void University::semester2(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Second Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalSecond();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester3(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Third Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalThird();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester4(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Fourth Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalFourth();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester5(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Fifth Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalFifth();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester6(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Sixth Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalSixth();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester7(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Seventh Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalSeventh();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}
void University::semester8(){
    int choice;
    cout << "1.  CS";
    cout << "\n2.  IT";
    cout << "\n3.  SE";
    cout << "\n4.  Total Eigth Semester Students";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            u.CS();
            break;
        case 2:
            u.SE();
            break;
        case 3:
            u.IT();
            break;
        case 4:
            totalEigth();
            break;
        default:
            cout << "\aInvalid Choice\n";
            break;
    }
}*/
void University::totalStudents()
{
   /* for (int a = 0; a < total; a++)
    {
        u.count++;
    }*/
    cout << "No Of Students: " << total<< endl;
   // u.count = 0;
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
        /* switch(smpt){
             case 1:
                 if((u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS")&&u.s[a].semester==smpt){
                     total_stuent++;
                 }
                 break;
             case 2:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     total_stuent++;
                 }
                 break;
             case 3:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             case 4:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             case 5:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             case 6:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             case 7:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             case 8:
                 if(u.s[a].department == "CS" || u.s[a].department == "cs" || u.s[a].department == "Cs" || u.s[a].department == "cS"){
                     u.count++;
                 }
                 break;
             default:
                 cout << "\nInvalid Choice";
                 break;
         }*/
    }
    cout << "No of Students of cs: " << total_stuent << endl;
    total_stuent = 0;
}
void University::SE(int smpt)
{
    for (int a = 0; a < total; a++)
    {
        switch (u.s[a].semester)
        {
        case 1:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 2:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 3:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 4:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 5:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 6:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 7:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        case 8:
            if (u.s[a].department == "SE" || u.s[a].department == "se" || u.s[a].department == "Se" || u.s[a].department == "sE")
            {
                u.count++;
            }
            break;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::IT(int smpt)
{
    for (int a = 0; a < total; a++)
    {
        switch (u.s[a].semester)
        {
        case 1:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 2:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 3:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 4:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 5:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 6:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 7:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        case 8:
            if (u.s[a].department == "IT" || u.s[a].department == "it" || u.s[a].department == "It" || u.s[a].department == "iT")
            {
                u.count++;
            }
            break;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalFirst()
{
    for (int a = 0; a < total; a++)
    {
        if (s[a].semester == 1)
        {
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
/*
void University::totalSecond(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 2){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalThird(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 3){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalFourth(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 4){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalFifth(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 5){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalSixth(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 6){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalSeventh(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 7){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}
void University::totalEigth(){
    for(int a = 0; a < total; a++){
        if(s[a].semester == 8){
            u.count++;
        }
    }
    cout << "No of Students: " << u.count << endl;
    u.count = 0;
}*/
int main()
{
    u.menu();
    return 0;
}