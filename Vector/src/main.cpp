#include<iostream>
#include"vector.hpp"

int main(){
    Vector <char> t;
    t.push_back('G');
    t.push_back('O');
    t.push_back('R');
    t.pop_back();
    t.pop_back();
    t.push_back('R');
    std::cout<<t[1]<<std::endl;
    // t.pop_back();
    t.show();
    Vector <int> arr{1, 2, 3, 4, 5, 8, 9};
    Vector <int> ppp{1, 2, 3, 4, 5, 9};
    if(arr == ppp){
        std::cout<<"True arrays are equal"<<std::endl;
    }else{
        std::cout<<"False"<<std::endl;
    }
    Vector <int> am;
    am = arr;
    am.show();
    Vector <int>aii{1, 2, 3, 4, 5, 8, 9};
    aii.push_back(43);
    aii.push_back(43);
    aii.push_back(43);
    
    std::cout<<"Pop are called"<<std::endl;
      aii.pop_back();
      aii.pop_back();
      aii.pop_back();
      aii.pop_back();
      std::cout<<aii.capacity()<<std::endl;
      aii.pop_back();
      aii.pop_back();
      aii.pop_back();
      aii.pop_back();

     std::cout<<aii.capacity()<<std::endl;
  

      aii.show();
      aii.clear();
      aii.show();
      aii.push_back(43);
      aii.show();
      std::cout<<aii.empty()<<std::endl;
      aii.clear();
      std::cout<<aii.empty()<<std::endl;

     std::cout<<aii.capacity()<<std::endl;
     std::cout<<aii.size()<<std::endl;
  
    aii.push_back(43);
    aii.push_back(43);
    aii.push_back(43);
    aii.push_back(43);
    Vector <int> g(arr);
    g.show();



    return 0;
}


