#include <stdio.h>
#include <assert.h>
#include <set>
#include <algorithm>
#include <vector>
#include <functional>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

struct Point {
    int position_, height_;
    bool start_;
    Point() : position_(0), height_(0), start_(0) {}
    Point(int position, int height, bool start) : 
        position_(position), height_(height), start_(start) {}
    
    bool operator < (const Point& that) const {
        return position_ < that.position_;
    }
};

int getNum(const char* & input) {
    int num = 0;
    while (input != NULL && *input >= '0' && *input <= '9') {
        num = num * 10 + *input - '0';
        ++input; 
    }
    ++input;
    return num;
}

int resolve(const char* input)
{
    int num = 0;
    num = getNum(input);
    if (num == 0)
        return 0;
        
    std::vector<Point> points;
    for (int i = 0; i < num; ++i) {
        int left = getNum(input);
        int right = getNum(input);
        int height = getNum(input);
        points.push_back(Point(left, height, true));
        points.push_back(Point(right, height, false));
    }
    sort(points.begin(), points.end());
    
    int prev = 0, res = 0;
    std::multiset<int, std::greater<int> > ms;
    for (unsigned int i = 0; i < points.size(); ++i) {
        if (points[i].start_) {
            ms.insert(points[i].height_);
        } else {
            ms.erase(ms.find(points[i].height_));
        }
        
        if (i < points.size() - 1 && points[i].position_ == points[i+1].position_)
            continue;
        int curr = ms.empty() ? 0 : *ms.begin();
        if (curr != prev) {
            res += abs(curr - prev);
            prev = curr;
        } 
    }
    
    res += points.back().position_;
            
    return res;
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}

