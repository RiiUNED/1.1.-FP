#include "InsertBasisData.h"

void InsertBasisData(AllManager allManager)
{
  // 1
  allManager[0].warehouse.code = 1;
  strcpy(allManager[0].warehouse.city, "Majadahonda");
  strcpy(allManager[0].warehouse.address, "Calle Manzano, 5");
  strcpy(allManager[0].warehouse.state, "Madrid");
  strcpy(allManager[0].warehouse.description, "Centro");

  // 2
  allManager[1].warehouse.code = 2;
  strcpy(allManager[1].warehouse.city, "Requena");
  strcpy(allManager[1].warehouse.address, "Calle Acacias, 27");
  strcpy(allManager[1].warehouse.state, "Valencia");
  strcpy(allManager[1].warehouse.description, "Este");

  // 3
  allManager[2].warehouse.code = 3;
  strcpy(allManager[2].warehouse.city, "Utrera");
  strcpy(allManager[2].warehouse.address, "Carretera Cadiz, 84");
  strcpy(allManager[2].warehouse.state, "Sevilla");
  strcpy(allManager[2].warehouse.description, "Sur");

  // 4
  allManager[3].warehouse.code = 4;
  strcpy(allManager[3].warehouse.city, "Cuidad Rodrigo");
  strcpy(allManager[3].warehouse.address, "Avenida de Portugal, 39");
  strcpy(allManager[3].warehouse.state, "Salamanca");
  strcpy(allManager[3].warehouse.description, "Oeste");

  // 5
  allManager[4].warehouse.code = 5;
  strcpy(allManager[4].warehouse.city, "Oviedo");
  strcpy(allManager[4].warehouse.address, "Calle San Mateo, 6");
  strcpy(allManager[4].warehouse.state, "Asturias");
  strcpy(allManager[4].warehouse.description, "Norte");

  // 1, 1
  strcpy(allManager[0].patientList[0].id[0], "Maria");
  strcpy(allManager[0].patientList[0].id[1], "Carrera");
  allManager[0].patientList[0].position[0] = 5432;
  allManager[0].patientList[0].position[1] = 1990;

  // 1, 2
  strcpy(allManager[0].patientList[1].id[0], "Loreto");
  strcpy(allManager[0].patientList[1].id[1], "Arenillas");
  allManager[0].patientList[1].position[0] = 7430;
  allManager[0].patientList[1].position[1] = 1255;

  // 1, 3
  strcpy(allManager[0].patientList[2].id[0], "Jesus");
  strcpy(allManager[0].patientList[2].id[1], "Aguado");
  allManager[0].patientList[2].position[0] = 2965;
  allManager[0].patientList[2].position[1] = 54;

  // 1, 4
  strcpy(allManager[0].patientList[3].id[0], "Luis Miguel");
  strcpy(allManager[0].patientList[3].id[1], "Brasero");
  allManager[0].patientList[3].position[0] = 3754;
  allManager[0].patientList[3].position[1] = 1934;

  // 1, 5
  strcpy(allManager[0].patientList[4].id[0], "Carolina");
  strcpy(allManager[0].patientList[4].id[1], "Moreno");
  allManager[0].patientList[4].position[0] = 23;
  allManager[0].patientList[4].position[1] = 578;

  // 2, 1
  strcpy(allManager[1].patientList[0].id[0], "Jose Maria");
  strcpy(allManager[1].patientList[0].id[1], "Barrio");
  allManager[1].patientList[0].position[0] = 9034;
  allManager[1].patientList[0].position[1] = 1452;

  // 2, 2
  strcpy(allManager[1].patientList[1].id[0], "Eva");
  strcpy(allManager[1].patientList[1].id[1], "Bailen");
  allManager[1].patientList[1].position[0] = 11789;
  allManager[1].patientList[1].position[1] = 378;

  // 2, 3
  strcpy(allManager[1].patientList[2].id[0], "Marta");
  strcpy(allManager[1].patientList[2].id[1], "Llorente");
  allManager[1].patientList[2].position[0] = 334;
  allManager[1].patientList[2].position[1] = 250;

  // 2, 4
  strcpy(allManager[1].patientList[3].id[0], "Sergio");
  strcpy(allManager[1].patientList[3].id[1], "Arribas");
  allManager[1].patientList[3].position[0] = 7113;
  allManager[1].patientList[3].position[1] = 994;

  // 2, 5
  strcpy(allManager[1].patientList[4].id[0], "Isabel");
  strcpy(allManager[1].patientList[4].id[1], "Royo");
  allManager[1].patientList[4].position[0] = 643;
  allManager[1].patientList[4].position[1] = 12;

  //1, 1
  allManager[0].orderList[0].refPatient = 1;
  allManager[0].orderList[0].orderDate.sendNumbers = 1;
  allManager[0].orderList[0].orderDate.firstSendingDay.day = 21;
  allManager[0].orderList[0].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[0].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[0].orderDrugs[0].name, "Bicarbonato");
  allManager[0].orderList[0].orderDrugs[0].weight = 2750;
  allManager[0].orderList[0].orderDrugs[0].unities = 1;

  allManager[0].orderList[1].refPatient = 1;
  allManager[0].orderList[1].orderDate.sendNumbers = 1;
  allManager[0].orderList[1].orderDate.firstSendingDay.day = 21;
  allManager[0].orderList[1].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[1].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[1].orderDrugs[0].name, "Ibuprofeno");
  allManager[0].orderList[1].orderDrugs[0].weight = 250;
  allManager[0].orderList[1].orderDrugs[0].unities = 2;

  //1, 1
  allManager[0].orderList[2].refPatient = 1;
  allManager[0].orderList[2].orderDate.sendNumbers = 1;
  allManager[0].orderList[2].orderDate.firstSendingDay.day = 1;
  allManager[0].orderList[2].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[2].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[2].orderDrugs[0].name, "Paracetamol");
  allManager[0].orderList[2].orderDrugs[0].weight = 75;
  allManager[0].orderList[2].orderDrugs[0].unities = 2;

  //1, 4
  allManager[0].orderList[3].refPatient = 2;
  allManager[0].orderList[3].orderDate.sendNumbers = 1;
  allManager[0].orderList[3].orderDate.firstSendingDay.day = 1;
  allManager[0].orderList[3].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[3].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[3].orderDrugs[0].name, "Antihistaminico");
  allManager[0].orderList[3].orderDrugs[0].weight = 100;
  allManager[0].orderList[3].orderDrugs[0].unities = 1;

  //1, 5
  allManager[0].orderList[4].refPatient = 2;
  allManager[0].orderList[4].orderDate.sendNumbers = 1;
  allManager[0].orderList[4].orderDate.firstSendingDay.day = 30;
  allManager[0].orderList[4].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[4].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[4].orderDrugs[0].name, "Omeprazol");
  allManager[0].orderList[4].orderDrugs[0].weight = 350;
  allManager[0].orderList[4].orderDrugs[0].unities = 2;

  //1, 6
  allManager[0].orderList[5].refPatient = 2;
  allManager[0].orderList[5].orderDate.sendNumbers = 1;
  allManager[0].orderList[5].orderDate.firstSendingDay.day = 20;
  allManager[0].orderList[5].orderDate.firstSendingDay.month = february;
  allManager[0].orderList[5].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[5].orderDrugs[0].name, "Ibuprofeno");
  allManager[0].orderList[5].orderDrugs[0].weight = 50;
  allManager[0].orderList[5].orderDrugs[0].unities = 3;

  //1, 7
  allManager[0].orderList[6].refPatient = 3;
  allManager[0].orderList[6].orderDate.sendNumbers = 1;
  allManager[0].orderList[6].orderDate.firstSendingDay.day = 1;
  allManager[0].orderList[6].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[6].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[6].orderDrugs[0].name, "Alcohol");
  allManager[0].orderList[6].orderDrugs[0].weight = 150;
  allManager[0].orderList[6].orderDrugs[0].unities = 3;

  //1, 8
  allManager[0].orderList[7].refPatient = 3;
  allManager[0].orderList[7].orderDate.sendNumbers = 1;
  allManager[0].orderList[7].orderDate.firstSendingDay.day = 1;
  allManager[0].orderList[7].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[7].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[7].orderDrugs[0].name, "Aspirina");
  allManager[0].orderList[7].orderDrugs[0].weight = 50;
  allManager[0].orderList[7].orderDrugs[0].unities = 2;

  //1, 9
  allManager[0].orderList[8].refPatient = 3;
  allManager[0].orderList[8].orderDate.sendNumbers = 1;
  allManager[0].orderList[8].orderDate.firstSendingDay.day = 10;
  allManager[0].orderList[8].orderDate.firstSendingDay.month = january;
  allManager[0].orderList[8].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[0].orderList[8].orderDrugs[0].name, "Omeprazol");
  allManager[0].orderList[8].orderDrugs[0].weight = 750;
  allManager[0].orderList[8].orderDrugs[0].unities = 1;

  //2, 1
  allManager[1].orderList[0].refPatient = 1;
  allManager[1].orderList[0].orderDate.sendNumbers = 1;
  allManager[1].orderList[0].orderDate.firstSendingDay.day = 30;
  allManager[1].orderList[0].orderDate.firstSendingDay.month = march;
  allManager[1].orderList[0].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[0].orderDrugs[0].name, "Ibuprofeno");
  allManager[1].orderList[0].orderDrugs[0].weight = 25;
  allManager[1].orderList[0].orderDrugs[0].unities = 2;

  //2, 2
  allManager[1].orderList[1].refPatient = 1;
  allManager[1].orderList[1].orderDate.sendNumbers = 1;
  allManager[1].orderList[1].orderDate.firstSendingDay.day = 30;
  allManager[1].orderList[1].orderDate.firstSendingDay.month = march;
  allManager[1].orderList[1].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[1].orderDrugs[0].name, "Bicarbonato");
  allManager[1].orderList[1].orderDrugs[0].weight = 250;
  allManager[1].orderList[1].orderDrugs[0].unities = 1;

  //2, 3
  allManager[1].orderList[2].refPatient = 1;
  allManager[1].orderList[2].orderDate.sendNumbers = 1;
  allManager[1].orderList[2].orderDate.firstSendingDay.day = 30;
  allManager[1].orderList[2].orderDate.firstSendingDay.month = march;
  allManager[1].orderList[2].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[2].orderDrugs[0].name, "Omeprazol");
  allManager[1].orderList[2].orderDrugs[0].weight = 850;
  allManager[1].orderList[2].orderDrugs[0].unities = 1;

  //2, 4
  allManager[1].orderList[3].refPatient = 2;
  allManager[1].orderList[3].orderDate.sendNumbers = 1;
  allManager[1].orderList[3].orderDate.firstSendingDay.day = 30;
  allManager[1].orderList[3].orderDate.firstSendingDay.month = march;
  allManager[1].orderList[3].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[3].orderDrugs[0].name, "Aspirina");
  allManager[1].orderList[3].orderDrugs[0].weight = 115;
  allManager[1].orderList[3].orderDrugs[0].unities = 2;

  //2, 5
  allManager[1].orderList[4].refPatient = 2;
  allManager[1].orderList[4].orderDate.sendNumbers = 1;
  allManager[1].orderList[4].orderDate.firstSendingDay.day = 22;
  allManager[1].orderList[4].orderDate.firstSendingDay.month = february;
  allManager[1].orderList[4].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[4].orderDrugs[0].name, "Bicarbonato");
  allManager[1].orderList[4].orderDrugs[0].weight = 450;
  allManager[1].orderList[4].orderDrugs[0].unities = 1;

  //2, 6
  allManager[1].orderList[5].refPatient = 2;
  allManager[1].orderList[5].orderDate.sendNumbers = 1;
  allManager[1].orderList[5].orderDate.firstSendingDay.day = 11;
  allManager[1].orderList[5].orderDate.firstSendingDay.month = february;
  allManager[1].orderList[5].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[5].orderDrugs[0].name, "Almax");
  allManager[1].orderList[5].orderDrugs[0].weight = 150;
  allManager[1].orderList[5].orderDrugs[0].unities = 4;

  //2, 7
  allManager[1].orderList[6].refPatient = 1;
  allManager[1].orderList[6].orderDate.sendNumbers = 1;
  allManager[1].orderList[6].orderDate.firstSendingDay.day = 30;
  allManager[1].orderList[6].orderDate.firstSendingDay.month = march;
  allManager[1].orderList[6].orderDate.firstSendingDay.year = 2021;
  strcpy(allManager[1].orderList[6].orderDrugs[0].name, "Mercromina");
  allManager[1].orderList[6].orderDrugs[0].weight = 1400;
  allManager[1].orderList[6].orderDrugs[0].unities = 2;
}
