#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string filename = "test.txt";
	ifstream input;

	input.open(filename);
	if(!input.is_open()){
		cout << "No se pudo abrir el archivo" << endl;
		return 0;
	}

	while(input.peek() != EOF){
		string instruction;
		getline(input, instruction, ' ');

		int imm1, imm2, result;
		input >> imm1;
		input >> imm2;

		//Este get es para deshacerse del ultimo '\n' de cada linea
		input.get();

		if(instruction == "addi"){
			result = imm1 + imm2;
		} else {
			cout << instruction << " es una instruccion inválida!!" << endl;
			continue;
		}

		cout << instruction << " " << imm1 << " " << imm2 << " ---> " << result << '\n';
	}

	input.close();

	return 0;
}