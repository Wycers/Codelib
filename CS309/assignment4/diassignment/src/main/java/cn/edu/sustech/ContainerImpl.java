package cn.edu.sustech;

public class ContainerImpl implements Container {
    @Override
    public <T> void register(Class<T> serviceType) {

    }

    @Override
    public <T> void register(Class<T> serviceType, Class<? extends T> implementationType) {

    }

    @Override
    public <T> T resolve(Class<T> serviceType) {
        return null;
    }
}
