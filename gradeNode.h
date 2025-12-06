class GradeNode {
public:
  
    int numericGrade;
    GradeNode* next;   
    GradeNode(int grade) : numericGrade(grade), next(nullptr) {}
};
#endif
