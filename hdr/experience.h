#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "base.h"
#include "employee.h"
/*
  Đối với nhân viên Experience có thêm thuộc tính: 
  Số năm kinh nghiệm (ExpInYear), 
  Kỹ năng chuyên môn (ProSkill)
*/
class Experience : public Employee {
private:
    int _expInYear;
    string _proSkill;
public:
    Experience();
    ~Experience();
    static int _experienceCount;

    //override
    void inputInfo();
    void showMe();
};

#endif

