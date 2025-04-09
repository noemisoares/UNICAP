import java.util.Scanner;

class ControleDeTarefas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        LDEDeTarefas lista = new LDEDeTarefas();
        int esc;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Inserir nova tarefa");
            System.out.println("2. Buscar tarefa e contar tarefas anteriores");
            System.out.println("3. Executar tarefa de maior prioridade");
            System.out.println("4. Cancelar tarefa");
            System.out.println("5. Exibir tarefas por prioridade");
            System.out.println("6. Exibir todas as tarefas");
            System.out.println("7. Alterar prioridade de uma tarefa");
            System.out.println("8. Sair");
            System.out.println("Escolha: ");
            esc = scanner.nextInt();
            scanner.nextLine();

            switch (esc) {
                case 1:
                    System.out.print("Descrição da tarefa: ");
                    String descricao = scanner.nextLine();
                    System.out.print("Prioridade da tarefa (1-10): ");
                    int prioridade = scanner.nextInt();
                    scanner.nextLine();
                    if (prioridade < 1 || prioridade > 10) {
                        System.out.println("Prioridade inválida.");
                    } else {
                        lista.inserirTarefa(new Tarefa(descricao, prioridade));
                    }
                    break;
                case 2:
                    System.out.print("Descrição da tarefa: ");
                    descricao = scanner.nextLine();
                    lista.tarefasAntes(descricao);
                    break;
                case 3:
                    lista.executarTarefa();
                    break;
                case 4:
                    System.out.print("Descrição da tarefa: ");
                    descricao = scanner.nextLine();
                    lista.cancelarTarefa(descricao);
                    break;
                case 5:
                    System.out.print("Prioridade (1-10): ");
                    prioridade = scanner.nextInt();
                    scanner.nextLine();
                    lista.exibirTarefasPrioridade(prioridade);
                    break;
                case 6:
                    lista.exibirTodasTarefas();
                    break;
                case 7:
                    System.out.print("Descrição da tarefa: ");
                    descricao = scanner.nextLine();
                    System.out.print("Nova prioridade (1-10): ");
                    prioridade = scanner.nextInt();
                    scanner.nextLine();
                    lista.alterarPrioridade(descricao, prioridade);
                    break;
                case 8:
                    System.out.println("Saindo...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Opção inválida.");
            }
        } while (esc != 0);
        scanner.close();
    }
}