#include <iostream>
#include <time.h>
#include <locale.h>
#include <limits>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;

struct horario{
    int hora,minuto,segundo;
};
struct data{
    int dia=0,mes=0,ano=0;
};
struct assunto{
    string genero;
};
struct autor{
    int codigo=0,idade;
    string nomeCompleto,pais;
    int obrasCadastradas=0;
};
struct editora{
    int codigo;
    string nome;
    int obrasCadastradas=0;
};
struct usuario{
    int codigo,idade;
    string nome,pais;
    data nascimento;
    };
struct obra{
    string nome,tipo,editora,assunto;
    data lancamento;
    autor escritor;
    int paginas,codigo;
    bool disponibilidade=true;
    int atraso=0;
    data devolucao;
};

void text_color(int a){//fun��o que muda de cor os textos do c�digo
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, a);
}
void piscar_verde(){// fun��o para piscar a tela em verde
for(int i=0;i<2;i++){
        system("color af");
        Sleep(400);
        system("color 0f");
        Sleep(300);
    }
}
void piscar_colorido(string x){// fun��o que pisca a tela colorido
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t"<<x<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    system("color 1f");
    Sleep(200);
    system("color 2f");
    Sleep(200);
    system("color 3f");
    Sleep(200);
    system("color 4f");
    Sleep(200);
    system("color 5f");
    Sleep(200);
    system("color 6f");
    Sleep(200);
    system("color 7f");
    Sleep(200);
    system("color 0f");
    Sleep(600);
}
void piscar_vermelho(){// fun��o que pisca a tela em vermelho
for(int i=0;i<2;i++){
        system("color 40");
        Sleep(400);
        system("color 0f");
        Sleep(300);
    }
}

data hoje(data a){//fun��o que calcula a data de hoje
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    a.ano=tm.tm_year+1900;
    a.mes=tm.tm_mon+1;
    a.dia=tm.tm_mday;
    return(a);
}
bool verificador(int &a, string c){//verificador que impede de colocar letra em locais que recebe valores int
    bool aux=false;
    do {
    text_color(3);
    cout << c;
    text_color(15);
    if (cin >> a) {
        if (a >= 0 && a <= 10000) {
            aux = true;
        }
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
} while (aux == false);
return true;
}

void ler_autor(autor a){//fun��o que imprime os dados de autores
        text_color(10);
        cout<<"\n\tAutor cadastrado\n";
        cout<<"\nNome: "<<a.nomeCompleto<<endl;
        cout<<"Idade: "<<a.idade<<endl;
        cout<<"Pa�s de Origem: "<<a.pais<<endl;
        cout<<"N�mero de Obras Cadastradas: "<<a.obrasCadastradas<<endl;
        cout<<"C�digo de autor: #"<<a.codigo<<endl<<endl;
        text_color(15);
}
void ler_obra(obra a){//fun��o que imprime os dados de obra
    text_color(10);
    cout<<"\nTipo: "<<a.tipo<<endl;
    cout<<"Nome da obra: "<<a.nome<<endl;
    cout<<"Nome do autor: "<<a.escritor.nomeCompleto<<endl;
    cout<<"N�mero de p�ginas: "<<a.paginas<<endl;
    cout<<"Assunto: "<<a.assunto<<endl;
    printf("Dada de lan�amento: %d/%d/%d\n",a.lancamento.dia,a.lancamento.mes,a.lancamento.ano);
    if(a.disponibilidade==true){
        cout<<"Disponibilidade: Dispon�vel"<<endl;
    }
    else{
            text_color(4);
        cout<<"Disponibilidade: Indispon�vel"<<endl;
        printf("Dada de devolu��o: %d/%d/%d\n",a.devolucao.dia,a.devolucao.mes,a.devolucao.ano);
        text_color(15);
    }
    cout<<"\nC�digo da obra: #"<<a.codigo<<endl<<endl;
    text_color(15);
}
void ler_usuario(usuario a){//fun��o que imprime os dados de usu�rios
    text_color(10);
    cout<<"\nNome: "<<a.nome<<endl;
    cout<<"Pa�s de origem: "<<a.pais<<endl;
    printf("Data de nascimento: %d/%d/%d\n",a.nascimento.dia,a.nascimento.mes,a.nascimento.ano);
    cout<<"Idade: "<<a.idade<<endl;
    cout<<"C�digo de Usu�rio: #"<<a.codigo<<endl<<endl;
    text_color(15);
}
void ler_editora(editora a){//fun��o que imprime os dados de usu�rios
    text_color(10);
    cout<<"\nNome: "<<a.nome<<endl;
    cout<<"\nObras cadastradas: "<<a.obrasCadastradas<<endl<<endl;
    text_color(15);
}

void escrever_obra(obra& a,autor b[],int aux_autor){//fun��o que cria os dados de obras
    bool aux;
    cin.ignore();
    text_color(14);
    cout<<"\nInsira o nome do autor: ";
    getline(cin,a.escritor.nomeCompleto);
    for(int i=0;i<aux_autor;i++){
        if(a.escritor.nomeCompleto==b[i].nomeCompleto){
            ler_autor(b[i]);
            text_color(14);
            cout<<"\nInsira o tipo da obra: ";
            getline(cin,a.tipo);
            cout<<"\nInsira o nome da obra: ";
            getline(cin,a.nome);
            cout<<endl;
            do{
                cout<<"Insira a quantidade de p�ginas: ";
                cin>>a.paginas;
            }while(a.paginas<1||isalnum(a.paginas)==true||isalpha(a.paginas)==true);
            cin.ignore();
            do{
            cout<<"\nInsira a data de lan�amento da obra (dd/mm/aaaa): ";
            scanf("%d/%d/%d",&a.lancamento.dia,&a.lancamento.mes,&a.lancamento.ano);
            }while(a.lancamento.dia>31||a.lancamento.dia<=0||a.lancamento.mes>12||a.lancamento.mes<=0||a.lancamento.ano>2023||a.lancamento.ano<=0);
            cin.ignore();
            cout<<"\nInsira o assunto da obra: ";
            getline(cin,a.assunto);
            cout<<"\nInsira o nome da editora da obra: ";
            getline(cin,a.editora);
            cout<<endl;
            piscar_verde();
            break;
        }
        else{
            piscar_vermelho();
            text_color(4);
            cout<<"\n\tEste Autor n�o est� cadastrado na nossa Base de dados!!Cadastre-o antes.\n"<<endl;
            text_color(15);
            return;
        }
    }
    text_color(15);
}
void escrever_autor(autor &a){//fun��o que cria os dados de autores
    text_color(14);
    cin.ignore();
    cout<<"\nInsira o nome completo do autor: ";
    getline(cin,a.nomeCompleto);
    cout<<"\nInsira o pa�s de origem do autor: ";
    getline(cin,a.pais);
    cout<<endl;
    do{
        cout<<"Insira a idade do autor: ";
        cin>>a.idade;
    }while(a.idade<0||isalnum(a.idade)==true||isalpha(a.idade)==true);
    text_color(15);
}
void escrever_usuario(usuario& a){//fun��o que cria os dados de usu�rios
    text_color(14);
    data aux;
    hoje(aux);
    cin.ignore();
    cout<<"\nInsira o nome: ";
    getline(cin,a.nome);
    do{
    cout<<"\nInsira sua data de nascimento (dd/mm/aaaa): ";
    scanf("%d/%d/%d",&a.nascimento.dia,&a.nascimento.mes,&a.nascimento.ano);
    }while(a.nascimento.dia>31||a.nascimento.dia<=0||a.nascimento.mes>12||a.nascimento.mes<=0||a.nascimento.ano>2023||a.nascimento.ano<=0);
    cin.ignore();
    cout<<"\nInsira seu pa�s de origem: ";
    getline(cin,a.pais);
    cout<<endl;
    do{
        cout<<"Insira sua idade: ";
        cin>>a.idade;
        cout<<endl;
    }while(a.idade<0||isalnum(a.idade)==true||isalpha(a.idade)==true);
    text_color(15);
}
void escrever_editora(editora &a){//fun��o que cria os dados de editora
    text_color(14);
    cin.ignore();
    cout<<"\nInsira o nome da editora: ";
    getline(cin,a.nome);
    text_color(15);
}

void cadastrar_obras(obra a[],int &tam,autor b[],int aux_autor){//fun��o que cadastra os dados de obras em quantidade
        for( int i=0;i<tam;i++){
            cout<<"\n\tObra ["<<i+1<<"]\n"<<endl;
            escrever_obra(a[i],b,aux_autor);
            a[i].codigo=i+1;
        }
}
void cadastrar_autores(autor a[],int &tam){//fun��o que cadastra os dados de autores em quantidade
        for( int i=0;i<tam;i++){
            cout<<"\n\tAutor ["<<i+1<<"]\n"<<endl;
            escrever_autor(a[i]);
            a[i].codigo =i+1;
        }
}
void cadastrar_usuarios(usuario a[],int &b){//fun��o que cadastra os dados de usu�rios em quantidade
        for( int i=0;i<b;i++){
            cout<<"\n\tUsu�rio ["<<i+1<<"]     "<<endl;
            cout<<endl;
            escrever_usuario(a[i]);
            a[i].codigo=i+1;
        }
}
void cadastrar_editoras(editora a[], int &b){//fun��o que cadastra os dados de editoras em quantidade
    for( int i=0;i<b;i++){
            cout<<"\n\tEditora ["<<i+1<<"]\n"<<endl;
            escrever_editora(a[i]);
            a[i].codigo =i+1;
        }
}

void ler_cadastro_obras(obra a[],int b){//fun��o que imprime os dados de obras em quantidade
    text_color(10);
    for(int i=0;i<b;i++){
        cout<<"\n\tObras cadastradas ["<<i+1<<"]\n"<<endl;
        ler_obra(a[i]);
        }
}
void ler_cadastro_autores(autor a[],int b){//imprime cadastro de autores em lote
    for(int i=0;i<b;i++){
        text_color(10);
        cout<<"\n\tAutores Cadastrados ["<<i+1<<"]\n"<<endl;
        ler_autor(a[i]);
        }
    text_color(15);
}
void ler_cadastro_usuarios(usuario a[],int b){//imprime cadastro de usu�rios em lote
    text_color(10);
    for(int i=0;i<b;i++){
        cout<<"\n\tUsu�rio["<<i+1<<"]";
        ler_usuario(a[i]);
    }
    text_color(15);
}
void ler_cadastro_editoras(editora a[], int b){//imprime em lote o cadastro de editoras
    text_color(10);
    for(int i=0; i<b; i++){
        cout<<"\n\tEditora Cadastrada["<<i+1<<"]\n"<<endl;
        ler_editora(a[i]);
    }
    text_color(15);
}
void ler_cadastro_assuntos(obra a[],int b){//imprime em lote o cadastro de assuntos
    text_color(10);
    cout<<"\n\tAssuntos cadastrados\n"<<endl;
    for(int i=0;i<b;i++){
        if(a[i].assunto!=a[i-1].assunto){
        cout<<"["<<i+1<<"] "<<a[i].assunto<<endl;
        }
    }
    text_color(15);
}
void ler_cadastro_tipos(obra a[],int b){//imprime em lote o cadastro de tipos
    text_color(10);
    cout<<"\n\tAssuntos cadastrados\n"<<endl;
    for(int i=0;i<b;i++){
        if(a[i].tipo!=a[i-1].tipo){
        cout<<"["<<i+1<<"] "<<a[i].tipo<<endl;
        }
    }
    text_color(15);
}

int verificador_cadastro_obras(obra a[],int b,int escolha){//verifica se existe alguma obra cadastrada
    for(int i=0;i<b;i++){
        if(a[i].codigo>0) return(escolha);
        else {
                system("cls");
                text_color(4);
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNenhuma Obra est� cadastrada! Cadastre alguma obra antes.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                text_color(15);
                escolha=0;
                return(escolha);
                }
        }
}
int verificador_cadastro_autores(autor a[],int b,int escolha){//verifica se existe algum autor cadastrado
    for(int i=0;i<b;i++){
        if(a[i].codigo>0) return(escolha);
        else {
            system("cls");
            text_color(4);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNenhum autor est� cadastrado! Cadastre algum autor antes.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            text_color(15);
            escolha=0;
            return(escolha);
        }
        }
}
int verificador_cadastro_editoras(editora a[],int b,int escolha){//verifica se existe alguma editora cadastrada
    for(int i=0;i<b;i++){
        if(a[i].codigo>0) return(escolha);
        else {
            system("cls");
            text_color(4);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNenhuma editora est� cadastrada! Cadastre alguma editora antes.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            text_color(15);
            escolha=0;
            return(escolha);
        }
        }
}
int verificador_cadastro_usuarios(usuario a[],int b,int escolha){//verifica se existe algum usu�rio cadastrado
    for(int i=0;i<b;i++){
        if(a[i].codigo>0) return(escolha);
        else {
            system("cls");
            text_color(4);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNenhum Usu�rio est� cadastrado! Cadastre algum usu�rio antes.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            text_color(15);
            escolha=0;
            return(escolha);
        }

        }
}

void pesquisa_assunto(obra a[], int &b, string c){//pesquisa por assuntos
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].assunto==c){
            piscar_verde();
            ler_obra(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma obra com este assunto foi encontrada!    \n";
        text_color(15);
    }
}
void pesquisa_tipo(obra a[], int &b, string c){//pesquisa por tipo
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].tipo==c){
            piscar_verde();
            ler_obra(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma obra deste tipo foi encontrada!    \n";
        text_color(15);
    }
}
void pesquisa_nome_Autor(autor a[], int &b, string c){//fun��o que pesquisa por nome de autor
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].nomeCompleto==c){
            piscar_verde();
            ler_autor(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma obra deste autor foi encontrada!    \n";
        text_color(15);
    }
}
void pesquisa_nome_editora(obra a[], int &b, string c){//fun��o que pesquisa por nome de editora
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].editora==c){
            piscar_verde();
            ler_obra(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma editora com este nome foi encontrada!    \n";
        text_color(15);
    }
}
void pesquisa_nome_obra(obra a[], int &b, string c){//fun��o que pesquisa por nome de obra
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].nome==c){
            piscar_verde();
            ler_obra(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma obra com este nome foi encontrada!    \n";
        text_color(15);
    }
}
void pesquisa_nome_usuario(usuario a[], int &b, string c){//fun��o que pesquisa por nome de usu�rio
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].nome==c){
            piscar_verde();
            ler_usuario(a[i]);
            contador++;

        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum usu�rio com este nome foi encontrado!    \n";
        text_color(15);
    }

}
void pesquisa_dados_autor_nome(autor a[], int &b, string c){//fun��o que pesquisa os dados do por nome de autor
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].nomeCompleto==c){
            piscar_verde();
            ler_autor(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum autor com esse nome foi encontrado!    \n";
        text_color(15);
    }
}
void pesquisa_codigo_autor(autor a[], int &b, int c){//fun��o que pesquisa por c�digo de autor
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].codigo==c){
            piscar_verde();
            ler_autor(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum autor com esse c�digo foi encontrado!    \n";
        text_color(15);
    }
}
void pesquisa_codigo_usuario(usuario a[], int &b, int c){//fun��o que pesquisa por c�digo de usu�rio
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].codigo==c){
            piscar_verde();
            ler_usuario(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum usu�rio com esse c�digo foi encontrado!    \n";
        text_color(15);
    }
}
void pesquisa_codigo_obra(obra a[], int &b, int c){//fun��o que pesquisa por c�digo de obra
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].codigo==c){
            piscar_verde();
            ler_obra(a[i]);
            contador++;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum autor com esse c�digo foi encontrado!    \n";
        text_color(15);
    }
}
void pesquisa_dados_autor_codigo(autor a[], int &b, int c){//fun��o que pesquisa dados de auto por c�digo
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].codigo==c){
            piscar_verde();
            ler_autor(a[i]);
            contador++;
        }
    }
    if(contador==0){
        text_color(4);
        cout<<"\n    Nenhum autor com esse c�digo foi encontrado!    \n";
        text_color(15);
    }
}
void pesquisa_disponibilidade(obra a[], int &b, bool c){//fun��o que pesquisa por disponibilidade da obra
    int contador=0;
    for(int i=0; i<b; i++){

        if(a[i].disponibilidade==true && c==true){
            cout<<"\t\t\t\t\t<=====Livros Dispon�veis=====>\n\n\n"<<endl;
            ler_obra(a[i]);
            contador++;
        }
        else if(a[i].disponibilidade==false && c==false){
            cout<<"\t\t\t\t\t<=====Livros Indispon�veis=====>\n\n\n"<<endl;
            ler_obra(a[i]);
            text_color(14);
            printf("%d/%d/%d",a[i].devolucao.dia,a[i].devolucao.mes,a[i].devolucao.ano);
            text_color(15);
            contador++;
        }
        if(contador==0 && c==true){
            piscar_vermelho();
            text_color(4);
            cout<<"Nenhum livro dispon�vel foi encontrado!"<<endl;
            text_color(15);
        }
        else if(contador==0 && c==false){
            piscar_vermelho();
            text_color(4);
            cout<<"Nenhum livro indispon�vel foi encontrado!"<<endl;
            text_color(15);
        }
    }
}
void pesquisa_atrasados(obra a[], int &b){//fun��o que pesquisa por obras atrasadas
    int contador=0;
    for(int i=0; i<b; i++){
        if(a[i].atraso>7){
            ler_obra(a[i]);
            contador++;
        }
    }
        if(contador==0){
            system("cls");
            piscar_vermelho();
            text_color(4);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNenhuma obra atrasada foi encontrada!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            text_color(15);
    }
}

void alterar_Usuario(usuario a[],int &b){//fun��o que altera o cadastro do usu�rio
    int escolha;
    int codigo;
    cout<<"Qual � o c�digo do usu�rio que deseja alterar?"<<endl;
    cin>>codigo;
    int contador=0;
    int posicao;
    for(int i=0; i<b; i++){
        if(a[i].codigo==codigo){
            ler_usuario(a[i]);
            contador++;
            posicao=i;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum usu�rio com esse c�digo foi encontrado!    \n";
        text_color(15);
    }
    cout<<endl;
    cout<<"O que voc� deseja alterar neste usu�rio?\n\n\n"<<endl;
    cout<<"[1] Nome do usu�rio\n"<<endl;
    cout<<"[2] Nascimento do usu�rio\n"<<endl;
    cout<<"[3] Pa�s de origem do usu�rio\n"<<endl;
    cout<<"[4] Idade do usu�rio\n"<<endl;
    verificador(escolha,"Insira uma das op��es:");
    switch(escolha){
    case 1:
        cin.ignore();
        cout<<"Insira o novo nome de usu�rio:";
        getline(cin,a[posicao].nome);
        cout<<endl;
        ler_usuario(a[posicao]);
        break;
    case 2:
        cin.ignore();
        cout<<"Insira a nova data de nascimento do usu�rio (dd/mm/aaaa):";
        do{
        scanf("%d/%d/%d",&a[posicao].nascimento.dia,&a[posicao].nascimento.mes,&a[posicao].nascimento.ano);
        }while(a[posicao].nascimento.dia>31||a[posicao].nascimento.dia<=0||a[posicao].nascimento.mes>12||a[posicao].nascimento.mes<=0||a[posicao].nascimento.ano>2023||a[posicao].nascimento.ano<=0);
        cout<<endl;
        ler_usuario(a[posicao]);
        break;
    case 3:
        cin.ignore();
        cout<<"Insira o novo pa�s de origem do usu�rio:";
        getline(cin,a[posicao].pais);
        cout<<endl;
        ler_usuario(a[posicao]);
        break;
    case 4:
        cin.ignore();
        cout<<"Insira a nova idade do usu�rio:";
        cin>>a[posicao].idade;
        cout<<endl;
        ler_usuario(a[posicao]);
        break;

    }
}
void alterar_Editora(editora a[],int &b){//fun��o que altera o cadastro da editora
    int escolha;
    int codigo;
    cout<<"Qual � o c�digo da editora que deseja alterar?"<<endl;
    cin>>codigo;
    int contador=0;
    int posicao;
    for(int i=0; i<b; i++){
        if(a[i].codigo==codigo){
            ler_editora(a[i]);
            contador++;
            posicao=i;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhuma editora com esse c�digo foi encontrada!    \n";
        text_color(15);
        return;
    }
    cout<<endl;
    cout<<"O que voc� deseja alterar nesta editora?\n\n\n"<<endl;
    cout<<"[1] Nome da editora\n"<<endl;
    verificador(escolha,"Insira uma das op��es:");
    switch(escolha){
    case 1:
        cin.ignore();
        cout<<"Insira o novo nome de editora:";
        getline(cin,a[posicao].nome);
        cout<<endl;
        ler_editora(a[posicao]);
        break;
    }
}
void alterar_Autor(autor a[],int &b){//fun��o que altera o cadastro do autor
    int escolha;
    int codigo;
    cout<<"Qual � o c�digo do autor que deseja alterar?"<<endl;
    cin>>codigo;
    int contador=0;
    int posicao;
    for(int i=0; i<b; i++){
        if(a[i].codigo==codigo){
            ler_autor(a[i]);
            contador++;
            posicao=i;
        }
    }
    if(contador==0){
        piscar_vermelho();
        text_color(4);
        cout<<"\n    Nenhum autor com este c�digo foi encontrado!    \n";
        text_color(15);
    }
    cout<<endl;
    cout<<"O que voc� deseja alterar neste usu�rio?\n\n\n"<<endl;
    cout<<"[1] Nome do autor\n"<<endl;
    cout<<"[2] Idade do autor\n"<<endl;
    cout<<"[3] Pa�s de origem do autor\n"<<endl;
    verificador(escolha,"Insira uma das op��es:");
    switch(escolha){
    case 1:
        cin.ignore();
        cout<<"Insira o novo nome de autor:";
        getline(cin,a[posicao].nomeCompleto);
        cout<<endl;
        ler_autor(a[posicao]);
        break;
    case 2:
        cin.ignore();
        cout<<"Insira a nova idade do autor:";
        cin>>a[posicao].idade;
        cout<<endl;
        ler_autor(a[posicao]);
        break;
    case 3:
        cin.ignore();
        cout<<"Insira o novo pa�s de origem do autor:";
        getline(cin,a[posicao].pais);
        cout<<endl;
        ler_autor(a[posicao]);
        break;
    }
}
void alterar_Obra(obra a[],int &b){//fun��o que altera o cadastro da obra
    int escolha;
    int codigo;
    cout<<"Qual � o c�digo da obra que deseja alterar?"<<endl;
    cin>>codigo;
    int contador=0;
    int posicao;
    for(int i=0; i<b; i++){
        if(a[i].codigo==codigo){
            ler_obra(a[i]);
            contador++;
            posicao=i;
        }
    }
    if(contador==0){
        text_color(4);
        cout<<"\n    Nenhum autor com este c�digo foi encontrado!    \n";
        text_color(15);
    }
    cout<<endl;
    cout<<"O que voc� deseja alterar nesta obra?\n\n\n"<<endl;
    cout<<"[1] Nome da obra\n"<<endl;
    cout<<"[2] Assunto da obra\n"<<endl;
    cout<<"[3] Nome do autor\n"<<endl;
    cout<<"[4] Nome da editora\n"<<endl;
    cout<<"[5] Data de lan�amento\n"<<endl;
    cout<<"[6] N�mero de p�ginas\n"<<endl;
    cout<<"[7] Tipo de obra\n"<<endl;
    verificador(escolha,"Insira uma das op��es:");
    switch(escolha){
    case 1:
        cin.ignore();
        cout<<"Insira o novo nome da obra:";
        getline(cin,a[posicao].nome);
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 2:
        cin.ignore();
        cout<<"Insira o novo assunto da obra:";
        cin>>a[posicao].assunto;
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 3:
        cin.ignore();
        cout<<"Insira o novo nome do autor:";
        getline(cin,a[posicao].escritor.nomeCompleto);
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 4:
        cin.ignore();
        cout<<"Insira o novo nome da editora:";
        getline(cin,a[posicao].editora);
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 5:
        cin.ignore();
        cout<<"Insira a nova data de lan�amento da obra:";
        do{
        scanf("%d%d%d",&a[posicao].lancamento.dia,&a[posicao].lancamento.mes,&a[posicao].lancamento.ano);
        }while(a[posicao].lancamento.dia>31||a[posicao].lancamento.dia<=0||a[posicao].lancamento.mes>12||a[posicao].lancamento.mes<=0||a[posicao].lancamento.ano>2023||a[posicao].lancamento.ano<=0);
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 6:
        cin.ignore();
        cout<<"Insira o novo n�mero de p�ginas da obra:";
        cin>>a[posicao].paginas;
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    case 7:
        cin.ignore();
        cout<<"Insira o novo tipo da obra:";
        getline(cin,a[posicao].tipo);
        cout<<endl;
        ler_obra(a[posicao]);
        break;
    }
}

bool is_leap_year(int year) {//fun��o que verfica se o ano inserido � bissexto ou n�o
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int days_in_month(int month, int year) {//fun��o que verifica quantos dias tem em determinado m�s
    switch(month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4:
            return 30;
        case 6:
            return 30;
        case 9:
            return 30;
        case 11:
            return 30;
        default:
            return 31;
    }
}
int date_to_days(int day, int month, int year) {//fun��o que soma os dias
    int days = day;
    for (int m = 1; m < month; m++) {
        days += days_in_month(m, year);
    }
    for (int y = 1900; y < year; y++) {
        days += is_leap_year(y) ? 366 : 365;
    }
    return days;
}
void data_devolucao(data &a){
    if (a.dia > days_in_month(a.mes,a.ano)) {
        a.dia -= days_in_month(a.mes, a.ano);
        a.mes++;
        if (a.mes > 12) {
            a.mes = 1;
            a.ano++;
        }
    }
}
void sistema_devolucao_livro(obra a[], int &b, usuario d[]){//fun��o que faz o empr�stimo e a devolu��o das obras
   int escolha;
   int Aux_codigo_usuario;
   int auxiliar_posicao=0;
   data data_retirada;
        verificador(escolha,"Insira o c�digo de obra que deseja procurar: ");
        int contador=0;
        int CONTADOR=0;
        for(int i=0; i<b; i++){
            if(a[i].codigo==escolha){
                ler_obra(a[i]);
                contador++;
                auxiliar_posicao=i;
            }
        }
        if(contador==0){
            piscar_vermelho();
            text_color(4);
            cout<<"\n    Nenhum autor com esse c�digo foi encontrado!    ";
            text_color(15);
            return;
        }
        verificador(Aux_codigo_usuario,"Insira o seu c�digo de usu�rio: ");
        for(int i=0; i<b; i++){
            if(d[i].codigo==Aux_codigo_usuario){
                CONTADOR++;
            }
        }
        if(CONTADOR==0){
            cout<<"\n\tNenhum usu�rio com esse c�digo foi encontrado!    ";
            }
        if(CONTADOR!=0){
            cout<<"\t\t\t\t\t<=====Devolu��es e empr�stimo de obras=====>\n\n\n"<<endl;
            cout<<"[1] Cadastrar devolu��o de Obra\n"<<endl;
            cout<<"[2] Cadastrar retirada de Obra\n"<<endl;
            cout<<"[0] Sair\n"<<endl;
            verificador(escolha,"Qual das op��es voc� deseja utilizar? ");
            switch(escolha)
                {
                case 1:
                    if(a[auxiliar_posicao].disponibilidade==true){
                        cout<<"N�o � poss�vel devolver a obra, porque ela est� dispon�vel na biblioteca"<<endl;
                        break;
                    }
                    else{
                        a[auxiliar_posicao].disponibilidade=true;
                        cout<<"Livro devolvido com sucesso\n";
                        a[auxiliar_posicao].atraso=0;
                    }
                    break;
                case 2:
                    if(a[auxiliar_posicao].disponibilidade==false){
                        cout<<"N�o � poss�vel pegar a obra, porque ela est� indispon�vel"<<endl;
                        break;
                    }
                    else{
                        int quantidade_dias_desde_retirada;
                        do{
                        cout<<"Insira a data de retirada (dd/mm/aaaa): ";
                        scanf("%d/%d/%d",&data_retirada.dia,&data_retirada.mes,&data_retirada.ano);
                        }while(data_retirada.dia>31||data_retirada.dia<=0||data_retirada.mes>12||data_retirada.mes<=0||data_retirada.ano>2023||data_retirada.ano<=0);
                        int dias_retirada=date_to_days(data_retirada.dia, data_retirada.mes, data_retirada.ano);
                        data hoje_variavel;
                        hoje_variavel=hoje(hoje_variavel);

                        int dias_hoje=date_to_days(hoje_variavel.dia, hoje_variavel.mes, hoje_variavel.ano);
                        quantidade_dias_desde_retirada=dias_hoje-dias_retirada;
                        a[auxiliar_posicao].atraso=quantidade_dias_desde_retirada;
                        if(quantidade_dias_desde_retirada>7){
                            cout<<"O livro cadastrado est� em atraso ";
                            cout<<"h� "<<a[auxiliar_posicao].atraso<<" dias"<<endl;
                        }
                        else{
                            cout<<"O livro n�o est� em atraso ";
                            quantidade_dias_desde_retirada=7-quantidade_dias_desde_retirada;
                            piscar_verde();
                            text_color(2);
                            cout<<"A obra dever� ser devolvida em: "<<quantidade_dias_desde_retirada<<" dias"<<endl;
                            text_color(15);
                        }
                        a[auxiliar_posicao].disponibilidade=false;
                        cout<<"Livro emprestado com sucesso\n";
                        a[auxiliar_posicao].devolucao.dia=data_retirada.dia+7;
                        a[auxiliar_posicao].devolucao.mes=data_retirada.mes;
                        a[auxiliar_posicao].devolucao.ano=data_retirada.ano;
                        data_devolucao(a[auxiliar_posicao].devolucao);
                    }
                    break;
                case 0:
                    break;
                }
        }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha;//declara��o de todas as vari�veis utilizadas no c�digo
    int tam_obras;
    int tam_usuarios;
    int tam_autor;
    int tam_editora;
    string aux_pesquisa;
    usuario usuarios_db[50];
    obra obras_db[50];
    autor autores_db[50];
    editora editoras_db[50];
    int AUX_pesquisa;

    piscar_colorido("Seja bem-vindo � nossa biblioteca!!!");//tela de bem-vindo
do{//in�cio do loop do c�digo
    system("pause");
    system("cls");
    text_color(11);
    cout<<"\t\t\t\t\t\t<=====MENU=====>\n\n\n"<<endl;//primeiro menu
    text_color(15);
    cout<<"[1] Cadastros\n"<<endl;
    cout<<"[2] Pesquisas\n"<<endl;
    cout<<"[3] Listagens\n"<<endl;
    cout<<"[4] Sistema Devolu��es/Empr�stimos\n"<<endl;
    cout<<"[0] SAIR\n"<<endl;
    verificador(escolha,"Insira uma das op��es:");
    system("cls");
    switch(escolha){//MENU PRINCIPAL
    case 1:
        text_color(11);
        cout<<"\t\t\t\t\t<=====CADASTROS=====>\n\n\n"<<endl;//segundo menu
        text_color(15);
        cout<<"[1] Novo cadastro\n"<<endl;
        cout<<"[2] Alterar cadastro\n"<<endl;
        cout<<"[0] SAIR\n"<<endl;

        verificador(escolha,"Insira uma das op��es:");
        system("cls");
        switch(escolha){//CADASTROS
        case 1:
            text_color(11);
            cout<<"\t\t\t\t\t<=====NOVO CADASTRO=====>\n\n\n"<<endl;//terceiro menu
            text_color(15);
            cout<<"[1] Cadastrar Usu�rio\n"<<endl;
            cout<<"[2] Cadastrar Obra\n"<<endl;
            cout<<"[3] Cadastrar Autor\n"<<endl;
            cout<<"[4] Cadastrar Editora\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            system("cls");
            switch(escolha){//NOVO CADASTRO
            case 1:
                text_color(11);
                cout<<"\t\t\t\t\t<=====CADASTRAR USU�RIOS=====>\n\n\n"<<endl;//quarto menu
                text_color(15);
                cout<<"Quantos usu�rios voc� deseja cadastrar? ";
                cin>>tam_usuarios;
                cadastrar_usuarios(usuarios_db,tam_usuarios);
                ler_cadastro_usuarios(usuarios_db,tam_usuarios);
                break;
            case 2:
                verificador(tam_obras,"Quantas obras voc� deseja inserir? ");
                cadastrar_obras(obras_db,tam_obras,autores_db,tam_autor);
                ler_cadastro_obras(obras_db,tam_obras);
                break;
            case 3:
                verificador(tam_autor,"Quantos autores voc� deseja inserir? ");
                cadastrar_autores(autores_db,tam_autor);
                ler_cadastro_autores(autores_db,tam_autor);
                break;
            case 4:
                verificador(tam_editora,"Quantas editoras voc� deseja inserir? ");
                cadastrar_editoras(editoras_db,tam_editora);
                ler_cadastro_editoras(editoras_db,tam_editora);
                break;
            case 0:
                break;
            default:
            cout<<"Op��o inv�lida!!\n"<<endl;
            }//NOVO CADASTRO
            break;
        case 2:
            text_color(11);
            cout<<"\t\t\t\t\t<=====ALTERAR CADASTRO=====>\n\n\n"<<endl;//quinto menu
            text_color(15);
            cout<<"[1] Alterar cadastro de Usu�rio\n"<<endl;
            cout<<"[2] Alterar cadastro de Autor\n"<<endl;
            cout<<"[3] Alterar cadastro Obra\n"<<endl;
            cout<<"[4] Alterar cadastro Editora\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            system("cls");
            if(escolha==1)escolha=verificador_cadastro_usuarios(usuarios_db,tam_usuarios,escolha);
            if(escolha==2)escolha=verificador_cadastro_autores(autores_db,tam_autor,escolha);
            if(escolha==3)escolha=verificador_cadastro_obras(obras_db,tam_obras,escolha);
            if(escolha==4)escolha=verificador_cadastro_editoras(editoras_db,tam_editora,escolha);
            switch(escolha){//ALTERAR CADASTRO
            case 1:
                alterar_Usuario(usuarios_db,tam_usuarios);
                break;
            case 2:
                alterar_Autor(autores_db,tam_autor);
                break;
            case 3:
                alterar_Obra(obras_db,tam_obras);
                break;
            case 4:
                alterar_Editora(editoras_db, tam_editora);
                break;
            case 0:
                break;
            default:
                cout<<"Op��o inv�lida!!\n"<<endl;
            }//ALTERAR CADASTRO
            break;
        case 0:
            break;
        default:
        cout<<"Op��o inv�lida!!\n"<<endl;
        }//CADASTROS
        break;
    case 2:
        text_color(11);
        cout<<"\t\t\t\t\t<=====PESQUISAS=====>\n\n\n"<<endl;//sexto menu
        text_color(15);
        cout<<"[1] Pesquisa por Obra\n"<<endl;
        cout<<"[2] Pesquisa por Autor\n"<<endl;
        cout<<"[3] Pesquisa por Usu�rio\n"<<endl;
        cout<<"[4] Pesquisa por Editora\n"<<endl;
        cout<<"[5] Pesquisa por Disponibilidade\n"<<endl;
        cout<<"[0] SAIR\n"<<endl;

        verificador(escolha,"Insira uma das op��es:");
        system("cls");
        if(escolha==1||escolha==5)escolha=verificador_cadastro_obras(obras_db,tam_obras,escolha);
        if(escolha==2)escolha=verificador_cadastro_autores(autores_db,tam_autor,escolha);
        if(escolha==3)escolha=verificador_cadastro_usuarios(usuarios_db,tam_usuarios,escolha);
        if(escolha==4)escolha=verificador_cadastro_editoras(editoras_db,tam_editora,escolha);
        switch(escolha){//PESQUISAS
        case 1:
            text_color(11);
            cout<<"\t\t\t\t\t<=====PESQUISA POR OBRA=====>\n\n\n"<<endl;//s�timo menu
            text_color(15);
            cout<<"[1] Pesquisa por nome de Obra\n"<<endl;
            cout<<"[2] Pesquisa por c�digo de Obra\n"<<endl;
            cout<<"[3] Pesquisa por autor da Obra\n"<<endl;
            cout<<"[4] Pesquisa por editora da Obra\n"<<endl;
            cout<<"[5] Pesquisa por assunto da Obra\n"<<endl;
            cout<<"[6] Pesquisa por tipo\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            cout<<endl;
            switch(escolha){//PESQUISA POR OBRA
            case 1:
                cin.ignore();
                cout<<"Qual o nome da obra que deseja pesquisar? ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_nome_obra(obras_db,tam_obras,aux_pesquisa);
                break;
            case 2:
                verificador(AUX_pesquisa,"Qual � o c�digo da obra que deseja pesquisar?");
                cout<<endl;
                pesquisa_codigo_obra(obras_db,tam_obras,AUX_pesquisa);
                break;
            case 3:
                cin.ignore();
                cout<<"Qual o nome do autor da obra que deseja pesquisar? ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_nome_Autor(autores_db,tam_autor,aux_pesquisa);
                break;
            case 4:
                cin.ignore();
                cout<<"Qual o nome da editora da obra que deseja pesquisar? ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_nome_editora(obras_db,tam_obras,aux_pesquisa);
                break;
            case 5:
                cin.ignore();
                cout<<"Qual o assunto da obra que deseja pesquisar? ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_assunto(obras_db,tam_obras,aux_pesquisa);
                break;
            case 6:
                cin.ignore();
                cout<<"Qual o tipo da obra que deseja pesquisar? ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_tipo(obras_db,tam_obras,aux_pesquisa);
                break;
            case 0:
                break;
            default:
            cout<<"Op��o inv�lida!!\n"<<endl;
            }//PESQUISA POR OBRA
            break;
        case 2:
            text_color(11);
            cout<<"\t\t\t\t\t<=====PESQUISA POR AUTOR=====>\n\n\n"<<endl;//oitavo menu
            text_color(15);
            cout<<"[1] Pesquisa por nome de Autor\n"<<endl;
            cout<<"[2] Pesquisa por c�digo de Autor\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            cout<<endl;
            switch(escolha){//PESQUISA POR AUTOR
        case 1:
            cin.ignore();
            cout<<"Insira o nome do autor que deseja pesquisar: ";
            getline(cin,aux_pesquisa);
            cout<<endl;
            pesquisa_dados_autor_nome(autores_db,tam_autor,aux_pesquisa);
            break;
        case 2:
            verificador(AUX_pesquisa,"Insira o c�digo do autor que deseja pesquisar: ");
            cout<<endl;
            pesquisa_dados_autor_codigo(autores_db,tam_autor,AUX_pesquisa);
            break;
        case 0:
            break;
        default:
        cout<<"Op��o inv�lida!!\n"<<endl;
            }//PESQUISA POR AUTOR
            break;
        case 3:
            text_color(11);
            cout<<"\t\t\t\t\t<=====PESQUISA POR USU�RIO=====>\n\n\n"<<endl;//nono menu
            text_color(15);
            cout<<"[1] Pesquisa por nome de Usu�rio\n"<<endl;
            cout<<"[2] Pesquisa por c�digo de Usu�rio\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            switch(escolha){//PESQUISA POR USU�RIO
            case 1:
                cin.ignore();
                cout<<"Insira o nome do usu�rio que deseja pesquisar: ";
                getline(cin,aux_pesquisa);
                cout<<endl;
                pesquisa_nome_usuario(usuarios_db,tam_usuarios,aux_pesquisa);
                break;
            case 2:
                verificador(AUX_pesquisa,"Insira o c�digo do usu�rio que deseja pesquisar: ");
                cout<<endl;
                pesquisa_codigo_usuario(usuarios_db,tam_usuarios,AUX_pesquisa);
                break;
            case 0:
                break;
            default:
            cout<<"Op��o inv�lida!!\n"<<endl;
            }//PESQUISA POR USU�RIO
            break;
        case 4:
            text_color(11);
            cout<<"\t\t\t\t\t<=====PESQUISA POR EDITORA=====>\n\n\n"<<endl;
            text_color(15);
            cin.ignore();
            cout<<"Insira o nome da Editora que deseja pesquisar: ";
            getline(cin,aux_pesquisa);
            cout<<endl;
            pesquisa_nome_editora(obras_db,tam_obras,aux_pesquisa);
            break;
        case 5:
            text_color(11);
            cout<<"\t\t\t\t\t<=====PESQUISA POR DISPONIBILIDADE=====>\n\n\n"<<endl;
            text_color(15);
            cout<<"[1] Dispon�veis\n"<<endl;
            cout<<"[2] Indispon�veis\n"<<endl;
            cout<<"[0] SAIR\n"<<endl;

            verificador(escolha,"Insira uma das op��es:");
            switch(escolha){//PESQUISA POR DISPONIBILIDADE
            case 1:
                pesquisa_disponibilidade(obras_db,tam_obras,true);
                break;
            case 2:
                pesquisa_disponibilidade(obras_db,tam_obras,false);
                break;
            case 0:
                break;
            default:
            cout<<"Op��o inv�lida!!\n"<<endl;
            }// PESQUISA POR DISPONIBILIDADE
            break;
        case 0:
            break;
        default:
            cout<<"Op��o inv�lida!!\n"<<endl;
        }//PESQUISAS
        break;
    case 3:
        text_color(11);
        cout<<"\t\t\t\t\t<=====LISTAGENS=====>\n\n\n"<<endl;//d�cimo menu
        text_color(15);
        cout<<"[1] Listagem Obras\n"<<endl;
        cout<<"[2] Listagem Autores\n"<<endl;
        cout<<"[3] Listagem Usu�rios\n"<<endl;
        cout<<"[4] Listagem Editoras\n"<<endl;
        cout<<"[5] Listagem Tipos\n"<<endl;
        cout<<"[6] Listagem Atrasados\n"<<endl;
        cout<<"[7] Listagem Assuntos \n"<<endl;
        cout<<"[0] SAIR\n"<<endl;

        verificador(escolha,"Insira uma das op��es:");
        if(escolha==1||escolha==5||escolha==6)escolha=verificador_cadastro_obras(obras_db,tam_obras,escolha);
        if(escolha==2)escolha=verificador_cadastro_autores(autores_db,tam_autor,escolha);
        if(escolha==3)escolha=verificador_cadastro_usuarios(usuarios_db,tam_usuarios,escolha);
        if(escolha==4)escolha=verificador_cadastro_editoras(editoras_db,tam_editora,escolha);
        switch(escolha){//LISTAGENS
        case 1:ler_cadastro_obras(obras_db, tam_obras);
            break;
        case 2:ler_cadastro_autores(autores_db, tam_autor);
            break;
        case 3:ler_cadastro_usuarios(usuarios_db, tam_usuarios);
            break;
        case 4:ler_cadastro_editoras(editoras_db, tam_editora);
            break;
        case 5:ler_cadastro_tipos(obras_db,tam_obras);
            break;
        case 6:pesquisa_atrasados(obras_db, tam_obras);
            break;
        case 7:ler_cadastro_assuntos(obras_db,tam_obras);
            break;
        case 0:
            break;
        default:
        cout<<"Op��o inv�lida\n!!"<<endl;
        }//LISTAGENS
        break;
    case 4:
        sistema_devolucao_livro(obras_db, tam_obras, usuarios_db);
        break;
    case 0:
        piscar_colorido("Obrigado por usar o nosso programa!!!");
        return 0;
        break;
    default:
        cout<<"Op��o inv�lida!!!\n"<<endl;
    }//MENU PRINCIPAL

}while(true);

  return 0;
}
