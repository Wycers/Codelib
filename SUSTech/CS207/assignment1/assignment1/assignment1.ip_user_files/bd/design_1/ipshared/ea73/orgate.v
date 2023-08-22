`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/10/21 23:39:12
// Design Name: 
// Module Name: orgate
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


module orgate
#(parameter Port_Num = 2,          // ָ��ȱʡ��������2������˿�
  parameter WIDTH=1)              //ָ�����ݿ�Ȳ�����ȱʡֵ��8
  (
    input [(WIDTH-1):0] a,
    input [(WIDTH-1):0] b,
    input [(WIDTH-1):0] c,
    input [(WIDTH-1):0] d,
    input [(WIDTH-1):0] e,
    input [(WIDTH-1):0] f,
    input [(WIDTH-1):0] g,
    input [(WIDTH-1):0] h,
    output [(WIDTH-1):0] q
    );
    
    assign q = (a | b | c | d | e | f | g | h);
    
endmodule
