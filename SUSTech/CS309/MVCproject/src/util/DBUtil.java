package util;
import com.mysql.jdbc.Driver;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
public class DBUtil {
    public Connection getConnection() throws Exception{
        Connection connection=null;
        String diverClass="com.mysql.cj.jdbc.Driver";
        String url="jdbc:mysql://localhost:3306/mvcproject";
        String name="root";
        String password="wdnmd";
        Class.forName(diverClass);
        connection=DriverManager.getConnection(url,name,password);
        return connection;
    }
/**
 * 关闭数据库链接
 * @param connection
 * @param preparedStatement
 * @param resultSet
 * @throws Exception
 */
public void closeDBResource(Connection connection, PreparedStatement preparedStatement,
                            ResultSet resultSet) throws Exception{
    if(resultSet!=null){
        try{
            resultSet.close();
        }finally{
            resultSet=null;
        }
    }
    if(preparedStatement!=null){
        try{
            preparedStatement.close();
        }finally{
            preparedStatement=null;
        }
    }
    if(connection!=null){
        try{
            connection.close();
        }finally{
            connection=null;
        }
    }
}
}