#include <iostream>
using namespace  std;
int temp;

class Farmer
{
public:
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
    void boughtChickens()
    {
        numChickens += 1;
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
    int money = 150;
    int numCows = 0;
    int maxCows;
    int numChickens = 0;
    int maxChickens;
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
    int age;
    int price;
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
private:

    int age [50];
    int price [5] = {10, 50, 200, 300, 500};
};
Farmer farmer;
Farm farm;
Cow cow;
Chicken chicken;
int menu()
{
    cout << "Options:\n";
    cout << "1. Check economy\n";
    cout << "2. Buy animals\n";
    cout << "3. Sell animals\n";
    cout << "4. Check all animals\n";
    cout << "5. Upgrade or check farm level\n";
    cout << "6. Other upgrades\n";
    cout << "7. Go to next year\n";
    cout << "Pick what you want to do: ";
    cin >> temp;
    return temp;
}

void buysellAnimals(bool buying)
{
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
                    farmer.setMoney(-50);
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
                    chicken.setAge(farmer.getNumChickens(), 1);
                    farmer.setMoney(-10);
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
        }
        else if(temp == 2)
        {
            //Show all alternative chickens
        }
    }
}

void checkAnimals()
{
    cout << "What animal, press 1 for cows and 2 for chickens: ";
    cin >> temp;
    if(temp == 1)
    {
        for(int x = 0; x <= farmer.getNumCows(); x++)
        {
            if(cow.getAge(x) > 0)
            {
                cout << "Cow number " + to_string(x+1) + ", age is " + to_string(cow.getAge(x)) + " and the value of the cow is " + to_string(cow.getPrice(cow.getAge(x))) + "USD\n";
            }
        }
    }
    else if(temp == 2)
    {
        for(int x = 0; x <= farmer.getNumChickens(); x++)
        {
            if(cow.getAge(x) > 0)
            {
                cout << "Chicken number " + to_string(x+1) + ", age is " + to_string(chicken.getAge(x)) + " and the value of the chicken is " + to_string(chicken.getPrice(chicken.getAge(x))) + "USD\n";
            }
        }
    }
}

bool farmUpgrade()
{
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

void options()
{

}

void increaseYear()
{

}


int main() {
    bool playing = true;
    int choice;

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
                buysellAnimals(true);
                break;
            case 3: //Sell animals
                buysellAnimals(false);
                break;
            case 4: //Check all animals
                checkAnimals();
                break;
            case 5: //Upgrade or check farm level
                if(farmUpgrade() == true)
                {
                    farmer.upgradeFarm();
                    farmer.setMaxCows(farm.getMaxCow(farmer.getFarm()));
                    farmer.setMaxChickens(farm.getMaxChickens(farmer.getFarm()));
                    cout << "Farm upgraded sucessfully\n";
                }
                break;
            case 6: //Other options
                options();
                break;
            case 7: //Move to next year
                increaseYear();
                break;
        }
        cout << "\n";
    }
}

