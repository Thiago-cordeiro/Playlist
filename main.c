#include <stdio.h>
#include <string.h>
#include "playlist.h"

int main() {
    Playlist* playlist = criar_playlist();
    int executando = 1;
    char comando[20];


        // Adicionando músicas de teste
        adicionar_musica(playlist, "Blinding Lights", "The Weeknd", 10);
        adicionar_musica(playlist, "Sicko Mode", "Travis Scott", 8);
        adicionar_musica(playlist, "Bad Guy", "Billie Eilish", 12);
        adicionar_musica(playlist, "Levitating", "Dua Lipa", 9);
        adicionar_musica(playlist, "Industry Baby", "Lil Nas X", 7);
        adicionar_musica(playlist, "Peaches", "Justin Bieber", 6);
        adicionar_musica(playlist, "Shape of You", "Ed Sheeran", 10);
        adicionar_musica(playlist, "Montero", "Lil Nas X", 5);


    printf("=== Sistema Playlist! ===\n");

    while (executando) {
        // Exibir a música atual
        exibir_musica_atual(playlist);

        printf("\n(Digite 'm' para abrir o menu ou ENTER para continuar ouvindo)\n");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0; // remove o \n

        if (strcmp(comando, "m") == 0) {
            int func;

            printf("\n========== MENU PLAYLIST ==========\n");
            printf("0 - Encerrar\n");
            printf("1 - Listar músicas\n");
            printf("2 - Buscar música\n");
            printf("3 - Adicionar música\n");
            printf("4 - Remover música\n");
            printf("===================================\n");

            printf("Escolha uma opção: ");
            scanf("%d", &func);
            getchar(); // consome o \n

            if (func == 0) {
                executando = 0;
                printf("Encerrando...\n");
            } 
            else if (func == 1) {
                listar_musicas(playlist);
            } 
            else if (func == 2) {
                char titulo[100];
                printf("Digite o titulo da musica que deseja buscar: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                buscar_musica(playlist, titulo);
            } 
            else if (func == 3) {
                char titulo[100], artista[100];
                int duracao;

                printf("Titulo da musica: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0;

                printf("Artista: ");
                fgets(artista, sizeof(artista), stdin);
                artista[strcspn(artista, "\n")] = 0;

                printf("Duracao (em segundos): ");
                scanf("%d", &duracao);
                getchar();

                adicionar_musica(playlist, titulo, artista, duracao);
            } 
            else if (func == 4) {
                char titulo[100];
                printf("Digite o título da musica a ser removida: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0;

                if (remover_musica(playlist, titulo)) {
                    printf("Musica removida com sucesso!\n");
                } else {
                    printf("Musica não encontrada.\n");
                }
            } 
            else {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }

        printf("\n\n");
    }

    liberar_playlist(playlist);
    return 0;
}
