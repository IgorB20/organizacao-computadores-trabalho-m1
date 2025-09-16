//
//  main.cpp
//  trabalho-m1-organiz. de computadores
//
//  Created by Igor Benedet on 10/09/25.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void readU(string instruction){
    char type = 'U';
    string opcode;
    string rd, imm;
    
    opcode = instruction.substr(instruction.size() - 8, instruction.size());
    rd = instruction.substr(instruction.size() - 12, instruction.size() - 8);
    imm = instruction.substr(0, instruction.size() - 12);
    /*
        opcode 0:6
        rd 7:11
        imm 12:31
    */
}

void readR(){
    /*
        opcode 0:6
        rd 7:11
        funct3 12:14
        rs1 15:19
        rs2 20:24
        funct7 25:31
    */
}


int main(int argc, const char * argv[]) {
    
    string line;

    // Read from the text file
    ifstream MyReadFile("fib_rec_binario.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, line)) {
      int opcodeStartIndex = line.size() - 8;
      
      // ler opcode - bits de 0 a 6 ( 7 bits )
      char type;
      string opcode = line.substr(opcodeStartIndex, line.size());
      
     
      if(opcode == "0110111") type = 'U';
      if(opcode == "1101111") type = 'J';
      if(opcode == "1100111" || opcode == "0010011" || opcode == "0001111" || opcode == "0001111") type = 'I';
      if(opcode == "1100011") type = 'B';
      if(opcode == "0100011") type = 'S';
      if(opcode == "0110011") type = 'R';
        
        
      cout << opcode << " " << line.size() << endl;
    }
}
