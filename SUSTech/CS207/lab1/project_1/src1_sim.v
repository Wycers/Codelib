`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/08/02 09:29:04
// Design Name: 
// Module Name: src1_sim
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


module src1_sim( );
//input
//reg [23:0] clk
//output
wire [23:0] led;
//instantiate the unit 
src1 usrc1(
    .led(led)
);
endmodule
