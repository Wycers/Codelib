package cn.edu.sustech;

public class ContainerImpl implements Container {
    @Override
    public <T> void register(Class<T> serviceType) {
        if (serviceType == null) {
            throw new IllegalArgumentException();
        }

    }

    @Override
    public <T> void register(Class<T> serviceType, Class<? extends T> implementationType) {
        if (serviceType == null || implementationType == null) {
            throw new IllegalArgumentException();
        }

    }

    @Override
    public <T> T resolve(Class<T> serviceType) {
        if (serviceType == null) {
            throw new IllegalArgumentException();
        }
        return null;
    }
}
