`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/12/04 22:35:20
// Design Name: 
// Module Name: task3
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

module task3(output A, B, An, Bn, input x_in, clk, rst_n);
    d_ff dff_A(A, An, A&(~x_in)|B&(x_in), clk, rst_n); 
    d_ff dff_B(B, Bn, ~A&(x_in)|B&(~x_in), clk, rst_n); 
endmodule 
