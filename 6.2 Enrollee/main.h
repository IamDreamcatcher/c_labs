#ifndef MAIN_H
#define MAIN_H

#include "enrollee.h"

void apply(vector <specialty>& specialties, string my_specialty, enrollee& enrollee_);
void pick_up_application(vector <specialty>& specialties, string& my_specialty, full_name& enrollee_);
double find_out_the_passing_score(vector <specialty>& specialties, string& specialty_name);
double find_out_the_semi_pass_score(vector <specialty>& specialties, string& specialty_name);
void print_enrollees(vector<enrollee>& enrollees, int size_, FILE* output);
void get_enrollee_rating(vector <specialty>& specialties, FILE* output);
void get_a_list_of_applicants(vector <specialty>& specialties, string& specialty_name, FILE* output);
void get_specialties_rating(vector <specialty>& specialties, FILE* output);
void get_university_information(vector <specialty>& specialties, FILE* input);
void print_menu();
void processing();

#endif
