`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/08/08 14:26:34
// Design Name: 
// Module Name: ram_sim
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


module ram_sim(
    );
    // input
    reg[31:0] address = 32'h00000010;     //来自memorio模块，源头是来自执行单元算出的alu_result
    reg[31:0] write_data = 32'ha0000000;  //来自译码单元的read_data2
    reg  Memwrite = 1'b0;         //来自控制单元
    reg  clock = 1'b0;    
    // output
    wire[31:0] read_data;

    dmemory32 Uram(read_data,address,write_data,Memwrite,clock);

    initial begin
      #200 begin write_data = 32'hA00000F5;Memwrite = 1'b1; end
      #200 Memwrite = 1'b0;
    end
    always #50 clock = ~clock;            
endmodule
