package ufba.dcc.mata55;

public class Avaliacao {
	private Filme filme;
	private byte nota;
		
	public Avaliacao(Filme filme, byte nota) {
		super();
		this.filme = filme;
		this.nota = nota;
	}
	public Filme getFilme() {
		return filme;
	}
	public void setFilme(Filme filme) {
		this.filme = filme;
	}
	public byte getNota() {
		return nota;
	}
	public void setNota(byte nota) {
		this.nota = nota;
	}
}
