#include <iostream>
#include <string.h>
using namespace std;
//alterado
void tiraSpace(char *palavraSecreta, char *palavraSemEspaco); //line 23
void upperCase(char *palavraSecreta);                         //line 44
void tela(char *palavraDescoberta, char *dica);
char letraUpper(char letra);
bool letrasNaoDescobertas(char *palavraDescoberta);
void inicializa(char *vetor, int tamanho);
bool letraValida(char letra);


bool jogo(char *palavraSecreta, char *palavraDescoberta,char letra, char *dica);
//////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{   
    int escolha = 1;
    while(escolha == 1){
    
    int chances= 4;
    char dica[20], letra;
    char palavraSecreta[20];
    char palavraDescoberta[20]={""};
    char onlyChar[20] = {""};
    bool acerto;

    chances = 4;
    cout<<"Dica: ";
    cin.getline(dica, 20);
    cout<<"Palavra secreta: ";
    cin.getline(palavraSecreta, 20);
    int tamanho = strlen(palavraSecreta);

    inicializa(palavraDescoberta, tamanho);
    tela(palavraDescoberta, dica);
        while (chances>0 && letrasNaoDescobertas(palavraDescoberta))
        {   cout<<"Chances: "<<chances<<endl;
            cout<<"Tamanho da palavra: "<<tamanho<<endl;
            cout<<"Escolha uma letra: ";
            cin>>letra;
            while(!(letraValida(letra))){
                cin>>letra;
            }
            acerto = jogo(palavraSecreta, palavraDescoberta, letra, dica);
            if (!acerto)
            {   cout<<"Essa palavra nao tem a letra "<< letra <<"."<<endl;
                chances--;
            } else
            {
                cout<<"Voce acertou , continue assim!"<<endl;
            }    
        }
        if(chances == 0 ){
            cout<<"A palavra era: "<<palavraSecreta<<endl;
            cout<<"Voce perdeu, na proxima vez tenho certeza que voce ganhara!\n";
        } else
        {
            cout<<"Parabens voce ganhou!!!\n";
        }
        cout<<"Deseja jogar novamente? 1- Sim   2- Nao: ";
        cin>>escolha;
        setbuf(stdin, NULL);
        }
    system("pause");
    return 0;
}

void tiraSpace(char *palavraSecreta, char *palavraSemEspaco){
    int n = strlen(palavraSecreta);
   int j =0;
    for (int i = 0; i < n; i++)
    {
        if (palavraSecreta[i] != ' ')
        {   
            palavraSemEspaco[j] = palavraSecreta[i];
            j++;

        }
    }
}

void upperCase(char *palavraSecreta){
    for(int i=0; i<strlen(palavraSecreta); i++)
    {   
        char letra = palavraSecreta[i];
        if(letra >= 'a' && letra <= 'z')
        {
            palavraSecreta[i] = 'A'+(letra-'a');
        }
    }
}
void tela(char *palavraDescoberta, char *dica){
        system("cls");
        cout<<"Dica: "<< dica<<endl;
        for (size_t i = 0; i < strlen(palavraDescoberta); i++)
        {   
            if (palavraDescoberta[i] == '0' )
            {
                cout<<" _ ";
            } else{
                cout<<" "<<palavraDescoberta[i]<<" ";
            }
            
        }
        cout<<endl;       
}
char letraUpper(char letra){
    if (letra >= 'a' && letra <= 'z')
    {
        letra = 'A'+(letra-'a');
    }
    return letra;
}
bool letrasNaoDescobertas(char *palavraDescoberta){
    bool faltaLetra = false ;
    for (size_t i = 0; i < strlen(palavraDescoberta); i++)
    {
       if( palavraDescoberta[i] == '0'){
           faltaLetra = true;
           break;
       }
    }
    return faltaLetra;
}
void inicializa(char *vetor, int tamanho){
    for (size_t i = 0; i < tamanho; i++)
    {
        vetor[i]='0';
    }
}
bool jogo(char *palavraSecreta, char *palavraDescoberta,char letra, char *dica){
    bool acerto = false;
    letra = letraUpper(letra);
    upperCase(palavraSecreta);
    

    for (size_t i = 0; i < strlen(palavraSecreta); i++)
    {   
        if(palavraSecreta[i] == letra ){
            palavraDescoberta[i] = letra;
            acerto = true;
        } else if(palavraSecreta[i] == '-'){
            palavraDescoberta[i] = '-';
        } else if (palavraSecreta[i] == ' '){
            palavraDescoberta[i] = ' ';
        }
    }
    tela(palavraDescoberta, dica);
    return acerto;
}
bool letraValida(char letra){
    if ( !((letra >= 'a' && letra <= 'z') || (letra>='A' && letra <= 'Z')) )
    {
        cout<<"Letra invalida, digite novamente!\n";
        return false;
    }
    return true;
    
}
