#include <iostream>
#include <string>
#include <vector>

// luodaan struct Student
struct Student
{
    std::string name {};
    int age {};
    int grade {};
};

//funktio palauttaa vektorista arvosanojen keskiarvon
double calc_average_grade(const std::vector<Student>& students)
{
    double sum {0.0};
    for (const auto& student : students) {
        sum += student.grade;
    }
    
    return (sum / students.size());
}

// funktio palauttaa structin: studentin jolla korkein arvosana
Student find_max_grade_student(const std::vector<Student>& students)
{
    Student max_grade_student = students[0];
    for (const auto& student : students) {
        if (student.grade > max_grade_student.grade) {
            max_grade_student = student;
        }
    }

    return max_grade_student;
}

int main()
{
    std::cout << "How many students will be input? ";
    int num_students {};
    std::cin >> num_students;

    // luodaan vektori käyttäjän antaman koon mukaan
    std::vector<Student> students(num_students);

    // luupataan vektoriin käyttäjältä tiedot
    for (int i {0}; i < num_students; i++) {
        std::cout << "Student " << (i + 1) << '\n';

        std::cout << "Enter name: ";
        std::cin >> students[i].name;

        std::cout << "Enter age: ";
        std::cin >> students[i].age;

        std::cout << "Enter grade: ";
        std::cin >> students[i].grade;
    }

    // etsitään funktiolla student jolla korkein arvosana, tulostetaan nimi alla
    Student student_with_max_grade = find_max_grade_student(students);

    std::cout << "Average grade is: " << calc_average_grade(students) << '\n';
    std::cout << "Student with the highest grade is: " << student_with_max_grade.name << '\n';
    
    return 0;
}
