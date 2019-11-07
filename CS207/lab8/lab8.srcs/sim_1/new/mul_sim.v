`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/09 09:26:23
// Design Name: 
// Module Name: mul_sim
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


module mul_sim();
    reg [1:0] a = 2'b00 ;
    reg [1:0] b = 2'b00;
    wire [3:0] c ;
    mul sb(.a(a),.b(b),.c(c));
    always #20 {a,b} = {a,b} +1;
endmodule
