#pragma once

#define TEMP_ENTRY_POINT_FAKE		0x49d2a
#define TEMP_ENTRY_POINT			0xba0000
//GetModule -> dwSize : 		0x3516000


#define OFF_ENCRYPT_1				0x0000000
#define OFF_ENCRYPT_2				0x0000000


#define BASE_ANTI_ISSUE_ORDER       0x23a0ca0   //10c73a6	mov dword ptr ds:[23a0ca0],0
#define OFF_FUCKING_MOVE            0xca6278    //ca6278	BodyFunc	........
#define OFF_FUCKING_CAST            0xc5ccd4    //c5ccd4	BodyFunc	........

#define BASE                        0x3fba934   //10c739d	mov ecx, dword ptr ds:[3fba934]
#define BASE_SKILL                  0x2718eb4   //10c7f01	mov eax, dword ptr ds:[2718eb4]
#define BASE_ENDGAME                0x3fb4cf8   //df840c	mov eax, dword ptr ds:[3fb4cf8]

#define BASE_MAPDATA                0x3fcfb10   //13d8e70	mov ecx, dword ptr ds:[3fcfb10]
#define BASE_MAPDATA_2              0x3fcfb10   //13d86f8	mov edi, dword ptr ds:[3fcfb10]
#define BASE_TIME_DU_BI             0x27169B8   //dbb5ae	call ca5d00
#define BASE_OBJECT_ALL             0x2718e7c   //d6e4d4	mov ecx, dword ptr ds:[2718e7c]
#define BASE_RENDERER               0x3fd6cf8   //eaaa22	mov ecx, dword ptr ds:[3fd6cf8]
#define BASE_RENDERER_2             0x3fd6cf8   //f14d76	mov ecx, dword ptr ds:[3fd6cf8]

#define BASE_GAME_TIME_NOW_X        0x3FB36F4   		//db39ad	====<<UNKNOW COMMAND>>====
#define BASE_GAME_TIME1             0x2716938   //cf9cb4	mov ecx, dword ptr ds:[2716938]
#define GET_GAMETIME_FUNC           0x13ad300   //cf9cc0	call 13ad300

#define BASE_AttackableUnit         0x2719104   //d00865	mov esi, dword ptr ds:[2719104]
#define BASE_AttackableUnit_MAX     0x2719108   //d0085f	mov edi, dword ptr ds:[2719108]

#define BASE_HERO                   0x33652b4   //c8c69a	mov esi, dword ptr ds:[33652b4]
#define BASE_HERO_MAX               0x33652b8   //c8c692	mov edi, dword ptr ds:[33652b8]

//-----------------------------------
#define BASE_DDS_NEW                0x3fd55a8   //14430ce	mov eax, dword ptr ds:[3fd55a8]
#define GET_DDS_NEW_FUNC            0x1449040   //1475129	call 1449040
#define BASE_TEXTURE_DDS            0x3fcfb88   //13e62b3	push  dword ptr ds:[3fcfb88]				====<<ADDED CODE>>====
#define OFFSET_TEXTURE_DDS          0x80        		//d6c816	(8D) ====<<UNKNOW COMMAND>>====
//-----------------------GAME_DRAW_CIRCLE_FUNC: 47 83 C4 1C 3B 7C 24 20 (-B)
#define GAME_DRAW_CIRCLE_FUNC       0x1035a90   //1032d62	call 1035a90

#define HamChuaLuNay_CIRCLEMINIMAP  0x10f03c0   //11307fb	call 10f03c0
#define BASE_DRAW_CIRCLEMINIMAP     0x3fba92c   //113079f	mov eax, dword ptr ds:[3fba92c]
#define DRAWCIRCLEMINIMAP_OFFSET1   0xa0        //11307a4	mov ecx, dword ptr ds:[eax + a0]
#define DRAWCIRCLEMINIMAP_OFFSET2   0x14c       //10f04d9	mov eax, dword ptr ss:[ebp + 14c]
#define GAMEDRAW_CIRCLE_MiMAP_FUNC  0x10e1cd0   //10f058d	call 10e1cd0

#define DrawCircleChuaCanDung_FUNC  0x1036cd0   //10bb9dd	call 1036cd0
#define GAME_DRAW_LINE_FUNC         0x10372d0   //10bc59f	call 10372d0
#define GAME_DRAW_LINE_FUNC_222     0x1037510   //1034022	call 1037510

#define GET_WPOS_BAR_FUNC           0x10bf1f0   //10bf1f0	BodyFunc	........
#define WPOS_2_SPOS_FUNC            0x145aab0   //10bf218	call 145aab0
#define GAME_DRAW_2D_FUNC           0x1455cf0   //10d353d	call 1455cf0
#define DRAW_ICON2D_1_FUNC          0x1478680   //1455d2b	call 1478680
#define DRAW_ICON2D_2_FUNC          0x1478a70   //1455d5c	call 1478a70
#define DRAW_ICON2D_3_FUNC          0x1476fc0   //1455d8c	call 1476fc0
#define BASE_ICON2D                 0x3fcf940   //13c2703	mov ecx, dword ptr ds:[3fcf940]

#define WPOS2_SCREENMINI_FUNC       0x111de60   //10f5144	call 111de60
#define BASE_FOLDER_SOURCE          0x3fb3f28   //d6bf72	mov ecx, 3fb3f28
#define LOAD_FOLDER_SOURCE_OLD_FUNC 0xdd26e0    //d6bf77	call dd26e0
#define LOAD_FOLDER_SOURCE_FUNC     0xdd7fc0    //d29aaa	call dd7fc0

#define MODSKIN_FUNC                0xd742e0    //d742e0	BodyFunc	........
#define MODSKIN_FUNC_2              0xd742e0    //d60785	call d742e0
#define MODSKIN_HU1_FUNC            0xdd3a40    //118624d	call dd3a40
#define MODSKIN_HU2_FUNC            0xe43330    //d4b84a	call e43330

//-----------------------------------
#define ECX_SEND_CHAT               0x3fbb85c   //ec41f7	mov eax, dword ptr ds:[3fbb85c]
#define GET_PINGGAME_FUNC           0xec1ca0    //11a8929	call ec1ca0

#define BASE_IS_CHATTING            0x0         // ===========<<NOT FOUND>>===========

#define BASE_CHAT_SYS               0x2716768   //da9fd3	mov ecx, dword ptr ds:[2716768]
#define SEND_TEXT_SYSTEM_FUNC       0x109ebc0   //da9fda	call 109ebc0

//-----------------------------------
#define GET_PMOVE_FUNC              0xd48f80    //d5e54a	call d48f80
#define GET_CDBA_NEW_FUNC           0xd028a0    //d402d5	call d028a0

#define IS_OBJ_DELETED_FUNC         0xd0ffa0    //e3d45c	call d0ffa0
#define IS_HERO_FUNC                0xd7ba20    //e3feb5	call d7ba20
#define IS_MINION_FUNC              0xd7ba60    //e3fea1	call d7ba60
#define IS_TURRET_FUNC              0xd7bc10    //e3fec9	call d7bc10
#define IS_NEXUS_FUNC               0xd7b9a0    //e3fedd	call d7b9a0
#define IS_INHIBITOR_FUNC           0xd7b8a0    //e3fef1	call d7b8a0

#define IS_ALIVE_FUNC               0xd38980    //d38980	BodyFunc	........
#define BASE_DEVICE                 0x3fd91f8   //14a0c23	mov eax, dword ptr ds:[3fd91f8]

//-----------------------------------
#define GET_AA_DELAY_FUNC           0xe3bfd0    //d40311	call e3bfd0
#define GET_AA_DELAY_FUNC_2         0xe3bfd0    //da3815	call e3bfd0
#define GET_BASIC_ATTACK_FUNC       0xd64990    //d402fb	call d64990
#define GET_AA_ANIMATE_DELAY_FUNC   0xe3bee0    //d40305	call e3bee0
#define GET_AA_ANIMATE_DELAY_FUNC_2 0xe3bee0    //fc8523	call e3bee0

#define VMT_ONPROCESSSPELL_INDEX    0x70        //d301b7	call  dword ptr ds:[eax+70]					====<<ADDED CODE>>====
#define VMT_ONPROCESSSPELL_OFFSET   0x1028      //d301ba	mov eax, dword ptr ds:[esi + 1028]
#define VMT_ONCREAREMISSILE_INDEX   0x418       //1031d58	call  dword ptr ds:[eax+418]				====<<ADDED CODE>>====
#define VMT_ONCREAREMISSILE_OFFSET  0x0         // ===========<<NOT FOUND>>===========
#define VMT_ONPLAYANIMATION_INDEX   0x40c       //d3c8a6	call  dword ptr ds:[eax+40c]				====<<ADDED CODE>>====
#define VMT_ONPLAYANIMATION_OFFSET  0x0         // ===========<<NOT FOUND>>===========
//-----------------------------------
#define ON_PLAY_ANIMATION_FUNC      0x150f5d0   //150f5d0	BodyFunc	........
#define ON_DO_CAST_FUNC             0x0         		//101f7d6	====<<UNKNOW COMMAND>>====
#define ON_PROCESS_SPELL_FUNC       0x0         // ===========<<NOT FOUND>>===========
#define ON_CREATE_OBJ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define ON_DELETE_OBJ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define ON_UPDATE_BUFF_FUNC         0xfedae0    //fda458	call fedae0
#define ON_REMOVE_ADD_BUFF_FUNC     0x103bce0   //103bce0	BodyFunc	........
#define ON_NEW_PATH_FUNC            0x0         // ===========<<NOT FOUND>>===========

#define NAVMESH_CREATEPATH_FUNC     0x13d2730   //d5f271	call 13d2730
#define NAVMESH_SMOOTHPATH_FUNC     0xd76260    //d76260	BodyFunc	........

#define GET_OBJ_BY_NET_ID           0xd6e360    //fda42b	call d6e360
#define BASE_OBJ_BY_ID              0x27190e0   //cc0fff	mov ecx, 27190e0
#define GET_OBJ_BY_ID               0xcce850    //cc100a	call cce850

#define GET_BOUND_RADIUS_FUNC       0xd4a820    //d4a820	BodyFunc	........

#define Offset__pBuffs              0x0         // ===========<<NOT FOUND>>===========
#define Offset__pMax_Buffs          0x0         // ===========<<NOT FOUND>>===========
#define Offset__pMOVE               0x0         		//d11dd1	====<<UNKNOW COMMAND>>====
#define Offset__pNormalAttack       0x0         // ===========<<NOT FOUND>>===========
#define Offset__Enemy_ID            0x0         		//d11cfe	====<<UNKNOW COMMAND>>====
#define Offset__nBLOCK_MOVE         0x460       //10c8399	call  dword ptr ds:[eax+460]				====<<ADDED CODE>>====
#define Offset__nBar_Soucre         0x0         		//11b9e2b	====<<UNKNOW COMMAND>>====

#define EVENT_MOVE_TO_FUNC          0x10c7ec0   //10c7ec0	BodyFunc	........
#define RCLICK_MOVE_TO_FUNC         0x10d3920   //10c7f55	call 10d3920
#define MOVE_TO_FUNC                0xd11b20    //10c73b0	call d11b20
#define NORMAL_ATK_FUNC             0xd11b20    //d11b20	BodyFunc	........

#define CAN_SEE_FUNC                0xd389b0    //d389b0	BodyFunc	........
//-----------------------------------
#define CAST_SPELL_XYZ_FUNC         0x1028740   //10ce576	call 1028740
#define OFF_THIS_CAST_SPELL_XYZ     0x2ab0      		//10ce56c	(8D) ====<<UNKNOW COMMAND>>====
#define RELEASE_SPELL_XYZ_FUNC      0x102bc00   //10b94bc	call 102bc00
//-----------------------CAN_CASTSPELL2_FUNC: 51 6A 03 8B C8 (+0x5) -OldNotFound
#define CAN_CASTSPELL2_FUNC         0x101cf20   //10d72de	call 101cf20
//-----------------------------------
#define HACK_R_VELKOZ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define LEVELUP_SPELL_1_FUNC        0x10c6f00   //10de71c	call 10c6f00
#define LEVELUP_SPELL_2_FUNC        0x10c5520   //10de72f	call 10c5520
#define BUY_ITEM_FUNC               0x0         // ===========<<NOT FOUND>>===========
#define OFF_THIS_BUY_ITEM           0x0         // ===========<<NOT FOUND>>===========
#define SELL_ITEM_FUNC              0x0         // ===========<<NOT FOUND>>===========
#define OFF_THIS_SELL_ITEM          0x0         // ===========<<NOT FOUND>>===========

//-------------------||----------------||-------------------|
#define NEXUS                       0x0         // ===========<<NOT FOUND>>===========
#define INHIBITOR                   0x0         // ===========<<NOT FOUND>>===========
#define BASE_DIRECTION              0x0         		//d6c883	====<<UNKNOW COMMAND>>====
#define GET_TEXTURE_GAME_FUNC       0x0         // ===========<<NOT FOUND>>===========
#define GET_BAR_DETAIL_FUNC         0x0         // ===========<<NOT FOUND>>===========
#define CHAT_TO_PLAYER_FUNC         0x0         // ===========<<NOT FOUND>>===========
#define POS2CELL_FUNC               0x0         // ===========<<NOT FOUND>>===========
#define CAN_CASTSPELL_FUNC          0x0         // ===========<<NOT FOUND>>===========
