// https://leetcode.com/problems/valid-square/description/

int squaredis(vector<int> &point1, vector<int> &point2)
{
    return pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2);
}

bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    vector<vector<int>> points = {p1, p2, p3, p4};
    sort(points.begin(), points.end());
    int side1 = squaredis(points[0], points[1]);
    int side2 = squaredis(points[0], points[2]);
    int side3 = squaredis(points[1], points[3]);
    int side4 = squaredis(points[2], points[3]);

    int diag1 = squaredis(points[0], points[3]);
    int diag2 = squaredis(points[1], points[2]);

    return (side1 && side2 && (side1 == side2) && (diag1 == diag2));
}