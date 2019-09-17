


#include <vector>

class Card
{

private:


    std::vector<unsigned int> card;

public:

    Card(unsigned int Width, unsigned int Height, unsigned int DrumMaxNumber);


    const unsigned int Width;
    const unsigned int Height;

    unsigned int &operator[](int index)
    {
        return card[index];
    }

};


