package ufba.dcc.mata55;



import java.io.File;
import java.io.IOException;
import java.util.Locale; 
import jxl.Workbook;
import jxl.WorkbookSettings;
import jxl.write.Label;
import jxl.write.WritableCellFormat;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;
import jxl.write.biff.RowsExceededException;

public class InsereDados {
	
	
	
	// Metodo responsavel por fazer a escrita, a inserecoes dos dados na planilha
	public  void insere() throws IOException, RowsExceededException, WriteException{
			// Cria um novo arquivo
			//cria o arquivo .xls, de nome "Planilha1.xls"
			WritableWorkbook workbook = Workbook.createWorkbook(new File("Planilha1.xls"));
			//cria a planilha, de nome "Plan1"
			WritableSheet sheet = workbook.createSheet("Plan1", 0);
			
			//Cria um Label para preencher um célula
			//é importante notar que os  2 primeiros parâmetros passados (0,0)
			//representam a localização da célula que será escrita
			//neste caso na célula A1
// ----------------------- Se Descomentar aqui Ele criae e escreve so que no mesmo metodo de criar-------------------------------
//			Label label = new Label(0,0, "Teste");
//			
//			//adiciona a célula na planilha
//			sheet.addCell(label);
//-----------------------------------------------------------------------------------------------------------------------------------
			
//			WritableWorkbook workbook = Workbook.createWorkbook(arquivo, wbSettings);
//			// Define um nome para a planilha
//			workbook.createSheet("Filme", 0);
//			WritableSheet excelSheet = workbook.getSheet(0);
//			criaLabel(excelSheet);
//			defineConteudo(excelSheet);

			workbook.write();
			workbook.close();
		}
		
		public void defineConteudo(WritableSheet sheet) throws WriteException,
		RowsExceededException {
			for (int i = 0; i < 20; i++) {
				// Primeira coluna
				addLabel(sheet, 0, i, "Filme ");
				// Segunda coluna
				addLabel(sheet, 1, i, "Tutorial");
				// Terceira coluna
				addLabel(sheet, 2, i, "Exemplo");
			}
		}
		
		public void addLabel(WritableSheet planilha, int coluna, int linha, String conteudo)
				throws WriteException, RowsExceededException {
			
			Label label;
			label = new Label(coluna, linha, conteudo);
			planilha.addCell(label);
		}
			
	}
