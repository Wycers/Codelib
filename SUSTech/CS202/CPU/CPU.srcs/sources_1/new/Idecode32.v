`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////

module Idecode32(read_data_1,read_data_2,Instruction,read_data,ALU_result,
                 Jal,RegWrite,MemtoReg,RegDst,Sign_extend,clock,reset, opcplus4,register);
    output[31:0] read_data_1;               // ����ĵ�һ������
    output[31:0] read_data_2;               // ����ĵڶ�������
    input[31:0]  Instruction;               // ȡָ��Ԫ����ָ��
    input[31:0]  read_data;   				//  ��DATA RAM or I/O portȡ��������
    input[31:0]  ALU_result;   				// ��ִ�е�Ԫ��������Ľ������Ҫ��չ��������32λ
    input        Jal;                               //  ���Կ��Ƶ�Ԫ��˵����JALָ�� 
    input        RegWrite;                  // ���Կ��Ƶ�Ԫ
    input        MemtoReg;              // ���Կ��Ƶ�Ԫ
    input        RegDst;                    //  ���Կ��Ƶ�Ԫ
    output  [31:0] Sign_extend;               // ���뵥Ԫ�������չ���32λ������//////////////////////
    //output reg [31:0] Sign_extend;               // ���뵥Ԫ�������չ���32λ������//////////////////////

    input		 clock,reset;                // ʱ�Ӻ͸�λ
    input[31:0]  opcplus4;                 // ����ȡָ��Ԫ��JAL����
    output reg[31:0] register[0:31];
    
    wire[31:0] read_data_1;
    wire[31:0] read_data_2;
    			   //�Ĵ����鹲32��32λ�Ĵ��� //********************************************
    reg[4:0] write_register_address;        // Ҫд�ļĴ����ĺ�
    reg[31:0] write_data;                   // Ҫд�Ĵ��������ݷ�����

    wire[4:0] read_register_1_address;    // Ҫ���ĵ�һ���Ĵ����ĺţ�rs��
    wire[4:0] read_register_2_address;     // Ҫ���ĵڶ����Ĵ����ĺţ�rt��
    wire[4:0] write_register_address_1;   // r-formָ��Ҫд�ļĴ����ĺţ�rd��
    wire[4:0] write_register_address_0;    // i-formָ��Ҫд�ļĴ����ĺ�(rt)
    wire[15:0] Instruction_immediate_value;  // ָ���е�������
    wire[5:0] opcode;                       // ָ����
    
    assign opcode = Instruction[31: 26];	//OP
    assign read_register_1_address = Instruction[25: 21]; //rs 
    assign read_register_2_address = Instruction[20: 16]; //rt 
    assign write_register_address_1 = Instruction[15: 11];// rd(r-form)
    assign write_register_address_0 = Instruction[20: 16];//rt(i-form)
    assign Instruction_immediate_value = Instruction[15: 0];//data,rladr(i-form)


    wire sign;                                            // ȡ����λ��ֵ

    assign sign = Instruction_immediate_value[15];
    //assign Sign_extend = {(opcode != 6'hc && opcode != 6'hd && opcode != 6'he && sign? 16'hffff:16'h0000), Instruction_immediate_value};
       assign Sign_extend[31:0] = (opcode==6'hc || opcode==6'hd)?{{16{1'b0}},Instruction_immediate_value}://ZeroExtImm
                               {{16{sign}},Instruction_immediate_value};//SignExImm
//    always @ *
//    begin
//        if(opcode != 6'hc && opcode != 6'hd && opcode != 6'he && sign)
//        begin
//            Sign_extend = { 16'hffff,Instruction_immediate_value };
//        end else
//        begin
//            Sign_extend = { 16'h0000,Instruction_immediate_value };
//        end
////        if (Instruction[31: 26] == 4'hc || Instruction[31: 26] == 4'hd)
////            Sign_extend = { 16'h0000, Instruction_immediate_value};
////        else if (sign == 1'b1)
////            Sign_extend = { 16'hffff, Instruction_immediate_value};
////        else
////            Sign_extend = { 16'h0000, Instruction_immediate_value};
//    end
    
    
    assign read_data_1 = register[read_register_1_address];
    assign read_data_2 = register[read_register_2_address];
    
    always @* begin                                            //??????????????????????????
      if(Jal) write_register_address=5'd31;
      else begin
        if(RegDst) write_register_address=write_register_address_1;
        else write_register_address=write_register_address_0;
      end 
    end
    
    always @* begin  //������̻�������ʵ�ֽṹͼ�����µĶ�·ѡ����,׼��Ҫд������
        if(Jal)
        begin
            write_data = opcplus4;
        end
        else if (MemtoReg)
        begin
             write_data = read_data;
        end
        else 
        begin
            write_data = ALU_result;
        end
     end
    
    integer i;
    always @(posedge clock) begin       // ������дĿ��Ĵ���
        if(reset==1) begin              // ��ʼ���Ĵ�����
            for(i=0;i<32;i=i+1) register[i] <= 0;
        end else if(RegWrite==1) begin  // ע��Ĵ���0�����0
            if(write_register_address != 0) 

            begin
                register[write_register_address] = write_data;
            end
        end
    end
endmodule
