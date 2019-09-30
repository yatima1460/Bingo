#include <algorithm>
#include <Settings.hpp>
#include "PrizeSystem.hpp"

std::vector<Prize> PrizeSystem::prizesRegistered;
unsigned int PrizeSystem::bingoValue;

unsigned int PrizeSystem::checkCard(Card& card, const std::vector<unsigned int>& extracted)
{



    // Create lookup table for O(1) check if a number was extracted
    unsigned int maxNExtracted = *std::max_element(std::begin(extracted), std::end(extracted));
    unsigned int maxNCard = *std::max_element(std::begin(card.NUMBERS), std::end(card.NUMBERS));
    std::vector<unsigned int> lookup(std::max(maxNExtracted, maxNCard) + 1);
    for (unsigned int j : extracted)
        lookup[j] = 1;


    // First check special case of Bingo
    bool bingo = true;
    for (size_t i = 0; i < card.WIDTH * card.HEIGHT; i++)
    {
        if (lookup[card[i]] == 0)
        {
            bingo = false;
            break;
        }
    }
    if (bingo)
        return bingoValue;

    // TODO: fix this ugly code
    for (Prize& p : prizesRegistered)
    {
        unsigned int rowsMatched = 0;
        for (size_t row = 0; row < card.HEIGHT; row++)
        {
            bool rowMatch = true;
            for (size_t column = 0; column < card.WIDTH; column++)
            {
                size_t index = row * card.WIDTH + column;

                unsigned int cardNumber = card[index];
                if (lookup[cardNumber] == 0)
                {
                    rowMatch = false;
                    break;
                }
            }
            if (rowMatch)
            {
                rowsMatched++;
            }
        }

        unsigned int columnsMatched = 0;
        for (size_t column = 0; column < card.WIDTH; column++)
        {
            bool columnMatch = true;
            for (size_t row = 0; row < card.HEIGHT; row++)
            {
                size_t index = row * card.WIDTH + column;

                unsigned int cardNumber = card[index];
                if (lookup[cardNumber] == 0)
                {
                    columnMatch = false;
                    break;
                }
            }
            if (columnMatch)
            {
                columnsMatched++;
            }
        }

        if (rowsMatched >= p.MINIMUM_ROWS && columnsMatched >= p.MINIMUM_COLUMNS)
            return p.VALUE * rowsMatched + p.VALUE * columnsMatched;

    }

    return 0;
}

std::string PrizeSystem::toString()
{
    std::stringstream ss;
    for (Prize p: prizesRegistered)
    {
        ss << p.toString() << ",";
    }
    if (bingoValue)
        ss << "B" << bingoValue;
    return ss.str();
}

void PrizeSystem::setBingo(unsigned int credits)
{
    bingoValue = credits;
}

struct custom_prizes_sort
{
    inline bool operator()(const Prize& struct1, const Prize& struct2)
    {
        // FIXME: should prizes be sorted by area or by value?
        //return (struct1.MINIMUM_COLUMNS * struct1.MINIMUM_ROWS > struct2.MINIMUM_COLUMNS * struct2.MINIMUM_ROWS);
        return struct1.VALUE > struct2.VALUE;
    }
};


bool parsePrize(const std::string& prizeString, Prize& out)
{
    const std::string::size_type posC = prizeString.find('C');
    const std::string creditsString = prizeString.substr(posC + 1);
    for (char s : creditsString)
        if (!isdigit(s))
            return false;

    const std::string::size_type posV = prizeString.find('V');
    const std::string columnsString = prizeString.substr(posV + 1, posC - posV - 1);
    for (char s : columnsString)
        if (!isdigit(s))
            return false;

    const std::string::size_type posH = prizeString.find('H');

    if (posH != 0)
        return false;

    const std::string rowsString = prizeString.substr(1, posV - 1);
    for (char s : rowsString)
        if (!isdigit(s))
            return false;


    unsigned int prizeValue;
    unsigned int prizeRows;
    unsigned int prizeColumns;

    std::stringstream css(creditsString);
    css >> prizeValue;
    std::stringstream vss(columnsString);
    vss >> prizeColumns;
    std::stringstream hss(rowsString);
    hss >> prizeRows;

    if (prizeValue == 0)
        return false;

    if (prizeRows == 0 && prizeColumns == 0)
        return false;

    out = Prize(prizeRows, prizeColumns, prizeValue);

    return true;
}

bool PrizeSystem::load()
{

    std::string prizesString;
    try
    {
        prizesString = Settings::get<std::string>("prizes");
    }
    catch (std::invalid_argument& e)
    {
        return false;
    }


    //FIXME: ugly code ahead, maybe use JSON for settings next time?
    std::replace(prizesString.begin(), prizesString.end(), ',', ' ');  // replace ',' by ' '

    std::vector<std::string> array;
    std::stringstream ss(prizesString);
    std::string temp;
    while (ss >> temp)
        array.push_back(temp);

    for (const std::string& prizeString : array)
        if (!addPrize(prizeString))
            return false;

    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
    return true;
}

std::vector<Prize>& PrizeSystem::getPrizes()
{
    return prizesRegistered;
}

unsigned int PrizeSystem::getBingoValue()
{
    return bingoValue;
}

bool PrizeSystem::save()
{
    Settings::set("prizes", toString());
    return Settings::save();
}

void PrizeSystem::removePrize(unsigned int index)
{
    prizesRegistered.erase(prizesRegistered.begin() + index);

    //FIXME: is sort really needed with erase?
    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
}

bool PrizeSystem::addPrize(const std::string& prizeString)
{
    // error another same code

    for (Prize& p : prizesRegistered)
    {
        if (p.toString() == prizeString)
            return false;
    }

    if (prizeString.length() == 0)
        return false;

    switch (prizeString[0])
    {
        case 'B':
        {
            std::stringstream ssbingo(prizeString.substr(1));
            auto ss = ssbingo.str();
            for (char s : ss)
                if (!isdigit(s))
                    return false;
            ssbingo >> bingoValue;
            break;
        }
        case 'H':
        {
            Prize p;
            if (!parsePrize(prizeString, p))
                return false;
            else
            {
                prizesRegistered.emplace_back(p);
                std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());

            }

            break;
        }
        default:
            //FIXME: exceptions instead of return false?
            return false;
    }


    return true;
}


void PrizeSystem::addPrize(unsigned int minRows, unsigned int minColumns, unsigned int value)
{


    prizesRegistered.emplace_back(minRows, minColumns, value);


    std::sort(prizesRegistered.begin(), prizesRegistered.end(), custom_prizes_sort());
}
