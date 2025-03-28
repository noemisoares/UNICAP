package Procedimentos;
import ABBGenerica.ABB;
import Objetos.Produtos;
import java.util.Scanner;

public class Cadastro {
    private ABB<Produtos> produtos;
    Scanner scanner = new Scanner(System.in);
    
    public Cadastro() {
        this.produtos = new ABB<>();
    }

    public void cadastrarProduto() {
        System.out.println("Digite o código do produto: ");
        String codigo = scanner.nextLine();
        Produtos produtoExistente = produtos.find(new Produtos(codigo, "", "", 0.0, 0));

        if (produtoExistente != null) {
            System.out.println("Produto com esse código já existe.");
            return;
        }

        System.out.println("Digite a descrição do produto: ");
        String descricao = scanner.nextLine();

        System.out.println("Digite o fornecedor do produto: ");
        String fornecedor = scanner.nextLine();

        System.out.println("Digite o preço do produto: ");
        double preco = scanner.nextDouble();

        System.out.println("Digite a quantidade em estoque do produto: ");
        int quantidadeEstoque = scanner.nextInt();
        scanner.nextLine();

        Produtos produto = new Produtos(codigo, descricao, fornecedor, preco, quantidadeEstoque);
        produtos.insert(produto);
        System.out.println("Produto cadastrado com sucesso!");
    }

    public void exibirProdutos() {
        System.out.println("Produtos Cadastrados: ");
        produtos.emOrdem();
    }

    public void alterarPreco() {
        System.out.println("Digite o código do produto: ");
        String codigo = scanner.nextLine();
        Produtos produto = produtos.find(new Produtos(codigo, "", "", 0.0, 0));

        if (produto != null) {
            System.out.println("Digite o novo preço: ");
            produto.setPreco(scanner.nextDouble());
            System.out.println("Preço alterado com sucesso!");
        } else {
            System.out.println("Produto não encontrado.");
        }
    }

    public void alterarQuantidade() {
        System.out.println("Digite o código do produto: ");
        String codigo = scanner.nextLine();
        Produtos produto = produtos.find(new Produtos(codigo, "", "", 0.0, 0));

        if (produto != null) {
            System.out.println("Digite a nova quantidade em estoque: ");
            produto.setQtdEstoque(scanner.nextInt());
            System.out.println("Quantidade alterada com sucesso!");
        } else {
            System.out.println("Produto não encontrado.");
        }
    }

    public void exibirProduto() {
        System.out.println("Digite o código do produto: ");
        String codigo = scanner.nextLine();
        Produtos produto = produtos.find(new Produtos(codigo, "", "", 0.0, 0));

        if (produto != null) {
            System.out.println(produto);
        } else {
            System.out.println("Produto não encontrado.");
        }
    }

    public void removerProduto() {
        System.out.println("Digite o código do produto: ");
        String codigo = scanner.nextLine();
        Produtos produto = produtos.find(new Produtos(codigo, "", "", 0.0, 0));

        if (produto != null) {
            produtos.remover(produto);
            System.out.println("Produto removido com sucesso.");
        } else {
            System.out.println("Produto não encontrado.");
        }
    }
}