SUBDIRS = src/Oled_Expansion src/Pwm_Expansion src/Relay_Expansion
all:    subdirs
.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@