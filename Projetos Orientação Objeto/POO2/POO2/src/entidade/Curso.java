package entidade;

import java.util.ArrayList;

public class Curso {
    private String titulo;
    private int cargaHorariaSemanal, duracaoSemanas;
    private ArrayList<Curso> preRequisitos = new ArrayList<Curso>();

    public Curso(String titulo, int cargaHorariaSemanal, int duracaoSemanas){
        this.titulo = titulo;
        this.cargaHorariaSemanal = cargaHorariaSemanal;
        this.duracaoSemanas = duracaoSemanas;
    }
    
    public  String getTitulo(){
        return titulo;
    }
    public int getCargaHorariaSemanal(){
        return cargaHorariaSemanal;
    }
    public int getDuracaoSemanas(){
        return duracaoSemanas;
    }
    public ArrayList<Curso> getPreRequisitos(){
        return preRequisitos;
    }
    
    public boolean inserirPreRequisitos(Curso curso){
        if(!preRequisitos.contains(curso)){
            preRequisitos.add(curso);
            return true;
        }else return false;
    }
    
    public boolean removePreRequisitos(Curso curso){
        return preRequisitos.remove(curso);
    }

}

