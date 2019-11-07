//Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2017.4 (win64) Build 2086221 Fri Dec 15 20:55:39 MST 2017
//Date        : Tue Apr 16 15:18:42 2019
//Host        : Wycer running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (a,
    b,
    q,
    sel);
  input a;
  input b;
  output [0:0]q;
  input sel;

  wire a;
  wire b;
  wire [0:0]q;
  wire sel;

  design_1 design_1_i
       (.a(a),
        .b(b),
        .q(q),
        .sel(sel));
endmodule
