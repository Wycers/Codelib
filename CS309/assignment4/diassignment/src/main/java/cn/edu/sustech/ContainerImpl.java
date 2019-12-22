package cn.edu.sustech;

import java.lang.reflect.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ContainerImpl implements Container {
    private Map<Class, Class> mp = new HashMap<>();

    @Override
    public <T> void register(Class<T> serviceType) {
        register(serviceType, serviceType);
    }

    @Override
    public <T> void register(Class<T> serviceType, Class<? extends T> implementationType) {
        if (serviceType == null || implementationType == null) {
            throw new IllegalArgumentException();
        }
        if (Modifier.isAbstract(implementationType.getModifiers()) ||
                Modifier.isInterface(implementationType.getModifiers()) ||
                serviceType.getConstructors().length > 1 ||
                implementationType.getConstructors().length > 1)
            throw new IllegalArgumentException();
        mp.put(serviceType, implementationType);
    }

    public <T> void justDoIt(T object, Class<?> now) throws IllegalAccessException {
        if (now == null)
            return;

        Field[] fields = now.getDeclaredFields();
        Field[] tmpFields = Arrays.stream(fields).filter((item) -> item.getAnnotation(Inject.class) != null).toArray(Field[]::new);
        for (Field item : tmpFields) {
            item.setAccessible(true);
            item.set(object, resolve(item.getType()));
            item.setAccessible(false);
        }
    }

    @Override
    public <T> T resolve(Class<T> serviceType) {
        if (serviceType == null)
            throw new IllegalArgumentException();
        if (mp.get(serviceType) == null)
            throw new ServiceNotFoundException();

        try {
            Class<?> implementationType = mp.get(serviceType);
            Constructor<?>[] constructors = implementationType.getConstructors();
            Constructor<?> constructor = constructors[0];
            Class<?>[] classes = constructor.getParameterTypes();
            Object[] objects = Arrays.stream(classes).map(this::resolve).toArray();
            T res = (T) constructor.newInstance(objects);

            justDoIt(res, implementationType.getSuperclass());
            justDoIt(res, implementationType);

            return res;
        } catch (InstantiationException | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
        }
        return null;
    }
}
