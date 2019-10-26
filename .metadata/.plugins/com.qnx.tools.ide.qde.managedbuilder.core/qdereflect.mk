cc_reflect=$(if $(filter $(COMPILER_DRIVER),qcc),\
		qcc $(COMPILER_SPEC) -E -Wp$(comma)-P -Wp$(comma)-v -Wp$(comma)-dD,\
		$(CC$(select_compiler)) -E -P -v -dD)

qde-reflect:
	@echo INCVPATH::$(OS)::$(CPU)::$(VARIANT1)::$(INCVPATH)
	-@$(cc_reflect) $(SPECS_FILE)

.PHONY: qde-reflect
