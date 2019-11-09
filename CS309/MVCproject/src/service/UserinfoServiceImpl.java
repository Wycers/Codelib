package service;

import dao.UserinfoDao;
import dao.UserinfoDaoImpl;

public class UserinfoServiceImpl implements UserinfoService {

    private UserinfoDao userinfoDao = new UserinfoDaoImpl();
    @Override
    public int login(String username, String password) {
        int result = 0;
        try{
            result=userinfoDao.login(username,password);
        }catch(Exception e){
            e.printStackTrace();
        }
        return result;
    }
}
