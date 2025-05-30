package B;
import Fila.Queue;

public class B {
    private int m = 5;
    private NodeB root;

    public boolean isEmpty(){
        return this.root == null;
    }

    public void insert(int valor) {
        if (isEmpty()) {
            this.root = new NodeB(m);
            this.root.getChaves()[0] = valor;
            this.root.setN(1);
        } else {
            insertNode(root, valor);

            if (this.root.getN() == m) {
                NodeB novaRaiz = new NodeB(m);
                novaRaiz.setFolha(false);
                novaRaiz.getFilhos()[0] = this.root;
                paginaCisao(novaRaiz, 0, this.root);
                this.root = novaRaiz;
            }
        }
    }

    private void insertNode(NodeB no, int valor) {
        int i = no.getN() - 1;

        if (no.isFolha()) {
            while (i >= 0 && valor < no.getChaves()[i]) {
                no.getChaves()[i + 1] = no.getChaves()[i];
                i--;
            }
            no.getChaves()[i + 1] = valor;
            no.setN(no.getN() + 1);
        } else {
            while (i >= 0 && valor < no.getChaves()[i]) {
                i--;
            }
            i++;
            insertNode(no.getFilhos()[i], valor);

            if (no.getFilhos()[i].getN() == m) {
                paginaCisao(no, i, no.getFilhos()[i]);
            }
        }
    }

    private void paginaCisao(NodeB pai, int pos, NodeB cheio) {
        NodeB novoNo = new NodeB(m);
        novoNo.setFolha(cheio.isFolha());

        int t = m / 2;
        int chaveMediana = cheio.getChaves()[t];

        for (int j = 0; j < m - t - 1; j++) {
            novoNo.getChaves()[j] = cheio.getChaves()[t + 1 + j];
            cheio.getChaves()[t + 1 + j] = 0;
        }
        novoNo.setN(m - t - 1);

        if (!cheio.isFolha()) {
            for (int j = 0; j < m - t; j++) {
                novoNo.getFilhos()[j] = cheio.getFilhos()[t + 1 + j];
                cheio.getFilhos()[t + 1 + j] = null;
            }
        }

        cheio.setN(t);

        for (int j = pai.getN(); j > pos; j--) {
            pai.getChaves()[j] = pai.getChaves()[j - 1];
        }

        for (int j = pai.getN() + 1; j > pos + 1; j--) {
            pai.getFilhos()[j] = pai.getFilhos()[j - 1];
        }

        pai.getChaves()[pos] = chaveMediana;
        pai.getFilhos()[pos + 1] = novoNo;
        pai.setN(pai.getN() + 1);
    }

    public void emOrdem() {
        if (this.isEmpty()) {
            System.out.println("Árvore vazia");
        } else {
            percorrerEmOrdem(this.root);
            System.out.println();
        }
    }

    private void percorrerEmOrdem(NodeB no) {
        if (no != null) {
            if (no.isFolha()) {
                System.out.print("[");
                for (int i = 0; i < no.getN(); i++) {
                    System.out.print(no.getChaves()[i]);
                    if (i < no.getN() - 1) System.out.print(" | ");
                }
                System.out.print("] ");
            } else {
                percorrerEmOrdem(no.getFilhos()[0]);
                for (int i = 0; i < no.getN(); i++) {
                    System.out.print("[" + no.getChaves()[i] + "] ");
                    percorrerEmOrdem(no.getFilhos()[i + 1]);
                }
            }
        }
    }

    public void porNivel() {
        if (isEmpty()) {
            System.out.println("Árvore B vazia!");
        } else {
            passeioPorNivel(this.root);
        }
    }

    private void passeioPorNivel(NodeB raiz) {
        Queue<NodeB> fila = new Queue<>();
        fila.enQueue(raiz);

        while (!fila.isEmpty()) {
            int qtd = fila.getQtd();
            for (int i = 0; i < qtd; i++) {
                NodeB atual = fila.deQueue();
                if (atual != null) {
                    System.out.print("[");
                    for (int j = 0; j < atual.getN(); j++) {
                        System.out.print(atual.getChaves()[j]);
                        if (j < atual.getN() - 1) {
                            System.out.print(" | ");
                        }
                    }
                    System.out.print("] ");
                    if (!atual.isFolha()) {
                        for (int j = 0; j <= atual.getN(); j++) {
                            fila.enQueue(atual.getFilhos()[j]);
                        }
                    }
                }
            }
            System.out.println();
        }
    }

    public void remove(int valor) {
        if (isEmpty()) {
            System.out.println("Árvore está vazia.");
            return;
        }

        removeNode(root, valor);

        if (root.getN() == 0 && !root.isFolha()) {
            root = root.getFilhos()[0];
        } else if (root.getN() == 0) {
            root = null;
        }
    }

    private void removeNode(NodeB no, int valor) {
        int idx = 0;
        while (idx < no.getN() && valor > no.getChaves()[idx]) {
            idx++;
        }

        if (idx < no.getN() && no.getChaves()[idx] == valor) {
            if (no.isFolha()) {
                for (int i = idx; i < no.getN() - 1; i++) {
                    no.getChaves()[i] = no.getChaves()[i + 1];
                }
                no.setN(no.getN() - 1);
                
                if (no.getN() < m/2 && no != this.root) {
                    tratarPropagacao(no);
                }
            } else {
                NodeB sucessor = no.getFilhos()[idx + 1];
                while (!sucessor.isFolha()) {
                    sucessor = sucessor.getFilhos()[0];
                }
                int chaveSucessora = sucessor.getChaves()[0];
                no.getChaves()[idx] = chaveSucessora;
                removeNode(no.getFilhos()[idx + 1], chaveSucessora);
            }
        } else if (!no.isFolha()) {
            if (no.getFilhos()[idx].getN() < m / 2) {
                balancear(no, idx);
                if (no.getN() < m/2 && no != this.root) {
                    tratarPropagacao(no);
                }
                if (idx > no.getN()) {
                    idx = no.getN();
                }
            }
            removeNode(no.getFilhos()[idx], valor);
        }
    }

    private void tratarPropagacao(NodeB no) {
        NodeB atual = no;
        
        while (atual != this.root && atual.getN() < m/2) {
            NodeB pai = encontrarPai(this.root, atual);
            int idxFilho = encontrarIndiceFilho(pai, atual);
            balancear(pai, idxFilho);
            atual = pai;
        }
        
        if (this.root.getN() == 0 && !this.root.isFolha()) {
            this.root = this.root.getFilhos()[0];
        }
    }

    private NodeB encontrarPai(NodeB atual, NodeB filho) {
        if (atual == null || atual.isFolha()) return null;
        
        for (int i = 0; i <= atual.getN(); i++) {
            if (atual.getFilhos()[i] == filho) {
                return atual;
            }
            NodeB encontrado = encontrarPai(atual.getFilhos()[i], filho);
            if (encontrado != null) {
                return encontrado;
            }
        }
        return null;
    }

    private int encontrarIndiceFilho(NodeB pai, NodeB filho) {
        for (int i = 0; i <= pai.getN(); i++) {
            if (pai.getFilhos()[i] == filho) {
                return i;
            }
        }
        return -1;
    }

    private void balancear(NodeB pai, int idx) {
        if (idx < pai.getN() && pai.getFilhos()[idx + 1].getN() >= (m + 1) / 2) {
            redistribuir(pai, idx, true);
        }
        else if (idx > 0 && pai.getFilhos()[idx - 1].getN() >= (m + 1) / 2) {
            redistribuir(pai, idx - 1, false);
        }
        else if (idx < pai.getN()) {
            concatenar(pai, idx);
        }
        else {
            concatenar(pai, idx - 1);
        }
    }

    private void redistribuir(NodeB pai, int idx, boolean direita) {
        NodeB filho = pai.getFilhos()[idx];
        NodeB irmao;
        if (direita) {
            irmao = pai.getFilhos()[idx + 1];
        } else {
            irmao = pai.getFilhos()[idx - 1];
        }

        if (direita) {
            filho.getChaves()[filho.getN()] = pai.getChaves()[idx];
            filho.setN(filho.getN() + 1);

            pai.getChaves()[idx] = irmao.getChaves()[0];

            for (int i = 0; i < irmao.getN() - 1; i++) {
                irmao.getChaves()[i] = irmao.getChaves()[i + 1];
            }

            if (!irmao.isFolha()) {
                filho.getFilhos()[filho.getN()] = irmao.getFilhos()[0];
                for (int i = 0; i < irmao.getN(); i++) {
                    irmao.getFilhos()[i] = irmao.getFilhos()[i + 1];
                }
            }

            irmao.setN(irmao.getN() - 1);
        } else {
            for (int i = filho.getN(); i > 0; i--) {
                filho.getChaves()[i] = filho.getChaves()[i - 1];
            }

            filho.getChaves()[0] = pai.getChaves()[idx];
            filho.setN(filho.getN() + 1);

            pai.getChaves()[idx] = irmao.getChaves()[irmao.getN() - 1];

            if (!irmao.isFolha()) {
                for (int i = filho.getN(); i > 0; i--) {
                    filho.getFilhos()[i] = filho.getFilhos()[i - 1];
                }
                filho.getFilhos()[0] = irmao.getFilhos()[irmao.getN()];
            }

            irmao.setN(irmao.getN() - 1);
        }
    }

    private void concatenar(NodeB pai, int idx) {
        NodeB filho = pai.getFilhos()[idx];
        NodeB irmao = pai.getFilhos()[idx + 1];
        int nFilho = filho.getN();
        int nIrmao = irmao.getN();

        filho.getChaves()[nFilho] = pai.getChaves()[idx];

        for (int i = 0; i < nIrmao; i++) {
            filho.getChaves()[nFilho + 1 + i] = irmao.getChaves()[i];
        }

        if (!filho.isFolha()) {
            for (int i = 0; i <= nIrmao; i++) {
                filho.getFilhos()[nFilho + 1 + i] = irmao.getFilhos()[i];
            }
        }

        filho.setN(nFilho + 1 + nIrmao);

        for (int i = idx; i < pai.getN() - 1; i++) {
            pai.getChaves()[i] = pai.getChaves()[i + 1];
            pai.getFilhos()[i + 1] = pai.getFilhos()[i + 2];
        }

        pai.getChaves()[pai.getN() - 1] = 0;
        pai.getFilhos()[pai.getN()] = null;
        pai.setN(pai.getN() - 1);
    }
}