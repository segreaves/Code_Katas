#include <iostream>

bool RobotReturnToOrigin(std::string moves)
{
    int x{0}, y{0};
    for (const auto& move : moves)
    {
        if (move == 'U') y++;
        else if (move == 'D') y--;
        else if (move == 'L') x--;
        else if (move == 'R') x++;
    }
    return x == 0 && y == 0;
}

int main()
{
    std::cout << "Should be true: " << (RobotReturnToOrigin("UD") ? "true" : "false") << std::endl;
    std::cout << "Should be false: " << (RobotReturnToOrigin("LL") ? "true" : "false") << std::endl;
}