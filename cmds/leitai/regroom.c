#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��ҵǼ���"NOR);
	set("long", @LONG
============================================================
    ����������ҵȴ��˺ż���ĵط�����ұ��뼤��������ʽ
    ��ʼ��Ϸ��
    
    �����QQȺ88397272������ϵQQ  10388172 ����ȡ���
    
    Ϊ�˸���Ļ�����ͨ��������ر���������id��ע��email
    
    Ϊ�˸��õع����齣���Ը���Ҵ����Ĳ��㾴��ԭ�¡�
================================================================
LONG);
	set("no_death", 1);
//         set("no_summon_out", 1);
	set("no_save", 1);
	set("no_update", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("indoors", "�齣");
	setup();
}

void init()
{
        add_action("do_quit","suicide");      
        add_action("do_quit","exert");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","halt");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","chat");
        add_action("do_quit2","respirate");
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
        add_action("do_quit2","chat*");
        add_action("do_quit2","fight");
        add_action("do_quit2","kill");
        add_action("do_quit2","hit");
}

int do_quit(string arg)
{
        if(arg=="roar") {
        write(this_player()->query("name")+"�������QQȺ88397272������ϵQQ  10388172 ����ȡ���\n");
        return 1;
        }

        if(arg=="all") {
        write(this_player()->query("name")+"�������QQȺ88397272������ϵQQ  10388172 ����ȡ���\n");
        return 1;
        }
        if(arg=="corpse") {
        write(this_player()->query("name")+"�������QQȺ88397272������ϵQQ  10388172 ����ȡ���\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"�������QQȺ88397272������ϵQQ  10388172 ����ȡ���\n");
        return 1;
}

