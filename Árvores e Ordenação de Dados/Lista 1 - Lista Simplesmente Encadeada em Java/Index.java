import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LSEAluno lista = new LSEAluno();
        int esc;

        do {
            System.out.println("\nMenu de Opções:");
            System.out.println("1 - Inserir aluno no início");
            System.out.println("2 - Inserir aluno no final");
            System.out.println("3 - Exibir todos os alunos");
            System.out.println("4 - Exibir dados de um aluno");
            System.out.println("5 - Alterar dados de um aluno");
            System.out.println("6 - Remover o primeiro aluno");
            System.out.println("7 - Remover o último aluno");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            esc = scanner.nextInt();
            scanner.nextLine();

            switch (esc) {
                case 1:
                    System.out.print("Matrícula: ");
                    String matriculaI = scanner.nextLine();
                    System.out.print("Nome: ");
                    String nomeI = scanner.nextLine();
                    System.out.print("Média: ");
                    double mediaI = scanner.nextDouble();
                    System.out.print("Faltas: ");
                    int faltasI = scanner.nextInt();
                    lista.inserirInicio(new Aluno(matriculaI, nomeI, mediaI, faltasI));
                    break;
                case 2:
                    System.out.print("Matrícula: ");
                    String matriculaF = scanner.nextLine();
                    System.out.print("Nome: ");
                    String nomeF = scanner.nextLine();
                    System.out.print("Média: ");
                    double mediaF = scanner.nextDouble();
                    System.out.print("Faltas: ");
                    int faltasF = scanner.nextInt();
                    lista.inserirFim(new Aluno(matriculaF, nomeF, mediaF, faltasF));
                    break;
                case 3:
                    lista.exibirTodos();
                    break;
                case 4:
                    System.out.print("Matrícula do aluno: ");
                    String matriculaExibir = scanner.nextLine();
                    lista.exibirAluno(matriculaExibir);
                    break;
                case 5:
                    System.out.print("Matrícula do aluno: ");
                    String matriculaNova = scanner.nextLine();
                    System.out.print("Nova média: ");
                    double mediaNova = scanner.nextDouble();
                    System.out.print("Novas faltas: ");
                    int faltaNova = scanner.nextInt();
                    lista.alterarAluno(matriculaNova, mediaNova, faltaNova);
                    break;
                case 6:
                    lista.removerInicio();
                    break;
                case 7:
                    lista.removerFim();
                    break;
                case 0:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente de novo.");
            }
        } while (esc != 0);
        scanner.close();
    }
}
