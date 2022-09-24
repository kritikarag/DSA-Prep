// https://leetcode.com/problems/flood-fill/

void dfs(vector<vector<int>> &image, int sr, int sc, int color, int val)
{
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != val)
    {
        return;
    }
    image[sr][sc] = color;

    dfs(image, sr + 1, sc, color, val);
    dfs(image, sr - 1, sc, color, val);
    dfs(image, sr, sc + 1, color, val);
    dfs(image, sr, sc - 1, color, val);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, color, val);
    return image;
}