#include "courseCatalog.hpp"

CourseCatalog::CourseCatalog() {
    fstream savedCatalog;
    savedCatalog.open("courseCatalogMemory.txt",ios::in);
    if (savedCatalog.is_open()) {
        string delimiter = ",";
        string line;
        while (getline(savedCatalog,line)) {
            int splitIndex = line.find(delimiter);
            courseMap.insert({line.substr(0,splitIndex),line.substr(splitIndex+1,size(line))});
        }
    savedCatalog.close();
    } else {
        cout << "Failed to load catalog from memory.\n";
    }
}

void CourseCatalog::saveToTextFile() {
    fstream courseCatalogMemory;
    courseCatalogMemory.open("courseCatalogMemory.txt",ios::out);
    if (courseCatalogMemory.is_open()) {
        for (const auto& m:courseMap) {
            courseCatalogMemory << m.first << "," << m.second << "\n";
        }
    courseCatalogMemory.close();
    } else {
        cout << "Was unable to save mapping to file\n";
    }
}

void CourseCatalog::addCourse(string courseCode, string courseName){
    courseMap.insert({courseCode,courseName});
    //courseMap[courseCode] = courseName;
    saveToTextFile();
}

void CourseCatalog::removeCourse(string courseCode){
    courseMap.erase(courseCode);
    saveToTextFile();
}

string CourseCatalog::getCourse(string courseCode){
    return courseMap.at(courseCode);
}

ostream& operator<<(ostream& os, const CourseCatalog& c){
    for (const auto& course:c.courseMap) {
        os << "Course code: " << course.first << ", course name: " << course.second << "\n";
    }
    return os;
}

