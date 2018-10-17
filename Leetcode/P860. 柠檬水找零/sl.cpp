class Solution
{
  public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (int i = 0, len = bills.size(); i < len; ++i)
        {
            if (bills[i] == 20)
            {
                if (ten && five)
                    --ten, --five;
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
            else if (bills[i] == 10)
            {
                if (five)
                    --five;
                else
                    return false;
                ++ten;
            }
            else 
            {
                ++five;
            }
        }
        return true;
    }
};