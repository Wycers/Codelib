`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/02 15:39:23
// Design Name: 
// Module Name: addition_sim
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


module addition_sim();
    reg [1: 0] ia = 0, ib = 0;
    wire [1: 0] oa, ob;
    wire [2: 0] oc;
    
    Lab2_Addition Yeah(
        .addend(ia), .augend(ib),
        .addend_led(oa), .augend_led(ob),
        .sum_led(oc)
    );
    
    always #10 {ia, ib} = {ia, ib} + 1;
endmodule
