#ifndef MAIN_H
#define MAIN_H

#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<int> solve(string first, string second);
vector<int> convert(string number);
void remove_leading_zeros(vector<int>& number);
vector<int> subtraction(vector<int> first_number, vector<int> second_number);
vector<int> multiplication(vector<int> first_number, vector<int> second_number);
vector<int> multiplication_by_int(vector<int> number, int mid);
bool less_or_equal(vector<int> first_number, vector<int> second_number);
vector<int> division(vector<int> first_number, vector<int> second_number);
vector<int> remainder_of_the_division(vector<int> first_number, vector<int> second_number);
bool is_null(vector<int> number);
bool is_corect(string input);



#endif
