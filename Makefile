all:
	git status
	git add .
	git commit -m "updated files on `date +%D`"
	git push
	git status
update:
	git pull
