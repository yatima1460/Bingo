#pragma once


#include <Prize.hpp>

class PrizeSystem
{

private:

    static std::vector<Prize> prizesRegistered;

    static unsigned int bingoValue;


public:


    /**
     * Gets a string representation of the prizes saved, useful to be serialized or console debug reasons
     * @return
     */
    static std::string toString();

    /**
     * Adds a prize to the PrizeSystem
     * @param minRows
     * @param minColumns
     * @param value credits for the prize
     */
    static void addPrize(unsigned int minRows, unsigned int minColumns, unsigned int value);


    static void removePrize(unsigned int index);


    /**
     * Given a card and extracted numbers returns the amount of prize
     * @param card
     * @return
     */
    static unsigned int checkCard(Card& card, const std::vector<unsigned int>& extracted);

    /**
     * The bingo is a special bonus, it means when all rows and columns are marked
     * The bingo value CAN be 0
     * @param credits value of the bonus
     */
    static void setBingo(unsigned int credits);


    /**
     * Loads the prizes from Settings.ini
     * @return true on success, false on error
     */
    static bool load();


    static std::vector<Prize>& getPrizes();

    static unsigned int getBingoValue();


    [[nodiscard]] static bool save();
};