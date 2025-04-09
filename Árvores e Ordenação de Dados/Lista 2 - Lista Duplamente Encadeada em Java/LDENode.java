class LDENode {
    private Tarefa tarefa;
    private LDENode prox;
    private LDENode ant;

    public LDENode(Tarefa tarefa) {
        this.tarefa = tarefa;
    }

    public Tarefa getTarefa() {
        return tarefa;
    }

    public void setTarefa(Tarefa tarefa) {
        this.tarefa = tarefa;
    }

    public LDENode getProx() {
        return prox;
    }

    public void setProx(LDENode next) {
        this.prox = next;
    }

    public LDENode getAnt() {
        return ant;
    }

    public void setAnt(LDENode prev) {
        this.ant = prev;
    }
}
