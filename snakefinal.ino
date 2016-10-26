int randnumberx, randnumbery;
int led[7][7]{{0,1,2,3,4,5,6},
              {7,8,9,10,11,12,13},
              {14,15,16,17,18,19,20},
              {21,22,23,24,25,26,27},
              {28,29,30,31,32,33,34},
              {35,36,37,38,39,40,41},
              {53,43,44,45,46,47,48}};
int  pos[2][49]{{2,1,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
               {3,3,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}};
int t=0, p=0,sit=0, aux[2][49], botao=0, cont=2, temp=0, xpos=0, xneg=0, ypos=0, yneg=0,x=0, bolinha[2], sit2=0, sitbol=0, leda;

void setup(){
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(A7));
  pinMode(led[0][0], OUTPUT);
  pinMode(led[0][1], OUTPUT);
  pinMode(led[0][2], OUTPUT);
  pinMode(led[0][3], OUTPUT);
  pinMode(led[0][4], OUTPUT);
  pinMode(led[0][5], OUTPUT);
  pinMode(led[0][6], OUTPUT);
  pinMode(led[1][0], OUTPUT);
  pinMode(led[1][1], OUTPUT);
  pinMode(led[1][2], OUTPUT);
  pinMode(led[1][3], OUTPUT);
  pinMode(led[1][4], OUTPUT);
  pinMode(led[1][5], OUTPUT);
  pinMode(led[1][6], OUTPUT);
  pinMode(led[2][0], OUTPUT);
  pinMode(led[2][1], OUTPUT);
  pinMode(led[2][2], OUTPUT);
  pinMode(led[2][3], OUTPUT);
  pinMode(led[2][4], OUTPUT);
  pinMode(led[2][5], OUTPUT);
  pinMode(led[2][6], OUTPUT);
  pinMode(led[3][0], OUTPUT);
  pinMode(led[3][1], OUTPUT);
  pinMode(led[3][2], OUTPUT);
  pinMode(led[3][3], OUTPUT);
  pinMode(led[3][4], OUTPUT);
  pinMode(led[3][5], OUTPUT);
  pinMode(led[3][6], OUTPUT);
  pinMode(led[4][0], OUTPUT);
  pinMode(led[4][1], OUTPUT);
  pinMode(led[4][2], OUTPUT);
  pinMode(led[4][3], OUTPUT);
  pinMode(led[4][4], OUTPUT);
  pinMode(led[4][5], OUTPUT);
  pinMode(led[4][6], OUTPUT);
  pinMode(led[5][0], OUTPUT);
  pinMode(led[5][1], OUTPUT);
  pinMode(led[5][2], OUTPUT);
  pinMode(led[5][3], OUTPUT);
  pinMode(led[5][4], OUTPUT);
  pinMode(led[5][5], OUTPUT);
  pinMode(led[5][6], OUTPUT);
  pinMode(led[6][0], OUTPUT);
  pinMode(led[6][1], OUTPUT);
  pinMode(led[6][2], OUTPUT);
  pinMode(led[6][3], OUTPUT);
  pinMode(led[6][4], OUTPUT);
  pinMode(led[6][5], OUTPUT);
  pinMode(led[6][6], OUTPUT);
  pinMode(49, INPUT);
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(52, INPUT);
}

void loop() {
  //randNumbery = random(3);
  //digitalWrite(led[randNumberx][randNumbery],HIGH);
  //delay(1000);
  //digitalWrite(led[randNumberx][randNumbery],LOW);
 if (sit==0){
	 t=0;
	 p=0;
	 while(t<=6){
		 while(p<=6){
			 digitalWrite(led[t][p], LOW);
			 p++;
		 };
                  p=0;
		 t++;
	 };
         t=0;
         p=0;
         while(t<=1){
           while(p<=48){
             aux[t][p]=7;
             p++;
           };
           p=0;
           t++;
         };
	 t=0;
	 while(t<=6){
		digitalWrite(led[t][t], HIGH);
		digitalWrite(led[t][6-t], HIGH);
		 t++;
	 };
	 x=0;
	 while(x==0){
		 if((digitalRead(49)==HIGH)||(digitalRead(50)==HIGH)||(digitalRead(51)==HIGH)||(digitalRead(52)==HIGH)){
		     delay(500);
                      botao=0;	 
                    x=1;
		 };
	 };
	t=0;
        p=0;
	 while(t<=6){
		digitalWrite(led[t][t], LOW);
		digitalWrite(led[t][6-t], LOW);
		 t++;
	 };
	 x=0;
	 cont=2;
	 pos[0][0]=2;
         pos[0][1]=1;
         pos[0][2]=0;
         pos[1][0]=3;
         pos[1][1]=3;
         pos[1][2]=3;
         t=3;
         while(t<=48){
           pos[0][t]=7;
           pos[1][t]=7;
           t++;
         };
   digitalWrite(led[2][3], HIGH);
   digitalWrite(led[1][3], HIGH);
   digitalWrite(led[0][3], HIGH);
   sit=1;
   sitbol=1;
 };
 t=0;
 p=0;
 if(sitbol==1){
   randnumberx=random(7);
   randnumbery=random(7);
   while(digitalRead(led[randnumberx][randnumbery])==HIGH){
           randnumberx=random(7);
           randnumbery=random(7);
   };
   bolinha[0]=randnumberx;
   bolinha[1]=randnumbery;
   digitalWrite(led[bolinha[0]][bolinha[1]], HIGH);
   sitbol=0;
 };
 temp=0;
 while(temp<=500){
   xpos=digitalRead(49);
   xneg=digitalRead(50);
   ypos=digitalRead(51);
   yneg=digitalRead(52);
   if((xpos==HIGH)&&(botao!=1)){
     botao=0;
   }
   else if((xneg==HIGH)&&(botao!=0)){
     botao=1;
   }  
   else if((ypos==HIGH)&&(botao!=3)){
     botao=2;
   }
   else if((yneg==HIGH)&&(botao!=2)){
     botao=3;
   }
   xpos=0;
   xneg=0;
   ypos=0;
   yneg=0;
   delay(10);
   temp=temp+10;
 };
if (botao==0){
   if(pos[0][0]<=5){
	   t=0;
	   while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[0][0]++;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  
	   }
            sit2=0;
	}
	else if(pos[0][0]==6){
		t=0;
		while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[0][0]=0;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	};
 }
else if (botao==1){
   if(pos[0][0]>=1){
	   t=0;
	   while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[0][0]--;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	}
	else if(pos[0][0]==0){
		t=0;
		while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[0][0]=6;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	};
 }
 else if (botao==2){
   if(pos[1][0]>=1){
	   t=0;
	   while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[1][0]--;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	}
	else if(pos[1][0]==0){
		t=0;
		while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[1][0]=6;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   } 
	   sit2=0;
	};
 }
 else if (botao==3){
  if(pos[1][0]<=5){
	   t=0;
	   while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[1][0]++;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	}
	else if(pos[1][0]==6){
		t=0;
		while(t<=48){
		 aux[0][t]=pos[0][t];
		 aux[1][t]=pos[1][t];
		 t++;
	   };
	   pos[1][0]=0;
	   t=0;
	   while(t<cont){
		 pos[0][t+1]=aux[0][t];
		 pos[1][t+1]=aux[1][t];
		t++; 
	   };
	   if(digitalRead(led[pos[0][0]][pos[1][0]])==HIGH){
		   if((pos[0][0]==bolinha[0])&&(pos[1][0]==bolinha[1])){
			   cont++;
			   pos[0][cont]=aux[0][cont-1];
			   pos[1][cont]=aux[1][cont-1];
			   sit2=1; 
			   sitbol=1;
		   }
		   else{
			  sit=0; 
		   }
	   };
	   digitalWrite(led[pos[0][0]][pos[1][0]], HIGH);
	   if (sit2==0){
	   digitalWrite(led[aux[0][cont]][aux[1][cont]], LOW);  

	   }
	   sit2=0;
	}; 
 }
 
}
