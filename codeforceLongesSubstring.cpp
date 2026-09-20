// тоже захотел решить как предыдущую задачу - вложенными переборами
// но решил, что для этой задачи это будет слишком долго, так что принял
// следущее - двигающиеся рамки.
// мы двигаем края рамки: правую вправо, пока не встретим повтор.
// левую ставим на повтор и снова увеличиваем рамку, и так за один проход находим максимальную строку
// для самой рамки unordered_set - т.к. нам важно лишь наличие повторного знака
// а hash-таблица "под капотом" делает все операции бысто

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen_chars;
        int max_len = 0;
        int left = 0;
        int n = s.size();
        for (int right = 0; right < n; right++) {
            while (seen_chars.find(s[right]) != seen_chars.end()) {
                seen_chars.erase(s[left]);
                left++;
            }

            seen_chars.insert(s[right]);

            int current_len = right - left + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }

        return max_len;
    }
};