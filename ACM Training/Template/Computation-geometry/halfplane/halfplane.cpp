#include "../polygon/polygon.cpp"

struct halfplanes
{
    int n;
    Line hp[N], *q[N];
    Vector p[N];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
    }
    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; ++i)
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
        sort(hp, hp + n);
        unique();
        q[st = 0] = &hp[0];
        q[ed = 1] = &hp[1];
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; ++i)
        {
            while (st < ed && hp[i].prelation(p[ed]) < 0)
                --ed;
            while (st < ed && hp[i].prelation(p[st + 1]) < 0)
                ++st;
            q[++ed] = &hp[i];
            if (hp[i].parallel(*q[ed - 1]))
                return false;
            p[ed] = hp[i].crosspoint(*q[ed - 1]);
        }
        while (st < ed && q[st]->prelation(p[ed]) < 0)
            --ed;
        while (st < ed && q[st]->prelation(p[st + 1]) < 0)
            ++st;
        if (st + 1 >= ed)
            return false;
        return true;
    }
    void getconvex(polygon &con)
    {
        p[st] = q[st]->crosspoint(*q[ed]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; ++i, ++j)
            con.p[i] = p[j];
    }
} hp;

int main()
{

    return 0;
}