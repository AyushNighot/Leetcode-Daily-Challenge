class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int res = 0, v1ptr = 0, v2ptr = 0, n1 = 0, n2 = 0,
        sz1 = version1.length(), sz2 = version2.length();
        while (v1ptr < sz1 or v2ptr < sz2)
        {
            n1 = n2 = 0;
            while (v1ptr < sz1 and version1[v1ptr] != '.')
            {
                n1 = n1 * 10 + (version1[v1ptr] - '0');
                v1ptr++;
            }
            while (v2ptr < sz2 and version2[v2ptr] != '.')
            {
                n2 = n2 * 10 + (version2[v2ptr] - '0');
                v2ptr++;
            }
            if (n1 < n2) { return -1; }
            else if (n1 > n2) { return 1; }
            v1ptr++; v2ptr++;
        }
        return 0;
    }
};
