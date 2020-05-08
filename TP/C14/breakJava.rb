f = File.open("Vechicle887998184.java","w")
#f.write("public class Vechicle0 {\n}\n")
for  i in 1..887998183
    f.write("class Vechicle"+i.to_s+" extends Vechicle"+(i+1).to_s+" {\n}\n");
    puts i
end
f.write("public class Vechicle887998184 {\n}\n")
