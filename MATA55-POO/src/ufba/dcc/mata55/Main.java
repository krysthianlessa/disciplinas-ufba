package ufba.dcc.mata55;

import java.io.IOException;

import javax.swing.SwingUtilities;

import jxl.write.WriteException;
import jxl.write.biff.RowsExceededException;

public class Main {
	
	public static void main(String[] args) {
		
		SwingUtilities.invokeLater(new Runnable(){ 
			public void run(){ 
//------------------------------<>Mudei aqui add na Main by:Hugo</>----------------------------------------------------------
				InsereDados inseredados = new InsereDados();
				
				try {
					inseredados.insere();
				} catch (RowsExceededException e2) {
					// TODO Auto-generated catch block
					e2.printStackTrace();
				} catch (WriteException e2) {
					// TODO Auto-generated catch block
					e2.printStackTrace();
				} catch (IOException e2) {
					// TODO Auto-generated catch block
					e2.printStackTrace();
				}
//------------------------------<>Mudei aqui add na Main by:Hugo</>----------------------------------------------------------
				Tela tela1;
				tela1 = new Tela(); 	
				tela1.setVisible(true);
			} 
		});	
	}
}
