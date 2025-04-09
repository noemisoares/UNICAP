class LSEAluno {
    private LSENode inicio;
    private LSENode fim;
    private int qtd;

    public LSEAluno() {
        this.inicio = null;
        this.fim = null;
        this.qtd = 0;
    }

    public LSENode buscarAluno(Aluno aluno) {
        LSENode atual = inicio;
        while (atual != null) {
            if (atual.getInfo().compareTo(aluno) == 0) {
                return atual;
            }
            atual = atual.getProx();
        }
        return null;
    }

    public void inserirInicio(Aluno aluno) {
        if (buscarAluno(aluno) != null) {
            System.out.println("Aluno está na lista.");
            return;
        }
        LSENode novo = new LSENode(aluno);
        if (inicio == null) {
            inicio = fim = novo;
        } else {
            novo.setProx(inicio);
            inicio = novo;
        }
        qtd++;
        System.out.println("Aluno inserido no início da lista.");
    }

    public void inserirFim(Aluno aluno) {
        if (buscarAluno(aluno) != null) {
            System.out.println("Aluno está na lista.");
            return;
        }
        LSENode novo = new LSENode(aluno);
        if (fim == null) {
            inicio = fim = novo;
        } else {
            fim.setProx(novo);
            fim = novo;
        }
        qtd++;
        System.out.println("Aluno inserido no final da lista.");
    }

    public void exibirTodos() {
        if (inicio == null) {
            System.out.println("Lista vazia.");
            return;
        }
        LSENode atual = inicio;
        while (atual != null) {
            System.out.println(atual.getInfo());
            atual = atual.getProx();
        }
    }

    public void exibirAluno(String matricula) {
        LSENode atual = inicio;
        while (atual != null) {
            if (atual.getInfo().getMatricula().equals(matricula)) {
                System.out.println(atual.getInfo());
                return;
            }
            atual = atual.getProx();
        }
        System.out.println("Aluno não encontrado.");
    }

    public void alterarAluno(String matricula, double novaMedia, int novasFaltas) {
        LSENode atual = inicio;
        while (atual != null) {
            if (atual.getInfo().getMatricula().equals(matricula)) {
                atual.getInfo().setMedia(novaMedia);
                atual.getInfo().setFaltas(novasFaltas);
                System.out.println("Dados alterados com sucesso.");
                return;
            }
            atual = atual.getProx();
        }
        System.out.println("Aluno não encontrado.");
    }

    public void removerInicio() {
        if (inicio == null) {
            System.out.println("Lista vazia.");
            return;
        }
        inicio = inicio.getProx();
        if (inicio == null) {
            fim = null;
        }
        qtd--;
        System.out.println("Primeiro aluno removido.");
    }

    public void removerFim() {
        if (inicio == null) {
            System.out.println("Lista vazia.");
            return;
        }
        if (inicio == fim) {
            inicio = fim = null;
        } else {
            LSENode atual = inicio;
            while (atual.getProx() != fim) {
                atual = atual.getProx();
            }
            atual.setProx(null);
            fim = atual;
        }
        qtd--;
        System.out.println("Último aluno removido.");
    }
}
