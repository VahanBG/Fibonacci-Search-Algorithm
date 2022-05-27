#include <iostream>
#include<vector>
#include <algorithm>


int fibanachi( int index_of_fibanachi ) { //տալիս է ֆիբանաչիի տրված ինդեքսի թիվը
    if ( index_of_fibanachi <= 1 ){
        return index_of_fibanachi;
    }
    else{
         return fibanachi( index_of_fibanachi - 1 ) + fibanachi( index_of_fibanachi - 2 );
    }
}
int index_of_fibanachi( int size_of_arr ){  //վերադարցնում է ֆիբոնաչիի այն էլէմենտի արժեքը + 1,որը ">=" է զանգվածի չափից + 1
    int index = 0;
    while(!(fibanachi(index) >= size_of_arr +1)){
        index ++ ;
    }
  
    return index-1 ;     

}
int fibanachi_search (std::vector<int> arr ,  int number){// գտնում ենք այն մեր ուզած ֆիբ․թիվը, արդեն սորտավորված զանգվածում և վերադարցնում այդ թվի ինդեքսը
    int numfor_search_fib = index_of_fibanachi( arr.size() );//k
    int index_for_mas = fibanachi( numfor_search_fib +1 ) - ( arr.size() + 1 );//M թույլ է տալիս տարածել փնտրումը ցանկացած զանգվածի չափով
    int index_for_search = fibanachi( numfor_search_fib ) - index_for_mas ; // i պետք է փնտրման տիրույթները որոշելու համար
    int first_value_search = fibanachi( numfor_search_fib - 1 ) ;//p 
    int last_value_search = fibanachi( numfor_search_fib - 2 ) ;//q 
    bool finish = false ;
    int result_of_fib_search = -1 ;
    for( ; !finish ; ){
        if(index_for_search < 0 ){ //5
            if(first_value_search = 1 ){  ////փնտրման միջակայքը հանում է վերև
                        finish = true;
            }
            else{
                    index_for_search += last_value_search ;
                    first_value_search -= last_value_search ;
                    last_value_search -= first_value_search ;
                    
            }
        }    
        else if( index_for_search >= arr.size() ){ //4
                if( last_value_search == 0 ){  //փնտրման միջակայքը իջացնում է ներքև
                   finish = true;
                 }
                else{
                index_for_search -= last_value_search;
                int tmp = last_value_search ;
                last_value_search = first_value_search - last_value_search ;
                first_value_search = tmp ;
                }
        }
         if( arr[ index_for_search ] == number ){
                result_of_fib_search = index_for_search ;
                break;
        }        
        else if(number < arr[ index_for_search ]){
                if( last_value_search == 0 ){  //4//փնտրման միջակայքը իջացնում է ներքև
                    finish = true;
                 }
                else{
                index_for_search -= last_value_search;
                int tmp = last_value_search ;
                last_value_search = first_value_search - last_value_search ;
                first_value_search = tmp ;
               
                }

        }
        else if( number > arr[ index_for_search ]){
                if(first_value_search == 1 ){ //5 //փնտրման միջակայքը հանում է վերև
                        finish = true;
                }
                else{
                    index_for_search += last_value_search;
                    first_value_search -= last_value_search ;
                    last_value_search -= first_value_search ;
                   
                }
        }
        
    }
    
   return result_of_fib_search ;

}
void print_arr( std::vector <int> arr , int size_arr ){ //տպւմ ենք զանգվածը
  for(int i = 0 ; i < size_arr ; i++ ){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int size ;
    std::cout << "please enter size of numbers in your array" << std::endl ;
    std::cin >> size ;
    std::cout << "please enter numbers of your array" << std::endl;
    std::vector <int> myVector;
    int numbers ;
    for(int i = 0 ; i < size ; i++){// լցնում ենք զանգվածը
         std::cout << "enter value of " << i << " index " << std::endl ;
         std::cin >> numbers;
         myVector.push_back(numbers);
         numbers = 0;
    }
     std::sort( myVector.begin(), myVector.end() );
    std::cout << "your array after sorting : " << std::endl;
    print_arr(myVector,size);
    int number;
    std::cout << "please enter the number which are you search" << std::endl;
    std::cin >> number;
   if( fibanachi_search( myVector , number) != -1){
    std::cout << "the number index in your arr is : " << fibanachi_search(myVector , number); 
    }
    else{
    std::cout<<"the number which you are serarching not in your arr";
   
    }
     
}
    
