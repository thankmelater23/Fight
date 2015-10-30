#include "DarkGDK.h"
#include "CONSTANTS.h"
	

	int const SYNC = 25;

	void loadGSM();
	void detectCollision();
	void memoryLeak();
	void fightText();
	void playMusic();


void DarkGDK(void)
{

	
	loadGSM();
	fightText();

	
	

	while(LoopGDK())
	{
		

		
		detectCollision();


		dbSync();
	}
	
	memoryLeak();

	return;
}






void loadGSM()
{
	dbSetDisplayMode(640, 480, 32);
	dbSetWindowTitle("Fight");
	dbSyncOn();
	dbSyncRate(SYNC);
	dbSetImageColorKey(0, 255, 0);
	dbDisableEscapeKey();

	dbCreateAnimatedSprite(HERO_SPRITE, "player.bmp", 10, 1, HERO_IMG);
	dbCreateAnimatedSprite(HERO_SPRITE2, "player2.bmp", 9, 1, HERO_IMG2);
	dbLoadImage("backgroundG.bmp", BACKGROUND_IMG);
	dbLoadImage("HealthBar.bmp", HEALTH_BAR_IMG);
	dbLoadImage("ground_top.bmp", GROUND1_IMG);
	dbLoadImage("ground_bottom.bmp", GROUND2_IMG);
	dbLoadImage("end_line.bmp", END_LINE_IMG);
	dbLoadImage("horizontal_line.bmp", HORO_LINE_IMG);
	dbLoadImage("front_stamina.bmp", FRNT_STAM_IMG);
	dbLoadImage("back_stamina.bmp", BACK_STAM_IMG);
	dbLoadImage("stamina_bar.bmp", STAM_IMG);
	dbLoadImage("clock.bmp", CLOCK_IMG);


	dbLoadMusic("Grove Street.mp3", 1);
	dbLoadMusic("South Park - Timmy Freestyles.mp3", 2);


	dbSprite(BACKGROUND_SPRITE, BACKGROUND_STRT_X, BACKGROUND_STRT_Y, BACKGROUND_IMG);
	dbSprite(HEALTH_BAR_SPRITE, HEALTH_BAR_STRT_X, HEALTH_BAR_STRT_Y, HEALTH_BAR_IMG);	
	dbSprite(GROUND1_SPRITE, GROUND1_STRT_X, GROUND1_STRT_Y, GROUND1_IMG);
	dbSprite(GROUND2_SPRITE,GROUND2_STRT_X, GROUND2_STRT_Y, GROUND2_IMG);
	dbSprite(HERO_SPRITE, HERO_STRT_X,HERO_STRT_Y, HERO_IMG);
	dbSprite(END_LINE_SPRITE, END_LINE_STRT_X, END_LINE_STRT_Y, END_LINE_IMG);
	dbSprite(END_LINE_SPRITE2, END_LINE_STRT_X2, END_LINE_STRT_Y2, END_LINE_IMG);
	dbSprite(HORO_LINE_SPRITE, HORO_LINE_STRT_X, HORO_LINE_STRT_Y, HORO_LINE_IMG);
	dbSprite(HORO_LINE_SPRITE2, HORO_LINE_STRT_X2, HORO_LINE_STRT_Y2, HORO_LINE_IMG);
	dbSprite(FRNT_STAM_SPRITE, FRNT_STAM_STRT_X, FRNT_STAM_STRT_Y, FRNT_STAM_IMG);
	dbSprite(FRNT_STAM_SPRITE2, FRNT_STAM_STRT_X2, FRNT_STAM_STRT_Y2, FRNT_STAM_IMG);
	dbSprite(BACK_STAM_SPRITE, BACK_STAM_STRT_X, BACK_STAM_STRT_Y, BACK_STAM_IMG);
	dbSprite(BACK_STAM_SPRITE2, BACK_STAM_STRT_X2, BACK_STAM_STRT_Y2, BACK_STAM_IMG);
	dbSprite(STAM_SPRITE, STAM_STRT_X, STAM_STRT_Y, STAM_IMG);
	dbSprite(STAM_SPRITE2, STAM_STRT_X2, STAM_STRT_Y2, STAM_IMG);
	dbSprite(CLOCK_SPRITE, CLOCK_STRT_X, CLOCK_STRT_Y, CLOCK_IMG);
	dbSprite(HERO_SPRITE2, HERO_STRT_X2,HERO_STRT_Y2, HERO_IMG2);
	


	dbSetSpritePriority(HERO_SPRITE, 4);
	dbSetSpritePriority(HERO_SPRITE2, 4);
	dbSetSpritePriority(HEALTH_BAR_SPRITE, 3);
	dbSetSpritePriority(END_LINE_SPRITE, 4);
	dbSetSpritePriority(END_LINE_SPRITE2, 4);
	dbSetSpritePriority(HORO_LINE_SPRITE, 8);
	dbSetSpritePriority(HORO_LINE_SPRITE2, 8);
	dbSetSpritePriority(CLOCK_SPRITE, 6);
	dbSetSpritePriority(FRNT_STAM_SPRITE2, 12);
	dbSetSpritePriority(FRNT_STAM_SPRITE, 12);
	dbSetSpritePriority(BACKGROUND_SPRITE, 1);
	dbSetSpritePriority(STAM_SPRITE, 5);
	dbSetSpritePriority(STAM_SPRITE2, 5);
	dbSetSpritePriority(BACK_STAM_SPRITE, 7);
	dbSetSpritePriority(GROUND1_SPRITE, 3);
	dbSetSpritePriority(BACK_STAM_SPRITE2, 7);

	dbSetSpriteAlpha(HEALTH_BAR_SPRITE, HEALTHBAR_TRANS_LEVEL);
	dbSetSpriteAlpha(STAM_SPRITE, 180);
	dbSetSpriteAlpha(STAM_SPRITE2, 180);
	return;
}




void detectCollision()
{

	dbSetSpriteImage(HERO_SPRITE2, 1);

	if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) == 1)
				{
					dbDeleteMusic(2);
				}


	if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 1)
			{
				dbPlaySprite(HERO_SPRITE, 5, 6, 150);
			}


	if(dbLeftKey() < 1 && dbRightKey() < 1 && dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) == 1 && dbDownKey() != 1 )
		{
			dbSetSpriteFrame(HERO_SPRITE, 1);
		}
	
	if(dbSpriteCollision(HERO_SPRITE, END_LINE_SPRITE))
		{
			dbRotateSprite(HERO_SPRITE,90);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);
		}

		if(dbSpriteCollision(HERO_SPRITE, END_LINE_SPRITE2))
		{
			dbRotateSprite(HERO_SPRITE,270);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);
		}

		
				if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 1)
		{
			dbRotateSprite(HERO_SPRITE,180);
			dbMoveSprite(HERO_SPRITE,8);
			dbRotateSprite(HERO_SPRITE,0);
		}

			


		if(dbUpKey() == 1)
		{
			if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) == 1)

			{
				dbMoveSprite(HERO_SPRITE, UP_SPD);
				dbLoadMusic("South Park - Timmy Freestyles.mp3", 2);
				dbPlayMusic(2);
			}

					
		}     



		if(dbLeftKey() == 1)
		{
			dbPlaySprite(HERO_SPRITE, 7, 8, 50);

			dbRotateSprite(HERO_SPRITE,270);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);

		}



		if(dbRightKey() == 1)
		{
			dbPlaySprite(HERO_SPRITE, 2, 3, 50);
			dbRotateSprite(HERO_SPRITE,90);
			dbMoveSprite(HERO_SPRITE,RGT_LFT_SPD);
			dbRotateSprite(HERO_SPRITE, 0);

		}



		if(dbDownKey() == 1 && dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 0)
			{
			
				dbPlaySprite(HERO_SPRITE, 9, 9, 100);
			
			if(dbSpriteCollision(HERO_SPRITE, GROUND2_SPRITE) != 1)
			{
			dbRotateSprite(HERO_SPRITE,180);
			dbMoveSprite(HERO_SPRITE, 1);
			dbRotateSprite(HERO_SPRITE, 0);
			}
			}


return;

}

void fightText()
{
	dbSetCursor(dbScreenWidth() / 2 - 100, dbScreenHeight() / 2 - 40);
	dbSetTextSize(42);
	dbSetTextToBoldItalic();
	dbInk(RED, GREEN);
	dbPrint("Fight");
	dbWait(1000);
	
	return;
}

void playMusic()
{
	dbPlayMusic(1);
	dbSetMusicVolume(1, 30);

	return;
}


void memoryLeak()
{

	for(int i = 1; i > 10; i++)
	{
	dbDeleteImage(i);
	dbDeleteSprite(i);
	dbDeleteSound(i);
	dbDeleteMusic(i);
	}
}