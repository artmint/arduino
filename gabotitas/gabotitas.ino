const int rownum[8] = {
2,7,19,5,13,18,12,16 };

const int colnum[8] = {
6,11,10,3,17,4,8,9  };

float timeCount = 0;

int t[8][8] = {
{0,1,1,1,1,1,1,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0}};

int e[8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,1,1,0,0,0,0},
{0,1,1,1,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,1,1,1,1,1,0}};

int a[8][8] = {
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0}};

int m[8][8] = {
{0,1,1,0,0,1,1,0},
{0,1,0,1,1,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0}};

int o[8][8] = {
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,0,1,1,1,1,0,0}};

int cor[8][8] = {
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0}
};

int g[8][8] = {
{0,1,1,1,1,1,1,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,1,1,1,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,1,0}};

int b[8][8] = {
{0,1,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,0,0},
{0,1,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,0,0}};

int I[8][8] = {
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,1,1,1,0,0}};

int s[8][8] = {
{0,0,1,1,1,1,1,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,1,1,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,1,1,1,1,1,0,0}};

int blank[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}};

int cor1[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0}
};

int cor2[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

int cor3[8][8] = {
  {0,1,1,0,0,1,1,0},
  {1,0,0,1,1,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0}
};

void setup() {
  Serial.begin(9600);
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(colnum[thisPin], OUTPUT);
    pinMode(rownum[thisPin], OUTPUT);
    digitalWrite(colnum[thisPin], HIGH);
  }
}

void loop() {
  delay(5);
  timeCount += 1;
  if(timeCount < 200) {
    drawScreen(t);
  } else if (timeCount < 230) {
  } else if (timeCount < 400) {
    drawScreen(e);
  } else if (timeCount < 430) {
  } else if (timeCount < 600) {
    drawScreen(a);
  } else if (timeCount < 630) {
  } else if (timeCount < 800) {
    drawScreen(m);
  } else if (timeCount < 830) {
  } else if (timeCount < 1000) {
    drawScreen(o);
  } else if (timeCount < 1030) {
  } else if (timeCount < 1200) {
    drawScreen(g);
  } else if (timeCount < 1230) {
  } else if (timeCount < 1400) {
    drawScreen(a);
  } else if (timeCount < 1430) {
  } else if (timeCount < 1600) {
    drawScreen(b);
  } else if (timeCount < 1630) {
  } else if (timeCount < 1800) {
    drawScreen(o);
  } else if (timeCount < 1830) {
  } else if (timeCount < 2000) {
    drawScreen(t);
  } else if (timeCount < 2030) {
  } else if (timeCount < 2200) {
    drawScreen(I);
  } else if (timeCount < 2230) {
  } else if (timeCount < 2400) {
    drawScreen(t);
  } else if (timeCount < 2430) {
  } else if (timeCount < 2600) {
    drawScreen(a);
  } else if (timeCount < 2630) {
  } else if (timeCount < 2800) {
    drawScreen(s);
  } else if (timeCount < 2830) {
  } else if (timeCount < 3000) {
    drawScreen(cor2);
  } else if (timeCount < 2930) {
  } else if (timeCount < 3100) {
    drawScreen(cor1);
  } else if (timeCount < 3030) {
  } else if (timeCount < 3200) {
    drawScreen(cor);
  } else if (timeCount < 3130) {
  } else if (timeCount < 3300) {
    drawScreen(cor3);
  } else if (timeCount < 3430) {
  } else if (timeCount < 3600) {
  } else {
    timeCount = 0;
  }
}

int row(int i) {
  if(i == 1) {
    return 2;
  } else if (i == 2) {
    return 7;
  } else if (i == 3) {
    return 19;
  } else if (i == 4) {
    return 5;
  } else if (i == 5) {
    return 13;
  } else if (i == 6) {
    return 18;
  } else if (i == 7) {
    return 12;
  } else if (i == 8) {
    return 16;
  }
}

int col(int i) {
  if(i == 1) {
    return 6;
  } else if (i == 2) {
    return 11;
  } else if (i == 3) {
    return 10;
  } else if (i == 4) {
    return 3;
  } else if (i == 5) {
    return 17;
  } else if (i == 6) {
    return 4;
  } else if (i == 7) {
    return 8;
  } else if (i == 8) {
    return 9;
  }
}

void drawScreen(int character[8][8]) {
  for(int j = 0; j < 8; j++) {
    int rowNumber = j + 1;
    digitalWrite(row(rowNumber), HIGH);
    for (int k = 0; k < 8; k++) {
      int columnNumber = k + 1;
      if(character[j][k] == 1) {
        digitalWrite(col(columnNumber), LOW);
      }
      digitalWrite(col(columnNumber), HIGH);
    }
    digitalWrite(row(rowNumber), LOW);
  }
}
