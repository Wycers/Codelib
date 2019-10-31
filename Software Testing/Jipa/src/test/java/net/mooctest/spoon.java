package net.mooctest;

import org.junit.Test;

import spoon.Launcher;
import spoon.reflect.code.BinaryOperatorKind;
import spoon.reflect.code.CtBinaryOperator;
import spoon.reflect.declaration.CtClass;
import spoon.reflect.declaration.CtMethod;
import spoon.reflect.visitor.filter.NamedElementFilter;
import spoon.reflect.visitor.filter.TypeFilter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static spoon.refactoring.Refactoring.changeMethodName;

public class spoon {

    public static void work(String workPath, String outputPath) {
        File path = new File(workPath);
        System.out.println(path.getAbsolutePath());
        if (!path.exists()) {
            System.err.println("Work path does not exist.");
            return;
        }
        if (!path.isDirectory()) {
            System.err.println("Work path is not a directory");
            return;
        }

        Launcher launcher = new Launcher();

        launcher.addInputResource(workPath);
        launcher.buildModel();

        List<CtClass> classes = launcher.getFactory().Package().getRootPackage().getElements(new TypeFilter(CtClass.class));

        List<Object> methods = new ArrayList<Object>();
        int cnt = 0;
        for (CtClass ctClass : classes) {
            String className = ctClass.getQualifiedName();
            if (className.endsWith("scaffolding"))
                continue;
            if (className.endsWith("spoon"))
                continue;

            System.out.println(ctClass.getQualifiedName());
            for (Object method : ctClass.getMethods()) {
                changeMethodName((CtMethod<?>) method, "test" + cnt++);
                methods.add(method);
            }
        }

        output(methods, outputPath);
    }

    public static void output(List<Object> methods, String output) {
        File file = new File(output);
        if (file.exists()) {
            System.out.println("Output exists");
        } else {
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            FileWriter fileWriter = new FileWriter(file);
            for (Object method : methods) {
                fileWriter.write(method.toString());
                fileWriter.write("\n");
            }
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public static void main(String[] args) {
        work("src/evo/net/mooctest", "./wdnmd.txt");
    }
}
