// Փնտրում ենք մեր ուզած էլեմնտը,
//եթե առկա է զանգվածում ՝ վերադարցնում ենք ինդեքսը, եթե ոճ ՝ -1 ։
#include<iostream>
#include<vector>
#include <algorithm>
void sort ( std::vector<int>::iterator arr , int size_arr )
{
    for(int i = 0 ; i < size_arr - 1 ; i++){
        for( int j = i + 1 ; j < size_arr ; j++){
            if( arr[i] > arr[j] ) {
               std::swap ( arr[i] , arr[j] ) ;
            }
        }
    }
}

int search_binar(std::vector<int>::iterator arr,int size,int number){
    int first_index = 0 ; //pntrvox arachin element
    int last_index = size - 1 ;//pntrvox verchin element
    while( first_index <= last_index ){
        int middle = first_index + (last_index - first_index)/2 ;
        if(number < arr[middle]){
            last_index = middle - 1 ;
        }
        else if (number > arr[middle]){
            first_index = middle + 1 ;
        }
        else{
            return middle;
        }
    }
          return -1 ;
}

void print_arr ( std::vector<int>::iterator arr , int size_arr){
  for( int i = 0 ; i < size_arr; i++ ){
        std::cout << arr[i] << " " ;
    }
}



int main()
{
     //int arr[]= {2,5,7,45,18,13,78,65,12,44};
     int size;// = sizeof(arr) / sizeof(arr[0]);
     std::cout<<"please enter size of numbers in your array"<<std::endl;
     std::cin >> size ;
     std::cout<<"please enter numbers of your array"<<std::endl;
     std::vector <int> myVector;
     int numbers ;
     for(int i = 0 ; i < size ; i++){
         std::cout<<"enter value of "<< i << " index " <<std::endl ;
         std::cin>> numbers;
         myVector.push_back(numbers);
         numbers = 0 ;
     }
     int number;
     std::cout<<"please enter the number which are you search"<<std::endl;
     std::cin>>number;
     //if(search(arr,size,number) != -1){
     //std::cout<<"the number index in your arr is : "<<search(arr,size,number); 
     //
     //else{std::cout<<"the number which you are serarching not in your arr";}
     std::vector<int>::iterator it;
     it = myVector.begin();
     sort(it,size);
     print_arr(it,size);//tpum e zangvac@
     //std::cout<<search_binar(myVector,size,number);
     
     
}
