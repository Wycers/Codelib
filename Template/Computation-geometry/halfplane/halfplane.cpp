#include "../polygon/polygon.cpp"

const int LN = 10;
struct halfplane
{
    int n;
    Line hp[LN];
    Vector p[LN];
    int que[LN];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
    }
    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; i++)
        {
            if (sign(hp[i].ag - hp[i - 1].ag) != 0)
                hp[m++] = hp[i];
            else if (sign((hp[m - 1].e - hp[m - 1].s) ^ (hp[i].s - hp[m - 1].s)) > 0)
                hp[m - 1] = hp[i];
        }
        n = m;
    }
    bool halfplaneinsert()
    {
        for (int i = 0; i < n; i++)
            hp[i].calangle();
        sort(hp, hp + n);
        unique();
        que[st = 0] = 0;
        que[ed = 1] = 1;
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; i++)
        {
            while (st < ed && sign((hp[i].e - hp[i].s) ^ (p[ed] - hp[i].s)) < 0)
                ed--;
            while (st < ed && sign((hp[i].e - hp[i].s) ^ (p[st + 1] - hp[i].s)) < 0)
                st++;
            que[++ed] = i;
            if (hp[i].parallel(hp[que[ed - 1]]))
                return false;
            p[ed] = hp[i].crosspoint(hp[que[ed - 1]]);
        }
        while (st < ed && sign((hp[que[st]].e - hp[que[st]].s) ^ (p[ed] - hp[que[st]].s)) < 0)
            ed--;
        while (st < ed && sign((hp[que[ed]].e - hp[que[ed]].s) ^ (p[st + 1] - hp[que[ed]].s)) < 0)
            st++;
        if (st + 1 >= ed)
            return false;
        return true;
    }
    void getconvex(polygon &con)
    {
        p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; i++, j++)
            con.p[i] = p[j];
    }
};

int main()
{

    return 0;
}