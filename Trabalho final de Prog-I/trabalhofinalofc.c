#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALUNO 50

typedef struct Aluno{
    char nome[30];
    int matricula;
    float nota1,nota2,media;
    char situacao[50];
}Aluno;
Aluno alunos[ALUNO]; //renomeando a struct com letra maiuscula, porque ela é um tipo e não variavel
int i = 0;

float media(float n1,float n2){
	float soma=0;
		soma = n1+n2;
	return soma/2;
}

char *verificar(float media){
        char *sit;

        if(media >=7){
            sit="Aprovado";
        }else if((media >=4) && (media <7)){
            sit = "Prova Final";
        }else{
            sit ="Reprovado Por Nota";
        }
        return sit;

    }

void cadastroAluno(){
    FILE *file;
    file = fopen("alunos.txt","a");

    printf("\n----------------Cadastro de aluno(a)----------------\n\n");

        printf("Informe a matricula: \n");
        scanf("%d",&alunos[i].matricula);

        printf("Informe o nome: \n");
        scanf("\n %[^\n]",alunos[i].nome);//%s le um vetor de char

        alunos[i].nota1 = -1;
        alunos[i].nota2 = -1;
        alunos[i].media = -1;
        strcpy(alunos[i].situacao,"Reprovado");

        fprintf(file,"%d\n",alunos[i].matricula);
        fprintf(file,"%s\n",alunos[i].nome);
        fprintf(file,"%f\n",alunos[i].nota1);
        fprintf(file,"%f\n",alunos[i].nota2);
        fprintf(file,"%f\n",alunos[i].media);
        fprintf(file,"%s\n",alunos[i].situacao);

        fclose(file);
        i++;

        printf("Aluno(a) cadastrado!\n");
        system("PAUSE");
}

void cadastrarNota(){
    FILE *file;
    file = fopen("alunos.txt","w");

    int matricula;
    bool existe = false;

    printf("Informe a matricula: \n");
    scanf("%d",&matricula);

    for(int j=0;j<i;j++){
            if(matricula == alunos[j].matricula){
                printf("Nome: %s\n",alunos[j].nome);

                printf("Informe a primeira nota: \n");
                scanf("%f",&alunos[j].nota1);

                printf("Informe a segunda nota: \n");
                scanf("%f",&alunos[j].nota2);

                alunos[j].media = media(alunos[j].nota1,alunos[j].nota2);

                strcpy(alunos[j].situacao,verificar(alunos[j].media));

                existe = true;

                break;
            }

    }
    if(existe){
        for(int j=0;j<i;j++){
            fprintf(file,"%d\n",alunos[j].matricula);
            fprintf(file,"%s\n",alunos[j].nome);
            fprintf(file,"%f\n",alunos[j].nota1);
            fprintf(file,"%f\n",alunos[j].nota2);
            fprintf(file,"%f\n",alunos[j].media);
            fprintf(file,"%s\n",alunos[j].situacao);
        }

    printf("Notas cadastradas!\n");

    }else{
        printf("Matricula nao existe!\n");
    }

    system("PAUSE");

    fclose(file);
}

void alterarDados(){
        FILE *file;
        file = fopen("alunos.txt","w");

        int matricula;
        bool existe = false;

        printf("Informe a matricula: \n");
        scanf("%d",&matricula);

        for(int j=0;j<i;j++){
                if(matricula == alunos[j].matricula){
                    printf("Nome: %s\n",alunos[j].nome);
                    printf("Nota 1.......: %f\n",alunos[j].nota1);
                    printf("Nota 2.......: %f\n",alunos[j].nota2);

                    printf("Informe o novo nome: \n");
                    scanf("%[^\n]",alunos[j].nome);
                    printf("Informe a nova primeira nota: \n");
                    scanf("%f",&alunos[j].nota1);
                    printf("Informe a nova segunda nota: \n");
                    scanf("%f",&alunos[j].nota2);

                    alunos[j].media = media(alunos[j].nota1,alunos[j].nota2);

                    strcpy(alunos[j].situacao,verificar(alunos[j].media));

                    existe = true;

                    break;
                }

        }
        if(existe){
            for(int j=0;j<i;j++){
                fprintf(file,"%d\n",alunos[j].matricula);
                fprintf(file,"%s\n",alunos[j].nome);
                fprintf(file,"%f\n",alunos[j].nota1);
                fprintf(file,"%f\n",alunos[j].nota2);
                fprintf(file,"%f\n",alunos[j].media);
                fprintf(file,"%s\n",alunos[j].situacao);
            }

        printf("Dados alterados com sucesso!\n");

        }else{
            printf("Matricula nao existe!\n");
        }

        system("PAUSE");

        fclose(file);
    }

void excluir(){
    FILE *file;
    file = fopen("alunos.txt","w");

    int matricula;
    bool existe = false;

    printf("Informe a matricula: \n");
    scanf("%d",&matricula);

    for(int j=0;j<i;j++){
        if(matricula != alunos[j].matricula){
            fprintf(file,"%d\n",alunos[j].matricula);
            fprintf(file,"%s\n",alunos[j].nome);
            fprintf(file,"%f\n",alunos[j].nota1);
            fprintf(file,"%f\n",alunos[j].nota2);
            fprintf(file,"%f\n",alunos[j].media);
            fprintf(file,"%s\n",alunos[j].situacao);
        }else{
            existe = true;
        }
    }
    fclose(file);

    if(existe){
        file = fopen("alunos.txt","r");

        i = 0;
        char matricula[40];
        char nome[40];
        char n1[40];
        char n2[40];
        char media[40];
        char situacao[40];
        while(!feof(file)) {
            Aluno a;
            if(fscanf(file,"%s\n",matricula) == EOF){
                break;
            }
            fscanf(file,"%[^\n]",nome);
            fscanf(file,"%s\n",n1);
            fscanf(file,"%s\n",n2);
            fscanf(file,"%s\n",media);
            fscanf(file,"%[^\n]",situacao);

            a.matricula = atoi(matricula);
            strcpy(a.nome,nome);
            a.nota1 = atof(n1);
            a.nota2 = atof(n2);
            a.media = atof(media);
            strcpy(a.situacao,situacao);

            alunos[i] = a;

            i++;
        }
        fclose(file);


        printf("Cadastro excluido!\n");

    }else{
        printf("Matricula nao existe!\n");
    }

    system("PAUSE");

    fclose(file);
}

void listaAprovados(){

    for(int j = 0; j<i;j++){

        if(alunos[j].media!= -1 && alunos[j].media>=7){
            printf("Matricula.......:%d \n",alunos[j].matricula);
            printf("Nome.......:%s \n",alunos[j].nome);
            printf("Nota 1.......:%f \n",alunos[j].nota1);
            printf("Nota 2.......:%f \n",alunos[j].nota2);
            printf("MEDIA.......:%f \n",alunos[j].media);

            printf("-----------------------------------------\n");
       }

    }
    system("PAUSE");
}

void listaReprovados(){
    for(int j = 0; j<i;j++){

        if(alunos[j].media!= -1 && alunos[j].media<4){
            printf("Matricula.......:%d \n",alunos[j].matricula);
            printf("Nome.......:%s \n",alunos[j].nome);
            printf("Nota 1.......:%f \n",alunos[j].nota1);
            printf("Nota 2.......:%f \n",alunos[j].nota2);
            printf("MEDIA.......:%f \n",alunos[j].media);

            printf("-----------------------------------------\n");
       }

    }
    system("PAUSE");
}

void menu(){
    int op;

    while(op!=7){
        system("cls");//limpar tela no windows
        printf("\n----------------------Menu----------------------\n\n");
        printf("1- Cadastrar aluno\n");
        printf("2- Cadastrar nota\n");
        printf("3- Alterar dados de um aluno\n");
        printf("4- Excluir dados de um aluno\n");
        printf("5- Listar Aprovados\n");
        printf("6- Listar Reprovados\n");
        printf("7- Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                cadastroAluno();
            break;
            case 2:
                cadastrarNota();
            break;
            case 3:
                alterarDados();
            break;
            case 4:
                excluir();
            break;
            case 5:
                listaAprovados();
            break;
            case 6:
                listaReprovados();
            break;
        }
    };
}

int main(){
FILE *file;
    file = fopen("alunos.txt","r");
    char matricula[40];
    char nome[40];
    char n1[40];
    char n2[40];
    char media[40];
    char situacao[40];
    while(!feof(file)) {
        Aluno a;
        if(fscanf(file,"%s\n",matricula) == EOF){
            break;
        }
        fscanf(file,"%[^\n]",nome);
        fscanf(file,"%s\n",n1);
        fscanf(file,"%s\n",n2);
        fscanf(file,"%s\n",media);
        fscanf(file,"%[^\n]",situacao);

        a.matricula = atoi(matricula);
        strcpy(a.nome,nome);
        a.nota1 = atof(n1);
        a.nota2 = atof(n2);
        a.media = atof(media);
        strcpy(a.situacao,situacao);

        alunos[i] = a;

        i++;
    }
    fclose(file);

    menu();

}
