#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<regex>
#include<fstream>

#define ArraySize 32

class PCB {
	char memory[ArraySize];
	int startIndex = 4;
	
	bool isOutRange(char adrr){ return adrr >= 0 && adrr < ArraySize;}
public:
	bool status = true;
	std::shared_ptr<std::vector<std::string>> program;

	PCB() { 
		for (int i = 0; i < ArraySize; ++i) { memory[i] = 0; } 
		program = std::make_shared<std::vector<std::string>>(); 
	}
	PCB(std::string program_adrr) : PCB() {
		std::string bufor;
		std::ifstream in(program_adrr);
		std::cout << program_adrr << "\n";
		while (in >> bufor) {
			for (char& c : bufor) { c = std::toupper(c); }
			this->program->push_back(bufor);
		}
		in.close();
	}
	PCB(const PCB& pcb) :PCB(){
		startIndex = pcb.startIndex;
		program = pcb.program;
	}
	
	void writeInMemory(int adrr, char value){
		adrr += startIndex;
		this->memory[adrr] = value;
	}
	char readFromMemory(char adrr){
		adrr += startIndex;
		return memory[adrr];
	}
	char getAX() { return memory[0]; }
	char getBX() { return memory[1]; }
	char getCX() { return memory[2]; }
	char getDX() { return memory[3]; }

	void setAX(char value) { memory[0] = value; }
	void setBX(char value) { memory[1] = value; }
	void setCX(char value) { memory[2] = value; }
	void setDX(char value) { memory[3] = value; }

	void printMemory() {
		for (int i = 0; i < ArraySize; ++i) { std::cout<<static_cast<int>(memory[i]) <<"|"; }
	}
};