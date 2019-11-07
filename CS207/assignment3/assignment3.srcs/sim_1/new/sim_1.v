`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/11/15 17:14:46
// Design Name: 
// Module Name: sim_1
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


module sim_1();
reg[15:0] in;
wire[7:0] out;
design_led XD(.out(out), .in(in));
initial
begin
    in=16'b0000000000000000;
    while(in<16'b1111111111111111)
    begin
        #10
        in = in + 1;
    end
    #10
    $finish(1);
end
endmodule
