class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 = [x1, y1, x2, y2]
        // rec2 = [a1, b1, a2, b2]
        return !(rec1[2] <= rec2[0] ||  // rec1 right <= rec2 left
                 rec1[0] >= rec2[2] ||  // rec1 left >= rec2 right
                 rec1[3] <= rec2[1] ||  // rec1 top <= rec2 bottom
                 rec1[1] >= rec2[3]);   // rec1 bottom >= rec2 top
    }
};
