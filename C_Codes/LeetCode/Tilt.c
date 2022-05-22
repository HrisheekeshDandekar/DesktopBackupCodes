void add_all(struct TreeNode* root, int* sum);
void tilts_all_recursive(int* tot_sum, struct TreeNode* root);
int sub_tree_sum(struct TreeNode* root);

int findTilt(struct TreeNode* root)
{
    int tot_sum = 0;
    tilts_all_recursive(&tot_sum, root);
    return tot_sum;
}

void tilts_all_recursive(int* tot_sum, struct TreeNode* root)
{
    if (!root)
    {
        return;
    }
    
    tilts_all_recursive(tot_sum, root->left);
    tilts_all_recursive(tot_sum, root->right);
    
    int left_val = 0; 
    int right_val = 0;

    if (root->left)
    {
        if (root->right)
        {
            left_val = sub_tree_sum(root->left);
            right_val = sub_tree_sum(root->right);
        }
        else
        {
            left_val = sub_tree_sum(root->left);
        }
    }
    else if (root->right)
    {
        right_val = sub_tree_sum(root->right);
    }

    int diff = left_val - right_val;    
    if (diff < 0)
    {
        diff *= -1;
    }
    *tot_sum = *tot_sum + diff;

}

int sub_tree_sum(struct TreeNode* root)
{
    int sum = 0;
    if (root)
    {
        add_all(root, &sum);
    }
    return sum;
}

void add_all(struct TreeNode* root, int* sum)
{
    if (root->left)
    {
        add_all(root->left, sum);
    }
    if (root->right)
    {
        add_all(root->right, sum);
    }
    *sum = *sum + root->val;
}