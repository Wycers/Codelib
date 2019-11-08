`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/26 22:38:02
// Design Name: 
// Module Name: CPU
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


module CPU(
    clk, reset,switch_signal,led_out
    //,register, PC, next_pc,opcplus4
    );
    input clk;
    input reset;
    input [23:0]switch_signal;
    output [23:0]led_out;
//    output reg[31:0] register[0:31];
//    output [31:0]next_pc;   //时钟与复位
//    output [31:0]opcplus4;              // JAL指令专用的PC+4
//    output [31:0]PC; 
    wire clock ;
    wire [31:0] Instruction;            // 输出指令到其他模块
    wire [31:0]  PC_plus_4_out;         // (pc+4)送执行单元
    wire [31:0]  Add_result;            // 来自执行单元,算出的跳转地址
    wire [31:0]  Read_data_1;           // 来自译码单元，jr指令用的地址
    wire         Branch;                // 来自控制单元
    wire         nBranch;               // 来自控制单元
    wire         Jmp;                   // 来自控制单元
    wire         Jal;                   // 来自控制单元
    wire         Jrn;                   // 来自控制单元
    wire         Zero;        
    wire[31:0]  Read_data_2;        // 从译码单元的Read_data_2中来
    wire[31:0]  Sign_extend;        // 从译码单元来的扩展后的立即数
    wire[5:0]   Function_opcode;      // 取指单元来的r-类型指令功能码,r-form instructions[5:0]
    wire[5:0]   Exe_opcode;          // 取指单元来的操作码
    wire[1:0]   ALUOp;             // 来自控制单元的运算指令控制编码
    wire[4:0]   Shamt;             // 来自取指单元的instruction[10:6]，指定移位次数
    wire           Sftmd;            // 来自控制单元的，表明是移位指令
    wire        ALUSrc;            // 来自控制单元，表明第二个操作数是立即数（beq，bne除外）
    wire        I_format;          // 来自控制单元，表明是除beq, bne, LW, SW之外的I-类型指令
    wire[31:0] ALU_Result;        // 计算的数据结果
    wire[31:0] Add_Result;        // 计算的地址结果        
    wire[31:0]  PC_plus_4;         // 来自取指单元的PC+4    
    wire MemorIOtoReg;
    wire memRead;//from ctrl
    wire memWrite;//from ctrl
    wire ioRead;//from ctrl
    wire ioWrite;//from ctrl
    wire[31:0] wdata;//from idecode, data that you want to writeishuo
    wire[31:0]  read_data;                   //  从DATA RAM or I/O port取出的数据
    wire        RegWrite;                  // 来自控制单元
    wire       RegDST;                    //  来自控制单元
    
    assign Function_opcode = Instruction[5:0];
    assign Exe_opcode = Instruction[31:26];
    assign  Shamt = Instruction[10:6];
    //assign clock = clk;
    wire  opcplus4;                 // 来自取指单元，JAL中用///
    
    cpuclk u0(.clk_in1(clk), .clk_out1(clock));
    
    lfetc32 u1(.clock(clock),
    .reset(reset),
    .Branch(Branch),
    .nBranch(nBranch),
    .Jmp(Jmp),
    .Jal(Jal),
    .Jrn(Jrn),
    .Zero(Zero),
    .Add_result(Add_Result),
    .Read_data_1(Read_data_1),
    //.next_PC(next_pc),
    .PC_plus_4_out(PC_plus_4_out),
    .opcplus4(opcplus4),
    //.PC(PC),
    .Instruction(Instruction));
    
    Executs32 u2(
    .Read_data_1(Read_data_1),
    .Read_data_2(Read_data_2),
    .Sign_extend(Sign_extend),
    .Function_opcode(Function_opcode),
    .Exe_opcode(Exe_opcode),
    .ALUOp(ALUOp),
     .Shamt(Shamt),
     .ALUSrc(ALUSrc),
     .I_format(I_format),
     .Zero(Zero),
     .Jrn(Jrn),
     .Sftmd(Sftmd),
     .ALU_Result(ALU_Result),
     .Add_Result(Add_Result),
     .PC_plus_4(PC_plus_4_out)
      );
      
    control32 u3(
    .IOWrite(ioWrite),
    .IORead(ioRead),
    .MemRead(memRead),
    .MemorIOtoReg(MemorIOtoReg),
    .Alu_resultHigh(ALU_Result[31:10]),
    .Opcode(Exe_opcode),
    .Function_opcode(Function_opcode),
    .Jrn(Jrn),
    .RegDST(RegDST),
    .ALUSrc(ALUSrc),
    .RegWrite(RegWrite),
    .MemWrite(memWrite),
    .Branch(Branch),
    .nBranch(nBranch),
    .Jmp(Jmp),
    .Jal(Jal),
    .I_format(I_format),
    .Sftmd(Sftmd),
    .ALUOp(ALUOp)
    );
    
    memio u4(
         .clk(clock),
        //ioread
         .ioread_rst(reset),
         .ior(ioRead),//from ctrl/////////////////////////////////////////////////////////////////////////
        //memorio
         .caddress(ALU_Result),// from alu_result in executs32 reg
         .memRead(memRead),//from ctrl
         .memWrite(memWrite),//from ctrl
         .ioRead(ioRead),//from ctrl
         .ioWrite(ioWrite),//from ctrl
         .wdata(Read_data_2),//from idecode, data that you want to write
        //led
         .led_rst(reset),
         .led_write(ioWrite),//from ctrl
         .led_out(led_out),//to leds on board
        //switch
         .switch_rst(reset),
         .switch_read(ioRead),//from ctrl
         .switch_signal(switch_signal),//from switches on board
         .rdata(read_data)//data from memory or IO that want to read into register/ wire
    );
    
   Idecode32 u5(.read_data_1(Read_data_1),.read_data_2(Read_data_2),.Instruction(Instruction),.read_data(read_data),.ALU_result(ALU_Result),
                     .Jal(Jal),.RegWrite(RegWrite),.MemtoReg(MemorIOtoReg),.RegDst(RegDST),.Sign_extend(Sign_extend),.clock(clock),.reset(reset), .opcplus4(opcplus4)
                    
                    //,.register(register)
                     );
    
endmodule
