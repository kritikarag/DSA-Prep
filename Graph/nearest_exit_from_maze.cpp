int nearestExit(vector<vector<char>> &maze, vector<int> &e)
{
    queue<pair<int, int>> q;
    q.push({e[0], e[1]});
    // current moves
    int moves = 1;
    int rows = maze.size();
    int cols = maze[0].size();

    // to move in all directions
    vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // mark the entrance  as visited
    maze[e[0]][e[1]] = '+';
    while (!q.empty())
    {
        int l = q.size();
        // for every node in the queue visit all of it's adjacent nodes which are not visited yet
        for (int k = 0; k < l; k++)
        {
            auto [i, j] = q.front();
            q.pop();

            // try all 4 directions from the current cell
            for (int l = 0; l < 4; l++)
            {
                int x = i + offsets[l][0];
                int y = j + offsets[l][1];
                // a invalid move
                if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '+')
                    continue;
                // if we have reached the exit then current moves are the min moves to reach the exit
                if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1)
                    return moves;
                // block the cell as we have visited
                maze[x][y] = '+';
                q.push({x, y});
            }
        }
        // increment the moves
        moves++;
    }
    return -1;
}