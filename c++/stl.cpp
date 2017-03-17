#include <iostream>
#include <string>
#include <unordered_map>

int main(void)
{
    std::unordered_map<std::string, int> workers = {
        { "rafael", 23 },
        { "torvalds", 28 },
        { "chris", 25 },
        { "paul", 20 }
    };

    for (const auto& w : workers) {
        printf("%s\t%3d\n", w.first.data(), w.second);
    }

    return 0;
}
