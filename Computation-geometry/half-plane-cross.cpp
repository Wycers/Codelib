bool Onleft(Line A, poi p) {return cross(A.v, p-A.p) > 0;}
//用叉积判断点是否在直线左边
int HalfplaneIntersection(Line *L,Line *Q,poi *a,poi *out,int cnt)
{
    sort(L,L+cnt);//极角排序
    int head = 0,tail = 0;
    Q[0] = L[0];//双端队列初始化
    for(int i = 1; i < cnt; i++)
    {
        while(head < tail && !Onleft(L[i],a[tail-1])) --tail;//队尾变得无用
        while(head < tail && !Onleft(L[i],a[head])) ++head;//队首变得无用
        Q[++tail] = L[i];
        if(fabs(cross(Q[tail].v,Q[tail-1].v)) < eps){
            --tail;
            if(Onleft(Q[tail],L[i].p)) Q[tail] = L[i];//新的直线是否在原来直线的左边
        }//两向量平行取内侧一个
        if(head < tail) a[tail-1] = GetLineIntersection(Q[tail-1],Q[tail]);//求交点
    }
    while(head < tail && !Onleft(Q[head],a[tail-1])) --tail;//删除无用平面如下图
    if(tail - head <= 1) return 0;//空集
    a[tail] = GetLineIntersection(Q[head],Q[tail]);//首尾两个平面的交点
    int m = 0;
    for(int i = head; i <= tail; i++) out[m++] = a[i];//输出
    return m;
}