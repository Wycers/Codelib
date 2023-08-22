// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
// Date        : Wed Apr 17 09:21:15 2019
// Host        : Wycer running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               D:/Projects/vivado/lab9_mux/lab9_mux.srcs/sources_1/bd/mux/ip/mux_NOT_GATE_0_0_1/mux_NOT_GATE_0_0_stub.v
// Design      : mux_NOT_GATE_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tfgg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "not_gate,Vivado 2017.4" *)
module mux_NOT_GATE_0_0(a, q)
/* synthesis syn_black_box black_box_pad_pin="a[0:0],q[0:0]" */;
  input [0:0]a;
  output [0:0]q;
endmodule
