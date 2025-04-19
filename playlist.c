#include <stdio.h>
#include <string.h>
#include "playlist.h"
#include <stdlib.h>

Playlist* criar_playlist(){
    Playlist* playlist = (Playlist*)malloc(sizeof(playlist));
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

int remover_musica(Playlist* playlist, const char* titulo){
    if (playlist == NULL) return 0;
    
    Musica* MusicaAdeletar; 
    MusicaAdeletar = buscar_musica(playlist, titulo);
    if (MusicaAdeletar == NULL) return 0;
    
    if (MusicaAdeletar->proxima == MusicaAdeletar) {
        free(MusicaAdeletar);
        playlist->atual = NULL;
        playlist->qtdMusicas = 0;
        return 1;
    }

    Musica* anterior = playlist->atual;
    while (anterior->proxima != MusicaAdeletar) {
        anterior = anterior->proxima;
    }
    if (playlist->atual == MusicaAdeletar) {
        playlist->atual = MusicaAdeletar->proxima;
    }

    free(MusicaAdeletar);
    MusicaAdeletar = NULL;
    playlist->qtdMusicas--;
    playlist->tamanho--;
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
