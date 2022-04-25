#include <fstream>
#include <iostream>
#include <algorithm>
#include "InstructionMemory.h"

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
  SW,
  BEQ,
  BNE,
  BLT,
  BGE
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
    if( input == "beq" ) return BEQ;
    if( input == "bne" ) return BNE;
    if( input == "blt" ) return BLT;
    if( input == "bge" ) return BGE;
    return INVALID;
}

void TypeR(string &line, int &rd, int &rs1, int &rs2){
  string temp;
  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rd = stoi(temp);

  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+2);
  rs1 = stoi(temp);

  rs2 = stoi(line);
}

void TypeI(string &line, int &rd, int &rs1, int &imm){
  string temp;
  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rd = stoi(temp);

  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rs1 = stoi(temp);

  imm = stoi(line);
}

void TypeL(string &line, int &rd, int &rs1, int &imm){
  string temp;
  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rd = stoi(temp);

  temp = line.substr(0, line.find('('));
  line.erase(0, line.find('(')+2);
  imm = stoi(temp);

  temp = line.substr(0, line.find(')'));
  rs1 = stoi(temp);
}

void TypeS(string &line, int &rs1, int &rs2, int &imm){
  string temp;
  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rs2 = stoi(temp);

  temp = line.substr(0, line.find('('));
  line.erase(0, line.find('(')+2);
  imm = stoi(temp);

  temp = line.substr(0, line.find(')'));
  rs1 = stoi(temp);
 }

void TypeB(string &line, int &rd, int &rs1, int &imm){
  string temp;
  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rd = stoi(temp);

  temp = line.substr(1, line.find(','));
  line.erase(0, line.find(',')+1);
  rs1 = stoi(temp);

  imm = stoi(line);
}

InstructionMemory::InstructionMemory(sc_module_name nm) : sc_module(nm) {

  //Guardamos el programa en Memoria

  string filename = "test.txt";
  ifstream input;

  input.open(filename);
  if(!input.is_open()){
    cout << "No se pudo abrir el archivo" << endl;
  }

  int i = 0;

  while(input.peek() != EOF){
    getline(input, memory[i], '\n');
    i++;    
  }

  input.close();

  // Se lee una instruccion cada vez que el contador de programa cambie

  SC_METHOD(read);
  sensitive << counterIn;
}

void InstructionMemory::read() {
  int PC = counterIn.read();
  string line = memory[PC];

  //Leemos la instruccion (ADD, OR, SUB, etc..)
  string instruction = line.substr(0, line.find(' '));
  line.erase(0, line.find(' ')+1);

  //Eliminamos los espacios ' '
  line.erase(remove(line.begin(), line.end(), ' '), line.end());

  int _rd = 0, _rs1 = 0, _rs2 = 0, _imm = 0;
  int _opcode = resolveInstruction(instruction);

  //Segun el tipo de instruccion leemos los datos de manera diferente
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
      TypeR(line, _rd, _rs1, _rs2);
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
      TypeI(line, _rd, _rs1, _imm);
    break;
    case LW:
      TypeL(line, _rd, _rs1, _imm);
    break;
    case SW:
      TypeS(line, _rs1, _rs2, _imm);
    break;
    case BEQ:
    case BNE:
    case BLT:
    case BGE:
      TypeB(line, _rd, _rs1, _rs2);
    break;
    default:
      cout << "'" << instruction << "' es una instruccion invalida \n";
      return;
    break;
  }

  rd.write(_rd);
  rs1.write(_rs1);
  rs2.write(_rs2);
  opcode.write(_opcode);
  imm.write(_imm);

}

InstructionMemory::~InstructionMemory(){

}
