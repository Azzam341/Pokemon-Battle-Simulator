#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class Typing 
{
    FIRE = 0, WATER, GRASS, ELECTRIC, PSYCHIC, DARK, FIGHTING, NORMAL, FLYING, GROUND, STEEL,
    ICE, POISON, BUG, DRAGON, NONE
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
    string moveType;
    int accuracy;

    friend ostream& operator<<(ostream& os, const moveBehavior& move) {
        os << move.moveName << " (Power: " << move.movePower << ", Type: " << move.moveType << ", Accuracy: " << move.accuracy << ")";
        return os;
    }

    moveBehavior makeMoves (string moveName, int movePower, string moveType, int accuracy)
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

int calculateDamage(Pokemon pkmn1, Pokemon pkmn2, moveBehavior move) {
    double levelFactor = ((2.0 * pkmn1.level) / 5.0) + 2;
    double attackDefenseRatio = (double)pkmn1.atk / (double)pkmn2.dfs; // Ensure floating-point division
    double baseDamage = ((levelFactor * move.movePower * attackDefenseRatio) / 50.0) + 2;
    
    return (int)baseDamage;
}

int getRandom (int min, int max)
{
    return min + rand() % (max - min + 1);
}


void defineTyping()
{
    //Make later
}

int main ()
{
    cout << "Battle Start!" << endl;
    moveBehavior moveI;
    Pokemon pkmnI;
    Typing typeI;
    moveBehavior pkmn1Move1 = moveI.makeMoves("FlameThrower", 90, "FIRE", 100);
    moveBehavior pkmn1Move2 = moveI.makeMoves("Steel Wing", 75, "STEEL", 95);
    moveBehavior pkmn1Move3 = moveI.makeMoves("Dragon Claw", 100, "DRAGON", 100);
    moveBehavior pkmn1Move4 = moveI.makeMoves("Wing Attack", 60, "FLYING", 100);

    Pokemon pkmn1 = pkmnI.makePokemon("Charizard", Typing::FIRE, Typing::FLYING, 
         pkmn1Move1, pkmn1Move2 , pkmn1Move3 , pkmn1Move4,
         78, 0 , 84, 78, 109, 85, 100, 100);
    //pkmn1.viewPokemonDetails(pkmn1);
    moveBehavior pkmn2Move1 = moveI.makeMoves("Hydro Pump", 110, "WATER", 80);
    moveBehavior pkmn2Move2 = moveI.makeMoves("Surf", 90, "WATER", 100);
    moveBehavior pkmn2Move3 = moveI.makeMoves("Ice Beam", 90, "ICE", 100);
    moveBehavior pkmn2Move4 = moveI.makeMoves("Crunch", 80, "DARK", 100);
    

    Pokemon pkmn2 = pkmnI.makePokemon("Blastoise", Typing::WATER, Typing::NONE,
         pkmn2Move1, pkmn2Move2, pkmn2Move3, pkmn2Move4,
        79, 0 , 83, 100, 85, 105, 78, 100);
        pkmn1.battlehp = calculateBattleHP(pkmn1);
        pkmn2.battlehp = calculateBattleHP(pkmn2);
    //pkmn2.viewPokemonDetails(pkmn2);
    //Main Battle Menu
    bool isvalid = true;
    while (isvalid)
    {
        if(pkmn1.battlehp <= 0)
        {
            cout << "Opponent " << pkmn2.pokemonName << " won. You lost" << endl;
            isvalid= false;
        }
        else if(pkmn2.battlehp <= 0)
        {
            cout << "Opponent " << pkmn2.pokemonName << " lost. You won!" << endl;
            isvalid= false;
        }
        else{
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
                cout << "1. " << pkmn1.move1.moveName << "       2. " << pkmn1.move2.moveName << endl;
                cout << "3. " << pkmn1.move3.moveName << "       4. " << pkmn1.move4.moveName << endl;
                int moveChoice;
                cin >> moveChoice;
                cout << "You chose move: ";
                switch (moveChoice)
                {
                    case 1:
                    cout << pkmn1.pokemonName << " used " << pkmn1.move1.moveName << endl;
                    pkmn2.battlehp = pkmn2.battlehp - calculateDamage(pkmn1, pkmn2, pkmn1.move1);
                    if(pkmn1.battlehp <= 0)
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
                    pkmn2.battlehp = pkmn2.battlehp - calculateDamage(pkmn1, pkmn2, pkmn1.move2);
                    if(pkmn1.battlehp <= 0)
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
                    pkmn2.battlehp = pkmn2.battlehp - calculateDamage(pkmn1, pkmn2, pkmn1.move3);
                    if(pkmn1.battlehp <= 0)
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
                        pkmn2.battlehp = pkmn2.battlehp - calculateDamage(pkmn1, pkmn2, pkmn1.move4);
                        if(pkmn1.battlehp <= 0)
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
                //Bag Menu
                break;
            case 3:
                //Pokemon Party
                break;
            case 4:
                cout << "You ran from battle..." << endl;
                return 0; // End the program
                break;
        }

        cout <<endl<< "Opponent's Turn" << endl;
        srand(time(0));
        int opponentChoice = getRandom(1,4);
        switch (opponentChoice)
                {
                    case 1:
                        cout << pkmn2.pokemonName << " used " << pkmn2.move1.moveName << endl;
                        pkmn1.battlehp = pkmn1.battlehp - calculateDamage(pkmn2, pkmn1, pkmn2.move1);
                        if(pkmn2.battlehp <= 0)
                        {
                            pkmn2.battlehp = 0;
                            cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                        }
                        else
                        {
                            cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                        }
                        break;
                    case 2:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move2.moveName << endl;
                    pkmn1.battlehp = pkmn1.battlehp - calculateDamage(pkmn2, pkmn1, pkmn2.move2);
                    if(pkmn2.battlehp <= 0)
                    {
                        pkmn2.battlehp = 0;
                        cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else
                    {
                        
                        cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                    }
                    break;
                    case 3:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move3.moveName << endl;
                    pkmn1.battlehp = pkmn1.battlehp - calculateDamage(pkmn2, pkmn1, pkmn2.move3);
                    if(pkmn2.battlehp <= 0)
                    {
                        pkmn2.battlehp = 0;
                        cout << pkmn1.pokemonName << "'s HP is: " << 0 << endl;
                    }
                    else
                    {
                        cout << pkmn1.pokemonName << "'s HP is: " << pkmn1.battlehp << endl;
                    }
                    break;
                    case 4:
                    cout << pkmn2.pokemonName << " used " << pkmn2.move4.moveName << endl;
                        pkmn1.battlehp = pkmn1.battlehp - calculateDamage(pkmn2, pkmn1, pkmn2.move4);
                        if(pkmn2.battlehp <= 0)
                        {
                            pkmn2.battlehp = 0;
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

    }
}
}
