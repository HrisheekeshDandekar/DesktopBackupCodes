package com.hri.clg.ads.lab1;

import java.util.Scanner;

import javax.print.attribute.standard.RequestingUserName;

import java.util.*;

public class BinarySearchTree {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        //Taking input for number of elements

        BST.inorder();
    }

    public void choice_delete()
    {
        System.out.println("Enter the element you want to delete: ");
        int to_delete = int_input();

    }

    public void delete(int to_delete)
    {
        
    }

    public void choice_insert(int tot_inserts)
    {
        int tot_nums = -1;
        while (tot_nums < 1)
        {
            System.out.println("Enter the number of inputs for the binary tree:");
            tot_nums = int_input();
            if (tot_nums < 1) {
                System.out.println("Enter a positive integer");
            }
        }
        
        for (int i = 0; i < tot_nums; i++)
        {
            int inp = int_input();
            BST.insert(inp);
        }

    }

    public void insert(int insert_num) 
    {

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

public class Node {
    int val;
    Node left;
    Node right;
}