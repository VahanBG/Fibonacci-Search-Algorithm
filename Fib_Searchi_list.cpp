#include <iostream>
#include<vector>
#include<list>
#include <algorithm>

void sort(std::list<int>::iterator it_first,std::list<int>::iterator it_last) //սա դասավորում է զանգվածի ելեմենտները աճման կարգով
{

 while( it_first != it_last)
 {
     int i = 0 ;
    while ( it_last != it_first){

     if(*it_first > *it_last)
     std::iter_swap(it_first , it_last);
     it_last -- ;
     i++;
    }
     std::advance(it_last , i);
     it_first++ ;


}
}
int fibanachi( int index_of_fibanachi ) { //տալիս է ֆիբանաչիի տրված ինդեքսի թիվը
    if ( index_of_fibanachi <= 1 ){
        return index_of_fibanachi;
    }
    else{
         return fibanachi( index_of_fibanachi - 1 ) + fibanachi( index_of_fibanachi - 2 );
    }
}
int fibanachi_search (std::list<int> mylist , int number){// գտնում ենք այն մեր ուզած ֆիբ․թիվը, արդեն սորտավորված զանգվածում և վերադարցնում այդ թվի ինդեքսը
    int size = mylist.size();
    auto it_first = mylist.begin();
    auto it_last = mylist.end();
    it_last --;
    int numfor_search_fib ;// index_of_fibanachi( size );// k
    for(int index = 0 ; index <= size ; ++index ){
        if (fibanachi ( index ) >= size + 1 ){
            numfor_search_fib =  index -1;
        }
    }
    auto numfor_search_fib_iter = mylist.begin();
    std::advance(numfor_search_fib_iter , numfor_search_fib) ;// k   
    
    int index_for_mas = fibanachi( numfor_search_fib +1 ) - ( size + 1 );//m
    auto index_for_mas_iter = mylist.begin();
    std::advance(index_for_mas_iter , index_for_mas) ;// m
    
    int index_for_search = fibanachi( numfor_search_fib ) - index_for_mas ;//i
    auto index_for_search_iter = mylist.begin();
    std::advance(index_for_search_iter , index_for_search) ;//i
   
    int first_value_search = fibanachi( numfor_search_fib - 1 ) ;//p 
    auto first_value_search_iter = mylist.begin();
    std::advance(first_value_search_iter , first_value_search);

    int last_value_search = fibanachi( numfor_search_fib - 2 ) ;//q 
    auto last_value_search_iter = mylist.begin();
    std::advance(last_value_search_iter , last_value_search); //q
    
    bool finish = false ;
    int result_of_fib_search = -1 ;
    
    for( ; !finish ; ){
        if(index_for_search < 0 ){
            if(first_value_search = 1 ){  ////փնտրման միջակայքը հանում է վերև
                        finish = true;
            }
            else{
                    index_for_search += last_value_search ;
                    first_value_search -= last_value_search ;
                    last_value_search -= first_value_search ;
                    //std::advance(index_for_search_iter ,(index_for_search + last_value_search) );//index_for_search += last_value_search ;
                    //std::advance(first_value_search_iter,(first_value_search - last_value_search));//first_value_search -= last_value_search ;
                    //std::advance(last_value_search_iter , (last_value_search - first_value_search));//last_value_search -= first_value_search ;
                    
            }          
        }
        else if( index_for_search >= size ){
                if( last_value_search == 0 ){  //փնտրման միջակայքը իջացնում է ներքև
                   finish = true;
                }
                else{
                std::advance(index_for_search_iter , (index_for_search-last_value_search));//index_for_search -= last_value_search;
                int tmp = last_value_search ;
                last_value_search = first_value_search - last_value_search ;
                first_value_search = tmp ;
                auto tmp1 = last_value_search_iter;
                std::advance(last_value_search_iter , (first_value_search-last_value_search));
                *first_value_search_iter = *tmp1;
                }
        }
        else if (*index_for_search_iter == number){    //( arr[ index_for_search ] == number ){
                result_of_fib_search = index_for_search ;
                break;
        }
        else if  (number < *index_for_search_iter) {//(number < arr[ index_for_search ]){
                if( last_value_search == 0 ){  //փնտրման միջակայքը իջացնում է ներքև
                   finish = true;
                 }
                else{
                std::advance(index_for_search_iter , (index_for_search-last_value_search));//index_for_search -= last_value_search;
                int tmp = last_value_search ;
                last_value_search = first_value_search - last_value_search ;
                first_value_search = tmp ;
                auto tmp1 = last_value_search_iter;
                std::advance(last_value_search_iter , (first_value_search-last_value_search));
                *first_value_search_iter = *tmp1;
                }

        }        
        else if (number > *index_for_search_iter){//( number > arr[ index_for_search ]){
                if(first_value_search = 1 ){  //փնտրման միջակայքը հանում է վերև
                        finish = true;
                }
                else{
                    index_for_search += last_value_search ;
                    first_value_search -= last_value_search ;
                    last_value_search -= first_value_search ;
                    std::advance(index_for_search_iter ,(index_for_search + last_value_search) );//index_for_search += last_value_search ;
                    std::advance(first_value_search_iter,(first_value_search - last_value_search));//first_value_search -= last_value_search ;
                    std::advance(last_value_search_iter , (last_value_search - first_value_search));//last_value_search -= first_value_search ;
                    
                }
        }
    }
     return result_of_fib_search ;
}
void print_list(std::list<int> mylist ){ //տպւմ ենք զանգվածը
  for (auto it_first=mylist.begin(); it_first!=mylist.end(); ++it_first){
    std::cout << ' ' << *it_first;
  }
 std::cout << std::endl;
}

int main()
{
    std::list<int > mylist;
    int size ;
    std::cout << "please enter size of numbers in your array" << std::endl ;
    std::cin >> size ;
    std::cout << "please enter numbers of your array" << std::endl;
    int numbers ;
    for(int i = 0 ; i < size ; i++){// լցնում ենք զանգվածը
         std::cout << "enter value of " << i << " index " << std::endl ;
         std::cin >> numbers;
         mylist.push_back(numbers);
         numbers = 0;
    }
  std::cout << "mylist contains:";
  print_list(mylist);
  std::cout << std::endl;
  std::list<int>::iterator it_first = mylist.begin();
  auto it_last = mylist.end();
  it_last --;
  sort(it_first,it_last);
  std::cout << "mylist contains after sorting :";
  print_list(mylist);
  std::cout << std::endl;
  int number;
  std::cout << "please enter the number which are you search" << std::endl;
  std::cin >> number;
  std::cout<<"the index of number fibanachi which you are looking for in your numbers is: "<<fibanachi_search(mylist,number);

}
      