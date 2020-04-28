清空静态变量用

``` java
@Before
public void handleBefore() {
  Jipa.TOTAL_INSTRUCTIONS = 0;
  Jipa.instruction = new String[0];
  Jipa.iPtr = 0;
  Label.labelList = new ArrayList<Label>();
}
```



System-rules测exit

``` java
@Rule
public final ExpectedSystemExit exit = ExpectedSystemExit.none();

exit.expectSystemExit();
```



System-rules测system-out

``` java
@Rule
public final SystemOutRule systemOutRule = new SystemOutRule().enableLog();

systemOutRule.getLog().replaceAll("\r\n", "\n")
```



System-rules测

``` java
@Rule
public final TextFromStandardInputStream systemInMock = emptyStandardInputStream();

systemInMock.provideLines("qwq.txt\n");
```





反射

``` java
public static Method getPrivateMethod(Class mClass, String methodName, Class ...params) throws NoSuchMethodException {
  Method privateMethod = mClass.getDeclaredMethod(methodName, params);
  privateMethod.setAccessible(true);
  return privateMethod;
}

public static Field getPrivateField(Class mClass, String fieldName) throws NoSuchFieldException {
  Field privateField = mClass.getDeclaredField(fieldName);
  if (privateField != null)
    privateField.setAccessible(true);
  return privateField;
}
```

