idea中使用@Test单元测试

首先在pom.xml中添加Junit的依赖

```xml
		<!-- https://mvnrepository.com/artifact/junit/junit -->
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.12</version>
            <scope>test</scope>
        </dependency>
        <dependency>
            <groupId>org.junit.jupiter</groupId>
            <artifactId>junit-jupiter</artifactId>
            <version>RELEASE</version>
            <scope>compile</scope>
        </dependency>
```



单元测试用例

```java
import org.junit.jupiter.api.Test;

/**
 * @Author ZechariahZheng
 * @Date 2019/11/27 15:03
 * @Version 1.0
 * @description
 */
public class Demo {

    @Test
    public void func() {
        func1("hello everyone");
    }

    public void func1(String str) {
        System.out.println(str);
    }
}

```

点击运行即可

运行结果：

![image-20191127151810411](C:\Users\ZZS\AppData\Roaming\Typora\typora-user-images\image-20191127151810411.png)