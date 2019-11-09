package dao;


public interface UserinfoDao{
    int login(String username, String password) throws Exception;
}