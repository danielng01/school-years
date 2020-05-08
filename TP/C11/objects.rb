class Objects
    attr_accessor :value
    def method
    
    end
    private
    def method_private
        puts "sss"    
    end
    public 
    def method_public
    
    end
end
o = Objects.new
o.method
o.send("method_private")
o.send(:method)
o.value
o.value=5
p o.value

