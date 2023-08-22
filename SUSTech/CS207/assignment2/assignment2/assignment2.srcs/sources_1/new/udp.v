`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/30 13:09:06
// Design Name: 
// Module Name: udp
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

`include "udp_body.v"
module udp(
    output q,
    input x,
    input y,
    input z
);
udp_body udp(q, x, y, z);
endmodule    
 

