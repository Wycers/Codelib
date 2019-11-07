`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/27 00:25:12
// Design Name: 
// Module Name: cpu_sim
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

module cpu_sim();
reg clk = 0;
reg rst = 1;
reg[23:0] switch_signal;
wire[23:0] led_out;

//reg[23:0] switch_signal;
//reg rst;
//reg clk;
//wire[23:0] led_out;
wire[31:0] register[0:31];
//wire[31:0] pc;
//wire[31:0] next_pc;
//wire[31:0] opcplus4;
CPU c(
	.reset(rst),
	.led_out(led_out),
	.clk(clk),
	.switch_signal(switch_signal),
	.register(register)
	);
initial
    begin
     switch_signal <= 24'b000000000000000010101100;
    #70 rst = 0;
    end
    always #10 clk = ~clk;
    
//initial 
//begin
    
//	switch_signal = 24'hABCDEF;
	
//	clk = 0;
//	#30 rst = 0;
//	forever
//	#20 clk = ~clk;
//end

endmodule
