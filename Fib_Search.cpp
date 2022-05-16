#include <iostream>
#include <algorithm>

void sort(int*arr,int size_arr)
{
    for(int i = 0 ; i < size_arr - 1 ; i++){
        for(int j = i + 1 ; j < size_arr ; j++){
            if(arr[i]>arr[j]){
               std::swap(arr[i],arr[j]);
            }  
        }

        
    }

}
void print_arr(int *arr,int size_arr){
  for(int i = 0 ; i < size_arr; i++ ){
        std::cout<<arr[i]<<" ";
    }
}
int fibanachi(int index_of_fibanachi){
    if (index_of_fibanachi<=1){
        return index_of_fibanachi;
    }
    else{
         return fibanachi(index_of_fibanachi - 1) + fibanachi(index_of_fibanachi - 2);
    }
}
int main()
{
    int arr[10]={-2,0,3,5,7,9,11,15,18,21};
    int size = sizeof(arr) / sizeof(arr[0]);
    //print_arr( arr , size );
    //sort(arr,size);
    //print_arr( arr , size );
    
   std::cout<<fibanachi(7);

    
}