#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;

vector<int> convert(string number) {
    vector <int> convert_number;
    for (int i = number.size() - 1; i >= 0; i--) {
        convert_number.push_back(number[i] - '0');
    }
    return convert_number;
}
void remove_leading_zeros(vector<int>& number) {
    while (number.size() > 0 && number.back() == 0) {
        number.pop_back();
    }
    if (number.size() == 0) {
        number.push_back(0);
    }
}
vector<int> subtraction(vector<int> first_number, vector<int> second_number) {
    for (size_t i = 0; i < first_number.size(); i++) {
        if (i < second_number.size()) {
            first_number[i] -= second_number[i];
        }
        if (first_number[i] < 0) {
            first_number[i] += 10;
            first_number[i + 1]--;
        }
    }
    remove_leading_zeros(first_number);
    return first_number;
}
vector<int> multiplication(vector<int> first_number, vector<int> second_number)  {
    vector<int> answer(first_number.size() + second_number.size(), 0);
    for (size_t i = 0; i < first_number.size(); i++) {
        int carry = 0;
        for (size_t j = 0; j < second_number.size() || carry; j++) {
            long long add = 0;
            if (j < second_number.size()) {
                add = 1ll * first_number[i] * second_number[j];
            }
            long long temp = answer[i + j] + add + carry;
            answer[i + j] = temp % 10;
            carry = temp / 10;
        }
    }
    remove_leading_zeros(answer);
    return answer;
}

vector<int> multiplication_by_int(vector<int> number, int mid) {
    vector<int> temp;
    temp.push_back(mid);
    return multiplication(number, temp);
}
bool less_or_equal(vector<int> first_number, vector<int> second_number) {
    if (second_number.size() > first_number.size()) {
        return true;
    }
    if (first_number.size() > second_number.size()) {
        return false;
    }
    for (int i = second_number.size() - 1; i >= 0; i--) {
        if (second_number[i] != first_number[i]) {
            return first_number[i] < second_number[i];
        }
    }
    return true;
}
vector<int> division(vector<int> first_number, vector<int> second_number) {
    vector<int> current;
    string answer;
    for (int i = first_number.size() - 1; i >= 0; i--) {
        current.insert(current.begin(), first_number[i]);
        int l = 0, r = 10;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            vector<int> temp = multiplication_by_int(second_number, mid);

            if (less_or_equal(temp, current)) {
                l = mid;
            }
            else {
                r = mid;
            }

        }
        answer += char(l + '0');
        vector <int> temp = multiplication_by_int(second_number, l);
        current = subtraction(current, temp);
    }
    vector <int> result = convert(answer);
    remove_leading_zeros(result);
    return result;
}
vector<int> remainder_of_the_division(vector<int> first_number, vector<int> second_number) {
    vector <int> temp = division(first_number, second_number);
    temp = multiplication(temp, second_number);
    return subtraction(first_number, temp);
}

bool is_null(vector<int> number) {
    if (number.size() == 1 && number[0] == 0) {
        return true;
    }
    return false;
}
vector<int> solve(string first, string second) {
    vector <int> first_number = convert(first);
    vector <int> second_number = convert(second);

    if (less_or_equal(second_number, first_number)) {
        swap(second_number, first_number);
    }
    while (!is_null(second_number)) {
        first_number = remainder_of_the_division(first_number, second_number);
        swap(first_number, second_number);
    }

    return first_number;
}

bool is_corect(string input) {
    for (size_t i = 0; i < input.size(); i++) {
        if (!(input[i] >= '0' && input[i] <= '9')) {
            return false;
        }
    }
    return true;
}
string read_number() {
    string input;
    std::cin >> input;
    while (!is_corect(input)) {
        std::cout << "Enter a positive number\n";
        char ch;
        while (ch != '\n') {
            std::cin >> ch;
        }
        std::cin >> input;
    }
    return input;
}
int main() {

    std::string first, second;
    std::cout << "Write first number\n";
    first = read_number();
    std::cout << "Write second number\n";
    second = read_number();
    vector <int> ans = solve(first, second);
    std::reverse(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
    }
        
    return 0;
}
