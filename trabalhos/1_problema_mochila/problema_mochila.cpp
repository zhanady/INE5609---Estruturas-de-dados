#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<int,double,int,int>> form_uso;
std::vector<std::tuple<int,int>> form_exit;

void put(const std::vector<std::tuple<int,double,int,int>>& itens, int capacity)
{
	for( int i = 0; i < itens.size() && capacity > 0; i++ )
	{
	    int id      = std::get<0>(itens[i]);
        double val  = std::get<1>(itens[i]);
        int qtd     = std::get<2>(itens[i]);
        int peso    = std::get<3>(itens[i]);
        
        if (capacity >= peso)
        {
			if (capacity >= peso * qtd)
			{
				capacity -=  peso * qtd;
                form_exit.push_back({id, qtd});
            }
			else
			{
				int qtd_k = qtd;
				for(qtd_k; qtd_k > 0; qtd_k-- )
				{
					if (capacity >= peso*qtd_k)
					{
						capacity -= peso*qtd_k;
						form_exit.push_back({id, qtd_k});
						break;
					}
				}
			}
		}
	}
}

void sort(std::vector<std::tuple<int,double,int,int>>& v_org)
{
	size_t n = v_org.size();
    for(int j = 1; j < n; j++)
    {
        int i = j;
        while(i > 0 && std::get<1>(v_org[i]) > std::get<1>(v_org[i-1]))
        {
            auto temp = v_org[i];
            v_org[i] = v_org[i-1];
            v_org[i-1] = temp;

            i -= 1;
        }
    }
}

void analyze(const std::vector<std::tuple<int,int,int>>& entradas)
{
	for (int i = 0; i < entradas.size(); i++)
	{
		int utilidade = std::get<0>(entradas[i]);
        int peso = std::get<1>(entradas[i]);
        int qtd = std::get<2>(entradas[i]);
		
		double value = static_cast<double>(utilidade)/peso;
		form_uso.push_back({i, value, qtd, peso});
	}
}

int main()
{
    std::vector<std::tuple<int,int,int>> user_ans;

	int x, y, z;
	std::cin >> x >> y >> z;

	while (x != -1) 
	{
		user_ans.push_back({x, y, z});
		std::cin >> x >> y >> z;
	}	

	int cap;
	std::cin >> cap;

	analyze(user_ans);
	sort(form_uso);
	put(form_uso, cap);

	for (auto& [item_id, qtd]: form_exit) 
	{
		std::cout << item_id << " " << qtd << "\n";
	}


    return 0;
}
