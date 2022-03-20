
#include "ReadFromFile.hpp"
#include "countLetters.hpp"
#include "courseCatalog.hpp"
#include "readTeps.hpp"

void testCourseCatalogClass();


int main() {
    //saveToFile("userStrings.txt");
    //includeLineNumbers("userStrings.txt");
    //printFrequencies(countLetters("grunnlov.txt"));
    //debuggerMain();
    //testCourseCatalogClass();
}



void testTempStruct() {
    ifstream f{"temperatures.txt"};
    Temps t;
    f >> t;
    cout << t.max << " , " << t.min << "\n";
}


void testCourseCatalogClass() {
    CourseCatalog courseCatalog;
    courseCatalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    courseCatalog.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    courseCatalog.addCourse("TMA4100", "Matematikk 1");

    courseCatalog.addCourse("TDT4102","C++"); 
    // Endrer ikke på noenting med .insert()
    // Endrer mapping med c[cc] = cn

    cout << courseCatalog << "\n";
}



