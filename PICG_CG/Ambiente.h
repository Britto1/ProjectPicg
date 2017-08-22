#ifndef AMBIENTE_H
#define AMBIENTE_H





#include <vector>


using namespace std;


class Ambiente
{
    float sizeIlha;

    public:
        Ambiente(float sizeIlha); //em porcentagem
        void criarIlha(vector<vector<char>> &mundo);
        void criarOceano(vector<vector<char>> &mundo);
        void desenharAmbiente(vector<vector<char>> mundo);
        int getAreaI(vector<vector<char>> mundo);
        virtual ~Ambiente();
        Ambiente(const Ambiente& other);
        Ambiente& operator=(const Ambiente& other);

    protected:

    private:
};

#endif // AMBIENTE_H
