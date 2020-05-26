//
// 原型模式 —— 简历复印
//

#ifndef DESIGNPATTERN_CPP_PROTOTYPE_H
#define DESIGNPATTERN_CPP_PROTOTYPE_H

// 简历 原型类
class Resume {
private:
    std::string name;
    std::string sex;
    std::string age;
    std::string timeArea;
    std::string company;
public:
    explicit Resume(std::string& inputName) {
        this->name = inputName;
    }

    void setPersonalInfo(std::string& inputSex, std::string& inputAge) {
        this->sex = inputSex;
        this->age = inputAge;
    }

    void setWorkExperience(std::string& inputTimeArea, std::string& inputCompany) {
        this->timeArea = inputTimeArea;
        this->company = inputCompany;
    }

    void display() {
        std::cout << this->name << " " << this->sex << " " << this->age << std::endl;
        std::cout << "Work experience: " << this->timeArea << " " << this->company << std::endl;
    }

    Resume clone() {
        Resume copy = Resume(this->name);
        copy.setPersonalInfo(this->sex, this->age);
        copy.setWorkExperience(this->timeArea, this->company);
        return copy;
    }
};

/*************************************
 *  // 原型                           *
 *  string name1 = "Big bird";       *
 *  string sex1 = "male";            *
 *  string age1 = "29";              *
 *  string ta1 = "1998-2000";        *
 *  string c1 = "XX company";        *
 *  Resume r1 = Resume(name1);       *
 *  r1.setPersonalInfo(sex1, age1);  *
 *  r1.setWorkExperience(ta1, c1);   *
 *                                   *
 *  string ta2 = "1998-2006";        *
 *  string c2 = "YY group";          *
 *  Resume r2 = r1.clone();          *
 *  r2.setWorkExperience(ta2, c2);   *
 *                                   *
 *  string sex2 = "female";          *
 *  string age2 = "24";              *
 *  Resume r3 = r1.clone();          *
 *  r3.setPersonalInfo(sex2, age2);  *
 *                                   *
 *  r1.display();                    *
 *  r2.display();                    *
 *  r3.display();                    *
 *************************************/

#endif //DESIGNPATTERN_CPP_PROTOTYPE_H
