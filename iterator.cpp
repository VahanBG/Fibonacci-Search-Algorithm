//իտերատորներ, լինում են 5 տեսակ,input , forword , bidirectional,random access , constiguous
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

int main(){
typedef std::vector <int> vi;
vi v;
for(int i = 0 ; i < 15 ; i++){ //լցնում ենք վեկտորը
    v.push_back(i);
}
// forward iterator
std::cout<<"forward iterator";
for( auto it = v.begin() ; it != v.end() - 7 ; it ++ ){
    *it *= 10 ; 
    std::cout<<", "<<*it ;
    }
std::cout<<std::endl;

// Backward iterator
std::cout<<"Backward iterator";
for( auto it = v.rbegin() ; it != v.rend() - 7 ; it ++ ){
    *it *= 10 ; 
    std::cout<<", "<<*it ;
    }
std::cout<<std::endl;

// const iterator, 
std::cout<<"const iterator";
for( auto it = v.cbegin() ; it != v.cend() - 7 ; it ++ ){
   // *it *= 10 ; չի կարելի փոխել error
    std::cout<<", "<<*it ;
    }
std::cout<<std::endl;


//iterator operations
    
//Advance , այն տեղափոխում է իտերատորի էլէմենտները որոծակի միջակայքով
//կա  prev(  ,  ) , next(  ,  ) , մեկը աջ, մեկը ձախ
 
 {
     auto it = v.begin();
     std::advance(it , 10 ) ;//տեղաշարժում է աջ 10 նիշով
     std::cout<< * it <<std::endl;
     std::advance( it , -5) ;//տեղաշարժում է ձախ 5 նիշով
     std::cout<< * it <<std::endl;
 }

// Distance , երկու էլեմենտների հեռավորությունը
{
    auto it = v.begin();
    auto it2 = v.end();
    std::cout<<"Dist: " <<std::distance(it , it2)<<std::endl;
}

//Iter_swap 
{
    auto it = v.begin();
    auto it2 = v.end()-1;
    std::iter_swap(it , it2);
    std::cout<< "Iter_swap : " << *it << " | " << *it2 << std::endl;

}
 
//Iterator generators

//Back_inserter r front_inserter , գւոմարում է մի վեկտորը մյուսի վեռչին

{
    std::vector<int> foo,bar;
    for(int i = 1 ; i < 5 ; i++ ){
        foo.push_back(i);
        bar.push_back(i*10);
    }
    std::copy (bar.begin(),bar.end(),std::back_inserter(foo));
    std::cout<<"Back_inserter: ";
    for(int n: foo){
        std::cout<<n<<", ";
    }
    std::cout<<std::endl;
}

// inserter , ընդունում է կոնտեներ, որտեղ պետք է դնի , և ինչ պետք է դնի
{
std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
std::fill_n(std::inserter(v,v.begin()),3,-1);// տեղադրում է էլեմենտները համապատասխան ինդեքսի տակ
std::cout<<"Inserter: ";
for(int n: v){
    std::cout<<n<<", ";
}
std::cout<<std::endl;
}

//Make_move_iterator տեղափոխում է մի կոնտեների եղածը մյուսի մեջ
{
    std::vector<std::string> s{"one","two","three"};
    std::vector<std::string> v1(s.begin(),s.end());//copy
    std::vector<std::string> v2(std::make_move_iterator(s.begin()),std::make_move_iterator(s.end()));
    std::cout<<"v1 now holds: ";
    for(auto str: v1){
        std::cout<<str<<", ";
    }
    std::cout<< std::endl <<"v2 now holds: ";
    for(auto str : v2){
        std::cout<<str<<", ";
    }
    std::cout<<std::endl<<"original vector now holds: ";
    for(auto str : s){
        std::cout<<str<<", ";
    }
    std::cout<<std::endl;
}

}