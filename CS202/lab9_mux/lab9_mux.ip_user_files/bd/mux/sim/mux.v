//Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
//Date        : Tue Apr 16 16:51:47 2019
//Host        : Wycer running 64-bit major release  (build 9200)
//Command     : generate_target mux.bd
//Design      : mux
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=4,numReposBlks=4,numNonXlnxBlks=4,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "mux.hwdef" *) 
module mux
   (a,
    b,
    q,
    sel);
  input a;
  input b;
  output [7:0]q;
  input sel;

  wire [0:0]AND_GATE_0_q;
  wire [0:0]AND_GATE_1_q;
  wire [0:0]NOT_GATE_0_q;
  wire Net;
  wire [7:0]OR_GATE_0_q;
  wire a_1;
  wire b_1;

  assign Net = sel;
  assign a_1 = a;
  assign b_1 = b;
  assign q[7:0] = OR_GATE_0_q;
  mux_AND_GATE_0_1 AND_GATE_0
       (.a(Net),
        .b(b_1),
        .q(AND_GATE_0_q));
  mux_AND_GATE_1_0 AND_GATE_1
       (.a(a_1),
        .b(NOT_GATE_0_q),
        .q(AND_GATE_1_q));
  mux_NOT_GATE_0_0 NOT_GATE_0
       (.a(Net),
        .q(NOT_GATE_0_q));
  mux_OR_GATE_0_0 OR_GATE_0
       (.a(AND_GATE_1_q),
        .b(AND_GATE_0_q),
        .q(OR_GATE_0_q));
endmodule
