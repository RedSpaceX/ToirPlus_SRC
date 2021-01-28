#pragma once

#define TEMP_ENTRY_POINT_FAKE		0x49d2a
#define TEMP_ENTRY_POINT			0x4a0000
//GetModule -> dwSize : 		0x34d6000


#define OFF_ENCRYPT_1				0x0000000
#define OFF_ENCRYPT_2				0x0000000


#define OFF_FUCKING_MOVE            0x5a5438    //5a5438	BodyFunc	........
#define OFF_FUCKING_CAST            0x55bdc4    //55bdc4	BodyFunc	........

#define BASE                        0x387e098   //9a265d	mov ecx, dword ptr ds:[387e098]
#define BASE_SKILL                  0x1fdc858   //9a35a1	mov eax, dword ptr ds:[1fdc858]
#define BASE_ENDGAME                0x38786f8   //6f304c	mov eax, dword ptr ds:[38786f8]

#define BASE_MAPDATA                0x3893010   //ca2460	mov ecx, dword ptr ds:[3893010]
#define BASE_MAPDATA_2              0x3893010   //ca1ce8	mov edi, dword ptr ds:[3893010]
#define BASE_TIME_DU_BI             0x1FDA3B8   //6a49be	call 5a4eb0
#define BASE_OBJECT_ALL             0x2c28eec   //66b9a4	mov ecx, dword ptr ds:[2c28eec]
#define BASE_RENDERER               0x389a288   //7a2de2	mov ecx, dword ptr ds:[389a288]
#define BASE_RENDERER_2             0x389a288   //80c5a6	mov ecx, dword ptr ds:[389a288]

#define BASE_GAME_TIME_NOW_X        0x3877014   		//69e40d	====<<UNKNOW COMMAND>>====
#define BASE_GAME_TIME1             0x1fda338   //5f81f4	mov ecx, dword ptr ds:[1fda338]
#define GET_GAMETIME_FUNC           0xc774d0    //5f8200	call c774d0

#define BASE_AttackableUnit         0x1fdcafc   //5fede5	mov esi, dword ptr ds:[1fdcafc]
#define BASE_AttackableUnit_MAX     0x1fdcb00   //5feddf	mov edi, dword ptr ds:[1fdcb00]

#define BASE_HERO                   0x2c28cac   //58218a	mov esi, dword ptr ds:[2c28cac]
#define BASE_HERO_MAX               0x2c28cb0   //582182	mov edi, dword ptr ds:[2c28cb0]

//-----------------------------------
#define BASE_DDS_NEW                0x3898b28   //d0c7ae	mov eax, dword ptr ds:[3898b28]
#define GET_DDS_NEW_FUNC            0xd12700    //d3e899	call d12700
#define BASE_TEXTURE_DDS            0x389310c   //caf8e3	push  dword ptr ds:[389310c]				====<<ADDED CODE>>====
#define OFFSET_TEXTURE_DDS          0x80        		//669786	(8D) ====<<UNKNOW COMMAND>>====
//-----------------------GAME_DRAW_CIRCLE_FUNC: 47 83 C4 1C 3B 7C 24 20 (-B)
#define GAME_DRAW_CIRCLE_FUNC       0x912d20    //90fff2	call 912d20

#define HamChuaLuNay_CIRCLEMINIMAP  0x9913f0    //a0764b	call 9913f0
#define BASE_DRAW_CIRCLEMINIMAP     0x387e09c   //a075ef	mov eax, dword ptr ds:[387e09c]
#define DRAWCIRCLEMINIMAP_OFFSET1   0xa0        //a075f4	mov ecx, dword ptr ds:[eax + a0]
#define DRAWCIRCLEMINIMAP_OFFSET2   0x14c       //991509	mov eax, dword ptr ss:[ebp + 14c]
#define GAMEDRAW_CIRCLE_MiMAP_FUNC  0x983050    //9915bd	call 983050

#define DrawCircleChuaCanDung_FUNC  0x913f60    //99557d	call 913f60
#define GAME_DRAW_LINE_FUNC         0x914560    //996362	call 914560
#define GAME_DRAW_LINE_FUNC_222     0x9147a0    //9112c8	call 9147a0

#define GET_WPOS_BAR_FUNC           0x999f90    //999f90	BodyFunc	........
#define WPOS_2_SPOS_FUNC            0xd242f0    //999fb8	call d242f0
#define GAME_DRAW_2D_FUNC           0xd1f480    //9aefed	call d1f480
#define DRAW_ICON2D_1_FUNC          0xd41db0    //d1f4bb	call d41db0
#define DRAW_ICON2D_2_FUNC          0xd421b0    //d1f4ec	call d421b0
#define DRAW_ICON2D_3_FUNC          0xd406d0    //d1f51c	call d406d0
#define BASE_ICON2D                 0x3892ec8   //c8bd73	mov ecx, dword ptr ds:[3892ec8]

#define WPOS2_SCREENMINI_FUNC       0x9b9450    //997434	call 9b9450
#define BASE_FOLDER_SOURCE          0x38779b0   //668ee2	mov ecx, 38779b0
#define LOAD_FOLDER_SOURCE_OLD_FUNC 0x6ea6f0    //668ee7	call 6ea6f0
#define LOAD_FOLDER_SOURCE_FUNC     0x6f0710    //62654a	call 6f0710

#define MODSKIN_FUNC                0x671ca0    //671ca0	BodyFunc	........
#define MODSKIN_FUNC_2              0x671ca0    //65d655	call 671ca0
#define MODSKIN_HU1_FUNC            0x6eb090    //a5c15d	call 6eb090
#define MODSKIN_HU2_FUNC            0x744410    //647a2a	call 744410

//-----------------------------------
#define ECX_SEND_CHAT               0x387f260   //7bc49e	mov eax, dword ptr ds:[387f260]
#define GET_PINGGAME_FUNC           0x7b9e50    //a7da39	call 7b9e50

#define BASE_IS_CHATTING            0x0         // ===========<<NOT FOUND>>===========

#define BASE_CHAT_SYS               0x1fda180   //695973	mov ecx, dword ptr ds:[1fda180]
#define SEND_TEXT_SYSTEM_FUNC       0x976e00    //69597a	call 976e00

//-----------------------------------
#define GET_PMOVE_FUNC              0x644c30    //65b8aa	call 644c30
#define GET_CDBA_NEW_FUNC           0x600e00    //63ca05	call 600e00

#define IS_OBJ_DELETED_FUNC         0x60c990    //73b14c	call 60c990
#define IS_HERO_FUNC                0x679410    //73ee55	call 679410
#define IS_MINION_FUNC              0x679450    //73ee41	call 679450
#define IS_TURRET_FUNC              0x679600    //73ee69	call 679600
#define IS_NEXUS_FUNC               0x679390    //73ee7d	call 679390
#define IS_INHIBITOR_FUNC           0x679290    //73ee91	call 679290

#define IS_ALIVE_FUNC               0x635060    //635060	BodyFunc	........
#define BASE_DEVICE                 0x389c780   //d6a1b3	mov eax, dword ptr ds:[389c780]

//-----------------------------------
#define GET_AA_DELAY_FUNC           0x739cc0    //63ca41	call 739cc0
#define GET_AA_DELAY_FUNC_2         0x739cc0    //692a45	call 739cc0
#define GET_BASIC_ATTACK_FUNC       0x661940    //63ca2b	call 661940
#define GET_AA_ANIMATE_DELAY_FUNC   0x739bd0    //63ca35	call 739bd0
#define GET_AA_ANIMATE_DELAY_FUNC_2 0x739bd0    //8c2433	call 739bd0

#define VMT_ONPROCESSSPELL_INDEX    0x70        //62cc77	call  dword ptr ds:[eax+70]					====<<ADDED CODE>>====
#define VMT_ONPROCESSSPELL_OFFSET   0x1028      //62cc7a	mov eax, dword ptr ds:[esi + 1028]
#define VMT_ONCREAREMISSILE_INDEX   0x414       //8fb39c	call  dword ptr ds:[eax+414]				====<<ADDED CODE>>====
#define VMT_ONCREAREMISSILE_OFFSET  0x0         // ===========<<NOT FOUND>>===========
#define VMT_ONPLAYANIMATION_INDEX   0x408       //638fa6	call  dword ptr ds:[eax+408]				====<<ADDED CODE>>====
#define VMT_ONPLAYANIMATION_OFFSET  0x0         // ===========<<NOT FOUND>>===========
//-----------------------------------
#define ON_PLAY_ANIMATION_FUNC      0xdd8960    //dd8960	BodyFunc	........
#define ON_DO_CAST_FUNC             0x0         		//8fd806	====<<UNKNOW COMMAND>>====
#define ON_PROCESS_SPELL_FUNC       0x0         // ===========<<NOT FOUND>>===========
#define ON_CREATE_OBJ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define ON_DELETE_OBJ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define ON_UPDATE_BUFF_FUNC         0x8d6a20    //8ceb68	call 8d6a20
#define ON_REMOVE_ADD_BUFF_FUNC     0x9057c0    //9057c0	BodyFunc	........
#define ON_NEW_PATH_FUNC            0x0         // ===========<<NOT FOUND>>===========

#define NAVMESH_CREATEPATH_FUNC     0xc9bd90    //65c5c1	call c9bd90
#define NAVMESH_SMOOTHPATH_FUNC     0x673c10    //673c10	BodyFunc	........

#define GET_OBJ_BY_NET_ID           0x66b830    //8ceb3b	call 66b830
#define BASE_OBJ_BY_ID              0x1fdcad8   //5bfb1f	mov ecx, 1fdcad8
#define GET_OBJ_BY_ID               0x5cd140    //5bfb2a	call 5cd140

#define GET_BOUND_RADIUS_FUNC       0x646a00    //646a00	BodyFunc	........

#define Offset__pBuffs              0x0         // ===========<<NOT FOUND>>===========
#define Offset__pMax_Buffs          0x0         // ===========<<NOT FOUND>>===========
#define Offset__pMOVE               0x0         		//60e7b1	====<<UNKNOW COMMAND>>====
#define Offset__pNormalAttack       0x0         // ===========<<NOT FOUND>>===========
#define Offset__Enemy_ID            0x0         		//60e6de	====<<UNKNOW COMMAND>>====
#define Offset__nBLOCK_MOVE         0x45c       //9a3a39	call  dword ptr ds:[eax+45c]				====<<ADDED CODE>>====
#define Offset__nBar_Soucre         0x0         		//a8f30b	====<<UNKNOW COMMAND>>====

#define EVENT_MOVE_TO_FUNC          0x9a3560    //9a3560	BodyFunc	........
#define RCLICK_MOVE_TO_FUNC         0x9af3d0    //9a35f5	call 9af3d0
#define MOVE_TO_FUNC                0x60e500    //9a2670	call 60e500
#define NORMAL_ATK_FUNC             0x60e500    //60e500	BodyFunc	........

#define CAN_SEE_FUNC                0x635090    //635090	BodyFunc	........
//-----------------------------------
#define CAST_SPELL_XYZ_FUNC         0x904e50    //9a9f16	call 904e50
#define OFF_THIS_CAST_SPELL_XYZ     0x2ab0      		//9a9f0c	(8D) ====<<UNKNOW COMMAND>>====
#define RELEASE_SPELL_XYZ_FUNC      0x908150    //992cfc	call 908150
//-----------------------CAN_CASTSPELL2_FUNC: 51 6A 03 8B C8 (+0x5) -OldNotFound
#define CAN_CASTSPELL2_FUNC         0x8fae10    //9b2bae	call 8fae10
//-----------------------------------
#define HACK_R_VELKOZ_FUNC          0x0         // ===========<<NOT FOUND>>===========
#define LEVELUP_SPELL_1_FUNC        0x9a21b0    //9bb9ac	call 9a21b0
#define LEVELUP_SPELL_2_FUNC        0x9a0620    //9bb9bf	call 9a0620
#define BUY_ITEM_FUNC               0x0         // ===========<<NOT FOUND>>===========
#define OFF_THIS_BUY_ITEM           0x0         // ===========<<NOT FOUND>>===========
#define SELL_ITEM_FUNC              0x0         // ===========<<NOT FOUND>>===========
#define OFF_THIS_SELL_ITEM          0x0         // ===========<<NOT FOUND>>===========

//-------------------||----------------||-------------------|
#define NEXUS                       0x0         // ===========<<NOT FOUND>>===========
#define INHIBITOR                   0x0         // ===========<<NOT FOUND>>===========
#define BASE_DIRECTION              0x0         		//6697f3	====<<UNKNOW COMMAND>>====
#define GET_TEXTURE_GAME_FUNC       0x0         // ===========<<NOT FOUND>>===========
#define GET_BAR_DETAIL_FUNC         0x0         // ===========<<NOT FOUND>>===========
#define CHAT_TO_PLAYER_FUNC         0x0         // ===========<<NOT FOUND>>===========
#define POS2CELL_FUNC               0x0         // ===========<<NOT FOUND>>===========
#define CAN_CASTSPELL_FUNC          0x0         // ===========<<NOT FOUND>>===========
