package cn.edu.sustech;

import java.util.Map;

public class ContainerImpl implements Container {
    private static Map<Class, Class> mp;

    @Override
    public <T> void register(Class<T> serviceType) {
        if (serviceType == null) {
            throw new IllegalArgumentException();
        }
        register(serviceType, serviceType);
    }

    @Override
    public <T> void register(Class<T> serviceType, Class<? extends T> implementationType) {
        if (serviceType == null || implementationType == null) {
            throw new IllegalArgumentException();
        }

    }

    @Override
    public <T> T resolve(Class<T> serviceType) {
        if (serviceType == null)
            throw new IllegalArgumentException();
        if (mp.get(serviceType) == null)
            throw new ServiceNotFoundException();
        return null;
    }
}
