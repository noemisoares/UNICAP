class Tarefa {
    private int prioridade;
    private String descricao;

    public Tarefa(String descricao, int prioridade) {
        this.prioridade = prioridade;
        this.descricao = descricao;
    }

    public int getPrioridade() {
        return prioridade;
    }

    public void setPrioridade(int prioridade) {
        this.prioridade = prioridade;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String toString() {
        return "Tarefa - " +
                "descricao:'" + descricao + '\'' +
                ", prioridade:" + prioridade;
    }
}
