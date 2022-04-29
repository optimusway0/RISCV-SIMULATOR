#include <systemc.h>
using namespace std;

typedef tuple<int, string> tag;

class InstructionMemory : public sc_module {
	public:
		sc_in<sc_int<32>> counterIn;

		sc_out<sc_uint<5>> rd;
		sc_out<sc_uint<5>> rs1;
		sc_out<sc_uint<5>> rs2;
		sc_out<sc_int<12>> imm;

		sc_out<sc_uint<5>> opcode;

		string memory[200];
		vector<tag> tags;

		SC_CTOR( InstructionMemory );
		~InstructionMemory();
	private:
		void read();
		int searchForTag(string);
};