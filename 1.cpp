#include <iostream>
#include <string>
#include <vector>

struct Pair{
    uint32_t key;
    uint64_t value;
};

void counting_sort(std::vector<Pair> & pairs, int & min_key, int & max_key){
    if (pairs.empty()) 
        return;

    int cur_key;
    int size = pairs.size();
    const int difka = max_key - min_key + 1;
    std::vector<int> array (difka);
    std::vector<Pair> final_pairs (size);

    for (size_t i = 0; i < size; ++i){
        array[pairs[i].key - min_key] += 1;
    }

    for (size_t i = 1; i < difka; ++i){
        array[i] += array[i-1];
    }

    for (int i = size - 1; i >= 0; --i){
        final_pairs[array[pairs[i].key - min_key]-- - 1] = pairs[i];
    }
    char formattedNumber[7];
    for (auto & pair: final_pairs){ 
        
        std::sprintf(formattedNumber, "%06d", pair.key);
        std::cout << formattedNumber << '\t' << pair.value << "\n";
    }
}

void min_or_max_key(uint32_t & key, int & min_key, int & max_key){
    int cur_key = key;
    if (cur_key < min_key)
        min_key = cur_key;
    if (cur_key > max_key)
        max_key = cur_key;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Pair pair;
    int min_key = 999999, max_key = 0;
    std::vector<Pair> pairs;
    pairs.reserve(10e6);
    while (std::cin >> pair.key >> pair.value){
        if (pair.key < min_key) min_key = pair.key;
        if (pair.key > max_key) max_key = pair.key;
        // min_or_max_key(pair.key, min_key, max_key);
        pairs.emplace_back(pair);
    }
    
    counting_sort(pairs, min_key, max_key);

    return 0;
    
}