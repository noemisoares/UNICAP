package Aplicacao;
import java.util.Scanner;

import REDBLACK.RedBlack;

public class App {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
       RedBlack<Integer> numeros = new RedBlack<Integer>();
        int escolha = 0;
        do{
            System.out.println("--- ÁRVORE RED-BLACK ---");
            System.out.println("1 - Inserir ");
            System.out.println("2 - Por Nível ");
            System.out.println("3 - Em Ordem ");
            System.out.println("4 - Remover ");
            System.out.println("0 - Sair ");
            System.out.println("Escolha: ");
            escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Digite um número: ");
                    int inserirNum = scanner.nextInt();
                    numeros.insert(inserirNum);
                    break;
                case 2:
                    System.out.println("Passeio Por Nível: ");
                    numeros.porNivel(); 
                    break;
                case 3:
                    System.out.println("Passeio Em Ordem: ");
                    numeros.emOrdem();                  
                    break;
                case 4:
                    System.out.println("Digite um número: ");
                    int removerNum = scanner.nextInt();
                    numeros.remove(removerNum);                 
                    break;
                case 0:
                    System.out.println("Saindo do programa... ");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente... ");
                    break;
            }
        } while(escolha != 0);
        scanner.close();
    }
}