// https://practice.geeksforgeeks.org/problems/asteroid-collision/1

vector<int> asteroidCollision(int N, vector<int> &asteroids)
{
    // code here
    vector<int> res;
    for (auto &x : asteroids)
    {
        bool destroyed = false;
        while (res.size() && res.back() > 0 && x < 0 && !destroyed)
        {
            if (res.back() >= -x)
                destroyed = true;
            if (res.back() <= -x)
                res.pop_back();
        }
        if (!destroyed)
        {
            res.push_back(x);
        }
    }
    return res;
}