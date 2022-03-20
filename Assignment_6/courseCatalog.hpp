#pragma once
#include "std_lib_facilities.h"


class CourseCatalog{
    map<string, string> courseMap;
    void saveToTextFile();
public:
    CourseCatalog();
    void addCourse(string courseCode, string courseName);
    void removeCourse(string courseCode);
    string getCourse(string courseCode);
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);
};
