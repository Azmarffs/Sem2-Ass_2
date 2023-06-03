/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
using namespace std;
class Student {
    int stdID; //student ID
    string name; //student name
    string* courseCodes; //array of course codes
    int numCourses; //number of courses student is enrolled in
    int* courseGrades; //array of course grades
    float gpa; //student's GPA
public:
    Student(){ //default constructor
        stdID = 0;
        name = "";
        courseCodes = nullptr;
        courseGrades = nullptr;
        numCourses = 0;
        gpa = 0.0;
    }
    /*
    getters and setters
    */
    int getID(){
        return stdID;
    }
    string getName(){
        return name;
    }
    int getNumCourses(){
        return numCourses;
    }
    string getCourseCodes(int i){
        return courseCodes[i];
    }
    int getCourseGrade(int i){
        return courseGrades[i];
    }
    float getGpa(){
        return gpa;
    }
    void setStdID(int id){
        stdID = id;
    }
    void setName(string n){
        name = n;
    }
    void setCourseGrade(string courseCode, int grade){
        for(int i = 0; i < numCourses; i++){
            if(courseCodes[i] == courseCode){
                courseGrades[i] = grade;
                calcGPA();
                break;
            }
        }
    }
    void addCourse(string courseCode, int grade){
        int* forNewGrade = new int[numCourses + 1]; //temporary array for course grades
        string* forNewCourse = new string[numCourses + 1]; //temporary array for course codes
        int i = 0;
        while(i < numCourses){
            forNewGrade[i] = courseGrades[i];
            forNewCourse[i] = courseCodes[i];
            i++;
        }
        forNewGrade[numCourses] = grade;
        forNewCourse[numCourses] = courseCode;
        numCourses += 1;
        if(courseCodes == nullptr && courseGrades == nullptr){ //if no courses were previously added
            courseCodes = forNewCourse;
            courseGrades = forNewGrade;
            calcGPA();
        } else {
            delete[] courseCodes; //delete the old arrays
            delete[] courseGrades;
            courseCodes = forNewCourse; //set the new arrays
            courseGrades = forNewGrade;
            calcGPA(); //recalculate GPA
        }
    }
    void calcGPA(){
        float sum = 0;
        for(int i = 0; i < numCourses; i++){
            sum += courseGrades[i];
        }
        gpa = sum / numCourses;
    }
};

//function to get a specific student from the array of students
Student getStudentsAT(Student students[], int index){
    return students[index];
}

//function to calculate the class GPA
float calClassGPA(Student students[], int numStudents){
    float initiaVal = 0;
    for(int i = 0; i < numStudents; i++){
        students[i].calcGPA(); //recalculate GPA for each student
        initiaVal += students[i].getGpa() / numStudents; //sum the GPAs
    }
    return initiaVal;
}
// Returns the maximum GPA among all students
float getMaxGPA(Student students[], int numStudents){
    float maxGPA = students[0].getGpa(); // initialize maxGPA with the GPA of the first student
    int i = 0;
    while(i < numStudents){
        if(students[i].getGpa() > maxGPA){ // update maxGPA if the GPA of the current student is greater
            maxGPA = students[i].getGpa();
        }
        i++;
    }
    return maxGPA;
}

// Returns the minimum GPA among all students
float getMinGPA(Student students[], int numStudents){
    float minGPA = students[0].getGpa(); // initialize minGPA with the GPA of the first student
    int i = 0;
    while(i < numStudents){
        if(students[i].getGpa() < minGPA){ // update minGPA if the GPA of the current student is smaller
            minGPA = students[i].getGpa();
        }
        i++;
    }
    return minGPA;
}

// Prints the record of a specific student
void printStudentRecord(Student student){ 
    cout << "The name of student is: " << student.getName(); // print student name
    cout << "The ID of student is: " << student.getID(); // print student ID
    cout << "The course code is: " ;
    for(int i=0;i<student.getNumCourses();i++){
        cout << student.getCourseCodes(i) << " "; // print course codes
    }
    cout << endl;
    cout << "The grades are: ";
    for(int i=0;i<student.getNumCourses();i++){
        cout << student.getCourseGrade(i) << " "; // print course grades
    }
    cout << endl;
    cout << "The GPA of the students is: " << student.getGpa(); // print student GPA
}

// Prints the record of all students in the array
void printAllStudentRecords(Student students[], int numStudents){
    for(int i=0;i<numStudents;i++){ // iterate over all students in the array
        printStudentRecord(students[i]); // print the record of each student
    }
}

int main() {
    // create an array of students
    const int numStudents = 3;
    Student students[numStudents];

    // create some students and add courses and grades for them
    Student s1, s2, s3;
    s1.setStdID(1234);
    s1.setName("John Smith");
    s1.addCourse("COMP101", 85);
    s1.addCourse("MATH101", 92);
    s2.setStdID(5678);
    s2.setName("Jane Doe");
    s2.addCourse("COMP101", 90);
    s2.addCourse("MATH101", 87);
    s3.setStdID(9012);
    s3.setName("Bob Johnson");
    s3.addCourse("COMP101", 80);
    s3.addCourse("MATH101", 95);

    // add the students to the array
    students[0] = s1;
    students[1] = s2;
    students[2] = s3;

    // print the student records
    for (int i = 0; i < numStudents; i++) {
        printStudentRecord(students[i]);
    }

    // calculate and print the class GPA
    float classGPA = calClassGPA(students, numStudents);
    cout << "The class GPA is: " << classGPA << endl;

    // find and print the max and min GPA in the class
    float maxGPA = getMaxGPA(students, numStudents);
    float minGPA = getMinGPA(students, numStudents);
    cout << "The max GPA in the class is: " << maxGPA << endl;
    cout << "The min GPA in the class is: " << minGPA << endl;

    return 0;
}
