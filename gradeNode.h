#ifndef GRADENODE_H
#define GRADENODE_H

class GradeNode {
public:
    int numericGrade;
    GradeNode* next;

    GradeNode() {
        next = nullptr;
    }
};
#endif