//
//  main.cpp
//  trabalho-m1-organiz. de computadores
//
//  Created by Igor Benedet on 10/09/25.
//


#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

struct U {
    
};

string readOpcode(string binary){
    return binary.substr(25, 7); // 6:0
}

string readRd(string binary){
    return binary.substr(20,    5); // 7:11
}

string readFunct3(string binary) {
    return binary.substr(17, 3); // 12:14
}

string readRs1(string binary) {
    return binary.substr(12, 5); // 15:19
}

string readRs2(string binary) {
    return binary.substr(7, 5); // 20:24
}

string readFunct7(string binary) {
    return binary.substr(0, 7); // 25:31
}

void readB(string instruction){
    /*
        opcode 0:6
        rd 7:11
        rs1
        rs2
        funct3
        imm 11
        imm 4:1
        imm 10:5
        imm 12
    */
    char type = 'B';
    string opcode = readOpcode(instruction);
    string rs1Bin = readRs1(instruction);
    string funct3Bin = readFunct3(instruction);
    string imm4_1    = instruction.substr(31-11, 4);
    string imm11    = instruction.substr(31-8, 1);
    string imm10_5  = instruction.substr(31-30, 6);
    string imm12 = instruction.substr(0, 1);
    string immTotal = imm12 + imm11 + imm10_5 + imm4_1 + "0";
    
    std::bitset<5> rs1(rs1Bin);
    std::bitset<3> funct3(funct3Bin);
    std::bitset<14> imm(immTotal);
    
    cout << instruction << " " << "formato: " << type << " "
     << "opcode: " << opcode << " "
         << "rs1: " << rs1.to_ulong() << " "
         << "funct3: " << funct3.to_ulong() << " "
         << "imm[4:1]: " << imm4_1 << " "
         << "imm[11]: " << imm11 << " "
         << "imm[10:5]: " << imm10_5 << " "
         << "imm[12]: " << imm12 << " "
    << "imediato: " << imm << endl;
            
}

void readU(string instruction){
    
    /*
        opcode 0:6
        rd 7:11
        imm 12:31
    */
    char type = 'U';

    string opcode = readOpcode(instruction);
    string rdBin = readRd(instruction);
    string imm = instruction.substr(0, 20); // adicionar LBS ?
 
    std::bitset<5> rd(rdBin);
    
    cout << instruction << " " << "formato: " << type << " ";
    cout << "opcode: " << opcode << " ";
    cout << "rd: " << rd.to_ulong() << " ";
    cout << "imm:" << imm << " " << endl;
}

void readJ(string instruction){
    /*
        opcode 0:6
        rd 7:11
        imm[19:12]
        imm[11]
        imm[10:1]
        imm[20]
    */
    
    char type = 'J';
    string opcode = readOpcode(instruction);
    string rdBin = readRd(instruction);
    string imm20    = instruction.substr(0, 1);    // bit 31
    string imm10_1  = instruction.substr(1, 10);   // bits 30–21
    string imm11    = instruction.substr(11, 1);   // bit 20
    string imm19_12 = instruction.substr(12, 8);
    string immTotal = imm20 + imm19_12 + imm11 + imm10_1;
    
    std::bitset<5> rd(rdBin);
    
    cout << instruction << " " << "formato: " << type << " ";
    cout << "opcode: " << opcode << " ";
    cout << "rd: " << rd.to_ulong() << " ";
    cout << "imm19_12: " << imm19_12 << " ";
    cout << "imm11: " << imm11 << " ";
    cout << "imm10_1: " << imm10_1 << " ";
    cout << "imm20: " << imm20 << " ";
    cout << "imediato: " << immTotal << endl;
}

void readR(string instruction) {
    /*
        opcode 0:6
        rd 7:11
        funct3[12:14]
        rs1[15: 19]
        rs2[20:24]
        funct7[25]
    */
    char type = 'R';
    string opcode;
    string rdBin, funct3Bin, rs1Bin, rs2Bin, funct7Bin;


    opcode = readOpcode(instruction);
    rdBin = readRd(instruction);
    funct3Bin = readFunct3(instruction);
    rs1Bin = readRs1(instruction);
    rs2Bin = readRs2(instruction);
    funct7Bin = readFunct7(instruction);

    std::bitset<5> rd(rdBin);
    std::bitset<3> funct3(funct3Bin);
    std::bitset<5> rs1(rs1Bin);
    std::bitset<5> rs2(rs2Bin);
    std::bitset<5> funct7(rs1Bin);

    cout << instruction << " " << "formato: " << type << " ";
    cout << "opcode: " << opcode << " ";
    cout << "rd: " << rd.to_ulong() << " ";
    cout << "funct3:" << funct3.to_ulong() << " ";
    cout << "rs1:" << rs1.to_ulong() << " ";
    cout << "rs2:" << rs2.to_ulong() << " ";
    cout << "funct7:" << funct7.to_ulong() << " " << endl;
}

void readI(string instruction) {
    /*
        opcode 0:6
        rd 7:11
        funct3[12:14]
        rs1[15: 19]
        imm[20:31]
    */
    char type = 'I';
    string opcode;
    string rdBin, funct3Bin, rs1Bin, imm;

    opcode = readOpcode(instruction);
    rdBin = readRd(instruction);
    funct3Bin = readFunct3(instruction);
    rs1Bin = readRs1(instruction);
    imm = instruction.substr(0, 12);
    
    std::bitset<5> rd(rdBin);
    std::bitset<3> funct3(funct3Bin);
    std::bitset<5> rs1(rs1Bin);
    
    cout << instruction << " " << "formato: " << type << " ";
    cout << "opcode: " << opcode << " ";
    cout << "rd: " << rd.to_ulong() << " ";
    cout << "funct3:" << funct3.to_ulong() << " ";
    cout << "rs1:" << rs1.to_ulong() << " ";
    cout << "imm:" << imm << " " << endl;
}

void readS(string instruction) {
    
    /*
        opcode 0:6
        rd 7:11
        funct3[12:14]
        rs1[15: 19]
        imm[20:31]
    */

    
    char type = 'S';
    string opcode;
    string imm4_0, funct3Bin, rs1Bin, rs2Bin, imm11_5;

    opcode = readOpcode(instruction);
    funct3Bin = readFunct3(instruction);
    rs1Bin = readRs1(instruction);
    rs2Bin = readRs2(instruction);
    imm4_0 = readRd(instruction);
    imm11_5 = readFunct7(instruction);
    
    std::bitset<3> funct3(funct3Bin);
    std::bitset<5> rs1(rs1Bin);
    std::bitset<5> rs2(rs2Bin);
    
    string immTotal = imm11_5 + imm4_0;
    
    cout << instruction << " " << "formato: " << type << " ";
    cout << "opcode: " << opcode << " ";
    cout << "imm4_0: " << imm4_0 << " ";
    cout << "funct3:" << funct3.to_ulong() << " ";
    cout << "rs1:" << rs1.to_ulong() << " ";
    cout << "rs2:" << rs2.to_ulong() << " ";
    cout << "imm11_5:" << imm11_5 << " ";
    cout << "imediato: " << immTotal << endl;
}


int main(int argc, const char * argv[]) {
    
    string line;
    ifstream MyReadFile("fib_rec_binario.txt");

    while (getline (MyReadFile, line)) {
       string opcode = readOpcode(line);
      
        if(opcode == "0110111") readU(line);
        if(opcode == "1101111") readJ(line);
        if(opcode == "1100111"
           || opcode == "0010011"
           || opcode == "0001111"
           || opcode == "0001111") readI(line);
        if(opcode == "1100011") readB(line);
        if(opcode == "0100011") readS(line);
        if(opcode == "0110011") readR(line);
    }
}
