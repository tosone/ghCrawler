app_name = spider

all: debug

release debug:
	if [ ! -d $@ ]; then mkdir $@; fi
	cd $@ && cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache \
	-DCMAKE_BUILD_TYPE=$@ .. && cmake --build .

.PHONY: clean
clean:
	$(RM) -r release debug

.PHONY: image
image:
	docker-compose build spider

.PHONY: docker-run
docker-run:
	docker-compose run --rm --name $(app_name) $(app_name)
