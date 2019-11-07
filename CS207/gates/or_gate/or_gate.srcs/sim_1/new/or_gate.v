`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/16 15:26:09
// Design Name: 
// Module Name: or_gate
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


module or_gate
#(
    parameter Port_Num = 2,
    parameter WIDTH=8
)
(
    input [(WIDTH - 1) : 0] a,
    input [(WIDTH - 1) : 0] b,
    input [(WIDTH - 1) : 0] c,
    input [(WIDTH - 1) : 0] d,
    input [(WIDTH - 1) : 0] e,
    input [(WIDTH - 1) : 0] f,
    input [(WIDTH - 1) : 0] g,
    input [(WIDTH - 1) : 0] h,
    output [(WIDTH - 1) : 0] q
);
assign q = (a | b | c | d | e | f | g | h);
endmodule
