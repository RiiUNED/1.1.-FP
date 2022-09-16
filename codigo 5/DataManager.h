#pragma once
//----------------------
#include "Patient.h"
//----------------------
#include "Order.h"


typedef Patient PatientList[20];

typedef Order OrderList[100];

//-------------------------Data Manager---------------------------------

void InsertOrderToPatient(OrderList allOrders, PatientList allPatients);

//--------------------------All Patient---------------------------------

void InsertPatient(PatientList List);

void ShowPatientList(PatientList List);

void PrintHeadShowPatientList();

//---------------------------All Order-----------------------------------

void ResetOrderList(OrderList allOrders);

bool CheckOrderList(OrderList allOrders); //True: full; False: empty

void ShowOrderList(OrderList allOrders);
