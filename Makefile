SUBDIRS = src/oled_expansion src/pwm_expansion src/relay_expansion
all:    subdirs
.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
