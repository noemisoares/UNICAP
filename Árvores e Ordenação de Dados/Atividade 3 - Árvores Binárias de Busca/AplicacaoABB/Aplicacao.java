package AplicacaoABB;
import java.util.Scanner;
import Procedimentos.Cadastro;

public class Aplicacao {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            Cadastro cadastro = new Cadastro();

            while (true) {
                System.out.println("\nMenu:");
                System.out.println("1. Cadastrar Produto");
                System.out.println("2. Exibir Produtos");
                System.out.println("3. Alterar Preço");
                System.out.println("4. Alterar Quantidade em Estoque");
                System.out.println("5. Exibir Produto");
                System.out.println("6. Remover Produto");
                System.out.println("0. Sair");
                System.out.print("Escolha uma opção: ");
                int opcao = scanner.nextInt();
                scanner.nextLine();

                switch (opcao) {
                    case 1:
                        cadastro.cadastrarProduto();
                        break;
                    case 2:
                        cadastro.exibirProdutos();
                        break;
                    case 3:
                        cadastro.alterarPreco();
                        break;
                    case 4:
                        cadastro.alterarQuantidade();
                        break;
                    case 5:
                        cadastro.exibirProduto();
                        break;
                    case 6:
                        cadastro.removerProduto();
                        break;
                    case 0:
                        System.out.println("Encerrando o programa...");
                        return;
                    default:
                        System.out.println("Opção inválida.");
                }
            }
        }
    }
}