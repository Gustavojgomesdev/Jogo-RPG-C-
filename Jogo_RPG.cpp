#include <iostream>
#include <locale.h>
#include <conio.h>

using namespace std;

enum Dificulty{
    easy=1, medium, hard
};


struct player{
	string name;
    int health;
    int attack;

    void criar(string snome, int svida, int sdano){
	    name = snome;
	    health = svida;
	    attack = sdano;
	}

	void status(){
        cout<<"NOME:"<<name<<endl;
        cout<<"VIDA:"<<health<<endl;
        cout<<"DANO:"<<attack<<endl;
        cout<<"\n\n";
    }

	int get_attack(){
		return attack;
	}

	int get_Hp(){
    	return health;
	}

	void dano_recebido(int ataque){
		health -= ataque;
		if(health < 0)
			health = 0;
	}

	void fury(int dano, int vida){
		attack += dano;
		health += vida;
	}

};

struct enemy{
    string name;
    int health;
    int attack;
    Dificulty df;

    void criar(string snome, int shealth, int sattack, Dificulty sdf){
        name = snome;
        health = shealth;
        attack = sattack;
        df = sdf;
    }

    void status(){
        cout<<"NONME:"<<name<<endl;
        cout<<"PONTOS DE VIDA:"<<health<<endl;
        cout<<"DANO:"<<attack<<endl;
        cout<<"DIFICULDADE:"<<df<<endl;
        cout<<"\n";
    }

	string get_Name(){
		return name;
	}

    int get_Hp(){
    	return health;
	}

	int get_attack(){
    	return attack;
	}

	void dano_recebido(int ataque){
		health -= ataque;
		if(health < 0)
			health = 0;
	}

};


int main(){
	setlocale(LC_ALL, "Portuguese");
	char r;
	int controle= 1;

	while(true){
		string name;
		cout<<"DIGITE O NOME DO SEU JOGADOR: ";
		cin>>name;
	    enemy enemies[3];
        enemies[0].criar("skull", 50,15, easy);
	    enemies[1].criar("gnoll",100, 30, medium);
	    enemies[2].criar("chronos", 200, 45, hard);

	    player player1;
	    player1.criar(name, 400, 60);

	    while(true){
	        string op;
	        system("cls");
	        cout<<"==========BATALHA========== "<<"\n\n";
	        player1.status();
		    for(int i = 0;i < 3;i++){
		        enemies[i].status();
		    }


	        while(true){
	            cout<<"Quem você quer atacar? [Digite o nome do inimigo]:";
	            cin>>op;
	            if(op == enemies[0].get_Name() || op == "caveira" && enemies[0].get_Hp() > 0){
	                enemies[0].dano_recebido(player1.get_attack());
	                cout<<"\nVocê destruiu a "<<enemies[0].get_Name()<<" com um único golpe de espada";
	                break;
	            }
	            else if(op == enemies[1].get_Name() || op == "gnoll" && enemies[1].get_Hp() > 0){
					enemies[1].dano_recebido(player1.get_attack());
	                cout<<"\nVocê atacou o "<<enemies[1].get_Name();
	                break;
	            }
	            else if(op == enemies[2].get_Name() || op == "chronos" && enemies[2].get_Hp() > 0){
	                enemies[2].dano_recebido(player1.get_attack());
	                cout<<"\nVocê atacou o "<<enemies[2].get_Name();
	                break;
	            }
	        }

	        if(enemies[0].get_Hp() > 0){
	            player1.dano_recebido(enemies[0].get_attack());
	            cout<<"\n\nO "<<enemies[0].get_Name()<<" te atacou"<<
	            "\nVocê perdeu 15 pontos de vida\n";
	        }

	        if(enemies[1].get_Hp() > 0){
	            player1.dano_recebido(enemies[1].get_attack());
	            cout<<"\n\nO "<<enemies[1].get_Name()<<" te atacou"<<
	            "\nVocê perdeu 30 pontos de vida\n";
	        }

	        if(enemies[2].get_Hp() > 0){
	            player1.dano_recebido(enemies[2].get_attack());
	            cout<<"\n\nO "<<enemies[2].get_Name()<<" te atacou"<<
	            "\nVoc~e perdeu 45 pontos de vida\n";
	        }
            if(player1.get_Hp() == 0){
	            cout<<"\n\nVocê Morreu! Sua alma foi para o Hades\n\n";
	            break;
	        }

	        if(enemies[0].get_Hp() == 0 && enemies[1].get_Hp() == 0 && enemies[2].get_Hp() == 0){
	            cout<<"\n\nVocê venceu! Agora sua espada está banhada com o sangue dos seus inimigos\n\n";
	            break;
	        }

	        if(player1.get_Hp() <= 30 && player1.get_Hp() > 0){
		    	if(controle == 1){//condi??o para garantir que ocorra uma ?nica vez
		    		player1.fury(20, 20);
			    	cout<<"\nVocê está perto da morte!\n"<<"Lute pela sua sobrevivência"
					<<"\nVocê ganha +20 pts de vida e 20 pts de dano\n";
				}
		    	controle = 2;
		    }
	        cout<<"\nPressione qualquer tecla para seguir";
	        getche();
		}
		cout<<"\n\nQuer jogar novamente?[S|N] ";
		cin>>r;
		if(r == 'n' || r == 'N')
	        break;
	}
    return 0;
}
