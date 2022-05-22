import javax.xml.transform.Source;

import java.util.Scanner;

public class Main{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args)  { 
       //create a BST object
        BST_class bst = new BST_class(); 

        boolean exit = false;

        while (!exit)
        {
            System.out.println("\n===| Enter Your Choice |===");
            System.out.println("Enter 1 for insert");
            System.out.println("Enter 2 for delete");
            System.out.println("Enter 3 for display");
            System.out.println("Enter 4 for exit");
            System.out.println("Input: ");
            
            int choice = int_input();
            switch (choice)
            {
                case 1: {
                    System.out.println("Enter Number to insert: ");
                    int to_insert = int_input();
                    if (bst.search(to_insert)) {
                        System.out.println("Entered value aldready exists in BST");
                    }
                    else {
                        bst.insert(to_insert);
                        System.out.println("== Element Inserted ==");
                    }
                }break;

                case 2: {
                    System.out.println("Enter Number to delete: ");
                    int to_delete = int_input();
                    if (bst.search(to_delete)) {
                        bst.deleteKey(to_delete);
                        System.out.println("== Element Deleted ==");
                    }
                    else {
                        System.out.println("Entered value does not exist in the BST");
                    }
                }break;

                case 3: {
                    System.out.println("-- Display Function ( inorder ) --");
                    bst.inorder();
                    System.out.println();
                }break;

                case 4: {
                    System.out.println("Thank you");
                    exit = true;
                }break;

                default: {
                    System.out.println("Entered Choice is incorrect. Range (1 - 4)");
                }
            }
        }
     } 

     public static int int_input()
     {
         boolean input_passed = false;
         int inpt = 69; 
 
         while (!input_passed)
         {
             try {
                 inpt = scanner.nextInt();
                 input_passed = true;
             } catch (Exception e) {
                 System.out.println("Wrong input");
                 System.out.println("Reason: " + e);
                 System.out.println("Try again: ");
                 scanner.next();
             }
         }
         return inpt;
     }
}

class BST_class { 
    //node class that defines BST node
    class Node { 
        int key; 
        Node left, right; 
   
        public Node(int data){ 
            key = data; 
            left = right = null; 
        } 
    } 
    // BST root node 
    Node root; 
  
   // Constructor for BST =>initial empty tree
    BST_class(){ 
        root = null; 
    } 
    //delete a node from BST
    void deleteKey(int key) { 
        root = delete_Recursive(root, key); 
    } 
   
    //recursive delete function
    Node delete_Recursive(Node root, int key)  { 
        //tree is empty
        if (root == null)  return root; 
   
        //traverse the tree
        if (key < root.key)     //traverse left subtree 
            root.left = delete_Recursive(root.left, key); 
        else if (key > root.key)  //traverse right subtree
            root.right = delete_Recursive(root.right, key); 
        else  { 
            // node contains only one child
            if (root.left == null) 
                return root.right; 
            else if (root.right == null) 
                return root.left; 
   
            // node has two children; 
            //get inorder successor (min value in the right subtree) 
            root.key = minValue(root.right); 
   
            // Delete the inorder successor 
            root.right = delete_Recursive(root.right, root.key); 
        } 
        return root; 
    } 
   
    int minValue(Node root)  { 
        //initially minval = root
        int minval = root.key; 
        //find minval
        while (root.left != null)  { 
            minval = root.left.key; 
            root = root.left; 
        } 
        return minval; 
    } 
   
    // insert a node in BST 
    void insert(int key)  { 
        root = insert_Recursive(root, key); 
    } 
   
    //recursive insert function
    Node insert_Recursive(Node root, int key) { 
          //tree is empty
        if (root == null) { 
            root = new Node(key); 
            return root; 
        } 
        //traverse the tree
        if (key < root.key)     //insert in the left subtree
            root.left = insert_Recursive(root.left, key); 
        else if (key > root.key)    //insert in the right subtree
            root.right = insert_Recursive(root.right, key); 
          // return pointer
        return root; 
    } 
 
// method for inorder traversal of BST 
    void inorder() { 
        if (root == null) {
            System.out.println("BST is empty");
        }
        else {
            inorder_Recursive(root); 
        }
    } 
   
    // recursively traverse the BST  
    void inorder_Recursive(Node root) { 
        if (root != null) { 
            inorder_Recursive(root.left); 
            System.out.print(root.key + " "); 
            inorder_Recursive(root.right); 
        } 
    } 
     
    boolean search(int key)  { 
        Node check = search_Recursive(root, key);
        if (check != null)
            return true;
        else
            return false;
    } 
   
    //recursive insert function
    Node search_Recursive(Node root, int key)  { 
        // Base Cases: root is null or key is present at root 
        if (root==null || root.key==key) 
            return root; 
        // val is greater than root's key 
        if (root.key > key) 
            return search_Recursive(root.left, key); 
        // val is less than root's key 
        return search_Recursive(root.right, key); 
    } 
}
