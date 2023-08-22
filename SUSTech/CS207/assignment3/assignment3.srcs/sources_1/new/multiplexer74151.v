`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/15 20:12:31
// Design Name: 
// Module Name: multiplexer74151
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

module multiplexer(
    input s2, s1, s0, d,
    output reg q
);
always @ (*)
    case({ s2, s1, s0 })
        3'b000 : q = 1;
        3'b001 : q = 1;
        3'b010 : q = 1;
        3'b011 : q = 1;
        3'b100 : q = 1;
        3'b101 : q = !d;
        3'b110 : q = d;
        3'b111 : q = d;
    endcase
endmodule