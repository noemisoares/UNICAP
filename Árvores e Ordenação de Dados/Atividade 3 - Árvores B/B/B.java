package B;

public class B {
    private NodeB root;

    public boolean isEmpty(){
        return this.root == null;
    }

    // A)
    private NodeB encontrarNoMaior(NodeB no) {
        if (no == null) {
            return null;
        }
        
        if (no.isFolha()) {
            return no;
        } else {
            return encontrarNoMaior(no.getFilhos()[no.getN()]);
        }
    }
    // B)
    public void exibirMaior() {
        NodeB no = encontrarNoMaior(root);
        if (no != null) {
            System.out.println("Maior chave: " + no.getChaves()[no.getN() - 1]);
        } else {
            System.out.println("Árvore vazia!");
        }
    }

    // C)
    private NodeB encontrarMenor(NodeB no) {
        if (no == null) {
            return null;
        }
        
        if (no.isFolha()) {
            return no;
        }
        return encontrarMenor(no.getFilhos()[0]);
    }
    // D)
    public void exibirMenor() {
        NodeB no = encontrarMenor(root);
        if (no != null) {
            System.out.println("Menor chave: " + no.getChaves()[0]);
        } else {
            System.out.println("Árvore vazia!");
        }
    }

    // E)
    public int calcularAltura() {
        NodeB no = this.root;
        if (no == null) return 0;
        int altura = 1;
        while (!no.isFolha()) {
            no = no.getFilhos()[0];
            altura++;
        }
        return altura;
    }

    // F)
    private NodeB noBusca;
    private int posBusca;

    private void buscar(NodeB no, int valor) {
        noBusca = null;
        posBusca = -1;
        
        if (no == null) return;
        
        int i = 0;
        while (i < no.getN() && valor > no.getChaves()[i]) {
            i++;
        }
        
        if (i < no.getN() && valor == no.getChaves()[i]) {
            noBusca = no;
            posBusca = i;
            return;
        }
        
        if (!no.isFolha()) {
            buscar(no.getFilhos()[i], valor);
        }
    }
    // G)
    public void procurar(int valor) {
        buscar(root, valor);
        if (noBusca != null) {
            System.out.println("Valor " + valor + " encontrado na posição " + posBusca);
        } else {
            System.out.println("Valor " + valor + " não encontrado");
        }
    }
}