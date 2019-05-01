import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;

public class ex123_11 
{
  public static void main(String[] args) throws Exception
  {
    ScriptEngineManager mgr = new ScriptEngineManager();
    ScriptEngine engine = mgr.getEngineByName("JavaScript");
    String foo = "3+(8-7.5)*10/5-(2+5*7)";
    System.out.println(engine.eval(foo));
  } 
}