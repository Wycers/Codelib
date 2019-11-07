`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/27 00:59:05
// Design Name: 
// Module Name: NAND_test
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


module NAND_test();
  reg [1: 0] a = 0;
  reg [1: 0] b = 0;
  reg [1: 0] c = 0;
  reg [1: 0] d = 255;
  wire [1: 0] q;
  NAND #(3, 2)XD (.a(a), .b(b), .c(c), .d(d), .q(q));
  initial
  begin
     {a,b,c}=6'b000000;
      for(integer i=0;i<63;i=i+1)
       begin
         #10 {a,b,c}=i;
       end
      #10 $finish(1);
  end
  
endmodule
