SUBDIRS = src/oled-exp src/pwm-exp src/relay-exp
all:	info
#all:    subdirs
.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

info:
	@echo "packages are pre-built"
