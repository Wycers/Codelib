`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/27 00:56:38
// Design Name: 
// Module Name: NAND
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module NAND #(parameter Port_Num = 2, WIDTH = 1) (
  input [(WIDTH - 1) : 0] a, input [(WIDTH - 1) : 0] b,
  input [(WIDTH - 1) : 0] c, input [(WIDTH - 1) : 0] d,
  output [(WIDTH - 1) : 0] q
);
  assign q = ~(a & b & c & d);
endmodule
