//�������
#include <ansi.h>
inherit SPEC;

void create()
{
	set_name(HIM"�������" NOR, ({ "wucai laba","laba","wucai"}));
        set("long", 
                 "һ��������ȣ�����˵�����Դ���ɫŶ��\n"
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
	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",20);
	set("flag","spec/laba");
	set("desc","����˵�����Դ���ɫ��");
	set("credit",50);	
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
        if (arg1 != "chat" && arg1 != "sj" && arg1 !="party" && arg1 != "group" 
        && arg1 !="say" && arg1 !="tell" && arg1 !="reply" && arg1 !="whisper" && arg1 !="shout")
        return notify_fail("������������ȴ�ʲô��\n");
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
       	me->force_me(arg1+" "+arg2);
set("no_cun",1);
	degree();
	return 1;
}