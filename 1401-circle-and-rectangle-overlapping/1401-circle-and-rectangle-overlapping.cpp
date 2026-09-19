class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        // Clamp circle center to rectangle boundaries
        int px = max(x1, min(xCenter, x2));
        int py = max(y1, min(yCenter, y2));
        
        // Compute squared distance
        long long dx = xCenter - px;
        long long dy = yCenter - py;
        
        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};
