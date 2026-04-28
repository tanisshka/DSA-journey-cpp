#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    double weight;
    int value;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double FractionalKnapsack(vector<Item>& items, int W){
    sort(items.begin(), items.end(), cmp);

    double totalVal = 0;

    for(auto item : items){
        if(item.weight <= W){
            totalVal += item.value;
            W -= item.weight;
        } else {
            double fraction = (double)W / item.weight;
            totalVal += item.value * fraction;
            break;
        }
    }
    return totalVal;
}

int main(){
    int n, W;
    cout<<"Enter Total Items: ";
    cin >> n;

    cout<<"Enter Capacity: ";
    cin>>W;

    vector<Item> items;

    for (int i = 0; i < n; i++){
        Item temp;
        cout<<"Enter  value and weight for Item "<<i+1<<" : ";
        cin >> temp.value >> temp.weight;
        items.push_back(temp);
    }

    cout << FractionalKnapsack(items, W);
}