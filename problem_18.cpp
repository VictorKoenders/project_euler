#include "time_utils.h"
#include "number_utils.h"
#include "string_utils.h"
#include <vector>
#include <fstream>

class Tree {
public:
    std::vector<std::vector<uint8_t>> layers;
    std::vector<uint64_t> find_highest_sum() const{
        // we need to flatten the tree from the bottom-up
        // while still remembering where the original positions of the numbers were

        // This is the highest value of the current layer and everything below it
        std::vector<uint64_t> layer;
        const auto& last_layer = this->layers.back();
        layer.reserve(last_layer.size());
        for(uint8_t item : last_layer){
            layer.push_back(static_cast<uint64_t>(item));
        }

        // This is the path of highest value for each item in the current list
        // We're at the bottom layer so we don't have anything yet
        std::vector<std::vector<uint64_t>> pathes;
        pathes.resize(layer.size(), std::vector<uint64_t>());

        for(size_t i = 0; i <= this->layers.size() - 2; i++){
            // For each item in this layer:
            // Check which of the two children has the largest value
            // update this value with the 
            auto index = this->layers.size() - i - 2;
            const auto& current_layer = this->layers[index];

            for(uint64_t position = 0; position < current_layer.size(); position++){
                uint64_t current_value = current_layer[position];
                uint64_t left = layer[position];
                uint64_t right = layer[position + 1];


                if(left >= right) {
                    // We keep the path from the left branch
                    // And we add our current position for left
                    pathes[position].push_back(position);
                    // And we set our new value
                    layer[position] = current_value + left;
                } else {
                    // We copy the path from the right branch
                    pathes[position] = pathes[position + 1];
                    // And we add position+1 for right
                    pathes[position].push_back(position + 1);
                    // And we set our new value
                    layer[position] = current_value + right;
                }
            }
        }

        return pathes[0];
    }
};

Tree get_tree_from_file(){
    std::ifstream file;
    file.open("problem_18_input.txt");
    if(!file) {
        std::cout << "Could not open \"problem_18_input.txt\"" << std::endl;
        exit(-1);
    }
    char line[256];
    Tree result;
    while(file.getline(line, 256)) {
        auto numbers = split(line, ' ');
        if(numbers.size() == 0) continue;
        std::vector<uint8_t> layer;
        for(auto number : numbers){
            layer.push_back(atoi(number.c_str()));
        }
        result.layers.push_back(layer);
    }
    return result;
}

int main(){
    measure_time([]{
        Tree tree = get_tree_from_file();
        // tree.layers.push_back({3});
        // tree.layers.push_back({7, 4});
        // tree.layers.push_back({2, 4, 6});
        // tree.layers.push_back({8, 5, 9, 3});
        for(auto layer : tree.layers) {
            for(uint8_t val : layer) {
                std::cout << static_cast<uint32_t>(val) << " ";
            }
            std::cout << std::endl;
        }

        auto path = tree.find_highest_sum();
        std::cout << "Path size: " << path.size() << std::endl;
        uint64_t sum = static_cast<uint64_t>(tree.layers[0][0]);
        for(uint8_t index = 0; index < path.size(); index++){
            uint64_t value = static_cast<uint64_t>(tree.layers[tree.layers.size() - index - 1][path[index]]);
            std::cout << static_cast<uint64_t>(path[index] + 1) << ": " << value << std::endl;
            sum += value;
        }
        std::cout << "0: " << static_cast<uint64_t>(tree.layers[0][0]) << std::endl;
        std::cout << "Sum is " << sum << std::endl;
    });
}