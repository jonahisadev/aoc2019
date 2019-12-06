#include <vector>
#include <iostream>
#include <fstream>
#include <string>

enum Opcode
{
    ADD = 1,
    MUL = 2,
    HLT = 99
};

void read_inst(std::vector<int>& inst)
{
    std::string buffer;
    
    std::ifstream file("input.txt");
    std::getline(file, buffer);
    file.close();

    size_t pos = 0;
    while ((pos = buffer.find(',')) != std::string::npos) {
        std::string token = buffer.substr(0, pos);
        inst.push_back(std::stoi(token));
        buffer.erase(0, pos + 1);
    }
}

int equation(int noun, int verb)
{
    return (((noun * 27) + 52) * 10000) + (625 + verb);
}

int main()
{
    std::vector<int> inst;
    read_inst(inst);

    int pc = 0;

    // Set noun and verb
    int noun = 71;
    int verb = 95;

    std::cout << "Equation yields " << equation(noun, verb) << " for noun(" << noun << 
        ") and verb(" << verb << ")" << std::endl;

    inst[1] = noun;
    inst[2] = verb;

    // Loop
    while (inst.at(pc) != Opcode::HLT) {
        int x = inst.at(inst.at(pc + 1));
        int y = inst.at(inst.at(pc + 2));
        int loc = inst.at(pc + 3);

        int opcode = inst.at(pc);
        switch (opcode) {
            case Opcode::ADD: {
                inst[loc] = x + y;
                break;
            }

            case Opcode::MUL: {
                inst[loc] = x * y;
                break;
            }

            default: {
                std::cout << "Error at PC " << pc << std::endl;
                break;
            }
        }

        pc += 4;
    }

    std::cout << "Final value: " << inst.at(0) << std::endl;

    return 0;
}