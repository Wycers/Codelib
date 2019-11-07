`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/30 13:22:07
// Design Name: 
// Module Name: udp_sim
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


module udp_sim();
reg x = 0, y = 0, z = 0; wire q;
udp_body udp(q, x, y, z);
initial 
begin
    $monitor("X=%d, Y=%d, Z=%d, A=%d", x, y, z, q);
    for (integer i = 0; i < 8; i = i + 1)
    begin
        #10 {x, y, z} = i;
    end
    #10 $finish(1);
end
endmodule


