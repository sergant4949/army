source_dirs := . Abilities Gamefield Units Units/SpellCasters Units/Warriors Interfaces Spells Weapons
search_wildcards := $(addsuffix /*.cpp, $(source_dirs)) 

.PHONY: all clean install uninstall

army: $(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards))))
	g++ $^ -o $@ 

VPATH := $(source_dirs)
     
%.o: %.cpp
	g++ -c -MD $(addprefix -I,$(source_dirs)) $<

include $(wildcard *.d) 

clean:
	rm -rf *.o *.d
