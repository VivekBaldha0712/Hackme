class RabinKarp
{
private:
    const int p = 31;
    int hashOfNeedle;
    vi prefix;
    vi powers;

public:
    RabinKarp(string& hay, string& need)
    {
        prefix.resize(hay.size());
        powers.resize(hay.size());
        hashOfNeedle = 0;

        makeNeedleHash(need);
        makeHayPrefix(hay);

    }

    void makeNeedleHash(string& s)
    {
        int power = 1;

        For(i, 0, sz(s))
        {
            int val = s[i] - '0' + 1;
            int middle = mod_mul(power, val, MOD);
            hashOfNeedle = mod_add(hashOfNeedle, middle, MOD);
            power = mod_mul(power, p, MOD);

        }

    }

    void makeHayPrefix(string& s)
    {
        int power = 1;

        For(i, 0, sz(s))
        {
            int val = s[i] - '0' + 1;
            int middle = mod_mul(power, val, MOD);
            prefix[i] = middle;

            if(i > 0)
                prefix[i] = mod_add(prefix[i - 1], middle, MOD);

            powers[i] = power;
            power = mod_mul(power, p, MOD);

        }

    }

    bool isMatch(int l, int r)
    {
        int cur = prefix[r];

        if(l > 0)
            cur = mod_sub(cur, prefix[l - 1], MOD);

        int newNeedle = mod_mul(hashOfNeedle, powers[l], MOD);

        return newNeedle == cur;

    }
};
