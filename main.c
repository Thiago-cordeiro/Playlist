#include <stdio.h>
#include <string.h>
#include "playlist.h"

int main() {

    int resposta;

    Playlist* playlist = criar_playlist();

    adicionar_musica(playlist, "goosebumps", "Travis Scott", 4);
    adicionar_musica(playlist, "FEIN", "Travis Scott", 4);
    adicionar_musica(playlist, "CALMA CALABRESO", "CALABRESO", 5);
    adicionar_musica(playlist, "CALMA VIDA", "GRELO", 3);


    buscar_musica(playlist, "FEIN");
    
    remover_musica(playlist, "FEIN");

    listar_musicas(playlist);

    liberar_playlist(playlist);
    return 0;
}
