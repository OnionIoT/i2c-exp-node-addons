SUBDIRS = src/oled-exp src/pwm-exp src/relay-exp
all:    subdirs
.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
