//Bugs known about is when increasing year it dosnt work and when inputing a string/char instead it crashes aswell! But everything works
#include <iostream>
using namespace  std;

class Farmer // Declaring a farmer class
{
public: //Making getters and setters for the private variables
    int getFarm()
    {
        return farm;
    }
    int getMoney()
    {
        return money;
    }
    void setMoney(int k)
    {
        money += k;
    }
    void upgradeFarm()
    {
        farm += 1;
    }
    void setMaxCows(int g)
    {
        maxCows = g;
    }
    void setMaxChickens(int f)
    {
        maxChickens = f;
    }
    void boughtCows()
    {
        numCows += 1;
    }
    void soldCows()
    {
        numCows -= 1;
    }
    void boughtChickens()
    {
        numChickens += 1;
    }
    void soldChickens()
    {
        numChickens -= 1;
    }
    int getNumCows()
    {
        return numCows;
    }
    int getNumChickens()
    {
        return numChickens;
    }

private:
    int farm = 0;
    int money = 1500;
    int numCows = 0;
    int maxCows = 0;
    int numChickens = 0;
    int maxChickens = 0;
};
class Farm
{
public:
    int getMaxCow(int k)
    {
        return maxCapCows[k];
    }
    int getMaxChickens(int t)
    {
        return maxCapChickens[t];
    }
    int getFarmPrice(int o)
    {
        return farmPrice[o];
    }
private:
    int maxCapCows [5] = {2, 5, 10, 15, 30};
    int maxCapChickens [5] = {5, 10, 20, 30, 50};
    int farmPrice [5] = {0, 500, 1000, 5000, 10000};
};
class Animal
{
public:

private:
    int age = 0;
    int price = 0;
};
class Cow : public Animal
{
public:
    int getPrice(int i)
    {
        return price[i-1];
    }
    int getAge(int x)
    {
        return age[x-1];
    }
    void setAge(int l, int h)
    {
        age[l] = h;
    }
    void newYearCow(int u)
    {
        age[u] += 1;
    }
private:

    int age [30];
    int price [15] = {50, 100, 200, 300, 500, 1000, 1500, 2000, 3000, 4000, 5000, 6500, 8000, 10000, 12000};
};
class Chicken : public Animal
{
public:
    int getPrice(int i)
    {
        return price[i-1];
    }
    int getAge(int x)
    {
        return age[x-1];
    }
    void setAge(int l, int h)
    {
        age[l] = h;
    }
    void newYearChicken(int u)
    {
        age[u] += 1;
    }
private:

    int age [50];
    int price [5] = {10, 50, 200, 300, 500};
};
class Upgrades
{
public:
    float getDiscount(int i)
    {
        return discount[i];
    }
    int getDiscountPrice(int k)
    {
        return discountPrice[k];
    }
    int getDiscountLevel()
    {
        return discountLevel;
    }
    void setDiscountLevel()
    {
        discountLevel += 1;
    }
    int getSellingMult(int o)
    {
        return sellingMult[o];
    }
    int getSellingMultPrice(int l)
    {
        return sellingMultPrice[l];
    }
    int getSellingLevel()
    {
        return sellingMultLevel;
    }
    void setSellingMultLevel()
    {
        sellingMultLevel += 1;
    }

private:
    float discount [4] = {1, 0.75, 0.5, 0.25};
    int discountPrice [4] = {0, 2500, 10000, 50000};
    int discountLevel = 0;
    int sellingMult [5] = {1, 2, 4, 8, 16};
    int sellingMultPrice [5] = {0, 2500, 10000, 25000, 50000};
    int sellingMultLevel = 0;
};

int menu()
{
    int temp = 0;
    cout << "Options:\n";
    cout << "1. Check economy\n";
    cout << "2. Buy animals\n";
    cout << "3. Sell animals\n";
    cout << "4. Check all animals\n";
    cout << "5. Upgrade or check farm level\n";
    cout << "6. Other upgrades\n";
    cout << "7. Go to next year\n";
    cout << "8. Quit game!\n";
    cout << "Pick what you want to do: ";
    cin >> temp;
    return temp;
}

void buySellAnimals(bool buying, Farmer& farmer, Farm& farm, Cow& cow, Chicken& chicken, Upgrades& upgrade)
{
    int temp = 0;
    int sellNum = 0;
    if(buying == true) // Buying
    {
        cout << "Do you want to buy cows if so press 1 but if you want to buy chickens press 2: ";
        cin >> temp;
        if(temp == 1)
        {
            cout << "Do you want to buy a cow for 50 USD if yes press 1 else press 2: ";
            cin >> temp;
            if(temp == 1)
            {
                if(farm.getMaxCow(farmer.getFarm())-1 >= farmer.getNumCows())
                {
                    cow.setAge(farmer.getNumCows()-1, 1);
                    farmer.setMoney(-cow.getPrice(1)*upgrade.getDiscount(upgrade.getDiscountLevel()));
                    farmer.boughtCows();
                    cout << "Purchase complete! You now have " + to_string(farmer.getNumCows()) + " cows and you have " + to_string(farmer.getMoney()) + " USD left!\n";
                }
            }
        }
        else if(temp == 2)
        {
            cout << "Do you want to buy a chicken for 10 USD if yes press 1 else press 2: ";
            cin >> temp;
            if(temp == 1)
            {
                if(farm.getMaxChickens(farmer.getFarm())-1 >= farmer.getNumChickens())
                {
                    chicken.setAge(farmer.getNumChickens()-1, 1);
                    farmer.setMoney(-chicken.getPrice(1)*upgrade.getDiscount(upgrade.getDiscountLevel()));
                    farmer.boughtChickens();
                    cout << "Purchase complete! You now have " + to_string(farmer.getNumChickens()) + " chickens and you have " + to_string(farmer.getMoney()) + " USD left!\n";
                }
            }
        }
    }
    else if(buying == false) //Selling
    {
        cout << "Do you want to sell cows if so press 1 but if you want to sell chickens press 2: ";
        cin >> temp;
        if(temp == 1)
        {
            //Show all alternative cows
            cout << "Cows:\n";
            for(int x = 0; x <= farmer.getNumCows()-1; x++)
            {
                if(cow.getAge(x) > 0)
                {
                    cout << "Number " + to_string(x+1) + ", age is " + to_string(cow.getAge(x)) + " and the value of the cow is " + to_string(static_cast<int>(cow.getPrice(cow.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
                }
            }
            cout << "Type the number of what cow you want to sell: ";
            cin >> sellNum;
            if(sellNum <= farmer.getNumCows())
            {
                cout << "Are you sure you want to sell cow number " + to_string(sellNum) + " worth " + to_string(cow.getPrice(static_cast<int>(cow.getAge(sellNum-1))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD, if yes press 1 and if not press 2: ";
                cin >> temp;
                if(temp == 1)
                {
                    farmer.setMoney(static_cast<int>(cow.getPrice(sellNum)*upgrade.getSellingMult(upgrade.getSellingLevel())));
                    if (sellNum < farmer.getNumCows())
                    {
                        for (int i = sellNum; i <= farmer.getNumCows(); i++)
                        {
                            cow.setAge(i, cow.getAge(i+1));
                        }
                        farmer.soldCows();
                    }
                    else if (sellNum = farmer.getNumCows())
                    {
                        cow.setAge(sellNum, 0);
                        farmer.soldCows();
                    }
                }
            }
        }
        else if(temp == 2)
        {
            //Show all alternative chickens
            cout << "Chickens:\n";
            for(int x = 0; x <= farmer.getNumChickens()-1; x++)
            {
                if(chicken.getAge(x) > 0)
                {
                    cout << "Number " + to_string(x+1) + ", age is " + to_string(chicken.getAge(x)) + " and the value of the chicken is " + to_string(static_cast<int>(chicken.getPrice(chicken.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
                }
            }
            cout << "Type the number of what chicken you want to sell: ";
            cin >> sellNum;
            if(sellNum <= farmer.getNumChickens())
            {
                cout << "Are you sure you want to sell chicken number " + to_string(sellNum) + " worth " + to_string(static_cast<int>(chicken.getPrice(chicken.getAge(sellNum-1))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD, if yes press 1 and if not press 2: ";
                cin >> temp;
                if(temp == 1)
                {
                    farmer.setMoney(static_cast<int>(cow.getPrice(sellNum)*upgrade.getSellingMult(upgrade.getSellingLevel())));
                    if (sellNum < farmer.getNumChickens())
                    {
                        for (int i = sellNum; i <= farmer.getNumChickens(); i++)
                        {
                            chicken.setAge(i, chicken.getAge(i+1));
                        }
                        farmer.soldChickens();
                    }
                    else if (sellNum = farmer.getNumChickens())
                    {
                        chicken.setAge(sellNum, 0);
                        farmer.soldChickens();
                    }
                }
            }
        }
    }
}

void checkAnimals(Farmer& farmer, Cow& cow, Chicken& chicken, Upgrades& upgrade)
{
    int temp = 0;

    cout << "What animal, press 1 for cows and 2 for chickens or 3 for both: ";
    cin >> temp;
    if(temp == 1)
    {
        for(int x = 0; x <= farmer.getNumCows()-1; x++) //Minus 1 because num cows is the actual amount of animals but when accessing an array you start from 0 and not 1 hence the minus 1
        {
            if(cow.getAge(x) > 0)
            {
                cout << "Cow number " + to_string(x+1) + ", age is " + to_string(cow.getAge(x)) + " and the value of the cow is " + to_string(static_cast<int>(cow.getPrice(cow.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
            }
        }
    }
    else if(temp == 2)
    {
        for(int x = 0; x <= farmer.getNumChickens()-1; x++)
        {
            if(chicken.getAge(x) > 0)
            {
                cout << "Chicken number " + to_string(x+1) + ", age is " + to_string(chicken.getAge(x)) + " and the value of the chicken is " + to_string(static_cast<int>(chicken.getPrice(chicken.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
            }
        }
    }
    else if(temp == 3)
    {
        cout << "Cows:\n";
        for(int x = 0; x <= farmer.getNumCows()-1; x++)
        {
            if(cow.getAge(x) > 0)
            {
                cout << "Number " + to_string(x+1) + ", age is " + to_string(cow.getAge(x)) + " and the value of the cow is " + to_string(cow.getPrice(static_cast<int>(cow.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
            }
        }
        cout << "\n";
        cout << "Chickens:\n";
        for(int x = 0; x <= farmer.getNumChickens()-1; x++)
        {
            if(chicken.getAge(x) > 0)
            {
                cout << "Number " + to_string(x+1) + ", age is " + to_string(chicken.getAge(x)) + " and the value of the chicken is " + to_string(static_cast<int>(chicken.getPrice(chicken.getAge(x))*upgrade.getSellingMult(upgrade.getSellingLevel()))) + "USD\n";
            }
        }
    }
}

bool farmUpgrade(Farmer& farmer, Farm& farm)
{
    int temp = 0;

    if(farmer.getMoney() >= farm.getFarmPrice(farmer.getFarm()+1))
    {
        cout << "Do you want to upgrade your farm for " + to_string(farm.getFarmPrice(farmer.getFarm()+1)) + "USD and you have " +
                to_string(farmer.getMoney())+  "USD and increase your cow capacity from " +
                to_string(farm.getMaxCow(farmer.getFarm())) + " to " + to_string(farm.getMaxCow(farmer.getFarm()+1)) + " and your chicken max from " +
                to_string(farm.getMaxChickens(farmer.getFarm())) + " to " + to_string(farm.getMaxChickens(farmer.getFarm()+1)) + "if yes press 1, if no press 2: ";
        cin >> temp;
        if(temp == 1)
        {
            return true;
        }
        if(temp == 2)
        {
            cout << "Okey farm not upgraded!\n";
            return false;
        }
    }
    else
    {
        cout << "You dont have enough money to upgrade!\n";
        return false;
    }
}

void upgrades(Farmer& farmer, Upgrades& upgrade) {
    int temp = 0;
    if (farmer.getMoney() >= upgrade.getSellingMultPrice(upgrade.getSellingLevel() + 1) || farmer.getMoney() >= upgrade.getDiscountPrice(upgrade.getDiscountLevel() + 1))
    {
        cout << "Upgrades:\n";
        cout << "Selling Multiplier for selling animals:\n ";
        if (upgrade.getSellingLevel() <= 4) {
            cout << "Current level is " + to_string(upgrade.getSellingLevel()) + " but can be upgraded for " +
                    to_string(upgrade.getSellingMultPrice(upgrade.getSellingLevel() + 1)) + "USD!\n";
        } else {
            cout << "Your selling multiplier is maxed out level is at: " + to_string(upgrade.getSellingLevel()) + "\n";
        }
        cout << "\n";
        cout << "Discount Multiplier for buying animals:\n ";
        if (upgrade.getDiscountLevel() <= 3) {
            cout << "Current level is " + to_string(upgrade.getDiscountLevel()) + " but can be upgraded for " +
                    to_string(upgrade.getDiscountPrice(upgrade.getDiscountLevel() + 1)) + "USD!\n";
        } else {
            cout << "Your selling multiplier is maxed out level is at: " + to_string(upgrade.getSellingLevel()) + "\n";
        }
        cout << "\n";
        cout
                << "If you want to purchase selling multiplier press 1, if you want to upgrade the discount multiplier press 2 or press 3 if you want to return to menu: ";
        cin >> temp;
        if (temp == 1) {
            upgrade.setSellingMultLevel();
            cout << "Selling multiplier now at " + to_string(upgrade.getSellingMult(upgrade.getSellingLevel())) + "\n";
        } else if (temp == 2) {
            upgrade.setDiscountLevel();
            cout << "Discount multiplier now at " + to_string(upgrade.getDiscount(upgrade.getDiscountLevel())) + "\n";
        } else {

        }
    }
    else if(farmer.getMoney() >= upgrade.getSellingMultPrice(upgrade.getSellingLevel()+1))
    {
        cout << "Upgrades:\n";
        cout << "You only have enough money for Selling Multiplier for selling animals:\n ";
        if(upgrade.getSellingLevel() <= 4)
        {
            cout << "Current level is " + to_string(upgrade.getSellingLevel()) + " but can be upgraded for " + to_string(upgrade.getSellingMultPrice(upgrade.getSellingLevel()+1)) + "USD!\n";
        }
        else
        {
            cout << "Your selling multiplier is maxed out level is at: " + to_string(upgrade.getSellingLevel()) + "\n";
        }
        cout << "\n";
        cout << "If you want to purchase selling multiplier press 1, if you want to go back to menu press 2: ";
        cin >> temp;
        if(temp == 1)
        {
            upgrade.setSellingMultLevel();
            farmer.setMoney(-upgrade.getSellingMultPrice(upgrade.getSellingLevel()));
            cout << "Selling multiplier now at " + to_string(upgrade.getSellingMult(upgrade.getSellingLevel())) + "\n";
        }
        else
        {

        }
    }
    else if(farmer.getMoney() >= upgrade.getDiscountPrice(upgrade.getDiscountLevel()+1))
    {
        cout << "Discount Multiplier for buying animals:\n ";
        if(upgrade.getDiscountLevel() <= 3)
        {
            cout << "Current level is " + to_string(upgrade.getDiscountLevel()) + " but can be upgraded for " + to_string(upgrade.getDiscountPrice(upgrade.getDiscountLevel()+1))+ "USD!\n";
        }
        else
        {
            cout << "Your discount multiplier is maxed out level is at: " + to_string(upgrade.getDiscountLevel()) + "\n";
        }
        cout << "\n";
        cout << "If you want to purchase discount multiplier press 1, if you want to go back to menu press 2: ";
        cin >> temp;
        if(temp == 1)
        {
            upgrade.setDiscountLevel();
            farmer.setMoney(-upgrade.getDiscountPrice(upgrade.getDiscountLevel()));
            cout << "Discount multiplier now at " + to_string(upgrade.getDiscount(upgrade.getDiscountLevel())) + "\n";
        }
        else
        {

        }
    }
    else
    {
        cout << "You don't have enough money for the upgrades get more to see what upgrades are possible! :) \n";
    }
}

void increaseYear(Farmer& farmer, Cow& cow, Chicken& chicken)
{
    for(int x = 0; x <= farmer.getNumCows()-1; x++)
    {
        cow.newYearCow(x);
    }
    for(int x = 0; x <= farmer.getNumChickens()-1; x++)
    {
        chicken.newYearChicken(x);
    }
}


int main() {
    Farmer farmer;
    Farm farm;
    Cow cow;
    Chicken chicken;
    Upgrades upgrade;

    bool playing = true;
    int choice = 0;


    farmer.setMaxCows(farm.getMaxCow(farmer.getFarm()));
    farmer.setMaxChickens(farm.getMaxChickens(farmer.getFarm()));

    cout << "Hello to your new career in farming! Hope you have a good time!\n";
    while(playing)
    {
        choice = menu();
        switch (choice) {
            case 1: //Check economy
                cout << "You have " + to_string(farmer.getMoney()) + "USD!\n";
                break;
            case 2: //Buy animals
                buySellAnimals(true, farmer, farm, cow, chicken, upgrade);
                break;
            case 3: //Sell animals
                buySellAnimals(false, farmer, farm, cow, chicken, upgrade);
                break;
            case 4: //Check all animals
                checkAnimals(farmer, cow, chicken, upgrade);
                break;
            case 5: //Upgrade or check farm level
                if(farmUpgrade(farmer, farm) == true)
                {
                    farmer.upgradeFarm();
                    farmer.setMaxCows(farm.getMaxCow(farmer.getFarm()));
                    farmer.setMaxChickens(farm.getMaxChickens(farmer.getFarm()));
                    cout << "Farm upgraded successfully!\n";
                }
                break;
            case 6: //Other upgrades
                upgrades(farmer, upgrade);
                break;
            case 7: //Move to next year
                increaseYear(farmer, cow, chicken);
                break;
            case 8:
                cout << "Thanks for playing!";
                playing = false;
                break;
        }
        cout << "\n";
    }
}