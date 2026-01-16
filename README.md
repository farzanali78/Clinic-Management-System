# Clinic Management System 

A C++ console-based application designed to manage patient flow, doctors, and emergency situations in a medical clinic or hospital setting. This system uses efficient data structures to handle patient queues and record retrieval.

##  Table of Contents
- [About](#about)
- [Features](#features)
- [Technologies Used](#technologies-used)

##  About
This project is a Command Line Interface (CLI) tool designed to help **small medical centers and clinics** manage their daily patient flow. It streamlines the Outpatient Department (OPD) process by handling standard appointments and prioritizing emergency walk-ins. The system allows receptionists to add patients, search records, and process the doctor's queue efficiently.

##  Features
Based on the main menu interface, the system includes the following functionalities:

### 1. Patient Admission
* **Add Patient:** Register a new patient into the general queue.
* **Add Emergency Patient:** Register a patient with critical status (likely prioritized in the queue).

### 2. Queue Management
* **Show Next Patient:** View details of the patient currently at the front of the line without removing them.
* **Serve Next Patient:** Process the current patient and remove them from the active queue.
* **Show All Patients:** Display the complete list of patients waiting.
* **Show Emergency Patients:** Display a specific list of high-priority cases.

### 3. Search & Records
* **Search by Name:** Find patient details using their first or last name.
* **Search by Token:** Find a specific patient using their unique ID/token number.
* **Search by Doctor:** Filter and view all patients assigned to a specific doctor.

### 4. Administration
* **Update Patient Info:** Edit details for existing records.
* **Discharge Patient:** Formally release a patient from the system after treatment.
* **Show All Doctors:** View the list of available medical staff.

##  Technologies & Concepts
* **Language:** C++
* **Interface:** Console / Command Line
* **Key Concepts likely used:**
    * **Queues / Priority Queues:** For managing patient flow.
    * **Linked Lists:** For dynamic memory management of patient records.

*Created by Farzan Ali*
