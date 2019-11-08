`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module ioread(reset,ior,switchctrl,ioread_data,ioread_data_switch);
    input reset;			// 复位信号 
    input ior;              //  从控制器来的I/O读，
    input switchctrl;		//  从memorio经过地址高端线获得的拨码开关模块片选
    input[15:0] ioread_data_switch;  //从外设来的读数据，此处来自拨码开关
    output[15:0] ioread_data;	// 将外设来的数据送给memorio
    
    reg[15:0] ioread_data;
    
    always @* begin
        if(reset == 1)
            ioread_data = 16'b0000000000000000;
        else if(ior == 1) begin
            if(switchctrl == 1)
                ioread_data = ioread_data_switch;
            else   ioread_data = ioread_data;
        end
    end
endmodule
