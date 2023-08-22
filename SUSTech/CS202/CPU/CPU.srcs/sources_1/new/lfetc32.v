
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
module lfetc32(clock,reset,Branch,nBranch,Jmp,Jal,Jrn,Zero,Add_result,Read_data_1,next_PC,PC_plus_4_out,opcplus4,PC,Instruction);
    output [31:0] Instruction;			// ���ָ�����ģ��
    output[31:0]  PC_plus_4_out;         // (pc+4)��ִ�е�Ԫ
    input[31:0]  Add_result;            // ����ִ�е�Ԫ,�������ת��ַ
    input[31:0]  Read_data_1;           // �������뵥Ԫ��jrָ���õĵ�ַ
    input        Branch;                // ���Կ��Ƶ�Ԫ
    input        nBranch;               // ���Կ��Ƶ�Ԫ
    input        Jmp;                   // ���Կ��Ƶ�Ԫ
    input        Jal;                   // ���Կ��Ƶ�Ԫ
    input        Jrn;                   // ���Կ��Ƶ�Ԫ
    input        Zero;                  //����ִ�е�Ԫ
    input        clock,reset;           //ʱ���븴λ
    output[31:0] opcplus4;              // JALָ��ר�õ�PC+4
    output[31:0] next_PC;   
    output[31:0] PC; 
    
    wire[31:0]   PC_plus_4;             // PC+4
     reg[31:0]	  PC;                   // PC�Ĵ����������������
     reg[31:0]    next_PC ;               // ����ָ���PC����һ����PC+4)
    reg[31:0]  opcplus4;
    reg[31:0] tmpIN;
   //����64KB ROM��������ʵ��ֻ�� 64KB ROM
    prgrom instmem(
        .clka(clock),         // input wire clka
        .addra(PC[15:2]),     // input wire [13 : 0] addra
        .douta(Instruction)         // output wire [31 : 0] douta
    );
    

   assign PC_plus_4[31:2] = PC[31:2]+1;
    assign PC_plus_4[1:0] = 0;
    assign PC_plus_4_out = PC_plus_4[31:0];  

    always @* 
    begin  // beq $n ,$m if $n=$m branch   bne if $n /=$m branch jr
        if(Branch)
            begin
                next_PC = (Zero==1)? Add_result:(PC_plus_4_out>>2);//shift right?
            end
        else if(nBranch)
        begin
            next_PC = (Zero==0)? Add_result:(PC_plus_4_out>>2);
        end
        else  begin
            next_PC = (Jrn==1)? Read_data_1: (PC_plus_4_out>>2);
        end 
         // �뿼����������ָ����ж�������
                                // �Լ�����ָ���ִ�иø�next_PC��ʲôֵ
        tmpIN = Instruction;
    end
    
   always @(negedge clock) 
   begin  //����J��Jalָ���reset�Ĵ���
     if(Jal)
     begin
         opcplus4 = next_PC;
         PC = {4'b0000,tmpIN[25:0],2'b00 };
     end
     else if(Jmp) 
     begin
         PC= {4'b0000,tmpIN[25:0],2'b00 };
     end
     else if(reset)
     begin
         PC =0;
     end
     else begin
         PC =next_PC<<2;//
     end

   end
endmodule
