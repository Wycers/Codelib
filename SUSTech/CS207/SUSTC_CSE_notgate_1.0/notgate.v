`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/01/29 22:59:30
// Design Name: 
// Module Name: notgate
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


module notgate
#(parameter WIDTH=1)           //ָ�����ݿ�Ȳ�����ȱʡֵ��1
   (
    input [(WIDTH-1):0] a,     // ����λ���ɲ���WIDTH����
    output [(WIDTH-1):0] c
    );

    assign c = ~a;           //  1�������

endmodule
