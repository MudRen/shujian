//�������
#include <ansi.h>
inherit ITEM;
/*
type: 1 : �漴��ɫ
      2 : �漴��ɫ��ǰ��ɫ
      3 : �漴��ɫ
      4 ���漴��ɫ
blink: 1 : ��˸
*/
string random_color(int type,int blink)
{
	string  *color_a  = ({ 	RED,
				YEL,
				BLU,
				MAG,
				CYN,
				HIR,
				HIG,
				HIY,
				HIB,
				HIM,
				HIC,
				HIW,
				WHT
				});

	string *color_b =   ({ 	BRED,
				BGRN,
				BYEL,
				BBLU,
				BMAG,
				BCYN,
 				HBRED,
				HBGRN,
				HBYEL,
				HBBLU,
				HBMAG,
				HBCYN,
				HBWHT,
			});
	string co="";
	int co1,co2;
	if( blink ) co+=BLINK;

	if( type==1 ) co+=color_b[random(sizeof(color_b))];
	else
	if( type==2 ) {
		co1=random(sizeof(color_b));
		co2=random(sizeof(color_a));
		while ( co1==co2 )
		{
		co1=random(sizeof(color_b));
		co2=random(sizeof(color_a));
		}
		co+=color_b[co1]+color_a[co2];
		}
	else
	if( type == 3 ) {
		if( random(6) )
		co1=random(6);
		else co1=13;
		co+=color_a[co1];
		}
	else
	if ( type == 4 ) {
		co1=6+random(7);
		co+=color_a[co1];
	}
	else 	co+=color_a[random(sizeof(color_a))];

	return co;
}

void create()
{
    set_name(random_color(4,0)+"��"+random_color(4,0)+"��"+random_color(4,0)+"��"+random_color(4,0)+"��" NOR, ({ "wucai laba","laba","wucai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("max_use",10+random(5));
                set("long", 
                        "һ��ո�µ�������ȣ�����˵�����Դ���ɫŶ��\n��������"+chinese_number(query("max_use"))+"�Ρ�\n"
                        "�÷���\n"
                        "cui ���� ��Ĵ��� ����������say reply shout chat �� \n"
                        "���� cui chat $HIG$ hi\n"
                        "��ɫ�б�\n"
                        "                     $NOR$ - �ָ�������ɫ\n"
			"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
			"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
			"$YEL$ - "YEL"����ɫ"NOR"       $HIY$ - "HIY"��ɫ\n"NOR
			"$BLU$ - "BLU"����ɫ"NOR"       $HIB$ - "HIB"��ɫ\n"NOR
			"$MAG$ - "MAG"ǳ��ɫ"NOR"       $HIM$ - "HIM"�ۺ�ɫ\n"NOR
			"$CYN$ - "CYN"����ɫ"NOR"       $HIC$ - "HIC"����ɫ\n"NOR
			"$WHT$ - ǳ��ɫ       $HIW$ - "HIW"��ɫ\n"NOR
                        );
		set("value", 1000);
		set("no_sell",1);	
                set("material", "wood");
             }
        setup();
}

void init()
{
        add_action("do_cui", "cui");
        add_action("do_cui", "chui");
}

int do_cui(string arg)
{
        string arg1,arg2;
        object me = this_player(); 
        if (!arg) return notify_fail("��Ҫ��ʲô��\n");
        sscanf(arg,"%s %s",arg1,arg2);
        if (arg1 != "chat" && arg1 != "rumor" && arg1 !="party" && arg1 != "group" 
        && arg1 !="say" && arg1 !="tell" && arg1 !="reply" && arg1 !="whisper" && arg1 !="shout" &&arg1 !="sj")
        return notify_fail("������������ȴ�ʲô��\n");
        if (query("used") >= query("max_use")) return notify_fail("��������Ѿ������ˡ�\n");
        arg2 = replace_string(arg2, "$RED$", RED);
        arg2 = replace_string(arg2, "$GRN$", GRN);
        arg2 = replace_string(arg2, "$YEL$", YEL);
        arg2 = replace_string(arg2, "$BLU$", BLU);
        arg2 = replace_string(arg2, "$MAG$", MAG);
        arg2 = replace_string(arg2, "$CYN$", CYN);
        arg2 = replace_string(arg2, "$WHT$", WHT);
        arg2 = replace_string(arg2, "$HIR$", HIR);
        arg2 = replace_string(arg2, "$HIG$", HIG);
        arg2 = replace_string(arg2, "$HIY$", HIY);
        arg2 = replace_string(arg2, "$HIB$", HIB);
        arg2 = replace_string(arg2, "$HIM$", HIM);
        arg2 = replace_string(arg2, "$HIC$", HIC);
        arg2 = replace_string(arg2, "$HIW$", HIW);
        arg2 = replace_string(arg2, "$NOR$", NOR);
        arg2 = replace_string(arg2, "$BRED$", BRED);
        arg2 = replace_string(arg2, "$BGRN$", BGRN);
        arg2 = replace_string(arg2, "$BBLU$", BBLU);
        arg2 = replace_string(arg2, "$BYEL$", BYEL);
        arg2 = replace_string(arg2, "$BMAG$", BMAG);
        arg2 = replace_string(arg2, "$BCYN$", BCYN);
        arg2 = replace_string(arg2, "$BBLK$", BBLK);
        arg2 = replace_string(arg2, "$HBRED$", HBRED);
        arg2 = replace_string(arg2, "$HBGRN$", HBGRN);
        arg2 = replace_string(arg2, "$HBBLU$", HBBLU);
        arg2 = replace_string(arg2, "$HBYEL$", HBYEL);
        arg2 = replace_string(arg2, "$HBMAG$", HBMAG);
        arg2 = replace_string(arg2, "$HBCYN$", HBCYN);
        arg2 = replace_string(arg2, "$HBWHT$", HBWHT);
        //arg2 = replace_string(arg2, "$BLINK$", BLINK);
        arg2 += NOR;
        add("used",1);
        if (query("used")>=query("max_use"))
		set("long", "һ���Ѿ�������������ȣ���Ҳ�����������ˡ�\n"
		        "�÷���\n"
                        "cui ���� ��Ĵ��� ����������say reply shout chat �� \n"
                        "���� cui chat $HIG$ hi\n"
                        "��ɫ�б�\n"
                        "                     $NOR$ - �ָ�������ɫ\n"
			"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
			"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
			"$YEL$ - "YEL"����ɫ"NOR"       $HIY$ - "HIY"��ɫ\n"NOR
			"$BLU$ - "BLU"����ɫ"NOR"       $HIB$ - "HIB"��ɫ\n"NOR
			"$MAG$ - "MAG"ǳ��ɫ"NOR"       $HIM$ - "HIM"�ۺ�ɫ\n"NOR
			"$CYN$ - "CYN"����ɫ"NOR"       $HIC$ - "HIC"����ɫ\n"NOR
			"$WHT$ - ǳ��ɫ       $HIW$ - "HIW"��ɫ\n"NOR
		);		
	else
	        set("long", "һ���Ѿ��ù���������ȣ�����˵�����Դ���ɫŶ��\n��������"+chinese_number(query("max_use")-query("used"))+"�Ρ�\n"
	                                "�÷���\n"
                        "cui ���� ��Ĵ��� ����������say reply shout chat �� \n"
                        "���� cui chat $HIG$ hi\n"
                        "��ɫ�б�\n"
                        "                     $NOR$ - �ָ�������ɫ\n"
			"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
			"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
			"$YEL$ - "YEL"����ɫ"NOR"       $HIY$ - "HIY"��ɫ\n"NOR
			"$BLU$ - "BLU"����ɫ"NOR"       $HIB$ - "HIB"��ɫ\n"NOR
			"$MAG$ - "MAG"ǳ��ɫ"NOR"       $HIM$ - "HIM"�ۺ�ɫ\n"NOR
			"$CYN$ - "CYN"����ɫ"NOR"       $HIC$ - "HIC"����ɫ\n"NOR
			"$WHT$ - ǳ��ɫ       $HIW$ - "HIW"��ɫ\n"NOR
	        );
        if (arg1 == "chat" || arg1 == "rumor" || arg1 =="party" || arg1 == "group"|| arg1 =="sj")

        	return me->force_me(arg1+"* �����������˵��:"+arg2);
        else
        	return me->force_me(arg1+" "+arg2);
}