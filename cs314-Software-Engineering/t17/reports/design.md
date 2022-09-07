# Introduction

This document describes the architecture and design of a single page web application that interacts with microservices via RESTful APIs.
The key elements in this document include the architecture, user interface, client components, and server classes.

This is a living document that is updated as changes are made each sprint.
The initial document describes the Base code students are given as a starting point for the semester.
During sprint planning the team will sketch proposed user interface changes, changes to the component hierarchy on the client, and changes to the class diagram on the server for each of the selected Epics.
At the end of the sprint, students should update the document to reflect the action changes made.


# Base

The Base is a simple application to provide the architecture to the students at the beginning of the semester.
The JavaScript code will include useful examples for students to learn from and leverage in the code they write for later sprints.
The progressive display of information using collapsible sections and popups will serve as examples of good user interface design.
The overall design is somewhat minimalist/simple for the intended mobile device audience.

### Architecture

The Base architecture is a JavaScript single page web application in an HTML5 browser that uses RESTful APIs to access Micro-services provided by a Java server running on Linux.
The client consists of a minimal index.html file that loads and executes the bundled JavaScript application.
The client and server files are bundled into a single JAR file for execution on the Linux server at a specified port.
The browser fetches the client HTML and JavaScript files from the server on the specified port.
The client application running in the browser makes Restful API calls for services specified in the protocol.

![overview](/client/src/static/images/BaseArchitecture.png)

The browser loads the index.html file (by default) which in turn loads the bundled JavaScript single page application bundle.js.
* The single page application makes RESTful API requests to the server on the same port using  JavaScript's asynchronous fetch.  
* A protocol document describes the JSON format for the RESTful API requests and responses.
* JSON Schemas are used to verify requests on the server side and responses on the client side.
* On the client, ReactJS renders the application using ReactStrap, Leaflet, and application defined components.
* GSON is used on the server to convert JSON requests to Java objects and Java objects to JSON responses.
* The client (ulog) and server (SLF4J) logging mechanisms control debugging output during development and production. 
* Print statements and console logging should never be used directly. 

The following architecture elements are not included in the Base system.
They will be added later in the semester.
* Client filesystem.
* Server SQL.
* Server concurrency.


### User Interface
![base](/client/src/static/images/Map.png)

The basic screen in black shows the view on a mobile device, with a header, footer, and trip.
The header contains a earth logo and the team name obtained from the server when the client was loaded.
The footer contains a connection icon along with the current server name and server URL the client is connected to.
The trip shows a map and the current list of destinations.

Rather than buttons or icons to signify actions, we are associating actions with elements that are already on the screen to reduce the clutter.
We are using both popups and collapsible sections in this design rather than choosing to use one exclusively.

* Collapsible/Hidden sections are used for the map and about sections since they have a significant amount of content and we don't need to see them at the same time.
* A popup is used for the URL change since we want to control the interaction until the operation is completed. It seemed more natural than another collapsible section.

#### Clicking on the team name in the header
Displays an About screen with team information, currently empty.
Hides tha trip information
Clicking again restores the trip information.
The About screen will be completed in Sprint 1.

#### Clicking on the map
Adds to the location to the trip.
* Displays a marker with latitude, longitude, and a description at that location on the map.
* Displays a line on the map showing the order of the destinations in the trip.
* The description is obtained from reverse geocoding.
* Appends the location to the destionations in the trip below the map.

#### Clicking the trip hamburger (&#8942;)
A list of menu options is displayed.
* You can add the current location the to the trip.
* You can add a location specfied by latitude and longitude.
* You can clear the list.

#### Clicking the hamburger (&#8942;) for a destination
A list of menu options is displayed.
* You can remove that destination from the list.

#### Clicking a entry is the trip list
Shows information about that destination.
* The detailed description of the entry will be toggled on or off.
* The map will move the marker to the selected location.

#### Clicking on the URL in the footer.
Show the information about the current server and let's you change the server for interoperability testing.
* When a user clicks on the URL, a popup should open showing the server configuration (team name and features) in an input text box.
* The Cancel button allows the user to exit the popup.
* When the user modifies the URL, the client will attempt to connect to the new server and update the configuration.
* When the client receives a successful response for a URL, it will display a Save button.
* When the user clicks the Save button, the server connection changes and the popup closes, revealing the new servername and URL in the footer.

### Component Hierarchy
The component hierarchy for the base application depicted below shows the our top level App component with four children components.
* App renders the major components on the screen.
* Header renders an icon and a team name in the top banner.
* Footer renders the current server connection in the bottom footer.
* Atlas renders a map.
* About renders information about the team.

![base component hierarchy](/client/src/static/images/ComponentsBase.png)

We do not show the many ReactStrap components in this hierarchy, even though they will appear when you are debugging on the client.

### Class Diagram
The class diagram for the base application depicted below shows the basic structure of the web server application.

![class diagram](/client/src/static/images/serverclasses.png )

The classes in blue represent the classes specific to this application.  
* WebApplication processes command line parameters and creates MicroServer.
* MicroServer start a web server on the given port, configures the server for security, static files, and APIs for different types of requests, and processes the requests as they arrive.
* JSONValidator verifies a request is properly formatted before attempting to process it using JSON Schemas.
* ConfigRequest is a specific request that allows the server to respond with its configuration to allow interoperability between clients and servers. 
* Request defines the basic components of all requests.
* BadReqeustException allows us to distinguish bad requests from other types of exceptions that may occur.

These test classes provide automated tests for unit testing.
* TestWebApplication
* TestMicroServer
* TestConfigRequest
* TestJSONValidator


# Sprint 1

In this sprint we focus on two epics.

### Epic: Team identification

#### User Interface
![team identification user inteface](/client/src/static/images/epicteamidentification.jpg)

This epic requires the team to the following information to update the team number and name:
* the browser tab contained in the TITLE tag of the HTML document.
* the header information that shows the client information.
* the footer information that shows the server information.  This may be different from the client information when the server is changed for interoperability testing.
  
#### Client Components 
There are no changes to the client component hierarchy for this epic.

Only a constants file needs to be modified.

#### Server Classes
There are no changes to the server class structure for this epic.

Only minor changes to text constants are required in the source and tests are required.

### Epic: About

#### User Interface
![about user interface](/client/src/static/images/epicAbout.jpg)

The template about page needs to be completed with:
* Team image
* Team mission statement
* Member name, hometown and bios.
* Member images.

#### Client Components
There are no changes to the client component hierarchy for this epic.  
The necessary components are already defined.

Changes required include:
* Updates to a constants file for the team mission statement.
* Updates to a constants file containing team member name and bio information.
* Addition of image files for the team and each team member. 

#### Server Classes
There are no changes to the server class structure for this epic.

# Sprint 2

In this sprint we focus on 3 epics.

### Epic: Load Trip

#### User Interface
![Load Trip Interface](/client/src/static/images/sprint2Diagrams/LoadTripDiagram.png)

This epic requires the team add or change the following:
* Add new icon to the hamburger drop-down 
* Give that icon button actuation 
* Add sub-menu for Load Trip that drops down, showing saved trips
* Add text to the drop-down menu indicating trips column / miles column
* Add Load Trip button at the bottom 
* Add Cancel button at the bottom
* Add button actuation for Load Trip to load the trip into the main window, closing the sub-menu
* Add button actuation for Cancel to close the sub-menu

#### Client Components 
Changes required include: 
* Adding imports for the ReactStrap icons. 
* Adding button actions
* Expanding ItineraryActionsDropdown() function 
* Building the frame of the sub-menu & labelling buttons/columns
* Displaying saved trips inside the & button functionality for selecting them

#### Server Classes
Changes required include: 
* Getting list of saved trips from the server

There likely will be more Server Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

### Epic: Distances

#### User Interface
![Distances Interface](/client/src/static/images/sprint2Diagrams/DistancesDiagram.png)

This epic requires the team add or change the following:
* Add new settings icon to the hamburger drop-down
* Give that settings icon button actuation
* Add sub-menu that drops-down from the settings button
* Add units button inside 'settings' menu
* Give the units button actuation
* Add pop-up menu from 'Units' button to include Miles, Kilometers, Nautical Miles selections
* Add additional selection option to 'Units' for Custom Units and Radius with button actuation 
* Add pop-up menu for additional custom unit option with text boxes for distance unit and earth radius
* Show the distance between selected 'legs' of the trip in map
* Show the cumulative distance at each 'leg' of the trip in map
* Show the total trip distance in 'Distances' section of interface
* Add mouse-over function for text boxes 'Distance Unit' and 'Earth Radius'
* Add clicking-hand indicator for selection boxes in unit options menu

#### Client Components 
Changes required include: 
* Add settings icon 
* Adding button actions for settings icon
* Build drop-down menu from setting icon
* Add units toggle button
* Build pop-up menu from 'Units' button
* In the 'Units' sub-menu, include buttons for miles, kilometers, nautical miles, and custom
* Build sub-menu for 'custom' button under 'Units'
* In  the 'custom' sub-menu, include text boxes to create distance units and the earth's radius
* Show a loaded trip's cumulative distance in interactive map
* Allow users to select 'legs' of a trip on the map to show distaance between them
* Allow users to select specific 'legs' on the map that will display total distance
* Include total trip distance in the 'Distance' section of interface
* Make mouse icon morph to a distinct pointer when hovering over clickable actions

#### Server Classes
(Tentative)

* Getting converted units from the server
* Getting calculated distances for loaded trips
* Getting distances between 'legs'

### Epic: Interoperability

#### User Interface
![Load Trip Interface](/client/src/static/images/sprint2Diagrams/InteroperabilityDiagram.png)

This epic requires the team add or change the following:
* Add a button 'Connect to a different server' in footer of the page 
* Give that button actuation
* Add pop-up menu displaying "What other server would you like to connect to? Server: ______"
* Add actuation to click inside text box to allow typing of a specific server
* Add logic that compares protocols of server user is trying to connect to/current server
* Add logic that if server protocols are the same, then connect to that server
* Add pop-up window stating "Connected to Server XXXXXX"
* Add logic that if server protocols are not the same, create a popup window that contains an error message inside.

#### Client Components 
Changes required include:  
* Adding button actions
* Building frames of sub-menus

#### Server Classes
Changes required include: 
* Checking if server has required protocols

There likely will be more Server Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 


# Sprint 3

In this sprint we will focus on 3 epics and 1 super epic that will be broken down into 7 epics for a grand total of 10 epics.

### Epic: Implement Distances to Work with Add Trip Button

#### User Interface
![Add_Trip_Distances_Diagram](/client/src/static/images/sprint3Diagrams/Add_Trip_Distances_Image.png)

This epic requires the team add or change the following:

* Adding the distance UI elements to the main page after Add Trip has been called.  
* Client will need to make an API request to the server for the distance update when Add Trip is called. 
* This will require updating the Add Trip function to make an API request to the server for a distances response. 

#### Client Components 
Changes required include: 
* Make an API request each time add trip is called once the Places array contains 2 or more places.
* Validate the server response.
* Retrieve the correct distances from the server.

#### Server Classes
Changes required include: 
* Validate the request from the client.
* Perform the calculations for the correct distance.
* Return the calculated distance in an array.

The epic above completes the epic from last Sprint "Distances".

### Epic: Find by Place: Server Side

#### User Interface
![Find_by_Place:Server_Side_Diagram](/client/src/static/images/sprint3Diagrams/serverStructureSprint3.png)

This epic requires the team add or change the following:
* Require us to add a new serverside integration with geolocater
* Require us to add a new serverside integration with a database that has names of places stored in it.

#### Server Classes
Changes required include: 

* A findPlacesResponse class.
* A findPlacesResponse buildResponse function. 
* A function that interfaces with the database and returns a list of matching locations. 
* Register endpoint in microserver.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

### Epic: Find by Place: Client Side

#### User Interface
![Find_by_Place:Client_Side_Diagram](/client/src/static/images/findplacesdiagram1.png)

This epic requires the team add or change the following:
* A new UI popup window that gives the user the ability to search for a place by name.
* The popup window will show which places match based on the input.
* There will be a UI button to add this found place to the user's current trip.

#### Client Components 
Changes required include: 

* A new button (eye glass) to enter the search sub menu.
* A new sub menu that displays options for searching for a place. 
* A new search field that allows the player to type a place. 
* A new 'Add to Trip' Button that puts the selected trips into the main page. 
* A new 'Cancel' button to close the Search popup.
* A new findPlaceRequest class that makes an API request to the server for a list of places. 

### Epic: Add Found Place

#### User Interface
![Add_Found_Place_Diagram](/client/src/static/images/sprint3Diagrams/addFoundPlace.png)

This epic requires the team add or change the following:

#### Client Components 
Changes required include: 
* Add new button next to found place that will add the place to itinerary.
* Take information returned by place search, then create a place object with said information.
* Store place object in itinerary.

#### Server Classes
Changes required include: 
* Create a database response with found place info, including name, lat, long, and altitude.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

### Epic: Find by Type: Server Side

#### User Interface
![Find_by_Type:Server_Side_Diagram](/client/src/static/images/sprint3Diagrams/serverStructureSprint3.png)

This epic requires the team add or change the following: 

* Make a build response from the database that applies a "type: where" filter to the data that is returned from the database.

#### Server Classes
Changes required include: 
* Receive a type request from client.
* Search database for places that correspond to the type request.
* Create response with list of places.
* Send response with places of corresponding type to client.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

### Epic: Find by Type: Client Side

#### User Interface
![Find_By_Type:Client_Side_Diagram](/client/src/static/images/findbyitem.png)

This epic requires the team add or change the following:
* Add a drop-down menu with specific types, including (but not limited to) airports, ship ports, heliports, etc.
* Create a request for type of place from within the database.

#### Client Components 
Changes required include: 
* Add drop down menu underneath search bar that has a list of place types.
* Once one is selected, show the selected type.
* Augment the API request to send a 'where' filter that matches the user input to the findPlaceRequest. 
* Validate json server response. 

### Epic: Find by Country: Server Side

#### User Interface
![Find_by_Country:Server_Side_Diagram](/client/src/static/images/sprint3Diagrams/serverStructureSprint3.png)

This epic requires the team add or change the following:
* Write a server build response that queries the database, filtering by a user entered country.
* Returns a lsit within that criteria.

#### Server Classes
Changes required include: 

* Add or augment the buildResponse to take into account the 'where' parameter for country.  
* A function that interfaces with the database and returns a list of matching locations. 
* Register endpoint in microserver.

### Epic: Find by Country: Client Side

#### User Interface
![Find_by_Country:Client_Side_Diagram](/client/src/static/images/findbyitem.png)

This epic requires the team add or change the following:

#### Client Components 
Changes required include: 
* Add drop-down list selection from 'Find Places' search box.
* Add selection option 'Find by Country'.
* Allow user to enter a string (country) which will be sent to the server for validation.
* Validate JSON server response on client side.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

### Epic: Find Place Random Generated List: Server Side

#### User Interface
![Find_Place:Random_Generated_List_Server_Side_Diagram](/client/src/static/images/findbyitem.png)

This epic requires the team add or change the following:
* Build a response from the database which randomly selects a list of places and then passes them to the client for the user.

#### Server Classes
Changes required include: 

* Validate the client request. 
* build function inside the findPlacesResponse to query the database for a random place or list of places.


### Epic: Find Place Random Generated List: Client Side

#### User Interface
![Find_Place_Random_Generated_List:Client_Side_Diagram](/client/src/static/images/generatedlocations.png)

This epic requires the team add or change the following:
* Team will need to send a request to the server to generate a random list of locations and display them in the client.

#### Client Components 
Changes required include: 
* Add 'randomly generated locations' button/icon to 'Find Places' menu.
* Button sends request to server for a query of random locations.
* Validate JSON response from server.
* Display randomized locations client-side.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

The 9 epics above complete the super epic "Find Places".

### Epic: Load Trip With CSV File

#### User Interface
![Load_Trip_With_CSV_File_Diagram](/client/src/static/images/sprint3Diagrams/LoadTripDiagram_CSV.png)

This epic requires the team add or change the following:
* Debug the issue currently being experienced with loading a CSV file in.
* Properly parse and load a CSV file into the web page.
* Potentially look at converting the CSV file to JSON if bug cannot be tracked down.

#### Client Components 
Changes required include: 
* Ensuring proper parsing of the CSV file.
* If converting to JSON, create a new class to convert the CSV file to JSON.
* Verify the returned JSON is valid.

#### Server Classes
Changes required include: 
* Verifying JSON passed is valid, especially if CSV files are being converted to JSON.
* Calculate the distances.
* Send distances back through.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

The epic above completes the epic from last Sprint "Load Trip".

### Epic: Interoperability

#### User Interface
![Interoperability_Sprint3_Diagram](/client/src/static/images/sprint3Diagrams/InteroperabilityDiagram_Sprint3.png)

This epic requires the team add or change the following:

#### Client Components 
Changes required include: 
* Add a pop up that shows if the server the user is trying to connect to doesn't have the same protocols implemented.
* Send a request to the server to validate protocols.

#### Server Classes
Changes required include: 
* Receive request to validate protocols.
* Validate protocols, and return true/false depending if the protocols are met.

There likely will be more Server/Client Side changes throughout the project, however 
as of right now the team is still learning the architecture behind the client
and server. 

The epic above completes the epic from last Sprint "Interoperability".

# Sprint 4 

In this sprint we will primarily focus on a single epic, the Tour epic where we optimize the trips input by the user. 

### Epic: Tour Client Side

#### User Interface
![ShorterTrip Image](/client/src/static/images/sprint4Diagrams/shorterTrip.png)

This epic requires the team to add or change the following:

#### Client Components 
Changes required include: 
* Add a new button to the widgets for trip optimization
* Add a server request class to the server API for the tour. 
* A pop-up menu when the optimize tour button is pressed that shows an optimized trip (if there is one) and allows the user to confirm / use it or discard it. 
* A button that confirms the user wants to use the optimized trip in the pop-up. 
* Replace the places object from input trip to an optimized version if the user decides to use it. 
* Import JSON schema validation for tour request.



### Epic : Tour Server Side
![ShorterTrip Image](/client/src/static/images/sprint4Diagrams/shorterTripServer.png)

### Server Components
Changes required include: 
* A server response from the API that returns an optimized trip list. All within 1 second.
* Make the endpoint in the server
* Register the new server response endpoint in the microserver.
* Update the feature's list in the server
* Upload JSON schema validation for response
* Update restful API to take the new schema 
* Update Features list in config.java file.


### Epic: NearestNeighbor

#### Server Implementation
![NearestNeighbor Image](/client/src/static/images/sprint4Diagrams/NearestNeighbor.png)

This epic requires the team to add or change the following:
### Server Side
Changes required include:
* A java class that implements a nearest neighbor's algorithm to optimize the user's trip
* Build a function that builds a TourResponse
* Improve the Nearest Neighbor algorithm to 2-opt
* Improve the Nearest Neighbor algorithm to 3-opt 
* Find limits where the algorithm won't respond in time for Nearest, 2-opt, & 3-opt 


### Epic: Find By Place: Server Side

#### Server Implementation
![FindByPlaceServerSide Image](/client/src/static/images/sprint4Diagrams/FindByPlaceServerSide.png)

This epic requires the team to add or change the following:
### Server Side
Changes required include:
* Change the query request to the database to poll all the tables in the database.

# Sprint 5

In this sprint we will focus on preparing the product for a final release. It contains 3 epics that focus on ensuring the correctness of the API, improvements to the trip optimization algorithm, and adding a feature that will allow the user to save a trip.

### Epic: Testing API

![TestAPI Image](/client/src/static/images/sprint5Diagrams/APItest.png)

This epic requires the team to add or change the following:

#### Client Changes

* Implement more test files on the client side to test API connections for each of the different epics.
* Depending on what the issues are tracked down as, the client changes could vary drastically.

#### Server Changes

* Implement more tests on the server side to test API connections for each of the different epics.
* Depending on what the issues are tracked down as, the server changes could vary drastically.

### Epic: 2-OPT

![NearestNeighbor Image](/client/src/static/images/sprint4Diagrams/NearestNeighbor.png)

This epic requires the team to add or change the following:

#### Client Changes
No client side changes should be required for this epic. 

#### Server Changes
* Update the NN algorithm to utilize 2-opt methods
* Find the new limit for number of trips that can be optimized using 2-opt
* Add new test cases for 2-opt algorithm. 
* Consider splitting the algorithm into two, where if the file cannot be optimized by 2-opt, it tries for NN instead. 

### Epic: Save Trip

![SaveTrip Diagram Image](/client/src/static/images/sprint5Diagrams/savetrip_draft.png)

This epic requires the team to add or change the following:

#### Client Changes
* Add new Save Trip widget button
* Add new popup for when the save trip widget is clicked
* Add save button
* Add cancel button
* Add an explorer browser popup when save is selected to allow the user to save locally 
* Add radio menu for file format type to save in

#### Server Changes
There should be no server side changes required for this epic. 
