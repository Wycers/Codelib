`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/16 09:14:02
// Design Name: 
// Module Name: mul
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


module mul(
    input [1 : 0] a,
    input [1 : 0] b,
    output [3 : 0] c
);
    assign c[3] = (a[1] & b[1]) & ((a[1] & b[0]) & (a[0] & b[1]));
    assign c[2] = (a[1] & b[1]) ^ ((a[1] & b[0]) & (a[0] & b[1]));
    assign c[1] = (a[1] & b[0]) ^ (a[0] & b[1]);
    assign c[0] = (a[0] & b[0]);
endmodule
