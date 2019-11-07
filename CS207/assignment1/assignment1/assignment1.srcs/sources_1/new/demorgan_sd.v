`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/02 17:42:50
// Design Name: 
// Module Name: demorgan_sd
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


module demorgan_sd(
    input x, y,
    output q1, q2, q3, q4
);
    wire notx, noty, xory, xandy;
    notgate_0 nx(.a(x), .c(notx));
    notgate_0 ny(.a(y), .c(noty));
    orgate_0 xoy(.a(x), .b(y), .q(xory));
    andgate_0 xay(.a(x), .b(y), .q(xandy));
    // ~(x | y)
    notgate_0 Q1(.a(xory), .c(q1)); 
    // (~x) & (~y) 
    andgate_0 Q2(.a(notx), .b(noty), .q(q2));
    // ~(x & y)
    notgate_0 Q3(.a(xandy), .c(q3));
    // (~x) | (~y)
    orgate_0 Q4(.a(notx), .b(noty), .q(q4)); 
endmodule
