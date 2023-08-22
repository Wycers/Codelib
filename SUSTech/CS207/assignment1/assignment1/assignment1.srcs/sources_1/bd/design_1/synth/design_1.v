//Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
//Date        : Tue Oct  2 19:15:27 2018
//Host        : Wycer running 64-bit major release  (build 9200)
//Command     : generate_target design_1.bd
//Design      : design_1
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=8,numReposBlks=8,numNonXlnxBlks=8,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "design_1.hwdef" *) 
module design_1
   (q1,
    q2,
    q3,
    q4,
    x,
    y);
  output [0:0]q1;
  output [0:0]q2;
  output [0:0]q3;
  output [0:0]q4;
  input x;
  input y;

  wire [0:0]andgate_0_q;
  wire [0:0]andgate_1_q;
  wire [0:0]notgate_0_c;
  wire [0:0]notgate_1_c;
  wire [0:0]notgate_2_c;
  wire [0:0]notgate_3_c;
  wire [0:0]orgate_0_q;
  wire [0:0]orgate_2_q;
  wire x_1;
  wire y_1;

  assign q1[0] = notgate_2_c;
  assign q2[0] = andgate_0_q;
  assign q3[0] = notgate_3_c;
  assign q4[0] = orgate_2_q;
  assign x_1 = x;
  assign y_1 = y;
  design_1_andgate_0_0 andgate_0
       (.a(notgate_0_c),
        .b(notgate_1_c),
        .q(andgate_0_q));
  design_1_andgate_0_1 andgate_1
       (.a(x_1),
        .b(y_1),
        .q(andgate_1_q));
  design_1_notgate_0_0 notgate_0
       (.a(x_1),
        .c(notgate_0_c));
  design_1_notgate_0_1 notgate_1
       (.a(y_1),
        .c(notgate_1_c));
  design_1_notgate_0_2 notgate_2
       (.a(orgate_0_q),
        .c(notgate_2_c));
  design_1_notgate_0_3 notgate_3
       (.a(andgate_1_q),
        .c(notgate_3_c));
  design_1_orgate_0_0 orgate_0
       (.a(x_1),
        .b(y_1),
        .q(orgate_0_q));
  design_1_orgate_2_0 orgate_2
       (.a(notgate_0_c),
        .b(notgate_1_c),
        .q(orgate_2_q));
endmodule
