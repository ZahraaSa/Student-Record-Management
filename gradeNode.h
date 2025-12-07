#ifndef GRADENODE_H
#define GRADENODE_H
#include<string>

class GradeNode {
    public:
     std::string courseName ; 
     int numericGrade;
     GradeNode* next; 

    GradeNode(){
        next=nullptr;
    }
};
#endif 

