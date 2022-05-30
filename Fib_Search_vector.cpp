#include <iostream>
#include <vector>
#include <algorithm>

int fibanachi(int index_of_fibanachi)
{
	//gives the index number given by Fibanacci
	if (index_of_fibanachi <= 1)
	{
		return index_of_fibanachi;
	}
	else
	{
		return fibanachi(index_of_fibanachi - 1) + fibanachi(index_of_fibanachi - 2);
	}
}
int fibanachi_search(std::vector<int> arr, int number)
{
	// find the fiber we want in the already sorted array, return the index of that number
	int numfor_search_fib = 0;
	while (!(fibanachi(numfor_search_fib) >= arr.size() + 1))
	{
		numfor_search_fib++;
	}
	numfor_search_fib--;
	int index_for_mas = fibanachi(numfor_search_fib + 1) - (arr.size() + 1);	//M allows you to spread the search to any size
	int index_for_search = fibanachi(numfor_search_fib) - index_for_mas;	// i need to determine search domains
	int first_value_search = fibanachi(numfor_search_fib - 1);	//p 
	int last_value_search = fibanachi(numfor_search_fib - 2);	//q 
	bool finish = false;
	int result_of_fib_search = -1;
	for (; !finish;)
	{
		if (index_for_search < 0)
		{
			//5
			if (first_value_search == 1)
			{
				////removes the search range
				finish = true;
			}
			else
			{
				index_for_search += last_value_search;
				first_value_search -= last_value_search;
				last_value_search -= first_value_search;
			}
		}
		else if (index_for_search >= arr.size())
		{
			//4
			if (last_value_search == 0)
			{
				//reduces the search range
				finish = true;
			}
			else
			{
				index_for_search -= last_value_search;
				int tmp = last_value_search;
				last_value_search = first_value_search - last_value_search;
				first_value_search = tmp;
			}
		}
		if (arr[index_for_search] == number)
		{
			result_of_fib_search = index_for_search;
			break;
		}
		else if (number < arr[index_for_search])
		{
			if (last_value_search == 0)
			{
				// 4	// Reduces the search range
				finish = true;
			}
			else
			{
				index_for_search -= last_value_search;
				int tmp = last_value_search;
				last_value_search = first_value_search - last_value_search;
				first_value_search = tmp;
			}
		}
		else if (number > arr[index_for_search])
		{
			if (first_value_search == 1)
			{
				// 5	// removes the search range
				finish = true;
			}
			else
			{
				index_for_search += last_value_search;
				first_value_search -= last_value_search;
				last_value_search -= first_value_search;
			}
		}
	}

	return result_of_fib_search;

}
void print_arr(std::vector<int> arr, int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	int size;
	std::cout << "please enter size of numbers in your array" << std::endl;
	std::cin >> size;
	std::cout << "please enter numbers of your array" << std::endl;
	std::vector<int> myVector;
	int numbers;
	for (int i = 0; i < size; i++)
	{
		std::cout << "enter value of " << i << " index " << std::endl;
		std::cin >> numbers;
		myVector.push_back(numbers);
		numbers = 0;
	}
	std::sort(myVector.begin(), myVector.end());
	std::cout << "your array after sorting : " << std::endl;
	print_arr(myVector, size);
	int number;
	std::cout << "please enter the number which are you search" << std::endl;
	std::cin >> number;
	if (fibanachi_search(myVector, number) != -1)
	{
		std::cout << "the number index in your arr is : " << fibanachi_search(myVector, number);
	}
	else
	{
		std::cout << "the number which you are serarching not in your arr";
	}
}