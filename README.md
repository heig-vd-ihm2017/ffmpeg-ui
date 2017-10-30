# FFMPEG-UI
A simple frontend application for FFMPEG made in Qt tending to have good UI/UX pratices based on Don Norman's [The Design of Everyday Things](https://en.wikipedia.org/wiki/The_Design_of_Everyday_Things).

This project is conducted for the course "IHM-2017", at HEIG-VD, Switzerland.

* Teacher: Andres Perez-Uribe
* Authors: Ludovic Delafontaine, Sathiya Kirushnapillai & Mathieu Monteverde

## Introduction
FFMPEG is a powerful tool. However, it is mostly used by command line and as so, not really user-friendly.

As in the project will create a program to use some aspects of FFMPEG with a nice and user-friendly UI.

As FFMPEG has many many options, we will stay focused on the following elements:

* A menu item allowing to exit the application
* A button allowing to select an input video file
* A text field allowing to edit the name of the input file
* A button allowing to select an output video file
* A text field allowing to edit the showing the properties of the input file
* A field allowing the user to select the start time of the output video
* A field allowing the user to select the stop time of the output video
* A text field showing the command line which should run ffmpeg to cut the video

The UI must give feedback about the following points as well:

* Whether the input file is valid
* The duration of the input video
* The start and stop time selected
* The overlapping between start and stop

## Disclaimer
As FFMPEG is normally used by command line, it is mostly for powerusers. As we wanted to deliver a program that everyone can use, the users used to FFMPEG may find our application way too simplish and heavy.

## UI/UX considerations
We decided to cut the whole process for cutting the video file into sequences. This allow the user to focus on one thing at a time and we can validate the step before continuing in the process.

We came to the following process:

* Introduction
* Choose the input file
* Set the start and end times for the given input file
* Choose the output file
* Summary and confirmation
* Result

For each step, we need to validate the step to allow the process to continue.

If there are errors, a message will be shown inside the layout to indicate what is wrong.

If the user presses more than two times the "Continue" button when there are errors, a more intrusive feedback will appear to ensure the user has seen the errors (pop-up, tooltip, etc.).

At every step, the user should be able to go back to edit previous steps.

### Introduction step
This step presents the program, what is it for and general considerations.

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/intro.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

### Input choice step
This step allows the user to select the input file.

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/input.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

The following feedbacks will ensure that the user can continue to the next step:
* Can we access to the input file ?
* Is the input file valid ?

### Times settings step
This step shows the input file properties and allows the user to select the start time and the end time to cut the video.

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/times.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

The following feedbacks will ensure that the user can continue to the next step:

* Is the start time inside the total length of the video file ?
* Is the stop time inside the total length of the video file ?
* Is the start time before the end time (no overlapping) ?

### Output choice step
This step shows the input file with its cutting times and total time of the potential output video. The user can select the desired output file.

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/output.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

The following feedbacks will ensure that the user can continue to the next step:

* Can we access to the output file ?
* Is the input filename valid ?
* Is there any files that have the same name ?
* If there is a file with the same name, does the program alerts the user that he is about to override the file ?

### Summary and confirmation step
This step shows the summary of the whole process:

* Input file with its properties
* Output file with the cutting and total times

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/summary.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

The following feedbacks will ensure that the user can continue to the next step:

* None, only need to confirm or go back to edit something.

### Result step
This step shows the FFMPEG's command line to launch to cut the input file to the new output file.

<img src="https://github.com/heig-vd-ihm2017/ffmpeg-ui/blob/master/images/results.png?raw=true" alt="Drawing" style="max-width: 50%;"/>

The user is invited to restart the process or exit the application.

## Technical details
* This application was made with [Qt](https://www.qt.io/)
* We used the [C++14 standard](https://en.wikipedia.org/wiki/C%2B%2B14) to develop this program
