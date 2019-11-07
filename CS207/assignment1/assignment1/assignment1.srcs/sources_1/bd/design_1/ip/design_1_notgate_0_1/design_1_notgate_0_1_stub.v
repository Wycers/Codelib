// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
// Date        : Tue Oct  2 17:44:50 2018
// Host        : Wycer running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top design_1_notgate_0_1 -prefix
//               design_1_notgate_0_1_ notgate_0_stub.v
// Design      : notgate_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tfgg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "notgate,Vivado 2017.4" *)
module design_1_notgate_0_1(a, c)
/* synthesis syn_black_box black_box_pad_pin="a[0:0],c[0:0]" */;
  input [0:0]a;
  output [0:0]c;
endmodule
