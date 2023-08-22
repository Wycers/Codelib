`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 20:06:21
// Design Name: 
// Module Name: jk_ff_pri
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


primitive jk_ff(output reg Q, input j, k, clk, rst);
initial Q = 0;
table
 // j   k   clk     rst Q   Q+
    ?   ?   ?       1:  ?:  0;
    ?   ?   (?0)    0:  ?:  -;
    0   0   (01)    0:  0:  0;
    0   0   (01)    0:  1:  1;
    0   1   (01)    0:  ?:  0;
    1   0   (01)    0:  ?:  1;
    1   1   (01)    0:  1:  0;
    1   1   (01)    0:  0:  1;
endtable
endprimitive
