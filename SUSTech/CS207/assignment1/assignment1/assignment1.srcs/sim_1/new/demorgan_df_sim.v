`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/02 17:35:05
// Design Name: 
// Module Name: demorgan_df_sim
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


module demorgan_df_sim();
    reg x = 0, y = 0;
    wire q1, q2, q3, q4;
    demorgan_df Yeah(
        .x(x), .y(y),
        .q1(q1), .q2(q2), .q3(q3), .q4(q4)
    );
    always #10 {x, y} = {x, y} + 1;
endmodule
