public class App{
    public static void main (String[] args){
       Paciente paciente = new Paciente("1234", "Naomi", "01/01/2001", "Feminino", "4321", "Corante", "O+");

       System.out.println("PACIENTE FILHA:");
       System.out.println("Código: " + paciente.codigo);
       System.out.println("Nome: " + paciente.nome);
       System.out.println("Data de Nascimento: " + paciente.dataNascimento);
       System.out.println("Sexo: " + paciente.sexo);
       System.out.println("Plano de Saúde: " + paciente.planoSaude);
       System.out.println("Alergia: " + paciente.alergia);
       System.out.println("Tipo Sanguineo: " + paciente.tipoSanguineo);

       paciente = new Paciente("4321", "Terezinha", "01/01/1901", "Feminino", "1234", "Poeira", "O-");
       
       System.out.println(" ");
       System.out.println("PACIENTE MÃE:");
       System.out.println("Código: " + paciente.codigo);
       System.out.println("Nome: " + paciente.nome);
       System.out.println("Data de Nascimento: " + paciente.dataNascimento);
       System.out.println("Sexo: " + paciente.sexo);
       System.out.println("Plano de Saúde: " + paciente.planoSaude);
       System.out.println("Alergia: " + paciente.alergia);
       System.out.println("Tipo Sanguineo: " + paciente.tipoSanguineo);
    }
}