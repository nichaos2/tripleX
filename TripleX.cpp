#include <iostream>

void PrintIntroduction(int Difficulty)
{
    std::cout << " _                       _                     _            \n";
    std::cout << "(_)                     | |                   | |           \n";
    std::cout << " _  _ __   _ __   _   _ | |_    ___  ___    __| |  ___  ___ \n";
    std::cout << "| || '_ \\ | '_ \\ | | | || __|  / __|/ _ \\  / _` | / _ \\/ __|\n";
    std::cout << "| || | | || |_) || |_| || |_  | (__| (_) || (_| ||  __/\\__ \\ \n";
    std::cout << "|_||_| |_|| .__/  \\__,_| \\__|  \\___|\\___/  \\__,_| \\___||___/\n";
    std::cout << "          | |                                               \n";
    std::cout << "          |_| \n";
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " level secure server room...\nYou need to enter the correct codes to continue...";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //
    std::cout << "\nHints:";
    std::cout << "\n+ There are 3 codes.";
    std::cout << "\n+ The codes add up to : " << CodeSum;
    std::cout << "\n+ The codes multiply to give : " << CodeProduct;

    //
    int GuessA, GuessB, GuessC;
    std::cout << "\nEnter your code here...\n";
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "\nYou entered: " << GuessA << " " << GuessB << " " << GuessC;

    //
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << "\nYour codes add up to : " << GuessSum;
    std::cout << "\nYour codes multiply to give : " << GuessProduct << "\n";

    //TODO replace string with a variable
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You win";
        return true;
    }
    else
    {
        std::cout << "You lose";
        return false;
    }
    

}
int main()
{
    int MaxLevel = 10;
    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            // increase the lvl
            ++LevelDifficulty;
        }
    }
    return 0;
}
