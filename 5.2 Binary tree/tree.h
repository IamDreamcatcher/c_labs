#ifndef TREE_H
#define TREE_H

#include <vector>

class tree{
    private:
        struct node{
            int key;
            node* left;
            node* right;
            node(int value) {
                key = value;
                left = right = nullptr;
            }
        };
        node* Root;
        size_t size;

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
            return cur;
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
                return min;
            }
            return cur;
        }
        node* remove_negative_numbers(node* root) {
            if (root -> left != nullptr) {
                root -> left = remove_negative_numbers(root -> left);
            }
            if (root -> right != nullptr) {
                root -> right = remove_negative_numbers(root -> right);
            }
            if (root -> key < 0) {
                root = erase(root, root -> key);
            }
            return root;
        }
        void to_vector(node* cur, std::vector <int>& vec){
            if (cur -> left != nullptr){
                to_vector(cur -> left, vec);
            }
            vec.push_back(cur -> key);
            if (cur -> right != nullptr){
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
        node* findmin(node* cur) {
            return cur -> left ? findmin(cur -> left) : cur;
        }
        node* removemin(node* cur) {
            if(cur -> left == 0) {
                return cur -> right;
            }
            cur -> left = removemin(cur -> left);
            return cur;
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
