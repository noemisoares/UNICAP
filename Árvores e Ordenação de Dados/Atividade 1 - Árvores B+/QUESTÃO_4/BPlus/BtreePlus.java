package BPlus;

import Alunos.Aluno;

public class BtreePlus {
    private BNodePlus root;

    //A
    public Aluno buscar(String chave) {
        if (this.root == null) {
            return null;
        } 
        return buscarChave(this.root, chave);
    }

    private Aluno buscarChave(BNodePlus no, String chave) {
        int i = 0;
        while (i < no.getN() && chave.compareTo(no.getChaves()[i]) > 0) {
            i++;
        }

        if (no.isEhFolha()) {
            if (i < no.getN() && chave.equals(no.getChaves()[i])) {
                return no.getInfos()[i];
            } else {
                return null;
            }
        } else {
            return buscarChave(no.getPont()[i], chave);
        }
    }

    //B)
    private BNodePlus encontrarMenor() {
        BNodePlus atual = this.root;
        while (!atual.isEhFolha()) {
            atual = atual.getPont()[0];
        }
        return atual;
    }

    //C
    private BNodePlus encontrarMaior() {
        BNodePlus atual = this.root;
        while (!atual.isEhFolha()) {
            atual = atual.getPont()[atual.getN()];
        }
        return atual;
    }

    //D
    public void exibirEmOrdem() {
        BNodePlus atual = encontrarMenor();
        while (atual != null) {
            for (int i = 0; i < atual.getN(); i++) {
                System.out.println(atual.getChaves()[i] + " - " + atual.getInfos()[i]);
            }
            atual = atual.getProx();
        }
    }
}