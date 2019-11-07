`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Design Name: 
// Module Name: lift_control
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

`define stop_on_one_floor ( (cur_state == floor1) || (cur_state == floor2) || (cur_state == floor3) || (cur_state == floor4) )
`define go_up (direction == UP)
`define go_down (direction == DOWN)
`define door_open (door_state == 1)
`define door_close (door_state == 0)

module lift_control(
    input rst_n,                // reset signal, 0 is effective
    input clk,                  // clk signal of floor control part  
    input [3:1] up,             // the up bottons in floor 1--3
    input [4:2] down,           // the down bottons in floor 2--4
    input [4:1] des,            // des stands for destination (floor 1--4), stores the input inside the elevator
    input open_door_botton,     // open_door botton inside the elevator, 1 is effective
    input close_door_botton,    // colse_door botton inside the elevator, 1 is effective
    
    output reg direction,       // moving direction, UP and DOWN (DOWN = 1'b0, UP = 1'b1)
    output reg door_state,      // 0 stands for close, 1 stands for open
    output reg [9:0] new_state, // represent the new state dispayed 
                                           // 0--9: des[1],des[2],des[3],des[4], up[1],up[2],up[3], down[2],down[3],down[4]
    output reg [2:0] cur_state            // current state
);
    
    reg en_counter;
    reg gap_time = 5;
    reg count_finish;
    wire count_end;
    
    floor_timeCounter ftc(en_counter, rst_n, clk, gap_time, count_end);
    
    always @(*)
    begin 
        if (count_end == 1)
            count_finish = 1;
        else
            count_finish = 0;
    end
   
    parameter floor1 = 3'b001, floor2 = 3'b010, floor3 = 3'b011, floor4 = 3'b100; 
    parameter floor1to2 = 3'b101, floor2to3 = 3'b110, floor3to4 = 3'b111;
    parameter DOWN = 1'b0, UP = 1'b1;
    
    always @(*)
    begin
        // index:            0       1      2     3        4     5    6       7       8       9
        //new_state = {des[1],des[2],des[3],des[4], up[1],up[2],up[3], down[2],down[3],down[4]};
        
        // index:       0         1        2       3      4      5      6       7       8       9
        new_state = { down[4], down[3], down[2], up[3], up[2], up[1], des[4], des[3], des[2], des[1] };
    end
    
    always @(posedge clk, negedge rst_n)
    begin
        if (~rst_n)
        begin
            cur_state <= floor1;
            direction <= UP;
            door_state <= 0;
            new_state <= 0;
        end
        else 
        begin
            // when the lift stops on one floor and someone press the open_door or close_door botton inside the lift
            if (`stop_on_one_floor )
            begin
                if (open_door_botton)
                begin
                    door_state <= 1;
                    en_counter <= 0;
                end
                else if (close_door_botton)
                begin
                    door_state <= 0;
                    en_counter <= 0;
                end
            end
                
            // when the lift stops on one floor and will go UP or DOWN, or move from one floor to another floor
            // stops on floor 1 (cur_state: UP)
            if ( cur_state == floor1 && `door_close && ~open_door_botton && `go_up )
            begin
                //if (up[1] || des[1])
                if (new_state[4] || new_state[0])
                begin
                    new_state[0] <= 0;    // des[1]
                    new_state[4] <= 0;    // up[1]
                    door_state <= 1;
                    en_counter <= 0;
                end
                //else if ( des[2] || des[3] || des[4] || up[2] || up[3] || down[2] || down[3] || down[4] )
                else if (new_state[1] || new_state[2] || new_state[3] || new_state[5] || new_state[6] || new_state[7] || new_state[8] || new_state[9])
                begin
                    cur_state <= floor1to2; 
                    new_state[0] <= 0;    // des[1]
                    new_state[4] <= 0;    // up[1]                                
                    direction <= UP;
                    door_state <= 0;
                    en_counter <= 1;
                end
            end
                
            // move from floor 1 to floor 2, or from floor 2 to floor 1
            if (cur_state == floor1to2 && `door_close && count_finish == 1) 
            begin
                if (`go_up)
                begin
                    cur_state <= floor2;
                    new_state[1] <= 0;    // des[2]
                    en_counter <= 0;
                end
                else if (`go_down)
                begin
                    direction <= UP;
                    cur_state <= floor1;
                    new_state[0] <= 0;    // des[1]
                    en_counter <= 0;
                end
            end
            
            
            // stops on floor 2 (cur_state: UP)
            if ( cur_state == floor2 && `door_close && ~open_door_botton && `go_up )
            begin
                //if ( (up[2] || des[2]) && ~down[2] )
                if ( (new_state[5] || new_state[1]) && ~new_state[7] )
                begin
                    new_state[1] <= 0;    // des[2]
                    new_state[5] <= 0;    // up[2]
                    door_state <= 1;
                    en_counter <= 0;
                end
                //else if ( ~up[2] && ~des[2] && (des[3] || des[4] || up[3] || down[3] || down[4]) )
                else if ( ~new_state[5] && ~new_state[1] && (new_state[2] || new_state[3] || new_state[6] || new_state[8] || new_state[9]) )
                begin
                    cur_state <= floor2to3; 
                    new_state[1] <= 0;    // des[2] 
                    door_state <= 0;
                    en_counter <= 1;
                end  
                //else if ( down[2] && ~des[2] && ~des[3] && ~des[4] && ~up[2] && ~up[3] && ~down[3] && ~down[4] )
                else if ( new_state[7] && ~new_state[1] && ~new_state[2] && ~new_state[3] && ~new_state[5] && ~new_state[6] && ~new_state[8] && ~new_state[9] )
                begin
                    new_state[1] <= 0;    // des[2]
                    new_state[7] <= 0;    // down[2]                     
                    door_state <= 1;
                    en_counter <= 0;
                    direction <= DOWN;
                end  
                //else if ( ~down[2] && ~des[2] && ~des[3] && ~des[4] && ~up[2] && ~up[3] && ~down[3] && ~down[4] && (up[1] || des[1]) )
                else if ( ~new_state[7] && ~new_state[1] && ~new_state[2] && ~new_state[3] && ~new_state[5] && ~new_state[6] && ~new_state[8] && ~new_state[9] && (new_state[4] || new_state[0]) )
                begin 
                    direction <= DOWN;
                    cur_state <= floor1to2;
                    new_state[1] <= 0;    // des[2]
                    door_state <= 0;
                    en_counter <= 1;
                end
            end
                    
            // stops on floor 2 (cur_state: DOWN)
            if ( cur_state == floor2 && `door_close && ~open_door_botton && `go_down )
            begin
                //if ( (down[2] || des[2]) && ~up[2])
                if ( (new_state[7] || new_state[1]) && ~new_state[5] )
                begin
                    new_state[1] <= 0;   // des[2]
                    new_state[7] <= 0;   // down[2]
                    door_state <= 1;
                    en_counter <= 0;   
                end  
                //else if ( ~down[2] && ~des[2] && (up[1] || des[1]) )
                else if ( ~new_state[7] && ~new_state[1] && (new_state[4] || new_state[0]) )
                begin
                    cur_state <= floor1to2; 
                    new_state[1] <= 0;   // des[2]
                    door_state <= 0;
                    en_counter <= 1;
                end  
                //else if ( ~des[1] && ~des[2] && ~up[1] && ~down[2] && up[2] )
                else if ( ~new_state[0] && ~new_state[1] && ~new_state[4] && ~new_state[7] && new_state[5] )
                begin
                    new_state[1] <= 0;   // des[2]
                    new_state[5] <= 0;   // up[2]
                    door_state <= 1;
                    en_counter <= 0;
                    direction <= UP;
                end     
                //else if (~des[1] && ~des[2] && ~up[1] && ~down[2] && ~up[2] && (up[3] || down[3] || down[4] || des[3] || des[4]) )
                else if (~new_state[0] && ~new_state[1] && ~new_state[4] && ~new_state[7] && ~new_state[5] && (new_state[6] || new_state[8] || new_state[9] || new_state[2] || new_state[3]) )
                begin
                    direction <= UP;
                    cur_state <= floor2to3;
                    new_state[1] <= 0;    // des[2]
                    door_state <= 0;
                    en_counter <= 1;                                  
                end
            end
                
            // move from floor 2 to floor 3, or from floor 3 to floor 2
            if (cur_state == floor2to3 && `door_close && count_finish == 1) 
            begin
                if (`go_up)
                begin
                    cur_state <= floor3;
                    new_state[2] <= 0;    // des[3]
                    en_counter <= 0;
                end
                else if (`go_down)
                begin
                    cur_state <= floor2;
                    new_state[1] <= 0;    // des[2]
                    en_counter <= 0;
                end
            end
                
            // stops on floor 3 (cur_state: UP)
            if ( cur_state == floor3 && `door_close && ~open_door_botton && `go_up )
            begin 
                //if ( (up[3] || des[3]) && ~down[3] )
                if ( (new_state[6] || new_state[2]) && ~new_state[8] )
                begin
                    new_state[2] <= 0;     // des[3]
                    new_state[6] <= 0;     // up[3]
                    door_state <= 1;
                    en_counter <= 0;
                end
                //else if ( ~up[3] && ~des[3] && (des[4] || down[4]) )
                else if ( ~new_state[6] && ~new_state[2] && (new_state[3] || new_state[9]) )
                begin   
                    cur_state <= floor3to4; 
                    new_state[2] <= 0;     // des[3]
                    door_state <= 0;
                    en_counter <= 1;
                end  
                //else if ( ~des[3] && ~des[4] && ~up[3] && down[3] && ~down[4] )
                else if ( ~new_state[2] && ~new_state[3] && ~new_state[6] && new_state[8] && ~new_state[9] )
                begin  
                    new_state[2] <= 0;     // des[3]
                    new_state[8] <= 0;     // down[3]
                    door_state <= 1;
                    en_counter <= 0;
                    direction <= DOWN;
                end    
                //else if ( ~des[3] && ~des[4] &&  ~up[3] && ~down[3] && ~down[4] && (des[1] || des[2] || up[1] || up[2] || down[2]) )
                else if ( ~new_state[2] && ~new_state[3] && ~new_state[6] && ~new_state[8] && ~new_state[9] && (new_state[0] || new_state[1] || new_state[4] || new_state[5] || new_state[7]) )
                begin 
                    direction <= DOWN;
                    cur_state <= floor2to3;
                    new_state[2] <= 0;     // des[3]
                    door_state <= 0;
                    en_counter <= 1;
                end
            end   
            
                // stops on floor 3 (cur_state: DOWN)
            if ( cur_state == floor3 && `door_close && ~open_door_botton && `go_down )
            begin  
                new_state[2] <= 0;           // des[3] 
                if ( (new_state[8] || new_state[2]) && ~new_state[6] )
                begin
                    new_state[8] <= 0;   //down[3]
                    door_state <= 1;
                    en_counter <= 0;    
                end   
                else if ( ~new_state[8] && ~new_state[2] && (new_state[0] || new_state[1] || new_state[4] || new_state[5] || new_state[7]) )
                begin
                    cur_state <= floor2to3; 
                    door_state <= 0;
                    en_counter <= 1;
                end  
                else if ( ~new_state[0] && ~new_state[1] && ~new_state[2] && ~new_state[4] && ~new_state[5] && ~new_state[7] && ~new_state[8] && new_state[6] )
                begin
                    new_state[6] <= 0;    // up[3]
                    door_state <= 1;
                    en_counter <= 0;
                    direction <= UP;
                end      
                else if (~new_state[0] && ~new_state[1] && ~new_state[2] && ~new_state[4] && ~new_state[5] && ~new_state[7] && ~new_state[8] && ~new_state[6] && (new_state[9] || new_state[3]) )
                begin
                    direction <= UP;
                    cur_state <= floor3to4;
                    door_state <= 0;
                    en_counter <= 1;                                  
                end
            end
                    
            // move from floor 3 to floor 4, or from floor 4 to floor 3
            if (cur_state == floor3to4 && `door_close && count_finish == 1) 
            begin
                if (`go_up)
                begin
                    direction <= DOWN;
                    cur_state <= floor4;
                    new_state[3] <= 0;      // des[4]
                    en_counter <= 0;
                end
                else if (`go_down)
                begin
                    cur_state <= floor3;
                    new_state[2] <= 0;     // des[3]
                    en_counter <= 0;
                end
            end     
            
            // stops on floor 4 (cur_state: DOWN)
            if ( cur_state == floor4 && `door_close && ~open_door_botton && `go_down )
            begin  
                new_state[3] <= 0;            // des[4]  
                //if ( down[4] || des[4] )
                if ( new_state[9] || new_state[3] )
                begin
                    new_state[9] <= 0;    // down[4]
                    door_state <= 1;
                    en_counter <= 0;    
                end
                else if ( ~new_state[9] && ~new_state[3] && (new_state[0] || new_state[1] || new_state[2] || new_state[4] || new_state[5] || new_state[6] || new_state[7] || new_state[8]) )
                begin
                    cur_state <= floor3to4; 
                    door_state <= 0;
                    en_counter <= 1;
                end
            end       
        end
    end
    
endmodule
