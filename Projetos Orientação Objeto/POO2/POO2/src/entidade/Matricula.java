package entidade;

import util.Data;

public class Matricula {
    public enum Bolsa{completa, parcial, nenhuma};
    
    private Aluno aluno;
    private Curso curso;
    private Bolsa bolsa;
    private Data dataInicio;
    private float notaFinal;
    
    
   public Matricula(Aluno aluno, Curso curso, Bolsa bolsa, 
           Data dataInicio){
       
       this.aluno = aluno;
       this.curso = curso;
       this.bolsa = bolsa;
       this.dataInicio = dataInicio;
   }
   
   public Aluno getAluno(){
       return aluno;
   }
   public Curso getCurso(){
       return curso;
   }
   public Bolsa getBolsa(){
       return bolsa;
   }
   public Data getDataInicio(){
       return dataInicio;
   }
   public float getNotaFinal(){
       return notaFinal;
   }
   public void setNotaFinal(float notaFinal){
       this.notaFinal = notaFinal;
   }
    
}
