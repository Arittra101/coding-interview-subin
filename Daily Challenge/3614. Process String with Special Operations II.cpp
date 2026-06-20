//challenge: memory limit exceeded

class Solution
{
public:
    char processStr(string s, long long k)
    {
        long long int l = 0;
        for (auto it : s)
        {
            if (it == '*')
            {
                if (l)
                    l -= 1;
            }
            else if (it == '#')
            {
                l *= 2;
            }
            else if (it == '%')
            {
                continue;
            }
            else
            {
                l += 1;
            }
        }

        if (k >= l)
        {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];

            if (c == '*')
            {
                l++;
            }

            else if (c == '#')
            {
                long long half = l / 2;
                if (k >= half)
                {
                    k = (k - half);
                }
                l = half;
            }

            else if (c == '%')
            {
                k = l - k - 1;
            }
            else
            {
                if (k == l - 1)
                    return c;
                l--;
            }
        }
        return '.';
    }
};

// https://leetcode.com/problems/process-string-with-special-operations-ii/?envType=daily-question&envId=2026-06-17