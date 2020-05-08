# coding: utf-8

class Transliteration
  def self.convert(text, enforce_language = nil)
    language = detect_input_language(text.split(/\s+/).first)

    return text if language == enforce_language

    map = self.send(language.to_s).sort_by {|k,v| v.length <=>  k.length}
    map.each do |translit_key, translit_value|
      text.gsub!(translit_key.capitalize, translit_value.first)
      text.gsub!(translit_key, translit_value.last)
    end
    text
  end

private
  def self.create_bulgarian_map
    self.english.inject({}) do |acc, tuple|
      bul_up, bul_low = tuple.last
      eng_value       = tuple.first
      acc[bul_up]  ? acc[bul_up]  << eng_value.capitalize : acc[bul_up]  = [eng_value.capitalize]
      acc[bul_low] ? acc[bul_low] << eng_value            : acc[bul_low] = [eng_value]
      acc
    end
  end

  def self.detect_input_language(text)
    text.scan(/\w+/).empty? ? :bulgarian : :english
  end

  def self.english
    { "a"=>["А","а"], "b"=>["Б","б"], "v"=>["В","в"], "g"=>["Г","г"], "d"=>["Д","д"], "e"=>["Е","е"],  "zh"=>["Ж","ж"],
      "z"=>["З","з"], "i"=>["И","и"], "j"=>["Й","й"], "k"=>["К","к"], "l"=>["Л","л"], "m"=>["М","м"], "n"=>["Н","н"], "o"=>["О","о"], "p"=>["П","п"], "r"=>["Р","р"],
      "s"=>["С","с"], "t"=>["Т","т"], "u"=>["У","у"], "f"=>["Ф","ф"], "h"=>["Х","х"], "x"=>["Х","х"], "c"=>["Ц","ц"], "ch"=>["Ч","ч"], "sh"=>["Ш","ш"],
      "sht"=>["Щ","щ"], "u"=>["Ъ","ъ"], "'"=>["Ь","ь"], "ju"=>["Ю","ю"], "yu"=>["Ю","ю"], "ya"=>["Я","я"], "ja"=>["Я","я"], "q"=>["Я","я"]}
  end

  def self.bulgarian
    @bulgarian ||= create_bulgarian_map
  end
end
p Transliteration.convert("daniel georgiev")
p "даниел георгиев"==Transliteration.convert("daniel georgiev")
f = File.open("daniel.txt","w")
f.write(Transliteration.convert("daniel georgiev"))
