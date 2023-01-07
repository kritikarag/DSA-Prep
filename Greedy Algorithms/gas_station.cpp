// https://leetcode.com/problems/gas-station/description/

we know if we run out of fuel say at some ith gas station. 
All the gas station between ith and starting point are bad starting point as well.
So, this means we can start trying at next gas station on the i + 1 station

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total_surplus = 0, curr_surplus = 0, start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total_surplus += gas[i] - cost[i];
        curr_surplus += gas[i] - cost[i];

        if (curr_surplus < 0)
        {
            curr_surplus = 0;
            start = i + 1;
        }
    }

    return (total_surplus < 0) ? -1 : start;
}
