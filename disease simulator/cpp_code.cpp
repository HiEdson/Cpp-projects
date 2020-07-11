

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Entity
{
public:
    string name;
    int id;
    string gate;
    string init_pos;
    pair<int, int> pos;
    //string infected;
    bool infected = false;
    bool can_be_infected = false;
    bool dead = false;
    bool immune = false;
    int infected_date_in_turn;
    bool will_die = false;
    bool is_infectious = false;
    int infected_at = 0;
};

void can_be_infected(Entity &entity_1)
{

    for (int i = 0; i < 5; i++)
    {
        if (entity_1.gate[i] == 'A' || entity_1.gate[i] == 'B')
        {

            entity_1.can_be_infected = true;
        }
    }
}

void dead(Entity &entity_1)
{ //, int turn
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 0; i < 5; i++)
    {
        if (entity_1.gate[i] == 'A')
        {
            a++;
        }
        else if (entity_1.gate[i] == 'B')
        {
            b++;
        }
        else if (entity_1.gate[i] == 'C')
        {
            c++;
        }
        else if (entity_1.gate[i] == 'D')
        {
            d++;
        }
    }
    int a_b = a + b + c + d;
    if (a_b >= 3)
    {
        entity_1.will_die = true;
    }
}

void escrever(vector<Entity> &all_entity, vector<vector<pair<int, int>>> &movs, int tc);

void infectious(vector<Entity> &all_entity, vector<vector<pair<int, int>>> &turns, int turns_count)
{
    //, vector< vector <pair<int, int>>> turns,
    int dead_count = 0;
    vector<Entity> infectious_entity;

    for (int i = 0; i < turns_count; i++)
    {
        infectious_entity.clear();
        // cout << " see the output " << endl;
        for (int j = 0; j < all_entity.size(); j++)
        {

            if (i - all_entity[j].infected_at == 3 && all_entity[j].infected == 1)
            {

                all_entity[j].is_infectious = true;
                //all_entity[j].infected_at = i;

                infectious_entity.push_back(all_entity[j]);
            }

            if (i - all_entity[j].infected_at == 14 && all_entity[j].will_die == 1 && all_entity[j].infected)
            {
                all_entity[j].dead = true;
            }
            if (i - all_entity[j].infected_at == 19 && all_entity[j].will_die == 1 && all_entity[j].infected)
            {
                all_entity[j].is_infectious = false;
            }
            if (i - all_entity[j].infected_at == 30 && all_entity[j].will_die != 1 && all_entity[j].infected)
            {
                all_entity[j].immune = true;
            }

        } //inner

        for (int e = 0; e < infectious_entity.size(); e++)
        {
            for (int j = 0; j < all_entity.size(); j++)
            {
                auto p = turns[i][all_entity[j].id - 1];
                auto p_infec = turns[i][infectious_entity[e].id - 1];
                if (all_entity[j].id == infectious_entity[e].id)
                {
                    continue;
                }
                else
                {
                    int x = p.first;
                    int y = p.second;
                    int x_infec = p_infec.first;
                    int y_infec = p_infec.second;

                    int result1 = abs(x - x_infec);
                    int result2 = abs(y - y_infec);

                    if (result1 <= 3 && result2 <= 3)
                    {
                        all_entity[j].infected = true;
                        all_entity[j].infected_at = i;
                    }
                }
            }
        }
        escrever(all_entity, turns, i);
    }
}

ofstream escreve_turns("TURNS.TXT");
ofstream escreve_out("OUTPUT.TXT");
int size_value, turncount_value;

void escrever_o(vector<Entity> &all_entity){
    int normal = 0, infected = 0, dead = 0, recovered = 0;
    for(auto e: all_entity){
        normal += (!e.infected);
        infected += (e.infected&&e.immune);
        recovered += e.immune;
        dead += e.dead;
    }
    escreve_out << "Normal   : "<<normal<<endl;
    escreve_out << "Infected : "<<infected<<endl;
    escreve_out << "Dead     : "<<dead<<endl;
    escreve_out << "recovered: "<<recovered<<endl;
    for(int i = 0; i<all_entity.size(); ++i){
        string status = "normal";
        auto e = all_entity[i];
        if(e.dead && e.immune) status="immune";
        else if(e.dead) status="dead";
        else if(e.infected) status="infected";

        escreve_out << "entity "<<i+1<<" "<<all_entity[i].pos.first<<'x'<<all_entity[i].pos.second<<" "<<status<<endl;
    }
}

void escrever(vector<Entity> &all_entity, vector<vector<pair<int, int>>> &movs, int tc)
{

    auto mov = movs[tc];
    bool flag = false;
    escreve_turns << "Turn :" << tc + 1 << endl;
    for (int i = 0; i < size_value + 2; ++i)
        escreve_turns << '-';
    escreve_turns << endl;

    for (auto &e : all_entity)
    {
        if (!e.dead)
        {
            e.pos = mov[e.id - 1];
            // cout<<e.pos.first<<" ";
        }
    }
    for (int i = 1; i <= size_value; ++i)
    {
        escreve_turns << '-';
        for (int j = 1; j <= size_value; ++j)
        {
            for (auto e : all_entity)
                if (e.pos.first == i && e.pos.second == j)
                {
                    if ((e.infected && !e.dead) || e.immune)
                        escreve_turns << 'X';
                    else if (!e.infected)
                        escreve_turns << 'O';
                    else if (e.dead && e.is_infectious)
                        escreve_turns << 'D';
                    else if(e.dead)
                        escreve_turns<<' ';
                    flag = true;
                }
            if (!flag)
                escreve_turns << ' ';
            flag = false;
        }
        escreve_turns << '-' << endl;
    }

    for (int i = 0; i < size_value + 2; ++i)
        escreve_turns << '-';
    escreve_turns << endl;
}

pair<int, int> clean_x(string a)
{
    auto x = a.find('x');
    pair<int, int> cleaned;
    cleaned.first = stoi(a.substr(0, x));
    cleaned.second = stoi(a.substr(x + 1));

    return cleaned;
}

int main()
{
    vector<Entity> all_entity;
    vector<vector<pair<int, int>>> movs;

    string name;
    int id;

    ifstream fcin;
    fcin.open("INPUT.TXT");
    fcin >> name >> size_value;
    fcin >> name >> turncount_value;

    int test = turncount_value;

    istringstream s;

    while (getline(fcin, name))
    {
        s.str(name);
        s.clear();
        Entity entity_1;

        if (name[0] == 'e')
        {
            if (name.size() >= 27)
            {

                s >> entity_1.name >> entity_1.id >> entity_1.gate >> entity_1.init_pos >> entity_1.infected;
                entity_1.infected = true;
            }
            else
            {
                s >> entity_1.name >> entity_1.id >> entity_1.gate >> entity_1.init_pos >> entity_1.init_pos;
            }
            dead(entity_1);
            can_be_infected(entity_1);
            entity_1.pos = clean_x(entity_1.init_pos);
            all_entity.push_back(entity_1);
        }

        if (name[0] == 't')
        {
            vector<pair<int, int>> mov;

            istringstream s(name);

            // /   cout <<"estamos tentando" <<endl;
            s >> name >> id;
            while (s >> name)
            {
                //  fcin >> name >> id >>mov.push_back(name)
                mov.push_back(clean_x(name));
            }

            //.. mov.push_back(name);
            //MainTurn.print();
            movs.push_back(mov);
        }
    }

    infectious(all_entity, movs, test);
    escrever_o(all_entity);

    return 0;
}
