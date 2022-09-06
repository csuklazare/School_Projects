import java.io.File;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class Lab9 {

	public void readXML(String fileName)
	{
		try {
			File file = new File(fileName);
			DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
			DocumentBuilder db = dbf.newDocumentBuilder();
			Document doc = db.parse(file);
			doc.getDocumentElement().normalize();
			NodeList nodeLst = doc.getElementsByTagName("Borrowed_by");

			for (int s = 0; s < nodeLst.getLength(); s++) {

				Node fstNode = nodeLst.item(s);

				if (fstNode.getNodeType() == Node.ELEMENT_NODE) {
					String MemberID_string;
					int MemberID;
					String ISBN;
					String Checkout_date;
					String Checkin_date;
					Element sectionNode = (Element) fstNode;
					
					NodeList memberIdElementList = sectionNode.getElementsByTagName("MemberID");
					Element memberIdElmnt = (Element) memberIdElementList.item(0);
					NodeList memberIdNodeList = memberIdElmnt.getChildNodes();
					MemberID_string = (((Node) memberIdNodeList.item(0)).getNodeValue().trim());
					MemberID = Integer.parseInt(MemberID_string);

					NodeList secnoElementList = sectionNode.getElementsByTagName("ISBN");
					Element secnoElmnt = (Element) secnoElementList.item(0);
					NodeList secno = secnoElmnt.getChildNodes();
					ISBN = (((Node) secno.item(0)).getNodeValue().trim());

					NodeList codateElementList = sectionNode.getElementsByTagName("Checkout_date");
					Element codElmnt = (Element) codateElementList.item(0);
					NodeList cod = codElmnt.getChildNodes();
					Checkout_date = (((Node) cod.item(0)).getNodeValue().trim());

					NodeList cidateElementList = sectionNode.getElementsByTagName("Checkin_date");
					Element cidElmnt = (Element) cidateElementList.item(0);
					NodeList cid = cidElmnt.getChildNodes();
					Checkin_date = (((Node) cid.item(0)).getNodeValue().trim());
					System.out.println("Checkout_date: " + Checkout_date);
					System.out.println("Checkin_date: " + Checkin_date);
					System.out.println("ISBN: " + ISBN);
					System.out.println("MemberID: "  + MemberID);
					
					Checkout_date = change_date_format(Checkout_date);
					Checkin_date = change_date_format(Checkin_date);
					Connection con = null;
					try {
						Statement stmt;
						Statement stmt_two;
						ResultSet rs;
						ResultSet rs_two;
						int counter = 0;
						int executingUpdate;
						Class.forName("com.mysql.cj.jdbc.Driver");
						String url = "jdbc:mysql://faure/fisher25";
						con = DriverManager.getConnection(url, "fisher25", "830304896");
						stmt = con.createStatement();
						try {
							if (Checkout_date != "NULL") {
								stmt_two = con.createStatement();
								rs_two = stmt_two.executeQuery("SELECT * FROM Book WHERE ISBN = '" + ISBN + "';");
								while (rs_two.next()) {
									counter++;
								}
								if (counter > 0) {
									executingUpdate = stmt.executeUpdate("INSERT INTO Borrowed_by VALUES (" + MemberID + ", '"  + ISBN + "', " + Checkout_date + ", " + Checkin_date + ");");
									System.out.println("Adding a new record to the table for book " + ISBN + " and memberID " + MemberID);
								}
								else {
									System.out.println("This book doesn't exist.");
								}
							}
							else if (Checkin_date !="NA") {
								stmt_two = con.createStatement();
								rs_two = stmt_two.executeQuery("SELECT * FROM Borrowed_by WHERE Checkin_date is NULL AND ISBN = '" + ISBN + "';");
								while (rs_two.next()) {
									counter++;
								}
								if (counter > 0) {
									executingUpdate = stmt.executeUpdate("UPDATE Borrowed_by SET Checkin_date = " + Checkin_date + " WHERE ISBN = '" + ISBN + "' AND MemberID = " + MemberID + ";");
									System.out.println("Book has been checked back in");
								}
								else {
									System.out.println("This book isn't currently checked out.");
								}
							}
						} catch (Exception e) {
							System.out.println(e);
							System.out.println("Failed to checkout book/check in book");
						}
						con.close();
					} catch (Exception e) {
						e.printStackTrace();
					}
					System.out.println();
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public String change_date_format(String old_date) {
		String new_date = " ";
		String return_date = " ";
		if (old_date.equals("N/A")) {
			return_date = "NULL";
		}
		else {
			try {
				String OLD_FORMAT = "MM/dd/yyyy";
				String NEW_FORMAT = "yyyy-MM-dd";
				SimpleDateFormat sdf = new SimpleDateFormat(OLD_FORMAT);
				Date d = sdf.parse(old_date);
				sdf.applyPattern(NEW_FORMAT);
				new_date = sdf.format(d);
			} catch (Exception e) {
				System.out.println(e);
			}
			return_date = "'" + new_date + "'";
		}
		return return_date;
	}
	

	public static void main(String args[]){
		try {

			Lab9 showXML = new Lab9();
			showXML.readXML ("Libdata.xml");
		}catch( Exception e ) {
			e.printStackTrace();

		}//end catch

	}//end main

}//end class 
