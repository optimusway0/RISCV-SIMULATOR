#include <iostream>
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
	SRA
};

Instructions resolveInstruction(std::string input) {
    if( input == "add" ) return ADD;
    if( input == "sub" ) return SUB;
    if( input == "and" ) return AND;
    if( input == "or" )  return OR;
    if( input == "xor" ) return XOR;
    if( input == "slt" ) return SLT;
    if( input == "sltu" ) return SLTU;
    if( input == "sll" ) return SLL;
    if( input == "srl" ) return SRL;
    if( input == "sra" ) return SRA;
    return INVALID;
 }

 void TypeR(ifstream &input, string &rd, string &rs1, string &rs2, int &opcode, string &instruction){
	getline(input, rd, ' ');
	getline(input, rs1, ' ');
	getline(input, rs2, '\n');
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

	int PROGRAM_COUNTER = -1;

	while(input.peek() != EOF){
		PROGRAM_COUNTER += 1;
		string instruction;
		getline(input, instruction, ' ');

		string rd, rs1, rs2, panic;
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
				TypeR(input, rd, rs1, rs2, opcode, instruction);
			break;
			default:
				getline(input, panic, '\n');
				cout << instruction << " es una instruccion invalida \n";
				continue;
			break;
		}	

		cout << "'" << PROGRAM_COUNTER << " " << opcode << " " << instruction << " " << rd << " " << rs1 << " " << rs2 << "'" <<'\n';
	}

	input.close();

	return 0;
}