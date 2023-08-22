`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/15 17:54:22
// Design Name: 
// Module Name: memio_test
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


module memio(
	input clk,
	//ioread
	input ioread_rst,
	input ior,//from ctrl
	//memorio
	input[31:0] caddress,// from alu_result in executs32 reg
	input memRead,//from ctrl
	input memWrite,//from ctrl
	input ioRead,//from ctrl
	input ioWrite,//from ctrl
	input[31:0] wdata,//from idecode, data that you want to write
	//led
	input led_rst,
	input led_write,//from ctrl
	output[23:0] led_out,//to leds on board
	//switch
	input switch_rst,
	input switch_read,//from ctrl
	input[23:0] switch_signal,//from switches on board
	output wire[31:0] rdata//data from memory or IO that want to read into register/ wire
);
wire[15:0] switch_r_data;
wire[15:0] ioread_data_IORead;
//wire[31:0] rdata;
wire[31:0] address;
wire[31:0] write_data;
wire LEDCtrl;
wire SwitchCtrl;
wire[31:0] readout;
ioread IOr(
	.reset(ioread_rst),//input
	.ior(ior),//input
	.switchctrl(address[4]),//from memorio
	.ioread_data_switch(switch_r_data),//from switch
	.ioread_data(ioread_data_IORead)//to memorio
	);
memorio mux(
	.caddress(caddress),//input
	.memread(memRead),//input
	.memwrite(memWrite),//input
	.ioread(ioRead),//input
	.iowrite(ioWrite),//input
	.mread_data(readout),// from dmem
	.ioread_data(ioread_data_IORead),//from IORead module
	.wdata(wdata),// input
	.rdata(rdata),// data from memory or IO that want to read into register/ wire
	.write_data(write_data),//to dmem or IO
	.address(address),// to dmem and IO
	.LEDCtrl(LEDCtrl),//to led
	.SwitchCtrl(SwitchCtrl)// to switch
	);
dmemory32 dmem(
	.clock(clk),//input
	.address(address),// from memorio
	.write_data(write_data),//from memorio
	.read_data(readout),// to memorio
	.Memwrite(memWrite)//input
	);
leds led(
	.led_clk(clk),//input
	.ledrst(led_rst),//input
	.ledwrite(led_write),//input
	.ledcs(LEDCtrl),//from memorio
	.ledaddr(address[1:0]),//from memorio
	.ledwdata(write_data[15:0]),// from memorio
	.ledout(led_out));//output
switchs switch(
	.switclk(clk),//input
	.switrst(switch_rst),//input
	.switchcs(SwitchCtrl),//from memorio
	.switchaddr(address[1:0]),//from memorio
	.switchread(switch_read),//input
	.switch_i(switch_signal),//input
	.switchrdata(switch_r_data)//to IORead
	);
endmodule
