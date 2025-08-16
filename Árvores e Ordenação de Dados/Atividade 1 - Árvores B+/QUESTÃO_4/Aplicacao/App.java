package Aplicacao;

import java.util.Scanner;

import BPlus.BtreePlus;
import Alunos.Aluno;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BtreePlus arvore = new BtreePlus();

        int escolha = 0;
        do {
            System.out.println("\n=== MENU ÁRVORE B+ ===");
            System.out.println("1 - Inserir aluno");
            System.out.println("2 - Buscar aluno por chave");
            System.out.println("3 - Exibir todos os registros (em ordem)");
            System.out.println("4 - Mostrar menor e maior chave");
            System.out.println("0 - Sair");
            System.out.print("Informe a opção desejada: ");
            escolha = scanner.nextInt();
            scanner.nextLine();

            switch (escolha) {
                case 1:
                    System.out.print("Informe a chave do aluno (ex: matrícula): ");
                    String chave = scanner.nextLine();

                    System.out.print("Informe o nome do aluno: ");
                    String nome = scanner.nextLine();

                    System.out.print("Informe a matrícula do aluno (número): ");
                    int matricula = scanner.nextInt();
                    scanner.nextLine();

                    Aluno novo = new Aluno(nome, matricula);
                    arvore.inserir(chave, novo);
                    System.out.println("Aluno inserido com sucesso!");
                    break;
                case 2:
                    System.out.print("Informe a chave que deseja buscar: ");
                    String chaveBusca = scanner.nextLine();

                    Object resultado = arvore.buscar(chaveBusca);
                    if (resultado != null) {
                        System.out.println("Aluno encontrado: " + resultado.toString());
                    } else {
                        System.out.println("Chave não encontrada.");
                    }
                    break;
                case 3:
                    System.out.println("Registros da árvore em ordem crescente:");
                    arvore.exibirEmOrdem();
                    break;
                case 4:
                    BNodePlus menor = arvore.encontrarMenor();
                    BNodePlus maior = arvore.encontrarMaior();
                    if (menor != null && maior != null) {
                        System.out.println("Menor chave: " + menor.getChaves()[0]);
                        System.out.println("Maior chave: " + maior.getChaves()[maior.getN() - 1]);
                    } else {
                        System.out.println("A árvore está vazia.");
                    }
                    break;
                case 0:
                    System.out.println("Saindo do programa...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente...");
                    break;
            }
        } while (escolha != 0);

        scanner.close();
    }
}