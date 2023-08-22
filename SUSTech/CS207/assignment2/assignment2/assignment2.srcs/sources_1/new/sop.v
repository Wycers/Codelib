`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/30 13:12:50
// Design Name: 
// Module Name: sop
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


module sop(
    input x,
    input y,
    input z,
    output q
);
    wire temp0;
    and Uq1(temp0,x,y,z);
    wire temp1;
    and U2(temp1,(~x),(~y),z);
    wire temp2;
    and U3(temp2,(~x),y,(~z));
    wire temp3;
    and U4(temp3,x,(~y),(~z));
    or U0(q,temp0,temp1,temp2,temp3);
endmodule

