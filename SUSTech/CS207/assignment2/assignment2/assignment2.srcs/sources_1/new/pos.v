`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/30 13:18:52
// Design Name: 
// Module Name: pos
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

module pos(
    input x,
    input y,
    input z,
    output q
);
    wire temp0;
    or U0(temp0,x,(~y),(~z));
    
    wire temp1;
    or U1(temp1,(~x),y,(~z));
    
    wire temp2;
    or U2(temp2,x,y,z);
    
    wire temp3;
    or U3(temp3,(~x),(~y),z);
    
    and U4(q,temp0,temp1,temp2,temp3);
endmodule

