#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Initializationg of list
    cout << "============================================" << endl;
    cout << "Initialization:" << endl;
    list<int> l1;
    list<int> l2 = {1, 2, 3, 4};
    list<int> l3(5, 10); // 5 elements with value 10

    cout << endl;
    cout << "============================================" << endl;
    cout << "Empty function:" << endl;
    if (l1.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Size function:" << endl;
    cout << "Size: " << l2.size() << endl;

    cout << endl;
    cout << "============================================" << endl;
    cout << "Front and Back Function" << endl;
    cout << "Front: " << l2.front() << endl;
    cout << "Back: " << l2.back() << endl;

    cout << endl;
    cout << "============================================" << endl;
    cout << "Inserting from front: push_back()" << endl;
    l2.push_front(-1);
    l2.push_front(0);

    cout << "Inserting from back: ";
    l2.push_back(5);
    l2.push_back(6);

    cout << " " << endl;
    for (auto val : l2)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Deleting from front: pop_front()" << endl;
    l2.pop_front();
    l2.pop_front();

    cout << "Deleting from back: pop_back()" << endl;
    l2.pop_back();
    l2.pop_back();

    cout << endl;
    for (auto val : l2)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Insert Function:" << endl;
    cout << "Insert single element:" << endl;
    list<int> l4 = {10, 20, 40};
    auto it = l4.begin();
    advance(it, 2);    // points to 40
    l4.insert(it, 30); // Insert 30 before 40
    // l4.insert(l4.begin()+2,25);  W e cannot move the pointer in list by adding number to iterate we need advance function
    for (int x : l4)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Insert a single element at the begining(equivalent to push_front()):" << endl;
    l4.insert(l4.begin(), 5);

    cout << endl;
    cout << "Insert a single element at the end(equivalent to the push_back()):" << endl;
    l4.insert(l4.end(), 45);
    for (auto val : l4)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "Insert Multiple copies of same value:" << endl;
    auto it1 = l4.begin();
    advance(it1, 2);
    l4.insert(it1, 3, 25);
    for (auto val : l4)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Insert a Range of elements:" << endl;
    list<int> l5 = {1, 2, 6};
    list<int> l6 = {3, 4, 5};
    auto it2 = l5.begin();
    advance(it2, 2);
    // Syntax : list.insert(position, first_iterator, last_iterator);
    l5.insert(it2, l6.begin(), l6.end());
    for (auto val : l5)
    {
        cout << val << " ";
    }

    cout << endl;
    list<int> l7 = {1, 5};
    auto it3 = l7.begin();
    advance(it3, 1);
    l7.insert(it3, {2, 3, 4});
    for (auto val : l7)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Erase function:" << endl;
    cout << "Erase a single element:" << endl;
    list<int> l8 = {1, 2, 3, 7, 4, 5, 6};
    auto it4 = l8.begin();
    advance(it4, 3);
    l8.erase(it4);
    for (int val : l8)
    {
        cout << val << " ";
    }
    cout << endl;
    list<int> l10 = {1, 2, 3, 100, 4, 5, 6, 7, 8, 100, 9, 10, 100};

    // After erase, I already moved forward — after no erase, I must move manually.
    for (auto it5 = l10.begin(); it5 != l10.end();)
    {
        if (*it5 == 100)
        {
            it5 = l10.erase(it5);
        }
        else
        {
            ++it5;
        }
    }

    for (auto val : l10)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "Erase a range of elements:" << endl;
    list<int> l9 = {10, 20, 20, 20, 20, 30};
    auto first_it = l9.begin();
    auto last_it = l9.begin();
    advance(first_it, 1);
    advance(last_it, 4);
    l9.erase(first_it, last_it);
    for (int val : l9)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Clear function:" << endl;
    list<int> l11 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l11.clear();
    cout << "Size: " << l11.size() << endl;

    cout << endl;
    cout << "============================================" << endl;
    cout << "Remove(value) function" << endl;
    cout << "Remove(value) function: This function removes every ocurence of value from the list" << endl;
    list<int> l12 = {1, 2, 3, 2, 4, 2, 5};
    l12.remove(2);
    for (auto val : l12)
    {
        cout << val << " ";
    }

    // How remove works internally?
    // for (auto it = begin(); it != end();)
    // {
    //     if (*it == value)
    //         it = erase(it);
    //     else
    //         ++it;
    // }

    cout << "remove_if(predicate) function : list::remove_if(predicate) removes every element for which predicate(element) returns true." << endl;
    list<int> l13 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    // Remove all the even numebers from the list
    l13.remove_if([](int x)
                  { return x % 2 == 0; });

    for (auto val : l13)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Unique function" << endl;
    cout << "Unique function: unique() removes all duplicate elements that are adjacent to each other, leaving only the first occurrence.";
    list<int> l14 = {1, 1, 2, 2, 2, 3, 1, 1};
    l14.unique();
    for (int x : l14)
    {
        cout << x << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Sort function:" << endl;
    list<int> l15 = {4, 1, 3, 2};
    l15.sort();
    for (auto val : l15)
    {
        cout << val << " ";
    }
    cout << endl;

    l15.sort([](int a, int b)
             { return a > b; });

    for (auto val : l15)
    {
        cout << val << " ";
    }

    cout << endl;
    cout << "============================================" << endl;
    cout << "Merge function:" << endl;
    list<int> l16 = {1, 3, 5};
    list<int> l17 = {2, 4, 5, 6};
    l16.merge(l17);

    for (auto val : l16)
    {
        cout << val << " ";
    }

       cout << endl;
    cout << "============================================" << endl;
    cout<<"Splice function:"<<endl;
    cout<<"Splice entire list"<<endl;
    list<int> l18={1,2,3};
    list<int> l19={4,5,6};
    //Syntax splice :- dest.splice(pos,src)
    auto it18=l18.begin();
    advance(it18,1);
    l18.splice(it18,l19);

    for(auto val:l18){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"Size of l19: "<<l19.size()<<endl;

    cout<<"Splice one element"<<endl;
    //Syntax : dest.splice(pos,src,it)

    list<int> l20={1,2,3};
    list<int> l21={4,5,6};
    auto it20=l20.begin();
    advance(it20,2);
    auto it21=l21.begin();
    advance(it21,1);
    l20.splice(it20,l21,it21);

    for(auto val:l20){
        cout<<val<<" ";
    }

    cout<<endl;
    cout<<"Splice Range"<<endl;

    list <int> l22={1,2,3};
    list <int> l23={4,5,6,7,8,9};
    //Syntax : dest.splice(pos,src,first_itr,last_itr);
    auto it22=l22.begin();
    advance(it22,1);

    auto first_itr=l23.begin();
    auto last_itr=l23.end();
    advance(first_itr,2);

    l22.splice(it22,l23,first_itr,last_itr);
    for(auto val:l22){
        cout<<val<<" ";
    }

    cout<<endl;
    for(auto val:l23){
        cout<<val<<" ";
    }
    return 0;
}