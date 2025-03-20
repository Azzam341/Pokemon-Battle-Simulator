#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;
float typechart[18][18] = {
    // NOR  FIR  WAT  ELE  GRA  ICE  FIG  POI  GRO  FLY  PSY  BUG  ROC  GHO  DRA  DAR  STE NONE
    { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0.5, 0,   1,   1,   0.5, 1 }, // NOR
    { 1,   0.5, 0.5, 1,   2,   2,   1,   1,   1,   1,   1,   2,   0.5, 1,   0.5, 1,   2,   1 }, // FIR
    { 1,   2,   0.5, 1,   0.5, 1,   1,   1,   2,   1,   1,   1,   2,   1,   0.5, 1,   1,   1 }, // WAT
    { 1,   1,   2,   0.5, 0.5, 1,   1,   1,   0,   2,   1,   1,   1,   1,   0.5, 1,   1,   1 }, // ELE
    { 1,   0.5, 2,   1,   0.5, 1,   1,   0.5, 2,   0.5, 1,   0.5, 2,   1,   0.5, 1,   0.5, 1 }, // GRA
    { 1,   0.5, 0.5, 1,   2,   0.5, 1,   1,   2,   2,   1,   1,   1,   1,   2,   1,   0.5, 1 }, // ICE
    { 2,   1,   1,   1,   1,   2,   1,   0.5, 1,   0.5, 0.5, 0.5, 2,   0,   1,   2,   2,   1 }, // FIG
    { 1,   1,   1,   1,   2,   1,   1,   0.5, 0.5, 1,   1,   1,   0.5, 0.5, 1,   1,   0,   1 }, // POI
    { 1,   2,   1,   2,   0.5, 1,   1,   2,   1,   0,   1,   0.5, 2,   1,   1,   1,   2,   1 }, // GRO
    { 1,   1,   1,   0.5, 2,   1,   2,   1,   1,   1,   1,   2,   0.5, 1,   1,   1,   0.5, 1 }, // FLY
    { 1,   1,   1,   1,   1,   1,   2,   2,   1,   1,   0.5, 1,   1,   1,   1,   0,   0.5, 1 }, // PSY
    { 1,   0.5, 1,   1,   2,   1,   0.5, 0.5, 1,   0.5, 2,   1,   1,   0.5, 1,   2,   0.5, 1 }, // BUG
    { 1,   2,   1,   1,   1,   2,   0.5, 1,   0.5, 2,   1,   2,   1,   1,   1,   1,   0.5, 1 }, // ROC
    { 0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   2,   1,   0.5, 1,   1 }, // GHO
    { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   0.5, 1 }, // DRA
    { 1,   1,   1,   1,   1,   1,   0.5, 1,   1,   1,   2,   1,   1,   2,   1,   0.5, 1,   1 }, // DAR
    { 1,   0.5, 0.5, 0.5, 1,   2,   1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   0.5, 1}, // STE
    { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1 }  // NONE
};

enum class Typing 
{
    NORMAL = 0, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON, GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, NONE
};

string convertToString (Typing typing)
{
    switch (typing)
    {
        case Typing::FIRE:
            return "FIRE";
        case Typing::WATER:
            return "WATER";
        case Typing::GRASS:
            return "GRASS";
        case Typing::ELECTRIC:
            return "ELECTRIC";
        case Typing::PSYCHIC:
            return "PSYCHIC";
        case Typing::DARK:
            return "DARK";
        case Typing::FIGHTING:
            return "FIGHTING";
        case Typing::NORMAL:
            return "NORMAL";
        case Typing::FLYING:
            return "FLYING";
        case Typing::GROUND:
            return "GROUND";
        case Typing::STEEL:
            return "STEEL";
        case Typing::ICE:
            return "ICE";
        case Typing::POISON:
            return "POISON";
        case Typing::BUG:
            return "BUG";
        case Typing::DRAGON:
            return "DRAGON";
        case Typing::NONE:
            return "NONE";
        default:
            return "UNKNOWN";
    }
}

struct moveBehavior
{
    string moveName;
    int movePower;
    Typing moveType;
    int accuracy;

    friend ostream& operator<<(ostream& os, const moveBehavior& move) {
        os << move.moveName << " (Power: " << move.movePower << ", Type: " << convertToString(move.moveType) << ", Accuracy: " << move.accuracy << ")";
        return os;
    }

    moveBehavior makeMoves (string moveName, int movePower, Typing moveType, int accuracy)
    {
        moveBehavior move;
        move.moveName = moveName;
        move.movePower = movePower;
        move.moveType = moveType;
        move.accuracy = accuracy;
        return move;
    }
};

struct Pokemon
{
    string pokemonName;
    moveBehavior move1, move2, move3, move4;
    int atk, dfs, spatk, spdfs, speed, basehp, battlehp, level;
    Typing type1;
    Typing type2;
    
    Pokemon makePokemon (string pokemonName,Typing type1, Typing type2, moveBehavior move1, moveBehavior move2, moveBehavior move3,
        moveBehavior move4, int basehp, int battlehp, int atk,  int dfs, int spatk, int spdfs, int speed, int level)
    {
        Pokemon pokemon;
        pokemon.pokemonName = pokemonName;
        pokemon.type1 = type1;
        pokemon.type2 = type2;
        pokemon.move1 = move1;
        pokemon.move2 = move2;
        pokemon.move3 = move3;
        pokemon.move4 = move4;
        pokemon.basehp = basehp;
        pokemon.battlehp = battlehp;
        pokemon.atk = atk;
        pokemon.dfs = dfs;
        pokemon.spatk = spatk;
        pokemon.spdfs = spdfs;
        pokemon.speed = speed;
        pokemon.level = level;
        return pokemon;
    }
    
    void viewPokemonDetails(Pokemon pokemon)
    {
        cout << "Pokemon name is " << pokemon.pokemonName << endl;
        cout << "Pokemon's typing is " << convertToString(pokemon.type1) << " " << convertToString(pokemon.type2) << endl;
        cout << "Move 1: " << pokemon.move1 << endl;
        cout << "Move 2: " << pokemon.move2 << endl;
        cout << "Move 3: " << pokemon.move3 << endl;
        cout << "Move 4: " << pokemon.move4 << endl;
        cout << "HP: " << pokemon.basehp << endl;
        cout << "Attack: " << pokemon.atk << endl;
        cout << "Defense: " << pokemon.dfs << endl;
        cout << "Special Attack: " << pokemon.spatk << endl;
        cout << "Special Defense: " << pokemon.spdfs << endl;
        cout << "Speed: " << pokemon.speed << endl;
        cout << "Level: " << pokemon.level << endl;
    }
};

int calculateBattleHP (Pokemon pkmn1)
{
    int HP = ((2*pkmn1.basehp*pkmn1.level)/100) + pkmn1.level + 10;
    return HP; 
}

int getRandom (int min, int max)
{
    return min + rand() % (max - min + 1);
}

float returnTypeMultiplier (moveBehavior move, Pokemon opponent)
{   Typing movetype = move.moveType;
    Typing opponentType1 = opponent.type1;
    Typing opponentType2 = opponent.type2;
    double multipler = typechart[static_cast<int>(movetype)][static_cast<int>(opponentType1)] * typechart[static_cast<int>(movetype)][static_cast<int>(opponentType2)];
    return multipler;
}

void displayTypeeffectiveness(float multiplier)
{
    cout << endl;
    if(multiplier == 0)
    {
        cout << "This move has no effect" << endl;
    }
    else if ((multiplier == 0.5) || (multiplier == 0.25))
    {
        cout << "It's not very effective" << endl;
    }

    else if (multiplier == 1)
    {
        cout << "";
    }
    else if ((multiplier == 2) || (multiplier == 4))
    {
        cout << "It's super effective" << endl;
    }

}


float returnSameTypeAttackBonus(Pokemon pkmn, moveBehavior move)
{
    if ((pkmn.type1 == move.moveType) || (pkmn.type2 == move.moveType))
    {
        return 1.5;
    }
    return 1.0;
}

int calculateDamage(Pokemon pkmn1, Pokemon pkmn2, moveBehavior move) {
    double levelFactor = ((2.0 * pkmn1.level) / 5.0) + 2;
    double attackDefenseRatio = (double)pkmn1.atk / (double)pkmn2.dfs; // Ensure floating-point division
    double baseDamage = ((levelFactor * move.movePower * attackDefenseRatio) / 50.0) + 2;
	float dmgtypemultiplier = returnTypeMultiplier(move, pkmn2);
	float dmgstabmultiplier = returnSameTypeAttackBonus(pkmn1, move);
	double finaldamage = baseDamage*dmgtypemultiplier*dmgstabmultiplier;
    return (int)finaldamage;
}

struct HealingItems
{
    string name;
    int healedAmount;
    int quantity;

    HealingItems makeHealingItems(string name, int healedAmount, int quantity)
    {
        HealingItems item;
        item.name = name;
        item.healedAmount = healedAmount;
        item.quantity = quantity;
        return item;
    }

    int heal (Pokemon &pkmn, HealingItems &item)
    {
        
        if (item.quantity > 0)
        {
        int currenthp = pkmn.battlehp;
        int maxhp = calculateBattleHP(pkmn);
        int recoveredHp = item.healedAmount;
        currenthp = currenthp + recoveredHp;
        if(currenthp > maxhp)
        {
            currenthp = maxhp;
            item.quantity = item.quantity - 1;
            return currenthp;
        }
        item.quantity = item.quantity - 1;
        return currenthp;
    }
    else
    {
        cout << "No item left in inventory" << endl;
        return pkmn.battlehp;
    }
    }

};



int main ()
{
    cout << "Battle Start!" << endl;
    moveBehavior moveI;
    Pokemon pkmnI;
    moveBehavior pkmn1Move1 = moveI.makeMoves("Flamethrower", 100, Typing::FIRE, 100);
    moveBehavior pkmn1Move2 = moveI.makeMoves("Steel Wing", 75, Typing::STEEL, 95);
    moveBehavior pkmn1Move3 = moveI.makeMoves("Dragon Claw", 100, Typing::DRAGON, 100);
    moveBehavior pkmn1Move4 = moveI.makeMoves("Wing Attack", 60, Typing::FLYING, 100);

    Pokemon pkmn1 = pkmnI.makePokemon("Charizard", Typing::FIRE, Typing::FLYING, 
         pkmn1Move1, pkmn1Move2 , pkmn1Move3 , pkmn1Move4,
         78, 0 , 84, 78, 109, 85, 100, 100);
    HealingItems hi;
    HealingItems potion = hi.makeHealingItems("Potion", 20, 10);
    HealingItems superPotion = hi.makeHealingItems("Super Potion", 50, 7);
    HealingItems hyperPotion = hi.makeHealingItems("Hyper Potion", 120, 5);
    HealingItems maxPotion = hi.makeHealingItems("Max Potion", 1000, 5);


    vector <HealingItems> healingitemslist;
    healingitemslist.push_back(potion);
    healingitemslist.push_back(superPotion);
    healingitemslist.push_back(hyperPotion);
    healingitemslist.push_back(maxPotion);


    moveBehavior pkmn2Move1 = moveI.makeMoves("Hydro Pump", 110, Typing::WATER, 80);
    moveBehavior pkmn2Move2 = moveI.makeMoves("Surf", 90, Typing::WATER, 100);
    moveBehavior pkmn2Move3 = moveI.makeMoves("Ice Beam", 90, Typing::ICE, 100);
    moveBehavior pkmn2Move4 = moveI.makeMoves("Crunch", 80, Typing::DARK, 100);
    

    Pokemon pkmn2 = pkmnI.makePokemon("Blastoise", Typing::WATER, Typing::NONE,
         pkmn2Move1, pkmn2Move2, pkmn2Move3, pkmn2Move4,
        79, 0 , 83, 100, 85, 105, 78, 100);
        pkmn1.battlehp = calculateBattleHP(pkmn1);
        pkmn2.battlehp = calculateBattleHP(pkmn2);

    bool isvalid = true;
    while (isvalid)
    {
        cout << "Player Pokemon " << pkmn1.pokemonName << endl;
        
        cout << " HP: " << pkmn1.battlehp << endl;
        cout << "Opponent Pokemon " << pkmn2.pokemonName << endl;

        cout << " HP: " << pkmn2.battlehp << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. FIGHT       2.BAG\n3.POKEMON       4.END BATTLE" << endl;
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                //Fight Menu
                cout << "Choose move: " << endl;
                cout << "1. " << pkmn1.move1.moveName << " (" << convertToString(pkmn1.move1.moveType) << ")       2. " << pkmn1.move2.moveName << " (" << convertToString(pkmn1.move2.moveType) << ")" << endl;
                cout << "3. " << pkmn1.move3.moveName << " (" << convertToString(pkmn1.move3.moveType) << ")       4. " << pkmn1.move4.moveName << " (" << convertToString(pkmn1.move4.moveType) << ")" << endl;
                int moveChoice;
                cin >> moveChoice;
                cout << "You chose move: ";
                switch (moveChoice)
                {
                    case 1:
                    cout << pkmn1.pokemonName << " used " << pkmn1.move1.moveName << endl;
                    pkmn2.battlehp = pkmn2.battlehp - calculateDamage(pkmn1, pkmn2, pkmn1.move1);
                    displayTypeeffectiveness(returnTypeMultiplier(pkmn1.move1, pkmn2));
                    
                    if(pkmn2.battlehp <= 0)
                    {
                        pkmn2.battlehp = 0;
                        cout << pkmn2.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else{
                    cout << pkmn2.pokemonName << "'s HP is: " << pkmn2.battlehp << endl;
                    }
                    break;



                    case 2:
                    cout << pkmn1.pokemonName << " used " << pkmn1.move2.moveName << endl;
                    pkmn2.battlehp = pkmn2.battlehp - (calculateDamage(pkmn1, pkmn2, pkmn1.move2));
                    displayTypeeffectiveness(returnTypeMultiplier(pkmn1.move2, pkmn2));
                    if(pkmn2.battlehp <= 0)
                    {
                        pkmn2.battlehp = 0;
                        cout << pkmn2.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else{
                    cout << pkmn2.pokemonName << "'s HP is: " << pkmn2.battlehp << endl;
                    }
                    break;



                    case 3:
                    cout << pkmn1.pokemonName << " used " << pkmn1.move3.moveName << endl;
                    pkmn2.battlehp = pkmn2.battlehp - (calculateDamage(pkmn1, pkmn2, pkmn1.move3));
                    displayTypeeffectiveness(returnTypeMultiplier(pkmn1.move3, pkmn2));
                    if(pkmn2.battlehp <= 0)
                    {
                        pkmn2.battlehp = 0;
                        cout << pkmn2.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else{
                    cout << pkmn2.pokemonName << "'s HP is: " << pkmn2.battlehp << endl;
                    }
                    break;
                    case 4:



                        cout << pkmn1.pokemonName << " used " << pkmn1.move4.moveName << endl;
                        pkmn2.battlehp = pkmn2.battlehp - (calculateDamage(pkmn1, pkmn2, pkmn1.move4));
                        displayTypeeffectiveness(returnTypeMultiplier(pkmn1.move4, pkmn2));
                        if(pkmn2.battlehp <= 0)
                        {
                            pkmn2.battlehp = 0;
                            cout << pkmn2.pokemonName << "'s HP is: " << 0 << endl;
                        }
                        else{
                        cout << pkmn2.pokemonName << "'s HP is: " << pkmn2.battlehp << endl;
                        }
                        break;
                    default:
                        cout << "Invalid move choice!" << endl;
                        break;
                }
                break;
                case 2:
                {
                    int option;
                    int i = 1;
                    cout << left << setw(15) << "Name" << setw(12) << "Heal Amount" << setw(10) << "Quantity" << endl;
                    for (HealingItems &h : healingitemslist) {
                        cout << i << ". " << left << setw(14) << h.name 
                             << setw(12) << h.healedAmount 
                             << setw(10) << h.quantity << endl;
                        i++;
                    }
                        cout << "Choose item (enter no)" << endl;
                        cin >> option;
                        switch (option)
                        {
                            case 1:
                                pkmn1.battlehp = healingitemslist[0].heal(pkmn1, healingitemslist[0]);
                                cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                                break;
                            case 2:
                                pkmn1.battlehp = healingitemslist[1].heal(pkmn1, healingitemslist[1]);
                                cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                                break;
                            case 3:
                                pkmn1.battlehp = healingitemslist[2].heal(pkmn1, healingitemslist[2]);
                                cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                                break;
                            case 4:
                                pkmn1.battlehp = healingitemslist[3].heal(pkmn1, healingitemslist[3]);
                                cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                                break;
                            case 5:
                                cout << "Back to menu" << endl;
                                break;
                            default:
                                cout << "Invalid item choice!" << endl;
                                break;
                        
                    }
                }
                break;
                
            case 3:
                //Pokemon Party
                break;
            case 4:
                cout << "You ran from battle..." << endl;
                return 0; // End the program
                break;
        }

        if(pkmn2.battlehp <= 0)
        {
            cout << "Opponent Lost. You win!" << endl;
            return 0;
        }

        cout <<endl<< "Opponent's Turn" << endl;
        srand(time(0));
        //int opponentChoice = getRandom(1,4);
        int opponentChoice = 4;
        switch (opponentChoice)
                {
                    case 1:
                        cout << pkmn2.pokemonName << " used " << pkmn2.move1.moveName << endl;
                        pkmn1.battlehp = pkmn1.battlehp - (calculateDamage(pkmn2, pkmn1, pkmn2.move1));
                        displayTypeeffectiveness(returnTypeMultiplier(pkmn2.move1, pkmn1));
                        if(pkmn1.battlehp <= 0)
                        {
                            pkmn1.battlehp = 0;
                            cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                        }
                        else
                        {
                            cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                        }
                        break;



                    case 2:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move2.moveName << endl;
                    pkmn1.battlehp = pkmn1.battlehp - (calculateDamage(pkmn2, pkmn1, pkmn2.move2));
                    displayTypeeffectiveness(returnTypeMultiplier(pkmn2.move2, pkmn1));
                    if(pkmn1.battlehp <= 0)
                    {
                        pkmn1.battlehp = 0;
                        cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else
                    {
                        
                        cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                    }
                    break;



                    case 3:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move3.moveName << endl;
                    pkmn1.battlehp = pkmn1.battlehp - (calculateDamage(pkmn2, pkmn1, pkmn2.move3));
                    displayTypeeffectiveness(returnTypeMultiplier(pkmn2.move3, pkmn1));
                    if(pkmn1.battlehp <= 0)
                    {
                        pkmn1.battlehp = 0;
                        cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else
                    {
                        cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                    }
                    break;



                    case 4:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move4.moveName << endl;
                        pkmn1.battlehp = pkmn1.battlehp - (calculateDamage(pkmn2, pkmn1, pkmn2.move4));
                        displayTypeeffectiveness(returnTypeMultiplier(pkmn2.move4, pkmn1));
                        if(pkmn1.battlehp <= 0)
                        {
                            pkmn1.battlehp = 0;
                            cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                        }
                        else
                        {
                            cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                        }
                        break;
                    default:
                        cout << "Invalid move choice!" << endl;
                        break;
                }
                if(pkmn1.battlehp <= 0)
                {
                    cout << "You Lost. Foe " << pkmn2.pokemonName <<" win!" << endl;
                    return 0;
                }

    
}
                
}
