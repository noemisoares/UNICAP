class LDEDeTarefas {
    private LDENode inicio;
    private LDENode fim;

    public LDENode buscarDescricao(String descricao) {
        LDENode atual = inicio;
        while (atual != null) {
            if (atual.getTarefa().getDescricao().equals(descricao)) {
                return atual;
            }
            atual = atual.getProx();
        }
        return null;
    }

    public boolean inserirTarefa(Tarefa tarefa) {
        if (buscarDescricao(tarefa.getDescricao()) != null) {
            System.out.println("Já existe uma tarefa com essa descrição.");
            return false;
        }

        LDENode novo = new LDENode(tarefa);
        if (inicio == null) {
            inicio = fim = novo;
        } else {
            LDENode atual = inicio;
            while (atual != null && atual.getTarefa().getPrioridade() >= tarefa.getPrioridade()) {
                atual = atual.getProx();
            }

            if (atual == inicio) {
                novo.setProx(inicio);
                inicio.setAnt(novo);
                inicio = novo;
            } else if (atual == null) {
                fim.setProx(novo);
                novo.setAnt(fim);
                fim = novo;
            } else {
                LDENode anterior = atual.getAnt();
                anterior.setProx(novo);
                novo.setAnt(anterior);
                novo.setProx(atual);
                atual.setAnt(novo);
            }
        }
        return true;
    }

    public void tarefasAntes(String descricao) {
        LDENode atual = buscarDescricao(descricao);
        if (atual == null) {
            System.out.println("Tarefa não encontrada.");
            return;
        }

        int contador = 0;
        LDENode aux = inicio;
        while (aux != atual) {
            contador++;
            aux = aux.getProx();
        }
        System.out.println("Existem " + contador + " tarefas antes da tarefa: " + descricao);
    }

    public void executarTarefa() {
        if (inicio == null) {
            System.out.println("Nenhuma tarefa para executar.");
            return;
        }

        System.out.println("Executando a tarefa: " + inicio.getTarefa());
        inicio = inicio.getProx();
        if (inicio != null) {
            inicio.setAnt(null);
        } else {
            fim = null;
        }
    }

    public void cancelarTarefa(String descricao) {
        LDENode atual = buscarDescricao(descricao);
        if (atual == null) {
            System.out.println("Tarefa não encontrada.");
            return;
        }

        if (atual == inicio) { 
            inicio = inicio.getProx();
            if (inicio != null) {
                inicio.setAnt(null);
            } else {
                fim = null;
            }
        } else if (atual == fim) {
            fim = fim.getAnt();
            fim.setProx(null);
        } else {
            LDENode anterior = atual.getAnt();
            LDENode proximo = atual.getProx();
            anterior.setProx(proximo);
            proximo.setAnt(anterior);
        }
        System.out.println("Tarefa cancelada: " + descricao);
    }

    public void exibirTarefasPrioridade(int prioridade) {
        if (prioridade < 1 || prioridade > 10) {
            System.out.println("Prioridade inválida. Deve estar entre 1 e 10.");
            return;
        }

        LDENode atual = inicio;
        int contador = 0;
        while (atual != null) {
            if (atual.getTarefa().getPrioridade() == prioridade) {
                System.out.println(atual.getTarefa());
                contador++;
            }
            atual = atual.getProx();
        }

        System.out.println("Total de tarefas com prioridade " + prioridade + ": " + contador);
    }

    public void exibirTodasTarefas() {
        LDENode atual = inicio;
        if (atual == null) {
            System.out.println("Nenhuma tarefa cadastrada.");
            return;
        }

        while (atual != null) {
            System.out.println(atual.getTarefa());
            atual = atual.getProx();
        }
    }

    public void alterarPrioridade(String descricao, int novaPrioridade) {
        if (novaPrioridade < 1 || novaPrioridade > 10) {
            System.out.println("Prioridade inválida. Deve estar entre 1 e 10.");
            return;
        }

        LDENode atual = buscarDescricao(descricao);
        if (atual == null) {
            System.out.println("Tarefa não encontrada.");
            return;
        }

        Tarefa tarefa = atual.getTarefa();
        cancelarTarefa(descricao);
        tarefa.setPrioridade(novaPrioridade);
        inserirTarefa(tarefa);
    }
}