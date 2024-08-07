// Import the roslibjs library
const ROSLIB = require('roslib');

// Create a ROS connection instance
const ros = new ROSLIB.Ros({
  url: 'ws://localhost:9090' // URL of the ROS bridge server
});

// Handle connection events
ros.on('connection', function() {
  console.log('Connected to websocket server.');
});

ros.on('error', function(error) {
  console.log('Error connecting to websocket server: ', error);
});

ros.on('close', function() {
  console.log('Connection to websocket server closed.');
});

// Create a ROS topic subscriber for the "chatter" topic
const chatterListener = new ROSLIB.Topic({
  ros: ros,
  name: '/chatter',
  messageType: 'std_msgs/String'
});

// Define a callback function to handle incoming messages
chatterListener.subscribe(function(message) {
  console.log('Received message on /chatter: ', message.data);
});
