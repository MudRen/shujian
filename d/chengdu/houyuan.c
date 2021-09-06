// houyuan.c ��Ժ
// 2001.10.04 update by Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����ǹص���ĺ�Ժ��Ժ�Ӻܴ���ǰ��Ժǽ����ķ�����һ�����ſ���
ͨ���𴦣������Ѿ����˶����ˡ�ŵ���Ժ���ﳤ�����Ӳݣ�������һС���
�أ��ر߷���һ��ˮͰ(tong)��
LONG);
        set("resource/water", 1);
	set("drink_msg","$Nſ��ˮͰ�ߺ���һ����ˮ��\n");
        set("sleep_room",1);
        set("no_fight", 1);

        set("item_desc", ([
                "tong" : "�����а�Ͱˮ�����˿��Ժȼ��ڡ�(drink tong)\n",
                "shuitong" : "�����а�Ͱˮ�����˿��Ժȼ��ڡ�(drink tong)\n"
        ]));

        set("exits", ([
                "south" : __DIR__"guandm",
        ]));

        set("objects", ([
                FOOD_D("mantou") : 4
        ]));

        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object me = this_player();
        object ob;

        if ( arg && (ob = present(arg)) && ob->id("man tou")){
                if ( !wizardp(me) && (present("man tou", me) || me->query("family/family_name")!="ؤ��"
                 || me->query("food") > me->query("str")*10 )){
                        write("�������и��Ͻл�����һ�����㲻�ɵ��������֡�\n");
                        return 1;
                }
        }
        return 0;
}