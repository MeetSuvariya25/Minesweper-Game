//THIS IS THE PROGRAM OF 2 GAMES MINESWPEER AND WOLFKILLER...

#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<windows.h>
#include<mmsystem.h>
#include<iomanip>
using namespace std;
//declaration of functions which will be individual for both games
void Wol();
void Mne();

//MINESWEEPER game code.
//one simple class (minesweeper).
class minesweeper{
public:
    char ans,m;
    int a,i,j,y,x,mine[10][10],score=0,location_temp=0;

//Getdata function will print salutation and also takes input.
    void getdata()
    {
    cout<<"\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n ";
    cout<<"\t\t\t\t\t Welcome to the mine sweeper game\n ";
    cout<<"\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n ";
    cout<<"\nWELCOME TO MINESWEEPER GAME..."<<endl;
    cout<<"\nPress any key for instruction\t";
    cin>>ans;
    cout<<"\n\t\tWarning!!!!!!\n ";
    cout<<"\n\t\tYou are entering a battelfield.\n ";
    cout<<"\n\t\tEnter the coordinate of x-y plane between 0-8\n\n";
    }

//body function will take input for co-ordinates and also check whether any bomb is there or not.
    void body()
    {
        label:
        cout<<"\nEnter the location of x:";
        cin>>x;
        cout<<"\nEnter the location of y:";
        cin>>y;
    if(x<8&&y<8)
    {
            switch(location_temp)
            {
             case 0:
                for(int j=0;j<8;j++)
                {
                    for(int k=0;k<8;k++)
                     {
                       mine[j][k]=1;
                       mine[0][1]=0;
                       mine[0][3]=0;
                       mine[1][2]=0;
                       mine[1][5]=0;
                       mine[2][0]=0;
                       mine[2][4]=0;
                       mine[2][7]=0;
                       mine[3][5]=0;
                       mine[4][6]=0;
                       mine[5][3]=0;
                       mine[6][5]=0;
                       mine[7][6]=0;
                       mine[7][0]=0;
                    }
              }
                break;
          case 1:
            for(int j=0;j<8;j++)
            {
                for(int k=0;k<8;k++)
                {
                    mine[j][k]=1;
                    mine[0][2]=0;
                    mine[1][3]=0;
                    mine[1][4]=0;
                    mine[2][5]=0;
                    mine[2][7]=0;
                    mine[3][4]=0;
                    mine[3][0]=0;
                    mine[4][6]=0;
                    mine[5][6]=0;
                    mine[5][3]=0;
                    mine[6][1]=0;
                    mine[7][6]=0;
                    mine[7][1]=0;
                }
            }
            break;
        case 2:
            for(int j=0;j<8;j++)
            {
                for(int k=0;k<8;k++)
                {
                    mine[j][k]=1;
                    mine[0][3]=0;
                    mine[0][5]=0;
                    mine[1][1]=0;
                    mine[1][7]=0;
                    mine[2][1]=0;
                    mine[2][4]=0;
                    mine[3][0]=0;
                    mine[4][3]=0;
                    mine[5][0]=0;
                    mine[5][5]=0;
                    mine[6][4]=0;
                    mine[7][2]=0;
                    mine[7][3]=0;
                }
           }
            break;
        }

    }
    else
    {
        cout<<"Sorry wrong coordinate of x-y ";
        goto label;
    }
    if(mine[x][y]==0)
     {
            sndPlaySound(TEXT("Bomb.wav"),SND_ASYNC);
            cout<<"\n  \tUnlucky lost";
            cout<<endl;
            cout<<"  \t********************\n";
            cout<<"  \tyour score is :"<<score<<endl;
            cout<<"  \t********************\n";
            cout<<"\nThe 0's are mine locations\n ";
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                cout<<"\t"<<mine[i][j];
                }
                cout<<endl;
            }
        }
      else
      {
          cout<<" \t\t********************\n";
          cout<<" \t\t    Lucky\n";
          cout<<" \t\t********************\n";
          score=score+5;
          goto label;
      }
    }
};


//WOLFKILLER GAME CODE

//declaration of classes
class Kill;
class Vote;
class Game{

public:
   // int no_of_players;
   int temp=7;
char arr[7];
    int n=7;
int no_of_players=7;
//Start function will just print NAME of game
    void Start()
    {
        cout<<"                        *********************************************************"<<endl;
        cout<<"                        -------------------------WOLFKILLER----------------------"<<endl;
        cout<<"                        *********************************************************"<<endl;
        cout<<"\nGAME STARTED...\n";
       // PlaySoundA("gamesound.wav" ,NULL, SND_FILENAME | SND_ASYNC);
    }
//Body function will initialize the array
    void body()
    {
               arr[0]='E';
        arr[3]='E';
        arr[6]='E';
        arr[1]='G';
        arr[2]='G';
        arr[4]='G';
        arr[5]='G';
        random_shuffle(&arr[0],&arr[7]);
    }
//This function is for seeing who is enemy and who is good team member
    void show()
    {
        for(int i=0;i<n;i++)
        {
            if(i>7)
                break;
                else
                {
            cout<<"Players "<<"--->"<<arr[i]<<endl;
                }
        }
    }



};

//DEFINITION of class Vote
class Vote:public Game{
public:
    int vot[7];
    int dead[7]={0};
  //  n=no_of_players;
//  lebel:
//vote function will take votes
    void vote()
    {
        cout<<"Enter the id of person you think is wolf(from 1 to 7):";

            for(int i=0;i<temp;i++)
            {
            cin>>vot[i];
            dead[vot[i]-1]++;

            }

    }

//sho function will just print the values of dead array
void sho()
    {
        cout<<"NUMBERS OF VOTES ARE : "<<endl;
        for(int i=0;i<n;i++)
        {
        cout<<dead[i];
        cout<<endl;
        }

    }


};

//Definition of class kill
class Kill:public Vote{
public:

//int coun[10];
   int players=no_of_players;

//compare function will kill the most voted person
  int compare()
   {

	  int index=0,no1=0,no2=0;
	  for (int j=0;j<players;j++)
	  {
		if(no1<=dead[j])
		{
		    //cout<<"\n "<<dead[index]<<" "<<no1<<" "<<no2;
		    index=j;
		    no2=no1;
		    no1=dead[index];
		    //no1=dead[index];
		    //no2=no1;
		    // cout<<"\n "<<dead[index]<<" "<<no1<<" "<<no2;
		}
	  }
	  if(no1==no2)
      {
          //cout<<no1<<no2<<"**************************************";
          cout<<"\nNo one died because of the tie .voting starts again...!"<<endl;
          return 0;

      }
	  if(arr[index]=='E')
                  {
                      arr[index]='0';
                      //vot[index]=0;
                      cout<<"YEAH!we killed an Enemy..."<<endl<<endl;
                      temp-=1;
                  }
	   else
                  {
                      arr[index]='0';
                      //vot[index]=0;
                      cout<<"BAD LUCK GOOD TEAM MEMBER DIED"<<endl;
                      temp-=1;
          	  }
       for(int i=0;i<n;i++)
       {
          dead[i]=0;
          vot[i]=0;
       }
    return 0;

   }

// All the calling and disision will be made in process function
void Process()
{       body();
while(1)
{
        vote();
        cout<<endl;
        //show();
        sho();
        cout<<endl;
        compare();
        int k=0;
        int flag=0;
        int gd=0,en=0;
        for(int i=0;i<7;i++)
        {
            if(arr[i]=='0')
            {
                k++;
            }
            else
            {
                if(arr[i]=='E')
                    en+=1;
                else if(arr[i]=='G')
                    gd+=1;

            }
            if(k==5)
            {
                if(en>=gd)
                {
                cout<<"\nOops!!!.. \nEnimies "<<"Won the game\n."<<endl;
                flag=1;
                break;
                }
                else
                {
                    cout<<"\nYehh.. \nGood team members "<<"Won the game\n."<<endl;
                    PlaySoundA("gamesound.wav" ,NULL, SND_FILENAME | SND_ASYNC);
                    flag=1;
                }
            }

        }
        if(flag==1)
            {
                break;
            }
}
}

};

//Definition of Mne function
//for mimesweeper game
void Mne(){
        system("color B0");
        system("cls");

    int a;
    minesweeper m;
    cout<<"MINESWEEPER game started..."<<endl;                 //object of class.
    m.getdata();

    repet:                              //repet label for play again.
    {
        cout<<"if want to play music than pree Y otherwise N:";
        cin>>m.m;
        if(m.m=='y' || m.m=='Y')
        {
            sndPlaySound(TEXT("sound.wav"),SND_ASYNC);
        }
        if(m.m=='n' || m.m=='N'){}
        m.body();
        cout<<"if you want to play again then press 1. if you want to exit press 0"<<endl;
        cin>>a;
    }

    if(a==1)
    {
        m.score=0;
        m.location_temp++;
        if(m.location_temp>2)
        {
            m.location_temp=0;
        }
        system("cls");
        goto repet;


    }
        }

//Definition of wol function
//for WOLFKILLER game
  void Wol(){
   system("color 2");
   // Game g;
   Kill k;
   system("cls");


    k.Start();
   k.Process();
   int play=0;
   cout<<"Do you want to play game again?"<<endl;
   cout<<"if you want to play again press 1::";
   cin>>play;
   if(play ==1)
   {
       for(int i=0;i<7;i++)
       {
       k.body();
       }
       random_shuffle(&k.arr[0],&k.arr[6]);
      Wol();
   }
   else{
       cout<<"\nGAME OVER..."<<endl;
        exit(1);}



}

//main function
int main()
{
     int starter=0;
    cout<<"\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n ";
    cout<<"\t\t\t\t\t       WELCOME TO ++GAMES         \n ";
    cout<<"\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n ";
    cout<<endl;
    cout<<" HERE TWO GAMES ARE THERE FOR U..."<<endl<<endl;
    cout<<"1. MINESWEEPER\n2. WOLFKILLER\n"<<endl;
    str:
        {
            cout<<"Enter 1 to play MINESWEEPER \nEnter 2 for playing WOLFKILLER\nEnter 0 for exit"<<endl;
            cin>>starter;
            cout<<endl;
        }
    if(starter==1)
    {
        Mne();
    }
    else if(starter==2)
    {

        Wol();
    }
    else if(starter==0)
    {

        exit(0);
    }
    else
    {
        cout<<"WRONGE INPUT\nPLEASE TRY AGAIN..."<<endl;
        goto str;
    }
    return 0;
}
