#include <iostream>
#include "Problem.h"
#include "KnapsackProblem.h"
#include "geneticAlgorithm.h"
#include "UnexpectedArgumentException.h";
#include "InvalidPathException.h"
#include "OutOfDomainException.h"
using namespace std;

int main() {

   
    try {
        cout << "Path to file with problem data: ";
        string path;
        cin >> path;
        KnapsackProblem* p = new KnapsackProblem(path);
        GeneticAlgorithm g{ *p, 10, 0.6, 0.01, 40 };
        g.run();

        cout << "solution value:";
        cout << g.getBestResult().getFitness() << endl;

        vector<int> answer{ g.getBestResult().getAnswer() };
        for (int i = 0; i < p->getGenotypeSize(); i++) {
            cout << answer[i];
            cout << " ";
        }

        delete p;
    }
    catch (UnexpectedArgumentException& e) {
        std::cout << e.what();
    }
    catch (InvalidPathException& e) {
        std::cout << e.what();
    }
    catch (OutOfDomainException& e) {
        std::cout << e.what();
    }
}