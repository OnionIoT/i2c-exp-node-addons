SUBDIRS = src sim
?
all:    subdirs
?
.PHONY: subdirs $(SUBDIRS)
?
subdirs: $(SUBDIRS)
?
?
$(SUBDIRS):
        $(MAKE) -C $@