#include <iostream>
#include <vector>
#include <algorithm>


int getSetSize(){
	int size{0};//set can't really be smaller than two
	std::cout << "How large does the set of numbers need to be?:";
	std::cin >> size;
	return size;
}

bool allSumsDistinct(int val, std::vector<int>& cache){

	std::vector<int> newCacheVals={val};
	for(int i{0};i<cache.size();i++){
		newCacheVals.push_back(val+cache[i]);
	}
	for (const int& num : cache) {
        	if (std::find(newCacheVals.begin(), newCacheVals.end(), num) != newCacheVals.end()) {
            		return false;
		}
        }
	//only occurs if this function returns true
	cache.insert(std::end(cache), std::begin(newCacheVals), std::end(newCacheVals));
	return true;
	       	       
}


int main(){
	std::vector<int> set={1,3};//seed set with first two elements
	std::vector<int> sumsCache={1,3,4};//cache of all sums

	int setSize{getSetSize()};
	for(int i{5};set.size()<setSize;i++){
		if(allSumsDistinct(i,sumsCache)){
			set.push_back(i);
		}
	}
	for(int element : set){
		std::cout << element << " ";
	}
	return 0;
	
}
