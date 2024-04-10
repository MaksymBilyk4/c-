#include <fmt/ranges.h>
#include <fmt/core.h>
#include <fmt/format.h>

enum StudentSortCriteria {

    NAME,

    SURNAME,

    INDEX,

    SEMESTER

};

struct Student {
private:
    std::string name;
    std::string surname;
    int studentNumber;
    int course;

public:
    Student(const std::string &name, const std::string &surname, int studentNumber, int course) : name(name),
                                                                                                  surname(surname),
                                                                                                  studentNumber(
                                                                                                          studentNumber),
                                                                                                  course(course) {}

public:

    auto getName() -> std::string { return name; };

    auto getSurname() -> std::string { return surname; };

    auto getStudentNumber() -> int { return studentNumber; };

    auto getCourse() -> int { return course; };

    auto setName(std::string studentName) -> void { name = studentName; };

    auto setSurname(std::string studentSurname) -> void { surname = studentSurname; };

    auto setStudentNumber(int number) -> void { studentNumber = number; };

    auto setCourse(int studentCourse) -> void { course = studentCourse; };

};

auto
sortStudent(std::vector<Student> &students, StudentSortCriteria sortCriteria = StudentSortCriteria::SEMESTER) -> void {
    if (sortCriteria == StudentSortCriteria::NAME)
        std::ranges::sort(students, {}, [](Student student) -> std::string { return student.getName(); });
    else if (sortCriteria == StudentSortCriteria::SURNAME)
        std::ranges::sort(students, {}, [](Student student) -> std::string { return student.getSurname(); });
    else if (sortCriteria == StudentSortCriteria::INDEX)
        std::ranges::sort(students, {}, [](Student student) -> int { return student.getStudentNumber(); });
    else std::ranges::sort(students, {}, [](Student student) -> int { return student.getCourse(); });
}

auto format_as(Student student) {
    return fmt::format("s{} - {} {}. Course: {}", student.getStudentNumber(), student.getSurname(), student.getName(),
                       student.getCourse());
}


auto main() -> int {

    Student s1 = Student("Maksym", "Bilyk", 30867, 1);
    Student s2 = Student("Abcd", "Gfqf", 10204, 2);
    Student s3 = Student("Random", "Random", 38094, 3);
    Student s4 = Student("Artem", "Tss", 39145, 1);

    auto students = std::vector<Student>{s1, s2, s3, s4};
    fmt::println("{}\n", students);

    sortStudent(students);
    fmt::println("{}\n", students);

    sortStudent(students, StudentSortCriteria::INDEX);
    fmt::println("{}\n", students);

    sortStudent(students, StudentSortCriteria::NAME);
    fmt::println("{}\n", students);

    sortStudent(students, StudentSortCriteria::SURNAME);
    fmt::println("{}\n", students);


    return 0;
}