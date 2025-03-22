public class CarrinhoDeCompras {
    private String[] itens;
    private int qtdItens;

    public CarrinhoDeCompras(int capacidade) {
        this.itens = new String[capacidade];
        this.qtdItens = 0;
    }

    String[] getItens() {
        return itens;
    }

    void setItens(String[] itens) {
        this.itens = itens;
    }

    int getQtdItens() {
        return qtdItens;
    }

    void setQtdItens(int qtdItens) {
        this.qtdItens = qtdItens;
    }

    void adicionar(String item){
        this.itens[qtdItens] = item;
        this.qtdItens++;
        System.out.println("Item foi adicionado na lista.");
    }

    void remover(String item) {
        for (int i = 0; i < this.qtdItens; i++) {
            if (this.itens[i].equals(item)) {
                for (int j = i; j < this.qtdItens - 1; j++) {
                    this.itens[j] = this.itens[j + 1];
                }
                this.itens[this.qtdItens - 1] = null;
                this.qtdItens--;
                System.out.println("Item foi removido da lista.");
                return;
            }
        }
        System.out.println("Item não encontrado.");
    }

    void listar(){
        for (int i = 0; i < this.qtdItens; i++) {
            System.out.println(this.itens[i]);
        }
    }
}