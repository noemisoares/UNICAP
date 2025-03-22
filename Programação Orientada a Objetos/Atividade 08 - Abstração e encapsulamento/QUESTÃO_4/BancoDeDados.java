public class BancoDeDados {
    private int[] dados;
    private int qtdDados;

    public BancoDeDados(int capacidade) {
        this.dados = new int[capacidade];
        this.qtdDados = 0;
    }

    int[] getDados() {
        return dados;
    }

    void setDados(int[] dados) {
        this.dados = dados;
    }

    int getQtdDados() {
        return qtdDados;
    }

    void setQtdDados(int qtdDados) {
        this.qtdDados = qtdDados;
    }

    void adicionar(int dado){
        this.dados[qtdDados] = dado;
        this.qtdDados++;
        System.out.println("Dado foi adicionado na lista.");
    }

    void remover(int dado) {
        for (int i = 0; i < this.qtdDados; i++) {
            if (this.dados[i] == dado) {
                for (int j = i; j < this.qtdDados - 1; j++) {
                    this.dados[j] = this.dados[j + 1];
                }
                this.qtdDados--;
                System.out.println("Dado foi removido da lista.");
                return;
            }
        }
        System.out.println("Dado não encontrado.");
    }

    void atualizar(int dado, int atualizar) {
        for (int i = 0; i < this.qtdDados; i++) {
            if (this.dados[i] == dado) {
                this.dados[i] = atualizar;
                System.out.println("Dado foi alterado da lista.");
                return;
            }
        }
        System.out.println("Dado não encontrado.");
    }

    void listar(){
        for (int i = 0; i < this.qtdDados; i++) {
            System.out.println(this.dados[i]);
        }
    }
}