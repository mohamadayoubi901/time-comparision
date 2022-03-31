/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mohamad ayoubi
 *
 * Created on 21 February 2022, 21:34
 */


#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <vector>
#include <iostream>

using namespace std;

/*
 * #include <time.h> 
 */


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*  purpose:  swap two element
    precondition:none
    post-condition: the two pointers are swapped with each other
 */

vector<int> fillvector(vector<int> a, int n) {
    srand(time(0));
    int max_value = (n * 2 - 1);
    for (int i = 0; i < n; i++)
        a.push_back(rand() % (max_value)); //add  random number in the vector
    return a;
}

/*  purpose:  insert random element in a vector
    precondition:number of element to be insert;
    post-condition: a filled vector with random integer is returned
 */

vector<int> bubbleSort(vector<int> a, int n) {


    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j > n - 1 - i; j--)
            if (a[j] > a[j - 1])//check if the previous value is smaller
                swap(a[j], a[j - 1]); //swap the 2 element

    return a;
}

/*  purpose:  sort the element in a vector using bubble sort algorithm
    precondition:the number of element in the vector;
    post-condition: a sorted vector is returned
 */

int firstalgorithm(vector<int> a, int n, int k) {
    a = bubbleSort(a, n); //sort the vector
    return a[k - 1]; //return the kth element;
}

/*  purpose:  sort the element in a vector using bubble sort algorithm and 
    return the kth element;
    precondition:the number of element in the vector, the number of the kth 
    element;
    post-condition: value of the kth order is returned
 */

int secondalgorithm(vector<int> a, int n, int k) {

    vector<int> firstHalf;

    //read the first half of the elements into an array
    for (int i = 0; i < k; i++) {
        firstHalf.push_back(a[i]);
    }
    //sort the first half of the elements in decreasing order
    firstHalf = bubbleSort(firstHalf, k);

    for (int i = k; i < n; i++) {
        int val = a[i];

        //check If the new element to insert is >= the kth largest
        if (val > firstHalf[k - 1]) {
            int pos = 0;
             //search for its right position;
            for (; pos < k - 1; pos++) {
                if (val > firstHalf[pos]) {
                    break; //I break once I have the correct position located
                }
            }
            //I make the swap
            for (int j = k - 1; j > pos; j--)
                firstHalf[j] = firstHalf[j - 1];
            firstHalf[pos] = val;

        }
    }
    //return the kth element
    return firstHalf[k - 1];
}

/*  purpose:  sort half the element in a vector using bubble sort algorithm and 
    then check rest one by one then return the kth element;
    precondition:the number of element in the vector, the number of the kth 
    element;
    post-condition: value of the kth order is returned
 */

int main(int argc, char** argv) {
    vector<int> a;
    cout << "N    Method  TIME(in millisecond)" << endl;

    for (int i = 1000; i <= 10000; i = i + 1000) {
        int n = i;
        int k = n / 2;
        //save the time before adding elements the vector and sorting them
        clock_t start_time = clock();
        a = fillvector(a, n); //add elements
        //use the first algorithm and get the kth element
        int b = firstalgorithm(a, n, k);
        //save the time after adding elements the vector and sorting them
        clock_t end_time = clock();
        clock_t result = end_time - start_time; //calculate the time different
        cout << n << "      " << 1 << "      " << result << endl;
        a.clear(); //clear the vector;
        //save the time before adding elements the vector and sorting them
        clock_t start_time1 = clock();
        a = fillvector(a, n); //add elements
        //use the second algorithm and get the kth element
        int d = secondalgorithm(a, n, k);
        //save the time after adding elements the vector and sorting them
        clock_t end_time1 = clock();
        clock_t result1 = end_time1 - start_time1; //calculate the time different
        cout << n << "      " << 2 << "      " << result1 << endl;
        a.clear(); //clear the vector;
    }


    return 0;
}

