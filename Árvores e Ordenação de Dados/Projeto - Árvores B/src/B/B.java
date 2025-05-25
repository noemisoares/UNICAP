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

            // Se a raiz ficou cheia, faz cisão e cria nova raiz
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
            // Move as chaves maiores para abrir espaço
            while (i >= 0 && valor < no.getChaves()[i]) {
                no.getChaves()[i + 1] = no.getChaves()[i];
                i--;
            }
            no.getChaves()[i + 1] = valor;
            no.setN(no.getN() + 1);
        } else {
            // Encontra o filho correto
            while (i >= 0 && valor < no.getChaves()[i]) {
                i--;
            }
            i++;

            // Insere recursivamente
            insertNode(no.getFilhos()[i], valor);

            // Verifica se o filho ficou cheio e precisa ser repartido
            if (no.getFilhos()[i].getN() == m) {
                paginaCisao(no, i, no.getFilhos()[i]);
            }
        }
    }

    private void paginaCisao(NodeB pai, int pos, NodeB cheio) {
        NodeB novoNo = new NodeB(m);
        novoNo.setFolha(cheio.isFolha());

        int t = m / 2; // grau mínimo
        int chaveMediana = cheio.getChaves()[t];

        // Copia as chaves para o novo nó (da direita)
        for (int j = 0; j < m - t - 1; j++) {
            novoNo.getChaves()[j] = cheio.getChaves()[t + 1 + j];
            cheio.getChaves()[t + 1 + j] = 0;
        }
        novoNo.setN(m - t - 1);

        // Se não for folha, copia os filhos também
        if (!cheio.isFolha()) {
            for (int j = 0; j < m - t; j++) {
                novoNo.getFilhos()[j] = cheio.getFilhos()[t + 1 + j];
                cheio.getFilhos()[t + 1 + j] = null;
            }
        }

        // Limita o número de chaves do nó original (esquerda)
        cheio.setN(t);

        // Desloca chaves no pai
        for (int j = pai.getN(); j > pos; j--) {
            pai.getChaves()[j] = pai.getChaves()[j - 1];
        }

        // Desloca filhos no pai
        for (int j = pai.getN() + 1; j > pos + 1; j--) {
            pai.getFilhos()[j] = pai.getFilhos()[j - 1];
        }

        // Insere a chave mediana e o novo filho no pai
        pai.getChaves()[pos] = chaveMediana;
        pai.getFilhos()[pos + 1] = novoNo;
        pai.setN(pai.getN() + 1);
    }






    public void preOrdem() {
        if (this.isEmpty()) {
            System.out.println("Árvore vazia");
        } else {
            percorrerPreOrdem(this.root);
        }
    }

    private void percorrerPreOrdem(NodeB no) {
        if (no != null) {
            System.out.print("[");
            for (int i = 0; i < no.getN(); i++) {
                System.out.print(no.getChaves()[i]);
                if (i < no.getN() - 1) {
                    System.out.print(" | ");
                }
            }
            System.out.println("]");            
            if (!no.isFolha()) {
                for (int i = 0; i <= no.getN(); i++) {
                    percorrerPreOrdem(no.getFilhos()[i]);
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



}