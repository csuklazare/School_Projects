README
======

A. - This package includes the following files.


|-- README.txt [This file]

B. - To run the program (assuming the seed is 13):

systemprompt> 


C. Questions:

	1. What is a docker container?
		- A docker container is a runtime instance of a docker image. A docker container consists of: A docker image, an execution environment, and a standard set of instructions. The concept is borrowed from shipping containers, which define a standard to ship goods globally. Docker defines a standard to ship software.

	2. What is the difference between a container and a virtual machine?
		- A virtual machine is heavier to run, provides more isolation, gets its own set of resources and does minimal sharing. 

	3. What is the purpose of a Dockerfile?
		- A Dockerfile is a text document that contains all the commands you would normally execute manually in order to build a Docker image. Docker can build images automatically by reading the instructions from a Dockerfile.

	4. What is the purpose of a requirement.txt file?
		- The requirements.txt file defines Python requiremenets that need installed by the parent image.

	5. What is the purpose of a docker-compose.yml file?
		- It defines the services that make up the application so they can be ran together in an isolated environment.

	6. What is the difference between a docker image and docker container?
		- Docker images are the basis of containers. An image is an ordered collection of root filesystem changes and the corresponding execution parameters for use within a container runtime. An image typically contains a union of layrered filesystems stacked on top of each other. An image does not have state and it never changes.

	7. What command can be used to create an image from a Dockerfile?
		- docker build

	8. What command will start a docker container?
		- docker start

	9. What command will stop a docker container?
		- docker stop

	10. What command will remove a docker container? Image?
		- docker rm for docker container. docker image rm for Image.

	11. What command will list all running docker container? All containers?
		- docker container ls defaults to list all running docker containers. docker container ls -a will list all containers

	12. What command will list all docker images?
		- docker image ls -a

	13. What command do you use to deploy docker containers using information in the docker-compose.yml file?
		- docker-compose run

	14. How can you specify in the docker-compose.yml file that you want docker containers to use the hosts network?
		- network: host

	15. How can you specify in the docker-compose.yml file where the Dockerfile for a particular container is found?
		- dockerfile: Location of Dockerfile



D. Example output code:


