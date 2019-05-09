all: git_ec5.git dat_ec5.dat sol_ec5.x

git_ec5.git: dat_ec5.dat graf_ec5.py
	python3 graf_ec5.py

dat_ec5.dat: sol_ec5.x
	./sol_ec5.x

sol_ec5.x: sol_ec5.cpp
	g++ sol_ec5.cpp -o sol_ec5.x

clean:
	rm -rf *.x *.dat *.png
