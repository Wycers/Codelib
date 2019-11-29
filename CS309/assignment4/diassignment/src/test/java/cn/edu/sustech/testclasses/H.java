package cn.edu.sustech.testclasses;

import cn.edu.sustech.Inject;

public class H {

    public H(D dDep) {
        this.dDep = dDep;
    }

    public C getCDep() {
        return cDep;
    }

    public D getDDep() {
        return dDep;
    }

    @Inject
    private C cDep;

    private D dDep;


}
