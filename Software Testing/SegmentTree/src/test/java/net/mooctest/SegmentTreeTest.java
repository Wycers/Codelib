package net.mooctest;

import org.junit.Test;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class SegmentTreeTest {

    @Test
    public void st() {

        SegmentTree.Data data = new SegmentTree.Data.QuadrantData(0, 1, 0, 0, 0);
        data.clear();
        assertEquals(Long.MIN_VALUE, data.start);
        assertEquals(Long.MAX_VALUE, data.end);

        SegmentTree.Data data1 = new SegmentTree.Data.QuadrantData(1, 2, 0, 0, 0);
        data.combined(data1);
        assertEquals("-9223372036854775808->9223372036854775807 2,0,0,0", data.toString());
    }

    @Test
    public void st_combine() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<Integer>(0, 1, 1);
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<Integer>(1, 2, -1);
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1, 1]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<Integer>(0, 1, 1);
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<Integer>(1, 2, -1);
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<Integer>(0, 1, 1);
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<Integer>(1, 2, -1);
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<Integer>(0, 1, 1);
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<Integer>(1, 2, -1);
        rs1.combined(rs2);
        assertEquals("0->1 sum=0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(0, rm1.hashCode());
        assertEquals(62, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void st_combine_long() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<Long>(0, 1, (long) 1);
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<Long>(1, 2, (long) -1);
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1, 1]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<Long>(0, 1, (long) 1);
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<Long>(1, 2, (long) -1);
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<Long>(0, 1, (long) 1);
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<Long>(1, 2, (long) -1);
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<Long>(0, 1, (long) 1);
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<Long>(1, 2, (long) -1);
        rs1.combined(rs2);
        assertEquals("0->1 sum=0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(31, rm1.hashCode());
        assertEquals(62, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void st_combine_double() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<Double>(0, 1, (double) 1);
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<Double>(1, 2, (double) -1);
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1.0, 1.0]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<Double>(0, 1, (double) 1);
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<Double>(1, 2, (double) -1);
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1.0", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<Double>(0, 1, (double) 1);
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<Double>(1, 2, (double) -1);
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1.0", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<Double>(0, 1, (double) 1);
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<Double>(1, 2, (double) -1);
        rs1.combined(rs2);
        assertEquals("0->1 sum=0.0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(1041235999, rm1.hashCode());
        assertEquals(-1106247649, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void st_combine_float() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<Float>(0, 1, (float) 1);
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<Float>(1, 2, (float) -1);
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1.0, 1.0]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<Float>(0, 1, (float) 1);
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<Float>(1, 2, (float) -1);
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1.0", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<Float>(0, 1, (float) 1);
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<Float>(1, 2, (float) -1);
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1.0", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<Float>(0, 1, (float) 1);
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<Float>(1, 2, (float) -1);
        rs1.combined(rs2);
        assertEquals("0->1 sum=0.0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(813695007, rm1.hashCode());
        assertEquals(-1333788641, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void st_combine_biginteger() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<BigInteger>(0, 1, new BigInteger("1"));
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<BigInteger>(1, 2, new BigInteger("-1"));
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1, 1]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<BigInteger>(0, 1, new BigInteger("1"));
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<BigInteger>(1, 2, new BigInteger("-1"));
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<BigInteger>(0, 1, new BigInteger("1"));
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<BigInteger>(1, 2, new BigInteger("-1"));
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<BigInteger>(0, 1, new BigInteger("1"));
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<BigInteger>(1, 2, new BigInteger("-1"));
        rs1.combined(rs2);
        assertEquals("0->1 sum=0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(0, rm1.hashCode());
        assertEquals(62, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void st_combine_bigdecimal() {

        SegmentTree.Data qd1 = new SegmentTree.Data.QuadrantData(0, 1, 1, 2, 3);
        SegmentTree.Data qd2 = new SegmentTree.Data.QuadrantData(1, 2, -1, -2, -3);
        qd1.combined(null);
        qd1.combined(qd2);
        assertEquals("0->0 3,0,0,0", qd1.toString());


        SegmentTree.Data ri1 = new SegmentTree.Data.IntervalData<BigDecimal>(0, 1, new BigDecimal("1"));
        SegmentTree.Data ri2 = new SegmentTree.Data.IntervalData<BigDecimal>(1, 2, new BigDecimal("-1"));
        ri1.combined(ri2);
        assertEquals("0->2 set=[-1, 1]", ri1.toString());


        SegmentTree.Data rm1 = new SegmentTree.Data.RangeMinimumData<BigDecimal>(0, 1, new BigDecimal("1"));
        SegmentTree.Data rm2 = new SegmentTree.Data.RangeMinimumData<BigDecimal>(1, 2, new BigDecimal("-1"));
        rm1.combined(rm2);
        assertEquals("0->1 minimum=-1", rm1.toString());


        SegmentTree.Data rx1 = new SegmentTree.Data.RangeMaximumData<BigDecimal>(0, 1, new BigDecimal("1"));
        SegmentTree.Data rx2 = new SegmentTree.Data.RangeMaximumData<BigDecimal>(1, 2, new BigDecimal("-1"));
        rx1.combined(rx2);
        assertEquals("0->1 maximum=1", rx1.toString());


        SegmentTree.Data rs1 = new SegmentTree.Data.RangeSumData<BigDecimal>(0, 1, new BigDecimal("1"));
        SegmentTree.Data rs2 = new SegmentTree.Data.RangeSumData<BigDecimal>(1, 2, new BigDecimal("-1"));
        rs1.combined(rs2);
        assertEquals("0->1 sum=0", rs1.toString());


        assertEquals(qd1, qd1);
        assertNotEquals(qd1, qd2);
        assertNotEquals(qd1, null);
        assertEquals(ri1, ri1);
        assertNotEquals(ri1, ri2);
        assertNotEquals(ri1, null);
        assertEquals(rm1, rm1);
        assertNotEquals(rm1, rm2);
        assertNotEquals(rm1, null);
        assertEquals(rx1, rx1);
        assertNotEquals(rx1, rx2);
        assertNotEquals(rx1, null);
        assertEquals(rs1, rs1);
        assertNotEquals(rs1, rs2);
        assertNotEquals(rs1, null);


        assertEquals(93, qd1.hashCode());
        assertEquals(124, ri1.hashCode());
        assertEquals(-930, rm1.hashCode());
        assertEquals(992, rx1.hashCode());
        assertEquals(31, rs1.hashCode());

        qd1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        ri1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        rm1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        rx1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        rs1.clear();
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());

        qd1.combined(null);
        ri1.combined(null);
        rm1.combined(null);
        rx1.combined(null);
        rs1.combined(null);
        assertEquals("-9223372036854775808->9223372036854775807 0,0,0,0", qd1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 set=[]", ri1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 minimum=null", rm1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 maximum=null", rx1.toString());
        assertEquals("-9223372036854775808->9223372036854775807 sum=null", rs1.toString());
    }

    @Test
    public void dt() {

        List<SegmentTree.Data> list = new ArrayList<>();

        list.add(new SegmentTree.Data.QuadrantData(0, 1, 0, 0, 0));
        list.add(new SegmentTree.Data.IntervalData<Integer>(1, 2, 233));
        list.add(new SegmentTree.Data.RangeMinimumData<Integer>(2, 3));
        list.add(new SegmentTree.Data.RangeMaximumData<Integer>(3, 4));
        list.add(new SegmentTree.Data.RangeSumData<Integer>(5, 6));

        DynamicSegmentTree<SegmentTree.Data> tree = new DynamicSegmentTree<>(list);

        SegmentTree.Data query = tree.query(0);
        assertEquals("0->0 1,0,0,0", query.toString());

        SegmentTree.Data query1 = tree.query(0, 1);
        assertEquals("0->1 1,0,0,0", query1.toString());

        SegmentTree.Data query2 = tree.query(0);
        assertEquals("0->0 1,0,0,0", query2.toString());

        SegmentTree.Data query3 = tree.query(6);
        assertEquals("6->6 sum=null", query3.toString());
    }

    @Test
    public void ft() {
        List<SegmentTree.Data> list = new ArrayList<>();

        list.add(new SegmentTree.Data.QuadrantData(0, 1, 0, 0, 0));
        list.add(new SegmentTree.Data.IntervalData<Integer>(1, 2, 233));
        list.add(new SegmentTree.Data.RangeMinimumData<Integer>(2, 3));
        list.add(new SegmentTree.Data.RangeMaximumData<Integer>(3, 4));
        list.add(new SegmentTree.Data.RangeSumData<Integer>(5, 6));
        list.add(new SegmentTree.Data.RangeSumData<Integer>(8, 10));

        FlatSegmentTree<SegmentTree.Data> tree = new FlatSegmentTree<>(list);


        assertEquals("└── 0->10 Length=11 Data={0->0 1,0,0,0} Set=[]\n" +
                "    ├── 0->4 Length=5 Data={0->0 1,0,0,0} Set=[]\n" +
                "    │   ├── 0->1 Length=2 Data={0->0 1,0,0,0} Set=[]\n" +
                "    │   │   ├── 0->0 Length=1 Data={0->0 1,0,0,0} Set=[0->0 Length=1 Data={0->0 1,0,0,0} Set=[]]\n" +
                "    │   │   └── 1->1 Length=1 Data={1->2 set=[233]} Set=[1->1 Length=1 Data={1->2 set=[233]} Set=[]]\n" +
                "    │   └── 2->4 Length=3 Data={1->2 set=[233]} Set=[]\n" +
                "    │       ├── 2->2 Length=1 Data={1->2 set=[233]} Set=[2->2 Length=1 Data={1->2 set=[233]} Set=[]]\n" +
                "    │       └── 3->4 Length=2 Data={2->3 minimum=null} Set=[]\n" +
                "    │           ├── 3->3 Length=1 Data={2->3 minimum=null} Set=[3->3 Length=1 Data={2->3 minimum=null} Set=[]]\n" +
                "    │           └── 4->4 Length=1 Data={3->4 maximum=null} Set=[4->4 Length=1 Data={3->4 maximum=null} Set=[]]\n" +
                "    └── 5->10 Length=6 Data={5->6 sum=null} Set=[]\n" +
                "        ├── 5->7 Length=3 Data={5->6 sum=null} Set=[]\n" +
                "        │   ├── 5->5 Length=1 Data={5->6 sum=null} Set=[5->5 Length=1 Data={5->6 sum=null} Set=[]]\n" +
                "        │   └── 6->7 Length=2 Data={5->6 sum=null} Set=[]\n" +
                "        │       ├── 6->6 Length=1 Data={5->6 sum=null} Set=[6->6 Length=1 Data={5->6 sum=null} Set=[]]\n" +
                "        │       └── 7->7 Length=1 Data={7->7 sum=null} Set=[7->7 Length=1 Data={7->7 sum=null} Set=[]]\n" +
                "        └── 8->10 Length=3 Data={8->10 sum=null} Set=[]\n" +
                "            ├── 8->8 Length=1 Data={8->10 sum=null} Set=[8->8 Length=1 Data={8->10 sum=null} Set=[]]\n" +
                "            └── 9->10 Length=2 Data={8->10 sum=null} Set=[]\n" +
                "                ├── 9->9 Length=1 Data={8->10 sum=null} Set=[9->9 Length=1 Data={8->10 sum=null} Set=[]]\n" +
                "                └── 10->10 Length=1 Data={8->10 sum=null} Set=[10->10 Length=1 Data={8->10 sum=null} Set=[]]\n", tree.toString().replace("\r", ""));


        SegmentTree.Data query = tree.query(0);
        assertEquals("0->0 1,0,0,0", query.toString());

        SegmentTree.Data query1 = tree.query(0, 1);
        assertEquals("0->0 1,0,0,0", query1.toString());


        SegmentTree.Data query2 = tree.query(1, 3);
        assertEquals("1->2 set=[233]", query2.toString());

        assertNull(tree.query(-233));


        SegmentTree.Data query3 = tree.query(5, 100);
        assertEquals("5->6 sum=null", query3.toString());


        SegmentTree.Data query4 = tree.query(0, 10);
        assertEquals("0->0 1,0,0,0", query4.toString());


        SegmentTree.Data queryx = tree.query(9);
        assertEquals("8->10 sum=null", queryx.toString());

    }
}
