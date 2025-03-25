import java.util.ArrayList;
import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        ArrayList<Livro> livros = new ArrayList<Livro>();
        int opcao = 0;
        
        do {
            System.out.println("BIBLIOTECA");
            System.out.println("1 - Cadastrar Novo Livro ");
            System.out.println("2 - Ver Catalogo de Livros ");
            System.out.println("3 - Empréstimo e Devolutivas ");
            System.out.println("4 - Verificar Disponibilidade do Livro ");
            System.out.println("Escolha: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    Livro livro = new Livro(null, null, true);
                    System.out.println("Digite o Titulo do Livro: ");
                    livro.setTitulo(scanner.nextLine());
                    System.out.println("Digite o Autor(a) do Livro: ");
                    livro.setAutor(scanner.nextLine());
                    livro.setDisponivel(true);
                    livros.add(livro);
                    break;
                case 2:
                    System.out.println("Catalogo de Livros: ");
                    for (Livro l : livros) {
                        System.out.println(l);
                    }
                    break;
                case 3:
                    System.out.println("Digite o Titulo do Livro: ");
                    String titulo = scanner.nextLine();
                    boolean encontrado = false;
                    for (Livro l : livros) {
                        if (l.compareTo(new Livro(titulo, "", true)) == 0) {
                            encontrado = true;
                            System.out.println("Deseja adquirir(1) ou devolver(2) o livro?");
                            int escolha = scanner.nextInt();
                            scanner.nextLine();
                            if (escolha == 1 && l.isDisponivel() == true) {
                                l.setDisponivel(false);
                                System.out.println("Livro adquirido com sucesso.");
                            } else if (escolha == 1 && l.isDisponivel() == false) {
                                System.out.println("Livro encontrado está indisponivel para reserva! ");
                            } 
                            else if (escolha == 2 && l.isDisponivel() == false) {
                                l.setDisponivel(true);
                                System.out.println("Livro devolvido com sucesso.");
                            } else if (escolha == 2 && l.isDisponivel() == true) {
                                System.out.println("Livro encontrado já se encontra disponivel no acervo.");
                            } 
                            else {
                                System.out.println("Erro: Opção inválida.");
                            }
                            break;
                        }
                    }
                    if (!encontrado) {
                        System.out.println("Livro não encontrado.");
                    }
                    break;
                case 4:
                    System.out.println("Livros Disponiveis: ");
                    for (Livro l : livros) {
                        if(l.isDisponivel() == true){
                            System.out.println(l);    
                        }
                    }
                    System.out.println("Livros Indisponiveis: ");
                    for (Livro l : livros) {
                        if(l.isDisponivel() == false){
                            System.out.println(l);  
                        }
                    }
                    break;
                case 0:
                    System.out.println("Adeus. Volte sempre!");
                    break;
                default:
                    System.out.println("Opcao Invalida! Tente Novamente... ");
                    break;
            }
        } while(opcao != 0);
        scanner.close();
    }
}