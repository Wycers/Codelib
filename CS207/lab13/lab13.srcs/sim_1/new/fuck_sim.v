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


module fuck_sim();
reg clk =0;
//switch
reg swtich_rst =0;
reg switch_select;//from memorio
reg[1:0] switch_address;
reg switch_read;
reg[23:0] switch_signal;
wire[15:0] switch_r_data;
//leds
reg led_rst=0;
reg led_write=0;
reg led_select;//from memorio
reg[1:0] led_address;
reg[15:0] led_w_data;
wire[23:0] led_out;
//ioread
reg ioread_rst=0;
reg ior;
reg SwitchCtrlInIORead;
reg[15:0] ioread_data_switch;
wire[15:0] ioread_data_IORead;
//memorio
reg[31:0] caddress;
reg memRead;
reg memWrite;
reg ioRead;
reg ioWrite;
reg[31:0] mread_data;
reg[15:0] ioread_data;
reg[31:0] wdata=0;
wire[31:0] rdata;
wire[31:0] address;
wire[31:0] write_data;
wire LEDCtrl;
wire SwitchCtrl;
//dmem
reg[31:0] writemem_data,mem_address;
reg mem_write;
wire[31:0] readout;

reg [31:0] register; 
reg [31:0]tmp ;


ioread IOr(
	.reset(ioread_rst),//reg
	.ior(ior),//from ctrl?? ioread// reg
	//.swtichctrl(SwitchCtrlInIORead),//??
	.switchctrl(address[4]),//from memorio
	.ioread_data_switch(switch_r_data),//from switch
	.ioread_data(ioread_data_IORead)//to memorio
	);

memorio mux(
	.caddress(caddress),// from alu_result in executs32 reg
	.memread(memRead),//from ctrl?? reg
	.memwrite(memWrite),//from ctrl?? reg
	.ioread(ioRead),//from ctrl?? reg
	.iowrite(ioWrite),//from ctrl?? reg
	.mread_data(readout),// from dmem
	.ioread_data(ioread_data_IORead),//from IORead module
	.wdata(wdata),// from idecode, data that you want to write?
	.rdata(rdata),// data from memory or IO that want to read into register? wire
	.write_data(write_data),//to dmem or IO
	.address(address),// to dmem and IO
	.LEDCtrl(LEDCtrl),//to led
	.SwitchCtrl(SwitchCtrl)// to switch
	);
dmemory32 dmem(
	.clock(clk),//reg
	.address(address),// from memorio
	.write_data(write_data),//from memorio
	.read_data(readout)// to memorio
	);

leds led(
	.led_clk(clk),//reg
	.ledrst(ledrst),//reg
	.ledwrite(led_write),//from ctrl reg
	.ledcs(LEDCtrl),//from memorio
	.ledaddr(address[1:0]),//from memorio
	.ledwdata(write_data[15:0]),// from memorio
	.ledout(led_out));//wire
switchs switch(
	.switclk(clk),//reg
	.switrst(swtich_rst),//reg
	.switchcs(SwitchCtrl),//from memorio
	.switchaddr(address[1:0]),//from memorio
	.switchread(switch_read),//from ctrl reg
	.switch_i(switch_signal),//reg
	.switchrdata(switch_r_data)//to IORead
	);

initial
begin
	forever
	#50 clk = ~clk;
end

initial
begin
	fork
	#200 
	begin
	ior=1;
	switch_read=1;
	switch_signal=24'b0;
	memRead = 0;
	memWrite =0;
	ioRead =1;
	ioWrite =0;
	caddress=32'hFFFFFC70;	
	#1  register = rdata;
	end
	#600
	begin
	wdata = register;
	ior = 0;
    switch_read=0;
    switch_signal=24'b0;
    memRead =0;
    memWrite=1;
    ioRead=0 ;
    ioWrite=0;
    caddress=32'h00000001; 
	end 
	
		#800
    begin
    
    memRead =1;
    memWrite=0;
    tmp = rdata;
       
    end 
    	#1000
    begin
    ioWrite=1;
    wdata = tmp;
    memRead =0;
    memWrite=0;
    led_write = 1;
    caddress = 32'hFFFFFC60; 
    wdata = tmp;
    end 
	join
	
end

endmodule
