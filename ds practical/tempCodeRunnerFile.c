
int main() {
    Node* root = create(1);
    root->left = create(5);
    root->right = create(3);
    root->left->left = create(2);
    root->left->right = create(4);
getLeafCount(root);