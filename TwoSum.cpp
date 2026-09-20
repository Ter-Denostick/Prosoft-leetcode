// решение: наиболее простое и быстрое - 2 вложенных цикла,
// чтобы гарантированно перебрать все пары чисел и проверить их сумму.
// изначально хотел сделать "ленивый" перебор - если число больше target, то скипнуть.
// но чуть позже заметил в ограничених, что числа могут быть отрицательными и убрал

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indicesPair;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indicesPair.push_back(i);
                    indicesPair.push_back(j);
                    return indicesPair;
                }
            }
        }
        return indicesPair;
    }
};
