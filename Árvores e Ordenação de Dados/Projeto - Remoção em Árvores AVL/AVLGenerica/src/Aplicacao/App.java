package Aplicacao;
import java.util.Scanner;
import AVL.AVLTree;

public class App {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        AVLTree<Integer> numeros = new AVLTree<Integer>();
        int escolha = 0;
        do{
            System.out.println("--- ÁRVORE BINÁRIA ---");
            System.out.println("1 - Inserir ");
            System.out.println("2 - Buscar ");
            System.out.println("3 - Passeio Em Ordem ");
            System.out.println("4 - Passeio Por Nível ");
            System.out.println("5 - Remover ");
            System.out.println("0 - Sair ");
            System.out.println("Escolha: ");
            escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Digite um número: ");
                    int inserirNum = scanner.nextInt();
                    numeros.insert(inserirNum);
                    System.out.println("Valor inserido com sucesso.");
                    break;
                case 2:
                    System.out.println("Digite um número: ");
                    int buscarNum = scanner.nextInt();
                    Integer busca = numeros.find(buscarNum);
                    if (busca != null){
                        System.out.println("Valor " + busca + " encontrado na árvore!");
                    } else {
                        System.out.println("Valor não encontrado.");
                    }                    
                    break;
                case 3:
                    System.out.println("Passeio Em Ordem: ");
                    numeros.emOrdem();
                    break;
                case 4:
                    System.out.println("Passeio Por Nível: ");
                    numeros.porNivel();
                    break;
                case 5:
                    System.out.println("Digite um número: ");
                    Integer removerNum = scanner.nextInt();
                    Integer buscaRemover = numeros.find(removerNum);
                    if (buscaRemover != null){
                        numeros.remove(removerNum);
                        System.out.println("Valor removido com sucesso.");
                    } else {
                        System.out.println("Valor para remoção não foi encontrado.");
                    }   
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