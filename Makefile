CurveSim/curvesim : CurveSim/*.cpp
	g++ -std=c++11 CurveSim/*.cpp -o curvesim
clean :
	rm curvesim
