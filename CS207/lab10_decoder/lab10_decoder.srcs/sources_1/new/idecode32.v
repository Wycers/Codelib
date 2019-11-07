`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Idecode32(read_data_1,read_data_2,Instruction,read_data,ALU_result,
                 Jal,RegWrite,MemtoReg,RegDst,Sign_extend,clock,reset, opcplus4,register);
    output[31:0] read_data_1;               // 输出的第一操作数
    output[31:0] read_data_2;               // 输出的第二操作数
    input[31:0]  Instruction;               // 取指单元来的指令
    input[31:0]  read_data;   				//  从DATA RAM or I/O port取出的数据
    input[31:0]  ALU_result;   				// 从执行单元来的运算的结果，需要扩展立即数到32位
    input        Jal;                               //  来自控制单元，说明是JAL指令 
    input        RegWrite;                  // 来自控制单元
    input        MemtoReg;              // 来自控制单元
    input        RegDst;                    //  来自控制单元
    output reg [31:0] Sign_extend;               // 译码单元输出的扩展后的32位立即数
    input		 clock,reset;                // 时钟和复位
    input[31:0]  opcplus4;                 // 来自取指单元，JAL中用
    output reg[31:0] register[0:31];
    
    wire[31:0] read_data_1;
    wire[31:0] read_data_2;
    			   //寄存器组共32个32位寄存器 //********************************************
    reg[4:0] write_register_address;        // 要写的寄存器的号
    reg[31:0] write_data;                   // 要写寄存器的数据放这里

    wire[4:0] read_register_1_address;    // 要读的第一个寄存器的号（rs）
    wire[4:0] read_register_2_address;     // 要读的第二个寄存器的号（rt）
    wire[4:0] write_register_address_1;   // r-form指令要写的寄存器的号（rd）
    wire[4:0] write_register_address_0;    // i-form指令要写的寄存器的号(rt)
    wire[15:0] Instruction_immediate_value;  // 指令中的立即数
    wire[5:0] opcode;                       // 指令码
    
    assign opcode = Instruction[31: 26];	//OP
    assign read_register_1_address = Instruction[25: 21]; //rs 
    assign read_register_2_address = Instruction[20: 16]; //rt 
    assign write_register_address_1 = Instruction[15: 11];// rd(r-form)
    assign write_register_address_0 = Instruction[20: 16];//rt(i-form)
    assign Instruction_immediate_value = Instruction[15: 0];//data,rladr(i-form)


    wire sign;                                            // 取符号位的值

    assign sign = Instruction_immediate_value[15];
    always @ *
    begin
        if (Instruction[31: 26] == 4'hc || Instruction[31: 26] == 4'hd)
            Sign_extend = { 16'h0000, Instruction_immediate_value};
        else if (sign == 1'b1)
            Sign_extend = { 16'hffff, Instruction_immediate_value};
        else
            Sign_extend = { 16'h0000, Instruction_immediate_value};
    end
    
    
    assign read_data_1 = register[read_register_1_address];
    assign read_data_2 = register[read_register_2_address];
    
    always @ * begin                                            //这个进程指定不同指令下的目标寄存器
        if(Jal == 1)
            write_register_address = 31;
        else if (opcode == 6'b000000)
            write_register_address = write_register_address_1;
        else
            write_register_address = write_register_address_0;
    end
    
    always @ * begin  //这个进程基本上是实现结构图中右下的多路选择器,准备要写的数据
        if(Jal)
            write_data = opcplus4;
        else if (MemtoReg)
            write_data = read_data;
        else 
            write_data = ALU_result;
     end
    
    integer i;
    always @(posedge clock) begin       // 本进程写目标寄存器
        if(reset==1)                    // 初始化寄存器组
            for(i = 0; i < 32; i = i + 1)
                register[i] <= i;
        else if(RegWrite==1) begin  // 注意寄存器0恒等于0
            if(write_register_address == 0)
                register[write_register_address] = 0;
            else
                register[write_register_address] = write_data;
        end
    end
endmodule
