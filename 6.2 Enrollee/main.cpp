#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "enrollee.h"

using std::string;
using std::vector;

string get_string(FILE* input) {
    string in = "";
    char c[1000];
    while (fscanf(input, "%s", c) != 1 ) {
        printf("Enter correct string\n");
    }
    in = c;
    return in;
}
int get_int(FILE* input) {
    int x;
    while (fscanf(input, "%d", &x) != 1 || x < 0 || x > 100) {
        printf("Enter correct int\n");
    }
    return x;
}
bool is_correct(string& input, vector<specialty>& specialties) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == input) {
            return true;
        }
    }
    return false;
}
string get_specialty(vector<specialty>& specialties, FILE* input) {
    string in = get_string(input);
    while (!is_correct(in, specialties)) {
        printf("Enter correct specialty\n");
        in = get_string(input);
    }    
    return in;
}
full_name get_full_name(FILE* input) {
    full_name full_name_;
    for (size_t i = 0; i < 3; i++) {
        string in = get_string(input);
        if (i == 0) {
            full_name_.name = in;
        }
        else if (i == 1) {
            full_name_.surname = in;
        }
        else {
            full_name_.father_name = in;
        }
    }
    return full_name_;   
}
passport_info get_passport(FILE* input) {
    passport_info passport_info;
    passport_info.full_name_ = get_full_name(input);
    passport_info.id_ = get_int(input);
    passport_info.adress_ = get_string(input);
    return passport_info;
}
enrollee get_student(FILE* input) {
    enrollee enrollee_;
    enrollee_.passport_ = get_passport(input);
    enrollee_.school_ = get_string(input);
    enrollee_.average_mark_certificate_ = get_int(input);
    enrollee_.points_first_subject_ = get_int(input);
    enrollee_.points_second_subject_ = get_int(input);
    enrollee_.points_third_subject_ = get_int(input);
    return enrollee_;
}
int get_rating(enrollee enrollee_) {
    return enrollee_.average_mark_certificate_ + enrollee_.points_first_subject_ +
        enrollee_.points_second_subject_ + enrollee_.points_third_subject_;
}
bool operator<(const enrollee& first, const enrollee& second) {
    double first_sum = get_rating(first);
    double second_sum = get_rating(second);
    return first_sum > second_sum;
}
bool operator==(const full_name& first, const full_name& second) {
    return first.name == second.name && first.surname == second.surname && first.father_name == second.father_name; 
}

void apply(vector <specialty>& specialties, string my_specialty, enrollee& enrollee_) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == my_specialty) {
            specialties[i].enrollees_.push_back(enrollee_);
            break;
        }
    }
}

void pick_up_application(vector <specialty>& specialties, string& my_specialty, full_name& enrollee_) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == my_specialty) {
            for (size_t j = 0; j < specialties[i].enrollees_.size(); j++) {
                if (specialties[i].enrollees_[j].passport_.full_name_ == enrollee_) {
                    specialties[i].enrollees_.erase(specialties[i].enrollees_.begin() + j);
                    break;
                }
            }
            break;
        }
    }
}

double find_out_the_passing_score(vector <specialty>& specialties, string& specialty_name) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == specialty_name) {
            std::sort(specialties[i].enrollees_.begin(), specialties[i].enrollees_.end());   
            int places = specialties[i].number_of_places_;
            if (specialties[i].enrollees_.size() <= places) {
                return get_rating(specialties[i].enrollees_.back());
            } 
            int x = get_rating(specialties[i].enrollees_[places]);
            int y = get_rating(specialties[i].enrollees_[places - 1]);
            return x == y ? x + 1 : x;
        }
    }
}

double find_out_the_semi_pass_score(vector <specialty>& specialties, string& specialty_name) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == specialty_name) {
            std::sort(specialties[i].enrollees_.begin(), specialties[i].enrollees_.end());   
            int places = specialties[i].number_of_places_;
            if (specialties[i].enrollees_.size() <= places) {
                return get_rating(specialties[i].enrollees_.back());
            } 
            int x = get_rating(specialties[i].enrollees_[places - 1]);
            return x;
        }
    }
}
void print_enrollees(vector<enrollee>& enrollees, int size_, FILE* output) {
    for (size_t i = 0; i < size_; i++) {
        fprintf(output, "Number in list: %d\n", i + 1);
        fprintf(output, "Name: %s\n", enrollees[i].passport_.full_name_.name.c_str());
        fprintf(output, "Surname: %s\n", enrollees[i].passport_.full_name_.surname.c_str());
        fprintf(output, "Father Name: %s\n", enrollees[i].passport_.full_name_.father_name.c_str());
        fprintf(output, "Total sum: %d\n", get_rating(enrollees[i]));
    }
}
void get_enrollee_rating(vector <specialty>& specialties, FILE* output) {
    vector <enrollee> enrollees;
    for (size_t i = 0; i < specialties.size(); i++) {
        for (size_t j = 0; j < specialties[i].enrollees_.size(); j++) {
            enrollees.push_back(specialties[i].enrollees_[j]);
        }
    }
    std::sort(enrollees.begin(), enrollees.end());
    print_enrollees(enrollees, enrollees.size(), output);
}

void get_a_list_of_applicants(vector <specialty>& specialties, string& specialty_name, FILE* output) {
    for (size_t i = 0; i < specialties.size(); i++) {
        if (specialties[i].specialty_name_ == specialty_name) {
            std::sort(specialties[i].enrollees_.begin(), specialties[i].enrollees_.end());   
            int number_of_applicants = std::min(specialties[i].number_of_places_, (int)specialties[i].enrollees_.size());
            print_enrollees(specialties[i].enrollees_, number_of_applicants, output);
        }
    }
}

void get_specialties_rating(vector <specialty>& specialties, FILE* output) {
    vector <std::pair<double, string>> specialties_rating;
    for (size_t i = 0; i < specialties.size(); i++) {
        int number_of_students = 0;
        double overall_rating = 0;
        for (size_t j = 0; j < specialties[i].enrollees_.size(); j++) {
            number_of_students++;
            overall_rating += get_rating(specialties[i].enrollees_[j]);
        }
        specialties_rating.push_back({overall_rating / number_of_students, specialties[i].specialty_name_});
    }
    std::sort(specialties_rating.begin(), specialties_rating.end());
    for (size_t i = 0; i < specialties_rating.size(); i++) {
        fprintf(output, "Number in rating:%d Name of specialty:%s Rating of specialty:%.4f", i + 1, 
            specialties_rating[i].second.c_str(), specialties_rating[i].first);
    }
}

void get_university_information(vector <specialty>& specialties, FILE* input) {
    int number_of_faculties = get_int(input);
    for (size_t i = 0; i < number_of_faculties; i++) {
        string fac_name = get_string(input);
        int number_of_specialties = get_int(input);
        for (size_t j = 0; j < number_of_specialties; j++) {
            specialty specialty_;
            specialty_.faculty_name_ = fac_name;
            specialty_.specialty_name_ = get_string(input);
            specialty_.number_of_places_ = get_int(input);
            specialties.push_back(specialty_);
        }
    }
} 

void print_menu() {
    printf("1) Apply\n");
    printf("2) Pick up application\n");
    printf("3) Find out the passing score\n");
    printf("4) Find out the semi-passing score\n");
    printf("5) Get enrollee rating\n");
    printf("6) Get a list of applicants\n");
    printf("7) Get specialties rating\n");
}

void processing() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w"); 
    if (input == NULL || output == NULL) {
        exit(-1);
    }
    vector <specialty> specialties;
    get_university_information(specialties, input);
    while(!feof(input)) {
        print_menu();
        int request = get_int(input);
        while (request < 1 && request > 7) {
            request = get_int(input);
        }
        if (request == 1) {
            enrollee student = get_student(input);
            string specialty_ = get_specialty(specialties, input);
            apply(specialties, specialty_, student);
        }
        if (request == 2) {
            full_name student = get_full_name(input);
            string specialty_ = get_specialty(specialties, input);
            pick_up_application(specialties, specialty_, student);
        }
        if (request == 3) {
            string specialty_ = get_specialty(specialties, input);
            fprintf(output, "Passing score is:%.4f\n", find_out_the_passing_score(specialties, specialty_));
        }
        if (request == 4) {
            string specialty_ = get_specialty(specialties, input);
            fprintf(output, "Semi-passing score is:%.4f\n", find_out_the_semi_pass_score(specialties, specialty_));
        }
        if (request == 5) {
            get_enrollee_rating(specialties, output);
        } 
        if (request == 6) {
            string specialty_ = get_specialty(specialties, input);
            get_a_list_of_applicants(specialties, specialty_, output);
        }
        if (request == 7) {
            get_specialties_rating(specialties, output);
        }
    }
    fclose(input);
    fclose(output);
}

int main() {
    processing();
    return 0;
}
