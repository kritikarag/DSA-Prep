// https://leetcode.com/problems/gas-station/description/

We know if we run out of fuel say at some ith gas station. 
All the gas station between ith and starting point are bad starting point as well.
So, this means we can start trying at next gas station on the i + 1 station

Just to add some insight as to why just checking (total_surplus < 0) ? -1 : start is sufficient at the end to get the start index.

So, we are resetting start as soon as surplus dips below 0 and setting it to the next index. 
Lets say the last update to start index was at index k where 0 <= k < n (length of the array);

At the end of the iteration, surplus contains the total amount of fuel collected from the last updated start index till the end of tha array
surplus = (gas[k] - cost[k]) + (gas[k + 1] - cost[k + 1]) + ... + (gas[n - 1] - cost[n - 1])

This surplus must be able to offset the net fuel consumption before the kth index so that we are able to circle back and finish at the index k.
Net Fuel Consumption Before k = (gas[0] - cost[0]) + (gas[1] - cost[1]) + ... + (gas[k - 1] - cost[k - 1])

Now, totalSurplus contains the total fuel collected from the 0th to the (n-1)th index
total_surplus = (gas[0] - cost[0]) + (gas[1] - cost[1]) + ... (gas[n - 1] - cost[n -1]);

What this means is Net Fuel Consumption Before k = total_surplus - surplus.

This implies that if (surplus + total_surplus - surplus) >= 0 then the current start is the correct answer
==> (totalSurplus >= 0) ? start : -1

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
