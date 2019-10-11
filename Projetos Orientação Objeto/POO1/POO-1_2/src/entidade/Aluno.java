package entidade;

public class Aluno {
    
    public enum EstadoCivil {solteiro, casado, separado, viuvo};
    
    private String nome;
    private int anoNascimento;
    private char sexo;
    private EstadoCivil estadocivil;
    private boolean estrangeiro;
    
    public Aluno(String nome,int anoNascimento, char sexo){
        
        this.nome = nome; 
        this.anoNascimento = anoNascimento;
        this.sexo = sexo;
           
    }
    
    /* GET & SET */ 
    public String getnome(){
        return nome;
    }
    public void setnome (String nome){
        this.nome = nome;
    }
    
    public int getanoNascimento(){
        return anoNascimento;
    }
    public void setanoNascimento(int anoNascimento){
        this.anoNascimento = anoNascimento;
    }
    
    public char getsexo(){
        return sexo;
    }
    public void setsexo(char sexo){
        this.sexo = sexo;
    }
    
    public EstadoCivil getestadocivil(){
        return estadocivil;
    }
    public void setestadocivil(EstadoCivil estadocivil){
        this.estadocivil = estadocivil;
    }
    
    public boolean getestrangeiro(){
        return estrangeiro;
    }
    public void setestrangeiro(boolean estrangeiro){
        this.estrangeiro = estrangeiro;
    }

    public boolean isEstrangeiro(){
        if (getestrangeiro()== true) return true;
        else return false;
    }
}
