#include <stdio.h>
#include <string.h>
#include "playlist.h"
#include <stdlib.h>
#include <windows.h>

Playlist* criar_playlist(){
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->atual = NULL;
    return playlist;
}

Musica* buscar_musica(Playlist* playlist, const char* titulo){
   
    if (playlist == NULL) return NULL;
    
    Musica* atual = playlist->atual;

    for (int z = 0; z <= playlist->qtdMusicas; z++){
        if (strcmp(atual->titulo, titulo) == 0){
            printf("Música encontrada: %s\n", atual->titulo);
            return atual;
        }
        atual = atual->proxima;
    }
}

void adicionar_musica(Playlist* playlist, const char* titulo, const char* artista, int duracao){
    Musica* novo = (Musica*)malloc(sizeof(Musica));
    strcpy(novo->titulo, titulo);
    strcpy(novo->artista, artista);
    novo->duracao = duracao;

    if (playlist->atual == NULL) {
        novo->proxima = novo;
        playlist->atual = novo;
    } else {
        novo->proxima = playlist->atual->proxima;
        playlist->atual->proxima = novo;
        playlist->atual = novo;
    }

    playlist->qtdMusicas = playlist->qtdMusicas + 1;
}

int remover_musica(Playlist* playlist, const char* titulo) {
    if (playlist == NULL || playlist->atual == NULL) return 0;

    Musica *atual = playlist->atual->proxima;
    Musica *anterior = playlist->atual;
    int encontrou = 0;

    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            encontrou = 1;
            break;
        }
        anterior = atual;
        atual = atual->proxima;
    } while (atual != playlist->atual->proxima);

    if (!encontrou) return 0;

    if (atual == anterior) { 
        playlist->atual = NULL;
    } else {
        anterior->proxima = atual->proxima;
        if (atual == playlist->atual) {
            playlist->atual = anterior;
        }
    }

    free(atual);
    playlist->qtdMusicas--;
    return 1;
}

void listar_musicas(Playlist* playlist) {
    if (playlist->atual == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Musica* inicio = playlist->atual->proxima;
    Musica* atual = inicio;
    do {
        printf("Artista: %s| Musica: %s | Duracao: %d\n", atual->artista, atual->titulo, atual->duracao);
        atual = atual->proxima;
    } while (atual != inicio);
    
    printf("\n");
}

void liberar_playlist(Playlist* playlist){
    if (playlist->atual == NULL) {
        free(playlist);
        return;
    }
    Musica* inicio = playlist->atual->proxima;
    Musica* atual = inicio;
    Musica* temp;
    do {
        temp = atual;
        atual = atual->proxima;
        free(temp);
    } while (atual != inicio);
    free(playlist);
}

void exibir_musica_atual(Playlist* playlist){
    if (playlist->atual == NULL) {
        printf("Lista vazia\n");
        return;
    }  
    
    printf("\n  Musica: %s | Artista: %s | Duracao: %d \n", playlist->atual->titulo, playlist->atual->artista, playlist->atual->duracao);
    Sleep(playlist->atual->duracao * 100);
    playlist->atual = playlist->atual->proxima;
}