#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

enum Instructions {
	INVALID,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	SLT,
	SLTU,
	SLL,
	SRL,
	SRA,
	ADDI,
	ANDI,
	ORI,
	XORI,
	SLTI,
	SLTUI,
	SLLI,
	SRLI,
	SRAI,
	LW,
	SW
};

Instructions resolveInstruction(std::string input) {
    if( input == "add" ) return ADD;
    if( input == "sub" ) return SUB;
    if( input == "and" ) return AND;
    if( input == "or" )  return OR;
    if( input == "xor" ) return XOR;
    if( input == "slt" ) return SLT;
    if( input == "sltu" )return SLTU;
    if( input == "sll" ) return SLL;
    if( input == "srl" ) return SRL;
    if( input == "sra" ) return SRA;
    if( input == "addi" ) return ADDI;
    if( input == "andi" ) return ANDI;
    if( input == "ori" )  return ORI;
    if( input == "xori" ) return XORI;
    if( input == "slti" ) return SLTI;
    if( input == "sltui" )return SLTUI;
    if( input == "slli" ) return SLLI;
    if( input == "srli" ) return SRLI;
    if( input == "srai" ) return SRAI;
    if( input == "lw" ) return LW;
    if( input == "sw" ) return SW;
    return INVALID;
}

void TypeR(string &line, string &rd, string &rs1, string &rs2, int &opcode, string &instruction){
	rd = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	rs1 = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	rs2 = line;

	opcode = resolveInstruction(instruction);
}

void TypeI(string &line, string &rd, string &rs1, string &imm, int &opcode, string &instruction){
	rd = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	rs1 = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	imm = line;

	opcode = resolveInstruction(instruction);
}

void TypeL(string &line, string &rd, string &imm, string &rs1, int &opcode, string &instruction){
	rd = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	imm = line.substr(0, line.find('('));
	line.erase(0, line.find('(')+1);

	rs1 = line.substr(0, line.find(')'));
	line.erase(0, line.find(')')+1);

	opcode = resolveInstruction(instruction);
}

void TypeS(string &line, string &rd, string &imm, string &rs1, int &opcode, string &instruction){
	rd = line.substr(0, line.find(','));
	line.erase(0, line.find(',')+1);

	imm = line.substr(0, line.find('('));
	line.erase(0, line.find('(')+1);

	rs1 = line.substr(0, line.find(')'));
	line.erase(0, line.find(')')+1);

	opcode = resolveInstruction(instruction);
 }

int main(){
	string filename = "test.txt";
	ifstream input;

	input.open(filename);
	if(!input.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
		return 0;
	}

	string instructionMemory[100];
	int i = 0;

	while(input.peek() != EOF){
		getline(input,	instructionMemory[i], '\n');
		i++;		
	}

	int PROGRAM_COUNTER = 0;
	string end = "exit";

	while(instructionMemory[PROGRAM_COUNTER].compare(end) != 0){
		string line = instructionMemory[PROGRAM_COUNTER];

		string instruction = line.substr(0, line.find(' '));
		line.erase(0, line.find(' ')+1);

		line.erase(remove(line.begin(), line.end(), ' '), line.end());

		string rd, rs1, rs2;
		int opcode = -1;

		switch(resolveInstruction(instruction)){
			case ADD:
			case SUB:
			case AND:
			case OR :
			case XOR:
			case SLT:
			case SLTU:
			case SLL:
			case SRL:
			case SRA:
				TypeR(line, rd, rs1, rs2, opcode, instruction);
			break;
			case ADDI:
			case ANDI:
			case ORI:
			case XORI:
			case SLTI:
			case SLTUI:
			case SLLI:
			case SRLI:
			case SRAI:
				TypeI(line, rd, rs1, rs2, opcode, instruction);
			break;
			case LW:
				TypeL(line, rd, rs1, rs2, opcode, instruction);
			break;
			case SW:
				TypeS(line, rd, rs1, rs2, opcode, instruction);
			break;
			default:
				cout << "'" << instruction << "' es una instruccion invalida \n";
			break;
		}

		cout << "'" << PROGRAM_COUNTER << " " << opcode << " " << instruction << " " << rd << " " << rs1 << " " << rs2 << "'" <<'\n';
		PROGRAM_COUNTER += 1;
	}

	input.close();

	return 0;
}
