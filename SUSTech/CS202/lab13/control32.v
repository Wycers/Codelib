`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
module control32(IOWrite,IORead,MemRead,MemorIOtoReg,Alu_resultHigh,Opcode,Function_opcode,Jrn,RegDST,ALUSrc,RegWrite,MemWrite,Branch,nBranch,Jmp,Jal,I_format,Sftmd,ALUOp);
    input[5:0]   Opcode;            // ����ȡָ��Ԫinstruction[31..26]
    input[5:0]   Function_opcode;  	// ����ȡָ��Ԫr-���� instructions[5..0]
    output       Jrn;         	 // Ϊ1������ǰָ����jr
    output       RegDST;          // Ϊ1����Ŀ�ļĴ�����rd������Ŀ�ļĴ�����rt
    output       ALUSrc;          // Ϊ1�����ڶ�������������������beq��bne���⣩
   
    output       RegWrite;   	//  Ϊ1������ָ����Ҫд�Ĵ���
    output       MemWrite;   	//  Ϊ1������ָ����Ҫд�洢��
    output       Branch;    	//  Ϊ1������Beqָ��
    output       nBranch;   	//  Ϊ1������Bneָ��
    output       Jmp;        	//  Ϊ1������Jָ��
    output       Jal;        	//  Ϊ1������Jalָ��
    output       I_format;  	//  Ϊ1������ָ���ǳ�beq��bne��LW��SW֮�������I-����ָ��
    output       Sftmd;     	//  Ϊ1��������λָ��
    output[1:0]  ALUOp;	        //  ��R-���ͻ�I_format=1ʱλ1Ϊ1, beq��bneָ����λ0Ϊ1
    input[21:0] Alu_resultHigh; // ����ִ�е�ԪAlu_Result[31..10]������Э���ж��Ƕ�Mem����IO���д���
    output MemorIOtoReg; // Ϊ1������Ҫ�Ӵ洢����I/O�����ݵ��Ĵ���
    output MemRead; // Ϊ1�����Ǵ洢����
    output IORead; // Ϊ1������I/O��
    output IOWrite; // Ϊ1������I/Oд
   
   
    wire Jmp,I_format,Jal,Branch,nBranch;
    wire R_format;        // Ϊ1��ʾ��R-����ָ��
    wire Lw;               // Ϊ1��ʾ��lwָ��
    wire Sw;               // Ϊ1��ʾ��swָ��

    
   assign RegWrite = (R_format || Lw || Jal || I_format) && !(Jrn) ; // ��Ҫд�Ĵ�����ָ��
    // д�洢������дIO
    assign MemWrite = ((Sw==1) && (Alu_resultHigh[21:0] != 22'b1111111111111111111111)) ? 1'b1:1'b0;
    assign MemRead =   ((Alu_resultHigh[21:0] != 22'b1111111111111111111111) && Lw==1) ? 1'b1:1'b0;   // ���洢��
    assign IORead =  ( (Alu_resultHigh[21:0] == 22'b1111111111111111111111) && Lw) ? 1'b1:1'b0;// ���˿�
    assign IOWrite = ( (Alu_resultHigh[21:0] == 22'b1111111111111111111111) && Sw)? 1'b1:1'b0; // д�˿�
   assign MemorIOtoReg = IORead || MemRead; //��������Ҫ�Ӷ˿ڻ�洢�������ݵ��Ĵ���
   
   
    assign R_format = (Opcode==6'b000000)? 1'b1:1'b0;    	//--00h 
    assign RegDST = R_format;                               //˵��Ŀ����rd��������rt
    assign I_format = (Opcode[5:3] == 3'b001)? 1:0; 
    assign Lw = (Opcode == 6'b100011)? 1:0; 
    assign Jal = (Opcode == 6'b000011)? 1:0; 
    assign Jrn = (Opcode == 6'b000000 && Function_opcode == 6'b001000)? 1:0; 

    assign RegWrite = ( Jrn != 1&&(I_format==1 || Lw==1 || Jal==1 || R_format==1 ))? 1:0;
    assign Sw = (Opcode ==  6'b101011) ? 1: 0;
    assign ALUSrc = (I_format == 1 || Opcode == 6'b100011 ||  Opcode == 6'b100011||Opcode == 6'b101011)? 1:0;
    assign Branch = (Opcode == 6'b000100) ? 1:0;
    assign nBranch = (Opcode == 6'b000101) ? 1:0;
    assign Jmp = (Opcode == 6'b000010) ? 1:0; 
    
    
    
    assign Sftmd = (Opcode == 6'b000000 &&(Function_opcode == 6'b000000 ||Function_opcode== 6'b000010 )) ? 1: 0;
  
    assign ALUOp = {(R_format || I_format),(Branch || nBranch)};  // ��R��type����Ҫ��������32λ��չ��ָ��1λΪ1,beq��bneָ����0λΪ1
endmodule
