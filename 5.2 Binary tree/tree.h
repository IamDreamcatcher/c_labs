#ifndef TREE_H
#define TREE_H

#include <vector>

class tree{
    private:
        struct node{
            int key;
            node* left;
            node* right;
            unsigned char height;
            node(int value) {
                key = value;
                left = right = nullptr;
                height = 1;
            }
        };
        node* Root;
        size_t size;

        unsigned char height(node* cur){
            return cur ? cur -> height : 0;
        }
        int bfactor(node* cur){
            return height(cur -> right) - height(cur -> left);
        }
        void fixheight(node* cur){
            unsigned char hl = height(cur -> left);
            unsigned char hr = height(cur -> right);
            cur -> height = (hl > hr ? hl : hr) + 1;
        }

        node* rotateright(node* cur){
            node* child = cur -> left;
            cur -> left = child -> right;
            child -> right = cur;
            fixheight(cur);
            fixheight(child);
            return child;
        }
        node* rotateleft(node* cur){
            node* child = cur -> right;
            cur -> right = child -> left;
            child -> left = cur;
            fixheight(cur);
            fixheight(child);
            return child;
        }

        node* balance(node* cur){
            fixheight(cur);
            if(bfactor(cur) == 2){
                if(bfactor(cur -> right) < 0){
                    cur -> right = rotateright(cur -> right);
                }
                return rotateleft(cur);
            }
            if(bfactor(cur) == -2){
                if(bfactor(cur -> left) > 0){
                    cur -> left = rotateleft(cur -> left);
                }
                return rotateright(cur);
            }
            return cur;
        }

        node* findmin(node* cur) {
            return cur -> left ? findmin(cur -> left) : cur;
        }
        node* removemin(node* cur) {
            if(cur -> left == 0) {
                return cur -> right;
            }
            cur -> left = removemin(cur -> left);
            return balance(cur);
        }
        node* insert(node* cur, int value) {
            if (!cur) {
                size++;
                return new node(value);
            }
            if (value < cur -> key) {
                cur -> left = insert(cur -> left, value);
            }
            else {
                cur -> right = insert(cur -> right, value);
            }
            return balance(cur);
        }
        node* erase(node* cur, int value) {
            if(!cur) {
                return 0;
            }
            if(value < cur -> key) {
                cur -> left = erase(cur -> left, value);
            }
            else if(value > cur -> key) {
                cur -> right = erase(cur -> right, value);
            }
            else {
                size--;
                node* q = cur -> left;
                node* r = cur -> right;
                delete cur;
                if(!r){
                    return q;
                }
                node* min = findmin(r);
                min -> right = removemin(r);
                min -> left = q;
                return balance(min);
            }
            return balance(cur);
        }
        node* remove_negative_numbers(node* cur) {
            if (cur -> left != nullptr) {
                cur -> left = remove_negative_numbers(cur -> left);
            }
            if (cur -> right != nullptr) {
                cur -> right = remove_negative_numbers(cur -> right);
            }
            if (cur -> key < 0) {
                cur = erase(cur, cur -> key);
            }
            return cur;
        }
        void to_vector(node* cur, std::vector <int>& vec){
            if (cur -> left != nullptr) {
                to_vector(cur -> left, vec);
            }
            vec.push_back(cur -> key);
            if (cur -> right != nullptr) {
                to_vector(cur -> right, vec);
            }
        }
    public:
        tree() {
            Root = nullptr;
        }
        void insert(int value) {
            Root = insert(Root, value);
        }
        void erase(int value) {
            Root = erase(Root, value);
        }
        size_t get_size() {
            return size;
        }
        void remove_negative_numbers() {
            Root = remove_negative_numbers(Root);
        }
        void to_vector(std::vector<int>& vec){
            to_vector(Root, vec);
        }
};

#endif
