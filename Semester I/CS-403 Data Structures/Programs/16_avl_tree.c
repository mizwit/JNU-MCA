/*
Problem 1: Insert 14, 17, 11, 7, 53, 4, 13, 12, 8 into an empty AVL tree. Draw the tree after every inspection, naming each rotation case used.
Problem 2: In the final tree of Problem 1, delete 53 and 4. Show the tree after each deletion and state the case (if any).
Problem 3: (a) What is the fewest number of nodes in an AVL tree of height 6? (b) What is the largest possible height of an AVL tree with 30 nodes? (c) Insert 1, 2, 3, ..., 7 in order: how many rotations occur?
*/

/*
AVL Tree:
1. Insert 14, 17, 11, 7, 53, 4, 13, 12, 8 into an empty AVL tree. Print the tree after
   every insertion and name the rotation case used.
2. In the final tree of Task 1, delete 53 and 4. Print the tree after each deletion and
   state the case (if any).
3. (a) Fewest number of nodes in an AVL tree of height 6.
   (b) Largest possible height of an AVL tree with 30 nodes.
   (c) Insert 1, 2, 3, ..., 7 in order: count the rotations.

Height is counted in edges (a single node has height 0, an empty tree has height -1).
Balance Factor (BF) = height(left subtree) - height(right subtree).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 120


// Define a struct representing a node of an AVL tree.
struct Node
{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};


// Function to get the height of a node (-1 for an empty subtree).
int get_height(struct Node *node)
{
    return (node == NULL) ? -1 : node->height;
}


// Function to recalculate the height of a node from its children.
void update_height(struct Node *node)
{
    int left = get_height(node->left);
    int right = get_height(node->right);
    node->height = 1 + ((left > right) ? left : right);
}


// Function to get the balance factor of a node.
int get_balance(struct Node *node)
{
    return get_height(node->left) - get_height(node->right);
}


// Function to create a new node.
struct Node *create_node(int key)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }
    new_node->key = key;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


// Function to rotate right around 'y'. Returns the new root of this subtree.
struct Node *rotate_right(struct Node *y, int *rotations)
{
    struct Node *x = y->left;
    y->left = x->right;
    x->right = y;
    update_height(y);
    update_height(x);
    (*rotations)++;
    return x;
}


// Function to rotate left around 'x'. Returns the new root of this subtree.
struct Node *rotate_left(struct Node *x, int *rotations)
{
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    update_height(x);
    update_height(y);
    (*rotations)++;
    return y;
}


// Function to fix a node whose balance factor is +2 or -2 (used by both insert and delete).
// The case is decided by the balance factor of the taller child.
struct Node *rebalance(struct Node *node, int *rotations)
{
    update_height(node);
    int balance = get_balance(node);

    if (balance > 1)
    {
        int left_balance = get_balance(node->left);
        if (left_balance < 0)
        {
            printf(">> Imbalance at node %d: LR case (left rotation, then right rotation)\n", node->key);
            node->left = rotate_left(node->left, rotations);
        }
        else
        {
            printf(">> Imbalance at node %d: LL case (right rotation)%s\n", node->key,
                   (left_balance == 0) ? " [R0 case, only possible on deletion]" : "");
        }
        return rotate_right(node, rotations);
    }

    if (balance < -1)
    {
        int right_balance = get_balance(node->right);
        if (right_balance > 0)
        {
            printf(">> Imbalance at node %d: RL case (right rotation, then left rotation)\n", node->key);
            node->right = rotate_right(node->right, rotations);
        }
        else
        {
            printf(">> Imbalance at node %d: RR case (left rotation)%s\n", node->key,
                   (right_balance == 0) ? " [L0 case, only possible on deletion]" : "");
        }
        return rotate_left(node, rotations);
    }

    return node;
}


// Function to insert a key into the AVL tree. Returns the new root of this subtree.
struct Node *insert_node(struct Node *node, int key, int *rotations)
{
    if (node == NULL)
    {
        return create_node(key);
    }
    if (key < node->key)
    {
        node->left = insert_node(node->left, key, rotations);
    }
    else if (key > node->key)
    {
        node->right = insert_node(node->right, key, rotations);
    }
    else
    {
        return node;   // duplicate keys are ignored
    }
    return rebalance(node, rotations);
}


// Function to delete a key from the AVL tree. Returns the new root of this subtree.
struct Node *delete_node(struct Node *node, int key, int *rotations)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (key < node->key)
    {
        node->left = delete_node(node->left, key, rotations);
    }
    else if (key > node->key)
    {
        node->right = delete_node(node->right, key, rotations);
    }
    else if (node->left == NULL || node->right == NULL)
    {
        // Zero or one child: replace the node with that child.
        struct Node *child = (node->left != NULL) ? node->left : node->right;
        free(node);
        return child;
    }
    else
    {
        // Two children: copy the inorder successor's key, then delete the successor.
        struct Node *successor = node->right;
        while (successor->left != NULL)
        {
            successor = successor->left;
        }
        node->key = successor->key;
        node->right = delete_node(node->right, successor->key, rotations);
    }
    return rebalance(node, rotations);
}


// Function to draw one node (and its subtree) on the canvas. Every node gets its own column,
// in inorder order, so no two nodes overlap. Returns the column of this node (-1 if empty).
int draw_node(struct Node *node, int row, int *next_col, char canvas[ROWS][COLS])
{
    if (node == NULL)
    {
        return -1;
    }
    int left_col = draw_node(node->left, row + 2, next_col, canvas);
    int col = 4 * (*next_col);
    (*next_col)++;
    int right_col = draw_node(node->right, row + 2, next_col, canvas);

    char label[12];
    sprintf(label, "%d", node->key);
    for (int i = 0; label[i] != '\0'; i++)
    {
        canvas[row][col + i] = label[i];
    }

    // Branch line below the node: .----'----.
    if (left_col != -1)
    {
        canvas[row + 1][left_col] = '.';
        for (int c = left_col + 1; c < col; c++)
        {
            canvas[row + 1][c] = '-';
        }
    }
    if (right_col != -1)
    {
        canvas[row + 1][right_col] = '.';
        for (int c = col + 1; c < right_col; c++)
        {
            canvas[row + 1][c] = '-';
        }
    }
    if (left_col != -1 || right_col != -1)
    {
        canvas[row + 1][col] = '\'';
    }
    return col;
}


// Function to print the tree from the top down (supports up to about 29 nodes).
void print_tree(struct Node *root)
{
    if (root == NULL)
    {
        printf(">> (empty tree)\n");
        return;
    }
    char canvas[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        memset(canvas[i], ' ', COLS - 1);
        canvas[i][COLS - 1] = '\0';
    }

    int next_col = 0;
    draw_node(root, 0, &next_col, canvas);

    for (int i = 0; i <= 2 * root->height; i++)
    {
        int end = COLS - 2;
        while (end >= 0 && canvas[i][end] == ' ')
        {
            end--;
        }
        canvas[i][end + 1] = '\0';
        printf(">> %s\n", canvas[i]);
    }
}


// Function to insert a key and print the result.
void insert_and_print(struct Node **root, int key, int *rotations)
{
    int before = *rotations;
    printf(">> \n>> Inserting %d:\n", key);
    *root = insert_node(*root, key, rotations);
    if (*rotations == before)
    {
        printf(">> No rotation needed.\n");
    }
    print_tree(*root);
}


// Function to delete a key and print the result.
void delete_and_print(struct Node **root, int key, int *rotations)
{
    int before = *rotations;
    printf(">> \n>> Deleting %d:\n", key);
    *root = delete_node(*root, key, rotations);
    if (*rotations == before)
    {
        printf(">> No imbalance, so no rotation needed.\n");
    }
    print_tree(*root);
}


// Function to find the fewest nodes in an AVL tree of height h.
// N(h) = N(h-1) + N(h-2) + 1, with N(-1) = 0 and N(0) = 1.
int min_nodes(int h)
{
    if (h < 0)
    {
        return 0;
    }
    if (h == 0)
    {
        return 1;
    }
    return min_nodes(h - 1) + min_nodes(h - 2) + 1;
}


// Function to find the largest possible height of an AVL tree with n nodes.
int max_height(int n)
{
    int h = 0;
    while (min_nodes(h + 1) <= n)
    {
        h++;
    }
    return h;
}


int main()
{
    struct Node *root = NULL;
    int rotations = 0;
    printf("\n\n");

    printf("TASK 1: Insert 14, 17, 11, 7, 53, 4, 13, 12, 8 into an empty AVL tree\n");
    printf("-------\n");
    int keys[9] = {14, 17, 11, 7, 53, 4, 13, 12, 8};
    for (int i = 0; i < 9; i++)
    {
        insert_and_print(&root, keys[i], &rotations);
    }
    printf("\n\n");

    printf("TASK 2: Delete 53 and 4 from the final tree of Task 1\n");
    printf("-------\n");
    delete_and_print(&root, 53, &rotations);
    delete_and_print(&root, 4, &rotations);
    printf("\n\n");

    printf("TASK 3: AVL tree questions\n");
    printf("-------\n");
    printf(">> (a) Fewest nodes in an AVL tree of height 6: %d\n", min_nodes(6));
    printf(">> (b) Largest possible height of an AVL tree with 30 nodes: %d\n", max_height(30));
    printf(">> (c) Inserting 1, 2, 3, ..., 7 in order:\n");
    struct Node *seq_root = NULL;
    int seq_rotations = 0;
    for (int key = 1; key <= 7; key++)
    {
        seq_root = insert_node(seq_root, key, &seq_rotations);
    }
    print_tree(seq_root);
    printf(">> Total rotations: %d\n", seq_rotations);
    printf(">> \n");
    printf(">> (Heights are counted in edges. If your class counts a single node as height 1,\n");
    printf(">> the answers to (a) and (b) become 20 and 6.)\n");
    printf("\n\n");

    return 0;
}