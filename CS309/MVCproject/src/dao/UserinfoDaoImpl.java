package dao;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.sql.Connection;
import java.sql.PreparedStatement;
import bean.UserinfoBean;
import util.DBUtil;
import com.mysql.jdbc.ResultSetImpl;


public class UserinfoDaoImpl implements UserinfoDao{

    Connection connection=null;
    DBUtil dbutil = new DBUtil();
    ResultSet resultSet =null;
    PreparedStatement preparedStatement = null;
    @Override
    public int login(String username, String password) throws Exception {
        // TODO Auto-generated method stub
        int result = 0;
        connection = dbutil.getConnection();
        String sql = "select count(*) from userinfo where username=? and password=?";
        System.out.println("here we are");
        preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, username);
        preparedStatement.setString(2, password);
        resultSet = preparedStatement.executeQuery();
        while (resultSet.next()) {
            result = resultSet.getInt(1);
        }
        dbutil.closeDBResource(connection, preparedStatement, resultSet);
        return result;
    }


}
