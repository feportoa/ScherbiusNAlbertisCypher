#include <ncurses.h>
#include <iostream>

int main() {
    initscr(); // Inicializa a tela do ncurses
    cbreak(); // Desabilita o buffer de linha (processa as teclas imediatamente)
    noecho(); // Desabilita a exibição dos caracteres digitados na tela
    keypad(stdscr, TRUE); // Habilita a captura de teclas especiais (setas, F1, F2, etc.)

    printw("Digite qualquer coisa (pressione 'q' para sair):\n");

    while (true) {
        int ch = getch(); // Captura o próximo caractere digitado

        if (ch == 'q' || ch == 'Q')
            break; // Sai do loop se 'q' ou 'Q' for digitado
            
        clear();

        printw("Você digitou: %c\n", ch);
    }

    endwin(); // Encerra a janela do ncurses

    return 0;
}
