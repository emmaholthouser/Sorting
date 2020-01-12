//
//  main.cpp
//  Project 4
//
//  Created by Emma Holthouser on 11/19/18.
//  Copyright © 2018 Emma Holthouser. All rights reserved.
//

#include <ctime>
#include <vector>
#include <time.h>
#include <iostream>
#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

//swapping helper function
void swap_help(int *x, int *y)
{
   
    int temp = *x;
    *x = *y;
    *y = temp;
}


void bubbleSort(vector<int>* &list)
{
    
    //going through entire vector and comparing two elements next to each other
    for(int i = 0; i < list->size() -1; i++)
    {
        for(int j = 0; j < list->size() - i -1; j++)
        {
            if(list->at(j) > list->at(j+1))
            {
                swap_help(&list->at(j), &list->at(j+1));
            }
        }
    }
}

void heapSort(vector<int>* list)
{
    Heap<int> heap1(list->size());
    
    //inserting into the heap
    for(int i = 0; i < list->size(); i++)
    {
        heap1.insertElement(list->at(i));
    }
    
    //removing the smallest element
    for(int i = 0; i < list->size(); i++)
    {
        cout << heap1.removeMin() << endl;
        
    }
}

void merge(vector<int>* S1, vector<int>* S2, vector<int>* &S)
{
    

    int i = 0;
    int j = 0;
    
    int n = S1->size() + S2->size();

    //while both have elemetns comparing both lists
    while(i < S1->size() && j < S2->size())
    {
        if(S1->at(i) <= S2->at(j))
        {
            S->at(i+j) = S1->at(i);
            i = i + 1;
        }
        else
        {
            S->at(i+j) = S2->at(j);
            j = j + 1;
        }
    }
    //if one side is finished add the rest of the other to the final array
    while(i < S1->size())
    {
        S->at(i+j) = S1->at(i);
        i++;
    }
    while(j < S2->size())
    {
        S->at(i+j) = S2->at(j);
        j++;
    }
    
    return;
}

void mergeSort(vector<int>* &S)
{
    //if size is less than 1 already sorted
    if(S->size() > 1)
    {
        //creating new vectors to  split
        vector<int>* vect1 = new vector<int>;
        vector<int>* vect2 = new vector<int>;
        int n = S->size();
        
        //halving the original vector
        vector<int>::iterator p;
        p = S->begin();
        for(int i = 0; i < n/2; i++) vect1->push_back(*p++);
        for(int i = n/2; i < n; i++) vect2->push_back(*p++);
        
        //recursion on split vectors
        mergeSort(vect1);
        mergeSort(vect2);
        
        //merging
        merge(vect1, vect2, S);
    }
    return;
}

void inplaceQuick(vector<int>* &list, int a, int b)
{
    if(a >= b)
    {
        return;
    }
    
    int p = list->at(b);
    int l = a;
    int r = b -1;
    //going through whole vector
    while(l <= r)
    {
        //making sure less side is less than pivot
        while(l <= r && list->at(l)<= p)
        {
            l = l + 1;
        }
        //making sure right side is less than pivot
        while(r >= l && list->at(r) >= p)
        {
            r = r -1;
        }
        //comparing left and right and swapping if necessary
        if(l < r)
        {
            swap_help(&list->at(l), &list->at(r));
        }
    }
    //swapping the left and pivot
    swap_help(&list->at(l), &list->at(b));
    
    //recursion on smaller vector
    inplaceQuick(list, a, l-1);
    inplaceQuick(list, l+1, b);
    
}


int main() {
    // insert code here...
    //this was all for testing the different values
    /* srand( static_cast<unsigned int>(time(NULL)));
    
   
    vector<int>* vect1 = new vector<int>;
    vector<int>* vect2 = new vector<int>;
    vector<int>* vect3 = new vector<int>;
    vector<int> output;
    
    for(int i = 0; i < 10000; i++)
    {
        vect1->push_back(i);
    }
    for(int i = 1000; i > 0; i--)
    {
        vect2->push_back(i);
    }
    for(int i = 0; i < 100000; i++)
    {
        vect3->push_back(rand() % 100 + 1);
    }
    const clock_t begin_time = clock();
    inplaceQuick(vect2, 0, vect2->size()-1);
    //bubbleSort(vect2);
   // mergeSort(vect2);
    //heapSort(vect3);
    cout << "Final " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
    for(int i = 0; i < vect2->size(); i++)
    {
        cout << "output" << vect2->at(i) << " ";
    }
    */
    
    string name;
    cout << "name of file";
    cin >> name;
    ifstream t{name};
    
    //I edited the scheme of my xcode project so that I could read in the txt file to test by using the path of the txt file
    //ifstream t{"numbers.txt"};
    
    try {
        
        if(!t.bad())
        {
            //first number
            int alg;
            t >> alg;
            //second number
            int elem;
            t >> elem;
           
            //creating vector
            vector<int>* cvect = new vector<int>;
            for(int i = 0; i < elem; i++)
            {
                int temp;
                t >> temp;
                cvect->push_back(temp);
            }
            
            if(alg == 1)
            {
                bubbleSort(cvect);
                
                for(int i = 0; i < cvect->size(); i++)
                {
                    cout << cvect->at(i) << endl;
                }
            }
            else if(alg == 2)
            {
                heapSort(cvect);
            }
            else if(alg == 3)
            {
                mergeSort(cvect);
                for(int i = 0; i < cvect->size(); i++)
                {
                    cout << cvect->at(i) << endl;
                }
            }
            else if(alg == 4)
            {
                inplaceQuick(cvect, 0, cvect->size()-1);
                for(int i = 0; i < cvect->size(); i++)
                {
                    cout << cvect->at(i) << endl;
                }
            }
            else
            {
                cout << "bad input";
            }
            
        }
        
    } catch (exception) {
        cout << "bad access";
    }
    
    
    
    
    return 0;
}
