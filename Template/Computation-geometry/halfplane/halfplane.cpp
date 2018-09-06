#include "../polygon/polygon.cpp"

struct halfplane
{
    int n;
    Line hp[N], *q[N];
    Vector p[N];
    int st, ed;
    void push(Line tmp)
    {
        hp[n++] = tmp;
    }
    void halfplaneinsert()
    {
        sort(hp, hp + n);
        q[st = ed = 0] = &hp[0];
        for (int i = 1; i < n; i++)
        {
            while (st < ed && hp[i].prelation(p[ed - 1]) != 1)
                --ed;       //Remove the top of the half plane
            while (st < ed && hp[i].prelation(p[st]) != 1)
                ++st;      //Remove the bottom half plane
            q[++ed] = &hp[i]; //The half plane current if the double ended queue at the top.
            if (sign(q[ed]->v ^ q[ed - 1]->v) == 0)
            { //For the polar angle the same, selective retention of a.
                --ed;
                if ((*q[ed]).prelation(hp[i].s) == 1)
                    q[ed] = &hp[i];
            }
            if (st < ed)
                p[ed - 1] = (*q[ed - 1]).crosspoint(*q[ed]); //Calculation of the top of the queue half plane intersection.
        }
        while (st < ed && (*q[st]).prelation(p[ed - 1]) != 1)
            --ed; //Remove the top of the queue of useless half plane.
        if (ed - st <= 1)
            return;
        p[ed] = (*q[ed]).crosspoint(*q[st]); //The top of the queue and the first intersection calculation.
    }
    bool getconvex(polygon &res)
    {
        res.n = ed - st + 1;
        if (ed - st <= 1)
            return false;                                   //Half plane degradation
        for (int i = st; i <= ed; i++)
            res.p[i - st] = p[i]; //The queue of point.
        return true;
    }
};

int main()
{

    return 0;
}