.PHONY: push pull

push:
	git add .
	git commit -m "$(filter-out $@,$(MAKECMDGOALS))"
	git push origin main

pull:
	git pull origin main