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
#(parameter WIDTH=1)           //指定数据宽度参数，缺省值是1
   (
    input [(WIDTH-1):0] a,     // 出具位数由参数WIDTH决定
    output [(WIDTH-1):0] c
    );

    assign c = ~a;           //  1输入非门

endmodule
