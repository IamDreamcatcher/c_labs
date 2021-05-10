#ifndef ENROLLE_H
#define ENROLLE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct full_name {
    string name;
    string surname;
    string father_name;
};

struct passport_info {
    int id_;
    full_name full_name_;
    string adress_;
};

struct enrollee {
    int points_first_subject_;
    int points_second_subject_;
    int points_third_subject_;
    int average_mark_certificate_;
    string school_;
    passport_info passport_; 
};

struct specialty {
    string faculty_name_;
    string specialty_name_;
    vector <enrollee> enrollees_;
    int number_of_places_;
};

#endif
