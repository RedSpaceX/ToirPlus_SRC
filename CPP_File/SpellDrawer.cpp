#include "SpellDrawer.h"
#include "Spell.h"
#include "Evade.h"

extern KLanguage*	 pLang;

extern SpellDetector*		_SpellDetector;
extern Evade*				_Evade;

extern int  rengar_ring;
extern bool DodgeSkillShots_menu, DodgeOnlyOnComboKeyEnabled_menu, DontDodgeKeyEnabled_menu;
extern int  DodgeComboKey_menu, DontDodgeKey_menu;
extern bool DrawSkillShots_menu, DrawEvadePosition_menu,ShowStatus_menu, DrawSpellPos_menu;
extern int  LowWidth_menu, LowColor_menu, NormalWidth_menu, NormalColor_menu, HighWidth_menu, HighColor_menu, ExtremeWidth_menu, ExtremeColor_menu;

extern int skillshot_Rectangle_base_r01_v01, skillshot_Rectangle_tip_r01_v01, /*Reticle_Gradient_Base_Q_01,*/ MinimapCircularRangeIndicator, ShockWave;

////////-------------------------------------------------//-----------------------//----------
////void DrawLine_Long(float x1, float y1, float x2, float y2, float nWidth, DWORD nColor, IDirect3DDevice9* pDev)
////{
////	LPD3DXLINE line;
////	D3DXCreateLine(pDev, &line);
////	D3DXVECTOR2 lines[] = {D3DXVECTOR2(x1, y1), D3DXVECTOR2(x2, y2)};
////	line->SetWidth(nWidth);
////	line->SetAntialias( true );
////	line->SetGLLines( true );
////	line->Begin();
////	line->Draw(lines, 2, nColor);
////	line->End();
////	line->Release();
////}

//-------------------------------------------------//-----------------------//----------
void DrawLineRectangle(Vec3D start, Vec3D end, float radius, float width, D3DCOLOR color)
{
	Vec3D dir  = (end - start).Normalized();
	Vec3D pDir = Perpendicular(dir);

	Vec3D rightStartPos = start + pDir * radius;
	Vec3D leftStartPos  = start - pDir * radius;
	Vec3D rightEndPos   = end   + pDir * radius;
	Vec3D leftEndPos    = end   - pDir * radius;
	
	KPos rStartPos, worldPos_1;		//for rightStartPos
	worldPos_1.x = rightStartPos.x; 
	worldPos_1.y = rightStartPos.y; 
	worldPos_1.z = rightStartPos.z;
	WorldPos_to_ScreenPos(&worldPos_1, &rStartPos);
	
	KPos lStartPos, worldPos_2;		//for leftStartPos
	worldPos_2.x = leftStartPos.x; 
	worldPos_2.y = leftStartPos.y; 
	worldPos_2.z = leftStartPos.z;
	WorldPos_to_ScreenPos(&worldPos_2, &lStartPos);

	KPos rEndPos, worldPos_3;		//for rightEndPos
	worldPos_3.x = rightEndPos.x; 
	worldPos_3.y = rightEndPos.y; 
	worldPos_3.z = rightEndPos.z;
	WorldPos_to_ScreenPos(&worldPos_3, &rEndPos);

	KPos lEndPos, worldPos_4;		//for leftEndPos
	worldPos_4.x = leftEndPos.x; 
	worldPos_4.y = leftEndPos.y; 
	worldPos_4.z = leftEndPos.z;
	WorldPos_to_ScreenPos(&worldPos_4, &lEndPos);
	
	float rangeSpell = Distance(start, end);
	if (  rangeSpell < 3500)
	{
		DrawLine_1(rStartPos.x, rStartPos.y, rEndPos.x  , rEndPos.y  , width, color, Get_Device());
		DrawLine_1(lStartPos.x, lStartPos.y, lEndPos.x  , lEndPos.y  , width, color, Get_Device());
		DrawLine_1(rStartPos.x, rStartPos.y, lStartPos.x, lStartPos.y, width, color, Get_Device());
		DrawLine_1(lEndPos.x  , lEndPos.y  , rEndPos.x  , rEndPos.y  , width, color, Get_Device());
	}
	else
	{
		GameDrawLineMissile_2(start, end, rangeSpell, radius + 20, skillshot_Rectangle_base_r01_v01, skillshot_Rectangle_tip_r01_v01);

		//GameDrawLineMissile_2(start, end, rangeSpell, radius, skillshot_Rectangle_tip_r01_v01, skillshot_Rectangle_base_r01_v01);
	}
}

//-------------------------------------------------//-----------------------//----------
void DrawLineTriangle(Vec3D start, Vec3D end, float radius, float width, D3DCOLOR color)
{
	if(start.y == 0 && end.y != 0) start.y = end.y;
	if(start.y != 0 && end.y == 0) end.y   = start.y;

	Vec3D dir = (end - start).Normalized();
	Vec3D pDir = Perpendicular(dir);

	Vec3D initStartPos = start + dir;
	Vec3D rightEndPos  = end + pDir * radius;
	Vec3D leftEndPos   = end - pDir * radius;

	KPos iStartPos, worldPos_1;		
	worldPos_1.x = initStartPos.x; 
	worldPos_1.y = initStartPos.y; 
	worldPos_1.z = initStartPos.z;
	WorldPos_to_ScreenPos(&worldPos_1, &iStartPos);
	//--//var iStartPos = Drawing.WorldToScreen(new Vector3(initStartPos.X, initStartPos.Y, myHero.Position.Z));

	KPos rEndPos, worldPos_2;		
	worldPos_2.x = rightEndPos.x; 
	worldPos_2.y = rightEndPos.y; 
	worldPos_2.z = rightEndPos.z;
	WorldPos_to_ScreenPos(&worldPos_2, &rEndPos);
	//--//var rEndPos = Drawing.WorldToScreen(new Vector3(rightEndPos.X, rightEndPos.Y, myHero.Position.Z));

	KPos lEndPos, worldPos_3;		
	worldPos_3.x = leftEndPos.x; 
	worldPos_3.y = leftEndPos.y; 
	worldPos_3.z = leftEndPos.z;
	WorldPos_to_ScreenPos(&worldPos_3, &lEndPos);
	//--//var lEndPos = Drawing.WorldToScreen(new Vector3(leftEndPos.X, leftEndPos.Y, myHero.Position.Z));
	

	DrawLine_1(iStartPos.x, iStartPos.y, rEndPos.x  , rEndPos.y  , width, color, Get_Device());
	DrawLine_1(iStartPos.x, iStartPos.y, lEndPos.x  , lEndPos.y  , width, color, Get_Device());
	DrawLine_1(rEndPos.x  , rEndPos.y  , lEndPos.x  , lEndPos.y  , width, color, Get_Device());


	//--//Drawing.DrawLine(iStartPos, rEndPos, width, color);
	//--//Drawing.DrawLine(iStartPos, lEndPos, width, color);
	//--//Drawing.DrawLine(rEndPos, lEndPos, width, color);
}

//-------------------------------------------------//-----------------------//----------
void DrawEvadeStatus()
{
	KNpc* myHero = GetPlayer();
	if(!myHero) return;

	if (ShowStatus_menu)
	{
		KPos heroPosOut, worldPos;		//for leftEndPos
		worldPos = myHero->CurrentPos;
		WorldPos_to_ScreenPos(&worldPos, &heroPosOut);

		Vec3D heroPos(heroPosOut.x, heroPosOut.y, heroPosOut.z);
		float dimension = 26.0f;
		
		//if(pLang->isEvade == true) PrintText("OldEvade : ON", 14 , sz__Arial, heroPos.x - dimension, heroPos.y + 1.69f*dimension, heroPos.x, heroPos.y, WHITE,  Get_Device());
		//else					   PrintText("OldEvade : OFF", 14, sz__Arial, heroPos.x - dimension, heroPos.y + 1.69f*dimension, heroPos.x, heroPos.y, GREY ,  Get_Device());


		if (DodgeSkillShots_menu)
		{
			if (_Evade->isDodging)
			{
				PrintTextBold("Evade : ON", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_RED_Nhat,  Get_Device());
			}
			else
			{
				if (DodgeOnlyOnComboKeyEnabled_menu == true && !(GetAsyncKeyState(DodgeComboKey_menu) & 0x8000))
				{
					PrintTextBold("Evade : OFF", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_GREY,  Get_Device());
				}
				else
				{
					if (DontDodgeKeyEnabled_menu == true && (GetAsyncKeyState(DontDodgeKey_menu) & 0x8000))
						PrintTextBold("Evade : OFF", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_GREY,  Get_Device());
					else if (isDodgeDangerousEnabled())
						PrintTextBold("Evade : ON", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_YELLOW_Nhat,  Get_Device());
					else
						PrintTextBold("Evade : ON", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_GREEN_BLUE,  Get_Device());
				}
			}
		}
		else
		{
			/*if (ObjectCache.menuCache.cache["ActivateEvadeSpells"].GetValue<KeyBind>().Active)
			{
				if (ObjectCache.menuCache.cache["DodgeOnlyOnComboKeyEnabled"].GetValue<bool>() == true
					&& ObjectCache.menuCache.cache["DodgeComboKey"].GetValue<KeyBind>().Active == false)
				{
					Drawing.DrawText(heroPos.X - dimension.Width / 2, heroPos.Y, Color.Gray, "Evade: OFF");
				}
				else
				{
					if (Evade.isDodgeDangerousEnabled())
						Drawing.DrawText(heroPos.X - dimension.Width / 2, heroPos.Y, Color.Yellow, "Evade: Spell");
					else
						Drawing.DrawText(heroPos.X - dimension.Width / 2, heroPos.Y, Color.DeepSkyBlue, "Evade: Spell");
				}
			}
			else*/
			{
				PrintTextBold("Evade : OFF", 16, sz__Arial, heroPos.x - dimension, heroPos.y + dimension, heroPos.x, heroPos.y, x_GREY,  Get_Device());
			}
		}
	}
}

//-------------------------------------------------//-----------------------//----------
DWORD GetColorSpell(int dangerlevel)
{
	DWORD result = WHITE;
	int							temp = LowColor_menu;			//Low
	if		(dangerlevel == 1)	temp = NormalColor_menu;		//Normal
	else if (dangerlevel == 2)	temp = HighColor_menu;			//High
	else if (dangerlevel >= 3)	temp = ExtremeColor_menu;		//Extreme

	//WHITE		GREEN		GREY	   RED	   YELLOW	   ORANGE	   BLUE	   PURPLE   BLACK	WHITE_1		WHITE_2	
	if		(temp == 0)	result = WHITE;
	else if (temp == 1)	result = GREEN;
	else if (temp == 2)	result = GREY;
	else if (temp == 3)	result = RED;
	else if (temp == 4)	result = YELLOW;
	else if (temp == 5)	result = ORANGE;
	else if (temp == 6)	result = BLUE;
	else if (temp == 7)	result = PURPLE;
	else if (temp == 8)	result = BLACK;
	else if (temp == 9)	result = WHITE_1;
	else if (temp == 10)result = WHITE_2;
	
	return result;
}


//-------------------------------------------------//-----------------------//----------
Vec3D GetCurrentSpellPosition_forDrawingSpell(Spell &spell, bool allowNegative, float delay, float extraDistance)
{
	Vec3D spellPos = spell.startPos;

	KNpc* myHero = GetPlayer();
	if(!myHero) return spellPos;

	if (spell.info.updatePosition == false)
	{
		return spellPos;
	}

	if (spell.spellType == Line || spell.spellType == Arc_x)
	{
		float spellTime = (float)GetTickCount() - spell.startTime -  spell.info.spellDelay - max(0, spell.info.extraEndTime);

		if (spell.info.projectileSpeed == FLT_MAX)
		{
			return spell.startPos;
		}

		if (spell.spellObject == 0 && spellTime >= 0)
		{
			spellPos = spell.startPos + spell.direction * spell.info.projectileSpeed * (spellTime / 1000);
		}
	}
	else if (spell.spellType == Circular || spell.spellType == Cone)
	{
		spellPos = spell.endPos;
	}

	if ( spell.spellObject != 0 && IsValidObj(spell.spellObject) /*&& spell.spellObject.IsVisible*/ &&	//ko check ddc IsVisible cua Missile
		Distance_2D(spell.spellObject->CurrentPos, myHero->CurrentPos) < spell.info.range + 1000 )
	{
		spellPos = spell.spellObject->currentPos();		
	}

	if (delay > 0 && spell.info.projectileSpeed != FLT_MAX && spell.spellType == Line)
	{
		spellPos = spellPos + spell.direction * spell.info.projectileSpeed * (delay / 1000);
		//__oMsg("-----[2] spellPos: %f, %f, %f", spellPos.x, spellPos.y, spellPos.z);
	}

	if (extraDistance > 0 && spell.info.projectileSpeed != FLT_MAX
		&& spell.spellType == Line)
	{
		spellPos = spellPos + spell.direction * extraDistance;
	}

	return spellPos;
}

//-------------------------------------------------//-----------------------//----------
void OnDraw_SpellDrawer()	//*********
{
	if(!pLang->isDrawingOnOff) return;

	//KNpc* enemy = SearchNearestNPC(3000);
	//if(enemy)
	//{
	//	//ProjectionInfo proJ = ProjectOn(enemy->currentPos(), mousePosVec3D(), GetPlayer()->currentPos());
	//	//Draw2DCircle(proJ.SegmentPoint, 5, WHITE);
	//	//Draw2DCircle(proJ.LinePoint, 5, RED);
	//	//__oMsg("isSerment: %d, %.3f (%.3f, %.3f, %.3f) (%.3f, %.3f, %.3f)", proJ.IsOnSegment, proJ.SegmentPoint.Distance2D(enemy->currentPos()), proJ.SegmentPoint.x, proJ.SegmentPoint.y, proJ.SegmentPoint.z, proJ.LinePoint.x, proJ.LinePoint.y, proJ.LinePoint.z);

	//}


	///*KPos pos2D, mousePos;	
	//mousePos = mousePosKpos();
	//WorldPos_to_ScreenPos(&mousePos, &pos2D);

	//__oMsg("mouse: %.3f, %.3f, %.3f  - pos2D: %.3f, %.3f, %.3f", mousePos.x, mousePos.y, mousePos.z, pos2D.x, pos2D.y, pos2D.z);*/

	////Vec3D test1(2420.298, 93.376, 85.536);
	//Vec3D exPos = Extend(GetPlayer()->currentPos(), mousePosVec3D(), Distance(GetPlayer()->currentPos(), mousePosVec3D()) + 3500);
	//DrawLineRectangle(GetPlayer()->currentPos(), exPos, 150, 1, YELLOW);

	//KPos pos2D;	
	//KPos exPosKpos(exPos.x, exPos.y, exPos.z);
	//WorldPos_to_ScreenPos(&exPosKpos, &pos2D);
	//__oMsg("mouse: %.3f, %.3f, %.3f  - pos2D: %.3f, %.3f, %.3f", exPos.x, exPos.y, exPos.z, pos2D.x, pos2D.y, pos2D.z);



    if (DrawEvadePosition_menu)
    {
        if (_Evade->lastPosInfo != 0)
        {
            Vec3D pos = _Evade->lastPosInfo->position; //Evade.lastEvadeCommand.targetPosition;
			GameDrawCircle(pos, 25, MinimapCircularRangeIndicator, x_GREEN);
			////Draw2DCircle(pos, 8, RED);
        }
    }

    DrawEvadeStatus();

    if (DrawSkillShots_menu == false)
    {
        return;
    }
	
	//////int sizeBefore = (int)_SpellDetector->detectedSpells->size();
	//////for (std::map<int, Spell>::iterator it = _SpellDetector->detectedSpells->begin(); it!= _SpellDetector->detectedSpells->end(); ++it)
	//////{
	//////	if ((int)_SpellDetector->detectedSpells->size() != sizeBefore) break;

	int sizeBefore = (int)_SpellDetector->drawSpells->size();
	for (std::map<int, Spell>::iterator it = _SpellDetector->drawSpells->begin(); it!= _SpellDetector->drawSpells->end(); ++it)
	{
		if ((int)_SpellDetector->drawSpells->size() != sizeBefore) break;

		Spell spell = it->second;
		//__oMsg("discccc = %f, %f, %f, %f", Distance(spell.currentSpellPosition, spell.endPos), Distance(spell.startPos, spell.endPos), Distance(spell.startPos_2, spell.endPos), Distance(spell.startPos, GetPlayer()->currentPos()));
		float spellDrawingWidth  = 1.0f;
		DWORD spellColor		 = WHITE;

		int	  dangerlevel		 = spell.info.dangerlevel - 1;
		bool  isDrawSpell_inMenu = true;
		for (std::map<std::string, SpellData>::iterator it_xxx=_SpellDetector->onProcessSpells->begin(); it_xxx!=_SpellDetector->onProcessSpells->end(); ++it_xxx)
		{
			if(spell.info.spellName.compare(it_xxx->second.sSetting.key_spell) == 0)
			{
				int danger_xx = it_xxx->second.sSetting.DangerLevel;	//danger in menu_comboBox
				dangerlevel	= danger_xx;

				isDrawSpell_inMenu = it_xxx->second.sSetting.DrawSpell;
				break;
			}
		}	
		spellColor = GetColorSpell(dangerlevel);

		if		(dangerlevel == 0)	spellDrawingWidth = (float)LowWidth_menu;		//Low
		else if (dangerlevel == 1)	spellDrawingWidth = (float)NormalWidth_menu;	//Normal
		else if (dangerlevel == 2)	spellDrawingWidth = (float)HighWidth_menu;		//High
		else if (dangerlevel >= 3)	spellDrawingWidth = (float)ExtremeWidth_menu;	//Extreme
	
		//-//var avoidRadius		 = ObjectCache.menuCache.cache["ExtraAvoidDistance"].GetValue<Slider>().Value;		//-->ko thay lam gi ca
        if (isDrawSpell_inMenu)
        {
			//bool canEvade1 = !_Evade->devModeOn;

			bool tmp1 = _Evade->lastPosInfo != 0;
			bool tmp2 = false;
			
			if(tmp1)
			{
				std::vector<int>::iterator it_x = find (_Evade->lastPosInfo->undodgeableSpells->begin(), _Evade->lastPosInfo->undodgeableSpells->end(), spell.spellID);
				if(it_x != _Evade->lastPosInfo->undodgeableSpells->end())
				{
					tmp2 = true;
				}
			}
			bool canEvade2 = !(tmp1 && tmp2);
			
			//-//bool canEvade = !(Evade.lastPosInfo != null && Evade.lastPosInfo.undodgeableSpells.Contains(spell.spellID)) || !Evade.devModeOn;
			bool canEvade = canEvade2 /*|| canEvade1*/;
			
            if (spell.spellType == Line)
            {
				Vec3D spellPos    = GetCurrentSpellPosition_forDrawingSpell(spell, false, 0, 0);
                Vec3D spellEndPos = GetSpellEndPosition(spell);

				////__oMsg("Ngoai : %.3f, %.3f, %.3f [%.3f, %.3f, %.3f]", spellPos.x, spellPos.y, spellPos.z, spellEndPos.x, spellEndPos.y, spellEndPos.z);

				//DrawLineRectangle(spellPos, spellEndPos, spell.radius, spellDrawingWidth, !canEvade ? YELLOW : spellColor);

				float rangeSpell = Distance(spell.startPos, spellEndPos);
				float rangeDraw  = Distance(spellPos, spellEndPos);
				float drawMoreRadius = 20;
			
				if		(spell.radius <  70) drawMoreRadius = 20;
				else if (spell.radius <  80) drawMoreRadius = 25 + 5;
				else if (spell.radius < 100) drawMoreRadius = 30 + 5;
				else if (spell.radius < 120) drawMoreRadius = 35 + 5;
				else if (spell.radius < 140) drawMoreRadius = 40 + 5;
				else if (spell.radius < 160) drawMoreRadius = 45 + 5;
				else if (spell.radius < 180) drawMoreRadius = 50 + 5;
				else if (spell.radius < 200) drawMoreRadius = 55 + 5;
				else if (spell.radius < 220) drawMoreRadius = 60 + 5;
				else						 drawMoreRadius = 70 + 5;
				
				//GameDrawLineMissile_2( spellPos, spellEndPos, rangeDraw, spell.radius + drawMoreRadius, skillshot_Rectangle_base_r01_v01, skillshot_Rectangle_tip_r01_v01);
				
				GameDrawLineMissile_2( spell.startPos, spellEndPos, rangeSpell, spell.radius + drawMoreRadius, skillshot_Rectangle_base_r01_v01, skillshot_Rectangle_tip_r01_v01);

                if (DrawSpellPos_menu)	//-// && spell.spellObject != null)
                {
					GameDrawCircle(spellPos, spell.radius + 5, ShockWave, !canEvade ? YELLOW : spellColor);
					////Draw2DCircle(spellPos, spell.radius/3.5f, !canEvade ? YELLOW : spellColor);
                }
            }
            else if (spell.spellType == Circular)
            {
				int pTextureCircle = rengar_ring;
				if (spell.radius < 250) pTextureCircle = ShockWave;

				KPos pos(spell.endPos.x, spell.endPos.y, spell.endPos.z);

				GameDrawCircle(&pos, spell.radius, pTextureCircle, !canEvade ? YELLOW : spellColor);
                //-//Render.Circle.DrawCircle(new Vector3(spell.endPos.X, spell.endPos.Y, spell.height), (int) spell.radius, !canEvade ? Color.Yellow : spellDrawingConfig.Color, spellDrawingWidth);

                if (spell.info.spellName == "VeigarEventHorizon")
                {
					GameDrawCircle(spell.endPos, spell.radius + 10 - 125, rengar_ring, !canEvade ? YELLOW : spellColor);
                    //-//Render.Circle.DrawCircle(new Vector3(spell.endPos.X, spell.endPos.Y, spell.height), (int) spell.radius - 125, !canEvade ? Color.Yellow : spellDrawingConfig.Color, spellDrawingWidth);
                }
                else if (spell.info.spellName == "DariusCleave")
                {
					GameDrawCircle(spell.endPos, spell.radius + 10 - 220, rengar_ring, !canEvade ? YELLOW : spellColor);
                    //-//Render.Circle.DrawCircle(new Vector3(spell.endPos.X, spell.endPos.Y, spell.height), (int) spell.radius - 220, !canEvade ? Color.Yellow : spellDrawingConfig.Color, spellDrawingWidth);
                }
            }
            else if (spell.spellType == Arc_x)	// ko thay no dung` code
            {
                //-///*var spellRange = spell.startPos.Distance(spell.endPos);
                //-//var midPoint = spell.startPos + spell.direction * (spellRange / 2);

                //-//Render.Circle.DrawCircle(new Vector3(midPoint.X, midPoint.Y, myHero.Position.Z), (int)spell.radius, spellDrawingConfig.Color, spellDrawingWidth);
                //-//
                //-//Drawing.DrawLine(Drawing.WorldToScreen(spell.startPos.To3D()),
                //-//                 Drawing.WorldToScreen(spell.endPos.To3D()), 
                //-//                 spellDrawingWidth, spellDrawingConfig.Color);*/
            }
            else if (spell.spellType == Cone)
            {
                DrawLineTriangle(spell.startPos, spell.endPos, spell.radius, spellDrawingWidth, !canEvade ? YELLOW : spellColor);
            }
        }
	}
}