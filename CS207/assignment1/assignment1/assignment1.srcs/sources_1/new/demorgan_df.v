`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/02 17:32:24
// Design Name: 
// Module Name: demorgan_df
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

module demorgan_df(
    input x, y,
    output q1, q2, q3, q4
);
assign q1 = ~(x | y), q2 = (~x) & (~y), q3 = ~(x & y), q4 = (~x) | (~y);
endmodule
