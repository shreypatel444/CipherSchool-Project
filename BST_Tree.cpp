#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    TreeNode* search(int key) {
        return searchRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }

        return node;
    }

    TreeNode* deleteRec(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->key) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* searchRec(TreeNode* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return searchRec(node->left, key);
        }

        return searchRec(node->right, key);
    }

    void inorderRec(TreeNode* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    void preorderRec(TreeNode* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void postorderRec(TreeNode* root) {
        if (root != nullptr) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->key << " ";
        }
    }
};

int main() {
	
	cout<<"Welcome to my BST program!!!"<<endl;
	
    BinarySearchTree bst;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. In-order Traversal\n";
        cout << "4. Pre-order Traversal\n";
        cout << "5. Post-order Traversal\n";
        cout << "6. Delete\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int n;
                cout<<"How many nodes do you want to insert ?: ";
                cin>>n;
                for(int i=0;i<n;i++){
                	int j;
                	cout<<"Enter the node which you want to insert: ";
                	cin>>j;
                	bst.insert(j);
            	}
                break;

            case 2:
                cout << "Enter key you want to search: ";
                cin >> key;
                if (bst.search(key) != nullptr) {
                    cout << "Found node with key: " << key << endl;
                } else {
                    cout << "Node with key " << key << " not found." << endl;
                }
                break;

            case 3:
                cout << "In-order traversal: ";
                bst.inorder();
                break;

            case 4:
                cout << "Pre-order traversal: ";
                bst.preorder();
                break;

            case 5:
                cout << "Post-order traversal: ";
                bst.postorder();
                break;

            case 6:
                cout << "Enter the node which you want to delete: ";
                cin >> key;
                bst.deleteNode(key);
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}