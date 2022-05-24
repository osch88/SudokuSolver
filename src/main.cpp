#include "puzzle.h"
#include "importer.h"
#include <chrono>
#include <vector>

int main(int argc, char *argv[])
{
    std::string filename = "../data/input/rashid.txt";
    std::vector<std::string> allSudokus;

    auto startMaster = std::chrono::high_resolution_clock::now();

    if (fileToVector(filename, allSudokus))
    {
        unsigned int i = 1;
        for (std::string &oneLine : allSudokus)
        {
            auto start = std::chrono::high_resolution_clock::now();

            std::cout << "Line: " << i++ << std::endl;
            Puzzle puzzle(oneLine);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            std::cout << "Number of guesses:\t" << puzzle.getAmountOfGuesses() << std::endl;
            std::cout << "Timestamp:\t" << duration.count() << " milliseconds\n"
                      << std::endl;

            std::cout << "=======================================================================================================\n";
        }
    }

    auto stopMaster = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopMaster - startMaster);
    std::cout << "Timestamp:\t" << duration.count() << " milliseconds\n"
              << std::endl;

    return 0;
}
