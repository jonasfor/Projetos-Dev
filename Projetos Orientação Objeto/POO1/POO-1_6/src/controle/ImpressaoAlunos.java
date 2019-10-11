package controle;
import entidade.Aluno;
import java.util.ArrayList;

public class ImpressaoAlunos {
    private static ArrayList<Aluno> alunos= new ArrayList();
    
    public static void main(String[] args){
        alunos = criarAlunos();
        imprimirAlunos("Alunos cadastrados", alunos);
        ArrayList<Aluno> alunos_selecionados = selecionarAlunos();
        imprimirAlunos("Alunos selecionados: ",alunos_selecionados);
    }

    private static ArrayList<Aluno> criarAlunos() {
        
        alunos.add(new Aluno ("Ana Julia", 1995, 'F', Aluno.EstadoCivil.solteiro, false));
        alunos.add(new Aluno ("Joaquim", 1990, 'M', Aluno.EstadoCivil.casado, true));
        alunos.add(new Aluno ("Ana Ligia", 1998, 'F', Aluno.EstadoCivil.solteiro, false));
        alunos.add(new Aluno ("Mateus", 1991, 'M', Aluno.EstadoCivil.solteiro, false));
        alunos.add(new Aluno ("Livia", 1985, 'F', Aluno.EstadoCivil.casado, true));
        alunos.add(new Aluno ("Roberto", 1990, 'M', Aluno.EstadoCivil.casado, false));
        alunos.add(new Aluno ("Ana Maria", 1991, 'F', Aluno.EstadoCivil.solteiro, false));
        alunos.add(new Aluno ("Sandro", 1992, 'M', Aluno.EstadoCivil.solteiro, true));
        return alunos;
    }

    private static ArrayList<Aluno> selecionarAlunos() {
        int ano_inicial = 1990;
        int ano_final = 1995;
        Aluno.EstadoCivil estado_civil;
        estado_civil = Aluno.EstadoCivil.solteiro;
        System.out.println("---Filtros de selecao: alunos nascidos entre: "
                + ano_inicial + "e" + ano_final + "com estado civil " + estado_civil + "\n");
        return filtrarAlunos(ano_inicial, ano_final, estado_civil);
    }

    private static ArrayList<Aluno> filtrarAlunos(int ano_inicial, int ano_final, Aluno.EstadoCivil estado_civil) {
        ArrayList<Aluno> alunos_selecionados = new ArrayList();
        for (Aluno aluno : alunos){
         int ano_nascimento = aluno.getanoNascimento();
         if((ano_nascimento >= ano_inicial)&&(ano_nascimento <= ano_final)
                 &&(aluno.getestadocivil() == estado_civil)){
             alunos_selecionados.add(aluno);
         }
        }
        return alunos_selecionados;
    }

    private static void imprimirAlunos(String cabecalho, ArrayList<Aluno> alunos) {
        System.out.println("---" + cabecalho);
        String dados_aluno;
        for(Aluno aluno : alunos){
            dados_aluno = aluno.getnome() + "   nasceu em : " + 
                    aluno.getanoNascimento() + "- sexo : ";
                    if (aluno.getsexo()=='F') dados_aluno += "Feminino";
                    else dados_aluno += "Masculino";
                    dados_aluno += "- estado civil : " + aluno.getestadocivil();
                    if (aluno.isEstrangeiro()) dados_aluno += "- estrangeiro.";
                    System.out.println(dados_aluno);
        }
        System.out.println();
    }
}
