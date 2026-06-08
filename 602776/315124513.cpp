#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool fun(vector<vector<int>> &mas){
    for(int i =1 ; i < mas.size(); i++){
        if(mas.at(i).front() >= mas.at(i-1).back()){

        }else{
        return false;
        }

    }
    return true;
}
int main()
{
    int n ;
    cin >> n;
    vector<int> mas(n);

    for(int &i :  mas){
        cin >> i;
    }
    vector<vector<int>> mas1;
    mas1.push_back({mas.at(0)});
    //int start = 0;
    for(int i = 1 ; i < n ; i++){
        if(mas.at(i) ==  mas.at(i-1)+1){
            mas1.back().push_back(mas.at(i));
        }else{
            mas1.push_back({mas.at(i)});
            //start = i;
        }
    }
    //cout << mas1.size() << "\n";
    if(mas1.size() >5){
        cout << -1;
        return 0;
    }
        if(mas1.size()==1){
        cout << -1;
        return 0;
    }
    if(mas1.size() == 5){
        if(mas1.at(0).back() <= mas1.at(3).front() && mas1.at(3).back() <= mas1.at(2).front() && mas1.at(1).front() >= mas1.at(2).back() && mas1.at(1).back() <= mas1.at(4).front()){
            cout << mas1.at(0).size()+1 << " "<< mas1.at(1).size() << "\n"<< mas1.at(0).size() + mas1.at(1).size() + mas1.at(2).size() +1<< " " << mas1.at(3).size();
            return 0;
           }
        cout << -1;
        return 0;
    }
    if(mas1.size() == 2){
        cout << 1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size()+1 << " " << mas1.at(1).size();
        return 0;
    }
    if(mas1.size() == 3){
        swap(mas1.at(0), mas1.at(1));
        if(fun(mas1)){
            swap(mas1.at(0), mas1.at(1));
            cout <<1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size() +1<< " " << mas1.at(1).size();
            return 0;
        }
        swap(mas1.at(0), mas1.at(1));
        swap(mas1.at(1), mas1.at(2));
        if(fun(mas1)){
            swap(mas1.at(1), mas1.at(2));
            cout <<mas1.at(0).size() +1 << " " << mas1.at(1).size() << "\n" << mas1.at(1).size() + mas1.at(0).size()+1<< " " << mas1.at(2).size();
            return 0;
        }
        swap(mas1.at(1), mas1.at(2));
        swap(mas1.at(0), mas1.at(2));
        if(fun(mas1)){
            swap(mas1.at(0), mas1.at(2));
            cout <<1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size()+ mas1.at(1).size()+1 << " " << mas1.at(2).size();
            return 0;
        }
        cout << -1;
        return 0;
    }
    if(mas1.size() == 4){
        swap(mas1.at(0), mas1.at(1));
        if(fun(mas1)){
                swap(mas1.at(0), mas1.at(1));
            cout <<1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size()+1 << " " << mas1.at(1).size();
            return 0;
        }
        swap(mas1.at(0), mas1.at(1));
        swap(mas1.at(1), mas1.at(2));
        if(fun(mas1)){
            swap(mas1.at(1), mas1.at(2));
            cout <<mas1.at(0).size() +1 << " " << mas1.at(1).size() << "\n" << mas1.at(1).size() + mas1.at(0).size()+1<< " " << mas1.at(2).size();
            return 0;
        }
        swap(mas1.at(1), mas1.at(2));
        swap(mas1.at(0), mas1.at(2));
        if(fun(mas1)){
            swap(mas1.at(0), mas1.at(2));
            cout <<1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size()+ mas1.at(1).size()+1 << " " << mas1.at(2).size();
            return 0;
        }
        swap(mas1.at(0), mas1.at(2));
        swap(mas1.at(0), mas1.at(3));
        if(fun(mas1)){
            swap(mas1.at(0), mas1.at(3));
            cout <<1 << " " << mas1.at(0).size() << "\n" << mas1.at(0).size()+ mas1.at(1).size()+ mas1.at(2).size()+1 << " " << mas1.at(3).size();
            return 0;
        }
        swap(mas1.at(0), mas1.at(3));
        swap(mas1.at(1), mas1.at(3));
        if(fun(mas1)){
            swap(mas1.at(1), mas1.at(3));
            cout <<mas1.at(0).size()+1  << " " << mas1.at(1).size() << "\n" << mas1.at(1).size() + mas1.at(0).size()+ mas1.at(2).size()+1<< " " << mas1.at(3).size();
            return 0;
        }
        swap(mas1.at(1), mas1.at(3));
        swap(mas1.at(2), mas1.at(3));
        if(fun(mas1)){
            swap(mas1.at(2), mas1.at(3));
            cout << mas1.at(0).size()+ mas1.at(1).size() +1<< " " << mas1.at(2).size() << "\n" << mas1.at(0).size()+ mas1.at(1).size() + mas1.at(2).size()+1<< " " << mas1.at(3).size();
            return 0;
        }
        cout << -1;
        return 0;
    }


}
