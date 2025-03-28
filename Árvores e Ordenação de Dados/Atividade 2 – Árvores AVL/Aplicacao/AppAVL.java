package Aplicacao;
import java.util.Scanner;
import AVL.AVL;

public class AppAVL {  
    public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       AVL<Integer> numeros = new AVL<>();
       int escolha = 0;
       
       do{
        System.out.println("---ÁRVORE AVL---");
        System.out.println("1 - Inserir");
        System.out.println("2 - Em Ordem");
        System.out.println("3 - Passeio Por Nível");
        System.out.println("Digite: ");
        escolha = scanner.nextInt();

        switch (escolha) {
            case 1:
                System.out.println("Digite um número: ");
                int numero = scanner.nextInt();
                numeros.insert(numero);
                break;
            case 2:
                System.out.println("Em Ordem: ");
                numeros.emOrdem();
                break;
            case 3:
                System.out.println("Passeio Por Nível: ");
                numeros.passeioPorNivel();
                break;
            default:
                System.out.println("Opção invalida! Tente novamente...");
                break;
        }
       } while(escolha != 0);
       scanner.close();
    }
}